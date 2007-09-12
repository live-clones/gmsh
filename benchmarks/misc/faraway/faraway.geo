
// From <irenee.cornaton@ortec.fr>

//lc = 0.001;
lc = 0.01;

Include "coque.geo" ;
//la ligne suivante est à enlever si y'a le include
//Point(0) = {0,0,0,lc} ;


//Creation du maillage 3D de la PE à trous brochés quadrifoliés 1

//1ère étape : création du contour rectangulaire au niveau de la base inf
//longueur de 36,29 mm
Point(2001) = {0.01814,-0.33346,8.976,lc};
Point(2002) = {0.01814,-0.29718,8.976,lc};
Point(2003) = {-0.01814,-0.33346,8.976,lc};
Point(2004) = {-0.01814,-0.29718,8.976,lc};
Line(2005) = {2001,2002} ;
Line(2006) = {2002,2004} ;
Line(2007) = {2004,2003} ;
Line(2008) = {2003,2001} ;
Transfinite Line {2005,2006,2007,2008} = 20 ;


//2ème étape : création du contour intérieur au niveau de la base inf
Point(2102) = {-16.83E-3*Sin(36.08*Pi/180),-0.31532+16.83E-3*Cos(36.08*Pi/180),8.976,lc} ;
Point(2103) = {-16.83E-3*Sin(78.48*Pi/180),-0.31532+16.83E-3*Cos(78.48*Pi/180),8.976,lc} ;
Point(2106) = {-16.83E-3*Sin(126.08*Pi/180),-0.31532+16.83E-3*Cos(126.08*Pi/180),8.976,lc} ;
Point(2107) = {-16.83E-3*Sin(168.48*Pi/180),-0.31532+16.83E-3*Cos(168.48*Pi/180),8.976,lc} ;
Point(2110) = {-16.83E-3*Sin(216.08*Pi/180),-0.31532+16.83E-3*Cos(216.08*Pi/180),8.976,lc} ;
Point(2111) = {-16.83E-3*Sin(258.48*Pi/180),-0.31532+16.83E-3*Cos(258.48*Pi/180),8.976,lc} ;
Point(2114) = {-16.83E-3*Sin(306.08*Pi/180),-0.31532+16.83E-3*Cos(306.08*Pi/180),8.976,lc} ;
Point(2115) = {-16.83E-3*Sin(348.48*Pi/180),-0.31532+16.83E-3*Cos(348.48*Pi/180),8.976,lc} ;



//3ème étape : création du contour circulaire à 1 mm du tube pour encastrement imparfait

//Point 2116  
Translate {-5.65e-3*0.144,4.033e-3*0.144,0} {Duplicata {Point{1314};} }
//Point 2117 
Translate {-6.017e-3*0.144,3.463e-3*0.144,0} {Duplicata {Point{1310};} }
//Point 2118  
Translate {-4.033e-3*0.144,-5.65e-3*0.144,0} {Duplicata {Point{1320};} }
//Point 2119 
Translate {-3.463e-3*0.144,-6.017e-3*0.144,0} {Duplicata {Point{1316};} }
//Point 2120  
Translate {5.65e-3*0.144,-4.033e-3*0.144,0} {Duplicata {Point{1326};} }
//Point 2121 
Translate {-6.017e-3*-0.144,3.463e-3*-0.144,0} {Duplicata {Point{1322};} }
//Point 2122  
Translate {-4.033e-3*-0.144,-5.65e-3*-0.144,0} {Duplicata {Point{1308};} }
//Point 2123 
Translate {3.463e-3*0.144,6.017e-3*0.144,0} {Duplicata {Point{1328};} }


//Création contours PE


Line(2009) = {2102,2117};
Line(2010) = {2103,2116};
Line(2011) = {2106,2119};
Line(2012) = {2107,2118};
Line(2013) = {2110,2121};
Line(2014) = {2111,2120};
Line(2015) = {2114,2123};
Line(2016) = {2115,2122};
Circle(2017) = {2114,1309,2115};
Circle(2018) = {2102,1309,2103};
Circle(2019) = {2106,1309,2107};
Circle(2020) = {2110,1309,2111};
Line(2025) = {1316,2119};
Line(2026) = {1320,2118};
Line(2027) = {1322,2121};
Line(2028) = {2120,1326};
Line(2029) = {2123,1328};
Line(2030) = {2122,1308};
Line(2031) = {1310,2117};
Line(2032) = {1314,2116};
Circle(2033) = {2123,1309,2120};
Circle(2034) = {2121,1309,2118};
Circle(2035) = {2119,1309,2116};
Circle(2036) = {2117,1309,2122};
Transfinite Line {2017,2018,2019,2020} = 12;
Transfinite Line {2033,2034,2035,2036} = 6;
Transfinite Line {2009:2016} = 4;
Transfinite Line {2025:2032} = 2;


//4ème étape : création du maillage 2D

//Création du maillage pour Encastrement Imparfait (périmètre de 1mm autour du tube)
Line Loop(2037) = {2031,2036,2030,1316};
Ruled Surface(2038) = {2037};
Line Loop(2039) = {2025,2035,-2032,1324};
Ruled Surface(2040) = {2039};
Line Loop(2041) = {2027,2034,-2026,1332};
Ruled Surface(2042) = {2041};
Line Loop(2043) = {-2029,2033,2028,1340};
Ruled Surface(2044) = {2043};

//Création du maillage du reste de la PE
Line Loop(2045) = {-2014,-2020,2013,2034,-2012,-2019,2011,2035,-2010,-2018,2009,2036,-2016,-2017,2015,2033};
Line Loop(2047) = {2007,2008,2005,2006};
Ruled Surface(2048) = {2047,2045};
Recombine Surface (2048)  ;


//5ème étape  : extrusion

Extrude Surface {2038,{0,0,0.03}}{Layers{4};Recombine;};
Extrude Surface {2040,{0,0,0.03}}{Layers{4};Recombine;};
Extrude Surface {2042,{0,0,0.03}}{Layers{4};Recombine;};
Extrude Surface {2044,{0,0,0.03}}{Layers{4};Recombine;};
Extrude Surface {2048,{0,0,0.03}}{Layers{4};Recombine;};




//Définition des Physical 1

//définition du groupe pour le maillage PE hormis zone 1mm (3D)
Physical Volume (4001) = {9004} ;
//définition du groupe pour les surfaces encastrées de la PE
Physical Surface (4002) = {2161,2165,2169,2173} ;
//définition du groupe pour la surface1 PE en contact PE/tube
Physical Surface (4003) = {1351} ;
//définition du groupe pour la surface2 PE en contact PE/tube
Physical Surface (4004) = {1355} ;
//définition du groupe pour la surface3 PE en contact PE/tube
Physical Surface (4005) = {1359} ;
//définition du groupe pour la surface4 PE en contact PE/tube
Physical Surface (4006) = {1363} ;
//définition du groupe pour affectation matériau dans zone 1mm
Physical Volume (4007) = {9000:9003} ;




//Creation du maillage 3D de la PE à trous brochés quadrifoliés 2

//1ère étape : création du contour rectangulaire au niveau de la base inf
//longueur de 36,29 mm
Point(5001) = {0.01814,0.33346,8.976,lc};
Point(5002) = {0.01814,0.29718,8.976,lc};
Point(5003) = {-0.01814,0.33346,8.976,lc};
Point(5004) = {-0.01814,0.29718,8.976,lc};
Line(5005) = {5001,5002} ;
Line(5006) = {5002,5004} ;
Line(5007) = {5004,5003} ;
Line(5008) = {5003,5001} ;
Transfinite Line {5005,5006,5007,5008} = 20 ;


//2ème étape : création du contour intérieur au niveau de la base inf
Point(5102) = {-16.83E-3*Sin(36.08*Pi/180),0.31532+16.83E-3*Cos(36.08*Pi/180),8.976,lc} ;
Point(5103) = {-16.83E-3*Sin(78.48*Pi/180),0.31532+16.83E-3*Cos(78.48*Pi/180),8.976,lc} ;
Point(5106) = {-16.83E-3*Sin(126.08*Pi/180),0.31532+16.83E-3*Cos(126.08*Pi/180),8.976,lc} ;
Point(5107) = {-16.83E-3*Sin(168.48*Pi/180),0.31532+16.83E-3*Cos(168.48*Pi/180),8.976,lc} ;
Point(5110) = {-16.83E-3*Sin(216.08*Pi/180),0.31532+16.83E-3*Cos(216.08*Pi/180),8.976,lc} ;
Point(5111) = {-16.83E-3*Sin(258.48*Pi/180),0.31532+16.83E-3*Cos(258.48*Pi/180),8.976,lc} ;
Point(5114) = {-16.83E-3*Sin(306.08*Pi/180),0.31532+16.83E-3*Cos(306.08*Pi/180),8.976,lc} ;
Point(5115) = {-16.83E-3*Sin(348.48*Pi/180),0.31532+16.83E-3*Cos(348.48*Pi/180),8.976,lc} ;


//3ème étape : création du contour circulaire à 1 mm du tube pour encastrement imparfait

//Point 5116  
Translate {-5.65e-3*0.144,4.033e-3*0.144,0} {Duplicata {Point{1435};} }
//Point 5117 
Translate {-6.017e-3*0.144,3.463e-3*0.144,0} {Duplicata {Point{1434};} }
//Point 5118  
Translate {-4.033e-3*0.144,-5.65e-3*0.144,0} {Duplicata {Point{1438};} }
//Point 5119 
Translate {-3.463e-3*0.144,-6.017e-3*0.144,0} {Duplicata {Point{1437};} }
//Point 5120  
Translate {5.65e-3*0.144,-4.033e-3*0.144,0} {Duplicata {Point{1441};} }
//Point 5121 
Translate {-6.017e-3*-0.144,3.463e-3*-0.144,0} {Duplicata {Point{1440};} }
//Point 5122  
Translate {-4.033e-3*-0.144,-5.65e-3*-0.144,0} {Duplicata {Point{1432};} }
//Point 5123 
Translate {3.463e-3*0.144,6.017e-3*0.144,0} {Duplicata {Point{1443};} }


//Création contours PE
Line(5013) = {5115,5122};
Line(5014) = {5102,5117};
Line(5015) = {5103,5116};
Line(5016) = {5106,5119};
Line(5017) = {5107,5118};
Line(5018) = {5110,5121};
Line(5019) = {5111,5120};
Line(5020) = {5114,5123};
Line(5021) = {5122,1432};
Line(5022) = {5117,1434};
Line(5023) = {5116,1435};
Line(5024) = {5119,1437};
Line(5025) = {5118,1438};
Line(5026) = {5121,1440};
Line(5027) = {5120,1441};
Line(5028) = {5123,1443};
Circle(5029) = {5122,1433,5117};
Circle(5030) = {5116,1433,5119};
Circle(5031) = {5118,1433,5121};
Circle(5032) = {5120,1433,5123};
Circle(5033) = {5114,1433,5115};
Circle(5034) = {5102,1433,5103};
Circle(5035) = {5106,1433,5107};
Circle(5036) = {5110,1433,5111};


Transfinite Line {5033:5036} = 12;
Transfinite Line {5029:5032} = 6;
Transfinite Line {5013:5020} = 4 ;
Transfinite Line {5021:5028} = 2 ;



//4ème étape : création du maillage 2D

//Création du maillage pour Encastrement Imparfait (périmètre de 1mm autour du tube)
Line Loop(5037) = {-1460,-5027,5032,5028};
Ruled Surface(5038) = {5037};
Line Loop(5039) = {-5022,-5029,5021,1448};
Ruled Surface(5040) = {5039};
Line Loop(5041) = {-5024,-5030,5023,1452};
Ruled Surface(5042) = {5041};
Line Loop(5043) = {-1456,-5025,5031,5026};
Ruled Surface(5044) = {5043};

//Création du maillage du reste de la PE
Line Loop(5045) = {5005,5006,5007,5008};
Line Loop(5047) = {-5020,5033,5013,5029,-5014,5034,5015,5030,-5016,5035,5017,5031,-5018,5036,5019,5032};
Ruled Surface(5048) = {5045,5047};

//a=newp;
//Translate{0,0,-9}{Point{1:a};}

//5ème étape  : extrusion

Extrude Surface {5038,{0,0,0.03}}{Layers{4};Recombine;};
Extrude Surface {5040,{0,0,0.03}}{Layers{4};Recombine;};
Extrude Surface {5042,{0,0,0.03}}{Layers{4};Recombine;};
Extrude Surface {5044,{0,0,0.03}}{Layers{4};Recombine;};
Extrude Surface {5048,{0,0,0.03}}{Layers{4};Recombine;};




//Définition des Physical 2

//définition du groupe pour le maillage PE hormis zone 1mm (3D)
Physical Volume (4101) = {10004} ;
//définition du groupe pour les surfaces encastrées de la PE
Physical Surface (4102) = {5161,5165,5169,5173} ;
//définition du groupe pour la surface1 PE en contact PE/tube
Physical Surface (4103) = {1451} ;
//définition du groupe pour la surface2 PE en contact PE/tube
Physical Surface (4104) = {1455} ;
//définition du groupe pour la surface3 PE en contact PE/tube
Physical Surface (4105) = {1459} ;
//définition du groupe pour la surface4 PE en contact PE/tube
Physical Surface (4106) = {1463} ;
//définition du groupe pour affectation matériau dans zone 1mm
Physical Volume (4107) = {10000:10003} ;

