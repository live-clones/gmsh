

// 
Ep =2.5e-3;
Lx = 500e-3;
Ly=200e-3;
R1=5e-3;
R2=10e-3;
xR=Lx/4;
pi=3.14159;


// characteristic length
l1 = Ep*10;
l2 = R1*10;
nh=2;
n1 = 5;
n2=26;
n3=51;
n4=101;

// Quadrillage
Point(1) = {0,0,0,l1};
Point(2) = {-Ly,0,0,l1};
Point(3) = {-Ly,0,-Lx,l1};
Point(4) = {0,0,-Lx,l1};
Point(5) = {0,0,-(xR-1.5*R1),l2};
Point(6) = {-1.5*R1,0,-(xR-1.5*R1),l2};
Point(7) = {-Ly,0,-(xR-1.5*R1),l2};
Point(8) = {0,0,-(xR+1.5*R1),l2};
Point(9) = {-1.5*R1,0,-(xR+1.5*R1),l2};
Point(10) = {-Ly,0,-(xR+1.5*R1),l2};
Point(11) = {-1.5*R1,0,0,l2};
Point(12) = {-1.5*R1,0,-Lx,l2};
// Points de la zone source
Point(20)={0,0,-xR,l2};
Point(21)={0,0,-(xR+R1),l2};
Point(22)={-R1*Sin(pi/3),0,-(xR+R1*Cos(pi/3)),l2};
Point(23)={-R1*Sin(pi/3),0,-(xR-R1*Cos(pi/3)),l2};
Point(24)={0,0,-(xR-R1),l2};
//Point(25)={0,0,-(xR+R2),l2};
//Point(26)={-R2*Sin(pi/3),0,-(xR+R2*Cos(pi/3)),l2};
//Point(27)={-R2*Sin(pi/3),0,-(xR-R2*Cos(pi/3)),l2};
//Point(28)={0,0,-(xR-R2),l2};
Point(40)={-R1/2*Sin(pi/3),0,-(xR+R1/2*Cos(pi/3)),l2};
Point(41)={-R1/2*Sin(pi/3),0,-(xR-R1/2*Cos(pi/3)),l2};
Point(42)={0,0,-(xR+R1/2*Cos(pi/3)),l2};
Point(43)={0,0,-(xR-R1/2*Cos(pi/3)),l2};
Line(1)={1,5};
Line(2)={5,6};
Line(3)={6,11};
Line(4)={11,1};
Line(5)={6,7};
Line(6)={7,2};
Line(7)={2,11};
Line(8)={6,9};
Line(9)={9,10};
Line(10)={10,7};
Line(12)={9,12};
Line(13)={12,3};
Line(14)={3,10};
Line(16)={8,4};
Line(17)={4,12};
Line(18)={9,8};
//Line(20)={5,28};
//Line(22)={27,6};
//Line(24)={26,9};
//Line(26)={25,8};
Line(30)={5,24};
Line(32)={23,6};
Line(34)={22,9};
Line(36)={21,8};
Line(40)={21,42};
Line(41)={42,43};
Line(42)={43,24};
Line(43)={43,41};
Line(44)={41,40};
Line(45)={40,42};
Line(46)={41,23};
Line(47)={40,22};
//Circle(21) = {28,20,27};
//Circle(23) = {27,20,26};
//Circle(25) = {26,20,25};
Circle(31) = {24,20,23};
Circle(33) = {23,20,22};
Circle(35) = {22,20,21};
// Construction des surfaces
Line Loop(1) = {1,2,3,4};
Line Loop(2) = {-3,5,6,7};
Line Loop(3) = {8,9,10,-5};
Line Loop(4) = {12,13,14,-9};
Line Loop(5) = {16,17,-12,18};
//Line Loop(6) = {20,21,22,-2};
//Line Loop(7) = {23,24,-8,-22};
//Line Loop(8) = {26,-18,-24,25};
Line Loop(9) = {30,31,32,-2};
Line Loop(10) = {33,34,-8,-32};
Line Loop(11) = {36,-18,-34,35};
Line Loop(20) = {-42,43,46,-31};
Line Loop(21) = {44,47,-33,-46};
Line Loop(22) = {45,-40,-35,-47};
Line Loop(23) = {-41,-45,-44,-43};
Plane Surface(1)={1};
Plane Surface(2)={2};
Plane Surface(3)={3};
Plane Surface(4)={4};
Plane Surface(5)={5};
//Plane Surface(6)={6};
//Plane Surface(7)={7};
//Plane Surface(8)={8};
Plane Surface(9)={9};
Plane Surface(10)={10};
Plane Surface(11)={11};
Plane Surface(20)={20};
Plane Surface(21)={21};
Plane Surface(22)={22};
Plane Surface(23)={23};


// Definition du maillage regle
// Zone source
Transfinite Line{2,8,18,30:36} = n1;
Transfinite Surface{9} = {24,23,6,5};
Recombine Surface{9};
c1[]=Extrude {0,Ep,0} {
   Surface{9}; Layers{nh,1}; Recombine;
 };
Transfinite Surface{10} = {23,22,9,6};
Recombine Surface{10};
c2[]=Extrude {0,Ep,0} {
   Surface{10}; Layers{nh,1}; Recombine;
 }; 
Transfinite Surface{11} = {21,8,9,22};
Recombine Surface{11};
c3[]=Extrude {0,Ep,0} {
   Surface{11}; Layers{nh,1}; Recombine;
 };
Transfinite Line{40:47} = n1; 
Transfinite Surface{20} = {24,43,41,23};
Recombine Surface{20};
s1[]=Extrude {0,Ep,0} {
   Surface{20}; Layers{nh,1}; Recombine;
 } ;
Transfinite Surface{21} = {41,40,22,23};
Recombine Surface{21};
s2[]=Extrude {0,Ep,0} {
   Surface{21}; Layers{nh,1}; Recombine;
 } ;
Transfinite Surface{22} = {42,21,22,40};
Recombine Surface{22};
s3[]=Extrude {0,Ep,0} {
   Surface{22}; Layers{nh,1}; Recombine;
 } ;
Transfinite Surface{23} = {43,42,40,41};
Recombine Surface{23};
s4[]=Extrude {0,Ep,0} {
   Surface{23}; Layers{nh,1}; Recombine;
 } ;   
// Autres regions  
// Transfinite Surface{6} = {5,28,27,6};
// Recombine Surface{6};
// a1[]=Extrude {0,Ep,0} {
//    Surface{6}; Layers{nh,1}; Recombine;
//  } ;
// Transfinite Surface{7} = {27,26,9,6};
// Recombine Surface{7};
// a2[]=Extrude {0,Ep,0} {
//    Surface{7}; Layers{nh,1}; Recombine;
//  };
// Transfinite Surface{8} = {25,8,9,26};
// Recombine Surface{8};
// a3[]=Extrude {0,Ep,0} {
//    Surface{8}; Layers{nh,1}; Recombine;
//  } ;  
// Autres regions 
Transfinite Line{1,3,6} = n2;
Transfinite Line{4,10,17} = n1;
Transfinite Line{5,7,9,13} = n3;
Transfinite Line{12,14,16} = n4;
Transfinite Surface{1} = {1,5,6,11};
Recombine Surface{1};
a4[]=Extrude {0,Ep,0} {
   Surface{1}; Layers{nh,1}; Recombine;
 }; 
Transfinite Surface{2} = {11,6,7,2};
Recombine Surface{2};
a5[]=Extrude {0,Ep,0} {
   Surface{2}; Layers{nh,1}; Recombine;
 };   
Transfinite Surface{3} = {6,9,10,7};
Recombine Surface{3};
a6[]=Extrude {0,Ep,0} {
   Surface{3}; Layers{nh,1}; Recombine;
 };  
Transfinite Surface{4} = {9,12,3,10};
Recombine Surface{4};
a7[]=Extrude {0,Ep,0} {
   Surface{4}; Layers{nh,1}; Recombine;
 }; 
Transfinite Surface{5} = {8,4,12,9};
Recombine Surface{5};
a8[]=Extrude {0,Ep,0} {
   Surface{5}; Layers{nh,1}; Recombine;
 } ;     


Physical Volume(101) = {s1[1],s2[1],s3[1],s4[1]}; // Source
Physical Volume(100) = {c1[1],c2[1],c3[1],a4[1],a5[1],a6[1],a7[1],a8[1]}; // Tout_sauf_Source
Physical Surface(200)={244};//Entree 
