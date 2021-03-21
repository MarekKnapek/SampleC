#ifndef INCLUDE_GUARD_MK_MATH
#define INCLUDE_GUARD_MK_MATH


#include "mk_check_ret.h"


#define MK_GCD(A, B) (((A) < (B)) ? (MK_GCD_IMPL_1((B), (A))) : (MK_GCD_IMPL_1((A), (B))))

#define MK_GCD_IMPL_1(A, B) (((B) == 0) ? (A) : (MK_GCD_IMPL_2((B), ((A) % ((B) + !(B))))))
#define MK_GCD_IMPL_2(A, B) (((B) == 0) ? (A) : (MK_GCD_IMPL_3((B), ((A) % ((B) + !(B))))))
#define MK_GCD_IMPL_3(A, B) (((B) == 0) ? (A) : (MK_GCD_IMPL_4((B), ((A) % ((B) + !(B))))))
#define MK_GCD_IMPL_4(A, B) (((B) == 0) ? (A) : (MK_GCD_IMPL_5((B), ((A) % ((B) + !(B))))))
#define MK_GCD_IMPL_5(A, B) (((B) == 0) ? (A) : (MK_GCD_IMPL_6((B), ((A) % ((B) + !(B))))))
#define MK_GCD_IMPL_6(A, B) (((B) == 0) ? (A) : (MK_GCD_IMPL_7((B), ((A) % ((B) + !(B))))))
#define MK_GCD_IMPL_7(A, B) ((mk_crash(), -1))


#define MK_REDUCE_FRACTION_A(A, B) ((A) / (MK_GCD((A), (B))))
#define MK_REDUCE_FRACTION_B(A, B) ((B) / (MK_GCD((A), (B))))


#endif
