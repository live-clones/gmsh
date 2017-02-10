SetFactory("OpenCASCADE");

//Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

Sphere(1) = {0,0,0, 0.5};
Sphere(2) = {1,0,0, 0.5, Pi/3};
Cylinder(3) = {2,0,0, 2.5,0,0, 0.5};
Block(4) = {3,0,0, 3.5,0.5,0.5};
Torus(5) = {4,0,0, 0.3, 0.1};
Torus(6) = {5,0,0, 0.3, 0.1, Pi/3};
Cone(7) = {6,0,0, 6.5,0,0, 0.5,0};
Cone(8) = {7,0,0, 7.5,0,0, 0.5,0, Pi/3};
Cone(9) = {8,0,0, 8.5,0,0, 0.5,0.2, Pi/3};
