/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   Trivial 3D example

   All important comments are marked with "README"
*/


// Let's include the first example

Include "demo-01.geo" ;

// We can extrude the surface to create a box of height h

h = 0.1 ;

Extrude Surface { 6, {0,0,h} };

// and specify a different characteristic length to some of the
// automatically created nodes

Characteristic Length{5,14} = lc * 5 ;

// And define a volume

/* README: In the same way one defines line loops to build surfaces,
   one must define surface loops to build volumes. The following
   volume is very simple, without holes (only one surface loop in the
   volume) */

Surface Loop(10022) = {10021,10008,6,10012,10016,10020};
Volume(10023) = {10022};

// Save volumic elements of volume 10023 with the associate number '1'

Physical Volume (1) = {41} ;

/* README: You can also specify options in the file. For example, this
   redefines the color of geometry points. Click on the '?' button in
   the main window, or save the options with File->Save Options as to
   get the full list of available options. */

General.Rotation0 = 10;
General.Color.Background = Red;
Geometry.Color.Points = Orange;

