// Extruded mesh by a full turn (OpenCASCADE kernel): the last layer closes on
// the source surface, without duplicate nodes. With x = 0 the rectangle
// touches the axis of revolution.

SetFactory("OpenCASCADE");

DefineConstant[
  x = {1, Min 0, Max 2, Step 0.5, Name "Distance to the axis"},
  recombine = {1, Choices{0, 1}, Name "Recombine"}
];

Mesh.MeshSizeMax = 0.1;

Rectangle(1) = {x, 0, 0, 0.5, 0.3};

If(recombine)
  Extrude {{0, 1, 0}, {0, 0, 0}, 2 * Pi} { Surface{1}; Layers{24}; Recombine; }
  Recombine Surface{1};
Else
  Extrude {{0, 1, 0}, {0, 0, 0}, 2 * Pi} { Surface{1}; Layers{24}; }
EndIf
