mm = 0.001 ; // 1 milimetre = 0.001 metre
lc = 2.1*mm ; // unite de base min pour la taille caracteristique du maillage

lcpba2  =  1.5*lc ;        // lc dessous plaque base 
lcpba1  =  lc ;          // lc dessus  plaque base
lcrint1 =  3*lc ;        // lc coquille spherique superieure
lcrint2 =  3*lc ;        // lc coquille spherique inferieure
lcrext1 =  2.9*lcrint1 ;   // lc coquille spherique infini superieure
lcrext2 =  2.9*lcrint2 ;   // lc coquille spherique infini inferieure

// definition de longueur de la plaque base

eppba1    = 7.7 *mm ;        // epaisseur plaque base 1
eppba2    = 6.8 *mm ;        // epaisseur plaque base 2
eppba3    = 3.5 *mm ;        // epaisseur plaque base 3
Raypba  = 88/2 *mm ;     // longueur plaque base 
Raypba1 = 35.5*mm ;
Raypba2 = 25.5*mm;
Raypba3 = 12.5*mm;

// Definition de la plaque base

Point(1)   = {  Raypba  , 0.0 ,   0.0  , lcpba2  };  
Point(2)   = {  Raypba  , 0.0 , eppba2 , lcpba2  };
Point(3)   = {  Raypba1 , 0.0 , eppba2 , lcpba2  };
Point(4)   = {  Raypba1 , 0.0 , eppba1 , lcpba1  };  
Point(5)   = {  Raypba2 , 0.0 , eppba1 , lcpba1  };
Point(6)   = {  Raypba2 , 0.0 , eppba3 , lcpba1  };
//Point(7)   = {  Raypba3 , 0.0 , eppba3 , lcpba1  };
//Point(8)   = {  Raypba3 , 0.0 , eppba1 ,  lcpba1 };

Point(9)   = { 0.0 , Raypba ,   0.0  , lcpba2  };  
Point(10)   = { 0.0 , Raypba  , eppba2 , lcpba2  };
Point(11)   = { 0.0 , Raypba1 , eppba2 , lcpba2  };
Point(12)   = { 0.0 , Raypba1 , eppba1 , lcpba1  };  
Point(13)   = { 0.0 , Raypba2 , eppba1 , lcpba1  };
Point(14)   = { 0.0 , Raypba2 , eppba3 , lcpba1  };
//Point(15)   = { 0.0 , Raypba3 , eppba3 , lcpba1  };
//Point(16)   = { 0.0 , Raypba3 , eppba1 ,  lcpba1 };

Point(17)   = {  -Raypba  , 0.0 ,   0.0  , lcpba2  };  
Point(18)   = {  -Raypba  , 0.0 , eppba2 , lcpba2  };
Point(19)   = {  -Raypba1 , 0.0 , eppba2 , lcpba2  };
Point(20)   = {  -Raypba1 , 0.0 , eppba1 , lcpba1  };  
Point(21)   = {  -Raypba2 , 0.0 , eppba1 , lcpba1  };
Point(22)   = {  -Raypba2 , 0.0 , eppba3 , lcpba1  };
//Point(23)   = {  -Raypba3 , 0.0 , eppba3 , lcpba1  };
//Point(24)   = {  -Raypba3 , 0.0 , eppba1 ,  lcpba1 };

Point(25)   = { 0.0 , -Raypba ,   0.0  , lcpba2  };  
Point(26)   = { 0.0 , -Raypba  , eppba2 , lcpba2  };
Point(27)   = { 0.0 , -Raypba1 , eppba2 , lcpba2  };
Point(28)   = { 0.0 , -Raypba1 , eppba1 , lcpba1  };  
Point(29)   = { 0.0 , -Raypba2 , eppba1 , lcpba1  };
Point(30)   = { 0.0 , -Raypba2 , eppba3 , lcpba1  };
//Point(31)   = { 0.0 , -Raypba3 , eppba3 , lcpba1  };
//Point(32)   = { 0.0 , -Raypba3 , eppba1 ,  lcpba1 };

centre1=newp;Point(centre1)= { 0.0,    0.0   ,    0.0      ,  lcpba2  }; 
centre2=newp;Point(centre2)= { 0.0,    0.0   ,   eppba2       ,  lcpba2  }; 
centre3=newp;Point(centre3)= { 0.0,    0.0   ,   eppba1      ,  lcpba2  }; 
centre4=newp;Point(centre4)= { 0.0,    0.0   ,   eppba3      ,  lcpba2  }; 

Circle(40) = {1,centre1,9};
Circle(41) = {2,centre2,10};
Circle(42) = {3,centre2,11};
Circle(43) = {4,centre3,12};
Circle(44) = {5,centre3,13};
Circle(45) = {6,centre4,14};
//Circle(46) = {7,centre4,15};
//Circle(47) = {8,centre3,16};

Circle(48) = {9,centre1,17};
Circle(49) = {10,centre2,18};
Circle(50) = {11,centre2,19};
Circle(51) = {12,centre3,20};
Circle(52) = {13,centre3,21};
Circle(53) = {14,centre4,22};
//Circle(54) = {15,centre4,23};
//Circle(55) = {16,centre3,24};

Circle(56) = {17,centre1,25};
Circle(57) = {18,centre2,26};
Circle(58) = {19,centre2,27};
Circle(59) = {20,centre3,28};
Circle(60) = {21,centre3,29};
Circle(61) = {22,centre4,30};
//Circle(62) = {23,centre4,31};
//Circle(63) = {24,centre3,32};

Circle(64) = {25,centre1,1};
Circle(65) = {26,centre2,2};
Circle(66) = {27,centre2,3};
Circle(67) = {28,centre3,4};
Circle(68) = {29,centre3,5};
Circle(69) = {30,centre4,6};
//Circle(70) = {31,centre4,7};
//Circle(71) = {32,centre3,8};

Line(72)={1,2};
Line(73)={3,4};
Line(74)={5,6};
//Line(75)={7,8};
Line(76)={17,18};
Line(77)={19,20};
Line(78)={21,22};
//Line(79)={23,24};
Line(80)={9,10};
Line(81)={11,12};
Line(82)={13,14};
//Line(83)={15,16};
Line(84)={25,26};
Line(85)={27,28};
Line(86)={29,30};
//Line(87)={31,32};

iCyl=0; dCyl=12.5*mm; hCyl=8*mm; 
xCyl=0; yCyl=0; zCyl= eppba1 ; lcCyl=lc;
Include "cylindric.geo";
Coherence;

nbtra=6;
nbtot=24;
thethatra[]={0,90,150,210,270,330,30,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,0};
pcen = centre3; 
pcen2= centre4;
difBox=eppba1-eppba3;
For i In {1:nbtot}
 If (i<=nbtra) 
   iBox=i; h1Box=7.5*mm;h2Box=16.5*mm; epBox=8*mm;RBox=Raypba3; 
   xBox=0; yBox=0; zBox=eppba1 ; lcBox=3*mm;thetaBox=thethatra[i];
   Include "traphedre1.geo";
 EndIf
 If (i>nbtra) 
   iBox=i; h1Box=36.5*mm;wBox=6*mm;lBox=12*mm; hBox=9*mm; 
   xBox=0; yBox=0; zBox=eppba2 ; lcBox=3*mm;thetaBox=thethatra[i];
   Include "box.geo";
 EndIf
EndFor

//12 arc de cercle manquant
arc1=newreg; Circle(arc1)={Boxes_Point5[1],centre3,Boxes_Point2[2]};
arc2=newreg; Circle(arc2)={Boxes_Point5[2],centre3,Boxes_Point2[3]};
arc3=newreg; Circle(arc3)={Boxes_Point5[3],centre3,Boxes_Point2[4]};
arc4=newreg; Circle(arc4)={Boxes_Point5[4],centre3,Boxes_Point2[5]};
arc5=newreg; Circle(arc5)={Boxes_Point5[5],centre3,Boxes_Point2[6]};
arc6=newreg; Circle(arc6)={Boxes_Point5[6],centre3,Boxes_Point2[1]};
arc7=newreg; Circle(arc7)={Boxes_Point12[1],centre4,Boxes_Point11[2]};
arc8=newreg; Circle(arc8)={Boxes_Point12[2],centre4,Boxes_Point11[3]};
arc9=newreg; Circle(arc9)={Boxes_Point12[3],centre4,Boxes_Point11[4]};
arc10=newreg; Circle(arc10)={Boxes_Point12[4],centre4,Boxes_Point11[5]};
arc11=newreg; Circle(arc11)={Boxes_Point12[5],centre4,Boxes_Point11[6]};
arc12=newreg; Circle(arc12)={Boxes_Point12[6],centre4,Boxes_Point11[1]};


surfpbc1=newreg;
Line Loop(surfpbc1)={40,64,56,48};
Plane Surface(surfpbc1+1)={surfpbc1};
surfpbc2=newreg;
Line Loop(surfpbc2)={72,41,-80,-40};
Ruled Surface(surfpbc2+1)={surfpbc2};
surfpbc3=newreg;
Line Loop(surfpbc3)={80,49,-76,-48};
Ruled Surface(surfpbc3+1)={surfpbc3};
surfpbc4=newreg;
Line Loop(surfpbc4)={76,57,-84,-56};
Ruled Surface(surfpbc4+1)={surfpbc4};
surfpbc5=newreg;
Line Loop(surfpbc5)={84,65,-72,-64};
Ruled Surface(surfpbc5+1)={surfpbc5};
surfpbc6=newreg;
Line Loop(surfpbc6)={41,49,57,65};
surfpbc7=newreg;
Line Loop(surfpbc7)={42,50,58,66};
Plane Surface(surfpbc7+1)={surfpbc6,surfpbc7,Boxes_LineLoop1[{7:24}]};
surfpbc8=newreg;
Line Loop(surfpbc8)={73,43,-81,-42};
Ruled Surface(surfpbc8+1)={surfpbc8};
surfpbc9=newreg;
Line Loop(surfpbc9)={81,51,-77,-50};
Ruled Surface(surfpbc9+1)={surfpbc9};
surfpbc10=newreg;
Line Loop(surfpbc10)={77,59,-85,-58};
Ruled Surface(surfpbc10+1)={surfpbc10};
surfpbc11=newreg;
Line Loop(surfpbc11)={85,67,-73,-66};
Ruled Surface(surfpbc11+1)={surfpbc11};
surfpbc12=newreg;
Line Loop(surfpbc12)={43,51,59,67};
surfpbc13=newreg;
Line Loop(surfpbc13)={44,52,60,68};
Plane Surface(surfpbc13+1)={surfpbc12,surfpbc13};
surfpbc14=newreg;
Line Loop(surfpbc14)={-74,44,82,-45};
Ruled Surface(surfpbc14+1)={surfpbc14};
surfpbc15=newreg;
Line Loop(surfpbc15)={-82,52,78,-53};
Ruled Surface(surfpbc15+1)={surfpbc15};
surfpbc16=newreg;
Line Loop(surfpbc16)={-78,60,86,-61};
Ruled Surface(surfpbc16+1)={surfpbc16};
surfpbc17=newreg;
Line Loop(surfpbc17)={-86,68,74,-69};
Ruled Surface(surfpbc17+1)={surfpbc17};
surfpbc18=newreg;
Line Loop(surfpbc18)={45,53,61,69};
surfpbc19=newreg;
Line Loop(surfpbc19)={Boxes_Linep11p12[{1:6}],arc7,arc8,arc9,arc10,arc11,arc12};
Plane Surface(surfpbc19+1)={surfpbc18,surfpbc19};

surfpbc20=newreg;
Line Loop(surfpbc20)={arc1,Boxes_Linep2p11[2],-arc7,-Boxes_Linep5p12[1]};
Ruled Surface(surfpbc20+1)={surfpbc20};
surfpbc21=newreg;
Line Loop(surfpbc21)={arc2,Boxes_Linep2p11[3],-arc8,-Boxes_Linep5p12[2]};
Ruled Surface(surfpbc21+1)={surfpbc21};
surfpbc22=newreg;
Line Loop(surfpbc22)={arc3,Boxes_Linep2p11[4],-arc9,-Boxes_Linep5p12[3]};
Ruled Surface(surfpbc22+1)={surfpbc22};
surfpbc23=newreg;
Line Loop(surfpbc23)={arc4,Boxes_Linep2p11[5],-arc10,-Boxes_Linep5p12[4]};
Ruled Surface(surfpbc23+1)={surfpbc23};
surfpbc24=newreg;
Line Loop(surfpbc24)={arc5,Boxes_Linep2p11[6],-arc11,-Boxes_Linep5p12[5]};
Ruled Surface(surfpbc24+1)={surfpbc24};
surfpbc25=newreg;
Line Loop(surfpbc25)={arc6,Boxes_Linep2p11[1],-arc12,-Boxes_Linep5p12[6]};
Ruled Surface(surfpbc25+1)={surfpbc25};
surfpbc26=newreg;
Line Loop(surfpbc26)={arc1,-Boxes_Linep1p2[2],-Boxes_Linep6p1[2],-Boxes_Linep5p6[2],arc2,-Boxes_Linep1p2[3],-Boxes_Linep6p1[3],-Boxes_Linep5p6[3],arc3,-Boxes_Linep1p2[4],-Boxes_Linep6p1[4],-Boxes_Linep5p6[4],arc4,-Boxes_Linep1p2[5],-Boxes_Linep6p1[5],-Boxes_Linep5p6[5],arc5,-Boxes_Linep1p2[6],-Boxes_Linep6p1[6],-Boxes_Linep5p6[6],arc6,-Boxes_Linep1p2[1],-Boxes_Linep6p1[1],-Boxes_Linep5p6[1]};
Plane Surface(surfpbc26+1)={surfpbc26,Cyles_BaseLoop[0]};

volpbc = newreg;
Surface Loop(volpbc)={surfpbc1+1,surfpbc2+1,surfpbc3+1,surfpbc4+1,surfpbc5+1,surfpbc7+1,surfpbc8+1,surfpbc9+1,surfpbc10+1,surfpbc11+1,surfpbc13+1,surfpbc14+1,surfpbc15+1,surfpbc16+1,surfpbc17+1,surfpbc19+1,surfpbc20+1,surfpbc21+1,surfpbc22+1,surfpbc23+1,surfpbc24+1,surfpbc25+1,surfpbc26+1,Boxes_PlanSurf1[{1:24}],Boxes_PlanSurf8[{1:6}],Cyles_BaseSurf[0]};
Volume(volpbc+1)={volpbc};


Physical Surface(7776)={surfpbc1+1,surfpbc2+1,surfpbc3+1,surfpbc4+1,surfpbc5+1,surfpbc7+1,surfpbc8+1,surfpbc9+1,surfpbc10+1,surfpbc11+1,surfpbc13+1,surfpbc14+1,surfpbc15+1,surfpbc16+1,surfpbc17+1,surfpbc19+1,surfpbc20+1,surfpbc21+1,surfpbc22+1,surfpbc23+1,surfpbc24+1,surfpbc25+1,surfpbc26+1,Boxes_PlanSurf8[{1:6}]};


Physical Surface(7777)={Cyles_BaseSurf[0],Cyles_HautSurf[0],Cyles_RuleSurf1[0],Cyles_RuleSurf2[0],Cyles_RuleSurf3[0],Cyles_RuleSurf4[0]};

Physical Surface(7778)={Boxes_PlanSurf1[{1:6}],Boxes_PlanSurf2[{1:6}],Boxes_PlanSurf3[{1:6}],Boxes_PlanSurf4[{1:6}],Boxes_PlanSurf5[{1:6}],Boxes_PlanSurf6[{1:6}],Boxes_PlanSurf7[{1:6}]};
Physical Surface(7779)={Boxes_PlanSurf1[{7:24}],Boxes_PlanSurf2[{7:24}],Boxes_PlanSurf3[{7:24}],Boxes_PlanSurf4[{7:24}],Boxes_PlanSurf5[{7:24}],Boxes_PlanSurf6[{7:24}]};









