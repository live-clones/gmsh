
Point(1) = {0,0,0,10};
Point(2) = {10,10,0,1};
Point(3) = {10,0,0,1};
Point(4) = {0,10,0,1};
Line(1) = {1,4};
Line(2) = {4,2};
Line(3) = {2,3};
Line(4) = {3,1};
Line Loop(5) = {4,1,2,3};
Plane Surface(6) = {5};
Extrude Surface (6, {0,0,1});
Coherence;

Point(111) = {5,5,-.1,.2};
Point(15) = {4,4,-.1,.2};
Point(16) = {4,6,-.1,.2};
Point(17) = {6,4,-.1,.2};
Point(18) = {6,6,-.1,.2};
Arc(29) = {15,111,16};
Arc(30) = {16,111,18};
Arc(31) = {18,111,17};
Arc(32) = {17,111,15};
Line Loop(33) = {30,31,32,29};
Plane Surface(34) = {33};
Extrude Surface (34, {0,0,-1});
Coherence;
Surface Loop(57) = {56,43,34,47,51,55};
Complex Volume(58) = {57};
/*
Surface Loop(58) = {28,15,6,19,23,27};
Complex Volume(59) = {58};
*/
