/********************************************************************* 
 *
 * Torus.geo Gmsh Program to Construct a Torus
 *
 *********************************************************************/
 
cm  = 1e-02;          // Define our scale
Lc1 = 0.5 * cm;       // Mesh size
r1  =   4 * cm;       // Origin->Disk center radius
r2  =   1 * cm;       // Disk radius
 
r2c = r2 * Cos( Pi/4 );  // Cos/Sine terms to define disk circumference points
r2s = r2 * Sin( Pi/4 );
 
deg90 = Pi / 2;          // Radian representation of 90 Degs
 
Point(1) = { 0.0,  0.0,   0.0,  Lc1 };   // Origin
 
Point(2)  = { 0.0,  r1    ,  0.0 ,  Lc1 };   // Circle center
Point(3)  = { 0.0,  r1+r2 ,  0.0 ,  Lc1 };   // 8 points along the circumference
Point(4)  = { 0.0,  r1+r2c,  r2s ,  Lc1 };
Point(5)  = { 0.0,  r1    ,  r2  ,  Lc1 };
Point(6)  = { 0.0,  r1-r2c,  r2s ,  Lc1 };
Point(7)  = { 0.0,  r1-r2 ,  0.0 ,  Lc1 };
Point(8)  = { 0.0,  r1-r2c,  -r2s,  Lc1 };
Point(9)  = { 0.0,  r1    ,  -r2 ,  Lc1 };
Point(10) = { 0.0,  r1+r2c,  -r2s,  Lc1 };
 
Circle(1) = {  3, 2,  4 } ;   // Arcsegments along the circumference
Circle(2) = {  4, 2,  5 } ;
Circle(3) = {  5, 2,  6 } ;
Circle(4) = {  6, 2,  7 } ;
Circle(5) = {  7, 2,  8 } ;
Circle(6) = {  8, 2,  9 } ;
Circle(7) = {  9, 2, 10 } ;
Circle(8) = { 10, 2,  3 } ;
 
// Merge arcsegments into a disk 
Line Loop (9) = { 1,2,3,4,5,6,7,8 };
Plane Surface(10) = {9};
 
// Extrude the disk to form a partial torus
 
// Things are fine as long as extrusion angle is <= Pi
/* Extrude Surface {10, {0,0,1}, {0,0,0},  1* deg90 }; */
 
// Things get somewhat odd for angles > Pi
Extrude Surface {10, {0,0,1}, {0,0,0},    1.9* deg90 };// { Layers{100,10,1}; };
 
