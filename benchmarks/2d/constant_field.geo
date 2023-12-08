cm = 1e-02;
e1 = 4.5 * cm; e2 = 6 * cm / 2; e3 =  5 * cm / 2;
h1 = 5 * cm; h2 = 10 * cm; h3 = 5 * cm; h4 = 2 * cm; h5 = 4.5 * cm;
R1 = 1 * cm; R2 = 1.5 * cm; r = 1 * cm;

ccos = (-h5*R1 + e2 * Hypot(h5, Hypot(e2, R1))) / (h5^2 + e2^2);
ssin = Sqrt(1 - ccos^2);

Point(1) = {-e1-e2, 0    , 0}; Point(2) = {-e1-e2, h1   , 0};
Point(3) = {-e3-r , h1   , 0}; Point(4) = {-e3-r , h1+r , 0};
Point(5) = {-e3   , h1+r , 0}; Point(6) = {-e3   , h1+h2, 0};
Point(7) = { e3   , h1+h2, 0}; Point(8) = { e3   , h1+r , 0};
Point(9) = { e3+r , h1+r , 0}; Point(10)= { e3+r , h1   , 0};
Point(11)= { e1+e2, h1   , 0}; Point(12)= { e1+e2, 0    , 0};
Point(13)= { e2   , 0    , 0};

Point(14)= { R1 / ssin, h5+R1*ccos, 0};
Point(15)= { 0        , h5        , 0};
Point(16)= {-R1 / ssin, h5+R1*ccos, 0};
Point(17)= {-e2       , 0.0       , 0};

Point(18)= {-R2 , h1+h3   , 0}; Point(19)= {-R2 , h1+h3+h4, 0};
Point(20)= { 0  , h1+h3+h4, 0}; Point(21)= { R2 , h1+h3+h4, 0};
Point(22)= { R2 , h1+h3   , 0}; Point(23)= { 0  , h1+h3   , 0};

Point(24)= { 0, h1+h3+h4+R2, 0}; Point(25)= { 0, h1+h3-R2,  0};

Line(1)  = {1 , 17};
Line(2)  = {17, 16};

Circle(3) = {14,15,16};
Line(4)  = {14, 13}; Line(5)   = {13, 12};   Line(6)    = {12, 11};
Line(7)  = {11, 10}; Circle(8) = {8, 9, 10}; Line(9)    = {8, 7};
Line(10) = {7, 6};   Line(11)  = {6, 5};     Circle(12) = {3, 4, 5};
Line(13) = {3, 2};   Line(14)  = {2, 1};     Line(15)   = {18, 19};
Circle(16) = {21, 20, 24}; Circle(17) = {24, 20, 19};
Circle(18) = {18, 23, 25}; Circle(19) = {25, 23, 22};
Line(20) = {21,22};

Curve Loop(21) = {17, -15, 18, 19, -20, 16};
Plane Surface(22) = {21};
Curve Loop(23) = {11, -12, 13, 14, 1, 2, -3, 4, 5, 6, 7, -8, 9, 10};
Plane Surface(24) = {23, 21};

Field[1] = Constant;
Field[1].SurfacesList = {22};
Field[1].VIn = 0.001;
Field[1].VOut = 0.01;

Field[2] = Constant;
Field[2].SurfacesList = {24};
Field[2].VIn = 0.01;

Field[3] = Min;
Field[3].FieldsList = {1, 2};
Background Field = 3;

Mesh.MeshSizeExtendFromBoundary = 0;
