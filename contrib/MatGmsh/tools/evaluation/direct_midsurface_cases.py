#!/usr/bin/env python3
"""Analytic STEP corpus for midsurface benchmarks (from the removed direct
BRep prototype; see doc/direct_midsurface_corpus.md).

Only STEP payloads are written beneath tests/. Reference data, hashes and CAD
checks go under build/tests/. No mesher output is used to define the reference.
"""
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import hashlib
import importlib.util
import json
import math
import os
import platform
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_OUTPUT = ROOT / "build/tests/direct_midsurface_20260916"

# OpenCASCADE toolkits linked by the standalone C++ helpers of the kept audits.
OCC_LIBRARIES = ("TKernel", "TKMath", "TKG2d", "TKG3d", "TKGeomBase", "TKBRep",
                 "TKGeomAlgo", "TKTopAlgo", "TKPrim", "TKBO", "TKShHealing",
                 "TKBool", "TKMesh", "TKDESTEP", "TKXSBase", "TKDE")


def _first_prefix(variable, candidates, marker, description):
    explicit = os.environ.get(variable)
    for prefix in map(Path, [explicit] if explicit else candidates):
        if (prefix / marker).is_file():
            return prefix
    where = f"{variable}={explicit}" if explicit else ", ".join(candidates)
    raise RuntimeError(f"{description} not found ({where}); set {variable} to its prefix")


def occ_helper_command(source: Path, binary: Path):
    """Compile command for a standalone OpenCASCADE + nlohmann/json helper.

    No CMake target links OpenCASCADE. MATGMSH_OCC_ROOT is the OCC prefix
    (with include/opencascade and lib), MATGMSH_JSON_INCLUDE_DIR the directory
    containing nlohmann/json.hpp and CXX the compiler (default c++).
    """
    occ = _first_prefix("MATGMSH_OCC_ROOT", ["/opt/homebrew/opt/opencascade",
                        "/usr/local/opt/opencascade", "/usr/local", "/usr"],
                        "include/opencascade/Standard.hxx", "OpenCASCADE")
    json_include = _first_prefix("MATGMSH_JSON_INCLUDE_DIR", ["/opt/homebrew/include",
                                 "/usr/local/include", "/usr/include"],
                                 "nlohmann/json.hpp", "nlohmann/json.hpp")
    return [os.environ.get("CXX", "c++"), "-std=c++17", "-O2",
            "-I" + str(occ / "include/opencascade"), "-I" + str(json_include),
            str(source), "-o", str(binary), "-L" + str(occ / "lib"),
            "-Wl,-rpath," + str(occ / "lib"), *("-l" + name for name in OCC_LIBRARIES)]


def load_gmsh(gmsh_root: Path | None = None):
    """Load the sibling API with its exact build library, never the installed one."""
    root = (gmsh_root or ROOT.parent / "gmsh").resolve()
    api = root / "api/gmsh.py"
    library = root / "build" / ("libgmsh.dylib" if platform.system() == "Darwin" else "libgmsh.so")
    if not api.is_file() or not library.is_file():
        raise RuntimeError(f"Missing sibling Gmsh API or build library: {root}")
    original = ctypes.CDLL
    original_find = ctypes.util.find_library
    ctypes.CDLL = lambda name, *a, **kw: original(str(library) if name is None or "gmsh" in str(name) else name, *a, **kw)
    ctypes.util.find_library = lambda name: str(library) if "gmsh" in name else original_find(name)
    try:
        spec = importlib.util.spec_from_file_location("direct_midsurface_gmsh", api)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
    finally:
        ctypes.CDLL = original
        ctypes.util.find_library = original_find
    module._direct_library_path = str(library)
    return module


def save_json(path: Path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    def scalar(value):
        if hasattr(value, "item"):
            return value.item()
        raise TypeError(f"Not a JSON scalar: {type(value).__name__}")
    path.write_text(json.dumps(data, indent=2, allow_nan=False, default=scalar) + "\n")


def plane(origin, u, v, bounds, thickness=1.0, **extra):
    return dict(kind="plane", origin=origin, u=u, v=v, bounds=bounds,
                thickness=thickness, **extra)


def case_definitions():
    base = plane([0, 0, 0], [1, 0, 0], [0, 1, 0], [-10, 10, -6, 6])
    rib = plane([0, 0, 0], [0, 0, 1], [0, 1, 0], [0, 10, -6, 6])
    cases = {}

    def add(name, kind, patches, **extra):
        cases[name] = dict(name=name, kind=kind, patches=patches, mesh_size=0.7,
                           min_thickness=0.7, max_thickness=1.8,
                           geometry_tolerance=1e-5, junction_extension=2.0,
                           expected_components=1, expected_euler=1,
                           expected_junction_length=0.0, **extra)

    add("DirectMidPlateHole", "plate_hole", [dict(base, hole=[0, 0, 2])])
    cases["DirectMidPlateHole"]["expected_euler"] = 0
    add("DirectMidWedge", "wedge", [dict(base, thickness_affine=[1.2, 0.04, 0],
                                          thickness_normal_scale=1 / math.sqrt(1 + 0.02**2))])
    add("DirectMidCylinder", "cylinder", [dict(kind="cylinder", radius=8.0,
                                               z_bounds=[-6, 6], thickness=1.0)])
    cases["DirectMidCylinder"]["expected_euler"] = 0
    add("DirectMidTSharp", "t_sharp", [base, rib])
    add("DirectMidTVariable", "t_variable", [base, dict(rib, thickness_affine=[0.8, 0.08, 0],
                                                         thickness_normal_scale=1 / math.sqrt(1 + 0.04**2))])
    add("DirectMidTFillet", "t_fillet", [dict(base, exclude_u=[-1.5, 1.5]),
                                         dict(rib, exclude_u=[0, 1.5])], fillet_radius=0.6)
    angle = math.radians(25)
    add("DirectMidTInclined", "t_inclined", [base, dict(rib, u=[math.sin(angle), 0, math.cos(angle)])],
        angle_degrees=25)
    add("DirectMidTHole", "t_hole", [dict(base, hole=[5, 0, 1.5]), rib])
    cases["DirectMidTHole"]["expected_euler"] = 0
    add("DirectMidTSplit", "t_split", [base, rib], equivalent_to="DirectMidTSharp")
    for unequal in (False, True):
        widths = [0.8, 1.2, 1.6] if unequal else [1.0] * 3
        patches = [plane([0, 0, 0], [math.cos(a), 0, math.sin(a)], [0, 1, 0],
                         [0, 10, -6, 6], width)
                   for a, width in zip(map(math.radians, (90, 210, 330)), widths)]
        add("DirectMidYUnequal" if unequal else "DirectMidYEqual", "y", patches, widths=widths)
    add("DirectMidCloseWalls", "close_walls", [dict(base, origin=[0, 0, -0.95]),
                                               dict(base, origin=[0, 0, 0.95])], void_gap=0.9)
    cases["DirectMidCloseWalls"].update(expected_components=2, expected_euler=2)
    add("DirectMidPlateBlock", "plate_block", [dict(base, bounds=[-10, 0, -6, 6])],
        thick_block_bounds=[0, 10, -6, 6, -3, 3], expect_thick_region_rejected=True)
    for case in cases.values():
        if case["kind"].startswith("t_") or case["kind"] == "y":
            case["expected_junction_length"] = 12.0
    # Real CAD fixture: keep the user's STEP byte-for-byte. This case has no
    # analytical midsurface oracle and uses the separate CAD integrity audit.
    cases["Doghouse"] = dict(name="Doghouse", kind="cad_regression",
        existing_source="tests/Doghouse/Doghouse.stp", mesh_size=1.0,
        min_thickness=1.0, max_thickness=4.0, geometry_tolerance=1e-5,
        junction_extension=4.0, expected_components=1,
        reference_kind="none", full_midsurface_reference_available=False,
        description="Industrial Doghouse CAD with curved base, profiled ribs and wall junctions; no full midsurface oracle")
    return cases


def prism(gmsh, polygon_xz, y0=-6, length=12):
    occ = gmsh.model.occ
    pts = [occ.addPoint(x, y0, z) for x, z in polygon_xz]
    lines = [occ.addLine(a, b) for a, b in zip(pts, pts[1:] + pts[:1])]
    surface = occ.addPlaneSurface([occ.addCurveLoop(lines)])
    out = occ.extrude([(2, surface)], 0, length, 0)
    return [tag for dim, tag in out if dim == 3][0]


def radial_blade(gmsh, angle, width):
    dx, dz = math.cos(angle), math.sin(angle)
    nx, nz = -dz, dx
    return prism(gmsh, [(s * dx + q * nx, s * dz + q * nz)
                        for s, q in ((0, -width / 2), (10, -width / 2),
                                     (10, width / 2), (0, width / 2))])


def generate_shape(gmsh, case):
    occ = gmsh.model.occ
    kind = case["kind"]
    if kind == "plate_hole":
        plate = occ.addBox(-10, -6, -0.5, 20, 12, 1)
        hole = occ.addCylinder(0, 0, -1, 0, 0, 2, 2)
        occ.cut([(3, plate)], [(3, hole)])
    elif kind == "wedge":
        prism(gmsh, [(-10, -0.4), (10, -0.8), (10, 0.8), (-10, 0.4)])
    elif kind == "cylinder":
        outer = occ.addCylinder(0, 0, -6, 0, 0, 12, 8.5)
        inner = occ.addCylinder(0, 0, -6, 0, 0, 12, 7.5)
        occ.cut([(3, outer)], [(3, inner)])
    elif kind == "close_walls":
        for z in (-1.45, 0.45):
            occ.addBox(-10, -6, z, 20, 12, 1)
    elif kind == "plate_block":
        plate = occ.addBox(-10, -6, -0.5, 10, 12, 1)
        block = occ.addBox(0, -6, -3, 10, 12, 6)
        occ.fuse([(3, plate)], [(3, block)])
    elif kind == "y":
        volumes = [radial_blade(gmsh, math.radians(a), width)
                   for a, width in zip((90, 210, 330), case["widths"])]
        occ.fuse([(3, volumes[0])], [(3, tag) for tag in volumes[1:]])
    elif kind == "t_split":
        corners = [(-10, -0.5), (10, -0.5), (10, 0.5), (0.5, 0.5),
                   (0.5, 10), (-0.5, 10), (-0.5, 0.5), (-10, 0.5)]
        polygon = []
        for p, q in zip(corners, corners[1:] + corners[:1]):
            polygon.extend([p, ((p[0] + q[0]) / 2, (p[1] + q[1]) / 2)])
        prism(gmsh, polygon)
    elif kind.startswith("t_"):
        base = occ.addBox(-10, -6, -0.5, 20, 12, 1)
        if kind == "t_variable":
            rib = prism(gmsh, [(-0.4, 0), (0.4, 0), (0.8, 10), (-0.8, 10)])
        elif kind == "t_inclined":
            rib = radial_blade(gmsh, math.radians(90 - case["angle_degrees"]), 1)
        else:
            rib = occ.addBox(-0.5, -6, 0, 1, 12, 10)
        volumes, _ = occ.fuse([(3, base)], [(3, rib)])
        if kind == "t_hole":
            hole = occ.addCylinder(5, 0, -1, 0, 0, 2, 1.5)
            occ.cut(volumes, [(3, hole)])
        if kind == "t_fillet":
            occ.synchronize()
            edges = []
            for _, tag in gmsh.model.getEntities(1):
                x, y, z = occ.getCenterOfMass(1, tag)
                if abs(abs(x) - 0.5) < 1e-8 and abs(y) < 1e-8 and abs(z - 0.5) < 1e-8:
                    edges.append(tag)
            if len(edges) != 2:
                raise RuntimeError(f"Expected two concave root edges, got {edges}")
            occ.fillet([tag for dim, tag in volumes if dim == 3], edges, [case["fillet_radius"]])
    else:
        raise ValueError(kind)
    occ.synchronize()


def generate(output: Path, names=None, gmsh_root=None, overwrite=False):
    gmsh = load_gmsh(gmsh_root)
    definitions = case_definitions()
    selected = names or [name for name, case in definitions.items()
                         if not case.get("existing_source") or
                         (ROOT / case["existing_source"]).is_file()]
    unknown = set(selected) - definitions.keys()
    if unknown:
        raise ValueError(f"Unknown cases: {sorted(unknown)}")
    output.mkdir(parents=True, exist_ok=True)
    manifest = dict(schema_version=1, generator=str(Path(__file__).resolve()),
                    gmsh_library=gmsh._direct_library_path, cases={})
    gmsh.initialize()
    gmsh.option.setNumber("General.Terminal", 0)
    try:
        for name in selected:
            case = dict(definitions[name])
            existing = case.get("existing_source")
            destination = ROOT / existing if existing else ROOT / "tests" / name / f"{name}.stp"
            if existing and not destination.is_file():
                raise FileNotFoundError(f"Existing CAD fixture is unavailable: {destination}")
            if not existing and destination.exists() and not overwrite:
                raise FileExistsError(f"Refusing to overwrite {destination}; use --overwrite explicitly")
            destination.parent.mkdir(parents=True, exist_ok=True)
            gmsh.clear()
            gmsh.model.add(name)
            if existing:
                gmsh.model.occ.importShapes(str(destination))
                gmsh.model.occ.synchronize()
            else:
                generate_shape(gmsh, case)
            volumes = gmsh.model.getEntities(3)
            expected_volumes = 2 if case["kind"] == "close_walls" else 1
            if len(volumes) != expected_volumes:
                raise RuntimeError(f"{name}: {len(volumes)} CAD volumes, expected {expected_volumes}")
            case.update(source=str(destination), cad_volume=sum(gmsh.model.occ.getMass(3, tag) for _, tag in volumes),
                        cad_volumes=len(volumes), cad_faces=len(gmsh.model.getEntities(2)),
                        cad_bbox=list(gmsh.model.getBoundingBox(-1, -1)))
            if not existing:
                gmsh.write(str(destination))
            case["sha256"] = hashlib.sha256(destination.read_bytes()).hexdigest()
            manifest["cases"][name] = case
            action = "REGISTERED" if existing else "GENERATED"
            print(f"{action} {name}: {case['cad_volumes']} volume(s), {case['cad_faces']} faces", flush=True)
    finally:
        gmsh.finalize()
    save_json(output / "cases.json", manifest)
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("cases", nargs="*")
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    parser.add_argument("--gmsh-root", type=Path)
    parser.add_argument("--overwrite", action="store_true")
    args = parser.parse_args()
    generate(args.output.resolve(), args.cases, args.gmsh_root, args.overwrite)


if __name__ == "__main__":
    main()
