#include "mk_allocator_heap_mt.h"

#include "mk_win_kernel.h"
#include "mk_assert.h"


void mk_allocator_heap_mt_construct(mk_allocator_heap_mt_t* const self)
{
	mk_win_handle_t heap;

	heap = mk_win_kernel_heap_create(mk_win_kernel_heap_create_generate_exceptions, 0, 0);
	MK_ASSERT(heap.m_value != MK_NULL);

	self->m_heap = heap;
}

void mk_allocator_heap_mt_destroy(mk_allocator_heap_mt_t* const self)
{
	mk_bool_t destroyed;

	destroyed = mk_win_kernel_heap_destroy(self->m_heap);
	MK_ASSERT(destroyed == MK_TRUE);
}


void* mk_allocator_heap_mt_allocate(mk_allocator_heap_mt_t* const self, mk_size_t const len, mk_size_t* const real_len)
{
	void* ret;

	ret = mk_win_kernel_heap_alloc(self->m_heap, mk_win_kernel_heap_alloc_generate_exceptions, len);
	MK_ASSERT(ret);
	*real_len = mk_win_kernel_heap_size(self->m_heap, (mk_win_kernel_heap_size_t)0, ret);
	MK_ASSERT(*real_len != (mk_size_t)-1);

	return ret;
}

void* mk_allocator_heap_mt_reallocate_inplace(mk_allocator_heap_mt_t* const self, void* const ptr, mk_size_t const len)
{
	void* ret;

	ret = mk_win_kernel_heap_realloc(self->m_heap, mk_win_kernel_heap_realloc_realloc_in_place_only, ptr, len);
	MK_ASSERT(!ret || ret == ptr);
	return ret;
}

void* mk_allocator_heap_mt_reallocate_copy(mk_allocator_heap_mt_t* const self, void* const ptr, mk_size_t const len)
{
	void* ret;

	ret = mk_win_kernel_heap_realloc(self->m_heap, mk_win_kernel_heap_realloc_generate_exceptions, ptr, len);
	MK_ASSERT(ret);
	return ret;
}

void mk_allocator_heap_mt_deallocate(mk_allocator_heap_mt_t* const self, void* const ptr)
{
	mk_bool_t freed;

	freed = mk_win_kernel_heap_free(self->m_heap, (mk_win_kernel_heap_free_t)0, ptr);
	MK_ASSERT(freed == MK_TRUE);
}
