#include "mk_types.h"

#include "mk_assert.h"


mk_bool_t mk_to_bool_t(int const val)
{
	MK_ASSERT(val == 0 || val == 1);
	if(val == 0)
	{
		return MK_FALSE;
	}
	else
	{
		return MK_TRUE;
	}
}
