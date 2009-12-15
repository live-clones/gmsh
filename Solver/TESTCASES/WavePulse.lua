--[[ 
     Function for initial conditions
--]]
function initial_condition( _x , _f )
  xyz = fullMatrix(_x)    
  f = fullMatrix(_f) 
  for i=0,xyz:size1()-1 do
    X = xyz:get(i,0) - .5
    Y = xyz:get(i,1) - .5
    Z = xyz:get(i,2)
    VALUE = math.exp(-40*(X*X+Y*Y+Z*Z));   
    f:set(i,0,7) 
    f:set(i,1,0.0) 
    f:set(i,2,0.0) 
  end
end

--[[ 
     Example of a lua program driving the DG code
--]]

print'*** Loading the mesh and the model ***'
myModel   = GModel  ()
myModel:load('square.geo')
myModel:mesh(2)

print'*** Create a dg solver ***'
DG = dgSystemOfEquations (myModel)
DG:setOrder(1)
DG:setConservationLaw('WaveEquation')

DG:addBoundaryCondition('Border','Wall')
DG:setup()

initialCondition = createFunction.lua(3,'initial_condition','XYZ')

print'*** setting the initial solution ***'

DG:L2Projection(initialCondition)

print'*** export ***'

DG:exportSolution('output/solution_000')

print'*** solve ***'

dt = 0.00125;
N  = 1;
for i=1,N do
    norm = DG:RK44(dt)
    print('*** ITER ***',i,norm)
    if (i % 10 == 0) then 
       DG:exportSolution(string.format("solution-%03d", i)) 
    end
end

print'*** done ***'


