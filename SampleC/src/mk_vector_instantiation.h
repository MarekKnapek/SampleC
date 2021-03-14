#ifndef INCLUDE_GUARD_MK_VECTOR_INSTANTIATION
#define INCLUDE_GUARD_MK_VECTOR_INSTANTIATION


#include "mk_ints.h"
#include "mk_macros.h"


#define X int
#include "mk_vector_template.h"
#undef X

#define X mk_sint32_t
#include "mk_vector_template.h"
#undef X

#define X mk_uint32_t
#include "mk_vector_template.h"
#undef X

#define X long
#include "mk_vector_template.h"
#undef X


#endif
