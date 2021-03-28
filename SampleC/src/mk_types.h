#ifndef INCLUDE_GUARD_MK_TYPES
#define INCLUDE_GUARD_MK_TYPES


#include "mk_macros.h"


#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386
	typedef int mk_ptrdiff_t;
#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64
	typedef __int64 mk_ptrdiff_t;
#endif

#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386
	typedef unsigned int mk_size_t;
#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64
	typedef unsigned __int64 mk_size_t;
#endif


typedef signed char mk_bool_t;
#define MK_FALSE ((mk_bool_t)0)
#define MK_TRUE ((mk_bool_t)1)


#endif
