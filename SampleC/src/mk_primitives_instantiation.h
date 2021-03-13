#ifndef INCLUDE_GUARD_MK_PRIMITIVES_INSTANTIATION
#define INCLUDE_GUARD_MK_PRIMITIVES_INSTANTIATION


#include "mk_macros.h"


#define X int
#include "mk_primitives_template.h"
#undef X

#define X long
#include "mk_primitives_template.h"
#undef X


#endif
