Mesh.ElementOrder = 2;
Mesh.CharacteristicLengthFactor = 0.1;
Mesh.RecombinationAlgorithm = 0;
Mesh.SecondOrderIncomplete = 1;

Point(1) = {-10,-8,0.000000};
Point(2) = {4, 6,0.000000};

Point(3) = {-11,-4,0.000000};
Point(4) = {-3, 4,0.000000};

Point(5) = {0,-7,0.000000};
Point(6) = {10, 3,0.000000};

Point(7) = {-8,-9,0.000000};
Point(8) = {3,2,0.000000};

Point(9) = {0,-9,0.000000};
Point(10)= {4,-5,0.000000};


Point(11) = {-9,-9,0.000000};
Point(12) = { 6,-9,0.000000};
                
Point(13) = { 1,-5 ,0.000000};
Point(14) = {11,-5 ,0.000000};
                
Point(15) = {-13, 0 ,0.000000};
Point(16) = { 3, 0 ,0.000000};
                
Point(17) = {-6 ,5  ,.000000};
Point(18) = {9 ,5  ,.000000};
                
Point(19) = {-4 ,9 ,.000000};
Point(20) = {4 ,9 ,.000000};


Line(1) = {1,2};
Line(2) = {3,4};
Line(3) = {5,6};
Line(4) = {7,8};
Line(5) = {9,10};


Line(6) = {11,12};
Line(7) = {13,14};
Line(8) = {15,16};
Line(9) = {17,18};
Line(10)= {19,20};


Point(288) = {-13,-10.000000,0.000000};
Point(289) = {-13,0.000000,0.000000};
Point(290) = {-13,10.000000,0.000000};
Point(286) = {13,10.000000,0.000000};
Point(287) = {13,-10.000000,0.000000};


Line(145) = {286,287};
Line(146) = {287,288};
Line(147) = {288,289};
Line(148) = {289,290};
Line(149) = {290,286};

Line Loop(150) = {145,146,147,148,149};
Plane Surface(1) = {150};

group1[] = {1, 2, 3, 4, 5};
group2[] = {6, 7, 8, 9,10};

Physical Line ( 1 ) = { group1[] } ;
Physical Line ( 2 ) = { group2[] } ;


Physical Line ( "DROITE" ) = { 145 } ;
Physical Line ( "BAS"    ) = { 146 } ;
Physical Line ( "GAUCHE" ) = { 147, 148 } ;
Physical Line ( "HAUT"   ) = { 149 } ;


Physical Surface ( "MASSIF" ) = { 1 } ;


Line { group1[] } In Surface {1};
Line { group2[] } In Surface {1};

Mesh 2;

Plugin(FaultZone).SurfaceTag = 1;
Plugin(FaultZone).Thickness = 0.05;
Plugin(FaultZone).Prefix = "FAMI_";
Plugin(FaultZone).Run;
