#ifndef INCLUDE_GUARD_MK_ALLOCATOR_HEAP_MT
#define INCLUDE_GUARD_MK_ALLOCATOR_HEAP_MT


#include "mk_windows.h"
#include "mk_types.h"


struct mk_allocator_heap_mt_s
{
	mk_win_handle_t m_heap;
};
typedef struct mk_allocator_heap_mt_s mk_allocator_heap_mt_t;


void mk_allocator_heap_mt_construct(mk_allocator_heap_mt_t* const self);
void mk_allocator_heap_mt_destroy(mk_allocator_heap_mt_t* const self);

void* mk_allocator_heap_mt_allocate(mk_allocator_heap_mt_t* const self, mk_size_t const len, mk_size_t* const real_len);
void* mk_allocator_heap_mt_reallocate_inplace(mk_allocator_heap_mt_t* const self, void* const ptr, mk_size_t const len);
void* mk_allocator_heap_mt_reallocate_copy(mk_allocator_heap_mt_t* const self, void* const ptr, mk_size_t const len);
void mk_allocator_heap_mt_deallocate(mk_allocator_heap_mt_t* const self, void* const ptr);


#endif
