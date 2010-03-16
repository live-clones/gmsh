PI = 3.14159

--[[ 
     Function for initial conditions
--]]
function initial_condition( XYZ, FCT )
  for i=0,XYZ:size1()-1 do
    X = XYZ:get(i,0)
    Y = XYZ:get(i,1)+0.12
    V = math.exp(-(X*X+Y*Y)*100)
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

function toIntegrate( sol, FCT )
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
law=dgConservationLawAdvectionDiffusion(velF,nuF)


law:addBoundaryCondition('Walls',law:new0FluxBoundary())
law:addBoundaryCondition('Top',law:new0FluxBoundary())
FS = functionLua(1, 'initial_condition', {xyzF})




GC=dgGroupCollection(myModel,2,order)
solTmp=dgDofContainer(GC,1)
solTmp:L2Projection(FS)
dt=GC:splitGroupsForMultirate(2,1,2,law,solTmp)
GC:buildGroupsOfInterfaces(myModel,2,order)
solution=dgDofContainer(GC,1)
solution:L2Projection(FS)
solution0=dgDofContainer(GC,1)
solution2=dgDofContainer(GC,1)
solution3=dgDofContainer(GC,1)
solution0:L2Projection(FS)
solution2:L2Projection(FS)
solution3:L2Projection(FS)
solution:exportGroupIdMsh()

print'---- Groups splitted ----'

print'*** setting the initial solution ***'

solution:exportMsh(string.format("output/adv_sr43-%06d", 0)) 
solution0:exportMsh(string.format("output/adv_sr22-%06d", 0)) 
solution2:exportMsh(string.format("outputMultirate/adv_mr43-%06d", 0)) 
solution3:exportMsh(string.format("outputMultirate/adv_mr22-%06d", 0))
print'*** solve ***'

LC = 0.1*.1
dt=dt
print('DT=',dt)
RK22=dgRungeKutta()
RK=dgRungeKutta()
multirateRK=dgRungeKuttaMultirate43(GC,law)
multirateRK22=dgRungeKuttaMultirate22(GC,law)
norm1=solution:norm()
norm0=solution:norm()
norm2=solution2:norm()
norm3=solution3:norm()
print('Norm: ',norm0,norm1,norm2,norm3)
dt=dt
time=0
i=0
integrator=dgFunctionIntegrator(functionLua(1, 'toIntegrate', {functionSolution.get()}))
       print('*** ITER-START ***')
       v=fullMatrix(1,1);
			 w=fullMatrix(1,1);
			 u=fullMatrix(1,1);
			 z=fullMatrix(1,1);
       integrator:compute(solution,v)
       integrator:compute(solution0,z)
			 integrator:compute(solution2,w)
			 integrator:compute(solution3,u)
			 uref=u:get(0,0,0)
			 vref=v:get(0,0,0)
			 wref=w:get(0,0,0)
			 zref=z:get(0,0,0)
			 print'*****************************************'
       print('integral (SR43) : ',v:get(0,0,0))
       print('integral (MR43) : ',w:get(0,0,0))
       print('integral (SR22) : ',z:get(0,0,0))
       print('integral (MR22) : ',u:get(0,0,0))
			 print'******************************************'
while i<10 do
		norm0=RK22:iterate22(law, dt, solution0)
    norm1 = RK:iterate43SchlegelJCAM2009(law,dt,solution)
    norm2 = multirateRK:iterate(dt,solution2)
		norm3 = multirateRK22:iterate(dt, solution3)
    time=time+dt
    if (i % 1 == 0) then 
       print('*** ITER ***',i)--,time,norm1, norm2,norm0, norm3)
			 print'-----------------------------------------'
			 integrator:compute(solution,v)
			 integrator:compute(solution2,w)
			 integrator:compute(solution3, u)
			 integrator:compute(solution0, z)
       print('integral (SR43) : ',v:get(0,0,0))
       print('integral (MR43) : ',w:get(0,0,0))
       print('integral (SR22) : ',z:get(0,0,0))
       print('integral (MR22) : ',u:get(0,0,0))
			 print(string.format("Mass conservation relative error:\n SR43=%0.16e,\n MR43=%0.16e,\n SR22=%0.16e,\n MR22=%0.16e",math.abs((vref-v:get(0,0,0))/vref), math.abs((wref-w:get(0,0,0))/wref),math.abs((zref-z:get(0,0,0))/zref),math.abs((uref-u:get(0,0,0))/uref)));
			 print'-----------------------------------------'
    end
    if (i % 10 == 0) then 
       solution:exportMsh(string.format("output/adv_sr43-%06d", i)) 
       solution2:exportMsh(string.format("outputMultirate/adv_mr43-%06d", i)) 
       solution3:exportMsh(string.format("outputMultirate/adv_mr22-%06d", i)) 
    end
    i=i+1
end

print'*** done ***'


