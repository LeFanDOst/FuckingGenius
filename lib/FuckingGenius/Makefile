# Linux=no
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

LibraryName=FuckingGenius

DirSrc=src
DirObj=obj
DirLib=lib

Compiler=g++
LibCompiler=ar
Link=-o
LibLink=-rv
Preproc=-c $(FlagsThatIWish) -fexceptions -std=c++$(CppVersion)
PreprocFlags=
# LinkFlags=$(PreprocFlags)

ifeq ($(Linux),yes)
	PreprocSysFlags=
	# LinkSysFlags=$(PreprocSysFlags)
	RM=rm -f
	cmdClean=$(RM) $(DirObj)/*.o
else
	PreprocSysFlags=
	# LinkSysFlags=$(PreprocSysFlags) -lgdi32 -luser32 -lkernel32 -lcomctl32
	RM=del
	cmdClean=$(RM) $(DirObj)\*.o
endif

Src=$(wildcard $(DirSrc)/*.cpp)
Obj=$(patsubst $(DirSrc)/%.cpp,$(DirObj)/%.o,$(Src))
Exec=lib$(LibraryName).a

ifeq ($(Linux),yes)
	cmdMrProper=$(RM) $(DirLib)/$(Exec)
else
	cmdMrProper=$(RM) $(DirLib)\$(Exec)
endif

all: $(DirLib)/$(Exec)

$(DirLib)/$(Exec): $(Obj)
	$(LibCompiler) $(LibLink) $@ $^

$(DirObj)/%.o: $(DirSrc)/%.cpp
	$(Compiler) $(Link) $@ $< $(Preproc) $(PreprocFlags) $(PreprocSysFlags)

.PONY: clean mrproper

clean:
	$(cmdClean)

mrproper:
	$(cmdMrProper)