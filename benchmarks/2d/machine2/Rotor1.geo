
Geometry.AutoCoherence = 0;      
Mesh.CharacteristicLengthFactor = 1;

NbrPoles = 1; // number of rotor poles in FE model
NbrPolesT = 4; // number of poles in complete cross-section 
NbrSectT = NbrPolesT; // number of "rotor teeth"
NbrSect = NbrSectT*NbrPoles/NbrPolesT; // number of "rotor teeth" in FE model

RotorAngle_R = 0; //Pi/NbrSectT; // initial rotor angle (radians)
RotorAngle_S = RotorAngle_R;


/* physical rotor numbers (for GetDP and Gmsh) */

RotorIron = 5000;
RotorShaft = 5555;
RotorAir = 7000;
RotorAirgapLayer = 999;
Tmagnet = 300; Tmagnet1 = Tmagnet+1; Tmagnet2 = Tmagnet+2; Tmagnet3 = Tmagnet+3; Tmagnet4 = Tmagnet+4; 
Cmagnet = 400; Cmagnet1 = Cmagnet+1; Cmagnet2 = Cmagnet+2; Cmagnet3 = Cmagnet+3; Cmagnet4 = Cmagnet+4; 

RotorPeriod_Reference = 200000; 
RotorPeriod_Dependent = 200001;
RotorBoundary = 900;
InnerMB = 16000; MB_R1 = InnerMB+1; MB_R2 = InnerMB+2; MB_R3 = InnerMB+3; MB_R4 = InnerMB+4;



// characteristic lengths
u = 1e-3;
//u = 54.3/55.8 * 1e-3;
uc = 1e-3*12;
p = uc* 1.3;
pa = uc* 0.4;
pc = uc* 0.8;
pMB = uc* 0.06 * 1.5/1.5/2;

R = 55.3;
R = 54.8;


Point(0)  = {0,0,0,p};


For i In {0:NbrSect-1}
For j In {0:1}

dP=newp-1;
Point(dP+1)  = {12.2 *u, 12.2 *u, 0 *u, p};   
Point(dP+2)  = {0 *u, 16.5 *u, 0 *u, pa};   
Point(dP+3)  = {7.9144 *u, 16.5 *u, 0 *u, pa};
Point(dP+4)  = {24.75 *u, 24.75 *u, 0 *u, pa*2};
Point(dP+5)  = {7.9144 *u, 34.07 *u, 0 *u, pa*2};
Point(dP+6)  = {14.5 *u, 34.07 *u, 0 *u, pa*2};
Point(dP+7)  = {14.5 *u, 50.4 *u, 0 *u, pa};
Point(dP+8)  = {0 *u, 50.4 *u, 0 *u, pc};
Point(dP+9)  = {12.611 *u, 53.226 *u, 0 *u, pMB*2/2};
Point(dP+10) = {0 *u, 54.7 *u, 0 *u, pMB*4};
Point(dP+11) = {38.679 *u, 38.679 *u, 0 *u, pMB*8};
Point(dP+12) = {R/Sqrt(2.) *u, R/Sqrt(2.) *u, 0 *u, pMB*4};
Point(dP+13) = {0 *u, R *u, 0 *u, pMB*4};
Point(dP+14) = {R/54.7*12.611 *u, R/54.7*53.226 *u, 0 *u, pMB};


For t In {dP+1:dP+14}
  Rotate {{0,0,1},{0,0,0}, RotorAngle_R+2*Pi*i/NbrSectT} {Point{t};}
EndFor

If (j==1)
  For t In {dP+1:dP+14}
    Symmetry {Cos(RotorAngle_S+2*Pi*i/NbrSectT),Sin(RotorAngle_S+2*Pi*i/NbrSectT),0,0} { Point{t}; }  
  EndFor
EndIf



dR=newreg-1;
Line(dR+1) = {dP+1,dP+3};
Line(dR+2) = {dP+3,dP+2};
Line(dR+3) = {dP+3,dP+5};
Line(dR+4) = {dP+5,dP+6};
Line(dR+5) = {dP+6,dP+7};
Line(dR+6) = {dP+7,dP+8};
Line(dR+7) = {dP+7,dP+9};
Circle(dR+8) = {dP+4,0,dP+5};
Circle(dR+9) = {dP+11,0,dP+9};
Circle(dR+10) = {dP+9,0,dP+10};
Circle(dR+11) = {dP+12,0,dP+14};
Circle(dR+12) = {dP+14,0,dP+13};
Line(dR+13) = {dP+2,dP+8};
Line(dR+14) = {dP+8,dP+10};
Line(dR+15) = {dP+10,dP+13};
Line(dR+16) = {0,dP+2};
Line(dR+17) = {0,dP+1};
Line(dR+18) = {dP+1,dP+4};
Line(dR+19) = {dP+4,dP+11};
Line(dR+20) = {dP+11,dP+12};



// physical lines

RotorBoundary_[{18*i+9*j:18*i+9*j+8}] = {dR+1,dR+2,dR+3,dR+4,dR+5,dR+6,dR+7,dR+8,dR+9};
If (j==0)
  InnerMB_[{4*i+2*j:4*i+2*j+1}] = {dR+11,dR+12};
EndIf
If (j==1)
  InnerMB_[{4*i+2*j:4*i+2*j+1}] = {-dR-11,-dR-12};
EndIf

If (NbrSectT != NbrSect)
  If (i==0 && j==0)
    Physical Line(RotorPeriod_Reference) = {dR+17,dR+18,dR+19};
  EndIf
  If (i == NbrSect-1  && j==1)
    Physical Line(RotorPeriod_Dependent) = {dR+17,dR+18,dR+19};
  EndIf
EndIf


dH=newreg;    // T-magnet
Line Loop(dH) = {-dR-13,-dR-2,dR+3,dR+4,dR+5,dR+6};                    
Plane Surface(dH) ={dH};
Tmagnet_[2*i+j] = dH;

dH=newreg;    // circular magnet
Line Loop(dH) = {dR+8,-dR-3,-dR-1,dR+18};                  
Plane Surface(dH) ={dH};
Cmagnet_[2*i+j] = dH;

dH=newreg;    // rotor iron
Line Loop(dH) = {-dR-9,-dR-19,dR+8,dR+4,dR+5,dR+7};
Plane Surface(dH) = {dH};
RotorIron_[2*i+j] = dH;

dH=newreg;    // rotor shaft
Line Loop(dH) = {dR+1,dR+2,-dR-16,dR+17};
Plane Surface(dH) = {dH};
RotorShaft_[2*i+j] = dH;

dH=newreg;    // rotor air
Line Loop(dH) = {dR+10,-dR-14,-dR-6,dR+7};
Plane Surface(dH) = {dH};
RotorAir_[2*i+j] = dH;

dH=newreg;  // rotor airgap layer
Line Loop(dH) = {dR+15,-dR-12,-dR-11,-dR-20,dR+9,dR+10};
Plane Surface(dH) = {dH};
RotorAirgapLayer_[2*i+j] = dH;



EndFor
EndFor




For i In {0:NbrSect-1}
  Physical Surface(Tmagnet+1+i) = {Tmagnet_[{2*i:2*i+1}]};
EndFor

For i In {0:2*NbrSect+1:2}
  nCon=0;
  If (Fmod(i-1+2*NbrSectT,2*NbrSectT) < 2*NbrSect)
    nCon++; Con[nCon-1] = Cmagnet_[Fmod(i-1+2*NbrSectT,2*NbrSectT)]; 
  EndIf
  If (i < 2*NbrSect)
    nCon++; Con[nCon-1] = Cmagnet_[i]; 
  EndIf
  If (nCon > 0)
    Physical Surface(Cmagnet+1+i/2) = {Con[{0:nCon-1}]};
  EndIf
EndFor

Physical Surface(RotorIron) = {RotorIron_[{0:NbrSect*2-1}]};
Physical Surface(RotorShaft) = {RotorShaft_[{0:NbrSect*2-1}]};
Physical Surface(RotorAir) = {RotorAir_[{0:NbrSect*2-1}]};
Physical Surface(RotorAirgapLayer) = {RotorAirgapLayer_[{0:NbrSect*2-1}]};

Physical Line(RotorBoundary) = {RotorBoundary_[]};



// moving band

For i In {NbrSect:NbrSectT-1}
If (i < NbrSectT)
  For j In {0:1}
    dP=newp-1;
    Point(dP+12) = {R/Sqrt(2.) *u, R/Sqrt(2.) *u, 0 *u, pMB*3};
    Point(dP+13) = {0 *u, R *u, 0 *u, pMB*3};
    Point(dP+14) = {R/54.7*12.611 *u, R/54.7*53.226 *u, 0 *u, pMB};
    Rotate {{0,0,1},{0,0,0}, RotorAngle_R+2*Pi*i/NbrSectT} { Point{dP+12}; Point{dP+13}; Point{dP+14}; }
    If (j==1)
      Symmetry {Cos(RotorAngle_S+2*Pi*i/NbrSectT),Sin(RotorAngle_S+2*Pi*i/NbrSectT),0,0} 
                { Point{dP+12}; Point{dP+13}; Point{dP+14}; }  
    EndIf
    dR=newreg-1;
    Circle(dR+11) = {dP+12,0,dP+14};
    Circle(dR+12) = {dP+14,0,dP+13};
    If (j==0)
      InnerMB_[{4*i+2*j:4*i+2*j+1}] = {dR+11,dR+12};
    EndIf
    If (j==1)
      InnerMB_[{4*i+2*j:4*i+2*j+1}] = {-dR-11,-dR-12};
    EndIf
  EndFor
EndIf
EndFor


For i In {0:NbrPolesT-1}
  Physical Line(InnerMB+i+1) = {InnerMB_[{i*4*NbrSect/NbrPoles:(i*4+4)*NbrSect/NbrPoles-1}]};
EndFor
  



Coherence;




