
mirror:
	cat gmsh.html |\
        sed "s/\/gmsh\//http:\/\/geuz.org\/gmsh\//g" |\
        sed "s/\/getdp\//http:\/\/geuz.org\/getdp\//g" |\
        sed "s/<!---BEGINDATE.Date: /Last updated<br>/g" |\
        sed "s/ .ENDDATE--->/<p>/g" |\
        sed "s/<!---BEGINMIRROR//g" |\
        sed "s/ENDMIRROR--->//g" \
        > gmsh-mirror.html

cgi:
	cat gmsh.html |\
        sed "s/<!---BEGINSCRIPT//g" |\
        sed "s/ENDSCRIPT--->//g" |\
        sed "s/<!---BEGINDATE.Date: /Last updated<br>/g" |\
        sed "s/ .ENDDATE--->/<p>/g" \
        > geuzaine-gmsh.cgi
	chmod 755 geuzaine-gmsh.cgi
