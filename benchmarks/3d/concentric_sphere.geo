/// sphere_layer.geo
// sphere of radius r1, centered on the origin
// with an outer spherical layer of radius r2

lc=0.2;
r1=0.3;
r2=0.6;

// inner semicircle points
Point(1) = {0,0,0,lc};
Point(2) = {0,0,-r1,lc};
Point(3) = {0,-r1,0,lc};
Point(4) = {0,0,r1,lc};

// outer semicircle points
Point(5) = {0,0,-r2,lc};
Point(6) = {0,-r2,0,lc};
Point(7) = {0,0,r2,lc};

// inner semicircle lines
Line(1) = {1,2};
Circle(2) = {2,1,3};
Circle(3) = {3,1,4};
Line(4) = {4,1};

// outer semicircular slice lines
Line(5) = {2,5};
Circle(6) = {5,1,6};
Circle(7) = {6,1,7};
Line(8) = {7,4};

// inner semi-circle line loop
Line Loop(9) = {1,2,3,4};
// outer slice line loop
Line Loop(10) = {5,6,7,8,-3,-2};

// inner semi-circular plane
Plane Surface(12) = {9};
// outer layer plane
Plane Surface(13) = {10};

// extrude inner semi-circle to get inner sphere
v1[] = Extrude Surface {12, {0.0,0.0,1.0}, {0.0,0.0,0.0},2*Pi/3};;
v2[] = Extrude Surface {v1[0], {0.0,0.0,1.0}, {0.0,0.0,0.0},2*Pi/3};;
v3[] = Extrude Surface {v2[0], {0.0,0.0,1.0}, {0.0,0.0,0.0},2*Pi/3};;

// extrude outer slice to get outer spherical layer
v4[] = Extrude Surface {13, {0.0,0.0,1.0}, {0.0,0.0,0.0},2*Pi/3};;
v5[] = Extrude Surface {v4[0], {0.0,0.0,1.0}, {0.0,0.0,0.0},2*Pi/3};;
v6[] = Extrude Surface {v5[0], {0.0,0.0,1.0}, {0.0,0.0,0.0},2*Pi/3};;


//assign volume number 1 to outer layer
Physical Volume(1) = {v4[1],v5[1],v6[1]};

// assign volume number 2 to inner sphere
Physical Volume(2) = {v1[1],v2[1],v3[1]};
