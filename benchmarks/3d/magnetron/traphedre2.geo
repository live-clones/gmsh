
  angle=30*Pi/180;
  chouilla=0.0005;
  R = RBox;
  racine=(Tan[angle]*chouilla+Sqrt[R^2-chouilla^2+(R^2*Tan[angle]^2)])/(1+Tan[angle]^2);

  
  p1 = newp; Point(p1) = {xBox+h1Box,yBox-(h1Box*Tan[angle]-chouilla) , zBox,  lcBox} ;
  p2 = newp; Point(p2) = {xBox+racine,yBox-(racine*Tan[angle]-chouilla), zBox,  lcBox} ;
  p3 = newp; Point(p3) = {xBox+h2Box,yBox-(h2Box*Tan[angle]-chouilla) , zBox,  lcBox} ;
  p4 = newp; Point(p4) = {xBox+h2Box,yBox , zBox,  lcBox} ;
  
  p6 = newp; Point(p6) = {xBox+h1Box,yBox , zBox,  lcBox} ;

  p7 = newp; Point(p7) = {xBox+h1Box,yBox-(h1Box*Tan[angle]-chouilla) , zBox+epBox,  lcBox} ;
  p8 = newp; Point(p8) = {xBox+h2Box,yBox-(h2Box*Tan[angle]-chouilla), zBox+epBox,  lcBox} ;
  p9 = newp; Point(p9) = {xBox+h2Box,yBox, zBox+epBox,  lcBox} ;
  p10 = newp; Point(p10) = {xBox+h1Box,yBox, zBox+epBox,  lcBox} ;

  p11 = newp; Point(p11) = {xBox+racine,yBox-(racine*Tan[angle]-chouilla), zBox-difBox,  lcBox} ;
  
  

  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p1}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p2}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p3}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p4}; }
  p5 = newp; Point(p5) = {xBox+RBox,yBox, zBox,  lcBox} ;
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p5}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p6}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p7}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p8}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p9}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p10}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p11}; }
  p12 = newp; Point(p12) = {xBox+RBox,yBox, zBox-difBox,  lcBox} ;
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Point{p12}; }

  Boxes_Point1[iBox] = p1 ;
  Boxes_Point2[iBox] = p2 ;
  Boxes_Point3[iBox] = p3 ;
  Boxes_Point4[iBox] = p4 ;
  Boxes_Point5[iBox] = p5 ;
  Boxes_Point6[iBox] = p6 ;
  Boxes_Point7[iBox] = p7 ;
  Boxes_Point8[iBox] = p8 ;
  Boxes_Point9[iBox] = p9 ;
  Boxes_Point10[iBox] = p10 ;
  Boxes_Point11[iBox] = p11 ; 
  Boxes_Point12[iBox] = p12 ;

  c1 = newreg; Line(c1) = {p1,p2};
  c2 = newreg; Line(c2) = {p2,p3};
  c3 = newreg; Line(c3) = {p3,p4};
  c4 = newreg; Line(c4) = {p4,p5};
  c5 = newreg; Line(c5) = {p5,p6};
  c6 = newreg; Line(c6) = {p6,p1};
  c7 = newreg; Circle(c7) = {p2,pcen,p5};
  c8 = newreg; Line(c8) = {p7,p8};
  c9 = newreg; Line(c9) = {p8,p9};
  c10 = newreg; Line(c10) = {p9,p10};
  c11 = newreg; Line(c11) = {p10,p7};
  c12 = newreg; Line(c12) = {p1,p7};
  c13 = newreg; Line(c13) = {p3,p8};
  c14 = newreg; Line(c14) = {p4,p9};
  c15 = newreg; Line(c15) = {p6,p10};
  c16 = newreg; Line(c16) = {p2,p11};
  c17 = newreg; Line(c17) = {p5,p12};
  c18 = newreg; Circle(c18) = {p11,pcen2,p12};

  Boxes_Linep1p2[iBox] = c1 ;
  Boxes_Linep2p3[iBox] = c2 ;
  Boxes_Linep3p4[iBox] = c3 ;
  Boxes_Linep4p5[iBox] = c4 ;
  Boxes_Linep5p6[iBox] = c5 ;
  Boxes_Linep6p1[iBox] = c6 ;
  Boxes_Linep2p5[iBox] = c7 ;
  Boxes_Linep7p8[iBox] = c8 ;
  Boxes_Linep8p9[iBox] = c9 ;
  Boxes_Linep9p10[iBox] = c10 ;
  Boxes_Linep10p7[iBox] = c11 ;
  Boxes_Linep1p7[iBox] = c12 ;
  Boxes_Linep3p8[iBox] = c13 ;
  Boxes_Linep4p9[iBox] = c14 ;
  Boxes_Linep6p10[iBox] = c15 ;
  Boxes_Linep2p11[iBox] = c16 ;
  Boxes_Linep5p12[iBox] = c17 ;
  Boxes_Linep11p12[iBox] = c18 ;

  
  l1 = newreg; Line Loop(l1) = {c1,c7,c5,c6}; Plane Surface(l1+1) = {l1};
  l2 = newreg; Line Loop(l2) = {c2,c3,c4,-c7}; Plane Surface(l2+1) = {l2};
  l3 = newreg; Line Loop(l3) = {c8,c9,c10,c11}; Plane Surface(l3+1) = {l3};
  l4 = newreg; Line Loop(l4) = {c1,c2,c13,-c8,-c12}; Plane Surface(l4+1) = {l4};
  l5 = newreg; Line Loop(l5) = {c3,c14,-c9,-c13}; Plane Surface(l5+1) = {l5};
  l6 = newreg; Line Loop(l6) = {c4,c5,c15,-c10,-c14}; Plane Surface(l6+1) = {l6};
  l7 = newreg; Line Loop(l7) = {c6,c12,-c11,-c15}; Plane Surface(l7+1) = {l7};
  l8 = newreg; Line Loop(l8) = {c16,c18,-c17,-c7}; Ruled Surface(l8+1) = {l8};

  Boxes_LineLoop1[iBox] = l1 ;Boxes_PlanSurf1[iBox] = l1+1;
  Boxes_LineLoop2[iBox] = l2 ;Boxes_PlanSurf2[iBox] = l2+1;
  Boxes_LineLoop3[iBox] = l3 ;Boxes_PlanSurf3[iBox] = l3+1;
  Boxes_LineLoop4[iBox] = l4 ;Boxes_PlanSurf4[iBox] = l4+1;
  Boxes_LineLoop5[iBox] = l5 ;Boxes_PlanSurf5[iBox] = l5+1;
  Boxes_LineLoop6[iBox] = l6 ;Boxes_PlanSurf6[iBox] = l6+1;
  Boxes_LineLoop7[iBox] = l7 ;Boxes_PlanSurf7[iBox] = l7+1;
  Boxes_LineLoop8[iBox] = l8 ;Boxes_PlanSurf8[iBox] = l8+1;

  s = newreg; Surface Loop(s) = {l1+1,l2+1,l3+1,l4+1,l5+1,l6+1,l7+1}; Volume(s+1) = s ;
  
  Boxes_SurfaceLoop[iBox] = s ;
  Boxes_Volume[iBox] = s+1 ;



