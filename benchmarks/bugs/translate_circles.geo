mm=0.001;
rh=8*mm;
rc=30*mm;
lc=3*mm;

Point(1)={0,0,0,lc};
Point(2)={0,rh,0,lc};
Point(3)={0,-rh,0,lc};
Point(4)={rh,0,0,lc};
Point(5)={-rh,0,0,lc};

Point(6)={0,rc,0,lc};
Point(7)={0,-rc,0,lc};
Point(8)={rc,0,0,lc};
Point(9)={-rc,0,0,lc};

Circle(1) = {5,1,2};
Circle(2) = {2,1,4};
Circle(3) = {4,1,3};
Circle(4) = {3,1,5};
Circle(5) = {9,1,6};
Circle(6) = {6,1,8};
Circle(7) = {8,1,7};
Circle(8) = {7,1,9};
Translate {20*mm,0,0} {  Duplicata {Line{2,3,4,1};}}
Rotate {{0,0,1}, {0,0,0}, Pi/3} {  Duplicata { Line{9,10,11,12}; }}
Rotate {{0,0,1}, {0,0,0}, Pi/3} {Duplicata { Line{16,13,14,15}; }}
Rotate {{0,0,1}, {0,0,0}, Pi/3} {Duplicata { Line{17,18,19,20}; }}
Rotate {{0,0,1}, {0,0,0}, Pi/3} {Duplicata { Line{24,23,22,21}; }}
Rotate {{0,0,1}, {0,0,0}, Pi/3} {Duplicata { Line{28,25,26,27}; }}

Dilate {{0,0,0}, 0.5} {Duplicata { Line{8,5,6,7}; }}

Translate {0,0,30*mm} {Line{33};}//When I do this , lines 1,2,3,4 and 5,6,7,8 come along . Very strange ( penny lane)
