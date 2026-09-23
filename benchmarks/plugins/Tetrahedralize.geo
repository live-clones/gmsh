// Plugin(Tetrahedralize): the Gauss points of a tetrahedral mesh (scalar),
// vector points with 2 steps, tensor points (the current view)
Merge "data/cube.msh";
Plugin(GaussPoints).Dimension = 3;
Plugin(GaussPoints).Run;
Plugin(Tetrahedralize).View = PostProcessing.NbViews - 1;
Plugin(Tetrahedralize).Run;

View "vectors" {
  VP(0, 0, 0){1, 0, 0, 2, 0, 0};  VP(1, 0, 0){0, 1, 0, 0, 2, 0};
  VP(1, 1, 0){0, 0, 1, 0, 0, 2};  VP(0, 1, 0){1, 1, 0, 2, 2, 0};
  VP(0, 0, 1){0, 1, 1, 0, 2, 2};  VP(1, 0, 1){1, 0, 1, 2, 0, 2};
  VP(1, 1, 1){1, 1, 1, 2, 2, 2};  VP(0, 1, 1){-1, 0, 0, -2, 0, 0};
  VP(0.4, 0.5, 0.6){0, -1, 0, 0, -2, 0};
};
Plugin(Tetrahedralize).View = PostProcessing.NbViews - 1;
Plugin(Tetrahedralize).Run;

View "tensors" {
  TP(0, 0, 0){1, 0, 0, 0, 1, 0, 0, 0, 1};
  TP(1, 0, 0){2, 0, 0, 0, 1, 0, 0, 0, 1};
  TP(0, 1, 0){1, 0, 0, 0, 2, 0, 0, 0, 1};
  TP(0, 0, 1){1, 0, 0, 0, 1, 0, 0, 0, 2};
  TP(1, 1, 1){1, 1, 1, 1, 1, 1, 1, 1, 1};
};
Plugin(Tetrahedralize).View = -1;
Plugin(Tetrahedralize).Run;
