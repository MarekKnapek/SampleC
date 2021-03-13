#include "mk_vector_instantiation.h"


#include "mk_macros.h"


#define X int
#include "mk_primitives_template.h"
#include "mk_vector_template.c"
#undef X

#define X long
#include "mk_primitives_template.h"
#include "mk_vector_template.c"
#undef X
