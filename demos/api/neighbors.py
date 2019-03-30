import gmsh

# small example showing how one could use the api to compute neighboring
# tetetradra (connected by a triangular face)

gmsh.initialize()

gmsh.model.add("my test model");
gmsh.model.occ.addBox(0,0,0, 1,1,1);
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(3)

# get tets and faces
tets, _ = gmsh.model.mesh.getElementsByType(4)
faces = gmsh.model.mesh.getElementFaceNodes(4, 3)

# compute face x tet incidence
fxt = {}
for i in range(0, len(faces), 3):
    f = tuple(sorted(faces[i:i+3]))
    t = tets[i/12]
    if not f in fxt:
        fxt[f] = [t]
    else:
        fxt[f].append(t)

# compute neighbors by face
txt = {}
for i in range(0, len(faces), 3):
    f = tuple(sorted(faces[i:i+3]))
    t = tets[i/12]
    if not t in txt:
        txt[t] = set()
    for tt in fxt[f]:
        if tt != t:
            txt[t].add(tt)

print("neighbors by face: ", txt)

gmsh.finalize()
