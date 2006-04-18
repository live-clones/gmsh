/*********************************************************************
 *
 *  Gmsh tutorial 3
 * 
 *  Extruded meshes, options
 *
 *********************************************************************/

// Again, we start by including the first tutorial:

Include "t1.geo";

// As in `t2.geo', we plan to perform an extrusion along the z axis.
// But here, instead of only extruding the geometry, we also want to
// extrude the 2D mesh. This is done with the same `Extrude' command,
// but by specifying the number of layers (4 layers in this case, each
// with heights equal to h/4, but with 8, 4, 2 and 1 subdivisions,
// respectively):

h = 0.1;

Extrude {0,0,h} { 
  Surface{6}; Layers{ {8,4,2,1}, {0.25,0.5,0.75,1} }; 
}

// The extrusion can also be performed with a rotation instead of a
// translation, and the resulting mesh can be recombined into prisms
// (wedges). All rotations are specified by an axis direction
// ({0,1,0}), an axis point ({-0.1,0,0.1}) and a rotation angle
// (-Pi/2):

Extrude { {0,1,0} , {-0.1,0,0.1} , -Pi/2 } { 
  Surface{122}; Layers { 7, 1 }; Recombine; 
}

// Note that a translation ({-2*h,0,0}) and a rotation ({1,0,0},
// {0,0.15,0.25}, Pi/2) can also be combined:

out[] = Extrude { {-2*h,0,0}, {1,0,0} , {0,0.15,0.25} , Pi/2 } { 
  Surface{news-1}; Layers{ 10, 1 }; Recombine; 
};

// In the last extrusion command we retrieved the volume
// number programatically by saving the output of the command
// into an array. This array will contain the "top" of the extruded
// surface as well as the newly created volume.

// We can then define a new physical volume to save all
// the tetrahedra with a common region number (101):

Physical Volume(101) = {1, 2, out[1]};

// Let us now change some options... Since all interactive options are
// accessible in Gmsh's scripting language, we can for example define
// a global characteristic length factor, redefine some background
// colors, disable the display of the axes, and select an initial
// viewpoint in XYZ mode (disabling the interactive trackball-like
// rotation mode) directly in the input file:

Mesh.CharacteristicLengthFactor = 4;
General.Color.Background = {120,120,120};
General.Color.Foreground = {255,255,255};
General.Color.Text = White;
Geometry.Color.Points = Orange;
General.Axes = 0;
General.Trackball = 0;
General.RotationCenterGravity = 0;
General.RotationCenterX = 0;
General.RotationCenterY = 0;
General.RotationCenterZ = 0;
General.RotationX = 10;
General.RotationY = 70;
General.TranslationX = -0.2;

// Note that all colors can be defined literally or numerically, i.e.
// `General.Color.Background = Red' is equivalent to
// `General.Color.Background = {255,0,0}'; and also note that, as with
// user-defined variables, the options can be used either as right or
// left hand sides, so that the following command will set the surface
// color to the same color as the points:

Geometry.Color.Surfaces = Geometry.Color.Points;

// You can click on the `?'  button in the status bar of the graphic
// window to see the current values of all options. To save all the
// options in a file, you can use the `File->Save as->Gmsh options'
// menu. To save the current options as the default options for all
// future Gmsh sessions, you should use the `Tools->Options->Save'
// button.
