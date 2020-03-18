SetFactory("OpenCASCADE");
Geometry.OCCAutoFix = 0;

// Airfoil points definition
// Airfoil points definition
x[0] = 1.000000000000;
x[1] = 0.997260950000;
x[2] = 0.989073800000;
x[3] = 0.975528260000;
x[4] = 0.956772730000;
x[5] = 0.933012700000;
x[6] = 0.904508500000;
x[7] = 0.871572410000;
x[8] = 0.834565300000;
x[9] = 0.793892630000;
x[10] = 0.750000000000;
x[11] = 0.703368320000;
x[12] = 0.654508500000;
x[13] = 0.603955850000;
x[14] = 0.552264230000;
x[15] = 0.500000000000;
x[16] = 0.447735770000;
x[17] = 0.396044150000;
x[18] = 0.345491500000;
x[19] = 0.296631680000;
x[20] = 0.250000000000;
x[21] = 0.206107370000;
x[22] = 0.165434700000;
x[23] = 0.128427590000;
x[24] = 0.095491500000;
x[25] = 0.066987300000;
x[26] = 0.043227270000;
x[27] = 0.024471740000;
x[28] = 0.010926200000;
x[29] = 0.002739050000;
x[30] = 0.000000000000;
x[31] = 0.002739050000;
x[32] = 0.010926200000;
x[33] = 0.024471740000;
x[34] = 0.043227270000;
x[35] = 0.066987300000;
x[36] = 0.095491500000;
x[37] = 0.128427590000;
x[38] = 0.165434700000;
x[39] = 0.206107370000;
x[40] = 0.250000000000;
x[41] = 0.296631680000;
x[42] = 0.345491500000;
x[43] = 0.396044150000;
x[44] = 0.447735770000;
x[45] = 0.500000000000;
x[46] = 0.552264230000;
x[47] = 0.603955850000;
x[48] = 0.654508500000;
x[49] = 0.703368320000;
x[50] = 0.750000000000;
x[51] = 0.793892630000;
x[52] = 0.834565300000;
x[53] = 0.871572410000;
x[54] = 0.904508500000;
x[55] = 0.933012700000;
x[56] = 0.956772730000;
x[57] = 0.975528260000;
x[58] = 0.989073800000;
x[59] = 0.997260950000;
x[60] = 1.000000000000;
y[0] = 0.000000000000;
y[1] = -0.000387120000;
y[2] = -0.001536530000;
y[3] = -0.003413310000;
y[4] = -0.005962090000;
y[5] = -0.009110730000;
y[6] = -0.012774640000;
y[7] = -0.016860840000;
y[8] = -0.021271280000;
y[9] = -0.025904860000;
y[10] = -0.030658060000;
y[11] = -0.035424340000;
y[12] = -0.040092730000;
y[13] = -0.044546420000;
y[14] = -0.048662010000;
y[15] = -0.052310250000;
y[16] = -0.055358620000;
y[17] = -0.057676040000;
y[18] = -0.059139400000;
y[19] = -0.059641200000;
y[20] = -0.059097420000;
y[21] = -0.057454430000;
y[22] = -0.054693790000;
y[23] = -0.050833980000;
y[24] = -0.045928610000;
y[25] = -0.040060790000;
y[26] = -0.033334310000;
y[27] = -0.025862480000;
y[28] = -0.017755950000;
y[29] = -0.009111020000;
y[30] = 0.000000000000;
y[31] = 0.009111020000;
y[32] = 0.017755950000;
y[33] = 0.025862480000;
y[34] = 0.033334310000;
y[35] = 0.040060790000;
y[36] = 0.045928610000;
y[37] = 0.050833980000;
y[38] = 0.054693790000;
y[39] = 0.057454440000;
y[40] = 0.059097420000;
y[41] = 0.059641200000;
y[42] = 0.059139400000;
y[43] = 0.057676040000;
y[44] = 0.055358620000;
y[45] = 0.052310250000;
y[46] = 0.048662010000;
y[47] = 0.044546420000;
y[48] = 0.040092730000;
y[49] = 0.035424340000;
y[50] = 0.030658060000;
y[51] = 0.025904860000;
y[52] = 0.021271280000;
y[53] = 0.016860840000;
y[54] = 0.012774640000;
y[55] = 0.009110730000;
y[56] = 0.005962090000;
y[57] = 0.003413310000;
y[58] = 0.001536530000;
y[59] = 0.000387120000;
y[60] = 0.000000000000;


// Variable definitions ========================================================
lc          = 0.05;
index_l     = 18; // lower surface point where the leading edge spline begins
index_u     = 19; // upper surface point where the leading edge spline begins
index_u =  #x[]- index_u;


le = 70; // Determines number of points in leading edge region, thus affecting the refinement in all the circular region in the continuation of the leading edge
BumpLe = 5.3; // Determines the progression of the size of elements from the leading edge to the upper and lowe surfaces
te_h = 70; // Determines the number of elements in the x direction in the portion of the domain downstream of the airfoil
te_v = 12; // Determines the number of elements in the y direction in the portion of the domain downstream of the airfoil (and therefore by matching the number of layers around the airfoil)
low = 10; // number of points on lower surface
up = 10; // number of points on upper surface
out = 18; // number of elements (radially) in the outer portion of the circular domain
out_p = 1.32; // progression associated with out
pte_h = 1.05; // progression associated with te_h
pte_v = 1.05; // progression associated with te_v


Lv = 0.35; // height of the rectangular portion of the domain trailing the airfoil
Lh = 20; // length of that same portion
L_le = 0.6; // extension of the tiny circular portion in front of leading edge
R =20; // radius of the outer circle

alpha = 90;
beta = 148; // determines the arc of the division of the outer circular portion of the domain

// Points definition airfoil ===================================================
For i In {1:#x[]-1}

    Point(i) = {x[i], y[i], 0.0, lc};

EndFor
// =============================================================================


// BSpline definition airfoil ==================================================
// Can use BSpline instead of Spline
Spline(1) = {60, 1 : index_l};
Spline(2) = {index_l: index_u};
Spline(3) = {index_u: #x[] -1};


Transfinite Line(1) = low Using Progression 1;
Transfinite Line(2) = le Using Bump BumpLe;
Transfinite Line(3) = up Using Progression 1;


// Grid around airfoil =========================================================
x[1000] = x[0] + Lh;
y[1000] = 0;
Point(1000) = {x[1000], y[1000], 0.0, lc};

x[1001] = x[1000];
y[1001] = -Lv;
Point(1001) = {x[1001], y[1001], 0.0, lc};

x[1002] = x[0];
y[1002] = -Lv;
Point(1002) = {x[1002], y[1002], 0.0, lc};

x[1003] = x[index_l] - L_le;
y[1003] = -Lv;
Point(1003) = {x[1003], y[1003], 0.0, lc};

x[1004] = x[index_u] - L_le;
y[1004] = Lv;
Point(1004) = {x[1004], y[1004], 0.0, lc};

x[1005] = x[0];
y[1005] = Lv;
Point(1005) = {x[1005], y[1005], 0.0, lc};

x[1006] = x[1000];
y[1006] = Lv;
Point(1006) = {x[1006], y[1006], 0.0, lc};

Line(4) = {60, 1000};
Transfinite Line(4) = te_h Using Progression pte_h;
Line(5) = {1000, 1001};
Transfinite Line(5) = te_v Using Progression pte_v;
Line(6) = {1002, 1001};
Transfinite Line(6) = te_h Using Progression pte_h;
Line(7) = {1002, 60};
Transfinite Line(7) = te_v Using Progression 1/pte_v;

Line(8) = {1002, 1003};
Transfinite Line(8) = low Using Progression 1;
Line(9) = {index_l, 1003};
Transfinite Line(9) = te_v Using Progression pte_v;

m = (y[1003] - y[index_l])/(x[1003] - x[index_l]);
q = y[1003] - m*x[1003];
x_center= -q/m;
Point(5000) = {x_center, 0.0, 0.0, lc};
Circle(10) = {1003, 5000, 1004};
Transfinite Line(10) = le Using Bump BumpLe;

Line(11) = {index_u, 1004};
Transfinite Line(11) = te_v Using Progression pte_v;
Line(12) = {1004, 1005};
Transfinite Line(12) = up Using Progression 1;
Line(13) = {1005, 60};
Transfinite Line(13) = te_v Using Progression 1/pte_v;
Line(14) = {1005, 1006};
Transfinite Line(14) = te_h Using Progression pte_h;
Line(15) = {1006, 1000};
Transfinite Line(15) = te_v Using Progression pte_v;

Line Loop(1) = {4, 5, -6, 7};
Plane Surface(1) = {1};
Transfinite Surface(1);
Recombine Surface(1);

Line Loop(2) = {7, 1, 9, -8};
Plane Surface(2) = {2};
Transfinite Surface(2);
Recombine Surface(2);

Line Loop(3) = {9, 10, -11, -2};
Plane Surface(3) = {3};
Transfinite Surface(3);
Recombine Surface(3);

Line Loop(4) = {-11, 3, -13, -12};
Plane Surface(4) = {4};
Transfinite Surface(4);
Recombine Surface(4);

Line Loop(5) = {13, 4, -15, -14};
Plane Surface(5) = {5};
Transfinite Surface(5);
Recombine Surface(5);

// Outer grid =========================================================



x[2001] = x[0] + Lh;
y[2001] = -R*Sin(alpha*Pi/180);
Point(2001) = {x[2001], y[2001], 0.0, lc};

x[2002] = x[0] + R*Cos(alpha*Pi/180);
y[2002] = -R*Sin(alpha*Pi/180);
Point(2002) = {x[2002], y[2002], 0.0, lc};

x[2003] = x[0] + R*Cos(beta*Pi/180);
y[2003] = -R*Sin(beta*Pi/180);
Point(2003) = {x[2003], y[2003], 0.0, lc};

x[2004] = x[0] + R*Cos(beta*Pi/180);
y[2004] = R*Sin(beta*Pi/180);
Point(2004) = {x[2004], y[2004], 0.0, lc};

x[2005] = x[0] + R*Cos(alpha*Pi/180);
y[2005] = R*Sin(alpha*Pi/180);
Point(2005) = {x[2005], y[2005], 0.0, lc};

x[2006] = x[0] + Lh;
y[2006] = R;
Point(2006) = {x[2006], y[2006], 0.0, lc};

Line(16) = {1001, 2001};
Transfinite Line(16) = out Using Progression out_p;
Line(17) = {2002, 2001};
Transfinite Line(17) = te_h Using Progression pte_h;
Line(18) = {2002, 1002};
Transfinite Line(18) = out Using Progression 1/out_p;
Circle(21) = {2002, 60, 2003};
Transfinite Line(21) = low Using Progression 1;
Line(22) = {2003, 1003};
Transfinite Line(22) = out Using Progression 1/out_p;
Circle(23) = {2003, 60, 2004};
Transfinite Line(23) = le Using Bump BumpLe;
Line(24) = {2004, 1004};
Transfinite Line(24) = out Using Progression 1/out_p;
Circle(25) = {2004, 60, 2005};
Transfinite Line(25) = up Using Progression 1;
Line(26) = {2005, 1005};
Transfinite Line(26) = out Using Progression 1/out_p;
Line(27) = {2005, 2006};
Transfinite Line(27) = te_h Using Progression pte_h;
Line(28) = {2006, 1006};
Transfinite Line(28) = out Using Progression 1/out_p;


Line Loop(6) = {16, -17, 18, 6};
Plane Surface(6) = {6};
Transfinite Surface(6);
Recombine Surface(6);


Line Loop(7) = {-8, -18, 21, 22};
Plane Surface(7) = {7};
Transfinite Surface(7);
Recombine Surface(7);

Line Loop(8) = {-22, 23, 24, -10};
Plane Surface(8) = {8};
Transfinite Surface(8);
Recombine Surface(8);

Line Loop(9) = {-12,  -24, 25, 26};
Plane Surface(9) = {9};
Transfinite Surface(9);
Recombine Surface(9);

Line Loop(10) = {14, -28, -27, 26};
Plane Surface(10) = {10};
Transfinite Surface(10);
Recombine Surface(10);

// In this last section we define physical features which NekMesh then requires to be able to convert the .msh to .xml
// Physical Surface defines the domain. The number of the physical surface will be the number of the composite
// The physical surface is defined by a sequence of Plane Surfaces defined above
Physical Surface(100) ={1,2,3,4,5,6,7,8,9,10};
// Physical Line defines a boundary. The number of the physical line will be the number of the composite. These numbers are needed to parametrize the simulation,
// namely to impose boundary conditions

// A physical line is define by a sequence of lines (note the points defining the lines must be in order)
// Inflow
Physical Line(200)={21,23,25};
// Top
Physical Line(300)={27};
// Bottom
Physical Line(400)={-17};
// Outflow
Physical Line(500)={28,15,5,16};
// Wall
Physical Line(600)={1,2,3};
