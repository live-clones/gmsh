model = GModel  ()
model:load ('square.geo')
model:load ('square.msh')
dg = dgSystemOfEquations (model)
dg:setOrder(1)


-- conservation law
-- advection speed
law = dgConservationLawAdvectionDiffusion.diffusionLaw(functionConstant({0.01}))
dg:setConservationLaw(law)

-- boundary condition
law:addBoundaryCondition('Border',law:newOutsideValueBoundary(functionConstant({1})))
--law:addBoundaryCondition('Border',law:new0FluxBoundary())

dg:setup()

-- initial condition
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    f:set (i, 0, math.exp(-100*((x-0.2)^2 +(y-0.3)^2)))
  end
end
-- dg:L2Projection(functionLua(1,'initial_condition',{functionCoordinates.get()}))

dg:exportSolution('output/Diffusion_00000')

-- main loop
for i=1,100 do
  norm = dg:RK44(0.01)
  --norm = dg:RK44_TransformNodalValue(0.00001)
  if (i % 50 == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/Diffusion-%05d", i)) 
  end
end
