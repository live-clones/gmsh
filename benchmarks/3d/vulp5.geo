/* Antenne VULP 9118-E */

Frequence = 235.e6 ;
Lambda = 2.99792458e8/Frequence ;
LambdaDemi = Lambda/2 ;

f1 = 10.e-3 ;

si = 50.e-3 ;
si1= 20.e-3 ;
si2= 100.e-3 ;
se = 300.e-3 ;

/* 2 longerons */

xmin =-27.e-3 ;
LL   = 1821.3e-3 ; 
ll   = 20.e-3 ; 
hh   = 20.e-3 ;
dc   = 8.e-3 ;
em   = 8.e-3/2 ; 
eM   = 40.e-3/2 ;
t    = ArcTan(eM/2-em/2/LL) ;

/* 22 barreaux */
/* longueur           ; rayon          ; dist % barreau 1       ; dist%y=0  */                  
 l1 =   77.e-3/2-ll/2 ;  r1 =  8.e-3/2 ;  d1 =   0              ;  e1 = em+dc+d1*Sin(t)-2.e-3 ;
 l2 =   91.e-3/2-ll/2 ;  r2 =  8.e-3/2 ;  d2 =   11.9e-3*Cos(t) ;  e2 = em+dc+d2*Sin(t)-2.e-3 ;
 l3 =  105.e-3/2-ll/2 ;  r3 =  8.e-3/2 ;  d3 =   25.8e-3*Cos(t) ;  e3 = em+dc+d3*Sin(t)-2.e-3 ;
 l4 =  122.e-3/2-ll/2 ;  r4 =  8.e-3/2 ;  d4 =   41.8e-3*Cos(t) ;  e4 = em+dc+d4*Sin(t)-2.e-3 ;
 l5 =  142.e-3/2-ll/2 ;  r5 = 10.e-3/2 ;  d5 =   60.5e-3*Cos(t) ;  e5 = em+dc+d5*Sin(t)-1.e-3 ;
 l6 =  164.e-3/2-ll/2 ;  r6 = 10.e-3/2 ;  d6 =   82.5e-3*Cos(t) ;  e6 = em+dc+d6*Sin(t)-1.e-3 ;
 l7 =  192.e-3/2-ll/2 ;  r7 = 12.e-3/2 ;  d7 =  107.0e-3*Cos(t) ;  e7 = em+dc+d7*Sin(t)  ;      
 l8 =  224.e-3/2-ll/2 ;  r8 = 12.e-3/2 ;  d8 =  138.5e-3*Cos(t) ;  e8 = em+dc+d8*Sin(t)  ;      
 l9 =  260.e-3/2-ll/2 ;  r9 = 12.e-3/2 ;  d9 =  172.0e-3*Cos(t) ;  e9 = em+dc+d9*Sin(t)  ;      
l10 =  303.e-3/2-ll/2 ; r10 = 12.e-3/2 ; d10 =  212.0e-3*Cos(t) ; e10 = em+dc+d10*Sin(t) ;      
l11 =  353.e-3/2-ll/2 ; r11 = 12.e-3/2 ; d11 =  258.5e-3*Cos(t) ; e11 = em+dc+d11*Sin(t) ;      
l12 =  410.e-3/2-ll/2 ; r12 = 12.e-3/2 ; d12 =  312.5e-3*Cos(t) ; e12 = em+dc+d12*Sin(t) ;      
l13 =  477.e-3/2-ll/2 ; r13 = 12.e-3/2 ; d13 =  375.0e-3*Cos(t) ; e13 = em+dc+d13*Sin(t) ;      
l14 =  554.e-3/2-ll/2 ; r14 = 12.e-3/2 ; d14 =  448.5e-3*Cos(t) ; e14 = em+dc+d14*Sin(t) ;      
l15 =  645.e-3/2-ll/2 ; r15 = 12.e-3/2 ; d15 =  533.0e-3*Cos(t) ; e15 = em+dc+d15*Sin(t) ;      
l16 =  749.e-3/2-ll/2 ; r16 = 12.e-3/2 ; d16 =  632.5e-3*Cos(t) ; e16 = em+dc+d16*Sin(t) ;      
l17 =  877.e-3/2-ll/2 ; r17 = 12.e-3/2 ; d17 =  750.5e-3*Cos(t) ; e17 = em+dc+d17*Sin(t) ;      
l18 = 1023.e-3/2-ll/2 ; r18 = 12.e-3/2 ; d18 =  888.0e-3*Cos(t) ; e18 = em+dc+d18*Sin(t) ;      
l19 = 1196.e-3/2-ll/2 ; r19 = 12.e-3/2 ; d19 = 1050.3e-3*Cos(t) ; e19 = em+dc+d19*Sin(t) ;      
l20 = 1404.e-3/2-ll/2 ; r20 = 12.e-3/2 ; d20 = 1241.7e-3*Cos(t) ; e20 = em+dc+d20*Sin(t) ;      
l21 = 1648.e-3/2-ll/2 ; r21 = 12.e-3/2 ; d21 = 1467.7e-3*Cos(t) ; e21 = em+dc+d21*Sin(t) ;      
l22 = 1934.e-3/2-ll/2 ; r22 = 12.e-3/2 ; d22 = 1734.3e-3*Cos(t) ; e22 = em+dc+d22*Sin(t) ;      

/* long caract */          
 s1 = f1 ;      s1l = f1 ;       
 s2 = f1 ;      s2l = f1 ;       
 s3 = f1 ;      s3l = f1 ;       
 s4 = f1 ;      s4l = f1 ;       
 s5 = f1 ;      s5l = f1 ;       
 s6 = f1 ;      s6l = f1 ;       
 s7 = f1 ;      s7l = f1 ;       
 s8 = f1 ;      s8l = f1 ;       
 s9 = f1 ;      s9l = f1 ;       
s10 = f1 ;     s10l = f1 ;       
s11 = f1 ;     s11l = f1 ;       
s12 = f1 ;     s12l = f1 ;       
s13 = f1 ;     s13l = f1 ;       
s14 = f1 ;     s14l = 1.3*f1 ;   
s15 = f1 ;     s15l = 1.6*f1 ;   
s16 = 1.1*f1 ; s16l = 2*f1 ;   
s17 = 1.4*f1 ; s17l = 2.3*f1 ;     
s18 = 1.6*f1 ; s18l = 2.6*f1 ; 
s19 = 1.8*f1 ; s19l = 3*f1 ; 
s20 = 2.0*f1 ; s20l = 3.3*f1 ;   
s21 = 2.2*f1 ; s21l = 3.6*f1 ; 
s22 = 2.4*f1 ; s22l = 4*f1 ;   

Point(9998) = {d11, 0, -l15, 1} ;

/* boite */

abs = LambdaDemi ;
bem = 2*si ;

bxM =  -200.e-3 ; bxm = bxM+bem ; bxP = 2000.e-3 ; bxp = bxP-bem ;
byM =  -150.e-3 ; bym = byM+bem ; byP =  150.e-3 ; byp = byP-bem ;
bzM = -1200.e-3 ; bzm = bzM+bem ; bzP = 1200.e-3 ; bzp = bzP-bem ;

bxM2 = bxM-abs ; bxP2 = bxP+abs ; 
byM2 = byM-abs ; byP2 = byP+abs ; 
bzM2 = bzM-abs ; bzP2 = bzP+abs ; 

/* longerons */

Point(1) = {xmin, -em-hh, -ll/2, f1} ; Point(5) = {xmin, em, -ll/2, f1/3} ; 
Point(2) = {xmin, -em-hh,  ll/2, f1} ; Point(6) = {xmin, em,  ll/2, f1/3} ; 
Point(3) = {xmin, -em,    -ll/2, f1/3} ; Point(7) = {xmin, em+hh, -ll/2, f1} ; 
Point(4) = {xmin, -em,     ll/2, f1/3} ; Point(8) = {xmin, em+hh,  ll/2, f1} ; 

f3 = s22/1.2 ;

Point(9)  = {xmin+LL, -eM-hh, -ll/2, f3} ; Point(13) = {xmin+LL, eM, -ll/2, f3} ; 
Point(10) = {xmin+LL, -eM-hh,  ll/2, f3} ; Point(14) = {xmin+LL, eM,  ll/2, f3} ; 
Point(11) = {xmin+LL, -eM,    -ll/2, f3} ; Point(15) = {xmin+LL, eM+hh, -ll/2, f3} ; 
Point(12) = {xmin+LL, -eM,     ll/2, f3} ; Point(16) = {xmin+LL, eM+hh,  ll/2, f3} ; 

Line(1) = {5,6};  Line(11) = {13,14};
Line(2) = {6,8};  Line(12) = {14,16};
Line(3) = {8,7};  Line(13) = {16,15};
Line(4) = {7,5};  Line(14) = {15,13};
Line(5) = {1,2};  Line(15) = {9,10}; 
Line(6) = {2,4};  Line(16) = {10,12};
Line(7) = {4,3};  Line(17) = {12,11};
Line(8) = {3,1};  Line(18) = {11,9}; 
Line(9) = {4,6};  Line(19) = {12,14};
Line(10) = {3,5}; Line(20) = {11,13};

Line(21) = {8,16}; Line(25) = {2,10}; 
Line(22) = {7,15}; Line(26) = {4,12}; 
Line(23) = {6,14}; Line(27) = {3,11}; 
Line(24) = {5,13}; Line(28) = {1,9};  

/* boite */

Point(51) = {bxm, bym, bzm, si1}; Point(61) = {bxM, byM, bzM, si2}; 
Point(52) = {bxm, bym, bzp, si1}; Point(62) = {bxM, byM, bzP, si2}; 
Point(53) = {bxm, byp, bzm, si1}; Point(63) = {bxM, byP, bzM, si2}; 
Point(54) = {bxm, byp, bzp, si1}; Point(64) = {bxM, byP, bzP, si2}; 
Point(55) = {bxp, bym, bzm, si}; Point(65) = {bxP, byM, bzM, si2}; 
Point(56) = {bxp, bym, bzp, si}; Point(66) = {bxP, byM, bzP, si2}; 
Point(57) = {bxp, byp, bzm, si}; Point(67) = {bxP, byP, bzM, si2}; 
Point(58) = {bxp, byp, bzp, si}; Point(68) = {bxP, byP, bzP, si2}; 

Line(51) = {51,52}; Line(59) = {52,54}; Line(67) = {54,53}; Line(75) = {53,51}; 
Line(52) = {52,56}; Line(60) = {56,58}; Line(68) = {58,54}; Line(76) = {51,55}; 
Line(53) = {55,57}; Line(61) = {57,53}; Line(69) = {55,56}; Line(77) = {58,57}; 
Line(54) = {53,63}; Line(62) = {51,61}; Line(70) = {54,64}; Line(78) = {52,62}; 
Line(55) = {62,61}; Line(63) = {61,63}; Line(71) = {63,64}; Line(79) = {64,62}; 
Line(56) = {57,67}; Line(64) = {55,65}; Line(72) = {65,67}; Line(80) = {67,63}; 
Line(57) = {61,65}; Line(65) = {58,68}; Line(73) = {56,66}; Line(81) = {66,65}; 
Line(58) = {68,67}; Line(66) = {68,66}; Line(74) = {66,62}; Line(82) = {64,68}; 

Point(70) = {bxM2, byM2, bzM2, se}; Point(71) = {bxM2, byM2, bzP2, se};
Point(72) = {bxM2, byP2, bzM2, se}; Point(73) = {bxM2, byP2, bzP2, se};
Point(74) = {bxP2, byM2, bzM2, se}; Point(75) = {bxP2, byM2, bzP2, se};
Point(76) = {bxP2, byP2, bzM2, se}; Point(77) = {bxP2, byP2, bzP2, se};

Line(7001) = {70,71}; Line(7002) = {71,73}; Line(7003) = {73,72}; Line(7004) = {72,70};
Line(7005) = {71,75}; Line(7006) = {75,77}; Line(7007) = {77,73}; Line(7008) = {74,75};
Line(7009) = {74,76}; Line(7010) = {76,77}; Line(7011) = {76,72}; Line(7012) = {74,70};
Line(7013) = {63,72}; Line(7014) = {61,70}; Line(7015) = {62,71}; Line(7016) = {64,73};
Line(7017) = {68,77}; Line(7018) = {66,75}; Line(7019) = {67,76}; Line(7020) = {65,74};

/* barreau 1 et 1' (le + a gauche, i.e. en x==0) */

Point(101) = {d1,    -e1,    -ll/2,    s1};  Point(111) = {d1,     e1,     ll/2,    s1}; 
Point(102) = {d1+r1, -e1,    -ll/2,    s1};  Point(112) = {d1+r1,  e1,     ll/2,    s1}; 
Point(103) = {d1,    -e1+r1, -ll/2,    s1};  Point(113) = {d1,     e1+r1,  ll/2,    s1}; 
Point(104) = {d1-r1, -e1,    -ll/2,    s1};  Point(114) = {d1-r1,  e1,     ll/2,    s1}; 
Point(105) = {d1,    -e1-r1, -ll/2,    s1};  Point(115) = {d1,     e1-r1,  ll/2,    s1}; 
Point(106) = {d1,    -e1,    -ll/2-l1, s1l};  Point(116) = {d1,     e1,     ll/2+l1, s1l}; 
Point(107) = {d1+r1, -e1,    -ll/2-l1, s1l};  Point(117) = {d1+r1,  e1,     ll/2+l1, s1l}; 
Point(108) = {d1,    -e1+r1, -ll/2-l1, s1l};  Point(118) = {d1,     e1+r1,  ll/2+l1, s1l}; 
Point(109) = {d1-r1, -e1,    -ll/2-l1, s1l};  Point(119) = {d1-r1,  e1,     ll/2+l1, s1l}; 
Point(110) = {d1,    -e1-r1, -ll/2-l1, s1l};  Point(120) = {d1,     e1-r1,  ll/2+l1, s1l}; 

Circle(101) = {102,101,103}; Circle(105) = {107,106,108}; Line(109) = {102,107};
Circle(102) = {103,101,104}; Circle(106) = {108,106,109}; Line(110) = {103,108};
Circle(103) = {104,101,105}; Circle(107) = {109,106,110}; Line(111) = {104,109};
Circle(104) = {105,101,102}; Circle(108) = {110,106,107}; Line(112) = {105,110};

Circle(113) = {112,111,113}; Circle(117) = {117,116,118}; Line(121) = {112,117};
Circle(114) = {113,111,114}; Circle(118) = {118,116,119}; Line(122) = {113,118};
Circle(115) = {114,111,115}; Circle(119) = {119,116,120}; Line(123) = {114,119};
Circle(116) = {115,111,112}; Circle(120) = {120,116,117}; Line(124) = {115,120};

Line Loop(101) = {102,103,104,101};   Plane Surface(121) = {101};
Line Loop(102) = {107,108,105,106};   Plane Surface(122) = {102};
Line Loop(103) = {116,113,114,115};   Plane Surface(123) = {103};
Line Loop(104) = {120,117,118,119};   Plane Surface(124) = {104};
Line Loop(105) = {108,-109,-104,112}; Ruled Surface(125) = {105};
Line Loop(106) = {112,-107,-111,103}; Ruled Surface(126) = {106};
Line Loop(107) = {-111,-102,110,106}; Ruled Surface(127) = {107};
Line Loop(108) = {-110,-101,109,105}; Ruled Surface(128) = {108};
Line Loop(109) = {121,-120,-124,116}; Ruled Surface(129) = {109};
Line Loop(110) = {-124,-115,123,119}; Ruled Surface(130) = {110};
Line Loop(111) = {123,-118,-122,114}; Ruled Surface(131) = {111};
Line Loop(112) = {122,-117,-121,113}; Ruled Surface(132) = {112};

/* barreau 2 et 2' */

Point(201) = {d2,    e2,    -ll/2,    s2};  Point(211) = {d2,     -e2,     ll/2,    s2}; 
Point(202) = {d2+r2, e2,    -ll/2,    s2};  Point(212) = {d2+r2,  -e2,     ll/2,    s2}; 
Point(203) = {d2,    e2+r2, -ll/2,    s2};  Point(213) = {d2,     -e2+r2,  ll/2,    s2}; 
Point(204) = {d2-r2, e2,    -ll/2,    s2};  Point(214) = {d2-r2,  -e2,     ll/2,    s2}; 
Point(205) = {d2,    e2-r2, -ll/2,    s2};  Point(215) = {d2,     -e2-r2,  ll/2,    s2}; 
Point(206) = {d2,    e2,    -ll/2-l2, s2l};  Point(216) = {d2,     -e2,     ll/2+l2, s2l}; 
Point(207) = {d2+r2, e2,    -ll/2-l2, s2l};  Point(217) = {d2+r2,  -e2,     ll/2+l2, s2l}; 
Point(208) = {d2,    e2+r2, -ll/2-l2, s2l};  Point(218) = {d2,     -e2+r2,  ll/2+l2, s2l}; 
Point(209) = {d2-r2, e2,    -ll/2-l2, s2l};  Point(219) = {d2-r2,  -e2,     ll/2+l2, s2l}; 
Point(210) = {d2,    e2-r2, -ll/2-l2, s2l};  Point(220) = {d2,     -e2-r2,  ll/2+l2, s2l}; 

Circle(201) = {202,201,203}; Circle(205) = {207,206,208}; Line(209) = {202,207};
Circle(202) = {203,201,204}; Circle(206) = {208,206,209}; Line(210) = {203,208};
Circle(203) = {204,201,205}; Circle(207) = {209,206,210}; Line(211) = {204,209};
Circle(204) = {205,201,202}; Circle(208) = {210,206,207}; Line(212) = {205,210};

Circle(213) = {212,211,213}; Circle(217) = {217,216,218}; Line(221) = {212,217};
Circle(214) = {213,211,214}; Circle(218) = {218,216,219}; Line(222) = {213,218};
Circle(215) = {214,211,215}; Circle(219) = {219,216,220}; Line(223) = {214,219};
Circle(216) = {215,211,212}; Circle(220) = {220,216,217}; Line(224) = {215,220};

Line Loop(201) = {202,203,204,201};   Plane Surface(221) = {201};
Line Loop(202) = {207,208,205,206};   Plane Surface(222) = {202};
Line Loop(203) = {216,213,214,215};   Plane Surface(223) = {203};
Line Loop(204) = {220,217,218,219};   Plane Surface(224) = {204};
Line Loop(205) = {208,-209,-204,212}; Ruled Surface(225) = {205};
Line Loop(206) = {212,-207,-211,203}; Ruled Surface(226) = {206};
Line Loop(207) = {-211,-202,210,206}; Ruled Surface(227) = {207};
Line Loop(208) = {-210,-201,209,205}; Ruled Surface(228) = {208};
Line Loop(209) = {221,-220,-224,216}; Ruled Surface(229) = {209};
Line Loop(210) = {-224,-215,223,219}; Ruled Surface(230) = {210};
Line Loop(211) = {223,-218,-222,214}; Ruled Surface(231) = {211};
Line Loop(212) = {222,-217,-221,213}; Ruled Surface(232) = {212};

/* barreau 3 et 3' */

Point(301) = {d3,    -e3,    -ll/2,    s3};  Point(311) = {d3,     e3,     ll/2,    s3}; 
Point(302) = {d3+r3, -e3,    -ll/2,    s3};  Point(312) = {d3+r3,  e3,     ll/2,    s3}; 
Point(303) = {d3,    -e3+r3, -ll/2,    s3};  Point(313) = {d3,     e3+r3,  ll/2,    s3}; 
Point(304) = {d3-r3, -e3,    -ll/2,    s3};  Point(314) = {d3-r3,  e3,     ll/2,    s3}; 
Point(305) = {d3,    -e3-r3, -ll/2,    s3};  Point(315) = {d3,     e3-r3,  ll/2,    s3}; 
Point(306) = {d3,    -e3,    -ll/2-l3, s3l};  Point(316) = {d3,     e3,     ll/2+l3, s3l}; 
Point(307) = {d3+r3, -e3,    -ll/2-l3, s3l};  Point(317) = {d3+r3,  e3,     ll/2+l3, s3l}; 
Point(308) = {d3,    -e3+r3, -ll/2-l3, s3l};  Point(318) = {d3,     e3+r3,  ll/2+l3, s3l}; 
Point(309) = {d3-r3, -e3,    -ll/2-l3, s3l};  Point(319) = {d3-r3,  e3,     ll/2+l3, s3l}; 
Point(310) = {d3,    -e3-r3, -ll/2-l3, s3l};  Point(320) = {d3,     e3-r3,  ll/2+l3, s3l}; 

Circle(301) = {302,301,303}; Circle(305) = {307,306,308}; Line(309) = {302,307};
Circle(302) = {303,301,304}; Circle(306) = {308,306,309}; Line(310) = {303,308};
Circle(303) = {304,301,305}; Circle(307) = {309,306,310}; Line(311) = {304,309};
Circle(304) = {305,301,302}; Circle(308) = {310,306,307}; Line(312) = {305,310};

Circle(313) = {312,311,313}; Circle(317) = {317,316,318}; Line(321) = {312,317};
Circle(314) = {313,311,314}; Circle(318) = {318,316,319}; Line(322) = {313,318};
Circle(315) = {314,311,315}; Circle(319) = {319,316,320}; Line(323) = {314,319};
Circle(316) = {315,311,312}; Circle(320) = {320,316,317}; Line(324) = {315,320};

Line Loop(301) = {302,303,304,301};   Plane Surface(321) = {301};
Line Loop(302) = {307,308,305,306};   Plane Surface(322) = {302};
Line Loop(303) = {316,313,314,315};   Plane Surface(323) = {303};
Line Loop(304) = {320,317,318,319};   Plane Surface(324) = {304};
Line Loop(305) = {308,-309,-304,312}; Ruled Surface(325) = {305};
Line Loop(306) = {312,-307,-311,303}; Ruled Surface(326) = {306};
Line Loop(307) = {-311,-302,310,306}; Ruled Surface(327) = {307};
Line Loop(308) = {-310,-301,309,305}; Ruled Surface(328) = {308};
Line Loop(309) = {321,-320,-324,316}; Ruled Surface(329) = {309};
Line Loop(310) = {-324,-315,323,319}; Ruled Surface(330) = {310};
Line Loop(311) = {323,-318,-322,314}; Ruled Surface(331) = {311};
Line Loop(312) = {322,-317,-321,313}; Ruled Surface(332) = {312};

/* barreau 4 et 4' */

Point(401) = {d4,    e4,    -ll/2,    s4};  Point(411) = {d4,     -e4,     ll/2,    s4}; 
Point(402) = {d4+r4, e4,    -ll/2,    s4};  Point(412) = {d4+r4,  -e4,     ll/2,    s4}; 
Point(403) = {d4,    e4+r4, -ll/2,    s4};  Point(413) = {d4,     -e4+r4,  ll/2,    s4}; 
Point(404) = {d4-r4, e4,    -ll/2,    s4};  Point(414) = {d4-r4,  -e4,     ll/2,    s4}; 
Point(405) = {d4,    e4-r4, -ll/2,    s4};  Point(415) = {d4,     -e4-r4,  ll/2,    s4}; 
Point(406) = {d4,    e4,    -ll/2-l4, s4l};  Point(416) = {d4,     -e4,     ll/2+l4, s4l}; 
Point(407) = {d4+r4, e4,    -ll/2-l4, s4l};  Point(417) = {d4+r4,  -e4,     ll/2+l4, s4l}; 
Point(408) = {d4,    e4+r4, -ll/2-l4, s4l};  Point(418) = {d4,     -e4+r4,  ll/2+l4, s4l}; 
Point(409) = {d4-r4, e4,    -ll/2-l4, s4l};  Point(419) = {d4-r4,  -e4,     ll/2+l4, s4l}; 
Point(410) = {d4,    e4-r4, -ll/2-l4, s4l};  Point(420) = {d4,     -e4-r4,  ll/2+l4, s4l}; 

Circle(401) = {402,401,403}; Circle(405) = {407,406,408}; Line(409) = {402,407};
Circle(402) = {403,401,404}; Circle(406) = {408,406,409}; Line(410) = {403,408};
Circle(403) = {404,401,405}; Circle(407) = {409,406,410}; Line(411) = {404,409};
Circle(404) = {405,401,402}; Circle(408) = {410,406,407}; Line(412) = {405,410};

Circle(413) = {412,411,413}; Circle(417) = {417,416,418}; Line(421) = {412,417};
Circle(414) = {413,411,414}; Circle(418) = {418,416,419}; Line(422) = {413,418};
Circle(415) = {414,411,415}; Circle(419) = {419,416,420}; Line(423) = {414,419};
Circle(416) = {415,411,412}; Circle(420) = {420,416,417}; Line(424) = {415,420};

Line Loop(401) = {402,403,404,401};   Plane Surface(421) = {401};
Line Loop(402) = {407,408,405,406};   Plane Surface(422) = {402};
Line Loop(403) = {416,413,414,415};   Plane Surface(423) = {403};
Line Loop(404) = {420,417,418,419};   Plane Surface(424) = {404};
Line Loop(405) = {408,-409,-404,412}; Ruled Surface(425) = {405};
Line Loop(406) = {412,-407,-411,403}; Ruled Surface(426) = {406};
Line Loop(407) = {-411,-402,410,406}; Ruled Surface(427) = {407};
Line Loop(408) = {-410,-401,409,405}; Ruled Surface(428) = {408};
Line Loop(409) = {421,-420,-424,416}; Ruled Surface(429) = {409};
Line Loop(410) = {-424,-415,423,419}; Ruled Surface(430) = {410};
Line Loop(411) = {423,-418,-422,414}; Ruled Surface(431) = {411};
Line Loop(412) = {422,-417,-421,413}; Ruled Surface(432) = {412};

/* barreau 5 et 5' */

Point(501) = {d5,    -e5,    -ll/2,    s5};  Point(511) = {d5,     e5,     ll/2,    s5}; 
Point(502) = {d5+r5, -e5,    -ll/2,    s5};  Point(512) = {d5+r5,  e5,     ll/2,    s5}; 
Point(503) = {d5,    -e5+r5, -ll/2,    s5};  Point(513) = {d5,     e5+r5,  ll/2,    s5}; 
Point(504) = {d5-r5, -e5,    -ll/2,    s5};  Point(514) = {d5-r5,  e5,     ll/2,    s5}; 
Point(505) = {d5,    -e5-r5, -ll/2,    s5};  Point(515) = {d5,     e5-r5,  ll/2,    s5}; 
Point(506) = {d5,    -e5,    -ll/2-l5, s5l};  Point(516) = {d5,     e5,     ll/2+l5, s5l}; 
Point(507) = {d5+r5, -e5,    -ll/2-l5, s5l};  Point(517) = {d5+r5,  e5,     ll/2+l5, s5l}; 
Point(508) = {d5,    -e5+r5, -ll/2-l5, s5l};  Point(518) = {d5,     e5+r5,  ll/2+l5, s5l}; 
Point(509) = {d5-r5, -e5,    -ll/2-l5, s5l};  Point(519) = {d5-r5,  e5,     ll/2+l5, s5l}; 
Point(510) = {d5,    -e5-r5, -ll/2-l5, s5l};  Point(520) = {d5,     e5-r5,  ll/2+l5, s5l}; 

Circle(501) = {502,501,503}; Circle(505) = {507,506,508}; Line(509) = {502,507};
Circle(502) = {503,501,504}; Circle(506) = {508,506,509}; Line(510) = {503,508};
Circle(503) = {504,501,505}; Circle(507) = {509,506,510}; Line(511) = {504,509};
Circle(504) = {505,501,502}; Circle(508) = {510,506,507}; Line(512) = {505,510};

Circle(513) = {512,511,513}; Circle(517) = {517,516,518}; Line(521) = {512,517};
Circle(514) = {513,511,514}; Circle(518) = {518,516,519}; Line(522) = {513,518};
Circle(515) = {514,511,515}; Circle(519) = {519,516,520}; Line(523) = {514,519};
Circle(516) = {515,511,512}; Circle(520) = {520,516,517}; Line(524) = {515,520};

Line Loop(501) = {502,503,504,501};   Plane Surface(521) = {501};
Line Loop(502) = {507,508,505,506};   Plane Surface(522) = {502};
Line Loop(503) = {516,513,514,515};   Plane Surface(523) = {503};
Line Loop(504) = {520,517,518,519};   Plane Surface(524) = {504};
Line Loop(505) = {508,-509,-504,512}; Ruled Surface(525) = {505};
Line Loop(506) = {512,-507,-511,503}; Ruled Surface(526) = {506};
Line Loop(507) = {-511,-502,510,506}; Ruled Surface(527) = {507};
Line Loop(508) = {-510,-501,509,505}; Ruled Surface(528) = {508};
Line Loop(509) = {521,-520,-524,516}; Ruled Surface(529) = {509};
Line Loop(510) = {-524,-515,523,519}; Ruled Surface(530) = {510};
Line Loop(511) = {523,-518,-522,514}; Ruled Surface(531) = {511};
Line Loop(512) = {522,-517,-521,513}; Ruled Surface(532) = {512};

/* barreau 6 et 6' */

Point(601) = {d6,    e6,    -ll/2,    s6};  Point(611) = {d6,     -e6,     ll/2,    s6}; 
Point(602) = {d6+r6, e6,    -ll/2,    s6};  Point(612) = {d6+r6,  -e6,     ll/2,    s6}; 
Point(603) = {d6,    e6+r6, -ll/2,    s6};  Point(613) = {d6,     -e6+r6,  ll/2,    s6}; 
Point(604) = {d6-r6, e6,    -ll/2,    s6};  Point(614) = {d6-r6,  -e6,     ll/2,    s6}; 
Point(605) = {d6,    e6-r6, -ll/2,    s6};  Point(615) = {d6,     -e6-r6,  ll/2,    s6}; 
Point(606) = {d6,    e6,    -ll/2-l6, s6l};  Point(616) = {d6,     -e6,     ll/2+l6, s6l}; 
Point(607) = {d6+r6, e6,    -ll/2-l6, s6l};  Point(617) = {d6+r6,  -e6,     ll/2+l6, s6l}; 
Point(608) = {d6,    e6+r6, -ll/2-l6, s6l};  Point(618) = {d6,     -e6+r6,  ll/2+l6, s6l}; 
Point(609) = {d6-r6, e6,    -ll/2-l6, s6l};  Point(619) = {d6-r6,  -e6,     ll/2+l6, s6l}; 
Point(610) = {d6,    e6-r6, -ll/2-l6, s6l};  Point(620) = {d6,     -e6-r6,  ll/2+l6, s6l}; 

Circle(601) = {602,601,603}; Circle(605) = {607,606,608}; Line(609) = {602,607};
Circle(602) = {603,601,604}; Circle(606) = {608,606,609}; Line(610) = {603,608};
Circle(603) = {604,601,605}; Circle(607) = {609,606,610}; Line(611) = {604,609};
Circle(604) = {605,601,602}; Circle(608) = {610,606,607}; Line(612) = {605,610};

Circle(613) = {612,611,613}; Circle(617) = {617,616,618}; Line(621) = {612,617};
Circle(614) = {613,611,614}; Circle(618) = {618,616,619}; Line(622) = {613,618};
Circle(615) = {614,611,615}; Circle(619) = {619,616,620}; Line(623) = {614,619};
Circle(616) = {615,611,612}; Circle(620) = {620,616,617}; Line(624) = {615,620};

Line Loop(601) = {602,603,604,601};   Plane Surface(621) = {601};
Line Loop(602) = {607,608,605,606};   Plane Surface(622) = {602};
Line Loop(603) = {616,613,614,615};   Plane Surface(623) = {603};
Line Loop(604) = {620,617,618,619};   Plane Surface(624) = {604};
Line Loop(605) = {608,-609,-604,612}; Ruled Surface(625) = {605};
Line Loop(606) = {612,-607,-611,603}; Ruled Surface(626) = {606};
Line Loop(607) = {-611,-602,610,606}; Ruled Surface(627) = {607};
Line Loop(608) = {-610,-601,609,605}; Ruled Surface(628) = {608};
Line Loop(609) = {621,-620,-624,616}; Ruled Surface(629) = {609};
Line Loop(610) = {-624,-615,623,619}; Ruled Surface(630) = {610};
Line Loop(611) = {623,-618,-622,614}; Ruled Surface(631) = {611};
Line Loop(612) = {622,-617,-621,613}; Ruled Surface(632) = {612};

/* barreau 7 et 7' */

Point(701) = {d7,    -e7,    -ll/2,    s7};  Point(711) = {d7,     e7,     ll/2,    s7}; 
Point(702) = {d7+r7, -e7,    -ll/2,    s7};  Point(712) = {d7+r7,  e7,     ll/2,    s7}; 
Point(703) = {d7,    -e7+r7, -ll/2,    s7};  Point(713) = {d7,     e7+r7,  ll/2,    s7}; 
Point(704) = {d7-r7, -e7,    -ll/2,    s7};  Point(714) = {d7-r7,  e7,     ll/2,    s7}; 
Point(705) = {d7,    -e7-r7, -ll/2,    s7};  Point(715) = {d7,     e7-r7,  ll/2,    s7}; 
Point(706) = {d7,    -e7,    -ll/2-l7, s7l};  Point(716) = {d7,     e7,     ll/2+l7, s7l}; 
Point(707) = {d7+r7, -e7,    -ll/2-l7, s7l};  Point(717) = {d7+r7,  e7,     ll/2+l7, s7l}; 
Point(708) = {d7,    -e7+r7, -ll/2-l7, s7l};  Point(718) = {d7,     e7+r7,  ll/2+l7, s7l}; 
Point(709) = {d7-r7, -e7,    -ll/2-l7, s7l};  Point(719) = {d7-r7,  e7,     ll/2+l7, s7l}; 
Point(710) = {d7,    -e7-r7, -ll/2-l7, s7l};  Point(720) = {d7,     e7-r7,  ll/2+l7, s7l}; 

Circle(701) = {702,701,703}; Circle(705) = {707,706,708}; Line(709) = {702,707};
Circle(702) = {703,701,704}; Circle(706) = {708,706,709}; Line(710) = {703,708};
Circle(703) = {704,701,705}; Circle(707) = {709,706,710}; Line(711) = {704,709};
Circle(704) = {705,701,702}; Circle(708) = {710,706,707}; Line(712) = {705,710};

Circle(713) = {712,711,713}; Circle(717) = {717,716,718}; Line(721) = {712,717};
Circle(714) = {713,711,714}; Circle(718) = {718,716,719}; Line(722) = {713,718};
Circle(715) = {714,711,715}; Circle(719) = {719,716,720}; Line(723) = {714,719};
Circle(716) = {715,711,712}; Circle(720) = {720,716,717}; Line(724) = {715,720};

Line Loop(701) = {702,703,704,701};   Plane Surface(721) = {701};
Line Loop(702) = {707,708,705,706};   Plane Surface(722) = {702};
Line Loop(703) = {716,713,714,715};   Plane Surface(723) = {703};
Line Loop(704) = {720,717,718,719};   Plane Surface(724) = {704};
Line Loop(705) = {708,-709,-704,712}; Ruled Surface(725) = {705};
Line Loop(706) = {712,-707,-711,703}; Ruled Surface(726) = {706};
Line Loop(707) = {-711,-702,710,706}; Ruled Surface(727) = {707};
Line Loop(708) = {-710,-701,709,705}; Ruled Surface(728) = {708};
Line Loop(709) = {721,-720,-724,716}; Ruled Surface(729) = {709};
Line Loop(710) = {-724,-715,723,719}; Ruled Surface(730) = {710};
Line Loop(711) = {723,-718,-722,714}; Ruled Surface(731) = {711};
Line Loop(712) = {722,-717,-721,713}; Ruled Surface(732) = {712};

/* barreau 8 et 8' */

Point(801) = {d8,    e8,    -ll/2,    s8};  Point(811) = {d8,     -e8,     ll/2,    s8}; 
Point(802) = {d8+r8, e8,    -ll/2,    s8};  Point(812) = {d8+r8,  -e8,     ll/2,    s8}; 
Point(803) = {d8,    e8+r8, -ll/2,    s8};  Point(813) = {d8,     -e8+r8,  ll/2,    s8}; 
Point(804) = {d8-r8, e8,    -ll/2,    s8};  Point(814) = {d8-r8,  -e8,     ll/2,    s8}; 
Point(805) = {d8,    e8-r8, -ll/2,    s8};  Point(815) = {d8,     -e8-r8,  ll/2,    s8}; 
Point(806) = {d8,    e8,    -ll/2-l8, s8l};  Point(816) = {d8,     -e8,     ll/2+l8, s8l}; 
Point(807) = {d8+r8, e8,    -ll/2-l8, s8l};  Point(817) = {d8+r8,  -e8,     ll/2+l8, s8l}; 
Point(808) = {d8,    e8+r8, -ll/2-l8, s8l};  Point(818) = {d8,     -e8+r8,  ll/2+l8, s8l}; 
Point(809) = {d8-r8, e8,    -ll/2-l8, s8l};  Point(819) = {d8-r8,  -e8,     ll/2+l8, s8l}; 
Point(810) = {d8,    e8-r8, -ll/2-l8, s8l};  Point(820) = {d8,     -e8-r8,  ll/2+l8, s8l}; 

Circle(801) = {802,801,803}; Circle(805) = {807,806,808}; Line(809) = {802,807};
Circle(802) = {803,801,804}; Circle(806) = {808,806,809}; Line(810) = {803,808};
Circle(803) = {804,801,805}; Circle(807) = {809,806,810}; Line(811) = {804,809};
Circle(804) = {805,801,802}; Circle(808) = {810,806,807}; Line(812) = {805,810};

Circle(813) = {812,811,813}; Circle(817) = {817,816,818}; Line(821) = {812,817};
Circle(814) = {813,811,814}; Circle(818) = {818,816,819}; Line(822) = {813,818};
Circle(815) = {814,811,815}; Circle(819) = {819,816,820}; Line(823) = {814,819};
Circle(816) = {815,811,812}; Circle(820) = {820,816,817}; Line(824) = {815,820};

Line Loop(801) = {802,803,804,801};   Plane Surface(821) = {801};
Line Loop(802) = {807,808,805,806};   Plane Surface(822) = {802};
Line Loop(803) = {816,813,814,815};   Plane Surface(823) = {803};
Line Loop(804) = {820,817,818,819};   Plane Surface(824) = {804};
Line Loop(805) = {808,-809,-804,812}; Ruled Surface(825) = {805};
Line Loop(806) = {812,-807,-811,803}; Ruled Surface(826) = {806};
Line Loop(807) = {-811,-802,810,806}; Ruled Surface(827) = {807};
Line Loop(808) = {-810,-801,809,805}; Ruled Surface(828) = {808};
Line Loop(809) = {821,-820,-824,816}; Ruled Surface(829) = {809};
Line Loop(810) = {-824,-815,823,819}; Ruled Surface(830) = {810};
Line Loop(811) = {823,-818,-822,814}; Ruled Surface(831) = {811};
Line Loop(812) = {822,-817,-821,813}; Ruled Surface(832) = {812};

/* barreau 9 et 9' */

Point(901) = {d9,    -e9,    -ll/2,    s9};  Point(911) = {d9,     e9,     ll/2,    s9}; 
Point(902) = {d9+r9, -e9,    -ll/2,    s9};  Point(912) = {d9+r9,  e9,     ll/2,    s9}; 
Point(903) = {d9,    -e9+r9, -ll/2,    s9};  Point(913) = {d9,     e9+r9,  ll/2,    s9}; 
Point(904) = {d9-r9, -e9,    -ll/2,    s9};  Point(914) = {d9-r9,  e9,     ll/2,    s9}; 
Point(905) = {d9,    -e9-r9, -ll/2,    s9};  Point(915) = {d9,     e9-r9,  ll/2,    s9}; 
Point(906) = {d9,    -e9,    -ll/2-l9, s9l};  Point(916) = {d9,     e9,     ll/2+l9, s9l}; 
Point(907) = {d9+r9, -e9,    -ll/2-l9, s9l};  Point(917) = {d9+r9,  e9,     ll/2+l9, s9l}; 
Point(908) = {d9,    -e9+r9, -ll/2-l9, s9l};  Point(918) = {d9,     e9+r9,  ll/2+l9, s9l}; 
Point(909) = {d9-r9, -e9,    -ll/2-l9, s9l};  Point(919) = {d9-r9,  e9,     ll/2+l9, s9l}; 
Point(910) = {d9,    -e9-r9, -ll/2-l9, s9l};  Point(920) = {d9,     e9-r9,  ll/2+l9, s9l}; 

Circle(901) = {902,901,903}; Circle(905) = {907,906,908}; Line(909) = {902,907};
Circle(902) = {903,901,904}; Circle(906) = {908,906,909}; Line(910) = {903,908};
Circle(903) = {904,901,905}; Circle(907) = {909,906,910}; Line(911) = {904,909};
Circle(904) = {905,901,902}; Circle(908) = {910,906,907}; Line(912) = {905,910};

Circle(913) = {912,911,913}; Circle(917) = {917,916,918}; Line(921) = {912,917};
Circle(914) = {913,911,914}; Circle(918) = {918,916,919}; Line(922) = {913,918};
Circle(915) = {914,911,915}; Circle(919) = {919,916,920}; Line(923) = {914,919};
Circle(916) = {915,911,912}; Circle(920) = {920,916,917}; Line(924) = {915,920};

Line Loop(901) = {902,903,904,901};   Plane Surface(921) = {901};
Line Loop(902) = {907,908,905,906};   Plane Surface(922) = {902};
Line Loop(903) = {916,913,914,915};   Plane Surface(923) = {903};
Line Loop(904) = {920,917,918,919};   Plane Surface(924) = {904};
Line Loop(905) = {908,-909,-904,912}; Ruled Surface(925) = {905};
Line Loop(906) = {912,-907,-911,903}; Ruled Surface(926) = {906};
Line Loop(907) = {-911,-902,910,906}; Ruled Surface(927) = {907};
Line Loop(908) = {-910,-901,909,905}; Ruled Surface(928) = {908};
Line Loop(909) = {921,-920,-924,916}; Ruled Surface(929) = {909};
Line Loop(910) = {-924,-915,923,919}; Ruled Surface(930) = {910};
Line Loop(911) = {923,-918,-922,914}; Ruled Surface(931) = {911};
Line Loop(912) = {922,-917,-921,913}; Ruled Surface(932) = {912};

/* barreau 10 et 10' */

Point(1001) = {d10,    e10,    -ll/2,    s10};  Point(1011) = {d10,     -e10,     ll/2,    s10}; 
Point(1002) = {d10+r10, e10,    -ll/2,    s10};  Point(1012) = {d10+r10,  -e10,     ll/2,    s10}; 
Point(1003) = {d10,    e10+r10, -ll/2,    s10};  Point(1013) = {d10,     -e10+r10,  ll/2,    s10}; 
Point(1004) = {d10-r10, e10,    -ll/2,    s10};  Point(1014) = {d10-r10,  -e10,     ll/2,    s10}; 
Point(1005) = {d10,    e10-r10, -ll/2,    s10};  Point(1015) = {d10,     -e10-r10,  ll/2,    s10}; 
Point(1006) = {d10,    e10,    -ll/2-l10, s10l};  Point(1016) = {d10,     -e10,     ll/2+l10, s10l}; 
Point(1007) = {d10+r10, e10,    -ll/2-l10, s10l};  Point(1017) = {d10+r10,  -e10,     ll/2+l10, s10l}; 
Point(1008) = {d10,    e10+r10, -ll/2-l10, s10l};  Point(1018) = {d10,     -e10+r10,  ll/2+l10, s10l}; 
Point(1009) = {d10-r10, e10,    -ll/2-l10, s10l};  Point(1019) = {d10-r10,  -e10,     ll/2+l10, s10l}; 
Point(1010) = {d10,    e10-r10, -ll/2-l10, s10l};  Point(1020) = {d10,     -e10-r10,  ll/2+l10, s10l}; 

Circle(1001) = {1002,1001,1003}; Circle(1005) = {1007,1006,1008}; Line(1009) = {1002,1007};
Circle(1002) = {1003,1001,1004}; Circle(1006) = {1008,1006,1009}; Line(1010) = {1003,1008};
Circle(1003) = {1004,1001,1005}; Circle(1007) = {1009,1006,1010}; Line(1011) = {1004,1009};
Circle(1004) = {1005,1001,1002}; Circle(1008) = {1010,1006,1007}; Line(1012) = {1005,1010};

Circle(1013) = {1012,1011,1013}; Circle(1017) = {1017,1016,1018}; Line(1021) = {1012,1017};
Circle(1014) = {1013,1011,1014}; Circle(1018) = {1018,1016,1019}; Line(1022) = {1013,1018};
Circle(1015) = {1014,1011,1015}; Circle(1019) = {1019,1016,1020}; Line(1023) = {1014,1019};
Circle(1016) = {1015,1011,1012}; Circle(1020) = {1020,1016,1017}; Line(1024) = {1015,1020};

Line Loop(1001) = {1002,1003,1004,1001};   Plane Surface(1021) = {1001};
Line Loop(1002) = {1007,1008,1005,1006};   Plane Surface(1022) = {1002};
Line Loop(1003) = {1016,1013,1014,1015};   Plane Surface(1023) = {1003};
Line Loop(1004) = {1020,1017,1018,1019};   Plane Surface(1024) = {1004};
Line Loop(1005) = {1008,-1009,-1004,1012}; Ruled Surface(1025) = {1005};
Line Loop(1006) = {1012,-1007,-1011,1003}; Ruled Surface(1026) = {1006};
Line Loop(1007) = {-1011,-1002,1010,1006}; Ruled Surface(1027) = {1007};
Line Loop(1008) = {-1010,-1001,1009,1005}; Ruled Surface(1028) = {1008};
Line Loop(1009) = {1021,-1020,-1024,1016}; Ruled Surface(1029) = {1009};
Line Loop(1010) = {-1024,-1015,1023,1019}; Ruled Surface(1030) = {1010};
Line Loop(1011) = {1023,-1018,-1022,1014}; Ruled Surface(1031) = {1011};
Line Loop(1012) = {1022,-1017,-1021,1013}; Ruled Surface(1032) = {1012};

/* barreau 11 et 11' */

Point(1101) = {d11,    -e11,    -ll/2,    s11};  Point(1111) = {d11,     e11,     ll/2,    s11}; 
Point(1102) = {d11+r11, -e11,    -ll/2,    s11};  Point(1112) = {d11+r11,  e11,     ll/2,    s11}; 
Point(1103) = {d11,    -e11+r11, -ll/2,    s11};  Point(1113) = {d11,     e11+r11,  ll/2,    s11}; 
Point(1104) = {d11-r11, -e11,    -ll/2,    s11};  Point(1114) = {d11-r11,  e11,     ll/2,    s11}; 
Point(1105) = {d11,    -e11-r11, -ll/2,    s11};  Point(1115) = {d11,     e11-r11,  ll/2,    s11}; 
Point(1106) = {d11,    -e11,    -ll/2-l11, s11l};  Point(1116) = {d11,     e11,     ll/2+l11, s11l}; 
Point(1107) = {d11+r11, -e11,    -ll/2-l11, s11l};  Point(1117) = {d11+r11,  e11,     ll/2+l11, s11l}; 
Point(1108) = {d11,    -e11+r11, -ll/2-l11, s11l};  Point(1118) = {d11,     e11+r11,  ll/2+l11, s11l}; 
Point(1109) = {d11-r11, -e11,    -ll/2-l11, s11l};  Point(1119) = {d11-r11,  e11,     ll/2+l11, s11l}; 
Point(1110) = {d11,    -e11-r11, -ll/2-l11, s11l};  Point(1120) = {d11,     e11-r11,  ll/2+l11, s11l}; 

Circle(1101) = {1102,1101,1103}; Circle(1105) = {1107,1106,1108}; Line(1109) = {1102,1107};
Circle(1102) = {1103,1101,1104}; Circle(1106) = {1108,1106,1109}; Line(1110) = {1103,1108};
Circle(1103) = {1104,1101,1105}; Circle(1107) = {1109,1106,1110}; Line(1111) = {1104,1109};
Circle(1104) = {1105,1101,1102}; Circle(1108) = {1110,1106,1107}; Line(1112) = {1105,1110};

Circle(1113) = {1112,1111,1113}; Circle(1117) = {1117,1116,1118}; Line(1121) = {1112,1117};
Circle(1114) = {1113,1111,1114}; Circle(1118) = {1118,1116,1119}; Line(1122) = {1113,1118};
Circle(1115) = {1114,1111,1115}; Circle(1119) = {1119,1116,1120}; Line(1123) = {1114,1119};
Circle(1116) = {1115,1111,1112}; Circle(1120) = {1120,1116,1117}; Line(1124) = {1115,1120};

Line Loop(1101) = {1102,1103,1104,1101};   Plane Surface(1121) = {1101};
Line Loop(1102) = {1107,1108,1105,1106};   Plane Surface(1122) = {1102};
Line Loop(1103) = {1116,1113,1114,1115};   Plane Surface(1123) = {1103};
Line Loop(1104) = {1120,1117,1118,1119};   Plane Surface(1124) = {1104};
Line Loop(1105) = {1108,-1109,-1104,1112}; Ruled Surface(1125) = {1105};
Line Loop(1106) = {1112,-1107,-1111,1103}; Ruled Surface(1126) = {1106};
Line Loop(1107) = {-1111,-1102,1110,1106}; Ruled Surface(1127) = {1107};
Line Loop(1108) = {-1110,-1101,1109,1105}; Ruled Surface(1128) = {1108};
Line Loop(1109) = {1121,-1120,-1124,1116}; Ruled Surface(1129) = {1109};
Line Loop(1110) = {-1124,-1115,1123,1119}; Ruled Surface(1130) = {1110};
Line Loop(1111) = {1123,-1118,-1122,1114}; Ruled Surface(1131) = {1111};
Line Loop(1112) = {1122,-1117,-1121,1113}; Ruled Surface(1132) = {1112};

/* barreau 12 et 12' */

Point(1201) = {d12,    e12,    -ll/2,    s12};  Point(1211) = {d12,     -e12,     ll/2,    s12}; 
Point(1202) = {d12+r12, e12,    -ll/2,    s12};  Point(1212) = {d12+r12,  -e12,     ll/2,    s12}; 
Point(1203) = {d12,    e12+r12, -ll/2,    s12};  Point(1213) = {d12,     -e12+r12,  ll/2,    s12}; 
Point(1204) = {d12-r12, e12,    -ll/2,    s12};  Point(1214) = {d12-r12,  -e12,     ll/2,    s12}; 
Point(1205) = {d12,    e12-r12, -ll/2,    s12};  Point(1215) = {d12,     -e12-r12,  ll/2,    s12}; 
Point(1206) = {d12,    e12,    -ll/2-l12, s12l};  Point(1216) = {d12,     -e12,     ll/2+l12, s12l}; 
Point(1207) = {d12+r12, e12,    -ll/2-l12, s12l};  Point(1217) = {d12+r12,  -e12,     ll/2+l12, s12l}; 
Point(1208) = {d12,    e12+r12, -ll/2-l12, s12l};  Point(1218) = {d12,     -e12+r12,  ll/2+l12, s12l}; 
Point(1209) = {d12-r12, e12,    -ll/2-l12, s12l};  Point(1219) = {d12-r12,  -e12,     ll/2+l12, s12l}; 
Point(1210) = {d12,    e12-r12, -ll/2-l12, s12l};  Point(1220) = {d12,     -e12-r12,  ll/2+l12, s12l}; 

Circle(1201) = {1202,1201,1203}; Circle(1205) = {1207,1206,1208}; Line(1209) = {1202,1207};
Circle(1202) = {1203,1201,1204}; Circle(1206) = {1208,1206,1209}; Line(1210) = {1203,1208};
Circle(1203) = {1204,1201,1205}; Circle(1207) = {1209,1206,1210}; Line(1211) = {1204,1209};
Circle(1204) = {1205,1201,1202}; Circle(1208) = {1210,1206,1207}; Line(1212) = {1205,1210};
       	       	     		    	    	    	       	       	   
Circle(1213) = {1212,1211,1213}; Circle(1217) = {1217,1216,1218}; Line(1221) = {1212,1217};
Circle(1214) = {1213,1211,1214}; Circle(1218) = {1218,1216,1219}; Line(1222) = {1213,1218};
Circle(1215) = {1214,1211,1215}; Circle(1219) = {1219,1216,1220}; Line(1223) = {1214,1219};
Circle(1216) = {1215,1211,1212}; Circle(1220) = {1220,1216,1217}; Line(1224) = {1215,1220};

Line Loop(1201) = {1202,1203,1204,1201};   Plane Surface(1221) = {1201};
Line Loop(1202) = {1207,1208,1205,1206};   Plane Surface(1222) = {1202};
Line Loop(1203) = {1216,1213,1214,1215};   Plane Surface(1223) = {1203};
Line Loop(1204) = {1220,1217,1218,1219};   Plane Surface(1224) = {1204};
Line Loop(1205) = {1208,-1209,-1204,1212}; Ruled Surface(1225) = {1205};
Line Loop(1206) = {1212,-1207,-1211,1203}; Ruled Surface(1226) = {1206};
Line Loop(1207) = {-1211,-1202,1210,1206}; Ruled Surface(1227) = {1207};
Line Loop(1208) = {-1210,-1201,1209,1205}; Ruled Surface(1228) = {1208};
Line Loop(1209) = {1221,-1220,-1224,1216}; Ruled Surface(1229) = {1209};
Line Loop(1210) = {-1224,-1215,1223,1219}; Ruled Surface(1230) = {1210};
Line Loop(1211) = {1223,-1218,-1222,1214}; Ruled Surface(1231) = {1211};
Line Loop(1212) = {1222,-1217,-1221,1213}; Ruled Surface(1232) = {1212};

/* barreau 13 et 13' */

Point(1301) = {d13,    -e13,    -ll/2,    s13};  Point(1311) = {d13,     e13,     ll/2,    s13}; 
Point(1302) = {d13+r13, -e13,    -ll/2,    s13};  Point(1312) = {d13+r13,  e13,     ll/2,    s13}; 
Point(1303) = {d13,    -e13+r13, -ll/2,    s13};  Point(1313) = {d13,     e13+r13,  ll/2,    s13}; 
Point(1304) = {d13-r13, -e13,    -ll/2,    s13};  Point(1314) = {d13-r13,  e13,     ll/2,    s13}; 
Point(1305) = {d13,    -e13-r13, -ll/2,    s13};  Point(1315) = {d13,     e13-r13,  ll/2,    s13}; 
Point(1306) = {d13,    -e13,    -ll/2-l13, s13l};  Point(1316) = {d13,     e13,     ll/2+l13, s13l}; 
Point(1307) = {d13+r13, -e13,    -ll/2-l13, s13l};  Point(1317) = {d13+r13,  e13,     ll/2+l13, s13l}; 
Point(1308) = {d13,    -e13+r13, -ll/2-l13, s13l};  Point(1318) = {d13,     e13+r13,  ll/2+l13, s13l}; 
Point(1309) = {d13-r13, -e13,    -ll/2-l13, s13l};  Point(1319) = {d13-r13,  e13,     ll/2+l13, s13l}; 
Point(1310) = {d13,    -e13-r13, -ll/2-l13, s13l};  Point(1320) = {d13,     e13-r13,  ll/2+l13, s13l}; 

Circle(1301) = {1302,1301,1303}; Circle(1305) = {1307,1306,1308}; Line(1309) = {1302,1307};
Circle(1302) = {1303,1301,1304}; Circle(1306) = {1308,1306,1309}; Line(1310) = {1303,1308};
Circle(1303) = {1304,1301,1305}; Circle(1307) = {1309,1306,1310}; Line(1311) = {1304,1309};
Circle(1304) = {1305,1301,1302}; Circle(1308) = {1310,1306,1307}; Line(1312) = {1305,1310};
       	       	     		    	    	    	       	       	   
Circle(1313) = {1312,1311,1313}; Circle(1317) = {1317,1316,1318}; Line(1321) = {1312,1317};
Circle(1314) = {1313,1311,1314}; Circle(1318) = {1318,1316,1319}; Line(1322) = {1313,1318};
Circle(1315) = {1314,1311,1315}; Circle(1319) = {1319,1316,1320}; Line(1323) = {1314,1319};
Circle(1316) = {1315,1311,1312}; Circle(1320) = {1320,1316,1317}; Line(1324) = {1315,1320};

Line Loop(1301) = {1302,1303,1304,1301};   Plane Surface(1321) = {1301};
Line Loop(1302) = {1307,1308,1305,1306};   Plane Surface(1322) = {1302};
Line Loop(1303) = {1316,1313,1314,1315};   Plane Surface(1323) = {1303};
Line Loop(1304) = {1320,1317,1318,1319};   Plane Surface(1324) = {1304};
Line Loop(1305) = {1308,-1309,-1304,1312}; Ruled Surface(1325) = {1305};
Line Loop(1306) = {1312,-1307,-1311,1303}; Ruled Surface(1326) = {1306};
Line Loop(1307) = {-1311,-1302,1310,1306}; Ruled Surface(1327) = {1307};
Line Loop(1308) = {-1310,-1301,1309,1305}; Ruled Surface(1328) = {1308};
Line Loop(1309) = {1321,-1320,-1324,1316}; Ruled Surface(1329) = {1309};
Line Loop(1310) = {-1324,-1315,1323,1319}; Ruled Surface(1330) = {1310};
Line Loop(1311) = {1323,-1318,-1322,1314}; Ruled Surface(1331) = {1311};
Line Loop(1312) = {1322,-1317,-1321,1313}; Ruled Surface(1332) = {1312};

/* barreau 14 et 14' */

Point(1401) = {d14,    e14,    -ll/2,    s14};  Point(1411) = {d14,     -e14,     ll/2,    s14}; 
Point(1402) = {d14+r14, e14,    -ll/2,    s14};  Point(1412) = {d14+r14,  -e14,     ll/2,    s14}; 
Point(1403) = {d14,    e14+r14, -ll/2,    s14};  Point(1413) = {d14,     -e14+r14,  ll/2,    s14}; 
Point(1404) = {d14-r14, e14,    -ll/2,    s14};  Point(1414) = {d14-r14,  -e14,     ll/2,    s14}; 
Point(1405) = {d14,    e14-r14, -ll/2,    s14};  Point(1415) = {d14,     -e14-r14,  ll/2,    s14}; 
Point(1406) = {d14,    e14,    -ll/2-l14, s14l};  Point(1416) = {d14,     -e14,     ll/2+l14, s14l}; 
Point(1407) = {d14+r14, e14,    -ll/2-l14, s14l};  Point(1417) = {d14+r14,  -e14,     ll/2+l14, s14l}; 
Point(1408) = {d14,    e14+r14, -ll/2-l14, s14l};  Point(1418) = {d14,     -e14+r14,  ll/2+l14, s14l}; 
Point(1409) = {d14-r14, e14,    -ll/2-l14, s14l};  Point(1419) = {d14-r14,  -e14,     ll/2+l14, s14l}; 
Point(1410) = {d14,    e14-r14, -ll/2-l14, s14l};  Point(1420) = {d14,     -e14-r14,  ll/2+l14, s14l}; 

Circle(1401) = {1402,1401,1403}; Circle(1405) = {1407,1406,1408}; Line(1409) = {1402,1407};
Circle(1402) = {1403,1401,1404}; Circle(1406) = {1408,1406,1409}; Line(1410) = {1403,1408};
Circle(1403) = {1404,1401,1405}; Circle(1407) = {1409,1406,1410}; Line(1411) = {1404,1409};
Circle(1404) = {1405,1401,1402}; Circle(1408) = {1410,1406,1407}; Line(1412) = {1405,1410};
       	       	     		    	    	    	       	       	   
Circle(1413) = {1412,1411,1413}; Circle(1417) = {1417,1416,1418}; Line(1421) = {1412,1417};
Circle(1414) = {1413,1411,1414}; Circle(1418) = {1418,1416,1419}; Line(1422) = {1413,1418};
Circle(1415) = {1414,1411,1415}; Circle(1419) = {1419,1416,1420}; Line(1423) = {1414,1419};
Circle(1416) = {1415,1411,1412}; Circle(1420) = {1420,1416,1417}; Line(1424) = {1415,1420};

Line Loop(1401) = {1402,1403,1404,1401};   Plane Surface(1421) = {1401};
Line Loop(1402) = {1407,1408,1405,1406};   Plane Surface(1422) = {1402};
Line Loop(1403) = {1416,1413,1414,1415};   Plane Surface(1423) = {1403};
Line Loop(1404) = {1420,1417,1418,1419};   Plane Surface(1424) = {1404};
Line Loop(1405) = {1408,-1409,-1404,1412}; Ruled Surface(1425) = {1405};
Line Loop(1406) = {1412,-1407,-1411,1403}; Ruled Surface(1426) = {1406};
Line Loop(1407) = {-1411,-1402,1410,1406}; Ruled Surface(1427) = {1407};
Line Loop(1408) = {-1410,-1401,1409,1405}; Ruled Surface(1428) = {1408};
Line Loop(1409) = {1421,-1420,-1424,1416}; Ruled Surface(1429) = {1409};
Line Loop(1410) = {-1424,-1415,1423,1419}; Ruled Surface(1430) = {1410};
Line Loop(1411) = {1423,-1418,-1422,1414}; Ruled Surface(1431) = {1411};
Line Loop(1412) = {1422,-1417,-1421,1413}; Ruled Surface(1432) = {1412};

/* barreau 15 et 15' */

Point(1501) = {d15,    -e15,    -ll/2,    s15};  Point(1511) = {d15,     e15,     ll/2,    s15}; 
Point(1502) = {d15+r15, -e15,    -ll/2,    s15};  Point(1512) = {d15+r15,  e15,     ll/2,    s15}; 
Point(1503) = {d15,    -e15+r15, -ll/2,    s15};  Point(1513) = {d15,     e15+r15,  ll/2,    s15}; 
Point(1504) = {d15-r15, -e15,    -ll/2,    s15};  Point(1514) = {d15-r15,  e15,     ll/2,    s15}; 
Point(1505) = {d15,    -e15-r15, -ll/2,    s15};  Point(1515) = {d15,     e15-r15,  ll/2,    s15}; 
Point(1506) = {d15,    -e15,    -ll/2-l15, s15l};  Point(1516) = {d15,     e15,     ll/2+l15, s15l}; 
Point(1507) = {d15+r15, -e15,    -ll/2-l15, s15l};  Point(1517) = {d15+r15,  e15,     ll/2+l15, s15l}; 
Point(1508) = {d15,    -e15+r15, -ll/2-l15, s15l};  Point(1518) = {d15,     e15+r15,  ll/2+l15, s15l}; 
Point(1509) = {d15-r15, -e15,    -ll/2-l15, s15l};  Point(1519) = {d15-r15,  e15,     ll/2+l15, s15l}; 
Point(1510) = {d15,    -e15-r15, -ll/2-l15, s15l};  Point(1520) = {d15,     e15-r15,  ll/2+l15, s15l}; 

Circle(1501) = {1502,1501,1503}; Circle(1505) = {1507,1506,1508}; Line(1509) = {1502,1507};
Circle(1502) = {1503,1501,1504}; Circle(1506) = {1508,1506,1509}; Line(1510) = {1503,1508};
Circle(1503) = {1504,1501,1505}; Circle(1507) = {1509,1506,1510}; Line(1511) = {1504,1509};
Circle(1504) = {1505,1501,1502}; Circle(1508) = {1510,1506,1507}; Line(1512) = {1505,1510};
       	       	     		    	    	    	       	       	   
Circle(1513) = {1512,1511,1513}; Circle(1517) = {1517,1516,1518}; Line(1521) = {1512,1517};
Circle(1514) = {1513,1511,1514}; Circle(1518) = {1518,1516,1519}; Line(1522) = {1513,1518};
Circle(1515) = {1514,1511,1515}; Circle(1519) = {1519,1516,1520}; Line(1523) = {1514,1519};
Circle(1516) = {1515,1511,1512}; Circle(1520) = {1520,1516,1517}; Line(1524) = {1515,1520};

Line Loop(1501) = {1502,1503,1504,1501};   Plane Surface(1521) = {1501};
Line Loop(1502) = {1507,1508,1505,1506};   Plane Surface(1522) = {1502};
Line Loop(1503) = {1516,1513,1514,1515};   Plane Surface(1523) = {1503};
Line Loop(1504) = {1520,1517,1518,1519};   Plane Surface(1524) = {1504};
Line Loop(1505) = {1508,-1509,-1504,1512}; Ruled Surface(1525) = {1505};
Line Loop(1506) = {1512,-1507,-1511,1503}; Ruled Surface(1526) = {1506};
Line Loop(1507) = {-1511,-1502,1510,1506}; Ruled Surface(1527) = {1507};
Line Loop(1508) = {-1510,-1501,1509,1505}; Ruled Surface(1528) = {1508};
Line Loop(1509) = {1521,-1520,-1524,1516}; Ruled Surface(1529) = {1509};
Line Loop(1510) = {-1524,-1515,1523,1519}; Ruled Surface(1530) = {1510};
Line Loop(1511) = {1523,-1518,-1522,1514}; Ruled Surface(1531) = {1511};
Line Loop(1512) = {1522,-1517,-1521,1513}; Ruled Surface(1532) = {1512};

/* barreau 16 et 16' */

Point(1601) = {d16,    e16,    -ll/2,    s16};  Point(1611) = {d16,     -e16,     ll/2,    s16}; 
Point(1602) = {d16+r16, e16,    -ll/2,    s16};  Point(1612) = {d16+r16,  -e16,     ll/2,    s16}; 
Point(1603) = {d16,    e16+r16, -ll/2,    s16};  Point(1613) = {d16,     -e16+r16,  ll/2,    s16}; 
Point(1604) = {d16-r16, e16,    -ll/2,    s16};  Point(1614) = {d16-r16,  -e16,     ll/2,    s16}; 
Point(1605) = {d16,    e16-r16, -ll/2,    s16};  Point(1615) = {d16,     -e16-r16,  ll/2,    s16}; 
Point(1606) = {d16,    e16,    -ll/2-l16, s16l};  Point(1616) = {d16,     -e16,     ll/2+l16, s16l}; 
Point(1607) = {d16+r16, e16,    -ll/2-l16, s16l};  Point(1617) = {d16+r16,  -e16,     ll/2+l16, s16l}; 
Point(1608) = {d16,    e16+r16, -ll/2-l16, s16l};  Point(1618) = {d16,     -e16+r16,  ll/2+l16, s16l}; 
Point(1609) = {d16-r16, e16,    -ll/2-l16, s16l};  Point(1619) = {d16-r16,  -e16,     ll/2+l16, s16l}; 
Point(1610) = {d16,    e16-r16, -ll/2-l16, s16l};  Point(1620) = {d16,     -e16-r16,  ll/2+l16, s16l}; 

Circle(1601) = {1602,1601,1603}; Circle(1605) = {1607,1606,1608}; Line(1609) = {1602,1607};
Circle(1602) = {1603,1601,1604}; Circle(1606) = {1608,1606,1609}; Line(1610) = {1603,1608};
Circle(1603) = {1604,1601,1605}; Circle(1607) = {1609,1606,1610}; Line(1611) = {1604,1609};
Circle(1604) = {1605,1601,1602}; Circle(1608) = {1610,1606,1607}; Line(1612) = {1605,1610};
       	       	     		    	    	    	       	       	   
Circle(1613) = {1612,1611,1613}; Circle(1617) = {1617,1616,1618}; Line(1621) = {1612,1617};
Circle(1614) = {1613,1611,1614}; Circle(1618) = {1618,1616,1619}; Line(1622) = {1613,1618};
Circle(1615) = {1614,1611,1615}; Circle(1619) = {1619,1616,1620}; Line(1623) = {1614,1619};
Circle(1616) = {1615,1611,1612}; Circle(1620) = {1620,1616,1617}; Line(1624) = {1615,1620};

Line Loop(1601) = {1602,1603,1604,1601};   Plane Surface(1621) = {1601};
Line Loop(1602) = {1607,1608,1605,1606};   Plane Surface(1622) = {1602};
Line Loop(1603) = {1616,1613,1614,1615};   Plane Surface(1623) = {1603};
Line Loop(1604) = {1620,1617,1618,1619};   Plane Surface(1624) = {1604};
Line Loop(1605) = {1608,-1609,-1604,1612}; Ruled Surface(1625) = {1605};
Line Loop(1606) = {1612,-1607,-1611,1603}; Ruled Surface(1626) = {1606};
Line Loop(1607) = {-1611,-1602,1610,1606}; Ruled Surface(1627) = {1607};
Line Loop(1608) = {-1610,-1601,1609,1605}; Ruled Surface(1628) = {1608};
Line Loop(1609) = {1621,-1620,-1624,1616}; Ruled Surface(1629) = {1609};
Line Loop(1610) = {-1624,-1615,1623,1619}; Ruled Surface(1630) = {1610};
Line Loop(1611) = {1623,-1618,-1622,1614}; Ruled Surface(1631) = {1611};
Line Loop(1612) = {1622,-1617,-1621,1613}; Ruled Surface(1632) = {1612};

/* barreau 17 et 17' */

Point(1701) = {d17,    -e17,    -ll/2,    s17};  Point(1711) = {d17,     e17,     ll/2,    s17}; 
Point(1702) = {d17+r17, -e17,    -ll/2,    s17};  Point(1712) = {d17+r17,  e17,     ll/2,    s17}; 
Point(1703) = {d17,    -e17+r17, -ll/2,    s17};  Point(1713) = {d17,     e17+r17,  ll/2,    s17}; 
Point(1704) = {d17-r17, -e17,    -ll/2,    s17};  Point(1714) = {d17-r17,  e17,     ll/2,    s17}; 
Point(1705) = {d17,    -e17-r17, -ll/2,    s17};  Point(1715) = {d17,     e17-r17,  ll/2,    s17}; 
Point(1706) = {d17,    -e17,    -ll/2-l17, s17l};  Point(1716) = {d17,     e17,     ll/2+l17, s17l}; 
Point(1707) = {d17+r17, -e17,    -ll/2-l17, s17l};  Point(1717) = {d17+r17,  e17,     ll/2+l17, s17l}; 
Point(1708) = {d17,    -e17+r17, -ll/2-l17, s17l};  Point(1718) = {d17,     e17+r17,  ll/2+l17, s17l}; 
Point(1709) = {d17-r17, -e17,    -ll/2-l17, s17l};  Point(1719) = {d17-r17,  e17,     ll/2+l17, s17l}; 
Point(1710) = {d17,    -e17-r17, -ll/2-l17, s17l};  Point(1720) = {d17,     e17-r17,  ll/2+l17, s17l}; 

Circle(1701) = {1702,1701,1703}; Circle(1705) = {1707,1706,1708}; Line(1709) = {1702,1707};
Circle(1702) = {1703,1701,1704}; Circle(1706) = {1708,1706,1709}; Line(1710) = {1703,1708};
Circle(1703) = {1704,1701,1705}; Circle(1707) = {1709,1706,1710}; Line(1711) = {1704,1709};
Circle(1704) = {1705,1701,1702}; Circle(1708) = {1710,1706,1707}; Line(1712) = {1705,1710};
       	       	     		    	    	    	       	       	   
Circle(1713) = {1712,1711,1713}; Circle(1717) = {1717,1716,1718}; Line(1721) = {1712,1717};
Circle(1714) = {1713,1711,1714}; Circle(1718) = {1718,1716,1719}; Line(1722) = {1713,1718};
Circle(1715) = {1714,1711,1715}; Circle(1719) = {1719,1716,1720}; Line(1723) = {1714,1719};
Circle(1716) = {1715,1711,1712}; Circle(1720) = {1720,1716,1717}; Line(1724) = {1715,1720};

Line Loop(1701) = {1702,1703,1704,1701};   Plane Surface(1721) = {1701};
Line Loop(1702) = {1707,1708,1705,1706};   Plane Surface(1722) = {1702};
Line Loop(1703) = {1716,1713,1714,1715};   Plane Surface(1723) = {1703};
Line Loop(1704) = {1720,1717,1718,1719};   Plane Surface(1724) = {1704};
Line Loop(1705) = {1708,-1709,-1704,1712}; Ruled Surface(1725) = {1705};
Line Loop(1706) = {1712,-1707,-1711,1703}; Ruled Surface(1726) = {1706};
Line Loop(1707) = {-1711,-1702,1710,1706}; Ruled Surface(1727) = {1707};
Line Loop(1708) = {-1710,-1701,1709,1705}; Ruled Surface(1728) = {1708};
Line Loop(1709) = {1721,-1720,-1724,1716}; Ruled Surface(1729) = {1709};
Line Loop(1710) = {-1724,-1715,1723,1719}; Ruled Surface(1730) = {1710};
Line Loop(1711) = {1723,-1718,-1722,1714}; Ruled Surface(1731) = {1711};
Line Loop(1712) = {1722,-1717,-1721,1713}; Ruled Surface(1732) = {1712};

/* barreau 18 et 18' */

Point(1801) = {d18,    e18,    -ll/2,    s18};  Point(1811) = {d18,     -e18,     ll/2,    s18}; 
Point(1802) = {d18+r18, e18,    -ll/2,    s18};  Point(1812) = {d18+r18,  -e18,     ll/2,    s18}; 
Point(1803) = {d18,    e18+r18, -ll/2,    s18};  Point(1813) = {d18,     -e18+r18,  ll/2,    s18}; 
Point(1804) = {d18-r18, e18,    -ll/2,    s18};  Point(1814) = {d18-r18,  -e18,     ll/2,    s18}; 
Point(1805) = {d18,    e18-r18, -ll/2,    s18};  Point(1815) = {d18,     -e18-r18,  ll/2,    s18}; 
Point(1806) = {d18,    e18,    -ll/2-l18, s18l};  Point(1816) = {d18,     -e18,     ll/2+l18, s18l}; 
Point(1807) = {d18+r18, e18,    -ll/2-l18, s18l};  Point(1817) = {d18+r18,  -e18,     ll/2+l18, s18l}; 
Point(1808) = {d18,    e18+r18, -ll/2-l18, s18l};  Point(1818) = {d18,     -e18+r18,  ll/2+l18, s18l}; 
Point(1809) = {d18-r18, e18,    -ll/2-l18, s18l};  Point(1819) = {d18-r18,  -e18,     ll/2+l18, s18l}; 
Point(1810) = {d18,    e18-r18, -ll/2-l18, s18l};  Point(1820) = {d18,     -e18-r18,  ll/2+l18, s18l}; 

Circle(1801) = {1802,1801,1803}; Circle(1805) = {1807,1806,1808}; Line(1809) = {1802,1807};
Circle(1802) = {1803,1801,1804}; Circle(1806) = {1808,1806,1809}; Line(1810) = {1803,1808};
Circle(1803) = {1804,1801,1805}; Circle(1807) = {1809,1806,1810}; Line(1811) = {1804,1809};
Circle(1804) = {1805,1801,1802}; Circle(1808) = {1810,1806,1807}; Line(1812) = {1805,1810};
       	       	     		    	    	    	       	       	   
Circle(1813) = {1812,1811,1813}; Circle(1817) = {1817,1816,1818}; Line(1821) = {1812,1817};
Circle(1814) = {1813,1811,1814}; Circle(1818) = {1818,1816,1819}; Line(1822) = {1813,1818};
Circle(1815) = {1814,1811,1815}; Circle(1819) = {1819,1816,1820}; Line(1823) = {1814,1819};
Circle(1816) = {1815,1811,1812}; Circle(1820) = {1820,1816,1817}; Line(1824) = {1815,1820};

Line Loop(1801) = {1802,1803,1804,1801};   Plane Surface(1821) = {1801};
Line Loop(1802) = {1807,1808,1805,1806};   Plane Surface(1822) = {1802};
Line Loop(1803) = {1816,1813,1814,1815};   Plane Surface(1823) = {1803};
Line Loop(1804) = {1820,1817,1818,1819};   Plane Surface(1824) = {1804};
Line Loop(1805) = {1808,-1809,-1804,1812}; Ruled Surface(1825) = {1805};
Line Loop(1806) = {1812,-1807,-1811,1803}; Ruled Surface(1826) = {1806};
Line Loop(1807) = {-1811,-1802,1810,1806}; Ruled Surface(1827) = {1807};
Line Loop(1808) = {-1810,-1801,1809,1805}; Ruled Surface(1828) = {1808};
Line Loop(1809) = {1821,-1820,-1824,1816}; Ruled Surface(1829) = {1809};
Line Loop(1810) = {-1824,-1815,1823,1819}; Ruled Surface(1830) = {1810};
Line Loop(1811) = {1823,-1818,-1822,1814}; Ruled Surface(1831) = {1811};
Line Loop(1812) = {1822,-1817,-1821,1813}; Ruled Surface(1832) = {1812};

/* barreau 19 et 19' */

Point(1901) = {d19,    -e19,    -ll/2,    s19};  Point(1911) = {d19,     e19,     ll/2,    s19}; 
Point(1902) = {d19+r19, -e19,    -ll/2,    s19};  Point(1912) = {d19+r19,  e19,     ll/2,    s19}; 
Point(1903) = {d19,    -e19+r19, -ll/2,    s19};  Point(1913) = {d19,     e19+r19,  ll/2,    s19}; 
Point(1904) = {d19-r19, -e19,    -ll/2,    s19};  Point(1914) = {d19-r19,  e19,     ll/2,    s19}; 
Point(1905) = {d19,    -e19-r19, -ll/2,    s19};  Point(1915) = {d19,     e19-r19,  ll/2,    s19}; 
Point(1906) = {d19,    -e19,    -ll/2-l19, s19l};  Point(1916) = {d19,     e19,     ll/2+l19, s19l}; 
Point(1907) = {d19+r19, -e19,    -ll/2-l19, s19l};  Point(1917) = {d19+r19,  e19,     ll/2+l19, s19l}; 
Point(1908) = {d19,    -e19+r19, -ll/2-l19, s19l};  Point(1918) = {d19,     e19+r19,  ll/2+l19, s19l}; 
Point(1909) = {d19-r19, -e19,    -ll/2-l19, s19l};  Point(1919) = {d19-r19,  e19,     ll/2+l19, s19l}; 
Point(1910) = {d19,    -e19-r19, -ll/2-l19, s19l};  Point(1920) = {d19,     e19-r19,  ll/2+l19, s19l}; 

Circle(1901) = {1902,1901,1903}; Circle(1905) = {1907,1906,1908}; Line(1909) = {1902,1907};
Circle(1902) = {1903,1901,1904}; Circle(1906) = {1908,1906,1909}; Line(1910) = {1903,1908};
Circle(1903) = {1904,1901,1905}; Circle(1907) = {1909,1906,1910}; Line(1911) = {1904,1909};
Circle(1904) = {1905,1901,1902}; Circle(1908) = {1910,1906,1907}; Line(1912) = {1905,1910};
       	       	     		    	    	    	       	       	   
Circle(1913) = {1912,1911,1913}; Circle(1917) = {1917,1916,1918}; Line(1921) = {1912,1917};
Circle(1914) = {1913,1911,1914}; Circle(1918) = {1918,1916,1919}; Line(1922) = {1913,1918};
Circle(1915) = {1914,1911,1915}; Circle(1919) = {1919,1916,1920}; Line(1923) = {1914,1919};
Circle(1916) = {1915,1911,1912}; Circle(1920) = {1920,1916,1917}; Line(1924) = {1915,1920};

Line Loop(1901) = {1902,1903,1904,1901};   Plane Surface(1921) = {1901};
Line Loop(1902) = {1907,1908,1905,1906};   Plane Surface(1922) = {1902};
Line Loop(1903) = {1916,1913,1914,1915};   Plane Surface(1923) = {1903};
Line Loop(1904) = {1920,1917,1918,1919};   Plane Surface(1924) = {1904};
Line Loop(1905) = {1908,-1909,-1904,1912}; Ruled Surface(1925) = {1905};
Line Loop(1906) = {1912,-1907,-1911,1903}; Ruled Surface(1926) = {1906};
Line Loop(1907) = {-1911,-1902,1910,1906}; Ruled Surface(1927) = {1907};
Line Loop(1908) = {-1910,-1901,1909,1905}; Ruled Surface(1928) = {1908};
Line Loop(1909) = {1921,-1920,-1924,1916}; Ruled Surface(1929) = {1909};
Line Loop(1910) = {-1924,-1915,1923,1919}; Ruled Surface(1930) = {1910};
Line Loop(1911) = {1923,-1918,-1922,1914}; Ruled Surface(1931) = {1911};
Line Loop(1912) = {1922,-1917,-1921,1913}; Ruled Surface(1932) = {1912};

/* barreau 20 et 20' */

Point(2001) = {d20,    e20,    -ll/2,    s20};  Point(2011) = {d20,     -e20,     ll/2,    s20}; 
Point(2002) = {d20+r20, e20,    -ll/2,    s20};  Point(2012) = {d20+r20,  -e20,     ll/2,    s20}; 
Point(2003) = {d20,    e20+r20, -ll/2,    s20};  Point(2013) = {d20,     -e20+r20,  ll/2,    s20}; 
Point(2004) = {d20-r20, e20,    -ll/2,    s20};  Point(2014) = {d20-r20,  -e20,     ll/2,    s20}; 
Point(2005) = {d20,    e20-r20, -ll/2,    s20};  Point(2015) = {d20,     -e20-r20,  ll/2,    s20}; 
Point(2006) = {d20,    e20,    -ll/2-l20, s20l};  Point(2016) = {d20,     -e20,     ll/2+l20, s20l}; 
Point(2007) = {d20+r20, e20,    -ll/2-l20, s20l};  Point(2017) = {d20+r20,  -e20,     ll/2+l20, s20l}; 
Point(2008) = {d20,    e20+r20, -ll/2-l20, s20l};  Point(2018) = {d20,     -e20+r20,  ll/2+l20, s20l}; 
Point(2009) = {d20-r20, e20,    -ll/2-l20, s20l};  Point(2019) = {d20-r20,  -e20,     ll/2+l20, s20l}; 
Point(2010) = {d20,    e20-r20, -ll/2-l20, s20l};  Point(2020) = {d20,     -e20-r20,  ll/2+l20, s20l}; 

Circle(2001) = {2002,2001,2003}; Circle(2005) = {2007,2006,2008}; Line(2009) = {2002,2007};
Circle(2002) = {2003,2001,2004}; Circle(2006) = {2008,2006,2009}; Line(2010) = {2003,2008};
Circle(2003) = {2004,2001,2005}; Circle(2007) = {2009,2006,2010}; Line(2011) = {2004,2009};
Circle(2004) = {2005,2001,2002}; Circle(2008) = {2010,2006,2007}; Line(2012) = {2005,2010};
       	       	     		    	    	    	       	       	   
Circle(2013) = {2012,2011,2013}; Circle(2017) = {2017,2016,2018}; Line(2021) = {2012,2017};
Circle(2014) = {2013,2011,2014}; Circle(2018) = {2018,2016,2019}; Line(2022) = {2013,2018};
Circle(2015) = {2014,2011,2015}; Circle(2019) = {2019,2016,2020}; Line(2023) = {2014,2019};
Circle(2016) = {2015,2011,2012}; Circle(2020) = {2020,2016,2017}; Line(2024) = {2015,2020};

Line Loop(2001) = {2002,2003,2004,2001};   Plane Surface(2021) = {2001};
Line Loop(2002) = {2007,2008,2005,2006};   Plane Surface(2022) = {2002};
Line Loop(2003) = {2016,2013,2014,2015};   Plane Surface(2023) = {2003};
Line Loop(2004) = {2020,2017,2018,2019};   Plane Surface(2024) = {2004};
Line Loop(2005) = {2008,-2009,-2004,2012}; Ruled Surface(2025) = {2005};
Line Loop(2006) = {2012,-2007,-2011,2003}; Ruled Surface(2026) = {2006};
Line Loop(2007) = {-2011,-2002,2010,2006}; Ruled Surface(2027) = {2007};
Line Loop(2008) = {-2010,-2001,2009,2005}; Ruled Surface(2028) = {2008};
Line Loop(2009) = {2021,-2020,-2024,2016}; Ruled Surface(2029) = {2009};
Line Loop(2010) = {-2024,-2015,2023,2019}; Ruled Surface(2030) = {2010};
Line Loop(2011) = {2023,-2018,-2022,2014}; Ruled Surface(2031) = {2011};
Line Loop(2012) = {2022,-2017,-2021,2013}; Ruled Surface(2032) = {2012};

/* barreau 21 et 21' */

Point(2101) = {d21,    -e21,    -ll/2,    s21};  Point(2111) = {d21,     e21,     ll/2,    s21}; 
Point(2102) = {d21+r21, -e21,    -ll/2,    s21};  Point(2112) = {d21+r21,  e21,     ll/2,    s21}; 
Point(2103) = {d21,    -e21+r21, -ll/2,    s21};  Point(2113) = {d21,     e21+r21,  ll/2,    s21}; 
Point(2104) = {d21-r21, -e21,    -ll/2,    s21};  Point(2114) = {d21-r21,  e21,     ll/2,    s21}; 
Point(2105) = {d21,    -e21-r21, -ll/2,    s21};  Point(2115) = {d21,     e21-r21,  ll/2,    s21}; 
Point(2106) = {d21,    -e21,    -ll/2-l21, s21l};  Point(2116) = {d21,     e21,     ll/2+l21, s21l}; 
Point(2107) = {d21+r21, -e21,    -ll/2-l21, s21l};  Point(2117) = {d21+r21,  e21,     ll/2+l21, s21l}; 
Point(2108) = {d21,    -e21+r21, -ll/2-l21, s21l};  Point(2118) = {d21,     e21+r21,  ll/2+l21, s21l}; 
Point(2109) = {d21-r21, -e21,    -ll/2-l21, s21l};  Point(2119) = {d21-r21,  e21,     ll/2+l21, s21l}; 
Point(2110) = {d21,    -e21-r21, -ll/2-l21, s21l};  Point(2120) = {d21,     e21-r21,  ll/2+l21, s21l}; 

Circle(2101) = {2102,2101,2103}; Circle(2105) = {2107,2106,2108}; Line(2109) = {2102,2107};
Circle(2102) = {2103,2101,2104}; Circle(2106) = {2108,2106,2109}; Line(2110) = {2103,2108};
Circle(2103) = {2104,2101,2105}; Circle(2107) = {2109,2106,2110}; Line(2111) = {2104,2109};
Circle(2104) = {2105,2101,2102}; Circle(2108) = {2110,2106,2107}; Line(2112) = {2105,2110};
       	       	     		    	    	    	       	       	   
Circle(2113) = {2112,2111,2113}; Circle(2117) = {2117,2116,2118}; Line(2121) = {2112,2117};
Circle(2114) = {2113,2111,2114}; Circle(2118) = {2118,2116,2119}; Line(2122) = {2113,2118};
Circle(2115) = {2114,2111,2115}; Circle(2119) = {2119,2116,2120}; Line(2123) = {2114,2119};
Circle(2116) = {2115,2111,2112}; Circle(2120) = {2120,2116,2117}; Line(2124) = {2115,2120};

Line Loop(2101) = {2102,2103,2104,2101};   Plane Surface(2121) = {2101};
Line Loop(2102) = {2107,2108,2105,2106};   Plane Surface(2122) = {2102};
Line Loop(2103) = {2116,2113,2114,2115};   Plane Surface(2123) = {2103};
Line Loop(2104) = {2120,2117,2118,2119};   Plane Surface(2124) = {2104};
Line Loop(2105) = {2108,-2109,-2104,2112}; Ruled Surface(2125) = {2105};
Line Loop(2106) = {2112,-2107,-2111,2103}; Ruled Surface(2126) = {2106};
Line Loop(2107) = {-2111,-2102,2110,2106}; Ruled Surface(2127) = {2107};
Line Loop(2108) = {-2110,-2101,2109,2105}; Ruled Surface(2128) = {2108};
Line Loop(2109) = {2121,-2120,-2124,2116}; Ruled Surface(2129) = {2109};
Line Loop(2110) = {-2124,-2115,2123,2119}; Ruled Surface(2130) = {2110};
Line Loop(2111) = {2123,-2118,-2122,2114}; Ruled Surface(2131) = {2111};
Line Loop(2112) = {2122,-2117,-2121,2113}; Ruled Surface(2132) = {2112};

/* barreau 22 et 22' */

Point(2201) = {d22,    e22,    -ll/2,    s22};  Point(2211) = {d22,     -e22,     ll/2,    s22}; 
Point(2202) = {d22+r22, e22,    -ll/2,    s22};  Point(2212) = {d22+r22,  -e22,     ll/2,    s22}; 
Point(2203) = {d22,    e22+r22, -ll/2,    s22};  Point(2213) = {d22,     -e22+r22,  ll/2,    s22}; 
Point(2204) = {d22-r22, e22,    -ll/2,    s22};  Point(2214) = {d22-r22,  -e22,     ll/2,    s22}; 
Point(2205) = {d22,    e22-r22, -ll/2,    s22};  Point(2215) = {d22,     -e22-r22,  ll/2,    s22}; 
Point(2206) = {d22,    e22,    -ll/2-l22, s22l};  Point(2216) = {d22,     -e22,     ll/2+l22, s22l}; 
Point(2207) = {d22+r22, e22,    -ll/2-l22, s22l};  Point(2217) = {d22+r22,  -e22,     ll/2+l22, s22l}; 
Point(2208) = {d22,    e22+r22, -ll/2-l22, s22l};  Point(2218) = {d22,     -e22+r22,  ll/2+l22, s22l}; 
Point(2209) = {d22-r22, e22,    -ll/2-l22, s22l};  Point(2219) = {d22-r22,  -e22,     ll/2+l22, s22l}; 
Point(2210) = {d22,    e22-r22, -ll/2-l22, s22l};  Point(2220) = {d22,     -e22-r22,  ll/2+l22, s22l}; 

Circle(2201) = {2202,2201,2203}; Circle(2205) = {2207,2206,2208}; Line(2209) = {2202,2207};
Circle(2202) = {2203,2201,2204}; Circle(2206) = {2208,2206,2209}; Line(2210) = {2203,2208};
Circle(2203) = {2204,2201,2205}; Circle(2207) = {2209,2206,2210}; Line(2211) = {2204,2209};
Circle(2204) = {2205,2201,2202}; Circle(2208) = {2210,2206,2207}; Line(2212) = {2205,2210};
       	       	     		    	    	    	       	       	   
Circle(2213) = {2212,2211,2213}; Circle(2217) = {2217,2216,2218}; Line(2221) = {2212,2217};
Circle(2214) = {2213,2211,2214}; Circle(2218) = {2218,2216,2219}; Line(2222) = {2213,2218};
Circle(2215) = {2214,2211,2215}; Circle(2219) = {2219,2216,2220}; Line(2223) = {2214,2219};
Circle(2216) = {2215,2211,2212}; Circle(2220) = {2220,2216,2217}; Line(2224) = {2215,2220};

Line Loop(2201) = {2202,2203,2204,2201};   Plane Surface(2221) = {2201};
Line Loop(2202) = {2207,2208,2205,2206};   Plane Surface(2222) = {2202};
Line Loop(2203) = {2216,2213,2214,2215};   Plane Surface(2223) = {2203};
Line Loop(2204) = {2220,2217,2218,2219};   Plane Surface(2224) = {2204};
Line Loop(2205) = {2208,-2209,-2204,2212}; Ruled Surface(2225) = {2205};
Line Loop(2206) = {2212,-2207,-2211,2203}; Ruled Surface(2226) = {2206};
Line Loop(2207) = {-2211,-2202,2210,2206}; Ruled Surface(2227) = {2207};
Line Loop(2208) = {-2210,-2201,2209,2205}; Ruled Surface(2228) = {2208};
Line Loop(2209) = {2221,-2220,-2224,2216}; Ruled Surface(2229) = {2209};
Line Loop(2210) = {-2224,-2215,2223,2219}; Ruled Surface(2230) = {2210};
Line Loop(2211) = {2223,-2218,-2222,2214}; Ruled Surface(2231) = {2211};
Line Loop(2212) = {2222,-2217,-2221,2213}; Ruled Surface(2232) = {2212};

/* barreau x et x' */
/*
Point(x01) = {dx,    -e,    -ll/2,    sx};  Point(x11) = {dx,     e,     ll/2,    sx}; 
Point(x02) = {dx+rx, -e,    -ll/2,    sx};  Point(x12) = {dx+rx,  e,     ll/2,    sx}; 
Point(x03) = {dx,    -e+rx, -ll/2,    sx};  Point(x13) = {dx,     e+rx,  ll/2,    sx}; 
Point(x04) = {dx-rx, -e,    -ll/2,    sx};  Point(x14) = {dx-rx,  e,     ll/2,    sx}; 
Point(x05) = {dx,    -e-rx, -ll/2,    sx};  Point(x15) = {dx,     e-rx,  ll/2,    sx}; 
Point(x06) = {dx,    -e,    -ll/2-lx, sx};  Point(x16) = {dx,     e,     ll/2+lx, sx}; 
Point(x07) = {dx+rx, -e,    -ll/2-lx, sx};  Point(x17) = {dx+rx,  e,     ll/2+lx, sx}; 
Point(x08) = {dx,    -e+rx, -ll/2-lx, sx};  Point(x18) = {dx,     e+rx,  ll/2+lx, sx}; 
Point(x09) = {dx-rx, -e,    -ll/2-lx, sx};  Point(x19) = {dx-rx,  e,     ll/2+lx, sx}; 
Point(x10) = {dx,    -e-rx, -ll/2-lx, sx};  Point(x20) = {dx,     e-rx,  ll/2+lx, sx}; 

Circle(x01) = {x02,x01,x03}; Circle(x05) = {x07,x06,x08}; Line(x09) = {x02,x07};
Circle(x02) = {x03,x01,x04}; Circle(x06) = {x08,x06,x09}; Line(x10) = {x03,x08};
Circle(x03) = {x04,x01,x05}; Circle(x07) = {x09,x06,x10}; Line(x11) = {x04,x09};
Circle(x04) = {x05,x01,x02}; Circle(x08) = {x10,x06,x07}; Line(x12) = {x05,x10};
       	       	     		    	    	    	       	       	   
Circle(x13) = {x12,x11,x13}; Circle(x17) = {x17,x16,x18}; Line(x21) = {x12,x17};
Circle(x14) = {x13,x11,x14}; Circle(x18) = {x18,x16,x19}; Line(x22) = {x13,x18};
Circle(x15) = {x14,x11,x15}; Circle(x19) = {x19,x16,x20}; Line(x23) = {x14,x19};
Circle(x16) = {x15,x11,x12}; Circle(x20) = {x20,x16,x17}; Line(x24) = {x15,x20};

Line Loop(x01) = {x02,x03,x04,x01};   Plane Surface(x21) = {x01};
Line Loop(x02) = {x07,x08,x05,x06};   Plane Surface(x22) = {x02};
Line Loop(x03) = {x16,x13,x14,x15};   Plane Surface(x23) = {x03};
Line Loop(x04) = {x20,x17,x18,x19};   Plane Surface(x24) = {x04};
Line Loop(x05) = {x08,-x09,-x04,x12}; Ruled Surface(x25) = {x05};
Line Loop(x06) = {x12,-x07,-x11,x03}; Ruled Surface(x26) = {x06};
Line Loop(x07) = {-x11,-x02,x10,x06}; Ruled Surface(x27) = {x07};
Line Loop(x08) = {-x10,-x01,x09,x05}; Ruled Surface(x28) = {x08};
Line Loop(x09) = {x21,-x20,-x24,x16}; Ruled Surface(x29) = {x09};
Line Loop(x10) = {-x24,-x15,x23,x19}; Ruled Surface(x30) = {x10};
Line Loop(x11) = {x23,-x18,-x22,x14}; Ruled Surface(x31) = {x11};
Line Loop(x12) = {x22,-x17,-x21,x13}; Ruled Surface(x32) = {x12};
*/

/* surface longerons */
Line Loop(3001) = {-13,-21,3,22};  Plane Surface(3101) = {3001}; /* ymax */
Line Loop(3002) = {23,-11,-24,1};  Plane Surface(3102) = {3002}; /* ymax - eps */
Line Loop(3003) = {-27,-7,26,17};  Plane Surface(3103) = {3003}; /* ymin + eps*/
Line Loop(3004) = {25,-15,-28,5};  Plane Surface(3104) = {3004}; /* ymin */
Line Loop(3005) = {3,4,1,2};       Plane Surface(3105) = {3005}; /* gauche haut */
Line Loop(3006) = {7,8,5,6};       Plane Surface(3106) = {3006}; /* gauche bas */
Line Loop(3007) = {11,12,13,14};   Plane Surface(3107) = {3007}; /* droite haut */
Line Loop(3008) = {18,15,16,17};   Plane Surface(3108) = {3008}; /* droite bas */
	   					  	
Line Loop(3009) = {-23,-9,26,19};  Plane Surface(3109) = {3009}; /* bouchon proche */
Line Loop(3010) = {24,-20,-27,10}; Plane Surface(3110) = {3010}; /* bouchon loin */
	   					  	
Line Loop(3011) = {-9,7,10,1};     Plane Surface(3111) = {3011}; /* input */
Line Loop(3012) = {-11,-20,-17,19};Plane Surface(3112) = {3012}; /* output */

Line Loop(3013) = {-26,-6,25,16};
Line Loop(3014) = {-28,-8,27,18};
Line Loop(3015) = {-21,-2,23,12};
Line Loop(3016) = {-24,-4,22,14};
Plane Surface(3113) = {3013,203,403,603,803,1003,1203,1403,1603,1803,2003,2203} ;
Plane Surface(3114) = {3014,101,301,501,701,901,1101,1301,1501,1701,1901,2101};
Plane Surface(3115) = {3015,103,303,503,703,903,1103,1303,1503,1703,1903,2103};
Plane Surface(3116) = {3016,201,401,601,801,1001,1201,1401,1601,1801,2001,2201};

/* surface boite interne */
Line Loop(4001) = {61,75,76,53};   Plane Surface(4101) = {4001};
Line Loop(4002) = {-54,-61,56,80}; Plane Surface(4102) = {4002};
Line Loop(4003) = {62,63,-54,75};  Plane Surface(4103) = {4003};
Line Loop(4004) = {-57,-62,76,64}; Plane Surface(4104) = {4004};
Line Loop(4005) = {-72,-64,53,56}; Plane Surface(4105) = {4005};
Line Loop(4006) = {80,-63,57,72};  Plane Surface(4106) = {4006};
Line Loop(4007) = {-52,-51,76,69}; Plane Surface(4107) = {4007};
Line Loop(4008) = {55,-62,51,78};  Plane Surface(4108) = {4008};
Line Loop(4009) = {74,-78,52,73};  Plane Surface(4109) = {4009};
Line Loop(4010) = {-81,-73,-69,64};Plane Surface(4110) = {4010};
Line Loop(4011) = {-57,-55,-74,81};Plane Surface(4111) = {4011};
Line Loop(4012) = {67,75,51,59};   Plane Surface(4112) = {4012};
Line Loop(4013) = {-71,-54,-67,70};Plane Surface(4113) = {4013};
Line Loop(4014) = {70,79,-78,59};  Plane Surface(4114) = {4014};
Line Loop(4015) = {55,63,71,79};   Plane Surface(4115) = {4015};
Line Loop(4016) = {61,-67,-68,77}; Plane Surface(4116) = {4016};
Line Loop(4017) = {70,82,-65,68};  Plane Surface(4117) = {4017};
Line Loop(4018) = {-58,-65,77,56}; Plane Surface(4118) = {4018};
Line Loop(4019) = {80,71,82,58};   Plane Surface(4119) = {4019};
Line Loop(4020) = {68,-59,52,60};  Plane Surface(4120) = {4020};
Line Loop(4021) = {66,-73,60,65};  Plane Surface(4121) = {4021};
Line Loop(4022) = {74,-79,82,66};  Plane Surface(4122) = {4022};
Line Loop(4023) = {-77,-60,-69,53};Plane Surface(4123) = {4023};
Line Loop(4024) = {-72,-81,-66,58};Plane Surface(4124) = {4024};

/* volume bouchon */

Surface Loop(4125) = {3103,-3110,-3102,-3109,3111,3112};
Complex Volume(4126) = {4125}; 

/* volume air */

Surface Loop(4127) = {4123,4116,-4101,4112,4107,4120};
Surface Loop(4128) = {2229,2232,2231,-2230,-3113,-3109,-3115,3101,3107,3112,-3110,-3116,-3105,3111,-3106,-3114,3104,3108,-127,126,-125,122,-128,-327,326,-325,322,-328,-527,526,-525,522,-528,-727,726,-725,722,-728,-927,926,-925,922,-928,-1127,1126,-1125,1122,-1128,-1327,1326,-1325,1322,-1328,-1527,1526,-1525,1522,-1528,-1727,1726,-1725,1722,-1728,-1927,1926,-1925,1922,-1928,-2127,2126,-2125,2122,-2128,-227,226,-225,222,-228,-427,426,-425,422,-428,-627,626,-625,622,-628,-827,826,-825,822,-828,-1027,1026,-1025,1022,-1028,-1227,1226,-1225,1222,-1228,-1427,1426,-1425,1422,-1428,-1627,1626,-1625,1622,-1628,-1827,1826,-1825,1822,-1828,-2027,2026,-2025,2022,-2028,-2227,2226,-2225,2222,-2228,129,132,131,-130,124,329,332,331,-330,324,529,532,531,-530,524,729,732,731,-730,724,929,932,931,-930,924,1129,1132,1131,-1130,1124,1329,1332,1331,-1330,1324,1529,1532,1531,-1530,1524,1729,1732,1731,-1730,1724,1929,1932,1931,-1930,1924,2129,2132,2131,-2130,2124,229,232,231,-230,224,429,432,431,-430,424,629,632,631,-630,624,829,832,831,-830,824,1029,1032,1031,-1030,1024,1229,1232,1231,-1230,1224,1429,1432,1431,-1430,1424,1629,1632,1631,-1630,1624,1829,1832,1831,-1830,1824,2029,2032,2031,-2030,2024,2224};
Complex Volume(4129) = {4127,4128};

/* volumes boite */

Surface Loop(4130) = {4101,4102,-4103,-4104,-4106,-4105}; Complex Volume(4131) = {4130}; /* Zm */
Surface Loop(4132) = {4113,4115,-4108,-4103,4112,-4114}; Complex Volume(4133) = {4132}; /* Xm */
Surface Loop(4134) = {4110,4111,-4104,4108,4107,4109}; Complex Volume(4135) = {4134}; /* Ym */
Surface Loop(4136) = {4118,4119,-4102,4113,-4116,-4117}; Complex Volume(4137) = {4136}; /* Yp */
Surface Loop(4138) = {4105,-4124,4110,-4121,-4123,-4118}; Complex Volume(4139) = {4138}; /* Xp */
Surface Loop(4140) = {4121,-4122,4109,-4114,4117,-4120}; Complex Volume(4141) = {4140}; /* Zp */

/* Surface et volume boite externe */

Line Loop(7021) = {-7013,-80,7019,7011};Plane Surface(7022) = {7021};
Line Loop(7023) = {-7014,63,7013,7004};Plane Surface(7024) = {7023};
Line Loop(7025) = {7020,7012,-7014,57};Plane Surface(7026) = {7025};
Line Loop(7027) = {-7009,-7020,72,7019};Plane Surface(7028) = {7027};
Line Loop(7029) = {-7012,7009,7011,7004};Plane Surface(7030) = {7029};
Line Loop(7031) = {-7015,55,7014,7001};Plane Surface(7032) = {7031};
Line Loop(7033) = {-7016,79,7015,7002};Plane Surface(7034) = {7033};
Line Loop(7035) = {-7013,71,7016,7003};Plane Surface(7036) = {7035};
Line Loop(7037) = {7003,7004,7001,7002};Plane Surface(7038) = {7037};
Line Loop(7039) = {-7018,81,7020,7008};Plane Surface(7040) = {7039};
Line Loop(7041) = {-7017,66,7018,7006};Plane Surface(7042) = {7041};
Line Loop(7043) = {-7017,58,7019,7010};Plane Surface(7044) = {7043};
Line Loop(7045) = {-7010,-7009,7008,7006};Plane Surface(7046) = {7045};
Line Loop(7047) = {7007,-7016,82,7017};Plane Surface(7048) = {7047};
Line Loop(7049) = {-7011,7010,7007,7003};Plane Surface(7050) = {7049};
Line Loop(7051) = {7015,7005,-7018,74};Plane Surface(7052) = {7051};
Line Loop(7053) = {7005,-7008,7012,7001};Plane Surface(7054) = {7053};
Line Loop(7055) = {7007,-7002,7005,7006};Plane Surface(7056) = {7055};

Surface Loop(7057) = {7036,7024,7032,7034,-4115,-7038}; Complex Volume(7058) = {7057}; /* XM */
Surface Loop(7059) = {7046,7044,-7042,-4124,-7028,-7040}; Complex Volume(7060) = {7059}; /* XP */
Surface Loop(7061) = {7054,-7052,-7032,-4111,-7026,7040}; Complex Volume(7062) = {7061}; /* YM */
Surface Loop(7063) = {7036,-7022,-4119,7048,-7050,7044}; Complex Volume(7064) = {7063}; /* YP */
Surface Loop(7065) = {4106,7022,7024,-7026,-7028,-7030}; Complex Volume(7066) = {7065}; /* ZM */
Surface Loop(7067) = {4122,-7052,7034,-7048,7056,-7042}; Complex Volume(7068) = {7067}; /* ZP */

/* physical entities */

AIR       = 8001 ;
XM        = 8002 ;
XP        = 8003 ;
YM        = 8004 ;
YP        = 8005 ;
ZM        = 8006 ;
ZP        = 8007 ;

CLINPUT   = 9001 ;
CLBOX     = 9002 ;
CLLONG    = 9003 ;
CLBARREAU = 9004 ;
CLBEM     = 9005 ;

Physical Volume (AIR) = {4126,4129,   4131,4133,4135,4137,4139,4141};
Physical Volume (XM) = {7058};
Physical Volume (XP) = {7060};
Physical Volume (YM) = {7062};
Physical Volume (YP) = {7064};
Physical Volume (ZM) = {7066};
Physical Volume (ZP) = {7068};

Physical Surface(CLINPUT) = {3111};
Physical Surface(CLBEM) = {4119,4106,4115,4111,4122,4124};
Physical Surface(CLBOX) = {7050,7030,7038,7054,7056,7046};
Physical Surface(CLLONG) = {3102,3115,3101,3116,3105,3107,3103,3114,3104,3113,3108,3106};
Physical Surface(CLBARREAU) = 
{ 
  122,125,126,127,128,
  124,129,130,131,132,
  222,225,226,227,228,
  224,229,230,231,232,
  322,325,326,327,328,
  324,329,330,331,332,
  422,425,426,427,428,
  424,429,430,431,432,
  522,525,526,527,528,
  524,529,530,531,532,
  622,625,626,627,628,
  624,629,630,631,632,
  722,725,726,727,728,
  724,729,730,731,732,
  822,825,826,827,828,
  824,829,830,831,832,
  922,925,926,927,928,
  924,929,930,931,932,
  1022,1025,1026,1027,1028,
  1024,1029,1030,1031,1032,
  1122,1125,1126,1127,1128,
  1124,1129,1130,1131,1132,
  1222,1225,1226,1227,1228,
  1224,1229,1230,1231,1232,
  1322,1325,1326,1327,1328,
  1324,1329,1330,1331,1332,
  1422,1425,1426,1427,1428,
  1424,1429,1430,1431,1432,
  1522,1525,1526,1527,1528,
  1524,1529,1530,1531,1532,
  1622,1625,1626,1627,1628,
  1624,1629,1630,1631,1632,
  1722,1725,1726,1727,1728,
  1724,1729,1730,1731,1732,
  1822,1825,1826,1827,1828,
  1824,1829,1830,1831,1832,
  1922,1925,1926,1927,1928,
  1924,1929,1930,1931,1932,
  2022,2025,2026,2027,2028,
  2024,2029,2030,2031,2032,
  2122,2125,2126,2127,2128,
  2124,2129,2130,2131,2132,
  2222,2225,2226,2227,2228,
  2224,2229,2230,2231,2232 
 };

