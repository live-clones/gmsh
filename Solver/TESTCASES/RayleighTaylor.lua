ATWOOD = .5
RHO1 = 1.0
RHO2 = RHO1 * (1.+ATWOOD)/(1.-ATWOOD) 
taper  = 6.0
--Mach number of perturbation
machnum =0.1              
GAMMA = 1.4
-- Min speed of sound is at top where p=1, rho=2 
epsilon_z= machnum * math.sqrt(GAMMA*1.0/2.0)
epsilon_xy= -epsilon_z*taper/16.0    
BANDWIDTH = 0.005;
PI = 3.14159

--[[ 
     Function for initial conditions
--]]
function initial_condition( XYZ, FCT )
  for i=0,XYZ:size1()-1 do
    X = XYZ:get(i,0)-.125
    Y = XYZ:get(i,1)
    RHO = 1;
    if Y > 0.0 then
      RHO = 2
    end
-- smooth version
    RHO = 1.0 + (math.atan (Y/BANDWIDTH) / PI + 0.5)

    PRES = 2 - RHO*Y;
    vx = epsilon_xy * math.sin(X/0.25 * 2*PI) * math.cos(Y*PI) * math.pow(math.cos(Y*PI),taper-1.0);
    vy = epsilon_z  * math.cos(X/0.25 * 2*PI) * math.pow(math.cos(Y*PI),taper);
    FCT:set(i,0,RHO) 
    FCT:set(i,1,RHO*vx) 
    FCT:set(i,2,RHO*vy) 
    FCT:set(i,3, 0.5*RHO*(vx*vx+vy*vy)+PRES/0.4) 
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
   myModel:load ('rect2.msh')
elseif (order == 4) then
   myModel:load ('rect4.msh')
end

print'*** Create a dg solver ***'
DG = dgSystemOfEquations (myModel)
DG:setOrder(order)
law=dgPerfectGasLaw2d()

g=fullMatrix(4,1);
g:set(0,0,0)
g:set(1,0,0)
g:set(2,0,-1.)
g:set(3,0,0)

law:setSource(functionConstant(g):getName())
DG:setConservationLaw(law)
law:addBoundaryCondition('Walls',law:newSlipWallBoundary())
FS = functionLua(4, 'initial_condition', {'XYZ'}):getName()
law:addBoundaryCondition('Top',law:newOutsideValueBoundary(FS))

DG:setup()

print'*** setting the initial solution ***'

DG:L2Projection(FS)
DG:limitSolution()

--print'*** export ***'

DG:exportSolution('output/rt_0')

print'*** solve ***'

LC = 0.1*.1
dt = .0003;
print('DT=',dt)

for i=1,10000 do
--    norm = DG:RK44_limiter(dt)
    norm = DG:RK44(dt)
    if (i % 10 == 0) then 
       print('*** ITER ***',i,norm)
    end
    if (i % 100 == 0) then 
       DG:exportSolution(string.format("output/rt-%06d", i)) 
    end
end

print'*** done ***'


