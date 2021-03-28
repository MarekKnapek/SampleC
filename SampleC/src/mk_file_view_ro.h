#ifndef INCLUDE_GUARD_MK_FILE_VIEW_RO
#define INCLUDE_GUARD_MK_FILE_VIEW_RO


#include "mk_file_mapping_ro.h"
#include "mk_types.h"


struct mk_file_view_ro_s
{
	void const* m_view;
};
typedef struct mk_file_view_ro_s mk_file_view_ro_t;


void mk_file_view_ro_construct(mk_file_view_ro_t* const self, mk_file_mapping_ro_t const* const file_mapping, mk_size_t const offset, mk_size_t const size);
void mk_file_view_ro_destroy(mk_file_view_ro_t* const self);

mk_bool_t mk_file_view_ro_ok(mk_file_view_ro_t const* const self);


#endif
