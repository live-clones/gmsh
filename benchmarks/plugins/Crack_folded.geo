// Plugin(Crack) on a sharply folded curve inside a square: the side of each
// element touching the crack is taken from the crack elements it touches (the
// closest crack element overall can be on the other sheet)
lc = 0.08;
Point(1) = {0, 0, 0, lc}; Point(2) = {2, 0, 0, lc};
Point(3) = {2, 2, 0, lc}; Point(4) = {0, 2, 0, lc};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4}; Plane Surface(1) = {1};
Point(5) = {0.5, 0.9, 0, lc / 4}; Point(6) = {1.5, 1, 0, lc / 4};
Point(7) = {0.5, 1.1, 0, lc / 4};
Line(5) = {5, 6}; Line(6) = {6, 7};
Curve{5, 6} In Surface{1};
Physical Curve(1) = {5, 6};
Physical Surface(2) = {1};
Mesh 2;
Plugin(Crack).Dimension = 1;
Plugin(Crack).PhysicalGroup = 1;
Plugin(Crack).Run;
