/*********************************************************************
 *
 *  Gmsh tutorial 13
 *
 *  Remeshing without an underlying CAD model
 *
 *********************************************************************/

// Let's merge a mesh that we would like to remesh. This mesh was reclassified
// ("colored") from an initial STL triangulation using the "Reclassify 2D" tool
// in Gmsh, so that we could split it along sharp geometrical features.
Merge "t13_data.msh";

// Create a geometry for all the curves and surfaces in the mesh, by computing a
// parametrization for each entity
CreateGeometry;

// Create a volume as usual
Surface Loop(1) = Surface{:};
Volume(1) = {1};

// element size imposed by a size field
Field[1] = MathEval;
Field[1].F = "4";
Background Field = 1;

funny = DefineNumber[0, Choices{0,1}, Name "Parameters/Apply funny mesh size field?" ];
If(funny)
  Field[1].F = "2*Sin((x+y)/5) + 3";
EndIf
