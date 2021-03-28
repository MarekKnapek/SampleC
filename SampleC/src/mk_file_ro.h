#ifndef INCLUDE_GUARD_MK_FILE_RO
#define INCLUDE_GUARD_MK_FILE_RO


#include "mk_types.h"
#include "mk_windows.h"


struct mk_file_ro_s
{
	mk_win_handle_t m_handle;
};
typedef struct mk_file_ro_s mk_file_ro_t;


void mk_file_ro_construct(mk_file_ro_t* const self, mk_win_widechar_t const* const file_name);
void mk_file_ro_destroy(mk_file_ro_t* const self);

mk_bool_t mk_file_ro_ok(mk_file_ro_t const* const self);


#endif
