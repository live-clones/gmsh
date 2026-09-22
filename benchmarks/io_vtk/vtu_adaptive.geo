// An adaptive view is saved as it is shown: refined. 24 tetrahedra of order 3
// refined twice make 24 x 64 tetrahedra of order 1, in one .vtu file or in the
// pieces of a .pvtu, which must fill the same volume and carry the same range
// of values.

Merge "../misc/adaptive_tet20.msh";
Plugin(MeshVolume).PhysicalGroup = -1; Plugin(MeshVolume).Dimension = 3;
Plugin(MeshVolume).Run;
volume0 = View[PostProcessing.NbViews - 1].Max;
Delete View[PostProcessing.NbViews - 1];
min0 = View[0].Min; max0 = View[0].Max;

View[0].AdaptVisualizationGrid = 1;
View[0].MaxRecursionLevel = 2;
View[0].TargetError = -1;
Save View[0] "vtu_adaptive_out.vtu";
Save View[0] "vtu_adaptive_out.pvtu";
Delete View[0];

For parallel In {0 : 1}
  Delete Model;
  If(!parallel)
    Merge "vtu_adaptive_out.vtu";
  Else
    Merge "vtu_adaptive_out.pvtu";
  EndIf
  If(Mesh.NbTetrahedra != 24 * 64 || PostProcessing.NbViews != 1)
    Error("Parallel %g: expected %g tetrahedra and 1 view, read %g and %g", parallel, 24 * 64, Mesh.NbTetrahedra, PostProcessing.NbViews);
  EndIf
  Plugin(MeshVolume).Run;
  volume = View[PostProcessing.NbViews - 1].Max;
  Delete View[PostProcessing.NbViews - 1];
  // (the curved boundary is followed better by the refined elements)
  If(Fabs(volume - volume0) > 1e-2 * volume0)
    Error("Parallel %g: volume %g (expected about %g)", parallel, volume, volume0);
  EndIf
  If(View[0].Min < min0 - 1e-6 * (max0 - min0) || View[0].Max > max0 + 1e-6 * (max0 - min0))
    Error("Parallel %g: values in [%g, %g], expected within [%g, %g]", parallel, View[0].Min, View[0].Max, min0, max0);
  EndIf
  Delete View[0];
EndFor
