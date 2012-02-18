/*********************************************************************
 *
 *  Gmsh tutorial 13
 *
 *  Remeshing STL with compounds
 *
 *********************************************************************/

// Since compound geometrical compute a new parametrization, one can
// also use them to remesh STL files, even if in this case there's
// usually only a single elementary geometrical entity per compound.

// Let's merge the mesh that we would like to remesh. This mesh was
// reclassified ("colored") from an initial STL triangulation using
// the "Reclassify 2D" tool in Gmsh, so that we could split it along
// sharp geometrical features.
Merge "t13_data.msh";

// Since the original mesh is a bit coarse, we refine it once
RefineMesh;

// Create the topology of the discrete model
CreateTopology;

// We can now define a compound line (resp. surface) for each discrete
// line (resp. surface) in the model
ll[] = Line "*";
For j In {0 : #ll[]-1}
  Compound Line(newl) = ll[j];
EndFor
ss[] = Surface "*";
s = news;
For i In {0 : #ss[]-1}
  Compound Surface(s+i) = ss[i];
EndFor

// And we can create the volume based on the new compound entities
Surface Loop(1) = {s : s + #ss[]-1};
Volume(1) = {1};

Physical Surface(1) = {s : s + #ss[]-1};
Physical Volume(1) = 1;

// Apply a funny mesh size field, just because we can :-)
Field[1] = MathEval;
Field[1].F = "2*Sin((x+y)/5) + 3";
Background Field = 1;

Mesh.RemeshAlgorithm = 1; // (0) no split (1) automatic (2) automatic only with metis
Mesh.RemeshParametrization = 1; // (0) harmonic (1) conformal
Geometry.HideCompounds = 0; // don't hide the compound entities
