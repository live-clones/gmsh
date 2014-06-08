
Mesh.CharacteristicLengthFactor = 1.;

Geometry.AutoCoherence = 0;      

NbrPoles = 1; // number of poles in FE model
NbrPolesT = 4; // number of poles in complete cross-section 
NbrSectT = 48; // number of stator teeth
NbrSect = NbrSectT*NbrPoles/NbrPolesT; // number of stator teeth in FE model

StatorAngle_ = Pi/NbrSectT-Pi/2; // initial stator angle (radians)
//StatorAngle_ = -2*Pi/NbrSectT; // initial stator angle (radians)
StatorAngle_S = StatorAngle_;

// physical stator numbers (for GetDP and Gmsh)

StatorConductor= 1000; //12000
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
      

u=1e-3;
AG = u* 0.47;       // airgap width
R2 = u* 92/2;     // inner stator radius
R3 = u* 150/2;      // outer stator radius
//R1 = u* 90/2;       // outer radius of moving band
R1 = R2-AG/3;       // outer radius of moving band

// parameters for conductor and slot opening
h1  = u* 1;
h2  = u* 15.3;
d1  = u* 2.5;
Rsl = u* 6.36/2;
ss = 0.05;

RR = (h2-Rsl*(1+1/Sin(Pi/NbrSectT)))/(1-1/Sin(Pi/NbrSectT));
Y1 = Sqrt(R2*R2-d1*d1/4) ;
Y2 = Sqrt(RR*RR-d1*d1/4) ;
Y3 = Sqrt(R1*R1-d1*d1/4) ;
RX = Rsl*Cos(Pi/NbrSectT) ;
RY = Rsl*Sin(Pi/NbrSectT) ;
RX2 = RR*Cos(Pi/NbrSectT) ;
RY2 = RR*Sin(Pi/NbrSectT) ;



// characteristic lengths
uc = u* 1.4 ;

pslo = uc* 0.3; // slot opening
psl  = uc* 0.6; // upper part slot 
pslu = uc* 1; // lower part slot 
pout = uc* 2; // outer radius
pMB  = AG*1; // MB 
//pMB  = uc* 0.5; // MB
p  = uc* 2; // 


lc_1=0.0004;
lc_2=0.001;
lc_3=0.003;
a_x=0.001500;
a_y=0.079986;
b_x=0.001500;
b_y=0.080900;
c_x=0.002658;
c_y=0.081380;
d_x=0.003664;
d_y=0.097100;
e_x=0.000006;
e_y=0.101000;
f_x=0.080*Sin(3.75*(Pi/180.));
f_y=0.080*Cos(3.75*(Pi/180.));
g_x=0.120*Sin((3.75*(Pi/180.)));
g_y=0.120*Cos((3.75*(Pi/180.)));
h_y=0.097334;
R_sup = Sqrt(d_x^2+(h_y-d_y)^2);
i_x=0.000000;
i_y=0.101000;
j_x=0.002762;
j_y=0.083000;
k_x=((0.080-(0.00065/3))*Sin(3.75*(Pi/180.)));
k_y=((0.080-(0.00065/3))*Cos(3.75*(Pi/180.)));
l_x=0.001500;
l_y=0.079986-0.00065/3;
m_x=((0.080-(0.00065/3))*Sin(0*(Pi/180.)));
m_y=((0.080-(0.00065/3))*Cos(0*(Pi/180.)));
n_x=0.080*Sin(0*(Pi/180.));
n_y=0.080*Cos(0*(Pi/180.));
o_x=0.120*Sin((0*(Pi/180.)));
o_y=0.120*Cos((0*(Pi/180.)));



//Point(0)  = {0,0,0,p};


For i In {0:NbrSect-1}
For j In {0:1}

dP=newp-1;
Point(dP+1) = {a_x,a_y,0,lc_1};
Point(dP+2) = {b_x,b_y,0,lc_1};
Point(dP+3) = {c_x,c_y,0,lc_2*0.6};
Point(dP+4) = {d_x,d_y,0,lc_3};
Point(dP+5) = {0,h_y+R_sup,0,lc_3*0.5};
Point(dP+6) = {g_x,g_y,0,lc_3*1.3};
Point(dP+7) = {f_x,f_y,0,lc_1*1.4};
Point(dP+8) = {0,h_y,0,lc_3};
Point(dP+9) = {k_x,k_y,0,lc_1*1.4};
Point(dP+10) = {l_x,l_y,0,lc_1};
Point(dP+11) = {m_x,m_y,0,lc_1};
Point(dP+12) = {n_x,n_y,0,lc_1};
Point(dP+13) = {o_x,o_y,0,lc_3*1.3};
Point(dP+14) = {j_x,j_y,0,lc_2};
Point(dP+15) = {0,j_y,0,lc_2};


For t In {dP+1:dP+15}
  Rotate {{0,0,1},{0,0,0}, StatorAngle_+2*Pi*i/NbrSectT} {Point{t};}
EndFor

If (j==1)
  For t In {dP+1:dP+15}
    Symmetry {Cos(StatorAngle_S+2*Pi*i/NbrSectT),Sin(StatorAngle_S+2*Pi*i/NbrSectT),0,0} { Point{t}; }  
  EndFor
EndIf


dR=newreg-1;
Line(dR+1) = {dP+7,dP+6};
Line(dR+2) = {dP+10,dP+1};
Line(dR+3) = {dP+1,dP+2};
Line(dR+4) = {dP+2,dP+3};
Line(dR+5) = {dP+3,dP+14};
Line(dR+6) = {dP+14,dP+4};
Line(dR+7) = {dP+11,dP+12};
Line(dR+8) = {dP+12,dP+15};
Line(dR+9) = {dP+15,dP+8};
Line(dR+10) = {dP+8,dP+5};
Line(dR+11) = {dP+5,dP+13};
Line(dR+12) = {dP+15,dP+14};
Circle(dR+13) = {dP+6,0,dP+13};
Circle(dR+14) = {dP+4,dP+8,dP+5};
Circle(dR+15) = {dP+9,0,dP+10};
Circle(dR+16) = {dP+10,0,dP+11};
Circle(dR+17) = {dP+7,0,dP+1};
Circle(dR+18) = {dP+1,0,dP+12};
Line(dR+19) = {dP+9,dP+7};


// physical lines

OuterStator_[{2*i+j}] = dR+13;
StatorBoundary_[{16*i+8*j:16*i+8*j+7}] = {dR+3,dR+4,dR+5,dR+6,dR+13,dR+14,dR+17,dR+12};

If (j==0)
  OuterMB_[{4*i+2*j:4*i+2*j+1}] = {dR+15,dR+16};
EndIf
If (j==1)
  OuterMB_[{4*i+2*j:4*i+2*j+1}] = {-dR-15,-dR-16};
EndIf


If (NbrSectT != NbrSect)
  If (i==0 && j==0)
    Physical Line(StatorPeriod_Reference) = {dR+1,dR+19};
    StatorPeriod_Reference_[] = {dR+1,dR+19};
  EndIf
  If (i == NbrSect-1  && j==1)
    Physical Line(StatorPeriod_Dependent) = {dR+1,dR+19};
    StatorPeriod_Dependent_[] = {dR+1,dR+19};
  EndIf
EndIf

dH=newreg; 
Line Loop(dH) = {dR+6,dR+14,-dR-10,-dR-9,dR+12};                    
Plane Surface(dH) ={dH};
StatorConductor_[2*i+j] = dH;

dH=newreg;
Line Loop(dH) = {dR+3,dR+4,dR+5,dR+6,dR+14,dR+11,-dR-13,-dR-1,dR+17};
Plane Surface(dH) = {dH};
StatorIron_[2*i+j] = dH;

dH=newreg;     
Line Loop(dH) = {-dR-12,-dR-8,-dR-18,dR+3,dR+4,dR+5};
Plane Surface(dH) ={dH};
StatorSlotOpening_[2*i+j] = dH;

dH=newreg;
Line Loop(dH) = {-dR-7,dR+17,dR+18,-dR-16,-dR-15,dR+19};
Plane Surface(dH) = {dH};
StatorAirgapLayer_[2*i+j] = dH;

EndFor
EndFor



qq=4;

For f In {0:5}
  nCon=0;
  For i In {0:NbrSect/qq-1}
    If (Fmod(i,6) == f)
      For j In {0:qq-1}
        nCon+=2; Con[{nCon-2,nCon-1}] = {StatorConductor_[2*i*qq+2*j],StatorConductor_[2*i*qq+2*j+1]};
      EndFor
    EndIf
  EndFor
  If (nCon > 0)
    Physical Surface(StatorConductor+1+f) = {Con[{0:nCon-1}]};
// Color {R[f],G[f],B[f],1} {Surface{Con[{0:nCon-1}]};}
    If (f == 0)
      Color Pink {Surface{Con[{0:nCon-1}]};}
    EndIf
    If (f == 1)
      Color Cyan {Surface{Con[{0:nCon-1}]};}
    EndIf
    If (f == 2)
      Color Orange {Surface{Con[{0:nCon-1}]};}
    EndIf
  EndIf
EndFor



Physical Surface(StatorIron) = {StatorIron_[{0:NbrSect*2-1}]};
Physical Surface(StatorSlotOpening) = {StatorSlotOpening_[{0:NbrSect*2-1}]};
Physical Surface(StatorAirgapLayer) = {StatorAirgapLayer_[{0:NbrSect*2-1}]};

Color Red {Surface{StatorIron_[{0:NbrSect*2-1}]};}
Color Black {Surface{StatorSlotOpening_[{0:NbrSect*2-1}]};}
Color Black {Surface{StatorAirgapLayer_[{0:NbrSect*2-1}]};}

Physical Line(OuterStator) = {OuterStator_[]};

If (NbrSectT != NbrSect)
  Physical Line(StatorBoundary) = {StatorBoundary_[],StatorPeriod_Reference_[],StatorPeriod_Dependent_[]};
EndIf
If (NbrSectT == NbrSect)
  Physical Line(StatorBoundary) = {StatorBoundary_[]};
EndIf




// moving band

For i In {NbrSect:NbrSectT-1}
If (i < NbrSectT)
  For j In {0:1}
    dP=newp-1;

    Point(dP+9) = {k_x,k_y,0,lc_1*1.4};
    Point(dP+10) = {l_x,l_y,0,lc_1};
    Point(dP+11) = {m_x,m_y,0,lc_1};
   // Point(dP+12) = {n_x,n_y,0,lc_1};

    Rotate {{0,0,1},{0,0,0}, StatorAngle_+2*Pi*i/NbrSectT} { Point{dP+9}; Point{dP+10}; Point{dP+11}; }
    If (j==1)
      Symmetry {Cos(StatorAngle_S+2*Pi*i/NbrSectT),Sin(StatorAngle_S+2*Pi*i/NbrSectT),0,0} 
                { Point{dP+9}; Point{dP+10}; Point{dP+11}; }  
    EndIf
    dR=newreg-1;
    Circle(dR+15) = {dP+9,0,dP+10};
    Circle(dR+16) = {dP+10,0,dP+11};

    If (j==0)
      OuterMB_[{4*i+2*j:4*i+2*j+1}] = {dR+15,dR+16};
    EndIf
    If (j==1)
      OuterMB_[{4*i+2*j:4*i+2*j+1}] = {-dR-15,-dR-16};
    EndIf
  EndFor
EndIf
EndFor

For i In {0:NbrPolesT-1}
  Physical Line(OuterMB+i+1) = {OuterMB_[{i*4*NbrSect/NbrPoles:(i*4+4)*NbrSect/NbrPoles-1}]};
EndFor
  

Coherence;









