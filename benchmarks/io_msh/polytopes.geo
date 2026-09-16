// A pentagon with a hanging node and an interior node in its triangulation,
// and a cube with an interior node in its tetrahedralization: read them, write
// them and read them back; then the same without the sub-triangulation and
// sub-tetrahedralization, which Gmsh computes when needed but never writes
Mesh.MeshOnlyEmpty = 1;
Merge "polytopes.msh";
If(Mesh.NbPolygons != 1 || Mesh.NbPolyhedra != 1)
  Error("Expected 1 polygon and 1 polyhedron, got %g and %g",
        Mesh.NbPolygons, Mesh.NbPolyhedra);
EndIf
Save "polytopes_out.msh";
Delete Model;
Merge "polytopes_out.msh";
If(Mesh.NbNodes != 15 || Mesh.NbPolygons != 1 || Mesh.NbPolyhedra != 1)
  Error("Expected 15 nodes, 1 polygon and 1 polyhedron after the round trip, "
        "got %g, %g and %g", Mesh.NbNodes, Mesh.NbPolygons, Mesh.NbPolyhedra);
EndIf
Mesh.Binary = 1;
Save "polytopes_out.msh";
Delete Model;
Merge "polytopes_out.msh";
If(Mesh.NbNodes != 15 || Mesh.NbPolygons != 1 || Mesh.NbPolyhedra != 1)
  Error("Expected 15 nodes, 1 polygon and 1 polyhedron after the binary round "
        "trip, got %g, %g and %g", Mesh.NbNodes, Mesh.NbPolygons,
        Mesh.NbPolyhedra);
EndIf
Mesh.Binary = 0;
Delete Model;
Merge "polytopes_nosub.msh";
Plugin(MeshVolume).Dimension = 2; Plugin(MeshVolume).Run;
Plugin(MeshVolume).Dimension = 3; Plugin(MeshVolume).Run;
Save "polytopes_out.msh";
Delete Model;
Merge "polytopes_out.msh";
If(Mesh.NbNodes != 15 || Mesh.NbPolygons != 1 || Mesh.NbPolyhedra != 1)
  Error("Expected 15 nodes, 1 polygon and 1 polyhedron without subdivisions, "
        "got %g, %g and %g", Mesh.NbNodes, Mesh.NbPolygons, Mesh.NbPolyhedra);
EndIf
