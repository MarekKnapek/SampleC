#ifndef INCLUDE_GUARD_MK_ALLOCATOR_GLOBAL
#define INCLUDE_GUARD_MK_ALLOCATOR_GLOBAL


#include "mk_types.h"
#include "mk_allocator.h"


void mk_allocator_global_init(void);
void mk_allocator_global_deinit(void);

void* mk_allocator_global_allocate(mk_size_t const len, mk_size_t* const real_len);
void* mk_allocator_global_reallocate_inplace(void* const ptr, mk_size_t const len);
void* mk_allocator_global_reallocate_copy(void* const ptr, mk_size_t const len);
void mk_allocator_global_deallocate(void* const ptr);


#endif
