/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   Trivial 3D example, with extrusion

   All important comments are marked with "README"
*/


// Let's include the first example, again

Include "demo-01.geo" ;

// In the same way as in demo-02.geo, we can extrude the surface to
// create a box of height h. But here we also extrude the 2D mesh into
// two layers (of 2 and 4 elements), with volume numbers 9000 and 9001
// and repective heights of 0.33*h and 0.67*h

h = 0.1 ;

Extrude Surface { 6, {0,0,h} } { Layers { {2,4}, {9000,9001}, {0.33,1} } ; };


// The extrusion can be combined with a rotation, and the extruded 3D
// mesh can be recombined into prisms (wedges). All rotations are
// specified by an axis direction ({0,1,0}), an axis point ({0,0,0})
// and a rotation angle (Pi/2)

Extrude Surface { 10021, {0,1,0} , {-0.1,0,0.1} , -Pi/2 } { 
  Recombine ; Layers { {7}, {9002}, {1} } ; 
};

