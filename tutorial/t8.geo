/********************************************************************* 
 *
 *  Gmsh tutorial 8
 * 
 *  Post-Processing, Scripting, Animations, Options
 *
 *********************************************************************/

// The first example is included, as well as two post-processing maps
// (for the format of the post-processing maps, see the FORMATS file):

Include "t1.geo" ;
Include "view1.pos" ;
Include "view1.pos" ;

// Some general options are set (all the options specified
// interactively can be directly specified in the ascii input
// files. The current options can be saved into a file by selecting
// 'File->Save_Options_as')...

General.Trackball = 0 ;
General.Rotation0 = 0 ;
General.Rotation1 = 0 ;
General.Rotation2 = 0 ;
General.Color.Background = White ;
General.Color.Text = Black ;
General.Orthographic = 0 ;
General.Axes = 0 ;

// ...as well as some options for each post-processing view...

View[0].Name = "This is a very stupid demonstration..." ;
View[0].IntervalsType = 2 ;
View[0].Offset2 = 0.05 ;
View[0].Raise2 = 0 ;
View[0].Light = 1 ;

View[1].Name = "...of Gmsh's scripting capabilities" ;
View[1].IntervalsType = 1 ;
View[1].ColorTable = { Green, Blue } ;
View[1].NbIso = 10 ;

// ...and loop from 1 to 255 with a step of 1 is performed (to use a
// step different from 1, just add a third argument in the list,
// e.g. 'For num In {0.5:1.5:0.1}' increments num from 0.5 to 1.5 with
// a step of 0.1):

t = 0 ;

For num In {1:255}

  View[0].TimeStep = t ;
  View[1].TimeStep = t ;

  t = (View[0].TimeStep < View[0].NbTimeStep-1) ? t+1 : 0 ;
  
  View[0].Raise2 += 0.001*t ;

  If (num == 3)
    // We want to use mpeg_encode to create a nice 320x240 animation
    // for all frames when num==3:
    General.Viewport2 = 320 ; 
    General.Viewport3 = 240 ;
  EndIf

  // It is possible to nest loops:

  For num2 In {1:50}

    General.Rotation0 += 10 ;
    General.Rotation1 = General.Rotation0 / 3 ;
    General.Rotation2 += 0.1 ;
 
    Sleep 0.01; // sleep for 0.01 second
    Draw; // draw the scene

    If ((num == 3) && (num2 < 10))
      // The Sprintf function permits to create complex strings using
      // variables (since all Gmsh variables are treated internally as
      // double precision numbers, the format should only contain valid
      // double precision number format specifiers):
      Print Sprintf("t8-0%g.jpg", num2);
    EndIf

    If ((num == 3) && (num2 >= 10))
      Print Sprintf("t8-%g.jpg", num2);
    EndIf

  EndFor

  If(num == 3)
    // We make a system call to generate the mpeg
    System "mpeg_encode t8.par" ;    
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
