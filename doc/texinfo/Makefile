# $Id: Makefile,v 1.18 2008-02-23 20:56:36 geuzaine Exp $
#
# Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
# Please report all bugs and problems to <gmsh@geuz.org>.

dvi:
	texi2dvi gmsh.texi 

ps: dvi
	dvips gmsh -o

pdf:
	texi2pdf gmsh.texi 

html:
	perl texi2html -init_file gmsh.t2h gmsh.texi
	rm -f index.html
	ln -s gmsh.html index.html

html1:
	perl texi2html -prefix gmsh-full -init_file gmsh-full.t2h gmsh.texi

html2:
	makeinfo --html gmsh.texi

info:
	makeinfo gmsh.texi

install-info:
	cp gmsh.info* /usr/info/
	install-info gmsh.info /usr/info/dir

infoz: info
	tar zcvf gmsh-info.tgz gmsh.info*

txt:
	makeinfo --no-headers gmsh.texi -o gmsh.txt

all: pdf html html1 infoz txt

clean:
	rm -f *.cp* *.fn* *.ky* *.pg* *.tp* *.vr* *.mv*\
          *.log *.toc *.aux *.dvi *.html *.txt\
          gmsh.ps gmsh.pdf gmsh.info* gmsh-info.tgz

