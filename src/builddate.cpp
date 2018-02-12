
#if !defined(DEBUG_DREAMPLACES) && !defined(PROFILER_DREAMPLACES) && !defined(MAX_AUTOEVENTS) && !defined(DEBUG_GL)
char *buildstring = __TIME__ " " __DATE__;
#else
char *buildstring = "--";
#endif

