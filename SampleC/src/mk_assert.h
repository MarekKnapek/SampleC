#ifndef INCLUDE_GUARD_MK_ASSERT
#define INCLUDE_GUARD_MK_ASSERT


extern __declspec(dllimport) void __cdecl _assert(char const*, char const*, unsigned);


#ifdef NDEBUG
#define MK_ASSERT(X) ((void)0)
#else
#define MK_ASSERT(X) (void)((X) || (_assert(#X, __FILE__, __LINE__), 0))
#endif

#endif
