/*********************************************************************

From: Archi Forshop <archi4shop@yahoo.com>
To: gmsh@geuz.org
Subject: [Gmsh] Possible Bug with Orientations

Hi,

I am having problems making meshed surface elements
oriented the same way as the physical surface entity
they belong to. I'm attaching below a simple script
that shows it clearly when both Geometry-Normals and
Surface-Normals are displayed at the same time.
Different mesh algorithms produce sometimes different
orientations, all basically wrong ones.

Maybe I'm doing something wrong myself.

Archi

*********************************************************************/

lc = 1.0;

xa    = 3.0;
yb    = 1.0;
zc    = 2.0;

p1 = newp; Point(p1) = {0.0, 0.0, 0.0, lc};
p2 = newp; Point(p2) = {xa , 0.0, 0.0, lc};
p3 = newp; Point(p3) = {xa , yb , 0.0, lc};
p4 = newp; Point(p4) = {0.0, yb , 0.0, lc};
p5 = newp; Point(p5) = {0.0, 0.0, zc , lc};
p6 = newp; Point(p6) = {xa , 0.0, zc , lc};
p7 = newp; Point(p7) = {xa , yb , zc , lc};
p8 = newp; Point(p8) = {0.0, yb , zc , lc};

l1  = newreg; Line(l1)  = {p1,p2};
l2  = newreg; Line(l2)  = {p2,p3};
l3  = newreg; Line(l3)  = {p3,p4};
l4  = newreg; Line(l4)  = {p4,p1};
l5  = newreg; Line(l5)  = {p1,p5};
l6  = newreg; Line(l6)  = {p2,p6};
l7  = newreg; Line(l7)  = {p3,p7};
l8  = newreg; Line(l8)  = {p4,p8};
l9  = newreg; Line(l9)  = {p5,p6};
l10 = newreg; Line(l10) = {p6,p7};
l11 = newreg; Line(l11) = {p7,p8};
l12 = newreg; Line(l12) = {p8,p5};

llp1 = newreg; Line Loop(llp1) = {l1,l6,-l9,-l5};
llp2 = newreg; Line Loop(llp2) = {l2,l7,-l10,-l6};
llp3 = newreg; Line Loop(llp3) = {l3,l8,-l11,-l7};
llp4 = newreg; Line Loop(llp4) = {l4,l5,-l12,-l8};
llp5 = newreg; Line Loop(llp5) = {l9,l10,l11,l12};
llp6 = newreg; Line Loop(llp6) = {-l1,-l4,-l3,-l2};

s1 = newreg; Plane Surface(s1)={llp1};
s2 = newreg; Plane Surface(s2)={llp2};
s3 = newreg; Plane Surface(s3)={llp3};
s4 = newreg; Plane Surface(s4)={llp4};
s5 = newreg; Plane Surface(s5)={llp5};
s6 = newreg; Plane Surface(s6)={llp6};

slp1 = newreg; Surface Loop(slp1) =
{s1,s2,s3,s4,s5,s6};

surfPhys = newreg; Physical Surface(surfPhys) = {s1,s2,s3,s4,s5,s6};
//surfPhys = newreg; Physical Surface(surfPhys) = {s1,-s2,s3,s4,-s5,s6};
Printf("surfPhys# = %g",surfPhys);

vbrick = newreg; Complex Volume(vbrick) = {slp1};

brick = newreg; Physical Volume(brick) = {vbrick};
