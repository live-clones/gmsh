Mesh.Algorithm = 2 ;
Mesh.CharacteristicLengthFactor = 1. ;
Mesh.Normals = 0;//Size of the normal vectors
Mesh.Points = 0 ;

FEM = 0 ;

u  = 1.e-6 ;

Lc = 475 * u ;
Lb = 205 * u ;
Ls = 625 * u ;

da = 80 * u ;
t = 150 * u ; 
bc = 275 * u ;
bb = 20 * u ;

w = 25 * u ;

p0=  20*u ;
p1 = 20*u ;
p2 = p1;

d =  4*u ;//4*u

td = .2 * u ;// .2*u
tin = .5 * u ;//.5*u
bin = 285 * u ;
Lin = 485 *u ;
win = bin/3 ;
gap = 3*u ;// 3*u


// Shell for FEM
lcs1 = 70 * u ;
lcs2 = 90 * u ;
R1 = 600 * u ; 
R2 = 900 * u ; 

Point(1) = { bc/2, Lc/2, 0, p0};
Point(2) = { bc/2,-Lc/2, 0, p0};
Point(3) = {-bc/2,-Lc/2, 0, p0};
Point(4) = {-bc/2, Lc/2, 0, p0};

k = newp ;
i = 0;kl = 1 ;
For(1:4) 
Point(k)   = { bc/2, Lc/2-3*w-i*(da+bb), 0, p1};
Point(k+1) = { bc/2, Lc/2-3*w-bb-i*(da+bb), 0, p1};
Point(k+2) = { -bc/2, Lc/2-3*w-i*(da+bb), 0, p1};
Point(k+3) = { -bc/2, Lc/2-3*w-bb-i*(da+bb), 0, p1};

Point(k+4)   = { bc/2+Lb, Lc/2-3*w-i*(da+bb), 0, p1};
Point(k+5) = { bc/2+Lb, Lc/2-3*w-bb-i*(da+bb), 0, p1};
Point(k+6) = { -bc/2-Lb, Lc/2-3*w-i*(da+bb), 0, p1};
Point(k+7) = { -bc/2-Lb, Lc/2-3*w-bb-i*(da+bb), 0, p1};

Line(kl) = {k,k+4};
Line(kl+1) = {k+1,k+5};
Line(kl+2) = {k+2,k+6};
Line(kl+3) = {k+3,k+7};

Line(kl+4) = {k,k+1};
Line(kl+5) = {k+4,k+5};
Line(kl+6) = {k+2,k+3};
Line(kl+7) = {k+6,k+7};

k += 8; i+=1; kl +=8 ;
EndFor

Line(33) = {4,1};
Line(34) = {4,7};
Line(35) = {8,15};
Line(36) = {16,23};
Line(37) = {24,31};
Line(38) = {32,3};
Line(39) = {3,2};
Line(40) = {2,30};
Line(41) = {29,22};
Line(42) = {21,14};
Line(43) = {13,6};
Line(44) = {5,1};

p_beams = 16 ;
p_wbeams = 3 ;
p_between = 4;//5
p_width = 12 ;

nl = 2 ;

Transfinite Line {1:4, 9:12, 17:20, 25:28 } = p_beams;
Transfinite Line {5:8,13:16, 21:24, 29:32 } = p_wbeams;
Transfinite Line {34:38,40:44} = p_between ; 
Transfinite Line {33,39} = p_width ; 

Line Loop(45) = {4,-8,-3,7};
Plane Surface(46) = {45};
Line Loop(47) = {12,-16,-11,15};
Plane Surface(48) = {47};
Line Loop(49) = {20,-24,-19,23};
Plane Surface(50) = {49};
Line Loop(51) = {28,-32,-27,31};
Plane Surface(52) = {51};

Line Loop(53) = {2,-6,-1,5};
Plane Surface(54) = {53};
Line Loop(55) = {-13,9,14,-10};
Plane Surface(56) = {55};
Line Loop(57) = {-21,17,22,-18};
Plane Surface(58) = {57};
Line Loop(59) = {-29,25,30,-26};
Plane Surface(60) = {59};

Transfinite Surface{46} = {8,12,11,7};
Transfinite Surface{48} = {16,20,19,15};
Transfinite Surface{50} = {24,28,27,23};
Transfinite Surface{52} = {32,36,35,31};

Transfinite Surface{54} = {10,6,5,9};
Transfinite Surface{56} = {18,14,13,17};
Transfinite Surface{58} = {26,22,21,25};
Transfinite Surface{60} = {34,30,29,33};

Line(61) = {7,5};
Line(62) = {8,6};
Line(63) = {15,13};
Line(64) = {16,14};
Line(65) = {23,21};
Line(66) = {24,22};
Line(67) = {31,29};
Line(68) = {32,30};

Transfinite Line {61:68} = p_width ; 

Line Loop(69) = {44,-33,34,61};
Plane Surface(70) = {69};
Line Loop(71) = {-5,-61,7,62};
Plane Surface(72) = {71};
Line Loop(73) = {43,-62,35,63};
Plane Surface(74) = {73};
Line Loop(75) = {-13,-63,15,64};
Plane Surface(76) = {75};
Line Loop(77) = {42,-64,36,65};
Plane Surface(78) = {77};
Line Loop(79) = {-21,-65,23,66};
Plane Surface(80) = {79};
Line Loop(81) = {41,-66,37,67};
Plane Surface(82) = {81};
Line Loop(83) = {-29,-67,31,68};
Plane Surface(84) = {83};
Line Loop(85) = {-40,-39,-38,68};
Plane Surface(86) = {85};

Transfinite Surface{70} = {5,1,4,7};
Transfinite Surface{72} = {6,5,7,8};
Transfinite Surface{74} = {13,6,8,15};
Transfinite Surface{76} = {14,13,15,16};
Transfinite Surface{78} = {21,14,16,23};
Transfinite Surface{80} = {22,21,23,24};
Transfinite Surface{82} = {29,22,24,31};
Transfinite Surface{84} = {30,29,31,32};
Transfinite Surface{86} = {2,30,32,3};

Color Turquoise {Surface{46:60:2};}
Color Turquoise {Surface{70:86:2};}

volPlateINT[] = {} ;

For i In {0:7}
vol[] = Extrude Surface { 46+i*2, {0,0,d}} { Layers { {nl},  {1}} ; };;
volPlateINT[] += vol[1];
EndFor
For i In {0:8}
vol[] = Extrude Surface { 70+i*2, {0,0,d}} { Layers { {nl},  {1}} ; };;
volPlateINT[] += vol[1];
EndFor


Sur_PlateINT = 1111 ;
PlateINT = 1100;

Physical Surface(Sur_PlateINT) = {261,-60,84,82,403,239,-58,80,78,359,217,-56,76,74,315,
				  183,-54,-187,-191,271,70,-275,279,103,-46,-95,99,108,-306,
				  196,-284,-328,323,125,-48,-117,121,130,-350,218,-209,-213,
				  -372,367,147,-50,-139,143,152,-394,240,-231,-235,-416,411,
				  169,-52,-161,165,174,-438,262,-253,-257,-460,447,86,451,455,72};

Physical Volume(PlateINT) = {volPlateINT[]};

Sur_Beam1i = 101 ; 
Sur_Beam2i = 102 ; 
Sur_Beam3i = 103 ; 
Sur_Beam4i = 104 ; 

Pto_Beam1i1 = 111 ;
Pto_Beam1i2 = 112 ; 
Pto_Beam1i3 = 113 ; 
Pto_Beam1i4 = 114 ; 

Pto_Beam2i1 = 121 ;
Pto_Beam2i2 = 122 ;
Pto_Beam2i3 = 123 ;
Pto_Beam2i4 = 124 ;

Pto_Beam3i1 = 131 ;
Pto_Beam3i2 = 132 ;
Pto_Beam3i3 = 133 ;
Pto_Beam3i4 = 134 ;

Pto_Beam4i1 = 141 ;
Pto_Beam4i2 = 142 ;
Pto_Beam4i3 = 143 ;
Pto_Beam4i4 = 144 ;

Physical Surface(Sur_Beam1i) = {99};
Physical Surface(Sur_Beam2i) = {121};
Physical Surface(Sur_Beam3i) = {143};
Physical Surface(Sur_Beam4i) = {165};

Physical Point(Pto_Beam1i1)= {11} ;
Physical Point(Pto_Beam1i2)= {12} ;
Physical Point(Pto_Beam1i3)= {38} ;
Physical Point(Pto_Beam1i4)= {42} ;

Physical Point(Pto_Beam2i1)= {19} ;
Physical Point(Pto_Beam2i2)= {20} ;
Physical Point(Pto_Beam2i3)= {48} ;
Physical Point(Pto_Beam2i4)= {52} ;

Physical Point(Pto_Beam3i1)= {27} ;
Physical Point(Pto_Beam3i2)= {28} ;
Physical Point(Pto_Beam3i3)= {58} ;
Physical Point(Pto_Beam3i4)= {62} ;

Physical Point(Pto_Beam4i1)= {35} ;
Physical Point(Pto_Beam4i2)= {36} ;
Physical Point(Pto_Beam4i3)= {68} ;
Physical Point(Pto_Beam4i4)= {72} ;

Sur_Beam1d = 201 ; 
Sur_Beam2d = 202 ; 
Sur_Beam3d = 203 ; 
Sur_Beam4d = 204 ; 

Pto_Beam1d1 = 211 ;
Pto_Beam1d2 = 212 ; 
Pto_Beam1d3 = 213 ; 
Pto_Beam1d4 = 214 ; 

Pto_Beam2d1 = 221 ;
Pto_Beam2d2 = 222 ;
Pto_Beam2d3 = 223 ;
Pto_Beam2d4 = 224 ;

Pto_Beam3d1 = 231 ;
Pto_Beam3d2 = 232 ;
Pto_Beam3d3 = 233 ;
Pto_Beam3d4 = 234 ;

Pto_Beam4d1 = 241 ;
Pto_Beam4d2 = 242 ;
Pto_Beam4d3 = 243 ;
Pto_Beam4d4 = 244 ;

Physical Surface(Sur_Beam1d) = {-187};
Physical Surface(Sur_Beam2d) = {-213};
Physical Surface(Sur_Beam3d) = {-235};
Physical Surface(Sur_Beam4d) = {-257};

Physical Point(Pto_Beam1d1)= {9} ;
Physical Point(Pto_Beam1d2)= {10} ;
Physical Point(Pto_Beam1d3)= {78} ;
Physical Point(Pto_Beam1d4)= {82} ;

Physical Point(Pto_Beam2d1)= {17} ;
Physical Point(Pto_Beam2d2)= {18} ;
Physical Point(Pto_Beam2d3)= {92} ;
Physical Point(Pto_Beam2d4)= {96} ;

Physical Point(Pto_Beam3d1)= {25} ;
Physical Point(Pto_Beam3d2)= {26} ;
Physical Point(Pto_Beam3d3)= {102} ;
Physical Point(Pto_Beam3d4)= {106} ;

Physical Point(Pto_Beam4d1)= {33} ;
Physical Point(Pto_Beam4d2)= {34} ;
Physical Point(Pto_Beam4d3)= {112} ;
Physical Point(Pto_Beam4d4)= {116} ;


Color Turquoise {Surface{261,60,84,82,403,239,58,80,78,359,217,56,76,74,315,
			 183,54,187,191,271,70,275,279,103,46,95,99,108,306,
			 196,284,328,323,125,48,117,121,130,350,218,209,213,
			 372,367,147,50,139,143,152,394,240,231,235,416,411,
			 169,52,161,165,174,438,262,253,257,460,447,86,451,455,72};}


Point(201) = { bin/2, Lin/2, -gap, p0};
Point(202) = { bin/2,-Lin/2, -gap, p0};
Point(203) = {-bin/2,-Lin/2, -gap, p0};
Point(204) = {-bin/2, Lin/2, -gap, p0};

Line(404) = {204,201};
Line(405) = {201,202};
Line(406) = {202,203};
Line(407) = {203,204};

p_widthD = 10 ;//14
p_heightD = 20 ;//24

Transfinite Line {404,406} = p_widthD ;
Transfinite Line {405,407} = p_heightD ;


Line Loop(461) = {404,405,406,407};
Plane Surface(462) = {461};

Transfinite Surface {462} = {204,201,202,203} ;

nl2 = 1 ;
vol[] = Extrude Surface { 462, {0,0,-td}} { Layers { {nl2}, {1}} ; };;
volDiel = vol[1];

Diel = 2000 ;
Physical Volume (Diel) = {volDiel};

Sur_Diel = 2001 ;
Physical Surface (Sur_Diel) = {-1128,-462,-1120,-1124,-1132};


//Color Coral {Surface{1128,462,1120,1124,1132}; }


vol[] = Extrude Surface {1133, {0,0,-tin}} { Layers { {nl2}, {1}} ; };;
volPlateIN = vol[1];

PlateIN = 2200 ;
Physical Volume (PlateIN) = {volPlateIN};

Sur_PlateIN = 2222;
Physical Surface (Sur_PlateIN) = {1133,2010,2014,2018,2022,-2023};

Color NavyBlue{Surface{1133,2010,2014,2018,2022,2023};}

//Coherence ;


If(FEM)
// Air Layer for computation with FEM
da = gap/4 ;

Point(281) = { bc/2+Lb+da, Lc/2+da, d+da, p0};
Point(282) = { bc/2+Lb+da,-Lc/2-da, d+da, p0};
Point(283) = {-bc/2-Lb-da,-Lc/2-da, d+da, p0};
Point(284) = {-bc/2-Lb-da, Lc/2+da, d+da, p0};
Point(285) = { bc/2+Lb+da, Lc/2+da, -da, p0};
Point(286) = { bc/2+Lb+da,-Lc/2-da, -da, p0};
Point(287) = {-bc/2-Lb-da,-Lc/2-da, -da, p0};
Point(288) = {-bc/2-Lb-da, Lc/2+da, -da, p0};

Line(451) = {284,281};
Line(452) = {281,282};
Line(453) = {282,283};
Line(454) = {283,284};
Line(455) = {288,285};
Line(456) = {285,286};
Line(457) = {286,287};
Line(458) = {287,288};
Line(459) = {288,284};
Line(460) = {285,281};
Line(461) = {286,282};
Line(462) = {287,283};

Line Loop(500) = {454,451,452,453};
Plane Surface(501) = {500};
Line Loop(502) = {455,456,457,458};
Plane Surface(503) = {502};
Line Loop(504) = {460,-451,-459,455};
Plane Surface(505) = {504};
Line Loop(506) = {461,-452,-460,456};
Plane Surface(507) = {506};
Line Loop(508) = {-453,-461,457,462};
Plane Surface(509) = {508};
Line Loop(510) = {-454,-462,458,459};
Plane Surface(511) = {510};


Surface Loop(512) = {511,501,505,507,509,503};

Surface Loop(513) = {261,60,84,82,403,239,58,80,78,359,217,56,76,74,315,
		     183,54,187,191,271,70,275,279,103,46,95,99,108,306,
		     196,284,328,323,125,48,117,121,130,350,218,209,213,
		     372,367,147,50,139,143,152,394,240,231,235,416,411,
		     169,52,161,165,174,438,262,253,257,460,447,86,451,455,72};
Volume(514) = {512,513};

AirLayer = 555 ;
Physical Volume (AirLayer) = {514};

//Shell
Point(0) = {0,0,0,lcs1} ;
Point(289) = {R1,0,0,lcs1} ;
Point(290) = {0,R1,0,lcs1} ;
Point(291) = {-R1,0,0,lcs1} ;
Point(292) = {0,-R1,0,lcs1} ;

Point(293) = {R2,0,0,lcs2} ;
Point(294) = {0,R2,0,lcs2} ;
Point(295) = {0,-R2,0,lcs2} ;
Point(296) = {-R2,0,0,lcs2} ;

Point(297) = {0,0,R1,lcs1} ;
Point(298) = {0,0,-R1,lcs1} ;
Point(299) = {0,0,R2,lcs2} ;
Point(300) = {0,0,-R2,lcs2} ;


Circle(2223) = {291,0,292};
Circle(2224) = {292,0,289};
Circle(2225) = {289,0,290};
Circle(2226) = {290,0,291};
Circle(2227) = {297,0,292};
Circle(2228) = {297,0,289};
Circle(2229) = {297,0,290};
Circle(2230) = {297,0,291};
Circle(2231) = {291,0,298};
Circle(2232) = {298,0,292};
Circle(2233) = {289,0,298};
Circle(2234) = {290,0,298};

Circle(2235) = {295,0,293};
Circle(2236) = {293,0,294};
Circle(2237) = {294,0,296};
Circle(2238) = {296,0,295};
Circle(2239) = {295,0,299};
Circle(2240) = {293,0,299};
Circle(2241) = {294,0,299};
Circle(2242) = {296,0,299};
Circle(2243) = {295,0,300};
Circle(2244) = {293,0,300};
Circle(2245) = {294,0,300};
Circle(2246) = {296,0,300};

Line Loop(2247) = {-2228,2227,2224};
Ruled Surface(2248) = {2247};
Line Loop(2249) = {-2225,-2228,2229};
Ruled Surface(2250) = {2249};
Line Loop(2251) = {-2226,-2229,2230};
Ruled Surface(2252) = {2251};
Line Loop(2253) = {-2227,2230,2223};
Ruled Surface(2254) = {2253};
Line Loop(2255) = {2224,2233,2232};
Ruled Surface(2256) = {2255};
Line Loop(2257) = {-2233,2225,2234};
Ruled Surface(2258) = {2257};
Line Loop(2259) = {-2234,2226,2231};
Ruled Surface(2260) = {2259};
Line Loop(2261) = {-2223,2231,2232};
Ruled Surface(2262) = {2261};

Line Loop(2263) = {-2239,2235,2240};
Ruled Surface(2264) = {2263};
Line Loop(2265) = {-2240,2236,2241};
Ruled Surface(2266) = {2265};
Line Loop(2267) = {-2241,2237,2242};
Ruled Surface(2268) = {2267};
Line Loop(2269) = {-2242,2238,2239};
Ruled Surface(2270) = {2269};
Line Loop(2271) = {-2243,2235,2244};
Ruled Surface(2272) = {2271};
Line Loop(2273) = {-2244,2236,2245};
Ruled Surface(2274) = {2273};
Line Loop(2275) = {-2245,2237,2246};
Ruled Surface(2276) = {2275};
Line Loop(2277) = {-2246,2238,2243};
Ruled Surface(2278) = {2277};

Surface Loop(2279) = {2266,2264,2270,2268,2276,2274,2272,2278};
Surface Loop(2280) = {2250,2258,2256,2248,2254,2252,2260,2262};
Volume(2281) = {2279,2280};


Shell = 3000 ;
Physical Volume (Shell) ={2281};


Surface Loop(2282) = {1120,462,1124,1128,1132,2022,2010,2014,2018,2023};

Volume(2283) = {2280,2282,512};

Air = 1000 ;
Physical Volume (Air) = {2283};

EndIf

