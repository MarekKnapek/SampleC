#include "mk_allocator_global.h"
#include "mk_application.h"
#include "mk_win_kernel.h"
#include "mk_win_user.h"
#include "mk_windows.h"


int __stdcall WinMain(mk_win_instance_t const instance, mk_win_instance_t const prev_instance, mk_win_widechar_t const* const cmd_line, int const cmd_show)
{
	mk_application_t application;
	int exit_code;

	mk_allocator_global_init();
	mk_application_construct(&application, instance, cmd_line, cmd_show);
	mk_application_set(&application);
	exit_code = mk_application_run(&application);
	mk_application_destroy(&application);
	mk_allocator_global_deinit();

	return exit_code;
}
