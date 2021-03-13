#include "mk_main_window.h"

#include "mk_assert.h"
#include "mk_application.h"
#include "mk_check_ret.h"


static mk_win_user_atom_t mk_main_window_g_atom;


mk_win_user_atom_t mk_main_window_get_atom(void)
{
	return mk_main_window_g_atom;
}

void mk_main_window_register_class(void)
{
	mk_win_user_class_t wc;
	mk_win_user_atom_t atom;

	MK_ASSERT(mk_main_window_g_atom.m_value == 0);
	
	wc.m_style.m_value = 0;
	wc.m_window_procedure.m_value = &mk_main_window_window_procedure_static;
	wc.m_class_extra = 0;
	wc.m_object_extra = 0;
	wc.m_instance = mk_application_get_instance(mk_application_get());
	wc.m_icon = mk_win_user_load_icon(mk_win_user_icon_id_application);
	wc.m_cursor = mk_win_user_load_cursor(mk_win_user_cursor_id_arrow);
	wc.m_background = mk_win_user_get_brush(mk_win_user_brush_id_window);
	wc.m_menu_name = MK_NULL;
	wc.m_class_name = (mk_win_widechar_t const*)L"main_window";

	atom = mk_win_user_register_class(&wc);
	MK_CHECK_CRASH(atom.m_value != 0);
	mk_main_window_g_atom = atom;
}

void mk_main_window_unregister_class(void)
{
	mk_win_instance_t instance;
	mk_bool_t unregistered;

	MK_ASSERT(mk_main_window_g_atom.m_value != 0);

	instance = mk_application_get_instance(mk_application_get());

	unregistered = mk_win_user_unregister_class(mk_main_window_g_atom, instance);
	MK_CHECK_CRASH(unregistered);
}

mk_win_user_lresult_t __stdcall mk_main_window_window_procedure_static(mk_win_user_hwnd_t const hwnd, mk_win_uint_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam)
{
	mk_size_t user_data;
	mk_main_window_t* self;
	mk_win_user_lresult_t lresult;

	if(msg.m_value == mk_win_user_wm_create)
	{
		mk_win_user_wm_create_t* wc;
		void* context;
		mk_size_t old_user_data;

		wc = (mk_win_user_wm_create_t*)lparam.m_value;
		context = wc->m_context;
		self = (mk_main_window_t*)context;
		user_data = (mk_size_t)self;

		old_user_data = mk_win_user_set_window_long(hwnd, mk_win_user_window_long_userdata, user_data);
		MK_ASSERT(old_user_data == 0);
	}

	user_data = mk_win_user_get_window_long(hwnd, mk_win_user_window_long_userdata);
	if(user_data != 0)
	{
		self = (mk_main_window_t*)user_data;
		lresult = mk_main_window_window_procedure(self, msg, wparam, lparam);
		return lresult;
	}

	lresult = mk_win_user_def_window_proc(hwnd, msg, wparam, lparam);
	return lresult;
}


void mk_main_window_construct(mk_main_window_t* const self)
{
	mk_win_widechar_t const* class_name;
	mk_win_widechar_t const* name;
	mk_win_user_hwnd_t parent;
	mk_win_user_menu_t menu;
	mk_win_instance_t instance;
	mk_win_user_hwnd_t hwnd;

	class_name = (mk_win_widechar_t const*)(mk_size_t)mk_main_window_g_atom.m_value;
	name = (mk_win_widechar_t const*)L"Main Window";
	parent.m_value = MK_NULL;
	menu.m_value = MK_NULL;
	instance = mk_application_get_instance(mk_application_get());

	hwnd = mk_win_user_create_window
	(
		mk_win_user_window_style_ex_overlappedwindow,
		class_name,
		name,
		mk_win_user_window_style_overlappedwindow,
		mk_win_user_create_window_usedefault,
		mk_win_user_create_window_usedefault,
		mk_win_user_create_window_usedefault,
		mk_win_user_create_window_usedefault,
		parent,
		menu,
		instance,
		self
	);
	MK_CHECK_RET(hwnd.m_value != MK_NULL);

	self->m_hwnd = hwnd;
}

void mk_main_window_destroy(mk_main_window_t* const self)
{
}

mk_win_user_hwnd_t mk_main_window_get_hwnd(mk_main_window_t const* const self)
{
	return self->m_hwnd;
}

mk_win_user_lresult_t mk_main_window_window_procedure(mk_main_window_t* const self, mk_win_uint_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam)
{
	mk_win_user_lresult_t ret;

	switch(msg.m_value)
	{
		case mk_win_user_wm_destroy:
		{
			mk_win_user_post_quit_message(0);
		}
		break;
	}

	ret = mk_win_user_def_window_proc(self->m_hwnd, msg, wparam, lparam);
	return ret;
}
