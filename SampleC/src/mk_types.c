#include "mk_types.h"


void mk_size_t_split(mk_size_t const size, unsigned* const hi, unsigned* const lo)
{
#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386
	*hi = 0;
	*lo = size;
#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64
	*hi = (size >> 32) & 0xFFFFFFFF;
	*lo = size & 0xFFFFFFFF;
#endif
}
