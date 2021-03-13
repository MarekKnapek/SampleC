#include "mk_macros.h"

#include "mk_mem.h"


void MK_CONCAT(X, _construct)(X* const self)
{
	X x;

	mk_memzero(&x, sizeof(x));
	*self = x;
}

void MK_CONCAT(X, _copy_construct)(X* const self, X const* const other)
{
	*self = *other;
}

void MK_CONCAT(X, _move_construct)(X* const self, X* const other)
{
	*self = *other;
}

void MK_CONCAT(X, _destroy)(X* const self)
{
}
