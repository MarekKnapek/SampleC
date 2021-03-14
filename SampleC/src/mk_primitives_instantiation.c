#include "mk_primitives_instantiation.h"


#define X int
#include "mk_primitives_template.c"
#undef X

#define X mk_sint32_t
#include "mk_primitives_template.c"
#undef X

#define X mk_uint32_t
#include "mk_primitives_template.c"
#undef X

#define X long
#include "mk_primitives_template.c"
#undef X
