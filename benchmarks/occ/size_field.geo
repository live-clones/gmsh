SetFactory("OpenCASCADE");
Disk(1) = {0, 0, 0, 4};
Physical Surface("surfacedomain") = {1};

Mesh.Algorithm = 5; // Delaunay is OK
//Mesh.Algorithm = 6; // frontal does not follow the size field

Field[3] = MathEval;
Field[3].F = ".5 - (.5-0.01)*exp(-(1./0.1) *((sqrt(x*x+y*y)-1))*((sqrt(x*x+y*y)-1)))";

Background Field = 3;
