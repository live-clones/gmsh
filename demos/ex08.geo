/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   3D with extrusion

   All important comments are marked with "README"
*/

lcp = 10;
lci = 10;

/* Plate */

Point(1) = {0,0,0,lcp};
Point(2) = {294,0,0,lcp};
Point(3) = {294,294,0,lcp};
Point(4) = {0,294,0,lcp};
Point(5) = {18,18,0,lcp};
Point(6) = {126,18,0,lcp};
Point(7) = {126,126,0,lcp};
Point(8) = {18,126,0,lcp};

/* Inductor */

Point(10) = {94,50,49,lci};
Point(11) = {94,150,49,lci};
Point(12) = {119,50,49,lci};
Point(13) = {119,150,49,lci};
Point(14) = {144,0,49,lci};
Point(15) = {144,25,49,lci};
Point(16) = {144,50,49,lci};
Point(17) = {144,150,49,lci};
Point(18) = {144,175,49,lci};
Point(19) = {144,200,49,lci};
Point(20) = {244,0,49,lci};
Point(21) = {244,25,49,lci};
Point(22) = {244,50,49,lci};
Point(23) = {244,150,49,lci};
Point(24) = {244,175,49,lci};
Point(25) = {244,200,49,lci};
Point(26) = {269,50,49,lci};
Point(27) = {269,150,49,lci};
Point(28) = {294,50,49,lci};
Point(29) = {294,150,49,lci};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};
Line(5) = {5,6};
Line(6) = {6,7};
Line(7) = {7,8};
Line(8) = {8,5};
Line(9) = {14,20};
Line(10) = {28,29};
Line(11) = {25,19};
Line(12) = {11,10};
Line(13) = {15,21};
Line(14) = {26,27};
Line(15) = {24,18};
Line(16) = {13,12};

Circle(17) = {21,22,26} ;
Circle(18) = {27,23,24} ;
Circle(19) = {18,17,13} ;
Circle(20) = {12,16,15} ;
Circle(21) = {20,22,28} ;
Circle(22) = {29,23,25} ;
Circle(23) = {19,17,11} ;
Circle(24) = {10,16,14} ;

Line Loop(25) = {4,1,2,3};
Line Loop(26) = {8,5,6,7};
Plane Surface(27) = {25,26};
Line Loop(28) = {23,12,24,9,21,10,22,11};
Line Loop(29) = {19,16,20,13,17,14,18,15};
Plane Surface(30) = {28,29};

Extrude(27, {0,0,10});
Coherence;
Extrude(30, {0,0,100});
Coherence;

Surface Loop(133) = {65,39,-27,42,45,47,56,59,62,64};
Complex Volume(134) = {133};
Surface Loop(135) = {132,78,-30,81,84,87,90,93,96,98,111,114,117,120,123,126,129,131};
Complex Volume(136) = {135};








