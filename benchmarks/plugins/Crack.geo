// Plugin(Crack): an interior curve embedded in a square (sealed tips, debug
// view), a curve from the boundary (open at the boundary point, new physical,
// swapped orientation) and an interior surface embedded in a cube

lc = 0.1;
Point(1) = {0, 0, 0, lc}; Point(2) = {1, 0, 0, lc};
Point(3) = {1, 1, 0, lc}; Point(4) = {0, 1, 0, lc};
Point(5) = {0, 0.25, 0, lc};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4};
Line(4) = {4, 5}; Line(5) = {5, 1};
Curve Loop(1) = {1, 2, 3, 4, 5};
Plane Surface(1) = {1};
Point(6) = {0.3, 0.6, 0, lc}; Point(7) = {0.7, 0.6, 0, lc};
Line(6) = {6, 7}; // interior crack
Point(8) = {0.4, 0.25, 0, lc};
Line(7) = {5, 8}; // edge crack
Line{6, 7} In Surface{1};
Physical Curve(10) = {6};
Physical Curve(11) = {7};
Physical Point(12) = {5};
Physical Surface(13) = {1};

lc3 = 0.25;
Point(11) = {2, 0, 0, lc3}; Point(12) = {3, 0, 0, lc3};
Point(13) = {3, 1, 0, lc3}; Point(14) = {2, 1, 0, lc3};
Line(11) = {11, 12}; Line(12) = {12, 13}; Line(13) = {13, 14}; Line(14) = {14, 11};
Curve Loop(11) = {11, 12, 13, 14};
Plane Surface(11) = {11};
Extrude {0, 0, 1} { Surface{11}; }
Point(101) = {2.3, 0.3, 0.5, lc3}; Point(102) = {2.7, 0.3, 0.5, lc3};
Point(103) = {2.7, 0.7, 0.5, lc3}; Point(104) = {2.3, 0.7, 0.5, lc3};
Line(101) = {101, 102}; Line(102) = {102, 103}; Line(103) = {103, 104};
Line(104) = {104, 101};
Curve Loop(101) = {101, 102, 103, 104};
Plane Surface(101) = {101};
Surface{101} In Volume{1};
Physical Surface(20) = {101};
Physical Volume(21) = {1};
Mesh 3;

Plugin(Crack).Dimension = 1;
Plugin(Crack).PhysicalGroup = 10;
Plugin(Crack).DebugView = 1;
Plugin(Crack).Run;
Plugin(Crack).DebugView = 0;

Plugin(Crack).PhysicalGroup = 11;
Plugin(Crack).OpenBoundaryPhysicalGroup = 12;
Plugin(Crack).NewPhysicalGroup = 14;
Plugin(Crack).SwapOrientation = 1;
Plugin(Crack).Run;
Plugin(Crack).OpenBoundaryPhysicalGroup = 0;
Plugin(Crack).NewPhysicalGroup = 0;
Plugin(Crack).SwapOrientation = 0;

Plugin(Crack).Dimension = 2;
Plugin(Crack).PhysicalGroup = 20;
Plugin(Crack).Run;
