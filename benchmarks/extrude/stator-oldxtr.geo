
r = 7.0e-3;
Wd = 2.e-3;
r0 = 3.0e-3;

nbr_tooth = 64;
teta_tooth = 0.0520881;

nbr_gap = 4;
teta_gap = Pi/180/2;

lcext =r*teta_tooth;
lcint =0.0008;

Point(1) = {0, 0, 0, lcext };

p=0; lt=0;
For i In {0:nbr_tooth-1}
  t = i*2*Pi/nbr_tooth + 2*Pi/nbr_tooth/2 ;
  p1 = newp; 
  Point(p1) = {r*Cos(t-teta_tooth/2) , r*Sin(t-teta_tooth/2) , 0 , lcext };
  p2 = newp; points[p] = p2; p++;
  Point(p2) = {(r+Wd)*Cos(t-teta_tooth/2) , (r+Wd)*Sin(t-teta_tooth/2) , 0 , lcext };
  p3 = newp;
  Point(p3) = {r*Cos(t+teta_tooth/2) , r*Sin(t+teta_tooth/2) , 0 , lcext };
  p4 = newp; points[p] = p4; p++;
  Point(p4) = {(r+Wd)*Cos(t+teta_tooth/2) , (r+Wd)*Sin(t+teta_tooth/2) , 0 , lcext };
  l1 = newreg; Line(l1) = {p2,p1};
  l2 = newreg; Line(l2) = {p3,p4};
  l3 = newreg; Circle(l3) = {p1,1,p3};
  l4 = newreg; Circle(l4) = {p2,1,p4};
  s1 = newreg; Line Loop(s1) = {-l1,-l2,-l3,l4};
  Plane Surface(s1+1) = {s1};
  surftooth[i] = s1+1;
  looptooth[lt] = l1; lt++;
  looptooth[lt] = l2; lt++;
  looptooth[lt] = l3; lt++;
EndFor
points[p] = points[0];

g=0; g0=0;
For i In {0:nbr_gap-1}
  t = i*2*Pi/nbr_gap;
  p1 = newp; gap[g] = p1; g++;
  Point(p1) = {(r+Wd)*Cos(t-teta_gap/2) , (r+Wd)*Sin(t-teta_gap/2) , 0 , lcext };
  p2 = newp; gap[g] = p2; g++;
  Point(p2) = {(r+Wd)*Cos(t+teta_gap/2) , (r+Wd)*Sin(t+teta_gap/2) , 0 , lcext };

  p3 = newp; gap0[g0] = p3; g0++;
  Point(p3) = {r0*Cos(t-teta_gap/2) , r0*Sin(t-teta_gap/2) , 0 , lcint };
  p4 = newp; gap0[g0] = p4; g0++;
  Point(p4) = {r0*Cos(t+teta_gap/2) , r0*Sin(t+teta_gap/2) , 0 , lcint };
EndFor
gap0[g0]=gap0[0];
gap[g]=gap[0];

j=1; g=0; le=0; lge=0;

For i In {1:p-1:2}
  If( Modulo(j,nbr_tooth/nbr_gap) )
    loopext[le] = newreg;
    Circle(loopext[le]) = {points[i],1,points[i+1]};
    le++;
  EndIf
  If( !Modulo(j,nbr_tooth/nbr_gap) )
    loopgapext[lge] = newreg;    
    Circle(loopgapext[lge]) = {gap[g],1,gap[g+1]};
    lge++;

    Printf("ii=%g", i);
    loopext[le] = newreg;
    Circle(loopext[le]) = {gap[g+1], 1, points[i-(2*nbr_tooth/nbr_gap-1)]};
    le++;

    loopext[le] = newreg;
    Circle(loopext[le]) = {points[i], 1, gap[g+2]};
    le++;

    g+=2;
  EndIf

  j++;
EndFor
loopext[le] = loopext[0];

li=0; lgi=0; lg=0;
For i In {0:g0-2:2}

  loopgapint[lgi] = newreg;
  Circle(loopgapint[lgi]) = {gap0[i],1,gap0[i+1]};
  lgi++;

  loopgap[lg] = newreg;
  Line(loopgap[lg]) = {gap[i], gap0[i]};
  lg++;
  loopgap[lg] = newreg;
  Line(loopgap[lg]) = {gap0[i+1] , gap[i+1]};
  lg++;


  loopint[li] = newreg;
  Circle(loopint[li]) = {gap0[i+1],1,gap0[i+2]};
  li++;

EndFor
loopgap[lg] = loopgap[0];

i_looptooth = 0;
i_loopext = 0;



For i In {1:nbr_gap}

  l1 = loopgap[2*i-1];
  l2 = loopgap[2*i];

  For j In {i_looptooth : i_looptooth+nbr_tooth*3/nbr_gap-1}
    Printf("tooth=%g", looptooth[j]);
  EndFor
  For j In {i_loopext : i_loopext+nbr_tooth/nbr_gap+1-1}
    Printf("ext=%g", loopext[j]);
  EndFor
  Printf("int=%g", loopint[i-1]);
  Printf("gap=%g,%g", l1, l2);

  ll = newreg;
  Line Loop(ll) = {
    looptooth[{i_looptooth : i_looptooth+nbr_tooth*3/nbr_gap-1}] ,
    loopext[{i_loopext : i_loopext+nbr_tooth/nbr_gap+1-1}] ,
    -loopint[i-1],
    l1, l2
  };
  Plane Surface(ll+1) = ll;
  surfair[i-1] = ll+1;

  ll = newreg;
  Line Loop(ll) = { 
    -loopgap[2*i-2],
    -loopgap[2*i-1],
    -loopgapint[i-1],
    loopgapext[i-1]
  };
  Plane Surface(ll+1) = ll;
  surfgap[i-1] = ll+1;
 
  i_looptooth += nbr_tooth*3/nbr_gap;
  i_loopext += nbr_tooth/nbr_gap+1;

EndFor

// Old extrusion mesh generator: gmsh -extrude < newstator.par
//
//
// All geometrical entities are automatically numbered:
//
//         volumes: V_ + layer * N_ + surf->num
// New XY surfaces: S_ + layer * N_ + surf->num
//  perp. surfaces: L_ + layer * N_ + curve->num
//     perp. lines: P_ + layer * N_ + point->Num

L_ = 100e6 ;
S_ = 200e6 ;
V_ = 300e6 ;
P_ = 400e6 ;
N_ = 1e6 ;

// Volumes: 

For i In {0:nbr_tooth-1}
  toothvol1[i] = V_ + 1*N_ + surftooth[i] ;
  toothvol2[i] = V_ + 2*N_ + surftooth[i] ;
  toothvol3[i] = V_ + 3*N_ + surftooth[i] ;
EndFor
For i In {0:nbr_gap-1}
  corpsvol1[i] = V_ + 1*N_ + surfair[i];
  corpsvol2[i] = V_ + 2*N_ + surfair[i];
  corpsvol3[i] = V_ + 3*N_ + surfair[i];
  gapvol1[i] = V_ + 1*N_ + surfgap[i];
  gapvol2[i] = V_ + 2*N_ + surfgap[i];
  gapvol3[i] = V_ + 3*N_ + surfgap[i];
EndFor

// 1, 2, 3, ... -> volmumes piezo
ii = 0;
For i In {1:nbr_gap}
  Physical Volume(i) = { toothvol1[{ii:(ii+nbr_tooth/nbr_gap-1)}], corpsvol1[i-1], gapvol1[i-1] };
  ii += nbr_tooth/nbr_gap;
EndFor

// 100 -> volume metal
Physical Volume(100) = { 
  toothvol2[{0:nbr_tooth-1}],
  toothvol3[{0:nbr_tooth-1}],
  corpsvol2[{0:nbr_gap-1}],
  gapvol2[{0:nbr_gap-1}]
};

// Surfaces

For i In {0:nbr_tooth-1}
  toothsur0[i] = surftooth[i] ;
  toothsur1[i] = S_ + 1*N_ + surftooth[i] ;
EndFor
For i In {0:nbr_gap-1}
  corpssur0[i] = surfair[i];
  corpssur1[i] = S_ + 1*N_ + surfair[i];
  gapsur1[i] = S_ + 1*N_ + surfgap[i];
EndFor

// 1000 -> surface plan de masse
Physical Surface(1000) = { toothsur1[] , corpssur1[] , gapsur1[] };

// 1001, 1002, ... -> surfaces electrodes
ii = 0;
For i In {1:nbr_gap}
  Physical Surface(1000+i) = { 
     toothsur0[{ii:(ii+nbr_tooth/nbr_gap-1)}], 
     corpssur0[i-1] 
  };
  ii += nbr_tooth/nbr_gap;
EndFor

j=0;
For i In {0:nbr_gap-1}
  cylint1[j] = L_ + 1*N_ + loopint[i]; 
  cylint1[j+1] = L_ + 1*N_ + loopgapint[i];
  cylint2[j] = L_ + 2*N_ + loopint[i];
  cylint2[j+1] = L_ + 2*N_ + loopgapint[i];
  j+=2;
EndFor  

// 1100 -> surface cylindre interieur
Physical Surface(1100) = {
  cylint1[],
  cylint2[]
};

