lc = 0.1;

Point(1) = {0,0,0,lc};
Point(2) = {0,1,0,lc};
Point(3) = {1,1,0,lc};
Point(4) = {1,0,0,lc};
Line(1) = {1,4};
Line(2) = {4,3};
Line(3) = {3,2};
Line(4) = {2,1};
Line Loop(5) = {3,4,1,2};

Plane Surface(6) = {5};

Transfinite Surface{6} = {1,2,3,4};
Recombine Surface{6};

Translate {2,0,0} {
  Duplicata{ Surface{6}; }
}
Translate {4,0,0} {
  Duplicata{ Surface{6}; }
}

Extrude Surface {6, {-1,1,0}, {2.5,2.5,1}, Pi/4}{
  Layers { {2/lc}, {100}, {1} }; Recombine;
};

Extrude Surface {7, {0,0,1}}{
  Layers { {1/lc}, {200}, {1} }; Recombine;
};

Extrude Surface {12, {-1,-1,0}, {2.5,2.5,1}, Pi/4}{
  Layers { {1/lc}, {300}, {1} };
};

Physical Volume(1) = {100,200,300};
Physical Surface(2) = {1:100};
Physical Line(3) = {1:100};
