lc = 1;
dext = 1;
dint = 0.2;
angle = Pi/4;
nbdiv = 2;

Point(1) = {0,0,0,lc};  
Point(2) = {dint,0,0,lc};
Point(3) = {0,dint,0,lc};
Point(4) = {dint*Sin(angle),0,Cos(angle)*dint,lc};
Point(5) = {dext,0,0,lc};
Point(6) = {0,dext,0,lc};
Point(7) = {dext*Sin(angle),0,Cos(angle)*dext,lc};

Circle(1) = {7,1,5};
Circle(2) = {4,1,2};
Circle(3) = {5,1,6};
Circle(4) = {2,1,3};
Circle(5) = {7,1,6};
Circle(6) = {4,1,3};
Line(8) = {5,2};
Line(10) = {6,3};
Line(12) = {7,4};

Line Loop(17) = {2,-8,-1,12};
Plane Surface(18) = {17};
Line Loop(19) = {-4,-8,3,10};
Plane Surface(20) = {19};
Line Loop(21) = {-6,-12,5,10};
Plane Surface(22) = {21};

Line Loop(23) = {-6,2,4};
Ruled Surface(24) = {23};
Line Loop(25) = {-5,1,3};
Ruled Surface(26) = {25};

Surface Loop(27) = {24,-22,-18,20,-26};
Complex Volume(28) = {27};

Transfinite Line {1,2,3,4,5,6} = nbdiv+1 ;
Transfinite Line {-8,-10,-12} = nbdiv+1 ;

Transfinite Surface {22} = {3,4,7,6};
Transfinite Surface {20} = {3,2,5,6};
Transfinite Surface {18} = {4,2,5,7};

Transfinite Surface {24} = {3,4,2};
Transfinite Surface {26} = {6,7,5};

Transfinite Volume {28} = {3,4,2,6,7,5};
