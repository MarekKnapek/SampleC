#ifndef INCLUDE_GUARD_MK_WIN_USER
#define INCLUDE_GUARD_MK_WIN_USER


#include "mk_types.h"
#include "mk_windows.h"


enum mk_win_user_icon_id_e
{
	mk_win_user_icon_id_application = 32512,
	mk_win_user_icon_id_hand        = 32513, /* error */
	mk_win_user_icon_id_question    = 32514,
	mk_win_user_icon_id_exclamation = 32515, /* warning */
	mk_win_user_icon_id_asterisk    = 32516, /* information */
	mk_win_user_icon_id_winlogo     = 32517, /* MK_WINVER >= 0x0400 */
	mk_win_user_icon_id_shield      = 32518, /* MK_WINVER >= 0x0600 */
};
typedef enum mk_win_user_icon_id_e mk_win_user_icon_id_t;

enum mk_win_user_cursor_id_e
{
	mk_win_user_cursor_id_arrow       = 32512,
	mk_win_user_cursor_id_ibeam       = 32513,
	mk_win_user_cursor_id_wait        = 32514,
	mk_win_user_cursor_id_cross       = 32515,
	mk_win_user_cursor_id_uparrow     = 32516,
	mk_win_user_cursor_id_size        = 32640, /* obsolete, use sizeall */
	mk_win_user_cursor_id_icon        = 32641, /* obsolete, use arrow */
	mk_win_user_cursor_id_sizenwse    = 32642,
	mk_win_user_cursor_id_sizenesw    = 32643,
	mk_win_user_cursor_id_sizewe      = 32644,
	mk_win_user_cursor_id_sizens      = 32645,
	mk_win_user_cursor_id_sizeall     = 32646,
	mk_win_user_cursor_id_no          = 32648, /* not in win3.1 */
	mk_win_user_cursor_id_hand        = 32649, /* MK_WINVER >= 0x0500 */
	mk_win_user_cursor_id_appstarting = 32650, /* not in win3.1 */
	mk_win_user_cursor_id_help        = 32651, /* MK_WINVER >= 0x0400 */
};
typedef enum mk_win_user_cursor_id_e mk_win_user_cursor_id_t;

enum mk_win_user_brush_id_e
{
	mk_win_user_brush_id_scrollbar               = 0,
	mk_win_user_brush_id_background              = 1,
	mk_win_user_brush_id_activecaption           = 2,
	mk_win_user_brush_id_inactivecaption         = 3,
	mk_win_user_brush_id_menu                    = 4,
	mk_win_user_brush_id_window                  = 5,
	mk_win_user_brush_id_windowframe             = 6,
	mk_win_user_brush_id_menutext                = 7,
	mk_win_user_brush_id_windowtext              = 8,
	mk_win_user_brush_id_captiontext             = 9,
	mk_win_user_brush_id_activeborder            = 10,
	mk_win_user_brush_id_inactiveborder          = 11,
	mk_win_user_brush_id_appworkspace            = 12,
	mk_win_user_brush_id_highlight               = 13,
	mk_win_user_brush_id_highlighttext           = 14,
	mk_win_user_brush_id_btnface                 = 15,
	mk_win_user_brush_id_btnshadow               = 16,
	mk_win_user_brush_id_graytext                = 17,
	mk_win_user_brush_id_btntext                 = 18,
	mk_win_user_brush_id_inactivecaptiontext     = 19,
	mk_win_user_brush_id_btnhighlight            = 20,
	mk_win_user_brush_id_triddkshadow            = 21, /* MK_WINVER >= 0x0400 */
	mk_win_user_brush_id_tridlight               = 22, /* MK_WINVER >= 0x0400 */
	mk_win_user_brush_id_infotext                = 23, /* MK_WINVER >= 0x0400 */
	mk_win_user_brush_id_infobk                  = 24, /* MK_WINVER >= 0x0400 */
	mk_win_user_brush_id_hotlight                = 26, /* MK_WINVER >= 0x0500 */
	mk_win_user_brush_id_gradientactivecaption   = 27, /* MK_WINVER >= 0x0500 */
	mk_win_user_brush_id_gradientinactivecaption = 28, /* MK_WINVER >= 0x0500 */
	mk_win_user_brush_id_menuhilight             = 29, /* MK_WINVER >= 0x0501 */
	mk_win_user_brush_id_menubar                 = 30, /* MK_WINVER >= 0x0501 */
	mk_win_user_brush_id_desktop                 = mk_win_user_brush_id_background,   /* MK_WINVER >= 0x0400 */
	mk_win_user_brush_id_tridface                = mk_win_user_brush_id_btnface,      /* MK_WINVER >= 0x0400 */
	mk_win_user_brush_id_tridshadow              = mk_win_user_brush_id_btnshadow,    /* MK_WINVER >= 0x0400 */
	mk_win_user_brush_id_tridhighligh            = mk_win_user_brush_id_btnhighlight, /* MK_WINVER >= 0x0400 */
	mk_win_user_brush_id_tridhilight             = mk_win_user_brush_id_btnhighlight, /* MK_WINVER >= 0x0400 */
	mk_win_user_brush_id_btnhilight              = mk_win_user_brush_id_btnhighlight, /* MK_WINVER >= 0x0400 */
};
typedef enum mk_win_user_brush_id_e mk_win_user_brush_id_t;

enum mk_win_user_show_window_e
{
	mk_win_user_show_window_hide            = 0,
	mk_win_user_show_window_shownormal      = 1,
	mk_win_user_show_window_normal          = 1,
	mk_win_user_show_window_showminimized   = 2,
	mk_win_user_show_window_showmaximized   = 3,
	mk_win_user_show_window_maximize        = 3,
	mk_win_user_show_window_shownoactivate  = 4,
	mk_win_user_show_window_show            = 5,
	mk_win_user_show_window_minimize        = 6,
	mk_win_user_show_window_showminnoactive = 7,
	mk_win_user_show_window_showna          = 8,
	mk_win_user_show_window_restore         = 9,
	mk_win_user_show_window_showdefault     = 10,
	mk_win_user_show_window_forceminimize   = 11,
	mk_win_user_show_window_max             = 11,
};
typedef enum mk_win_user_show_window_e mk_win_user_show_window_t;

enum mk_win_user_peek_message_e
{
	mk_win_user_peek_message_noremove = 0x0000,
	mk_win_user_peek_message_remove   = 0x0001,
};
typedef enum mk_win_user_peek_message_e mk_win_user_peek_message_t;

enum mk_win_user_window_style_e
{
	mk_win_user_window_style_overlapped       = 0x00000000l,
	mk_win_user_window_style_popup            = 0x80000000l,
	mk_win_user_window_style_child            = 0x40000000l,
	mk_win_user_window_style_minimize         = 0x20000000l,
	mk_win_user_window_style_visible          = 0x10000000l,
	mk_win_user_window_style_disabled         = 0x08000000l,
	mk_win_user_window_style_clipsiblings     = 0x04000000l,
	mk_win_user_window_style_clipchildren     = 0x02000000l,
	mk_win_user_window_style_maximize         = 0x01000000l,
	mk_win_user_window_style_caption          = 0x00c00000l, /* ws_border | ws_dlgframe  */
	mk_win_user_window_style_border           = 0x00800000l,
	mk_win_user_window_style_dlgframe         = 0x00400000l,
	mk_win_user_window_style_vscroll          = 0x00200000l,
	mk_win_user_window_style_hscroll          = 0x00100000l,
	mk_win_user_window_style_sysmenu          = 0x00080000l,
	mk_win_user_window_style_thickframe       = 0x00040000l,
	mk_win_user_window_style_group            = 0x00020000l,
	mk_win_user_window_style_tabstop          = 0x00010000l,
	mk_win_user_window_style_minimizebox      = 0x00020000l,
	mk_win_user_window_style_maximizebox      = 0x00010000l,

	mk_win_user_window_style_overlappedwindow =
		mk_win_user_window_style_overlapped |
		mk_win_user_window_style_caption |
		mk_win_user_window_style_sysmenu |
		mk_win_user_window_style_thickframe |
		mk_win_user_window_style_minimizebox |
		mk_win_user_window_style_maximizebox,
	mk_win_user_window_style_popupwindow =
		mk_win_user_window_style_popup |
		mk_win_user_window_style_border |
		mk_win_user_window_style_sysmenu,
	mk_win_user_window_style_childwindow =
		mk_win_user_window_style_child,

	mk_win_user_window_style_tiled            = mk_win_user_window_style_overlapped,
	mk_win_user_window_style_iconic           = mk_win_user_window_style_minimize,
	mk_win_user_window_style_sizebox          = mk_win_user_window_style_thickframe,
	mk_win_user_window_style_tiledwindow      = mk_win_user_window_style_overlappedwindow,
};
typedef enum mk_win_user_window_style_e mk_win_user_window_style_t;

enum mk_win_user_window_style_ex_e
{
	mk_win_user_window_style_ex_dlgmodalframe       = 0x00000001L,
	mk_win_user_window_style_ex_noparentnotify      = 0x00000004L,
	mk_win_user_window_style_ex_topmost             = 0x00000008L,
	mk_win_user_window_style_ex_acceptfiles         = 0x00000010L,
	mk_win_user_window_style_ex_transparent         = 0x00000020L,
	mk_win_user_window_style_ex_mdichild            = 0x00000040L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_toolwindow          = 0x00000080L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_windowedge          = 0x00000100L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_clientedge          = 0x00000200L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_contexthelp         = 0x00000400L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_right               = 0x00001000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_left                = 0x00000000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_rtlreading          = 0x00002000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_ltrreading          = 0x00000000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_leftscrollbar       = 0x00004000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_rightscrollbar      = 0x00000000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_controlparent       = 0x00010000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_staticedge          = 0x00020000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_appwindow           = 0x00040000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_overlappedwindow    = mk_win_user_window_style_ex_windowedge | mk_win_user_window_style_ex_clientedge, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_palettewindow       = mk_win_user_window_style_ex_windowedge | mk_win_user_window_style_ex_toolwindow | mk_win_user_window_style_ex_topmost, /* MK_WINVER >= 0x0400 */
	mk_win_user_window_style_ex_layered             = 0x00080000, /* MK_WINVER >= 0x0500 */
	mk_win_user_window_style_ex_noinheritlayout     = 0x00100000L, /* MK_WINVER >= 0x0500 */
	mk_win_user_window_style_ex_noredirectionbitmap = 0x00200000L, /* MK_WINVER >= 0x0602 */
	mk_win_user_window_style_ex_layoutrtl           = 0x00400000L, /* MK_WINVER >= 0x0500 */
	mk_win_user_window_style_ex_composited          = 0x02000000L, /* MK_WINVER >= 0x0501 */
	mk_win_user_window_style_ex_noactivate          = 0x08000000L, /* MK_WINVER >= 0x0500 */
};
typedef enum mk_win_user_window_style_ex_e mk_win_user_window_style_ex_t;

enum mk_win_user_create_window_e
{
	mk_win_user_create_window_usedefault = (int)0x80000000,
};

enum mk_win_user_wm_e
{
	mk_win_user_wm_null    = 0x0000,
	mk_win_user_wm_create  = 0x0001,
	mk_win_user_wm_destroy = 0x0002,
	mk_win_user_wm_quit    = 0x0012,
};
typedef enum mk_win_user_e mk_win_user_wm_t;

enum mk_win_user_window_long_e
{
	mk_win_user_window_long_wndproc    = -4,
	mk_win_user_window_long_hinstance  = -6,
	mk_win_user_window_long_hwndparent = -8,
	mk_win_user_window_long_id         = -12,
	mk_win_user_window_long_style      = -16,
	mk_win_user_window_long_exstyle    = -20,
	mk_win_user_window_long_userdata   = -21,
};
typedef enum mk_win_user_window_long_e mk_win_user_window_long_t;

enum mk_win_user_mb_e
{
	mk_win_user_mb_ok                        = 0x00000000L,
	mk_win_user_mb_okcancel                  = 0x00000001L,
	mk_win_user_mb_abortretryignore          = 0x00000002L,
	mk_win_user_mb_yesnocancel               = 0x00000003L,
	mk_win_user_mb_yesno                     = 0x00000004L,
	mk_win_user_mb_retrycancel               = 0x00000005L,
	mk_win_user_mb_canceltrycontinue         = 0x00000006L, /* MK_WINVER >= 0x0500 */
	mk_win_user_mb_iconhand                  = 0x00000010L,
	mk_win_user_mb_iconquestion              = 0x00000020L,
	mk_win_user_mb_iconexclamation           = 0x00000030L,
	mk_win_user_mb_iconasterisk              = 0x00000040L,
	mk_win_user_mb_usericon                  = 0x00000080L, /* MK_WINVER >= 0x0400 */
	mk_win_user_mb_iconwarning               = mk_win_user_mb_iconexclamation,  /* MK_WINVER >= 0x0400 */
	mk_win_user_mb_iconerror                 = mk_win_user_mb_iconhand, /* MK_WINVER >= 0x0400 */
	mk_win_user_mb_iconinformation           = mk_win_user_mb_iconasterisk,
	mk_win_user_mb_iconstop                  = mk_win_user_mb_iconhand,
	mk_win_user_mb_defbutton1                = 0x00000000L,
	mk_win_user_mb_defbutton2                = 0x00000100L,
	mk_win_user_mb_defbutton3                = 0x00000200L,
	mk_win_user_mb_defbutton4                = 0x00000300L, /* MK_WINVER >= 0x0400 */
	mk_win_user_mb_applmodal                 = 0x00000000L,
	mk_win_user_mb_systemmodal               = 0x00001000L,
	mk_win_user_mb_taskmodal                 = 0x00002000L,
	mk_win_user_mb_help                      = 0x00004000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_mb_nofocus                   = 0x00008000L,
	mk_win_user_mb_setforeground             = 0x00010000L,
	mk_win_user_mb_default_desktop_only      = 0x00020000L,
	mk_win_user_mb_topmost                   = 0x00040000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_mb_right                     = 0x00080000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_mb_rtlreading                = 0x00100000L, /* MK_WINVER >= 0x0400 */
	mk_win_user_mb_service_notification      = 0x00200000L, /* MK_WINNT >= 0x0400 */
	mk_win_user_mb_service_notification_nt3x = 0x00040000L,
	mk_win_user_mb_typemask                  = 0x0000000FL,
	mk_win_user_mb_iconmask                  = 0x000000F0L,
	mk_win_user_mb_defmask                   = 0x00000F00L,
	mk_win_user_mb_modemask                  = 0x00003000L,
	mk_win_user_mb_miscmask                  = 0x0000C000L,
};
typedef enum mk_win_user_mb_e mk_win_user_mb_t;


struct mk_win_user_atom_s { unsigned short int m_value; }; typedef struct mk_win_user_atom_s mk_win_user_atom_t;

struct mk_win_user_lresult_s { mk_ptrdiff_t m_value; }; typedef struct mk_win_user_lresult_s mk_win_user_lresult_t;

struct mk_win_user_wparam_s { mk_size_t m_value; }; typedef struct mk_win_user_wparam_s mk_win_user_wparam_t;
struct mk_win_user_lparam_s { mk_size_t m_value; }; typedef struct mk_win_user_lparam_s mk_win_user_lparam_t;

struct mk_win_user_hwnd_s { void* m_value; }; typedef struct mk_win_user_hwnd_s mk_win_user_hwnd_t;
struct mk_win_user_icon_s { void* m_value; }; typedef struct mk_win_user_icon_s mk_win_user_icon_t;
struct mk_win_user_cursor_s { void* m_value; }; typedef struct mk_win_user_cursor_s mk_win_user_cursor_t;
struct mk_win_user_brush_s { void* m_value; }; typedef struct mk_win_user_brush_s mk_win_user_brush_t;
struct mk_win_user_menu_s { void* m_value; }; typedef struct mk_win_user_menu_s mk_win_user_menu_t;


struct mk_win_user_window_procedure_s
{
	mk_win_user_lresult_t(__stdcall*m_value)
	(
		mk_win_user_hwnd_t,
		mk_win_uint_t,
		mk_win_user_wparam_t,
		mk_win_user_lparam_t
	);
};
typedef struct mk_win_user_window_procedure_s mk_win_user_window_procedure_t;


struct mk_win_user_class_s
{
	mk_win_uint_t m_style;
	mk_win_user_window_procedure_t m_window_procedure;
	int m_class_extra;
	int m_object_extra;
	mk_win_instance_t m_instance;
	mk_win_user_icon_t m_icon;
	mk_win_user_cursor_t m_cursor;
	mk_win_user_brush_t m_background;
	mk_win_widechar_t const* m_menu_name;
	mk_win_widechar_t const* m_class_name;
};
typedef struct mk_win_user_class_s mk_win_user_class_t;

struct mk_win_user_point_s
{
	mk_win_long_t m_x;
	mk_win_long_t m_y;
};
typedef struct mk_win_user_point_s mk_win_user_point_t;

struct mk_win_user_msg_s
{
	mk_win_user_hwnd_t m_hwnd;
	mk_win_uint_t m_msg;
	mk_win_user_wparam_t m_wparam;
	mk_win_user_lparam_t m_lparam;
	mk_win_dword_t m_time;
	mk_win_user_point_t m_point;
};
typedef struct mk_win_user_msg_s mk_win_user_msg_t;


struct mk_win_user_wm_create_s
{
	void* m_context;
	mk_win_instance_t m_instance;
	mk_win_user_menu_t m_menu;
	mk_win_user_hwnd_t m_parent;
	int m_height;
	int m_width;
	int m_y;
	int m_x;
	mk_win_long_t m_style;
	mk_win_widechar_t const* m_name;
	mk_win_widechar_t const* m_class;
	mk_win_dword_t m_ex_style;
};
typedef struct mk_win_user_wm_create_s mk_win_user_wm_create_t;


mk_win_user_icon_t mk_win_user_load_icon(mk_win_user_icon_id_t const icon_id);
mk_win_user_cursor_t mk_win_user_load_cursor(mk_win_user_cursor_id_t const cursor_id);
mk_win_user_brush_t mk_win_user_get_brush(mk_win_user_brush_id_t const brush_id);
mk_win_user_atom_t mk_win_user_register_class(mk_win_user_class_t const* const window_class);
mk_bool_t mk_win_user_unregister_class(mk_win_user_atom_t const atom, mk_win_instance_t const instance);
mk_win_user_hwnd_t mk_win_user_create_window(mk_win_user_window_style_ex_t const style_ex, mk_win_widechar_t const* const class_name, mk_win_widechar_t const* const name, mk_win_user_window_style_t const style, int const x, int const y,
	int const width, int const height, mk_win_user_hwnd_t const parent, mk_win_user_menu_t const menu, mk_win_instance_t const instance, void* const context);
mk_bool_t mk_win_user_show_window(mk_win_user_hwnd_t const hwnd, mk_win_user_show_window_t const show_window);
mk_bool_t mk_win_user_peek_message(mk_win_user_msg_t* const msg, mk_win_user_hwnd_t const hwnd, mk_win_uint_t const filter_min, mk_win_uint_t filter_max, mk_win_user_peek_message_t const flags);
mk_bool_t mk_win_user_translate_message(mk_win_user_msg_t* const msg);
mk_win_user_lresult_t mk_win_user_dispatch_message(mk_win_user_msg_t* const msg);
mk_win_bool_t mk_win_user_get_message(mk_win_user_msg_t* const msg, mk_win_user_hwnd_t const hwnd, mk_win_uint_t const filter_min, mk_win_uint_t const filter_max);
mk_win_user_lresult_t mk_win_user_def_window_proc(mk_win_user_hwnd_t const hwnd, mk_win_uint_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam);
mk_size_t mk_win_user_get_window_long(mk_win_user_hwnd_t const hwnd, mk_win_user_window_long_t const index);
mk_size_t mk_win_user_set_window_long(mk_win_user_hwnd_t const hwnd, mk_win_user_window_long_t const index, mk_size_t const new_value);
mk_bool_t mk_win_user_post_thread_message(mk_win_dword_t const thread_id, mk_win_user_wm_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam);
mk_bool_t mk_win_user_post_message(mk_win_user_hwnd_t const hwnd, mk_win_user_wm_t const msg, mk_win_user_wparam_t const wparam, mk_win_user_lparam_t const lparam);
void mk_win_user_post_quit_message(int const exit_code);
int mk_win_user_message_boxa(mk_win_user_hwnd_t const hwnd, char const* const text, char const* const caption, mk_win_user_mb_t const type);
mk_bool_t mk_win_user_set_window_text(mk_win_user_hwnd_t const hwnd, mk_win_widechar_t const* const text);


#endif
