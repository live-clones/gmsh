lcp = 10;  
lci = 10;  
  
/* Plaque */  
  
Point(1) = {0,0,0,lcp};  
Point(2) = {294,0,0,lcp};  
Point(3) = {294,294,0,lcp};  
Point(4) = {0,294,0,lcp};  
Point(5) = {0,294,19,lcp};  
Point(6) = {294,294,19,lcp};  
Point(7) = {294,0,19,lcp};  
Point(8) = {0,0,19,lcp};  
Point(9) = {18,18,19,lcp};  
Point(10) = {18,18,0,lcp};  
Point(11) = {126,18,0,lcp};  
Point(12) = {126,18,19,lcp};  
Point(13) = {126,126,19,lcp};  
Point(14) = {126,126,0,lcp};  
Point(15) = {18,126,0,lcp};  
Point(16) = {18,126,19,lcp};  
  
Line(1) = {4,3};  
Line(2) = {3,2};  
Line(3) = {2,1};  
Line(4) = {1,4};  
Line(5) = {5,6};  
Line(6) = {6,7};  
Line(7) = {7,8};  
Line(8) = {8,5};  
Line(9) = {15,14};  
Line(10) = {14,11};  
Line(11) = {11,10};  
Line(12) = {10,15};  
Line(13) = {16,13};  
Line(14) = {13,12};  
Line(15) = {12,9};  
Line(16) = {9,16};  
Line(17) = {4,5};  
Line(18) = {3,6};  
Line(19) = {2,7};  
Line(20) = {1,8};  
Line(21) = {10,9};  
Line(22) = {15,16};  
Line(23) = {14,13};  
Line(24) = {11,12};  
  
Line Loop(25) = {5,-18,-1,17};  
Plane Surface(26) = {25};  
Line Loop(27) = {-17,-4,20,8};  
Plane Surface(28) = {27};  
Line Loop(29) = {20,-7,-19,3};  
Plane Surface(30) = {29};  
Line Loop(31) = {6,-19,-2,18};  
Plane Surface(32) = {31};  
Line Loop(33) = {1,2,3,4};  
Line Loop(34) = {9,10,11,12};  
Plane Surface(35) = {33,34};  
Line Loop(36) = {5,6,7,8};  
Line Loop(37) = {13,14,15,16};  
Plane Surface(38) = {36,37};  
  
/* Inducteur */  
  
Point(17) = {94,50,49,lci};  
Point(18) = {94,150,49,lci};  
  
Point(19) = {119,50,49,lci};  
Point(20) = {119,150,49,lci};  
  
Point(21) = {144,0,49,lci};  
Point(22) = {144,25,49,lci};  
Point(23) = {144,50,49,lci};  
Point(24) = {144,150,49,lci};  
Point(25) = {144,175,49,lci};  
Point(26) = {144,200,49,lci};  
  
Point(27) = {244,0,49,lci};  
Point(28) = {244,25,49,lci};  
Point(29) = {244,50,49,lci};  
Point(30) = {244,150,49,lci};  
Point(31) = {244,175,49,lci};  
Point(32) = {244,200,49,lci};  
  
Point(33) = {269,50,49,lci};  
Point(34) = {269,150,49,lci};  
  
Point(35) = {294,50,49,lci};  
Point(36) = {294,150,49,lci};  
  
  
Circle(39) = {25,24,20};  
Circle(40) = {26,24,18};  
Circle(41) = {19,23,22};  
Circle(42) = {17,23,21};  
Circle(43) = {28,29,33};  
Circle(44) = {27,29,35};  
Circle(45) = {34,30,31};  
Circle(46) = {36,30,32};  
Line(47) = {31,32};  
Line(48) = {32,26};  
Line(49) = {26,25};  
Line(50) = {25,31};  
Line(51) = {20,18};  
Line(52) = {18,17};  
Line(53) = {17,19};  
Line(54) = {19,20};  
Line(55) = {22,21};  
Line(56) = {21,27};  
Line(57) = {27,28};  
Line(58) = {28,22};  
Line(59) = {33,35};  
Line(60) = {35,36};  
Line(61) = {36,34};  
Line(62) = {34,33};  
  
Line Loop(63) = {48,49,50,47};  
Plane Surface(64) = {63};  
Line Loop(65) = {-47,-45,-61,46};  
Plane Surface(66) = {65};  
Line Loop(67) = {61,62,59,60};  
Plane Surface(68) = {67};  
Line Loop(69) = {-59,-43,-57,44};  
Plane Surface(70) = {69};  
Line Loop(71) = {58,55,56,57};  
Plane Surface(72) = {71};  
Line Loop(73) = {-42,53,41,55};  
Plane Surface(74) = {73};  
Line Loop(75) = {52,53,54,51};  
Plane Surface(76) = {75};  
Line Loop(77) = {-51,-39,-49,40};  
Plane Surface(78) = {77};  
  
Extrude(64, {0,0,100});  
Coherence;  
Extrude(78, {0,0,100});  
Coherence;  
Extrude(76, {0,0,100});  
Coherence;  
Extrude(74, {0,0,100});  
Coherence;  
Extrude(72, {0,0,100});  
Coherence;  
Extrude(70, {0,0,100});  
Coherence;  
Extrude(68, {0,0,100});  
Coherence;  
Extrude(66, {0,0,100});  
Coherence;  
  
Line Loop(207) = {-13,-22,9,23};  
Plane Surface(208) = {207};  
Line Loop(209) = {-22,-12,21,16};  
Plane Surface(210) = {209};  
Line Loop(211) = {15,-21,-11,24};  
Plane Surface(212) = {211};  
Line Loop(213) = {24,-14,-23,10};  
Plane Surface(214) = {213};  
  
Delete { 
 Surface(117); 
} 
Delete { 
 Surface(143); 
} 
Delete { 
 Surface(179); 
} 
Delete { 
 Surface(205); 
} 
Delete { 
 Surface(227); 
} 
Delete { 
 Surface(249); 
} 
