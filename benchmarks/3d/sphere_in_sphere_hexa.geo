lc = 1;
n_patch = 5;
n_layer = 10;
R0 = 1;
R1 = 2;

Function SphereQuad
r = Sqrt(radius^2+radius^2+radius^2);
p1 = newp; Point(p1) = {r,r,-r,lc};
p2 = newp; Point(p2) = {-r,r,-r,lc};
p3 = newp; Point(p3) = {-r,-r,-r,lc};
p4 = newp; Point(p4) = {r,-r,-r,lc};
p5 = newp; Point(p5) = {r,r,r,lc};
p6 = newp; Point(p6) = {-r,r,r,lc};
p7 = newp; Point(p7) = {-r,-r,r,lc};
p8 = newp; Point(p8) = {r,-r,r,lc};
c1 = newl; Circle(c1) = {p1,p0,p2};
c2 = newl; Circle(c2) = {p2,p0,p3};
c3 = newl; Circle(c3) = {p3,p0,p4};
c4 = newl; Circle(c4) = {p4,p0,p1};
c5 = newl; Circle(c5) = {p5,p0,p6};
c6 = newl; Circle(c6) = {p6,p0,p7};
c7 = newl; Circle(c7) = {p7,p0,p8};
c8 = newl; Circle(c8) = {p8,p0,p5};
c9 = newl; Circle(c9) = {p1,p0,p5};
c10 = newl; Circle(c10) = {p2,p0,p6};
c11 = newl; Circle(c11) = {p3,p0,p7};
c12 = newl; Circle(c12) = {p4,p0,p8};
l1 = newll; Line Loop(l1) = {c1,c2,c3,c4}; 
l2 = newll; Line Loop(l2) = {c5,c6,c7,c8}; 
l3 = newll; Line Loop(l3) = {c1,c10,-c5,-c9}; 
l4 = newll; Line Loop(l4) = {c2,c11,-c6,-c10}; 
l5 = newll; Line Loop(l5) = {c3,c12,-c7,-c11};
l6 = newll; Line Loop(l6) = {c4,c9,-c8,-c12};
s1 = news; Ruled Surface(s1) = {l1};
s2 = news; Ruled Surface(s2) = {l2};
s3 = news; Ruled Surface(s3) = {l3};
s4 = news; Ruled Surface(s4) = {l4};
s5 = news; Ruled Surface(s5) = {l5};
s6 = news; Ruled Surface(s6) = {l6};
Transfinite Line{c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12} = n_patch;
Return

p0 = newp; Point(p0) = {0,0,0,lc};

radius = R0; Call SphereQuad;
radius = R1; Call SphereQuad;

// connect 2 spheres
Line(100) = {2,10};
Line(101) = {3,11};
Line(102) = {4,12};
Line(103) = {5,13};
Line(104) = {6,14};
Line(105) = {7,15};
Line(106) = {8,16};
Line(107) = {9,17};
Line Loop(100) = {1,101,-25,-100};  Plane Surface(100) = {100};
Line Loop(101) = {2,102,-26,-101};  Plane Surface(101) = {101};
Line Loop(102) = {3,103,-27,-102};  Plane Surface(102) = {102};
Line Loop(103) = {4,100,-28,-103};  Plane Surface(103) = {103};
Line Loop(104) = {5,105,-29,-104};  Plane Surface(104) = {104};
Line Loop(105) = {6,106,-30,-105};  Plane Surface(105) = {105};
Line Loop(106) = {7,107,-31,-106};  Plane Surface(106) = {106};
Line Loop(107) = {8,104,-32,-107};  Plane Surface(107) = {107};
Line Loop(108) = {9,104,-33,-100};  Plane Surface(108) = {108};
Line Loop(109) = {10,105,-34,-101}; Plane Surface(109) = {109};
Line Loop(110) = {11,106,-35,-102}; Plane Surface(110) = {110};
Line Loop(111) = {12,107,-36,-103}; Plane Surface(111) = {111};

Surface Loop(1) = {19,-100,-101,-102,-103,-43}; Volume(1) = {1};
Surface Loop(2) = {20,-104,-105,-106,-107,-44}; Volume(2) = {2};
Surface Loop(3) = {21,-100,-109,104,-45,108}; Volume(3) = {3};
Surface Loop(4) = {46,101,-22,110,-105,-109}; Volume(4) = {4};
Surface Loop(5) = {23,-102,-111,106,-47,110}; Volume(5) = {5};
Surface Loop(6) = {24,-103,-108,107,-48,111}; Volume(6) = {6};

Transfinite Line{100:107} = n_layer;
Transfinite Surface "*";
Recombine Surface "*";
Transfinite Volume "*";

Physical Volume(1) = {1:6};
Physical Surface(2) = {19:24}; // inner
Physical Surface(3) = {43:48}; // outer
