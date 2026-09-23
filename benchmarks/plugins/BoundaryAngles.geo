// Plugin(BoundaryAngles): angles along the boundary of an L-shaped triangle
// mesh and of a quadrangle mesh of a trapezoid; a second run with Remove
lc = 0.25;
Point(1) = {0, 0, 0, lc}; Point(2) = {2, 0, 0, lc}; Point(3) = {2, 1, 0, lc};
Point(4) = {1, 1, 0, lc}; Point(5) = {1, 2, 0, lc}; Point(6) = {0, 2, 0, lc};
For i In {1 : 6}
  Line(i) = {i, i % 6 + 1};
EndFor
Curve Loop(1) = {1 : 6};
Plane Surface(1) = {1};
Point(11) = {3, 0, 0, lc}; Point(12) = {5, 0, 0, lc};
Point(13) = {4.5, 1, 0, lc}; Point(14) = {3.5, 1, 0, lc};
Line(11) = {11, 12}; Line(12) = {12, 13}; Line(13) = {13, 14}; Line(14) = {14, 11};
Curve Loop(11) = {11 : 14};
Plane Surface(11) = {11};
Recombine Surface{11};
Mesh 2;

Plugin(BoundaryAngles).Visible = 1;
Plugin(BoundaryAngles).Run;
Plugin(BoundaryAngles).Remove = 1;
Plugin(BoundaryAngles).Run;
