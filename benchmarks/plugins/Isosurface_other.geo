// Plugin(Isosurface) on model data, drawing another view that has elements
// without data (element data) or fewer steps (both crashed)

Merge "data/cube.msh"; // views 0-3
Plugin(Isosurface).View = 0;
Plugin(Isosurface).Value = 1.2;
Plugin(Isosurface).OtherTimeStep = -1;
Plugin(Isosurface).OtherView = 3;
Plugin(Isosurface).Run;
Plugin(Isosurface).OtherView = 2;
Plugin(Isosurface).Run;
