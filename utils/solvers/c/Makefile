# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../../variables

solver.exe: solver.c GmshClient.c
	${CC} ${FLAGS} ${OPTIM} -o solver.exe solver.c GmshClient.c

clean:
	rm -f *.o *.exe *.pos

depend:
	true
