--[[ 
     Function for initial conditions
--]]


x = os.clock()
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
     f:set (i, 0, 3.14)
     f:set (i, 1, 0)
  end
end

PI = 3.14159
T= 0.05
t=0
Amax = 3.15

function inlet( FCT )
  FCT:set(0,0,Amax*math.sin(2*PI*t/T)*atan(1000*(T/2-t)) 
  FCT:set(0,1, 0) 
end

--[[
function pressureLawShallowWater (solution, bathymetry, f)
  for i=0,f:size1()-1 do
     f:set (i, 0, bathymetry:get(i,0))
  end
end
--]]

xyz = functionCoordinates.get()

--[[ 
     Example of a lua program driving the DG code
--]]

order=2
options = gmshOptions()
model = GModel()
model:load ('aorta.geo')
options:numberSet('Mesh',-1,'ElementOrder',order)
model:mesh(1)
model:save('aorta.msh')
dimension=1

-- boundary condition
inlet_bc = functionLua(2, 'inlet')
law = dgConservationLawShallowWater1d()
law:addBoundaryCondition('Inlet',law:newOutsideValueBoundary(inlet_bc))
law:addBoundaryCondition('Outlet',law:newBoundaryWall())
bathymetry = functionConstant({0})
law:setBathymetry(bathymetry)
--law:setPressureLaw(functionLua(1,'pressureLaw',{functionSolution.get(), bathymetry}))
law:setLinearDissipation(functionConstant({0}))

groups = dgGroupCollection(model, dimension, order)
groups:buildGroupsOfInterfaces()

rk=dgRungeKutta()
limiter = dgSlopeLimiter(law)

print'*** print projetion ***'
-- build solution vector
FS = functionLua(2, 'initial_condition', {xyz})
solution = dgDofContainer(groups, law:getNbFields())
solution:L2Projection(FS)

print'*** print initial sol ***'
solution:exportMsh('output/init')

print'*** solve ***'
--dt = 0.00001;
CFL = 0.2;
for i=1,9000 do 
    dt = CFL * rk:computeInvSpectralRadius(law,solution);  
    t = t+dt
    norm = rk:iterate44(law,dt,solution)
    if (i % 100 == 0) then 
       print('|ITER|',i,'|NORM|',norm,'|DT|',dt,'|CPU|',os.clock() - x)
    end
    if (i % 100 == 0) then 
       solution:exportMsh(string.format('output/solution-%06d', i)) 
    end
end
