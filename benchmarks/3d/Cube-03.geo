/*****************************
Another Way to generate
a cube
*****************************/
Point(1) = {0.0,0.0,0.0,.2};
Extrude {1,0.0,0} { Point{1}; }
Extrude {0.0,0.0,1} { Line{1}; }
Extrude {0,1,0} { Surface{5}; }
Physical Volume(28) = {1};
