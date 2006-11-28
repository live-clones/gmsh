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
// but by specifying element 'Layers' (2 layers in this case, the
// first one with 8 subdivisions and the second one with 2
// subdivisions, both with a height of h/2):

h = 0.1;

Extrude {0,0,h} { 
  Surface{6}; Layers{ {8,2}, {0.5,1} }; 
}

// The extrusion can also be performed with a rotation instead of a
// translation, and the resulting mesh can be recombined into prisms
// (we use only one layer here, with 7 subdivisions). All rotations
// are specified by an axis direction ({0,1,0}), an axis point
// ({-0.1,0,0.1}) and a rotation angle (-Pi/2):

Extrude { {0,1,0} , {-0.1,0,0.1} , -Pi/2 } { 
  Surface{122}; Layers { 7, 1 }; Recombine; 
}

// Note that a translation ({-2*h,0,0}) and a rotation ({1,0,0},
// {0,0.15,0.25}, Pi/2) can also be combined:

out[] = Extrude { {-2*h,0,0}, {1,0,0} , {0,0.15,0.25} , Pi/2 } { 
  Surface{news-1}; Layers{ 10, 1 }; Recombine; 
};

// In this last extrusion command we retrieved the volume
// number programatically by saving the output of the command
// into an array. This array will contain the "top" of the extruded
// surface (in out[0]) as well as the newly created volume (in
// out[1]).

// We can then define a new physical volume to save all
// the tetrahedra with a common region number (101):

Physical Volume(101) = {1, 2, out[1]};

// Let us now change some options... Since all interactive options are
// accessible in Gmsh's scripting language, we can for example define
// a global characteristic length factor or redefine some colors
// directly in the input file:

Mesh.CharacteristicLengthFactor = 4;
General.Color.Text = White;
Geometry.Color.Points = Orange;
Mesh.Color.Points = {255,0,0};

// Note that all colors can be defined literally or numerically, i.e.
// `Mesh.Color.Points = Red' is equivalent to `Mesh.Color.Points =
// {255,0,0}'; and also note that, as with user-defined variables, the
// options can be used either as right or left hand sides, so that the
// following command will set the surface color to the same color as
// the points:

Geometry.Color.Surfaces = Geometry.Color.Points;

// You can click on the `?'  button in the status bar of the graphic
// window to see the current values of all options. To save all the
// options in a file, you can use the `File->Save as->Gmsh options'
// menu. To save the current options as the default options for all
// future Gmsh sessions, you should use the `Tools->Options->Save'
// button.
