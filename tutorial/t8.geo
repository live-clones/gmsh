/********************************************************************* 
 *
 *  Gmsh tutorial 8
 * 
 *  Post-Processing, Scripting, Animations, Options
 *
 *********************************************************************/

// The first example is included, as well as some post-processing maps:

Include "t1.geo" ;
Include "view1.pos" ;
Include "view1.pos" ;
Include "view4.pos" ;

// Some general options are set (all the options specified
// interactively can be directly specified in the ascii input
// files. The current options can be saved into a file by selecting
// 'File->Save as->Gmsh options').

General.Trackball = 0 ;
General.RotationX = 0 ;
General.RotationY = 0 ;
General.RotationZ = 0 ;
General.Color.Background = White ;
General.Color.Foreground = Black ;
General.Color.Text = Black ;
General.Orthographic = 0 ;
General.Axes = 0 ;
General.SmallAxes = 0 ;

// Some options are also specified for each post-processing view:

v0 = PostProcessing.NbViews-4;
v1 = v0+1;
v2 = v0+2;
v3 = v0+3;

View[v0].IntervalsType = 2 ;
View[v0].OffsetZ = 0.05 ;
View[v0].RaiseZ = 0 ;
View[v0].Light = 1 ;
View[v0].ShowScale = 0;
View[v0].SmoothNormals = 1;

View[v1].IntervalsType = 1 ;
View[v1].ColorTable = { Green, Blue } ;
View[v1].NbIso = 10 ;
View[v1].ShowScale = 0;

View[v2].Name = "Test..." ;
View[v2].IntervalsType = 2 ;
View[v2].Type = 2;
View[v2].IntervalsType = 2 ;
View[v2].AutoPosition = 0;
View[v2].PositionX = 85;
View[v2].PositionY = 50;
View[v2].Width = 200;
View[v2].Height = 130;

View[v3].Type = 3;
View[v3].RangeType = 2;
View[v3].IntervalsType = 4 ;
View[v3].ShowScale = 0;
View[v3].Grid = 0;
View[v3].CustomMin = View[v2].CustomMin;
View[v3].CustomMax = View[v2].CustomMax;
View[v3].AutoPosition = 0;
View[v3].PositionX = View[v2].PositionX;
View[v3].PositionY = View[v2].PositionY;
View[v3].Width = View[v2].Width;
View[v3].Height = View[v2].Height;

// We loop from 1 to 255 with a step of 1 (to use a step different
// from 1, just add a third argument in the list. For example, 'For
// num In {0.5:1.5:0.1}' would increment num from 0.5 to 1.5 with a
// step of 0.1).

t = 0 ;

For num In {1:255}

  View[v0].TimeStep = t ;
  View[v1].TimeStep = t ;
  View[v2].TimeStep = t ;
  View[v3].TimeStep = t ;

  t = (View[v0].TimeStep < View[v0].NbTimeStep-1) ? t+1 : 0 ;
  
  View[v0].RaiseZ += 0.01*t ;

  If (num == 3)
    // We want to create 320x240 frames when num==3:
    General.GraphicsWidth = 320 ; 
    General.GraphicsHeight = 240 ;
  EndIf

  // It is possible to nest loops:
  For num2 In {1:50}

    General.RotationX += 10 ;
    General.RotationY = General.RotationX / 3 ;
    General.RotationZ += 0.1 ;
 
    Sleep 0.01; // sleep for 0.01 second
    Draw; // draw the scene

    If ((num == 3) && (num2 < 10))
      // The Sprintf function permits to create complex strings using
      // variables (since all Gmsh variables are treated internally as
      // double precision numbers, the format should only contain valid
      // double precision number format specifiers):
      Print Sprintf("t8-0%g.gif", num2);
      Print Sprintf("t8-0%g.jpg", num2);
    EndIf

    If ((num == 3) && (num2 >= 10))
       Print Sprintf("t8-%g.gif", num2);
       Print Sprintf("t8-%g.jpg", num2);
    EndIf

  EndFor

  If(num == 3)
    // We could make a system call to generate the mpeg (uncomment the
    // following of mpeg_encode is installed on your computer)

    // System "mpeg_encode t8.par" ;
  EndIf

EndFor
