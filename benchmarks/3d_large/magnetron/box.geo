  p1 = newp; Point(p1) = {xBox+h1Box,      yBox-lBox/2, zBox,  lcBox} ;
  p2 = newp; Point(p2) = {xBox+h1Box+wBox, yBox-lBox/2, zBox,  lcBox} ;
  p3 = newp; Point(p3) = {xBox+h1Box+wBox, yBox+lBox/2, zBox,  lcBox} ;
  p4 = newp; Point(p4) = {xBox+h1Box,      yBox+lBox/2, zBox,  lcBox} ;

  p5 = newp; Point(p5) = {xBox+h1Box,      yBox-lBox/2, zBox+hBox,  lcBox} ; 
  p6 = newp; Point(p6) = {xBox+h1Box+wBox, yBox-lBox/2, zBox+hBox,  lcBox} ;
  p7 = newp; Point(p7) = {xBox+h1Box+wBox, yBox+lBox/2, zBox+hBox,  lcBox} ;
  p8 = newp; Point(p8) = {xBox+h1Box,      yBox+lBox/2, zBox+hBox,  lcBox} ;
  
  Boxes_Point1[iBox] = p1 ;
  Boxes_Point2[iBox] = p2 ;
  Boxes_Point3[iBox] = p3 ;
  Boxes_Point4[iBox] = p4 ;
  Boxes_Point5[iBox] = p5 ;
  Boxes_Point6[iBox] = p6 ;
  Boxes_Point7[iBox] = p7 ;
  Boxes_Point8[iBox] = p8 ;

  c1 = newreg; Line(c1) = {p1,p2};
  c2 = newreg; Line(c2) = {p2,p3};
  c3 = newreg; Line(c3) = {p3,p4};
  c4 = newreg; Line(c4) = {p4,p1};

  c5 = newreg; Line(c5) = {p5,p6};
  c6 = newreg; Line(c6) = {p6,p7};
  c7 = newreg; Line(c7) = {p7,p8};
  c8 = newreg; Line(c8) = {p8,p5};

  c9 = newreg; Line(c9) = {p1,p5};
  c10 = newreg; Line(c10) = {p2,p6};
  c11 = newreg; Line(c11) = {p3,p7};
  c12 = newreg; Line(c12) = {p4,p8};

  Boxes_Linep1p2[iBox] = c1 ;
  Boxes_Linep2p3[iBox] = c2 ;
  Boxes_Linep3p4[iBox] = c3 ;
  Boxes_Linep4p1[iBox] = c4 ;
  Boxes_Linep5p6[iBox] = c5 ;
  Boxes_Linep6p7[iBox] = c6 ;
  Boxes_Linep7p8[iBox] = c7 ;
  Boxes_Linep8p1[iBox] = c8 ;
  Boxes_Linep1p5[iBox] = c9 ;
  Boxes_Linep2p6[iBox] = c10 ;
  Boxes_Linep3p7[iBox] = c11 ;
  Boxes_Linep4p8[iBox] = c12 ;

  l1 = newreg; Line Loop(l1) = {c1,c2,c3,c4}; Plane Surface(l1+1) = {l1};
  l2 = newreg; Line Loop(l2) = {c5,c6,c7,c8}; Plane Surface(l2+1) = {l2};

  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Surface{l1+1}; }
  Rotate{{0,0,1},{xBox,yBox,zBox},thetaBox*Pi/180}{ Surface{l2+1}; }
 
  l3 = newreg; Line Loop(l3) = {c9,-c8,-c12,c4}; Plane Surface(l3+1) = {l3};
  l4 = newreg; Line Loop(l4) = {c10,-c5,-c9,c1}; Plane Surface(l4+1) = {l4};
  l5 = newreg; Line Loop(l5) = {c6,-c11,-c2,c10}; Plane Surface(l5+1) = {l5};
  l6 = newreg; Line Loop(l6) = {c12,-c7,-c11,c3}; Plane Surface(l6+1) = {l6};

  Boxes_LineLoop1[iBox] = l1 ;
  Boxes_LineLoop2[iBox] = l2 ;
  Boxes_LineLoop3[iBox] = l3 ;
  Boxes_LineLoop4[iBox] = l4 ;
  Boxes_LineLoop5[iBox] = l5 ;
  Boxes_LineLoop6[iBox] = l6 ;

  Boxes_PlanSurf1[iBox] = l1+1;
  Boxes_PlanSurf2[iBox] = l2+1;
  Boxes_PlanSurf3[iBox] = l3+1;
  Boxes_PlanSurf4[iBox] = l4+1;
  Boxes_PlanSurf5[iBox] = l5+1;
  Boxes_PlanSurf6[iBox] = l6+1;

  s = newreg; Surface Loop(s) = {l2+1,l4+1,l5+1,l6+1,l3+1,l1+1}; Volume(s+1) = s ;

  Boxes_SurfaceLoop[iBox] = s ;
  Boxes_Volume[iBox] = s+1 ;


