mm = 0.001 ; // 1 milimetre = 0.001 metre
lc = 2.2*mm ; // unite de base min pour la taille caracteristique du maillage

lcpba   =   lc ;        // lc plaques base centrale et laterale 
lcrint1 =  2.6*lc ;        // lc coquille spherique superieure
lcrext1 =  2.9*lcrint1 ;   // lc coquille spherique infini superieure

// Definition de la plaque base centrale

r1pbc = 3*mm;
r2pbc = 5*mm;
r3pbc = 19.75*mm;
r4pbc = 18*mm;
e1pbc = 2*mm;
e2pbc = 4*mm;
e3pbc = 6*mm;

Point(1)   = { r1pbc ,    0.0   ,    0.0      ,  lcpba  };  
Point(2)   = { r2pbc ,    0.0   ,    0.0      ,  lcpba  };
Point(3)   = { r2pbc ,    0.0   ,   e1pbc     ,  lcpba  };
Point(4)   = { r3pbc ,    0.0   ,   e1pbc     ,  lcpba  };
Point(5)   = { r3pbc ,    0.0   ,   e2pbc      ,  lcpba  };  
Point(6)   = { r4pbc ,    0.0   ,   e2pbc      ,  lcpba  }; 
Point(7)   = { r4pbc ,    0.0   ,   e3pbc      ,  lcpba  }; 
Point(8)   = { r1pbc ,    0.0   ,   e3pbc      ,  lcpba  }; 

Point(9)   = { 0.0  ,     r1pbc   ,    0.0      ,  lcpba  };  
Point(10)   = { 0.0  ,    r2pbc   ,    0.0      ,  lcpba  };
Point(11)   = { 0.0  ,    r2pbc   ,   e1pbc     ,  lcpba  };
Point(12)   = { 0.0  ,    r3pbc   ,   e1pbc     ,  lcpba  };
Point(13)   = { 0.0  ,    r3pbc   ,   e2pbc      ,  lcpba  };  
Point(14)   = { 0.0  ,    r4pbc   ,   e2pbc      ,  lcpba  }; 
Point(15)   = { 0.0  ,    r4pbc   ,   e3pbc      ,  lcpba  }; 
Point(16)   = { 0.0  ,    r1pbc   ,   e3pbc      ,  lcpba  }; 


Line(20) = {1,2};
Line(21) = {2,3};
//Line(22) = {3,4};
Line(23) = {4,5};
Line(24) = {5,6};
Line(25) = {6,7};
Line(26) = {7,8};
Line(27) = {8,1};

Line(28) = {9,10};
Line(29) = {10,11};
Line(30) = {11,12};
Line(31) = {12,13};
Line(32) = {13,14};
Line(33) = {14,15};
Line(34) = {15,16};
Line(35) = {16,9};

centre1=newp;Point(centre1)= { 0.0,    0.0   ,    0.0      ,  lcpba  }; 
centre2=newp;Point(centre2)= { 0.0,    0.0   ,    e1pbc      ,  lcpba  }; 
centre3=newp;Point(centre3)= { 0.0,    0.0   ,    e2pbc      ,  lcpba  }; 
centre4=newp;Point(centre4)= { 0.0,    0.0   ,    e3pbc      ,  lcpba  }; 

Circle(40) = {1,centre1,9};
Circle(41) = {2,centre1,10};
Circle(42) = {3,centre2,11};
Circle(43) = {4,centre2,12};
Circle(44) = {5,centre3,13};
Circle(45) = {6,centre3,14};
Circle(46) = {7,centre4,15};
Circle(47) = {8,centre4,16};

// Definition de la plaque base laterale

r1pbl = 60*mm;
r2pbl = 74*mm;

Point(51)   = { r1pbl ,    0.0   ,   e1pbc      ,  lcpba  };  
Point(52)   = { r2pbl ,    0.0   ,   e1pbc      ,  lcpba  };
Point(53)   = { r2pbl ,    0.0   ,   e3pbc     ,  lcpba  };
Point(54)   = { r1pbl ,    0.0   ,   e3pbc     ,  lcpba  };

Point(55)   = { 0.0 ,    r1pbl   ,   e1pbc      ,  lcpba  };  
Point(56)   = { 0.0 ,    r2pbl   ,   e1pbc      ,  lcpba  };
Point(57)   = { 0.0 ,    r2pbl   ,   e3pbc     ,  lcpba  };
Point(58)   = { 0.0 ,    r1pbl   ,   e3pbc     ,  lcpba  };

//Line(60) = {51,52};
Line(61) = {52,53};
Line(62) = {53,54};
Line(63) = {54,51};
Line(64) = {55,56};
Line(65) = {56,57};
Line(66) = {57,58};
Line(67) = {58,55};

Circle(70) = {51,centre2,55};
Circle(71) = {52,centre2,56};
Circle(72) = {53,centre4,57};
Circle(73) = {54,centre4,58};

//introduction aimants

iFom=1;LFom=10.5*mm; lcFom=lc ;L1Fom=7*mm;
h1Fom=13*mm;R1Fom=26*mm;R2Fom=35*mm;angle=30*Pi/180;
xFom=39*mm;yFom=0;zFom=15*mm;
Include "forme2.geo";
Coherence;

iFom=2;LFom=21*mm; lcFom=lc ;L1Fom=7*mm;
h1Fom=13*mm;R1Fom=26*mm;R2Fom=35*mm;angle=30*Pi/180;theta=61;
xFom=39.2*mm;yFom=-10*mm;zFom=15*mm;
Include "forme1-old.geo";
Coherence;

//definition du volume de la plaque base centrale
//premiere etape ligne manquante (1)

axex1=newreg;
Line(axex1)={3,Fomes_Point12[1]} ;
axex2=newreg;
Line(axex2)={Fomes_Point11[1],4} ;

//deuxieme etape definir surface (10)

surfpbc1=newreg;
Line Loop(surfpbc1)={20,21,axex1,-Fomes_Linep11p12[1],axex2,23,24,25,26,27};
Plane Surface(surfpbc1+1)={surfpbc1};
surfpbc2=newreg;
Line Loop(surfpbc2)={28,29,30,31,32,33,34,35};
Plane Surface(surfpbc2+1)={surfpbc2};
surfpbc3=newreg;
Line Loop(surfpbc3)={27,40,-35,-47};
Ruled Surface(surfpbc3+1)={surfpbc3};
surfpbc4=newreg;
Line Loop(surfpbc4)={20,41,-28,-40};
Ruled Surface(surfpbc4+1)={surfpbc4};
surfpbc5=newreg;
Line Loop(surfpbc5)={21,42,-29,-41};
Ruled Surface(surfpbc5+1)={surfpbc5};
surfpbc6=newreg;
Line Loop(surfpbc6)={axex1,Fomes_Linep12p13[1],Fomes_Linep13p14[1],Fomes_Linep14p11[1],axex2,43,-30,-42};
Plane Surface(surfpbc6+1)={surfpbc6,Fomes_LineLoop5[2]};
surfpbc7=newreg;
Line Loop(surfpbc7)={23,44,-31,-43};
Ruled Surface(surfpbc7+1)={surfpbc7};
surfpbc8=newreg;
Line Loop(surfpbc8)={24,45,-32,-44};
Ruled Surface(surfpbc8+1)={surfpbc8};
surfpbc9=newreg;
Line Loop(surfpbc9)={25,46,-33,-45};
Ruled Surface(surfpbc9+1)={surfpbc9};
surfpbc10=newreg;
Line Loop(surfpbc10)={26,47,-34,-46};
Ruled Surface(surfpbc10+1)={surfpbc10};
volpbc=newreg;
Surface Loop(volpbc)={surfpbc1+1,surfpbc2+1,surfpbc3+1,surfpbc4+1,surfpbc5+1,surfpbc6+1,surfpbc7+1,surfpbc8+1,surfpbc9+1,surfpbc10+1,Fomes_Surf5[{1:2}]};
Volume(volpbc+1)={volpbc};

//definition du volume de la plaque base laterale
//premiere etape ligne manquante (1)

axex3=newreg;
Line(axex3)={51,Fomes_Point5[1]} ;
axex4=newreg;
Line(axex4)={Fomes_Point4[1],52} ;
//deuxieme etape definir surface (6)

surfpbl1=newreg;
Line Loop(surfpbl1)={axex3,-Fomes_Linep4p5[1],axex4,61,62,63};
Plane Surface(surfpbl1+1)={surfpbl1};
surfpbl2=newreg;
Line Loop(surfpbl2)={64,65,66,67};
Ruled Surface(surfpbl2+1)={surfpbl2};
surfpbl3=newreg;
Line Loop(surfpbl3)={-63,73,67,-70};
Ruled Surface(surfpbl3+1)={surfpbl3};
surfpbl4=newreg;
Line Loop(surfpbl4)={70,64,-71,-axex4,Fomes_Linep4p9[1],Fomes_Linep9p10[1],-Fomes_Linep5p10[1],-axex3};
Plane Surface(surfpbl4+1)={surfpbl4,Fomes_LineLoop2[2]};
surfpbl5=newreg;
Line Loop(surfpbl5)={61,72,-65,-71};
Ruled Surface(surfpbl5+1)={surfpbl5};
surfpbl6=newreg;
Line Loop(surfpbl6)={62,73,-66,-72};
Ruled Surface(surfpbl6+1)={surfpbl6};
volpbl=newreg;
Surface Loop(volpbl)={surfpbl1+1,surfpbl2+1,surfpbl3+1,surfpbl4+1,surfpbl5+1,surfpbl6+1,Fomes_Surf2[{1:2}]};
Volume(volpbl+1)={volpbl};

//creation des points pour creer les sphere de transfo inf

rint     = 95. *mm ;       // rayon interne coquille spherique
rext     = 1.5 * rint ;     // rayon externe coquille spherique
 
tranZ=10*mm;
Point(350) = {  rint  ,  0.0   ,  tranZ      , lcrint1 };
Point(351) = {  rext  ,  0.0   ,  tranZ     , lcrext1 };
Point(352) = {  0.0   ,  rint  ,  tranZ   , lcrint1 };
Point(353) = {  0.0   ,  rext  ,  tranZ   , lcrext1 };
Point(354) = {  0.0   ,  0.0   ,  rext+tranZ    , lcrext1 };
Point(355) = {  0.0   ,  0.0   ,  rint+tranZ     , lcrint1 };
Point(356) = {  0.0   ,  0.0   ,  -rint+tranZ    , lcrint1 };
Point(357) = {  0.0   ,  0.0   ,  -rext+tranZ    , lcrext1 };

Line(358)={centre1,356};
Line(359)={356,357};
Line(360)={centre1,355};
Line(361)={355,354};

centre=newreg;
Point(centre) = {  0.0     ,    0.0   ,   tranZ      ,  lcpba  };
Circle(362) = {350, centre,355};
Circle(363) = {351, centre,354};
Circle(364) = {350, centre,356};
Circle(365) = {351, centre,357};
Circle(366) = {352, centre,355};
Circle(367) = {353, centre,354};
Circle(368) = {352, centre,356};
Circle(369) = {353, centre,357};
Circle(370) = {350, centre,352};
Circle(371) = {351, centre,353};

Line Loop(372) = {362,-366,-370};
Ruled Surface(373) = {372};
Line Loop(374) = {363,-367,-371};
Ruled Surface(375) = {374};
Line Loop(376) = {364,-368,-370};
Ruled Surface(377) = {376};
Line Loop(378) = {365,-369,-371};
Ruled Surface(379) = {378};
Line Loop(380) = {361,-363,365,-359,-364,362};
Plane Surface(381) = {380};
Line Loop(382) = {361,-367,369,-359,-368,366};
Plane Surface(383) = {382};

Surface Loop(384) = {373,375,377,379,381,383};
Volume(385) = {384};

//Surfaces et volume manquants air

surfair1 = newreg;
Line Loop(surfair1)= {358,-364,362,-360};
//definir lineloop axex
lineloo1 = newreg;
Line Loop(lineloo1)= {20,21,axex1,-Fomes_Linep3p12[1],Fomes_Linep3p4[1],axex4,61,62,63,axex3,Fomes_Linep5p2[1],Fomes_Linep2p11[1],axex2,23,24,25,26,27};
Plane Surface(surfair1+1)= {surfair1,lineloo1};
surfair2 = newreg;
Line Loop(surfair2)= {358,-368,366,-360};
Plane Surface(surfair2+1)= {surfair2,surfpbc2,surfpbl2};

surfcent[]={surfpbc3+1,surfpbc4+1,surfpbc5+1,surfpbc6+1,surfpbc7+1,surfpbc8+1,surfpbc9+1,surfpbc10+1};
surflat[]={surfpbl3+1,surfpbl4+1,surfpbl5+1,surfpbl6+1};
surfaim[]={Fomes_Surf1[{1:2}],Fomes_Surf4[{1:2}],Fomes_Surf6[{1:2}],Fomes_Surf7[{1:2}],Fomes_Surf8[{1:2}],Fomes_Surf9[2],Fomes_Surf10[2],Fomes_Surf11[{1:2}]};

volair = newreg;
Surface Loop(volair)={surfair1+1,surfair2+1,surfcent[],surflat[],surfaim[],373,377};
Volume(volair+1) ={volair};

// definition des entites physiques

Physical Volume(9999)={volpbc+1,volpbl+1};
Physical Volume(9998)={volair+1};
Physical Volume(9997)={385};

Physical Volume(8888)={Fomes_Volume[1]};
Physical Volume(8887)={Fomes_Volume[2]};


Physical Surface(7776)={375,379};
Physical Surface(7777)={surfair1+1,381,surfair2+1,383,surfpbc1+1,surfpbc2+1,surfpbl1+1,surfpbl2+1,Fomes_Surf9[1],Fomes_Surf10[1]};

/*

Point(900)   = {    0.0   ,    50*mm   ,    0.0      ,  lc  }; 
Point(901)   = {   50*mm   ,    0*mm   ,    0.0      ,  lc };  
Point(902)   = {    0.0   ,    30*mm   ,    0.0      ,  lc  }; 
Point(903)   = {   30*mm   ,    0*mm   ,    0.0      ,  lc  }; 

Point(904)   = {    0.0   ,    60*mm   ,    0.0      ,  lc }; 
Point(905)   = {   60*mm   ,    0*mm   ,    0.0      ,  lc  };   

Circle(906) = {900,centre1,901};
Circle(907) = {902,centre1,903};
Circle(908) = {904,centre1,905};

Printf("surf1 %g surf2 %g surf11 %g",surfpbl1+1,surfpbl2+1,surfpbl6+1);

For i In {93:113:2}
Symmetry { 1,0,0,0 } {
   Duplicata {Surface{i+2};}
}
EndFor

For i In {1:volpb+190}
Symmetry { 0,1,0,0 } {
   Duplicata {Surface{i};}
}
EndFor
*/
