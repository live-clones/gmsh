model = GModel()
-- model:load('tetrahedra.geo')
-- model:load('tetrahedra.msh')
model:load('prisms.geo')
model:load('prisms.msh')
-- model:load('mixed.geo')
-- model:load('mixed.msh')
order=2

-- initial condition
function initial_condition( xyz , f )
   for i=0,xyz:size1()-1 do
      x = xyz:get(i,0)
      y = xyz:get(i,1)
      z = xyz:get(i,2)
--       f:set (i, 0, math.exp(x+3*y))
      f:set (i, 0, math.exp(-20*((x-0.4)^2+(y-0.3)^2)))
   end
end

init_cond = functionLua(1, 'initial_condition', {functionCoordinates.get()})
gc=dgGroupCollection(model,3,order)
gc:buildGroupsOfInterfaces(model,2,order)
solution=dgDofContainer(gc,1)
solution:L2Projection(init_cond)
-- solution:setAll(3.0)
solution:exportMsh('sol3d.msh')

gc2D = gc:newByTag(model,2,order,{"top"})
solution2d=dgDofContainer(gc2D,1)
-- solution2d:L2Projection(init_cond)
solution2d:setAll(2.0)
solution2d:exportMsh('sol2d.msh')

print("** Build projection matrix **")
pm = dgMesh2MeshProjection(solution,solution2d)
print("** 3D->2D projection **")
pm:projectFromTo(solution,solution2d)
solution2d:exportMsh('proj3d2d.msh')
print("** 3D->2D copy **")
pm:copyFromTo(solution,solution2d)
solution2d:exportMsh('copy3d2d.msh')

print("** 2D->3D projection **")
solution2d:setAll(2.0)
pm:projectFromTo(solution2d,solution)
solution:exportMsh('proj2d3d.msh')
print("** 2D->3D copy **")
pm:copyFromTo(solution2d,solution)
solution:exportMsh('copy2d3d.msh')

-- raises error
-- pm:copyFromTo(solution,solution)
-- pm:copyFromTo(solution2d,solution2d)
