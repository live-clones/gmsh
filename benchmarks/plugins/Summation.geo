// Plugin(Summation): sums of model data with 3 steps on triangles (scalar,
// vector), of element data given on a physical group only (it read the
// elements without data), and of list data on hexahedra

Merge "data/square.msh"; // views 0-3
Plugin(Summation).View0 = 0;
Plugin(Summation).View1 = 0;
Plugin(Summation).Run;
Plugin(Summation).View0 = 1;
Plugin(Summation).View1 = 1;
Plugin(Summation).View2 = 1;
Plugin(Summation).ResultingViewName = "triple";
Plugin(Summation).Run;

Plugin(NewView).Type = "ElementData";
Plugin(NewView).PhysicalGroup = 3;
Plugin(NewView).Value = 2;
Plugin(NewView).Run; // view 6, on the surface only
Plugin(Summation).View0 = 6;
Plugin(Summation).View1 = 6;
Plugin(Summation).View2 = -1;
Plugin(Summation).ResultingViewName = "default";
Plugin(Summation).Run;

Merge "data/hexes.pos"; // views 8-11
Plugin(Summation).View0 = 8;
Plugin(Summation).View1 = 8;
Plugin(Summation).Run;
