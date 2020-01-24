Linux=no
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

FlagsThatIWish=$(DebugFlag) $(LessErrFlag) $(NoErrFlags) $(OptFlags)

DirSrc=src
DirObj=obj

MainSourceFile=main
HeaderNeeded=include/Includes.hpp

Compiler=g++
Link=-o
Preproc=-c $(FlagsThatIWish) -fexceptions -std=c++$(CppVersion)
PreprocFlags=
LinkFlags=$(PreprocFlags)

ifeq ($(Linux),yes)
	PreprocSysFlags=
	LinkSysFlags=$(PreprocSysFlags)
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
	$(Compiler) $(Link) $@ $^ $(LinkFlags) $(LinkSysFlags)

$(DirObj)/$(MainSourceFile).o: $(HeaderNeeded)

$(DirObj)/%.o: $(DirSrc)/%.cpp
	$(Compiler) $(Link) $@ $< $(Preproc) $(PreprocFlags) $(PreprocSysFlags)

.PONY: clean mrproper run

clean:
	$(cmdClean)

mrproper:
	$(RM) $(Exec)

run:
	$(ExecPerm)
	$(cmdRun)