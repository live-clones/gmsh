#!/usr/bin/env python3
"""Synthetic thin parts whose mid-surface is known by construction.

Each case starts from its mid-surface: one or more sheets built with Gmsh's
OpenCASCADE kernel. Every sheet is thickened symmetrically into a solid
(thicken_sheet.cpp), the solids are fused and fillets are added on the new
junction edges and, optionally, on the free edges. The sheets are therefore the
exact (engineering) mid-surface of the part, away from its fillets.

Per case, in <output>/<case>/:
  <case>.stp              the solid, input of MatGmsh
  <case>_midsurface.brep  the sheets, fragmented so junctions are conformal
  <case>.json             family, level, parameters, thickness per sheet and
                          the role of every CAD face of the solid: skin (one of
                          the two walls of a sheet), edge (end face or hole
                          wall, normal to the sheet) or fillet (anything else)
and <output>/manifest.json lists the cases that were built.

Levels grow in difficulty: 1 single sheet, 2 junctions, 3 combinations and
quirks, 4 thickness varying from 2 to 6, 5 small parts mixing many features.
All cases use thickness 4 unless their parameters say otherwise.
"""

from __future__ import annotations

import argparse
import fnmatch
import json
import math
import os
import random
import shutil
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass
from pathlib import Path
from typing import Callable

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from direct_midsurface_cases import load_gmsh  # noqa: E402

gmsh = None
T = 4.0
# Write the solids with every face and edge converted to B-splines.
BSPLINE = False
# Seconds allowed to build one case in its child process.
WORKER_TIMEOUT = 900


# ---------------------------------------------------------------------------
# Sheet builders: each one adds surfaces to the current Gmsh OCC model.


def plate(a, b, x=0.0, y=0.0, z=0.0, holes=()):
    """Rectangle [x, x+a] x [y, y+b] at height z, minus circular holes."""
    def build(occ):
        s = occ.addRectangle(x, y, z, a, b)
        tools = [(2, occ.addDisk(hx, hy, z, r, r)) for hx, hy, r in holes]
        if tools:
            out, _ = occ.cut([(2, s)], tools)
            return out
        return [(2, s)]
    return build


def rounded_profile(points, radius):
    """Planar polyline (u, v) with every interior corner rounded to `radius`.

    Returns the segments as ('line', p, q) and ('arc', p, center, q)."""
    segments = []
    start = points[0]
    for i in range(1, len(points) - 1):
        p0, p1, p2 = points[i - 1], points[i], points[i + 1]
        d1 = unit(sub(p1, p0))
        d2 = unit(sub(p2, p1))
        cross = d1[0] * d2[1] - d1[1] * d2[0]
        turn = math.atan2(abs(cross), d1[0] * d2[0] + d1[1] * d2[1])
        if radius <= 0.0 or turn < 1e-9:
            segments.append(("line", start, p1))
            start = p1
            continue
        tangent = radius * math.tan(0.5 * turn)
        t1 = (p1[0] - tangent * d1[0], p1[1] - tangent * d1[1])
        t2 = (p1[0] + tangent * d2[0], p1[1] + tangent * d2[1])
        normal = (-d1[1], d1[0]) if cross > 0 else (d1[1], -d1[0])
        center = (t1[0] + radius * normal[0], t1[1] + radius * normal[1])
        segments.append(("line", start, t1))
        segments.append(("arc", t1, center, t2))
        start = t2
    segments.append(("line", start, points[-1]))
    return segments


def profile_sheet(points, radius, width, holes=()):
    """Profile in the (x, z) plane, extruded along y over `width`.

    `holes` are (segment index, s, y, r): a hole of radius r centered at
    fraction s along the straight segment of that index, at depth y."""
    def build(occ):
        curves = []
        for seg in rounded_profile(points, radius):
            if seg[0] == "line":
                p, q = seg[1], seg[2]
                if math.dist(p, q) < 1e-9:
                    continue
                curves.append(occ.addLine(occ.addPoint(p[0], 0, p[1]),
                                          occ.addPoint(q[0], 0, q[1])))
            else:
                p, c, q = seg[1], seg[2], seg[3]
                curves.append(occ.addCircleArc(occ.addPoint(p[0], 0, p[1]),
                                               occ.addPoint(c[0], 0, c[1]),
                                               occ.addPoint(q[0], 0, q[1])))
        out = occ.extrude([(1, c) for c in curves], 0, width, 0)
        surfaces = [dt for dt in out if dt[0] == 2]
        tools = []
        lines = [s for s in rounded_profile(points, radius) if s[0] == "line"]
        for index, s, y, r in holes:
            p, q = lines[index][1], lines[index][2]
            d = unit(sub(q, p))
            cx, cz = p[0] + s * (q[0] - p[0]), p[1] + s * (q[1] - p[1])
            disk = occ.addDisk(0, 0, 0, r, r)
            # The disk normal z is the sheet normal of a segment along x: turn
            # x onto the segment direction (rotation about y by -angle).
            occ.rotate([(2, disk)], 0, 0, 0, 0, 1, 0, -math.atan2(d[1], d[0]))
            occ.translate([(2, disk)], cx, y, cz)
            tools.append((2, disk))
        if tools:
            out, _ = occ.cut(surfaces, tools)
            return out
        return surfaces
    return build


def cylinder_panel(radius, angle, length):
    def build(occ):
        c = occ.addCircle(0, 0, 0, radius, angle1=0.0, angle2=angle)
        out = occ.extrude([(1, c)], 0, 0, length)
        return [dt for dt in out if dt[0] == 2]
    return build


def cone_panel(r1, r2, angle, length):
    def build(occ):
        v = occ.addCone(0, 0, 0, 0, 0, length, r1, r2, angle=angle)
        return keep_faces_of_type(occ, v, "Cone")
    return build


def sphere_cap(radius, polar_angle):
    """Spherical cap of half-angle `polar_angle` around +z."""
    def build(occ):
        v = occ.addSphere(0, 0, 0, radius, angle1=0.5 * math.pi - polar_angle)
        return keep_faces_of_type(occ, v, "Sphere")
    return build


def tray(a, b, h, bend_radius, corner_radius):
    """Open box (mid-surface) with rounded bottom edges and vertical corners."""
    def build(occ):
        v = occ.addBox(0, 0, 0, a, b, h)
        occ.synchronize()
        vertical = [c for _, c in occ.getEntities(1) if is_vertical(occ, c)]
        out = occ.fillet([v], vertical, [corner_radius])
        v = out[0][1]
        occ.synchronize()
        bottom = [c for _, c in occ.getEntities(1)
                  if abs(occ.getBoundingBox(1, c)[5]) < 1e-6]
        out = occ.fillet([v], bottom, [bend_radius])
        v = out[0][1]
        faces = occ.getEntities(2)
        top = [f for f in faces if abs(occ.getBoundingBox(*f)[2] - h) < 1e-6]
        occ.remove([(3, v)])
        occ.remove(top)
        return [f for f in faces if f not in top]
    return build


def polygon(points, holes=()):
    """Planar polygon through 3D `points`, minus disks (center, normal, r)."""
    def build(occ):
        tags = [occ.addPoint(*q) for q in points]
        lines = [occ.addLine(tags[i], tags[(i + 1) % len(tags)])
                 for i in range(len(tags))]
        s = occ.addPlaneSurface([occ.addCurveLoop(lines)])
        tools = [(2, oriented_disk(occ, c, n, r)) for c, n, r in holes]
        if tools:
            out, _ = occ.cut([(2, s)], tools)
            return out
        return [(2, s)]
    return build


def bend_gusset(y, radius, reach, segments=24):
    """Gusset in the plane y across the bend of an L section (legs along x
    and z, bend of mid radius `radius` centered at (radius, radius)): it
    meets the bend along the bend's mid-surface (an arc, polygonized), not
    along the chord between its ends, which lies inside the bend's material
    and leaves a gap with the mid-surface of the bend."""
    arc = [(radius + radius * math.cos(a), y, radius + radius * math.sin(a))
           for a in (math.radians(270 - 90 * k / segments) for k in range(1, segments))]
    return polygon([(0, y, radius), (0, y, reach), (reach, y, 0), (radius, y, 0)] + arc)


def gusset_outline(height, base, offset=0.0, snipe=8.0):
    """Outline (u, 0, z) of a gusset in its plane, u along the base from the
    wall it stands against (at u = offset), z up: legs `height` along the
    wall and `base` along the plate, its corner sniped (a cope for the weld)
    by `snipe` on both legs, less on a small gusset so that it stays 1.5 t
    wide: a narrower strip is a bar, with no mid-surface."""
    snipe = min(snipe, max(0.0, min(height, base) - 1.5 * T * math.sqrt(2.0)))
    if snipe < 1e-9:
        return [(offset, 0, 0), (offset, 0, height), (offset + base, 0, 0)]
    return [(offset, 0, snipe), (offset, 0, height), (offset + base, 0, 0), (offset + snipe, 0, 0)]


def oriented_disk(occ, center, normal, r):
    disk = occ.addDisk(0, 0, 0, r, r, zAxis=list(normal))
    occ.translate([(2, disk)], *center)
    return disk


def profile_face(points, radius, y, trim_ends=False):
    """Planar face in the plane y bounded by a rounded (x, z) profile and the
    segment closing it. With trim_ends, the first and last straight segments
    (the flanges of a hat) are left out: the face closes the hat only."""
    def build(occ):
        curves = []
        first = last = None
        segments = rounded_profile(points, radius)
        if trim_ends:
            segments = segments[1:-1]
        for seg in segments:
            if seg[0] == "line" and math.dist(seg[1], seg[2]) < 1e-9:
                continue
            p = occ.addPoint(seg[1][0], y, seg[1][1]) if last is None else last
            first = p if first is None else first
            q_xy = seg[2] if seg[0] == "line" else seg[3]
            last = occ.addPoint(q_xy[0], y, q_xy[1])
            if seg[0] == "line":
                curves.append(occ.addLine(p, last))
            else:
                c = occ.addPoint(seg[2][0], y, seg[2][1])
                curves.append(occ.addCircleArc(p, c, last))
        curves.append(occ.addLine(last, first))
        return [(2, occ.addPlaneSurface([occ.addCurveLoop(curves)]))]
    return build


def revolved_profile(points, radius):
    """Rounded (r, z) profile revolved about the z axis: dimples, collars."""
    def build(occ):
        curves = []
        for seg in rounded_profile(points, radius):
            if seg[0] == "line":
                if math.dist(seg[1], seg[2]) < 1e-9:
                    continue
                curves.append(occ.addLine(occ.addPoint(seg[1][0], 0, seg[1][1]),
                                          occ.addPoint(seg[2][0], 0, seg[2][1])))
            else:
                curves.append(occ.addCircleArc(occ.addPoint(seg[1][0], 0, seg[1][1]),
                                               occ.addPoint(seg[2][0], 0, seg[2][1]),
                                               occ.addPoint(seg[3][0], 0, seg[3][1])))
        out = occ.revolve([(1, c) for c in curves], 0, 0, 0, 0, 0, 1, 2 * math.pi)
        return [dt for dt in out if dt[0] == 2]
    return build


def combine(*builders, translate=(0.0, 0.0, 0.0)):
    """Several builders in one sheet (one shell once sewn)."""
    def build(occ):
        out = []
        for b in builders:
            out += b(occ)
        if any(translate):
            occ.translate(out, *translate)
        return out
    return build


def slotted_plate(a, b, slots=(), holes=()):
    """Plate minus obround slots (x0, y0, x1, y1, r) and holes (x, y, r)."""
    def build(occ):
        s = occ.addRectangle(0, 0, 0, a, b)
        tools = [(2, occ.addDisk(x, y, 0, r, r)) for x, y, r in holes]
        for x0, y0, x1, y1, r in slots:
            length = math.dist((x0, y0), (x1, y1))
            angle = math.atan2(y1 - y0, x1 - x0)
            body = occ.addRectangle(0, -r, 0, length, 2 * r)
            ends = [(2, occ.addDisk(0, 0, 0, r, r)), (2, occ.addDisk(length, 0, 0, r, r))]
            fused, _ = occ.fuse([(2, body)], ends)
            occ.rotate(fused, 0, 0, 0, 0, 0, 1, angle)
            occ.translate(fused, x0, y0, 0)
            tools += fused
        if tools:
            out, _ = occ.cut([(2, s)], tools)
            return out
        return [(2, s)]
    return build


def split_plate(widths, b):
    """Plate made of adjacent rectangles of the given widths: one sheet split
    into several CAD faces, as CAD exports often are."""
    def build(occ):
        out, x = [], 0.0
        for w in widths:
            out.append((2, occ.addRectangle(x, 0, 0, w, b)))
            x += w
        frag, _ = occ.fragment(out[:1], out[1:])
        return [dt for dt in frag if dt[0] == 2]
    return build


def plate_with_revolved(a, b, center, cut_radius, points, radius):
    """Plate minus a disk, completed by a revolved feature (dimple, collar)."""
    def build(occ):
        s = occ.addRectangle(0, 0, 0, a, b)
        out, _ = occ.cut([(2, s)], [(2, occ.addDisk(center[0], center[1], 0,
                                                    cut_radius, cut_radius))])
        feature = revolved_profile(points, radius)(occ)
        occ.translate(feature, center[0], center[1], 0)
        return out + feature
    return build


def annular_sector(r_in, r_out, angle, z):
    def build(occ):
        outer = occ.addCircle(0, 0, z, r_out, angle1=0.0, angle2=angle)
        inner = occ.addCircle(0, 0, z, r_in, angle1=0.0, angle2=angle)
        a0 = occ.addLine(occ.addPoint(r_in, 0, z), occ.addPoint(r_out, 0, z))
        c, s_ = math.cos(angle), math.sin(angle)
        a1 = occ.addLine(occ.addPoint(r_out * c, r_out * s_, z),
                         occ.addPoint(r_in * c, r_in * s_, z))
        loop = occ.addCurveLoop([a0, outer, a1, inner])
        return [(2, occ.addPlaneSurface([loop]))]
    return build


def tube(a, b, corner_radius, length, holes=()):
    """Closed rectangular tube with rounded corners, axis z, from z=0."""
    def build(occ):
        r = occ.addRectangle(-a / 2, -b / 2, 0, a, b, roundedRadius=corner_radius)
        occ.synchronize()
        curves = [(1, abs(c)) for _, c in gmsh.model.getBoundary([(2, r)], oriented=False)]
        out = occ.extrude(curves, 0, 0, length)
        occ.remove([(2, r)])
        surfaces = [dt for dt in out if dt[0] == 2]
        tools = [(2, oriented_disk(occ, c, n, rr)) for c, n, rr in holes]
        if tools:
            surfaces, _ = occ.cut(surfaces, tools)
        return surfaces
    return build


def pipe(radius, length, center=(0.0, 0.0), z0=0.0, thickness=T, extend=0.0):
    """Full cylinder sheet around a vertical axis, and its exact solid; the
    solid can extend `extend` below z0 (edge-to-edge joints)."""
    def sheet(occ):
        return translated(cylinder_panel(radius, 2 * math.pi, length), *center, z0)(occ)

    def volume(occ):
        h = length + extend
        outer = occ.addCylinder(*center, z0 - extend, 0, 0, h, radius + thickness / 2)
        inner = occ.addCylinder(*center, z0 - extend, 0, 0, h, radius - thickness / 2)
        out, _ = occ.cut([(3, outer)], [(3, inner)])
        return out
    return Sheet(sheet, thickness, volume=volume)


def elbow(bend_radius, tube_radius, angle):
    """Pipe elbow: a torus portion around z."""
    def build(occ):
        v = occ.addTorus(0, 0, 0, bend_radius, tube_radius, angle=angle)
        return keep_faces_of_type(occ, v, "Torus")
    return build


def saddle(a, b, k):
    """Doubly curved B-spline sheet z ~ k ((x-a/2)^2 - (y-b/2)^2)."""
    def build(occ):
        tags = []
        n = 4
        for j in range(n):
            for i in range(n):
                x, y = a * i / (n - 1), b * j / (n - 1)
                tags.append(occ.addPoint(x, y, k * ((x - a / 2) ** 2 - (y - b / 2) ** 2)))
        return [(2, occ.addBSplineSurface(tags, n))]
    return build


def annulus(r_in, r_out, z=0.0, holes=()):
    """Flat ring around z at height z, minus holes (x, y, r)."""
    def build(occ):
        outer = occ.addDisk(0, 0, z, r_out, r_out)
        tools = [(2, occ.addDisk(0, 0, z, r_in, r_in))]
        tools += [(2, occ.addDisk(x, y, z, r, r)) for x, y, r in holes]
        out, _ = occ.cut([(2, outer)], tools)
        return out
    return build


def framed_plate(a, b, margin, z, corner_radius):
    """Flange around a rounded rectangular opening [0, a] x [0, b] at height z."""
    def build(occ):
        frame = occ.addRectangle(-margin, -margin, z, a + 2 * margin, b + 2 * margin)
        hole = occ.addRectangle(0, 0, z, a, b, roundedRadius=corner_radius)
        out, _ = occ.cut([(2, frame)], [(2, hole)])
        return out
    return build


def translated(builder, dx, dy, dz):
    def build(occ):
        out = builder(occ)
        occ.translate(out, dx, dy, dz)
        return out
    return build


def rotated(builder, axis, angle, origin=(0.0, 0.0, 0.0)):
    def build(occ):
        out = builder(occ)
        occ.rotate(out, *origin, *axis, angle)
        return out
    return build


def is_vertical(occ, curve):
    x0, y0, z0, x1, y1, z1 = occ.getBoundingBox(1, curve)
    return abs(x1 - x0) < 1e-6 and abs(y1 - y0) < 1e-6


def keep_faces_of_type(occ, volume, kind):
    occ.synchronize()
    faces = gmsh.model.getBoundary([(3, volume)], oriented=False)
    keep = [f for f in faces if gmsh.model.getType(*f) == kind]
    occ.remove([(3, volume)])
    occ.remove([f for f in faces if f not in keep])
    return keep


def sub(p, q):
    return (p[0] - q[0], p[1] - q[1])


def unit(v):
    n = math.hypot(v[0], v[1])
    return (v[0] / n, v[1] / n)


# ---------------------------------------------------------------------------
# Cases.


@dataclass
class Sheet:
    build: Callable
    thickness: float = T
    # The sheet actually thickened, when it differs from the mid-surface: an
    # edge-to-edge corner extends each sheet by t/2 so the solid has no notch.
    solid: Callable | None = None
    # The solid itself, built directly: offsets of closed periodic sheets
    # (full cylinders) give solids that OpenCASCADE booleans drop.
    volume: Callable | None = None


@dataclass
class Case:
    name: str
    level: int
    family: str
    params: dict
    sheets: list
    junction_fillet: float = 0.0   # radius on the edges created by the fusion
    free_edge_fillet: float = 0.0  # radius on the edges of the end faces
    # Unify the faces lying on the same surface after the fusion (Gmsh's
    # Geometry.OCCUnionUnify). On bowed lofted parts it merges side faces into
    # degenerate planes, so those cases keep the faces as fused.
    unify: bool = True


def level1_cases():
    cases = []
    for a, b in [(60, 40), (120, 30), (200, 200)]:
        cases.append(Case(f"plate_{a}x{b}", 1, "plate", dict(a=a, b=b),
                          [Sheet(plate(a, b))]))
    for r in [4, 10]:
        cases.append(Case(f"plate_hole_r{r}", 1, "plate_hole", dict(a=80, b=60, r=r),
                          [Sheet(plate(80, 60, holes=[(40, 30, r)]))]))
    cases.append(Case("plate_holes_3", 1, "plate_hole",
                      dict(a=120, b=60, holes=[(25, 30, 6), (60, 30, 10), (95, 30, 4)]),
                      [Sheet(plate(120, 60, holes=[(25, 30, 6), (60, 30, 10), (95, 30, 4)]))]))
    for w in [8, 12, 20]:
        cases.append(Case(f"strip_w{w}", 1, "strip", dict(a=100, b=w),
                          [Sheet(plate(100, w))]))
    for angle in [45, 90, 135]:
        for rm in [4, 10]:
            th = math.radians(angle)
            pts = [(0, 0), (50, 0), (50 + 40 * math.cos(th), 40 * math.sin(th))]
            cases.append(Case(f"bend_{angle}deg_r{rm}", 1, "bend",
                              dict(angle=angle, mid_radius=rm, width=40),
                              [Sheet(profile_sheet(pts, rm, 40))]))
    profiles = {
        "u_channel": [(0, 40), (0, 0), (50, 0), (50, 40)],
        "z_section": [(0, 0), (30, 0), (30, 40), (60, 40)],
        "hat": [(0, 0), (20, 0), (20, 30), (60, 30), (60, 0), (80, 0)],
        "omega": [(0, 0), (20, 0), (30, 30), (60, 30), (70, 0), (90, 0)],
    }
    for family, pts in profiles.items():
        cases.append(Case(f"{family}_r6", 1, family, dict(points=pts, mid_radius=6, width=50),
                          [Sheet(profile_sheet(pts, 6, 50))]))
    for radius, angle in [(30, 90), (60, 120), (100, 60)]:
        cases.append(Case(f"cylinder_panel_R{radius}_{angle}deg", 1, "cylinder_panel",
                          dict(radius=radius, angle=angle, length=60),
                          [Sheet(cylinder_panel(radius, math.radians(angle), 60))]))
    cases.append(Case("cone_panel", 1, "cone_panel", dict(r1=40, r2=20, angle=120, length=50),
                      [Sheet(cone_panel(40, 20, math.radians(120), 50))]))
    for radius, polar in [(50, 40), (80, 25)]:
        cases.append(Case(f"sphere_cap_R{radius}_{polar}deg", 1, "sphere_cap",
                          dict(radius=radius, polar_angle=polar),
                          [Sheet(sphere_cap(radius, math.radians(polar)))]))
    for rb, rc in [(6, 10), (10, 20)]:
        cases.append(Case(f"tray_rb{rb}_rc{rc}", 1, "tray",
                          dict(a=100, b=70, h=30, bend_radius=rb, corner_radius=rc),
                          [Sheet(tray(100, 70, 30, rb, rc))]))
    return cases


def level2_cases():
    cases = []
    L, W = 80, 60
    flange = Sheet(plate(L, W, x=-L / 2))
    for h in [20, 40]:
        for r in [0, 2, 5]:
            rib = Sheet(polygon([(0, 0, 0), (0, W, 0), (0, W, h), (0, 0, h)]))
            cases.append(Case(f"t_junction_h{h}_r{r}", 2, "t_junction",
                              dict(flange=(L, W), rib_height=h, fillet=r),
                              [flange, rib], junction_fillet=r))
    for angle in [60, 45]:
        a = math.radians(angle)
        top = (30 * math.cos(a), 30 * math.sin(a))
        rib = Sheet(polygon([(0, 0, 0), (0, W, 0), (top[0], W, top[1]), (top[0], 0, top[1])]))
        cases.append(Case(f"inclined_rib_{angle}deg_r2", 2, "t_junction",
                          dict(flange=(L, W), rib_length=30, angle=angle, fillet=2),
                          [flange, rib], junction_fillet=2))
    for r in [0, 3]:
        rib = Sheet(polygon([(0, 0, -25), (0, W, -25), (0, W, 25), (0, 0, 25)]))
        cases.append(Case(f"x_junction_r{r}", 2, "x_junction",
                          dict(flange=(L, W), rib_height=50, fillet=r),
                          [flange, rib], junction_fillet=r))
    # Edge-to-edge corner: each solid extends t/2 past the shared edge.
    for r in [0, 3]:
        base = Sheet(plate(L, W), solid=plate(L + T / 2, W, x=-T / 2))
        wall = Sheet(polygon([(0, 0, 0), (0, W, 0), (0, W, 40), (0, 0, 40)]),
                     solid=polygon([(0, 0, -T / 2), (0, W, -T / 2), (0, W, 40), (0, 0, 40)]))
        cases.append(Case(f"corner_joint_r{r}", 2, "corner_joint",
                          dict(base=(L, W), wall_height=40, fillet=r),
                          [base, wall], junction_fillet=r))
    for n in [2, 3]:
        ribs = [Sheet(polygon([(x, 0, 0), (x, 100, 0), (x, 100, 25), (x, 0, 25)]))
                for x in [120 * (i + 1) / (n + 1) for i in range(n)]]
        cases.append(Case(f"ribbed_plate_{n}_r2", 2, "ribbed_plate",
                          dict(plate=(120, 100), ribs=n, rib_height=25, fillet=2),
                          [Sheet(plate(120, 100))] + ribs, junction_fillet=2))
    # Waffle: crossing ribs, vertical X junctions meeting the T junctions.
    ribs = [Sheet(polygon([(x, 0, 0), (x, 100, 0), (x, 100, 20), (x, 0, 20)])) for x in (40, 80)]
    ribs += [Sheet(polygon([(0, y, 0), (120, y, 0), (120, y, 20), (0, y, 20)])) for y in (50,)]
    cases.append(Case("waffle_3_r2", 2, "waffle", dict(plate=(120, 100), rib_height=20, fillet=2),
                      [Sheet(plate(120, 100))] + ribs, junction_fillet=2))
    u = [(0, 40), (0, 0), (50, 0), (50, 40)]
    for r in [0, 2]:
        cases.append(Case(f"channel_gusset_r{r}", 2, "channel_gusset",
                          dict(points=u, mid_radius=6, width=80, gusset_y=40, fillet=r),
                          [Sheet(profile_sheet(u, 6, 80)), Sheet(profile_face(u, 6, 40))],
                          junction_fillet=r))
    lb = [(0, 50), (0, 0), (50, 0)]
    gusset = Sheet(bend_gusset(30, 6, 35))
    cases.append(Case("bend_gusset_r2", 2, "bend_gusset",
                      dict(points=lb, mid_radius=6, width=60, fillet=2),
                      [Sheet(profile_sheet(lb, 6, 60)), gusset], junction_fillet=2))
    # The rib follows the tray section: its outline is the rounded U profile.
    section = [(0, 30), (0, 0), (70, 0), (70, 30)]
    for r in [0, 2]:
        rib = Sheet(rotated(profile_face(section, 6, -50), (0, 0, 1), 0.5 * math.pi))
        cases.append(Case(f"tray_rib_r{r}", 2, "tray_rib",
                          dict(a=100, b=70, h=30, bend_radius=6, corner_radius=10,
                               rib_x=50, fillet=r),
                          [Sheet(tray(100, 70, 30, 6, 10)), rib], junction_fillet=r))
    return cases


def level3_cases():
    cases = []
    # Rounded free edges: the end faces disappear into fillets.
    for r in [1.0, 1.5]:
        cases.append(Case(f"plate_round_edges_r{r}", 3, "round_edges",
                          dict(a=60, b=40, edge_fillet=r),
                          [Sheet(plate(60, 40))], free_edge_fillet=r))
        cases.append(Case(f"bend_round_edges_r{r}", 3, "round_edges",
                          dict(angle=90, mid_radius=6, width=40, edge_fillet=r),
                          [Sheet(profile_sheet([(0, 0), (50, 0), (50, 40)], 6, 40))],
                          free_edge_fillet=r))
    # Ligaments: holes close to each other and to the free edge.
    for gap in [2, 4, 8]:
        holes = [(30, 30, 8), (30 + 16 + gap, 30, 8)]
        cases.append(Case(f"ligament_holes_gap{gap}", 3, "ligament",
                          dict(a=100, b=60, holes=holes, gap=gap),
                          [Sheet(plate(100, 60, holes=holes))]))
        cases.append(Case(f"ligament_edge_gap{gap}", 3, "ligament",
                          dict(a=80, b=60, hole=(40, 8 + gap, 8), gap=gap),
                          [Sheet(plate(80, 60, holes=[(40, 8 + gap, 8)]))]))
    cases.append(Case("slotted_plate", 3, "slot",
                      dict(a=120, b=60, slots=[(20, 20, 60, 20, 5), (80, 15, 95, 45, 4)]),
                      [Sheet(slotted_plate(120, 60, slots=[(20, 20, 60, 20, 5),
                                                           (80, 15, 95, 45, 4)]))]))
    # Narrow tab and acute corner.
    tab = [(0, 0, 0), (60, 0, 0), (60, 25, 0), (90, 25, 0), (90, 33, 0), (60, 33, 0),
           (60, 50, 0), (0, 50, 0)]
    cases.append(Case("plate_tab_w8", 3, "tab", dict(outline=tab),
                      [Sheet(polygon(tab))]))
    for angle in [20, 40]:
        tip = (100 * math.cos(math.radians(angle)), 100 * math.sin(math.radians(angle)), 0)
        cases.append(Case(f"acute_corner_{angle}deg", 3, "acute_corner",
                          dict(angle=angle, length=100),
                          [Sheet(polygon([(0, 0, 0), (100, 0, 0), tip]))]))
    # CAD quirks: one sheet split into faces, one of them a sliver.
    cases.append(Case("split_faces", 3, "split_faces", dict(widths=[30, 25, 35], b=50),
                      [Sheet(split_plate([30, 25, 35], 50))]))
    cases.append(Case("sliver_face", 3, "split_faces", dict(widths=[40, 0.5, 40], b=50),
                      [Sheet(split_plate([40, 0.5, 40], 50))]))
    # Stamped features.
    bead = [(0, 0), (30, 0), (36, 6), (44, 6), (50, 0), (80, 0)]
    cases.append(Case("bead", 3, "bead", dict(points=bead, mid_radius=3, width=60),
                      [Sheet(profile_sheet(bead, 3, 60))]))
    dimple = [(0, -8), (10, -8), (20, 0), (30, 0)]
    cases.append(Case("dimple", 3, "dimple", dict(a=80, b=80, profile=dimple, mid_radius=4),
                      [Sheet(plate_with_revolved(80, 80, (40, 40), 30, dimple, 4))]))
    collar = [(30, 0), (12, 0), (12, -12)]
    cases.append(Case("collar", 3, "collar", dict(a=80, b=80, profile=collar, mid_radius=4),
                      [Sheet(plate_with_revolved(80, 80, (40, 40), 30, collar, 4))]))
    # Combinations.
    hat = [(0, 0), (20, 0), (20, 30), (60, 30), (60, 0), (80, 0)]
    holes = [(0, 0.5, 15, 4), (0, 0.5, 45, 4), (4, 0.5, 15, 4), (4, 0.5, 45, 4), (2, 0.5, 30, 6)]
    cases.append(Case("hat_holes", 3, "combination", dict(points=hat, mid_radius=6, width=60,
                                                          holes=holes),
                      [Sheet(profile_sheet(hat, 6, 60, holes=holes))]))
    u = [(0, 40), (0, 0), (50, 0), (50, 40)]
    cases.append(Case("channel_holes_gussets", 3, "combination",
                      dict(points=u, mid_radius=6, width=120, gussets=[20, 100], fillet=2),
                      [Sheet(profile_sheet(u, 6, 120, holes=[(1, 0.5, 60, 10), (0, 0.5, 60, 6),
                                                             (2, 0.5, 60, 6)])),
                       Sheet(profile_face(u, 6, 20)), Sheet(profile_face(u, 6, 100))],
                      junction_fillet=2))
    lb = [(0, 50), (0, 0), (50, 0)]
    cases.append(Case("bracket", 3, "combination",
                      dict(points=lb, mid_radius=6, width=60, fillet=2),
                      [Sheet(profile_sheet(lb, 6, 60, holes=[(0, 0.6, 15, 4), (0, 0.6, 45, 4),
                                                             (1, 0.7, 12, 4), (1, 0.7, 48, 4)])),
                       Sheet(bend_gusset(30, 6, 35))],
                      junction_fillet=2))
    cases.append(Case("bracket_round_edges", 3, "combination",
                      dict(points=lb, mid_radius=6, width=60, edge_fillet=1),
                      [Sheet(profile_sheet(lb, 6, 60, holes=[(0, 0.6, 15, 4), (0, 0.6, 45, 4),
                                                             (1, 0.6, 30, 6)]))],
                      free_edge_fillet=1.0))
    rib = Sheet(polygon([(x, y, z) for x, y, z in [(40, 0, 0), (40, 100, 0), (40, 100, 20),
                                                    (40, 0, 20)]], holes=[((40, 30, 10), (1, 0, 0), 5),
                                                                          ((40, 70, 10), (1, 0, 0), 5)]))
    cases.append(Case("ribbed_plate_holes", 3, "combination",
                      dict(plate=(120, 100), rib_height=20, fillet=2),
                      [Sheet(plate(120, 100, holes=[(102, 50, 8)])), rib,
                       Sheet(polygon([(80, 0, 0), (80, 100, 0), (80, 100, 20), (80, 0, 20)]))],
                      junction_fillet=2))
    cases.append(Case("cylinder_panel_ring_rib", 3, "combination",
                      dict(radius=60, angle=120, length=60, rib_depth=12, fillet=2),
                      [Sheet(cylinder_panel(60, math.radians(120), 60)),
                       Sheet(annular_sector(48, 60, math.radians(120), 30))],
                      junction_fillet=2))
    section = [(0, 30), (0, 0), (70, 0), (70, 30)]
    ribs = [Sheet(rotated(profile_face(section, 6, -x), (0, 0, 1), 0.5 * math.pi))
            for x in (35, 65)]
    cases.append(Case("tray_two_ribs_hole", 3, "combination",
                      dict(a=100, b=70, h=30, bend_radius=6, corner_radius=10,
                           ribs=[35, 65], fillet=2),
                      [Sheet(tray(100, 70, 30, 6, 10))] + ribs, junction_fillet=2))
    return cases


def level4_cases():
    """Thickness varying from 2 to 6 on the same part."""
    cases = []
    L, W = 80, 60
    for tf, tr in [(4, 2), (6, 3), (2, 6)]:
        cases.append(Case(f"t_junction_t{tf}_{tr}", 4, "t_junction",
                          dict(flange=(L, W), rib_height=30, fillet=2, thickness=(tf, tr)),
                          [Sheet(plate(L, W, x=-L / 2), tf),
                           Sheet(polygon([(0, 0, 0), (0, W, 0), (0, W, 30), (0, 0, 30)]), tr)],
                          junction_fillet=2))
    # Symmetric thickness step: coplanar mid-surfaces, the thin solid runs
    # into the thick one.
    for t1, t2 in [(4, 2), (6, 4), (6, 2)]:
        cases.append(Case(f"thickness_step_{t1}_{t2}", 4, "thickness_step",
                          dict(a=(40, 40), b=50, thickness=(t1, t2)),
                          [Sheet(plate(40, 50), t1),
                           Sheet(plate(40, 50, x=40), t2, solid=plate(40 + t1, 50, x=40 - t1))]))
    # One-sided (flush) step: the mid-surfaces are offset by (t1 - t2) / 2.
    cases.append(Case("flush_step_6_2", 4, "thickness_step",
                      dict(a=(40, 40), b=50, thickness=(6, 2), flush="bottom"),
                      [Sheet(plate(40, 50, z=3), 6),
                       Sheet(plate(40, 50, x=40, z=1), 2, solid=plate(46, 50, x=34, z=1))]))
    widths = [2, 3, 4, 5, 6]
    ribs = [Sheet(polygon([(x, 0, 0), (x, 100, 0), (x, 100, 20), (x, 0, 20)]), t)
            for x, t in zip([20, 40, 60, 80, 100], widths)]
    cases.append(Case("ribbed_plate_t2_to_6", 4, "ribbed_plate",
                      dict(plate=(120, 100), rib_thickness=widths, fillet=1),
                      [Sheet(plate(120, 100), 4)] + ribs, junction_fillet=1))
    u = [(0, 40), (0, 0), (50, 0), (50, 40)]
    cases.append(Case("channel_t3_gusset_t6", 4, "channel_gusset",
                      dict(points=u, mid_radius=6, width=80, thickness=(3, 6), fillet=2),
                      [Sheet(profile_sheet(u, 6, 80), 3), Sheet(profile_face(u, 6, 40), 6)],
                      junction_fillet=2))
    return cases


def level1b_cases():
    """More single sheets: closed sections, double curvature, tight bends."""
    cases = []
    for a, b, r in [(40, 30, 6), (60, 20, 8)]:
        cases.append(Case(f"tube_{a}x{b}_r{r}", 1, "tube",
                          dict(a=a, b=b, corner_radius=r, length=100),
                          [Sheet(tube(a, b, r, 100))]))
    cases.append(Case("pipe_R20", 1, "pipe", dict(radius=20, length=80), [pipe(20, 80)]))
    cases.append(Case("elbow_R40_r12", 1, "elbow", dict(bend_radius=40, tube_radius=12, angle=90),
                      [Sheet(elbow(40, 12, 0.5 * math.pi))]))
    for k in [0.005, 0.01]:
        cases.append(Case(f"saddle_k{k}", 1, "saddle", dict(a=80, b=80, k=k),
                          [Sheet(saddle(80, 80, k))]))
    wave = [(0, 0), (10, 0), (20, 10), (30, 10), (40, 0), (50, 0), (60, 10), (70, 10),
            (80, 0), (90, 0)]
    cases.append(Case("corrugated", 1, "corrugated", dict(points=wave, mid_radius=3, width=60),
                      [Sheet(profile_sheet(wave, 3, 60))]))
    for h in [4, 8]:
        joggle = [(0, 0), (40, 0), (40 + h, h), (90 + h, h)]
        cases.append(Case(f"joggle_h{h}", 1, "joggle", dict(points=joggle, mid_radius=4, width=50),
                          [Sheet(profile_sheet(joggle, 4, 50))]))
    # Hems: a 180 degree fold, mid radius r, inner gap 2 r - t between layers.
    for r in [3.0, 2.5, 2.2]:
        hem = [(0, 0), (60, 0), (60, 2 * r), (30, 2 * r)]
        cases.append(Case(f"hem_gap{2 * r - T:.1f}", 1, "hem",
                          dict(points=hem, mid_radius=r, width=50, inner_gap=2 * r - T),
                          [Sheet(profile_sheet(hem, r, 50))]))
    narrow = [(0, 40), (0, 0), (12, 0), (12, 40)]
    cases.append(Case("u_channel_narrow", 1, "u_channel",
                      dict(points=narrow, mid_radius=4, width=60, inner_width=12 - T),
                      [Sheet(profile_sheet(narrow, 4, 60))]))
    return cases


def level2b_cases():
    """More junctions: partial and tapered ribs, posts, pipe flange, pan."""
    cases = []
    W = 100
    rib = Sheet(polygon([(0, 20, 0), (0, 80, 0), (0, 80, 25), (0, 20, 25)]))
    cases.append(Case("partial_rib_r2", 2, "t_junction",
                      dict(plate=(80, W), rib=(20, 80), rib_height=25, fillet=2),
                      [Sheet(plate(80, W, x=-40)), rib], junction_fillet=2))
    taper = Sheet(polygon([(0, 0, 0), (0, W, 0), (0, W, 8), (0, 0, 30)]))
    cases.append(Case("tapered_rib_r2", 2, "t_junction",
                      dict(plate=(80, W), rib_height=(30, 8), fillet=2),
                      [Sheet(plate(80, W, x=-40)), taper], junction_fillet=2))
    for r in [0, 2]:
        post = pipe(8, 20, center=(40, 40))
        cases.append(Case(f"post_r{r}", 2, "post", dict(plate=(80, 80), radius=8, height=20,
                                                         fillet=r),
                          [Sheet(plate(80, 80)), post], junction_fillet=r))
    # Pipe with an end flange: edge-to-edge, each solid extends t/2.
    for r in [0, 3]:
        flange = Sheet(annulus(20, 40), solid=annulus(20 - T / 2, 40))
        cases.append(Case(f"pipe_flange_r{r}", 2, "pipe_flange",
                          dict(pipe_radius=20, length=40, flange_radius=40, fillet=r),
                          [pipe(20, 40, extend=T / 2), flange], junction_fillet=r))
    # Drawn pan: tray sides meet a flat flange edge to edge at the rim.
    for r in [0, 3]:
        pan = Sheet(translated(tray(80, 60, 25, 6, 12), 0, 0, -25),
                    solid=translated(tray(80, 60, 25 + T / 2, 6, 12), 0, 0, -25))
        flange = Sheet(framed_plate(80, 60, 20, 0, 12),
                       solid=translated(framed_plate(80 - T, 60 - T, 20 + T / 2, 0, 12 - T / 2),
                                        T / 2, T / 2, 0))
        cases.append(Case(f"pan_flange_r{r}", 2, "pan_flange",
                          dict(a=80, b=60, depth=25, flange=20, bend_radius=6,
                               corner_radius=12, fillet=r),
                          [pan, flange], junction_fillet=r))
    return cases


def level5_cases():
    """Small parts mixing many features, closer to body-in-white parts."""
    cases = []
    hat = [(0, 0), (20, 0), (20, 30), (60, 30), (60, 0), (80, 0)]
    holes = [(0, 0.5, y, 4) for y in (25, 75, 125, 175)] + \
            [(4, 0.5, y, 4) for y in (25, 75, 125, 175)] + [(2, 0.5, 100, 8)]
    caps = [Sheet(profile_face(hat, 6, y, trim_ends=True)) for y in (40, 160)]
    cases.append(Case("crossmember", 5, "part",
                      dict(points=hat, mid_radius=6, length=200, bulkheads=[40, 160], fillet=2),
                      [Sheet(profile_sheet(hat, 6, 200, holes=holes))] + caps,
                      junction_fillet=2))
    bolts = [(30 * math.cos(a), 30 * math.sin(a), 3) for a in
             [k * 0.5 * math.pi + 0.25 * math.pi for k in range(4)]]
    # Gussets chamfered clear of the pipe-flange fillet.
    gussets = [Sheet(rotated(polygon([(20, 0, 8), (20, 0, 25), (38, 0, 0), (28, 0, 0)]),
                             (0, 0, 1), a)) for a in (0, 0.5 * math.pi, math.pi, 1.5 * math.pi)]
    cases.append(Case("pipe_flange_bolts_gussets", 5, "part",
                      dict(pipe_radius=20, length=60, flange_radius=40, bolts=4, gussets=4,
                           fillet=1),
                      [pipe(20, 60, extend=T / 2), Sheet(annulus(20, 40, holes=bolts),
                                   solid=annulus(20 - T / 2, 40, holes=bolts))] + gussets,
                      junction_fillet=1))
    # Ribs stop below the rim: their top is a free edge.
    section = [(0, 18), (0, 0), (60, 0), (60, 18)]
    pan = Sheet(translated(tray(80, 60, 25, 6, 12), 0, 0, -25),
                solid=translated(tray(80, 60, 25 + T / 2, 6, 12), 0, 0, -25))
    flange_holes = [(x, y, 3) for x in (-10, 90) for y in (10, 50)]
    frame = framed_plate(80, 60, 20, 0, 12)
    framed = lambda occ: occ.cut(frame(occ), [(2, occ.addDisk(x, y, 0, r, r))
                                              for x, y, r in flange_holes])[0]
    frame_solid = translated(framed_plate(80 - T, 60 - T, 20 + T / 2, 0, 12 - T / 2),
                             T / 2, T / 2, 0)
    framed_solid = lambda occ: occ.cut(frame_solid(occ), [(2, occ.addDisk(x, y, 0, r, r))
                                                          for x, y, r in flange_holes])[0]
    ribs = [Sheet(translated(rotated(profile_face(section, 6, -x), (0, 0, 1), 0.5 * math.pi),
                             0, 0, -25)) for x in (27, 53)]
    cases.append(Case("pan_ribs_flange_holes", 5, "part",
                      dict(a=80, b=60, depth=25, flange=20, ribs=[27, 53], rib_height=18,
                           fillet=2),
                      [pan, Sheet(framed, solid=framed_solid)] + ribs, junction_fillet=2))
    lb = [(0, 50), (0, 0), (60, 0)]
    collar = [(14, 0), (8, 0), (8, -8)]
    cases.append(Case("bracket_t3_hem", 5, "part",
                      dict(points=lb, mid_radius=5, width=60, thickness=3, fillet=1.5),
                      [Sheet(profile_sheet([(0, 50), (0, 0), (60, 0), (60, 6), (40, 6)], 3.0, 60,
                                           holes=[(0, 0.5, 15, 4), (0, 0.5, 45, 4)]), 3.0),
                       Sheet(bend_gusset(30, 3, 35), 3.0)],
                      junction_fillet=1.5))
    return cases


# ---------------------------------------------------------------------------
# Level 6: relatively complex objects on a large base plate.


def rounded_tube(a, b, corner_radius, height, center, angle, z0=0.0, thickness=T):
    """Closed rounded rectangular wall standing on z0, and its exact solid."""
    def place(occ, out):
        occ.rotate(out, 0, 0, 0, 0, 0, 1, angle)
        occ.translate(out, center[0], center[1], 0)
        return out

    def sheet(occ):
        return place(occ, translated(tube(a, b, corner_radius, height), 0, 0, z0)(occ))

    def volume(occ):
        h = thickness / 2
        outer = occ.addRectangle(-a / 2 - h, -b / 2 - h, z0, a + 2 * h, b + 2 * h,
                                 roundedRadius=corner_radius + h)
        inner = occ.addRectangle(-a / 2 + h, -b / 2 + h, z0, a - 2 * h, b - 2 * h,
                                 roundedRadius=corner_radius - h)
        ring, _ = occ.cut([(2, outer)], [(2, inner)])
        out = [dt for dt in occ.extrude(ring, 0, 0, height) if dt[0] == 3]
        occ.remove(ring, recursive=True)
        return place(occ, out)
    return Sheet(sheet, thickness, volume=volume)


def base_sheet(kind, L, W, holes, revolved, openings, shrink=0.0):
    """Base of an assembly: a flat plate or a plate with its edges bent down
    (an upside-down shallow tray), minus holes and openings, plus revolved
    features (collars, dimples). `shrink` narrows the openings by t/2 for the
    thickened solid (edge-to-edge joint with the pocket walls)."""
    def build(occ):
        if kind == "flat":
            faces = [(2, occ.addRectangle(0, 0, 0, L, W))]
        else:
            faces = tray(L, W, 15, 6, 15)(occ)
            occ.rotate(faces, 0, 0, 0, 1, 0, 0, math.pi)
            occ.translate(faces, 0, W, 0)
        tools = [(2, occ.addDisk(x, y, 0, r, r)) for x, y, r in holes]
        tools += [(2, occ.addDisk(x, y, 0, rc, rc)) for x, y, rc, _, _ in revolved]
        for x, y, a, b, rc, angle in openings:
            o = occ.addRectangle(-a / 2 + shrink, -b / 2 + shrink, 0, a - 2 * shrink,
                                 b - 2 * shrink, roundedRadius=rc - shrink)
            occ.rotate([(2, o)], 0, 0, 0, 0, 0, 1, angle)
            occ.translate([(2, o)], x, y, 0)
            tools.append((2, o))
        if tools:
            faces, _ = occ.cut(faces, tools)
        for x, y, _, points, radius in revolved:
            faces += translated(revolved_profile(points, radius), x, y, 0)(occ)
        return faces
    return build


def assembly_case(seed):
    rng = random.Random(seed)
    L, W, nx, ny = rng.choice([(300, 200, 3, 2), (400, 200, 4, 2), (360, 240, 3, 2),
                               (400, 300, 4, 3), (260, 260, 2, 2), (320, 320, 3, 3)])
    kind = "flanged" if rng.random() < 0.3 else "flat"
    fillet = rng.choice([0, 1, 2, 2])
    cw, ch = L / nx, W / ny
    R = 0.5 * min(cw, ch) - 10  # footprint radius available in a cell
    holes, revolved, openings, sheets, features = [], [], [], [], []
    kinds = ["rib", "rib_gussets", "cross_ribs", "tee_ribs", "box", "pipe",
             "pipe_gussets", "channel", "angle", "holes", "collar", "dimple"]
    if kind == "flat":
        kinds.append("pocket")

    def frame(angle, c):
        return lambda b: translated(rotated(b, (0, 0, 1), angle), c[0], c[1], 0)

    for i in range(nx):
        for j in range(ny):
            if rng.random() < 0.15:
                continue
            c = ((i + 0.5) * cw, (j + 0.5) * ch)
            what = rng.choice(kinds)
            angle = rng.choice([0, 0.5 * math.pi, rng.uniform(0, math.pi)])
            put = frame(angle, c)
            f = dict(kind=what, center=[round(c[0], 3), round(c[1], 3)],
                     angle_deg=round(math.degrees(angle), 3))
            if what in ("rib", "rib_gussets"):
                l, h = rng.uniform(1.0, 1.9) * R, rng.uniform(12, 35)
                sheets.append(Sheet(put(polygon([(-l / 2, 0, 0), (l / 2, 0, 0),
                                                  (l / 2, 0, h), (-l / 2, 0, h)]))))
                f.update(length=l, height=h)
                if what == "rib_gussets":
                    g = min(0.8 * h, R - 6)
                    for x in (-l / 4, l / 4):
                        sheets.append(Sheet(put(polygon([(x, u, z) for u, _, z in
                                                         gusset_outline(0.8 * h, g)]))))
            elif what == "cross_ribs":
                l, h = rng.uniform(1.2, 1.9) * R, rng.uniform(12, 30)
                for a in (0, 0.5 * math.pi):
                    sheets.append(Sheet(frame(angle + a, c)(polygon(
                        [(-l / 2, 0, 0), (l / 2, 0, 0), (l / 2, 0, h), (-l / 2, 0, h)]))))
                f.update(length=l, height=h)
            elif what == "tee_ribs":
                l, h = rng.uniform(1.2, 1.9) * R, rng.uniform(12, 30)
                sheets.append(Sheet(put(polygon([(-l / 2, 0, 0), (l / 2, 0, 0),
                                                  (l / 2, 0, h), (-l / 2, 0, h)]))))
                sheets.append(Sheet(put(polygon([(0, 0, 0), (0, 0.45 * l, 0),
                                                  (0, 0.45 * l, h), (0, 0, h)]))))
                f.update(length=l, height=h)
            elif what == "box":
                a, b = rng.uniform(0.6, 1.3) * R, rng.uniform(0.5, 1.0) * R
                scale = min(1.0, 2 * R / math.hypot(a, b))
                a, b = a * scale, b * scale
                rc, h = rng.uniform(5, 0.3 * min(a, b)), rng.uniform(15, 40)
                sheets.append(rounded_tube(a, b, rc, h, c, angle))
                f.update(a=a, b=b, corner_radius=rc, height=h)
            elif what in ("pipe", "pipe_gussets"):
                r = rng.uniform(8, min(25, 0.5 * R))
                h = rng.uniform(15, 45)
                sheets.append(pipe(r, h, center=c))
                f.update(radius=r, height=h)
                if what == "pipe_gussets":
                    g = min(R - r, 0.6 * h)
                    for k in range(rng.choice([3, 4])):
                        a = angle + k * 2 * math.pi / 4
                        sheets.append(Sheet(frame(a, c)(polygon(gusset_outline(0.7 * h, g, offset=r)))))
            elif what in ("channel", "angle"):
                h, w = rng.uniform(15, 30), rng.uniform(16, 30)
                l = rng.uniform(1.0, 1.7) * R
                pts = [(-w / 2, 0), (-w / 2, h), (w / 2, h), (w / 2, 0)] if what == "channel" \
                    else [(0, 0), (0, h), (w, h)]
                sheets.append(Sheet(put(translated(profile_sheet(pts, 5, l), 0, -l / 2, 0))))
                f.update(height=h, width=w, length=l)
            elif what == "holes":
                n = rng.choice([1, 2, 3, 4])
                for k in range(n):
                    a = angle + k * 2 * math.pi / n
                    d = 0 if n == 1 else 0.5 * R
                    holes.append((c[0] + d * math.cos(a), c[1] + d * math.sin(a),
                                  rng.uniform(3, 0.3 * R if n > 1 else 0.6 * R)))
                f.update(count=n)
            elif what == "collar":
                ri = rng.uniform(8, 0.5 * R)
                profile = [(ri + 14, 0), (ri, 0), (ri, -rng.uniform(8, 15))]
                revolved.append((c[0], c[1], ri + 14, profile, 4))
                f.update(radius=ri)
            elif what == "dimple":
                rd = rng.uniform(0.5, 0.9) * R
                depth = rng.uniform(5, 12)
                profile = [(0, -depth), (0.4 * rd, -depth), (0.8 * rd, 0), (rd, 0)]
                revolved.append((c[0], c[1], rd, profile, 4))
                f.update(radius=rd, depth=depth)
            elif what == "pocket":
                a, b = rng.uniform(0.8, 1.3) * R, rng.uniform(0.6, 1.0) * R
                scale = min(1.0, 2 * R / math.hypot(a, b))
                a, b = a * scale, b * scale
                rc, d = rng.uniform(8, 0.35 * min(a, b)), rng.uniform(12, 25)
                openings.append((c[0], c[1], a, b, rc, angle))
                place = lambda bld: translated(rotated(translated(bld, -a / 2, -b / 2, -d),
                                                       (0, 0, 1), angle), c[0], c[1], 0)
                sheets.append(Sheet(place(tray(a, b, d, 5, rc)),
                                    solid=place(tray(a, b, d + T / 2, 5, rc))))
                f.update(a=a, b=b, corner_radius=rc, depth=d)
            features.append(f)
    base = Sheet(base_sheet(kind, L, W, holes, revolved, openings),
                 solid=base_sheet(kind, L, W, holes, revolved, openings, T / 2)
                 if openings else None)
    params = dict(seed=seed, base=kind, size=(L, W), cells=(nx, ny), fillet=fillet,
                  features=features)
    return Case(f"assembly_{seed:03d}", 6, "assembly", params, [base] + sheets,
                junction_fillet=fillet)


def level6_cases(count=100):
    return [assembly_case(seed) for seed in range(count)]


# ---------------------------------------------------------------------------
# Level 7: large curved trim panels with a return flange and clip towers
# ("doghouses"), in the spirit of a molded body panel.


def rounded_profile_radii(points, radii):
    """rounded_profile with one radius per interior corner."""
    segments, start = [], points[0]
    for i in range(1, len(points) - 1):
        piece = rounded_profile([start, points[i], points[i + 1]], radii[i - 1])
        segments += piece[:-1]
        start = piece[-1][1]
    segments.append(("line", start, points[-1]))
    return segments


class PanelShape:
    """Mid-surface of the panel: sections x = const lofted into one smooth
    sheet. Each section runs from the free edge (y = 0) over a cambered panel
    to a rounded bend and a return flange going down (-z). The bend line is
    curved in plan and the flange height varies along x."""

    def __init__(self, L, Y0, curve, sag, flange, bend_radius, notch, holes):
        self.L, self.Y0, self.curve, self.sag = L, Y0, curve, sag
        self.flange, self.bend_radius, self.notch, self.holes = flange, bend_radius, notch, holes

    def bend_line(self, x):
        u = 2 * x / self.L - 1
        return self.Y0 * (1 - self.curve * u * u)

    def section(self, x):
        u = 2 * x / self.L - 1
        Y = self.bend_line(x)
        s = self.sag * (1 - 0.5 * u * u)
        H = self.flange[0] + (self.flange[1] - self.flange[0]) * x / self.L
        pts = [(0.0, 0.0), (0.5 * Y, s), (Y, 0.0), (Y + 0.15 * H, -H)]
        # Camber arc: tangent length 40 % of the half section.
        turn = math.atan2(s, 0.5 * Y) * 2
        camber = 0.4 * 0.5 * Y / math.tan(0.5 * turn)
        return rounded_profile_radii(pts, [camber, self.bend_radius])

    def build(self, occ):
        wires = []
        for k in range(5):
            x = self.L * k / 4
            curves = []
            for seg in self.section(x):
                if seg[0] == "line":
                    a, b = seg[1], seg[2]
                    curves.append(occ.addLine(occ.addPoint(x, *a), occ.addPoint(x, *b)))
                else:
                    a, c, b = seg[1], seg[2], seg[3]
                    curves.append(occ.addCircleArc(occ.addPoint(x, *a), occ.addPoint(x, *c),
                                                   occ.addPoint(x, *b)))
            wires.append(occ.addWire(curves))
        faces = [dt for dt in occ.addThruSections(wires, makeSolid=False) if dt[0] == 2]
        tools = []
        if self.notch:
            a, b, r = self.notch
            n = occ.addRectangle(self.L - a, -b, -200, a + b, 2 * b, roundedRadius=r)
            tools += [dt for dt in occ.extrude([(2, n)], 0, 0, 400) if dt[0] == 3]
        for x, y, r in self.holes:
            tools.append((3, occ.addCylinder(x, y, -200, 0, 0, 400, r)))
        if tools:
            faces, _ = occ.cut(faces, tools)
            faces = [dt for dt in faces if dt[0] == 2]
        return faces


def frame_on(occ, faces, x, y, guess_z):
    """Point of the panel above (x, y), and its unit normal pointing to the
    flange side (down)."""
    occ.synchronize()
    best = None
    for _, f in faces:
        q, uv = gmsh.model.getClosestPoint(2, f, [x, y, guess_z])
        d = math.dist(q, (x, y, guess_z))
        if best is None or d < best[0]:
            best = (d, list(q), f, list(uv))
    _, q, f, uv = best
    n = list(gmsh.model.getNormal(f, uv))
    if n[2] > 0:
        n = [-c for c in n]
    return q, n


def standing(panel, x, y, w, local):
    """A sheet built by local(occ) in local coordinates (profile, width,
    height), with the width centered on w / 2 and the height going from below
    the panel (negative) up: placed at the panel point above (x, y), height
    along the panel normal on the flange side, profile across the panel x
    axis, then trimmed on the panel mid-surface."""
    def build(occ):
        faces = panel.build(occ)
        P, n = frame_on(occ, faces, x, y, 0.0)
        ex = [1.0 - n[0] * n[0], -n[0] * n[1], -n[0] * n[2]]
        norm = math.sqrt(sum(c * c for c in ex))
        ex = [c / norm for c in ex]
        ey = [n[1] * ex[2] - n[2] * ex[1], n[2] * ex[0] - n[0] * ex[2],
              n[0] * ex[1] - n[1] * ex[0]]
        out = local(occ)
        # Local (profile, width, height) -> (ey, ex, n), width centered on P.
        occ.affineTransform(out, [ey[0], ex[0], n[0], P[0] - w / 2 * ex[0],
                                  ey[1], ex[1], n[1], P[1] - w / 2 * ex[1],
                                  ey[2], ex[2], n[2], P[2] - w / 2 * ex[2]])
        _, children = occ.fragment(out, faces)
        pieces = [c for kids in children[:len(out)] for c in kids]
        panel_pieces = {c for kids in children[len(out):] for c in kids}
        occ.synchronize()
        keep = []
        for dt in pieces:
            if dt in panel_pieces:
                continue
            c = occ.getCenterOfMass(*dt)
            if sum((c[i] - P[i]) * n[i] for i in range(3)) > 0:
                keep.append(dt)
        occ.remove([dt for dt in set(pieces) | panel_pieces if dt not in keep])
        return keep
    return build


BELOW = 8.0  # local sheets start this far below the panel, then are trimmed


def rib_sheet(inner, inner_radius, outer, outer_radius, y0):
    """Planar sheet in the plane y = y0 between two rounded polylines of the
    (x, z) plane that start on the same bottom line: inner and outer, each
    rounded at its corners, joined at the bottom and at their ends."""
    def build(occ):
        points = {}

        def point(p):
            key = (round(p[0], 9), round(p[1], 9))
            if key not in points:
                points[key] = occ.addPoint(p[0], y0, p[1])
            return points[key]

        def curves_of(segments):
            out = []
            for seg in segments:
                if seg[0] == "line":
                    if math.dist(seg[1], seg[2]) > 1e-9:
                        out.append(occ.addLine(point(seg[1]), point(seg[2])))
                else:
                    out.append(occ.addCircleArc(point(seg[1]), point(seg[2]), point(seg[3])))
            return out

        loop = curves_of(rounded_profile(outer, outer_radius))
        loop.append(occ.addLine(point(outer[-1]), point(inner[-1])))
        inner_curves = curves_of(rounded_profile(inner, inner_radius))
        loop += [-c for c in reversed(inner_curves)]
        loop.append(occ.addLine(point(inner[0]), point(outer[0])))
        return [(2, occ.addPlaneSurface([occ.addCurveLoop(loop)]))]
    return build


def doghouse_part(panel, x, y, w, d, h, part, hole=3.5, gusset=6.0, bend=2.5, rib=4.0):
    """One sheet of a clip tower standing on the panel at (x, y): part 'bridge'
    (legs and holed top, a rounded ⊓ along the local x axis), 'gusset k'
    (k = 0..3, triangular ribs against the legs) or 'rib k' (k = 0..3: like
    the Doghouse, planar ribs across the legs at a quarter of the width,
    following the outside of a leg, its bend and the top, standing `rib` out
    of them, and tapering off on the top)."""
    def local(occ):
        if part == "bridge":
            prof = [(-d / 2, -BELOW), (-d / 2, h), (d / 2, h), (d / 2, -BELOW)]
            return profile_sheet(prof, bend, w, holes=[(1, 0.5, w / 2, hole)])(occ)
        k = int(part.split()[1])
        side, y0 = (1 if k % 2 else -1), (0.25 * w if k < 2 else 0.75 * w)
        if part.startswith("rib"):
            top = bend + 2.0
            inner = [(-d / 2, -BELOW), (-d / 2, h), (-d / 2 + top + rib, h)]
            outer = [(-d / 2 - rib, -BELOW), (-d / 2 - rib, h + rib), (-d / 2 + top, h + rib)]
            if side > 0:
                inner = [(-px, pz) for px, pz in inner]
                outer = [(-px, pz) for px, pz in outer]
            return rib_sheet(inner, bend, outer, bend + rib, y0)(occ)
        y0 = 3.0 if k < 2 else w - 3.0
        return polygon([(side * d / 2, y0, 0.85 * h), (side * (d / 2 + gusset), y0, -BELOW),
                        (side * d / 2, y0, -BELOW)])(occ)
    return standing(panel, x, y, w, local)


def keyhole_tower_part(panel, x, y, a, b, h, part, corner=3.0, gusset=7.0):
    """Tall clip tower: an open rounded rectangular tube a x b, height h, with a
    keyhole slot through its front wall (part 'tube'), or 'gusset k' (k = 0, 1:
    triangular ribs against the side walls)."""
    def local(occ):
        if part == "tube":
            out = translated(tube(a, b, corner, h + BELOW), 0, b / 2, -BELOW)(occ)
            hole = occ.addCylinder(0, b / 2, 0.6 * h, a, 0, 0, 0.18 * b)
            slot = occ.addBox(0, b / 2 - 0.07 * b, 0.3 * h, a, 0.14 * b, 0.3 * h)
            out, _ = occ.cut(out, [(3, hole), (3, slot)])
            return [dt for dt in out if dt[0] == 2]
        side = 1 if part.endswith("1") else -1
        return polygon([(side * a / 2, b / 2, 0.6 * h), (side * (a / 2 + gusset), b / 2, -BELOW),
                        (side * a / 2, b / 2, -BELOW)])(occ)
    return standing(panel, x, y, b, local)


def hook_part(panel, x, y, w, h, tab, bend=2.0):
    """L-shaped hook: a leg standing on the panel and a tab at its top."""
    def local(occ):
        return profile_sheet([(0, -BELOW), (0, h), (tab, h)], bend, w)(occ)
    return standing(panel, x, y, w, local)


def panel_case(seed):
    rng = random.Random(1000 + seed)
    L = rng.choice([400, 500, 600])
    Y0 = rng.uniform(0.5, 0.65) * L
    shape = dict(L=L, Y0=Y0, curve=rng.uniform(0.1, 0.3), sag=rng.uniform(6, 20),
                 flange=(rng.uniform(20, 35), rng.uniform(35, 60)),
                 bend_radius=rng.choice([6, 8, 10]))
    notch = (rng.uniform(0.15, 0.25) * L, rng.uniform(0.25, 0.35) * Y0, 12) \
        if rng.random() < 0.7 else None
    holes = []
    panel_t = 3.0
    dog_t = rng.choice([2.0, 2.5, 3.0])
    fillet = rng.choice([0, 1, 1])
    # Clip towers on a jittered grid, away from the notch, the flange and holes.
    nx, ny = rng.choice([(3, 2), (4, 2), (3, 3), (4, 3)])
    towers = []
    for i in range(nx):
        for j in range(ny):
            x = L * (0.15 + 0.7 * (i + 0.5) / nx) + rng.uniform(-10, 10)
            y = Y0 * (0.15 + 0.55 * (j + 0.5) / ny) + rng.uniform(-8, 8)
            if notch and x > L - notch[0] - 40 and y < notch[1] + 40:
                continue
            towers.append((x, y, rng.uniform(18, 24), rng.uniform(24, 30), rng.uniform(12, 20)))
    for k in range(rng.choice([2, 3, 4])):
        x, y = rng.uniform(0.1, 0.9) * L, rng.uniform(0.08, 0.12) * Y0
        if not (notch and x > L - notch[0] - 20):
            holes.append((x, y, rng.uniform(3, 5)))
    panel = PanelShape(notch=notch, holes=holes, **shape)
    sheets = [Sheet(panel.build, panel_t)]
    for x, y, w, d, h in towers:
        # Doghouse towers: holed bridge and four ribs standing above its top.
        sheets.append(Sheet(doghouse_part(panel, x, y, w, d, h, "bridge", hole=2.5), dog_t))
        sheets += [Sheet(doghouse_part(panel, x, y, w, d, h, f"rib {k}", hole=2.5), dog_t)
                   for k in range(4)]
    params = dict(seed=seed, shape=shape, notch=notch, holes=holes,
                  thickness=dict(panel=panel_t, towers=dog_t), fillet=fillet,
                  towers=[dict(x=x, y=y, width=w, depth=d, height=h) for x, y, w, d, h in towers])
    return Case(f"panel_{seed:03d}", 7, "panel", params, sheets, junction_fillet=fillet)


def level7_cases(count=20):
    return [panel_case(seed) for seed in range(count)]


# ---------------------------------------------------------------------------
# Level 8: geometries in the spirit of a given industrial part (a long molded
# trim strip): a bowed, cambered strip with a rounded end and an oblique end,
# a perimeter rim set back from the edge, and clips of several kinds.


class StripShape:
    """Mid-surface of a trim strip of length L and width W: sections x = const
    lofted into one sheet, bowed along x and cambered across, cut to an
    outline with a rounded end (corner radius R at x = L) and an oblique end
    (from (0, W) to (oblique, 0)), minus holes."""

    def __init__(self, L, W, bow, camber, R, oblique, holes, sweep=12.0):
        self.L, self.W, self.bow, self.camber = L, W, bow, camber
        self.R, self.oblique, self.holes, self.sweep = R, oblique, holes, sweep

    def outline(self, occ, inset, z):
        """Closed curve loop of the outline moved inwards by `inset`, every
        corner rounded (G1, so a wall built on it can be thickened)."""
        L, W, ob, c = self.L, self.W, self.oblique, self.sweep
        # The long sides follow a gentle arc in plan (sagitta c), like the
        # strip they imitate; straight sides of a bowed strip also make
        # OpenCASCADE build degenerate planar side faces when thickening.
        xs = [ob + (L - ob) * k / 4 for k in (1, 2, 3)]
        bottom = [(x, -c * (1 - (2 * x / L - 1) ** 2)) for x in xs]
        top = [(x, W - c * (1 - (2 * x / L - 1) ** 2)) for x in reversed(xs)]
        corners = [(ob, 0.0)] + bottom + [(L, 0.0), (L, W)] + top + [(0.0, W)]
        radii = [8.0, 400.0, 400.0, 400.0, self.R, self.R, 400.0, 400.0, 400.0, 8.0]
        m = len(corners)
        # Move each edge inwards (counterclockwise polygon: left normal).
        lines = []
        for k in range(m):
            a, b = corners[k], corners[(k + 1) % m]
            d = unit(sub(b, a))
            n = (-d[1], d[0])
            lines.append(((a[0] + inset * n[0], a[1] + inset * n[1]), d))
        pts = []
        for k in range(m):
            (p1, d1), (p2, d2) = lines[k - 1], lines[k]
            det = d1[0] * (-d2[1]) - d1[1] * (-d2[0])
            t = ((p2[0] - p1[0]) * (-d2[1]) - (p2[1] - p1[1]) * (-d2[0])) / det
            pts.append((p1[0] + t * d1[0], p1[1] + t * d1[1]))
        start = (0.5 * (pts[0][0] + pts[1][0]), 0.5 * (pts[0][1] + pts[1][1]))
        sequence = [start] + pts[1:] + [pts[0], start]
        segs = rounded_profile_radii(sequence, [r - inset for r in radii[1:] + radii[:1]])
        curves, first, last = [], None, None
        for seg in segs:
            if seg[0] == "line" and math.dist(seg[1], seg[2]) < 1e-9:
                continue
            a = occ.addPoint(seg[1][0], seg[1][1], z) if last is None else last
            first = a if first is None else first
            end = seg[2] if seg[0] == "line" else seg[3]
            last = first if math.dist(end, sequence[-1]) < 1e-9 and len(curves) > 0 \
                and seg is segs[-1] else occ.addPoint(end[0], end[1], z)
            if seg[0] == "line":
                curves.append(occ.addLine(a, last))
            else:
                curves.append(occ.addCircleArc(a, occ.addPoint(seg[2][0], seg[2][1], z), last))
        return occ.addCurveLoop(curves)

    def prism(self, occ, inset):
        s = occ.addPlaneSurface([self.outline(occ, inset, -200)])
        return [dt for dt in occ.extrude([(2, s)], 0, 0, 400) if dt[0] == 3]

    def build(self, occ, holes=True):
        wires = []
        for k in range(5):
            x = -5 + (self.L + 10) * k / 4
            u = 2 * x / self.L - 1
            z0 = self.bow * (1 - u * u)
            m = self.sweep + 5.0
            pts = [(-m, z0), (0.5 * self.W, z0 + self.camber), (self.W + 5.0, z0)]
            turn = 2 * math.atan2(self.camber, 0.5 * self.W + 5)
            radius = 0.4 * (0.5 * self.W + 5) / math.tan(0.5 * turn)
            curves = []
            for seg in rounded_profile_radii(pts, [radius]):
                if seg[0] == "line":
                    curves.append(occ.addLine(occ.addPoint(x, *seg[1]), occ.addPoint(x, *seg[2])))
                else:
                    curves.append(occ.addCircleArc(occ.addPoint(x, *seg[1]),
                                                   occ.addPoint(x, *seg[2]),
                                                   occ.addPoint(x, *seg[3])))
            wires.append(occ.addWire(curves))
        faces = [dt for dt in occ.addThruSections(wires, makeSolid=False) if dt[0] == 2]
        faces, _ = occ.intersect(faces, self.prism(occ, 0.0))
        faces = [dt for dt in faces if dt[0] == 2]
        if holes and self.holes:
            tools = [(3, occ.addCylinder(hx, hy, -200, 0, 0, 400, r)) for hx, hy, r in self.holes]
            faces, _ = occ.cut(faces, tools)
            faces = [dt for dt in faces if dt[0] == 2]
        return faces


def strip_rim(strip, inset, height):
    """Perimeter rim: a wall of constant height going down (-z) from the inset
    outline drawn on the strip mid-surface."""
    def build(occ):
        # Without the holes: only the outer loop carries the rim.
        faces = strip.build(occ, holes=False)
        inner, _ = occ.intersect(faces, strip.prism(occ, inset))
        inner = [dt for dt in inner if dt[0] == 2]
        occ.synchronize()
        curves = [(1, abs(c)) for _, c in gmsh.model.getBoundary(inner, combined=True,
                                                                 oriented=False)]
        wall = [dt for dt in occ.extrude(curves, 0, 0, -height) if dt[0] == 2]
        occ.remove(inner)
        occ.remove([dt for dt in faces if dt not in inner])
        return wall
    return build


def strip_case(seed):
    rng = random.Random(2000 + seed)
    L, W = rng.choice([(520, 110), (480, 130)])
    strip = StripShape(L=L, W=W, bow=rng.uniform(8, 15), camber=rng.uniform(2, 5),
                       R=rng.uniform(25, 35), oblique=rng.uniform(20, 40),
                       sweep=rng.uniform(10, 18),
                       holes=[(rng.uniform(0.2, 0.8) * L, rng.uniform(0.25, 0.75) * W, 3)
                              for _ in range(rng.choice([2, 3]))])
    panel_t, clip_t = 3.0, rng.choice([2.0, 2.5])
    sheets = [Sheet(strip.build, panel_t),
              Sheet(strip_rim(strip, 4.0, rng.uniform(5, 8)), clip_t)]
    clips = []
    xs = [L * (0.12 + 0.76 * k / 6) + rng.uniform(-8, 8) for k in range(7)]
    kinds = ["keyhole", "doghouse", "hook", "keyhole", "doghouse", "keyhole", "hook"]
    rng.shuffle(kinds)
    for x, kind in zip(xs, kinds):
        y = W * rng.choice([0.35, 0.5, 0.65])
        if kind == "keyhole":
            a, b, h = rng.uniform(10, 14), rng.uniform(18, 24), rng.uniform(30, 45)
            sheets.append(Sheet(keyhole_tower_part(strip, x, y, a, b, h, "tube"), clip_t))
            sheets += [Sheet(keyhole_tower_part(strip, x, y, a, b, h, f"gusset {k}"), clip_t)
                       for k in (0, 1)]
            clips.append(dict(kind=kind, x=x, y=y, a=a, b=b, height=h))
        elif kind == "doghouse":
            w, d, h = rng.uniform(18, 24), rng.uniform(12, 16), rng.uniform(12, 18)
            sheets.append(Sheet(doghouse_part(strip, x, y, w, d, h, "bridge"), clip_t))
            sheets += [Sheet(doghouse_part(strip, x, y, w, d, h, f"gusset {k}"), clip_t)
                       for k in range(4)]
            clips.append(dict(kind=kind, x=x, y=y, width=w, depth=d, height=h))
        else:
            w, h, tab = rng.uniform(10, 16), rng.uniform(14, 22), rng.uniform(6, 10)
            sheets.append(Sheet(hook_part(strip, x, y, w, h, tab), clip_t))
            clips.append(dict(kind=kind, x=x, y=y, width=w, height=h, tab=tab))
    params = dict(seed=seed, inspired_by="long molded trim strip", length=L, width=W,
                  bow=strip.bow, camber=strip.camber, sweep=strip.sweep, end_radius=strip.R,
                  oblique=strip.oblique, holes=strip.holes,
                  thickness=dict(panel=panel_t, rim_and_clips=clip_t), clips=clips)
    # OpenCASCADE fails to fillet these junctions: no fillet.
    return Case(f"trim_strip_{seed:03d}", 8, "trim_strip", params, sheets, unify=False)


def rounded_rect_loop(occ, x0, y0, x1, y1, r, z):
    """Curve loop of the rounded rectangle [x0, x1] x [y0, y1] at height z."""
    rect = occ.addRectangle(x0, y0, z, x1 - x0, y1 - y0, roundedRadius=r)
    occ.synchronize()
    curves = [abs(c) for _, c in gmsh.model.getBoundary([(2, rect)], oriented=False)]
    occ.remove([(2, rect)])
    return occ.addCurveLoop(curves)


def prism_of(occ, loop):
    face = occ.addPlaneSurface([loop])
    occ.translate([(2, face)], 0, 0, -200)
    return [dt for dt in occ.extrude([(2, face)], 0, 0, 400) if dt[0] == 3]


class BezelShape:
    """Mid-surface of a bezel: a frame bowed along x around a rounded
    rectangular opening. Outline [0, L] x [0, H] with corner radius R; the
    opening is set back by `frame` with corner radius r."""

    def __init__(self, L, H, R, frame, r, bow, holes=()):
        self.L, self.H, self.R, self.frame, self.r, self.bow, self.holes = L, H, R, frame, r, bow, holes

    def base(self, occ):
        wires, m = [], 20.0
        for k in range(5):
            x = -m + (self.L + 2 * m) * k / 4
            u = 2 * x / self.L - 1
            z = self.bow * (1 - u * u)
            wires.append(occ.addWire([occ.addLine(occ.addPoint(x, -m, z),
                                                  occ.addPoint(x, self.H + m, z))]))
        return [dt for dt in occ.addThruSections(wires, makeSolid=False) if dt[0] == 2]

    def outer_prism(self, occ, offset=0.0):
        return prism_of(occ, rounded_rect_loop(occ, -offset, -offset, self.L + offset,
                                               self.H + offset, self.R + offset, 0))

    def inner_prism(self, occ, offset=0.0):
        f = self.frame
        return prism_of(occ, rounded_rect_loop(occ, f + offset, f + offset, self.L - f - offset,
                                               self.H - f - offset, self.r - offset, 0))

    def faces(self, occ, offset=0.0, holes=True):
        """The frame; offset > 0 grows it outwards and into the opening (the
        thickened solid of edge-to-edge joints with the skirt and the lip)."""
        faces, _ = occ.intersect(self.base(occ), self.outer_prism(occ, offset))
        faces, _ = occ.cut([dt for dt in faces if dt[0] == 2], self.inner_prism(occ, offset))
        faces = [dt for dt in faces if dt[0] == 2]
        if holes and self.holes:
            tools = [(3, occ.addCylinder(x, y, -200, 0, 0, 400, r)) for x, y, r in self.holes]
            faces, _ = occ.cut(faces, tools)
            faces = [dt for dt in faces if dt[0] == 2]
        return faces

    def build(self, occ):
        return self.faces(occ)


def bezel_wall(bezel, which, depth, lift=0.0):
    """Wall going back (-z) from the outer outline ('skirt') or the opening
    outline ('lip') drawn on the bezel mid-surface; lift raises its start, for
    the thickened solid of the edge-to-edge joint."""
    def build(occ):
        prism = bezel.outer_prism(occ) if which == "skirt" else bezel.inner_prism(occ)
        region, _ = occ.intersect(bezel.base(occ), prism)
        region = [dt for dt in region if dt[0] == 2]
        occ.synchronize()
        curves = [(1, abs(c)) for _, c in gmsh.model.getBoundary(region, combined=True,
                                                                 oriented=False)]
        curves = occ.copy(curves)
        if lift:
            occ.translate(curves, 0, 0, lift)
        wall = [dt for dt in occ.extrude(curves, 0, 0, -(depth + lift)) if dt[0] == 2]
        occ.remove(region, recursive=True)
        return wall
    return build


def boss_part(panel, x, y, radius, height):
    """Screw boss: a tube standing on the panel, trimmed on its mid-surface."""
    def local(occ):
        return translated(cylinder_panel(radius, 2 * math.pi, height + BELOW), 0, radius, -BELOW)(occ)
    return standing(panel, x, y, 2 * radius, local)


def bezel_case(seed):
    rng = random.Random(3000 + seed)
    L, H = rng.choice([(300, 180), (260, 200)])
    t, frame = 2.5, rng.uniform(32, 42)
    bezel = BezelShape(L, H, R=rng.uniform(22, 32), frame=frame, r=rng.uniform(16, 24),
                       bow=rng.uniform(8, 16))
    skirt, lip = rng.uniform(22, 32), rng.uniform(10, 16)
    sheets = [
        Sheet(bezel.build, t, solid=lambda occ: bezel.faces(occ, offset=t / 2)),
        Sheet(bezel_wall(bezel, "skirt", skirt), t, solid=bezel_wall(bezel, "skirt", skirt, t / 2)),
        Sheet(bezel_wall(bezel, "lip", lip), t, solid=bezel_wall(bezel, "lip", lip, t / 2)),
    ]
    clips = []
    for cx, cy in [(frame / 2, frame / 2), (L - frame / 2, frame / 2),
                   (frame / 2, H - frame / 2), (L - frame / 2, H - frame / 2)]:
        w, h, tab = rng.uniform(8, 12), rng.uniform(12, 18), rng.uniform(5, 8)
        sheets.append(Sheet(hook_part(bezel, cx, cy, w, h, tab), t))
        clips.append(dict(kind="hook", x=cx, y=cy, width=w, height=h, tab=tab))
    bx, by = L / 2, H - frame / 2
    sheets.append(Sheet(boss_part(bezel, bx, by, 5.0, rng.uniform(12, 18)), t))
    clips.append(dict(kind="boss", x=bx, y=by, radius=5.0))
    params = dict(seed=seed, inspired_by="molded bezel", length=L, height=H, frame=frame,
                  bow=bezel.bow, skirt=skirt, lip=lip, thickness=t, clips=clips)
    return Case(f"bezel_{seed:03d}", 8, "bezel", params, sheets, unify=False)


def floor_pan_sheet(a, b, h, bend, corner, revolved, holes):
    """Shallow drawn pan (floor at z = 0, walls up to h) with revolved floor
    features (x, y, cut radius, (r, z) profile, bend radius) and holes."""
    def build(occ):
        faces = tray(a, b, h, bend, corner)(occ)
        tools = [(2, occ.addDisk(x, y, 0, rc, rc)) for x, y, rc, _, _ in revolved]
        tools += [(2, occ.addDisk(x, y, 0, r, r)) for x, y, r in holes]
        if tools:
            faces, _ = occ.cut(faces, tools)
            faces = [dt for dt in faces if dt[0] == 2]
        for x, y, _, profile, radius in revolved:
            faces += translated(revolved_profile(profile, radius), x, y, 0)(occ)
        return faces
    return build


def floor_pan_case(seed):
    rng = random.Random(4000 + seed)
    a, b = rng.choice([(320, 240), (300, 260)])
    t, h, corner, margin = 3.0, rng.uniform(18, 26), rng.uniform(25, 40), rng.uniform(25, 35)
    revolved, features = [], []
    # Four conical bosses with a hole at the top, and a raised central pad.
    for fx, fy in [(0.25, 0.28), (0.75, 0.28), (0.25, 0.72), (0.75, 0.72)]:
        R, H = rng.uniform(24, 30), rng.uniform(12, 16)
        revolved.append((fx * a, fy * b, R, [(R, 0), (R * 0.45, H), (4.0, H)], 3.0))
        features.append(dict(kind="conical boss", x=fx * a, y=fy * b, radius=R, height=H))
    pad = rng.uniform(26, 32)
    revolved.append((0.5 * a, 0.5 * b, pad, [(pad, 0), (pad - 5, 5), (0, 5)], 3.0))
    features.append(dict(kind="raised pad", x=0.5 * a, y=0.5 * b, radius=pad))
    holes = [(0.5 * a, 0.12 * b, 4.0), (0.5 * a, 0.88 * b, 4.0)]
    pan = Sheet(floor_pan_sheet(a, b, h, 6, corner, revolved, holes), t,
                solid=floor_pan_sheet(a, b, h + t / 2, 6, corner, revolved, holes))
    flange = Sheet(framed_plate(a, b, margin, h, corner), t,
                   solid=translated(framed_plate(a - t, b - t, margin + t / 2, h, corner - t / 2),
                                    t / 2, t / 2, 0))
    sheets = [pan, flange]
    hr = rng.uniform(8, 12)
    rib = lambda x0, y0, x1, y1: Sheet(polygon([(x0, y0, 0), (x1, y1, 0), (x1, y1, hr),
                                                (x0, y0, hr)]), t)
    # Straight ribs between the bosses, clear of every revolved feature.
    sheets += [rib(0.06 * a, 0.5 * b, 0.36 * a, 0.5 * b), rib(0.64 * a, 0.5 * b, 0.94 * a, 0.5 * b),
               rib(0.5 * a, 0.06 * b, 0.5 * a, 0.3 * b), rib(0.5 * a, 0.7 * b, 0.5 * a, 0.94 * b),
               rib(0.08 * a, 0.06 * b, 0.08 * a, 0.18 * b), rib(0.92 * a, 0.82 * b, 0.92 * a, 0.94 * b)]
    # Short radial ribs around the pad.
    for k in range(8):
        ang = 2 * math.pi * k / 8 + math.pi / 8
        r0, r1 = pad + 4, pad + 16
        cx, cy = 0.5 * a, 0.5 * b
        sheets.append(rib(cx + r0 * math.cos(ang), cy + r0 * math.sin(ang),
                          cx + r1 * math.cos(ang), cy + r1 * math.sin(ang)))
    features.append(dict(kind="ribs", height=hr, straight=6, radial=8))
    params = dict(seed=seed, inspired_by="drawn floor pan", a=a, b=b, depth=h, corner=corner,
                  flange=margin, thickness=t, features=features)
    return Case(f"floor_pan_{seed:03d}", 8, "floor_pan", params, sheets)


class FlatPanel:
    """Flat rectangular plate [0, a] x [0, b] as a support for standing parts."""

    def __init__(self, a, b):
        self.a, self.b = a, b

    def build(self, occ):
        return plate(self.a, self.b)(occ)


def doghouse_case(fillet):
    """Look-alike of the Doghouse: one clip tower on a square plate, a holed
    rounded bridge and four ribs across its legs that stand above its top,
    with the thicknesses of the original (plate 3.4, bridge 1.4, ribs 1.25)."""
    base = FlatPanel(52, 52)
    w, d, h = 22.0, 24.0, 20.0
    sheets = [Sheet(base.build, 3.4),
              Sheet(doghouse_part(base, 26, 26, w, d, h, "bridge", hole=2.5), 1.4)]
    sheets += [Sheet(doghouse_part(base, 26, 26, w, d, h, f"rib {k}", hole=2.5, rib=3.5), 1.25)
               for k in range(4)]
    params = dict(plate=(52, 52), width=w, depth=d, height=h, rib=3.5, hole=2.5,
                  thickness=dict(plate=3.4, bridge=1.4, ribs=1.25), fillet=fillet)
    return Case(f"doghouse_r{fillet}", 8, "doghouse", params, sheets, junction_fillet=fillet)


def level8_cases(count=2):
    return ([strip_case(seed) for seed in range(count)] +
            [bezel_case(seed) for seed in range(count)] +
            [floor_pan_case(seed) for seed in range(count)] +
            [doghouse_case(r) for r in (0, 1)])


def all_cases():
    return (level1_cases() + level1b_cases() + level2_cases() + level2b_cases()
            + level3_cases() + level4_cases() + level5_cases() + level6_cases()
            + level7_cases() + level8_cases())


# ---------------------------------------------------------------------------
# Pipeline.


def compile_thicken(bin_dir: Path) -> Path:
    return compile_tool(bin_dir, "thicken_sheet")


def compile_tool(bin_dir: Path, name: str) -> Path:
    exe = bin_dir / name
    source = HERE / f"{name}.cpp"
    if exe.is_file() and exe.stat().st_mtime > source.stat().st_mtime:
        return exe
    occ = Path(os.environ.get("OCC_ROOT", "/opt/homebrew/opt/opencascade"))
    bin_dir.mkdir(parents=True, exist_ok=True)
    libs = ["TKernel", "TKMath", "TKG2d", "TKG3d", "TKGeomBase", "TKBRep",
            "TKGeomAlgo", "TKTopAlgo", "TKPrim", "TKBO", "TKShHealing", "TKBool",
            "TKOffset", "TKFillet", "TKMesh"]
    subprocess.run(["c++", "-std=c++17", "-O2", f"-I{occ}/include/opencascade",
                    str(source), "-o", str(exe), f"-L{occ}/lib",
                    f"-Wl,-rpath,{occ}/lib"] + [f"-l{lib}" for lib in libs],
                   check=True)
    return exe


def write_sheet(case_dir: Path, index, build) -> Path:
    gmsh.model.add(f"sheet{index}")
    surfaces = build(gmsh.model.occ)
    gmsh.model.occ.synchronize()
    if not surfaces:
        raise RuntimeError(f"sheet {index} has no surface")
    path = case_dir / f"sheet{index}.brep"
    gmsh.write(str(path))
    gmsh.model.remove()
    return path


def boundary(dim_tags):
    return sorted({t for _, t in gmsh.model.getBoundary(
        dim_tags, combined=False, oriented=False, recursive=False)})


def curve_midpoint(curve):
    lo, hi = gmsh.model.getParametrizationBounds(1, curve)
    return list(gmsh.model.getValue(1, curve, [0.5 * (lo[0] + hi[0])]))


def closest_on_face(surface, point):
    """Closest point of the trimmed face: (distance, parametric coordinates)."""
    q, uv = gmsh.model.getClosestPoint(2, surface, point)
    if gmsh.model.isInside(2, surface, list(uv), parametric=True):
        return math.dist(point, q), list(uv)
    best = None
    for c in boundary([(2, surface)]):
        qc, _ = gmsh.model.getClosestPoint(1, c, point)
        d = math.dist(point, qc)
        if best is None or d < best[0]:
            best = (d, qc)
    _, uv = gmsh.model.getClosestPoint(2, surface, best[1])
    return best[0], list(uv)


def crease_curve(curve, sheets):
    """Whether a junction curve of the fused solid runs along a crease of the
    mid-surface: two sheets joined edge to edge there (their free boundaries
    meet), rather than one sheet standing on the inside of another. A fillet
    on the inside of a crease alone would make the solid unsymmetric about
    the sheets, which would then no longer be its mid-surface."""
    p = curve_midpoint(curve)
    ends = []
    for faces, t in sheets:
        if min(closest_on_face(f, p)[0] for f in faces) > 2 * t:
            continue
        # Free boundary of the sheet: curves of one of its faces only.
        count = {}
        for f in faces:
            for c in boundary([(2, f)]):
                count[c] = count.get(c, 0) + 1
        best = None
        for c, n in count.items():
            if n != 1:
                continue
            q, _ = gmsh.model.getClosestPoint(1, c, p)
            d = math.dist(p, q)
            if best is None or d < best[0]:
                best = (d, q)
        if best is not None:
            ends.append((best[1], t))
    return any(math.dist(a, b) < 0.1 * min(ta, tb)
               for i, (a, ta) in enumerate(ends) for b, tb in ends[i + 1:])


def junction_curves(volume, solids):
    """Curves of the fused volume lying on the walls of two input solids."""
    walls = [boundary([(3, s)]) for s in solids]
    out = []
    for c in boundary([(2, s) for s in boundary([(3, volume)])]):
        p = curve_midpoint(c)
        normals = []
        for w in walls:
            for s in w:
                d, uv = closest_on_face(s, p)
                if d < 1e-6:
                    normals.append(gmsh.model.getNormal(s, uv))
                    break
        # On two solids, between walls that are not coplanar.
        if any(abs(sum(a * b for a, b in zip(n, m))) < 0.999
               for i, n in enumerate(normals) for m in normals[i + 1:]):
            out.append(c)
    return out


def face_samples(surface, count=16):
    """Up to `count` points of the face with their parametric coordinates,
    without meshing (Gmsh's 2D mesher can loop on some faces): the inside
    points of a parametric grid, plus points just inside each boundary curve
    (thin trimmed faces: annular sectors, fillets, slivers)."""
    lo, hi = gmsh.model.getParametrizationBounds(2, surface)
    samples = []
    n = 5
    for i in range(n):
        for j in range(n):
            uv = [lo[0] + (i + 0.5) / n * (hi[0] - lo[0]), lo[1] + (j + 0.5) / n * (hi[1] - lo[1])]
            if gmsh.model.isInside(2, surface, uv, parametric=True):
                samples.append((list(gmsh.model.getValue(2, surface, uv)), uv))
    center = [0.5 * (lo[0] + hi[0]), 0.5 * (lo[1] + hi[1])]
    for _, c in gmsh.model.getBoundary([(2, surface)], oriented=False):
        q = curve_midpoint(abs(c))
        _, uv = gmsh.model.getClosestPoint(2, surface, q)
        for step in (0.02, 0.1, 0.3):
            w = [uv[0] + step * (center[0] - uv[0]), uv[1] + step * (center[1] - uv[1])]
            if gmsh.model.isInside(2, surface, w, parametric=True):
                samples.append((list(gmsh.model.getValue(2, surface, w)), w))
                break
    if not samples:
        q, uv = gmsh.model.getClosestPoint(2, surface,
                                           gmsh.model.occ.getCenterOfMass(2, surface))
        samples.append((list(q), list(uv)))
    step = max(1, len(samples) // count)
    return samples[::step][:count]


SAMPLING_ALGORITHM = 6


def mesh_for_sampling(volume, thickness):
    gmsh.option.setNumber("Mesh.Algorithm", SAMPLING_ALGORITHM)
    gmsh.option.setNumber("Mesh.MeshSizeMax", 2.0 * thickness)
    gmsh.option.setNumber("Mesh.MeshSizeMin", 0.0)
    gmsh.model.mesh.clear()
    gmsh.model.mesh.generate(2)


def classify_faces(volume, sheets):
    """sheets: list of (surface tags, thickness). Role of every volume face."""
    roles = {}
    for surface in boundary([(3, volume)]):
        votes = {"skin": 0, "edge": 0, "fillet": 0}
        for p, uv in face_samples(surface):
            n = gmsh.model.getNormal(surface, uv)
            best = None
            for tags, thickness in sheets:
                for s in tags:
                    d, quv = closest_on_face(s, p)
                    if best is None or d < best[0]:
                        best = (d, s, quv, thickness)
            d, s, quv, thickness = best
            m = gmsh.model.getNormal(s, quv)
            cosine = abs(sum(a * b for a, b in zip(n, m)))
            if abs(d - 0.5 * thickness) < 0.02 * thickness and cosine > 0.995:
                votes["skin"] += 1
            elif cosine < 0.05 and d < 0.51 * thickness:
                votes["edge"] += 1
            else:
                votes["fillet"] += 1
        role = max(("fillet", "edge", "skin"), key=lambda k: votes[k])
        roles[surface] = dict(role=role, votes=votes,
                              area=gmsh.model.occ.getMass(2, surface))
    return roles


class quiet_stdout:
    """Silence OpenCASCADE's STEP writer, which prints on file descriptor 1."""

    def __enter__(self):
        sys.stdout.flush()
        self.saved = os.dup(1)
        null = os.open(os.devnull, os.O_WRONLY)
        os.dup2(null, 1)
        os.close(null)

    def __exit__(self, *exc):
        os.dup2(self.saved, 1)
        os.close(self.saved)


def remove_dangling(dim):
    """Remove the entities of dimension < dim that bound no entity of dim."""
    used = set()
    ents = gmsh.model.getEntities(dim)
    while ents and ents[0][0] > 0:
        ents = list(set(gmsh.model.getBoundary(ents, combined=False,
                                               oriented=False, recursive=False)))
        used.update(ents)
    free = [e for d in range(dim) for e in gmsh.model.getEntities(d) if e not in used]
    if free:
        gmsh.model.occ.remove(free)
    gmsh.model.occ.synchronize()


def thicken_all(case, case_dir, thicken):
    sheet_paths = [write_sheet(case_dir, i, s.build) for i, s in enumerate(case.sheets)]
    solid_paths = []
    for i, (path, sheet) in enumerate(zip(sheet_paths, case.sheets)):
        solid = case_dir / f"solid{i}.brep"
        if sheet.volume is not None:
            gmsh.model.add(f"volume{i}")
            sheet.volume(gmsh.model.occ)
            gmsh.model.occ.synchronize()
            gmsh.write(str(solid))
            gmsh.model.remove()
            solid_paths.append(solid)
            continue
        if sheet.solid is not None:
            path = write_sheet(case_dir, f"{i}_solid", sheet.solid)
        run = subprocess.run([str(thicken), str(path), repr(sheet.thickness), str(solid)],
                             capture_output=True, text=True)
        if run.returncode != 0:
            raise RuntimeError(f"thicken sheet {i}: {run.stderr.strip()}")
        solid_paths.append(solid)
        if sheet.solid is not None:
            path.unlink()
    return sheet_paths, solid_paths


def build_case(case: Case, out_root: Path, thicken: Path) -> dict:
    case_dir = out_root / case.name
    if case_dir.exists():
        shutil.rmtree(case_dir)
    case_dir.mkdir(parents=True)
    sheet_paths, solid_paths = thicken_all(case, case_dir, thicken)

    gmsh.model.add(case.name)
    occ = gmsh.model.occ
    solids = []
    for path in solid_paths:
        solids += [t for d, t in occ.importShapes(str(path)) if d == 3]
    sheets = []
    for path, sheet in zip(sheet_paths, case.sheets):
        sheets.append(([t for d, t in occ.importShapes(str(path)) if d == 2],
                       sheet.thickness))
    if len(solids) > 1:
        gmsh.option.setNumber("Geometry.OCCUnionUnify", 1 if case.unify else 0)
        out, _ = occ.fuse([(3, solids[0])], [(3, s) for s in solids[1:]],
                          removeObject=False, removeTool=False)
        volumes = [t for d, t in out if d == 3]
    else:
        volumes = [t for d, t in occ.copy([(3, solids[0])])]
    occ.synchronize()
    if len(volumes) != 1:
        raise RuntimeError(f"fusion gave {len(volumes)} volumes")
    volume = volumes[0]
    if case.junction_fillet > 0:
        # Not on the creases of sheets joined edge to edge (see crease_curve).
        curves = [c for c in junction_curves(volume, solids) if not crease_curve(c, sheets)]
        if curves:
            volume = occ.fillet([volume], curves, [case.junction_fillet])[0][1]
            occ.synchronize()
    occ.remove([(3, s) for s in solids], recursive=True)
    occ.synchronize()
    if case.free_edge_fillet > 0:
        roles = classify_faces(volume, sheets)
        # Round the edges between an end face and a skin, not the corners
        # between two end faces.
        skin = {c for s, info in roles.items() if info["role"] == "skin"
                for c in boundary([(2, s)])}
        curves = sorted({c for s, info in roles.items() if info["role"] == "edge"
                         for c in boundary([(2, s)])} & skin)
        volume = occ.fillet([volume], curves, [case.free_edge_fillet])[0][1]
        occ.synchronize()

    degenerate = [s for s in boundary([(3, volume)]) if not abs(occ.getMass(2, s)) > 1e-9]
    if degenerate:
        raise RuntimeError(f"degenerate (zero-area) faces in the solid: {degenerate}")
    roles = classify_faces(volume, sheets)
    volume_mass = occ.getMass(3, volume)
    expected = sum(t * occ.getMass(2, s) for tags, t in sheets for s in tags)
    if not 0.5 < volume_mass / expected < 1.1:
        raise RuntimeError(f"volume {volume_mass:.6g} is not close to the sum of "
                           f"area x thickness {expected:.6g}")
    sheet_area = sum(occ.getMass(2, s) for tags, _ in sheets for s in tags)
    sheet_volume = sum(t * occ.getMass(2, s) for tags, t in sheets for s in tags)
    occ.remove([(2, s) for tags, _ in sheets for s in tags], recursive=True)
    occ.synchronize()
    remove_dangling(3)
    gmsh.model.mesh.clear()
    if BSPLINE:
        # Same solid, every face and edge as a B-spline.
        analytic = case_dir / "analytic.brep"
        gmsh.write(str(analytic))
        gmsh.model.remove()
        converted = case_dir / "bspline.brep"
        run = subprocess.run([str(compile_tool(out_root / "bin", "nurbs_convert")),
                              str(analytic), str(converted)], capture_output=True, text=True)
        if run.returncode != 0:
            raise RuntimeError(f"B-spline conversion: {run.stderr.strip()}")
        gmsh.model.add(case.name + "_bspline")
        gmsh.model.occ.importShapes(str(converted))
        gmsh.model.occ.synchronize()
        analytic.unlink()
        converted.unlink()
    with quiet_stdout():
        gmsh.write(str(case_dir / f"{case.name}.stp"))
    gmsh.model.remove()

    # Mid-surface: the sheets, fragmented together so junctions are conformal.
    gmsh.model.add(case.name + "_midsurface")
    parts, thickness_of = [], {}
    for path, sheet in zip(sheet_paths, case.sheets):
        for dt in occ.importShapes(str(path)):
            if dt[0] == 2:
                parts.append(dt)
                thickness_of[dt] = sheet.thickness
    if len(parts) > 1:
        _, children = occ.fragment(parts[:1], parts[1:])
        thickness_of = {child: thickness_of[parent]
                        for parent, kids in zip(parts, children) for child in kids}
    occ.synchronize()
    remove_dangling(2)
    # Thickness of every mid-surface face, keyed by its center of mass (tags do
    # not survive a BREP round trip).
    midsurface_faces = [dict(center=list(occ.getCenterOfMass(*dt)), area=occ.getMass(*dt),
                             thickness=t) for dt, t in sorted(thickness_of.items())]
    gmsh.write(str(case_dir / f"{case.name}_midsurface.brep"))
    gmsh.model.remove()
    for path in sheet_paths + solid_paths:
        path.unlink()

    counts = {}
    for info in roles.values():
        counts[info["role"]] = counts.get(info["role"], 0) + 1
    meta = dict(name=case.name, level=case.level, family=case.family,
                params=case.params, thickness=[s.thickness for s in case.sheets],
                junction_fillet=case.junction_fillet,
                free_edge_fillet=case.free_edge_fillet,
                volume=volume_mass, midsurface_area=sheet_area,
                face_role_counts=counts, midsurface_faces=midsurface_faces,
                representation="bspline" if BSPLINE else "analytic",
                face_roles={str(k): v for k, v in sorted(roles.items())})
    # Volume over sum(area x thickness) of the sheets: 1 for a single sheet
    # without fillet, a check of the build; junction overlaps lower it.
    meta["volume_ratio"] = volume_mass / sheet_volume
    (case_dir / f"{case.name}.json").write_text(json.dumps(meta, indent=1) + "\n")
    return meta


def build_one(name: str, output: Path, fillet_scale: float = 1.0,
              sampling_algorithm: int = 6) -> int:
    """Worker: build one case in this process and print its summary as JSON."""
    global gmsh, BSPLINE, SAMPLING_ALGORITHM
    BSPLINE = "--bspline" in sys.argv
    SAMPLING_ALGORITHM = sampling_algorithm
    case = next(c for c in all_cases() if c.name == name)
    case.junction_fillet *= fillet_scale
    case.free_edge_fillet *= fillet_scale
    thicken = compile_thicken(output / "bin")
    gmsh = load_gmsh()
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    gmsh.option.setNumber("Geometry.OCCParallel", 0)
    try:
        meta = build_case(case, output, thicken)
        summary = {k: meta[k] for k in ("name", "level", "family", "thickness",
                                        "volume_ratio", "face_role_counts")}
        print("RESULT " + json.dumps(summary), flush=True)
        return 0
    except Exception as error:
        print("ERROR " + json.dumps(str(error)), flush=True)
        return 1
    finally:
        gmsh.finalize()


def run_worker(case, output: Path):
    """Build one case in a child process: an OpenCASCADE crash then fails that
    case only. OpenCASCADE fillets fail or crash on some configurations: retry
    with half the radii, then without fillet (the JSON records the radii)."""
    has_fillet = case.junction_fillet > 0 or case.free_edge_fillet > 0
    # The 2D mesher used to sample the faces can loop forever on a face: each
    # attempt has a time limit, and the next one switches to MeshAdapt.
    attempts = [(1.0, 6), (1.0, 1)] + ([(0.5, 6), (0.0, 6), (0.0, 1)] if has_fillet else [])
    errors = []
    for scale, algorithm in attempts:
        command = [sys.executable, str(Path(__file__).resolve()), "--worker", case.name,
                   "--output", str(output), "--fillet-scale", repr(scale),
                   "--sampling-algorithm", str(algorithm)] + (["--bspline"] if BSPLINE else [])
        try:
            run = subprocess.run(command, capture_output=True, text=True, errors="replace",
                                 timeout=WORKER_TIMEOUT)
        except subprocess.TimeoutExpired:
            errors.append(f"fillet x{scale}, mesher {algorithm}: timeout")
            continue
        error = None
        for line in run.stdout.splitlines():
            if line.startswith("RESULT "):
                summary = json.loads(line[7:])
                summary["fillet_scale"] = scale
                return summary, "; ".join(errors) or None
            if line.startswith("ERROR "):
                error = json.loads(line[6:])
        if error is None:
            error = (f"crashed with signal {-run.returncode}" if run.returncode < 0
                     else f"exit code {run.returncode}: {run.stderr.strip()[-200:]}")
        errors.append(f"fillet x{scale}, mesher {algorithm}: {error}")
    return None, "; ".join(errors)


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--output", type=Path, default=None,
                        help="default build/corpus, or build/corpus_bspline with --bspline")
    parser.add_argument("--bspline", action="store_true",
                        help="write the solids with all faces and edges as B-splines")
    parser.add_argument("--only", default="*", help="glob on case names")
    parser.add_argument("--level", type=int, default=0, help="only this level")
    parser.add_argument("--list", action="store_true")
    parser.add_argument("--jobs", type=int, default=max(1, (os.cpu_count() or 2) // 2))
    parser.add_argument("--worker", help=argparse.SUPPRESS)
    parser.add_argument("--fillet-scale", type=float, default=1.0, help=argparse.SUPPRESS)
    parser.add_argument("--sampling-algorithm", type=int, default=6, help=argparse.SUPPRESS)
    args = parser.parse_args()
    global BSPLINE
    BSPLINE = args.bspline
    if args.output is None:
        args.output = HERE.parents[1] / ("build/corpus_bspline" if BSPLINE else "build/corpus")
    if args.worker:
        return build_one(args.worker, args.output, args.fillet_scale, args.sampling_algorithm)
    cases = [c for c in all_cases() if fnmatch.fnmatch(c.name, args.only)
             and (args.level == 0 or c.level == args.level)]
    if args.list:
        for c in cases:
            print(f"{c.level} {c.family:16s} {c.name}")
        return 0
    compile_thicken(args.output / "bin")
    if BSPLINE:
        compile_tool(args.output / "bin", "nurbs_convert")
    args.output.mkdir(parents=True, exist_ok=True)
    with ThreadPoolExecutor(args.jobs) as pool:
        results = list(pool.map(lambda c: run_worker(c, args.output), cases))
    manifest = []
    for case, (summary, error) in zip(cases, results):
        if summary is None:
            print(f"FAIL {case.name:32s} {error}")
            shutil.rmtree(args.output / case.name, ignore_errors=True)
            continue
        manifest.append(summary)
        note = f"  fillets x{summary['fillet_scale']}" if summary["fillet_scale"] != 1 else ""
        print(f"ok   {case.name:32s} faces {summary['face_role_counts']} "
              f"V/(A t) {summary['volume_ratio']:.3f}{note}")
    # Keep the cases built earlier and not rebuilt now in the manifest.
    path = args.output / "manifest.json"
    names = {c.name for c in cases}
    if path.is_file():
        manifest += [m for m in json.loads(path.read_text()) if m["name"] not in names
                     and (args.output / m["name"]).is_dir()]
    order = {c.name: i for i, c in enumerate(all_cases())}
    manifest.sort(key=lambda m: order.get(m["name"], len(order)))
    path.write_text(json.dumps(manifest, indent=1) + "\n")
    failures = sum(summary is None for summary, _ in results)
    print(f"{len(cases) - failures} cases built, {failures} failed")
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
