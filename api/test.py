import gmsh

gmsh.Initialize()
gmsh.Open("square.msh")

gmsh.ModelCreate("square")
gmsh.ModelGeoAddPoint(0,0,0,0.1,1)
gmsh.ModelGeoAddPoint(1,0,0,0.1,2)
gmsh.ModelGeoAddPoint(1,1,0,0.1,3)
gmsh.ModelGeoAddPoint(0,1,0,0.1,4)
gmsh.ModelGeoAddLine(1,2,1)
gmsh.ModelGeoAddLine(2,3,2)
gmsh.ModelGeoAddLine(3,4,3)
line4 = gmsh.ModelGeoAddLine(4,1,-1)
print("line4 received tag ", line4)
gmsh.ModelGeoAddLineLoop([1,2,3,line4],1)
gmsh.ModelGeoAddPlaneSurface([1],6)
gmsh.ModelGeoSynchronize()

ptag = gmsh.ModelAddPhysicalGroup(1,[1,2,3,4],-1)
ent = gmsh.ModelGetEntitiesForPhysicalGroup(1,ptag)
print("new physical group ",ptag,":",ent, type(ent))

gmsh.ModelAddPhysicalGroup(2,[6],-1)

print(gmsh.OptionGetString("General.BuildOptions"))
print(gmsh.OptionGetNumber("Mesh.Algorithm"))
gmsh.OptionSetNumber("Mesh.Algorithm", 3.0)
print(gmsh.OptionGetNumber("Mesh.Algorithm"))
gmsh.ModelMesh(2)
gmsh.Export("square.msh")

print("Entities")
entities = gmsh.ModelGetEntities(-1)
for e in entities :
    print("entity ",e)
    types,tags,vertices = gmsh.ModelGetMeshElements(e[0],e[1])
    for i in range(len(types)):
        print("type ", types[i])
        print("tags : ", list(tags[i]))
        print("vertices : ", list(vertices[i]))


print("Vertices")
tags, coord, _ = gmsh.ModelGetMeshVertices(2,6)
print(tags)
print(coord)
gmsh.Finalize()
