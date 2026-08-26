#!/usr/bin/env python3
"""Quick-look plots for SU2 VTU output without requiring VTK/PyVista."""

from __future__ import annotations

import re
import struct
import os
from pathlib import Path
from typing import Dict, Tuple

os.environ.setdefault("MPLCONFIGDIR", "/tmp/matplotlib-gmsh")

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.collections import LineCollection, PolyCollection

HERE = Path(__file__).resolve().parent


def parse_header(text: str):
  piece = re.search(r'<Piece NumberOfPoints="(\d+)" NumberOfCells="(\d+)">', text)
  if not piece:
    raise RuntimeError("Could not find VTU Piece header")
  npoints = int(piece.group(1))
  ncells = int(piece.group(2))
  arrays = []
  for m in re.finditer(
    r'<DataArray type="([^"]+)" Name="([^"]*)" NumberOfComponents= "([^"]+)" offset="([^"]+)" format="appended"/>',
    text,
  ):
    arrays.append((m.group(2), m.group(1), int(m.group(3)), int(m.group(4))))
  return npoints, ncells, arrays


def vtk_dtype(vtk_type: str):
  if vtk_type == "Float32":
    return np.float32
  if vtk_type == "Int32":
    return np.int32
  if vtk_type == "UInt8":
    return np.uint8
  raise RuntimeError(f"Unsupported VTU type {vtk_type}")


def read_raw_array(raw: bytes, offset: int, vtk_type: str, ncomp: int):
  start = offset
  nbytes = struct.unpack_from("<Q", raw, start)[0]
  start += 8
  dtype = vtk_dtype(vtk_type)
  arr = np.frombuffer(raw[start : start + nbytes], dtype=dtype).copy()
  if ncomp > 1:
    arr = arr.reshape((-1, ncomp))
  return arr


def read_vtu(path: Path):
  data = path.read_bytes()
  marker = b"<AppendedData encoding=\"raw\">\n_"
  idx = data.index(marker)
  xml = data[:idx].decode("utf-8")
  raw = data[idx + len(marker) :]
  npoints, ncells, arrays = parse_header(xml)
  out: Dict[str, np.ndarray] = {}
  for name, vtk_type, ncomp, offset in arrays:
    key = name if name else "Points"
    out[key] = read_raw_array(raw, offset, vtk_type, ncomp)
  return npoints, ncells, out


def cells_from_arrays(arrays):
  conn = arrays["connectivity"]
  offsets = arrays["offsets"]
  types = arrays["types"]
  cells = []
  start = 0
  for end, typ in zip(offsets, types):
    nodes = conn[start:end].astype(int)
    start = end
    cells.append((int(typ), nodes))
  return cells


def plot_flow(field: str, out: Path, cmap: str = "viridis") -> None:
  _, _, arrays = read_vtu(HERE / "flow.vtu")
  pts = arrays["Points"][:, :2]
  vals = arrays[field]
  cells = cells_from_arrays(arrays)
  polys = []
  cell_vals = []
  for typ, nodes in cells:
    if typ not in (5, 9):  # triangle, quad
      continue
    polys.append(pts[nodes])
    cell_vals.append(float(np.mean(vals[nodes])))
  fig, ax = plt.subplots(figsize=(10, 5), dpi=180)
  pc = PolyCollection(polys, array=np.array(cell_vals), cmap=cmap, linewidth=0.05)
  pc.set_edgecolor((0, 0, 0, 0.12))
  ax.add_collection(pc)
  ax.autoscale()
  ax.set_aspect("equal")
  ax.set_axis_off()
  cb = fig.colorbar(pc, ax=ax, shrink=0.75)
  cb.set_label(field)
  fig.tight_layout(pad=0)
  fig.savefig(out, bbox_inches="tight", pad_inches=0.02)
  plt.close(fig)


def plot_surface(field: str, out: Path, cmap: str = "plasma") -> None:
  _, _, arrays = read_vtu(HERE / "surface_flow.vtu")
  pts = arrays["Points"][:, :2]
  vals = arrays[field]
  cells = cells_from_arrays(arrays)
  segments = []
  seg_vals = []
  for typ, nodes in cells:
    if typ != 3:  # line
      continue
    segments.append(pts[nodes])
    seg_vals.append(float(np.mean(vals[nodes])))
  fig, ax = plt.subplots(figsize=(10, 4), dpi=180)
  lc = LineCollection(segments, array=np.array(seg_vals), cmap=cmap, linewidth=2.0)
  ax.add_collection(lc)
  ax.autoscale()
  ax.set_aspect("equal")
  ax.set_axis_off()
  cb = fig.colorbar(lc, ax=ax, shrink=0.75)
  cb.set_label(field)
  fig.tight_layout(pad=0)
  fig.savefig(out, bbox_inches="tight", pad_inches=0.02)
  plt.close(fig)


def print_ranges() -> None:
  for name in ["flow.vtu", "surface_flow.vtu"]:
    _, _, arrays = read_vtu(HERE / name)
    print(name)
    for field in ["Mach", "Pressure_Coefficient", "Y_Plus", "Eddy_Viscosity"]:
      vals = arrays[field]
      print(
        f"  {field}: min {float(np.min(vals)):.6g}, "
        f"avg {float(np.mean(vals)):.6g}, max {float(np.max(vals)):.6g}"
      )


if __name__ == "__main__":
  print_ranges()
  plot_flow("Mach", HERE / "flow_mach.png")
  plot_flow("Pressure_Coefficient", HERE / "flow_cp.png", "coolwarm")
  plot_surface("Pressure_Coefficient", HERE / "surface_cp.png", "coolwarm")
  plot_surface("Y_Plus", HERE / "surface_yplus.png", "viridis")
  print("wrote flow_mach.png, flow_cp.png, surface_cp.png, surface_yplus.png")
