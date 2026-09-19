# Generates the mesh and view files of the graphics tests that cannot be
# written as .geo scripts:
#
#   elements_o<k>.msh: conforming patches of every element type (points,
#     lines, triangles, quadrangles, tetrahedra, hexahedra, prisms, pyramids
#     and a trihedron), at order k = 1, 2 (complete), 2i (incomplete) and 3
#     (no prisms), the high-order nodes moved off the straight elements
#   views_o<k>.msh: scalar, vector and tensor node, element and element-node
#     data on them (in this order, 1, 3 and 9 components), to merge after
#     the mesh
#   lists.pos: the same first order elements as list-based views, scalar,
#     vector and tensor, with 2D and 3D strings, and a 2D graph
#   polytopes.msh: polygons (agglomerated triangles with interior nodes, and
#     polygons given by their boundary, one of them not convex) and polyhedra
#     (a stack of hexagonal prisms sharing faces, and a cube with given
#     tetrahedra); polytopes_views.msh: the same data as views_o<k>.msh on
#     them
#
# Run by run.py into its output directory, or by hand with the Python API of
# the build to test: python3 generate.py [output directory]

import gmsh
import math
import os
import sys

TENSOR = lambda x, y, z: [1 + x, 0.2 * y, 0, 0.2 * y, 1 + y, 0, 0, 0, 0.5 + z]
VECTOR = lambda x, y, z: [y - 0.5, 0.5 - x, 0.3 * z]
SCALAR = lambda x, y, z: math.sin(3 * x) * math.cos(2 * y) + z


def patches(prisms=True):
    occ = gmsh.model.occ
    # 1D and 2D: a curve and two surfaces, triangles and quadrangles
    occ.addLine(occ.addPoint(0, -1, 0), occ.addPoint(1, -1, 0))
    occ.addPoint(1.5, -1, 0)
    occ.addRectangle(0, 0, 0, 1, 1)
    q = occ.addRectangle(1.5, 0, 0, 1, 1)
    # 3D: tetrahedra next to hexahedra (pyramids in between), prisms
    t = occ.addBox(0, 2, 0, 1, 1, 1)
    h = occ.addBox(1, 2, 0, 1, 1, 1)
    occ.fragment([(3, t)], [(3, h)])
    if prisms: # not at order 3
        p = occ.addRectangle(3, 2, 0, 1, 1)
        occ.extrude([(2, p)], 0, 0, 1, [2], recombine=True)
    occ.synchronize()
    m = gmsh.model.mesh
    gmsh.option.setNumber("Mesh.MeshSizeMax", 0.35)
    gmsh.model.mesh.setRecombine(2, q)
    hexa = gmsh.model.getEntitiesInBoundingBox(0.9, 1.9, -0.1, 2.1, 3.1, 1.1, 3)
    for d, e in gmsh.model.getBoundary(hexa, False, False, True):
        if d == 1: m.setTransfiniteCurve(e, 3)
    for d, e in gmsh.model.getBoundary(hexa, False, False, False):
        m.setTransfiniteSurface(e)
        m.setRecombine(2, e)
    m.setTransfiniteVolume(hexa[0][1])
    m.generate(3)
    # a point element on the lone point, and a trihedron in a volume of its
    # own
    pt = [e for d, e in gmsh.model.getEntities(0)
          if abs(gmsh.model.getValue(0, e, [])[0] - 1.5) < 1e-9][0]
    tags, _, _ = m.getNodes(0, pt)
    m.addElementsByType(pt, 15, [], tags)
    r = gmsh.model.addDiscreteEntity(3)
    n = int(m.getMaxNodeTag())
    m.addNodes(3, r, [n + 1, n + 2, n + 3, n + 4],
               [5, 2, 0, 6, 2, 0, 6, 3, 0.2, 5, 3, 0])
    m.addElementsByType(r, 140, [], [n + 1, n + 2, n + 3, n + 4])


def curve():
    # the nodes that are not corners are moved: the elements are curved
    corners = set()
    et, el, en = gmsh.model.mesh.getElements()
    for t, ids, nodes in zip(et, el, en):
        nn = len(nodes) // len(ids)
        npri = 4 if t == 140 else gmsh.model.mesh.getElementProperties(t)[5]
        for k in range(len(ids)):
            corners.update(nodes[k * nn:k * nn + npri])
    tags, xyz, _ = gmsh.model.mesh.getNodes()
    for i, t in enumerate(tags):
        if t in corners: continue
        x, y, z = xyz[3 * i:3 * i + 3]
        gmsh.model.mesh.setNode(t, [x, y, z + 0.08 * math.sin(4 * x + 3 * y)],
                                [])


def polytopes():
    m = gmsh.model.mesh
    # polygons agglomerated from the triangles of a square, which are their
    # sub-triangulation (their interior nodes stay nodes of the polygons)
    gmsh.model.add("triangles")
    gmsh.model.occ.addRectangle(0, 0, 0, 2, 1)
    gmsh.model.occ.synchronize()
    gmsh.option.setNumber("Mesh.MeshSizeMax", 0.12)
    m.generate(2)
    nodeTags, coord, _ = m.getNodes()
    xyz = {nodeTags[i]: coord[3 * i:3 * i + 3] for i in range(len(nodeTags))}
    triTags, triNodes = m.getElementsByType(2)
    groups = {}
    for i in range(len(triTags)):
        n = list(triNodes[3 * i:3 * i + 3])
        bx = sum(xyz[k][0] for k in n) / 3
        by = sum(xyz[k][1] for k in n) / 3
        groups.setdefault((math.floor(bx / 0.4), math.floor(by / 0.4)),
                          []).append(n)
    gmsh.model.remove()

    def loop(triangles):
        # the boundary of oriented triangles as one loop of nodes, or None
        edges = set()
        for n in triangles:
            for a, b in ((n[0], n[1]), (n[1], n[2]), (n[2], n[0])):
                edges.add((a, b))
        nxt = {}
        for a, b in edges:
            if (b, a) not in edges:
                if a in nxt: return None
                nxt[a] = b
        if not nxt: return None
        l = [next(iter(nxt))]
        while nxt.get(l[-1]) not in (None, l[0]):
            l.append(nxt[l[-1]])
        return l if len(l) == len(nxt) and nxt.get(l[-1]) == l[0] else None

    gmsh.model.add("polytopes")
    s = gmsh.model.addDiscreteEntity(2)
    m.addNodes(2, s, nodeTags, coord)
    polyNodes, polyNumNodes, simplices, numSimplices, rest = [], [], [], [], []
    for key in sorted(groups):
        l = loop(groups[key])
        if l is None:
            rest += [k for n in groups[key] for k in n]
            continue
        polyNodes += l
        polyNumNodes.append(len(l))
        simplices += [k for n in groups[key] for k in n]
        numSimplices.append(len(groups[key]))
    m.addPolygons(s, [], polyNodes, polyNumNodes)
    tags, _, _ = m.getPolygons(s)
    m.setPolytopeSimplices(tags, numSimplices, simplices)
    if rest: m.addElementsByType(s, 2, [], rest)

    # polygons given by their boundary only (triangulated when needed): a
    # hexagon and a non-convex L
    n0 = int(m.getMaxNodeTag()) + 1
    s2 = gmsh.model.addDiscreteEntity(2)
    pts = []
    for i in range(6):
        a = i * math.pi / 3
        pts += [0.5 + 0.4 * math.cos(a), -1 + 0.4 * math.sin(a), 0]
    pts += [1.2, -1.4, 0, 2, -1.4, 0, 2, -1.1, 0, 1.5, -1.1, 0, 1.5, -0.6, 0,
            1.2, -0.6, 0]
    m.addNodes(2, s2, list(range(n0, n0 + 12)), pts)
    m.addPolygons(s2, [], list(range(n0, n0 + 12)), [6, 6])

    # a stack of three hexagonal prisms sharing their hexagons
    n0 = int(m.getMaxNodeTag()) + 1
    r = gmsh.model.addDiscreteEntity(3)
    pts, ntags = [], []
    for k in range(4):
        for i in range(6):
            a = i * math.pi / 3
            pts += [3.5 + 0.6 * math.cos(a), 0.5 + 0.6 * math.sin(a), 0.5 * k]
            ntags.append(n0 + 6 * k + i)
    m.addNodes(3, r, ntags, pts)
    node = lambda k, i: n0 + 6 * k + i % 6
    numFaces, faceSizes, faces = [], [], []
    for k in range(3):
        numFaces.append(8)
        faceSizes += [6, 6] + [4] * 6
        faces += [node(k, i) for i in range(5, -1, -1)]
        faces += [node(k + 1, i) for i in range(6)]
        for i in range(6):
            faces += [node(k, i), node(k, i + 1), node(k + 1, i + 1),
                      node(k + 1, i)]
    m.addPolyhedra(r, [], numFaces, faceSizes, faces)

    # a cube as a polyhedron, with its tetrahedra given
    n0 = int(m.getMaxNodeTag()) + 1
    r2 = gmsh.model.addDiscreteEntity(3)
    c = [(0, 0, 0), (1, 0, 0), (1, 1, 0), (0, 1, 0), (0, 0, 1), (1, 0, 1),
         (1, 1, 1), (0, 1, 1)]
    m.addNodes(3, r2, list(range(n0, n0 + 8)),
               [v for p in c for v in (5 + 0.8 * p[0], 0.1 + 0.8 * p[1],
                                       0.8 * p[2])])
    q = [[0, 3, 2, 1], [4, 5, 6, 7], [0, 1, 5, 4], [1, 2, 6, 5], [2, 3, 7, 6],
         [3, 0, 4, 7]]
    m.addPolyhedra(r2, [], [6], [4] * 6, [n0 + i for f in q for i in f])
    tags, _, _, _ = m.getPolyhedra(r2)
    tets = [[0, 1, 3, 4], [1, 2, 3, 6], [1, 4, 5, 6], [3, 4, 6, 7],
            [1, 3, 4, 6]]
    m.setPolytopeSimplices(tags, [5], [n0 + i for t in tets for i in t])
    gmsh.write("polytopes.msh")
    views("polytopes")
    for i, v in enumerate(gmsh.view.getTags()):
        gmsh.view.write(v, "polytopes_views.msh", append=(i > 0))
    for v in gmsh.view.getTags(): gmsh.view.remove(v)
    gmsh.model.remove()


def views(name):
    tags, xyz, _ = gmsh.model.mesh.getNodes()
    pts = [xyz[3 * i:3 * i + 3] for i in range(len(tags))]
    for comp, f in ((1, SCALAR), (3, VECTOR), (9, TENSOR)):
        v = gmsh.view.add("%s node data %d" % (name, comp))
        data = [f(*p) if comp > 1 else [f(*p)] for p in pts]
        gmsh.view.addModelData(v, 0, "", "NodeData", tags, data)
        et, el, en = gmsh.model.mesh.getElements()
        ev, eids, envals, enids = [], [], [], []
        for t, ids, nodes in zip(et, el, en):
            for k, e in enumerate(ids):
                # (the nodes of a polytope vary in number)
                enodes = gmsh.model.mesh.getElement(e)[1]
                nn = len(enodes)
                c = [0., 0., 0.]
                vals = []
                for j in range(nn):
                    x, y, z = gmsh.model.mesh.getNode(enodes[j])[0]
                    c = [c[0] + x / nn, c[1] + y / nn, c[2] + z / nn]
                    # discontinuous: depends on the element
                    s = f(x + 0.1 * (e % 3), y, z)
                    vals += s if comp > 1 else [s]
                eids.append(e)
                ev.append(f(*c) if comp > 1 else [f(*c)])
                enids.append(e)
                envals.append(vals)
        v = gmsh.view.add("%s element data %d" % (name, comp))
        gmsh.view.addModelData(v, 0, "", "ElementData", eids, ev)
        v = gmsh.view.add("%s element node data %d" % (name, comp))
        gmsh.view.addModelData(v, 0, "", "ElementNodeData", enids, envals)


def lists():
    # one list per first order element type and number of components
    names = {15: "P", 1: "L", 2: "T", 3: "Q", 4: "S", 5: "H", 6: "I", 7: "Y"}
    for comp, pre, f in ((1, "S", SCALAR), (3, "V", VECTOR), (9, "T", TENSOR)):
        v = gmsh.view.add("list %s" % pre)
        et, el, en = gmsh.model.mesh.getElements()
        for t, ids, nodes in zip(et, el, en):
            if t not in names: continue
            nn = len(nodes) // len(ids)
            data = []
            for k in range(len(ids)):
                p = [gmsh.model.mesh.getNode(nodes[k * nn + j])[0]
                     for j in range(nn)]
                for c in range(3):
                    data += [p[j][c] for j in range(nn)]
                for j in range(nn):
                    s = f(*p[j])
                    data += s if comp > 1 else [s]
            gmsh.view.addListData(v, pre + names[t], len(ids), data)
    v = gmsh.view.add("strings")
    gmsh.view.addListDataString(v, [0.5, 0.5, 1.2], ["3D string"])
    gmsh.view.addListDataString(v, [20, -20], ["2D string"])
    # drawn as a 2D graph with View.Type = 2 (not saved in the file)
    v = gmsh.view.add("graph")
    n = 40
    data = [i / n for i in range(n + 1)] + [0] * (n + 1) + [0] * (n + 1) + \
        [math.sin(6 * i / n) for i in range(n + 1)]
    gmsh.view.addListData(v, "SP", n + 1,
                          [x for i in range(n + 1) for x in
                           (data[i], 0, 0, data[3 * (n + 1) + i])])


if len(sys.argv) > 1: os.chdir(sys.argv[1])
gmsh.initialize(readConfigFiles=False)
gmsh.option.setNumber("General.Terminal", 1)
for order, incomplete, suffix in ((1, 0, "1"), (2, 0, "2"), (2, 1, "2i"),
                                  (3, 0, "3")):
    gmsh.model.add("elements")
    patches(order < 3)
    gmsh.option.setNumber("Mesh.SecondOrderIncomplete", incomplete)
    gmsh.model.mesh.setOrder(order)
    if order > 1: curve()
    gmsh.write("elements_o%s.msh" % suffix)
    views("o" + suffix)
    for i, v in enumerate(gmsh.view.getTags()):
        gmsh.view.write(v, "views_o%s.msh" % suffix, append=(i > 0))
    if order == 1:
        for v in gmsh.view.getTags(): gmsh.view.remove(v)
        lists()
        for i, v in enumerate(gmsh.view.getTags()):
            gmsh.view.write(v, "lists.pos", append=(i > 0))
    for v in gmsh.view.getTags(): gmsh.view.remove(v)
    gmsh.model.remove()
polytopes()
gmsh.finalize()
