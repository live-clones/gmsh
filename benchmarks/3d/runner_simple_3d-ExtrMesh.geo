/*simple runner for 3d-studies;  07.07.1999/hm*/  

// good test for the coherence of extruded surface mesh shared between
// two volumes
  
/*variables*/  
r=0.004;  
a=0.005;  
b=0.005;  
m=0.010;  
mh=0.020;  
  
h1=0.005;  
h2=0.005;  
h3=0.005;  
h4=0.005;  
hl = 0.012;  
f   =0.015;  
l   =0.040;  
  
lc1 = 0.002;  
  
/*points*/  
  
Point(1) = {-r,0.0,0.0,lc1};  
  
Point(2) = {0,0.0,0.0,lc1};  
  
Point(3) = {+r,0.0,0.0,lc1};  
Point(4) = {r+a,0.0,0.0,lc1};  
Point(5) = {r+a+b,0.0,0.0,lc1};  
Point(6) = {r+a+b,-h4,0.0,lc1};  
  
Point(11) = {-r,h1,0.0,lc1};  
  
Point(13) = {+r,h1,0.0,lc1};  
Point(14) = {r+a,h2,0.0,lc1};  
Point(15) = {r+a+b,h3,0.0,lc1};  
  
/*flange*/  
  
Point(25) = {r+a+b+f,0,0.0,lc1};  
Point(26) = {r+a+b+f,h3,0.0,lc1};  
Point(27) = {r+a+b+f,-h4,0.0,lc1};  
Point(28) = {r+a+b+f,-hl,0.0,lc1};  
  
/*laminate*/  
  
Point(30) = {r+a+b+f+l,0.0,0.0,lc1};  
Point(31) = {r+a+b+f+l,h3,0.0,lc1};  
Point(32) = {r+a+b+f+l,-h4,0.0,lc1};  
Point(33) = {r+a+b+f+l,-hl,0.0,lc1};  
  
/*lines*/  
  
Circle(100) = {1,2,3};  
  
Line(101) = {1,11};  
Line(102) = {11,13};  
Line(103) = {13,14};  
Line(104) = {14,15};  
Line(105) = {3,13};  
Line(106) = {3,4};  
Line(107) = {4,14};  
Line(108) = {4,5};  
Line(109) = {5,15};  
  
  
  
Line(110) = {15,26};  
Line(111) = {5,25};  
Line(112) = {6,27};  
Line(113) = {5,6};  
Line(114) = {26,25};  
Line(115) = {25,27};  
Line(116) = {26,31};  
Line(117) = {25,30};  
Line(118) = {27,32};  
Line(119) = {31,30};  
Line(120) = {30,32};  
  
Line(121) = {27,28};  
Line(122) = {28,33};  
Line(123) = {32,33};  
  
Line Loop(300) = {-102,-101,100,105};  
Plane Surface(301) = {300};  
Line Loop(400) = {107,-103,-105,106};  
Plane Surface(401) = {400};  
Line Loop(402) = {109,-104,-107,108};  
Plane Surface(403) = {402};  
  
  
Line Loop(404) = {-114,-110,-109,111};  
Plane Surface(405) = {404};  
Line Loop(406) = {-112,-113,111,115};  
Plane Surface(407) = {406};  
Line Loop(408) = {117,-119,-116,114};  
Plane Surface(409) = {408};  
Line Loop(410) = {118,-120,-117,115};  
Plane Surface(411) = {410};  
Line Loop(412) = {118,123,-122,-121};  
Plane Surface(413) = {412};  
  
/*mould*/  
  
Point(511) = {-m,h1,0.0,lc1};  
Point(512) = {-m,h1-mh,0.0,lc1};  
Point(533) = {r+a+b+f+l,h1-mh,0.0,lc1};  
  
Line(614) = {511,512};  
Line(615) = {511,11};  
Line(616) = {512,533};  
Line(617) = {533,33};  
/*  
Line Loop(618) = {-617,-616,-614,615,-101,100,106,108,113,112,121,122,-617,-616,-614,615,-
101,100,106,108,113,112};*/  
  
Line Loop(618) = {-617,-616,-614,615,-101,100,106,108,113,112,121,122};  
Plane Surface(619) = {618};  
  
ex = .05;

Extrude Surface{619, {0.0,0.0,ex}}{ Layers{ {10}, {1}, {1} };  };  
Coherence;  
Extrude Surface{301, {0.0,0.0,ex}}{ Layers{ {10}, {1}, {1} };  };  
Coherence;  
Extrude Surface{401, {0.0,0.0,ex}}{ Layers{ {10}, {1}, {1} };  };  
Coherence;  
Extrude Surface{403, {0.0,0.0,ex}}{ Layers{ {10}, {1}, {1} };  };  
Coherence;  
Extrude Surface{405, {0.0,0.0,ex}}{ Layers{ {10}, {1}, {1} };  };  
Coherence;  
Extrude Surface{407, {0.0,0.0,ex}}{ Layers{ {10}, {1}, {1} };  };  
Coherence;  
Extrude Surface{409, {0.0,0.0,ex}}{ Layers{ {10}, {1}, {1} };  };  
Coherence;  
Extrude Surface{411, {0.0,0.0,ex}}{ Layers{ {10}, {1}, {1} };  };  
Coherence;  
Extrude Surface{413, {0.0,0.0,ex}}{ Layers{ {10}, {1}, {1} };  };  
Coherence;  
 
Physical Volume(1) = {1};
Physical Surface(2) = {652,656,702,660,664,734,790,791,756,676,680,848,636,826,804};
 
