// Read .vtu files written by VTK itself (vtkCellTypeSource, 2x2x2 blocks of
// high-order cells; see vtk_written.py), so that the node ordering is VTK's
// and not what the Gmsh writer thinks it is. The cells are straight-sided:
// min(J)/max(J) is 1 in every element only if the reader puts the high-order
// nodes where they belong. The files also differ in their encoding:
// appended raw data compressed with zlib, inline base64, ascii, appended raw.
// The cells of order 2 are Lagrange cells (VTK types 72 and 73), which the
// Gmsh writer never produces.

Macro Check
  // file, nodes, cells -> error if the mesh read is not the one expected
  Merge StrCat(file);
  n = Mesh.NbTetrahedra + Mesh.NbHexahedra + Mesh.NbPrisms + Mesh.NbPyramids;
  If(Mesh.NbNodes != nodes || n != cells)
    Error(StrCat(file, ": expected %g nodes and %g cells, read %g and %g"), nodes, cells, Mesh.NbNodes, n);
  EndIf
  Plugin(AnalyseMeshQuality).JacobianDeterminant = 1;
  Plugin(AnalyseMeshQuality).CreateView = 1;
  Plugin(AnalyseMeshQuality).DimensionOfElements = 3;
  Plugin(AnalyseMeshQuality).Recompute = 1;
  Plugin(AnalyseMeshQuality).Run;
  quality = View[PostProcessing.NbViews - 1].Min;
  Delete View[PostProcessing.NbViews - 1];
  Plugin(MeshVolume).PhysicalGroup = -1;
  Plugin(MeshVolume).Dimension = 3;
  Plugin(MeshVolume).Run;
  volume = View[PostProcessing.NbViews - 1].Max;
  Delete View[PostProcessing.NbViews - 1];
  If(quality < 0.99 || Fabs(volume - 8) > 1e-8)
    Error(StrCat(file, ": wrong node ordering, min(J)/max(J) = %g and volume %g (expected 1 and 8)"), quality, volume);
  EndIf
  Delete Model;
Return

// the compressed file can only be read if Gmsh is built with zlib
If(StrFind(General.BuildOptions, "Zlib"))
  file = "vtk_tetrahedra_order3.vtu"; nodes = 869; cells = 96; Call Check;
Else
  Printf("Skipping vtk_tetrahedra_order3.vtu (zlib-compressed): Gmsh is built without zlib");
EndIf
file = "vtk_hexahedra_order3.vtu"; nodes = 343; cells = 8; Call Check;
file = "vtk_hexahedra_order2.vtu"; nodes = 125; cells = 8; Call Check;
file = "vtk_prisms_order2.vtu"; nodes = 125; cells = 16; Call Check;
file = "vtk_pyramids_order2.vtu"; nodes = 153; cells = 48; Call Check;
