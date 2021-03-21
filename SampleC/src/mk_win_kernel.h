#ifndef INCLUDE_GUARD_MK_WIN_KERNEL
#define INCLUDE_GUARD_MK_WIN_KERNEL


#include "mk_types.h"
#include "mk_windows.h"


enum mk_win_kernel_heap_create_e
{
	mk_win_kernel_heap_create_no_serialize          = 0x00000001,
	mk_win_kernel_heap_create_generate_exceptions   = 0x00000004,
	mk_win_kernel_heap_create_create_enable_execute = 0x00040000,
};
typedef enum mk_win_kernel_heap_create_e mk_win_kernel_heap_create_t;

enum mk_win_kernel_heap_alloc_e
{
	mk_win_kernel_heap_alloc_no_serialize        = 0x00000001,
	mk_win_kernel_heap_alloc_generate_exceptions = 0x00000004,
	mk_win_kernel_heap_alloc_zero_memory         = 0x00000008,
};
typedef enum mk_win_kernel_heap_alloc_e mk_win_kernel_heap_alloc_t;

enum mk_win_kernel_heap_realloc_e
{
	mk_win_kernel_heap_realloc_no_serialize          = 0x00000001,
	mk_win_kernel_heap_realloc_generate_exceptions   = 0x00000004,
	mk_win_kernel_heap_realloc_zero_memory           = 0x00000008,
	mk_win_kernel_heap_realloc_realloc_in_place_only = 0x00000010,
};
typedef enum mk_win_kernel_heap_realloc_e mk_win_kernel_heap_realloc_t;

enum mk_win_kernel_heap_size_e
{
	mk_win_kernel_heap_size_no_serialize          = 0x00000001,
};
typedef enum mk_win_kernel_heap_size_e mk_win_kernel_heap_size_t;

enum mk_win_kernel_heap_free_e
{
	mk_win_kernel_heap_free_no_serialize        = 0x00000001,
};
typedef enum mk_win_kernel_heap_free_e mk_win_kernel_heap_free_t;


struct mk_win_user_instance_s { void* m_value; }; typedef struct mk_win_user_instance_s mk_win_user_instance_t;


struct mk_win_kernel_list_entry_s
{
	void* m_next;
	void* m_prev;
};
typedef struct mk_win_kernel_list_entry_s mk_win_kernel_list_entry_t;

struct mk_win_kernel_critical_section_s;
typedef struct mk_win_kernel_critical_section_s mk_win_kernel_critical_section_t;

struct mk_win_kernel_critical_section_debug_s
{
	mk_win_word_t m_type;
	mk_win_word_t m_creator_back_trace_index;
	mk_win_kernel_critical_section_t* m_critical_section;
	mk_win_kernel_list_entry_t m_process_locks_list;
	mk_win_dword_t m_entry_count;
	mk_win_dword_t m_contention_count;
	mk_win_dword_t m_flags;
	mk_win_word_t m_creator_back_trace_index_high;
	mk_win_word_t m_reserved;
};
typedef struct mk_win_kernel_critical_section_debug_s mk_win_kernel_critical_section_debug_t;

struct mk_win_kernel_critical_section_s
{
	mk_win_kernel_critical_section_debug_t* m_critical_section_debug;
	mk_win_long_t m_lock_count;
	mk_win_long_t m_recursion_count;
	mk_win_handle_t m_owning_thread;
	mk_win_handle_t m_lock_semaphore;
	mk_size_t m_spin_count;
};
typedef struct mk_win_kernel_critical_section_s mk_win_kernel_critical_section_t;


void mk_win_kernel_debug_break(void);
mk_win_handle_t mk_win_kernel_get_current_process(void);
mk_win_dword_t mk_win_kernel_get_current_thread_id(void);
mk_bool_t mk_win_kernel_terminate_process(mk_win_handle_t const handle, mk_win_uint_t const exit_code);
void mk_win_kernel_initialize_critical_section(mk_win_kernel_critical_section_t* const critical_section);
void mk_win_kernel_enter_critical_section(mk_win_kernel_critical_section_t* const critical_section);
void mk_win_kernel_leave_critical_section(mk_win_kernel_critical_section_t* const critical_section);
void mk_win_kernel_delete_critical_section(mk_win_kernel_critical_section_t* const critical_section);
mk_win_handle_t mk_win_kernel_get_process_heap(void);
mk_win_handle_t mk_win_kernel_heap_create(mk_win_kernel_heap_create_t const options, mk_size_t const initial_size, mk_size_t const maximum_size);
void* mk_win_kernel_heap_alloc(mk_win_handle_t const heap, mk_win_kernel_heap_alloc_t const flags, mk_size_t const bytes);
void* mk_win_kernel_heap_realloc(mk_win_handle_t const heap, mk_win_kernel_heap_realloc_t const flags, void* const mem, mk_size_t const bytes);
mk_size_t mk_win_kernel_heap_size(mk_win_handle_t const heap, mk_win_kernel_heap_size_t const flags, void* const mem);
mk_bool_t mk_win_kernel_heap_free(mk_win_handle_t const heap, mk_win_kernel_heap_free_t const flags, void* const mem);
mk_bool_t mk_win_kernel_heap_destroy(mk_win_handle_t const heap);
mk_win_dword_t mk_win_kernel_get_tick_count(void);
void mk_win_kernel_output_debug_string(char const* const str);


#endif
