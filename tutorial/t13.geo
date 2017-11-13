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

// FIXME - the global "meshDiscrete" option will be replaced by meshing
// constraints "Compound Surface{...};"
General.MeshDiscrete = 1;

// Let's merge the mesh that we would like to remesh. This mesh was reclassified
// ("colored") from an initial STL triangulation using the "Reclassify 2D" tool
// in Gmsh, so that we could split it along sharp geometrical features.
Merge "t13_data.msh";
RefineMesh;

// We can now define a compound line (resp. surface) for each discrete line
// (resp. surface) in the model
// FIXME: this is currently not used
ll[] = Line {:};
ss[] = Surface {:};

// And we can create the volume based on the new compound entities
Surface Loop(1) = {ss[]};
Volume(1) = {1};

// element size imposed by a size field
Field[1] = MathEval;
Field[1].F = "2.0";
Background Field = 1;

DefineConstant[
  funny = {1, Choices{0,1},
    Name "Parameters/Apply funny mesh size field?"}
];

If(funny)
  Field[1].F = "2*Sin((x+y)/5) + 3";
EndIf
