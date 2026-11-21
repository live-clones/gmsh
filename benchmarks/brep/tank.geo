Geometry.OCCFixDegenerated=1;
Geometry.OCCFixSmallEdges=1;
Geometry.OCCFixSmallFaces=1;
Geometry.OCCSewFaces=1;

Merge "tank.brep";

n = 2;

Transfinite Line {56, 57, 13, 12, 37, 32, 99, 98, 101, 109, 83,
    64, 67, 81, 51, 49} = 5*n; // indep.

Transfinite Line {55, 26, 24, 2, 16, 9, 4, 72, 95, 76, 74, 84, 52,
    82, 53, 80, 102, 104, 65, 90, 106, 66, 91, 107, 88, 63, 39,
    41, 68, 93, 78, 50} = 10*n; // indep.

Transfinite Line {5, 7, 17, 18, 28, 46, 47, 69, 48, 44, 70, 35,
    60, 62, 34, 113, 115, 117, 112} = 2*n; // indep.

Transfinite Line {105, 89, 86, 85, 103, 92, 79, 77} = 2*n; // indep.

n1 = 2*n;
n2 = 5*n;
n3 = 6*n;
Transfinite Line {23, 27} = n1;

Transfinite Line {18, 38, 1, 14, 29, 8, 22, 21, 19, 6, 3, 15, 30,
    10, 73, 75, 94, 96, 31, 11, 36, 58, 97, 100, 108, 110, 42, 43,
    45, 48, 70, 71} = n2;

Transfinite Line {20} = n3;

Transfinite Line {25, 54, 40} = 2*(n1-1) + 4*(n2-1) + (n3-1) + 1;

// automatic corners:
Transfinite Surface {1:6, 8:10, 12:13, 15:20, 23:33, 35:48};

// manual corners:
Transfinite Surface {7} = {18,19,20,21};
Transfinite Surface {14} = {21,25,26,18};

Mesh.Smoothing = 10;

Recombine Surface{1:52};
//Mesh.SubdivisionAlgorithm=3;
