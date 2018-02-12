
#ifndef QTYPES_H
#define QTYPES_H

#ifdef NO_DOUBLE
typedef float dr_time_t;
typedef float dr_real_t;
#define dr_sqrt(A) sqrtf(A)
#define dr_cos(A)  cosf(A)
#define dr_sin(A)  sinf(A)
#define dr_tan(A)  tanf(A)
#define dr_pow(A,B)  powf(A,B)
#define dr_acos(A) acosf(A)
#define dr_asin(A) asinf(A)
#define dr_atan(A) atanf(A)
#define dr_atan2(A,B) atan2f(A,B)
#define dr_floor(A) floorf(A)
#define dr_fabs(A) fabsf(A)
#define dr_ceil(A) ceilf(A)
#define dr_log(A) logf(A)
#define dr_exp(A) expf(A)
#else
typedef double dr_time_t;
typedef double dr_real_t;
#define dr_sqrt(A) sqrt(A)
#define dr_cos(A)  cos(A)
#define dr_sin(A)  sin(A)
#define dr_tan(A)  tan(A)
#define dr_pow(A,B)  pow(A,B)
#define dr_acos(A) acos(A)
#define dr_asin(A) asin(A)
#define dr_atan(A) atan(A)
#define dr_atan2(A,B) atan2(A,B)
#define dr_floor(A) floor(A)
#define dr_fabs(A) fabs(A)
#define dr_ceil(A) ceil(A)
#define dr_log(A) log(A)
#define dr_exp(A) exp(A)
#endif


#undef true
#undef false

#ifndef __cplusplus
typedef enum qboolean_e {false, true} qboolean;
#else
typedef bool qboolean;
#endif

#if defined(WIN32) && !defined(WIN64)
# define ssize_t long
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef FALSE
#define FALSE false
#define TRUE true
#endif

// up / down
#define	PITCH	0

// left / right
#define	YAW		1

// fall over
#define	ROLL	2

#endif
