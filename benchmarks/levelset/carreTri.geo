
l=2;
nb=5;
cl=l/nb;

Point(1) = {-l/2,-l/2,0,cl};
Point(2) = {-l/2,l/2,0,cl};
Point(3) = {l/2,l/2,0,cl};
Point(4) = {l/2,-l/2,0,cl};
//Point(3) = {2*l,l,0,cl};
//Point(4) = {2*l,0,0,cl};

Line(1) = {1,2} ;
Line(2) = {2,3} ;
Line(3) = {3,4} ;
Line(4) = {4,1} ;

Line Loop(5) = {1,2,3,4} ;
Plane Surface(6) = {5} ;
//Recombine Surface{6};

Physical Line(100) = {1};
Physical Line(200) = {2};
Physical Line(300) = {3};
Physical Line(400) = {4};
Physical Surface(1000) = {6};

Mesh 2;

Levelset Plane (1) = {0,-1,0,0.5};
//Levelset Plane (2) = {-1,0,0,0.5};
Levelset Sphere (2) = {{0,0,0},0.75};
Levelset Intersection (3) = {1,2};
Levelset CutMesh {3};

//Transfinite Line{1,3}=nb+1;
//Transfinite Line{2,4}=2*nb+1+1;
//Transfinite Surface{6}={1,2,3,4};

