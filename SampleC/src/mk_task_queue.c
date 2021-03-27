#include "mk_task_queue.h"


#define X mk_task_t
#include "mk_primitives_template.c"
#include "mk_vector_template.c"
#undef X


void mk_task_queue_construct(mk_task_queue_t* const self)
{
	mk_vector_mk_task_t_construct(&self->m_vec_1);
	mk_vector_mk_task_t_construct(&self->m_vec_2);
	self->m_idx = 0;
	mk_lock_critical_section_construct(&self->m_lock);
}

void mk_task_queue_destroy(mk_task_queue_t* const self)
{
	mk_lock_critical_section_destroy(&self->m_lock);
	mk_vector_mk_task_t_destroy(&self->m_vec_2);
	mk_vector_mk_task_t_destroy(&self->m_vec_1);
}

void mk_task_queue_add_task(mk_task_queue_t* const self, mk_task_t const task)
{
	mk_lock_critical_section_lock(&self->m_lock);
	mk_vector_mk_task_t_push_back(&self->m_vec_1, &task);
	mk_lock_critical_section_unlock(&self->m_lock);
}

mk_bool_t mk_task_queue_execute_task(mk_task_queue_t* const self)
{
	mk_task_t* task;

	if(self->m_idx < mk_vector_mk_task_t_size(&self->m_vec_2))
	{
		task = mk_vector_mk_task_t_at(&self->m_vec_2, self->m_idx);
		++self->m_idx;
		task->m_prc(task->m_ctx);
		return MK_TRUE;
	}
	mk_vector_mk_task_t_clear(&self->m_vec_2);
	mk_lock_critical_section_lock(&self->m_lock);
	mk_vector_mk_task_t_swap(&self->m_vec_2, &self->m_vec_1);
	mk_lock_critical_section_unlock(&self->m_lock);
	if(mk_vector_mk_task_t_is_empty(&self->m_vec_2))
	{
		return MK_FALSE;
	}
	task = mk_vector_mk_task_t_at(&self->m_vec_2, 0);
	self->m_idx = 1;
	task->m_prc(task->m_ctx);
	return MK_TRUE;
}
