//set options
Geometry.Surfaces=1;
Mesh.SurfaceFaces=1;
Mesh.RecombinationAlgorithm = 0;
Mesh.RemeshAlgorithm = 1;
Mesh.Algorithm=6; // mesh algorithm
Mesh.Algorithm3D=4; // mesh algorithm
Geometry.AutoCoherence = 1;
  Geometry.OldRuledSurface=1;
  
  
r = .70;
a = .4;
b = 0.1;

Point (newp) = { r-a/2.0, -a/2, 0.0};
Point (newp) = { r-a/2.0, a/2, 0.0};
Point (newp) = { r+a/2.0, a/2, 0.0};
Point (newp) = { r+a/2.0, -a/2, 0.0};
Point (newp) = { r-a/2.0-b, -a/2-b, 0.0 };
Point (newp) = { r-a/2.0-b, a/2+b, 0.0 };
Point (newp) = { r+a/2.0+b, a/2+b, 0.0 };
Point (newp) = { r+a/2.0+b, -a/2-b, 0.0 };

list_points[] = {newp-8, newp-7, newp-6, newp-5, newp-4, newp-3, newp-2, newp-1};

Line (newl) = {list_points[0], list_points[1]};
Line (newl) = {list_points[1], list_points[2]};
Line (newl) = {list_points[2], list_points[3]};
Line (newl) = {list_points[3], list_points[0]};

Line (newl) = {list_points[4], list_points[5]};
Line (newl) = {list_points[5], list_points[6]};
Line (newl) = {list_points[6], list_points[7]};
Line (newl) = {list_points[7], list_points[4]};


list_lines_sq[] = {newl-8, newl-7, newl-6, newl-5};
list_lines_outer[] = {newl-4, newl-3, newl-2, newl-1};
 
Line (newl) = {list_points[0], list_points[4]};
Line (newl) = {list_points[1], list_points[5]};
Line (newl) = {list_points[2], list_points[6]};
Line (newl) = {list_points[3], list_points[7]};

cross_lines[] = {newl-4, newl-3, newl-2, newl-1};

Transfinite Line { list_lines_sq[], list_lines_outer[]} = 10;
Transfinite Line { cross_lines[] } = 4;

Line Loop (newll) = { list_lines_sq[] };
Ruled Surface (news) = newll-1;
surf0 = news-1;
Transfinite Surface {news-1};
Recombine Surface {news-1};

Line Loop (newll) = {list_lines_sq[0], cross_lines[1], -list_lines_outer[0], -cross_lines[0]};
Ruled Surface (news) = newll-1;
surf1 = news-1;

Line Loop (newll) = {list_lines_sq[1], cross_lines[2], -list_lines_outer[1], -cross_lines[1]};
Ruled Surface (news) = newll-1;
surf2 = news-1;

Line Loop (newll) = {list_lines_sq[2], cross_lines[3], -list_lines_outer[2], -cross_lines[2]};
Ruled Surface (news) = newll-1;
surf3 = news-1;

Line Loop (newll) = {list_lines_sq[3], cross_lines[0], -list_lines_outer[3], -cross_lines[3]};
Ruled Surface (news) = newll-1;
surf4 = news-1;


Compound Surface (news) = {surf1, surf2, surf3, surf4} Boundary {{list_lines_outer[]},{list_lines_sq[]}};
//Recombine Surface {news-1};
surfc = news-1;
Hide {Surface {surf1, surf2, surf3, surf4};}
Mesh.Smoothing = 100;


first[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {surf0}; Layers{20}; Recombine;};

second[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {first[0]};Layers{20}; Recombine;};

third[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {second[0]};Layers{20}; Recombine;};

fourth[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {third[0]}; Layers{20}; Recombine;};


outer_first[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {surfc}; Layers{20}; Recombine; QuadTriNoNewVerts;};

outer_second[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {outer_first[0]};Layers{20}; Recombine; QuadTriNoNewVerts RecombLaterals;};

outer_third[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {outer_second[0]};Layers{20}; Recombine; QuadTriAddVerts; };

outer_fourth[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {outer_third[0]}; Layers{20}; Recombine; QuadTriAddVerts RecombLaterals;};
