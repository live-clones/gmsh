// an example of a purely hexahedral mesh

lc = 0.3;
Point(1) = {0,0,0,lc};
Point(2) = {1,0,0,lc};
Point(3) = {1,1,0,lc};
Point(4) = {0,1,0,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(5) = {2,3,4,1};
Plane Surface(6) = {5};

Transfinite Line{1:4} = 5;
Transfinite Surface{6} = {1,2,3,4};
Recombine Surface{6};
Extrude {0,0,1} {
  Surface{6}; Layers{5,1}; Recombine;
}


// we could do the same using only extrusions:

Point(100) = {2,0,0,lc};
l[] = Extrude {1,0,0}{
  Point{100}; Layers{4,1};
};
s[] = Extrude {0,1,0}{
  Line{l[1]}; Layers{4,1}; Recombine;
};
Extrude {0,0,1}{
  Surface{s[1]}; Layers{4,1}; Recombine;
};
