// A model that publishes the kind of parameters a solver publishes, so that
// the tree down the left side has something under its commands to show. They
// are ordinary parameters and not "ONELAB Context/" templates: those belong
// to the per-entity window and are kept out of the tree on purpose.
//
// One of every widget the tree can build, in the order the FLTK tree draws
// them -- a bounded value, a switch, an enumeration, a line of words, words
// one may also choose from, a value one reads and cannot edit, and a file.

Point(1) = {0, 0, 0, 1.0};
Point(2) = {1, 0, 0, 1.0};
Line(1) = {1, 2};

DefineConstant[
  steps = {8, Name "Solver/0Number of steps", Min 1, Max 100, Step 1,
           Help "How many steps the solver takes"},
  fixed = {1, Choices{0, 1}, Name "Solver/1Enabled"},
  method = {0, Choices{0 = "Fast", 1 = "Accurate", 2 = "Exact"},
            Name "Solver/2Method"},
  note = {"a note", Name "Solver/3Note"},
  material = {"copper", Choices{"copper", "steel", "air"},
              Name "Solver/4Material"},
  computed = {3.14159, Name "Solver/5Computed", ReadOnly 1},
  input = {"input.txt", Name "Solver/6Input file", Kind "file"}
];
