#!/usr/bin/env python3
"""Generate the 3CW boundary-layer figures used in the notes.

The script deliberately runs several independent Gmsh sessions. This makes it
possible to save the useful intermediate states:

  1. the initial mesh without boundary layer;
  2. a single boundary-layer row, obtained with Size = Thickness;
  3. the P2 large-element state before parametric layer splitting;
  4. the final split P2 boundary-layer mesh.
  5. the same split P2 mesh with a much larger smoothing neighborhood.

Images are rendered with matplotlib from the generated MSH files, so no Gmsh GUI
context is required.
"""

from __future__ import annotations

import os
from collections import Counter, defaultdict
from dataclasses import dataclass
from math import sqrt
from pathlib import Path
from time import perf_counter
from typing import Dict, Iterable, List, Optional, Sequence, Tuple

os.environ.setdefault("MPLCONFIGDIR", "/tmp/matplotlib-gmsh")
# Avoid an OpenMPI TCP listener warning in restricted batch environments. This
# script does not use MPI communication.
os.environ.setdefault("OMPI_MCA_btl", "^tcp")

import gmsh  # type: ignore
import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.collections import LineCollection


SCRIPT_DIR = Path(__file__).resolve().parent
REPO = SCRIPT_DIR.parents[1]
GEO = REPO / "benchmarks" / "bl" / "3cw.geo"
FIG_DIR = SCRIPT_DIR / "figures"
TMP_DIR = Path("/tmp")

SURFACE = "16"
CURVES = "1,2,3,4,5,6,7"
WALL_CURVE_TAGS = set(range(1, 8))

THICKNESS = 40.0
FIRST_LAYER_SIZE = 0.3
RATIO = 1.5
SMOOTHING_LAYERS = 5
GLOBAL_SMOOTHING_LAYERS = 100
PARAMETRIC_QUADRATURE_POINTS = 3
HIGH_ORDER_SUBEDGES = 10
MESH_SIZE_FACTOR = 0.5
MESH_SIZE_FROM_CURVATURE = 20
MESH_SIZE_EXTEND_FROM_BOUNDARY = 0

LEADING_EDGE_ZOOM = (-130.0, 170.0, -190.0, 90.0)
TRAILING_EDGE_ZOOM = (1020.0, 1260.0, -190.0, 20.0)


@dataclass
class Case:
  name: str
  msh: Path
  plugin: bool
  high_order: int = 1
  high_order_strategy: Optional[int] = None
  thickness: float = THICKNESS
  size: float = FIRST_LAYER_SIZE
  ratio: float = RATIO
  smoothing_layers: int = SMOOTHING_LAYERS
  mean_plane_untangler: int = 1
  image_title: str = ""


CASES = [
  Case(
    name="no_bl",
    msh=TMP_DIR / "3cw_no_bl.msh",
    plugin=False,
    image_title="3CW mesh without boundary layer",
  ),
  Case(
    name="single_layer",
    msh=TMP_DIR / "3cw_bl_single_layer.msh",
    plugin=True,
    high_order=1,
    thickness=THICKNESS,
    size=THICKNESS,
    image_title="3CW single boundary-layer row",
  ),
  Case(
    name="p2_unsplit",
    msh=TMP_DIR / "3cw_bl_p2_unsplit.msh",
    plugin=True,
    high_order=2,
    high_order_strategy=0,
    image_title="3CW P2 large boundary-layer elements before splitting",
  ),
  Case(
    name="p2_split",
    msh=TMP_DIR / "3cw_bl.msh",
    plugin=True,
    high_order=2,
    high_order_strategy=2,
    image_title="3CW split P2 boundary-layer mesh",
  ),
  Case(
    name="p2_split_global_smoothing",
    msh=TMP_DIR / "3cw_bl_global_smoothing.msh",
    plugin=True,
    high_order=2,
    high_order_strategy=2,
    smoothing_layers=GLOBAL_SMOOTHING_LAYERS,
    image_title="3CW split P2 mesh with global smoothing",
  ),
]


def target_layer_widths() -> List[float]:
  widths: List[float] = []
  total = 0.0
  h = FIRST_LAYER_SIZE
  while True:
    widths.append(h)
    total += h
    if total + h >= THICKNESS:
      break
    h *= RATIO
  return widths


def run_case(case: Case) -> None:
  print(f"\n== Running {case.name} ==")
  gmsh.initialize()
  try:
    gmsh.option.setNumber("General.Terminal", 1)
    gmsh.option.setNumber("General.Verbosity", 3)
    gmsh.option.setNumber("Mesh.MeshSizeFactor", MESH_SIZE_FACTOR)
    gmsh.option.setNumber("Mesh.MeshSizeFromCurvature", MESH_SIZE_FROM_CURVATURE)
    gmsh.option.setNumber(
      "Mesh.MeshSizeExtendFromBoundary", MESH_SIZE_EXTEND_FROM_BOUNDARY
    )
    gmsh.option.setNumber("Mesh.NumSubEdges", HIGH_ORDER_SUBEDGES)
    gmsh.merge(str(GEO))
    gmsh.model.occ.synchronize()
    gmsh.model.mesh.generate(2)

    if case.plugin:
      gmsh.plugin.setString("BoundaryLayer", "Surfaces", SURFACE)
      gmsh.plugin.setString("BoundaryLayer", "Curves", CURVES)
      gmsh.plugin.setNumber("BoundaryLayer", "Thickness", case.thickness)
      gmsh.plugin.setNumber("BoundaryLayer", "Size", case.size)
      gmsh.plugin.setNumber("BoundaryLayer", "Ratio", case.ratio)
      gmsh.plugin.setNumber(
        "BoundaryLayer", "SmoothingLayers", case.smoothing_layers
      )
      gmsh.plugin.setNumber("BoundaryLayer", "HighOrder", case.high_order)
      gmsh.plugin.setNumber(
        "BoundaryLayer", "MeanPlaneUntangler", case.mean_plane_untangler
      )
      gmsh.plugin.setNumber(
        "BoundaryLayer",
        "ParametricQuadraturePoints",
        PARAMETRIC_QUADRATURE_POINTS,
      )
      if case.high_order_strategy is not None:
        gmsh.plugin.setNumber(
          "BoundaryLayer", "HighOrderStrategy", case.high_order_strategy
        )
      gmsh.plugin.run("BoundaryLayer")

    gmsh.write(str(case.msh))
  finally:
    gmsh.finalize()


def read_msh(path: Path):
  coords: Dict[int, Tuple[float, float, float]] = {}
  node_entity: Dict[int, Tuple[int, int]] = {}
  elements: List[Tuple[int, int, int, int, List[int]]] = []

  lines = [line.strip() for line in path.read_text().splitlines()]
  i = 0
  while i < len(lines):
    if lines[i] == "$Nodes":
      i += 1
      num_blocks, _, _, _ = map(int, lines[i].split())
      i += 1
      for _ in range(num_blocks):
        dim, tag, _, num_nodes = map(int, lines[i].split())
        i += 1
        tags = []
        for _ in range(num_nodes):
          node = int(lines[i])
          tags.append(node)
          node_entity[node] = (dim, tag)
          i += 1
        for node in tags:
          x, y, z = map(float, lines[i].split()[:3])
          coords[node] = (x, y, z)
          i += 1
    elif lines[i] == "$Elements":
      i += 1
      num_blocks, _, _, _ = map(int, lines[i].split())
      i += 1
      for _ in range(num_blocks):
        dim, tag, etype, num_elements = map(int, lines[i].split())
        i += 1
        for _ in range(num_elements):
          values = list(map(int, lines[i].split()))
          elements.append((dim, tag, etype, values[0], values[1:]))
          i += 1
    i += 1
  return coords, node_entity, elements


def element_edges(corners: Sequence[int]) -> List[Tuple[int, int]]:
  if len(corners) == 3:
    return [(corners[0], corners[1]), (corners[1], corners[2]),
            (corners[2], corners[0])]
  return [(corners[0], corners[1]), (corners[1], corners[2]),
          (corners[2], corners[3]), (corners[3], corners[0])]


def line_segments_from_points(points):
  return [[points[i], points[i + 1]] for i in range(len(points) - 1)]


def quadratic_edge_segments(coords, a: int, b: int, m: int):
  p0 = coords[a]
  p1 = coords[b]
  pm = coords[m]
  points = []
  for i in range(HIGH_ORDER_SUBEDGES + 1):
    t = i / HIGH_ORDER_SUBEDGES
    s = 1.0 - t
    x = s * s * p0[0] + 2.0 * s * t * pm[0] + t * t * p1[0]
    y = s * s * p0[1] + 2.0 * s * t * pm[1] + t * t * p1[1]
    points.append((x, y))
  return line_segments_from_points(points)


def linear_edge_segment(coords, a: int, b: int):
  return [[(coords[a][0], coords[a][1]), (coords[b][0], coords[b][1])]]


def collect_segments(coords, elements):
  triangles = []
  quads = []
  lines = []
  for dim, _, etype, _, nodes in elements:
    if dim == 1 and etype == 1:
      a, b = nodes[:2]
      lines.extend(linear_edge_segment(coords, a, b))
      continue
    if dim == 1 and etype == 8:
      lines.extend(quadratic_edge_segments(coords, nodes[0], nodes[1], nodes[2]))
      continue
    if dim != 2:
      continue
    if etype == 2:
      corners = nodes[:3]
      for a, b in element_edges(corners):
        triangles.extend(linear_edge_segment(coords, a, b))
    elif etype == 9:
      triangles.extend(quadratic_edge_segments(coords, nodes[0], nodes[1],
                                               nodes[3]))
      triangles.extend(quadratic_edge_segments(coords, nodes[1], nodes[2],
                                               nodes[4]))
      triangles.extend(quadratic_edge_segments(coords, nodes[2], nodes[0],
                                               nodes[5]))
    elif etype == 3:
      corners = nodes[:4]
      for a, b in element_edges(corners):
        quads.extend(linear_edge_segment(coords, a, b))
    elif etype == 10:
      quads.extend(quadratic_edge_segments(coords, nodes[0], nodes[1], nodes[4]))
      quads.extend(quadratic_edge_segments(coords, nodes[1], nodes[2], nodes[5]))
      quads.extend(quadratic_edge_segments(coords, nodes[2], nodes[3], nodes[6]))
      quads.extend(quadratic_edge_segments(coords, nodes[3], nodes[0], nodes[7]))
  return triangles, quads, lines


def plot_mesh(path: Path, out: Path, title: str,
              zoom: Optional[Tuple[float, float, float, float]] = None) -> None:
  coords, _, elements = read_msh(path)
  triangles, quads, lines = collect_segments(coords, elements)

  fig, ax = plt.subplots(figsize=(8, 5), dpi=220)
  if triangles:
    ax.add_collection(LineCollection(triangles, colors="0.15", linewidths=0.22))
  if quads:
    ax.add_collection(LineCollection(quads, colors="#0066cc", linewidths=0.34))
  if lines:
    ax.add_collection(LineCollection(lines, colors="black", linewidths=0.28))

  xs = [p[0] for p in coords.values()]
  ys = [p[1] for p in coords.values()]
  ax.set_aspect("equal", adjustable="box")
  if zoom:
    ax.set_xlim(zoom[0], zoom[1])
    ax.set_ylim(zoom[2], zoom[3])
  else:
    ax.set_xlim(min(xs), max(xs))
    ax.set_ylim(min(ys), max(ys))
  ax.set_title(title, fontsize=10)
  ax.axis("off")
  fig.tight_layout(pad=0)
  fig.savefig(out, bbox_inches="tight", pad_inches=0.02)
  plt.close(fig)
  print(f"wrote {out}")


def analyze_boundary_layer(path: Path) -> None:
  coords, node_entity, elements = read_msh(path)
  wall_edges = set()
  for dim, tag, etype, _, nodes in elements:
    if dim == 1 and tag in WALL_CURVE_TAGS and etype in (1, 8, 26, 27, 28):
      wall_edges.add(tuple(sorted((nodes[0], nodes[1]))))

  quads = []
  for dim, tag, etype, eid, nodes in elements:
    if dim == 2 and tag == int(SURFACE) and etype in (3, 10):
      quads.append((eid, nodes[:4], etype))

  edge_to_quads = defaultdict(list)
  for qi, (_, corners, _) in enumerate(quads):
    for ei, edge in enumerate(element_edges(corners)):
      edge_to_quads[tuple(sorted(edge))].append((qi, ei))

  def midpoint(edge: Tuple[int, int]):
    a, b = edge
    return tuple((coords[a][j] + coords[b][j]) * 0.5 for j in range(3))

  def distance(p, q):
    return sqrt(sum((p[j] - q[j]) ** 2 for j in range(3)))

  def edge_at(qi: int, ei: int):
    return element_edges(quads[qi][1])[ei]

  counts = []
  outer_distances = []
  seen = set()
  for qi, (_, corners, _) in enumerate(quads):
    for ei, edge in enumerate(element_edges(corners)):
      key = tuple(sorted(edge))
      if key not in wall_edges or key in seen:
        continue
      seen.add(key)
      current_q = qi
      current_e = ei
      previous_q = None
      chain = []
      layer_edges = [edge]
      while True:
        chain.append(current_q)
        opposite = (current_e + 2) % 4
        outer_edge = edge_at(current_q, opposite)
        layer_edges.append(outer_edge)
        next_candidates = [
          item for item in edge_to_quads[tuple(sorted(outer_edge))]
          if item[0] != current_q and item[0] != previous_q
        ]
        if not next_candidates:
          break
        previous_q = current_q
        current_q, current_e = next_candidates[0]
        if len(chain) > 100:
          break
      counts.append(len(chain))
      outer_distances.append(distance(midpoint(layer_edges[0]),
                                      midpoint(layer_edges[-1])))

  if not counts:
    return
  print(
    f"{path.name}: {len(wall_edges)} wall edges, {len(quads)} quads, "
    f"layer counts {Counter(counts)}, outer distance min/avg/max "
    f"{min(outer_distances):.3f}/"
    f"{sum(outer_distances) / len(outer_distances):.3f}/"
    f"{max(outer_distances):.3f}"
  )


def main() -> None:
  FIG_DIR.mkdir(parents=True, exist_ok=True)

  widths = target_layer_widths()
  print("Parameters")
  print(f"  geometry: {GEO}")
  print(f"  surface: {SURFACE}")
  print(f"  curves: {CURVES}")
  print(f"  thickness: {THICKNESS}")
  print(f"  first size: {FIRST_LAYER_SIZE}")
  print(f"  ratio: {RATIO}")
  print(f"  smoothing layers: {SMOOTHING_LAYERS}")
  print(f"  global smoothing layers: {GLOBAL_SMOOTHING_LAYERS}")
  print(f"  mesh size factor: {MESH_SIZE_FACTOR}")
  print(f"  mesh size from curvature: {MESH_SIZE_FROM_CURVATURE}")
  print(f"  mesh size extend from boundary: {MESH_SIZE_EXTEND_FROM_BOUNDARY}")
  print(f"  high-order subedges: {HIGH_ORDER_SUBEDGES}")
  print(f"  layer widths: {widths}")
  print(f"  cumulative width: {sum(widths)}")

  for case in CASES:
    start = perf_counter()
    run_case(case)
    elapsed = perf_counter() - start
    print(f"{case.name}: batch time {elapsed:.3f} s")
    analyze_boundary_layer(case.msh)

  plot_mesh(CASES[0].msh, FIG_DIR / "3cw_no_bl.png", CASES[0].image_title)
  plot_mesh(CASES[1].msh, FIG_DIR / "3cw_bl_single_layer.png",
            CASES[1].image_title)
  plot_mesh(CASES[2].msh, FIG_DIR / "3cw_bl_p2_unsplit.png",
            CASES[2].image_title)
  plot_mesh(CASES[2].msh, FIG_DIR / "3cw_bl_p2_unsplit_leading_edge.png",
            "3CW P2 large elements, leading edge zoom", LEADING_EDGE_ZOOM)
  plot_mesh(CASES[2].msh, FIG_DIR / "3cw_bl_p2_unsplit_trailing_edge.png",
            "3CW P2 large elements, trailing edge zoom", TRAILING_EDGE_ZOOM)
  plot_mesh(CASES[3].msh, FIG_DIR / "3cw_bl.png", CASES[3].image_title)
  plot_mesh(CASES[3].msh, FIG_DIR / "3cw_bl_leading_edge.png",
            "3CW split P2 mesh, leading edge zoom", LEADING_EDGE_ZOOM)
  plot_mesh(CASES[3].msh, FIG_DIR / "3cw_bl_trailing_edge.png",
            "3CW split P2 mesh, trailing edge zoom", TRAILING_EDGE_ZOOM)
  plot_mesh(CASES[4].msh, FIG_DIR / "3cw_bl_global_smoothing.png",
            CASES[4].image_title)
  plot_mesh(CASES[4].msh,
            FIG_DIR / "3cw_bl_global_smoothing_leading_edge.png",
            "3CW global smoothing, leading edge zoom", LEADING_EDGE_ZOOM)
  plot_mesh(CASES[4].msh,
            FIG_DIR / "3cw_bl_global_smoothing_trailing_edge.png",
            "3CW global smoothing, trailing edge zoom", TRAILING_EDGE_ZOOM)


if __name__ == "__main__":
  main()
