#ifndef INCLUDE_GUARD_MK_ASSERT
#define INCLUDE_GUARD_MK_ASSERT


void mk_crash(void);


#ifdef NDEBUG
#define MK_ASSERT(X) ((void)0)
#else
#define MK_ASSERT(X) ((void)((X) || (mk_crash(), 0)))
#endif


#endif
