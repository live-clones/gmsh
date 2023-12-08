SetFactory("OpenCASCADE");
Sphere(1) = {0, 0, 0, 0.5};
Dilate {{0, 0, 0}, {1.5, 1, 0.5}} { Volume{1}; }
Mesh.Algorithm = 6;
Characteristic Length{:} = 0.1;
