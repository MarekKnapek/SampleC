#ifndef INCLUDE_GUARD_MK_TASK_QUEUE
#define INCLUDE_GUARD_MK_TASK_QUEUE


#include "mk_macros.h"
#include "mk_types.h"
#include "mk_lock_critical_section.h"


struct mk_task_s
{
	void(*m_prc)(void* const);
	void* m_ctx;
};
typedef struct mk_task_s mk_task_t;


#define X mk_task_t
#include "mk_primitives_template.h"
#include "mk_vector_template.h"
#undef X


struct mk_task_queue_s
{
	mk_vector_mk_task_t_t m_vec_1;
	mk_vector_mk_task_t_t m_vec_2;
	mk_size_t m_idx;
	mk_lock_critical_section_t m_lock;
};
typedef struct mk_task_queue_s mk_task_queue_t;


void mk_task_queue_construct(mk_task_queue_t* const self);
void mk_task_queue_destroy(mk_task_queue_t* const self);
void mk_task_queue_add_task(mk_task_queue_t* const self, mk_task_t const task);
mk_bool_t mk_task_queue_execute_task(mk_task_queue_t* const self);


#endif
