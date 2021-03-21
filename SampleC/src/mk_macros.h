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


#ifdef __cplusplus
# define MK_C "C"
#else
# define MK_C
#endif


#define MK_NULL 0
#define MK_UNREFERENCED(X) (X) = (X)
#define MK_STATIC_ASSERT(X) { char arr[(X) ? 1 : 0]; (void)arr; }

#define MK_PASTE(A, B) A ## _ ## B
#define MK_CONCAT(A, B) MK_PASTE(A, B)
#define MK_CONCAT3(A, B, C) MK_CONCAT(A, MK_PASTE(B, C))
#define MK_CONCAT4(A, B, C, D) MK_CONCAT(A, MK_CONCAT(B, MK_PASTE(C, D)))
#define MK_CONCAT5(A, B, C, D, E) MK_CONCAT(A, MK_CONCAT(B, MK_CONCAT(C, MK_PASTE(D, E))))
#define MK_CONCAT6(A, B, C, D, E, F) MK_CONCAT(A, MK_CONCAT(B, MK_CONCAT(C, MK_CONCAT(D, MK_PASTE(E, F)))))
#define MK_CONCAT7(A, B, C, D, E, F, G) MK_CONCAT(A, MK_CONCAT(B, MK_CONCAT(C, MK_CONCAT(D, MK_CONCAT(E, MK_PASTE(F, G))))))
#define MK_CONCAT8(A, B, C, D, E, F, G, H) MK_CONCAT(A, MK_CONCAT(B, MK_CONCAT(C, MK_CONCAT(D, MK_CONCAT(E, MK_CONCAT(F, MK_PASTE(G, H)))))))
#define MK_CONCAT9(A, B, C, D, E, F, G, H, I) MK_CONCAT(A, MK_CONCAT(B, MK_CONCAT(C, MK_CONCAT(D, MK_CONCAT(E, MK_CONCAT(F, MK_CONCAT(G, MK_PASTE(H, I))))))))
#define MK_CONCAT10(A, B, C, D, E, F, G, H, I, J) MK_CONCAT(A, MK_CONCAT(B, MK_CONCAT(C, MK_CONCAT(D, MK_CONCAT(E, MK_CONCAT(F, MK_CONCAT(G, MK_CONCAT(H, MK_PASTE(I, J)))))))))


#endif
