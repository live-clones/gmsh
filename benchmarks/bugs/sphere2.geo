
// se plante sous Linux qd on compile avec -O2

Mesh.Algorithm = 3;
Mesh.CharacteristicLengthFactor = 0.5;

r = 1;
boxlength = 14*r;
cl1 = .1*boxlength;
cl2 = .2*r;
nth = 15;
nphi = nth;
//they must be equal!


/*
r = 1;
boxlength = 20*r;
cl1 = .05*boxlength;
cl2 = .1*r;
nth = 15;
nphi = nth;
//they must be equal!
*/



temp1 = nth*nphi;

//points, 1000s
For t In {1:temp1}
  phinumber = Fmod(t-1,nth)+1;
  thnumber = ((t-(Fmod(t-1,nth)+1))/nth) + 1;
  phi =  (2*Pi/(nphi))*(phinumber-1);
  th = ((Pi)/(nth+1))*(thnumber);
  Point(1000+t) = {r*Sin(th)*Cos(phi),r*Sin(th)*Sin(phi),r*Cos(th),cl2};
EndFor

//lines in phi dir, 2000s
For t In {1:temp1}
  phinumber = Fmod(t-1,nth)+1;
  thnumber = ((t-(Fmod(t-1,nth)+1))/nth) + 1;
  tthp1 = (phinumber) + ((thnumber+1)-1)*nth;
  tphip1 = (phinumber+1) + ((thnumber)-1)*nphi;
  tphiback = (1) + ((thnumber)-1)*nphi;
  If (phinumber < nphi) 
    Line(2000 + t) = {1000 + t,1000 + tphip1};
  EndIf
  If (phinumber == nphi)
    Line(2000 + t) = {1000+t, 1000 + tphiback}; 
  EndIf 
EndFor

//lines in th dir, 3000s
For t In {1:temp1}
  phinumber = Fmod(t-1,nth)+1;
  thnumber = ((t-(Fmod(t-1,nth)+1))/nth) + 1;
  tthp1 = (phinumber) + ((thnumber+1)-1)*nth;
  tphip1 = (phinumber+1) + ((thnumber)-1)*nphi;
  tphiback = (1) + ((thnumber)-1)*nphi;
  If (thnumber < nth) 
    Line(3000 + t) = {1000 + t,1000 + tthp1};
  EndIf
EndFor

//computer gen all surface but the ends
//line loops 4000, planes 5000
For t In {1:temp1}
  phinumber = Fmod(t-1,nth)+1;
  thnumber = ((t-(Fmod(t-1,nth)+1))/nth) + 1;
  tthp1 = (phinumber) + ((thnumber+1)-1)*nth;
  tphip1 = (phinumber+1) + ((thnumber)-1)*nphi;
  tphiback = (1) + ((thnumber)-1)*nphi;
  tphibackp1 = (2) + ((thnumber)-1)*nphi;
  If ((thnumber < nth) && (phinumber < nphi)) 
    Line Loop(4000 + t) = {3000 + t,2000 + tthp1, -(3000 + tphip1), -(2000 + t)};
    Plane Surface(5000 + t) = {4000 + t}; 
  EndIf
  If ((thnumber < nth) && (phinumber == nphi))
    Line Loop(4000 + t) = {3000 + t,2000 + tthp1, -(3000 + tphiback), -(2000 + t)};
    Plane Surface(5000 + t) = {4000 + t}; 
  EndIf 
EndFor


//Extra stuff, like ends is 6000
tv1 = 2000 + nth;
tv2 = 2000 + (nth)*(nth-1) + 1;
tv3 = 2000 + nth^2;
tv4 = 5000 + (nth)*(nth-1);
Line Loop(6001) = {2001:tv1};
Line Loop(6002) = {tv2:tv3};
Plane Surface(6003) = {6001};
Plane Surface(6004) = {6002};
Surface Loop(6005) = {5001:tv4,6003,6004};


//oh, and a box to keep it in


Point(1) = {boxlength/2,-boxlength/2,-boxlength/2,cl1};
Point(2) = {boxlength/2,boxlength/2,-boxlength/2,cl1};
Point(3) = {-boxlength/2,boxlength/2,-boxlength/2,cl1};
Point(4) = {-boxlength/2,-boxlength/2,-boxlength/2,cl1};

Point(5) = {boxlength/2,-boxlength/2,boxlength/2,cl1};
Point(6) = {boxlength/2,boxlength/2,boxlength/2,cl1};
Point(7) = {-boxlength/2,boxlength/2,boxlength/2,cl1};
Point(8) = {-boxlength/2,-boxlength/2,boxlength/2,cl1};

Line(9) = {1,2};
Line(10) = {2,3};
Line(11) = {3,4};
Line(12) = {4,1};

Line(13) = {5,6};
Line(14) = {6,7};
Line(15) = {7,8};
Line(16) = {8,5};

Line(17) = {2,6};
Line(18) = {3,7};
Line(19) = {4,8};
Line(20) = {1,5};


Line Loop(21) = {9,17,-13,-20};
Line Loop(22) = {10,18,-14,-17};
Line Loop(23) = {11,19,-15,-18};
Line Loop(24) = {12,20,-16,-19};
Line Loop(25) = {9,10,11,12};
Line Loop(26) = {13,14,15,16};

Plane Surface(27) = {21};
Plane Surface(28) = {22};
Plane Surface(29) = {23};
Plane Surface(30) = {24};
Plane Surface(31) = {25};
Plane Surface(32) = {26};

Physical Surface(36) = {27};
Physical Surface(37) = {28};
Physical Surface(38) = {29};
Physical Surface(39) = {30};
Physical Surface(40) = {31};
Physical Surface(41) = {32};

Surface Loop(33) = {27,28,29,30,31,32};

Volume(34) = {33,6005};
Volume(6006) = {6005};
Physical Volume(35) = {34};
Physical Volume(6007) = {6006};
