Include "bump_contour.geo";

Mesh.CharacteristicLengthFromPoints = 1;
Mesh.CharacteristicLengthExtendFromBoundary = 1;

// =============================================================
// SURFACES
// =============================================================

// Left wall
Line Loop(1) = {1:6};
Plane Surface(1) = {1};

// Extrusion of the domain contour
out[] = Extrude{0,0,2*W}{ Surface{1}; };

dist = 1.5;

Field[1] = Box;
Field[1].XMin = 2.0 - dist;
Field[1].XMax = 2.0 + dist;
Field[1].YMin =  0.0;
Field[1].YMax =  0.4;
Field[1].ZMin = -W;
Field[1].ZMax =  W;
Field[1].VIn =   0.2*lc;
Field[1].VOut =  0.8*lc;

Field[2] = Min;
Field[2].FieldsList = {1};

Background Field = 2;

// =============================================================
// PHYSICAL ENTITIES
// =============================================================
Physical Surface("Inlet") = {25};
Physical Surface("Outlet") = {17};
Physical Surface("SymmetryLeft") = {1};
Physical Surface("SymmetryRight") = {26};
Physical Surface("Bottom") = {13};
Physical Surface("Top") = {21};

Physical Volume("Fluid") = {1};
