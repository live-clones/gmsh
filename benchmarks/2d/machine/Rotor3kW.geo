


NbrSect = 32; // number of rotor teeth

u=1e-3; // scale factor

AG = u* 0.4;       // airgap width
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
RX = Rsl*Cos(Pi/NbrSect) ;
RY = Rsl*Sin(Pi/NbrSect) ;
RR = (h2-Rsl*(1+1/Sin(Pi/NbrSect)))/(1-1/Sin(Pi/NbrSect));
RX2 = RR*Cos(Pi/NbrSect) ;
RY2 = RR*Sin(Pi/NbrSect) ;

//Point(0)  = {0,0,0,p};

dP=newp-1;
Point(dP+1)  = {d1/2,Y1,0,pslo};
Point(dP+2)  = {-d1/2,Y1,0,pslo};
Point(dP+3)  = {d1/2,Y1-h1,0,pslo};
Point(dP+4)  = {-d1/2,Y1-h1,0,pslo};
Point(dP+5)  = {0,Y1-h1-Y2,0,pslo};
Point(dP+6)  = {RX,Y1-h1-Y2-RY,0,psl};
Point(dP+7)  = {-RX,Y1-h1-Y2-RY,0,psl};
Point(dP+8)  = {0,Y1-h1-Y2+Rsl-h2+RR,0,p};
Point(dP+9)  = {RX2,Y1-h1-Y2+Rsl-h2+RR-RY2,0,pslu};
Point(dP+10)  = {-RX2,Y1-h1-Y2+Rsl-h2+RR-RY2,0,pslu};
Point(dP+11)  = {0,Y1-h1-Y2+Rsl-h2,0,pslu};
Point(dP+12)  = {0,Y1-h1-Y2+Rsl,0,p};                          // not used
Point(dP+13) = {R3*Sin(Pi/NbrSect),R3*Cos(Pi/NbrSect),0,psha};
Point(dP+14) = {-R3*Sin(Pi/NbrSect),R3*Cos(Pi/NbrSect),0,psha};

Point(dP+15) = {R2*Sin(Pi/NbrSect),R2*Cos(Pi/NbrSect),0,pMB};
Point(dP+16) = {-R2*Sin(Pi/NbrSect),R2*Cos(Pi/NbrSect),0,pMB};
Point(dP+17) = {R1*Sin(Pi/NbrSect),R1*Cos(Pi/NbrSect),0,pMB};
Point(dP+18) = {-R1*Sin(Pi/NbrSect),R1*Cos(Pi/NbrSect),0,pMB};


For t In {dP+1:dP+18}
  Rotate {{0,0,1},{0,0,0}, 0*Pi/10} {Point{t};}
EndFor


i=1;
L[i] = newreg; i++; Line(newreg) = {dP+06,dP+09};
L[i] = newreg; i++; Line(newreg) = {dP+07,dP+10};
L[i] = newreg; i++; Line(newreg) = {dP+01,dP+03};
L[i] = newreg; i++; Line(newreg) = {dP+02,dP+04};
L[i] = newreg; i++; Circle(newreg) = {dP+13,0,dP+14};
L[i] = newreg; i++; Circle(newreg) = {dP+15,0,dP+01};
L[i] = newreg; i++; Circle(newreg) = {dP+01,0,dP+02};
L[i] = newreg; i++; Circle(newreg) = {dP+02,0,dP+16};
L[i] = newreg; i++; Circle(newreg) = {dP+06,dP+05,dP+03};
L[i] = newreg; i++; Circle(newreg) = {dP+03,dP+05,dP+04};
L[i] = newreg; i++; Circle(newreg) = {dP+04,dP+05,dP+07};
L[i] = newreg; i++; Circle(newreg) = {dP+10,dP+08,dP+11};
L[i] = newreg; i++; Circle(newreg) = {dP+11,dP+08,dP+09};
L[i] = newreg; i++; Circle(newreg) = {dP+17,0,dP+18};

NbrLine = 14;

/*
L[i] = newreg; i++; Line(newreg) = {dP+15,dP+17};
L[i] = newreg; i++; Line(newreg) = {dP+16,dP+18};
L[i] = newreg; i++; Line(newreg) = {dP+14,dP+16};
L[i] = newreg; i++; Line(newreg) = {dP+13,dP+15};
L[i] = newreg; i++; Line(newreg) = {dP+13,0};
L[i] = newreg; i++; Line(newreg) = {dP+14,0};
*/


NbrLines1 = 3;  LineLoop1[] = {6,7,8};                         // inner airgap
NbrLines2 = 7;  LineLoop2[] = {11,2,12,13,-1,9,10};            // rotor conductor
NbrLines3 = 4;  LineLoop3[] = {10,-4,-7,3};                    // rotor slot opening
NbrLines4 = 1;  LineLoop4[] = {14};                            // inner moving band
NbrLines5 = 1;  LineLoop5[] = {5};                             // shaft
NbrLines6 = 10; LineLoop6[] = {-8,4,11,2,12,13,-1,9,-3,-6};    // inner rotor iron


