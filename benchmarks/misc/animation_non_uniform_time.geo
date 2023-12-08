View "adaptive_time" {
  SP(0,0,0){0,1,2,3,4,5,6,7,8,9,10};
  TIME{0,0.1,0.2,0.3,4,5,6,7,10,11,20};
};

// accessing min and max times is a bit clumsy (setting the time step changes
// the current time):
View[0].TimeStep = 0;
tmin = View[0].Time;

View[0].TimeStep = View[0].NbTimeStep - 1;
tmax = View[0].Time;

Printf("View has %g time steps with time values between %g and %g",
  View[0].NbTimeStep, tmin, tmax);

View[0].Type = 3; // 2D time
View[0].Axes = 1;
View[0].IntervalsType = 3; // to see the points

For time In {tmin : tmax : (tmax - tmin) / 24}
  // Setting the current time will select the closest time step
  View[0].Time = time;

  Printf("Displaying step %g for time value %g", View[0].TimeStep, time);
  Sleep 0.01;
  Draw;
EndFor
