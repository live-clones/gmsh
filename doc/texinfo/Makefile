# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

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

