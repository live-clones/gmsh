// -----------------------------------------------------------------------------
//
//  Gmsh C++ tutorial 12
//
//  Cross-patch meshing with compounds
//
// -----------------------------------------------------------------------------

#include <gmsh.h>

namespace factory = gmsh::model::geo;

// "Compound" meshing constraints allow to generate meshes across surface
// boundaries, which can be useful e.g. for imported CAD models (e.g. STEP) with
// undesired small features.

// When a `setCompound()' meshing constraint is given, at mesh generation time
// Gmsh
//  1. meshes the underlying elementary geometrical entities, individually
//  2. creates a discrete entity that combines all the individual meshes
//  3. computes a discrete parametrization (i.e. a piece-wise linear mapping)
//     on this discrete entity
//  4. meshes the discrete entity using this discrete parametrization instead
//     of the underlying geometrical description of the underlying elementary
//     entities making up the compound
//  5. optionally, reclassifies the mesh elements and nodes on the original
//     entities

// Step 3. above can only be performed if the mesh resulting from the
// combination of the individual meshes can be reparametrized, i.e. if the shape
// is "simple enough". If the shape is not amenable to reparametrization, you
// should create a full mesh of the geometry and first re-classify it to
// generate patches amenable to reparametrization (see `t13.cpp').

// The mesh of the individual entities performed in Step 1. should usually be
// finer than the desired final mesh; this can be controlled with the
// `Mesh.CompoundCharacteristicLengthFactor' option.

// The optional reclassification on the underlying elementary entities in Step
// 5. is governed by the `Mesh.CompoundClassify' option.

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("t12");

  double lc = 0.1;

  factory::addPoint(0, 0, 0, lc, 1);
  factory::addPoint(1, 0, 0, lc, 2);
  factory::addPoint(1, 1, 0.5, lc, 3);
  factory::addPoint(0, 1, 0.4, lc, 4);
  factory::addPoint(0.3, 0.2, 0, lc, 5);
  factory::addPoint(0, 0.01, 0.01, lc, 6);
  factory::addPoint(0, 0.02, 0.02, lc, 7);
  factory::addPoint(1, 0.05, 0.02, lc, 8);
  factory::addPoint(1, 0.32, 0.02, lc, 9);

  factory::addLine(1, 2, 1);
  factory::addLine(2, 8, 2);
  factory::addLine(8, 9, 3);
  factory::addLine(9, 3, 4);
  factory::addLine(3, 4, 5);
  factory::addLine(4, 7, 6);
  factory::addLine(7, 6, 7);
  factory::addLine(6, 1, 8);
  factory::addSpline({7, 5, 9}, 9);
  factory::addLine(6, 8, 10);

  factory::addCurveLoop({5, 6, 9, 4}, 11);
  factory::addSurfaceFilling({11}, 1);

  factory::addCurveLoop({-9, 3, 10, 7}, 13);
  factory::addSurfaceFilling({13}, 5);

  factory::addCurveLoop({-10, 2, 1, 8}, 15);
  factory::addSurfaceFilling({15}, 10);

  factory::synchronize();

  // Treat curves 2, 3 and 4 as a single curve when meshing (i.e. mesh across
  // points 6 and 7)
  gmsh::model::mesh::setCompound(1, {2, 3, 4});

  // Idem with curves 6, 7 and 8
  gmsh::model::mesh::setCompound(1, {6, 7, 8});

  // Treat surfaces 1, 5 and 10 as a single surface when meshing (i.e. mesh
  // across curves 9 and 10)
  gmsh::model::mesh::setCompound(2, {1, 5, 10});

  gmsh::finalize();

  return 0;
}
