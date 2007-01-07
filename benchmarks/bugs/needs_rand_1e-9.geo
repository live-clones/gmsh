//Mesh.Algorithm = 1;
//Mesh.CharacteristicLengthFactor = 1;
Geometry.AutoCoherence = 1;

u = 1e-3;

FEM = 0; /* 0->Hybrid model, 1->FEM model */ 

a=u* 1000;
b=u* 1;
c=u* 400;
d=u* 150;
R=u* 30;                   // radius conductors
ym = u* -250;               // vertical offset of circular ring
M =u* 1000*Sqrt(0.5);       // circular ring inner boundary
m =u* 1500*Sqrt(0.5);       // circular ring outerr boundary


eh1 =u* 0.5;
ev1 =u* 0.5*2;
eh2 =u* 1.5;
ev2 =u* 1.5*2;
eh3 =u* 4.5;
ev3 =u* 4.5*2;



p =u* 2;
pe1 =u* 2; 
pe2 =u* 5; 
pe3 =u* 10; 

p =u* 2;
pe1 =u* 2; 
pe2 =u* 5; 
pe3 =u* 10; 

pu=u*6*3.6;

pM1=4*pu;//4 /* For refining FEM mesh */
pM2=4*pu;
pc=pu/3;


b1=0;
b2=-b/4;
b3=-b/2;
b4=-3*b/4;
b5=-b;

Point(1) = {-a/2,b1+ym,0,p};
Point(2) = {-a/2,b2+ym,0,p};
Point(3) = { a/2,b1+ym,0,p};
Point(4) = { a/2,b2+ym,0,p};
Point(5) = {-a/2,b3+ym,0,p};
Point(6) = { a/2,b3+ym,0,p};
Point(7) = {-a/2,b4+ym,0,p};
Point(8) = { a/2,b4+ym,0,p};
Point(9) = {-a/2,b5+ym,0,p};
Point(10) = { a/2,b5+ym,0,p};

Line(701) = {2,4};
Line(703) = {4,3};
Line(704) = {3,1};
Line(705) = {1,2};

Line(901) = {2,5};
Line(902) = {5,6};
Line(903) = {6,4};

Line(913) = {5,7};
Line(914) = {7,8};
Line(915) = {6,8};
Line(916) = {8,10};
Line(917) = {10,9};
Line(918) = {9,7};


Line Loop(714) = {705,701,703,704};
Plane Surface(715) = {714};

Line Loop(904) = {-903,-902,-901,701};
Plane Surface(905) = {904};

Line Loop(919) = {914,-915,-902,913};
Plane Surface(920) = {919};

Line Loop(921) = {914,916,917,918};
Plane Surface(922) = {921};


Fpc = 100;
If (FEM)
  Fpc = 1;
EndIf


Point(11) = {-c/2+R/2,-b-d+ym+R/2,0,pc*Fpc};
Point(12) = {-c/2+R/2,-b-d+ym-R/2,0,pc*Fpc};
Point(13) = {-c/2-R/2,-b-d+ym+R/2,0,pc*Fpc};
Point(14) = {-c/2-R/2,-b-d+ym-R/2,0,pc*Fpc};

Point(21) = {R/2,-b-d+ym+R/2,0,pc*Fpc};
Point(22) = {R/2,-b-d+ym-R/2,0,pc*Fpc};
Point(23) = {-R/2,-b-d+ym+R/2,0,pc*Fpc};
Point(24) = {-R/2,-b-d+ym-R/2,0,pc*Fpc};

Point(31) = {c/2+R/2,-b-d+ym+R/2,0,pc*Fpc};
Point(32) = {c/2+R/2,-b-d+ym-R/2,0,pc*Fpc};
Point(33) = {c/2-R/2,-b-d+ym+R/2,0,pc*Fpc};
Point(34) = {c/2-R/2,-b-d+ym-R/2,0,pc*Fpc};


Line(1) = {12,11};
Line(2) = {11,13};
Line(3) = {13,14};
Line(4) = {14,12};
Line(5) = {22,21};
Line(6) = {21,23};
Line(7) = {23,24};
Line(8) = {24,22};
Line(9) = {32,31};
Line(10) = {31,33};
Line(11) = {33,34};
Line(12) = {34,32};



Line Loop(906) = {1,2,3,4};
Plane Surface(907) = {906};
Line Loop(908) = {5,6,7,8};
Plane Surface(909) = {908};
Line Loop(910) = {9,10,11,12};
Plane Surface(911) = {910};




Point(501) = {-a/2-eh1,b1+ym+ev1,0,pe1};
Point(502) = {-a/2-eh1,b5+ym-ev1,0,pe1};
Point(503) = {0,b1+ym+ev1,0,pe1};
Point(504) = {0,b5+ym-ev1,0,pe1};
Point(505) = {a/2+eh1,b1+ym+ev1,0,pe1};
Point(506) = {a/2+eh1,b5+ym-ev1,0,pe1};
Point(507) = {-a/2-eh1,ym+(b1+b5)/2,0,pe1/1};
Point(508) = {a/2+eh1,ym+(b1+b5)/2,0,pe1/1};


Line(100003) = {502,507};
Line(100004) = {501,503};
Line(100005) = {503,505};
Line(100006) = {505,508};
Line(100007) = {506,504};
Line(100008) = {504,502};
Line(100009) = {507,501};
Line(100010) = {508,506};

Point(601) = {-a/2-eh2,b1+ym+ev2,0,pe2};
Point(602) = {-a/2-eh2,b5+ym-ev2,0,pe2};
Point(603) = {0,b1+ym+ev2,0,pe2};
Point(604) = {0,b5+ym-ev2,0,pe2};
Point(605) = {a/2+eh2,b1+ym+ev2,0,pe2};
Point(606) = {a/2+eh2,b5+ym-ev2,0,pe2};
Point(607) = {-a/2-eh2,ym+(b1+b5)/2,0,pe2/1};
Point(608) = {a/2+eh2,ym+(b1+b5)/2,0,pe2/1};

Line(200003) = {602,607};
Line(200004) = {601,603};
Line(200005) = {603,605};
Line(200006) = {605,608};
Line(200007) = {606,604};
Line(200008) = {604,602};
Line(200009) = {607,601};
Line(200010) = {608,606};



Point(701) = {-a/2-eh3,b1+ym+ev3,0,pe3};
Point(702) = {-a/2-eh3,b5+ym-ev3,0,pe3};
Point(703) = {0,b1+ym+ev3,0,pe3};
Point(704) = {0,b5+ym-ev3,0,pe3};
Point(705) = {a/2+eh3,b1+ym+ev3,0,pe3};
Point(706) = {a/2+eh3,b5+ym-ev3,0,pe3};
Point(707) = {-a/2-eh3,ym+(b1+b5)/2,0,pe3/1};
Point(708) = {a/2+eh3,ym+(b1+b5)/2,0,pe3/1};

Line(300003) = {702,707};
Line(300004) = {701,703};
Line(300005) = {703,705};
Line(300006) = {705,708};
Line(300007) = {706,704};
Line(300008) = {704,702};
Line(300009) = {707,701};
Line(300010) = {708,706};






Line Loop(100009) = {100004,100005,100006,100007,100008,100003,100009,100010};
Line Loop(100010) = {703,704,705,901,913,-918,-917,-916,-915,903};
Plane Surface(100011) = {100009,100010};

Line Loop(200009) = {200004,200005,200006,200007,200008,200003,200009,200010};
Line Loop(300009) = {300004,300005,300006,300007,300008,300003,300009,300010};

Plane Surface(200011) = {200009,100009};
Plane Surface(300011) = {300009,200009};

AirLayer1 = 1000;
Physical Surface(AirLayer1) = {100011}; // AirLayer1
SkinAirLayer1 = 1500 ;
Physical Line(SkinAirLayer1) = {100004,100003,100008,100007,100006,100005,100009,100010}; // SkinAirLayer1

AirLayer2 = 2000 ;
Physical Surface(AirLayer2) = {200011}; // AirLayer2
SkinAirLayer2 = 2500 ;
Physical Line(SkinAirLayer2) = {200004,200003,200008,200007,200006,200005,200009,200010}; // SkinAirLayer2

AirLayer3 = 3000 ;
Physical Surface(AirLayer3) = {300011}; // AirLayer3
SkinAirLayer3 = 3500 ;
Physical Line(SkinAirLayer3) = {300004,300003,300008,300007,300006,300005,300009,300010}; // SkinAirLayer3

ym2 = u* 0;

If (FEM)

Point(0) = {0,-ym2,0,p};

Point(100) = {M,M-ym2,0,pM1};
Point(101) = {-M,-M-ym2,0,pM1};
Point(102) = {-M,M-ym2,0,pM1};
Point(103) = {M,-M-ym2,0,pM1};

Point(200) = {m,m-ym2,0,pM2};
Point(201) = {-m,-m-ym2,0,pM2};
Point(202) = {-m,m-ym2,0,pM2};
Point(203) = {m,-m-ym2,0,pM2};

Circle(25) = {103,0,100};
Circle(26) = {100,0,102};
Circle(27) = {102,0,101};
Circle(28) = {101,0,103};
Circle(35) = {203,0,200};
Circle(36) = {200,0,202};
Circle(37) = {202,0,201};
Circle(38) = {201,0,203};

Line Loop(307) = {37,38,35,36};
Line Loop(720) = {27,28,25,26};

Line Loop(923) = {913,-918,-917,-916,-915,903,703,704,705,901};

EndIf

Physical Surface(100) = {907}; // left conductor
Physical Surface(150) = {909}; // middle conductor
Physical Surface(200) = {911}; // right conductor

//Recombine Surface {715,905,920,922};
Plate = 300 ;
Physical Surface(Plate) = {715,905,920,922}; // plate 

Physical Line(700) = {-1,-2,-3,-4}; // SkinLeft
Physical Line(750) = {-5,-6,-7,-8}; // SkinMid
Physical Line(800) = {-9,-10,-11,-12}; // SkinRight
SkinPlate = 900 ;
Physical Line(SkinPlate) = {-704,-705,-901,918,917,916,915,-903,-703,-913}; // SkinPlate


If (FEM)
Plane Surface(722) = {307,720};
Plane Surface(924) = {720,300009,906,908,910}; // air

Physical Surface(400) = {924}; // air
RingIn = 500 ;
RingOut = 600 ;
Physical Surface(RingIn) = {722}; // ring
Physical Line(RingOut) = {35,36,37,38}; // outer boundary

EndIf








//Post Processing
xt1=0.8; 
xt2=0.6; 
yt1=ym+0.5; 
yt2=ym+1.0; 


Point(10001) = {xt1,yt1,0,p};
Point(10002) = {-xt1,yt1,0,p};
Point(10003) = {xt2,yt2,0,p};
Point(10004) = {-xt2,yt2,0,p};

Line(100001) = {10001,10002};
Line(100002) = {10003,10004};


