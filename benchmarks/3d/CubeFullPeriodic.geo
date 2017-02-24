//Mesh.Dual = 1;
//Mesh.Voronoi=1;

lc = 0.08;
Point(1) = {0.0,0.0,0.0,lc};
Point(2) = {1,0.0,0.0,lc};
Point(3) = {1,1,0.0,lc};
Point(4) = {0,1,0.0,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(5) = {2,3,4,1};
Plane Surface(6) = {5};
Extrude {0,0.0,1}{ Surface{6}; }


Periodic Surface 28 {11, 10, 9, 8} = 6 {1, 4, 3, 2} ;
Periodic Surface 19 {-3,18,-9,14} = 27 {1, 22,11,13} ;
Periodic Surface 23 {-4,18,-10,22} = 15 {2,14,8,13} ;

//Periodic Surface 23 {22, 4, -18, -10} = 6 {1, 4, 3, 2} ;
