Rinf = 0.964183099831;
l2 = 0.02;
l = 0.04;
h = 0.005;
ri = 0.0325;
hcoil = 0.005;
ro = 0.0375;
ricoil = 0.0395;
dl = 0.004;
Ncoil = 10;
lcoil = 0.04;
dlcoil = 0.004;
coil_period = 0.044;
Rbnd = 0.482091549916;
lcoil_total = 0.436;
rocoil = 0.0445;
period = 0.044;
zcm = 1.0;
lmag_total = 0.26;
cm = 0.01;
zcoil = 0.01;
N = 6;


ipt = 1;
igeo = 1;

mag_pts[] = {1,2,3,4};

Point(1) = {ri,-lmag_total/2,0,h/10};
Point(2) = {ro,-lmag_total/2,0,h/10};
Point(3) = {ro,-lmag_total/2+l,0,h/10};
Point(4) = {ri,-lmag_total/2+l,0,h/10};

ipt += 4;

mag_lines[] = {1,2,3,4};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};

mag_loop[] = {5};
Line Loop(5) = {1,2,3,4};
mag_surf[] = {6};
Plane Surface(6) = {5};
igeo += 6;

z = 0.0;

For i In {1:N-1}
  z += period;
  Translate {0.0,z,0.0} { Duplicata{Point{mag_pts[0]};Point{mag_pts[1]};
                          Point{mag_pts[2]};Point{mag_pts[3]};}}
  iloop = igeo;
  Line(igeo) = {ipt,ipt+1}; igeo += 1;
  Line(igeo) = {ipt+1,ipt+2}; igeo += 1;
  Line(igeo) = {ipt+2,ipt+3}; igeo += 1;
  Line(igeo) = {ipt+3,ipt}; igeo += 1;
  mag_loop[i] = igeo;
  Line Loop(igeo) = {iloop,iloop+1,iloop+2,iloop+3}; igeo += 1;
  mag_surf[i] = igeo;
  Plane Surface(igeo) = {igeo-1}; igeo += 1;
  ipt += 4;
EndFor

iorg = ipt;

Point(ipt) = {0,0,0,ri/20};ipt += 1;

bnd_pts[] = {ipt,ipt+1,ipt+2};
Point(ipt) = {0,-Rbnd,0,Rbnd/20};ipt += 1;
Point(ipt) = {Rbnd,0,0,Rbnd/20};ipt += 1;
Point(ipt) = {0,Rbnd,0,Rbnd/20};ipt += 1;

bnd_cir[] = {igeo,igeo+1};
Circle(igeo) = {bnd_pts[0],iorg,bnd_pts[1]};igeo += 1;
Circle(igeo) = {bnd_pts[1],iorg,bnd_pts[2]};igeo += 1;

org_line[] = {igeo,igeo+1};
Line(igeo) = {iorg,bnd_pts[0]};igeo += 1;
Line(igeo) = {iorg,bnd_pts[2]};igeo += 1;

inf_pts[] = {ipt,ipt+1,ipt+2};
Point(ipt) = {0,-Rinf,0,Rinf/20};ipt += 1;
Point(ipt) = {Rinf,0,0,Rinf/20};ipt += 1;
Point(ipt) = {0,Rinf,0,Rinf/20};ipt += 1;

inf_cir[] = {igeo,igeo+1};
Circle(igeo) = {inf_pts[0],iorg,inf_pts[1]};igeo += 1;
Circle(igeo) = {inf_pts[1],iorg,inf_pts[2]};igeo += 1;

bnd_line[] = {igeo,igeo+1,igeo+2};
Line(igeo) = {bnd_pts[0],inf_pts[0]};igeo += 1;
Line(igeo) = {bnd_pts[1],inf_pts[1]};igeo += 1;
Line(igeo) = {bnd_pts[2],inf_pts[2]};igeo += 1;

inf_loop[] = {igeo,igeo+1};
Line Loop(igeo) = {bnd_cir[0],bnd_line[1],-inf_cir[0],-bnd_line[0]}; igeo += 1;
Line Loop(igeo) = {bnd_cir[1],bnd_line[2],-inf_cir[1],-bnd_line[1]}; igeo += 1;
inf_sur[] = {igeo,igeo+1};
Plane Surface(igeo) = {inf_loop[0]};igeo += 1;
Plane Surface(igeo) = {inf_loop[1]}; igeo += 1;

coil_pts[] = {ipt,ipt+1,ipt+2,ipt+3};

Point(ipt) = {ricoil,zcoil-lcoil_total/2,0,hcoil/10};ipt += 1;
Point(ipt) = {rocoil,zcoil-lcoil_total/2,0,hcoil/10};ipt += 1;
Point(ipt) = {rocoil,zcoil-lcoil_total/2+lcoil,0,hcoil/10};ipt += 1;
Point(ipt) = {ricoil,zcoil-lcoil_total/2+lcoil,0,hcoil/10};ipt += 1;

coil_line[] = {igeo,igeo+1,igeo+2,igeo+3};

Line(igeo) = {coil_pts[0],coil_pts[1]};igeo += 1;
Line(igeo) = {coil_pts[1],coil_pts[2]};igeo += 1;
Line(igeo) = {coil_pts[2],coil_pts[3]};igeo += 1;
Line(igeo) = {coil_pts[3],coil_pts[0]};igeo += 1;

coil_loop[] = {igeo};
Line Loop(igeo) = {coil_line[0],coil_line[1],coil_line[2],coil_line[3]};igeo += 1;
coil_surf[] = {igeo};
Plane Surface(igeo) = {igeo-1};igeo += 1;

z = 0.0;

For i In {1:Ncoil-1}
  z += coil_period;
  Translate {0.0,z,0.0} { Duplicata{Point{coil_pts[0]};Point{coil_pts[1]};
                          Point{coil_pts[2]};Point{coil_pts[3]};}}
  iloop = igeo;
  Line(igeo) = {ipt,ipt+1}; igeo += 1;
  Line(igeo) = {ipt+1,ipt+2}; igeo += 1;
  Line(igeo) = {ipt+2,ipt+3}; igeo += 1;
  Line(igeo) = {ipt+3,ipt}; igeo += 1;
  coil_loop[i] = igeo;
  Line Loop(igeo) = {iloop,iloop+1,iloop+2,iloop+3}; igeo += 1;
  coil_surf[i] = igeo;
  Plane Surface(igeo) = {igeo-1}; igeo += 1;
  ipt += 4;
EndFor

air_loop = igeo;
Line Loop(igeo) = {bnd_cir[0],bnd_cir[1],-org_line[1],org_line[0]};igeo += 1;
air_surf[] = {air_loop};

For i In {1:N}
  air_surf[i] = mag_loop[i-1];
EndFor
For i In {1:Ncoil}
  air_surf[i+N] = coil_loop[i-1];
EndFor

Air_surf = igeo;
Plane Surface(igeo) = air_surf[];igeo += 1;

j = 0;
For i In {0:N-2:2}
	mag_psurfP[j] = mag_surf[i];
	mag_psurfM[j] = mag_surf[i+1];
	j += 1;
EndFor

j = 0;
For i In {0:Ncoil-2:2}
	coil_psurfP[j] = coil_surf[i];
	coil_psurfM[j] = coil_surf[i+1];
	j += 1;
EndFor

Coherence;

Physical Surface(1000) = coil_psurfP[]; 
Physical Surface(1001) = coil_psurfM[]; 
Physical Surface(1002)  = mag_psurfP[]; 
Physical Surface(1003)  = mag_psurfM[];
Physical Surface(1004)  = {Air_surf}; 
Physical Surface(1005)  = {inf_sur[0],inf_sur[1]}; 
