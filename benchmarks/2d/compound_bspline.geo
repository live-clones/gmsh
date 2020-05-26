// Transfinte mesh for naca0012
Mesh.RecombineAll = 1;

Li = 50.0; // distance of inflow boundary from origin
Lo = 50.0; // distance of outflow boundary from origin

n  = 50; // points on upper/lower surface of airfoil used to define airfoil
         // These points may not appear in the mesh.

na = 20; // points on upper/lower airfoil
nv = 25; // points in wall normal direction
nw = 50; // points on wake

ra = 0.1; // bump ratio for airfoil upper/lower side
ro = 1.5; // in wall normal direction
rw = 1.11; // along wake

m = 2*n - 2; // total number of points on airfoil without repetition
             // LE and TE points are common to upper/lower surface

nle = n; // point number of LE = no. of points on upper surface
         // Point(1) is trailing edge

// NACA0012 profile
// formula taken from http://turbmodels.larc.nasa.gov/naca0012_val.html
Macro NACA0012
   x2 = x * x;
   x3 = x * x2;
   x4 = x * x3;
   y = 0.594689181*(0.298222773*Sqrt(x)
       - 0.127125232*x - 0.357907906*x2 + 0.291984971*x3 - 0.105174606*x4);
Return

// put points on upper surface of airfoil
For i In {1:n}
   theta = Pi * (i-1) / (n-1);
   x = 0.5 * (Cos(theta) + 1.0);
   Call NACA0012;
   Point(i) = {x, y, 0.0};
   xx[i] = x;
   yy[i] = y;
EndFor

// put points on lower surface of airfoil, use upper surface points and reflect
For i In {n+1:m}
   Point(i) = {xx[2*n-i], -yy[2*n-i], 0.0};
EndFor

Spline(1) = {1:n};
Spline(2) = {n:m, 1};

// incline the internal boundary starting at TE
ang = 90.0*Pi/180.0;

Point(1000) = {1.0+Cos(ang)*Li, Li, 0.0};
Point(1001) = {0.0, Li, 0.0};
Point(1002) = {-Li, 0.0, 0.0};
Point(1003) = {0.0, -Li, 0.0};
Point(1004) = {1.0+Cos(ang)*Li, -Li, 0.0};

Point(1005) = {Lo, 0.0, 0.0};
Point(1006) = {Lo, Li, 0.0};
Point(1007) = {Lo, -Li, 0.0};

Line(3) = {nle, 1002};
Line(4) = {1, 1000};
Line(5) = {1000, 1001};
Circle(6) = {1001, nle, 1002};
Circle(7) = {1002, nle, 1003};
Line(8) = {1003, 1004};
Line(9) = {1004, 1};
Compound BSpline(10) = {5,6} Using 100;
Compound BSpline(11) = {7,8} Using 100;
Line(12) = {1,1005};
Line(13) = {1005, 1006};
Line(14) = {1005, 1007};
Line(15) = {1006, 1000};
Line(16) = {1007, 1004};

Line Loop(1) = {-1,4,10,-3};
Plane Surface(1) = {1};
Transfinite Surface(1) = {nle,1,1000,1002};

Line Loop(2) = {-2,3,11,9};
Plane Surface(2) = {2};
Transfinite Surface(2) = {1002, 1004, 1, nle};

Line Loop(3) = {12,13,15,-4};
Plane Surface(3) = {3};
Transfinite Surface(3) = {1, 1005, 1006, 1000};

Line Loop(4) = {-9, -16, -14, -12};
Plane Surface(4) = {4};
Transfinite Surface(4) = {1004, 1007, 1005, 1};

Transfinite Line{1,2} = na Using Bump ra;
Transfinite Line{10,11} = na;
Transfinite Line{3,4,-9} = nv Using Progression ro;
Transfinite Line{13,14} = nv Using Progression ro;
Transfinite Line{12} = nw Using Progression rw;
Transfinite Line{-15,-16} = nw;

// set physical labels for use in boundary condition
Physical Surface(100) = {1,2,3,4};
Physical Line(1) = {10,11,15,16}; // inflow and top/bottom
Physical Line(2) = {1,2};         // upper and lower airfoil
Physical Line(3) = {13,14}; // outflow

// Uncomment this to display normal vector
//Mesh.Normals = 100;
