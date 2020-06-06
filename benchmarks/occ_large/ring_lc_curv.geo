Merge "ring.brep";
Physical Volume(100) = {1};            // volume ring
Physical Volume(200) = {2};            // air volume
Physical Surface(1000) = {7};        // outer truncation boundary

Mesh.CharacteristicLengthMin = 10;
Mesh.CharacteristicLengthMax = 100;
Mesh.CharacteristicLengthFromCurvature = 1;
Mesh.MinimumElementsPerTwoPi = 20; // ele per 2*pi
