
NbrSect = 36; // number of stator teeth

u=1e-3;

AG = u* 0.4;       // airgap width
R2 = u* 92/2;     // inner stator radius
R3 = u* 150/2;      // outer stator radius
//R1 = u* 90/2;       // outer radius of moving band
R1 = R2-AG/3;       // outer radius of moving band


// parameters for conductor and slot opening
h1  = u* 1;
h2  = u* 15.3;
d1  = u* 2.5;
Rsl = u* 6.36/2;

RR = (h2-Rsl*(1+1/Sin(Pi/NbrSect)))/(1-1/Sin(Pi/NbrSect));

Y1 = Sqrt(R2*R2-d1*d1/4) ;
Y2 = Sqrt(RR*RR-d1*d1/4) ;
RX = Rsl*Cos(Pi/NbrSect) ;
RY = Rsl*Sin(Pi/NbrSect) ;
RX2 = RR*Cos(Pi/NbrSect) ;
RY2 = RR*Sin(Pi/NbrSect) ;


p = u* 1.5;



// characteristic lengths
uc = u* 1.4;

pslo = uc* 0.3; // slot opening
psl  = uc* 0.6; // upper part slot 
pslu = uc* 1; // lower part slot 
pout = uc* 3; // outer radius
pMB  = AG; // MB
//pMB  = uc* 0.5; // MB
p  = uc* 2; // 


Point(0)  = {0,0,0,p};

dP=newp-1;
Point(dP+1)  = {d1/2,Y1,0,pslo};
Point(dP+2)  = {-d1/2,Y1,0,pslo};
Point(dP+3)  = {d1/2,Y1+h1,0,pslo};
Point(dP+4)  = {-d1/2,Y1+h1,0,pslo};
Point(dP+5)  = {0,Y1+h1+Y2,0,p};
Point(dP+6)  = {RX2,Y1+h1+Y2-RY2,0,psl};
Point(dP+7)  = {-RX2,Y1+h1+Y2-RY2,0,psl};
Point(dP+8)  = {0,Y1+h1+Y2-RR+h2-Rsl,0,p};
Point(dP+9)  = {RX,Y1+h1+Y2-RR+h2-Rsl-RY,0,pslu};
Point(dP+10)  = {-RX,Y1+h1+Y2-RR+h2-Rsl-RY,0,pslu};
Point(dP+11)  = {0,Y1+h1+Y2-RR+h2,0,pslu};
Point(dP+12)  = {0,Y1+h1+Y2-Rsl,0,p}; //not used
Point(dP+13) = {R3*Sin(Pi/NbrSect),R3*Cos(Pi/NbrSect),0,pout};
Point(dP+14) = {-R3*Sin(Pi/NbrSect),R3*Cos(Pi/NbrSect),0,pout};
Point(dP+15) = {R2*Sin(Pi/NbrSect),R2*Cos(Pi/NbrSect),0,pMB};
Point(dP+16) = {-R2*Sin(Pi/NbrSect),R2*Cos(Pi/NbrSect),0,pMB};
Point(dP+17) = {R1*Sin(Pi/NbrSect),R1*Cos(Pi/NbrSect),0,pMB};
Point(dP+18) = {-R1*Sin(Pi/NbrSect),R1*Cos(Pi/NbrSect),0,pMB};


/*
For t In {dP+1:dP+18}
  Rotate {{0,0,1},{0,0,0}, 0*Pi/10} {Point{t};}
EndFor
*/


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
L[i] = newreg; i++; Line(newreg) = {dP+13,dP+15};
L[i] = newreg; i++; Line(newreg) = {dP+15,dP+17};
L[i] = newreg; i++; Line(newreg) = {dP+14,dP+16};
L[i] = newreg; i++; Line(newreg) = {dP+16,dP+18};
*/


/*
Line Loop(19) = {6,7,8,18,-14,-16};
Plane Surface(20) = {19};
Line Loop(21) = {6,3,10,-4,8,18,-14,-16};
Plane Surface(22) = {21};
Line Loop(23) = {3,-9,1,-13,-12,-2,-11,-4,8,-17,-5,15,6};
Plane Surface(24) = {23};
Line Loop(25) = {11,2,12,13,-1,9,10};
Plane Surface(26) = {25};
*/

NbrLines1 = 3;  LineLoop1[] = {6,7,8};                       // outer airgap
NbrLines2 = 7;  LineLoop2[] = {11,2,12,13,-1,9,10};                     // conductor
NbrLines3 = 4;  LineLoop3[] = {3,10,-4,-7};             // slot opening
NbrLines4 = 1;  LineLoop4[] = {14};                             // outer moving band
NbrLines5 = 1;  LineLoop5[] = {5};                             // outer stator
NbrLines6 = 10; LineLoop6[] = {6,3,-9,1,-13,-12,-2,-11,-4,8};  // inner stator iron









