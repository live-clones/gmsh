// Write meshes to VTK XML (.vtu) and to legacy VTK (.vtk) files and read them
// back: a box of tetrahedra, of
// hexahedra and of prisms, at several orders, in ascii and in binary. The
// meshes are straight-sided, so that min(J)/max(J) is 1 in every element
// (nearly 1 for the hexahedra of order 4) only if the high-order nodes are
// where they should: a node ordering that the writer and the reader do not
// undo exactly shows as a lower ratio.
// The volume of the physical group checks the physical tags.

SetFactory("OpenCASCADE");

Macro Measure
  // -> quality (worst min(J)/max(J) of the volume elements), volume (of
  // physical group 7), and the numbers of nodes and volume elements
  Plugin(AnalyseMeshQuality).JacobianDeterminant = 1;
  Plugin(AnalyseMeshQuality).CreateView = 1;
  Plugin(AnalyseMeshQuality).DimensionOfElements = 3;
  Plugin(AnalyseMeshQuality).Recompute = 1;
  Plugin(AnalyseMeshQuality).Run;
  quality = View[PostProcessing.NbViews - 1].Min;
  Plugin(MeshVolume).PhysicalGroup = 7;
  Plugin(MeshVolume).Dimension = 3;
  Plugin(MeshVolume).Run;
  volume = View[PostProcessing.NbViews - 1].Max;
  Delete View[PostProcessing.NbViews - 1];
  Delete View[PostProcessing.NbViews - 1];
  nodes = Mesh.NbNodes;
  cells = Mesh.NbTetrahedra + Mesh.NbHexahedra + Mesh.NbPrisms;
Return

For kind In {0 : 2} // tetrahedra, hexahedra, prisms
  For order In {1 : (kind == 2 ? 2 : 4)} // (Gmsh has no prisms of order > 2)
    For binary In {0 : 1}
    For legacy In {0 : 1}
      Delete Model;
      If(kind == 0)
        Box(1) = {0, 0, 0, 1, 2, 3};
      Else
        Rectangle(1) = {0, 0, 0, 1, 2};
        If(kind == 1)
          Transfinite Curve{:} = 3;
          Transfinite Surface{1};
          Recombine Surface{1};
        EndIf
        Extrude {0, 0, 3} { Surface{1}; Layers{3}; Recombine; }
      EndIf
      Physical Volume(7) = {1};
      Physical Surface(8) = {1};
      Mesh.MeshSizeMin = 1; Mesh.MeshSizeMax = 1;
      Mesh.ElementOrder = order;
      Mesh 3;
      Call Measure;
      quality0 = quality; volume0 = volume; nodes0 = nodes; cells0 = cells;
      If(quality0 < 0.99 || Fabs(volume0 - 6) > 1e-8)
        Error("Kind %g, order %g: unexpected mesh, quality %g, volume %g", kind, order, quality0, volume0);
      EndIf

      Mesh.Binary = binary;
      If(!legacy)
        Save "vtu_roundtrip_out.vtu";
        Delete Model;
        Merge "vtu_roundtrip_out.vtu";
      Else
        Save "vtu_roundtrip_out.vtk";
        Delete Model;
        Merge "vtu_roundtrip_out.vtk";
      EndIf
      Call Measure;
      If(nodes != nodes0 || cells != cells0)
        Error("Kind %g, order %g, binary %g, legacy %g: %g nodes and %g cells written, %g and %g read", kind, order, binary, legacy, nodes0, cells0, nodes, cells);
      EndIf
      If(Fabs(quality - quality0) > 1e-8)
        Error("Kind %g, order %g, binary %g, legacy %g: wrong node ordering, min(J)/max(J) = %g after the round trip", kind, order, binary, legacy, quality);
      EndIf
      If(Fabs(volume - 6) > 1e-8)
        Error("Kind %g, order %g, binary %g, legacy %g: physical volume 7 measures %g after the round trip", kind, order, binary, legacy, volume);
      EndIf
    EndFor
    EndFor
  EndFor
EndFor
Mesh.Binary = 0;
