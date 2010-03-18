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

-- Example of Conservative Multirate scheme with Butcher tables as input (here RK2a)
A=fullMatrix(2, 2)
A:set(0, 0, 0)
A:set(0, 1, 0)
A:set(1, 0, 1)
A:set(1, 1, 0)

b=fullMatrix(1, 2)
b:set(0, 0, 0.5)
b:set(0, 1, 0.5)

c=fullMatrix(1, 2)
c:set(0, 0, 0)
c:set(0, 1, 1)

-- Building the RK objects

multirateRK=dgRungeKuttaMultirateConservative.new2b(GC, law)
multirateRK:printButcher()
-- RK2a
RK2a=dgRungeKutta()

-- RK43
RK43=dgRungeKutta()

-- Multirate RK2a

-- *** Default Multirate RK2a ***
--multirateRK2a=dgRungeKuttaMultirate22(GC,law)

-- *** Multirate RK2a with as input the butcher tables ***
multirateRK2a=dgRungeKuttaMultirateConservative(GC, law, A, b, c)

-- Multirate RK43
multirateRK43=dgRungeKuttaMultirate43(GC,law)

-- Multirate RK2b 
multirateRK2b=dgRungeKuttaMultirateConservative.new2b(GC, law)
-- multirateRK2b:printButcher()

GC:buildGroupsOfInterfaces(myModel,2,order)
solution0=dgDofContainer(GC,1)
solution1=dgDofContainer(GC,1)
solution2=dgDofContainer(GC,1)
solution3=dgDofContainer(GC,1)
solution4=dgDofContainer(GC,1)
solution0:L2Projection(FS)
solution1:L2Projection(FS)
solution2:L2Projection(FS)
solution3:L2Projection(FS)
solution4:L2Projection(FS)
solution0:exportGroupIdMsh()

print'---- Groups splitted ----'

print'*** setting the initial solution ***'

solution0:exportMsh(string.format("outputSinglerate/adv_sr2a-%06d", 0)) 
solution1:exportMsh(string.format("outputSinglerate/adv_sr43-%06d", 0)) 
solution2:exportMsh(string.format("outputMultirate/adv_mr2a-%06d", 0)) 
solution3:exportMsh(string.format("outputMultirate/adv_mr43-%06d", 0))
solution4:exportMsh(string.format("outputMultirate/adv_mr2b-%06d", 0))
print'*** solve ***'

LC = 0.1*.1
dt=dt
print('DT=',dt)

norm0=solution0:norm()
norm1=solution1:norm()
norm2=solution2:norm()
norm3=solution3:norm()
norm4=solution4:norm()

print('Norm: ', norm0, norm1, norm2, norm3, norm4)
dt=dt
time=0
i=0
integrator=dgFunctionIntegrator(functionLua(1, 'toIntegrate', {functionSolution.get()}))
       print('*** ITER-START ***')
       w0=fullMatrix(1,1);
			 w1=fullMatrix(1,1);
			 w2=fullMatrix(1,1);
			 w3=fullMatrix(1,1);
			 w4=fullMatrix(1,1);
       integrator:compute(solution0,w0)
       integrator:compute(solution1,w1)
			 integrator:compute(solution2,w2)
			 integrator:compute(solution3,w3)
			 integrator:compute(solution4,w4)
			 w0ref=w0:get(0,0,0)
			 w1ref=w1:get(0,0,0)
			 w2ref=w2:get(0,0,0)
			 w3ref=w3:get(0,0,0)
			 w4ref=w4:get(0,0,0)
			 print'*****************************************'
       print('integral (SR2a) : ',w0:get(0,0,0))
       print('integral (SR43) : ',w1:get(0,0,0))
       print('integral (MR2a) : ',w2:get(0,0,0))
       print('integral (MR43) : ',w3:get(0,0,0))
       print('integral (MR2b) : ',w4:get(0,0,0))
			 print'******************************************'
while i<10 do
		norm0 = RK2a:iterate22(law, dt, solution0)
    norm1 = RK43:iterate43SchlegelJCAM2009(law, dt, solution1)
    norm2 = multirateRK2a:iterate(dt, solution2)
		norm3 = multirateRK43:iterate(dt, solution3)
		norm4 = multirateRK2b:iterate(dt, solution4)
    time=time+dt
    if (i % 1 == 0) then 
       print('*** ITER ***',i)--,time,norm0, norm1,norm2, norm3)
			 print'-----------------------------------------'
			 integrator:compute(solution0, w0)
			 integrator:compute(solution1, w1)
			 integrator:compute(solution2, w2)
			 integrator:compute(solution3, w3)
			 integrator:compute(solution4, w4)

       print('integral (SR2a) : ',w0:get(0,0,0))
       print('integral (SR43) : ',w1:get(0,0,0))
       print('integral (MR2a) : ',w2:get(0,0,0))
       print('integral (MR43) : ',w3:get(0,0,0))
       print('integral (MR2b) : ',w4:get(0,0,0))
			 
			 print(string.format("Mass conservation relative error:\n SR2a=%0.16e,\n SR43=%0.16e,\n MR2a=%0.16e,\n MR43=%0.16e,\n MR2b=%0.16e",math.abs((w0ref-w0:get(0,0,0))/w0ref), math.abs((w1ref-w1:get(0,0,0))/w1ref),math.abs((w2ref-w2:get(0,0,0))/w2ref),math.abs((w3ref-w3:get(0,0,0))/w3ref), math.abs((w4ref-w4:get(0,0,0))/w4ref)));
			 print'-----------------------------------------'
    end
    if (i % 10 == 0) then 
       solution0:exportMsh(string.format("outputSinglerate/adv_sr2a-%06d", i)) 
       solution1:exportMsh(string.format("outputSinglerate/adv_sr43-%06d", i)) 
       solution2:exportMsh(string.format("outputMultirate/adv_mr2a-%06d", i)) 
       solution3:exportMsh(string.format("outputMultirate/adv_mr43-%06d", i)) 
       solution4:exportMsh(string.format("outputMultirate/adv_mr2b-%06d", i)) 
    end
    i=i+1
end

print'*** done ***'


