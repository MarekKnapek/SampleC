#ifndef INCLUDE_GUARD_MK_LOCK_CRITICAL_SECTION
#define INCLUDE_GUARD_MK_LOCK_CRITICAL_SECTION


#include "mk_win_kernel.h"


struct mk_lock_critical_section_s
{
	mk_win_kernel_critical_section_t m_critical_section;
};
typedef struct mk_lock_critical_section_s mk_lock_critical_section_t;


void mk_lock_critical_section_construct(mk_lock_critical_section_t* const self);
void mk_lock_critical_section_destroy(mk_lock_critical_section_t* const self);
void mk_lock_critical_section_lock(mk_lock_critical_section_t* const self);
void mk_lock_critical_section_unlock(mk_lock_critical_section_t* const self);


#endif
