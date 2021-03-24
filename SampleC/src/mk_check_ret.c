#include "mk_check_ret.h"

#include "mk_macros.h"
#include "mk_win_user.h"
#include "mk_win_kernel.h"
#include "mk_charconv.h"


void mk_report(int const line)
{
	char buffer[12];
	char* ptr;
	mk_win_user_hwnd_t hwnd;
	char const* text;
	char const* caption;
	mk_win_user_mb_t type;
	int msg;

	ptr = mk_to_chars_sint32(buffer, buffer + 12, line);
	*ptr = '\0';

	hwnd.m_value = MK_NULL;
	text = buffer;
	caption = "Surprise, Madafaka!";
	type = (mk_win_user_mb_t)(mk_win_user_mb_ok | mk_win_user_mb_iconerror);
	msg = mk_win_user_message_boxa(hwnd, text, caption, type);
}

void mk_crash(void)
{
	mk_win_handle_t current_process;
	mk_win_uint_t exit_code;
	mk_bool_t terminated;

	mk_win_kernel_debug_break();

	current_process = mk_win_kernel_get_current_process();
	exit_code.m_value = 1;
	terminated = mk_win_kernel_terminate_process(current_process, exit_code);
	MK_UNREFERENCED(terminated);
}
