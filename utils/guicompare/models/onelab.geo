// A surface a solver would attach parameters to, so that the per-entity ONELAB
// window has something to show. The parameters below are templates: the window
// makes one of each for whatever entity it is opened on, which is the whole
// point of it. One of every kind there is, so that the picture holds every
// widget that window can build -- a value, a switch, an enumeration, a line of
// words, and words one may also choose from.

Point(1) = {0, 0, 0, 1.0};
Point(2) = {1, 0, 0, 1.0};
Point(3) = {1, 1, 0, 1.0};
Point(4) = {0, 1, 0, 1.0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};
Physical Surface("plate", 10) = {1};

DefineConstant[
  flux = {1.5, Name "ONELAB Context/Surface Template/0Flux",
          Min 0, Max 10, Step 0.1,
          Help "The flux through the surface"},
  fixed = {1, Choices{0, 1}, Name "ONELAB Context/Surface Template/1Fixed"},
  kind = {0, Choices{0 = "Dirichlet", 1 = "Neumann", 2 = "Robin"},
          Name "ONELAB Context/Surface Template/2Condition"},
  note = {"a note", Name "ONELAB Context/Surface Template/3Note"},
  material = {"copper", Choices{"copper", "steel", "air"},
              Name "ONELAB Context/Surface Template/4Material"}
];

// what a double click on the surface does, which is how one opens that window
Geometry.DoubleClickedSurfaceCommand = "ONELAB";
