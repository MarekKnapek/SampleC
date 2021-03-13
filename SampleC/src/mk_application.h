#ifndef INCLUDE_GUARD_MK_APPLICATION
#define INCLUDE_GUARD_MK_APPLICATION


#include "mk_main_window.h"
#include "mk_windows.h"
#include "mk_task_queue.h"


struct mk_application_s
{
	mk_win_instance_t m_instance;
	mk_win_widechar_t const* m_cmd_line;
	int m_cmd_show;
	mk_task_queue_t m_idle_tasks;
	mk_main_window_t* m_main_window;
};
typedef struct mk_application_s mk_application_t;


mk_application_t* mk_application_get(void);
void mk_application_set(mk_application_t* const application);

void mk_application_construct(mk_application_t* const self, mk_win_instance_t const instance, mk_win_widechar_t const* const cmd_line, int const cmd_show);
void mk_application_destroy(mk_application_t* const self);

mk_win_instance_t mk_application_get_instance(mk_application_t const* const self);

int mk_application_run(mk_application_t* const self);
void mk_application_add_task(mk_application_t* const self, mk_task_t const task);

int mk_application_run_message_loop(mk_application_t* const self);
mk_bool_t mk_application_on_idle(mk_application_t* const self);


#endif
