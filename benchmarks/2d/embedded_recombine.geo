// Options
Mesh.SubdivisionAlgorithm = 1;
Mesh.MshFileVersion = 1;

// Variables
ch_length = 0.4 ;

// Noeuds
p1 = newp; Point(p1) = {0, 0, 0, ch_length} ;
p2 = newp; Point(p2) = {2, 0, 0, ch_length} ;
p3 = newp; Point(p3) = {2, 5, 0, ch_length} ;
p4 = newp; Point(p4) = {0, 5, 0, ch_length} ;
p5 = newp; Point(p5) = {0.5, 2, 0, ch_length} ;
p6 = newp; Point(p6) = {1, 1.6, 0, ch_length} ;
p7 = newp; Point(p7) = {1.2, 2.6, 0, ch_length} ;

// Lignes
l1 = newl; Line(l1) = {p1, p2} ;
l2 = newl; Line(l2) = {p2, p3} ;
l3 = newl; Line(l3) = {p3, p4} ;
l4 = newl; Line(l4) = {p4, p1} ;
l5 = newl; Line(l5) = {p6, p7} ;

// Surface Dalle
ll1 = newll; Line Loop (ll1) = {l1, l2, l3, l4} ;
s1 = news; Plane Surface (s1) = {ll1} ;

// Affinage des lignes
/*
Transfinite Line {l1} = 1 + 2 / ch_length ;
Transfinite Line {l2} = 1 + 5 / ch_length ;
Transfinite Line {l3} = 1 + 2 / ch_length ;
Transfinite Line {l4} = 1 + 5 / ch_length ;
Transfinite Line {l5} = 1 + 1.3 / ch_length ;
*/

Point{p5} In Surface{s1} ;
Line{l5} In Surface{s1} ;

// Transformation des triangles en quadrangles
Recombine Surface {s1} ;
