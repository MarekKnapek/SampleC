#ifndef INCLUDE_GUARD_MK_ALLOCATOR
#define INCLUDE_GUARD_MK_ALLOCATOR


#include "mk_types.h"


enum mk_allocator_id_e
{
	mk_allocator_id_heap,
	mk_allocator_id_heap_mt,
};
typedef enum mk_allocator_id_e mk_allocator_id_t;


struct mk_allocator_s
{
	void* m_allocator;
	mk_allocator_id_t m_allocator_id;
};
typedef struct mk_allocator_s mk_allocator_t;


void mk_allocator_construct(mk_allocator_t* const self, void* const allocator, mk_allocator_id_t const allocator_id);
void mk_allocator_destroy(mk_allocator_t* const self);
void* mk_allocator_allocate(mk_allocator_t* const self, mk_size_t const len, mk_size_t* const real_len);
void* mk_allocator_reallocate_inplace(mk_allocator_t* const self, void* const ptr, mk_size_t const len);
void* mk_allocator_reallocate_copy(mk_allocator_t* const self, void* const ptr, mk_size_t const len);
void mk_allocator_deallocate(mk_allocator_t* const self, void* const ptr);


#endif
