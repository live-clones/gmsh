cm = 1e-02;
cl = 0.005;


//box
Point(1) = {0, 0, 0, cl};
Point(2) = {0, 0, 10*cm, cl};
Point(3) = {10*cm, 0, 10*cm, cl};
Point(4) = {10*cm, 0, 0, cl};
Point(5) = {0, 2*cm, 0, cl};
Point(6) = {0, 2*cm, 10*cm, cl};
Point(7) = {10*cm, 2*cm, 10*cm, cl};
Point(8) = {10*cm, 2*cm, 0, cl};

//outer conductor
Point(14) = {6.25*cm, 0, 5*cm, cl};
Point(15) = {6.25*cm, 0, 4.6*cm, cl};
Point(16) = {5.85*cm, 0, 5*cm, cl};
Point(17) = {6.25*cm, 0, 5.4*cm, cl};
Point(18) = {6.65*cm, 0, 5*cm, cl};

//inner conductor
Point(19) = {6.25*cm, 1*cm, 5*cm, cl};
Point(20) = {6.25*cm, 1*cm, 4.9*cm, cl};
Point(21) = {6.15*cm, 1*cm, 5*cm, cl};
Point(22) = {6.25*cm, 1*cm, 5.1*cm, cl};
Point(23) = {6.35*cm, 1*cm, 5*cm, cl};

//box
Line(1)  = {1,2};
Line(2)  = {2,3};
Line(3)  = {3,4};
Line(4)  = {4,1};
Line(5)  = {1,5};
Line(6)  = {2,6};
Line(7)  = {3,7};
Line(8)  = {4,8};
Line(9)  = {5,6};
Line(10)  = {6,7};
Line(11)  = {7,8};
Line(12)  = {8,5};

//outer conductor
Circle(17) = {15,14,16};
Circle(18) = {16,14,17};
Circle(19) = {17,14,18};
Circle(20) = {18,14,15};

//inner conductor
Circle(21) = {20,19,21};
Circle(22) = {21,19,22};
Circle(23) = {22,19,23};
Circle(24) = {23,19,20};

//Side Walls
Line Loop(25) = {9,-6,-1,5};   Plane Surface(1) = {25};//CW
Line Loop(26) = {-10,-6,2,7};   Plane Surface(2) = {26};
Line Loop(27) = {-11,-7,3,8};   Plane Surface(3) = {27};
Line Loop(28) = {12,-5,-4,8};   Plane Surface(4) = {28};//CW

Line Loop(31) = {21,22,23,24};   Plane Surface(7) = {31}; 

//upper inner conductor volume
innerCond[] = Extrude {0,-1*cm,0}  { Surface{7}; Recombine;};

//middle inner conductor plate
Line Loop(33) = {33,34,35,36};  

//Bottom
Line Loop(30) = {1,2,3,4};   Plane Surface(6) = {30,33};   

//middle inner conductor + upper outer conductor
Line Loop(29) = {17,18,19,20};  Plane Surface(10) = {29,33};

//extrudes outside the box
outterCond[] = Extrude {0,-1*cm,0}  { Surface{10}; Recombine;};

//top
LL1 = newll;  Line Loop(LL1) = {9,10,11,12};   
S1 = news;  Plane Surface(S1) = {LL1};

SL1 = newsl;  Surface Loop(SL1) = {S1,-1,2,3,-4,-6,40,44,48,52,7};
Volume(4) = {SL1};




























