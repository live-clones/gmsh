L = 0.25;
lclev = L / 4;

Point(1) = {0.0*L, 0.0*L,   0.0, lclev};

Extrude Point {1, {L,0,0}}{ Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; };
Extrude Line {1, {0,L/2,0}}{ Layers { {5,10}, {2,2}, {0.7,1} } ; Recombine;  };
Extrude Surface {5, {0,0,L}}{ Layers { {5,10}, {3,3}, {0.7,1} } ; Recombine; };

Physical Volume(111) = {3};
