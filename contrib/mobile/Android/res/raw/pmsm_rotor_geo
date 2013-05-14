//--------------------------------------------------------------------------------
// Rotor PMSM
//--------------------------------------------------------------------------------
A = InitialRotorAngle-45/2*deg2rad + A1; // with Theta_Park

sinA = Sin(A); cosA = Cos(A);
pntR[]+=newp; Point(newp)={rR1*cosA, rR1*sinA, 0, pR1};
pntR[]+=newp; Point(newp)={rR2*cosA, rR2*sinA, 0, pR1};
pntR[]+=newp; Point(newp)={rR4*cosA, rR4*sinA, 0, pR1};
pntR[]+=newp; Point(newp)={rR5*cosA, rR5*sinA, 0, pR1};
pntR[]+=newp; Point(newp)={rB1*cosA, rB1*sinA, 0, pR2};

For k In {0:#pntR[]-2}
 linR0[]+=newl; Line(newl) = {pntR[k], pntR[k+1]};
EndFor

Transfinite Line{linR0[0]} = Ceil[(rR2-rR1)/pR1] ;
Transfinite Line{linR0[1]} = Ceil[(rR4-rR2)/pR1] ;
Transfinite Line{linR0[2]} = Ceil[(rR5-rR4)/pR1] ;
Transfinite Line{linR0[3]} = Ceil[(rB1-rR5)/pR1] ;

For k In {0:#linR0[]-1}
 linR1[] += Rotate {{0, 0, 1}, {0, 0, 0}, A0+A1} { Duplicata{Line{linR0[k]};} };
EndFor

AA[] = {(A0-Th_magnet)/2+A1, Th_magnet, (A0-Th_magnet)/2+A1} ;

lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, AA[0]} { Point{pntR[0]}; };
cirR[]+=lin[1];
lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, AA[1]} { Point{lin[0]}; };
cirR[]+=lin[1];
lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, AA[2]} { Point{lin[0]}; };
cirR[]+=lin[1];

surfint[]=cirR[{0,1,2}] ; // boundary conditions

pMagnet[] = Rotate {{0, 0, 1}, {0, 0, 0}, AA[0]} { Duplicata{Point{pntR[1]};} };
lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, AA[1]} { Point{pMagnet[0]}; };
pMagnet[] += lin[0];
cirR[] += lin[1] ;

lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, AA[0]} { Point{pntR[2]}; };
cirR[]+=lin[1]; pMagnet[] += lin[0];
pMagnet[] += Rotate {{0, 0, 1}, {0, 0, 0}, AA[1]} { Duplicata{Point{lin[0]};} };
lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, AA[2]} { Point{pMagnet[3]}; };
cirR[]+=lin[1];

lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, AA[0]} { Point{pntR[3]}; };
cirR[]+=lin[1];
lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, AA[1]} { Point{lin[0]}; };
cirR[]+=lin[1];
lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, AA[2]} { Point{lin[0]}; };
cirR[]+=lin[1];

lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, A0+A1} { Point{pntR[4]}; };
cirR[]+=lin[1];

linR2[] = Rotate {{0, 0, 1}, {0, 0, 0}, (A0-Th_magnet)/2+A1} { Duplicata{Line{linR0[{1,2}]};} };
linR3[] = Rotate {{0, 0, 1}, {0, 0, 0},-(A0-Th_magnet)/2+A1} { Duplicata{Line{linR1[{1,2}]};} };

// surfaces rotor
Line Loop(newll) = {linR0[{0,1}], cirR[4], -linR2[0], cirR[3], linR3[0], cirR[5], -linR1[{1,0}], -cirR[{2,1,0}]};
srotor[0]=news; Plane Surface(srotor[0]) = {newll-1};

Line Loop(newl) = {linR2[1], cirR[7], -linR3[{1,0}], -cirR[3], linR2[0]};
smagnet[0]=news; Plane Surface(smagnet[0]) = {newll-1};

nn = #cirR[]-1 ;
Line Loop(newll) = {cirR[{nn-5}], linR2[1], -cirR[{nn-3}], -linR0[2]};
sairrotor[]+=news; Plane Surface(news) = {newll-1};
Line Loop(newll) = {cirR[{nn-4}], linR1[2], -cirR[{nn-1}], -linR3[1]};
sairrotor[]+=news; Plane Surface(news) = {newll-1};

Line Loop(newll) = {linR0[3], cirR[nn], -linR1[3], -cirR[{nn-1:nn-3:-1}]};
sairrotormb[]+=news; Plane Surface(news) = {newll-1};

// -------------------------------------------------------------------------------
// Moving band == AirGap rotor side
// -------------------------------------------------------------------------------
Transfinite Line{cirR[nn]} = NbrDivMB+1 ;

//Filling the gap for the whole 2*Pi
lineMBrotor[]=cirR[{nn}];
For k In {1:NbrPolesTot-1}
  lineMBrotoraux[]+=Rotate {{0, 0, 1}, {0, 0, 0}, k*A0} { Duplicata{Line{lineMBrotor[]};} };
EndFor

// -------------------------------------------------------------------------------
// -------------------------------------------------------------------------------
If(SymmetryFactor<8)
// FULL MODEL ==> Rotation of NbrPolesTot*Pi/4
// For simplicity: rotating first the interior and exterior boundaries

  If (SymmetryFactor>1)
    For k In {0:#linR1[]-1}
      linR1_[] += Rotate {{0, 0, 1}, {0, 0, 0}, 2*Pi/SymmetryFactor-Pi/4} { Duplicata{Line{linR1[k]};} };
    EndFor
    linR1[] = linR1_[];
  EndIf

  For k In {1:NbrPoles-1}
    surfint[] += Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Line{surfint[{0:2}]};} };
  EndFor
  For k In {1:NbrPoles-1}
    srotor[] += Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Surface{srotor[0]};} };
    smagnet[]+= Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Surface{smagnet[0]};} };
    sairrotor[]  += Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Surface{sairrotor[{0,1}]};} };
    sairrotormb[]+= Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Surface{sairrotormb[0]};} };
  EndFor
EndIf


// -------------------------------------------------------------------------------
// Physical regions
// -------------------------------------------------------------------------------

Physical Surface(ROTOR_FE)     = {srotor[]};     // Rotor
Physical Surface(ROTOR_AIR)    = {sairrotor[]};  // AirRotor
Physical Surface(ROTOR_AIRGAP) = {sairrotormb[]};// AirRotor for possible torque computation with Maxwell stress tensor

NN = (Flag_Symmetry)?NbrPoles:NbrPolesTot;
For k In {0:NN-1}
  Physical Surface(ROTOR_MAGNET+k) = {smagnet[k]}; // Magnets
EndFor

Physical Line(SURF_INT) = {surfint[]}; // SurfInt


If(Flag_Symmetry)  //Lines for symmetry link
  Physical Line(ROTOR_BND_A0)  = linR0[];
  Physical Line(ROTOR_BND_A1)  = linR1[];
EndIf

lineMBrotor[] += lineMBrotoraux[] ;
If(!Flag_Symmetry)
  Physical Line(ROTOR_BND_MOVING_BAND)  = {lineMBrotor[]};
EndIf
If(Flag_Symmetry)
  nr = #lineMBrotor[];
  nnp = nr/(NbrPolesTot/NbrSect) ;
  For k In {1:Floor[NbrPolesTot/NbrSect]}
    kk= ((k*nnp-1) > nr) ? nr-1 : k*nnp-1 ;
    Physical Line(ROTOR_BND_MOVING_BAND+k-1) = lineMBrotor[{(k-1)*nnp:kk}] ;
  EndFor
  k1 = Floor[NbrPolesTot/NbrSect];
  k2 = Ceil[NbrPolesTot/NbrSect];
  If (k2 > k1)
    Physical Line(ROTOR_BND_MOVING_BAND+k2-1) = lineMBrotor[{(k2-1)*nnp:#lineMBrotor[]-1}] ;
  EndIf
EndIf

// For nice visualisation...
linRotor[]  = CombinedBoundary{Surface{srotor[]};};
linMagnet[] = Boundary{Surface{smagnet[]};};

nicepos_rotor[] += { linRotor[], linMagnet[] };

Color SteelBlue {Surface{srotor[]};}
Color SkyBlue {Surface{sairrotor[], sairrotormb[]};}
Color Orchid {Surface{smagnet[{0:#smagnet[]-1:2}]};}
If(#smagnet[]>1)
Color Purple {Surface{smagnet[{1:#smagnet[]-1:2}]};}
EndIf
