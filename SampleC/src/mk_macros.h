#ifndef INCLUDE_GUARD_MK_MACROS
#define INCLUDE_GUARD_MK_MACROS


#define MK_ARCHITECTURE_I386 2
#define MK_ARCHITECTURE_AMD64 3

#ifdef _M_IX86
# define MK_ARCHITECTURE MK_ARCHITECTURE_I386
#else
# ifdef _M_X64
#  define MK_ARCHITECTURE MK_ARCHITECTURE_AMD64
# else
#  error Unknown architecture.
# endif
#endif


#define MK_NULL 0
#define MK_UNREFERENCED(X) (X) = (X)
#define MK_STATIC_ASSERT(X) { char arr[(X) ? 1 : 0]; (void)arr; }

#define MK_PASTE(A, B) A ## B
#define MK_CONCAT(A, B) MK_PASTE(A, B)
#define MK_CONCAT3(A, B, C) MK_CONCAT(A, MK_PASTE(B, C))


#endif
