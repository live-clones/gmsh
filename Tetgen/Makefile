# makefile for Tetgen
#
# Type "make" to compile tetgen.
#
# After compiling, type "tetgen -h" to read instructions
#   for using this programs.
#
# Type "make clean" to delete all object(*.o) files.

# BIN is the directory where you want to put the executable programs.
# SRC is the directory in which the *.cpp source files are. 

BIN = ../bin/
SRC = ./

# CC should be set to the name of your favorite C++ compiler.

CC = g++

# CSWITCHES is a list of all switches passed to the C++ compiler.  
#   You'd best using the best level of optimization.  
#
# By default, Tetgen use double precision floating point numbers.  
#   If you prefer single precision, use the -DSINGLE switch.
#   Double precision uses more memory, but improves the resolution of
#   the meshes you can generate with Tetgen.  It also reduces the
#   likelihood of a floating exception due to overflow.
#
# If yours is not a Unix system, use the -DNO_TIMER switch to eliminate 
#   the Unix-specific timer code.
#
# If you are modifying Tetgen, I recommend using the -DSELF_CHECK switch
#   while you are debugging.  Defining the SELF_CHECK symbol causes
#   Tetgen to include self-checking code.  Tetgen will execute more
#   slowly, however, so be sure to remove this switch before compiling a
#   production version.
#

CSWITCHES = -O

# Objects in lexicographic order.

OBJS = constrain.o \
       linklist.o \
       predicate.o \
       quality.o \
       tetlib.o \
       trilib.o 

# RM should be set to the name of your favorite rm (file deletion program).

RM = /bin/rm

# The action starts here.

all: tetlib tetgen

.cpp.o:
	$(CC) $(CSWITCHES) -c $<

tetlib: $(OBJS)
	ar r ../lib/Tetgen.a $(OBJS)

tetgen: tetmain.o $(OBJS)
	$(CC) $(CSWITCHES) -o $(BIN)tetgen tetmain.o $(OBJS) -lm

clean:
	$(RM) $(SRC)*.o
