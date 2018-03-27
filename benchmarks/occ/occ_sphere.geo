SetFactory("OpenCASCADE");
Sphere(1) = {0, 0, 0, 0.5, -Pi/2, Pi/2, 2*Pi};

Mesh.CharacteristicLengthFactor = 0.99;

Mesh.Algorithm = 6; // Frontal
Mesh.Algorithm3D = 2; // New Delaunay