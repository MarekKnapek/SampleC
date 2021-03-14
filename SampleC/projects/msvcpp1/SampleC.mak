# Microsoft Visual C++ generated build script - Do not modify

PROJ = SAMPLEC
DEBUG = 1
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
ORIGIN = MSVCNT
ORIGIN_VER = 1.00
PROJPATH = C:\DEV\PROJEKTY\SAMPLEC\SAMPLEC\PROJECTS\MSVCPP1\ 
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC = MK_APPLICATION.C
FIRSTCPP = 
RC = rc
CFLAGS_D_WEXE32 = /nologo /G3 /Za /W3 /WX /Gf /Zi /Od /FAcs /FR /Zn /MD /Fd"SampleC.pdb"
CFLAGS_R_WEXE32 = /nologo /G3 /Za /W3 /WX /Gf /O2 /Oa /Og /Oi /Op- /Ot /Oy /Ox /Ob2 /D "NDEBUG" /MD
LFLAGS_D_WEXE32 = /NOLOGO /MAP:"SampleC.map" /DEBUG /DEBUGTYPE:both /SUBSYSTEM:windows user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib olecli32.lib olesvr32.lib shell32.lib
LFLAGS_R_WEXE32 = /NOLOGO /SUBSYSTEM:windows user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib olecli32.lib olesvr32.lib shell32.lib
LFLAGS_D_LIB32 = /NOLOGO
LFLAGS_R_LIB32 = /NOLOGO
LIBS_D_WEXE32 = 
LIBS_R_WEXE32 = 
RCFLAGS32 = 
D_RCDEFINES32 = -d_DEBUG
R_RCDEFINES32 = -dNDEBUG
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WEXE32)
LFLAGS = $(LFLAGS_D_WEXE32)
LIBS = $(LIBS_D_WEXE32)
LFLAGS_LIB=$(LFLAGS_D_LIB32)
MAPFILE_OPTION = -map:$(PROJ).map
RCDEFINES = $(D_RCDEFINES32)
!else
CFLAGS = $(CFLAGS_R_WEXE32)
LFLAGS = $(LFLAGS_R_WEXE32)
LIBS = $(LIBS_R_WEXE32)
MAPFILE_OPTION = 
LFLAGS_LIB=$(LFLAGS_R_LIB32)
RCDEFINES = $(R_RCDEFINES32)
!endif
SBRS = MK_ALLOCATOR_HEAP.SBR \
		MK_APPLICATION.SBR \
		MK_CHARCONV.SBR \
		MK_CHECK_RET.SBR \
		MK_LOCK_CRITICAL_SECTION.SBR \
		MK_MAIN.SBR \
		MK_MAIN_WINDOW.SBR \
		MK_PRIMITIVES_INSTANTIATION.SBR \
		MK_TYPES.SBR \
		MK_VECTOR_INSTANTIATION.SBR \
		MK_WIN_KERNEL.SBR \
		MK_WIN_USER.SBR \
		MK_ALLOCATOR_GLOBAL.SBR \
		MK_ALLOCATOR.SBR \
		MK_ALLOCATOR_HEAP_MT.SBR \
		MK_MEM.SBR \
		MK_TASK_QUEUE.SBR \
		MK_ALLOCATOR_PROCESS_HEAP.SBR


MK_ALLOCATOR_HEAP_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_heap.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h


MK_APPLICATION_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_application.h \
	c:\dev\projekty\samplec\samplec\src\mk_main_window.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_user.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_task_queue.h \
	c:\dev\projekty\samplec\samplec\src\mk_lock_critical_section.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_primitives_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_vector_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_check_ret.h \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h


MK_CHARCONV_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_charconv.h \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h


MK_CHECK_RET_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_check_ret.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_user.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_charconv.h


MK_LOCK_CRITICAL_SECTION_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_lock_critical_section.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h


MK_MAIN_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_global.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator.h \
	c:\dev\projekty\samplec\samplec\src\mk_application.h \
	c:\dev\projekty\samplec\samplec\src\mk_main_window.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_user.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_task_queue.h \
	c:\dev\projekty\samplec\samplec\src\mk_lock_critical_section.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_primitives_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_vector_template.h


MK_MAIN_WINDOW_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_main_window.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_user.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h \
	c:\dev\projekty\samplec\samplec\src\mk_application.h \
	c:\dev\projekty\samplec\samplec\src\mk_task_queue.h \
	c:\dev\projekty\samplec\samplec\src\mk_lock_critical_section.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_primitives_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_vector_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_check_ret.h


MK_PRIMITIVES_INSTANTIATION_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_primitives_instantiation.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_primitives_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_primitives_template.c \
	c:\dev\projekty\samplec\samplec\src\mk_mem.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h


MK_TYPES_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h


MK_VECTOR_INSTANTIATION_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_vector_instantiation.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_vector_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_primitives_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_vector_template.c \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h \
	c:\dev\projekty\samplec\samplec\src\mk_check_ret.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_global.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator.h


MK_WIN_KERNEL_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h


MK_WIN_USER_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_win_user.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h


MK_ALLOCATOR_GLOBAL_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_global.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_process_heap.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h


MK_ALLOCATOR_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_allocator.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_heap.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_heap_mt.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_process_heap.h


MK_ALLOCATOR_HEAP_MT_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_heap_mt.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h


MK_MEM_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_mem.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h


MK_TASK_QUEUE_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_task_queue.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_lock_critical_section.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_primitives_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_vector_template.h \
	c:\dev\projekty\samplec\samplec\src\mk_primitives_template.c \
	c:\dev\projekty\samplec\samplec\src\mk_mem.h \
	c:\dev\projekty\samplec\samplec\src\mk_vector_template.c \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h \
	c:\dev\projekty\samplec\samplec\src\mk_check_ret.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_global.h \
	c:\dev\projekty\samplec\samplec\src\mk_allocator.h


MK_ALLOCATOR_PROCESS_HEAP_DEP =  \
	c:\dev\projekty\samplec\samplec\src\mk_allocator_process_heap.h \
	c:\dev\projekty\samplec\samplec\src\mk_windows.h \
	c:\dev\projekty\samplec\samplec\src\mk_types.h \
	c:\dev\projekty\samplec\samplec\src\mk_macros.h \
	c:\dev\projekty\samplec\samplec\src\mk_win_kernel.h \
	c:\dev\projekty\samplec\samplec\src\mk_check_ret.h \
	c:\dev\projekty\samplec\samplec\src\mk_assert.h


all:	$(PROJ).EXE $(PROJ).BSC

MK_ALLOCATOR_HEAP.OBJ:	..\..\SRC\MK_ALLOCATOR_HEAP.C $(MK_ALLOCATOR_HEAP_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_ALLOCATOR_HEAP.C

MK_APPLICATION.OBJ:	..\..\SRC\MK_APPLICATION.C $(MK_APPLICATION_DEP)
	$(CC) $(CFLAGS) $(CCREATEPCHFLAG) /c ..\..\SRC\MK_APPLICATION.C

MK_CHARCONV.OBJ:	..\..\SRC\MK_CHARCONV.C $(MK_CHARCONV_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_CHARCONV.C

MK_CHECK_RET.OBJ:	..\..\SRC\MK_CHECK_RET.C $(MK_CHECK_RET_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_CHECK_RET.C

MK_LOCK_CRITICAL_SECTION.OBJ:	..\..\SRC\MK_LOCK_CRITICAL_SECTION.C $(MK_LOCK_CRITICAL_SECTION_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_LOCK_CRITICAL_SECTION.C

MK_MAIN.OBJ:	..\..\SRC\MK_MAIN.C $(MK_MAIN_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_MAIN.C

MK_MAIN_WINDOW.OBJ:	..\..\SRC\MK_MAIN_WINDOW.C $(MK_MAIN_WINDOW_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_MAIN_WINDOW.C

MK_PRIMITIVES_INSTANTIATION.OBJ:	..\..\SRC\MK_PRIMITIVES_INSTANTIATION.C $(MK_PRIMITIVES_INSTANTIATION_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_PRIMITIVES_INSTANTIATION.C

MK_TYPES.OBJ:	..\..\SRC\MK_TYPES.C $(MK_TYPES_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_TYPES.C

MK_VECTOR_INSTANTIATION.OBJ:	..\..\SRC\MK_VECTOR_INSTANTIATION.C $(MK_VECTOR_INSTANTIATION_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_VECTOR_INSTANTIATION.C

MK_WIN_KERNEL.OBJ:	..\..\SRC\MK_WIN_KERNEL.C $(MK_WIN_KERNEL_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_WIN_KERNEL.C

MK_WIN_USER.OBJ:	..\..\SRC\MK_WIN_USER.C $(MK_WIN_USER_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_WIN_USER.C

MK_ALLOCATOR_GLOBAL.OBJ:	..\..\SRC\MK_ALLOCATOR_GLOBAL.C $(MK_ALLOCATOR_GLOBAL_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_ALLOCATOR_GLOBAL.C

MK_ALLOCATOR.OBJ:	..\..\SRC\MK_ALLOCATOR.C $(MK_ALLOCATOR_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_ALLOCATOR.C

MK_ALLOCATOR_HEAP_MT.OBJ:	..\..\SRC\MK_ALLOCATOR_HEAP_MT.C $(MK_ALLOCATOR_HEAP_MT_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_ALLOCATOR_HEAP_MT.C

MK_MEM.OBJ:	..\..\SRC\MK_MEM.C $(MK_MEM_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_MEM.C

MK_TASK_QUEUE.OBJ:	..\..\SRC\MK_TASK_QUEUE.C $(MK_TASK_QUEUE_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_TASK_QUEUE.C

MK_ALLOCATOR_PROCESS_HEAP.OBJ:	..\..\SRC\MK_ALLOCATOR_PROCESS_HEAP.C $(MK_ALLOCATOR_PROCESS_HEAP_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ..\..\SRC\MK_ALLOCATOR_PROCESS_HEAP.C


$(PROJ).EXE:	MK_ALLOCATOR_HEAP.OBJ MK_APPLICATION.OBJ MK_CHARCONV.OBJ MK_CHECK_RET.OBJ \
	MK_LOCK_CRITICAL_SECTION.OBJ MK_MAIN.OBJ MK_MAIN_WINDOW.OBJ MK_PRIMITIVES_INSTANTIATION.OBJ \
	MK_TYPES.OBJ MK_VECTOR_INSTANTIATION.OBJ MK_WIN_KERNEL.OBJ MK_WIN_USER.OBJ MK_ALLOCATOR_GLOBAL.OBJ \
	MK_ALLOCATOR.OBJ MK_ALLOCATOR_HEAP_MT.OBJ MK_MEM.OBJ MK_TASK_QUEUE.OBJ MK_ALLOCATOR_PROCESS_HEAP.OBJ $(OBJS_EXT) $(LIBS_EXT)
	echo >NUL @<<$(PROJ).CRF
MK_ALLOCATOR_HEAP.OBJ 
MK_APPLICATION.OBJ 
MK_CHARCONV.OBJ 
MK_CHECK_RET.OBJ 
MK_LOCK_CRITICAL_SECTION.OBJ 
MK_MAIN.OBJ 
MK_MAIN_WINDOW.OBJ 
MK_PRIMITIVES_INSTANTIATION.OBJ 
MK_TYPES.OBJ 
MK_VECTOR_INSTANTIATION.OBJ 
MK_WIN_KERNEL.OBJ 
MK_WIN_USER.OBJ 
MK_ALLOCATOR_GLOBAL.OBJ 
MK_ALLOCATOR.OBJ 
MK_ALLOCATOR_HEAP_MT.OBJ 
MK_MEM.OBJ 
MK_TASK_QUEUE.OBJ 
MK_ALLOCATOR_PROCESS_HEAP.OBJ 
$(OBJS_EXT)
-OUT:$(PROJ).EXE
$(MAPFILE_OPTION)

$(LIBS)
$(LIBS_EXT)
$(DEFFILE_OPTION) -implib:$(PROJ).lib
<<
	link $(LFLAGS) @$(PROJ).CRF

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
