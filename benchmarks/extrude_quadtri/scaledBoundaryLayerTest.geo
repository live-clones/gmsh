//set options
Geometry.Surfaces=1;
Mesh.SurfaceFaces=1;
Mesh.RecombinationAlgorithm = 0;
Mesh.RemeshAlgorithm = 1;
Mesh.Algorithm=6; // mesh algorithm
Mesh.Algorithm3D=4; // mesh algorithm
Geometry.AutoCoherence = 1;
Geometry.OldRuledSurface=1;
  
  
curve_radius = .50;

Point(newp) = { 0.0, 0.0, 0.0};
Point(newp) = { 1.0, 0.0, 0.20};
Point(newp) = { 2.0, 0.0, 0.0};
Point(newp) = { 1.0, 1.0, 0.20};
Point(newp) = { 2.0, 1.0, 0.0};
Point(newp) = { 0.0, 1.0, 0.0};

Point(newp) = { 1.0, 0.5, -curve_radius};

Line (newl) = { 1, 2 };
Line (newl) = { 2, 3 };
Circle (newl) = { 2, 7, 4 };
Line (newl) = { 4, 6 };
Line (newl) = { 5, 4 };
Line (newl) = { 3, 5 };
Line (newl) = { 6, 1 };

Transfinite Line { 3 } = 20;
Transfinite Line { 1 } = 10 Using Progression 0.8;
Transfinite Line { 2 } = 10 Using Progression 1/.8;
Transfinite Line { 4, 5, 6, 7 } = 10;

Line Loop (newll) = {1, 3,4,7};
Line Loop (newll) = {2, 6, 5,-3};

Surface (news) = { 8 };
Surface (news) = { 9 };
Recombine Surface {news-2, news-1};

Extrude { Surface { 10}; Layers{{1,1},{0.05,1.2}}; Recombine; Using Index[0]; ScaleLastLayer; QuadTriAddVerts;}
Extrude { Surface { 11}; Layers{{1,1},{0.05,1.2}}; Recombine;  Using Index[0]; ScaleLastLayer; QuadTriAddVerts;}


// A third surface to show that when not connected to the previous two surfaces, a surface in the same boundary layer
// can be meshed normally without ScaleLastLayer and still be valid.
Point (newp) = { -1, 0, 0 };
Point (newp) = { -1, 1 ,0};
Point (newp) = { -2, 1, 0};
Point (newp) = { -2, 0, 0};
Line (newl) = { newp-4, newp-3};
Line (newl) = { newp-3, newp-2};
Line (newl) = { newp-2, newp-1};
Line (newl) = { newp-1, newp-4};

Line Loop (newll) = {newl-4, newl-3, newl-2, newl-1};
Surface (news) = newll-1;

Extrude { Surface { news-1}; Layers{{1},{.5}}; Recombine; Using Index[0];QuadTriNoNewVerts RecombLaterals;}
