Rext = 0.2 ;
Ep   = 0.02 ;
Rint = Rext - Ep;
RC   = 0.6     ;
LG   = 3.0    ;

h = 0.008;

Point(1) = {Rext, 0, 0, h};
Point(2) = {Rint, 0, 0, h};


Line(1) = {1,2};

Extrude { {0,1,0}, {0,0,0}, -Pi/2}{ Line {1}; Layers{10}; Recombine; }
Extrude { {0,1,0}, {0,0,0}, -Pi/2}{ Line {2}; Layers{10}; Recombine; }
Extrude {0,LG,0}{ Surface {5}; Layers{50}; Recombine; }
Extrude {0,LG,0}{ Surface {9}; Layers{50}; Recombine; }
Extrude { {0,0,1}, {RC,LG,0}, -(Pi/2)}{ Surface {31}; Recombine ; Layers{30}; }
Extrude { {0,0,1}, {RC,LG,0}, -(Pi/2)}{ Surface {53}; Recombine ; Layers{30}; }
Extrude {LG,0,0}{ Surface {75}; Recombine; Layers{50}; }
Extrude {LG,0,0}{ Surface {97}; Recombine; Layers{50}; }
