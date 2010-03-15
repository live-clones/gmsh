
model = GModel()
model:load('box.geo')
model:load('box.msh')
dg = dgSystemOfEquations(model)
dg:setOrder(1)

-- initial condition
function initial_condition(xyz ,f)
   for i=0,xyz:size1()-1 do
      x = xyz:get(i,0)
      y = xyz:get(i,1)
      z = xyz:get(i,2)
      --f:set (i, 0, math.exp(-100*((x-0.5)^2)))
      --f:set (i, 0, x )
      f:set (i, 0, math.sqrt((x-0.3)*(x-0.3)+(y-0.3)*(y-0.3)+z*z)-0.2)	
      --f:set(i, 0, math.exp((x-.3)*(x-.3)+(y-.3)*(y-.3)+z*z)-.2))
   end
end

-- conservation law
-- advection speed
law = dgConservationLawAdvectionDiffusion.advectionLaw(functionConstant({0,0,0.15}))
dg:setConservationLaw(law)

-- boundary condition
--freestreem=law:newOutsideValueBoundary(functionConstant({0,0,0.15}))

xyz = functionCoordinates.get()
freestream=law:newOutsideValueBoundary(functionLua(1,'initial_condition',{functionCoordinates:get()}))

law:addBoundaryCondition('wall',law:new0FluxBoundary())
law:addBoundaryCondition('inlet',freestream)
law:addBoundaryCondition('outlet',law:newSymmetryBoundary())
law:addBoundaryCondition('symmetry',law:newSymmetryBoundary())

dg:setup()

dg:L2Projection(functionLua(1,'initial_condition',{xyz}))
dg:exportSolution('output/Adv3D-00000')

print'***exporting init solution ***'

-- main loop
n = 10
for i=1,100*n do
  norm = dg:RK44(0.03)
  if (i % n == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/Adv3D-%05d", i)) 
  end
end
