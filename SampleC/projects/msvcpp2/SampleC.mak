# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "SampleC.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
MTL=MkTypLib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseO"
# PROP Intermediate_Dir "ReleaseI"
OUTDIR=.\ReleaseO
INTDIR=.\ReleaseI

ALL : $(OUTDIR)/SampleC.exe $(OUTDIR)/SampleC.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32  
# ADD BASE CPP /nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /G3 /MD /Za /W3 /WX /GX /O2 /Ob2 /D "NDEBUG" /c
# SUBTRACT CPP /YX /Fr
CPP_PROJ=/nologo /G3 /MD /Za /W3 /WX /GX /O2 /Ob2 /D "NDEBUG" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\ReleaseI/
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"SampleC.bsc" 
BSC32_SBRS= \
	

$(OUTDIR)/SampleC.bsc : $(OUTDIR)  $(BSC32_SBRS)
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /PDB:none /MACHINE:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /NOLOGO /SUBSYSTEM:windows /PDB:none /MACHINE:I386\
 /OUT:$(OUTDIR)/"SampleC.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/SampleC.obj

$(OUTDIR)/SampleC.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugO"
# PROP Intermediate_Dir "DebugI"
OUTDIR=.\DebugO
INTDIR=.\DebugI

ALL : $(OUTDIR)/SampleC.exe .\DebugI\SampleC.map $(OUTDIR)/SampleC.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE CPP /nologo /W3 /GX /Zi /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs /Fa"listing" /FR"DebugIB/" /Zn /c
# SUBTRACT CPP /YX
CPP_PROJ=/nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs /Fa"listing"\
 /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c 
CPP_OBJS=.\DebugI/
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /Iu /o$(OUTDIR)/"SampleC.bsc" 
BSC32_SBRS= \
	.\DebugIB\mk_win_user.sbr \
	.\DebugIB\mk_win_kernel.sbr \
	.\DebugIB\mk_vector_instantiation.sbr \
	.\DebugIB\mk_types.sbr \
	.\DebugIB\mk_task_queue.sbr \
	.\DebugIB\mk_primitives_instantiation.sbr \
	.\DebugIB\mk_mem.sbr \
	.\DebugIB\mk_main_window.sbr \
	.\DebugIB\mk_main.sbr \
	.\DebugIB\mk_lock_critical_section.sbr \
	.\DebugIB\mk_check_ret.sbr \
	.\DebugIB\mk_charconv.sbr \
	.\DebugIB\mk_application.sbr \
	.\DebugIB\mk_allocator_heap_mt.sbr \
	.\DebugIB\mk_allocator_heap.sbr \
	.\DebugIB\mk_allocator_global.sbr \
	.\DebugIB\mk_allocator.sbr \
	.\DebugIB\mk_allocator_process_heap.sbr

$(OUTDIR)/SampleC.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /INCREMENTAL:no /MAP /DEBUG /MACHINE:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /NOLOGO /SUBSYSTEM:windows /INCREMENTAL:no\
 /PDB:$(OUTDIR)/"SampleC.pdb" /MAP:$(INTDIR)/"SampleC.map" /DEBUG /MACHINE:I386\
 /OUT:$(OUTDIR)/"SampleC.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/mk_win_user.obj \
	$(INTDIR)/mk_win_kernel.obj \
	$(INTDIR)/mk_vector_instantiation.obj \
	$(INTDIR)/mk_types.obj \
	$(INTDIR)/mk_task_queue.obj \
	$(INTDIR)/mk_primitives_instantiation.obj \
	$(INTDIR)/mk_mem.obj \
	$(INTDIR)/mk_main_window.obj \
	$(INTDIR)/mk_main.obj \
	$(INTDIR)/mk_lock_critical_section.obj \
	$(INTDIR)/mk_check_ret.obj \
	$(INTDIR)/mk_charconv.obj \
	$(INTDIR)/mk_application.obj \
	$(INTDIR)/mk_allocator_heap_mt.obj \
	$(INTDIR)/mk_allocator_heap.obj \
	$(INTDIR)/mk_allocator_global.obj \
	$(INTDIR)/mk_allocator.obj \
	$(INTDIR)/mk_allocator_process_heap.obj

$(OUTDIR)/SampleC.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Group "Source Files"

################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\jumbo\SampleC.c
DEP_SAMPL=\
	..\..\src\mk_allocator.c\
	..\..\src\mk_allocator_global.c\
	..\..\src\mk_allocator_heap.c\
	..\..\src\mk_allocator_heap_mt.c\
	..\..\src\mk_application.c\
	..\..\src\mk_charconv.c\
	..\..\src\mk_check_ret.c\
	..\..\src\mk_lock_critical_section.c\
	..\..\src\mk_main.c\
	..\..\src\mk_main_window.c\
	..\..\src\mk_mem.c\
	..\..\src\mk_primitives_instantiation.c\
	..\..\src\mk_task_queue.c\
	..\..\src\mk_types.c\
	..\..\src\mk_vector_instantiation.c\
	..\..\src\mk_win_kernel.c\
	..\..\src\mk_win_user.c\
	\dev\projekty\SampleC\SampleC\src\mk_allocator.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_heap.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_heap_mt.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_global.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_application.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_user.h\
	\dev\projekty\SampleC\SampleC\src\mk_check_ret.h\
	\dev\projekty\SampleC\SampleC\src\mk_charconv.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_lock_critical_section.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_main_window.h\
	\dev\projekty\SampleC\SampleC\src\mk_mem.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_instantiation.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.c\
	\dev\projekty\SampleC\SampleC\src\mk_task_queue.h\
	\dev\projekty\SampleC\SampleC\src\mk_vector_template.c\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_vector_instantiation.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_vector_template.h

!IF  "$(CFG)" == "Win32 Release"

$(INTDIR)/SampleC.obj :  $(SOURCE)  $(DEP_SAMPL) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /O2 /Ob2 /D "NDEBUG" /Fo$(INTDIR)/ /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_windows.h
# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_win_user.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_win_user.c
DEP_MK_WI=\
	\dev\projekty\SampleC\SampleC\src\mk_win_user.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_win_user.obj :  $(SOURCE)  $(DEP_MK_WI) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_win_kernel.c
DEP_MK_WIN=\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_win_kernel.obj :  $(SOURCE)  $(DEP_MK_WIN) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_vector_template.h
# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_vector_template.c
DEP_MK_VE=\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_check_ret.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_global.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator.h
# PROP Exclude_From_Build 1
# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_vector_long.h
# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_vector_instantiation.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_vector_instantiation.c
DEP_MK_VEC=\
	\dev\projekty\SampleC\SampleC\src\mk_vector_instantiation.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_vector_template.c\
	\dev\projekty\SampleC\SampleC\src\mk_vector_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_check_ret.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_global.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_vector_instantiation.obj :  $(SOURCE)  $(DEP_MK_VEC) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_types.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_types.c
DEP_MK_TY=\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_types.obj :  $(SOURCE)  $(DEP_MK_TY) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_task_queue.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_task_queue.c
DEP_MK_TA=\
	\dev\projekty\SampleC\SampleC\src\mk_task_queue.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.c\
	\dev\projekty\SampleC\SampleC\src\mk_vector_template.c\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_lock_critical_section.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_vector_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_mem.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_check_ret.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_global.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_task_queue.obj :  $(SOURCE)  $(DEP_MK_TA) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_primitives_template.h
# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_primitives_template.c
DEP_MK_PR=\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_mem.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h
# PROP Exclude_From_Build 1
# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_primitives_instantiation.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_primitives_instantiation.c
DEP_MK_PRI=\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_instantiation.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.c\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_mem.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_primitives_instantiation.obj :  $(SOURCE)  $(DEP_MK_PRI) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_mem.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_mem.c
DEP_MK_ME=\
	\dev\projekty\SampleC\SampleC\src\mk_mem.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_mem.obj :  $(SOURCE)  $(DEP_MK_ME) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_main_window.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_main_window.c
DEP_MK_MA=\
	\dev\projekty\SampleC\SampleC\src\mk_main_window.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_application.h\
	\dev\projekty\SampleC\SampleC\src\mk_check_ret.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_user.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_task_queue.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_lock_critical_section.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_vector_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_main_window.obj :  $(SOURCE)  $(DEP_MK_MA) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_main.c
DEP_MK_MAI=\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_global.h\
	\dev\projekty\SampleC\SampleC\src\mk_application.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_user.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator.h\
	\dev\projekty\SampleC\SampleC\src\mk_main_window.h\
	\dev\projekty\SampleC\SampleC\src\mk_task_queue.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_lock_critical_section.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_vector_template.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_main.obj :  $(SOURCE)  $(DEP_MK_MAI) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_macros.h
# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_lock_critical_section.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_lock_critical_section.c
DEP_MK_LO=\
	\dev\projekty\SampleC\SampleC\src\mk_lock_critical_section.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_lock_critical_section.obj :  $(SOURCE)  $(DEP_MK_LO) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_check_ret.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_check_ret.c
DEP_MK_CH=\
	\dev\projekty\SampleC\SampleC\src\mk_check_ret.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_user.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_charconv.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_check_ret.obj :  $(SOURCE)  $(DEP_MK_CH) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_charconv.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_charconv.c
DEP_MK_CHA=\
	\dev\projekty\SampleC\SampleC\src\mk_charconv.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_charconv.obj :  $(SOURCE)  $(DEP_MK_CHA) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_assert.h
# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_application.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_application.c
DEP_MK_AP=\
	\dev\projekty\SampleC\SampleC\src\mk_application.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_user.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_check_ret.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_main_window.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_task_queue.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h\
	\dev\projekty\SampleC\SampleC\src\mk_lock_critical_section.h\
	\dev\projekty\SampleC\SampleC\src\mk_primitives_template.h\
	\dev\projekty\SampleC\SampleC\src\mk_vector_template.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_application.obj :  $(SOURCE)  $(DEP_MK_AP) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_allocator_heap_mt.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_allocator_heap_mt.c
DEP_MK_AL=\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_heap_mt.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_allocator_heap_mt.obj :  $(SOURCE)  $(DEP_MK_AL) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_allocator_heap.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_allocator_heap.c
DEP_MK_ALL=\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_heap.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_allocator_heap.obj :  $(SOURCE)  $(DEP_MK_ALL) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_allocator_global.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_allocator_global.c
DEP_MK_ALLO=\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_global.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_heap_mt.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_allocator_global.obj :  $(SOURCE)  $(DEP_MK_ALLO) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_allocator.h
# End Source File
################################################################################
# Begin Source File

SOURCE=..\..\src\mk_allocator.c
DEP_MK_ALLOC=\
	\dev\projekty\SampleC\SampleC\src\mk_allocator.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_heap.h\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_heap_mt.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_allocator.obj :  $(SOURCE)  $(DEP_MK_ALLOC) $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\dev\projekty\SampleC\SampleC\src\mk_allocator_process_heap.c
DEP_MK_ALLOCA=\
	\dev\projekty\SampleC\SampleC\src\mk_allocator_process_heap.h\
	\dev\projekty\SampleC\SampleC\src\mk_win_kernel.h\
	\dev\projekty\SampleC\SampleC\src\mk_check_ret.h\
	\dev\projekty\SampleC\SampleC\src\mk_assert.h\
	\dev\projekty\SampleC\SampleC\src\mk_windows.h\
	\dev\projekty\SampleC\SampleC\src\mk_types.h\
	\dev\projekty\SampleC\SampleC\src\mk_macros.h

!IF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/mk_allocator_process_heap.obj :  $(SOURCE)  $(DEP_MK_ALLOCA)\
 $(INTDIR)
   $(CPP) /nologo /G3 /MD /Za /W3 /WX /GX /Zi /Od /D "_DEBUG" /FAcs\
 /Fa"listing" /FR"DebugIB/" /Zn /Fo$(INTDIR)/ /Fd$(OUTDIR)/"SampleC.pdb" /c\
  $(SOURCE) 

!ENDIF 

# End Source File
# End Group
# End Project
################################################################################
