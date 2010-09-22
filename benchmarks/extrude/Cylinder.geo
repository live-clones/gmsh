Mesh.RemeshParametrization=1; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split metis

Point(1) = {0, 0, 0};
Point(2) = {1, 0, 0};
Point(3) = {0, 1, 0};
Point(4) = {0, -1, 0};
Point(5) = {-1, 0, 0};
Circle(1) = {3, 1, 2};
Circle(2) = {2, 1, 4};
Circle(3) = {4, 1, 5};
Circle(4) = {5, 1, 3};
Extrude {0, 0, 13} {
  Line{4, 1, 2, 3};
}


Compound Surface(10000) = {20, 16, 12, 8};

