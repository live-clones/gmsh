Mesh.CharacteristicLengthFactor = 1;
Mesh.Algorithm = 2; /*2D mesh algorithm (1=isotropic, 2=anisotropic, 3=triangle)*/


CLF = 0.995 ; // MARCHE PAS
//CLF = 0.999 ; //OK

RRes = 0.001;  dzRes1 = 0.01 ; 
REl1 = 0.025;  dzEl1 = REl1/25 ;  
RLay1 = 0.030;  dzLay1 = 0.0003 ;
RLay2 = 0.050;  dzLay2 = 0.050 ; 
REl2 = 0.025; dzEl2 = REl2/25 ; 


SigCopper = 1/1.0e-8 ;
SigGel = 1/5000.0 ;
SigMuscle = 1/5.0 ;
Res = 1e6 ; 
SigRes = 1/Res * dzRes1 / Pi / RRes^2 ;

j = 0.1/Pi/0.025^2 ;
I = j * Pi * REl1^2 ; VElec1Pot = I * Res ;




dztot = 0 ;


/* Resistance */
Point(1) = {0,dztot,0.0,RRes/2*CLF};
Point(2) = {RRes,dztot,0,RRes/2*CLF};
dztot = dztot - dzRes1 ; 
Point(3) = {RRes,dztot,0.0,RRes/2*CLF};
Point(4) = {0,dztot,0.0,RRes/2*CLF};		// not used

/* electrode 1 */
lc1 = REl1/50 ; lc2 = REl1/50 ;
Point(5) = {0,dztot,0.0,lc1*CLF};
Point(6) = {REl1,dztot,0,lc1*CLF};
dztot = dztot - dzEl1 ;
Point(7) = {REl1,dztot,0.0,lc2/10*CLF};
Point(8) = {0,dztot,0.0,lc2*CLF};		// not used


/* layer 1 Gel or Resistive slab */ 
lc1 = RLay1/250 ; lc2 = RLay1/250 ;
Point(9) = {0,dztot,0.0,REl1/100*CLF};
Point(10) = {RLay1,dztot,0,lc2*CLF};
dztot = dztot - dzLay1 ; dzElecSurf1 = dztot ;
Point(11) = {RLay1,dztot,0,lc2*CLF};
/*Point(12) = {0,dztot,0.0,lc1*CLF};		// not used

/* layer 2 muscle */
lc1 = REl1/10*CLF; lc2 = Fabs(REl1-RLay2)/10*CLF ; lc3 = dzLay2/10*CLF ;

Point(13) = {0.0,dztot,0.0,lc1/20};
Point(14) = {REl1,dztot,0.0,lc1/20};	/*attractor*/
Point(15) = {RLay2,dztot,0,lc2/2};
dztot = dztot - dzLay2/5 ;			/*attractor*/
Point(16) = {RLay2,dztot,0.0,Sqrt(lc2 * lc3)/2};
Point(17) = {0,dztot,0.0,Sqrt(lc1 * lc3)/2};
dztot = dztot - 3*dzLay2/5 ;			/*attractor*/
Point(18) = {RLay2,dztot,0.0,Sqrt(lc3* lc2)/2 };
Point(19) = {0,dztot,0.0,Sqrt(lc3* lc1)/2};
dztot = dztot - dzLay2/5 ; dzElecSurf2 = dztot ;
Point(20) = {RLay2,dztot,0,lc2/2};	
/*Point(21) = {0,dztot,0.0,lc1/20};		// not used

/* electrode 2 */
lc1 = REl2/100 ; 
Point(22) = {0,dztot,0.0,lc1*CLF};
Point(23) = {REl2,dztot,0,lc1/5*CLF};
dztot = dztot - dzEl2 ;
Point(24) = {REl2,dztot,0.0,1};
Point(25) = {0,dztot,0.0,1};

/* ElectrodeCenterEdge */
Point(26) = {0,dzElecSurf1,0.0,1};
Point(27) = {REl1,dzElecSurf1,0.0,1};
Point(28) = {0,dzElecSurf2,0.0,1};
Point(29) = {REl2,dzElecSurf2,0.0,1};


Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,5};
Line(4) = {5,1};
Line(5) = {3,6};
Line(6) = {6,7};
Line(7) = {7,9};
Line(8) = {9,5};
Line(9) = {7,10};
Line(10) = {10,11};
Line(11) = {11,14};
Line(12) = {14,13};
Line(13) = {13,9};
Line(14) = {11,15};
Line(15) = {15,16};
Line(16) = {16,18};
Line(17) = {18,20};
Line(18) = {20,23};
Line(19) = {23,22};
Line(20) = {22,19};
Line(21) = {19,17};
Line(22) = {17,13};
Line(23) = {23,24};
Line(24) = {24,25};
Line(25) = {25,22};

Line Loop(26) = {2,3,4,1};
Plane Surface(27) = {26};
Line Loop(28) = {5,6,7,8,-3};
Plane Surface(29) = {28};
Line Loop(30) = {9,10,11,12,13,-7};
Plane Surface(31) = {30};
Line Loop(32) = {15,16,17,18,19,20,21,22,-12,-11,14};
Plane Surface(33) = {32};
Physical Point(100) = {26,27,28,29};
Physical Line(101) = {1};
Physical Line(102) = {19};
Physical Surface(1001) = {27};
Physical Surface(1002) = {29};
Physical Surface(1003) = {31};
Physical Surface(1004) = {33};

