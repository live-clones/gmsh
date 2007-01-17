Include "KDS70-2_dat.pro";
Include "Probe_position.pro";

ncore1 = 3 ;
ncore2 = 4 ;

s0 = 1 ;

lcc = Rcore/3/s0 ;

cte = news-1 ;

cen0 = newp ; Point(cen0) = {xp0, yp0  , 0,lcc};
cen1 = newp ; Point(cen1) = {xp0, yp0+w, 0,lcc};

pc1 = newp ; Point(pc1) = {xp0, yp0+w, Rcore, lcc};
pc2 = newp ; Point(pc2) = {xp0, yp0+w+Rcore, 0, lcc };
pc3 = newp ; Point(pc3) = {xp0, yp0+w, -Rcore, lcc };

c1 = newl ; Circle(c1) = {pc1,cen1,pc2};
c2 = newl ; Circle(c2) = {pc2,cen1,pc3};

pc4 = newp ; Point(pc4) = {xp0, yp0+w,Rcore+w,lcc};
pc5 = newp ; Point(pc5) = {xp0, yp0+2*w+Rcore, 0,lcc};
pc6 = newp ; Point(pc6) = {xp0, yp0+w, -(Rcore+w),lcc};

c3 = newl ; Circle(c3) = {pc4,cen1,pc5};
c4 = newl ; Circle(c4) = {pc5,cen1,pc6};

pc7 = newp ; Point(pc7) = {xp0, yp0, Rcore+w,lcc};
pc8 = newp ; Point(pc8) = {xp0, yp0,-(Rcore+w),lcc};

ln1 = newl ; Line(ln1) ={pc1,pc3}; 
ln2 = newl ; Line(ln2) ={pc7,pc8}; 
ln3 = newl ; Line(ln3) ={pc4,pc7}; 
ln4 = newl ; Line(ln4) ={pc6,pc8}; 

surfcore1 = newl ;
Line Loop(surfcore1) = {ln1,-c2,-c1};
Plane Surface(surfcore1) = {surfcore1};

surfcoil1 = newl ;
Line Loop(surfcoil1) ={ln2,-ln4,-c4,-c3,ln3};
Plane Surface(surfcoil1) = {surfcoil1,surfcore1};

surf[]=Symmetry {0.0,1.0,0.0,-yp0}{Duplicata { Surface{surfcore1}; }};
surfcore2 = surf[0];
surf[]=Symmetry {0.0,1.0,0.0,-yp0}{Duplicata { Surface{surfcoil1}; }};
surfcoil2 = surf[0];


pc1_ = newp ; Point(pc1_) = {xp0, yp0+w, Rcore + w + w,lcc};
pc2_ = newp ; Point(pc2_) = {xp0, yp0+2*w + Rcore + w,0,lcc};
pc3_ = newp ; Point(pc3_) = {xp0, yp0+w,-(Rcore+w +w),lcc};

c1_ = newl ; Circle(c1_) = {pc1_,cen1,pc2_};
c2_ = newl ; Circle(c2_) = {pc2_,cen1,pc3_};

lin[]=Symmetry {0.0,1.0,0.0,-yp0}{Duplicata { Line{c1_}; }};
c3_ = lin[0];
lin[]=Symmetry {0.0,1.0,0.0,-yp0}{Duplicata { Line{c2_}; }};
c4_ = lin[0];

ln5 = newl ; Line(ln5)={pc1_,pc1_+3};
ln6 = newl ; Line(ln6)={pc3_,pc3_+6};

pa1 = newp ; Point(pa1) = {xp0, yp0, Rcore +2*w+w_air, lcc};
pa2 = newp ; Point(pa2) = {xp0, yp0+Rcore +2*w+w_air, 0, lcc };
pa3 = newp ; Point(pa3) = {xp0, yp0, -(Rcore +2*w+w_air), lcc};
pa4 = newp ; Point(pa4) = {xp0, yp0-(Rcore +2*w+w_air), 0, lcc };

ca1 = newl ; Circle(ca1) = {pa1,cen0,pa2};
ca2 = newl ; Circle(ca2) = {pa2,cen0,pa3};
ca3 = newl ; Circle(ca3) = {pa3,cen0,pa4};
ca4 = newl ; Circle(ca4) = {pa4,cen0,pa1};

pb1 = newp ; Point(pb1) = {xp0, yp0, Rcore +2*w+w_air+w_blindage, lcc};
pb2 = newp ; Point(pb2) = {xp0, yp0+Rcore +2*w+w_air+w_blindage, 0, lcc };
pb3 = newp ; Point(pb3) = {xp0, yp0, -(Rcore +2*w+w_air+w_blindage), lcc};
pb4 = newp ; Point(pb4) = {xp0, yp0-(Rcore +2*w+w_air+w_blindage), 0, lcc };

cb1 = newl ; Circle(cb1) = {pb1,cen0,pb2};
cb2 = newl ; Circle(cb2) = {pb2,cen0,pb3};
cb3 = newl ; Circle(cb3) = {pb3,cen0,pb4};
cb4 = newl ; Circle(cb4) = {pb4,cen0,pb1};

scoilout = news ;
Line Loop(scoilout) = {c3,c4,ln4,17+cte,18+cte,19+cte,20+cte,-ln3};
scoilout_ = news;
Line Loop(scoilout_) = {c1_,c2_,ln6,-c3_,-c4_,-ln5};
Plane Surface(scoilout) = {scoilout_,scoilout};

lair = news;
Line Loop(lair) = {ca1,ca2,ca3,ca4};
sair = news;
Plane Surface(sair) = {lair,scoilout_};

sblin=news;
Line Loop(sblin) = {cb1,cb2,cb3,cb4};
Plane Surface(sblin) = {sblin,lair};

//__________________________________________________________________________
//__________________________________________________________________________

//Core

dx = -dist ; dy = 0.; dz = 0.;

vol[]=Extrude Surface{surfcore1, {dx,dy,dz}} {Layers {{ncore1},{1}};};;
vCore10 = vol[1];
vol[]=Extrude Surface{surfcore2, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vCore20 = vol[1];

dx = hc ;  
vol[]=Extrude Surface{surfcore1, {dx,dy,dz}} {Layers {{ncore2},{1}};};; 
vCore11 = vol[1];
surfcore11 = news-1;
vol[]=Extrude Surface{surfcore2, {dx,dy,dz}} {Layers {{ncore2},{1}};};; 
vCore21 = vol[1];

dx = dist ;  
surfcore21 = news-1;
vol[]=Extrude Surface{surfcore11, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vCore12 = vol[1];
vol[]=Extrude Surface{surfcore21, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vCore22 = vol[1];


//Coils_in
dx = hc ;
vol[]=Extrude Surface{surfcoil1, {dx,dy,dz}} {Layers {{ncore2},{1}};};; 
vCoilIn1 = vol[1]; surfcoil1up = news-1;
vol[]=Extrude Surface{surfcoil2, {dx,dy,dz}} {Layers {{ncore2},{1}};};; 
vCoilIn2 = vol[1]; surfcoil2up = news-1;

dx = -dist;
vol[]=Extrude Surface{surfcoil1, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vAir0CoilIn1 = vol[1];
vol[]=Extrude Surface{surfcoil2, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vAir0CoilIn2 = vol[1];

dx = dist;
vol[]=Extrude Surface{surfcoil1up, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vAir1CoilIn1 = vol[1];
vol[]=Extrude Surface{surfcoil2up, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vAir1CoilIn2 = vol[1];

//Coil_out
dx = -dist ; 
vol[]=Extrude Surface{scoilout, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vAir0CoilOut0 = vol[1];
dx = hc ;
vol[]=Extrude Surface{scoilout, {dx,dy,dz}} {Layers {{ncore2},{1}};};; 
vCoilOut = vol[1];
dx=dist;
vol[]=Extrude Surface{news-1, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vAir1CoilOut0 = vol[1];

//Air in
dx = -dist;
vol[]=Extrude Surface{sair,{dx,dy,dz} } {Layers {{ncore1},{1}};};;
vAirIn0 = vol[1];
dx=hc;
vol[]=Extrude Surface{sair, {dx,dy,dz}} {Layers {{ncore2},{1}};};; 
vAirIn = vol[1];
dx=dist;
vol[]=Extrude Surface{news-1, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vAirIn1 = vol[1];

//Blindage
dx = -dist;
vol[]=Extrude Surface{sblin, {dx,dy,dz}} {Layers {{ncore1},{1}};};;
vBlin0 = vol[1];
dx=hc;
vol[]=Extrude Surface{sblin, {dx,dy,dz}} {Layers {{ncore2},{1}};};; 
vBlin1 = vol[1];

sblin1 = news-1;
dx=dist;
vol[]=Extrude Surface{sblin1, {dx,dy,dz}} {Layers {{ncore1},{1}};};; 
vBlin2 = vol[1];


//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------

Physical Volume(COILIN1) = {vCoilIn1};
Physical Volume(COILIN2) = {vCoilIn2};
Physical Volume(COILOUT) = {vCoilOut};
Physical Volume(CORE1) = {vCore11};
Physical Volume(CORE2) = {vCore21};
Physical Volume(CORE1_0) = {vCore10};
Physical Volume(CORE2_0) = {vCore20};
Physical Volume(CORE1_1) = {vCore12};
Physical Volume(CORE2_1) = {vCore22};

Physical Volume(GAP)={vAirIn,vAirIn0,vAirIn1,
		      vAir0CoilIn1,vAir0CoilIn2,vAir1CoilIn1,vAir1CoilIn2,
		      vAir0CoilOut0,vAir1CoilOut0};
Physical Volume(SHIELD) = {vBlin0,vBlin1,vBlin2};

Physical Surface(SKINCOILIN1) = 
{89+cte,85+cte,81+cte,158+cte,170+cte,166+cte,162+cte,154+cte,10+cte,183+cte};
Physical Surface(SKINCOILIN12) ={89+cte,85+cte,81+cte};
Physical Surface(SKINCOILIN2) = 
{106+cte,102+cte,204+cte,208+cte,98+cte,154+cte,212+cte,200+cte,15+cte,225+cte};
Physical Surface(SKINCOILIN22) ={106+cte,102+cte,98+cte};

Physical Surface(CUTCOILIN1) = {90+cte};//up
Physical Surface(CUTCOILIN2) = {107+cte};//up

Physical Surface(SKINCOILOUT) = 
{488+cte,484+cte,504+cte,500+cte,496+cte,492+cte,162+cte,166+cte,208+cte,204+cte,
200+cte,158+cte,170+cte,212+cte,537+cte,35+cte};
Physical Surface(SKINCOILOUT2) = 
{162+cte,166+cte,170+cte,212+cte,208+cte,204+cte,200+cte,158+cte};


Physical Surface(CUTCOILOUT) = {9+cte,10+cte,11+cte,15+cte};//down

Physical Surface(SKINCORE1)=
{124+cte,123+cte,119+cte,115+cte,89+cte,85+cte,81+cte,47+cte,55+cte,51+cte,56+cte};
Physical Surface(SKINCORE2)= 
{141+cte,132+cte,136+cte,140+cte,98+cte,102+cte,106+cte,64+cte,68+cte,72+cte,73+cte};


//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
Color Gold {Surface{89+cte,85+cte,81+cte,158+cte,170+cte,166+cte,162+cte,154+cte,10+cte,183+cte};}
Color Gold {Surface{106+cte,102+cte,204+cte,208+cte,98+cte,154+cte,212+cte,200+cte,15+cte,225+cte};}
Color Gold {Volume{vCoilIn1,vCoilIn2};}

Color Red {Surface{488+cte,484+cte,504+cte,500+cte,496+cte,492+cte,162+cte,166+cte,208+cte,204+cte,
		   200+cte,158+cte,170+cte,212+cte,537+cte,35+cte};}
Color Red {Volume{vCoilOut};}

Color DeepSkyBlue1 {Surface{124+cte,123+cte,119+cte,115+cte,89+cte,85+cte,81+cte,47+cte,55+cte,51+cte,56+cte};}
Color DeepSkyBlue1 {Surface{141+cte,132+cte,136+cte,140+cte,98+cte,102+cte,106+cte,64+cte,68+cte,72+cte,73+cte};}
Color DeepSkyBlue1 {Volume{vCore10,vCore11,vCore12,vCore20,vCore21,vCore22};}

Color MidnightBlue {Volume{vBlin0,vBlin1,vBlin2};}

surftotprobe = news ;
Surface Loop(surftotprobe) = 
{891+cte,862+cte,820+cte,-778-cte,-782-cte,824+cte,828+cte,-786-cte,-790-cte,
832+cte,874+cte,870+cte,866+cte,-807-cte,-661-cte,-465-cte,267+cte,-309-cte,
-73-cte,56+cte,765+cte,609+cte,-351-cte,393+cte,141+cte,-124-cte};
