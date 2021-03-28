#ifndef INCLUDE_GUARD_MK_WIN_KERNEL
#define INCLUDE_GUARD_MK_WIN_KERNEL


#include "mk_types.h"
#include "mk_windows.h"


#define MK_WIN_KERNEL_INVALID_HANDLE_VALUE ((void*)(mk_size_t)-1)
#define MK_WIN_KERNEL_INVALID_FILE_SIZE (0xFFFFFFFF)


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

enum mk_win_kernel_access_right_generic_e
{
	mk_win_kernel_access_right_generic_all     = 0x10000000L,
	mk_win_kernel_access_right_generic_execute = 0x20000000L,
	mk_win_kernel_access_right_generic_write   = 0x40000000L,
	mk_win_kernel_access_right_generic_read    = 0x80000000L,
};
typedef enum mk_win_kernel_access_right_generic_e mk_win_kernel_access_right_generic_t;

enum mk_win_kernel_access_right_sacl_e
{
	mk_win_kernel_access_right_sacl_access_sacl = 0x01000000L,
};
typedef enum mk_win_kernel_access_right_sacl_e mk_win_kernel_access_right_sacl_t;

enum mk_win_kernel_access_right_standard_e
{
	mk_win_kernel_access_right_standard_delete          = 0x00010000L,
	mk_win_kernel_access_right_standard_read_control    = 0x00020000L,
	mk_win_kernel_access_right_standard_write_dac       = 0x00040000L,
	mk_win_kernel_access_right_standard_write_owner     = 0x00080000L,
	mk_win_kernel_access_right_standard_synchronize     = 0x00100000L,
	mk_win_kernel_access_right_standard_rights_required = 0x000F0000L,
};
typedef enum mk_win_kernel_access_right_standard_e mk_win_kernel_access_right_standard_t;

enum mk_win_kernel_access_right_specific_file_e
{
	mk_win_kernel_access_right_specific_file_read_data                 = 0x0001,
	mk_win_kernel_access_right_specific_file_write_data                = 0x0002,
	mk_win_kernel_access_right_specific_file_append_data               = 0x0004,
	mk_win_kernel_access_right_specific_file_read_extended_attributes  = 0x0008,
	mk_win_kernel_access_right_specific_file_write_extended_attributes = 0x0010,
	mk_win_kernel_access_right_specific_file_execute                   = 0x0020,
	mk_win_kernel_access_right_specific_file_read_attributes           = 0x0080,
	mk_win_kernel_access_right_specific_file_write_attributes          = 0x0100,
};
typedef enum mk_win_kernel_access_right_specific_file_e mk_win_kernel_access_right_specific_file_t;

enum mk_win_kernel_access_right_specific_dir_e
{
	mk_win_kernel_access_right_specific_dir_list_directory            = 0x0001,
	mk_win_kernel_access_right_specific_dir_add_file                  = 0x0002,
	mk_win_kernel_access_right_specific_dir_add_subdirectory          = 0x0004,
	mk_win_kernel_access_right_specific_dir_read_extended_attributes  = 0x0008,
	mk_win_kernel_access_right_specific_dir_write_extended_attributes = 0x0010,
	mk_win_kernel_access_right_specific_dir_traverse                  = 0x0020,
	mk_win_kernel_access_right_specific_dir_delete_child              = 0x0040,
	mk_win_kernel_access_right_specific_dir_read_attributes           = 0x0080,
	mk_win_kernel_access_right_specific_dir_write_attributes          = 0x0100,
};
typedef enum mk_win_kernel_access_right_specific_dir_e mk_win_kernel_access_right_specific_dir_t;

enum mk_win_kernel_access_right_specific_pipe_e
{
	mk_win_kernel_access_right_specific_pipe_read_data            = 0x0001,
	mk_win_kernel_access_right_specific_pipe_write_data           = 0x0002,
	mk_win_kernel_access_right_specific_pipe_create_pipe_instance = 0x0004,
	mk_win_kernel_access_right_specific_pipe_read_attributes      = 0x0080,
	mk_win_kernel_access_right_specific_pipe_write_attributes     = 0x0100,
};
typedef enum mk_win_kernel_access_right_specific_pipe_e mk_win_kernel_access_right_specific_pipe_t;

enum mk_win_kernel_file_share_e
{
	mk_win_kernel_file_share_none   = 0,
	mk_win_kernel_file_share_read   = 1,
	mk_win_kernel_file_share_write  = 2,
	mk_win_kernel_file_share_delete = 4,
};
typedef enum mk_win_kernel_file_share_e mk_win_kernel_file_share_t;

enum mk_win_kernel_file_create_e
{
	mk_win_kernel_file_create_create_new        = 1,
	mk_win_kernel_file_create_create_always     = 2,
	mk_win_kernel_file_create_open_existing     = 3,
	mk_win_kernel_file_create_open_always       = 4,
	mk_win_kernel_file_create_truncate_existing = 5,
};
typedef enum mk_win_kernel_file_create_e mk_win_kernel_file_create_t;

enum mk_win_kernel_file_attribute_e
{
	mk_win_kernel_file_attribute_readonly              = 0x00000001,
	mk_win_kernel_file_attribute_hidden                = 0x00000002,
	mk_win_kernel_file_attribute_system                = 0x00000004,
	mk_win_kernel_file_attribute_directory             = 0x00000010,
	mk_win_kernel_file_attribute_archive               = 0x00000020,
	mk_win_kernel_file_attribute_device                = 0x00000040,
	mk_win_kernel_file_attribute_normal                = 0x00000080,
	mk_win_kernel_file_attribute_temporary             = 0x00000100,
	mk_win_kernel_file_attribute_sparse_file           = 0x00000200,
	mk_win_kernel_file_attribute_reparse_point         = 0x00000400,
	mk_win_kernel_file_attribute_compressed            = 0x00000800,
	mk_win_kernel_file_attribute_offline               = 0x00001000,
	mk_win_kernel_file_attribute_not_content_indexed   = 0x00002000,
	mk_win_kernel_file_attribute_encrypted             = 0x00004000,
	mk_win_kernel_file_attribute_integrity_stream      = 0x00008000,
	mk_win_kernel_file_attribute_virtual               = 0x00010000,
	mk_win_kernel_file_attribute_no_scrub_data         = 0x00020000,
	mk_win_kernel_file_attribute_ea                    = 0x00040000,
	mk_win_kernel_file_attribute_recall_on_open        = 0x00040000,
	mk_win_kernel_file_attribute_pinned                = 0x00080000,
	mk_win_kernel_file_attribute_unpinned              = 0x00100000,
	mk_win_kernel_file_attribute_recall_on_data_access = 0x00400000,
};
typedef enum mk_win_kernel_file_attribute_e mk_win_kernel_file_attribute_t;

enum mk_win_kernel_file_flag_e
{
	mk_win_kernel_file_flag_first_pipe_instance = 0x00080000,
	mk_win_kernel_file_flag_open_no_recall      = 0x00100000,
	mk_win_kernel_file_flag_open_reparse_point  = 0x00200000,
	mk_win_kernel_file_flag_session_aware       = 0x00800000,
	mk_win_kernel_file_flag_posix_semantics     = 0x01000000,
	mk_win_kernel_file_flag_backup_semantics    = 0x02000000,
	mk_win_kernel_file_flag_delete_on_close     = 0x04000000,
	mk_win_kernel_file_flag_sequential_scan     = 0x08000000,
	mk_win_kernel_file_flag_random_access       = 0x10000000,
	mk_win_kernel_file_flag_no_buffering        = 0x20000000,
	mk_win_kernel_file_flag_overlapped          = 0x40000000,
	mk_win_kernel_file_flag_write_through       = 0x80000000,
};
typedef enum mk_win_kernel_file_flag_e mk_win_kernel_file_flag_t;

enum mk_win_kernel_file_security_qos_e
{
	mk_win_kernel_file_security_qos_anonymous        = (0u << 16),
	mk_win_kernel_file_security_qos_identification   = (1u << 16),
	mk_win_kernel_file_security_qos_impersonation    = (2u << 16),
	mk_win_kernel_file_security_qos_delegation       = (3u << 16),
	mk_win_kernel_file_security_qos_context_tracking = 0x00040000,
	mk_win_kernel_file_security_qos_effective_only   = 0x00080000,
	mk_win_kernel_file_security_qos_present          = 0x00100000,
};
typedef enum mk_win_kernel_file_security_qos_e mk_win_kernel_file_security_qos_t;

enum mk_win_kernel_page_protect_e
{
	mk_win_kernel_page_protect_readonly          = 0x02,
	mk_win_kernel_page_protect_readwrite         = 0x04,
	mk_win_kernel_page_protect_writecopy         = 0x08,
	mk_win_kernel_page_protect_execute_read      = 0x20,
	mk_win_kernel_page_protect_execute_readwrite = 0x40,
	mk_win_kernel_page_protect_execute_writecopy = 0x80,
};
typedef enum mk_win_kernel_page_protect_e mk_win_kernel_page_protect_t;

enum mk_win_kernel_section_protect_e
{
	mk_win_kernel_section_protect_reserve          = 0x04000000,
	mk_win_kernel_section_protect_commit           = 0x08000000,
	mk_win_kernel_section_protect_image            = 0x01000000,
	mk_win_kernel_section_protect_nocache          = 0x10000000,
	mk_win_kernel_section_protect_image_no_execute = 0x11000000,
	mk_win_kernel_section_protect_writecombine     = 0x40000000,
	mk_win_kernel_section_protect_large_pages      = 0x80000000,
};
typedef enum mk_win_kernel_section_protect_e mk_win_kernel_section_protect_t;

enum mk_win_kernel_section_e
{
	mk_win_kernel_section_query                = 0x0001,
	mk_win_kernel_section_map_write            = 0x0002,
	mk_win_kernel_section_map_read             = 0x0004,
	mk_win_kernel_section_map_execute          = 0x0008,
	mk_win_kernel_section_extend_size          = 0x0010,
	mk_win_kernel_section_map_execute_explicit = 0x0020, /* not in all access */
	mk_win_kernel_section_all_access =
		mk_win_kernel_access_right_standard_rights_required |
		mk_win_kernel_section_query |
		mk_win_kernel_section_map_write |
		mk_win_kernel_section_map_read |
		mk_win_kernel_section_map_execute |
		mk_win_kernel_section_extend_size,
};
typedef enum mk_win_kernel_section_e mk_win_kernel_section_t;

enum mk_win_kernel_file_map_e
{
	mk_win_kernel_file_map_copy            = 0x00000001,
	mk_win_kernel_file_map_write           = mk_win_kernel_section_map_write,
	mk_win_kernel_file_map_read            = mk_win_kernel_section_map_read,
	mk_win_kernel_file_map_execute         = mk_win_kernel_section_map_execute_explicit,
	mk_win_kernel_file_map_all_access      = mk_win_kernel_section_all_access,
	mk_win_kernel_file_map_large_pages     = 0x20000000,
	mk_win_kernel_file_map_targets_invalid = 0x40000000,
};
typedef enum mk_win_kernel_file_map_e mk_win_kernel_file_map_t;


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
mk_win_handle_t mk_win_kernel_create_file(mk_win_widechar_t const* const file_name, mk_win_kernel_access_right_generic_t const desired_access, mk_win_kernel_file_share_t const share_mode, void* const security_attributes, mk_win_kernel_file_create_t const creation_disposition, mk_win_kernel_file_attribute_t const flags_and_attributes, mk_win_handle_t const template_file);
mk_bool_t mk_win_kernel_close_handle(mk_win_handle_t const handle);
mk_win_dword_t mk_win_kernel_get_file_size(mk_win_handle_t const file, mk_win_dword_t* const size_hi);
mk_win_dword_t mk_win_kernel_get_last_error(void);
mk_win_handle_t mk_win_kernel_create_file_mapping(mk_win_handle_t const file, void* const security_attributes, mk_win_kernel_page_protect_t const page_protect, mk_win_dword_t const max_size_hi, mk_win_dword_t const max_size_lo, mk_win_widechar_t const* const name);
void* mk_win_kernel_map_view_of_file(mk_win_handle_t const mapping, mk_win_kernel_file_map_t const desired_access, mk_win_dword_t const file_offset_hi, mk_win_dword_t const file_offset_lo, mk_size_t const size);
mk_bool_t mk_win_kernel_unmap_view_of_file(void const* const ptr);


#endif
