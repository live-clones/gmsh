/********************************************************************* 
 *
 *  Gmsh tutorial 3
 * 
 *  Extruded meshes, Options
 *
 *********************************************************************/

// Again, the first tutorial example is included:

Include "t1.geo" ;

// As in 't2.geo', an extrusion along the z axis will be performed:

h = 0.1 ;

// But contrary to 't2.geo', not only the geometry will be extruded,
// but we also the 2D mesh. This is done with the same Extrude
// command, but by specifying the number of layers (here, there will
// be two layers, of respectively 2 and 4 elements in depth), with
// volume numbers 9000 and 9001 and respective heights of 0.33*h and
// 0.67*h:

Extrude Surface { 6, {0,0,h} } { Layers { {2,4}, {9000,9001}, {0.33,1} } ; } ;

// The extrusion can also be combined with a rotation, and the
// extruded 3D mesh can be recombined into prisms (wedges). All
// rotations are specified by an axis direction ({0,1,0}), an axis
// point ({0,0,0}) and a rotation angle (Pi/2):

Extrude Surface { 122, {0,1,0} , {-0.1,0,0.1} , -Pi/2 } { 
  Recombine ; Layers { {7}, {9002}, {1} } ; 
};

// All interactive options can also be set directly in the input file.
// For example, the following lines redefine the background color of
// the graphic window, the color of the points of the geometry,
// disable the display of the axes, and select an initial viewpoint in
// xyz mode (disabling the interactive trackball-like rotation mode):

General.Color.Background = Red;
Geometry.Color.Points = Orange;
General.Axes = 0;

General.Trackball = 0;
General.RotationX = 10;
General.RotationY = 70;
General.TranslationX = -0.1;

// Note: all colors can be defined literally or numerically, i.e.
// 'General.Color.Background = Red' is equivalent to
// 'General.Color.Background = {255,0,0}'. As with user-defined
// variables, the options can be used either as right hand or left
// hand sides, so that

Geometry.Color.Surfaces = Geometry.Color.Points;

// will set the color of the surfaces in the geometry to the same
// color as the points.

// A click on the '?'  button in status bar of the graphic window will
// dump all current options to the terminal. To save all available
// options to a file, use the 'File->Save_as->GEO complete options'
// menu. To save the current options as the default options for all
// future Gmsh sessions, use the 'File->Save_Options' menu.
