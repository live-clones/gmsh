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
Line (d1) = Liste[c1,c2];
d2 = newreg;
Line (d2) = Liste[c2,c3];
d3 = newreg;
Line (d3) = Liste[c3,c4];
d4 = newreg;
Line (d4) = Liste[c4,c5];
d5 = newreg;
Line (d5) = Liste[c5,c6];
d6 = newreg;
Line (d6) = Liste[c6,c7];
d7 = newreg;
Line (d7) = Liste[c7,c8];
d8 = newreg;
Line (d8) = Liste[c8,c1];

e1 = newreg;
Boucle (newreg) = Liste[d1,d2,d3,d4,d5,d6,d7,d8];
f1 = newreg;
Zone (f1) = Liste[e1];
Extrude ( f1, {D5,0.00000E+00, 0.00000E+00} );

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
Line(lbox1) = Liste[box7,box6];
lbox2 = newreg;
Line(lbox2) = Liste[box6,box1];
lbox3 = newreg;
Line(lbox3) = Liste[box1,box4];
lbox4 = newreg;
Line(lbox4) = Liste[box4,box7];
lbox5 = newreg;
Line(lbox5) = Liste[box8,box5];
lbox6 = newreg;
Line(lbox6) = Liste[box5,box2];
lbox7 = newreg;
Line(lbox7) = Liste[box2,box3];
lbox8 = newreg;
Line(lbox8) = Liste[box3,box8];
lbox9 = newreg;
Line(lbox9) = Liste[box5,box6];
lbox10 = newreg;
Line(lbox10) = Liste[box2,box1];
lbox11 = newreg;
Line(lbox11) = Liste[box3,box4];



s1 = newp;
Point(s1) = {0,0,D4+e,l};
s2 = newp;
Point(s2) = {0,0,D2-D4-e,l};
s3 = newp;
Point(s3) = {0,D3-e,D2-D4-e,l};
s4 = newp;
Point(s4) = {0,D3-e,D4+e,l};

q1 = newreg;
Line(q1) = Liste[s1,s2];
q2 = newreg;
Line(q2) = Liste[s2,s3];
q3 = newreg;
Line(q3) = Liste[s3,s4];
q4 = newreg;
Line(q4) = Liste[s4,s1];

v1 = newreg;
Line(v1) = Liste[box8,c1];
v2 = newreg;
Line(v2) = Liste[s2,box7];
v3 = newreg;
Line(v3) = Liste[s1,c8];

e2 = newreg;
Boucle (newreg) = Liste[q1,q2,q3,q4];
f2 = newreg;
Reglee (f2) = Liste[e2];
Extrude ( f2, {D6,0.00000E+00, 0.00000E+00} );

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
Line(ll1) = Liste[r2,r1];
ll2 = newreg;
Line(ll2) = Liste[r1,r4];
ll3 = newreg;
Arc Trigonometrique (ll3) = Liste[r4,cc,r5];
ll4 = newreg;
Line(ll4) = Liste[r5,r8];
ll5 = newreg;
Line(ll5) = Liste[r8,r7];
ll6 = newreg;
Line(ll6) = Liste[r7,r6];
ll7 = newreg;
Arc Trigonometrique(ll7) = Liste[r3,cc,r6];
ll8 = newreg;
Line(ll8) = Liste[r3,r2];

BFondDeLInducteur = newreg;
Boucle(BFondDeLInducteur) = Liste[ll1,ll2,ll3,ll4,ll5,ll6,-ll7,ll8];
FondDeLInducteur = newreg;
Zone(FondDeLInducteur) = Liste[BFondDeLInducteur];
Extrude ( FondDeLInducteur, {0,0,DzInducteur} );

Boucle(127) = Liste[2,3,4,5,6,7,-62,-59,-58,-57,61,45,-53,-49,60,1];
Zone(128) = Liste[127,116];
Boucle(129) = Liste[39,18,-20,-60,-52,55,48,-61,71,-65,-70,62];
Zone(130) = Liste[129,104];
Boucle(131) = Liste[50,51,52,49];
Reglee(132) = Liste[131];
Boucle(133) = Liste[-55,-51,54,47];
Reglee(134) = Liste[133];
Boucle(135) = Liste[46,47,48,45];
Reglee(136) = Liste[135];
Boucle(137) = Liste[54,-46,-53,50];
Reglee(138) = Liste[137];
Volume(139) = Liste[117,-92,105,108,111,114,126,120,-123,125];
Volume Complexe(140) = Liste[139];
Volume(141) = Liste[73,-64,76,79,81,82];
Volume Complexe(142) = Liste[141];
Volume(143) = Liste[-43,10,-23,-26,-29,-32,-35,-38,-41,-44];
Volume Complexe(144) = Liste[143];
Volume(145) = Liste[26,-128,29,32,35,38,41,-130,44,23,-132,138,-134,136,-76,-79,-81,-82,92,-108,-111,-114,-126,-120,123,-125];
Volume Complexe(146) = Liste[145];
Physical Surface (11111) = Liste [117];
Physical Surface (22222) = Liste [92,123,120,126,114,108,125,111];
Physical Surface (33333) = Liste [10,43,64,73,105,117,128,130,132,134,136,138];
Physical Volume  (44444) = Liste [140];
Physical Volume  (55555) = Liste [142,144];
Physical Volume  (66666) = Liste [146];



