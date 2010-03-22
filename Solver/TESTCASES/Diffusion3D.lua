model = GModel()
-- model:load('tetrahedra.geo')
-- model:load('tetrahedra.msh')
-- model:load('prisms.geo')
-- model:load('prisms.msh')
model:load('mixed.geo')
model:load('mixed.msh')
dg = dgSystemOfEquations(model)
dg:setOrder(2)

-- initial condition
function initial_condition( xyz , f )
   for i=0,xyz:size1()-1 do
      x = xyz:get(i,0)
      y = xyz:get(i,1)
      z = xyz:get(i,2)
      f:set (i, 0, math.exp(-50*((x-0.4)^2+(y-0.3)^2)))
--       f:set (i, 0, math.exp(-50*((x-0.4)^2+(z+0.3)^2)))
   end
end

-- conservation law

law = dgConservationLawAdvectionDiffusion:diffusionLaw(functionConstant({0.1}))
dg:setConservationLaw(law)

law:addBoundaryCondition('side1',law:new0FluxBoundary())
law:addBoundaryCondition('side2',law:new0FluxBoundary())
law:addBoundaryCondition('side3',law:new0FluxBoundary())
law:addBoundaryCondition('side4',law:new0FluxBoundary())
law:addBoundaryCondition('top',law:newSymmetryBoundary())
law:addBoundaryCondition('bottom',law:newSymmetryBoundary())

dg:setup()

--dg:L2Projection(functionLua(1,'initial_condition',{'XYZ'}))

dt = 0.0001
--CFL = 20 -- good for lc=0.1 mesh
CFL = 1
-- dt = CFL*dg:computeInvSpectralRadius()
-- export_interval = 5*dt
export_interval = 0.05
end_time = 3
output_dir = 'output'
output_prefix = 'diff3d'
output_pattern = output_dir .. '/' .. output_prefix .. '-'


-- main loop
next_export_time = export_interval
export_count = 0
io.write(string.format('Export: %d iter: %4d t: %.6f n: %.8f dt:%.8f\n',export_count,0,0,0,dt))
dg:exportSolution(output_pattern .. string.format("%05d",export_count))
for i=1,10000 do
--   dt = CFL*dg:computeInvSpectralRadius()
  norm = dg:RK44(dt)
  time = i*dt
  io.write('.')
  io.flush()
--     io.write('\n')
--     io.write(string.format('Export: %d iter: %4d t: %.6f n: %.8f dt:%.8f\n',export_count,i,time,norm,dt))
  if (time >= next_export_time) then
    export_count = export_count +1
    io.write('\n')
    io.write(string.format('Export: %d iter: %4d t: %.6f n: %.8f dt:%.8f\n',export_count,i,time,norm,dt))
    dg:exportSolution(output_pattern .. string.format("%05d",export_count)) 
    next_export_time = next_export_time + export_interval
  end
  if time >= end_time then
    break
  end
end
