mm = 0.001 ; // 1 milimetre = 0.001 metre
lc = 3*mm ; // unite de base min pour la taille caracteristique du maillage

lcpba   =   lc ;        // lc plaques base centrale et laterale 


// Definition de la plaque base centrale

r1pbc = 3*mm;
r2pbc = 5*mm;
r3pbc = 19.75*mm;
r4pbc = 18*mm;
e1pbc = 2*mm;
e2pbc = 4*mm;
e3pbc = 6.2*mm;

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

Point(17)   = { -r1pbc ,    0.0   ,    0.0      ,  lcpba  };  
Point(18)   = { -r2pbc ,    0.0   ,    0.0      ,  lcpba  };
Point(19)   = { -r2pbc ,    0.0   ,   e1pbc     ,  lcpba  };
Point(20)   = { -r3pbc ,    0.0   ,   e1pbc     ,  lcpba  };
Point(21)   = { -r3pbc ,    0.0   ,   e2pbc      ,  lcpba  };  
Point(22)   = { -r4pbc ,    0.0   ,   e2pbc      ,  lcpba  }; 
Point(23)   = { -r4pbc ,    0.0   ,   e3pbc      ,  lcpba  }; 
Point(24)   = { -r1pbc ,    0.0   ,   e3pbc      ,  lcpba  }; 

Point(25)   = { 0.0  ,    -r1pbc   ,    0.0      ,  lcpba  };  
Point(26)   = { 0.0  ,    -r2pbc   ,    0.0      ,  lcpba  };
Point(27)   = { 0.0  ,    -r2pbc   ,   e1pbc     ,  lcpba  };
Point(28)   = { 0.0  ,    -r3pbc   ,   e1pbc     ,  lcpba  };
Point(29)   = { 0.0  ,    -r3pbc   ,   e2pbc      ,  lcpba  };  
Point(30)   = { 0.0  ,    -r4pbc   ,   e2pbc      ,  lcpba  }; 
Point(31)   = { 0.0  ,    -r4pbc   ,   e3pbc      ,  lcpba  }; 
Point(32)   = { 0.0  ,    -r1pbc   ,   e3pbc      ,  lcpba  }; 


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

Circle(48) = {9,centre1,17};
Circle(49) = {10,centre1,18};
Circle(50) = {11,centre2,19};
Circle(51) = {12,centre2,20};
Circle(52) = {13,centre3,21};
Circle(53) = {14,centre3,22};
Circle(54) = {15,centre4,23};
Circle(55) = {16,centre4,24};

Circle(56) = {17,centre1,25};
Circle(57) = {18,centre1,26};
Circle(58) = {19,centre2,27};
Circle(59) = {20,centre2,28};
Circle(60) = {21,centre3,29};
Circle(61) = {22,centre3,30};
Circle(62) = {23,centre4,31};
Circle(63) = {24,centre4,32};

Circle(64) = {25,centre1,1};
Circle(65) = {26,centre1,2};
Circle(66) = {27,centre2,3};
Circle(67) = {28,centre2,4};
Circle(68) = {29,centre3,5};
Circle(69) = {30,centre3,6};
Circle(70) = {31,centre4,7};
Circle(71) = {32,centre4,8};

Line(72)={2,3};
Line(73)={4,5};
Line(74)={6,7};
Line(75)={8,1};
Line(76)={18,19};
Line(77)={20,21};
Line(78)={22,23};
Line(79)={24,17};
Line(80)={10,11};
Line(81)={12,13};
Line(82)={14,15};
Line(83)={16,9};
Line(84)={26,27};
Line(85)={28,29};
Line(86)={30,31};
Line(87)={32,25};


// Definition de la plaque base laterale

r1pbl = 60*mm;
r2pbl = 74*mm;

Point(91)   = { r1pbl ,    0.0   ,   e1pbc      ,  lcpba  };  
Point(92)   = { r2pbl ,    0.0   ,   e1pbc      ,  lcpba  };
Point(93)   = { r2pbl ,    0.0   ,   e3pbc     ,  lcpba  };
Point(94)   = { r1pbl ,    0.0   ,   e3pbc     ,  lcpba  };

Point(95)   = { 0.0 ,    r1pbl   ,   e1pbc      ,  lcpba  };  
Point(96)   = { 0.0 ,    r2pbl   ,   e1pbc      ,  lcpba  };
Point(97)   = { 0.0 ,    r2pbl   ,   e3pbc     ,  lcpba  };
Point(98)   = { 0.0 ,    r1pbl   ,   e3pbc     ,  lcpba  };

Point(99)   = { -r1pbl ,    0.0   ,   e1pbc      ,  lcpba  };  
Point(100)   = { -r2pbl ,    0.0   ,   e1pbc      ,  lcpba  };
Point(101)   = { -r2pbl ,    0.0   ,   e3pbc     ,  lcpba  };
Point(102)   = { -r1pbl ,    0.0   ,   e3pbc     ,  lcpba  };

Point(103)   = { 0.0 ,    -r1pbl   ,   e1pbc      ,  lcpba  };  
Point(104)   = { 0.0 ,    -r2pbl   ,   e1pbc      ,  lcpba  };
Point(105)   = { 0.0 ,    -r2pbl   ,   e3pbc     ,  lcpba  };
Point(106)   = { 0.0 ,    -r1pbl   ,   e3pbc     ,  lcpba  };

Circle(107) = {91,centre2,95};
Circle(108) = {92,centre2,96};
Circle(109) = {93,centre4,97};
Circle(110) = {94,centre4,98};

Circle(111) = {95,centre2,99};
Circle(112) = {96,centre2,100};
Circle(113) = {97,centre4,101};
Circle(114) = {98,centre4,102};

Circle(115) = {99,centre2,103};
Circle(116) = {100,centre2,104};
Circle(117) = {101,centre4,105};
Circle(118) = {102,centre4,106};

Circle(119) = {103,centre2,91};
Circle(120) = {104,centre2,92};
Circle(121) = {105,centre4,93};
Circle(122) = {106,centre4,94};

Line(123)={92,93};
Line(124)={94,91};
Line(125)={100,101};
Line(126)={102,99};
Line(127)={96,97};
Line(128)={98,95};
Line(129)={104,105};
Line(130)={106,103};

//introduction aimants

LFom=21*mm; lcFom=lc ;L1Fom=7*mm;
h1Fom=13*mm;R1Fom=26*mm;R2Fom=35*mm;angle=30*Pi/180;
xFom=39*mm;yFom=-10.5*mm;zFom=15*mm;
thetarot[]={0,60,120,180,240,300,0};

For i In {1:6}
iFom=i;
theta=thetarot[i];
Include "forme1.geo";
EndFor

// definition des surfaces

surfpbc1=newreg;
Line Loop(surfpbc1)={41,65,57,49};
surfpbc2=newreg;
Line Loop(surfpbc2)={40,64,56,48};
Plane Surface(surfpbc1+1)={surfpbc1,surfpbc2};
surfpbc3=newreg;
Line Loop(surfpbc3)={80,41,-72,-42};
Ruled Surface(surfpbc3+1)={surfpbc3};
surfpbc4=newreg;
Line Loop(surfpbc4)={72,65,-84,-66};
Ruled Surface(surfpbc4+1)={surfpbc4};
surfpbc5=newreg;
Line Loop(surfpbc5)={84,57,-76,-58};
Ruled Surface(surfpbc5+1)={surfpbc5};
surfpbc6=newreg;
Line Loop(surfpbc6)={76,49,-80,-50};
Ruled Surface(surfpbc6+1)={surfpbc6};
surfpbc7=newreg;
Line Loop(surfpbc7)={43,67,59,51};
surfpbc8=newreg;
Line Loop(surfpbc8)={42,66,58,50};
Plane Surface(surfpbc7+1)={surfpbc7,surfpbc8,Fomes_LineLoop5[{1:6}]};
surfpbc9=newreg;
Line Loop(surfpbc9)={81,43,-73,-44};
Ruled Surface(surfpbc9+1)={surfpbc9};
surfpbc10=newreg;
Line Loop(surfpbc10)={73,67,-85,-68};
Ruled Surface(surfpbc10+1)={surfpbc10};
surfpbc11=newreg;
Line Loop(surfpbc11)={85,59,-77,-60};
Ruled Surface(surfpbc11+1)={surfpbc11};
surfpbc12=newreg;
Line Loop(surfpbc12)={77,51,-81,-52};
Ruled Surface(surfpbc12+1)={surfpbc12};
surfpbc13=newreg;
Line Loop(surfpbc13)={44,52,60,68};
surfpbc14=newreg;
Line Loop(surfpbc14)={45,53,61,69};
Plane Surface(surfpbc13+1)={surfpbc13,surfpbc14};
surfpbc15=newreg;
Line Loop(surfpbc15)={74,46,-82,-45};
Ruled Surface(surfpbc15+1)={surfpbc15};
surfpbc16=newreg;
Line Loop(surfpbc16)={82,54,-78,-53};
Ruled Surface(surfpbc16+1)={surfpbc16};
surfpbc17=newreg;
Line Loop(surfpbc17)={78,62,-86,-61};
Ruled Surface(surfpbc17+1)={surfpbc17};
surfpbc18=newreg;
Line Loop(surfpbc18)={86,70,-74,-69};
Ruled Surface(surfpbc18+1)={surfpbc18};
surfpbc19=newreg;
Line Loop(surfpbc19)={46,54,62,70};
surfpbc20=newreg;
Line Loop(surfpbc20)={47,55,63,71};
Plane Surface(surfpbc20+1)={surfpbc19,surfpbc20};
surfpbc21=newreg;
Line Loop(surfpbc21)={75,40,-83,-47};
Ruled Surface(surfpbc21+1)={surfpbc21};
surfpbc22=newreg;
Line Loop(surfpbc22)={83,48,-79,-55};
Ruled Surface(surfpbc22+1)={surfpbc22};
surfpbc23=newreg;
Line Loop(surfpbc23)={79,56,-87,-63};
Ruled Surface(surfpbc23+1)={surfpbc23};
surfpbc24=newreg;
Line Loop(surfpbc24)={87,64,-75,-71};
Ruled Surface(surfpbc24+1)={surfpbc24};


surfpbl1=newreg;
Line Loop(surfpbl1)={120,116,112,108};
surfpbl2=newreg;
Line Loop(surfpbl2)={119,115,111,107};
Plane Surface(surfpbl2+1)={surfpbl1,surfpbl2,Fomes_LineLoop2[{1:6}]};
surfpbl3=newreg;
Line Loop(surfpbl3)={123,109,-127,-108};
Ruled Surface(surfpbl3+1)={surfpbl3};
surfpbl4=newreg;
Line Loop(surfpbl4)={127,113,-125,-112};
Ruled Surface(surfpbl4+1)={surfpbl4};
surfpbl5=newreg;
Line Loop(surfpbl5)={125,117,-129,-116};
Ruled Surface(surfpbl5+1)={surfpbl5};
surfpbl6=newreg;
Line Loop(surfpbl6)={129,121,-123,-120};
Ruled Surface(surfpbl6+1)={surfpbl6};
surfpbl7=newreg;
Line Loop(surfpbl7)={109,113,117,121};
surfpbl8=newreg;
Line Loop(surfpbl8)={110,114,118,122};
Plane Surface(surfpbl8+1)={surfpbl7,surfpbl8};
surfpbl9=newreg;
Line Loop(surfpbl9)={124,107,-128,-110};
Ruled Surface(surfpbl9+1)={surfpbl9};
surfpbl10=newreg;
Line Loop(surfpbl10)={128,111,-126,-114};
Ruled Surface(surfpbl10+1)={surfpbl10};
surfpbl11=newreg;
Line Loop(surfpbl11)={126,115,-130,-118};
Ruled Surface(surfpbl11+1)={surfpbl11};
surfpbl12=newreg;
Line Loop(surfpbl12)={130,119,-124,-122};
Ruled Surface(surfpbl12+1)={surfpbl12};

volpbc=newreg;
Surface Loop(volpbc)={surfpbc1+1,surfpbc3+1,surfpbc4+1,surfpbc5+1,surfpbc6+1,surfpbc7+1,surfpbc9+1,surfpbc10+1,surfpbc11+1,surfpbc12+1,surfpbc13+1,surfpbc15+1,surfpbc16+1,surfpbc17+1,surfpbc18+1,surfpbc20+1,surfpbc21+1,surfpbc22+1,surfpbc23+1,surfpbc24+1,Fomes_Surf5[{1:6}]};
Volume(volpbc+1)={volpbc};


volpbl=newreg;
Surface Loop(volpbl)={surfpbl2+1,surfpbl3+1,surfpbl4+1,surfpbl5+1,surfpbl6+1,surfpbl8+1,surfpbl9+1,surfpbl10+1,surfpbl11+1,surfpbl12+1,Fomes_Surf2[{1:6}]};
Volume(volpbl+1)={volpbl};
Printf("num %g",volpbl+1);

// definition des entites physiques


Physical Surface(7776)={surfpbc1+1,surfpbc3+1,surfpbc4+1,surfpbc5+1,surfpbc6+1,surfpbc7+1,surfpbc9+1,surfpbc10+1,surfpbc11+1,surfpbc12+1,surfpbc13+1,surfpbc15+1,surfpbc16+1,surfpbc17+1,surfpbc18+1,surfpbc20+1,surfpbc21+1,surfpbc22+1,surfpbc23+1,surfpbc24+1};

Physical Surface(7777)={surfpbl2+1,surfpbl3+1,surfpbl4+1,surfpbl5+1,surfpbl6+1,surfpbl8+1,surfpbl9+1,surfpbl10+1,surfpbl11+1,surfpbl12+1};
Physical Surface(7778)={Fomes_Surf1[{1:6}],Fomes_Surf2[{1:6}],Fomes_Surf3[{1:6}],Fomes_Surf4[{1:6}],Fomes_Surf5[{1:6}],Fomes_Surf6[{1:6}],Fomes_Surf7[{1:6}],Fomes_Surf8[{1:6}],Fomes_Surf9[{1:6}],Fomes_Surf10[{1:6}],Fomes_Surf11[{1:6}]};


