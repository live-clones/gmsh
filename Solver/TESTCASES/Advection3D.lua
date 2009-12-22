model = GModel  ()
model:load ('box.geo')
model:load ('box.msh')
dg = dgSystemOfEquations (model)
dg:setOrder(1)


-- conservation law
-- advection speed
v=fullMatrix(3,1);
v:set(0,0,0.15)
v:set(1,0,0)
v:set(2,0,0)
-- diffusivity
nu=fullMatrix(1,1);
nu:set(0,0,0.001)

--law = ConservationLawAdvection(functionConstant(v):getName(),functionConstant(nu):getName())
--law = ConservationLawAdvection('',functionConstant(nu):getName())
law = dgConservationLawAdvection(functionConstant(v):getName(),'')

dg:setConservationLaw(law)

-- boundary condition
outside=fullMatrix(1,1)
outside:set(0,0,1)
bndcondition=law:newOutsideValueBoundary(functionConstant(outside):getName())
--[[law:addBoundaryCondition('Left',bndcondition)
law:addBoundaryCondition('Right',bndcondition)
--]]

dg:setup()

-- initial condition
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    --y = xyz:get(i,1)
    --z = xyz:get(i,2)
    --f:set (i, 0, math.exp(-100*((x-0.5)^2)))
    f:set (i, 0, x )
  end
end
-- dg:L2Projection(functionLua(1,'initial_condition',{'XYZ'}):getName())

law:addBoundaryCondition('boundary',law:new0FluxBoundary())

dg:exportSolution('output/Adv3D_00000')

-- main loop
n = 5
for i=1,100*n do
  norm = dg:RK44(0.0003)
  if (i % n == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/Adv3D-%05d", i)) 
  end
end
