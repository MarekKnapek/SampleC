#include "mk_win_user.h"

#include "mk_assert.h"


extern __declspec(dllimport) mk_win_user_icon_t __stdcall LoadIconW(mk_win_instance_t, mk_win_widechar_t const*);
extern __declspec(dllimport) mk_win_user_cursor_t __stdcall LoadCursorW(mk_win_instance_t, mk_win_widechar_t const*);
extern __declspec(dllimport) mk_win_user_atom_t __stdcall RegisterClassW(mk_win_user_class_t const*);
extern __declspec(dllimport) mk_win_bool_t __stdcall UnregisterClassW(mk_win_widechar_t const*, mk_win_instance_t);
extern __declspec(dllimport) mk_win_user_hwnd_t __stdcall CreateWindowExW(mk_win_dword_t, mk_win_widechar_t const*, mk_win_widechar_t const*, mk_win_dword_t, int, int, int, int, mk_win_user_hwnd_t, mk_win_user_menu_t, mk_win_instance_t, void*);
extern __declspec(dllimport) mk_win_bool_t __stdcall ShowWindow(mk_win_user_hwnd_t, int);
extern __declspec(dllimport) mk_win_bool_t __stdcall PeekMessageW(mk_win_user_msg_t*, mk_win_user_hwnd_t, mk_win_uint_t, mk_win_uint_t, mk_win_uint_t);
extern __declspec(dllimport) mk_win_bool_t __stdcall TranslateMessage(mk_win_user_msg_t*);
extern __declspec(dllimport) mk_win_user_lresult_t __stdcall DispatchMessageW(mk_win_user_msg_t*);
extern __declspec(dllimport) mk_win_bool_t __stdcall GetMessageW(mk_win_user_msg_t*, mk_win_user_hwnd_t, mk_win_uint_t, mk_win_uint_t);
extern __declspec(dllimport) mk_win_user_lresult_t __stdcall DefWindowProcW(mk_win_user_hwnd_t, mk_win_uint_t, mk_win_user_wparam_t, mk_win_user_lparam_t);
#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386
extern __declspec(dllimport) mk_size_t __stdcall GetWindowLongW(mk_win_user_hwnd_t, int);
extern __declspec(dllimport) mk_size_t __stdcall SetWindowLongW(mk_win_user_hwnd_t, int, mk_size_t);
#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64
extern __declspec(dllimport) mk_size_t __stdcall GetWindowLongPtrW(mk_win_user_hwnd_t, int);
extern __declspec(dllimport) mk_size_t __stdcall SetWindowLongPtrW(mk_win_user_hwnd_t, int, mk_size_t);
#endif
extern __declspec(dllimport) mk_win_bool_t __stdcall PostThreadMessageW(mk_win_dword_t, mk_win_uint_t, mk_win_user_wparam_t, mk_win_user_lparam_t);
extern __declspec(dllimport) mk_win_bool_t __stdcall PostMessageW(mk_win_user_hwnd_t, mk_win_uint_t, mk_win_user_wparam_t, mk_win_user_lparam_t);
extern __declspec(dllimport) void __stdcall PostQuitMessage(int);
extern __declspec(dllimport) int __stdcall MessageBoxA(mk_win_user_hwnd_t, char const*, char const*, mk_win_uint_t);
extern __declspec(dllimport) mk_win_bool_t __stdcall SetWindowTextW(mk_win_user_hwnd_t, mk_win_widechar_t const*);


mk_win_user_icon_t mk_win_user_load_icon(mk_win_user_icon_id_t const icon_id)
{
	mk_win_instance_t instance;
	mk_win_widechar_t const* icon_name;
	mk_win_user_icon_t ret;

	instance.m_value = MK_NULL;
	icon_name = (mk_win_widechar_t const*)(mk_size_t)icon_id;
	ret = LoadIconW(instance, icon_name);
	return ret;
}

mk_win_user_cursor_t mk_win_user_load_cursor(mk_win_user_cursor_id_t const cursor_id)
{
	mk_win_instance_t instance;
	mk_win_widechar_t const* cursor_name;
	mk_win_user_cursor_t ret;

	instance.m_value = MK_NULL;
	cursor_name = (mk_win_widechar_t const*)(mk_size_t)cursor_id;
	ret = LoadCursorW(instance, cursor_name);
	return ret;
}

mk_win_user_brush_t mk_win_user_get_brush(mk_win_user_brush_id_t const brush_id)
{
	mk_win_user_brush_t ret;
	ret.m_value = (void*)(mk_size_t)(brush_id + 1);
	return ret;
}

mk_win_user_atom_t mk_win_user_register_class(mk_win_user_class_t const* const window_class)
{
	mk_win_user_atom_t atom;
	atom = RegisterClassW(window_class);
	return atom;
}

mk_bool_t mk_win_user_unregister_class(mk_win_user_atom_t const atom, mk_win_instance_t const instance)
{
	mk_win_bool_t unregistered;
	mk_bool_t ret;

	unregistered = UnregisterClassW((mk_win_widechar_t const*)(mk_size_t)atom.m_value, instance);
	MK_ASSERT(unregistered.m_value == 0 || unregistered.m_value == 1);
	ret = mk_to_bool_t(unregistered.m_value != 0);
	return ret;
}

mk_win_user_hwnd_t mk_win_user_create_window(mk_win_user_window_style_ex_t const style_ex, mk_win_widechar_t const* const class_name, mk_win_widechar_t const* const name, mk_win_user_window_style_t const style, int const x, int const y,
	int const width, int const height, mk_win_user_hwnd_t const parent, mk_win_user_menu_t const menu, mk_win_instance_t const instance, void* const context)
{
	mk_win_dword_t style_exx;
	mk_win_dword_t stylee;
	mk_win_user_hwnd_t ret;

	style_exx.m_value = style_ex;
	stylee.m_value = style;
	ret = CreateWindowExW(style_exx, class_name, name, stylee, x, y, width, height, parent, menu, instance, context);
	return ret;
}

mk_bool_t mk_win_user_show_window(mk_win_user_hwnd_t const hwnd, mk_win_user_show_window_t const show_window)
{
	mk_win_bool_t shown;
	mk_bool_t ret;

	shown = ShowWindow(hwnd, show_window);
	MK_ASSERT(shown.m_value == 0 || shown.m_value == 1);
	ret = mk_to_bool_t(shown.m_value != 0);
	return ret;
}

mk_bool_t mk_win_user_peek_message(mk_win_user_msg_t* const msg, mk_win_user_hwnd_t const hwnd, mk_win_uint_t const filter_min, mk_win_uint_t filter_max, mk_win_user_peek_message_t const flags)
{
	mk_win_uint_t flagss;
	mk_win_bool_t peeked;
	mk_bool_t ret;

	flagss.m_value = flags;
	peeked = PeekMessageW(msg, hwnd, filter_min, filter_max, flagss);
	MK_ASSERT(peeked.m_value == 0 || peeked.m_value == 1);
	ret = mk_to_bool_t(peeked.m_value != 0);
	return ret;
}

mk_bool_t mk_win_user_translate_message(mk_win_user_msg_t* const msg)
{
	mk_win_bool_t translated;
	mk_bool_t ret;

	translated = TranslateMessage(msg);
	MK_ASSERT(translated.m_value == 0 || translated.m_value == 1);
	ret = mk_to_bool_t(translated.m_value != 0);
	return ret;
}

mk_win_user_lresult_t mk_win_user_dispatch_message(mk_win_user_msg_t* const msg)
{
	mk_win_user_lresult_t const ret = DispatchMessageW(msg);
	return ret;
}

mk_win_bool_t mk_win_user_get_message(mk_win_user_msg_t* const msg, mk_win_user_hwnd_t const hwnd, mk_win_uint_t const filter_min, mk_win_uint_t const filter_max)
{
	mk_win_bool_t const ret = GetMessageW(msg, hwnd, filter_min, filter_max);
	return ret;
}

mk_win_user_lresult_t mk_win_user_def_window_proc(mk_win_user_hwnd_t const hwnd, mk_win_uint_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam)
{
	mk_win_user_lresult_t const ret = DefWindowProcW(hwnd, msg, wparam, lparam);
	return ret;
}

mk_size_t mk_win_user_get_window_long(mk_win_user_hwnd_t const hwnd, mk_win_user_window_long_t const index)
{
#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386

	mk_size_t ret;
	ret = GetWindowLongW(hwnd, index);
	return ret;

#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64

	mk_size_t ret;
	ret = GetWindowLongPtrW(hwnd, index);
	return ret;

#endif
}

mk_size_t mk_win_user_set_window_long(mk_win_user_hwnd_t const hwnd, mk_win_user_window_long_t const index, mk_size_t const new_value)
{
#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386

	mk_size_t ret;
	ret = SetWindowLongW(hwnd, index, new_value);
	return ret;

#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64

	mk_size_t ret;
	ret = SetWindowLongPtrW(hwnd, index, new_value);
	return ret;

#endif
}

mk_bool_t mk_win_user_post_thread_message(mk_win_dword_t const thread_id, mk_win_user_wm_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam)
{
	mk_win_uint_t msgg;
	mk_win_bool_t posted;
	mk_bool_t ret;

	msgg.m_value = msg;
	posted = PostThreadMessageW(thread_id, msgg, wparam, lparam);
	ret = posted.m_value != 0 ? MK_TRUE : MK_FALSE;
	return ret;
}

mk_bool_t mk_win_user_post_message(mk_win_user_hwnd_t const hwnd, mk_win_user_wm_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam)
{
	mk_win_uint_t msgg;
	mk_win_bool_t posted;
	mk_bool_t ret;

	msgg.m_value = msg;
	posted = PostMessageW(hwnd, msgg, wparam, lparam);
	ret = posted.m_value == 0 ? MK_TRUE : MK_FALSE;
	return ret;
}

void mk_win_user_post_quit_message(int const exit_code)
{
	PostQuitMessage(exit_code);
}

int mk_win_user_message_boxa(mk_win_user_hwnd_t const hwnd, char const* const text, char const* const caption, mk_win_user_mb_t const type)
{
	mk_win_uint_t typee;
	int ret;

	typee.m_value = type;
	ret = MessageBoxA(hwnd, text, caption, typee);
	return ret;
}

mk_bool_t mk_win_user_set_window_text(mk_win_user_hwnd_t const hwnd, mk_win_widechar_t const* const text)
{
	mk_win_bool_t set;
	mk_bool_t ret;

	set = SetWindowTextW(hwnd, text);
	ret = set.m_value == 0 ? MK_TRUE : MK_FALSE;
	return ret;
}
