

General.Trackball = 0;
General.Rotation0 = 0 ;

For(1:300)

  General.Rotation0 ++ ;
  General.Rotation1 =  General.Rotation0 / 3 ;

  Post.View[0].TimeStep += 
    (Post.View[0].TimeStep < Post.View[0].NbTimeStep-1) ? 1 : 0 ;

  Sleep 0.3;
  Draw;

EndFor

