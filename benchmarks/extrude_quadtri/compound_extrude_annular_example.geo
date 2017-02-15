// an annulus in 4 parts to test extruding compound surface with a hole


//set options
Geometry.Surfaces=1;
Mesh.SurfaceFaces=1;
Mesh.RecombinationAlgorithm = 0;
Mesh.RemeshAlgorithm = 1;
Mesh.Algorithm=6; // mesh algorithm
Mesh.Algorithm3D=4; // mesh algorithm
Geometry.AutoCoherence = 1;
Geometry.OldRuledSurface=1;
  
  
// center
Point (newp) = {0, 0, 0};  
circle_center = newp-1;

//inner circle
Point (newp) = {1, 0, -.2};
inner_point1 = newp-1;
Point (newp) = {-1, 0, 0};
Point (newp) = {0, 1, 0 };
Point (newp) = {0, -1, 0};


//outer circle
Point (newp) = {2, 0, -.2};
outer_point1 = newp-1;
Point (newp) = {-2, 0, 0};
Point (newp) = {0, 2, 0 };
Point (newp) = {0, -2, 0};

//inner circle lines
Circle (newl) = {inner_point1, circle_center, inner_point1+2};
inner_line1 = newl-1;
Circle (newl) = {inner_point1+2, circle_center, inner_point1+1};
Circle (newl) = {inner_point1+1, circle_center, inner_point1+3};
Circle (newl) = {inner_point1+3, circle_center, inner_point1};

//outer circle lines
Circle (newl) = {outer_point1, circle_center, outer_point1+2};
outer_line1 = newl-1;
Circle (newl) = {outer_point1+2, circle_center, outer_point1+1};
Circle (newl) = {outer_point1+1, circle_center, outer_point1+3};
Circle (newl) = {outer_point1+3, circle_center, outer_point1};

//cross lines
Line (newl) = {inner_point1, outer_point1};
cross_line1 = newl-1;
Line (newl) = {inner_point1+2, outer_point1+2};
Line (newl) = {inner_point1+1, outer_point1+1};
Line (newl) = {inner_point1+3, outer_point1+3};


// Transfinite Lines
Transfinite Line {outer_line1, outer_line1+1, outer_line1+2,outer_line1+3} = 10;
Transfinite Line {inner_line1, inner_line1+1, inner_line1+2,inner_line1+3} = 6;
Transfinite Line {cross_line1, cross_line1+1, cross_line1+2, cross_line1+3} = 5;

// line loops and surfaces
Line Loop (newll) = {cross_line1, outer_line1, -(cross_line1+1), -inner_line1};
lineloop1=newll-1;
Line Loop (newll) = {cross_line1+1, outer_line1+1, -(cross_line1+2), -(inner_line1+1)};
Line Loop (newll) = {cross_line1+2, outer_line1+2, -(cross_line1+3), -(inner_line1+2)};
Line Loop (newll) = {cross_line1+3, outer_line1+3, -cross_line1, -(inner_line1+3)};
Surface (news) = lineloop1;
Surface (news) = lineloop1+1;
Surface (news) = lineloop1+2;
Surface (news) = lineloop1+3;
ind_surfaces = {news-3, news-4, news-2, news-1};
Compound Surface (news) = {ind_surfaces[]};
//Hide {Surface{ind_surfaces[]};}
Extrude {0, 0 , 1} {Surface{news-1}; Layers{{5},{1}};Recombine; }
