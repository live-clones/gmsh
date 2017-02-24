/*****************************
A cube with a hole
*****************************/

Point(1) = {0.0,0.0,0.0,.1};
Extrude {1,0.0,0} { Point{1}; }
Extrude {0.0,0.0,1} { Line{1}; }
aa[] = Extrude {0,1,0} { Surface{5}; };

Point(100) = {0.3,0.3,0.3,.1};
Extrude {.4,0.0,0} { Point{100}; }
Extrude {0,0.4,0} { Line {28}; }
Coherence;
bb[] = Extrude {0,0.,0.4} { Surface {32}; };
Coherence;

Delete { Volume{aa[1],bb[1]}; }

Surface Loop(55) = {26,5,14,18,22,27};
Surface Loop(56) = {41,32,45,49,53,54};
Volume(57) = {55,56};
