SetFactory("OpenCASCADE");
Sphere(1) = {0, 0, 0, 0.5};
Dilate {{0, 0, 0}, {1.5, 1, 0.5}} { Volume{1}; }

// ok in 4.7 ; broken in 4.8
Mesh.ElementOrder = 4;
Mesh.HighOrderOptimize = 2;
Mesh.MeshSizeMax = 0.11;
