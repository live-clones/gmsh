/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   2D Scalar map, with automatic animation

   All important comments are marked with "README"
*/

Include "demo-01.geo" ;
Include "view-01.pos" ;
Include "view-01.pos" ;

General.Trackball = 0 ;
General.Rotation0 = 0 ;
General.Rotation1 = 0 ;
General.Rotation2 = 0 ;
General.Color.Background = White ;
General.Color.Text = Black ;
General.Orthographic = 0 ;
General.Axes = 0 ;

PostProcessing.View[0].Name = "This is a very stupid demonstration..." ;
PostProcessing.View[0].IntervalsType = 2 ;
PostProcessing.View[0].Offset = {0,0,0.05} ;
PostProcessing.View[0].Raise = {0,0,0} ;
PostProcessing.View[0].Light = 1 ;

PostProcessing.View[1].Name = "...of Gmsh's scripting capabilities" ;
PostProcessing.View[1].IntervalsType = 1 ;
PostProcessing.View[1].Color = { Green, Blue } ;
PostProcessing.View[1].NbIso = 10 ;

t = 0 ;

For(1:255)

  PostProcessing.View[0].TimeStep = t ;
  PostProcessing.View[1].TimeStep = t ;

  t = (PostProcessing.View[0].TimeStep < PostProcessing.View[0].NbTimeStep-1) ? t+1 : 0 ;
  
  PostProcessing.View[0].Raise += {0,0,0.001*t} ;

  For(1:10)

    General.Rotation0 += 10 ;
    General.Rotation1 = General.Rotation0 / 3 ;
    General.Rotation2 += 0.1 ;
 
    Sleep 0.01;
    Draw;

  EndFor

EndFor


