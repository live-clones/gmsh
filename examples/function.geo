x = 0;
y = 0;
r = 1;
theloop = 0;

Function myCircle
  p1 = newp;
  Point (p1) = {x,y,0,0.2};
  p2 = newp;
  Point (p2) = {r+x,y,0,0.2};
  p3 = newp;
  Point (p3) = {x,r+y,0,0.2};
  p4 = newp;
  Point (p4) = {-r+x,y,0,0.2};
  p5 = newp;
  Point (p5) = {x,-r+y,0,0.2};
  c1 = newreg;
  Circle (c1) = {p2,p1,p3};
  c2 = newreg;
  Circle (c2) = {p3,p1,p4};
  c3 = newreg;
  Circle (c3) = {p4,p1,p5};
  c4 = newreg;
  Circle (c4) = {p5,p1,p2};
  theloop = newreg;
  Line Loop (theloop) = {c1,c2,c3,c4};
Return

x = 2;
y = 2;
Call myCircle;
/*loop,x,y and r should be parameters*/
loop1 = theloop;
x = -2;
y = 2;
Call myCircle;
loop2 = theloop;
x = 2;
y = -2;
Call myCircle;
loop3 = theloop;
x = -2;
y = -2;
Call myCircle;
loop4 = theloop;

r = 5;
x = 0;
y = 0;
Call myCircle;
loop5 = theloop;

Plane Surface(newreg) = {loop5,loop4,loop3,loop2,loop1};
Line(10000) = {6,11};
Attractor Line {10000} = {1,.03,1};

Mesh.Algorithm = 2 ; // This is the new 2D anisotropic algorithm


