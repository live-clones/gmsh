SOLVERS=loader
SOURCES=myOS StringUtils mathex OnelabClients OnelabMessage OnelabParser metamodel

COMMON_DIR=$(GMSH_DIR)/Common
ONELAB_DIR=$(GMSH_DIR)/projects/onelab
MATHEX_DIR=$(GMSH_DIR)/contrib/MathEx

OBJDIR=objects

ifeq ($(STATICLINUX), 32)
	LDFLAGS+=-static-libgcc -static-libstdc++ -static -m32
	CPPFLAGS+= -m32
	OBJDIR=objects-static-linux32
	EXESUFFIX=32
endif
ifeq ($(STATICLINUX), 64)
	LDFLAGS+=-static-libgcc -static-libstdc++ -static
	OBJDIR=objects-static-linux64
	EXESUFFIX=64
endif
ifeq ($(MINGW), 32)
	CXX=i686-w64-mingw32-g++
	LDFLAGS+=-static-libgcc -static-libstdc++ -static -lws2_32
	OBJDIR=objects-mingw32
	EXESUFFIX=32.exe
endif
ifeq ($(MINGW), 64)
	CXX=x86_64-w64-mingw32-g++
	LDFLAGS+=-static-libgcc -static-libstdc++ -static -lws2_32
	OBJDIR=objects-mingw64
	EXESUFFIX=64.exe
endif

TARGETS=$(SOLVERS:=_onelab$(EXESUFFIX))
all : $(TARGETS)
ifndef GMSH_DIR
	@echo '"The environment variable GMSH_DIR is not set."'
	@exit
endif

CPPFLAGS+=-I$(COMMON_DIR) -I$(ONELAB_DIR) -I$(MATHEX_DIR) -g
VPATH=$(ONELAB_DIR):$(COMMON_DIR):$(MATHEX_DIR)

OBJECTS=$(foreach OBJ, $(SOURCES), $(OBJDIR)/$(OBJ).o)
$(OBJDIR)/%.o : %.cpp $(ONELAB_DIR)/*.h
	@mkdir -p $(OBJDIR) 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

%_onelab$(EXESUFFIX) : $(OBJDIR)/%.o $(OBJECTS)
	$(CXX) $< $(OBJECTS) $(LDFLAGS) -o $@

clean :
	$(RM) $(TARGETS) $(OBJDIR)/*.o

.PRECIOUS: $(OBJDIR)/%.o
