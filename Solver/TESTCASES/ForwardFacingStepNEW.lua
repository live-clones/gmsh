MACH = 3.0;
GAMMA = 1.4;
U = 3.0
V = 0.0 
RHO  = 1.4;

PRES = RHO*U*U/(GAMMA*MACH*MACH)

--PRES = 1;
--PRES = ./(MACH*RHO*RHO*GAMMA*GAMMA) 

SOUND = math.sqrt(U*U+V*V)/MACH

--[[ 
     Function for initial conditions
--]]
function free_stream( XYZ, FCT )
  for i=0,XYZ:size1()-1 do
    FCT:set(i,0,RHO) 
    FCT:set(i,1,RHO*U) 
    FCT:set(i,2,RHO*V) 
    FCT:set(i,3, 0.5*RHO*(U*U+V*V)+PRES/(GAMMA-1)) 
  end
end

--[[ 
     Example of a lua program driving the DG code
--]]


print'*** Loading the mesh and the model ***'
model   = GModel  ()
model:load ('step.geo')
model:load ('step.msh')
order = 1
dimension = 2

FS = functionLua(4, 'free_stream', {XYZ})

-- boundary condition
law=dgPerfectGasLaw2d()
law:addBoundaryCondition('Walls',law:newNonSlipWallBoundary())
law:addBoundaryCondition('LeftRight',law:newOutsideValueBoundary(FS))
--law:addBoundaryCondition('Walls',law:newOutsideValueBoundary(FS))

groups = dgGroupCollection(model, dimension, order)
groups:buildGroupsOfInterfaces()

-- build Runge Kutta and limiter
rk=dgRungeKutta()
limiter = dgSlopeLimiter(law)
rk:setLimiter(limiter) 

-- build solution vector
solution = dgDofContainer(groups, law:getNbFields())
solution:L2Projection(FS)
solution:exportGroupIdMsh()

print'*** setting the initial solution ***'
solution:exportMsh('output/init')
limiter:apply(solution)
solution:exportMsh('output/init_limit')

print'*** solve ***'
dg = dgSystemOfEquations (model)
CFL = 2
local x = os.clock()
for i=1,5000 do
    dt = CFL * rk:computeInvSpectralRadius(law,solution);    
--  norm = rk:iterate44(law,dt,solution)
    norm = rk:iterateEuler(law,dt,solution)
    if (i % 10 == 0) then 
       print('|ITER|',i,'|NORM|',norm,'|DT|',dt,'|CPU|',os.clock() - x)
    end
    if (i % 100 == 0) then 
       solution:exportMsh(string.format('output/solution-%06d', i)) 
    end
end

print'*** done ***'


