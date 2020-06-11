Merge "discrete.msh";

DefineConstant[
  demo = {0, Name "What to remesh?",
    Choices {0="Everything", 1="All volumes", 2="Volume 69", 3="Surface 35"}
  }
];

If(demo == 0)
  // create geo for all entities - meshing will remesh everything
  CreateGeometry;
ElseIf(demo == 1)
  // create geo only for all volumes - meshing will only remesh all volumes: curve and
  // surface mesh will not be changed
  CreateGeometry { Volume{:}; }
ElseIf(demo == 2)
  // create geo only for a single volume - meshing will only remesh that volume:
  //curve, surface and all other volume meshes will be left as-is
  CreateGeometry { Volume{69}; }
ElseIf(demo == 3)
  // create geo only for a single surface - meshing will remesh the surface *and
  // the volumes connected to that surface*
  CreateGeometry { Surface{35}; }
EndIf
