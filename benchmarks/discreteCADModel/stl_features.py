# What the discrete CAD import recovers from STL files: OpenCASCADE geometries
# (and those of the .geo files given as arguments) are meshed, written as a
# single STL solid (without their surfaces), possibly with their nodes moved
# randomly (-noise amplitude, relative to the mesh size), imported with
# gmsh.model.discrete.importShapes, and the recovered curves compared with the
# OpenCASCADE ones, classified by the angle between the outward normals of
# their two surfaces: the fraction of the sharp ones (at least the import
# angle), the weak ones (at least half of it), the faint ones and the tangent
# ones (recovered by the recognition of analytic surfaces) along which a
# recovered curve runs, and the fraction of the recovered curves along an
# OpenCASCADE one.
#
# python3 stl_features.py [file.geo ...] [-size h/diagonal] [-noise amplitude]

import gmsh
import math
import os
import sys
import tempfile
import numpy as np

pi = math.pi
angle = 40 * pi / 180


def geometries():
    g = {}

    def box(m):
        m.addBox(0, 0, 0, 4, 2, 1)
    g["box"] = box

    def chamfered(m):
        b = m.addBox(0, 0, 0, 4, 2, 1)
        m.synchronize()
        curves = [c for _, c in m.getEntities(1)]
        m.chamfer([b], curves,
                  [gmsh.model.getAdjacencies(1, c)[0][0] for c in curves],
                  [0.25])
    g["chamfered box"] = chamfered

    def filleted(m):
        b = m.addBox(0, 0, 0, 4, 2, 1)
        m.synchronize()
        m.fillet([b], [c for _, c in m.getEntities(1)], [0.25])
    g["filleted box"] = filleted

    def roof(m):
        # a shallow roof: a 30 degree ridge
        h = math.tan(15 * pi / 180)
        p = [m.addPoint(*q) for q in
             [(0, 0, 0), (2, 0, 0), (2, 1, 0), (1, 1 + h, 0), (0, 1, 0)]]
        lines = [m.addLine(p[i], p[(i + 1) % 5]) for i in range(5)]
        m.extrude([(2, m.addPlaneSurface([m.addCurveLoop(lines)]))], 0, 0, 3)
    g["shallow roof"] = roof

    def drilled(m):
        tools = []
        for x, y in [(1, 1), (3, 1), (5, 1), (1, 3), (3, 3), (5, 3)]:
            tools.append((3, m.addCylinder(x, y, -1, 0, 0, 3, 0.3)))
            tools.append((3, m.addCone(x, y, 0.5, 0, 0, 0.31, 0.3, 0.6)))
        m.cut([(3, m.addBox(0, 0, 0, 6, 4, 0.8))], tools)
    g["drilled plate"] = drilled

    def tpipe(m):
        t, _ = m.fuse([(3, m.addCylinder(-3, 0, 0, 6, 0, 0, 1))],
                      [(3, m.addCylinder(0, 0, 0, 0, 0, 3, 0.7))])
        m.cut(t, [(3, m.addCylinder(-4, 0, 0, 8, 0, 0, 0.8)),
                  (3, m.addCylinder(0, 0, 0, 0, 0, 4, 0.5))])
    g["T pipe"] = tpipe

    def flange(m):
        t, _ = m.fuse([(3, m.addCylinder(0, 0, 0, 0, 0, 0.3, 2))],
                      [(3, m.addCylinder(0, 0, 0.3, 0, 0, 1, 0.8))])
        t, _ = m.cut(t, [(3, m.addCylinder(0, 0, -1, 0, 0, 3, 0.5))])
        t, _ = m.cut(t, [(3, m.addCylinder(1.4 * math.cos(a), 1.4 * math.sin(a),
                                           -1, 0, 0, 3, 0.2))
                         for a in [k * pi / 3 for k in range(6)]])
        chamfer, _ = m.cut([(3, m.addCylinder(0, 0, 1, 0, 0, 0.3, 1))],
                           [(3, m.addCone(0, 0, 1, 0, 0, 0.3, 0.8, 0.6))])
        m.cut(t, chamfer)
    g["flange"] = flange

    def sphere(m):
        m.intersect([(3, m.addSphere(0, 0, 0, 1))],
                    [(3, m.addBox(-0.7, -2, -0.6, 1.4, 4, 1.4))])
    g["cut sphere"] = sphere

    def torus(m):
        m.cut([(3, m.addTorus(0, 0, 0, 1, 0.35))],
              [(3, m.addBox(-2, -2, -1, 4, 2, 2))])
    g["cut torus"] = torus
    return g


def sample(dim, tag, step):
    lo, hi = gmsh.model.getParametrizationBounds(dim, tag)
    p = np.array(gmsh.model.getValue(dim, tag, np.linspace(lo[0], hi[0], 21)))
    length = np.sum(np.linalg.norm(np.diff(p.reshape(-1, 3), axis=0), axis=1))
    t = np.linspace(lo[0], hi[0], max(21, int(length / step) + 1))
    return np.array(gmsh.model.getValue(dim, tag, t)).reshape(-1, 3)


def nearest(p, q):
    # the distance of each point of p to the nearest point of q
    d = np.empty(len(p))
    for i in range(0, len(p), 512):
        d[i:i + 512] = np.min(np.linalg.norm(
            p[i:i + 512, None, :] - q[None, :, :], axis=2), axis=1)
    return d


def run(name, build, size, noise, directory):
    gmsh.model.add("truth")
    if isinstance(build, str):
        gmsh.merge(build)
    else:
        build(gmsh.model.occ)
    gmsh.model.occ.synchronize()
    b = gmsh.model.getBoundingBox(-1, -1)
    h = size * math.sqrt(sum((b[k + 3] - b[k]) ** 2 for k in range(3)))
    tolerance = 0.3 * h
    surfaces = len(gmsh.model.getEntities(2))
    # the curves, with the angle between the outward normals of their two
    # surfaces (none for seams)
    sign = {}
    for _, v in gmsh.model.getEntities(3):
        for _, s in gmsh.model.getBoundary([(3, v)], oriented=True):
            sign.setdefault(abs(s), 1 if s > 0 else -1)
    truth = []
    for _, c in gmsh.model.getEntities(1):
        up, _ = gmsh.model.getAdjacencies(1, c)
        a = None
        if len(up) == 2 and up[0] != up[1]:
            lo, hi = gmsh.model.getParametrizationBounds(1, c)
            a = 0.
            for f in (0.37, 0.61):
                p = gmsh.model.getValue(1, c, [lo[0] + f * (hi[0] - lo[0])])
                n = [np.array(gmsh.model.getNormal(
                    s, gmsh.model.getParametrization(2, s, p))) * sign.get(s, 1)
                     for s in up]
                a = max(a, math.acos(max(-1, min(1, float(
                    np.dot(n[0], n[1]) / np.linalg.norm(n[0]) /
                    np.linalg.norm(n[1]))))))
        truth.append((a, sample(1, c, tolerance / 3)))
    gmsh.option.setNumber("Mesh.MeshSizeMax", h)
    gmsh.model.mesh.generate(2)
    if noise:
        tags, coord, _ = gmsh.model.mesh.getNodes()
        rng = np.random.default_rng(12345)
        coord = coord + noise * h * rng.uniform(-1, 1, len(coord))
        for i, t in enumerate(tags):
            gmsh.model.mesh.setNode(t, coord[3 * i:3 * i + 3], [])
    stl = os.path.join(directory, "part.stl")
    gmsh.write(stl)
    gmsh.model.remove()

    gmsh.model.add("import")
    gmsh.logger.start()
    verbosity = gmsh.option.getNumber("General.Verbosity")
    gmsh.option.setNumber("General.Verbosity", 5)
    try:
        gmsh.model.discrete.importShapes(stl, angle)
        gmsh.model.discrete.synchronize()
        error = None
    except Exception as e:
        error = str(e)
    gmsh.option.setNumber("General.Verbosity", verbosity)
    recognized = [l.split(": ", 2)[2].split(" recognized")[0]
                  for l in gmsh.logger.get() if "recognized" in l]
    gmsh.logger.stop()
    if error:
        gmsh.model.remove()
        print("%-15s import failed: %s" % (name, error))
        return
    # the recovered curves, except the seams (on a single surface)
    recovered, embedded = [], 0
    for _, c in gmsh.model.getEntities(1):
        up, _ = gmsh.model.getAdjacencies(1, c)
        if len(up) == 1:
            continue
        if len(up) == 0:
            embedded += 1
        recovered.append(sample(1, c, tolerance / 3))
    ours = len(gmsh.model.getEntities(2))
    gmsh.model.remove()
    allRecovered = np.vstack(recovered) if recovered else np.zeros((0, 3))

    def recall(cls):
        p = [q for a, q in truth if a is not None and cls(a)]
        if not p:
            return "  -  "
        if not len(allRecovered):
            return " 0.00"
        return "%5.2f" % np.mean(nearest(np.vstack(p), allRecovered) <= tolerance)
    precision = "  -  "
    if len(allRecovered):
        precision = "%5.2f" % np.mean(nearest(
            allRecovered, np.vstack([q for _, q in truth])) <= tolerance)
    print("%-15s %4d/%-4d %s %s %s %s %s %3d  %s" % (
        name, ours, surfaces, recall(lambda a: a >= angle),
        recall(lambda a: angle / 2 <= a < angle),
        recall(lambda a: 1e-3 < a < angle / 2), recall(lambda a: a <= 1e-3),
        precision, embedded, recognized[0] if recognized else ""))


size, noise, files = 1 / 40., 0., []
args = iter(sys.argv[1:])
for a in args:
    if a == "-size":
        size = float(next(args))
    elif a == "-noise":
        noise = float(next(args))
    else:
        files.append(a)
gmsh.initialize()
gmsh.option.setNumber("General.Verbosity", 1)
print("mesh size %g x diagonal, noise %g x mesh size" % (size, noise))
print("%-15s %9s %5s %5s %5s %5s %5s %3s  %s" % (
    "geometry", "surfaces", "sharp", "weak", "faint", "tang.", "prec.", "emb",
    "recognized"))
cases = list(geometries().items()) + [(os.path.basename(f), f) for f in files]
with tempfile.TemporaryDirectory() as directory:
    for name, build in cases:
        run(name, build, size, noise, directory)
gmsh.finalize()
