
--[[ 
     Function for initial conditions
--]]

function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    if (x>-0.3 and x<0.3) then
     f:set (i, 0, 1)
   else
     f:set (i, 0, 0)
    end	
  end
end

--[[ 
     Example of a lua program driving the DG code
--]]

model = GModel  ()
model:load ('edge.msh')
order=1
dimension=1

-- conservation law
-- advection speed
v=fullMatrix(3,1);
v:set(0,0,0.15)
v:set(1,0,0)
v:set(2,0,0)
-- diffusivity
nu=fullMatrix(1,1);
nu:set(0,0,0)

law = dgConservationLawAdvectionDiffusion(functionConstant(v):getName(), '') 

-- boundary condition
outside=fullMatrix(1,1)
outside:set(0,0,0.)
bndcondition=law:newOutsideValueBoundary(functionConstant(outside):getName())
law:addBoundaryCondition('Left',bndcondition)
law:addBoundaryCondition('Right',bndcondition)

groups = dgGroupCollection(model, dimension, order)
groups:buildGroupsOfInterfaces()

-- build Runge Kutta and limiter
rk=dgRungeKutta()
limiter = dgSlopeLimiter(law)
rk:setLimiter(limiter) 

-- build solution vector
FS = functionLua(1, 'initial_condition', {'XYZ'}):getName()
solution = dgDofContainer(groups, law:getNbFields())
solution:L2Projection(FS)

solution:exportMsh('output/init')
limiter:apply(solution)
solution:exportMsh('output/init_limit')

print'*** solve ***'
local x = os.clock()
dt = 0.03
for i=1,100 do
  norm = rk:iterate44(law,dt,solution)
   if (i % 20 == 0) then 
       print('|ITER|',i,'|NORM|',norm,'|DT|',dt,'|CPU|',os.clock() - x)
    end
    if (i % 200 == 0) then 
     solution:exportMsh(string.format('output/solution-%06d',i))
    end
end
