#include "mk_file_view_ro.h"

#include "mk_assert.h"
#include "mk_win_kernel.h"


void mk_file_view_ro_construct(mk_file_view_ro_t* const self, mk_file_mapping_ro_t const* const file_mapping, mk_size_t const offset, mk_size_t const size)
{
	mk_win_dword_t offset_hi;
	mk_win_dword_t offset_lo;
	void const* ret;

	mk_size_t_split(offset, &offset_hi.m_value, &offset_lo.m_value);
	ret = mk_win_kernel_map_view_of_file(file_mapping->m_handle, mk_win_kernel_file_map_read, offset_hi, offset_lo, size);
	self->m_view = ret;
}

void mk_file_view_ro_destroy(mk_file_view_ro_t* const self)
{
	mk_bool_t unmapped;

	if(!mk_file_view_ro_ok(self))
	{
		return;
	}
	unmapped = mk_win_kernel_unmap_view_of_file(self->m_view);
	MK_ASSERT(unmapped);
}


mk_bool_t mk_file_view_ro_ok(mk_file_view_ro_t const* const self)
{
	mk_bool_t ret;

	ret = self->m_view == MK_NULL ? MK_TRUE : MK_FALSE;
	return ret;
}
