export Linux=yes
export Raspbian=yes
Debug=yes
LessError=yes
NoError=yes
Optimisation=yes
OptimisationLevel=3
CppVersion=11

ifeq ($(Debug),yes)
	DebugFlag=-g
else
	DebugFlag=
endif

ifeq ($(LessError),yes)
	LessErrFlag=-Wall
else
	LessErrFlag=
endif

ifeq ($(NoError),yes)
	NoErrFlags=-Wextra -Werror -Wfatal-errors
else
	NoErrFlags=
endif

ifeq ($(Optimisation),yes)
	OptFlags=-O$(OptimisationLevel)
else
	OptFlags=
endif

ifeq ($(Linux),yes)
	ifeq ($(Raspbian),yes)
		Defining=-DLINUX
	else
		Defining=
	endif
else
	Defining=
endif

FlagsThatIWish=$(DebugFlag)  $(Defining) $(LessErrFlag) $(NoErrFlags) $(OptFlags)

LibraryName=FuckingGenius

DirSrc=src
DirObj=obj
DirLib=lib

MainSourceFile=main
HeaderNeeded=include/Includes.hpp

Compiler=g++
Link=-o
Preproc=-c $(FlagsThatIWish) -fexceptions -std=c++$(CppVersion)
PreprocFlags=
LinkFlags=$(PreprocFlags) -L$(DirLib)/$(LibraryName)/lib -l$(LibraryName)

ifeq ($(Linux),yes)
	PreprocSysFlags=
	LinkSysFlags=$(PreprocSysFlags) -lX11
	RM=rm -f
	cmdClean=$(RM) $(DirObj)/*.o
	Extension=
else
	PreprocSysFlags=
	LinkSysFlags=$(PreprocSysFlags) -lgdi32 -luser32 -lkernel32 -lcomctl32
	RM=del
	cmdClean=$(RM) $(DirObj)\*.o
	Extension=.exe
endif

Src=$(wildcard $(DirSrc)/*.cpp)
Obj=$(patsubst $(DirSrc)/%.cpp,$(DirObj)/%.o,$(Src))
Exec=$(MainSourceFile)$(Extension)

ifeq ($(Linux),yes)
	ExecPerm=chmod u+x $(Exec) ./$(Exec)
	cmdRun=./$(Exec)
else
	ExecPerm=
	cmdRun=$(Exec)
endif

all: $(Exec)

$(Exec): $(Obj)
	@(cd $(DirLib)/$(LibraryName) && $(MAKE))
	$(Compiler) $(Link) $@ $^ $(LinkFlags) $(LinkSysFlags)

$(DirObj)/$(MainSourceFile).o: $(HeaderNeeded)

$(DirObj)/%.o: $(DirSrc)/%.cpp
	$(Compiler) $(Link) $@ $< $(Preproc) $(PreprocFlags) $(PreprocSysFlags)

.PONY: clean mrproper run

clean:
	@(cd $(DirLib)/$(LibraryName) && $(MAKE) $@)
	$(cmdClean)

mrproper:
	@(cd $(DirLib)/$(LibraryName) && $(MAKE) $@)
	$(RM) $(Exec)

run:
	$(ExecPerm)
	$(cmdRun)
