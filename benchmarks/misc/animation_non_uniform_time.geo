View "adaptive_time" {
  SP(0,0,0){0,1,2,3,4,5,6,7,8,9,10};
  TIME{0,0.1,0.2,0.3,4,5,6,7,10,11,20};
};

View[0].Type = 3; // 2D time
View[0].Axes = 1;
View[0].IntervalsType = 3; // to see the points

For time In {0:20:0.1}
  View[0].Time = time;
  Printf("time %g %g", time, View[0].TimeStep);
  Sleep 0.01;
  Draw;
EndFor
