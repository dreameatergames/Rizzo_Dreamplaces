#ifndef _DREAMPLACES_PROFILER_H_
#define _DREAMPLACES_PROFILER_H_

enum{
	PROFILER_TOTAL = 0,
	PROFILER_BLIT,
	PROFILER_NET,
	PROFILER_SV,
	PROFILER_CL,
	PROFILER_RENDER,
	PROFILER_DWORLD,
	PROFILER_DMODEL,
	PROFILER_R0,
	PROFILER_R1,
	PROFILER_R2,
	PROFILER_R3,
	PROFILER_R4,
	PROFILER_R5,
	PROFILER_R6,
	PROFILER_R7,
};



#ifndef PROFILER_DREAMPLACES

#define dreamplaces_prof_start(A)
#define dreamplaces_prof_end(A)
#define dreamplaces_prof_show()
#define dreamplaces_prof_init()
#define dreamplaces_prof_reset()

#else

#ifdef PROFILER_SDL
#include <SDL.h>
#define PROFILER__REDUCTION__ 0
#define PROFILER__ADJUST__ 0
#define get_time_in_micros() (unsigned long long)SDL_GetTicks()
#else
#ifndef DREAMCAST
#include <sys/time.h>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <time.h>

#ifndef __GNUC__
#define EPOCHFILETIME (116444736000000000i64)
#else
#define EPOCHFILETIME (116444736000000000LL)
#endif


static __inline__ int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    FILETIME        ft;
    LARGE_INTEGER   li;
    __int64         t;
    static int      tzflag;

    if (tv)
    {
        GetSystemTimeAsFileTime(&ft);
        li.LowPart  = ft.dwLowDateTime;
        li.HighPart = ft.dwHighDateTime;
        t  = li.QuadPart;       /* In 100-nanosecond intervals */
        t -= EPOCHFILETIME;     /* Offset to the Epoch time */
        t /= 10;                /* In microseconds */
        tv->tv_sec  = (long)(t / 1000000);
        tv->tv_usec = (long)(t % 1000000);
    }

    return 0;
}

#endif

static __inline__ unsigned long long get_time_in_micros(void)
{
	unsigned long long ret;
	struct timeval tm;
	gettimeofday(&tm,NULL);
	ret=tm.tv_sec;
	ret*=1000000LL;
	ret+=tm.tv_usec;
	return ret;
}
#define PROFILER__REDUCTION__ 0
#define PROFILER__ADJUST__ 0
#else
#include <kos.h>
#define PROFILER__REDUCTION__ 2
#define PROFILER__ADJUST__ 1
#define get_time_in_micros() timer_us_gettime64()
#endif
#endif

#define DREAMPLACES_PROFILER_MAX 64

extern unsigned long long dreamplaces_prof_initial[DREAMPLACES_PROFILER_MAX];
extern unsigned long long dreamplaces_prof_sum[DREAMPLACES_PROFILER_MAX];
extern unsigned long long dreamplaces_prof_executed[DREAMPLACES_PROFILER_MAX];
extern int dreamplaces_prof_started[DREAMPLACES_PROFILER_MAX];

static __inline__ void dreamplaces_prof_start(unsigned a)
{
	if (dreamplaces_prof_started[a])
		return;
	dreamplaces_prof_executed[a]++;
	dreamplaces_prof_initial[a]=get_time_in_micros();
	dreamplaces_prof_started[a]=1;
}


static __inline__ void dreamplaces_prof_end(unsigned a)
{
	if (!dreamplaces_prof_started[a])
		return;

	extern unsigned dreamplaces_prof_total;
	unsigned i;
	for(i=0;i<dreamplaces_prof_total;i++)
		dreamplaces_prof_initial[i]+=PROFILER__REDUCTION__;
	dreamplaces_prof_sum[a]+=get_time_in_micros()-dreamplaces_prof_initial[a]+PROFILER__ADJUST__;
	dreamplaces_prof_started[a]=0;
}

#undef PROFILER__REDUCTION__
#undef PROFILER__ADJUST__

void dreamplaces_prof_init(void);
void dreamplaces_prof_add(char *msg);
void dreamplaces_prof_show(void);
void dreamplaces_prof_setmsg(int n, char *msg);
void dreamplaces_prof_reset(void);


#endif





#endif


