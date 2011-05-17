// Gmsh project created on Fri Feb  1 12:17:44 2008

//Delete All;

RSphere = 1.;
lcSphere = .25;

RDom = 10;
lcDom = 0.7; //1.0

/*
Point(1) = {0,0,0,lcSphere};
Point(2) = {RSphere,0,0,lcSphere};
Point(3) = {0,RSphere,0,lcSphere};
Circle(1) = {2,1,3};
Point(4) = {-RSphere,0,0.0,lcSphere};
Point(5) = {0,-RSphere,0.0,lcSphere};
Circle(2) = {3,1,4};
Circle(3) = {4,1,5};
Circle(4) = {5,1,2};
Point(6) = {0,0,-RSphere,lcSphere};
Point(7) = {0,0,RSphere,lcSphere};
Circle(5) = {3,1,6};
Circle(6) = {6,1,5};
Circle(7) = {5,1,7};
Circle(8) = {7,1,3};
Circle(9) = {2,1,7};
Circle(10) = {7,1,4};
Circle(11) = {4,1,6};
Circle(12) = {6,1,2};
Line Loop(13) = {2,8,-10};
Ruled Surface(14) = {13};
Line Loop(15) = {10,3,7};
Ruled Surface(16) = {15};
Line Loop(17) = {-8,-9,1};
Ruled Surface(18) = {17};
Line Loop(19) = {-11,-2,5};
Ruled Surface(20) = {19};
Line Loop(21) = {-5,-12,-1};
Ruled Surface(22) = {21};
Line Loop(23) = {-3,11,6};
Ruled Surface(24) = {23};
Line Loop(25) = {-7,4,9};
Ruled Surface(26) = {25};
Line Loop(27) = {-4,12,-6};
Ruled Surface(28) = {27};
Surface Loop(29) = {28,26,16,14,20,24,22,18};
*/

Point(101) = {0,0,0,lcDom};
Point(102) = {RDom,0,0,lcDom};
Point(103) = {0,RDom,0,lcDom};
Circle(101) = {102,101,103};
Point(104) = {-RDom,0,0.0,lcDom};
Point(105) = {0,-RDom,0.0,lcDom};
Circle(102) = {103,101,104};
Circle(103) = {104,101,105};
Circle(104) = {105,101,102};
Point(106) = {0,0,-RDom,lcDom};
Point(107) = {0,0,RDom,lcDom};
Circle(105) = {103,101,106};
Circle(106) = {106,101,105};
Circle(107) = {105,101,107};
Circle(108) = {107,101,103};
Circle(109) = {102,101,107};
Circle(110) = {107,101,104};
Circle(111) = {104,101,106};
Circle(112) = {106,101,102};
Line Loop(113) = {102,108,-110};
Ruled Surface(114) = {113};
Line Loop(115) = {110,103,107};
Ruled Surface(116) = {115};
Line Loop(117) = {-108,-109,101};
Ruled Surface(118) = {117};
Line Loop(119) = {-111,-102,105};
Ruled Surface(120) = {119};
Line Loop(121) = {-105,-112,-101};
Ruled Surface(122) = {121};
Line Loop(123) = {-103,111,106};
Ruled Surface(124) = {123};
Line Loop(125) = {-107,104,109};
Ruled Surface(126) = {125};
Line Loop(127) = {-104,112,-106};
Ruled Surface(128) = {127};
Surface Loop(129) = {128,126,116,114,120,124,122,118};

//Volume(200) = {129,29};
Volume(200) = {129};


// Wall ID = 2100
//Physical Surface(2100) = {28,26,16,14,20,24,22,18};
// Farfield CBC ID = 2222
Physical Surface("Wall") = {128,126,116,114,120,124,122,118};
// Interior ID = 1000
Physical Volume(1000) = {200};


