// Obdelnikovy vzorek, ctvercove kontakty 
// jednoduchy model

m=0.1;

delka=150;
sirka=20;

sirkak=2;

rohx1=1;
rohy1=1;

rohx2=delka-sirkak-1;
rohy2=1;

rohx3=delka-sirkak-1;
rohy3=sirka-sirkak-1;

rohx4=1;
rohy4=sirka-sirkak-1;


// Vzorek
Point(1)= {0,0,0,m};
Point(2)= {delka,0,0,m};
Point(3)= {delka,sirka,0,m};
Point(4)= {0,sirka,0,m};

Line(1)= {1,2};
Line(2)= {2,3};
Line(3)= {3,4};
Line(4)= {4,1};

Line Loop(1)={1,2,3,4};

//////////////////////////////////
// Kontakt 1

Point(5)= {rohx1,rohy1,0,m};
Point(6)= {rohx1+sirkak,rohy1,0,m};
Point(7)= {rohx1+sirkak,rohy1+sirkak,0,m};
Point(8)= {rohx1,rohy1+sirkak,0,m};

Line(5)= {5,6};
Line(6)= {6,7};
Line(7)= {7,8};
Line(8)= {8,5};

Line Loop(2)={5,6,7,8};
Plane Surface(2)={2};

////////////////////////////////////
//// Kontakt 2

Point(9)= {rohx2,rohy2,0,m};
Point(10)= {rohx2+sirkak,rohy2,0,m};
Point(11)= {rohx2+sirkak,rohy2+sirkak,0,m};
Point(12)= {rohx2,rohy2+sirkak,0,m};

Line(9)= {9,10};
Line(10)= {10,11};
Line(11)= {11,12};
Line(12)= {12,9};

Line Loop(3)={9,10,11,12};
Plane Surface(3)={3};

////////////////////////////////////
// Kontakt 3

Point(13)= {rohx3,rohy3,0,m};
Point(14)= {rohx3+sirkak,rohy3,0,m};
Point(15)= {rohx3+sirkak,rohy3+sirkak,0,m};
Point(16)= {rohx3,rohy3+sirkak,0,m};

Line(13)= {13,14};
Line(14)= {14,15};
Line(15)= {15,16};
Line(16)= {16,13};

Line Loop(4)={13,14,15,16};
Plane Surface(4)={4};

////////////////////////////////////
//// Kontakt 4

Point(17)= {rohx4,rohy4,0,m};
Point(18)= {rohx4+sirkak,rohy4,0,m};
Point(19)= {rohx4+sirkak,rohy4+sirkak,0,m};
Point(20)= {rohx4,rohy4+sirkak,0,m};

Line(17)= {17,18};
Line(18)= {18,19};
Line(19)= {19,20};
Line(20)= {20,17};

Line Loop(5)={17,18,19,20};
Plane Surface(5)={5};
Plane Surface(1)={1,2,3,4,5};
Coherence;

Physical Surface (1001) = {2};
Physical Surface (1002) = {3};
Physical Surface (1003) = {4};
Physical Surface (1004) = {5};

Physical Surface (1000) = {1};

