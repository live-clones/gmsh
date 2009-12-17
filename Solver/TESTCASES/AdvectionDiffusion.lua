model = GModel  ()
model:load ('square.geo')
model:load ('square.msh')

model2 = GModel()
model2:load('')

vmodel = {GModel(),GModel()}
vmodel[1]:load('')
vmodel[2]:load('')

dg = dgSystemOfEquations (model)
dg:setOrder(1)

-- conservation law

-- advection speed
v=fullMatrix(3,1);
v:set(0,0,0.15)
v:set(1,0,0.05)
v:set(2,0,0)

-- diffusivity
nu=fullMatrix(1,1);
nu:set(0,0,0.001)

law = ConservationLawAdvection(FunctionConstant(v):getName(),FunctionConstant(nu):getName())
dg:setConservationLaw(law)

-- boundary condition
outside=fullMatrix(1,1)
outside:set(0,0,0.)
law:addBoundaryCondition('Border',law:newOutsideValueBoundary(FunctionConstant(outside):getName()))

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
dg:L2Projection(FunctionLua(1,'initial_condition',{'XYZ'}):getName())

dg:exportSolution('output/Advection_00000')

-- main loop
for i=1,10000 do
  norm = dg:RK44(0.01)
  if (i % 1 == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/Advection-%05d", i)) 
  end
end
