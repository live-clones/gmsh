Rext = 0.2 ;
Ep   = 0.02 ;
Rint = Rext - Ep;
RC   = 0.6     ;
LG   = 3.0    ;

h = 0.008;

Point(1) = {Rext, 0, 0, h};
Point(2) = {Rint, 0, 0, h};


Line(1) = {1,2};

Extrude Line {1,{0,1,0}, {0,0,0}, -Pi/2}
             {Layers{10,5,1}; Recombine; };

Extrude Line {2,{0,1,0}, {0,0,0}, -Pi/2}
             {Layers{10,9,1}; Recombine; };


Coherence;

Extrude Surface {5,{0,LG,0}}
                {Layers{50,2,1}; Recombine;  };


Extrude Surface {9,{0,LG,0}}
                {Layers{50,2,1}; Recombine;  };



Extrude Surface {31,{0,0,1}, {RC,LG,0}, -(Pi/2)}
                {Recombine ; Layers {30,52000,1}; };
Extrude Surface {53,{0,0,1}, {RC,LG,0}, -(Pi/2)}
                {Recombine ; Layers {30,530000,1}; };

Extrude Surface {75,{LG,0,0}}
                {Recombine; Layers{50,540000,1}; };
Extrude Surface {97,{LG,0,0}}
                {Recombine; Layers{50,550000,1}; };

