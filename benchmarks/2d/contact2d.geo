unit = 1.e-2;
size = 0.1 * unit;

Point(1) = {4.8*unit,0.8*unit,0, size};
Point(2) = {4.8*unit,1.2*unit,0, size/2};
Point(3) = {4.8*unit,1.4*unit,0, size/2};
Point(4) = {4*unit,1.4*unit,0, size/2};
Point(5) = {4*unit,1.2*unit,0, size/2};
Point(6) = {3.5*unit,1.2*unit,0, size};
Point(7) = {2.1*unit,0.4*unit,0, size*2};
Point(8) = {0,0.4*unit,0, size*2};
Point(9) = {0,0,0, size*2};
Point(10) = {2.2*unit,0,0, size*2};
Point(11) = {3.6*unit,0.8*unit,0, size};
Point(13) = {0.0445,0.008,0,size};
Point(15) = {0.0435,0.008,0,size};
Point(16) = {0.0435,0.012,0,size/4};
Point(18) = {0.0445,0.012,0,size/4};
Point(19) = {0.058,0.008,0,size};
Point(20) = {0.058,0.010,0,size};
Point(21) = {0.048,0.010,0,size}; 
Point(22) = {0.0435,0.01,0,size/4};
Point(23) = {0.0445,0.01,0,size/4};


Line(1) = {9,10};
Line(2) = {10,11};
Line(3) = {11,15};
Line(4) = {15,22};
Line(5) = {22,23};
Line(6) = {23,13};
Line(7) = {13,1};
Line(8) = {1,19};
Line(9) = {19,20};
Line(10) = {20,21};
Line(11) = {21,2};
Line(12) = {2,18};
Line(13) = {18,16};
Line(14) = {16,5};
Line(15) = {5,6};
Line(16) = {6,7};
Line(17) = {7,8};
Line(18) = {8,9};
Line(19) = {5,4};
Line(20) = {4,3};
Line(21) = {3,2};
Line(22) = {22,16};
Line(23) = {23,18};
Line Loop(24) = {15,16,17,18,1,2,3,4,22,14};
Plane Surface(25) = {24};
Line Loop(26) = {23,13,-22,5};
Plane Surface(27) = {26};
Line Loop(28) = {12,-23,6,7,8,9,10,11};
Plane Surface(29) = {28};
Line Loop(30) = {14,19,20,21,12,13};
Plane Surface(31) = {30};

/* entree flux */
/* pastille */
/* contact fixe */
/* contact fixe ou air */

Physical Line(1000) = {20};   
Physical Surface(2000) = {31};  
Physical Surface(3000) = {25,29};
Physical Surface(3001) = {27};

