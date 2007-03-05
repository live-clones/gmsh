// a sphere
lc = .2;
Point(1) = {0.0,0.0,0.0,lc}; 
Point(2) = {0.5,0.0,0.0,lc};
Point(3) = {0,0.5,0.0,lc}; 
Point(4) = {-0.5,0,0.0,lc};
Point(5) = {0,-0.5,0.0,lc}; 
Point(6) = {0,0,-0.5,lc};
Point(7) = {0,0,0.5,lc};
Circle(1) = {2,1,3};
Circle(2) = {3,1,4};
Circle(3) = {4,1,5};
Circle(4) = {5,1,2};
Circle(5) = {3,1,6};
Circle(6) = {6,1,5};
Circle(7) = {5,1,7};
Circle(8) = {7,1,3};
Circle(9) = {2,1,7};
Circle(10) = {7,1,4};
Circle(11) = {4,1,6};
Circle(12) = {6,1,2};
Line Loop(13) = {-2,-8,10}; Ruled Surface(14) = {13};
Line Loop(15) = {10,3,7}; Ruled Surface(16) = {15};
Line Loop(17) = {-8,-9,1}; Ruled Surface(18) = {17};
Line Loop(19) = {-11,-2,5}; Ruled Surface(20) = {19};
Line Loop(21) = {5,12,1}; Ruled Surface(22) = {21};
Line Loop(23) = {-3,11,6}; Ruled Surface(24) = {23};
Line Loop(25) = {-7,4,9}; Ruled Surface(26) = {25};
Line Loop(27) = {4,-12,6}; Ruled Surface(28) = {27};
Surface Loop(29) = {-28,26,16,-14,20,24,-22,18};

// a structured box around it, with its mesh carved out
Point(10000) = {-2, -2, -2, lc};
Point(10001) = {2, -2, -2, lc};
Line(10000) = {10000, 10001};
Transfinite Line{10000} = 20;
tmp[] = Extrude {0, 4, 0} { Line{10000}; Layers{20}; };
tmp[] = Extrude {0, 0, 4} { Surface{tmp[1]}; Layers{20}; 
  Hole(20000) = {28,26,16,14,20,24,22,18} Using 0.5;
};

Surface Loop(30001) = 20000;
Volume(30002) = {30001, 29};
