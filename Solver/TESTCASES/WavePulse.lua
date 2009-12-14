--[[ 
     Function for initial conditions
--]]
function initial_condition( x , f )
  XYZ = fullMatrix(x)    
  FCT = fullMatrix(f)    
  for i=0,XYZ:size1()-1 do
    X = XYZ:get(i,0) - .5
    Y = XYZ:get(i,1) - .5
    Z = XYZ:get(i,2)
    VALUE = math.exp(-40*(X*X+Y*Y+Z*Z));   
    FCT:set(i,0,VALUE) 
    FCT:set(i,1,0.0) 
    FCT:set(i,2,0.0) 
  end
end

--[[ 
     Example of a lua program driving the DG code
--]]

order = 5
print'*** Loading the mesh and the model ***'
myModel   = GModel  ()
myModel:load ('box.geo')
myModel:load ('box.msh')
print'*** Create a dg solver ***'
DG = dgSystemOfEquations (myModel)
DG:setOrder(order)
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
for i=1,1000 do
    norm = DG:RK44(dt)
    print('*** ITER ***',i,norm)
    if (i % 10 == 0) then 
       DG:exportSolution(string.format("solution-%03d", i)) 
    end
end

print'*** done ***'


