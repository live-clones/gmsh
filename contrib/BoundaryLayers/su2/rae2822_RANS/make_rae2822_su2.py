#!/usr/bin/env python3
"""Generate a RAE2822 boundary-layer mesh in SU2 format and optionally run SU2."""

from __future__ import annotations

import os
import re
import shutil
import subprocess
import math
import csv
from pathlib import Path

os.environ.setdefault("OMPI_MCA_btl", "^tcp")

import gmsh  # type: ignore

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[3]
GEO = Path(os.environ.get(
  "RAE2822_GEO", str(REPO / "benchmarks" / "bl" / "RAE2822.geo")))
GEOMETRY_ONLY = HERE / "_rae2822_geometry.geo"
MESH = HERE / "rae2822_bl.su2"

USE_NICE_GEO = GEO.name in ("RAE2822_NICE.geo", "RAE2822_adapt.geo")

SURFACE = 1 if USE_NICE_GEO else 16
BL_CURVES = [1, 2]
FARFIELD_CURVES = [3] if USE_NICE_GEO else [3, 4, 5, 6]
AOA_DEGREES = 2.8

FARFIELD_CENTER_X = 0.5
FARFIELD_CENTER_Y = 0.0
FARFIELD_RADIUS = 20.0
FARFIELD_MESH_SIZE = 1.5

THICKNESS = 0.005 if USE_NICE_GEO else 0.02
FIRST_LAYER_SIZE = 2.e-5
RATIO = 1.2
SMOOTHING_LAYERS = 25 if USE_NICE_GEO else 5
HIGH_ORDER = 1
HIGH_ORDER_SUBEDGES = 10
PARAMETRIC_QUADRATURE_POINTS = 7

TRAILING_EDGE_POINTS = [65]
TRAILING_EDGE_SIZE = 0.002
TRAILING_EDGE_SIZE_MAX = FARFIELD_MESH_SIZE
TRAILING_EDGE_DIST_MIN = 0.01
TRAILING_EDGE_DIST_MAX = 0.06
TRIM_TRAILING_EDGE_BL = False

NEAR_WALL_SIZE = 0.003
NEAR_WALL_DIST_MIN = THICKNESS
NEAR_WALL_DIST_MAX = 0.75

AIRFOIL_HALO_SIZE = 0.02
AIRFOIL_HALO_DIST_MIN = 0.25
AIRFOIL_HALO_DIST_MAX = 0.9

WAKE_SIZE = 0.03
WAKE_XMIN = 0.98
WAKE_XMAX = 10.0
WAKE_HALF_WIDTH = 0.18
WAKE_TRANSITION_DISTANCE = 0.45
WAKE_SAMPLES = 80

SHOCK_REFINEMENT = os.environ.get(
  "RAE2822_SHOCK_REFINEMENT", "0" if USE_NICE_GEO else "1") != "0"
SHOCK_AUTO_FROM_CP = True
SHOCK_CP_FILE = HERE / "surface_cp_xy.csv"
SHOCK_FLOW_FILE = HERE / "flow.vtu"
SHOCK_X = 0.54
SHOCK_Y = 0.061
SHOCK_TILT_DX_DY = -0.08
SHOCK_LENGTH = 1.0
SHOCK_SIZE = 0.004
SHOCK_DIST_MIN = 0.01
SHOCK_DIST_MAX = 0.12
SHOCK_SAMPLES = 100
SHOCK_YMIN = 0.055
SHOCK_YMAX = 0.35
SHOCK_MIN_SCORE = 6.0


def airfoil_curves() -> list[int]:
  if TRIM_TRAILING_EDGE_BL:
    return [1, 101, 102, 2]
  return BL_CURVES


def shock_seed_from_surface_cp() -> tuple[float, float]:
  if not SHOCK_AUTO_FROM_CP or not SHOCK_CP_FILE.exists():
    return SHOCK_X, SHOCK_Y

  points = []
  with SHOCK_CP_FILE.open() as f:
    for row in csv.DictReader(f):
      x = float(row["x"])
      y = float(row["y"])
      cp = float(row["Cp"])
      if y > 1.e-6 and 0.25 < x < 0.75:
        points.append((x, y, cp))
  points.sort()
  if len(points) < 3:
    return SHOCK_X, SHOCK_Y

  # Locate the strongest pressure recovery on the upper side. This is only used
  # to place the refinement for the next mesh, not in the flow solve itself.
  best_jump = -1.e100
  best_seed = (SHOCK_X, SHOCK_Y)
  for p0, p1 in zip(points[:-1], points[1:]):
    dx = p1[0] - p0[0]
    if dx <= 1.e-10:
      continue
    dcpdx = (p1[2] - p0[2]) / dx
    if dcpdx > best_jump:
      best_jump = dcpdx
      best_seed = (0.5 * (p0[0] + p1[0]), 0.5 * (p0[1] + p1[1]))
  return best_seed


def shock_points_from_flow() -> list[tuple[float, float]]:
  if not SHOCK_FLOW_FILE.exists():
    return []

  sys_path = str((HERE / "../mach07_RANS").resolve())
  import sys
  if sys_path not in sys.path:
    sys.path.insert(0, sys_path)
  from plot_su2_results import read_vtu  # type: ignore

  _, _, data = read_vtu(SHOCK_FLOW_FILE)
  pts = data["Points"]
  mach = data["Mach"]
  cp = data["Pressure_Coefficient"]
  x = pts[:, 0]
  y = pts[:, 1]

  shock = []
  for yc in [SHOCK_YMIN + i * (SHOCK_YMAX - SHOCK_YMIN) / 20 for i in range(21)]:
    h = 0.014 + 0.025 * yc
    mask = (
      (y > yc - h) & (y < yc + h) &
      (x > 0.3) & (x < 0.9) & (mach > 0.2)
    )
    if mask.sum() < 12:
      continue

    xx = x[mask]
    mm = mach[mask]
    cc = cp[mask]
    bins = [0.3 + i * 0.6 / 96 for i in range(97)]
    xb, mb, cb = [], [], []
    for i in range(len(bins) - 1):
      bmask = (xx >= bins[i]) & (xx < bins[i + 1])
      if bmask.sum() >= 2:
        xb.append(0.5 * (bins[i] + bins[i + 1]))
        vals_m = sorted(float(v) for v in mm[bmask])
        vals_c = sorted(float(v) for v in cc[bmask])
        mb.append(vals_m[len(vals_m) // 2])
        cb.append(vals_c[len(vals_c) // 2])

    if len(xb) < 8:
      continue

    best_score = -1.e100
    best_x = None
    for i in range(len(xb) - 1):
      dx = xb[i + 1] - xb[i]
      if dx <= 0.:
        continue
      dmdx = (mb[i + 1] - mb[i]) / dx
      dcpdx = (cb[i + 1] - cb[i]) / dx
      score = max(-dmdx, 0.) + 0.25 * max(dcpdx, 0.)
      if score > best_score:
        best_score = score
        best_x = 0.5 * (xb[i] + xb[i + 1])

    if best_x is not None and best_score > SHOCK_MIN_SCORE:
      shock.append((best_x, yc))

  if not shock:
    return []

  # Keep a compact, ordered point cloud. The last valid solution can be a little
  # noisy close to the wall, so this deliberately feeds Gmsh a cloud instead of
  # fitting a single straight line.
  shock.sort(key=lambda p: p[1])
  return shock


def write_geometry_only() -> None:
  """Strip the mesh/plugin commands from the benchmark .geo file."""
  src = GEO.read_text()
  cut = src.find("\nMesh 2;")
  if cut < 0:
    raise RuntimeError(f"Could not find 'Mesh 2;' in {GEO}")
  src = src[:cut]

  if USE_NICE_GEO:
    GEOMETRY_ONLY.write_text(src + "\n")
    return

  farfield_points = {
    1066: (FARFIELD_CENTER_X - FARFIELD_RADIUS, FARFIELD_CENTER_Y),
    1067: (FARFIELD_CENTER_X, FARFIELD_CENTER_Y + FARFIELD_RADIUS),
    1068: (FARFIELD_CENTER_X + FARFIELD_RADIUS, FARFIELD_CENTER_Y),
    1069: (FARFIELD_CENTER_X, FARFIELD_CENTER_Y - FARFIELD_RADIUS),
  }
  for tag, (x, y) in farfield_points.items():
    src = re.sub(
      rf"Point\({tag}\)\s*=\s*\{{[^}}]+\}};",
      f"Point({tag}) = {{{x:.16g}, {y:.16g}, 0, {FARFIELD_MESH_SIZE:.16g}}};",
      src
    )
  src = re.sub(
    r"Point\(1069\)\s*=\s*\{[^}]+\};",
    f"Point(1069) = {{{farfield_points[1069][0]:.16g}, "
    f"{farfield_points[1069][1]:.16g}, 0, {FARFIELD_MESH_SIZE:.16g}}};\n"
    f"Point(2000) = {{{FARFIELD_CENTER_X:.16g}, {FARFIELD_CENTER_Y:.16g}, "
    f"0, {FARFIELD_MESH_SIZE:.16g}}};",
    src
  )
  for tag, a, b in [(3, 1066, 1067), (4, 1067, 1068),
                    (5, 1068, 1069), (6, 1069, 1066)]:
    src = re.sub(
      rf"Line\({tag}\)\s*=\s*\{{[^}}]+\}};",
      f"Circle({tag}) = {{{a}, 2000, {b}}};",
      src
    )
  src = re.sub(
    r"MeshSize\s*\{\s*1066\s*,\s*1067\s*,\s*1068\s*,\s*1069\s*\}\s*=\s*[^;]+;",
    f"MeshSize {{1066, 1067, 1068, 1069}} = {FARFIELD_MESH_SIZE:.16g};",
    src
  )

  if TRIM_TRAILING_EDGE_BL:
    src = src.replace(
      "Spline(1) = {1 ... 65};",
      "Spline(1) = {1 ... 64};\nSpline(101) = {64, 65};"
    )
    src = src.replace(
      "Spline(2) = {1, 1001 ... 1063, 65};",
      "Spline(2) = {1, 1001 ... 1063};\nSpline(102) = {1063, 65};"
    )
    src = src.replace("Line Loop(8) = {1, -2};",
                      "Line Loop(8) = {1, 101, -102, -2};")
  GEOMETRY_ONLY.write_text(src + "\n")


def add_mesh_refinement() -> None:
  fields = []

  wall_dist = gmsh.model.mesh.field.add("Distance")
  gmsh.model.mesh.field.setNumbers(wall_dist, "CurvesList", BL_CURVES)
  gmsh.model.mesh.field.setNumber(wall_dist, "Sampling", 200)

  wall_threshold = gmsh.model.mesh.field.add("Threshold")
  gmsh.model.mesh.field.setNumber(wall_threshold, "InField", wall_dist)
  gmsh.model.mesh.field.setNumber(wall_threshold, "SizeMin", NEAR_WALL_SIZE)
  gmsh.model.mesh.field.setNumber(wall_threshold, "SizeMax", FARFIELD_MESH_SIZE)
  gmsh.model.mesh.field.setNumber(wall_threshold, "DistMin", NEAR_WALL_DIST_MIN)
  gmsh.model.mesh.field.setNumber(wall_threshold, "DistMax", NEAR_WALL_DIST_MAX)
  fields.append(wall_threshold)

  halo_threshold = gmsh.model.mesh.field.add("Threshold")
  gmsh.model.mesh.field.setNumber(halo_threshold, "InField", wall_dist)
  gmsh.model.mesh.field.setNumber(halo_threshold, "SizeMin", AIRFOIL_HALO_SIZE)
  gmsh.model.mesh.field.setNumber(halo_threshold, "SizeMax", FARFIELD_MESH_SIZE)
  gmsh.model.mesh.field.setNumber(halo_threshold, "DistMin",
                                  AIRFOIL_HALO_DIST_MIN)
  gmsh.model.mesh.field.setNumber(halo_threshold, "DistMax",
                                  AIRFOIL_HALO_DIST_MAX)
  fields.append(halo_threshold)

  wake_slope = math.tan(math.radians(AOA_DEGREES))
  wake_points = []
  for i in range(WAKE_SAMPLES):
    t = i / (WAKE_SAMPLES - 1)
    x = WAKE_XMIN + t * (WAKE_XMAX - WAKE_XMIN)
    y = wake_slope * (x - 1.0)
    wake_points.append(gmsh.model.geo.addPoint(x, y, 0.0, WAKE_SIZE))
  gmsh.model.geo.synchronize()

  wake_dist = gmsh.model.mesh.field.add("Distance")
  gmsh.model.mesh.field.setNumbers(wake_dist, "PointsList", wake_points)

  wake_threshold = gmsh.model.mesh.field.add("Threshold")
  gmsh.model.mesh.field.setNumber(wake_threshold, "InField", wake_dist)
  gmsh.model.mesh.field.setNumber(wake_threshold, "SizeMin", WAKE_SIZE)
  gmsh.model.mesh.field.setNumber(wake_threshold, "SizeMax", FARFIELD_MESH_SIZE)
  gmsh.model.mesh.field.setNumber(wake_threshold, "DistMin", WAKE_HALF_WIDTH)
  gmsh.model.mesh.field.setNumber(wake_threshold, "DistMax", WAKE_TRANSITION_DISTANCE)
  fields.append(wake_threshold)

  if SHOCK_REFINEMENT:
    xy_shock = shock_points_from_flow()
    if not xy_shock:
      x0, y0 = shock_seed_from_surface_cp()
      xy_shock = []
      for i in range(SHOCK_SAMPLES):
        t = i / (SHOCK_SAMPLES - 1)
        dy = SHOCK_LENGTH * t
        xy_shock.append((x0 + SHOCK_TILT_DX_DY * dy, y0 + dy))

    shock_points = []
    for x, y in xy_shock:
      shock_points.append(gmsh.model.geo.addPoint(x, y, 0.0, SHOCK_SIZE))
    gmsh.model.geo.synchronize()

    shock_dist = gmsh.model.mesh.field.add("Distance")
    gmsh.model.mesh.field.setNumbers(shock_dist, "PointsList", shock_points)

    shock_threshold = gmsh.model.mesh.field.add("Threshold")
    gmsh.model.mesh.field.setNumber(shock_threshold, "InField", shock_dist)
    gmsh.model.mesh.field.setNumber(shock_threshold, "SizeMin", SHOCK_SIZE)
    gmsh.model.mesh.field.setNumber(shock_threshold, "SizeMax", FARFIELD_MESH_SIZE)
    gmsh.model.mesh.field.setNumber(shock_threshold, "DistMin", SHOCK_DIST_MIN)
    gmsh.model.mesh.field.setNumber(shock_threshold, "DistMax", SHOCK_DIST_MAX)
    fields.append(shock_threshold)
    x0, y0 = xy_shock[0]
    x1, y1 = xy_shock[-1]
    print(
      "shock refinement: "
      f"{len(xy_shock)} points from ({x0:.6g}, {y0:.6g}) "
      f"to ({x1:.6g}, {y1:.6g}), size {SHOCK_SIZE:.6g}, "
      f"dist {SHOCK_DIST_MIN:.6g}..{SHOCK_DIST_MAX:.6g}"
    )

  dist = gmsh.model.mesh.field.add("Distance")
  gmsh.model.mesh.field.setNumbers(dist, "PointsList", TRAILING_EDGE_POINTS)

  threshold = gmsh.model.mesh.field.add("Threshold")
  gmsh.model.mesh.field.setNumber(threshold, "InField", dist)
  gmsh.model.mesh.field.setNumber(threshold, "SizeMin", TRAILING_EDGE_SIZE)
  gmsh.model.mesh.field.setNumber(threshold, "SizeMax", TRAILING_EDGE_SIZE_MAX)
  gmsh.model.mesh.field.setNumber(threshold, "DistMin", TRAILING_EDGE_DIST_MIN)
  gmsh.model.mesh.field.setNumber(threshold, "DistMax", TRAILING_EDGE_DIST_MAX)
  fields.append(threshold)

  background = gmsh.model.mesh.field.add("Min")
  gmsh.model.mesh.field.setNumbers(background, "FieldsList", fields)
  gmsh.model.mesh.field.setAsBackgroundMesh(background)


def generate_mesh() -> None:
  write_geometry_only()
  gmsh.initialize()
  try:
    gmsh.option.setNumber("General.Terminal", 1)
    gmsh.option.setNumber("General.Verbosity", 3)
    gmsh.option.setNumber("Mesh.NumSubEdges", HIGH_ORDER_SUBEDGES)
    if not USE_NICE_GEO:
      gmsh.option.setNumber("Mesh.MeshSizeFromCurvature", 20)
      gmsh.option.setNumber("Mesh.MeshSizeExtendFromBoundary", 1)
      gmsh.option.setNumber("Mesh.MeshSizeMax", FARFIELD_MESH_SIZE)

    gmsh.merge(str(GEOMETRY_ONLY))
    gmsh.model.geo.synchronize()
    if not USE_NICE_GEO:
      gmsh.option.setNumber("Mesh.MeshSizeFromCurvature", 20)
      gmsh.option.setNumber("Mesh.MeshSizeExtendFromBoundary", 1)
      gmsh.option.setNumber("Mesh.MeshSizeMax", FARFIELD_MESH_SIZE)
      add_mesh_refinement()
    gmsh.model.mesh.generate(2)

    gmsh.plugin.setString("BoundaryLayer", "Surfaces", str(SURFACE))
    gmsh.plugin.setString(
      "BoundaryLayer", "Curves", ",".join(str(c) for c in BL_CURVES))
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
    airfoil = gmsh.model.addPhysicalGroup(1, airfoil_curves(), name="airfoil")
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
