Mesh.CharacteristicLengthExtendFromBoundary = 1;
Merge "lann_ver1.stp";

MeshAlgorithm Surface {5,6}  1;

/// Create a boundary layer field
Field[1] = BoundaryLayer;
/// Edges in the symmetry plane from which BL meshes are extruded
Field[1].EdgesList = {3, 4};
/// Faces in the volume from which BL meshes are extruded
Field[1].FacesList = {3, 4, 5, 6};
//// Mesh Size far from the surface
Field[1].hfar = 1000;
/// Normal size to the wall
Field[1].hwall_n = .12;
/// Tangent size on the wall
Field[1].hwall_t = 10;
/// Growth rate of the BL 
Field[1].ratio = 1.4;
/// Maximal Thickness of the BL
Field[1].thickness = 8.12;
/// Edges in the volume where fans of elements are created 
/// This should be either closed or end in the symmetry plane 
Field[1].FansList = {6,7,8,11,10,12};
/// Vertices in the symmetry plane where fans of elements are created 
Field[1].FanNodesList = {3, 4};
/// Set the boundary layer field to be field 1
BoundaryLayer Field = 1;

Characteristic Length {5, 6, 7, 3, 4} = 10;
Surface Loop(129) = {1,2,3,4,5,6};
Volume(1000) = {129};

