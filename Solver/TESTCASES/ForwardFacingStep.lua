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

order = 1
print'*** Loading the mesh and the model ***'
myModel   = GModel  ()
myModel:load ('step.geo')
myModel:load ('step.msh')

print'*** Create a dg solver ***'
DG = dgSystemOfEquations (myModel)
DG:setOrder(order)
FS = functionLua(4, 'free_stream', {'XYZ'}):getName()

law=dgPerfectGasLaw2d()
DG:setConservationLaw(law)

law:addBoundaryCondition('Walls',law:newWallBoundary())
law:addBoundaryCondition('LeftRight',law:newOutsideValueBoundary(FS))
--law:addBoundaryCondition('Walls',law:newOutsideValueBoundary(FS))

DG:setup()

print'*** setting the initial solution ***'

DG:L2Projection(FS)
DG:limitSolution()

print'*** export ***'

DG:exportSolution('output/solution_0')

print'*** solve ***'
CFL = 2

for i=1,5000 do
    dt = CFL * DG:computeInvSpectralRadius();    
    norm = DG:RK44_limiter(dt)
    DG:limitSolution()
    if (i % 10 == 0) then 
       print('*** ITER ***',i,norm,dt)
    end
    if (i % 100 == 0) then 
       DG:exportSolution(string.format("output/solution-%06d", i)) 
    end
end

print'*** done ***'


