
N = 5000;

Printf("Testing Combine TimeSteps with %g views", N);
For i In {1:N}
  View "aa" {SP(0,0,0){i};};
EndFor
Combine TimeSteps;
//Save View[0] "new.pos";
Printf("Done testing Combine");

M = 10;
Printf("Testing leaks with %g allocations of %g views", M, N);

For j In {1:M}
Printf("-- create %g", j);
For i In {1:N}
  View "aa" {SP(0,0,0){i};};
EndFor
Printf("-- delete %g", j);
For i In {1:N}
  Delete View[0];
EndFor
EndFor

Printf("Done testing leaks");
