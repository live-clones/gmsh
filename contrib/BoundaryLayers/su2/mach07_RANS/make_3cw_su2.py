#!/usr/bin/env python3
"""Generate a 3CW boundary-layer mesh in SU2 format and optionally run SU2."""

from __future__ import annotations

import os
import shutil
import subprocess
from pathlib import Path

os.environ.setdefault("OMPI_MCA_btl", "^tcp")

import gmsh  # type: ignore

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[3]
GEO = REPO / "benchmarks" / "bl" / "3cw.geo"
MESH = HERE / "3cw_bl.su2"

SURFACE = 16
WALL_CURVES = [1, 2, 3, 4, 5, 6, 7]
FARFIELD_CURVES = [8, 9, 10, 11]
TRAILING_EDGE_POINTS = [1, 2]

THICKNESS = 20.0
FIRST_LAYER_SIZE = 0.002
RATIO = 1.2
SMOOTHING_LAYERS = 5
HIGH_ORDER = 1
HIGH_ORDER_SUBEDGES = 10
PARAMETRIC_QUADRATURE_POINTS = 7
TRAILING_EDGE_SIZE = 4.0
TRAILING_EDGE_SIZE_MAX = 1.e22
TRAILING_EDGE_DIST_MIN = 1.0
TRAILING_EDGE_DIST_MAX = 8.0


def add_trailing_edge_refinement() -> None:
  dist = gmsh.model.mesh.field.add("Distance")
  gmsh.model.mesh.field.setNumbers(dist, "PointsList", TRAILING_EDGE_POINTS)

  threshold = gmsh.model.mesh.field.add("Threshold")
  gmsh.model.mesh.field.setNumber(threshold, "InField", dist)
  gmsh.model.mesh.field.setNumber(threshold, "SizeMin", TRAILING_EDGE_SIZE)
  gmsh.model.mesh.field.setNumber(threshold, "SizeMax", TRAILING_EDGE_SIZE_MAX)
  gmsh.model.mesh.field.setNumber(threshold, "DistMin", TRAILING_EDGE_DIST_MIN)
  gmsh.model.mesh.field.setNumber(threshold, "DistMax", TRAILING_EDGE_DIST_MAX)
  gmsh.model.mesh.field.setAsBackgroundMesh(threshold)


def generate_mesh() -> None:
  gmsh.initialize()
  try:
    gmsh.option.setNumber("General.Terminal", 1)
    gmsh.option.setNumber("General.Verbosity", 3)
    gmsh.option.setNumber("Mesh.MeshSizeFactor", 0.5)
    gmsh.option.setNumber("Mesh.MeshSizeFromCurvature", 20)
    gmsh.option.setNumber("Mesh.MeshSizeExtendFromBoundary", 0)
    gmsh.option.setNumber("Mesh.NumSubEdges", HIGH_ORDER_SUBEDGES)

    gmsh.merge(str(GEO))
    gmsh.model.occ.synchronize()
    add_trailing_edge_refinement()
    gmsh.model.mesh.generate(2)

    gmsh.plugin.setString("BoundaryLayer", "Surfaces", str(SURFACE))
    gmsh.plugin.setString(
      "BoundaryLayer", "Curves", ",".join(str(c) for c in WALL_CURVES)
    )
    gmsh.plugin.setNumber("BoundaryLayer", "Thickness", THICKNESS)
    gmsh.plugin.setNumber("BoundaryLayer", "Size", FIRST_LAYER_SIZE)
    gmsh.plugin.setNumber("BoundaryLayer", "Ratio", RATIO)
    gmsh.plugin.setNumber("BoundaryLayer", "SmoothingLayers", SMOOTHING_LAYERS)
    gmsh.plugin.setNumber("BoundaryLayer", "HighOrder", HIGH_ORDER)
    gmsh.plugin.setNumber(
      "BoundaryLayer", "ParametricQuadraturePoints",
      PARAMETRIC_QUADRATURE_POINTS
    )
    gmsh.plugin.run("BoundaryLayer")

    fluid = gmsh.model.addPhysicalGroup(2, [SURFACE], name="fluid")
    airfoil = gmsh.model.addPhysicalGroup(1, WALL_CURVES, name="airfoil")
    farfield = gmsh.model.addPhysicalGroup(1, FARFIELD_CURVES, name="farfield")
    gmsh.model.setPhysicalName(2, fluid, "fluid")
    gmsh.model.setPhysicalName(1, airfoil, "airfoil")
    gmsh.model.setPhysicalName(1, farfield, "farfield")

    gmsh.option.setNumber("Mesh.Format", 42)
    gmsh.write(str(MESH))
  finally:
    gmsh.finalize()


def run_su2() -> None:
  su2 = shutil.which("SU2_CFD")
  if not su2:
    local = Path.home() / "SU2" / "bin" / "SU2_CFD"
    if local.exists():
      su2 = str(local)
  if not su2:
    print("SU2_CFD was not found in PATH.")
    print("Generated mesh:", MESH)
    print("Run manually after loading SU2:")
    print(f"  cd {HERE}")
    print("  SU2_CFD config.cfg")
    return

  subprocess.run([su2, "config.cfg"], cwd=HERE, check=True)


if __name__ == "__main__":
  generate_mesh()
  run_su2()
