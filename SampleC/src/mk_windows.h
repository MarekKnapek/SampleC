#ifndef INCLUDE_GUARD_MK_WINDOWS
#define INCLUDE_GUARD_MK_WINDOWS


struct mk_win_widechar_t { unsigned short int m_value; }; typedef struct mk_win_widechar_s mk_win_widechar_t;
struct mk_win_word_s     { unsigned short int m_value; }; typedef struct mk_win_word_s     mk_win_word_t;

struct mk_win_uint_s  { unsigned int m_value; }; typedef struct mk_win_uint_s  mk_win_uint_t;
struct mk_win_dword_s { unsigned int m_value; }; typedef struct mk_win_dword_s mk_win_dword_t;

struct mk_win_bool_s { signed long int m_value; }; typedef struct mk_win_bool_s mk_win_bool_t;
struct mk_win_long_s { signed long int m_value; }; typedef struct mk_win_long_s mk_win_long_t;

struct mk_win_instance_s { void* m_value; }; typedef struct mk_win_instance_s mk_win_instance_t;
struct mk_win_handle_s   { void* m_value; }; typedef struct mk_win_handle_s   mk_win_handle_t;


#endif
