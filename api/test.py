import gmsh

gmsh.initialize()
gmsh.open("square.msh")

model = gmsh.model

model.add("square")
factory = model.geo
factory.addPoint(0,0,0,0.1,1)
factory.addPoint(1,0,0,0.1,2)
factory.addPoint(1,1,0,0.1,3)
factory.addPoint(0,1,0,0.1,4)
factory.addLine(1,2,1)
factory.addLine(2,3,2)
factory.addLine(3,4,3)
line4 = factory.addLine(4,1,-1)
print("line4 received tag ", line4)
factory.addLineLoop([1,2,3,line4],1)
factory.addPlaneSurface([1],6)
factory.synchronize()

ptag = model.addPhysicalGroup(1,[1,2,3,4],-1)
ent = model.getEntitiesForPhysicalGroup(1,ptag)
print("new physical group ",ptag,":",ent, type(ent))

model.addPhysicalGroup(2,[6],-1)

print(gmsh.option.getString("General.BuildOptions"))
print(gmsh.option.getNumber("Mesh.Algorithm"))
gmsh.option.setNumber("Mesh.Algorithm", 3.0)
print(gmsh.option.getNumber("Mesh.Algorithm"))
model.mesh.generate(2)

gmsh.write("square.msh")

print("Entities")
entities = model.getEntities(-1)
for e in entities :
    print("entity ",e)
    types,tags,vertices = model.mesh.getElements(e[0],e[1])
    for i in range(len(types)):
        print("type ", types[i])
        print("tags : ", list(tags[i]))
        print("vertices : ", list(vertices[i]))

print("Vertices")
tags, coord, _ = model.mesh.getVertices(2,6)
print(tags)
print(coord)
gmsh.finalize()
