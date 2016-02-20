/*********************************************************************
 *
 *  Gmsh tutorial 8
 *
 *  Post-processing, scripting, animations, options
 *
 *********************************************************************/

// We first include `t1.geo' as well as some post-processing views:

Include "t1.geo";
Include "view1.pos";
Include "view1.pos";
Include "view4.pos";

// We then set some general options:

General.Trackball = 0;
General.RotationX = 0; General.RotationY = 0; General.RotationZ = 0;
General.Color.Background = White; General.Color.Foreground = Black;
General.Color.Text = Black;
General.Orthographic = 0;
General.Axes = 0; General.SmallAxes = 0;

// We also set some options for each post-processing view:

v0 = PostProcessing.NbViews-4;
v1 = v0+1; v2 = v0+2; v3 = v0+3;

View[v0].IntervalsType = 2;
View[v0].OffsetZ = 0.05;
View[v0].RaiseZ = 0;
View[v0].Light = 1;
View[v0].ShowScale = 0;
View[v0].SmoothNormals = 1;

View[v1].IntervalsType = 1;
View[v1].ColorTable = { Green, Blue };
View[v1].NbIso = 10;
View[v1].ShowScale = 0;

View[v2].Name = "Test...";
View[v2].Axes = 1;
View[v2].Color.Axes = Black;
View[v2].IntervalsType = 2;
View[v2].Type = 2;
View[v2].IntervalsType = 2;
View[v2].AutoPosition = 0;
View[v2].PositionX = 85;
View[v2].PositionY = 50;
View[v2].Width = 200;
View[v2].Height = 130;

View[v3].Visible = 0;

// We then loop from 1 to 3 with a step of 1. (To use a different step, just add
// a third argument in the list. For example, `For num In {0.5:1.5:0.1}' would
// increment num from 0.5 to 1.5 with a step of 0.1.)

t = 0;

For num In {1:3}

  View[v0].TimeStep = t;
  View[v1].TimeStep = t;
  View[v2].TimeStep = t;
  View[v3].TimeStep = t;

  t = (View[v0].TimeStep < View[v0].NbTimeStep-1) ? t+1 : 0;

  View[v0].RaiseZ += 0.01/View[v0].Max * t;

  If (num == 3)
    // We want to create 640x480 frames when num == 3:
    General.GraphicsWidth = General.MenuWidth + 640;
    General.GraphicsHeight = 480;
  EndIf

  frames = 50;

  // It is possible to nest loops:
  For num2 In {1:frames}

    General.RotationX += 10;
    General.RotationY = General.RotationX / 3;
    General.RotationZ += 0.1;

    Sleep 0.01; // sleep for 0.01 second
    Draw; // draw the scene (one could use DrawForceChanged instead to force the
          // reconstruction of the vertex arrays, e.g. if changing element
          // clipping)

    If (num == 3)
      // The `Print' command saves the graphical window; the `Sprintf' function
      // permits to create the file names on the fly:
      //Print Sprintf("t8-%02g.gif", num2);
      //Print Sprintf("t8-%02g.ppm", num2);
      //Print Sprintf("t8-%02g.jpg", num2);
    EndIf

  EndFor

  If(num == 3)
    // Here we could make a system call to generate a movie. For example,

    // with whirlgif:
    /*
    System "whirlgif -minimize -loop -o t8.gif t8-*.gif";
    */

    // with mpeg_encode (create parameter file first, then run encoder):
    /*
    Printf("PATTERN I") > "t8.par";
    Printf("BASE_FILE_FORMAT PPM") >> "t8.par";
    Printf("GOP_SIZE 1") >> "t8.par";
    Printf("SLICES_PER_FRAME 1") >> "t8.par";
    Printf("PIXEL HALF") >> "t8.par";
    Printf("RANGE 10") >> "t8.par";
    Printf("PSEARCH_ALG EXHAUSTIVE") >> "t8.par";
    Printf("BSEARCH_ALG CROSS2") >> "t8.par";
    Printf("IQSCALE 1") >> "t8.par";
    Printf("PQSCALE 1") >> "t8.par";
    Printf("BQSCALE 25") >> "t8.par";
    Printf("REFERENCE_FRAME DECODED") >> "t8.par";
    Printf("OUTPUT t8.mpg") >> "t8.par";
    Printf("INPUT_CONVERT *") >> "t8.par";
    Printf("INPUT_DIR .") >> "t8.par";
    Printf("INPUT") >> "t8.par";
    tmp = Sprintf("t8-*.ppm [01-%02g]", frames);
    Printf(tmp) >> "t8.par";
    Printf("END_INPUT") >> "t8.par";
    System "mpeg_encode t8.par";
    */

    // with mencoder:
    /*
    System "mencoder 'mf://*.jpg' -mf fps=5 -o t8.mpg -ovc lavc
            -lavcopts vcodec=mpeg1video:vhq";
    System "mencoder 'mf://*.jpg' -mf fps=5 -o t8.mpg -ovc lavc
           -lavcopts vcodec=mpeg4:vhq";
    */

    // with ffmpeg:
    /*
    System "ffmpeg -hq -r 5 -b 800 -vcodec mpeg1video
            -i t8-%02d.jpg t8.mpg"
    System "ffmpeg -hq -r 5 -b 800 -i t8-%02d.jpg t8.asf"
    */
  EndIf

EndFor
