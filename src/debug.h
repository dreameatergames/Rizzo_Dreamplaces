#include <SDL.h>

#ifndef DEBUG_DREAMPLACES_H
#define DEBUG_DREAMPLACES_H

#ifdef DEBUG_DREAMPLACES

#ifndef START_DEBUG
#define START_DEBUG 0
#endif

extern int DEBUG_AHORA;
#ifdef DEBUG_FILE
extern FILE *DEBUG_STR_FILE;
#else
#define DEBUG_STR_FILE stdout
#endif

#ifdef DEBUG_DREAMPLACES_FFLUSH
#define DREAMPLACES_FFLUSH fflush(DEBUG_STR_FILE);
#else
#define DREAMPLACES_FFLUSH
#endif

#ifdef DEBUG_FILE
#define dbg(TEXTO) \
	if (DEBUG_AHORA) \
	{ \
		fprintf(DEBUG_STR_FILE,"%s\n",TEXTO); \
		DREAMPLACES_FFLUSH \
	}


#define dbgf(FORMATO, RESTO...) \
	if (DEBUG_AHORA) \
	{ \
		fprintf (DEBUG_STR_FILE,FORMATO , ## RESTO); \
		DREAMPLACES_FFLUSH \
	}
#else
#define dbg(TEXTO) \
	if (DEBUG_AHORA) \
	{ \
		puts(TEXTO); \
		DREAMPLACES_FFLUSH \
	}


#define dbgf(FORMATO, RESTO...) \
	if (DEBUG_AHORA) \
	{ \
		printf(FORMATO , ## RESTO); \
		DREAMPLACES_FFLUSH \
	}
#endif


static __inline__ void dbgsum(char *str, void *buff, unsigned len)
{
	if (DEBUG_AHORA)
	{
		unsigned char *p=(unsigned char *)buff;
		unsigned i,ret=0;
		for(i=0;i<len;i++,p++)
			ret+=(*p)*i;
		fprintf(DEBUG_STR_FILE,"%s : 0x%X\n",str,ret);
#ifdef DEBUG_DREAMPLACES_FFLUSH
		fflush(DEBUG_STR_FILE);
#endif
	}
}


#else

#define dbg(TEXTO)
#define dbgf(FORMATO, RESTO...)
#define debsum(STR)


#endif

#endif
