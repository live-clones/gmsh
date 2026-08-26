#!/usr/bin/env python3
"""Create a Gmsh POS view of the optimal mesh size from SU2 Mach.

The indicator is the norm of the Mach number gradient multiplied by the
triangle area. Quadrangles are split into two triangles. The written scalar is
the optimal mesh size h_i^* = h_i / r_i.
"""

from __future__ import annotations

import argparse
import math
import sys
from pathlib import Path

import numpy as np

HERE = Path(__file__).resolve().parent
TOOLS = (HERE / "../mach07_RANS").resolve()
if str(TOOLS) not in sys.path:
  sys.path.insert(0, str(TOOLS))

from plot_su2_results import cells_from_arrays, read_vtu  # type: ignore

VTK_TRIANGLE = 5
VTK_QUAD = 9
VTK_QUADRATIC_TRIANGLE = 22
VTK_QUADRATIC_QUAD = 23
VTK_BIQUADRATIC_QUAD = 28


def fmt(x: float) -> str:
  return f"{float(x):.16g}"


def triangle_area(p0: np.ndarray, p1: np.ndarray, p2: np.ndarray) -> float:
  e1 = p1[:2] - p0[:2]
  e2 = p2[:2] - p0[:2]
  return 0.5 * abs(float(e1[0] * e2[1] - e1[1] * e2[0]))


def circumradius(p0: np.ndarray, p1: np.ndarray, p2: np.ndarray) -> float:
  a = float(np.linalg.norm(p1[:2] - p0[:2]))
  b = float(np.linalg.norm(p2[:2] - p1[:2]))
  c = float(np.linalg.norm(p0[:2] - p2[:2]))
  area = triangle_area(p0, p1, p2)
  if area <= 1.e-300:
    return 0.
  return a * b * c / (4. * area)


def mach_gradient_norm(coords: np.ndarray, mach: np.ndarray) -> float:
  p0, p1, p2 = coords[:3, :2]
  mat = np.array([[p1[0] - p0[0], p1[1] - p0[1]],
                  [p2[0] - p0[0], p2[1] - p0[1]]], dtype=float)
  rhs = np.array([mach[1] - mach[0], mach[2] - mach[0]], dtype=float)
  det = float(np.linalg.det(mat))
  if abs(det) <= 1.e-300:
    return 0.
  grad = np.linalg.solve(mat, rhs)
  return float(np.linalg.norm(grad))


def split_cells(cells):
  for typ, nodes in cells:
    if typ == VTK_TRIANGLE and len(nodes) >= 3:
      yield [int(nodes[0]), int(nodes[1]), int(nodes[2])]
    elif typ == VTK_QUAD and len(nodes) >= 4:
      yield [int(nodes[0]), int(nodes[1]), int(nodes[2])]
      yield [int(nodes[0]), int(nodes[2]), int(nodes[3])]
    elif typ == VTK_QUADRATIC_TRIANGLE and len(nodes) >= 6:
      yield [int(nodes[0]), int(nodes[1]), int(nodes[2])]
    elif typ in (VTK_QUADRATIC_QUAD, VTK_BIQUADRATIC_QUAD) and len(nodes) >= 8:
      yield [int(nodes[0]), int(nodes[1]), int(nodes[2])]
      yield [int(nodes[0]), int(nodes[2]), int(nodes[3])]


def write_pos(out: Path, pts: np.ndarray, triangles, values, view_name: str) -> None:
  with out.open("w") as f:
    f.write(f'View "{view_name}" {{\n')
    for tri, val in zip(triangles, values):
      coords = pts[tri]
      f.write("ST(")
      f.write(",".join(
        f"{fmt(p[0])},{fmt(p[1])},{fmt(p[2])}" for p in coords
      ))
      f.write("){")
      f.write(f"{fmt(val)},{fmt(val)},{fmt(val)}")
      f.write("};\n")
    f.write("};\n")


def main() -> None:
  parser = argparse.ArgumentParser(
    description="Write Mach-gradient optimal mesh sizes as a Gmsh POS view."
  )
  parser.add_argument("--vtu", type=Path, default=HERE / "flow.vtu",
                      help="SU2 VTU file")
  parser.add_argument("--out", type=Path, default=HERE / "flow_Mach_hstar.pos",
                      help="output POS file")
  parser.add_argument("--target", type=float, default=None,
                      help="target number of triangles Nbar; default is current split count")
  parser.add_argument("--dimension", type=float, default=2.0,
                      help="dimension d")
  parser.add_argument("--order", type=float, default=1.0,
                      help="convergence order k")
  parser.add_argument("--eps-floor", type=float, default=1.e-14,
                      help="lower bound for the Mach-gradient indicator")
  args = parser.parse_args()

  _, _, arrays = read_vtu(args.vtu)
  pts = arrays["Points"]
  mach = arrays["Mach"]
  triangles = list(split_cells(cells_from_arrays(arrays)))
  if not triangles:
    raise RuntimeError(f"No triangles or quads found in {args.vtu}")

  eps = []
  radii = []
  kept_triangles = []
  for tri in triangles:
    coords = pts[tri]
    area = triangle_area(coords[0], coords[1], coords[2])
    radius = circumradius(coords[0], coords[1], coords[2])
    if area <= 0. or radius <= 0.:
      continue
    kept_triangles.append(tri)
    radii.append(radius)
    eps.append(max(mach_gradient_norm(coords, mach[tri]) * area,
                   args.eps_floor))

  if not kept_triangles:
    raise RuntimeError("No non-degenerate triangles found")

  eps_arr = np.array(eps, dtype=float)
  d = float(args.dimension)
  k = float(args.order)
  alpha = 2. * k / d
  nbar = float(args.target) if args.target is not None else float(len(kept_triangles))

  # General form of the error-equidistribution reduction factor.
  eps_exp = 2. / (d * (1. + alpha))
  sum_exp = 2. / (1. + alpha)
  alpha_factor = alpha ** (-1. / (d * (1. + alpha)))
  denom = (
    np.sum(eps_arr ** sum_exp) *
    (alpha ** (-(2. + alpha) / (1. + alpha)) +
     alpha ** (1. / (1. + alpha)))
  )
  if denom <= 0.:
    raise RuntimeError("Invalid normalization denominator")
  global_factor = (((1. + alpha) * nbar) / denom) ** (1. / d)
  r = (eps_arr ** eps_exp) * alpha_factor * global_factor

  h = np.array(radii, dtype=float)
  hstar = h / np.maximum(r, 1.e-300)
  write_pos(args.out, pts, kept_triangles, hstar, "Mach gradient optimal mesh size")
  print(f"wrote {args.out}")
  print(f"triangles: {len(kept_triangles)} target: {nbar:g} d: {d:g} k: {k:g} alpha: {alpha:g}")
  print(f"eps min/max: {eps_arr.min():.6g} {eps_arr.max():.6g}")
  print(f"r min/max/mean: {r.min():.6g} {r.max():.6g} {r.mean():.6g}")
  print(f"h* min/max/mean: {hstar.min():.6g} {hstar.max():.6g} {hstar.mean():.6g}")


if __name__ == "__main__":
  main()
