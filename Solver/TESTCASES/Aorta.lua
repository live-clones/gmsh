--[[ 
     Function for initial conditions
     CGS UNITS
--]]

t=0
Ainit = 3.0
T= 0.05
Amax = 0.01
p0 = 0.0
rho  = 1.06
--c = 500
--beta = 2*rho*math.pow(c,2)/math.sqrt(A0)
beta = 282166
--KR = 8*math.pi*0.04/rho
KR = 0.0

--[[ 
     Functions
--]]

function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
     f:set (i, 0, 0)
     f:set (i, 1, 0)
  end
end

function inlet( FCT )
  FCT:set(0,0,Amax*math.sin(2*math.pi*t/T)*math.atan(1000*(T/2-t)))
  --FCT:set(0,0, Amax)	
  FCT:set(0,1, 0) 
end

function pressureFlux (solution, bathymetry, f)
  for i=0,f:size1()-1 do
     A0 = bathymetry:get(i,0)	
     A = A0 + solution:get(i,0)
     p = p0 + beta*(math.sqrt(A)-math.sqrt(A0))
     f:set (i, 0, p)
  end
end

function celerityFunction (solution, bathymetry, f)
   for i=0,f:size1()-1 do
    A0 = bathymetry:get(i,0)	
    c = math.sqrt(beta/(2*rho))*math.pow(A0, 0.25)
    f:set (i, 0, c)
   end
end


function characteristicFunction (solution, celerity, f)
  for i=0,f:size1()-1 do
    W1 = sol:get(i,1) + 4*celerity:get(i,0)
    W2 = sol:get(i,1) - 4*celerity:get(i,0)	
    f:set (i, 0, W1)
    f:set (i, 1, W2)
  end
end

--[[ 
     Example of a lua program driving the DG code
--]]

order=1
dimension=1

model = GModel()
model:load('aorta.msh')
--options = gmshOptions()
--model:load ('aorta.geo')
--options:numberSet('Mesh',-1,'ElementOrder',order)
--model:mesh(dimension)
--model:save('aorta.msh')

bathymetry = functionConstant({Ainit})
dissipation = functionConstant({KR})
pressure = functionLua(1,'pressureFlux', {functionSolution.get(), bathymetry})
pwv = functionLua(1,'celerityFunction', {functionSolution.get(), bathymetry})
--chars = functionLua(1,'characteristicFunction', {functionSolution.get(), pwv})

-- boundary condition
inlet_bc = functionLua(2, 'inlet')
law = dgConservationLawShallowWater1d()
law:addBoundaryCondition('Inlet',law:newOutsideValueBoundary(inlet_bc))
law:addBoundaryCondition('Outlet',law:newBoundaryWall())
law:setLinearDissipation(dissipation)
law:setBathymetry(bathymetry)
law:setPressureFlux(pressure)
law:setCelerity(pwv)
--law:setCharacteristicFunction(chars)

groups = dgGroupCollection(model, dimension, order)
groups:buildGroupsOfInterfaces()

rk=dgRungeKutta()

print'*** print projetion ***'
-- build solution vector
FS = functionLua(2, 'initial_condition', {functionCoordinates.get()})
solution = dgDofContainer(groups, law:getNbFields())
solution:L2Projection(FS)

print'*** print initial sol ***'
solution:exportMsh('output/init')

print'*** solve ***'
CFL = 0.2;
x = os.clock()
for i=1,10000 do 
    dt = CFL * rk:computeInvSpectralRadius(law,solution);  
    t = t+dt
    norm = rk:iterate44(law,dt,solution)
    if (i % 100 == 0) then 
       print('|ITER|',i,'|NORM|',norm,'|DT|',dt, '|t|', t, '|CPU|',os.clock() - x)
    end
    if (i % 100 == 0) then 
       solution:exportMsh(string.format('output/solution-%06d', i)) 
    end
end
