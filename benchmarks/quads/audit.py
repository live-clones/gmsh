# Independent audit of a surface quad/tri mesh against the CAD normal.
# usage: audit.py case.geo mesh.msh   (mesh written with -format msh2 -save_all)
# Reports per face the cells whose smallest corner sine, measured against the CAD
# normal at the cell centroid, is not positive (flipped or invalid), and the
# smallest sine. Mesh.* options are stripped so any Gmsh version can read the CAD.
import sys, math, collections, os, tempfile
import gmsh
geo, msh = sys.argv[1], sys.argv[2]
geo = os.path.abspath(geo)
with tempfile.NamedTemporaryFile("w", suffix=".geo", dir=os.path.dirname(geo), delete=False) as tmp:
    tmp.write("".join(l for l in open(geo) if not l.strip().startswith("Mesh.")))
gmsh.initialize(["-v","0"]); gmsh.open(tmp.name); os.unlink(tmp.name)
nodes = {}; elems = []
lines = open(msh).read().split("\n"); i = 0
while i < len(lines):
    if lines[i] in ("$Nodes","$ParametricNodes"):
        n = int(lines[i+1]); 
        for k in range(n):
            t = lines[i+2+k].split(); nodes[int(t[0])] = (float(t[1]),float(t[2]),float(t[3]))
        i += n+2
    elif lines[i] == "$Elements":
        n = int(lines[i+1])
        for k in range(n):
            t = lines[i+2+k].split(); ty = int(t[1]); nt = int(t[2])
            if ty in (2,3): elems.append((ty, int(t[4]), [int(x) for x in t[3+nt:]]))
        i += n+2
    else: i += 1
def sub(a,b): return (a[0]-b[0],a[1]-b[1],a[2]-b[2])
def cross(a,b): return (a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0])
def dot(a,b): return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]
def nrm(a): return math.sqrt(dot(a,a))
warped = collections.defaultdict(int)
ind = collections.Counter()  # industrial criteria, over the whole mesh
area = collections.defaultdict(float)  # mesh area of each face
stats = collections.defaultdict(lambda: [0,0,0,1.0, 0])  # sgn+ , sgn-, n, minq, tri
res = {}
for ty, tag, ids in elems:
    P = [nodes[j] for j in ids]; n = len(P)
    c = tuple(sum(p[d] for p in P)/n for d in range(3))
    try:
        par = gmsh.model.getParametrization(2, tag, list(c))
        ng = gmsh.model.getNormal(tag, par)
    except Exception: continue
    s = 1e9; sg = 0
    for k in range(n):
        a = sub(P[k],P[k-1]); b = sub(P[(k+1)%n],P[k]); cr = cross(a,b)
        v = dot(cr, ng)/(nrm(a)*nrm(b)+1e-300)
        s = min(s, v)
    if n == 4:  # largest angle between the normals of the two triangles, both diagonals
        def tn(a, b, c): return cross(sub(b, a), sub(c, a))
        w = 0.
        for d in (0, 1):
            u = tn(P[d], P[(d+1)%4], P[(d+2)%4]); v = tn(P[d], P[(d+2)%4], P[(d+3)%4])
            den = nrm(u)*nrm(v)
            w = max(w, 180. if den == 0 else math.degrees(math.acos(max(-1., min(1., dot(u, v)/den)))))
        warped[tag] += w > 25.
        ind['quads'] += 1
        ind['warp15'] += w > 15.
        edges = [nrm(sub(P[(k+1)%4], P[k])) for k in range(4)]
        ind['aspect5'] += max(edges) > 5.*min(edges)
        ang = [math.degrees(math.acos(max(-1., min(1., dot(sub(P[(k+1)%4], P[k]), sub(P[k-1], P[k]))/(edges[k]*edges[k-1]+1e-300))))) for k in range(4)]
        ind['angle<45'] += min(ang) < 45.
        ind['angle>135'] += max(ang) > 135.
    a2 = (0., 0., 0.)
    for k in range(1, n-1): a2 = tuple(x+y for x, y in zip(a2, cross(sub(P[k], P[0]), sub(P[k+1], P[0]))))
    area[tag] += nrm(a2)/2.
    st = stats[tag]; st[2] += 1; st[4] += (ty==2)
    if s > 0: st[0] += 1
    else: st[1] += 1
    st[3] = min(st[3], s)
for tag, st in sorted(stats.items()):
    pos, neg = st[0], st[1]
    print(f"face {tag}: cells={st[2]} tri={st[4]} orientedOK={pos} flipped/invalid={neg} minSine={st[3]:.3f} warped={warped[tag]}")
tri = sum(st[4] for st in stats.values()); cells = sum(st[2] for st in stats.values())
# A face much smaller than a cell is a CAD sliver (it has no room for a cell): its
# invalid cells are counted apart.
typical = sum(area.values())/max(cells, 1)
sliver = {t for t, a in area.items() if a < 0.05*typical}
real = sum(st[1] for t, st in stats.items() if t not in sliver)
tri_real = sum(st[4] for t, st in stats.items() if t not in sliver); cells_real = sum(st[2] for t, st in stats.items() if t not in sliver)
print(f"slivers: {len(sliver)} faces smaller than 0.05 cell, invalid cells {sum(st[1] for t, st in stats.items() if t in sliver)}, triangles {tri - tri_real}; other faces: invalid {real}, triangles {tri_real} of {cells_real} cells ({100.*tri_real/max(cells_real,1):.1f}%)")
q = max(ind['quads'], 1)
print(f"industrial: invalid_real={real} quads={ind['quads']} tri%={100.*tri/max(cells,1):.1f} angle<45={ind['angle<45']} angle>135={ind['angle>135']} "
      f"warp>15={ind['warp15']} aspect>5={ind['aspect5']} (quads %: {100.*ind['angle<45']/q:.1f} {100.*ind['angle>135']/q:.1f} {100.*ind['warp15']/q:.1f} {100.*ind['aspect5']/q:.1f})")
gmsh.finalize()
