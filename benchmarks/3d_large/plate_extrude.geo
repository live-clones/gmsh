// This works fine; examine memory usage, though...

// Grosseur maille (mm)
lc=1. ;
// def. des points (par ex. zmax - zmin = hauteur passage, zmin position sortie, etc)
xmin = -260. ;
xmax = 302. ;
ymin = -75. ;
ymax = 69. ;
zmin = -184. ;
zmax = -180. ;
Point (1) = {xmin,ymin,zmin,lc} ;
Point (2) = {xmax,ymin,zmin,lc} ;
Point (3) = {xmax,ymax,zmin,lc} ;
Point (4) = {xmin,ymax,zmin,lc} ;
Line(1) = {1,2} ;
Line(2) = {2,3} ;
Line(3) = {3,4} ;
Line(4) = {4,1} ;
Line Loop(23) = {3,4,1,2} ;
Plane Surface(24)={23} ;
Extrude Surface{24, {0,0,zmax-zmin}} {Layers{3,1};};
