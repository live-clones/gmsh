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
     f:set (i, 2, 0)	
    else
     f:set (i, 0, 5)
     f:set (i, 1, 0)
     f:set (i, 2, 0)	
    end	
  end
end

--[[ 
     Example of a lua program driving the DG code
--]]

model = GModel()
model:load ('rect2.msh')
order=1
dimension=2

-- boundary condition
law = dgConservationLawShallowWater2d()
law:addBoundaryCondition('Wall',law:newBoundaryWall())
law:addBoundaryCondition('Symmetry',law:newSymmetryBoundary())
law:setCoriolisFactor(functionConstant({0}))
law:setQuadraticDissipation(functionConstant({0}))
law:setLinearDissipation(functionConstant({0}))
law:setSource(functionConstant({0}))
law:setBathymetry(functionConstant({0}))

groups = dgGroupCollection(model, dimension, order)
groups:buildGroupsOfInterfaces()

rk=dgRungeKutta()
limiter = dgSlopeLimiter(law)
rk:setLimiter(limiter) 

-- build solution vector
xyz = functionCoordinates.get()
FS = functionLua(1, 'initial_condition', {xyz})
solution = dgDofContainer(groups, law:getNbFields())
solution:L2Projection(FS)

print'*** print initial sol ***'
--solution:exportMsh('output/init')
limiter:apply(solution)
solution:exportMsh('output/init_limit')

print'*** solve ***'
--dt = 0.00001;
CFL = 0.02;
for i=1,9000 do 
    dt = CFL * rk:computeInvSpectralRadius(law,solution);  
--  norm = rk:iterate44(law,dt,solution)
    norm = rk:iterateEuler(law,dt,solution)
    if (i % 100 == 0) then 
       print('|ITER|',i,'|NORM|',norm,'|DT|',dt,'|CPU|',os.clock() - x)
    end
    if (i % 100 == 0) then 
       solution:exportMsh(string.format('output/solution-%06d', i)) 
    end
end
