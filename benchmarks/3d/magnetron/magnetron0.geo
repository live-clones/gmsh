// (c) patrick lefevre

Geometry.AutoCoherence = 0;//speed up!

mm = 0.001 ; // 1 milimetre = 0.001 metre
lc = 7.3*mm ; // unite de base min pour la taille caracteristique du maillage

lcpba2  =  2*lc ;        // lc dessous plaque base 
lcpba1  =  lc ;          // lc dessus  plaque base
lcrint1 =  3*lc ;        // lc coquille spherique superieure
lcrint2 =  3*lc ;        // lc coquille spherique inferieure
lcrext1 =  3*lcrint1 ;   // lc coquille spherique infini superieure
lcrext2 =  3*lcrint2 ;   // lc coquille spherique infini inferieure

// definition de longueur de la plaque base

eppba    = 28. *mm ;        // epaisseur plaque base 
longpba  = 640./2 *mm ;     // longueur plaque base 
largpba  = 550./2 *mm ;     // largeur plaque base  
rint     = 500. *mm ;       // rayon interne coquille spherique
rext     = 1.5 * rint ;     // rayon externe coquille spherique
// Definition de la plaque base

Point(1)   = {    0.0   ,    0.0   ,    0.0      ,  lcpba2  };  
Point(2)   = {  largpba ,    0.0   ,    0.0      ,  lcpba2  };
Point(3)   = {  largpba ,  longpba ,    0.0      ,  lcpba2  };
Point(4)   = {    0.0   ,  longpba ,    0.0      ,  lcpba2  };

Point(5)   = {    0.0   ,    0.0   ,    eppba      ,  lcpba1  };  
Point(6)   = {  largpba ,    0.0   ,    eppba      ,  lcpba1  };
Point(7)   = {  largpba ,  longpba ,    eppba      ,  lcpba1  };
Point(8)   = {    0.0   ,  longpba ,    eppba      ,  lcpba1  };

Line(9) = {1,2};
Line(10) = {2,3};
Line(11) = {3,4};
Line(12) = {4,1};

Line(14) = {6,7};
Line(15) = {7,8};

Line(17) = {1,5};
Line(18) = {2,6};
Line(19) = {3,7};
Line(20) = {4,8};

//la surface sur laquelle repose les aimants va etre definie plus tard,et donc aussi le volume
Line Loop(21) = {9,10,11,12};
Plane Surface(22) = {21};
Line Loop(25) = {-14,-18,10,19};
Plane Surface(26) = {25};
Line Loop(27) = {20,-15,-19,11};
Plane Surface(28) = {27};

// Air au dessus des aimants pour le degre 2
epair =  eppba +20*mm +60*mm ;
tranZ = 60*mm ;  
Point(32)   = {    0.0   ,    0.0   ,    epair      ,  lcpba2  };  
Point(33)   = {  largpba ,    0.0   ,    epair      ,  lcpba2  };
Point(34)   = {  largpba ,  longpba ,    epair      ,  lcpba2  };
Point(35)   = {    0.0   ,  longpba ,    epair      ,  lcpba2  };

centre=newreg;
Point(centre) = {  0.0     ,    0.0   ,   tranZ      ,  lcpba2  };

Line(37) = {32,33};
Line(38) = {33,34};
Line(39) = {34,35};
Line(40) = {35,32};
Line Loop(41) = {40,37,38,39};
Plane Surface(42) = {41};

// tole sur laquelle on veut calculer la force

hautole = 53*mm; 

Point(50) = {  0.0     ,  0.0   ,  hautole  ,  lc/3 };
Point(51) = { largpba  ,  0.0   ,  hautole  ,  lc/3 };
Point(52) = { largpba  , 215*mm ,  hautole  ,  lc/3 };
Point(53) = {  0.0     , 215*mm  , hautole  ,  lc/3 };
Point(54) = { largpba  , longpba , hautole  ,  lc };
Point(55) = {  0.0     , longpba , hautole  ,  lc };

Line(43) = {6,51};
Line(44) = {7,54};
Line(45) = {8,55};
Line(56) = {50,51};
Line(57) = {51,52};
Line(58) = {52,53};
Line(59) = {53,50};
Line(60) = {52,54};
Line(61) = {53,55};
Line(62) = {54,55};
Line(63) = {50,32};
Line(64) = {51,33};
Line(65) = {54,34};
Line(66) = {55,35};


Line Loop(67) = {56,57,58,59};
Plane Surface(68) = {67};
Line Loop(69) = {-58,60,62,-61};
Plane Surface(70) = {69};Line Loop(71) = {64,-37,-63,56};
Plane Surface(72) = {71};
Line Loop(73) = {-65,-60,-57,64,38};
Plane Surface(74) = {73};
Line Loop(75) = {66,-39,-65,62};
Plane Surface(76) = {75};
Line Loop(77) = {66,40,-63,-59,61};
Plane Surface(78) = {77};
Surface Loop(79) = {42,78,76,74,70,68,72};
Volume(80) = {79};

Line Loop(80) = {44,-60,-57,-43,14};
Plane Surface(81) = {80};
Line Loop(82) = {-45,-15,44,62};
Plane Surface(83) = {82};



//
//Spheres_infini 
//
Point(100) = {  rint  ,  0.0   ,  tranZ      , lcrint1 };
Point(101) = {  rext  ,  0.0   ,  tranZ     , lcrext1 };
Point(102) = {  0.0   ,  rint  ,  tranZ   , lcrint1 };
Point(103) = {  0.0   ,  rext  ,  tranZ   , lcrext1 };
Point(104) = {  0.0   ,  0.0   ,  rext+tranZ    , lcrext1 };
Point(105) = {  0.0   ,  0.0   ,  rint+tranZ     , lcrint1 };
Point(106) = {  0.0   ,  0.0   ,  -rint+tranZ    , lcrint2 };
Point(107) = {  0.0   ,  0.0   ,  -rext+tranZ    , lcrext2 };

Line(108)={1,106};
Line(109)={106,107};
Line(110)={32,105};
Line(111)={105,104};

Circle(112) = {100, centre,105};
Circle(113) = {101, centre,104};
Circle(114) = {102, centre,105};
Circle(115) = {103, centre,104};
Circle(116) = {100, centre,106};
Circle(117) = {101, centre,107};
Circle(118) = {102, centre,106};
Circle(119) = {103, centre,107};
Circle(120) = {100, centre,102};
Circle(121) = {101, centre,103};

Line Loop(122) = {-112,120,114};
Ruled Surface(123) = {122};
Line Loop(124) = {-113,121,115};
Ruled Surface(125) = {124};
Line Loop(126) = {118,-116,120};
Ruled Surface(127) = {126};
Line Loop(128) = {-119,-121,117};
Ruled Surface(129) = {128};

Line Loop(130) = {-112,116,-108,9,18,43,64,-37,110};
Plane Surface(131) = {130};
Line Loop(132) = {109,-117,113,-111,-112,116};
Plane Surface(133) = {132};
Line Loop(134) = {-114,118,-108,-12,20,45,66,40,110};
Plane Surface(135) = {134};
Line Loop(136) = {109,-119,115,-111,-114,118};
Plane Surface(137) = {136};

Surface Loop(138) = {74,76,135,123,131,127,22,26,81,83,28,42};
Volume(139) = {138};
Surface Loop(139) = {123,133,137,129,125,127};
Volume(140) = {139};


// la partie suivante definit les caracteristiques des differents aimants (longueur, largeur, hauteur, espacement, ancrage, angle de rotation)

nbx = 5;                  //nbre d'aimant sur l' axe x
nby = 5;                  //nbre d'aimant sur l' axe y
totsym = nbx+nby;
nbc = 32;                 //nbre d'aimant centraux
totaim = totsym+nbc;


longaim[]= {20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,40*mm,40*mm,40*mm,40*mm,10*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,10*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,10*mm,40*mm,40*mm,40*mm,40*mm,40*mm,40*mm,190*mm,190*mm,190*mm,190*mm,190*mm};     // liste des longueurs des aimants
largaim[]= {7.5*mm,15*mm,15*mm,15*mm,15*mm,15*mm,7.5*mm,7.5*mm,7.5*mm,7.5*mm,7.5*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,15*mm,10*mm,10*mm,10*mm,10*mm,10*mm}; // liste des largeurs des aimants
hautaim[]= {20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm,20*mm};     // liste des hauteurs des aimants
xancaim[]= {0*mm,37.5*mm,82.5*mm,127.5*mm,172.5*mm,217.5*mm,0*mm,0*mm,0*mm,0*mm,0*mm,37.5*mm,37.5*mm,37.5*mm,37.5*mm,38*mm,82.5*mm,82.5*mm,82.5*mm,82.5*mm,82.5*mm,127.5*mm,127.5*mm,127.5*mm,127.5*mm,128*mm,46.3*mm,172.5*mm,172.5*mm,172.5*mm,172.5*mm,172.5*mm,217.5*mm,217.5*mm,217.5*mm,217.5*mm,218*mm,136.3*mm,197.5*mm,152.5*mm,107.5*mm,62.5*mm,17.5*mm}; // liste des xBox des aimants
espaaim[]= {0*mm,0*mm,0*mm,0*mm,0*mm,0*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,2.5*mm,0*mm,0*mm,0*mm,0*mm,0*mm}; // liste des espaces entre aimants

For i In {0:totaim}  //boucle pour creer la coord y du point d'ancrage des aimants
  If (i>=0 && i<=nbx)
  yancaim[i]= 0*mm;EndIf
  If (i==nbx+1)
  yancaim[i]= espaaim[i]+longaim[0];EndIf
  If (i>nbx+1 && i<=totsym)
  yancaim[i]= espaaim[i]+yancaim[i-1]+longaim[i-1];EndIf
  If (i==totsym+1)
  yancaim[i]=espaaim[i]+longaim[1];EndIf
  If (i>totsym+1 && i<=15)
  yancaim[i]= espaaim[i]+yancaim[i-1]+longaim[i-1];EndIf
  If (i==16)
  yancaim[i]=espaaim[i]+longaim[2];EndIf
  If (i>16 && i<=20)
  yancaim[i]= espaaim[i]+yancaim[i-1]+longaim[i-1];EndIf
  If (i==21)
  yancaim[i]=espaaim[i]+longaim[3];EndIf
  If (i>21 && i<=25)
  yancaim[i]= espaaim[i]+yancaim[i-1]+longaim[i-1];EndIf
  If (i==26)
  yancaim[i]= 206.36*mm;EndIf
  If (i==27)
  yancaim[i]=espaaim[i]+longaim[4];EndIf
  If (i>27 && i<=31)
  yancaim[i]= espaaim[i]+yancaim[i-1]+longaim[i-1];EndIf
  If (i==32)
  yancaim[i]=espaaim[i]+longaim[5];EndIf
  If (i>32 && i<=36)
  yancaim[i]= espaaim[i]+yancaim[i-1]+longaim[i-1];EndIf
  If (i==37)
  yancaim[i]= 206.36*mm;EndIf
  If (i==38)
  yancaim[i]= 5*mm;EndIf
  If (i==39)
  yancaim[i]= 5*mm;EndIf
  If (i==40)
  yancaim[i]= 5*mm;EndIf
  If (i==41)
  yancaim[i]= 5*mm;EndIf
  If (i==42)
  yancaim[i]= 5*mm;EndIf
EndFor  
anglerot[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,0,0,63,-63,0,0,0,0,0,0,0,0,0,63,-63,0,0,0,0,0};//liste des angles de rotation des aimants

// Introduction des aimants
For i In {0:totaim}
  iBox=i; wBox=largaim[i]; lBox=longaim[i]; hBox=hautaim[i]; 
  xBox=xancaim[i]; 
  yBox=yancaim[i]; zBox= eppba ; lcBox=lc; thetaBox= anglerot[i];
  Include "box-old.geo"; 
EndFor

Coherence;

For tx In {1:nbx} // creation des lignes manquantes sur l'axe x
  divline = newreg;
  Line(divline) = {Boxes_Point2[tx-1],Boxes_Point1[tx]};
  Boxes_divx[tx-1]=divline;
EndFor

divline = newreg;// creation des lignes manquantes sur l'axe y
Line(divline) = {Boxes_Point4[0],Boxes_Point1[nbx+1]};
Boxes_divy[0]=divline;
Boxes_divyN[0]=-divline;

For i In {1:(nby-1)}
  divline = newreg;
  Line(divline) = {Boxes_Point4[i+nbx],Boxes_Point1[i+nbx+1]};
  Boxes_divy[i]=divline;
  Boxes_divyN[i]=-divline;
EndFor

derx = newreg;
Line(derx)= {Boxes_Point2[nbx],6};
axex[]={Boxes_divx[],derx};

maille = newreg;
Point(maille)={    0.0   ,  250*mm ,    eppba      ,  lcpba1  };
dery1= newreg;
Line(dery1)={maille,8};

dery = newreg;
Line(dery)= {Boxes_Point4[totsym],maille};
axey[]={Boxes_divy[],dery,dery1};
axeyN[]={Boxes_divyN[],-dery,-dery1};
axez = newreg;
Line(axez)={Boxes_Point5[0],50};

//il manque 5 surface

surfxpb = newreg;
Line Loop(surfxpb)= {Boxes_Linep1p2[{0:nbx}],axex[],-18,-9,17};
Plane Surface(surfxpb+1)= {surfxpb};

surfypb = newreg;
Line Loop(surfypb)= {Boxes_Linep4p1[0],Boxes_Linep4p1[{(nbx+1):(totsym)}],axey[],-20,12,17};
Plane Surface(surfypb+1)= {surfypb};

surfxair = newreg;
Line Loop(surfxair)= {Boxes_Linep5p6[{0:nbx}],Boxes_Linep2p6[{0:nbx}],Boxes_Linep1p5[{1:nbx}],axex[],43,-56,-axez};
Plane Surface(surfxair+1)= {surfxair};

surfyair = newreg;
Line Loop(surfyair)= {Boxes_Linep8p5[0],Boxes_Linep4p8[0],Boxes_Linep4p8[{(nbx+1):(totsym)}],Boxes_Linep8p5[{(nbx+1):(totsym)}],axey[],Boxes_Linep1p5[{(nbx+1):(totsym)}],45,-61,59,-axez};
Plane Surface(surfyair+1)= {surfyair};


surfbase = newreg;
Line Loop(surfbase)= {axex[],Boxes_Linep3p4[{0:totsym}],Boxes_Linep2p3[{0:totsym}],Boxes_Linep4p1[{1:nbx}],Boxes_Linep2p1[{(nbx+1):(totsym)}],14,15,axeyN[]};
Plane Surface(surfbase+1)= {surfbase,Boxes_LineLoop1[{totsym+1:totaim}]};

// il manque 2 volume

volpb = newreg;
Surface Loop(volpb)={surfxpb+1,26,28,22,surfypb+1,surfbase+1,Boxes_PlanSurf1[]};
Volume(volpb+1)= {volpb};

volair = newreg;
Surface Loop(volair)={surfxair+1,surfyair+1,surfbase+1,68,70,81,83,Boxes_PlanSurf2[],Boxes_PlanSurf6[],Boxes_PlanSurf5[],Boxes_PlanSurf3[{1:nbx}],Boxes_PlanSurf3[{(totsym+1):totaim}],Boxes_PlanSurf4[{(nbx+1):(totaim)}]};
Volume(volair+1)={volair};

// definition des entites physiques

Physical Volume(9999)={volpb+1,Boxes_Volume[10],Boxes_Volume[20],Boxes_Volume[31],Boxes_Volume[{totaim-4:totaim}]};
Physical Volume(9998)={volair+1,80};
Physical Volume(9997)={139};
Physical Volume(9996)={140};

//config2Physical Volume(8888)={Boxes_Volume[0],Boxes_Volume[2],Boxes_Volume[{nbx+1:totsym}],Boxes_Volume[{14:16}]};
//config2Physical Volume(8887)={Boxes_Volume[1],Boxes_Volume[3],Boxes_Volume[{9:13}],Boxes_Volume[{17:22}]};
Physical Volume(8888)={Boxes_Volume[0],Boxes_Volume[2],Boxes_Volume[4],Boxes_Volume[{nbx+1:totsym-1}],Boxes_Volume[{16:19}],Boxes_Volume[{27:30}]};
Physical Volume(8887)={Boxes_Volume[1],Boxes_Volume[3],Boxes_Volume[5],Boxes_Volume[{11:15}],Boxes_Volume[{21:26}],Boxes_Volume[{32:37}]};

Physical Surface(7776)={125,129};
Physical Surface(7777)={Boxes_PlanSurf4[{0:nbx}],surfxpb+1,surfxair+1,72,131,133,Boxes_PlanSurf3[0],Boxes_PlanSurf3[{nbx+1:totsym}],surfypb+1,surfyair+1,135,137,78};


Physical Surface(6666)={68};

