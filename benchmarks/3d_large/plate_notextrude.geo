// Grosseur maille (mm)
lc=1. ;
// def. des points (par ex. zmax - zmin = hauteur passage, zmin position sortie, etc)
xmin = -260. ;
xmax = 302. ;
ymin = -75. ;
ymax = 69. ;
zmin = -184. ;
zmax = -180. ;
// def du parallelipipede:
// (xmin, ymin, zmin)
// (xmax, ymin, zmin)
// (xmax, ymax, zmin)
//( xmin, ymax, zmin)
// (xmin, ymin, zpass)
// (xmax, ymin, zpass)
// (xmax, ymax, zpass)
//( xmin, ymax, zpass)
Point (1) = {xmin,ymin,zmin,lc} ;
Point (2) = {xmax,ymin,zmin,lc} ;
Point (3) = {xmax,ymax,zmin,lc} ;
Point (4) = {xmin,ymax,zmin,lc} ;
Point (5) = {xmin,ymin,zmax,lc} ;
Point (6) = {xmax,ymin,zmax,lc} ;
Point (7) = {xmax,ymax,zmax,lc} ;
Point (8) = {xmin,ymax,zmax,lc} ;
Line(1) = {1,2} ;
Line(2) = {2,3} ;
Line(3) = {3,4} ;
Line(4) = {4,1} ;
Line(5) = {2,6} ;
Line(6) = {6,7} ;
Line(7) = {7,3} ;
Line(8) = {5,6} ;
Line(9) = {7,8} ;
Line(10) = {1,5} ;
Line(11) = {4,8} ;
Line(12) = {5,8} ;
Line Loop(13) = {1,5,-8,-10} ;
Plane Surface(14)={13} ;
Line Loop(15) = {-5,2,-7,-6} ;
Plane Surface(16)={15} ;
Line Loop(17) = {-9,7,3,11} ;
Plane Surface(18)={17} ;
Line Loop(19) = {-4,11,-12,-10} ;
Plane Surface(20)={19} ;
Line Loop(21) = {9,-12,8,6} ;
Plane Surface(22)={21} ;
Line Loop(23) = {3,4,1,2} ;
Plane Surface(24)={23} ;
Surface Loop(25)={-14,16,18,20,22,24};
Volume (26)={25};
