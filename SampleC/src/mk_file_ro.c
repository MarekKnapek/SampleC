#include "mk_file_ro.h"

#include "mk_assert.h"
#include "mk_win_kernel.h"


void mk_file_ro_construct(mk_file_ro_t* const self, mk_win_widechar_t const* const file_name)
{
	mk_win_handle_t template_file;
	mk_win_handle_t file;

	template_file.m_value = MK_NULL;
	file = mk_win_kernel_create_file(file_name, mk_win_kernel_access_right_generic_read, mk_win_kernel_file_share_read, MK_NULL, mk_win_kernel_file_create_open_existing, mk_win_kernel_file_attribute_normal, template_file);
	self->m_handle = file;
}

void mk_file_ro_destroy(mk_file_ro_t* const self)
{
	mk_bool_t closed;

	if(!mk_file_ro_ok(self))
	{
		return;
	}
	closed = mk_win_kernel_close_handle(self->m_handle);
	MK_ASSERT(closed);
}


mk_bool_t mk_file_ro_ok(mk_file_ro_t const* const self)
{
	mk_bool_t ret;

	ret = self->m_handle.m_value != MK_WIN_KERNEL_INVALID_HANDLE_VALUE ? MK_TRUE : MK_FALSE;
	return ret;
}
