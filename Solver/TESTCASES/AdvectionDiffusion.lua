model = GModel  ()
model:load ('square.geo')
model:load ('square.msh')

dg = dgSystemOfEquations (model)
dg:setOrder(4)

-- conservation law
law = dgConservationLawAdvectionDiffusion(functionConstant({0.15,0.05,0}),functionConstant({0.001}))
dg:setConservationLaw(law)

-- boundary condition
law:addBoundaryCondition('Border',law:newOutsideValueBoundary(functionConstant({0,0,0})))

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
dg:L2Projection(functionLua(1,'initial_condition',{functionCoordinates.get()}))

dg:exportSolution('output/Advection_00000')

-- main loop
for i=1,10000 do
  norm = dg:RK44(0.001)
  if (i % 10 == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/Advection-%05d", i)) 
  end
end
