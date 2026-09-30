SetFactory("OpenCASCADE");
Torus(1) = {0, 0, 0, 0.5, 0.2, 2*Pi};

// Create slice of cake:
Point(10) = {0,0,-2.5,1};
Point(11) = {5,0,-2.5,1};
Point(12) = {5/Sqrt(2),5/Sqrt(2),-2.5,1};

Line(3) = {11, 10};
Line(4) = {10, 12};

Circle(5) = {11, 10, 12};

Curve Loop(2) = {4, 3, 5};
Plane Surface(2) = {2};
Extrude {0, 0, 5} {
  Surface{2};
}

BooleanIntersection{ Volume{2}; Delete;}{ Volume{1}; Delete; }

a = Pi/4;
Periodic Surface {1} = {3} Affine {
  Cos(a),-Sin(a),0,0,
  Sin(a),Cos(a),0,0,
  0,0,-1,0}; // note the 180 deg rotation along z to get the correct surface orientation!
