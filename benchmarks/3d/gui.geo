lc = 0.5;
Point(1) = {-0,0,0,lc};
Point(2) = {2.5,-0,0,lc};
Point(3) = {7.5,-0,0,lc};
Point(4) = {10,-0,0,lc};
Point(5) = {-0,2.5,0,lc};
Point(6) = {10,2.5,0,lc};
Point(8) = {3.5,2.5,0,lc};
Point(9) = {6.5,2.5,0,lc};
Point(10) = {5,0.5,0,lc};
Point(12) = {3.5,9,0,lc};
Point(13) = {6.5,9,0,lc};
Circle(1) = {8,10,9};
Translate {0.0,1.5,0} { 
// neat: we can transform the point AFTER the curve has been created
  Point{10};
}
Line(2) = {2,8};
Line(3) = {9,3};
Line(4) = {1,2};
Line(5) = {1,5};
Line(6) = {3,4};
Line(7) = {4,6};
BSpline(8) = {5,5,5,12,12,13,13,6,6,6};
Point(14) = {5,6.5,0,lc};
Point(15) = {5,8,0,lc};
Point(16) = {4,6.5,0,lc};
Point(17) = {5,5,0,lc};
Point(18) = {6,6.5,0,lc};
Ellipse(9) = {18,14,14,15};
Ellipse(10) = {15,14,14,16};
Ellipse(11) = {16,14,14,17};
Ellipse(12) = {17,14,14,18};
Line Loop(13) = {8,-7,-6,-3,-1,-2,-4,5};
Line Loop(14) = {9,10,11,12};
Plane Surface(15) = {13,14};
Extrude Surface {15, {0.0,0.0,2.5}};
