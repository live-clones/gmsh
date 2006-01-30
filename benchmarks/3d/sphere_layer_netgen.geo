
lc=0.1;
r1=0.3; // inner sphere radius
r2=0.6; // outer layer radius

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
v1[] = Extrude {{0.0,0.0,1.0}, {0.0,0.0,0.0},-2*Pi/3}{ Surface {12}; };
v2[] = Extrude {{0.0,0.0,1.0}, {0.0,0.0,0.0},-2*Pi/3}{ Surface {v1[0]}; };
v3[] = Extrude {{0.0,0.0,1.0}, {0.0,0.0,0.0},-2*Pi/3}{ Surface {v2[0]}; };

// extrude outer slice to get outer spherical layer
v4[] = Extrude {{0.0,0.0,1.0}, {0.0,0.0,0.0},-2*Pi/3}{ Surface {13}; };
v5[] = Extrude {{0.0,0.0,1.0}, {0.0,0.0,0.0},-2*Pi/3}{ Surface {v4[0]}; };
v6[] = Extrude {{0.0,0.0,1.0}, {0.0,0.0,0.0},-2*Pi/3}{ Surface {v5[0]}; };

Delete { 
  Volume{v1[1], v2[1], v3[1], v4[1], v5[1], v6[1]}; 
}

Surface Loop(112) = {36,-27,41,39};
Volume(113) = {112};
Surface Loop(114) = {86,-75,97,89,-39,-36};
Volume(115) = {114};

Surface Loop(116) = {25,27,-12,22};
Volume(117) = {116};
Surface Loop(118) = {64,-13,75,67,-25,-22};
Volume(119) = {118};

Surface Loop(120) = {53,12,-41,50};
Volume(121) = {120};
Surface Loop(122) = {111,13,-97,108,-53,-50};
Volume(123) = {122};

// assign volume number 1 to outer layer
Physical Volume(1) = {115,119,122};

// assign volume number 2 to inner sphere
Physical Volume(2) = {113,117,121};

Mesh.Algorithm3D = 4; //netgen
