#ifdef DREAMCAST
#include <kos.h>
//extern uint8 romdisk[];
KOS_INIT_FLAGS(INIT_DEFAULT);
//KOS_INIT_ROMDISK(romdisk);
#include <SDL.h>
#include <SDL_dreamcast.h>
#define chdir(A) fs_chdir(A)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#include <io.h>
#include "conio.h"
#else
#include <unistd.h>
#include <fcntl.h>
#ifndef NO_DLLS
#include <dlfcn.h>
#endif
#endif
#include <time.h>
#include <sys/time.h>

#ifdef DEBUG_DREAMPLACES
#if START_DEBUG==0
int DEBUG_AHORA=1;
#else
int DEBUG_AHORA=0;
#endif
#ifdef DEBUG_FILE
FILE *DEBUG_STR_FILE=NULL;
#endif
#endif


static char sys_timestring[48];


#include <signal.h>

#include "quakedef.h"

#include <SDL.h>


#ifdef PROFILER_DREAMPLACES
static unsigned dreamplaces_prof_total_initial=0;
unsigned dreamplaces_prof_total=0;
static char *dreamplaces_prof_msg[DREAMPLACES_PROFILER_MAX];
unsigned long long dreamplaces_prof_initial[DREAMPLACES_PROFILER_MAX];
unsigned long long dreamplaces_prof_sum[DREAMPLACES_PROFILER_MAX];
unsigned long long dreamplaces_prof_executed[DREAMPLACES_PROFILER_MAX];
int dreamplaces_prof_started[DREAMPLACES_PROFILER_MAX];

void dreamplaces_prof_reset(void)
{
	int i;
	unsigned long long s=get_time_in_micros();
	for(i=0;i<DREAMPLACES_PROFILER_MAX;i++)
	{
		dreamplaces_prof_initial[i]=s;
		dreamplaces_prof_sum[i]=0;
		if (dreamplaces_prof_started[i])
			dreamplaces_prof_executed[i]=1;
		else
			dreamplaces_prof_executed[i]=0;
	}
	dreamplaces_prof_total_initial=s;
}

void dreamplaces_prof_init(void)
{
	unsigned i;
	unsigned long long s=get_time_in_micros();
	for(i=0;i<DREAMPLACES_PROFILER_MAX;i++)
	{
		dreamplaces_prof_initial[i]=s;
		dreamplaces_prof_sum[i]=0;
		if (!dreamplaces_prof_total)
		{
			dreamplaces_prof_executed[i]=0;
			dreamplaces_prof_started[i]=0;
			dreamplaces_prof_msg[i]=NULL;
		}
		else
		{
			if (dreamplaces_prof_started[i])
			        dreamplaces_prof_executed[i]=1;
			else
			        dreamplaces_prof_executed[i]=0;
		}
	}
	dreamplaces_prof_total_initial=s;
}

void dreamplaces_prof_add(char *msg)
{
	if (dreamplaces_prof_total<DREAMPLACES_PROFILER_MAX)
	{
		dreamplaces_prof_msg[dreamplaces_prof_total]=msg;
		dreamplaces_prof_total++;
	}
}

void dreamplaces_prof_show(void)
{
	int i;
	double toper=0;
	unsigned long long to;
	for(i=dreamplaces_prof_total-1;i>=0;i--)
		dreamplaces_prof_end(i);
	to=dreamplaces_prof_sum[0];
	puts("\n\n\n\n");
	puts("--------------------------------------------");
	for(i=0;i<dreamplaces_prof_total;i++)
	{
		unsigned long long t0=dreamplaces_prof_sum[i];
		double percent=(double)t0;
		percent*=100.0;
		percent/=(double)to;
		toper+=percent;
#ifndef PROFILER_SDL
		t0/=1000;
#endif
		printf("%s: %.2f%% -> Ticks=%i ->",dreamplaces_prof_msg[i],percent,((unsigned)t0));
		if (dreamplaces_prof_executed[i]>3000LL)
			printf("%iK veces\n",(unsigned)(dreamplaces_prof_executed[i]/1000LL));
		else
			printf("%i veces\n",(unsigned)(dreamplaces_prof_executed[i]));
	}
//      printf("TOTAL: %.2f%% -> Ticks=%i\n",toper,to);
	puts("--------------------------------------------"); fflush(stdout);
}

void dreamplaces_prof_setmsg(int n, char *msg)
{
	dreamplaces_prof_msg[n]=msg;
}

#endif

int SDL_Quake_MapKey( unsigned int sdlkey );

// =======================================================================
// General routines
// =======================================================================

void Sys_Shutdown (void)
{
	puts("DreamPlaces: Shutdown!!!");
	fflush(stdout);
	SDL_Quit();
}

#ifndef NO_CONSOLE
void Sys_Error (const char *error, ...)
{
	va_list argptr;
	char string[MAX_INPUTLINE];

	va_start (argptr,error);
	dpvsnprintf (string, sizeof (string), error, argptr);
	va_end (argptr);

	Con_Printf ("Quake Error: %s\n", string);

	Host_Shutdown ();
	exit (1);
}
#endif

void Sys_PrintToTerminal(const char *text)
{
//	puts(text);
	printf("%s",text); //fflush(stdout);
}

double Sys_DoubleTime (void)
{
#if !defined(MAX_AUTOEVENTS) && !defined(DEBUG_GL) && !defined(DEBUG_DREAMPLACES) && !defined(PROFILER_DREAMPLACES)
	static int first = true;
	static double oldtime = 0.0, curtime = 0.0;
	double newtime;
	newtime = (double) SDL_GetTicks() / 1000.0;


	if (first)
	{
		first = false;
		oldtime = newtime;
	}

	if (newtime < oldtime)
	{
/*
		// warn if it's significant
		if (newtime - oldtime < -0.01)
			Con_Printf("Sys_DoubleTime: time stepped backwards (went from %f to %f, difference %f)\n", oldtime, newtime, newtime - oldtime);
*/
	}
	else
		curtime += newtime - oldtime;
	oldtime = newtime;

	return curtime;
#else
	static double rt=0.0;
//	rt+=0.002;
	rt+=0.123;
	return rt;
#endif
}

char *Sys_ConsoleInput(void)
{
	static char text[MAX_INPUTLINE];
	int len = 0;
	SDL_Event e;

	if (cls.state != ca_dedicated)
		return NULL;

	while(SDL_PollEvent (&e) && len < (MAX_INPUTLINE-1))
		if (e.type==SDL_KEYUP)
			text[len++]=SDL_Quake_MapKey(e.key.keysym.sym);

	if (!len)
		return NULL;
	text[len]=0;
	return text;
}

#if 0
void Sys_Sleep(int microseconds)
{
	if (microseconds < 1000)
		microseconds = 1000;
	SDL_Delay(microseconds / 1000);
}
#endif

char *Sys_GetClipboardData (void)
{
	return NULL;
}

void Sys_InitConsole (void)
{
}

void Sys_Init_Commands (void)
{
}

char *Sys_TimeString(const char *timeformat)
{
	time_t mytime = time(NULL);
	strftime(sys_timestring, sizeof(sys_timestring), timeformat, localtime(&mytime));
	return sys_timestring;
}


extern qboolean host_shuttingdown;
void Sys_Quit (void)
{
	host_shuttingdown = true;
	Host_Shutdown();
	exit(0);
}

/*
===============================================================================

DLL MANAGEMENT

===============================================================================
*/

qboolean Sys_LoadLibrary (const char** dllnames, dllhandle_t* handle, const dllfunction_t *fcts)
{
	const dllfunction_t *func;
	dllhandle_t dllhandle = 0;
	unsigned int i;

	if (handle == NULL)
		return false;

	// Initializations
	for (func = fcts; func && func->name != NULL; func++)
		*func->funcvariable = NULL;

	// Try every possible name
	Con_Printf ("Trying to load library...");
	for (i = 0; dllnames[i] != NULL; i++)
	{
		Con_Printf (" \"%s\"", dllnames[i]);
#ifndef NO_DLLS
#ifdef WIN32
		dllhandle = LoadLibrary (dllnames[i]);
#else
		dllhandle = dlopen (dllnames[i], RTLD_LAZY | RTLD_GLOBAL);
#endif
		if (dllhandle)
			break;
#endif
	}

	// No DLL found
	if (! dllhandle)
	{
		Con_Printf(" - failed.\n");
		return false;
	}

	Con_Printf(" - loaded.\n");

	// Get the function adresses
	for (func = fcts; func && func->name != NULL; func++)
		if (!(*func->funcvariable = (void *) Sys_GetProcAddress (dllhandle, func->name)))
		{
			Con_Printf ("Missing function \"%s\" - broken library!\n", func->name);
			Sys_UnloadLibrary (&dllhandle);
			return false;
		}

	*handle = dllhandle;
	return true;
}

void Sys_UnloadLibrary (dllhandle_t* handle)
{
	if (handle == NULL || *handle == NULL)
		return;
#ifndef NO_DLLS
#ifdef WIN32
	FreeLibrary (*handle);
#else
	dlclose (*handle);
#endif
#endif

	*handle = NULL;
}

void* Sys_GetProcAddress (dllhandle_t handle, const char* name)
{
#ifndef NO_DLLS
#ifdef WIN32
	return (void *)GetProcAddress (handle, name);
#else
	return (void *)dlsym (handle, name);
#endif
#else
	return NULL;
#endif
}


#ifdef DREAMCAST
int mkdir(const char *pathname, mode_t mode)
{
	return -1;
}

int dup(int oldfd)
{
	return (int)fs_dup(oldfd);
}

static char *dummy_argv[]={ "dreamplaces",	// 1
			   "-basedir", 		// 2
			   DATA_PREFIX, 	// 3
			   "-particles",	// 4
			   "256",		// 5
			   "-bpp",		// 6
			   "16",		// 7
			   "-fullscreen",	// 8
			   "-novorbis",		// 9
			   "+snd_streaming",	// 10
			   "0",			// 11
			   "+snd_speed",	// 12
			   "22050",		// 13
			   "+gl_max_size",	// 14
			   "128",		// 15
			   "+gl_picmip",	// 16
			   "2",			// 17
			   "+r_lightmaprgba",	// 18
			   "0",			// 19
			   "+snd_precache", 	// 20
			   "0",			// 21
			   "+r_precachetextures", // 22
			   "2",			// 23
			   "+scr_screenshot_jpeg", // 24
			   "0",			// 25
			   "+r_mipsprites",	// 26
			   "0",			// 27
			   "+r_mipskins",	// 28
			   "0",			// 29
			   "+gl_texturemode",	// 30
			   "GL_LINEAR",	// 31
//			   "GL_NEAREST",	// 31
// "-benchmark", "demo1",
			   "-notexture3d",	// 32
			   "-nosound",		// 33
			   "+changelevel",	// 34
//			   "dm4",		// 35
//			   "e1m7",		// 35
//			   "end",		// 35
			   "start",		// 35
		"","",NULL };
#endif

int main (int argc, char *argv[])
{
#ifdef DREAMCAST
	com_argc = 35;
	com_argv = (const char **)dummy_argv;
#else
	signal(SIGFPE, SIG_IGN);
	com_argc = argc;
	com_argv = (const char **)argv;
#endif

	puts("DreamPlaces: MAIN!!!"); fflush(stdout);
#ifdef DREAMCAST
	chdir(DATA_PREFIX);
	SDL_DC_ShowAskHz(SDL_FALSE);
#endif

#if defined(DEBUG_DREAMPLACES) && defined(DEBUG_FILE)
	DEBUG_STR_FILE=fopen(DEBUG_FILE,"wt");
#endif

#ifdef PROFILER_DREAMPLACES
	dreamplaces_prof_init();
	dreamplaces_prof_add("Main");		// PROFILER_TOTAL
	dreamplaces_prof_add("Blit");		// PROFILER_BLIT
	dreamplaces_prof_add("Net");		// PROFILER_NET
	dreamplaces_prof_add("Server");		// PROFILER_SV
	dreamplaces_prof_add("Client");		// PROFILER_CL
	dreamplaces_prof_add("Render");		// PROFILER_RENDER
	dreamplaces_prof_add("Draw World");	// PROFILER_DWORLD
	dreamplaces_prof_add("Draw Model");	// PROFILER_DMODEL
	dreamplaces_prof_add("R0");		// PROFILER_R0
	dreamplaces_prof_add("R1");		// PROFILER_R1
	dreamplaces_prof_add("R2");		// PROFILER_R2
	dreamplaces_prof_add("R3");		// PROFILER_R3
	dreamplaces_prof_add("R4");		// PROFILER_R4
	dreamplaces_prof_add("R5");		// PROFILER_R5
	dreamplaces_prof_add("R6");		// PROFILER_R6
	dreamplaces_prof_add("R7");		// PROFILER_R7
#endif

	// we don't know which systems we'll want to init, yet...
//	SDL_Init(0);

	Host_Main();

	return 0;
}

