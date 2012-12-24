all: _onelab.so
GMSH_DIR=../../../../
COMMON_DIR=$(GMSH_DIR)/Common
CPPFLAGS+= $(shell python-config --includes) -I$(COMMON_DIR) -DONELAB_LOADER

onelab_wrap.cpp : onelab.i
	swig -python -c++ ${CPPFLAGS} -o $@ $<

_onelab.so : onelab_wrap.cpp
	$(CXX) -shared onelab_wrap.cpp -o $@ $(CPPFLAGS) -fPIC -DSWIG
.PRECIOUS: $(OBJDIR)/%.o
