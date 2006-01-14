L = 0.25;
lclev = L / 4;

Point(1) = {0.0*L, 0.0*L,   0.0, lclev};

Extrude {L,0,0}{ Point{1}; }{ Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; }
Extrude {0,L/2,0}{ Line{1}; } { Layers { {5,10}, {2,2}, {0.7,1} } ; Recombine;  }
Extrude {0,0,L}{ Surface{5}; } { Layers { {5,10}, {3,3}, {0.7,1} } ; Recombine; }

Point(1000) = {1, 0, 0, lclev};
Extrude { {0,0,1} , {0.85,0,0} , -2*Pi/3 }{ Point{1000}; } {
  Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; 
}

Extrude { {0,0,1} , {0.85,0,0} , -2*Pi/3 }{ Point{1001}; } {
  Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; 
}
Extrude { {0,0,1} , {0.85,0,0} , -2*Pi/3 }{ Point{1003}; } {
  Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; 
}

Line Loop(31) = {29,30,28};
Plane Surface(32) = {31};
Extrude {0,0,L/2}{ Surface{32}; } {
  Layers { {5,10}, {1,1}, {0.7,1} } ; Recombine; 
}
