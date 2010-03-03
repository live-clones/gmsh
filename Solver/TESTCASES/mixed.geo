//*********** mixed.geo *************//
C = 1;
Lup = 1;
L = 1.;
lc = .3;

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

outtet[] = Extrude {0,0,0.7*L} { Surface{6};};
// Printf("top surface = %g", outtet[0]);
// Printf("volume = %g", outtet[1]);
// Printf("side surfaces = %g %g %g %g", outtet[2], outtet[3], outtet[4], outtet[5]);

outpri[]= Extrude {0,0,0.5*L}{ Surface{outtet[0]}; Layers{4};Recombine;};
// outv[]= Extrude {0,0,0.5*L}{ Surface{7}; Layers{5};Recombine;};
// Printf("top surface = %g", outpri[0]);
// Printf("volume = %g", outpri[1]);
// Printf("side surfaces = %g %g %g %g", outpri[2], outpri[3], outpri[4], outpri[5]);

Mesh.Algorithm3D=4; // frontal [lobes]

Physical Surface("top") = {outpri[0]};
Physical Surface("bottom") = {5};
Physical Surface("side1") = {outpri[2],outtet[2]};
Physical Surface("side2") = {outpri[3],outtet[3]};
Physical Surface("side3") = {outpri[4],outtet[4]};
Physical Surface("side4") = {outpri[5],outtet[5]};
Physical Volume("volume") = {outtet[1],outpri[1]};

