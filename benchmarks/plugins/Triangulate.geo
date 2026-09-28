// Plugin(Triangulate): the Gauss points of a triangle mesh (scalar), vector
// points with 2 steps on a tilted plane, tensor points (the current view)
Merge "data/square.msh";
Plugin(GaussPoints).Run;
Plugin(Triangulate).View = PostProcessing.NbViews - 1;
Plugin(Triangulate).Run;

View "vectors" {
  VP(0, 0, 0){1, 0, 0, 2, 0, 0};    VP(1, 0, 0.5){0, 1, 0, 0, 2, 0};
  VP(2, 0, 1){0, 0, 1, 0, 0, 2};    VP(0, 1, 0.2){1, 1, 0, 2, 2, 0};
  VP(1, 1, 0.7){0, 1, 1, 0, 2, 2};  VP(2, 1, 1.2){1, 0, 1, 2, 0, 2};
  VP(0, 2, 0.4){1, 1, 1, 2, 2, 2};  VP(1, 2, 0.9){-1, 0, 0, -2, 0, 0};
  VP(2, 2, 1.4){0, -1, 0, 0, -2, 0};
};
Plugin(Triangulate).View = PostProcessing.NbViews - 1;
Plugin(Triangulate).Run;

View "tensors" {
  TP(0, 0, 0){1, 0, 0, 0, 1, 0, 0, 0, 1};
  TP(1, 0, 0){2, 0, 0, 0, 1, 0, 0, 0, 1};
  TP(0, 1, 0){1, 0, 0, 0, 2, 0, 0, 0, 1};
  TP(1, 1, 0){1, 0, 0, 0, 1, 0, 0, 0, 2};
  TP(0.5, 0.5, 0){1, 1, 1, 1, 1, 1, 1, 1, 1};
};
Plugin(Triangulate).View = -1;
Plugin(Triangulate).Run;
