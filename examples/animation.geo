

General.Trackball = 0;
General.Rotation0 = 0 ;
General.Color.Background = White ;
General.Color.ForeGround = Red ;

Post.View[0].IntervalsType = 2 ;
Post.View[0].Raise = {0,0,0.1} ;

For(1:300)

  General.Rotation0 += 10 ;
  General.Rotation1 =  General.Rotation0 / 3 ;

  Post.View[0].TimeStep += 
    (Post.View[0].TimeStep < Post.View[0].NbTimeStep-1) ? 1 : 0 ;

  Post.View[0].Raise -= {0,0,0.01} ;

  Sleep 0.1;
  Draw;

EndFor

