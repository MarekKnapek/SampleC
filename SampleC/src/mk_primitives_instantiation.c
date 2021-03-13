#include "mk_primitives_instantiation.h"


#include "mk_macros.h"


#define X int
#include "mk_primitives_template.c"
#undef X

#define X long
#include "mk_primitives_template.c"
#undef X
