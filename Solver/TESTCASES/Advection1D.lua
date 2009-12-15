model = GModel  ()
model:load ('edge.geo')
--model:mesh (1)
--model:save ('edge_new.msh')
model:load ('edge_new.msh')
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
nu:set(0,0,0)

dg:setConservationLaw('AdvectionDiffusion',createFunction.constant(v),createFunction.constant(nu))

-- boundary condition
outside=fullMatrix(1,1)
outside:set(0,0,0.)
dg:addBoundaryCondition('Left','OutsideValues',createFunction.constant(outside))
dg:addBoundaryCondition('Right','OutsideValues',createFunction.constant(outside))

dg:setup()

-- initial condition
function initial_condition( _x , _f )
  xyz = fullMatrix(_x)    
  f = fullMatrix(_f)    
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    f:set (i, 0, math.exp(-100*((x+0.8)^2)))
  end
end
dg:L2Projection(createFunction.lua(1,'initial_condition','XYZ'))

dg:exportSolution('output/Adv1D_00000')

-- main loop
n = 5
for i=1,100*n do
  norm = dg:RK44(0.03)
  if (i % n == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/Adv1D-%05d", i)) 
  end
end
