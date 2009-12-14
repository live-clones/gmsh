lc = 1./2.5;
Point(1) = { 0.0 ,0.0 ,0., lc};
Point(2) = { 1.0 ,0.0 ,0., lc};
Point(3) = { 1.0 ,1.0 ,0., lc};
Point(4) = { 0.0 ,1.0 ,0., lc};

// Point(1) = { 0., 0.0 ,0.0 ,lc};
// Point(2) = { 0., 1.0 ,0.0 , lc};
// Point(3) = { 0., 1.0 ,1.0 , lc};
// Point(4) = { 0., 0.0 ,1.0 , lc};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};

Line Loop(4) = {1,2,3,4};
Plane Surface(5) = {4};

Extrude {0, 0, 0.1} {
  Surface{5};
}
Surface Loop(28) = {5, 14, 18, 22, 26, 27};
Volume(29) = {28};
