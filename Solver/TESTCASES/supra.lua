model = GModel  ()
model:load ('square_supra.geo')
model:load ('square_supra.msh')
dg = dgSystemOfEquations (model)
dg:setOrder(1)

c=1e-3
n=20
t=0
dt=1e-8
T=3e-4

function diffusivity( sol , f )
  for i=0,f:size1()-1 do
    f:set (i, 0, math.abs(sol:get(i,0))^(n-1)*n/c )
  end
end

function valueRight(f)
  for i=0,f:size1()-1 do
    f:set(i,0,math.sin(2*math.pi*t/T))
  end
end

function valueLeft(f)
  for i=0,f:size1()-1 do
    f:set(i,0,-math.sin(2*math.pi*t/T))
  end
end

law = dgConservationLawAdvectionDiffusion('',functionLua(1,'diffusivity',{'Solution'}):getName())
dg:setConservationLaw(law)

-- boundary condition
--[[
outsideLeft=fullMatrix(1,1)
outsideLeft:set(0,0,-1)
outsideRight=fullMatrix(1,1)
outsideRight:set(0,0,1)
--]]
law:addBoundaryCondition('Top',law:new0FluxBoundary())
law:addBoundaryCondition('Bottom',law:new0FluxBoundary())
leftFunction=functionLua(1,'valueLeft',{}):getName()
rightFunction=functionLua(1,'valueRight',{}):getName()
--[[
law:addBoundaryCondition('Left',law:newNeumannBoundary(leftFunction))
law:addBoundaryCondition('Right',law:newNeumannBoundary(rightFunction))
--]]
law:addBoundaryCondition('Left',law:newOutsideValueBoundary(leftFunction))
law:addBoundaryCondition('Right',law:newOutsideValueBoundary(rightFunction))

dg:setup()

-- initial condition
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    f:set (i, 0,0*math.exp(-100*((x-0.2)^2 +(y-0.3)^2)))
  end
end
dg:L2Projection(functionLua(1,'initial_condition',{'XYZ'}):getName())

dg:exportSolution('output/supra-00000')

-- main loop
for i=1,150000 do
  norm = dg:RK44_limiter(dt)
  t=t+dt
  if (i % 100 == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/supra-%05d", i)) 
  end
end
