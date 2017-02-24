//Mesh.Algorithm3D = 9;
//Mesh.Algorithm = 9;
//Mesh.Recombine3DAll = 1;
Mesh.Smoothing=1;
//Mesh.Dual = 1;
//Mesh.Voronoi=1;

lc = 0.1;
Point(1) = {0.0,0.0,0.0,lc/10};
Point(2) = {1,0.0,0.0,lc/1};
Point(3) = {1,1,0.0,lc};
Point(4) = {0,1,0.0,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(5) = {2,3,4,1};
Plane Surface(6) = {5};
Extrude {0,0.0,1} { Surface {6}; }
//Characteristic Length {10} = lc/100;
//Physical Point(1)={1 };
