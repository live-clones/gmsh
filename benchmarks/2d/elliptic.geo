
lc = 0.007 ;

Point(1) = {0,  0,  0, 9.e-1 * lc} ;
Point(2) = {.1, 0,  0, lc} ;
Point(3) = {.1, .3, 0, lc} ;
Point(4) = {0,  .3, 0, lc} ;
Line(1) = {1,2} ;
Line(2) = {3,2} ;
Line(3) = {3,4} ;
Line(4) = {4,1} ;
Line Loop(5) = {4,1,-2,3} ;
Plane Surface(6) = {5} ;

Transfinite Line{2,4} = 30 ;
Transfinite Line{1,3} = 30 Using Progression 1.08;
Transfinite Surface{6} = {1,2,3,4};
Recombine Surface{6};

Translate {0.2,0.0,0.0} {
  Duplicata { Surface{6}; }
}

Transfinite Line{8,10} = 30 ;
Transfinite Line{9,11} = 30 Using Progression 1.08;

Transfinite Surface{7} = {6,10,14,5};
Recombine Surface{7};

Extrude Surface {7, {0.0,0.0,0.1}}{Layers{10,1,1};Recombine;};

Mesh.Smoothing  = 30;
