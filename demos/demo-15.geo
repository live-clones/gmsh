/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   2D Scalar map, with automatic animation

   All important comments are marked with "README"
*/

Include "demo-01.geo" ;
Include "view-01.pos" ;

General.Trackball = 0 ;
General.Rotation0 = 0 ;
General.Rotation1 = 0 ;
General.Rotation2 = 0 ;
General.Color.Background = White ;
General.Color.Text = Black ;

PostProcessing.View[0].IntervalsType = 2 ;
PostProcessing.View[0].Offset = {0,0,0.05} ;
PostProcessing.View[0].Raise = {0,0,0} ;

t = 0 ;

For(1:100)

  General.Rotation0 += 10 ;
  General.Rotation1 = General.Rotation0 / 3 ;
  General.Rotation2 += 0.1 ;

  PostProcessing.View[0].TimeStep = t ;

  t = (PostProcessing.View[0].TimeStep < PostProcessing.View[0].NbTimeStep-1) ? t+1 : 0 ;
  
  PostProcessing.View[0].Raise += {0,0,0.0002*t} ;

  Sleep 0.1;

  Draw;

EndFor


