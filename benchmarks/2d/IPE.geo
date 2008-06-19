LC   = t/2;
LC2  = r/4;

Point(1) = {-c,-h/2,0,LC};
Point(2) = {-c,-h/2+t,0,LC};
Point(3) = {-t/2-r,-h/2+t,0,LC2};
Point(4) = {-t/2,-h/2+t+r,0,LC2};
Point(5) = {-t/2-r,-h/2+t+r,0,LC2};

Point(11) = {-c,h/2,0,LC};
Point(12) = {-c,h/2-t,0,LC};
Point(13) = {-t/2-r,h/2-t,0,LC2};
Point(14) = {-t/2,h/2-t-r,0,LC2};
Point(15) = {-t/2-r,h/2-t-r,0,LC2};

Point(21) = {c,-h/2,0,LC};
Point(22) = {c,-h/2+t,0,LC};
Point(23) = {t/2+r,-h/2+t,0,LC2};
Point(24) = {t/2,-h/2+t+r,0,LC2};
Point(25) = {t/2+r,-h/2+t+r,0,LC2};

Point(31) = {c,h/2,0,LC};
Point(32) = {c,h/2-t,0,LC};
Point(33) = {t/2+r,h/2-t,0,LC2};
Point(34) = {t/2,h/2-t-r,0,LC2};
Point(35) = {t/2+r,h/2-t-r,0,LC2};


Line(1) = {1,21};
Line(2) = {21,22};
Line(3) = {22,23};
Line(4) = {1,2};
Line(5) = {2,3};
Line(6) = {4,14};
Line(7) = {34,24};
Line(8) = {11,31};
Line(9) = {31,32};
Line(10) = {32,33};
Line(11) = {11,12};
Line(12) = {12,13};
Circle(13) = {13,15,14};
Circle(14) = {33,35,34};
Circle(15) = {3,5,4};
Circle(16) = {23,25,24};
Line Loop(17) = {-7,-14,-10,-9,-8,11,12,13,-6,-15,-5,-4,1,2,3,16};
Plane Surface(18) = {17};
Physical Line(19) = {8,9,10,14,7,16,3,2,1,4,5,15,6,13,12,11};
Physical Surface(20) = {18};
