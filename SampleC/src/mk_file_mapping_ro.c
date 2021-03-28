#include "mk_file_mapping_ro.h"

#include "mk_assert.h"
#include "mk_win_kernel.h"


void mk_file_mapping_ro_construct(mk_file_mapping_ro_t* const self, mk_file_ro_t const* const file)
{
	mk_win_dword_t file_size_hi;
	mk_win_dword_t file_size_lo;
	mk_win_dword_t err;
	mk_win_dword_t mapping_size_hi;
	mk_win_dword_t mapping_size_lo;
	mk_win_handle_t file_mapping;

	file_size_lo = mk_win_kernel_get_file_size(file->m_handle, &file_size_hi);
	if(file_size_lo.m_value == MK_WIN_KERNEL_INVALID_FILE_SIZE)
	{
		err = mk_win_kernel_get_last_error();
		if(err.m_value != 0)
		{
			self->m_handle.m_value = MK_NULL;
			return;
		}
	}

	if(file_size_lo.m_value == 0 && file_size_hi.m_value == 0)
	{
		self->m_handle.m_value = MK_NULL;
		return;
	}

	mapping_size_hi.m_value = 0;
	mapping_size_lo.m_value = 0;
	file_mapping = mk_win_kernel_create_file_mapping(file->m_handle, MK_NULL, mk_win_kernel_page_protect_readonly, mapping_size_hi, mapping_size_lo, MK_NULL);
	self->m_handle = file_mapping;
}

void mk_file_mapping_ro_destroy(mk_file_mapping_ro_t* const self)
{
	mk_bool_t freed;

	if(!mk_file_mapping_ro_ok(self))
	{
		return;
	}
	freed = mk_win_kernel_close_handle(self->m_handle);
	MK_ASSERT(freed);
}


mk_bool_t mk_file_mapping_ro_ok(mk_file_mapping_ro_t const* const self)
{
	mk_bool_t ret;

	ret = self->m_handle.m_value != MK_NULL ? MK_TRUE : MK_FALSE;
	return ret;
}
