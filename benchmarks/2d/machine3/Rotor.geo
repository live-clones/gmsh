
Geometry.AutoCoherence = 0;      
Mesh.CharacteristicLengthFactor = 1.;

NbrPoles = 1; // number of rotor poles in FE model
NbrPolesT = 4; // number of poles in complete cross-section 
NbrSectT = 40; // number of "rotor teeth"
NbrSect = NbrSectT*NbrPoles/NbrPolesT; // number of "rotor teeth" in FE model

RotorAngle_R = Pi/NbrSectT -Pi/2; // initial rotor angle (radians)
RotorAngle_S = RotorAngle_R;


/* physical rotor numbers (for GetDP and Gmsh) */

RotorBars= 17900; gg=RotorBars;
  RotorBar01 = gg+01; RotorBar02 = gg+02; RotorBar03 = gg+03; RotorBar04 = gg+04; RotorBar05 = gg+05; RotorBar06 = gg+06;
  RotorBar07 = gg+07; RotorBar08 = gg+08; RotorBar09 = gg+09; RotorBar10 = gg+10; RotorBar11 = gg+11; RotorBar12 = gg+12;  
  RotorBar13 = gg+13; RotorBar14 = gg+14; RotorBar15 = gg+15; RotorBar16 = gg+16; RotorBar17 = gg+17; RotorBar18 = gg+18;
  RotorBar19 = gg+19; RotorBar20 = gg+20; RotorBar21 = gg+21; RotorBar22 = gg+22; RotorBar23 = gg+23; RotorBar24 = gg+24;  
  RotorBar25 = gg+25; RotorBar26 = gg+26; RotorBar27 = gg+27; RotorBar28 = gg+28; RotorBar29 = gg+29; RotorBar30 = gg+30; 
  RotorBar31 = gg+31; RotorBar32 = gg+32; RotorBar33 = gg+33; RotorBar34 = gg+34; RotorBar35 = gg+35; RotorBar36 = gg+36;
  RotorBar37 = gg+37; RotorBar38 = gg+38; RotorBar39 = gg+39; RotorBar40 = gg+40; RotorBar41 = gg+41; RotorBar42 = gg+42;


RotorIron = 5000;
RotorShaft = 5555;
RotorAirgapLayer = 1999;
RotorSlotOpening = 2999;

RotorPeriod_Reference = 200000; 
RotorPeriod_Dependent = 200001;
RotorBoundary = 900;
OuterShaft = 6666;
InnerMB = 16000; MB_R1 = InnerMB+1; MB_R2 = InnerMB+2; MB_R3 = InnerMB+3; MB_R4 = InnerMB+4;


u=1e-3; // scale factor

AG = u* 0.47;       // airgap width
R2 = u* 92/2 - AG;      // outer rotor radius
//R2 = u* 92/2;      // outer rotor radius
R3 = u* 31.75/2;      // shaft radius
//R1 = u* 94/2;        // inner radius of moving band
R1 = R2+AG/3;        // inner radius of moving band

/*
R1 = u* 88/2;       // inner radius of moving band
R2 = u* 86/2;     // outer rotor radius
R3 = u* 31.75/2;      // shaft radius
*/


// parameters for conductor and slot opening
h1  = u* 1;
h2  = u* 14.25;
d1  = u* 2;
Rsl = u* 4.26/2;
      
// characteristic lengths
uc = u* 1.3;

pslo = uc* 0.3; // slot opening
psl  = uc* 0.6; // upper part slot 
pslu = uc* 1; // lower part slot 
psha = uc* 2; // shaft radius
pMB  = AG; // MB
//pMB  = uc* 0.5; // MB
p  = uc* 2; // 

Y1 = Sqrt(R2*R2-d1*d1/4) ;
Y2 = Sqrt(Rsl*Rsl-d1*d1/4) ;
Y3 = Sqrt(R1*R1-d1*d1/4) ;
RX = Rsl*Cos(Pi/NbrSectT) ;
RY = Rsl*Sin(Pi/NbrSectT) ;
RR = (h2-Rsl*(1+1/Sin(Pi/NbrSectT)))/(1-1/Sin(Pi/NbrSectT));
RX2 = RR*Cos(Pi/NbrSectT) ;
RY2 = RR*Sin(Pi/NbrSectT) ;


lc_1=0.0005;
lc_2=0.0015;
lc_3=0.003;
lc_4=0.005;

a_x=0.000784;
a_y=0.04755;
b_x=0.002319;
b_y=0.067049;
c_x=0.000700;
c_y=0.070521;
d_x=0.0007;
d_y=0.075021;
e_x=0.00145;
e_y=0.075650;
f_x=0.001450;
f_y=0.077333;
g_x=0;
g_y=0.078550;
h_x=(0.053/2)*Sin(4.5*(Pi/180.));
h_y=(0.053/2)*Cos(4.5*(Pi/180.));
hh_x=(0.053/2)*Sin(0*(Pi/180.));
hh_y=(0.053/2)*Cos(0*(Pi/180.));
R_i=0.080-0.00065;
i_x=R_i*Sin(4.5*Pi/180);
i_y=R_i*Cos(4.5*Pi/180);


k_y=0.080-0.000650;
l_y=0.080-(0.000650*(2/3));
m_x=l_y*Sin(4.5*(Pi/180.));
m_y=l_y*Cos(4.5*(Pi/180.));
o_x=R_i*Sin(1.5*(Pi/180.));
o_y=R_i*Cos(1.5*(Pi/180.));
o_x=1.45e-3;
o_y=Sqrt(R_i^2-o_x^2);

oo_x=1.45e-3;
oo_y=Sqrt(l_y^2-o_x^2);


ii_x=l_y*Sin(4.5*Pi/180);
ii_y=l_y*Cos(4.5*Pi/180);

Point(0)  = {0,0,0,p};

For i In {0:NbrSect-1}
For j In {0:1}

dP=newp-1;

Point(dP+1) = {h_x,h_y,0,lc_4};
Point(dP+2) = {hh_x,hh_y,0,lc_4};
Point(dP+3) = {i_x,i_y,0, 0.7e-3};
Point(dP+4) = {ii_x,ii_y,0, 0.7e-3};
Point(dP+5) = {a_x,a_y,0, 2e-3};
Point(dP+6) = {0,a_y,0,1e-3};
Point(dP+7) = {b_x,b_y,0,lc_3*0.8};
Point(dP+8) = {c_x,c_y,0,lc_2*0.8};
Point(dP+9) = {0,c_y,0,lc_2};
Point(dP+10) = {d_x,d_y,0,lc_2};
Point(dP+11) = {0,d_y,0,lc_2};
Point(dP+12) = {e_x,e_y,0,lc_2};
Point(dP+13) = {f_x,f_y,0,lc_1};
Point(dP+14) = {g_x,g_y,0,lc_1};
Point(dP+15) = {0,R_i,0,0.3e-3};
Point(dP+16) = {0,l_y,0,0.3e-3};
Point(dP+17) = {o_x,o_y,0, 0.6e-3};
Point(dP+18) = {oo_x,oo_y,0, 0.6e-3};

For t In {dP+1:dP+18}
  Rotate {{0,0,1},{0,0,0}, RotorAngle_R+2*Pi*i/NbrSectT} {Point{t};}
EndFor

If (j==1)
  For t In {dP+1:dP+18}
    Symmetry {Cos(RotorAngle_S+2*Pi*i/NbrSectT),Sin(RotorAngle_S+2*Pi*i/NbrSectT),0,0} { Point{t}; }  
  EndFor
EndIf

dR=newreg-1;
Line(dR+1) = {dP+16,dP+15};
Line(dR+2) = {dP+15,dP+14};
Line(dR+3) = {dP+14,dP+11};
Line(dR+4) = {dP+14,dP+13};
Line(dR+5) = {dP+13,dP+12};
Line(dR+6) = {dP+12,dP+10};
Line(dR+7) = {dP+4,dP+3};
Line(dR+8) = {dP+11,dP+9};
Line(dR+9) = {dP+10,dP+8};
Line(dR+10) = {dP+8,dP+7};
Line(dR+11) = {dP+7,dP+5};
Line(dR+12) = {dP+5,dP+6};
Line(dR+13) = {dP+6,dP+9};
Line(dR+14) = {dP+6,dP+2};
Line(dR+15) = {dP+3,dP+1};
Circle(dR+16) = {dP+3,0,dP+17};
Circle(dR+17) = {dP+17,0,dP+15};
Circle(dR+18) = {dP+1,0,dP+2};
Circle(dR+19) = {dP+4,0,dP+18};
Circle(dR+20) = {dP+18,0,dP+16};
Line(dR+21) = {dP+13,dP+17};


// physical lines

OuterShaft_[{2*i+j}] = dR+18;
//RotorBoundary_[{14*i+7*j:14*i+7*j+6}] = {dR+12,dR+15,dR+13,dR+1,dR+16,dR+17,dR+14};
RotorBoundary_[{20*i+10*j:20*i+10*j+9}] = {dR+4,dR+5,dR+6,dR+9,dR+10,dR+11,dR+12,dR+18,dR+16,dR+17};
If (j==0)
  InnerMB_[{4*i+2*j:4*i+2*j+1}] = {dR+19,dR+20};
EndIf
If (j==1)
  InnerMB_[{4*i+2*j:4*i+2*j+1}] = {-dR-19,-dR-20};
EndIf

If (NbrSectT != NbrSect)
  If (i==0 && j==0)
    Physical Line(RotorPeriod_Reference) =  {dR+7,dR+15};
    RotorPeriod_Reference_[] =  {dR+7,dR+15};
  EndIf
  If (i == NbrSect-1  && j==1)
    Physical Line(RotorPeriod_Dependent) = {dR+7,dR+15};
    RotorPeriod_Dependent_[] =  {dR+7,dR+15};
  EndIf
EndIf


dH=newreg;  // rotor conductor
Line Loop(dH) = {-dR-12,-dR-11,-dR-10,-dR-9,-dR-6,-dR-5,-dR-4,dR+3,dR+8,-dR-13};                    
Plane Surface(dH) ={dH};
RotorConductor_[2*i+j] = dH;


dH=newreg;  // rotor iron
Line Loop(dH) = {dR+16,-dR-21,dR+5,dR+6,dR+9,dR+10,dR+11,dR+12,dR+14,-dR-18,-dR-15};
Plane Surface(dH) = {dH};
RotorIron_[2*i+j] = dH;

/*
dH=newreg;   // rotor shaft
Line Loop(dH) = {-dR-5,dR+2,dR+12};
Plane Surface(dH) = {dH};
RotorShaft_[2*i+j] = dH;
*/

dH=newreg;   // rotor slot opening  
Line Loop(dH) = {dR+21,dR+17,dR+2,dR+4};
Plane Surface(dH) ={dH};
RotorSlotOpening_[2*i+j] = dH;

dH=newreg;  // rotor airgap layer
Line Loop(dH) = {-dR-1,-dR-20,-dR-19,dR+7,dR+16,dR+17};
Plane Surface(dH) = {dH};
RotorAirgapLayer_[2*i+j] = dH;


EndFor
EndFor



For i In {0:NbrSect-1}
   Physical Surface(RotorBars+1+i) = RotorConductor_[{2*i:2*i+1}];
   Color Orange {Surface{RotorConductor_[{2*i}]};}
   Color Orange {Surface{RotorConductor_[{2*i+1}]};}
EndFor


Physical Surface(RotorIron) = {RotorIron_[{0:NbrSect*2-1}]};
Physical Surface(RotorSlotOpening) = {RotorSlotOpening_[{0:NbrSect*2-1}]};
Physical Surface(RotorAirgapLayer) = {RotorAirgapLayer_[{0:NbrSect*2-1}]};

Color Red {Surface{RotorIron_[{0:NbrSect*2-1}]};}
Color Black {Surface{RotorSlotOpening_[{0:NbrSect*2-1}]};}
Color Black {Surface{RotorAirgapLayer_[{0:NbrSect*2-1}]};}
//Color Black {Surface{RotorShaft_[{0:NbrSect*2-1}]};}

Physical Line(OuterShaft) = {OuterShaft_[]};

If (NbrSectT != NbrSect)
  Physical Line(RotorBoundary) = {RotorBoundary_[],RotorPeriod_Reference_[],RotorPeriod_Dependent_[]};
EndIf
If (NbrSectT == NbrSect)
  Physical Line(RotorBoundary) = {RotorBoundary_[]};
EndIf



// moving band

For i In {NbrSect:NbrSectT-1}
If (i < NbrSectT)
  For j In {0:1}
    dP=newp-1;


    Point(dP+4) = {ii_x,ii_y,0,0.7e-3};
    Point(dP+16) = {0,l_y,0,0.3e-3};
    Point(dP+18) = {oo_x,oo_y,0,0.6e-3};
    Rotate {{0,0,1},{0,0,0}, RotorAngle_R+2*Pi*i/NbrSectT} { Point{dP+4}; Point{dP+16}; Point{dP+18}; }
    If (j==1)
      Symmetry {Cos(RotorAngle_S+2*Pi*i/NbrSectT),Sin(RotorAngle_S+2*Pi*i/NbrSectT),0,0} 
                { Point{dP+4}; Point{dP+16}; Point{dP+18}; }  
    EndIf

    dR=newreg-1;
    Circle(dR+19) = {dP+4,0,dP+18};
    Circle(dR+20) = {dP+18,0,dP+16};

    If (j==0)
      InnerMB_[{4*i+2*j:4*i+2*j+1}] = {dR+19,dR+20};
    EndIf
    If (j==1)
      InnerMB_[{4*i+2*j:4*i+2*j+1}] = {-dR-19,-dR-20};
    EndIf
  EndFor
EndIf
EndFor

For i In {0:NbrPolesT-1}
  Physical Line(InnerMB+i+1) = {InnerMB_[{i*4*NbrSect/NbrPoles:(i*4+4)*NbrSect/NbrPoles-1}]};
EndFor
  


Coherence;












