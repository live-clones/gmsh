# Parametric sheet-metal surface models for the QuadOpt test cases: a crash box
# (hat-section rail with trigger beads), a hood (outer panel and corrugated inner
# panel with cut-outs) and a wing box (skin, ribs with lightening holes, spars,
# stringers). Surfaces only (mid-surfaces), written as STEP next to this script.
#   python3 gen_industrial.py [crashbox hood wingbox]
import math
import os
import sys
import gmsh

occ = gmsh.model.occ
HERE = os.path.dirname(os.path.abspath(__file__))


def unit(v):
    n = math.sqrt(sum(c * c for c in v))
    return [c / n for c in v]


def filleted_wire(pts, radius, closed=False):
    """Polyline with a circular arc of the given radius at each interior corner
    (at every corner if closed). Returns a wire."""
    n = len(pts)
    cut = {}  # corner -> (tangent point before, tangent point after, arc center)
    for i in (range(n) if closed else range(1, n - 1)):
        p, a, b = pts[i], pts[i - 1], pts[(i + 1) % n]
        u = unit([a[k] - p[k] for k in range(3)])
        v = unit([b[k] - p[k] for k in range(3)])
        ang = math.acos(max(-1., min(1., sum(u[k] * v[k] for k in range(3)))))
        w = unit([u[k] + v[k] for k in range(3)])
        t, c = radius / math.tan(ang / 2.), radius / math.sin(ang / 2.)
        cut[i] = ([p[k] + u[k] * t for k in range(3)], [p[k] + v[k] * t for k in range(3)],
                  [p[k] + w[k] * c for k in range(3)])
    curves, last, first = [], None, None
    for i in range(n):
        if i in cut:
            a, b, c = (occ.addPoint(*q) for q in cut[i])
            if last is None:
                first = a
            else:
                curves.append(occ.addLine(last, a))
            curves.append(occ.addCircleArc(a, c, b))
            last = b
        else:
            tag = occ.addPoint(*pts[i])
            if last is None:
                first = tag
            else:
                curves.append(occ.addLine(last, tag))
            last = tag
    if closed:
        curves.append(occ.addLine(last, first))
    return occ.addWire(curves, checkClosed=closed)


def prism(wire, z0, height):
    face = occ.addPlaneSurface([wire])
    occ.translate([(2, face)], 0, 0, z0)
    out = occ.extrude([(2, face)], 0, 0, height)
    return [d for d in out if d[0] == 3]


# --------------------------------------------------------------------------
# Crash box: hat section (flanges, drafted walls, top) tapered along x, with two
# trigger beads.
# --------------------------------------------------------------------------
def crashbox():
    L, f, r, draft, t = 320., 18., 6., 5., 1.5
    # Uniformly spaced stations (a loft through unevenly spaced ones is badly
    # parametrized): linear taper, bead depth reduction at two places.
    stations = []
    for k in range(17):
        x = 20. * k
        stations.append((x, 30. + 10. * x / L, 52. + 10. * x / L,
                         7. if x in (60., 80., 160., 180.) else 0.))
    wires = []
    for x, hw, d, dent in stations:
        dd = d - dent
        pts = [(x, -hw - f, 0), (x, -hw, 0), (x, -hw + draft, dd), (x, hw - draft, dd),
               (x, hw, 0), (x, hw + f, 0)]
        wires.append(filleted_wire(pts, r))
    occ.addThruSections(wires, -1, False, False)
    return L


# --------------------------------------------------------------------------
# Hood: outer panel (double curvature) and inner panel (corrugated, big cut-outs,
# hinge holes), both trimmed to the same outline.
# --------------------------------------------------------------------------
def hood():
    L, W = 1100., 1300.

    def skin(x, y):
        s = x / L
        return 110. * s + 70. * (1. - 0.4 * s) * (1. - (2. * y / W) ** 2) - 90. * s ** 4

    def bead(x, y):
        edge = max(0., 1. - (abs(y) / (W * 0.46)) ** 6)  # no beads near the sides
        return 9. * edge * 0.5 * (1. + math.cos(2. * math.pi * y / 200.)) * min(1., x / 150.)

    xs = [L * k / 8. for k in range(9)]
    ys = [-W / 2. + W * k / 40. for k in range(41)]

    def panel(offset, corrugated):
        # A low-degree B-spline surface on a control grid: cheap to project on.
        pts = [occ.addPoint(x, y, skin(x, y) - offset - (bead(x, y) if corrugated else 0.))
               for y in ys for x in xs]
        return [(2, occ.addBSplineSurface(pts, len(xs), -1, 3, 3))]

    outer, inner = panel(0., False), panel(28., True)
    outline = [(-20, -W / 2 - 20, 0), (L + 20, -W / 2 * 0.82, 0),
               (L + 20, W / 2 * 0.82, 0), (-20, W / 2 + 20, 0)]
    trim = prism(filleted_wire(outline, 90., closed=True), -400, 800)
    outer = occ.intersect(outer, trim, removeObject=True, removeTool=False)[0]
    inner = occ.intersect(inner, trim, removeObject=True, removeTool=True)[0]
    # Cut-outs of the inner panel: three ellipses, hinge holes.
    tools = []
    for cx, cy, rx, ry in [(330, -300, 140, 120), (330, 300, 140, 120), (760, 0, 190, 230),
                           (80, -560, 18, 18), (80, 560, 18, 18), (150, -480, 14, 14),
                           (150, 480, 14, 14)]:
        disk = occ.addDisk(cx, cy, -400, max(rx, ry), min(rx, ry))
        if ry > rx:
            occ.rotate([(2, disk)], cx, cy, -400, 0, 0, 1, math.pi / 2.)
        tools += [d for d in occ.extrude([(2, disk)], 0, 0, 800) if d[0] == 3]
    occ.cut(inner, tools, removeObject=True, removeTool=True)
    return L


# --------------------------------------------------------------------------
# Wing box: ruled wing (taper, sweep, twist), skins, ribs with lightening holes,
# two spars, stringer blades on both skins; the surfaces are fragmented so that the
# assembly is conforming.
# --------------------------------------------------------------------------
def naca(m, p, t, xc, upper):
    yt = 5 * t * (0.2969 * math.sqrt(xc) - 0.1260 * xc - 0.3516 * xc ** 2 +
                  0.2843 * xc ** 3 - 0.1036 * xc ** 4)
    yc = m / p ** 2 * (2 * p * xc - xc ** 2) if xc < p else m / (1 - p) ** 2 * (1 - 2 * p + 2 * p * xc - xc ** 2)
    return yc + yt if upper else yc - yt


def wingbox():
    span = 3000.
    sections = [(0., 1200., 0., 0., 0., 0.), (span, 560., -3., 520., 0., 90.)]  # y, chord, twist, dx, ., dz

    def at(sec, xc, upper):
        y, chord, twist, dx, _, dz = sec
        z = naca(0.02, 0.4, 0.12, xc, upper) * chord
        px, pz = (xc - 0.25) * chord, z
        a = math.radians(twist)
        return (0.25 * chord + dx + px * math.cos(a) + pz * math.sin(a), y,
                dz - px * math.sin(a) + pz * math.cos(a))

    ks = [0.5 * (1. - math.cos(math.pi * i / 16.)) for i in range(17)]
    wires = []
    for sec in sections:
        top = [occ.addPoint(*at(sec, x, True)) for x in ks]
        bot = [occ.addPoint(*at(sec, x, False)) for x in ks]
        bot[0], bot[-1] = top[0], top[-1]
        wires.append(occ.addWire([occ.addSpline(top), occ.addSpline(bot)], checkClosed=True))
    wing = occ.addThruSections(wires, -1, True, True)[0][1]
    occ.synchronize()
    caps = []
    skins = []
    for _, tag in occ.getEntities(2):
        b = occ.getBoundingBox(2, tag)
        (caps if b[4] - b[1] < 50. else skins).append((2, tag))
    for d in caps:
        occ.remove([d])
    band_in = occ.copy([(3, wing)])
    occ.dilate(band_in, 0.25 * 1200., 0, 0, 0.97, 1., 0.6)
    band = occ.copy([(3, wing)])
    band = occ.cut(band, band_in, removeObject=True, removeTool=True)[0]

    def root_tip(f, upper=None):
        """Point at chord fraction f on the root and tip sections (mean line if None)."""
        out = []
        for sec in sections:
            if upper is None:
                a, b = at(sec, f, True), at(sec, f, False)
                out.append(tuple(0.5 * (a[k] + b[k]) for k in range(3)))
            else:
                out.append(at(sec, f, upper))
        return out

    def plate_through(a, b, vertical=True, pad=400.):
        """Large planar rectangle containing the segment a-b and the z direction."""
        d = [b[k] - a[k] for k in range(3)]
        s0, s1 = -100. / d[1], (span + 100.) / d[1]
        corners = [(a[0] + s0 * d[0], a[1] + s0 * d[1], a[2] + s0 * d[2] - pad),
                   (a[0] + s1 * d[0], a[1] + s1 * d[1], a[2] + s1 * d[2] - pad),
                   (a[0] + s1 * d[0], a[1] + s1 * d[1], a[2] + s1 * d[2] + pad),
                   (a[0] + s0 * d[0], a[1] + s0 * d[1], a[2] + s0 * d[2] + pad)]
        p = [occ.addPoint(*c) for c in corners]
        loop = occ.addWire([occ.addLine(p[i], p[(i + 1) % 4]) for i in range(4)],
                           checkClosed=True)
        return (2, occ.addPlaneSurface([loop]))

    parts = list(skins)
    # Spars at 25 % and 70 % of the chord, stringer blades on both skins.
    for f in (0.25, 0.70):
        a, b = root_tip(f)
        parts += occ.intersect([plate_through(a, b)], [(3, wing)], removeObject=True,
                               removeTool=False)[0]
    for f in (0.35, 0.47, 0.58, 0.82):
        a, b = root_tip(f)
        parts += occ.intersect([plate_through(a, b)], band, removeObject=True,
                               removeTool=False)[0]
    # Ribs every 500 mm, root and tip included, with three lightening holes.
    ribs = []
    for k in range(7):
        y = span * k / 6.
        rect = occ.addRectangle(-200, y, -400, 2200, 800)
        occ.rotate([(2, rect)], 0, y, 0, 1, 0, 0, math.pi / 2.)
        ribs += occ.intersect([(2, rect)], [(3, wing)], removeObject=True,
                              removeTool=False)[0]
    holes = []
    for f in (0.35, 0.47, 0.59):
        a, b = root_tip(f, None)
        d = [b[k] - a[k] for k in range(3)]
        t = 100. / span
        holes.append((3, occ.addCone(a[0] - t * d[0], a[1] - t * d[1], a[2] - t * d[2],
                                     d[0] * (1 + 2 * t), d[1] * (1 + 2 * t), d[2] * (1 + 2 * t),
                                     30. + 15. * t, 15. - 15. * t)))
    ribs = occ.cut(ribs, holes, removeObject=True, removeTool=True)[0]
    parts += ribs
    occ.remove([(3, wing)], recursive=True)
    occ.remove(band, recursive=True)
    occ.synchronize()
    alive = set(gmsh.model.getEntities(2))
    surfaces = [d for d in dict.fromkeys(parts) if d in alive]
    occ.fragment(surfaces, [])
    occ.synchronize()
    # Drop the slivers the intersections leave at the trailing edge.
    occ.remove([d for d in gmsh.model.getEntities(2) if occ.getMass(*d) < 100.])
    return span


if __name__ == "__main__":
    names = sys.argv[1:] or ["crashbox", "hood", "wingbox"]
    gmsh.initialize(["-v", "0"])
    for name in names:
        gmsh.model.add(name)
        globals()[name]()
        occ.synchronize()
        gmsh.write(os.path.join(HERE, name + ".stp"))
        print(name, "surfaces:", len(gmsh.model.getEntities(2)),
              "volumes:", len(gmsh.model.getEntities(3)))
        gmsh.model.remove()
    gmsh.finalize()
