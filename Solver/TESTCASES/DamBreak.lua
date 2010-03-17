--[[ 
     Function for initial conditions
--]]

function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    if (x<0.0) then
     f:set (i, 0, 40)
     f:set (i, 1, 0)
    else
     f:set (i, 0, 20)
     f:set (i, 1, 0)
    end	
  end
end

--[[ 
     Example of a lua program driving the DG code
--]]

model = GModel()
model:load ('edge.msh')
order=1
dimension=1

-- boundary condition
law = dgConservationLawShallowWater1d()
law:addBoundaryCondition('Left',law:newBoundaryWall())
law:addBoundaryCondition('Right',law:newBoundaryWall())

groups = dgGroupCollection(model, dimension, order)
groups:buildGroupsOfInterfaces()

claw = dgConservationLawShallowWater1d()
claw:addBoundaryCondition('Wall',law:newBoundaryWall())

rk=dgRungeKutta()
limiter = dgSlopeLimiter(law)
rk:setLimiter(limiter) 

-- build solution vector
xyz = functionCoordinates.get()
FS = functionLua(1, 'initial_condition', {xyz})
solution = dgDofContainer(groups, law:getNbFields())
solution:L2Projection(FS)

print'*** print initial sol ***'
solution:exportMsh('output/init')
limiter:apply(solution)
solution:exportMsh('output/init_limit')

print'*** solve ***'
--dt = 0.00001;
CFL = 1;
for i=1,1000 do 
    dt = CFL * rk:computeInvSpectralRadius(law,solution);  
--  norm = rk:iterate44(law,dt,solution)
    norm = rk:iterateEuler(law,dt,solution)
    if (i % 20 == 0) then 
       print('|ITER|',i,'|NORM|',norm,'|DT|',dt,'|CPU|',os.clock() - x)
    end
    if (i % 20 == 0) then 
       solution:exportMsh(string.format('output/solution-%06d', i)) 
    end
end
