lc = 0.1;

Point(1)={0.0,0.0,0.0,lc};
Point(2)={1.0,0.0,0.0,lc};

Line(1)={1,2};

Extrude Line { 1, {0,0.1,0.0} }
{ Layers { {10,10}, {10,20}, {0.2,1} };
 Recombine;
};

Extrude Point { 1, {0,-0.2,-0.3} }
{ Layers { {10,10}, {11,21}, {0.2,1} }; };


Extrude Surface{ 5, {0,0.1,0.6}}
{ Layers { {10,10}, {110,210}, {0.2,1} }; Recombine; };
