/********************************************************************* 
 *
 *  Gmsh tutorial 8
 * 
 *  Post-Processing, Scripting, Animations, Options
 *
 *********************************************************************/

// The first example is included, as well as some post-processing maps
// (for the format of the post-processing maps, see the FORMATS file):

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

View[0].IntervalsType = 2 ;
View[0].OffsetZ = 0.05 ;
View[0].RaiseZ = 0 ;
View[0].Light = 1 ;
View[0].ShowScale = 0;
View[0].SmoothNormals = 1;

View[1].IntervalsType = 1 ;
View[1].ColorTable = { Green, Blue } ;
View[1].NbIso = 10 ;
View[1].ShowScale = 0;

View[2].Name = "Test..." ;
View[2].IntervalsType = 2 ;
View[2].Type = 2;
View[2].IntervalsType = 2 ;
View[2].AutoPosition = 0;
View[2].PositionX = 85;
View[2].PositionY = 50;
View[2].Width = 200;
View[2].Height = 150;

View[3].Type = 3;
View[3].RangeType = 2;
View[3].IntervalsType = 4 ;
View[3].ShowScale = 0;
View[3].Grid = 0;
View[3].CustomMin = View[2].CustomMin;
View[3].CustomMax = View[2].CustomMax;
View[3].AutoPosition = 0;
View[3].PositionX = View[2].PositionX;
View[3].PositionY = View[2].PositionY;
View[3].Width = View[2].Width;
View[3].Height = View[2].Height;

// We loop from 1 to 255 with a step of 1 (to use a step different
// from 1, just add a third argument in the list. For example, 'For
// num In {0.5:1.5:0.1}' would increment num from 0.5 to 1.5 with a
// step of 0.1).

t = 0 ;

For num In {1:255}

  View[0].TimeStep = t ;
  View[1].TimeStep = t ;
  View[2].TimeStep = t ;
  View[3].TimeStep = t ;

  t = (View[0].TimeStep < View[0].NbTimeStep-1) ? t+1 : 0 ;
  
  View[0].RaiseZ += 0.01*t ;

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


// Here is the list of available scripting commands:
//  
//  Merge string;     (to merge a file)
//  Draw;             (to draw the scene)
//  Mesh int;         (to perform the mesh generation; 'int' = 0, 1, 2 or 3)
//  Save string;      (to save the mesh)
//  Print string;     (to print the graphic window)
//  Sleep expr;       (to sleep during expr seconds)
//  Delete View[int]; (to free the view int)
//  Delete Meshes;    (to free all meshes)
//  System string;    (to execute a system call)
