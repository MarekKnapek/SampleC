#include "mk_lock_critical_section.h"


void mk_lock_critical_section_construct(mk_lock_critical_section_t* const self)
{
	mk_win_kernel_initialize_critical_section(&self->m_critical_section);
}

void mk_lock_critical_section_destroy(mk_lock_critical_section_t* const self)
{
	mk_win_kernel_delete_critical_section(&self->m_critical_section);
}

void mk_lock_critical_section_lock(mk_lock_critical_section_t* const self)
{
	mk_win_kernel_enter_critical_section(&self->m_critical_section);
}

void mk_lock_critical_section_unlock(mk_lock_critical_section_t* const self)
{
	mk_win_kernel_leave_critical_section(&self->m_critical_section);
}
