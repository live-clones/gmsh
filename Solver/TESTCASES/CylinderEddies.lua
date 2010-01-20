MACH = .05;
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

order = 5

FS = functionLua(4, 'free_stream', {'XYZ'}):getName()

-- diffusivity
mu=fullMatrix(1,1);
mu:set(0,0,0.01)
kappa=fullMatrix(1,1);
kappa:set(0,0,0.01)

print'*** Loading the mesh and the model ***'
myModel   = GModel  ()
myModel:load ('cyl2.geo')	
myModel:load ('cyl2.msh')

print'*** Create a dg solver ***'
DG = dgSystemOfEquations (myModel)
DG:setOrder(order)
law=dgPerfectGasLaw2d()

law:setViscosityAndThermalConductivity(functionConstant(mu):getName(),functionConstant(kappa):getName());

DG:setConservationLaw(law)
law:addBoundaryCondition('Cylinder',law:newNonSlipWallBoundary())
law:addBoundaryCondition('Box'     ,law:newOutsideValueBoundary(FS))

DG:setup()

print'*** setting the initial solution ***'

DG:L2Projection(FS)

--print'*** export ***'

DG:exportSolution('output/cyl_0')

print'*** solve ***'

CFL = 20.1;
dt = CFL * DG:computeInvSpectralRadius();
print('DT = ',dt)
T = 0;
for i=1,1000000 do
    dt = CFL * DG:computeInvSpectralRadius();    
    norm = DG:RK44(dt)
    T = T + dt
    if (i % 10 == 0) then 
       print('*** ITER ***',i,norm,dt,T)
    end
    if (i % 100 == 0) then 
       DG:exportSolution(string.format("output/cyl-%06d", i)) 
       DG:saveSolution(string.format("output/cyl-%06d.bin", i)) 
    end
end

print'*** done ***'


