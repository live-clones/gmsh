
General.Trackball = 0;
General.RotationX = 0 ;
General.Color.Background = White ;
General.Color.Foreground = Red ;

View[0].IntervalsType = 2 ;
View[0].RaiseZ = 0.1 ;

For(1:300)

  General.RotationX += 10 ;
  General.RotationY =  General.RotationX / 3 ;

  View[0].TimeStep += 
    (View[0].TimeStep < View[0].NbTimeStep-1) ? 1 : 0 ;

  View[0].RaiseZ -= .01 ;

  Sleep 0.1;
  Draw;

EndFor

