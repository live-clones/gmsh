mm = 0.001 ; // 1 milimetre = 0.001 metre
lc = 1.5*mm ; // unite de base min pour la taille caracteristique du maillage

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
rint     = 90. *mm ;       // rayon interne coquille spherique
rext     = 1.5 * rint ;     // rayon externe coquille spherique
 
Point(1)   = {  Raypba  , 0.0 ,   0.0  , lcpba2  };  
Point(2)   = {  Raypba  , 0.0 , eppba2 , lcpba2  };
Point(3)   = {  Raypba1 , 0.0 , eppba2 , lcpba2  };
Point(4)   = {  Raypba1 , 0.0 , eppba1 , lcpba1  };  
Point(5)   = {  Raypba2 , 0.0 , eppba1 , lcpba1  };
Point(6)   = {  Raypba2 , 0.0 , eppba3 , lcpba1  };
Point(7)   = {  Raypba3 , 0.0 , eppba3 , lcpba1  };
Point(8)   = {  Raypba3 , 0.0 , eppba1 ,  lcpba1 };

Point(9)   = { 0.0 , Raypba ,   0.0  , lcpba2  };  
Point(10)   = { 0.0 , Raypba  , eppba2 , lcpba2  };
Point(11)   = { 0.0 , Raypba1 , eppba2 , lcpba2  };
Point(12)   = { 0.0 , Raypba1 , eppba1 , lcpba1  };  
Point(13)   = { 0.0 , Raypba2 , eppba1 , lcpba1  };
Point(14)   = { 0.0 , Raypba2 , eppba3 , lcpba1  };
//Point(15)   = { 0.0 , Raypba3 , eppba3 , lcpba1  };
//Point(16)   = { 0.0 , Raypba3 , eppba1 ,  lcpba1 };

centre1=newp;Point(centre1)= { 0.0,    0.0   ,    0.0      ,  lcpba2  }; 
centre2=newp;Point(centre2)= { 0.0,    0.0   ,   eppba2       ,  lcpba2  }; 
centre3=newp;Point(centre3)= { 0.0,    0.0   ,   eppba1      ,  lcpba2  }; 
centre4=newp;Point(centre4)= { 0.0,    0.0   ,   eppba3      ,  lcpba2  }; 
Circle(20) = {1,centre1,9};
Circle(21) = {2,centre2,10};
Circle(22) = {3,centre2,11};
Circle(23) = {4,centre3,12};
Circle(24) = {5,centre3,13};
Circle(25) = {6,centre4,14};
//Circle(26) = {7,centre4,15};
//Circle(27) = {8,centre3,16};

Line(28)={centre1,1};
Line(29)={1,2};
//Line(30)={2,3};
Line(31)={3,4};
Line(32)={4,5};
Line(33)={5,6};
Line(34)={6,7};
Line(35)={7,8};
//Line(36)={8,centre3};
Line(37)={centre3,centre1};

Line(38)={centre1,9};
Line(39)={9,10};
Line(40)={10,11};
Line(41)={11,12};
Line(42)={12,13};
Line(43)={13,14};
//Line(44)={14,15};
//Line(45)={15,16};
//Line(46)={16,centre3};

iCyl=0; dCyl=12.5*mm; hCyl=8*mm; 
xCyl=0; yCyl=0; zCyl= eppba1 ; lcCyl=lc;
Include "quacylin.geo";
Coherence;
nbtra=2;
nbtot=7;
thethatra[]={0,90,30,20,40,60,80,0};
pcen = centre3; 
pcen2= centre4;
difBox=eppba1-eppba3;

For i In {1:nbtot}
 If (i==1) 
   iBox=i; h1Box=7.5*mm;h2Box=16.5*mm; epBox=8*mm;RBox=Raypba3; 
   xBox=0; yBox=0; zBox=eppba1 ; lcBox=lc;thetaBox=thethatra[i];
   Include "traphedre2.geo";
 EndIf
   If (i==2) 
   iBox=i; h1Box=7.5*mm;h2Box=16.5*mm; epBox=8*mm;RBox=Raypba3; 
   xBox=0; yBox=0; zBox=eppba1 ; lcBox=lc;thetaBox=thethatra[i];
   Include "traphedre1.geo";
 EndIf
   If (i>nbtra && i<nbtot) 
   iBox=i; h1Box=36.5*mm;wBox=6*mm;lBox=12*mm; hBox=9*mm; 
   xBox=0; yBox=0; zBox=eppba2 ; lcBox=lc;thetaBox=thethatra[i];
   Include "box.geo";
 EndIf
  If (i==nbtot) 
   iBox=i; h1Box=36.5*mm;wBox=6*mm;lBox=6*mm; hBox=9*mm; 
   xBox=0; yBox=3*mm; zBox=eppba2 ; lcBox=lc;thetaBox=thethatra[i];
   Include "box.geo";
  EndIf
EndFor

//ligne et arc de cercle manquant
arc1=newreg; Circle(arc1)={8,centre3,Boxes_Point2[2]};
arc2=newreg; Circle(arc2)={Boxes_Point5[2],centre3,Boxes_Point2[1]};
arc3=newreg; Circle(arc3)={7,centre4,Boxes_Point11[2]};
arc4=newreg; Circle(arc4)={Boxes_Point12[2],centre4,Boxes_Point11[1]};
axex1=newreg;
Line(axex1) = {Cyles_Point2[0],8};
axex2=newreg;
Line(axex2) = {3,Boxes_Point1[7]};
axex3=newreg;
Line(axex3) = {Boxes_Point2[7],2};
axex[]={axex1,axex2,axex3};
axey1=newreg;
Line(axey1) = {Cyles_Point3[0],Boxes_Point6[1]};
axey2=newreg;
Line(axey2) = {Boxes_Point12[1],14};

// Surfaces manquantes
surfpbx=newreg;
Line Loop(surfpbx)={Cyles_Linep1p2[0],axex[],-35,-34,-33,-32,-31,Boxes_Linep1p2[7],-29,-28,-37};
Plane Surface(surfpbx+1) ={surfpbx};
surfpby=newreg;
Line Loop(surfpby)={Cyles_Linep1p3[0],axey1,-Boxes_Linep5p6[1], Boxes_Linep5p12[1],axey2,-43,-42,-41,-40,-39,-38,-37};
Plane Surface(surfpby+1) ={surfpby};
surfpb1=newreg;
Line Loop(surfpb1)={28,20,-38};
Plane Surface(surfpb1+1) ={surfpb1};
surfpb2=newreg;
Line Loop(surfpb2)={29,21,-39,-20};
Ruled Surface(surfpb2+1) ={surfpb2};
surfpb3=newreg;
Line Loop(surfpb3)={axex2,-Boxes_Linep4p1[7],-Boxes_Linep3p4[7],-Boxes_Linep2p3[7],axex3,21,40,-22};
Plane Surface(surfpb3+1) ={surfpb3,Boxes_LineLoop1[{3:6}]};
surfpb4=newreg;
Line Loop(surfpb4)={31,23,-41,-22};
Ruled Surface(surfpb4+1) ={surfpb4};
surfpb5=newreg;
Line Loop(surfpb5)={32,24,-42,-23};
Plane Surface(surfpb5+1) ={surfpb5};
surfpb6=newreg;
Line Loop(surfpb6)={33,25,-43,-24};
Ruled Surface(surfpb6+1) ={surfpb6};
surfpb7=newreg;
Line Loop(surfpb7)={34,arc3,Boxes_Linep11p12[{1:2}],arc4,axey2,-25};
Plane Surface(surfpb7+1) ={surfpb7};
surfpb8=newreg;
Line Loop(surfpb8)={35,arc1,Boxes_Linep2p11[2],-arc3};
Ruled Surface(surfpb8+1) ={surfpb8};
surfpb9=newreg;
Line Loop(surfpb9)={arc2,Boxes_Linep2p11[1],-arc4,-Boxes_Linep5p12[2]};
Ruled Surface(surfpb9+1) ={surfpb9};
surfpb10=newreg;
Line Loop(surfpb10)={axex1,arc1,-Boxes_Linep1p2[2],-Boxes_Linep6p1[2],-Boxes_Linep5p6[2],arc2,-Boxes_Linep1p2[1],-Boxes_Linep6p1[1],-axey1,Cyles_Curvep3p2[0]};
Plane Surface(surfpb10+1) ={surfpb10};

//Volume plaque base

volpb=newreg;
Surface Loop(volpb)={surfpbx+1,surfpby+1,surfpb1+1,surfpb2+1,surfpb3+1,surfpb4+1,surfpb5+1,surfpb6+1,surfpb7+1,surfpb8+1,surfpb9+1,surfpb10+1,Boxes_PlanSurf8[{1:2}],Boxes_PlanSurf1[{1:7}],Cyles_BaseSurf[0]};
Volume(volpb+1)={volpb};


//creation des points pour creer les sphere de transfo inf
tranZ=20*mm;
Point(350) = {  rint  ,  0.0   ,  tranZ      , lcrint1 };
Point(351) = {  rext  ,  0.0   ,  tranZ     , lcrext1 };
Point(352) = {  0.0   ,  rint  ,  tranZ   , lcrint1 };
Point(353) = {  0.0   ,  rext  ,  tranZ   , lcrext1 };
Point(354) = {  0.0   ,  0.0   ,  rext+tranZ    , lcrext1 };
Point(355) = {  0.0   ,  0.0   ,  rint+tranZ     , lcrint1 };
Point(356) = {  0.0   ,  0.0   ,  -rint+tranZ    , lcrint2 };
Point(357) = {  0.0   ,  0.0   ,  -rext+tranZ    , lcrext2 };

Line(358)={centre1,356};
Line(359)={356,357};
Line(360)={Cyles_Point4[0],355};
Line(361)={355,354};

centre=newreg;
Point(centre) = {  0.0     ,    0.0   ,   tranZ      ,  lcpba2  };
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
Line Loop(surfair1)= {358,-364,362,-360,Cyles_Linep4p5[0],Cyles_Linep5p2[0],axex[],-35,-34,-33,-32,-31,Boxes_Linep1p5[7],Boxes_Linep5p6[7],-Boxes_Linep2p6[7],-29,-28};
Plane Surface(surfair1+1)= {surfair1};

surfair2 = newreg;
Line Loop(surfair2)= {358,-368,366,-360,Cyles_Linep4p6[0],Cyles_Linep6p3[0],axey1,Boxes_Linep6p10[1],-Boxes_Linep9p10[1],-Boxes_Linep4p9[1],Boxes_Linep4p5[1],Boxes_Linep5p12[1],axey2,-43,-42,-41,-40,-39,-38};
Plane Surface(surfair2+1)= {surfair2};

volair = newreg;
Surface Loop(volair)={surfair1+1,surfair2+1,Cyles_HautSurf[0],Cyles_RuleSurf1[0],surfpb1+1,surfpb2+1,surfpb3+1,surfpb4+1,surfpb5+1,surfpb6+1,surfpb7+1,surfpb8+1,surfpb9+1,surfpb10+1,Boxes_PlanSurf8[{1:2}],Boxes_PlanSurf7[{1:2}],Boxes_PlanSurf6[2],Boxes_PlanSurf5[{1:2}],Boxes_PlanSurf4[{1:2}],Boxes_PlanSurf3[{1:2}],Boxes_PlanSurf2[{1:2}],Boxes_PlanSurf2[{3:7}],Boxes_PlanSurf3[{3:7}],Boxes_PlanSurf4[{3:6}],Boxes_PlanSurf5[{3:7}],Boxes_PlanSurf6[{3:7}],373,377};
Volume(volair+1) ={volair};


// definition des entites physiques

Physical Volume(9999)={volpb+1};
Physical Volume(9998)={volair+1};
Physical Volume(9997)={385};

Physical Volume(8888)={Cyles_Volume[0]};
Physical Volume(8887)={Boxes_Volume[{3:7}]};
Physical Volume(8886)={Boxes_Volume[2]};
Physical Volume(8885)={Boxes_Volume[1]};

Physical Surface(7776)={375,379};
Physical Surface(7777)={Boxes_PlanSurf4[7],surfpbx+1,surfair1+1,381,Cyles_Surf3[0],Cyles_Surf4[0],Boxes_PlanSurf6[1],surfpby+1,surfair2+1,383};


/*
Point(900)   = {    0.0   ,    50*mm   ,    0.0      ,  lcpba2  }; 
Point(901)   = {   50*mm   ,    0*mm   ,    0.0      ,  lcpba2  };  

Point(902)   = {    0.0   ,    30*mm   ,    0.0      ,  lcpba2  }; 
Point(903)   = {   30*mm   ,    0*mm   ,    0.0      ,  lcpba2  }; 

Point(904)   = {    0.0   ,    60*mm   ,    0.0      ,  lcpba2  }; 
Point(905)   = {   60*mm   ,    0*mm   ,    0.0      ,  lcpba2  };   

Circle(906) = {900,centre1,901};
Circle(907) = {902,centre1,903};
Circle(908) = {904,centre1,905};
*/
