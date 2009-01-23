cl = 0.1;
Point ( 1) = {0,0,0,cl};
Point ( 2) = {6,0,0,cl};
Point ( 3) = {6,6,0,cl};
Point ( 4) = {0,6,0,cl};
BSpline (30) = {1,2,3,4,1};
Line Loop (33) = {30};
Plane Surface(28) = {33};
