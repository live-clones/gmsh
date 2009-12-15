--[[ 
     Function for initial conditions
--]]
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    X = xyz:get(i,0) - .5
    Y = xyz:get(i,1) - .5
    Z = xyz:get(i,2)
    VALUE = math.exp(-40*(X*X+Y*Y+Z*Z)); 
    f:set(i,0,VALUE) 
    f:set(i,1,0.0) 
    f:set(i,2,0.0) 
  end
end


print'*** Loading the mesh and the model ***'
myModel   = GModel  ()
--myModel:load('box.geo')
--myModel:load('box.msh')
myModel:load('square.msh')

print'*** Create a dg solver ***'
DG = dgSystemOfEquations (myModel)
DG:setOrder(1)
law=ConservationLawWaveEquation(2)
DG:setConservationLaw(law)
law:addBoundaryCondition('Border',law:newWallBoundary())
DG:setup()

initialCondition = FunctionLua(3,'initial_condition',{'XYZ'}):getName()

print'*** setting the initial solution ***'

DG:L2Projection(initialCondition)

print'*** export ***'

DG:exportSolution('output/solution_000')

print'*** solve ***'

dt = 0.00125;
N  = 1000;
for i=1,N do
    norm = DG:RK44(dt)
    print('*** ITER ***',i,norm)
    if (i % 10 == 0) then 
       DG:exportSolution(string.format("output/solution-%03d", i)) 
    end
end

print'*** done ***'


