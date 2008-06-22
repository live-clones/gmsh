Function IPE

// create vertices
p1 = newp; Point(p1) = {0, h, 0, lc};
p2 = newp; Point(p2) = {b, h, 0, lc};
p3 = newp; Point(p3) = {b, h-e, 0, lc};
p4 = newp; Point(p4) = {(0.5*b)+(0.5*a)+r, h-e, 0, lc};
p5 = newp; Point(p5) = {(0.5*b)+(0.5*a)+r, h-e-r, 0, lc};
p6 = newp; Point(p6) = {(0.5*b)+(0.5*a), h-e-r, 0, lc};
p7 = newp; Point(p7) = {(0.5*b)+(0.5*a), e+r, 0, lc};
p8 = newp; Point(p8) = {(0.5*b)+(0.5*a)+r, e+r, 0, lc};
p9 = newp; Point(p9) = {(0.5*b)+(0.5*a)+r, e, 0, lc};
p10 = newp; Point(p10) = {b, e, 0, lc};
p11 = newp; Point(p11) = {b, 0, 0, lc};
p12 = newp; Point(p12) = {0, 0, 0, lc};
p13 = newp; Point(p13) = {0, e, 0, lc};
p14 = newp; Point(p14) = {(0.5*b)-(0.5*a)-r, e, 0, lc};
p15 = newp; Point(p15) = {(0.5*b)-(0.5*a)-r, e+r, 0, lc};
p16 = newp; Point(p16) = {(0.5*b)-(0.5*a), e+r, 0, lc};
p17 = newp; Point(p17) = {(0.5*b)-(0.5*a), h-e-r, 0, lc};
p18 = newp; Point(p18) = {(0.5*b)-(0.5*a)-r, h-e-r, 0, lc};
p19 = newp; Point(p19) = {(0.5*b)-(0.5*a)-r, h-e, 0, lc};
p20 = newp; Point(p20) = {0, h-e, 0, lc};

// create a line from two points;
ligne1 = newl; Line(ligne1) = {p1, p2};
ligne2 = newl; Line(ligne2) = {p2, p3};
ligne3 = newl; Line(ligne3) = {p3, p4};
ligne4 = newl; Line(ligne4) = {p6, p7};
ligne5 = newl; Line(ligne5) = {p9, p10};
ligne6 = newl; Line(ligne6) = {p10, p11};
ligne7 = newl; Line(ligne7) = {p11, p12};
ligne8 = newl; Line(ligne8) = {p12, p13};
ligne9 = newl; Line(ligne9) = {p13, p14};
ligne10 = newl; Line(ligne10) = {p16, p17};
ligne11 = newl; Line(ligne11) = {p19, p20};
ligne12 = newl; Line(ligne12) = {p20, p1};

// create a curve 
Arc1 = newl; Circle(Arc1) = {p4, p5 , p6};
Arc2 = newl; Circle(Arc2) = {p7, p8 , p9};
Arc3 = newl; Circle(Arc3) = {p14, p15 , p16};
Arc4 = newl; Circle(Arc4) = {p17, p18 , p19};

// create a wire
wire = newll; Line Loop(wire) = {ligne1, ligne2, ligne3, Arc1, ligne4, Arc2, ligne5, ligne6, ligne7, ligne8, ligne9, Arc3, ligne10, Arc4, ligne11, ligne12};

// create a face
face = news; Plane Surface(face) = {wire};
Return


lc = 10;

b = 200.;
e = 16.;
h = 500.;
a = 10.2;
r = 21.;
Call IPE;

e = 40;
r = 61.;
a = 40.2;
Call IPE;
Translate{300,0,0}{Surface{face};}
