model = GModel  ()
model:load ('square_supra.geo')
model:load ('square_supra.msh')
dg = dgSystemOfEquations (model)
dg:setOrder(1)


function diffusivity( sol , f )
  n=20
  c=1e-3
  for i=0,sol:size1()-1 do
    f:set (i, 0, sol:get(i,0)^(n-1)*n/c )
  end
end

law = dgConservationLawAdvectionDiffusion('',functionLua(1,'diffusivity',{'Solution'}):getName())
dg:setConservationLaw(law)

-- boundary condition
outsideLeft=fullMatrix(1,1)
outsideLeft:set(0,0,-1)
outsideRight=fullMatrix(1,1)
outsideRight:set(0,0,1)
law:addBoundaryCondition('Top',law:new0FluxBoundary())
law:addBoundaryCondition('Bottom',law:new0FluxBoundary())
leftFunction=functionConstant(outsideLeft):getName()
rightFunction=functionConstant(outsideRight):getName()
print(leftFunction)
print(rightFunction)
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

dg:exportSolution('output/Diffusion_00000')

-- main loop
for i=1,150000 do
  norm = dg:RK44_limiter(0.000005)
  if (i % 100 == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/Diffusion-%05d", i)) 
  end
end
