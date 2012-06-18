
/***********************************************
 *                                             *
 *  tunnel_test.geo                            *
 *  by Trevor Strickler                        *
 *  <trevor.strickler.gmail.com>               *
 *                                             *
 ***********************************************/

//set options
Geometry.Surfaces=1;
Mesh.SurfaceFaces=1;
Mesh.Algorithm=5; // mesh algorithm
Mesh.Algorithm3D=4; // mesh algorithm
General.InitialModule=2; 	//start in Mesh mode.
pi=Pi;


// geometric parameters
width = 1.0;
height = 1.0;
length = 3.0;
patch_width = 0.3;
patch_length = 0.3;
patch_height = height - 0.3;

num_trans_face_1 = 10;
num_trans_length = 20;
num_trans_patch = 5;

Point (newp) = { -width / 2.0, -height / 2.0, 0.0 };
Point (newp) = {  width / 2.0, -height / 2.0, 0.0 };
Point (newp) = {  width / 2.0,  height / 2.0, 0.0 };
Point (newp) = { -width / 2.0,  height / 2.0, 0.0 };

face_1_corners[] = {newp-4, newp-3, newp-2, newp-1};

Line (newl) = {face_1_corners[0], face_1_corners[1]};
Line (newl) = {face_1_corners[1], face_1_corners[2]};
Line (newl) = {face_1_corners[2], face_1_corners[3]};
Line (newl) = {face_1_corners[3], face_1_corners[0]};

face_1_lines[] = {newl-4, newl-3, newl-2, newl-1};
Transfinite Line {face_1_lines[]} = num_trans_face_1;

Line Loop (newll) = {face_1_lines[]};
face_1_line_loop = newll-1;

Plane Surface (news) = face_1_line_loop;
face_1_surface = news-1;
Transfinite Surface (face_1_surface) Left;

Recombine Surface (face_1_surface);

extrude_1[] = Extrude { 0.0, 0.0, -0.3 } { Surface{ face_1_surface }; Layers{3}; QuadTriSngl; Recombine; };

top_lines_extr_1[] = Boundary{ Surface{ extrude_1[0] }; };

top_points_extr_1[] += Boundary{ Line{ top_lines_extr_1[0] }; };
top_points_extr_1[] += Boundary{ Line{ top_lines_extr_1[1] }; };
top_points_extr_1[] += Boundary{ Line{ top_lines_extr_1[2] }; };
top_points_extr_1[] += Boundary{ Line{ top_lines_extr_1[3] }; };

Characteristic Length {top_points_extr_1[]} = length / (6 + num_trans_length);

Point (newp) = { -width / 2, -height / 2, -length };
Point (newp) = {  width / 2, -height / 2, -length };
Point (newp) = {  width / 2,  height / 2, -length };
Point (newp) = { -width / 2,  height / 2, -length };

face_2_corners[] = {newp-4, newp-3, newp-2, newp-1};

Line (newl) = {face_2_corners[0], face_2_corners[1]};
Line (newl) = {face_2_corners[1], face_2_corners[2]};
Line (newl) = {face_2_corners[2], face_2_corners[3]};
Line (newl) = {face_2_corners[3], face_2_corners[0]};

face_2_lines[] = {newl-4, newl-3, newl-2, newl-1};
Transfinite Line {face_2_lines[]} = num_trans_face_1;

Line Loop (newll) = {face_2_lines[]};
face_2_line_loop = newll-1;

Plane Surface (news) = face_2_line_loop;
face_2_surface = news-1;
Transfinite Surface (face_2_surface) Left;

Recombine Surface (face_2_surface);

extrude_2[] = Extrude { 0.0, 0.0, 0.3 } { Surface{ face_2_surface }; Layers{{1,1,1},{.3333333, .6666666,1.0}}; QuadTriSngl; Recombine;};

top_lines_extr_2[] = Boundary{ Surface{ extrude_2[0] }; };

top_points_extr_2[] += Boundary{ Line{ top_lines_extr_2[0] }; };
top_points_extr_2[] += Boundary{ Line{ top_lines_extr_2[1] }; };
top_points_extr_2[] += Boundary{ Line{ top_lines_extr_2[2] }; };
top_points_extr_2[] += Boundary{ Line{ top_lines_extr_2[3] }; };

Characteristic Length {top_points_extr_2[]} = length / (6 + num_trans_length);

Line (newl) = {top_points_extr_1[0], top_points_extr_2[0]};
Line (newl) = {top_points_extr_1[1], top_points_extr_2[1]};
Line (newl) = {top_points_extr_1[3], top_points_extr_2[3]};
Line (newl) = {14, 28};

length_lines[] = {newl-4, newl-3, newl-2, newl-1};
Transfinite Line { length_lines[] } = num_trans_length;

// create the little square patch at bottom lateral surface
Point (newp) = {-patch_width / 2.0, -height / 2.0, -length / 2.0 + patch_length / 2.0 };
Point (newp) = { patch_width / 2.0, -height / 2.0, -length / 2.0 + patch_length / 2.0 };
Point (newp) = { patch_width / 2.0, -height / 2.0, -length / 2.0 - patch_length / 2.0 };
Point (newp) = {-patch_width / 2.0, -height / 2.0, -length / 2.0 - patch_length / 2.0 };

patch_points[] = {newp-4, newp-3, newp-2, newp-1};

Line (newl) = {patch_points[0], patch_points[1]};
Line (newl) = {patch_points[1], patch_points[2]};
Line (newl) = {patch_points[2], patch_points[3]};
Line (newl) = {patch_points[3], patch_points[0]};

patch_lines[] = {newl-4, newl-3, newl-2, newl-1};

Transfinite Line {patch_lines[]} = num_trans_patch;

Line Loop (newll) = {patch_lines[]};
patch_loop = newll-1;
Plane Surface (news) = patch_loop;
patch_surface = news-1;
Transfinite Surface (patch_surface);
Recombine Surface patch_surface;

extrude_patch[] = Extrude { 0.0, patch_height, 0.0 } { Surface { patch_surface };
                            Layers{ {1,2,2,2,1}, {0.125, 0.375, 0.625, 0.875, 1.0}};
                            QuadTriSngl RecombLaterals; Recombine; };

//now mesh surfaces along length

Line Loop (newll) = {length_lines[0], top_lines_extr_2[0], -length_lines[1], -top_lines_extr_1[0]};
Line Loop (newll) = {length_lines[1], top_lines_extr_2[1], -length_lines[2], -top_lines_extr_1[1]};
Line Loop (newll) = {length_lines[2], top_lines_extr_2[2], -length_lines[3], -top_lines_extr_1[2]};
Line Loop (newll) = {length_lines[3], top_lines_extr_2[3], -length_lines[0], -top_lines_extr_1[3]};

length_loops[] = {newll-4, newll-3, newll-2, newll-1};

Plane Surface (news) = {length_loops[0], patch_loop};
Plane Surface (news) = length_loops[1];
Plane Surface (news) = length_loops[2];
Plane Surface (news) = length_loops[3];

lateral_surfaces[] = { news-4, news-3, news-2, news-1 };
Transfinite Surface { news-3, news-2, news-1};

// Create volume ( a little messy )

Surface Loop (newsl) = { -lateral_surfaces[], extrude_1[0], extrude_2[0], extrude_patch[{0,2:5}] };

Volume (newv) = newsl-1;
volume = newv-1;

// create physicals
Physical Surface ("inlet") = {face_1_surface};
Physical Surface ("outlet") = {face_2_surface};
Physical Surface ("laterals") = { lateral_surfaces[], extrude_1[{2:5}], extrude_2[{2:5}], patch_surface };
Physical Volume ("volume") = {volume, extrude_1[1], extrude_2[1], extrude_patch[1]};

Mesh.CharacteristicLengthMax = length / (8+num_trans_length);

