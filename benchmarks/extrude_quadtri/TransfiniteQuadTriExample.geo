//set options
Geometry.Surfaces=1;
Mesh.SurfaceFaces=1;
Mesh.RecombinationAlgorithm = 0;
Mesh.RemeshAlgorithm = 1;
Mesh.Algorithm=6; // mesh algorithm
Mesh.Algorithm3D=4; // mesh algorithm
Geometry.OldRuledSurface=1;


length1 = 1.0;
outer_length  = 2.0;

interface_width = 0.07;

transf1 = 15;
transf2 = 2;
transf_outer = 30;

Point (newp) = {0.0, 0.0, 0.0};
Point (newp) = {length1, 0.0, 0.0};
Point (newp) = {length1, length1, 0.0};
Point (newp) = {0.0, length1, 0.0};

source_pts[] = {newp-4, newp-3, newp-2, newp-1};

Line (newl) = {source_pts[0], source_pts[1]};
Line (newl) = {source_pts[1], source_pts[2]};
Line (newl) = {source_pts[2], source_pts[3]};
Line (newl) = {source_pts[3], source_pts[0]};

source_lines[] = {newl-4, newl-3, newl-2, newl-1};
Transfinite Line {source_lines[]} = transf1;
Line Loop (newll) = {source_lines[]};
source_loop = newll-1;

Surface (news) = {source_loop};
source_surf = news-1;
Transfinite Surface {source_surf};
Recombine Surface {source_surf};

vol1[] = Extrude { 0.0, 0.0, 1.0 }  { Surface{source_surf}; };


lines1[] = Boundary { Surface{ vol1[{0,2,3,4,5}] }; };
Transfinite Line { lines1[] } = transf1;

Transfinite Surface { vol1[{0,2:5}] };
Recombine Surface { vol1[{0,2:5}] };
Transfinite Volume { vol1[1] };
Recombine Volume { vol1[1] };

// transfinite QuadTri volumes start here

vol2[] = Extrude { 0.0, 0.0, -interface_width }  { Surface{source_surf}; };
lines2[] = Boundary { Surface{ vol2[{0,2,3,4,5}] }; };
Transfinite Line { lines2[] } = transf2;
// have to correct some of the previous tranfinite lines:
Transfinite Line { lines1[], Boundary{Surface{vol2[0]};} } = transf1;

Transfinite Surface { vol2[{0,2:5}] };
//Recombine Surface { vol2[{2:5}] };
Transfinite Volume { vol2[1] };
Recombine Volume { vol2[1] };

vol3[] = Extrude { 0.0, 0.0, interface_width }  { Surface{vol1[0]}; };
lines3[] = Boundary { Surface{ vol3[{0,2,3,4,5}] }; };
Transfinite Line { lines3[] } = transf2;
// have to correct some of the previous tranfinite lines:
Transfinite Line { lines1[], Boundary{Surface{vol3[0]};} } = transf1;

Transfinite Surface { vol3[{0,2:5}] };
//Recombine Surface { vol3[{2:5}] };
Transfinite Volume { vol3[1] };
Recombine Volume { vol3[1] };

vol4[] = Extrude { 0.0, -interface_width, 0.0 }  { Surface{vol1[2]}; };
lines4[] = Boundary { Surface{ vol4[{0,2,3,4,5}] }; };
Transfinite Line { lines4[] } = transf2;
// have to correct some of the previous tranfinite lines:
Transfinite Line { lines1[], Boundary{Surface{vol4[0]};} } = transf1;

Transfinite Surface { vol4[{0,2:5}] };
//Recombine Surface { vol4[{2:5}] };
Transfinite Volume { vol4[1] };
Recombine Volume { vol4[1] };

vol5[] = Extrude { 0.0, interface_width, 0.0 }  { Surface{vol1[4]}; };
lines5[] = Boundary { Surface{ vol5[{0,2,3,4,5}] }; };
Transfinite Line { lines5[] } = transf2;
// have to correct some of the previous tranfinite lines:
Transfinite Line { lines1[], Boundary{Surface{vol5[0]};} } = transf1;

Transfinite Surface { vol5[{0,2:5}] };
//Recombine Surface { vol5[{2:5}] };
Transfinite Volume { vol5[1] };
Recombine Volume { vol5[1] };

vol6[] = Extrude { interface_width,  0.0, 0.0 }  { Surface{vol1[3]}; };
lines6[] = Boundary { Surface{ vol6[{0,2,3,4,5}] }; };
Transfinite Line { lines6[] } = transf2;
// have to correct some of the previous tranfinite lines:
Transfinite Line { lines1[], Boundary{Surface{vol6[0]};} } = transf1;

Transfinite Surface { vol6[{0,2:5}] };
//Recombine Surface { vol6[{2:5}] };
Transfinite Volume { vol6[1] };
Recombine Volume { vol6[1] };

vol7[] = Extrude { -interface_width,  0.0, 0.0 }  { Surface{vol1[5]}; };
lines7[] = Boundary { Surface{ vol7[{0,2,3,4,5}] }; };
Transfinite Line { lines7[] } = transf2;
// have to correct some of the previous tranfinite lines:
Transfinite Line { lines1[], Boundary{Surface{vol7[0]};} } = transf1;

Transfinite Surface { vol7[{0,2:5}] };
//Recombine Surface { vol7[{2:5}] };
Transfinite Volume { vol7[1] };
Recombine Volume { vol7[1] };

//Here is the application of Transfinite QuadTri
TransfQuadTri { vol2[1], vol3[1], vol4[1], vol5[1], vol6[1], vol7[1]  };


// outer volume
Point (newp) = {-(outer_length-length1)/2.0, -(outer_length-length1)/2.0, -(outer_length-length1)/2.0};
Point (newp) = {(outer_length+length1)/2.0, -(outer_length-length1)/2.0, -(outer_length-length1)/2.0};
Point (newp) = {(outer_length+length1)/2.0, (outer_length+length1)/2.0, -(outer_length-length1)/2.0};
Point (newp) = {-(outer_length-length1)/2.0, (outer_length+length1)/2.0, -(outer_length-length1)/2.0};

outer_pts[] = {newp-4, newp-3, newp-2, newp-1};

Line (newl) = {outer_pts[0], outer_pts[1]};
Line (newl) = {outer_pts[1], outer_pts[2]};
Line (newl) = {outer_pts[2], outer_pts[3]};
Line (newl) = {outer_pts[3], outer_pts[0]};

outer_source_lines[] = {newl-4, newl-3, newl-2, newl-1};
Transfinite Line {outer_source_lines[]} = transf_outer;

Line Loop (newll) = {outer_source_lines[]};

Surface (news) = {newll-1};
outer_source = news-1;

outer_vol[] = Extrude { 0.0, 0.0, outer_length } { Surface { outer_source }; };
Delete { Volume {outer_vol[1]}; }
Transfinite Line { Boundary{ Surface{ outer_vol[{0,2:5}] }; } } = transf_outer;

Surface Loop (newsl) = {outer_source, outer_vol[{0,2:5}]};
outer_surf_loop = newsl-1;

Surface Loop (newsl) = { vol2[{0,2:5}], vol3[{0,2:5}], vol4[{0,2:5}], vol5[{0,2:5}], vol6[{0,2:5}],
                         vol7[{0,2:5}] };
inner_surf_loop = newsl-1;

Volume (newv) = { outer_surf_loop, inner_surf_loop };

Characteristic Length { Boundary{ Line{ Boundary{ Surface{outer_vol[{0,2:5}] }; } }; } } = outer_length / transf_outer ;
Characteristic Length { Boundary{ Line{ Boundary{ Surface{vol1[{0,2:5}], vol2[{0,2:5}], vol3[{0,2:5}], vol4[{0,2:5}],
                        vol5[{0,2:5}], vol6[{0,2:5}], vol7[{0,2:5}] }; } }; } } = length1 / transf1 ;

