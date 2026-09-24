// A view of high order is saved refined if PostProcessing.SaveAdapted says so,
// as adapted views are drawn, and as it is otherwise. 24 tetrahedra of order 3
// refined twice make 24 x 64 tetrahedra of order 1: in one .vtu file, in the
// pieces of a .pvtu, in a .msh file, or next to the mesh when the mesh is
// saved with its views; they must fill the same volume and carry the same
// range of values. Refined adaptively, each step of a view has a mesh of its
// own, and a file holds one mesh: a .vtu or a .msh file for each step, named
// after it (the .vtu files read back through their .pvd as a view whose steps
// are on the meshes of different models).

Macro Check
  // file, num -> error if the view read is not the one saved
  Delete Model;
  Merge StrCat(file);
  If(Mesh.NbTetrahedra != num || PostProcessing.NbViews != 1)
    Error(StrCat(file, ": expected %g tetrahedra and 1 view, read %g and %g"), num, Mesh.NbTetrahedra, PostProcessing.NbViews);
  EndIf
  Plugin(MeshVolume).Run;
  volume = View[PostProcessing.NbViews - 1].Max;
  Delete View[PostProcessing.NbViews - 1];
  // (the curved boundary is followed better by the refined elements)
  If(Fabs(volume - volume0) > 1e-2 * volume0)
    Error(StrCat(file, ": volume %g (expected about %g)"), volume, volume0);
  EndIf
  If(View[0].Min < min0 - 1e-6 * (max0 - min0) || View[0].Max > max0 + 1e-6 * (max0 - min0))
    Error(StrCat(file, ": values in [%g, %g], expected within [%g, %g]"), View[0].Min, View[0].Max, min0, max0);
  EndIf
  Delete View[0];
Return

Merge "../misc/adaptive_tet20.msh";
Plugin(MeshVolume).PhysicalGroup = -1; Plugin(MeshVolume).Dimension = 3;
Plugin(MeshVolume).Run;
volume0 = View[PostProcessing.NbViews - 1].Max;
Delete View[PostProcessing.NbViews - 1];
min0 = View[0].Min; max0 = View[0].Max;

View[0].MaxRecursionLevel = 2;
View[0].TargetError = -1;
Save View[0] "vtu_adaptive_out_raw.vtu";
PostProcessing.SaveAdapted = 1;
Save View[0] "vtu_adaptive_out.vtu";
Save View[0] "vtu_adaptive_out.pvtu";
Save View[0] "vtu_adaptive_out.msh";
Mesh.SaveViews = 2;
Save "vtu_adaptive_out_mesh.vtu";
Mesh.SaveViews = 0;
PostProcessing.SaveAdapted = 0;
Delete View[0];

file = "vtu_adaptive_out_raw.vtu"; num = 24; Call Check;
num = 24 * 64;
file = "vtu_adaptive_out.vtu"; Call Check;
file = "vtu_adaptive_out.pvtu"; Call Check;
file = "vtu_adaptive_out.msh"; Call Check;
file = "vtu_adaptive_out_mesh_views.vtu"; Call Check;

// a second step (x^24), which needs less refinement than the first
Delete Model;
Merge "../misc/adaptive_tet20.msh";
Merge "vtu_adaptive_step1.msh";
View[0].MaxRecursionLevel = 3;
View[0].TargetError = 1e-3;
PostProcessing.SaveAdapted = 1;
Save View[0] "vtu_adaptive_out_steps.vtu";
Save View[0] "vtu_adaptive_out_steps.msh";
PostProcessing.SaveAdapted = 0;
Delete View[0];
For step In {0 : 1}
  Delete Model;
  Merge Sprintf("vtu_adaptive_out_steps_%04g.vtu", step);
  tets~{step} = Mesh.NbTetrahedra;
  Plugin(MeshVolume).Run;
  volume = View[PostProcessing.NbViews - 1].Max;
  If(PostProcessing.NbViews != 2 || Fabs(volume - volume0) > 1e-2 * volume0)
    Error("Step %g: %g views and volume %g (expected 2 and about %g)", step, PostProcessing.NbViews, volume, volume0);
  EndIf
  Delete View[1];
  Delete View[0];
EndFor
If(tets~{0} <= tets~{1} || tets~{1} <= 24)
  Error("Steps refined into %g and %g tetrahedra (expected more for the first)", tets~{0}, tets~{1});
EndIf
// (each .msh file numbers its step as in the view)
For step In {0 : 1}
  Delete Model;
  Merge Sprintf("vtu_adaptive_out_steps_%04g.msh", step);
  If(PostProcessing.NbViews != 1 || View[0].NbTimeStep != step + 1 || Mesh.NbTetrahedra != tets~{step})
    Error("MSH step %g: %g views, %g steps and %g tetrahedra (expected 1, %g and %g)", step, PostProcessing.NbViews, View[0].NbTimeStep, Mesh.NbTetrahedra, step + 1, tets~{step});
  EndIf
  Delete View[0];
EndFor
Delete Model;
Merge "vtu_adaptive_out_steps.pvd";
If(PostProcessing.NbViews != 1 || View[0].NbTimeStep != 2 || Mesh.NbTetrahedra != tets~{0})
  Error("PVD: %g views, %g steps and %g tetrahedra (expected 1, 2 and %g)", PostProcessing.NbViews, View[0].NbTimeStep, Mesh.NbTetrahedra, tets~{0});
EndIf
