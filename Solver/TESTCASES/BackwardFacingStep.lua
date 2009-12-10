MACH = 0.1;
RHO  = 1.0;
PRES = 1./(MACH*RHO*RHO*1.4*1.4) 
V = 1.0 
SOUND = V/MACH

--[[ 
     Function for initial conditions
--]]
function free_stream( x, f )
  FCT = fullMatrix(f)    
  XYZ = fullMatrix(x)    
  for i=0,XYZ:size1()-1 do
    FCT:set(i,0,RHO) 
    FCT:set(i,1,RHO*V) 
    FCT:set(i,2,0.0) 
    FCT:set(i,3, 0.5*RHO*V*V+PRES/0.4) 
  end
end

--[[ 
     Example of a lua program driving the DG code
--]]

order = 1
print'*** Loading the mesh and the model ***'
myModel   = GModel  ()
myModel:load ('step.geo')
myModel:load ('step.msh')
print'*** Create a dg solver ***'
DG = dgSystemOfEquations (myModel)
DG:setOrder(order)
DG:setConservationLaw('PerfectGas2d')
DG:addBoundaryCondition('Walls','Wall')

FS = createFunction.lua(4, 'free_stream', 'XYZ')

DG:addBoundaryCondition('LeftRight','FreeStream',FS)
DG:setup()


print'*** setting the initial solution ***'

DG:L2Projection(FS)

print'*** export ***'

DG:exportSolution('solution_0')

print'*** solve ***'

LC = 0.1
dt = .3*LC/(SOUND+V);
print('DT=',dt)

for i=1,1000 do
    norm = DG:RK44(dt)
    print('*** ITER ***',i,norm)
    if (i % 20 == 0) then 
       DG:exportSolution(string.format("solution-%03d", i)) 
    end
end

print'*** done ***'


