#ifndef INCLUDE_GUARD_MK_MAIN_WINDOW
#define INCLUDE_GUARD_MK_MAIN_WINDOW


#include "mk_win_user.h"


struct mk_main_window_s
{
	mk_win_user_hwnd_t m_hwnd;
};
typedef struct mk_main_window_s mk_main_window_t;

mk_win_user_atom_t mk_main_window_get_atom(void);
void mk_main_window_register_class(void);
void mk_main_window_unregister_class(void);
mk_win_user_lresult_t __stdcall mk_main_window_window_procedure_static(mk_win_user_hwnd_t const hwnd, mk_win_uint_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam);

void mk_main_window_construct(mk_main_window_t* const self);
void mk_main_window_destroy(mk_main_window_t* const self);
mk_win_user_hwnd_t mk_main_window_get_hwnd(mk_main_window_t const* const self);
mk_win_user_lresult_t mk_main_window_window_procedure(mk_main_window_t* const self, mk_win_uint_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam);


#endif
