a = 0;
b = 0;
R = 1;
lc = R/10;

Point(1) = {a,b,0,lc};
Point(2) = {a+R,b,0,lc};
Line(1) = {1,2};
Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{1}; Layers {R/lc}; Recombine;
}
Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{2}; Layers {R/lc}; Recombine;
}
Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{5}; Layers {R/lc}; Recombine;
}
Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{8}; Layers {R/lc}; Recombine;
}
