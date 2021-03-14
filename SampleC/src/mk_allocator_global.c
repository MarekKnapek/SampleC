#include "mk_allocator_global.h"

#include "mk_allocator_process_heap.h"


static mk_allocator_process_heap_t mk_allocator_global_g;


void mk_allocator_global_init(void)
{
	mk_allocator_process_heap_construct(&mk_allocator_global_g);
}

void mk_allocator_global_deinit(void)
{
	mk_allocator_process_heap_destroy(&mk_allocator_global_g);
}

void* mk_allocator_global_allocate(mk_size_t const len, mk_size_t* const real_len)
{
	void* ret;

	ret = mk_allocator_process_heap_allocate(&mk_allocator_global_g, len, real_len);
	return ret;
}

void* mk_allocator_global_reallocate_inplace(void* const ptr, mk_size_t const len)
{
	void* ret;

	ret = mk_allocator_process_heap_reallocate_inplace(&mk_allocator_global_g, ptr, len);
	return ret;
}

void* mk_allocator_global_reallocate_copy(void* const ptr, mk_size_t const len)
{
	void* ret;

	ret = mk_allocator_process_heap_reallocate_copy(&mk_allocator_global_g, ptr, len);
	return ret;
}

void mk_allocator_global_deallocate(void* const ptr)
{
	mk_allocator_process_heap_deallocate(&mk_allocator_global_g, ptr);
}
