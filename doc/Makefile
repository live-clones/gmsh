
RM      = rm
RMFLAGS = -f

dvi:
	texi2dvi gmsh.texi 

ps: dvi
	dvips gmsh -o

pdf:
	texi2pdf gmsh.texi 

html:
	texi2html -expandinfo -number -split_chapter gmsh.texi

html2:
	Texi2html -init_file gmsh.htmlconfig gmsh.texi

html3:
	makeinfo --html gmsh.texi

info:
	makeinfo gmsh.texi

infoz:
	gtar zcvf gmsh-info.tgz gmsh.info*

doc: ps pdf html info

install:
	cp gmsh.info* /usr/local/info/
	install-info gmsh.info /usr/local/info/dir

clean:
	$(RM) $(RMFLAGS) *.cp* *.fn* *.ky* *.pg* *.tp* *.vr* *.mv* \
                         *.log *.toc *.aux \
                         *.dvi *.ps gmsh.pdf \
                         *.html *.info* gmsh-info.tgz*


