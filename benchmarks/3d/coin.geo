/*
# gmsh benchmarks/3d/coin.geo -o aa.msh -3 -clscale
# AuthenticAMD cpu MHz : 1466.431
# clscale nod elm time
1     250    1049    0.26
0.5   1635   7871    1.89
0.35  4575   23090   6.18
0.3   6943   36284   9.8
0.25  11572  62527   17.61
0.2   21939  121678  39
0.15  50181  287946  111.75
0.125 85025  496118  233.04
0.1   162625 965107  610.37
0.085 261542 1568048 1285.29
*/
lcar1 = .2;

Point(newp) = {0.5,0.5,0.5,lcar1}; /* Point      1 */
Point(newp) = {0.5,0.5,0,lcar1}; /* Point      2 */
Point(newp) = {0,0.5,0.5,lcar1}; /* Point      3 */
Point(newp) = {0,0,0.5,lcar1}; /* Point      4 */
Point(newp) = {0.5,0,0.5,lcar1}; /* Point      5 */
Point(newp) = {0.5,0,0,lcar1}; /* Point      6 */
Point(newp) = {0,0.5,0,lcar1}; /* Point      7 */
Point(newp) = {0,1,0,lcar1}; /* Point      8 */
Point(newp) = {1,1,0,lcar1}; /* Point     9 */
Point(newp) = {0,0,1,lcar1}; /* Point     10 */
Point(newp) = {0,1,1,lcar1}; /* Point     11 */
Point(newp) = {1,1,1,lcar1}; /* Point     12 */
Point(newp) = {1,0,1,lcar1}; /* Point     13 */
Point(newp) = {1,0,0,lcar1};

Line(1) = {8,9};
Line(2) = {9,12};
Line(3) = {12,11};
Line(4) = {11,8};
Line(5) = {9,14};
Line(6) = {14,13};
Line(7) = {13,12};
Line(8) = {11,10};
Line(9) = {10,13};
Line(10) = {10,4};
Line(11) = {4,5};
Line(12) = {5,6};
Line(13) = {6,2};
Line(14) = {2,1};
Line(15) = {1,3};
Line(16) = {3,7};
Line(17) = {7,2};
Line(18) = {3,4};
Line(19) = {5,1};
Line(20) = {7,8};
Line(21) = {6,14};
Line Loop(22) = {11,19,15,18};
Plane Surface(23) = {22};
Line Loop(24) = {16,17,14,15};
Plane Surface(25) = {24};
Line Loop(26) = {-17,20,1,5,-21,13};
Plane Surface(27) = {26};
Line Loop(28) = {4,1,2,3};
Plane Surface(29) = {28};
Line Loop(30) = {7,-2,5,6};
Plane Surface(31) = {30};
Line Loop(32) = {6,-9,10,11,12,21};
Plane Surface(33) = {32};
Line Loop(34) = {7,3,8,9};
Plane Surface(35) = {34};
Line Loop(36) = {10,-18,16,20,-4,8};
Plane Surface(37) = {36};
Line Loop(38) = {-14,-13,-12,19};
Plane Surface(39) = {38};
Surface Loop(40) = {35,31,29,37,33,23,39,25,27};
Complex Volume(41) = {40};
