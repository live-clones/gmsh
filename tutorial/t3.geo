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
// but also the 2D mesh. This is done with the same Extrude command,
// but by specifying the number of layers (here, there will be four
// layers, of respectively 8, 4, 2 and 1 elements in depth), with
// volume numbers 9000 to 9003 and respective heights equal to h/4:

Extrude Surface { 6, {0,0,h} } { 
  Layers { {8,4,2,1}, {9000:9003}, {0.25,0.5,0.75,1} } ; 
} ;

// The extrusion can also performed with a rotation instead of a
// translation, and the resulting mesh can be recombined into prisms
// (wedges) if the surface elements are triangles, or hexahedra if the
// surface elements are quadrangles. All rotations are specified by an
// axis direction ({0,1,0}), an axis point ({-0.1,0,0.1}) and a
// rotation angle (-Pi/2):

Extrude Surface { 122, {0,1,0} , {-0.1,0,0.1} , -Pi/2 } { 
  Recombine ; Layers { 7, 9004, 1 } ; 
};

// A translation ({-2*h,0,0}) and a rotation ({1,0,0} , {0,0.15,0.25},
// Pi/2) can be combined:

Extrude Surface {news-1, {-2*h,0,0}, {1,0,0} , {0,0.15,0.25} , Pi/2}{ 
  Layers {10,9004,1}; Recombine; 
};

Physical Volume(101) = {9000:9004};

// All interactive options can also be set directly in the input file.
// For example, the following lines define a global characteristic
// length factor, redefine some background colors, disable the display
// of the axes, and select an initial viewpoint in XYZ mode (disabling
// the interactive trackball-like rotation mode):

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

// Note: all colors can be defined literally or numerically, i.e.
// 'General.Color.Background = Red' is equivalent to
// 'General.Color.Background = {255,0,0}'. As with user-defined
// variables, the options can be used either as right hand or left
// hand sides, so that

Geometry.Color.Surfaces = Geometry.Color.Points;

// will assign the color of the surfaces in the geometry to the same
// color as the points.

// A click on the '?'  button in the status bar of the graphic window
// will dump all current options to the terminal. To save all
// available options to a file, use the 'File->Save as->Gmsh options'
// menu. To save the current options as the default options for all
// future Gmsh sessions, use the 'Tools->Options->Save' button.
