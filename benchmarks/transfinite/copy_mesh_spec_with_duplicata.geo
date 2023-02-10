Geometry.CopyMeshingMethod=1;

Point(1) = {-0.7, 0.4, 0};
Point(2) = {0.3, 0.4, 0};
Point(3) = {0.3, 1.2, 0};
Point(4) = {-0.7, 1.2, 0};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};

Line Loop(5) = {1, 2, 3, 4};

Plane Surface(6) = {5};

Transfinite Line {1, 2, 3, 4} = 10 Using Progression 1;

Transfinite Surface {6};

Recombine Surface {6};

Rotate {{1, 0, 0}, {0, -0.01, 0}, Pi} {
  Duplicata{ Surface{6}; }
}
