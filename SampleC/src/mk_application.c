#include "mk_application.h"

#include "mk_win_user.h"
#include "mk_win_kernel.h"
#include "mk_check_ret.h"
#include "mk_assert.h"


static mk_application_t* mk_application_g_application;


mk_application_t* mk_application_get(void)
{
	return mk_application_g_application;
}

void mk_application_set(mk_application_t* const application)
{
	mk_application_g_application = application;
}


void mk_application_construct(mk_application_t* const self, mk_win_instance_t const instance, mk_win_widechar_t const* const cmd_line, int const cmd_show)
{
	self->m_instance = instance;
	self->m_cmd_line = cmd_line;
	self->m_cmd_show = cmd_show;
	mk_task_queue_construct(&self->m_idle_tasks);
	self->m_main_window = MK_NULL;
}

void mk_application_destroy(mk_application_t* const self)
{
	mk_task_queue_destroy(&self->m_idle_tasks);
}


mk_win_instance_t mk_application_get_instance(mk_application_t const* const self)
{
	return self->m_instance;
}


int mk_application_run(mk_application_t* const self)
{
	mk_main_window_t main_window;
	int exit_code;

	mk_main_window_register_class();
	mk_main_window_construct(&main_window);
	self->m_main_window = &main_window;
	mk_win_user_show_window(mk_main_window_get_hwnd(&main_window), self->m_cmd_show);

	exit_code = mk_application_run_message_loop(self);

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
