// Function Forme1: cree un demi T - de pt d'ancrage xFor,yFor zFor
// 				    - de longueur LFor
//                  		    - de largeurs l1For, l2For
//                 		    - de hauteurs h1For, h2For, de lc lcFor
//
  l1Fom=Sqrt[R1Fom^2-h1Fom^2];
  l2Fom=Sqrt[R2Fom^2-h1Fom^2];
  chouilla=0.0005;
  p1 = newp; Point(p1) = {xFom       , yFom , zFom ,  lcFom} ;
  p2 = newp; Point(p2) = {xFom-l2Fom+(L1Fom/Tan[angle]) , yFom, zFom-Sqrt[R1Fom^2-(l2Fom-(L1Fom/Tan[angle]))^2]  ,  lcFom} ;
  p3 = newp; Point(p3) = {xFom-l2Fom+(L1Fom/Tan[angle]), yFom , zFom-Sqrt[R2Fom^2-(l2Fom-(L1Fom/Tan[angle]))^2]  ,  lcFom} ;
  p4 = newp; Point(p4) = {xFom+l2Fom , yFom , zFom-h1Fom ,  lcFom} ;
  p5 = newp; Point(p5) = {xFom+l1Fom , yFom , zFom-h1Fom ,  lcFom} ;
  
  p6 = newp; Point(p6)  = {xFom       , yFom+LFom  , zFom ,  lcFom} ;
  p7 = newp; Point(p7)  = {xFom-l2Fom+(L1Fom/Tan[angle]) , yFom+LFom, zFom-Sqrt[R1Fom^2-(l2Fom-(L1Fom/Tan[angle]))^2]  ,  lcFom} ;
  p8 = newp; Point(p8)  = {xFom-l2Fom+(L1Fom/Tan[angle]), yFom+LFom , zFom-Sqrt[R2Fom^2-(l2Fom-(L1Fom/Tan[angle]))^2]  ,  lcFom} ;
  p9 = newp; Point(p9)  = {xFom+l2Fom , yFom+LFom , zFom-h1Fom ,  lcFom} ;
  p10 = newp; Point(p10)= {xFom+l1Fom , yFom+LFom , zFom-h1Fom ,  lcFom} ;
  p11 = newp; Point(p11)= {xFom-l1Fom , yFom+(L1Fom-(l2Fom-l1Fom)*Tan[angle]) , zFom-h1Fom ,  lcFom} ;
  p12 = newp; Point(p12)= {xFom-l2Fom , yFom+L1Fom , zFom-h1Fom ,  lcFom} ;
  p13 = newp; Point(p13)= {xFom-l2Fom , yFom+LFom-L1Fom , zFom-h1Fom ,  lcFom} ;
  p14 = newp; Point(p14)= {xFom-l1Fom , yFom+(2*L1Fom+(l2Fom-l1Fom)*Tan[angle]) , zFom-h1Fom ,  lcFom} ;
  prot = newp; Point(prot)= {xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom ,  lcFom} ;
  
  Fomes_Point1[iFom] = p1 ;
  Fomes_Point2[iFom] = p2 ;
  Fomes_Point3[iFom] = p3 ;
  Fomes_Point4[iFom] = p4 ;
  Fomes_Point5[iFom] = p5 ;
  Fomes_Point6[iFom] = p6 ;
  Fomes_Point7[iFom] = p7 ;
  Fomes_Point8[iFom] = p8 ;
  Fomes_Point9[iFom] = p9 ;
  Fomes_Point10[iFom] = p10 ;
  Fomes_Point11[iFom] = p11 ;
  Fomes_Point12[iFom] = p12 ;
  Fomes_Point13[iFom] = p13 ;
  Fomes_Point14[iFom] = p14 ;

  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p1}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p2}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p3}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p4}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p5}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p6}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p7}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p8}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p9}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p10};}
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p11}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p12}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p13}; }
  Rotate{{0,0,1},{xFom-chouilla-(l2Fom+(L1Fom/(2*Tan[angle]))) , yFom+(3*L1Fom/2) , zFom-h1Fom},theta*Pi/180}{ Point{p14}; }

  c1 = newreg; Line(c1) = {p2,p3};
  c2 = newreg; Circle(c2) = {p3,p1,p4};
  c3 = newreg; Line(c3) = {p4,p5};
  c4 = newreg; Circle(c4) = {p5,p1,p2};
  c5 = newreg; Line(c5) = {p7,p8};
  c6 = newreg; Circle(c6) = {p8,p6,p9};
  c7 = newreg; Line(c7) = {p9,p10};
  c8 = newreg; Circle(c8) = {p10,p6,p7};
  c9 = newreg; Line(c9) = {p2,p7};
  c10 = newreg; Line(c10) = {p3,p8};
  c11 = newreg; Line(c11) = {p4,p9};
  c12 = newreg; Line(c12) = {p5,p10};

  c13 = newreg; Line(c13) = {p11,p12};
  c14 = newreg; Line(c14) = {p12,p13};
  c15 = newreg; Line(c15) = {p13,p14};
  c16 = newreg; Line(c16) = {p14,p11};
  c17 = newreg; Line(c17) = {p2,p11};
  c18 = newreg; Line(c18) = {p7,p14};
  c19 = newreg; Line(c19) = {p3,p12};
  c20 = newreg; Line(c20) = {p8,p13};  


  Fomes_Linep2p3[iFom] = c1 ;
  Fomes_Linep3p4[iFom] = c2 ;
  Fomes_Linep4p5[iFom] = c3 ;
  Fomes_Linep5p2[iFom] = c4 ;
  Fomes_Linep7p8[iFom] = c5 ;
  Fomes_Linep8p9[iFom] = c6 ;
  Fomes_Linep9p10[iFom] = c7 ;
  Fomes_Linep10p7[iFom] = c8 ;
  Fomes_Linep2p7[iFom] =  c9 ;
  Fomes_Linep3p8[iFom] = c10 ;
  Fomes_Linep4p9[iFom] = c11 ;
  Fomes_Linep5p10[iFom] = c12 ;
  Fomes_Linep11p12[iFom] = c13 ;
  Fomes_Linep12p13[iFom] = c14 ;
  Fomes_Linep13p14[iFom] = c15 ;
  Fomes_Linep14p11[iFom] = c16 ;
  Fomes_Linep2p11[iFom] = c17 ;
  Fomes_Linep7p14[iFom] = c18 ;
  Fomes_Linep3p12[iFom] = c19 ;
  Fomes_Linep8p13[iFom] = c20 ; 

  l1 = newreg; Line Loop(l1) = {c2,c11,-c6,-c10};Ruled Surface(l1+1) = {l1};
  l2 = newreg; Line Loop(l2) = {c3,c12,-c7,-c11};Plane Surface(l2+1) = {l2};
  l3 = newreg; Line Loop(l3) = {c1,c10,-c5,-c9};Plane Surface(l3+1) = {l3};
  l4 = newreg; Line Loop(l4) = {c4,c9,-c8,-c12};Ruled Surface(l4+1) = {l4};
  l5 = newreg; Line Loop(l5) = {c13,c14,c15,c16};Plane Surface(l5+1) = {l5};
  l6 = newreg; Line Loop(l6) = {c16,-c17,c9,c18};Plane Surface(l6+1) = {l6};  
  l7 = newreg; Line Loop(l7) = {c14,-c20,-c10,c19}; Plane Surface(l7+1) = {l7};
  l8 = newreg; Line Loop(l8) = {c5,c6,c7,c8}; Plane Surface(l8+1) = {l8};
  l9 = newreg; Line Loop(l9) = {c13,-c19,-c1,c17};Plane Surface(l9+1) = {l9};
  l10 = newreg; Line Loop(l10) = {c1,c2,c3,c4};Plane Surface(l10+1) = {l10};
  l11 = newreg; Line Loop(l11) = {c15,-c18,c5,c20};Plane Surface(l11+1) = {l11}; 
 

  Fomes_LineLoop1[iFom]=l1;Fomes_Surf1[iFom] = l1+1;
  Fomes_LineLoop2[iFom]=l2;Fomes_Surf2[iFom] = l2+1;
  Fomes_LineLoop3[iFom]=l3;Fomes_Surf3[iFom] = l3+1;
  Fomes_LineLoop4[iFom]=l4;Fomes_Surf4[iFom] = l4+1;
  Fomes_LineLoop5[iFom]=l5;Fomes_Surf5[iFom] = l5+1;
  Fomes_LineLoop6[iFom]=l6;Fomes_Surf6[iFom] = l6+1;
  Fomes_LineLoop7[iFom]=l7;Fomes_Surf7[iFom] = l7+1;
  Fomes_LineLoop8[iFom]=l8;Fomes_Surf8[iFom] = l8+1;
  Fomes_LineLoop9[iFom]=l9;Fomes_Surf9[iFom] = l9+1;
  Fomes_LineLoop10[iFom]=l10;Fomes_Surf10[iFom] = l10+1;
  Fomes_LineLoop10[iFom]=l10;Fomes_Surf11[iFom] = l11+1;


  s = newreg; Surface Loop(s) = {l1+1,l2+1,l4+1,l5+1,l6+1,l7+1,l8+1,l9+1,l10+1,l11+1}; Volume(s+1) = s ;

 
  Fomes_SurfaceLoop[iFom] = s ;
  Fomes_Volume[iFom] = s+1 ;









