// This example shows the possibility of inserting embedded points and lines on
// periodic surfaces

SetFactory("OpenCASCADE");
Sphere(1) = {0, 0, 0, 0.5, -Pi/2, Pi/2, 2*Pi};

Characteristic Length {1, 2} = 1.0;
Mesh.CharacteristicLengthFactor = 1.0;

Mesh.Algorithm = 6; // Frontal