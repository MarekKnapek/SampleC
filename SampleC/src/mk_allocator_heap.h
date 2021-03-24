#ifndef INCLUDE_GUARD_MK_ALLOCATOR_HEAP
#define INCLUDE_GUARD_MK_ALLOCATOR_HEAP


#include "mk_windows.h"
#include "mk_types.h"


struct mk_allocator_heap_s
{
	mk_win_handle_t m_heap;
};
typedef struct mk_allocator_heap_s mk_allocator_heap_t;


void mk_allocator_heap_construct(mk_allocator_heap_t* const self);
void mk_allocator_heap_destroy(mk_allocator_heap_t* const self);

void* mk_allocator_heap_allocate(mk_allocator_heap_t* const self, mk_size_t const len, mk_size_t* const real_len);
void* mk_allocator_heap_reallocate_inplace(mk_allocator_heap_t* const self, void* const ptr, mk_size_t const len);
void* mk_allocator_heap_reallocate_copy(mk_allocator_heap_t* const self, void* const ptr, mk_size_t const len);
void mk_allocator_heap_deallocate(mk_allocator_heap_t* const self, void* const ptr);


#endif
