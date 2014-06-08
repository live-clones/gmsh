
Geometry.AutoCoherence = 0;      

NbrPoles = 1; // number of poles in FE model
NbrPolesT = 4; // number of poles in complete cross-section 
NbrSectT = 36; // number of stator teeth
NbrSect = NbrSectT*NbrPoles/NbrPolesT; // number of stator teeth in FE model

StatorAngle_ = Pi/2. ; //Pi/NbrSectT; // initial stator angle (radians)
StatorAngle_S = StatorAngle_ + Pi/2 + Pi/NbrSectT;

// physical stator numbers (for GetDP and Gmsh)

StatorConductor= 12000;
 Stat_Up = StatorConductor+1; Stat_Wm = StatorConductor+2; Stat_Vp = StatorConductor+3; 
 Stat_Um = StatorConductor+4; Stat_Wp = StatorConductor+5; Stat_Vm = StatorConductor+6; 
StatorIron        = 10000;
StatorSlotOpening = 14000;
StatorAirgapLayer = 11000;

OuterStator = 40000;
StatorPeriod_Reference = 100000; 
StatorPeriod_Dependent = 100001;
StatorBoundary  = 800;
OuterMB = 17000; MB_S1 = OuterMB+1; MB_S2 = OuterMB+2; MB_S3 = OuterMB+3; MB_S4 = OuterMB+4;


// characteristic lengths
uc = 1e-3* 6;
pslo = uc* 0.3*2/2/1.5; // slot opening
psl  = uc* 1; // upper part slot 
pout = uc* 1.9; // outer radius
pMB  = uc* 0.2 * 2/2/2; // MB

R_=54.9;
//R_=54.3;


//Point(0)  = {0,0,0,psl};

For i In {0:NbrSect-1}
For j In {0:1}

dP=newp-1;
Point(dP+1)  = {54.907e-3,3.195e-3,0,pslo/3};
Point(dP+2)  = {55.905e-3,3.253e-3,0,pslo};
Point(dP+3)  = {58.099e-3,2.532e-3,0,psl};
Point(dP+4)  = {66.705e-3,2.450e-3,0,psl};
Point(dP+5)  = {68.594e-3,4.623e-3,0,psl};
Point(dP+6)  = {69e-3*Cos(Pi/36),69e-3*Sin(Pi/36),0,psl};
Point(dP+7)  = {56e-3*Cos(Pi/36),56e-3*Sin(Pi/36),0,pslo*1.5};
Point(dP+8)  = {55e-3*Cos(Pi/36),55e-3*Sin(Pi/36),0,pslo};
Point(dP+9)  = {55.000e-3,0.000e-3,0,pMB*3};
Point(dP+10) = {84.000e-3,0.000e-3,0,pout};
Point(dP+11)  = {84e-3*Cos(Pi/36),84e-3*Sin(Pi/36),0,pout};

Point(dP+12)  = {R_/55* 54.907e-3, R_/55* 3.195e-3,0,pMB};
Point(dP+13)  = {R_*1e-3*Cos(Pi/36),R_*1e-3*Sin(Pi/36),0,pMB};
Point(dP+14)  = {R_/55* 55.000e-3, R_/55* 0.000e-3,0,pMB*2};

For t In {dP+1:dP+14}
  Rotate {{0,0,1},{0,0,0}, StatorAngle_+2*Pi*i/NbrSectT} {Point{t};}
EndFor

If (j==1)
  For t In {dP+1:dP+14}
    Symmetry {Cos(StatorAngle_S+2*Pi*i/NbrSectT),Sin(StatorAngle_S+2*Pi*i/NbrSectT),0,0} { Point{t}; }  
  EndFor
EndIf


dR=newreg-1;
Line(dR+1) = {dP+9,dP+10};
Line(dR+2) = {dP+3,dP+4};
Line(dR+3) = {dP+4,dP+5};
Line(dR+4) = {dP+5,dP+6};
Line(dR+5) = {dP+6,dP+11};
Line(dR+6) = {dP+7,dP+6};
Line(dR+7) = {dP+8,dP+7};
Line(dR+8) = {dP+2,dP+7};
Line(dR+9) = {dP+2,dP+3};
Line(dR+10) = {dP+1,dP+2};
Circle(dR+11) = {dP+10,0,dP+11};
Circle(dR+12) = {dP+9,0,dP+1};
Circle(dR+13) = {dP+1,0,dP+8};
Circle(dR+14) = {dP+14,0,dP+12};
Circle(dR+15) = {dP+12,0,dP+13};
Line(dR+16) = {dP+14,dP+9};
Line(dR+17) = {dP+13,dP+8};





// physical lines

OuterStator_[{2*i+j}] = dR+11;
StatorBoundary_[{16*i+8*j:16*i+8*j+7}] = {dR+10,dR+8,dR+9,dR+2,dR+3,dR+4,dR+11,dR+12};

If (j==0)
  OuterMB_[{4*i+2*j:4*i+2*j+1}] = {dR+14,dR+15};
EndIf
If (j==1)
  OuterMB_[{4*i+2*j:4*i+2*j+1}] = {-dR-14,-dR-15};
EndIf

If (NbrSectT != NbrSect)
  If (i==0 && j==0)
    Physical Line(StatorPeriod_Reference) = {dR+1,dR+16};
  EndIf
  If (i == NbrSect-1  && j==1)
    Physical Line(StatorPeriod_Dependent) = {dR+1,dR+16};
  EndIf
EndIf


dH=newreg; 
Line Loop(dH) = {dR+6,-dR-4,-dR-3,-dR-2,-dR-9,dR+8};                    
Plane Surface(dH) ={dH};
StatorConductor_[2*i+j] = dH;

dH=newreg;
Line Loop(dH) = {dR+10,dR+9,dR+2,dR+3,dR+4,dR+5,-dR-11,-dR-1,dR+12};
Plane Surface(dH) = {dH};
StatorIron_[2*i+j] = dH;

dH=newreg;     
Line Loop(dH) = {dR+8,-dR-7,-dR-13,dR+10};    
Plane Surface(dH) ={dH};
StatorSlotOpening_[2*i+j] = dH;

dH=newreg;
Line Loop(dH) = {-dR-17,-dR-15,-dR-14,dR+16,dR+12,dR+13};
Plane Surface(dH) = {dH};
StatorAirgapLayer_[2*i+j] = dH;

EndFor
EndFor




// Stator winding

For f In {0:5}
  nCon=0;
  For i In {0:NbrSect/3-1}
    If (Fmod(i,6) == f)
      For j In {0:2}
        nCon+=2; Con[{nCon-2,nCon-1}] = {StatorConductor_[2*i*3+2*j],StatorConductor_[2*i*3+2*j+1]};
      EndFor
    EndIf
  EndFor
  If (nCon > 0)
    Physical Surface(StatorConductor+1+f) = {Con[{0:nCon-1}]};
    Color Green{ Surface{ Con[{0:nCon-1}] } ; }
  EndIf
EndFor


Physical Surface(StatorIron) = {StatorIron_[{0:NbrSect*2-1}]};
Physical Surface(StatorSlotOpening) = {StatorSlotOpening_[{0:NbrSect*2-1}]};
Physical Surface(StatorAirgapLayer) = {StatorAirgapLayer_[{0:NbrSect*2-1}]};

Color White{ Surface{ StatorIron_[{0:NbrSect*2-1}] } ; }
Color Blue{ Surface{ StatorSlotOpening_[{0:NbrSect*2-1}] } ; }

Physical Line(OuterStator) = {OuterStator_[]};
Physical Line(StatorBoundary) = {StatorBoundary_[]};

// moving band

For i In {NbrSect:NbrSectT-1}
If (i < NbrSectT)
  For j In {0:1}
    dP=newp-1;
    Point(dP+12)  = {R_/55* 54.907e-3, R_/55* 3.195e-3,0,pMB};
    Point(dP+13)  = {R_*1e-3*Cos(Pi/36),R_*1e-3*Sin(Pi/36),0,pMB};
    Point(dP+14)  = {R_/55* 55.000e-3, R_/55* 0.000e-3,0,pMB*2};
    Rotate {{0,0,1},{0,0,0}, StatorAngle_+2*Pi*i/NbrSectT} { Point{dP+12}; Point{dP+13}; Point{dP+14}; }
    If (j==1)
      Symmetry {Cos(StatorAngle_S+2*Pi*i/NbrSectT),Sin(StatorAngle_S+2*Pi*i/NbrSectT),0,0} 
                { Point{dP+12}; Point{dP+13}; Point{dP+14}; }  
    EndIf
    dR=newreg-1;
    Circle(dR+14) = {dP+14,0,dP+12};
    Circle(dR+15) = {dP+12,0,dP+13};
    If (j==0)
      OuterMB_[{4*i+2*j:4*i+2*j+1}] = {dR+14,dR+15};
    EndIf
    If (j==1)
      OuterMB_[{4*i+2*j:4*i+2*j+1}] = {-dR-14,-dR-15};
    EndIf
  EndFor
EndIf
EndFor

For i In {0:NbrPolesT-1}
  Physical Line(OuterMB+i+1) = {OuterMB_[{i*4*NbrSect/NbrPoles:(i*4+4)*NbrSect/NbrPoles-1}]};
EndFor
  


Coherence;





