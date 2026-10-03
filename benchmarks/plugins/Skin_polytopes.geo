// Plugin(Skin): the boundary of a view with polygons and polyhedra: the edges
// of a hexagon with a hanging node (7 lines) and the faces of a hexagonal
// prism (its hexagons as fans of 4 triangles each, its 6 quadrangles); then
// the skin of the mesh itself (FromMesh): the faces of the prism

Merge "data/polytopes.msh";
Plugin(Skin).Run;
Plugin(Skin).FromMesh = 1;
Plugin(Skin).Run;
If(Mesh.NbTriangles != 8 || Mesh.NbQuadrangles != 6)
  Error("Expected 8 triangles and 6 quadrangles on the skin of the prism, "
        "got %g and %g", Mesh.NbTriangles, Mesh.NbQuadrangles);
EndIf
