#include "mk_allocator.h"

#include "mk_allocator_heap.h"
#include "mk_allocator_heap_mt.h"
#include "mk_allocator_process_heap.h"


void mk_allocator_construct(mk_allocator_t* const self, void* const allocator, mk_allocator_id_t const allocator_id)
{
	self->m_allocator = allocator;
	self->m_allocator_id = allocator_id;
}

void mk_allocator_destroy(mk_allocator_t* const self)
{
	MK_UNREFERENCED(self);
}


void* mk_allocator_allocate(mk_allocator_t* const self, mk_size_t const len, mk_size_t* const real_len)
{
	void* ret;

	switch(self->m_allocator_id)
	{
		case mk_allocator_id_heap:
		{
			ret = mk_allocator_heap_allocate((mk_allocator_heap_t*)self->m_allocator, len, real_len);
		}
		break;
		case mk_allocator_id_heap_mt:
		{
			ret = mk_allocator_heap_mt_allocate((mk_allocator_heap_mt_t*)self->m_allocator, len, real_len);
		}
		break;
		case mk_allocator_id_process_heap:
		{
			ret = mk_allocator_process_heap_allocate((mk_allocator_process_heap_t*)self->m_allocator, len, real_len);
		}
		break;
		default:
		{
			MK_UNREACHABLE;
		}
		break;
	}

	return ret;
}

void* mk_allocator_reallocate_inplace(mk_allocator_t* const self, void* const ptr, mk_size_t const len)
{
	void* ret;

	switch(self->m_allocator_id)
	{
		case mk_allocator_id_heap:
		{
			ret = mk_allocator_heap_reallocate_inplace((mk_allocator_heap_t*)self->m_allocator, ptr, len);
		}
		break;
		case mk_allocator_id_heap_mt:
		{
			ret = mk_allocator_heap_mt_reallocate_inplace((mk_allocator_heap_mt_t*)self->m_allocator, ptr, len);
		}
		break;
		case mk_allocator_id_process_heap:
		{
			ret = mk_allocator_process_heap_reallocate_inplace((mk_allocator_process_heap_t*)self->m_allocator, ptr, len);
		}
		break;
		default:
		{
			MK_UNREACHABLE;
		}
		break;
	}

	return ret;
}

void* mk_allocator_reallocate_copy(mk_allocator_t* const self, void* const ptr, mk_size_t const len)
{
	void* ret;

	switch(self->m_allocator_id)
	{
		case mk_allocator_id_heap:
		{
			ret = mk_allocator_heap_reallocate_copy((mk_allocator_heap_t*)self->m_allocator, ptr, len);
		}
		break;
		case mk_allocator_id_heap_mt:
		{
			ret = mk_allocator_heap_mt_reallocate_copy((mk_allocator_heap_mt_t*)self->m_allocator, ptr, len);
		}
		break;
		case mk_allocator_id_process_heap:
		{
			ret = mk_allocator_process_heap_reallocate_copy((mk_allocator_process_heap_t*)self->m_allocator, ptr, len);
		}
		break;
		default:
		{
			MK_UNREACHABLE;
		}
		break;
	}

	return ret;
}

void mk_allocator_deallocate(mk_allocator_t* const self, void* const ptr)
{
	switch(self->m_allocator_id)
	{
		case mk_allocator_id_heap:
		{
			mk_allocator_heap_deallocate((mk_allocator_heap_t*)self->m_allocator, ptr);
		}
		break;
		case mk_allocator_id_heap_mt:
		{
			mk_allocator_heap_mt_deallocate((mk_allocator_heap_mt_t*)self->m_allocator, ptr);
		}
		break;
		case mk_allocator_id_process_heap:
		{
			mk_allocator_process_heap_deallocate((mk_allocator_process_heap_t*)self->m_allocator, ptr);
		}
		break;
		default:
		{
			MK_UNREACHABLE;
		}
		break;
	}
}
