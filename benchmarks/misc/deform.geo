Merge "deform.pos";

fact = 0.5; // deformation factor
PostProcessing.Format = 3; // save view as STL

For t In {0 : View[0].NbTimeStep - 1}

  Plugin(Warp).View = 0;
  Plugin(Warp).OtherView = 0;
  Plugin(Warp).TimeStep = t;
  Plugin(Warp).Factor = fact;
  Plugin(Warp).Run;

  Save View[0] Sprintf("deform%g.stl", t);

  // reset
  Plugin(Warp).Factor = -fact;
  Plugin(Warp).Run;

EndFor
