#include "mk_win_kernel.h"


extern __declspec(dllimport) void __stdcall DebugBreak(void);
extern __declspec(dllimport) mk_win_handle_t __stdcall GetCurrentProcess(void);
extern __declspec(dllimport) mk_win_dword_t __stdcall GetCurrentThreadId(void);
extern __declspec(dllimport) mk_bool_t __stdcall TerminateProcess(mk_win_handle_t, mk_win_uint_t);
extern __declspec(dllimport) void __stdcall InitializeCriticalSection(mk_win_kernel_critical_section_t*);
extern __declspec(dllimport) void __stdcall EnterCriticalSection(mk_win_kernel_critical_section_t*);
extern __declspec(dllimport) void __stdcall LeaveCriticalSection(mk_win_kernel_critical_section_t*);
extern __declspec(dllimport) void __stdcall DeleteCriticalSection(mk_win_kernel_critical_section_t*);
extern __declspec(dllimport) mk_win_handle_t __stdcall GetProcessHeap(void);
extern __declspec(dllimport) mk_win_handle_t __stdcall HeapCreate(mk_win_dword_t, mk_size_t, mk_size_t);
extern __declspec(dllimport) void* __stdcall HeapAlloc(mk_win_handle_t, mk_win_dword_t, mk_size_t);
extern __declspec(dllimport) void* __stdcall HeapReAlloc(mk_win_handle_t, mk_win_dword_t, void*, mk_size_t);
extern __declspec(dllimport) mk_size_t __stdcall HeapSize(mk_win_handle_t, mk_win_dword_t, void*);
extern __declspec(dllimport) mk_win_bool_t __stdcall HeapFree(mk_win_handle_t, mk_win_dword_t, void*);
extern __declspec(dllimport) mk_win_bool_t __stdcall HeapDestroy(mk_win_handle_t);
extern __declspec(dllimport) mk_win_dword_t __stdcall GetTickCount(void);
extern __declspec(dllimport) void __stdcall OutputDebugStringA(char const*);


void mk_win_kernel_debug_break(void)
{
	DebugBreak();
}

mk_win_handle_t mk_win_kernel_get_current_process(void)
{
	mk_win_handle_t ret;
	ret = GetCurrentProcess();
	return ret;
}

mk_win_dword_t mk_win_kernel_get_current_thread_id(void)
{
	mk_win_dword_t ret;
	ret = GetCurrentThreadId();
	return ret;
}

mk_bool_t mk_win_kernel_terminate_process(mk_win_handle_t const handle, mk_win_uint_t const exit_code)
{
	mk_bool_t ret;
	ret = TerminateProcess(handle, exit_code);
	return ret;
}

void mk_win_kernel_initialize_critical_section(mk_win_kernel_critical_section_t* const critical_section)
{
	InitializeCriticalSection(critical_section);
}

void mk_win_kernel_enter_critical_section(mk_win_kernel_critical_section_t* const critical_section)
{
	EnterCriticalSection(critical_section);
}

void mk_win_kernel_leave_critical_section(mk_win_kernel_critical_section_t* const critical_section)
{
	LeaveCriticalSection(critical_section);
}

void mk_win_kernel_delete_critical_section(mk_win_kernel_critical_section_t* const critical_section)
{
	DeleteCriticalSection(critical_section);
}

mk_win_handle_t mk_win_kernel_get_process_heap(void)
{
	mk_win_handle_t ret;

	ret = GetProcessHeap();
	return ret;
}

mk_win_handle_t mk_win_kernel_heap_create(mk_win_kernel_heap_create_t const options, mk_size_t const initial_size, mk_size_t const maximum_size)
{
	mk_win_dword_t optionss;
	mk_win_handle_t ret;

	optionss.m_value = options;
	ret = HeapCreate(optionss, initial_size, maximum_size);
	return ret;
}

void* mk_win_kernel_heap_alloc(mk_win_handle_t const heap, mk_win_kernel_heap_alloc_t const flags, mk_size_t const bytes)
{
	mk_win_dword_t flagss;
	void* ret;

	flagss.m_value = flags;
	ret = HeapAlloc(heap, flagss, bytes);
	return ret;
}

void* mk_win_kernel_heap_realloc(mk_win_handle_t const heap, mk_win_kernel_heap_realloc_t const flags, void* const mem, mk_size_t const bytes)
{
	void* ret;
	mk_win_dword_t flagss;

	flagss.m_value = flags;
	ret = HeapReAlloc(heap, flagss, mem, bytes);
	return ret;
}

mk_size_t mk_win_kernel_heap_size(mk_win_handle_t const heap, mk_win_kernel_heap_size_t const flags, void* const mem)
{
	mk_win_dword_t flagss;
	mk_size_t ret;

	flagss.m_value = flags;
	ret = HeapSize(heap, flagss, mem);
	return ret;
}

mk_bool_t mk_win_kernel_heap_free(mk_win_handle_t const heap, mk_win_kernel_heap_free_t const flags, void* const mem)
{
	mk_win_dword_t flagss;
	mk_win_bool_t freed;
	mk_bool_t ret;

	flagss.m_value = flags;
	freed = HeapFree(heap, flagss, mem);
	ret = freed.m_value != 0 ? MK_TRUE : MK_FALSE;
	return ret;
}

mk_bool_t mk_win_kernel_heap_destroy(mk_win_handle_t const heap)
{
	mk_win_bool_t destroyed;
	mk_bool_t ret;

	destroyed = HeapDestroy(heap);
	ret = destroyed.m_value != 0 ? MK_TRUE : MK_FALSE;
	return ret;
}

mk_win_dword_t mk_win_kernel_get_tick_count(void)
{
	mk_win_dword_t ret;

	ret = GetTickCount();
	return ret;
}

void mk_win_kernel_output_debug_string(char const* const str)
{
	OutputDebugStringA(str);
}
