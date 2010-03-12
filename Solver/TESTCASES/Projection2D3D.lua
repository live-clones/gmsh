model = GModel()
-- model:load('tetrahedra.geo')
-- model:load('tetrahedra.msh')
model:load('prisms.geo')
model:load('prisms.msh')
-- model:load('mixed.geo')
-- model:load('mixed.msh')
order=1

-- initial condition
function initial_condition( xyz , f )
   for i=0,xyz:size1()-1 do
      x = xyz:get(i,0)
      y = xyz:get(i,1)
      z = xyz:get(i,2)
      f:set (i, 0, math.exp(-50*((x-0.5)^2+(y-0.5)^2)))
--       f:set (i, 0, math.exp(-50*((x-0.4)^2+(z+0.3)^2)))
   end
end

proj = linearSystemCSRGmmdouble()

init_cond = functionLua(1, 'initial_condition', {'XYZ'}):getName()
gc=dgGroupCollection(model,3,order)
solTmp=dgDofContainer(gc,1)
solTmp:L2Projection(init_cond)
gc:buildGroupsOfInterfaces(model,2,order)
solution=dgDofContainer(gc,1)
solution:L2Projection(init_cond)
solution:exportMsh('sol3d.msh')

gc2D = gc:newByTag(model,2,order,{"top"})
solution2d=dgDofContainer(gc2D,1)
--solution2d:L2Projection(init_cond)

solution2d:Mesh2Mesh_BuildL2Projection(proj,solution)
solution2d:Mesh2Mesh_ApplyL2Projection(proj,solution)
solution2d:exportMsh('sol2d.msh')

