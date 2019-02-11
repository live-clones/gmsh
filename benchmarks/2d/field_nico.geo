h=0.05;
Point(1) = {0, 0, 0,h};
Point(2) = {0, 0.01, 0,h};
Point(3) = {1, 0.01, 0,h};
Point(4) = {1, 0.3, 0,h};
Point(5) = {-1, 0.3, 0,h};
Point(6) = {-1, 0, 0,h};
Point(7) = {-0.01, 0, 0,h};

Circle(1) = {7, 1, 2};
Line(2) = {6, 5};
Line(3) = {5, 4};
Line(4) = {4, 3};
Line(5) = {3, 2};
Line(6) = {7, 6};
Line Loop(7) = {3, 4, 5, -1, 6, 2};
Plane Surface(8) = {7};
Physical Surface(9) = {8};

// rayon du raffinement
// R =0.02
R=0.001;
// facteur de raffinement
fact=0.01;

Field[1] = Distance;
Field[1].NNodesByEdge = 100;
Field[1].EdgesList = {1};


Field[2] = MathEval;
Field[2].F = Sprintf("%g*(Exp(-%g/(F1*F1))+%g)", h, R, fact);
//

Background Field =2;
