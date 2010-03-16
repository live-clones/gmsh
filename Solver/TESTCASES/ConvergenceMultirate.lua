PI = 3.14159

--[[ 
     Function for initial conditions
--]]
function initial_condition( XYZ , FCT )
  for i=0,XYZ:size1()-1 do
    X = XYZ:get(i,0)
    Y = XYZ:get(i,1)
    -- +0.12
    V = X*X*Y*Y
    -- math.exp(-(X*X+Y*Y)*100)
    FCT:set(i,0,V) 
  end
end
function velocity( XYZ, FCT )
  for i=0,XYZ:size1()-1 do
    X = XYZ:get(i,0)
    Y = XYZ:get(i,1)
    FCT:set(i,0,0)
    FCT:set(i,1,1) 
    FCT:set(i,2,0) 
  end
end

function L2Norm( sol, FCT )
  for i=0,sol:size1()-1 do
    s = sol:get(i,0)
    FCT:set(i,0,s*s) 
  end
end
function solF( sol, FCT )
  for i=0,sol:size1()-1 do
    s = sol:get(i,0)
    FCT:set(i,0,s) 
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
xyzF = functionCoordinates.get()
velF = functionLua(3, 'velocity', {xyzF})
nuF = functionConstant({0})
law = dgConservationLawAdvectionDiffusion(velF, nuF)

-- law:addBoundaryCondition('Walls',law:newOutsideValueBoundary(functionConstant(g)))
-- law:addBoundaryCondition('Top',law:newOutsideValueBoundary(functionConstant(g)))
law:addBoundaryCondition('Walls',law:new0FluxBoundary())
law:addBoundaryCondition('Top',law:new0FluxBoundary())
FS = functionLua(1, 'initial_condition', {xyzF})
GC=dgGroupCollection(myModel,2,order)
solTmp=dgDofContainer(GC,1)
solTmp:L2Projection(FS)
dt=GC:splitGroupsForMultirate(20,1,2,law,solTmp)
GC:buildGroupsOfInterfaces(myModel,2,order)
solution=dgDofContainer(GC,1)
solutionRef=dgDofContainer(GC,1)
solutionRef:L2Projection(FS)
solution:exportGroupIdMsh()
solution:exportMultirateGroupMsh()
solutionRef:exportMsh("solution") 

nRefSteps=40
dtRef=dt/nRefSteps
RK=dgRungeKutta()
print'Compute reference solution'
for i=1,nRefSteps do
  RK:iterate44(law,dtRef,solutionRef)
  if(i%10==0) then
    print('it ',i)
  end
end

--multirateRK=dgRungeKuttaMultirate43(GC,law)
multirateRK=dgRungeKuttaMultirate22(GC,law)
integrator=dgFunctionIntegrator(functionLua(1, 'L2Norm', {functionSolution.get()}))
intSol=dgFunctionIntegrator(functionLua(1, 'solF', {functionSolution.get()}))

oldnorm=1
for n=0,3 do
  solution:L2Projection(FS)
  print('solnorm ',solution:norm())
  sN1=fullMatrix(1,1)
  intSol:compute(solution,sN1)
  print(string.format("solution integral before: %0.16e",sN1:get(0,0)))
  for i=1,2^n do
    multirateRK:iterate(dt/(2^n),solution)
    print('it ',i)
  end
  sN2=fullMatrix(1,1)
  intSol:compute(solution,sN2)
  print(string.format("solution integral after: %0.16e",sN2:get(0,0)))
  print(string.format("Mass conservation relative error: %0.16e",(sN1:get(0,0)-sN2:get(0,0))/sN1:get(0,0) ))
  solution:axpy(solutionRef,-1)
  lsq=fullMatrix(1,1)
  integrator:compute(solution,lsq)
  norm=math.sqrt(lsq:get(0,0))
  print(string.format("L2 norm for dt/%d %e",2^n,norm))
  if ( n~=0 ) then
    print(string.format("oldnorm/norm: %f",oldnorm/norm))
    print(string.format("Convergence rate: %f",math.log(oldnorm/norm)/math.log(2)))
  end
  oldnorm=norm
  solution:exportMsh("solution")
end
