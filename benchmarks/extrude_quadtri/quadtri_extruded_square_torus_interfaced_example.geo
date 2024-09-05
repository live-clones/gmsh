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
big = 2.5;
big_transf = 12;

Point (newp) = { r-a/2.0, -a/2, 0.0};
Point (newp) = { r-a/2.0, a/2, 0.0};
Point (newp) = { r+a/2.0, -a/2, 0.0};
Point (newp) = { r+a/2.0, a/2, 0.0};
Point (newp) = { r-a/2.0-b, -a/2-b, 0.0 };
Point (newp) = { r-a/2.0-b, a/2+b, 0.0 };
Point (newp) = { r+a/2.0+b, a/2+b, 0.0 };
Point (newp) = { r+a/2.0+b, -a/2-b, 0.0 };

list_points[] = {newp-8, newp-7, newp-6, newp-5, newp-4, newp-3, newp-2, newp-1};

Line (newl) = {list_points[0], list_points[1]};
Line (newl) = {list_points[1], list_points[3]};
Line (newl) = {list_points[3], list_points[2]};
Line (newl) = {list_points[2], list_points[0]};

Line (newl) = {list_points[4], list_points[5]};
Line (newl) = {list_points[5], list_points[6]};
Line (newl) = {list_points[6], list_points[7]};
Line (newl) = {list_points[7], list_points[4]};


list_lines_sq[] = {newl-8, newl-7, newl-6, newl-5};
list_lines_outer[] = {newl-4, newl-3, newl-2, newl-1};


Transfinite Line { list_lines_sq[], list_lines_outer[]} = 10;

Line Loop (newll) = {list_lines_sq[]};
Surface (news) = newll-1;
Transfinite Surface {news-1} = {1, 2, 4, 3};
Recombine Surface {news-1};
surf1 = news-1;

Line Loop (newll) = {list_lines_outer[]};
Surface (news) = {newll-1,-(newll-3)};
//Transfinite Surface {news-1} = {1, 2, 4, 3};
Recombine Surface {news-1};
surf2 = news-1;

Mesh.Smoothing = 100;

first[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {surf1}; Layers{20}; Recombine; };

second[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {first[0]};Layers{20}; Recombine;};

third[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {second[0]};Layers{20}; Recombine;};

fourth[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {third[0]}; Layers{20}; Recombine; };


outer_first[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {surf2}; Layers{20}; Recombine; QuadTriAddVerts;};
quadtri_laterals[] += outer_first[{2:5}];

outer_second[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {outer_first[0]};Layers{20}; Recombine;QuadTriAddVerts;};
quadtri_laterals[] += outer_second[{2:5}];

outer_third[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {outer_second[0]};Layers{20}; Recombine;QuadTriAddVerts;};
quadtri_laterals[] += outer_third[{2:5}];

outer_fourth[] = Extrude { {0, 1, 0}, {0, 0, 0}, Pi/2 }{ Surface {outer_third[0]}; Layers{20}; Recombine; QuadTriAddVerts;};
quadtri_laterals[] += outer_fourth[{2:5}];


//outer big unstructured volume 
Point (newp) = {-big/2, -big/2, -big/2};
Point (newp) = {big/2, -big/2, -big/2};
Point (newp) = {big/2, big/2, -big/2};
Point (newp) = {-big/2, big/2, -big/2};
unstr_source_pts[] = { newp-4, newp-3, newp-2, newp-1};

Line (newl) = {unstr_source_pts[0], unstr_source_pts[1]};
Line (newl) = {unstr_source_pts[1], unstr_source_pts[2]};
Line (newl) = {unstr_source_pts[2], unstr_source_pts[3]};
Line (newl) = {unstr_source_pts[3], unstr_source_pts[0]};
unstr_source_lines[] = { newl-4, newl-3, newl-2, newl-1};

Line Loop (newll) = {unstr_source_lines[]};

Surface (news) = {newll-1};
unstr_source = news-1;

unstr_extr[] = Extrude {0.0, 0.0, big} { Surface{unstr_source}; };

Transfinite Line {Boundary{Boundary{Volume{unstr_extr[1]};}}} = big_transf;
Characteristic Length { Boundary{Boundary{Boundary{Volume{unstr_extr[1]};}}}} = .001;

outer_big_bnd_surfs[] = Boundary{Volume{unstr_extr[1]};};
Delete{ Volume{unstr_extr[1]};}

Surface Loop (newsl) = {outer_big_bnd_surfs[]};
Surface Loop (newsl) = {quadtri_laterals[]};
Volume (newv) = { newsl-2, -(newsl-1) };
unstr_vol = newv-1;


