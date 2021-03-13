#include "mk_allocator_global.h"

#include "mk_allocator_heap_mt.h"


static mk_allocator_heap_mt_t mk_allocator_global_g;


void mk_allocator_global_init(void)
{
	mk_allocator_heap_mt_construct(&mk_allocator_global_g);
}

void mk_allocator_global_deinit(void)
{
	mk_allocator_heap_mt_destroy(&mk_allocator_global_g);
}

mk_allocator_t mk_allocator_global_get(void)
{
	mk_allocator_t ret;
	mk_allocator_construct(&ret, &mk_allocator_global_g, mk_allocator_id_heap_mt);
	return ret;
}


void* mk_allocator_global_allocate(mk_size_t const len, mk_size_t* const real_len)
{
	mk_allocator_t allocator;
	void* ret;

	allocator = mk_allocator_global_get();
	ret = mk_allocator_allocate(&allocator, len, real_len);
	return ret;
}

void* mk_allocator_global_reallocate_inplace(void* const ptr, mk_size_t const len)
{
	mk_allocator_t allocator;
	void* ret;

	allocator = mk_allocator_global_get();
	ret = mk_allocator_reallocate_inplace(&allocator, ptr, len);
	return ret;
}

void* mk_allocator_global_reallocate_copy(void* const ptr, mk_size_t const len)
{
	mk_allocator_t allocator;
	void* ret;

	allocator = mk_allocator_global_get();
	ret = mk_allocator_reallocate_copy(&allocator, ptr, len);
	return ret;
}

void mk_allocator_global_deallocate(void* const ptr)
{
	mk_allocator_t allocator;

	allocator = mk_allocator_global_get();
	mk_allocator_deallocate(&allocator, ptr);
}
