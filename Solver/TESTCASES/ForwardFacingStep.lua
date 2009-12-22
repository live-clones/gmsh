MACH = 3;
RHO  = 1.0;
PRES = 1./(MACH*RHO*RHO*1.4*1.4) 
V = 1.0 
SOUND = V/MACH

--[[ 
     Function for initial conditions
--]]
function free_stream( XYZ, FCT )
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
law=ConservationLawPerfectGas2d()
DG:setConservationLaw(law)
law:addBoundaryCondition('Walls',law:newWallBoundary())

FS = FunctionLua(4, 'free_stream', {'XYZ'}):getName()

law:addBoundaryCondition('LeftRight',law:newOutsideValueBoundary(FS))
DG:setup()


print'*** setting the initial solution ***'

DG:L2Projection(FS)
DG:limitSolution()

print'*** export ***'

DG:exportSolution('output/solution_0')

print'*** solve ***'

LC = 0.1*.1
dt = .3*LC/(SOUND+V);
print('DT=',dt)

for i=1,10000 do
    norm = DG:RK44_limiter(dt)
    print('*** ITER ***',i,norm)
    if (i % 100 == 0) then 
       DG:exportSolution(string.format("output/solution-%06d", i)) 
    end
end

print'*** done ***'


