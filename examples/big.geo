la = .05;
la2 = .03;

Point(newp) = {0,0,0,la};  /* Point 1 */
Point(newp) = {-1,0,0,la};  /* Point 2 */
Point(newp) = {1,0,0,la};  /* Point 3 */
Point(newp) = {1.1,0,0,la};  /* Point 4 */
Point(newp) = {-1.1,0,0,la};  /* Point 5 */
Circle(2) = {4,1,5};
Circle(3) = {3,1,2};
Point(newp) = {-.2,.4,0,la};  /* Point 6 */
Point(newp) = {-.2,.4,0,la};  /* Point 7 */
Point(newp) = {.2,.4,0,la};  /* Point 8 */
Point(newp) = {.6,.4,0,la};  /* Point 9 */
Point(newp) = {-.6,.4,0,la2};  /* Point 10 */
Point(newp) = {-.65,.4,0,la2};  /* Point 11 */
Point(newp) = {-.55,.4,0,la2};  /* Point 12 */
Point(newp) = {-.25,.4,0,la2};  /* Point 13 */
Point(newp) = {-.15,.4,0,la2};  /* Point 14 */
Point(newp) = {.15,.4,0,la2};  /* Point 15 */
Point(newp) = {.25,.4,0,la2};  /* Point 16 */
Point(newp) = {.55,.4,0,la2};  /* Point 17 */
Point(newp) = {.65,.4,0,la2};  /* Point 18 */

Circle(4) = {18,9,17};
Circle(5) = {17,9,18};
Circle(6) = {16,8,15};
Circle(7) = {15,8,16};
Circle(8) = {14,7,13};
Circle(9) = {13,7,14};
Circle(10) = {12,10,11};
Circle(11) = {11,10,12};

Line(12) = {5,2};
Line(13) = {2,3};
Line(14) = {3,4};
Loop(15) = {-12,-2,-14,3};
Plane Surface(16) = {15};
Loop(17) = {3,13};
Loop(18) = {10,11};
Loop(19) = {8,9};
Loop(20) = {6,7};
Loop(21) = {4,5};
Plane Surface(22) = {17,18,19,20,21};

Transfinite Line{12,14} = 7 Using Progression 0.9;
Transfinite Line{2,3} = 40;
Transfinite Surface{16} = {5,2,3,4};

Recombine Surface{16};
