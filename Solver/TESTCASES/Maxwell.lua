model = GModel  ()

model:load ('box_maxwell.geo')
model:load ('box_maxwell.msh')
dg = dgSystemOfEquations (model)
dg:setOrder(1)



function valueOutlet(xyz, f)
  for i=0,xyz:size1()-1 do
    X = xyz:get(i,0)
    Y = xyz:get(i,1)
    Z = xyz:get(i,2)
    VALUE1= math.sqrt(X*X+Y*Y)  
    f:set(i,0,0)
    f:set(i,1,0)
    f:set(i,2,0)
    f:set(i,3,0)
    f:set(i,4,0)
    f:set(i,5,0)
  end
end


function valueInlet(xyz, f)
  for i=0,xyz:size1()-1 do
    X = xyz:get(i,0)
    Y = xyz:get(i,1)
    Z = xyz:get(i,2)
    VALUE1= math.sqrt(X*X+Y*Y)
    f:set(i,0,0)
    f:set(i,2,0)
    f:set(i,1,0*math.exp(-50*(z^2)))
    f:set(i,3,0)
    f:set(i,4,0)
    f:set(i,5,0)
  end
end


mu_eps=fullMatrix(6,1)
mu_eps:set(0,0,1)
mu_eps:set(1,0,1)
mu_eps:set(2,0,1)
mu_eps:set(3,0,1)
mu_eps:set(4,0,1)
mu_eps:set(5,0,1)
law = dgConservationLawMaxwell(functionConstant(mu_eps):getName())
dg:setConservationLaw(law)


-- box-----
outletFunction=functionLua(6,'valueOutlet',{'XYZ'}):getName()
inletFunction=functionLua(6,'valueInlet',{'XYZ'}):getName()

law:addBoundaryCondition('wall',law:newBoundaryWall())
law:addBoundaryCondition('symmetry',law:newBoundaryWall())

law:addBoundaryCondition('inlet',law:newSymmetryBoundary())
law:addBoundaryCondition('outlet',law:newSymmetryBoundary())


dg:setup()

-- initial condition
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    f:set (i, 0,0)
    f:set (i, 1,0)
    f:set (i, 2,math.exp(-50*((x-0.3)^2+(y-0.3)^2)))
    f:set (i, 3,0) 
    f:set (i, 4,0*math.cos(math.pi*x)) 
    f:set (i, 5,0) 
  end
end
dg:L2Projection(functionLua(6,'initial_condition',{'XYZ'}):getName())

dg:exportSolution('output/MaxW-00000')

dt=0.00075
n=50

-- main loop
for i=1,3000 do
 norm =  dg:RK44(dt)  
  --t=t+dt
  if (i % n == 0) then 
    print('iter',i,norm)
    dg:exportSolution(string.format("output/MaxW-%05d",i)) 
  end
end
