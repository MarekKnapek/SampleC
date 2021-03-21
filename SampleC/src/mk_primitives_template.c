#include "mk_macros.h"

#include "mk_mem.h"


void MK_CONCAT(X, construct)(X* const self)
{
	X x;

	mk_memzero(&x, sizeof(x));
	*self = x;
}

void MK_CONCAT(X, copy_construct)(X* const self, X const* const other)
{
	*self = *other;
}

void MK_CONCAT(X, move_construct)(X* const self, X* const other)
{
	*self = *other;
}

void MK_CONCAT(X, destroy)(X* const self)
{
}
