
Mesh.CharacteristicLengthFactor = 2;

fact     = 0.4 ;
rondelle = fact * 0.01;
iris     = fact * 0.004;
size     = fact * 0.01;

larg = 86.36e-3 / 2.0 ;
long = 45.0e-3 ;
l    = 16.e-3 / 2.0 ;
re   = 90.e-3 / 2.0 ;
re2  = re + 3.e-3 ;
ri   = 8.e-3 / 2.0 ;
ll   = 60.0e-3 / 2.0;
a    = larg - ll;
c45  = 0.5^0.5  ;

hg   = 21.59e-3 ;
hcav = 42.5e-3 ;

x2   = long;
y1   = ri * c45;
y2   = ri ;
y3   = l ;
ss1  = l / re ;
xtemp = re * ( ( 1.0 - ss1 * ss1 ) ^ 0.5 ) ;
ss2  = ( 1.0 - ( xtemp / re2 ) * ( xtemp / re2 ) ) ^ 0.5 ;
y4   = ss2 * xtemp ;
ss3  = ll / re2;
xtemp2 = re2 *  ( ( 1.0 - ss3 * ss3 ) ^ 0.5 ) ;
x1   = long - ( xtemp - xtemp2 ) ;
x6   = x1 + xtemp ;
x3   = x6 - re * c45 ;
x4   = x6 - ri ;
x5   = x6 - ri * c45 ;
x7   = x6 + ri * c45 ;
x8   = x6 + ri ;
x9   = x6 + re * c45 ;
x10  = x6 + re ;
y5   = ll ;
y6   = re * c45 ;
y7   = re ;
y8   = larg ;


Point(1) = {0.0,0.0,0.0,size};
Point(2) = {0.0,y8,0.0,size};
Point(3) = {x2,y8,0.0,size};
Point(4) = {x2,y5,0.0,size};
Point(5) = {x1,y4,0.0,size};
Point(6) = {x1,y3,0.0,iris};
Point(7) = {x1,0.0,0.0,iris};
Point(8) = {x3,y6,0.0,size};
Point(9) = {x6,y7,0.0,size};
Point(10) = {x9,y6,0.0,size};
Point(11) = {x10,0.0,0.0,size};
Point(12) = {x8,0.0,0.0,rondelle};
Point(13) = {x6,0.0,0.0,rondelle};
Point(14) = {x4,0.0,0.0,rondelle};
Point(15) = {x7,y1,0.0,rondelle};
Point(16) = {x6,y2,0.0,rondelle};
Point(17) = {x5,y1,0.0,rondelle};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {5,6};
Line(5) = {1,7};
Line(6) = {7,14};
Line(10) = {6,7};
Line(11) = {14,13};
Line(12) = {13,12};
Circle(16) = {11,13,10};
Circle(17) = {10,13,9};
Circle(18) = {9,13,8};
Circle(19) = {8,13,6};
Circle(20) = {4,13,5};
Line(21) = {11,12};
Circle(22) = {17,13,14};
Circle(23) = {16,13,17};
Circle(24) = {15,13,16};
Circle(25) = {12,13,15};

Line Loop(26) = {-5,1,2,3,20,4,10};
Plane Surface(27) = {26};

Line Loop(28) = {-6,-10,-19,-18,-17,-16,21,25,24,23,22};
Plane Surface(29) = {28};

Line Loop(30) = {11,12,25,24,23,22};
Plane Surface(31) = {30};

Extrude Surface{27, {0,0,hg} };
Coherence;

Extrude Surface{29, {0,0,hg} };
Coherence;

Extrude Surface{31, {0,0,hg} };
Coherence;

Extrude Surface {105, {0,0,hcav-hg} };
Coherence;

Extrude Surface {126, {0,0,hcav-hg} };
Coherence;

//Characteristic Length {58,71} = 0.01; 
