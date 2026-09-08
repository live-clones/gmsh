// Parametric boundary-only T-Q^k-T strip.  The accompanying CMake driver
// exercises k = 0, 2, 3 and 4 independently; k = 1 is covered by
// testOptimizeQuadsFastQuadTwoTriangles.geo.
General.Terminal = 1;
General.AbortOnError = 1;
General.NumThreads = 1;

If(!Exists(StripLength))
  StripLength = 0;
EndIf
boundaryCount = 2 * StripLength + 4;

// Counter-clockwise boundary numbering:
// left apex, lower row, right apex, reversed upper row.
Point(1) = {0, 0.6, 0};
For i In {0:StripLength}
  Point(2 + i) = {1 + i, 0, 0};
EndFor
Point(StripLength + 3) = {StripLength + 2, 0.6, 0};
For i In {0:StripLength}
  Point(StripLength + 4 + i) = {StripLength + 1 - i, 1.2, 0};
EndFor

For i In {1:boundaryCount - 1}
  Line(i) = {i, i + 1};
EndFor
Line(boundaryCount) = {boundaryCount, 1};
Curve Loop(1) = {1:boundaryCount};
Plane Surface(1) = {1};

Merge Sprintf("testOptimizeQuadsFastTriangleQuadStrip%g.msh", StripLength);
OptimizeMesh "OptimizeQuadsFast";
OptimizeMesh "OptimizeQuadsFast";
