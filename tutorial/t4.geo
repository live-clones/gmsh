/********************************************************************* 
 *
 *  Gmsh tutorial 4
 * 
 *  Built-in functions, holes, strings, mesh color
 *
 *********************************************************************/

// As usual, we start by defining some variables, some points and some
// lines:

cm = 1e-02;

e1 = 4.5*cm; e2 = 6*cm / 2; e3 =  5*cm / 2;

h1 = 5*cm; h2 = 10*cm; h3 = 5*cm; h4 = 2*cm; h5 = 4.5*cm;

R1 = 1*cm; R2 = 1.5*cm; r = 1*cm;

ccos = ( -h5*R1 + e2 * Hypot(h5,Hypot(e2,R1)) ) / (h5^2 + e2^2);
ssin = Sqrt(1-ccos^2);

Lc1 = 0.01;
Lc2 = 0.003;

Point(1) = { -e1-e2, 0.0  , 0.0 , Lc1};
Point(2) = { -e1-e2, h1   , 0.0 , Lc1};
Point(3) = { -e3-r , h1   , 0.0 , Lc2};
Point(4) = { -e3-r , h1+r , 0.0 , Lc2};
Point(5) = { -e3   , h1+r , 0.0 , Lc2};
Point(6) = { -e3   , h1+h2, 0.0 , Lc1};
Point(7) = {  e3   , h1+h2, 0.0 , Lc1};
Point(8) = {  e3   , h1+r , 0.0 , Lc2};
Point(9) = {  e3+r , h1+r , 0.0 , Lc2};
Point(10)= {  e3+r , h1   , 0.0 , Lc2};
Point(11)= {  e1+e2, h1   , 0.0 , Lc1};
Point(12)= {  e1+e2, 0.0  , 0.0 , Lc1};
Point(13)= {  e2   , 0.0  , 0.0 , Lc1};

Point(14)= {  R1 / ssin , h5+R1*ccos, 0.0 , Lc2};
Point(15)= {  0.0       , h5        , 0.0 , Lc2};
Point(16)= { -R1 / ssin , h5+R1*ccos, 0.0 , Lc2};
Point(17)= { -e2        , 0.0       , 0.0 , Lc1};

Point(18)= { -R2  , h1+h3   , 0.0 , Lc2};
Point(19)= { -R2  , h1+h3+h4, 0.0 , Lc2};
Point(20)= {  0.0 , h1+h3+h4, 0.0 , Lc2};
Point(21)= {  R2  , h1+h3+h4, 0.0 , Lc2};
Point(22)= {  R2  , h1+h3   , 0.0 , Lc2};
Point(23)= {  0.0 , h1+h3   , 0.0 , Lc2};

Point(24)= {  0 , h1+h3+h4+R2, 0.0 , Lc2};
Point(25)= {  0 , h1+h3-R2,    0.0 , Lc2};

Line(1)  = {1 ,17};
Line(2)  = {17,16};

// Since not all curves are straight lines, Gmsh provides many other
// curve primitives: splines, B-splines, circle arcs, ellipse arcs,
// etc. Here we define a new circle arc, starting at point 14 and
// ending at point 16, and with the circle's center being the point
// 15:

Circle(3) = {14,15,16};
 
// Note that, in Gmsh, circle arcs should always be stricly smaller
// than Pi. We can then define additional lines and circles, as well
// as a new surface:

Line(4)  = {14,13};
Line(5)  = {13,12};
Line(6)  = {12,11};
Line(7)  = {11,10};
Circle(8) = { 8, 9,10};
Line(9)  = { 8, 7};
Line(10) = { 7, 6};
Line(11) = { 6, 5};
Circle(12) = { 3, 4, 5};
Line(13) = { 3, 2};
Line(14) = { 2, 1};
Line(15) = {18,19};
Circle(16) = {21,20,24};
Circle(17) = {24,20,19};
Circle(18) = {18,23,25};
Circle(19) = {25,23,22};
Line(20) = {21,22};

Line Loop(21) = {17,-15,18,19,-20,16};
Plane Surface(22) = {21};

// But we still need to define the exterior surface. Since it has a
// hole, its definition now requires two lines loops:

Line Loop(23) = {11,-12,13,14,1,2,-3,4,5,6,7,-8,9,10};
Plane Surface(24) = {23,21};

// Finally, we can add some comments by simply embedding a
// post-processing view containg some strings, and change the color of
// some mesh entities:

View "comments" {
  // 10 pixels from the left and 15 pixels from the top of the graphic
  // window:
  T2(10,15,0){"File created on Fri Oct 18 23:50:20 2002"};

  // 10 pixels from the left and 10 pixels from the bottom of the
  // graphic window:
  T2(10,-10,0){"Copyright (C) My Company"};

  // in the model, at (X,Y,Z) = (0.0,0.11,0.0):
  T3(0,0.11,0,0){"Hole"};
};

Color White{ Surface{ 22 }; }
Color Purple{ Surface{ 24 }; }
Color Red{ Line{ 1:14 }; }
Color Yellow{ Line{ 15:20 }; }
