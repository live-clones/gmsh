/*
         c8
         +---------------------+ c7
         |                 c4  |
         |   +-------------+   |
         |   | c3          +---+
         +---+             c5  c6   
         c1  c2

*/

/* Base inferieure du fer */
D1 = .05;
/* Base inferieure du fer */
D2 = .15;
D3 = .01;
D4 = .03;
D5 = .05;
D6 = .025;

ax  = 3.2;
ay  = 3.2;
az  = 3.2;
Dy = ax * D1;
Dz = ay * D2;
Dx = az * D5;

e  = 2*.001;

l = .008;
lbox = 2.*ax*l;

c1=newp;
Point(c1) = {0,0,0,l};
c2=newp;
Point(c2) = {0,D1,0,l};
c3=newp;
Point(c3) = {0,D1,D2,l};
c4=newp;
Point(c4) = {0,D3,D2,l};
c5=newp;
Point(c5) = {0,D3,D2-D4,l};
c6=newp;
Point(c6) = {0,D1-D4,D2-D4,l};
c7=newp;
Point(c7) = {0,D1-D4,D4,l};
c8=newp;
Point(c8) = {0,0,D4,l};

d1 = newreg;
Line (d1) = {c1,c2};
d2 = newreg;
Line (d2) = {c2,c3};
d3 = newreg;
Line (d3) = {c3,c4};
d4 = newreg;
Line (d4) = {c4,c5};
d5 = newreg;
Line (d5) = {c5,c6};
d6 = newreg;
Line (d6) = {c6,c7};
d7 = newreg;
Line (d7) = {c7,c8};
d8 = newreg;
Line (d8) = {c8,c1};

e1 = newreg;
Line Loop (newreg) = {d1,d2,d3,d4,d5,d6,d7,d8};
f1 = newreg;
Plane Surface (f1) = {e1};
Extrude Surface { f1, {D5,0.00000E+00, 0.00000E+00} };

box1 = newp;
Point(box1) = {Dx,Dy,Dz,lbox};
box2 = newp;
Point(box2) = {Dx,Dy,-Dz/6,lbox};
box3 = newp;
Point(box3) = {Dx,0,-Dz/6,lbox};
box4 = newp;
Point(box4) = {Dx,0,Dz,lbox};
box5 = newp;
Point(box5) = {0,Dy,-Dz/6,lbox};
box6 = newp;
Point(box6) = {0,Dy,Dz,lbox};
box7 = newp;
Point(box7) = {0,0,Dz,lbox};
box8 = newp;
Point(box8) = {0,0,-Dz/6,lbox};

lbox1 = newreg;
Line(lbox1) = {box7,box6};
lbox2 = newreg;
Line(lbox2) = {box6,box1};
lbox3 = newreg;
Line(lbox3) = {box1,box4};
lbox4 = newreg;
Line(lbox4) = {box4,box7};
lbox5 = newreg;
Line(lbox5) = {box8,box5};
lbox6 = newreg;
Line(lbox6) = {box5,box2};
lbox7 = newreg;
Line(lbox7) = {box2,box3};
lbox8 = newreg;
Line(lbox8) = {box3,box8};
lbox9 = newreg;
Line(lbox9) = {box5,box6};
lbox10 = newreg;
Line(lbox10) = {box2,box1};
lbox11 = newreg;
Line(lbox11) = {box3,box4};



s1 = newp;
Point(s1) = {0,0,D4+e,l};
s2 = newp;
Point(s2) = {0,0,D2-D4-e,l};
s3 = newp;
Point(s3) = {0,D3-e,D2-D4-e,l};
s4 = newp;
Point(s4) = {0,D3-e,D4+e,l};

q1 = newreg;
Line(q1) = {s1,s2};
q2 = newreg;
Line(q2) = {s2,s3};
q3 = newreg;
Line(q3) = {s3,s4};
q4 = newreg;
Line(q4) = {s4,s1};

v1 = newreg;
Line(v1) = {box8,c1};
v2 = newreg;
Line(v2) = {s2,box7};
v3 = newreg;
Line(v3) = {s1,c8};

e2 = newreg;
Line Loop (newreg) = {q1,q2,q3,q4};
f2 = newreg;
Ruled Surface (f2) = {e2};
Extrude Surface { f2, {D6,0.00000E+00, 0.00000E+00} };

DxInducteur = .005;
DyInducteur = .01;
DzInducteur = .06;
Rinducteur  = .001;
Xinducteur  = .028;
Yinducteur  = .00;
Zinducteur  = .04;
LcInducteur = .006;

r1 = newp;
Point(r1) = {Xinducteur,Yinducteur,Zinducteur,LcInducteur};
r2 = newp;
Point(r2) = {Xinducteur+DxInducteur,Yinducteur,Zinducteur,LcInducteur};
r3 = newp;
Point(r3) = {Xinducteur+DxInducteur,Yinducteur+DyInducteur,Zinducteur,LcInducteur};
r4 = newp;
Point(r4) = {Xinducteur,Yinducteur+DyInducteur,Zinducteur,LcInducteur};
cc = newp;
Point(cc) = {Xinducteur-Rinducteur,Yinducteur+DyInducteur,Zinducteur,LcInducteur};
r5 = newp;
Point(r5) = {Xinducteur-Rinducteur,Yinducteur+DyInducteur+Rinducteur,Zinducteur,LcInducteur};
r6 = newp;
Point(r6) = {Xinducteur-Rinducteur,Yinducteur+DyInducteur+DxInducteur+Rinducteur,Zinducteur,LcInducteur};
r7 = newp;
Point(r7) = {0,Yinducteur+DxInducteur+DyInducteur+Rinducteur,Zinducteur,LcInducteur};
r8 = newp;
Point(r8) = {0,Yinducteur+DyInducteur+Rinducteur,Zinducteur,LcInducteur};

ll1 = newreg;
Line(ll1) = {r2,r1};
ll2 = newreg;
Line(ll2) = {r1,r4};
ll3 = newreg;
Circle (ll3) = {r4,cc,r5};
ll4 = newreg;
Line(ll4) = {r5,r8};
ll5 = newreg;
Line(ll5) = {r8,r7};
ll6 = newreg;
Line(ll6) = {r7,r6};
ll7 = newreg;
Circle(ll7) = {r3,cc,r6};
ll8 = newreg;
Line(ll8) = {r3,r2};

BFondDeLInducteur = newreg;
Line Loop(BFondDeLInducteur) = {ll1,ll2,ll3,ll4,ll5,ll6,-ll7,ll8};
FondDeLInducteur = newreg;
Plane Surface(FondDeLInducteur) = {BFondDeLInducteur};
Extrude Surface { FondDeLInducteur, {0,0,DzInducteur} };
