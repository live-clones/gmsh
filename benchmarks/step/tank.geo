Merge "tank.brep";

n = 1;

Transfinite Line {55, 56, 13, 12, 36, 32, 95, 94, 97, 105, 
    80, 61, 64, 78, 50, 48} = 5*n; // indep.

Transfinite Line {54, 26, 24, 2, 16, 9, 4, 69, 91, 73, 71, 
    81, 51, 79, 52, 77, 98, 100, 62, 86, 102, 63, 87, 103, 
    84, 60, 38, 40, 65, 89, 75, 49} = 10*n; // indep.

Transfinite Line {5, 7, 17, 18, 28, 45, 46, 66, 47, 43, 67, 34, 58,
    59, 33, 108, 109, 110, 107} = 2*n; // indep.

Transfinite Line {101, 85, 83, 82, 99, 88, 76, 74} = 2*n; // indep.

n1 = 2*n;
n2 = 5*n;
n3 = 6*n;
Transfinite Line {23, 27} = n1;

Transfinite Line {18, 37, 1, 14, 29, 8, 22, 21, 19, 6, 3,
    15, 30, 10, 70, 72, 90, 92, 31, 11, 35, 57, 93, 96,
    104, 106, 41, 42, 44, 47, 67, 68} = n2;

Transfinite Line {20} = n3;

Transfinite Line {25, 53, 39} = 2*(n1-1) + 4*(n2-1) + (n3-1) + 1;

// automatic corners:
Transfinite Surface {1:6, 8:10, 12:13, 15:20, 23:33, 35:48};

// manual corners:
Transfinite Surface {7} = {18,19,20,21};
Transfinite Surface {14} = {21,25,26,18};

Mesh.Smoothing = 10;

Recombine Surface{1:52};
Mesh.SubdivisionAlgorithm=3;
