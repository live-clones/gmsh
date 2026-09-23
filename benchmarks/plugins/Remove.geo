// Plugin(Remove): drop points, lines, triangles, quadrangles, tetrahedra,
// hexahedra, prisms and pyramids from scalar, vector and tensor list data,
// keeping the kinds of values switched off; 2D and 3D strings

Merge "data/square.pos"; // views 0-3
Plugin(Remove).Text2D = 0;
Plugin(Remove).Text3D = 0;
Plugin(Remove).Points = 1;
Plugin(Remove).Lines = 1;
Plugin(Remove).View = 0; // scalar: triangles left
Plugin(Remove).Run;
Plugin(Remove).Vector = 0;
Plugin(Remove).View = 1; // vector values kept
Plugin(Remove).Run;
Plugin(Remove).Vector = 1;
Plugin(Remove).Scalar = 0;
Plugin(Remove).Points = 0;
Plugin(Remove).Triangles = 1;
Plugin(Remove).View = 2; // tensor: points left
Plugin(Remove).Run;
Plugin(Remove).View = 3; // scalar cell values kept
Plugin(Remove).Run;
Plugin(Remove).Scalar = 1;
Plugin(Remove).Lines = 0;
Plugin(Remove).Triangles = 0;

Merge "data/quads.pos"; // views 4-7
Plugin(Remove).Quadrangles = 1;
Plugin(Remove).View = 5;
Plugin(Remove).Run;
Plugin(Remove).Quadrangles = 0;

Merge "data/cube.pos"; // views 8-11
Plugin(Remove).Tetrahedra = 1;
Plugin(Remove).View = 8;
Plugin(Remove).Run;
Plugin(Remove).View = 10;
Plugin(Remove).Run;
Plugin(Remove).Tetrahedra = 0;

Merge "data/hexes.pos"; // views 12-15
Plugin(Remove).Hexahedra = 1;
Plugin(Remove).View = 13;
Plugin(Remove).Run;
Plugin(Remove).Hexahedra = 0;

View "strings" { // view 16
  T2(10, 20, 0){"two", "lines"};
  T2(10, 50, 0){"2D"};
  T3(0.5, 0.5, 0.5, 0){"3D"};
  SP(0, 0, 0){1};
  SI(0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1){1, 2, 3, 4, 5, 6};
  SY(0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0.5, 0.5, -1){1, 2, 3, 4, 5};
  VY(0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0.5, 0.5, -1)
    {1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0, 0, 5, 0, 1};
};
Plugin(Remove).Text2D = 1;
Plugin(Remove).Prisms = 1;
Plugin(Remove).Pyramids = 1;
Plugin(Remove).Vector = 0;
Plugin(Remove).View = 16; // 3D string, point and vector pyramid left
Plugin(Remove).Run;
