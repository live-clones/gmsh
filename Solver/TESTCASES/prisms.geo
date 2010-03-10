//*********** prisms.geo *************//
C = 1;
Lup = 1;
L = 1.;
lc = .1;

Point(1) = {0.0, 0.0, -Lup, lc};
Point(2) = {C  , 0.0, -Lup, lc};
Point(3) = {C  , C  , -Lup, lc};
Point(4) = {0.0, C  , -Lup, lc};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};


Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};

outpri[]= Extrude {0,0,1.2*L}{ Surface{6}; Layers{Ceil(1.2*L/lc)};Recombine;};
// outv[]= Extrude {0,0,0.5*L}{ Surface{7}; Layers{5};Recombine;};
// Printf("top surface = %g", outpri[0]);
// Printf("volume = %g", outpri[1]);
// Printf("side surfaces = %g %g %g %g", outpri[2], outpri[3], outpri[4], outpri[5]);

Mesh.Algorithm3D=4; // frontal [lobes]

Physical Surface("top") = {outpri[0]};
Physical Surface("bottom") = {6};
Physical Surface("side1") = {outpri[2]};
Physical Surface("side2") = {outpri[3]};
Physical Surface("side3") = {outpri[4]};
Physical Surface("side4") = {outpri[5]};
Physical Volume("volume") = {outpri[1]};

