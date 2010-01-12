--[[ 
     Function for initial conditions
--]]
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    X = xyz:get(i,0) - .5
    Y = xyz:get(i,1) - .5
    Z = xyz:get(i,2)
--    X2 = xyz:get(i,0) - 1.5
--    Y2 = xyz:get(i,1) - .5
--    Z2 = xyz:get(i,2)
    VALUE = math.exp(-40*(X*X+Y*Y+Z*Z))
-- + math.exp(-40*(X2*X2+Y2*Y2+Z2*Z2)); 
    f:set(i,0,VALUE) 
    f:set(i,1,0.0) 
    f:set(i,2,0.0) 
  end
end


print'*** Loading the mesh and the model ***'
myModel   = GModel  ()
--myModel:load('box.geo')
--myModel:load('box.msh')
--myModel:load('square_quads.msh')
myModel:load('square_mixed.msh')


print'*** Create a dg solver ***'
DG = dgSystemOfEquations (myModel)
DG:setOrder(3)
law=dgConservationLawWaveEquation(2)
DG:setConservationLaw(law)
law:addBoundaryCondition('Border',law:newBoundaryWall())
DG:setup()

initialCondition = functionLua(3,'initial_condition',{'XYZ'}):getName()

print'*** setting the initial solution ***'

DG:L2Projection(initialCondition)

print'*** export ***'

DG:exportSolution('output/solution_000')

print'*** solve ***'

N  = 100;
CFL = 2.1;
dt = CFL * DG:computeInvSpectralRadius();
print('DT = ',dt)
for i=1,N do
--    norm = DG:multirateRK43(dt)
    norm = DG:RK44(dt)
    if (i % 100 == 0) then 
      print('*** ITER ***',i,norm)
      DG:exportSolution(string.format("output/solution-%04d", i)) 
    end
end

print'*** done ***'


