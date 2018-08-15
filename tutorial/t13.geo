/*********************************************************************
 *
 *  Gmsh tutorial 13
 *
 *  Remeshing STL with compounds
 *
 *********************************************************************/

// Since compound geometrical compute a new parametrization, one can also use
// them to remesh STL files, even if in this case there's usually only a single
// elementary geometrical entity per compound.

// Compute parametrization of discrete (i.e. already meshed) curves and surfaces
// read from mesh file
General.MeshDiscrete = 1;

// (Note that this behavior is currently global. It will probably be modified in
// the future, so that the parametrizations are only computed when they are
// actually needed.)

// Let's merge the mesh that we would like to remesh. This mesh was reclassified
// ("colored") from an initial STL triangulation using the "Reclassify 2D" tool
// in Gmsh, so that we could split it along sharp geometrical features.
Merge "t13_data.msh";

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
