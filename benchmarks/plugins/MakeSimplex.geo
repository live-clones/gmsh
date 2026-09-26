// Plugin(MakeSimplex): quadrangles to triangles, hexahedra, prisms and
// pyramids to tetrahedra, scalar, vector and tensor list data, several steps;
// simplices untouched

Merge "data/quads.pos"; // views 0-3
Merge "data/hexes.pos"; // views 4-7
Merge "data/square.pos"; // view 8-11
View "prism and pyramid" { // view 12, 2 steps
  SI(0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1)
    {1, 2, 3, 4, 5, 6, 10, 20, 30, 40, 50, 60};
  VY(0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0.5, 0.5, -1)
    {1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0, 0, 5, 0, 1,
     0, 1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0, 0, 5, 1};
};
For v In {0 : 12}
  Plugin(MakeSimplex).View = v;
  Plugin(MakeSimplex).Run;
EndFor
