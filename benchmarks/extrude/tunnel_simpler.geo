// Gmsh project created on Wed Jan 31 21:34:00 2007
Geometry.ExtrudeReturnLateralEntities = 0;

// definition of geometry
radius = 5;
surface = 20;
model_width = 60; 	// from tunnel center
model_depth = 40; 	// from tunnel center
vicinity_width = 20;	// from tunnel center
vicinity_depth = 20;	// from tunnel center

z1=-50; z2=0; z3= 50;

// extra fine
np_tunnelsector		= 8;
np_abovecrown		= 10;
np_farfield_bottom  	= 3;
np_farfield_lateral 	= 4;
np_along_tunnel		= 20;
np_along_core 		= 6;
progression_to_tunnel 		= 0.3;
progression_farfield		= 1.5;
progression_along_tunnel 	= 0.8;
prograssion_along_core 		= 2.0;


// test
np_tunnelsector		= 6;
np_abovecrown		= 5;
np_farfield_bottom  	= 3;
np_farfield_lateral 	= 6;
np_along_tunnel		= 10;
np_along_core 		= 6;
progression_to_tunnel 		= 0.3;
progression_farfield		= 1.5;
progression_along_tunnel 	= 0.8;
prograssion_along_core 		= 1.6;

// extra grob
np_tunnelsector		= 2;
np_abovecrown		= 2;
np_farfield_bottom  	= 2;
np_farfield_lateral 	= 2;
np_along_tunnel		= 3;
np_along_core 		= 3;
progression_to_tunnel 		= 1.0;
progression_farfield		= 1.0;
progression_along_tunnel 	= 1.0;
prograssion_along_core 		= 1.0;


// extra fine vergroebert damit band moeglich
np_tunnelsector		= 4;
np_abovecrown		= 8;
np_farfield_bottom  	= 3;
np_farfield_lateral 	= 4;
np_along_tunnel		= 10;
np_along_core 		= 5;
progression_to_tunnel 		= 0.6;
progression_farfield		= 1.5;
progression_along_tunnel 	= 0.8;
prograssion_along_core 		= 2.0;


// extra grob
np_tunnelsector		= 4;
np_abovecrown		= 4;
np_farfield_bottom  	= 2;
np_farfield_lateral 	= 2;
np_along_tunnel		= 3;
np_along_core 		= 6;
progression_to_tunnel 		= 0.6;
progression_farfield		= 1.5;
progression_along_tunnel 	= 0.8;
prograssion_along_core 		= 2.0;

// extra fine gekoppelt skyline ok, band nicht
np_tunnelsector		= 6;
np_abovecrown		= 12;
np_farfield_bottom  	= 3;
np_farfield_lateral 	= 4;
np_along_tunnel		= 12;
np_along_core 		= 6;
progression_to_tunnel 		= 0.6;
progression_farfield		= 1.5;
progression_along_tunnel 	= 0.8;
prograssion_along_core 		= 2.0;

// extra fine vergroebert fuer testzwecke
np_tunnelsector		= 4;
np_abovecrown		= 8;
np_farfield_bottom  	= 3;
np_farfield_lateral 	= 4;
np_along_tunnel		= 10;
np_along_core 		= 5;
progression_to_tunnel 		= 0.6;
progression_farfield		= 1.5;
progression_along_tunnel 	= 0.8;
prograssion_along_core 		= 2.0;


// vergroebert fuer solvertest
np_tunnelsector		= 3;
np_abovecrown		= 3;
np_farfield_bottom  	= 3;
np_farfield_lateral 	= 2;
np_along_tunnel		= 2;
np_along_core 		= 3;
progression_to_tunnel 		= 0.6;
progression_farfield		= 1.5;
progression_along_tunnel 	= 0.8;
prograssion_along_core 		= 2.0;



/* geometry of cross section 1
***************************************************************************************************************** */
sector = 60*Pi/180;
rcos= radius*Cos(sector);
rsin= radius*Sin(sector);
dummy=3;

// points
a1 = newp; Point(a1) = {-model_width,		surface,	z1,dummy};
b1 = newp; Point(b1) = {-vicinity_width,	surface,	z1,dummy};
c1 = newp; Point(c1) = {0,			surface,	z1,dummy};
d1 = newp; Point(d1) = {-model_width,		-vicinity_depth,z1,dummy};
e1 = newp; Point(e1) = {-vicinity_width,	-vicinity_depth,z1,dummy};
f1 = newp; Point(f1) = {0,			-vicinity_depth,z1,dummy};
g1 = newp; Point(g1) = {-model_width,		-model_depth,	z1,dummy};
h1 = newp; Point(h1) = {-vicinity_width,	-model_depth,	z1,dummy};
i1 = newp; Point(i1) = {0,			-model_depth,	z1,dummy};
j1 = newp; Point(j1) = {0,			radius,		z1,dummy};
k1 = newp; Point(k1) = {-rsin, 			rcos,		z1,dummy};
l1 = newp; Point(l1) = {-rsin,			-rcos,		z1,dummy};
m1 = newp; Point(m1) = {0, 			-radius,	z1,dummy};
o1 = newp; Point(o1) = {0,			0,		z1,dummy};

// straight lines (excel assistance)
ab1=newc; Line(ab1)={a1,b1};
bc1=newc; Line(bc1)={b1,c1};
de1=newc; Line(de1)={d1,e1};
ef1=newc; Line(ef1)={e1,f1};
gh1=newc; Line(gh1)={g1,h1};
hi1=newc; Line(hi1)={h1,i1};
kb1=newc; Line(kb1)={k1,b1};
le1=newc; Line(le1)={l1,e1};
ad1=newc; Line(ad1)={a1,d1};
dg1=newc; Line(dg1)={d1,g1};
be1=newc; Line(be1)={b1,e1};
eh1=newc; Line(eh1)={e1,h1};
cj1=newc; Line(cj1)={c1,j1};
mj1=newc; Line(mj1)={m1,j1};
mf1=newc; Line(mf1)={m1,f1};
fi1=newc; Line(fi1)={f1,i1};

// arches
jk1=newc; Circle(jk1)={j1,o1,k1};
kl1=newc; Circle(kl1)={k1,o1,l1};
lm1=newc; Circle(lm1)={l1,o1,m1};

// surfaces (excel assistance)
bade1_loop=newll; Line Loop(bade1_loop)={-ab1,ad1,de1,-be1}; bade1=news; Ruled Surface(bade1)={bade1_loop};
edgh1_loop=newll; Line Loop(edgh1_loop)={-de1,dg1,gh1,-eh1}; edgh1=news; Ruled Surface(edgh1)={edgh1_loop};
cbkj1_loop=newll; Line Loop(cbkj1_loop)={-bc1,-kb1,-jk1,-cj1}; cbkj1=news; Ruled Surface(cbkj1)={cbkj1_loop};
kbel1_loop=newll; Line Loop(kbel1_loop)={kb1,be1,-le1,-kl1}; kbel1=news; Ruled Surface(kbel1)={kbel1_loop};
lefm1_loop=newll; Line Loop(lefm1_loop)={le1,ef1,-mf1,-lm1}; lefm1=news; Ruled Surface(lefm1)={lefm1_loop};
jklm1_loop=newll; Line Loop(jklm1_loop)={jk1,kl1,lm1,mj1}; jklm1=news; Ruled Surface(jklm1)={jklm1_loop};
fehi1_loop=newll; Line Loop(fehi1_loop)={-ef1,eh1,hi1,-fi1}; fehi1=news; Ruled Surface(fehi1)={fehi1_loop};

// lines in cross section 1 (manually)
Transfinite Line{jk1,kl1,lm1,   bc1,ef1,hi1,be1,ad1} = np_tunnelsector;
Transfinite Line{mj1} = np_tunnelsector Using Bump 0.1 ;
Transfinite Line{cj1,-mf1,-kb1,-le1} = np_abovecrown Using Progression progression_to_tunnel;
Transfinite Line{dg1,eh1,fi1} = np_farfield_bottom Using Progression progression_farfield;
Transfinite Line{ab1,de1,gh1} = np_farfield_lateral Using Progression 1/progression_farfield;

/* Transfinite surfaces (excel assistance)
***************************************************************************************************************** */

// cross section
Transfinite Surface {bade1}={b1,a1,d1,e1}; Recombine Surface {bade1};
Transfinite Surface {edgh1}={e1,d1,g1,h1}; Recombine Surface {edgh1};
Transfinite Surface {cbkj1}={c1,b1,k1,j1}; Recombine Surface {cbkj1};
Transfinite Surface {kbel1}={k1,b1,e1,l1}; Recombine Surface {kbel1};
Transfinite Surface {lefm1}={l1,e1,f1,m1}; Recombine Surface {lefm1};
Transfinite Surface {jklm1}={j1,k1,l1,m1}; Recombine Surface {jklm1};
Transfinite Surface {fehi1}={f1,e1,h1,i1}; Recombine Surface {fehi1};

s1[] = {bade1, edgh1, cbkj1, kbel1, lefm1, jklm1, fehi1};

s2[] = Extrude {0, 0, z2-z1}{ Surface {s1[]} ; Layers{2}; Recombine; };
s3[] = Extrude {0, 0, z3-z2}{ Surface {s2[]} ; Layers{2}; Recombine; };
