# $Id: Makefile,v 1.5 2002-05-18 00:55:14 geuzaine Exp $
#
# Makefile for "libGmshTriangle.a"
#
# If yours is not a Unix system, use the -DNO_TIMER switch to eliminate the
#   Unix-specific timer code.
#
# If you are modifying Triangle, I recommend using the -DSELF_CHECK switch
#   while you are debugging.  Defining the SELF_CHECK symbol causes
#   Triangle to include self-checking code.  Triangle will execute more
#   slowly, however, so be sure to remove this switch before compiling a
#   production version.
#
# If the size of the Triangle binary is important to you, you may wish to
#   generate a reduced version of Triangle.  The -DREDUCED switch gets rid
#   of all features that are primarily of research interest.  Specifically,
#   defining the REDUCED symbol eliminates the -i, -F, -s, and -C switches.
#   The -DCDT_ONLY switch gets rid of all meshing algorithms above and beyond
#   constrained Delaunay triangulation.  Specifically, defining the CDT_ONLY
#   symbol eliminates the -r, -q, -a, -S, and -s switches.  The REDUCED and
#   CDT_ONLY symbols may be particularly attractive when Triangle is called
#   by another program that does not need all of Triangle's features; in
#   this case, these switches should appear as part of "TRILIBDEFS" below.

.IGNORE:

CC       = gcc
AR       = ar ruvs
RM       = rm
RANLIB   = ranlib

LIB     = ../lib/libGmshTriangle.a

RMFLAGS  = -f

# Do not optimize Triangle: it fucks up on Linux
CFLAGS   = -O0 $(OS_FLAGS) -DTRILIBRARY

SRC = triangle.c

OBJ = $(SRC:.c=.o)

.SUFFIXES: .o .c

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ) 
	$(RANLIB) $(LIB)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o triangle showme tricall *.?.poly *.?.node *.?.ele

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CC) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
