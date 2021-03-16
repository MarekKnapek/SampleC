#ifndef INCLUDE_GUARD_MK_APPLICATION
#define INCLUDE_GUARD_MK_APPLICATION


#include "mk_main_window.h"
#include "mk_task_queue.h"
#include "mk_windows.h"


#define MK_T1 mk_uint32_t
#define MK_T2 2000
#define MK_T3 250
#define MK_T4 1000
#include "mk_counter_template.h"
#undef MK_T3
#undef MK_T2
#undef MK_T1



struct mk_application_s
{
	mk_win_instance_t m_instance;
	mk_win_widechar_t const* m_cmd_line;
	int m_cmd_show;
	mk_task_queue_t m_idle_tasks;
	mk_main_window_t* m_main_window;
	mk_counter_mk_uint32_t_2000_250_1000_t m_counter;
};
typedef struct mk_application_s mk_application_t;


mk_application_t* mk_application_get(void);
void mk_application_set(mk_application_t* const application);
void __stdcall mk_application_timer_proc(mk_win_user_hwnd_t const hwnd, mk_win_uint_t const msg, mk_size_t const id, mk_win_dword_t const time);

void mk_application_construct(mk_application_t* const self, mk_win_instance_t const instance, mk_win_widechar_t const* const cmd_line, int const cmd_show);
void mk_application_destroy(mk_application_t* const self);

mk_win_instance_t mk_application_get_instance(mk_application_t const* const self);

int mk_application_run(mk_application_t* const self);
void mk_application_add_task(mk_application_t* const self, mk_task_t const task);

int mk_application_run_message_loop(mk_application_t* const self);
mk_bool_t mk_application_on_idle(mk_application_t* const self);


#endif
