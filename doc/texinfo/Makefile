# $Id: Makefile,v 1.1 2003-03-12 23:41:45 geuzaine Exp $

dvi:
	texi2dvi gmsh.texi 

ps: dvi
	dvips gmsh -o

pdf:
	texi2pdf gmsh.texi 

html:
	./texi2html -init_file gmsh.t2h gmsh.texi
	rm -f index.html
	ln -s gmsh.html index.html

html2:
	makeinfo --html gmsh.texi

info:
	makeinfo gmsh.texi

install-info:
	cp gmsh.info* /usr/info/
	install-info gmsh.info /usr/info/dir

infoz: info
	gtar zcvf gmsh-info.tgz gmsh.info*

all: ps pdf html infoz

clean:
	rm -f *.cp* *.fn* *.ky* *.pg* *.tp* *.vr* *.mv* \
                         *.log *.toc *.aux *.dvi *.html \
                         gmsh.ps gmsh.pdf gmsh.info* \
                         gmsh-info.tgz gmsh-doc.tgz

