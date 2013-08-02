// -------------------------------------------------------------------------------
// Moving band == AirGap stator side
// -------------------------------------------------------------------------------
pntG[]+=newp; Point(newp) = {rB2, 0., 0., pS1}; // aligned with the stator
circ[] = Extrude {{0, 0, 1}, {0, 0, 0}, A0} { Point{pntG[0]}; };
pntG[]+=circ[0];
lineMBstator[]=circ[1];
Transfinite Line{lineMBstator[0]} = NbrDivMB+1 ;

//Filling the gap for the whole 2*Pi
For k In {1:NbrPolesTot-1}
  lineMBstatoraux[]+= Rotate {{0, 0, 1}, {0, 0, 0}, k*A0} { Duplicata{Line{lineMBstator[0]};} };
EndFor

// -------------------------------------------------------------------------------
// Stator
// -------------------------------------------------------------------------------

pntS[] = newp; Point(newp)={rS1, 0, 0, pS1};
linS[] = newl; Line(newl) = {pntG[0], pntS[0]};
linS[]+= Rotate {{0, 0, 1}, {0, 0, 0}, A0} { Duplicata{Line{linS[0]};} };

pntS[]+=newp; Point(newp)={rS7,0,0,pS2};
points[]=Boundary{Line{linS[1]};};
pntS[]+=points[1];

lin[] = Extrude {{0, 0, 1}, {0, 0, 0}, A0} { Point{pntS[1]}; };
cirS[]= lin[1]; pntS[]+=lin[0];

linS[]+=newl; Line(newl) = {pntS[0], pntS[1]};
linS[]+=newl; Line(newl) = {pntS[2], pntS[3]};

// -------------------------------------------------------------------------------
// Slots
// -------------------------------------------------------------------------------

A2 = 0.0;
AA[]=deg2rad*{2.77+A2, 4.0+A2, 5.52+A2, 5.56+A2, 5.65+A2, 9.35+A2, 9.44+A2, 9.48+A2, 11+A2, 12.23+A2} ;

For k In {0:#AA[]-1}
  cosAA[]+=Cos(AA[k]); sinAA[]+=Sin(AA[k]);
EndFor

pntSlot[]+=newp; Point(newp)={rS5*cosAA[0], rS5*sinAA[0], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS3*cosAA[1], rS3*sinAA[1], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS1*cosAA[2], rS1*sinAA[2], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS2*cosAA[3], rS2*sinAA[3], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS4*cosAA[3], rS4*sinAA[3], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS6*cosAA[4], rS6*sinAA[4], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS6*cosAA[5], rS6*sinAA[5], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS4*cosAA[6], rS4*sinAA[6], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS2*cosAA[6], rS2*sinAA[6], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS1*cosAA[7], rS1*sinAA[7], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS3*cosAA[8], rS3*sinAA[8], 0., pS3};
pntSlot[]+=newp; Point(newp)={rS5*cosAA[9], rS5*sinAA[9], 0., pS3};

// air slot 1
linASlot[]+=newl ; Line(newl)={pntSlot[2], pntSlot[3]};
linASlot[]+=newl ; Line(newl)={pntSlot[3], pntSlot[1]};
linASlot[]+=newl ; Circle(newl)={pntSlot[1], cen, pntSlot[10]};
linASlot[]+=newl ; Line(newl)={pntSlot[10], pntSlot[8]};
linASlot[]+=newl ; Line(newl)={pntSlot[8], pntSlot[9]};
linASlot[]+=newl ; Circle(newl)={pntSlot[9], cen, pntSlot[2]};

Line Loop(newll) = {linASlot[]};
sairslot[] += news ; Plane Surface(sairslot[0]) = {newll-1};

// coil slot 1
linSlot[]+=newl ; Line(newl)={pntSlot[1], pntSlot[0]};
linSlot[]+=newl ; Circle(newl)= {pntSlot[0], pntSlot[4], pntSlot[5]};
linSlot[]+=newl ; Line(newl)={pntSlot[5], pntSlot[6]};
linSlot[]+=newl ; Circle(newl)={pntSlot[6], pntSlot[7],pntSlot[11]};
linSlot[]+=newl ; Line(newl)={pntSlot[11], pntSlot[10]};

Line Loop(newll) = {-linASlot[2],linSlot[]};
sslot[] += news ; Plane Surface(sslot[0]) = {newll-1};

// slots 2 and 3
A2 = 15*deg2rad;

pntSlot0[0] = pntSlot[2];
pntSlot1[0] = pntSlot[9];
For k In{1:2}
  pntSlot0[] += Rotate {{0, 0, 1}, {0, 0, 0}, A2} { Duplicata{Point{pntSlot0[k-1]};} };
  pntSlot1[] += Rotate {{0, 0, 1}, {0, 0, 0}, A2} { Duplicata{Point{pntSlot1[k-1]};} };
EndFor

For k In{1:2}
  sslot[] += Rotate {{0, 0, 1}, {0, 0, 0}, A2} { Duplicata{Surface{sslot[k-1]};} };
  sairslot[] += Rotate {{0, 0, 1}, {0, 0, 0}, A2} { Duplicata{Surface{sairslot[k-1]};} };
EndFor

cSlot[]+=newl; Circle(newl) = {pntS[0], cen, pntSlot[2]};
cSlot[]+=newl; Circle(newl) = {pntSlot1[0], cen, pntSlot0[1]};
cSlot[]+=newl; Circle(newl) = {pntSlot1[1], cen, pntSlot0[2]};
cSlot[]+=newl; Circle(newl) = {pntSlot1[2], cen, pntS[2]};

linesslot0[] = CombinedBoundary{ Surface{ sslot[0], sairslot[0] } ;};
linesslot1[] = CombinedBoundary{ Surface{ sslot[1], sairslot[1] } ;};
linesslot2[] = CombinedBoundary{ Surface{ sslot[2], sairslot[2] } ;};

Line Loop(newll) = {-lineMBstator[0],linS[0], cSlot[0],-linesslot0[{4}],
                    cSlot[1],-linesslot1[{9}],
                    cSlot[2],-linesslot2[{9}], cSlot[3], -linS[1]};
sairgapS[0]=news; Plane Surface(sairgapS[0]) = {newll-1};

linesslot0[] -= linesslot0[{4}];
linesslot1[] -= linesslot1[{9}];
linesslot2[] -= linesslot2[{9}];
Line Loop(newll) = { cSlot[0], linesslot0[],
                     cSlot[1], linesslot1[],
                     cSlot[2], linesslot2[],
                     cSlot[3], linS[3], -cirS[0], -linS[2]};
sstator[0]=news; Plane Surface(sstator[0]) = {newll-1};

// -------------------------------------------------------------------------------
// -------------------------------------------------------------------------------

auxlink[]=linS[{1,3}]; // A1

If(SymmetryFactor<8)
  // FULL MODEL ==> Rotation of NbrPolesTot*Pi/4
  // For simplicity: rotating the interior and exterior boundaries

 If (SymmetryFactor>1)
    For k In {0:#auxlink[]-1}
      auxlink_[] += Rotate {{0, 0, 1}, {0, 0, 0}, 2*Pi/SymmetryFactor-Pi/4} { Duplicata{Line{auxlink[k]};} };
    EndFor
    auxlink[] = auxlink_[];
  EndIf

  For k In {1:NbrPoles-1}
    cirS[] += Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Line{cirS[{0}]};} };
  EndFor
  For k In {1:NbrPoles-1}
    sstator[]+= Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Surface{sstator[0]};} };
    sairgapS[]+= Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Surface{sairgapS[0]};} };
    sairslot[]+= Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Surface{sairslot[{0:2}]};} };
    sslot[]+= Rotate {{0, 0, 1}, {0, 0, 0}, k*Pi/4} { Duplicata{ Surface{sslot[{0:2}]};} };
  EndFor
EndIf



// -------------------------------------------------------------------------------
// -------------------------------------------------------------------------------
// Physical regions
// -------------------------------------------------------------------------------
// -------------------------------------------------------------------------------

Physical Surface(STATOR_FE)     = {sstator[]};  // Stator
Physical Surface(STATOR_AIR)    = {sairslot[]}; // AirStator
Physical Surface(STATOR_AIRGAP) = {sairgapS[]}; // AirStator for possible torque computation with Maxwell stress tensor

NN = (Flag_Symmetry)?NbrSectStator:NbrSectTotStator;
//For k In {0:NN-1}
//  Physical Surface(STATOR_IND+k) = {sslot[k]}; //Inds
//EndFor

Physical Surface(STATOR_IND_AM) = {sslot[{0:NN-1:6}]};
Physical Surface(STATOR_IND_CP) = {sslot[{1:NN-1:6}]};
Physical Surface(STATOR_IND_BM) = {sslot[{2:NN-1:6}]};
If(NbrSectStator>2)
  Physical Surface(STATOR_IND_AP) = {sslot[{3:NN-1:6}]};
  Physical Surface(STATOR_IND_CM) = {sslot[{4:NN-1:6}]};
  Physical Surface(STATOR_IND_BP) = {sslot[{5:NN-1:6}]};
EndIf

Color Pink         {Surface{ sslot[{0:NN-1:6}] };} // A-
Color ForestGreen  {Surface{ sslot[{1:NN-1:6}] };} // C+
Color PaleGoldenrod{Surface{ sslot[{2:NN-1:6}] };} // B-
If (#sslot[]>=6)
Color Red        {Surface{ sslot[{3:NN-1:6}] };} // A+
Color SpringGreen{Surface{ sslot[{4:NN-1:6}] };} // C-
Color Gold       {Surface{ sslot[{5:NN-1:6}] };} // B+
EndIf


Physical Line(SURF_EXT) = {cirS[]}; // SurfExt

If(Flag_Symmetry) //Lines for symmetry link
  Physical Line(STATOR_BND_A0) = linS[{0,2}];
  Physical Line(STATOR_BND_A1) = auxlink[] ;
EndIf


lineMBstator[] += lineMBstatoraux[] ;
If(!Flag_Symmetry)
  Physical Line(STATOR_BND_MOVING_BAND) = {lineMBstator[]};
EndIf
If(Flag_Symmetry)
ns = #lineMBstator[];
nns = ns/SymmetryFactor ;
For k In {1:SymmetryFactor}
  kk= ((k*nns-1) > ns) ? ns-1 : k*nns-1 ;
  Physical Line(STATOR_BND_MOVING_BAND+k-1) = {lineMBstator[{(k-1)*nns:kk}]};
EndFor
  k1 = Floor[NbrPolesTot/NbrSect];
  k2 = Ceil[NbrPolesTot/NbrSect];
  If (k2 > k1)
    Physical Line(STATOR_BND_MOVING_BAND+k2-1) = lineMBstator[{(k2-1)*nns:#lineMBstator[]-1}] ;
  EndIf
EndIf


// For nice visualisation...
linStator[] = CombinedBoundary{Surface{sstator[]};};
linSlot[] = CombinedBoundary{Surface{sslot[]};};

nicepos_stator[] += {linStator[],linSlot[] };

Color SteelBlue {Surface{sstator[]};}
Color SkyBlue {Surface{sairslot[],sairgapS[]};}


