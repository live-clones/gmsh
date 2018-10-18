SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 0.05;
Mesh.CharacteristicLengthMax = 0.05;

p1 = newp; Point(p1) = {0.449999988079071,0.500000000000000,0.039574999362230};
p2 = newp; Point(p2) = {0.449999988079071,0.000000000000000,-0.007677000015974};
p3 = newp; Point(p3) = {0.000000000000000,0.500000000000000,-0.012500000186265};
p4 = newp; Point(p4) = {0.000000000000000,0.000000000000000,0.025000000372529};
p5 = newp; Point(p5) = {0.000000000000000,1.000000000000000,0.025000000372529};
p6 = newp; Point(p6) = {0.449999988079071,1.000000000000000,0.015499000437558};

l1 = newl; Line(l1) = {p1,p2};
l2 = newl; Line(l2) = {p2,p3};
l3 = newl; Line(l3) = {p1,p3};
l4 = newl; Line(l4) = {p2,p4};
l5 = newl; Line(l5) = {p3,p4};
l6 = newl; Line(l6) = {p3,p5};
l7 = newl; Line(l7) = {p1,p5};
l8 = newl; Line(l8) = {p1,p6};
l9 = newl; Line(l9) = {p5,p6};

cl1 = news; Curve Loop(cl1) = {l1,l2,-l3};
s1 = news;  Plane Surface(s1) = {cl1};

// FIXME: OpenCASCADE ignore signs in loops for now: how to use them ?
cl2 = news; Curve Loop(cl2) = {-l2,l4,-l5};
s2 = news;  Plane Surface(s2) = {cl2};
cl3 = news; Curve Loop(cl3) = {l6,-l7,l3};
s3 = news;  Plane Surface(s3) = {cl3};
cl4 = news; Curve Loop(cl4) = {-l8,l7,l9};
s4 = news;  Plane Surface(s4) = {cl4};
