# $Id: Makefile,v 1.10 2003-04-15 21:49:43 geuzaine Exp $
#
# Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA.
# 
# Please report all bugs and problems to "gmsh@geuz.org".

all:
	cd texinfo && ${MAKE} all
	gtar zcvf gmsh-doc.tgz\
          FAQ CONTRIBUTORS VERSIONS README.win32 \
          texinfo/gmsh.ps texinfo/gmsh.pdf texinfo/gmsh.txt\
          texinfo/*.html \
          texinfo/gmsh-info.tgz gmsh.1 

clean:
	rm -f *~ .*~ gmsh.ps gmsh.pdf gmsh.info*
	cd texinfo && ${MAKE} clean
