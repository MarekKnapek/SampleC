#include "mk_mem.h"

#include "mk_assert.h"


void mk_memzero(void* const ptr, mk_size_t const size)
{
	mk_size_t addr;
	mk_size_t align;
	mk_size_t bytes_before_align;
	mk_size_t n;
	unsigned char* ptr_small;
	mk_size_t i;
	mk_size_t remaining;
	mk_size_t* ptr_large;

	addr = (mk_size_t)ptr;
	align = sizeof(mk_size_t);
	bytes_before_align = (((addr - 1) / align) + 1) * align - addr;
	MK_ASSERT(bytes_before_align < align);

	n = bytes_before_align < size ? bytes_before_align : size;
	ptr_small = (unsigned char*)ptr;
	for(i = 0; i != n; ++i)
	{
		*ptr_small = (unsigned char)0;
		++ptr_small;
	}
	MK_ASSERT((mk_size_t)ptr_small % align == 0);
	remaining = size - n;

	n = remaining / align;
	ptr_large = (mk_size_t*)ptr_small;
	for(i = 0; i != n; ++i)
	{
		*ptr_large = (mk_size_t)0;
	}
	remaining -= n * align;
	MK_ASSERT(remaining < align);

	ptr_small = (unsigned char*)ptr_large;
	for(i = 0; i != remaining; ++i)
	{
		*ptr_small = (unsigned char)0;
	}
}
