
#ifdef NO_NET

#ifdef DREAMCAST
#include<kos.h>
#endif


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "quakedef.h"
#include "zone.h"
#include "sys.h"
#include "netconn.h"

#include "lhnet.h"


//#define SOCKLEN_T int
#define ioctlsocket ioctl
#define closesocket close
#define SOCKETERRNO errno
#define SOCKLEN_T socklen_t

#ifndef REDUCE_MEMORY
#define BUFF_SOCKET_LEN ((64*1024)-16)
#else
#define BUFF_SOCKET_LEN ((4*1024)-16)
#endif

static lhnetsocket_t ret_socket[4];
static unsigned char buff_socket[2][BUFF_SOCKET_LEN+16];
static unsigned buff_socket_pr[2];
static unsigned buff_socket_pw[2];


int LHNETADDRESS_FromPort(lhnetaddress_t *address, int addresstype, int port)
{
	if (!address)
		return 0;
	switch(addresstype)
	{
		case LHNETADDRESSTYPE_LOOP:
			memset(address, 0, sizeof(*address));
			address->addresstype = LHNETADDRESSTYPE_LOOP;
			address->addressdata.loop.port = port;
			return 1;
		case LHNETADDRESSTYPE_INET4:
			memset(address, 0, sizeof(*address));
			address->addresstype = LHNETADDRESSTYPE_INET4;
			address->addressdata.inet4.family = LHNETADDRESSTYPE_INET4_FAMILY;
			address->addressdata.inet4.port = /*htons*/((unsigned short)port);
			return 1;
	}
	return 0;
}

int LHNETADDRESS_FromString(lhnetaddress_t *address, const char *string, int defaultport)
{
	char name[64];
	const char *colon;
	int port = 0, namelen;
	if (!address || !string || !*string)
		return 0;
	memset(address, 0, sizeof(*address));
	address->addresstype = LHNETADDRESSTYPE_NONE;
	colon = strrchr(string, ':');
	if (colon)
		port = atoi(colon + 1);
	else
		colon = string + strlen(string);
	if (port == 0)
		port = defaultport;
	namelen = colon - string + 1;
	if (namelen > 63)
		namelen = 63;
	memset(name,0,64);
	strlcpy((char *)&name,string,namelen);
	if (!strcmp((char *)&name, "local"))
	{
		address->addresstype = LHNETADDRESSTYPE_LOOP;
		address->addressdata.inet4.port = port;
		address->addressdata.loop.port = port;
	}
	else
	{
		int d1, d2, d3, d4;
		if (sscanf((char *)&name, "%d.%d.%d.%d", &d1, &d2, &d3, &d4) >= 1 && (unsigned int)d1 < 256 && (unsigned int)d2 < 256 && (unsigned int)d3 < 256 && (unsigned int)d4 < 256)
		{
			address->addresstype = LHNETADDRESSTYPE_INET4;
			address->addressdata.inet4.family = LHNETADDRESSTYPE_INET4_FAMILY;
			address->addressdata.inet4.port = /*htons*/((unsigned short)port);
			address->addressdata.inet4.address[0] = (unsigned char)d1;
			address->addressdata.inet4.address[1] = (unsigned char)d2;
			address->addressdata.inet4.address[2] = (unsigned char)d3;
			address->addressdata.inet4.address[3] = (unsigned char)d4;
		}
	}

	return 1; //0;
}

int LHNETADDRESS_ToString(const lhnetaddress_t *address, char *string, int stringbuffersize, int includeport)
{
	if (!address || !string || stringbuffersize < 1)
		return 0;
	*string = 0;
	switch(address->addresstype)
	{
		case LHNETADDRESSTYPE_LOOP:
			if (includeport)
			{
				if (stringbuffersize >= 12)
				{
					sprintf(string, "local:%d", (int)address->addressdata.loop.port);
					return 1;
				}
			}
			else
			{
				if (stringbuffersize >= 6)
				{
					memcpy(string, "local", 6);
					return 1;
				}
			}
			break;
		case LHNETADDRESSTYPE_INET4:
			if (includeport)
			{
				if (stringbuffersize >= 22)
				{
					sprintf(string, "%d.%d.%d.%d:%d", (int)address->addressdata.inet4.address[0], (int)address->addressdata.inet4.address[1], (int)address->addressdata.inet4.address[2], (int)address->addressdata.inet4.address[3], (int)/*ntohs*/(address->addressdata.inet4.port));
					return 1;
				}
			}
			else
			{
				if (stringbuffersize >= 16)
				{
					sprintf(string, "%d.%d.%d.%d", (int)address->addressdata.inet4.address[0], (int)address->addressdata.inet4.address[1], (int)address->addressdata.inet4.address[2], (int)address->addressdata.inet4.address[3]);
					return 1;
				}
			}
			break;
	}
	return 0;
}

int LHNETADDRESS_GetAddressType(const lhnetaddress_t *address)
{
	if (address)
		return address->addresstype;
	else
		return LHNETADDRESSTYPE_NONE;
}

int LHNETADDRESS_GetPort(const lhnetaddress_t *address)
{
	if (!address)
		return -1;
	switch(address->addresstype)
	{
		case LHNETADDRESSTYPE_LOOP:
			return address->addressdata.loop.port;
		case LHNETADDRESSTYPE_INET4:
			return /*ntohs*/(address->addressdata.inet4.port);
	}
	return -1;
}

int LHNETADDRESS_SetPort(lhnetaddress_t *address, int port)
{
	if (!address)
		return 0;
	switch(address->addresstype)
	{
		case LHNETADDRESSTYPE_LOOP:
			address->addressdata.loop.port = port;
			return 1;
		case LHNETADDRESSTYPE_INET4:
			address->addressdata.inet4.port = /*htons*/((unsigned short)port);
			return 1;
	}
	return 0;
}

int LHNETADDRESS_Compare(const lhnetaddress_t *address1, const lhnetaddress_t *address2)
{
	if (!address1 || !address2)
		return 1;
	if (address1->addresstype != address2->addresstype)
		return 1;
	switch(address1->addresstype)
	{
		case LHNETADDRESSTYPE_LOOP:
			if (address1->addressdata.loop.port != address2->addressdata.loop.port)
				return -1;
			return 0;
		case LHNETADDRESSTYPE_INET4:
			if (address1->addressdata.inet4.family != address2->addressdata.inet4.family)
				return 1;
			if (memcmp(address1->addressdata.inet4.address, address2->addressdata.inet4.address, sizeof(address1->addressdata.inet4.address)))
				return 1;
			if (address1->addressdata.inet4.port != address2->addressdata.inet4.port)
				return -1;
			return 0;
	}
	return 1;
}

typedef struct lhnetpacket_s
{
	void *data;
	int length;
	int sourceport;
	int destinationport;
	time_t timeout;
	double sentdoubletime;
	struct lhnetpacket_s *next, *prev;
}
lhnetpacket_t;

//static int lhnet_active;
//static lhnetsocket_t lhnet_socketlist;
//static lhnetpacket_t lhnet_packetlist;

void LHNET_Init(void)
{
}

void LHNET_Shutdown(void)
{
}


void LHNET_SleepUntilPacket_Microseconds(int microseconds)
{
}


lhnetsocket_t *LHNET_OpenSocket_Connectionless(lhnetaddress_t *address)
{
	static unsigned actual=0;
	int n=actual&3;
	lhnetsocket_t *ret=(lhnetsocket_t *)&ret_socket[n];

	buff_socket_pr[0]=buff_socket_pw[0]=0;
	buff_socket_pr[1]=buff_socket_pw[1]=0;
#ifdef DEBUG_NET
	dbgf("LHNET_OpenSocket_Connectionless <- %i\n",n);
#endif

	memset(ret,0,sizeof(lhnetsocket_t));
	if (address)
		ret->address = *address;
	ret->prev=(lhnetsocket_t *)&ret_socket[(actual-1)&3];
	ret->next=(lhnetsocket_t *)&ret_socket[(actual+1)&3];
	actual++;
	return ret;
}

void LHNET_CloseSocket(lhnetsocket_t *lhnetsocket)
{
}

lhnetaddress_t *LHNET_AddressFromSocket(lhnetsocket_t *sock)
{
	if (sock)
		return &sock->address;
	return NULL;
}

int LHNET_Read(lhnetsocket_t *lhnetsocket, void *content, int maxcontentlength, lhnetaddress_t *address)
{
	int ret=0,n=1, len=0;
	unsigned char *b=(unsigned char *)content;

	if (lhnetsocket==&ret_socket[1])
		return 0;

	if (lhnetsocket==&ret_socket[2])
		n=0;
	if (lhnetsocket==&ret_socket[3])
		return 0;

	if (!lhnetsocket || !address || !content || maxcontentlength < 1)
		return -1;
	if (buff_socket_pr[n]!=buff_socket_pw[n])
	{
		len=buff_socket[n][buff_socket_pr[n]++];
		len<<=8;
		len&=0xFF00;
		len|=buff_socket[n][buff_socket_pr[n]++];
	}
#ifdef DEBUG_NET
	dbgf("LHNET_Read %i, pr=%i, pw=%i <- len=%i\n",n,buff_socket_pr[n],buff_socket_pw[n],len);
#endif

	while(buff_socket_pr[n]!=buff_socket_pw[n] && ret<len)
	{
#ifdef DEBUG_NET
		if (!ret)
			dbgf("LHNET_Read: ");
#endif
		if (ret<maxcontentlength)
			*b++=buff_socket[n][buff_socket_pr[n]];
#ifdef DEBUG_NET
		dbgf("%.2X, ",buff_socket[n][buff_socket_pr[n]]);
#endif
		buff_socket_pr[n]++;
		if (buff_socket_pr[n]>=BUFF_SOCKET_LEN)
			buff_socket_pr[n]=0;
		ret++;
	}
	if (ret)
	{
#ifdef DEBUG_NET
		dbg(" .");
#endif
		if (lhnetsocket->address.addresstype == LHNETADDRESSTYPE_LOOP)
		{
			*address = lhnetsocket->address;
			address->addressdata.loop.port =lhnetsocket->address.addressdata.loop.port;
			address->addresstype = LHNETADDRESSTYPE_LOOP;

		}
		else
		{
			*address = lhnetsocket->address;
			address->addressdata.inet4.port =lhnetsocket->address.addressdata.inet4.port;
			address->addressdata.inet4.address[0] =lhnetsocket->address.addressdata.inet4.address[0];
			address->addressdata.inet4.address[1] =lhnetsocket->address.addressdata.inet4.address[1];
			address->addressdata.inet4.address[2] =lhnetsocket->address.addressdata.inet4.address[2];
			address->addressdata.inet4.address[3] =lhnetsocket->address.addressdata.inet4.address[3];
			address->addresstype = LHNETADDRESSTYPE_INET4;
		}
	}
	else
	{
		address->addresstype = LHNETADDRESSTYPE_NONE;
	}
	return ret;
}

int LHNET_Write(lhnetsocket_t *lhnetsocket, const void *content, int contentlength, const lhnetaddress_t *address)
{
	int ret=0, n=0;
	unsigned char *b=(unsigned char *)content;

	if (!lhnetsocket || !address || !content || contentlength < 1)
		return -1;
	if (lhnetsocket==&ret_socket[1]) return 0;

	if (lhnetsocket==&ret_socket[2])
		n=1;
	if (lhnetsocket==&ret_socket[3]) return 0;

	buff_socket[n][buff_socket_pw[n]++]=contentlength >> 8;
	buff_socket[n][buff_socket_pw[n]++]=contentlength;
#ifdef DEBUG_NET
	dbgf("LHNET_Write %i, pr=%i, pw=%i <- len=%i\n",n,buff_socket_pr[n],buff_socket_pw[n],contentlength);
#endif

	while(ret<contentlength)
	{
#ifdef DEBUG_NET
		if (!ret)
			dbgf("LHNET_Write: ");
#endif
		buff_socket[n][buff_socket_pw[n]]=*b++;
#ifdef DEBUG_NET
		dbgf("%.2X, ",buff_socket[n][buff_socket_pw[n]]);
#endif
		buff_socket_pw[n]++;
		if (buff_socket_pw[n]>=BUFF_SOCKET_LEN)
			buff_socket_pw[n]=0;
		ret++;
	}
#ifdef DEBUG_NET
	if (ret)
		dbg(" .");
#endif
	return ret;
}

#endif
