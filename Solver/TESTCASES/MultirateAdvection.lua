PI = 3.14159

--[[ 
     Function for initial conditions
--]]
function initial_condition( XYZ, FCT )
  for i=0,XYZ:size1()-1 do
    X = XYZ:get(i,0)
    Y = XYZ:get(i,1)+0.12
    V = math.exp(-(X*X+Y*Y)*100)
    FCT:set(i,0,V) 
  end
end
function velocity( XYZ, FCT )
  for i=0,XYZ:size1()-1 do
    X = XYZ:get(i,0)
    Y = XYZ:get(i,1)
    FCT:set(i,0,0) 
    FCT:set(i,1,1) 
  end
end

function toIntegrate( XYZ, FCT )
  for i=0,XYZ:size1()-1 do
    X = XYZ:get(i,0)
    Y = XYZ:get(i,1)
    FCT:set(i,0,X*X) 
  end
end
--[[ 
     Example of a lua program driving the DG code
--]]

order = 1
print'*** Loading the mesh and the model ***'
myModel   = GModel  ()
 myModel:load ('rect.geo')	
if (order == 1) then
   myModel:load ('rect.msh')
elseif (order == 2) then
   myModel:load ('rect2.msh')
elseif (order == 3) then
   myModel:load ('rect3.msh')
elseif (order == 4) then
   myModel:load ('rect4.msh')
elseif (order == 5) then
   myModel:load ('rect5.msh')
end

print'*** Create a dg solver ***'
velF = functionLua(2, 'velocity', {'XYZ'}):getName()
law=dgConservationLawAdvectionDiffusion(velF,"")

g=fullMatrix(1,1);
g:set(0,0,0)
law:addBoundaryCondition('Walls',law:newOutsideValueBoundary(functionConstant(g):getName()))
law:addBoundaryCondition('Top',law:newOutsideValueBoundary(functionConstant(g):getName()))
FS = functionLua(1, 'initial_condition', {'XYZ'}):getName()

GC=dgGroupCollection(myModel,2,order)
solTmp=dgDofContainer(GC,1)
solTmp:L2Projection(FS)
dt=GC:splitGroupsForMultirate(4,law,solTmp)
GC:buildGroupsOfInterfaces(myModel,2,order)
solution=dgDofContainer(GC,1)
solution:L2Projection(FS)
solution2=dgDofContainer(GC,1)
solution2:L2Projection(FS)
solution:exportGroupIdMsh()

print'------------------- splitted !!'

-- limiter = dgSlopeLimiter(law)
-- limiter:apply(solution)

print'*** setting the initial solution ***'
--print'*** export ***'

solution:exportMsh(string.format("output/rt-%06d", 0)) 
solution2:exportMsh(string.format("outputMultirate/rt-%06d", 0)) 

print'*** solve ***'

LC = 0.1*.1
dt=dt
print('DT=',dt)
RK=dgRungeKutta()
multirateRK=dgRungeKuttaMultirate43(GC,law)
norm1=solution:norm()
norm2=solution2:norm()
print('Norm: ',norm1,norm2)
dt=dt
time=0
-- multirateRK:setLimiter(limiter)
--for i=1,1000
i=0
integrator=dgFunctionIntegrator(functionLua(1, 'toIntegrate', {'XYZ'}):getName())
while time<0.2 do
--     norm1 = RK:iterate43SchlegelJCAM2009(law,dt,solution)
-- TEST with Explicit Euler multirate !!!
    norm2 = multirateRK:iterate(dt,solution2)
    time=time+dt
    if (i % 10 == 0) then 
       print('*** ITER ***',i,time,norm2)
       v=fullMatrix(1,1);
       integrator:compute(solution2,v);
       print('integral : ',v:get(0,0,0))
    end
    if (i % 10 == 0) then 
  --     solution:exportMsh(string.format("output/rt-%06d", i)) 
       solution2:exportMsh(string.format("outputMultirate/rt-%06d", i)) 
    end
    i=i+1
end

print'*** done ***'


