#include "mk_allocator_process_heap.h"

#include "mk_win_kernel.h"
#include "mk_check_ret.h"
#include "mk_assert.h"


void mk_allocator_process_heap_construct(mk_allocator_process_heap_t* const self)
{
	mk_win_handle_t heap;

	heap = mk_win_kernel_get_process_heap();
	MK_ASSERT(heap.m_value);

	self->m_heap = heap;
}

void mk_allocator_process_heap_destroy(mk_allocator_process_heap_t* const self)
{
}

mk_win_handle_t mk_allocator_process_heap_get_handle(mk_allocator_process_heap_t const* const self)
{
	return self->m_heap;
}

void* mk_allocator_process_heap_allocate(mk_allocator_process_heap_t* const self, mk_size_t const len, mk_size_t* const real_len)
{
	void* ret;

	ret = mk_win_kernel_heap_alloc(self->m_heap, mk_win_kernel_heap_alloc_generate_exceptions, len);
	MK_ASSERT(ret);
	*real_len = mk_win_kernel_heap_size(self->m_heap, (mk_win_kernel_heap_size_t)0, ret);
	MK_ASSERT(*real_len != (mk_size_t)-1);

	return ret;
}

void* mk_allocator_process_heap_reallocate_inplace(mk_allocator_process_heap_t* const self, void* const ptr, mk_size_t const len)
{
	void* ret;

	ret = mk_win_kernel_heap_realloc(self->m_heap, mk_win_kernel_heap_realloc_realloc_in_place_only, ptr, len);
	MK_ASSERT(!ret || ret == ptr);
	return ret;
}

void* mk_allocator_process_heap_reallocate_copy(mk_allocator_process_heap_t* const self, void* const ptr, mk_size_t const len)
{
	void* ret;

	ret = mk_win_kernel_heap_realloc(self->m_heap, mk_win_kernel_heap_realloc_generate_exceptions, ptr, len);
	MK_ASSERT(ret);
	return ret;
}

void mk_allocator_process_heap_deallocate(mk_allocator_process_heap_t* const self, void* const ptr)
{
	mk_bool_t freed;

	freed = mk_win_kernel_heap_free(self->m_heap, (mk_win_kernel_heap_free_t)0, ptr);
	MK_ASSERT(freed == MK_TRUE);
}
