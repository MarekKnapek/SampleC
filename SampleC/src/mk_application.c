#include "mk_application.h"

#include "mk_assert.h"
#include "mk_charconv.h"
#include "mk_check_ret.h"
#include "mk_ints.h"
#include "mk_win_kernel.h"
#include "mk_win_user.h"


#define MK_T_TYPE mk_uint32_t
#define MK_T_DURATION 2000
#define MK_T_PRECISION 250
#define MK_T_UNIT 1000
#include "mk_counter_template.c"
#undef MK_T_UNIT
#undef MK_T_PRECISION
#undef MK_T_DURATION
#undef MK_T_TYPE


static mk_application_t* mk_application_g_application;


mk_application_t* mk_application_get(void)
{
	return mk_application_g_application;
}

void mk_application_set(mk_application_t* const application)
{
	mk_application_g_application = application;
}

void __stdcall mk_application_timer_proc(mk_win_user_hwnd_t const hwnd, mk_win_uint_t const msg, mk_size_t const id, mk_win_dword_t const time)
{
	mk_win_dword_t curr_time;
	mk_uint32_t msgs_per_second;
	char buffer[12 + 3];
	char* end;

	MK_UNREFERENCED(hwnd);
	MK_UNREFERENCED(msg);
	MK_UNREFERENCED(id);
	MK_UNREFERENCED(time);

	curr_time = mk_win_kernel_get_tick_count();
	msgs_per_second = mk_counter_mk_uint32_t_2000_250_1000_get_count(&mk_application_g_application->m_counter, curr_time.m_value);
	end = mk_to_chars_uint32(buffer, buffer + 12, msgs_per_second);
	end[0] = '\x0D';
	end[1] = '\x0A';
	end[2] = '\0';

	mk_win_kernel_output_debug_string(buffer);
}


void mk_application_construct(mk_application_t* const self, mk_win_instance_t const instance, mk_win_widechar_t const* const cmd_line, int const cmd_show)
{
	self->m_instance = instance;
	self->m_cmd_line = cmd_line;
	self->m_cmd_show = cmd_show;
	mk_task_queue_construct(&self->m_idle_tasks);
	self->m_main_window = MK_NULL;
	mk_counter_mk_uint32_t_2000_250_1000_construct(&self->m_counter);
}

void mk_application_destroy(mk_application_t* const self)
{
	mk_counter_mk_uint32_t_2000_250_1000_destroy(&self->m_counter);
	mk_task_queue_destroy(&self->m_idle_tasks);
}


mk_win_instance_t mk_application_get_instance(mk_application_t const* const self)
{
	return self->m_instance;
}


int mk_application_run(mk_application_t* const self)
{
	mk_win_user_hwnd_t const timer_hwnd = {MK_NULL};
	mk_win_uint_t const timer_elapse = {1000};
	mk_win_user_timer_proc_t const timer_proc = {&mk_application_timer_proc};

	mk_bool_t timer_killed;

	mk_main_window_t main_window;
	mk_size_t timer_id;
	int exit_code;

	mk_main_window_register_class();
	mk_main_window_construct(&main_window);
	self->m_main_window = &main_window;
	mk_win_user_show_window(mk_main_window_get_hwnd(&main_window), (mk_win_user_show_window_t)self->m_cmd_show);
	timer_id = mk_win_user_set_timer(timer_hwnd, 0, timer_elapse, timer_proc); MK_ASSERT(timer_id != 0);

	exit_code = mk_application_run_message_loop(self);

	timer_killed = mk_win_user_kill_timer(timer_hwnd, timer_id); MK_ASSERT(timer_killed);
	mk_main_window_destroy(&main_window);
	MK_ASSERT((self->m_main_window = MK_NULL, MK_TRUE));
	mk_main_window_unregister_class();

	return exit_code;
}

void mk_application_add_task(mk_application_t* const self, mk_task_t const task)
{
	mk_win_dword_t thread_id;
	mk_win_user_wparam_t wparam;
	mk_win_user_lparam_t lparam;
	mk_bool_t posted;

	mk_task_queue_add_task(&self->m_idle_tasks, task);

	thread_id = mk_win_kernel_get_current_thread_id();
	wparam.m_value = 0;
	lparam.m_value = 0;
	posted = mk_win_user_post_thread_message(thread_id, mk_win_user_wm_null, wparam, lparam);
	MK_ASSERT(posted == MK_TRUE);
}


int mk_application_run_message_loop(mk_application_t* const self)
{
	mk_win_user_hwnd_t const null_hwnd = {MK_NULL};
	mk_win_uint_t const filter_min = {0};
	mk_win_uint_t const filter_max = {0};

	mk_win_user_msg_t msg;
	mk_bool_t peeked;
	mk_win_dword_t curr_time;
	mk_bool_t translated;
	mk_win_user_lresult_t dispatched;
	mk_bool_t idled;
	mk_win_bool_t got;
	int exit_code;

	for(;;)
	{
		peeked = mk_win_user_peek_message(&msg, null_hwnd, filter_min, filter_max, mk_win_user_peek_message_remove);
		if(peeked)
		{
			if(msg.m_msg.m_value == mk_win_user_wm_quit)
			{
				break;
			}
			translate:
			curr_time = mk_win_kernel_get_tick_count();
			mk_counter_mk_uint32_t_2000_250_1000_count(&self->m_counter, curr_time.m_value, 1);
			translated = mk_win_user_translate_message(&msg);
			dispatched = mk_win_user_dispatch_message(&msg);
		}
		else
		{
			idled = mk_application_on_idle(self);
			if(idled)
			{
				continue;
			}
			else
			{
				got = mk_win_user_get_message(&msg, null_hwnd, filter_min, filter_max);
				if(got.m_value == 0)
				{
					break;
				}
				goto translate;
			}
		}
	}
	while(mk_application_on_idle(self))
	{
	};
	exit_code = (int)msg.m_wparam.m_value;
	return exit_code;
}

mk_bool_t mk_application_on_idle(mk_application_t* const self)
{
	mk_bool_t ret;

	ret = mk_task_queue_execute_task(&self->m_idle_tasks);
	return ret;
}
