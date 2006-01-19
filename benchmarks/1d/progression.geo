// the mesh nodes should match the points below

Point(1) = {0,0,0,1};
Point(2) = {1,0,0,1};
Point(3) = {3,0,0,1};
Point(4) = {7,0,0,1};
Point(5) = {15,0,0,1};

n = 4; // number of intervals
r = 2; // progression

// progression using transfinite mesh

Point(6) = {0,0.4,0,1};
Point(7) = {15,0.4,0,1};
Line(1) = {6,7};
Transfinite Line {1} = n+1 Using Progression r;

// progression using extruded mesh

a = (r - 1) / (r^n - 1);
one[0] = 1;
layer[0] = 0;
For i In {1:n}
  one[i] = 1;
  layer[i] = layer[i-1] + a * r^(i-1);
EndFor
Point(10) = {0,0.8,0,1};
Extrude {15,0,0} {
  Point{10}; Layers{one[], layer[]};
}
