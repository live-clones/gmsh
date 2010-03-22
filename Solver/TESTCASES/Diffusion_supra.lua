model = GModel  ()
model:load ('plaque_supra.geo')
model:load ('plaque_supra.msh')
dg = dgSystemOfEquations (model)
dg:setOrder(1)

Ec=1e-7
Jc=100 
mu0=4*math.pi*1e-10
c=mu0*Jc/Ec

Bmax = 1e-6/Ec
t=0
dt=1e-6


function diffusivity(f )
  for i=0,f:size1()-1 do
    f:set (i, 0, 1/c )
  end
end

function valueRight(f)
  for i=0,f:size1()-1 do
     f:set(i,0,Bmax)
  end
end

function valueLeft(f)
  for i=0,f:size1()-1 do
    f:set(i,0,Bmax)
  end
end



nu=fullMatrix(1,1);
nu:set(0,0,1/c)

-- conservation law
-- advection speed
law = dgConservationLawAdvectionDiffusion.diffusionLaw(functionLua(1,'diffusivity',{}))
dg:setConservationLaw(law)

law:addBoundaryCondition('Top',law:new0FluxBoundary())
law:addBoundaryCondition('Bottom',law:new0FluxBoundary())
leftFunction=functionLua(1,'valueLeft',{})
rightFunction=functionLua(1,'valueRight',{})


law:addBoundaryCondition('Right',law:newNeumannBoundary(rightFunction))
law:addBoundaryCondition('Left',law:newNeumannBoundary(leftFunction))
dg:setup()

-- initial condition
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    f:set (i, 0, 0*math.exp(-100*((x-0.2)^2 +(y-0.3)^2)))
  end
end

dg:L2Projection(functionLua(1,'initial_condition',{functionCoordinates.get()}))
dg:exportSolution('output/DiffusionSupra_00000')

-- main loop
for i=1,1000 do
 -- norm = dg:RK44(0.01)
  norm = dg:RK44_TransformNodalValue_limiter(0.00001)
  if (i % 50 == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/DiffusionSupra-%05d", i)) 
 end
t=t+dt
end
