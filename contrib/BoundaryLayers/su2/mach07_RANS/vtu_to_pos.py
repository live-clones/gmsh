#!/usr/bin/env python3
"""Convert SU2 VTU output to simple Gmsh POS scalar views."""

from __future__ import annotations

from pathlib import Path

import numpy as np

from plot_su2_results import cells_from_arrays, read_vtu

HERE = Path(__file__).resolve().parent
P2_SUBDIVISIONS = 10

VTK_LINE = 3
VTK_TRIANGLE = 5
VTK_QUAD = 9
VTK_QUADRATIC_EDGE = 21
VTK_QUADRATIC_TRIANGLE = 22
VTK_QUADRATIC_QUAD = 23
VTK_BIQUADRATIC_QUAD = 28


def fmt(x: float) -> str:
  return f"{float(x):.16g}"


def line2_shape(t: float) -> np.ndarray:
  return np.array([(1. - t) * (1. - 2. * t),
                   t * (2. * t - 1.),
                   4. * t * (1. - t)])


def tri6_shape(r: float, s: float) -> np.ndarray:
  l0 = 1. - r - s
  l1 = r
  l2 = s
  return np.array([l0 * (2. * l0 - 1.),
                   l1 * (2. * l1 - 1.),
                   l2 * (2. * l2 - 1.),
                   4. * l0 * l1,
                   4. * l1 * l2,
                   4. * l2 * l0])


def quad8_shape(xi: float, eta: float) -> np.ndarray:
  return np.array([
    -0.25 * (1. - xi) * (1. - eta) * (1. + xi + eta),
    -0.25 * (1. + xi) * (1. - eta) * (1. - xi + eta),
    -0.25 * (1. + xi) * (1. + eta) * (1. - xi - eta),
    -0.25 * (1. - xi) * (1. + eta) * (1. + xi - eta),
    0.5 * (1. - xi * xi) * (1. - eta),
    0.5 * (1. + xi) * (1. - eta * eta),
    0.5 * (1. - xi * xi) * (1. + eta),
    0.5 * (1. - xi) * (1. - eta * eta),
  ])


def quad9_shape(xi: float, eta: float) -> np.ndarray:
  lx0 = 0.5 * xi * (xi - 1.)
  lx1 = 1. - xi * xi
  lx2 = 0.5 * xi * (xi + 1.)
  ly0 = 0.5 * eta * (eta - 1.)
  ly1 = 1. - eta * eta
  ly2 = 0.5 * eta * (eta + 1.)
  return np.array([lx0 * ly0, lx2 * ly0, lx2 * ly2, lx0 * ly2,
                   lx1 * ly0, lx2 * ly1, lx1 * ly2, lx0 * ly1,
                   lx1 * ly1])


def interp(coords, scalars, weights):
  return weights @ coords, float(weights @ scalars)


def write_linear_entity(f, kind: str, coords, scalars) -> None:
  f.write(f"{kind}(")
  f.write(",".join(f"{fmt(x)},{fmt(y)},{fmt(z)}" for x, y, z in coords))
  f.write("){")
  f.write(",".join(fmt(v) for v in scalars))
  f.write("};\n")


def write_quadratic_line(f, coords, scalars, n: int) -> None:
  samples = [interp(coords, scalars, line2_shape(i / n)) for i in range(n + 1)]
  for i in range(n):
    write_linear_entity(
      f, "SL", [samples[i][0], samples[i + 1][0]],
      [samples[i][1], samples[i + 1][1]]
    )


def write_quadratic_triangle(f, coords, scalars, n: int) -> None:
  samples = {}
  for i in range(n + 1):
    for j in range(n + 1 - i):
      samples[(i, j)] = interp(coords, scalars, tri6_shape(i / n, j / n))
  for i in range(n):
    for j in range(n - i):
      p0, v0 = samples[(i, j)]
      p1, v1 = samples[(i + 1, j)]
      p2, v2 = samples[(i, j + 1)]
      write_linear_entity(f, "ST", [p0, p1, p2], [v0, v1, v2])
      if j < n - i - 1:
        p3, v3 = samples[(i + 1, j + 1)]
        write_linear_entity(f, "ST", [p1, p3, p2], [v1, v3, v2])


def write_quadratic_quad(f, coords, scalars, n: int, biquadratic: bool) -> None:
  shape = quad9_shape if biquadratic else quad8_shape
  samples = {}
  for i in range(n + 1):
    xi = -1. + 2. * i / n
    for j in range(n + 1):
      eta = -1. + 2. * j / n
      samples[(i, j)] = interp(coords, scalars, shape(xi, eta))
  for i in range(n):
    for j in range(n):
      p0, v0 = samples[(i, j)]
      p1, v1 = samples[(i + 1, j)]
      p2, v2 = samples[(i + 1, j + 1)]
      p3, v3 = samples[(i, j + 1)]
      write_linear_entity(f, "SQ", [p0, p1, p2, p3], [v0, v1, v2, v3])


def write_pos_for_values(vtu: Path, values, out: Path, cells_to_write,
                         view_name: str) -> None:
  _, _, arrays = read_vtu(vtu)
  pts = arrays["Points"]
  cells = cells_from_arrays(arrays)

  with out.open("w") as f:
    f.write(f'View "{view_name}" {{\n')
    for typ, nodes in cells:
      if typ not in cells_to_write:
        continue
      coords = pts[nodes]
      scalars = values[nodes]
      if typ == VTK_LINE and len(nodes) == 2:
        write_linear_entity(f, "SL", coords, scalars)
      elif typ == VTK_TRIANGLE and len(nodes) == 3:
        write_linear_entity(f, "ST", coords, scalars)
      elif typ == VTK_QUAD and len(nodes) == 4:
        write_linear_entity(f, "SQ", coords, scalars)
      elif typ == VTK_QUADRATIC_EDGE and len(nodes) == 3:
        write_quadratic_line(f, coords, scalars, P2_SUBDIVISIONS)
      elif typ == VTK_QUADRATIC_TRIANGLE and len(nodes) == 6:
        write_quadratic_triangle(f, coords, scalars, P2_SUBDIVISIONS)
      elif typ == VTK_QUADRATIC_QUAD and len(nodes) == 8:
        write_quadratic_quad(f, coords, scalars, P2_SUBDIVISIONS, False)
      elif typ == VTK_BIQUADRATIC_QUAD and len(nodes) == 9:
        write_quadratic_quad(f, coords, scalars, P2_SUBDIVISIONS, True)
    f.write("};\n")


def write_pos_for_field(vtu: Path, field: str, out: Path, cells_to_write) -> None:
  _, _, arrays = read_vtu(vtu)
  write_pos_for_values(vtu, arrays[field], out, cells_to_write,
                       f"{vtu.stem} {field}")


def write_all() -> None:
  flow = HERE / "flow.vtu"
  surf = HERE / "surface_flow.vtu"

  for field in ["Mach", "Pressure_Coefficient", "Y_Plus", "Eddy_Viscosity"]:
    write_pos_for_field(
      flow, field, HERE / f"flow_{field}.pos",
      {VTK_TRIANGLE, VTK_QUAD, VTK_QUADRATIC_TRIANGLE,
       VTK_QUADRATIC_QUAD, VTK_BIQUADRATIC_QUAD}
    )

  for field in ["Pressure_Coefficient", "Y_Plus", "Skin_Friction_Coefficient"]:
    if field == "Skin_Friction_Coefficient":
      # For vectors, write the magnitude as a scalar POS field.
      write_surface_vector_magnitude(surf, field, HERE / "surface_Cf_magnitude.pos")
    else:
      write_pos_for_field(
        surf, field, HERE / f"surface_{field}.pos",
        {VTK_LINE, VTK_QUADRATIC_EDGE}
      )


def write_surface_vector_magnitude(vtu: Path, field: str, out: Path) -> None:
  _, _, arrays = read_vtu(vtu)
  vals = np.linalg.norm(arrays[field], axis=1)
  write_pos_for_values(vtu, vals, out, {VTK_LINE, VTK_QUADRATIC_EDGE},
                       f"{vtu.stem} Cf magnitude")


if __name__ == "__main__":
  write_all()
  print("wrote:")
  for p in sorted(HERE.glob("*.pos")):
    print(f"  {p.name}")
