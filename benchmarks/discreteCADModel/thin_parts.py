# The most loaded assemblies of the MatGmsh synthetic thin-part corpus (level 6,
# tests/corpus/generate_corpus.py), rebuilt with boxes, cylinders and cones:
# the same random draws (seeds, sizes, positions), the thickened sheets as thin
# boxes, pipes and collars as differences of cylinders, dimples as differences
# of cones; no fillets nor bends (sharp corners), angles snapped to multiples of
# 90 degrees. Run with --separate for one file per assembly and kernel.
import math, random, sys

T = 4.0
H = T / 2


def assembly(seed):
    """The draws of generate_corpus.assembly_case(seed), in the same order."""
    rng = random.Random(seed)
    L, W, nx, ny = rng.choice([(300, 200, 3, 2), (400, 200, 4, 2), (360, 240, 3, 2),
                               (400, 300, 4, 3), (260, 260, 2, 2), (320, 320, 3, 3)])
    kind = "flanged" if rng.random() < 0.3 else "flat"
    fillet = rng.choice([0, 1, 2, 2])
    cw, ch = L / nx, W / ny
    R = 0.5 * min(cw, ch) - 10
    kinds = ["rib", "rib_gussets", "cross_ribs", "tee_ribs", "box", "pipe",
             "pipe_gussets", "channel", "angle", "holes", "collar", "dimple"]
    if kind == "flat":
        kinds.append("pocket")
    features = []
    for i in range(nx):
        for j in range(ny):
            if rng.random() < 0.15:
                continue
            c = ((i + 0.5) * cw, (j + 0.5) * ch)
            what = rng.choice(kinds)
            angle = rng.choice([0, 0.5 * math.pi, rng.uniform(0, math.pi)])
            f = dict(kind=what, c=c, angle=angle)
            if what in ("rib", "rib_gussets"):
                f["l"], f["h"] = rng.uniform(1.0, 1.9) * R, rng.uniform(12, 35)
                if what == "rib_gussets":
                    f["g"] = min(0.8 * f["h"], R - 6)
            elif what in ("cross_ribs", "tee_ribs"):
                f["l"], f["h"] = rng.uniform(1.2, 1.9) * R, rng.uniform(12, 30)
            elif what == "box":
                a, b = rng.uniform(0.6, 1.3) * R, rng.uniform(0.5, 1.0) * R
                scale = min(1.0, 2 * R / math.hypot(a, b))
                f["a"], f["b"] = a * scale, b * scale
                f["rc"], f["h"] = rng.uniform(5, 0.3 * min(f["a"], f["b"])), rng.uniform(15, 40)
            elif what in ("pipe", "pipe_gussets"):
                f["r"] = rng.uniform(8, min(25, 0.5 * R))
                f["h"] = rng.uniform(15, 45)
                if what == "pipe_gussets":
                    f["g"] = min(R - f["r"], 0.6 * f["h"])
                    f["n"] = rng.choice([3, 4])
            elif what in ("channel", "angle"):
                f["h"], f["w"] = rng.uniform(15, 30), rng.uniform(16, 30)
                f["l"] = rng.uniform(1.0, 1.7) * R
            elif what == "holes":
                n = rng.choice([1, 2, 3, 4])
                f["holes"] = []
                for k in range(n):
                    a = angle + k * 2 * math.pi / n
                    d = 0 if n == 1 else 0.5 * R
                    f["holes"].append((c[0] + d * math.cos(a), c[1] + d * math.sin(a),
                                       rng.uniform(3, 0.3 * R if n > 1 else 0.6 * R)))
            elif what == "collar":
                f["ri"] = rng.uniform(8, 0.5 * R)
                f["depth"] = rng.uniform(8, 15)
            elif what == "dimple":
                f["rd"] = rng.uniform(0.5, 0.9) * R
                f["depth"] = rng.uniform(5, 12)
            elif what == "pocket":
                a, b = rng.uniform(0.8, 1.3) * R, rng.uniform(0.6, 1.0) * R
                scale = min(1.0, 2 * R / math.hypot(a, b))
                f["a"], f["b"] = a * scale, b * scale
                f["rc"], f["d"] = rng.uniform(8, 0.35 * min(f["a"], f["b"])), rng.uniform(12, 25)
            features.append(f)
    return kind, L, W, R, features


def snap(x):
    """On a grid of 2^-10 mm: the bounds of boxes, their sums and differences
    exact, flush faces exactly coplanar."""
    return round(x * 1024.0) / 1024.0


class Part:
    def __init__(self, dx=0., dy=0., tag=0):
        self.lines, self.tag, self.dx, self.dy = [], tag, dx, dy
    def new(self):
        self.tag += 1
        return self.tag
    def box(self, lo, hi):
        lo = (lo[0] + self.dx, lo[1] + self.dy, lo[2])
        hi = (hi[0] + self.dx, hi[1] + self.dy, hi[2])
        lo, hi = [snap(x) for x in lo], [snap(x) for x in hi]
        t = self.new()
        self.lines.append("Box(%d) = {%.17g, %.17g, %.17g, %.17g, %.17g, %.17g};"
                          % (t, lo[0], lo[1], lo[2], hi[0] - lo[0], hi[1] - lo[1], hi[2] - lo[2]))
        return t
    def cylinder(self, x, y, z0, z1, r):
        x, y = x + self.dx, y + self.dy
        x, y, z0, z1 = snap(x), snap(y), snap(z0), snap(z1)
        t = self.new()
        self.lines.append("Cylinder(%d) = {%.17g, %.17g, %.17g, 0, 0, %.17g, %.17g};" % (t, x, y, z0, z1 - z0, r))
        return t
    def cone(self, x, y, z0, z1, r0, r1):
        x, y = x + self.dx, y + self.dy
        x, y, z0, z1 = snap(x), snap(y), snap(z0), snap(z1)
        t = self.new()
        self.lines.append("Cone(%d) = {%.17g, %.17g, %.17g, 0, 0, %.17g, %.17g, %.17g};" % (t, x, y, z0, z1 - z0, r0, r1))
        return t
    def difference(self, a, b):
        t = self.new()
        self.lines.append("BooleanDifference(%d) = { Volume{%d}; Delete; }{ Volume{%s}; Delete; };"
                          % (t, a, ", ".join(map(str, b))))
        return t


def local_box(part, f, lo, hi):
    """A box given in the frame of a feature: rotated by its angle snapped to
    a multiple of 90 degrees, translated to its center."""
    q = round(f["angle"] / (0.5 * math.pi)) % 4
    rot = lambda x, y: [(x, y), (-y, x), (-x, -y), (y, -x)][q]
    corners = [rot(x, y) for x in (lo[0], hi[0]) for y in (lo[1], hi[1])]
    xs, ys = [p[0] + f["c"][0] for p in corners], [p[1] + f["c"][1] for p in corners]
    return part.box((min(xs), min(ys), lo[2]), (max(xs), max(ys), hi[2]))


def assemblyGeo(seed, dx=0., dy=0., tag=0):
    """The .geo commands of an assembly, shifted by (dx, dy), its tags after
    tag; the resulting volume in the list part<seed>()."""
    kind, L, W, R, features = assembly(seed)
    part = Part(dx, dy, tag)
    if kind == "flat":
        base = part.box((0, 0, -H), (L, W, H))
    else:
        # the plate with its edges bent down (an upside-down tray, depth 15)
        outer = part.box((-H, -H, -15), (L + H, W + H, H))
        inner = part.box((H, H, -16), (L - H, W - H, -H))
        base = part.difference(outer, [inner])
    tools, cutters = [], []
    for f in features:
        k, c = f["kind"], f["c"]
        if k in ("rib", "rib_gussets", "tee_ribs", "cross_ribs"):
            l, h = f["l"], f["h"]
            tools.append(local_box(part, f, (-l / 2, -H, 0), (l / 2, H, h)))
            if k == "cross_ribs":
                tools.append(local_box(part, f, (-H, -l / 2, 0), (H, l / 2, h)))
            if k == "tee_ribs":
                tools.append(local_box(part, f, (-H, 0, 0), (H, 0.45 * l, h)))
            if k == "rib_gussets":
                # each gusset (a triangle of legs 0.8 h and g) as its largest
                # inscribed rectangle
                g = f["g"]
                for x in (-l / 4, l / 4):
                    tools.append(local_box(part, f, (x - H, 0, 0), (x + H, 0.5 * g, 0.4 * h)))
        elif k == "box":
            a, b, h = f["a"], f["b"], f["h"]
            outer = local_box(part, f, (-a / 2 - H, -b / 2 - H, 0), (a / 2 + H, b / 2 + H, h))
            inner = local_box(part, f, (-a / 2 + H, -b / 2 + H, -1), (a / 2 - H, b / 2 - H, h + 1))
            tools.append(part.difference(outer, [inner]))
        elif k in ("pipe", "pipe_gussets"):
            r, h = f["r"], f["h"]
            outer = part.cylinder(c[0], c[1], 0, h, r + H)
            inner = part.cylinder(c[0], c[1], -1, h + 1, r - H)
            tools.append(part.difference(outer, [inner]))
            if k == "pipe_gussets":
                g = f["g"]
                for m in range(f["n"]):
                    q = dict(f, angle=f["angle"] + m * 0.5 * math.pi)
                    tools.append(local_box(part, q, (r, -H, 0), (r + 0.5 * g, H, 0.35 * h)))
        elif k in ("channel", "angle"):
            h, w, l = f["h"], f["w"], f["l"]
            if k == "channel":
                for x in (-w / 2, w / 2):
                    tools.append(local_box(part, f, (x - H, -l / 2, 0), (x + H, l / 2, h + H)))
                tools.append(local_box(part, f, (-w / 2 - H, -l / 2, h - H), (w / 2 + H, l / 2, h + H)))
            else:
                tools.append(local_box(part, f, (-H, -l / 2, 0), (H, l / 2, h + H)))
                tools.append(local_box(part, f, (-H, -l / 2, h - H), (w, l / 2, h + H)))
        elif k == "holes":
            for x, y, r in f["holes"]:
                cutters.append(part.cylinder(x, y, -20, 20, r))
        elif k == "collar":
            ri, d = f["ri"], f["depth"]
            tools.append(part.cylinder(c[0], c[1], -d, H, ri + H))
            cutters.append(part.cylinder(c[0], c[1], -d - 1, H + 1, ri - H))
        elif k == "dimple":
            # a conical dish: flat bottom of radius 0.4 rd at the depth, wall
            # up to 0.8 rd; the offsets of its mid-surface cone by t / 2
            rd, d = f["rd"], f["depth"]
            s = 0.4 * rd / d
            off = H * math.sqrt(1 + s * s)
            mid = lambda z: 0.8 * rd + s * z
            tools.append(part.cone(c[0], c[1], -d - H, H, mid(-d - H) + off, mid(H) + off))
            cutters.append(part.cone(c[0], c[1], -d + H, H + 1, mid(-d + H) - off, mid(H + 1) - off))
        elif k == "pocket":
            a, b, d = f["a"], f["b"], f["d"]
            tools.append(local_box(part, f, (-a / 2 - H, -b / 2 - H, -d - H), (a / 2 + H, b / 2 + H, H)))
            cutters.append(local_box(part, f, (-a / 2 + H, -b / 2 + H, -d + H), (a / 2 - H, b / 2 - H, H + 1)))
    out = ["// assembly %d: %s base %gx%g, %s" % (seed, kind, L, W,
                                                   ", ".join(f["kind"] for f in features))]
    out += part.lines
    out.append("part%d() = BooleanUnion{ Volume{%d}; Delete; }{ Volume{%s}; Delete; };"
               % (seed, base, ", ".join(map(str, tools))))
    if cutters:
        out.append("part%d() = BooleanDifference{ Volume{part%d()}; Delete; }{ Volume{%s}; Delete; };"
                   % (seed, seed, ", ".join(map(str, cutters))))
    return out


HEADER = ["// The most loaded assemblies of the MatGmsh synthetic thin-part corpus",
          "// (level 6), rebuilt with the discrete CAD modeler: boxes, cylinders, cones",
          "// and exact boolean operations (generated by thin_parts.py)"]


if __name__ == "__main__":
    # all the assemblies on a grid in thin_parts.geo, or each one in its own
    # files for both kernels (--separate: assembly_<seed>.geo and
    # assembly_<seed>_occ.geo)
    args = sys.argv[1:]
    separate = "--separate" in args
    seeds = [int(a) for a in args if a.isdigit()] or [50, 64, 61, 25, 92, 88, 65, 99, 27, 84]
    if separate:
        for seed in seeds:
            for factory, suffix in (("Discrete", ""), ("OpenCASCADE", "_occ")):
                out = HEADER + ['SetFactory("%s");' % factory, "Geometry.DiscreteTolerance = 1e-3;"]
                out += assemblyGeo(seed) + ["Mesh.MeshSizeMax = 5;"]
                open("assembly_%03d%s.geo" % (seed, suffix), "w").write("\n".join(out) + "\n")
    else:
        out = HEADER + ['SetFactory("Discrete");', "Geometry.DiscreteTolerance = 1e-3;"]
        for k, seed in enumerate(seeds):
            out += assemblyGeo(seed, 450 * (k % 5), -380 * (k // 5), 1000 * (k + 1))
        out += ["Mesh.MeshSizeMax = 5;"]
        open("thin_parts.geo", "w").write("\n".join(out) + "\n")
