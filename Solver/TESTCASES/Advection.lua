model = GModel  ()
model:load ('square.geo')
model:load ('square.msh')
dg = dgSystemOfEquations (model)
dg:setOrder(1)


-- conservation law
-- advection speed
v=fullMatrix(3,1);
v:set(0,0,0.15)
v:set(1,0,0.05)
v:set(2,0,0)
dg:setConservationLaw('AdvectionDiffusion',createFunction.constant(v))

-- boundary condition
outside=fullMatrix(1,1)
outside:set(0,0,0.)
dg:addBoundaryCondition('Border','OutsideValues',createFunction.constant(outside))

dg:setup()

-- initial condition
function initial_condition( _x , _f )
  xyz = fullMatrix(_x)    
  f = fullMatrix(_f)    
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    f:set (i, 0, math.exp(-100*((x-0.2)^2 +(y-0.3)^2)))
  end
end
dg:L2Projection(createFunction.lua(1,'initial_condition','XYZ'))

dg:exportSolution('output/Advection_00000')

-- main loop
for i=1,800 do
  norm = dg:RK44(0.01)
  if (i % 10 == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/Advection-%05d", i)) 
  end
end
