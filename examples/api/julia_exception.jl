import gmsh
gmsh.initialize()
gmsh.model.occ.addSphere(0,0,0,1)
gmsh.model.occ.synchronize()
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.5)
gmsh.model.mesh.generate(3)
gmsh.model.mesh.setOrder(2)

@time begin
    try
        e = gmsh.model.mesh.getElementByCoordinates(0.5,0,0) # ok
        #e = gmsh.model.mesh.getElementByCoordinates(2,0,0) # ko
    catch
        println("do something when the element is not found")
    end
end

gmsh.finalize()
