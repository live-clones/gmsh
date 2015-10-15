//Geometry.OldNewReg = 1;


// Define parameters
charLength = 1.0;

// allow changing transfinite constraints for Blossom
Mesh.FlexibleTransfinite = 1;

// Edge length square
lSquare = 1;

// Grid boundary layer size = d2-d1
d1 = 0.5;
d2 = 1.0;

// Wake
dw1 = 3.5;
dw2 = 6.5;
dw3 = 15.0;

// Far-field
xfff = 10.0;
yfff = 15.0;
xffb = 30.0;
yffb = 15.0;

// Use to define 4 corners of the domain
xMax = 20.0;
xMin = -8.0;
yMax = 8.0;

// Points square cylinder
p1 = newp; Point(p1) = {-d1,d1,0.0,charLength};
p2 = newp; Point(p2) = {-d1,-d1,0.0,charLength};
p3 = newp; Point(p3) = {d1,-d1,0.0,charLength};
p4 = newp; Point(p4) = {d1,d1,0.0,charLength};

// Points BL
p5 = newp; Point(p5) = {-d2,d2,0.0,charLength};
p6 = newp; Point(p6) = {-d2,-d2,0.0,charLength};
p7 = newp; Point(p7) = {d2,-d2,0.0,charLength};
p8 = newp; Point(p8) = {d2,d2,0.0,charLength};

// Lines square cylinder
l1 = newl; Line(l1) = {p1,p2};
l2 = newl; Line(l2) = {p2,p3};
l3 = newl; Line(l3) = {p3,p4};
l4 = newl; Line(l4) = {p4,p1};

// Lines BL
l5 = newl; Line(l5) = {p1,p5};
l6 = newl; Line(l6) = {p2,p6};
l7 = newl; Line(l7) = {p3,p7};
l8 = newl; Line(l8) = {p4,p8};
l9 = newl; Line(l9) = {p5,p6};
l10 = newl; Line(l10) = {p6,p7};
l11 = newl; Line(l11) = {p7,p8};
l12 = newl; Line(l12) = {p8,p5};

// Points wake
p9 = newp; Point(p9) = {dw1,dw1,0.0,charLength};
p10 = newp; Point(p10) = {dw1,-dw1,0.0,charLength};
p11 = newp; Point(p11) = {dw3,-dw2,0.0,charLength};
p12 = newp; Point(p12) = {dw3,dw2,0.0,charLength};

// Lines wake
l13 = newl; Line(l13) = {p9,p10};
l14 = newl; Line(l14) = {p10,p11};
l15 = newl; Line(l15) = {p11,p12};
l16 = newl; Line(l16) = {p12,p9};

// Connect wake to BL
l17 = newl; Line(l17) = {p8,p9};
l18 = newl; Line(l18) = {p7,p10};

// Far-field points
p13 = newp; Point(p13) = {-xfff,yfff,0.0,charLength};
p14 = newp; Point(p14) = {-xfff,-yfff,0.0,charLength};
p15 = newp; Point(p15) = {xffb,-yffb,0.0,charLength};
p16 = newp; Point(p16) = {xffb,yffb,0.0,charLength};

// Far-field lines
l19 = newl; Line(l19) = {p13,p14};
l20 = newl; Line(l20) = {p14,p15};
l21 = newl; Line(l21) = {p15,p16};
l22 = newl; Line(l22) = {p16,p13};

// Points second butterfly layer
p17 = newp; Point(p17) = {-0.75*dw1,dw1,0.0,charLength};
p18 = newp; Point(p18) = {-0.75*dw1,-dw1,0.0,charLength};

// Lines second butterfly layer
l23 = newl; Line(l23) = {p9,p17};
l24 = newl; Line(l24) = {p17,p18};
l25 = newl; Line(l25) = {p18,p10};
l26 = newl; Line(l26) = {p5,p17};
l27 = newl; Line(l27) = {p6,p18};


// Line loops
ll1 = newl; Line Loop(ll1) = {-l1,l5,l9,-l6};
ll2 = newl; Line Loop(ll2) = {-l2,l6,l10,-l7};
ll3 = newl; Line Loop(ll3) = {-l3,l7,l11,-l8};
ll4 = newl; Line Loop(ll4) = {-l4,l8,l12,-l5};
ll5 = newl; Line Loop(ll5) = {-l11,l18,-l13,-l17};
ll6 = newl; Line Loop(ll6) = {l13,l14,l15,l16};
ll7 = newl; Line Loop(ll7) = {l19,l20,l21,l22,l24,l25,l14,l15,l16,l23};
ll8 = newl; Line Loop(ll8) = {l23,-l26,-l12,l17};
ll9 = newl; Line Loop(ll9) = {l26,l24,-l27,-l9};
ll10 = newl; Line Loop(ll10) = {l27,l25,-l18,-l10};

// Surfaces
s1 = news; Plane Surface(s1) = {ll1};
s2 = news; Plane Surface(s2) = {ll2};
s3 = news; Plane Surface(s3) = {ll3};
s4 = news; Plane Surface(s4) = {ll4};
s5 = news; Plane Surface(s5) = {ll5};
s6 = news; Plane Surface(s6) = {ll6};
s7 = news; Plane Surface(s7) = {ll7};
s8 = news; Plane Surface(s8) = {ll8};
s9 = news; Plane Surface(s9) = {ll9};
s10 = news; Plane Surface(s10) = {ll10};



//Transfinite Surface{s1} = {p1,p5,p6,p2};
Transfinite Surface{s2} = {p2,p6,p7,p3};
Transfinite Surface{s3} = {p3,p7,p8,p4};
Transfinite Surface{s4} = {p4,p8,p5,p1};

//// DISTRIBUTION OF THE POINTS: The game has to be played here ;-)
///////////////////////////////////////////////////////////////////
// North, South, East square walls
Transfinite Line{l1,l2,l3,l4,l10,l12} = 25 Using Bump 0.1;
Transfinite Line{l3,l11} = 40 Using Bump 0.1;

// West square wall
Transfinite Line{l9} = 15 Using Progression 1.0;

// Four lines which connect the square and the end of the BL
Transfinite Line{-l5,-l6,-l7,-l8} = 20 Using Progression 0.9;

// First divergent part of the wake: sides
Transfinite Line{l17,l18} = 30 Using Progression 1.0;

// End first divergent part of the wake
Transfinite Line{l13} = 40 Using Progression 1.0;

// Second divergent part of wake: sides
Transfinite Line{l14,-l16} = 40 Using Progression 1.0;

// End second divergent part of the wake
Transfinite Line{l15} = 40 Using Progression 1.0;

// Second butterfly layer
Transfinite Line{l24} = 15 Using Progression 1.0;
Transfinite Line{l23,l25} = 30 Using Progression 1.0;
Transfinite Line{l26,l27} = 20 Using Progression 1.0;

// Inlet
Transfinite Line{l19} = 10 Using Progression 1.0;

// Outlet
Transfinite Line{l21} = 10 Using Progression 1.0;

// Far-field sides
Transfinite Line{l22,-l20} = 20 Using Progression 1.0;


//// Subdivides triangles in 3 quads
//Mesh.SubdivisionAlgorithm=1;

// Recombine surfaces
Recombine Surface{s1};
Recombine Surface{s2};
Recombine Surface{s3};
Recombine Surface{s4};
Recombine Surface{s5};
Recombine Surface{s6};
Recombine Surface{s7};
Recombine Surface{s8};
Recombine Surface{s9};
Recombine Surface{s10};

// Make a list of all surfaces which need to be extruded
allParts[] = {s1,s2,s3,s4,s5,s6,s7,s8,s9,s10};

// Extrude geometry and quadrilateral mesh in Z direction //
zdir[] = Extrude{0, 0, 5} { Surface{allParts[]}; Layers{1}; Recombine;};

// 3) Set background field
//    --------------------

//Field[5] = Min;
//Field[5].FieldsList = {2,4};
//Background Field = 5;
