L = 0.25;
lclev = L / 4;

Point(1) = {0.0*L, 0.0*L,   0.0, lclev};

Extrude Point {1, {L,0,0}}{ Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; };
Extrude Line {1, {0,L/2,0}}{ Layers { {5,10}, {2,2}, {0.7,1} } ; Recombine;  };
Extrude Surface {5, {0,0,L}}{ Layers { {5,10}, {3,3}, {0.7,1} } ; Recombine; };

Point(1000) = {1, 0, 0, lclev};
Extrude Point {1000, {0,0,1} , {0.85,0,0} , -2*Pi/3 }{
  Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; 
};
Extrude Point {1001, {0,0,1} , {0.85,0,0} , -2*Pi/3 }{
  Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; 
};
Extrude Point {1003, {0,0,1} , {0.85,0,0} , -2*Pi/3 }{
  Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; 
};

Line Loop(31) = {29,30,28};
Plane Surface(32) = {31};
Extrude Surface {32, {0,0,L/2}}{
  Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; 
};
