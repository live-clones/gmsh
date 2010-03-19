PI = 3.14159
-- Defining functions

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

order = 1
dimension = 2
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

--functions
xyzF = functionCoordinates.get()
velF = functionLua(3, 'velocity', {xyzF})
nuF = functionConstant({0})

--Conservation laws
law=dgConservationLawAdvectionDiffusion(velF,nuF)

--Add the boundary conditions
law:addBoundaryCondition('Walls',law:new0FluxBoundary())
law:addBoundaryCondition('Top',law:new0FluxBoundary())

--Fix initial condition
FS = functionLua(1, 'initial_condition', {xyzF})

-- Creating the different "base" Element groups before splitting them (if multirate)

-- Singlerate 
GC0=dgGroupCollection(myModel,dimension,order)
solTmp0=dgDofContainer(GC0,1)
solTmp0:L2Projection(FS)
GC0:buildGroupsOfInterfaces();

GC1=dgGroupCollection(myModel,dimension,order)
solTmp1=dgDofContainer(GC1,1)
solTmp1:L2Projection(FS)
GC1:buildGroupsOfInterfaces();

--Multirate
GC2=dgGroupCollection(myModel,dimension,order)
solTmp2=dgDofContainer(GC2,1)
solTmp2:L2Projection(FS)

GC3=dgGroupCollection(myModel,dimension,order)
solTmp3=dgDofContainer(GC3,1)
solTmp3:L2Projection(FS)

GC4=dgGroupCollection(myModel,dimension,order)
solTmp4=dgDofContainer(GC4,1)
solTmp4:L2Projection(FS)

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

-- RK2a
print'--- RK2a ---'
RK2a=dgRungeKutta()
--dt0=RK2a:splitForMultirate(100, solTmp)
-- RK43
print'--- RK43 ---'
RK43=dgRungeKutta()
--dt1=RK43:splitForMultirate(100, solTmp)

-- Multirate RK2a

-- *** Default Multirate RK2a ***
--multirateRK2a=dgRungeKuttaMultirate22(GC,law)

-- *** Multirate RK2a with as input the butcher tables ***
print'--- multirateRK2a ---'
multirateRK2a=dgRungeKuttaMultirateConservative(GC2, law, A, b, c)
dt2=multirateRK2a:splitForMultirate(10, solTmp2)

-- Multirate RK43
print'--- multirateRK43 ---'
multirateRK43=dgRungeKuttaMultirate43(GC3,law)
dt3=multirateRK43:splitForMultirate(10, solTmp3)

-- Multirate RK2b 
print'--- multirateRK2b ---'
multirateRK2b=dgRungeKuttaMultirateConservative.new2b(GC4, law)
-- multirateRK2b:printButcher()
dt4=multirateRK2b:splitForMultirate(10, solTmp4)

dt0=dt2
dt1=dt2

solution0=dgDofContainer(GC0,1)
solution1=dgDofContainer(GC1,1)
solution2=dgDofContainer(GC2,1)
solution3=dgDofContainer(GC3,1)
solution4=dgDofContainer(GC4,1)

solution0:L2Projection(FS)
solution1:L2Projection(FS)
solution2:L2Projection(FS)
solution3:L2Projection(FS)
solution4:L2Projection(FS)

solution4:exportGroupIdMsh()

print'---- Groups splitted ----'

print'*** setting the initial solution ***'

solution0:exportMsh(string.format("outputSinglerate/adv_sr2a-%06d", 0)) 
solution1:exportMsh(string.format("outputSinglerate/adv_sr43-%06d", 0)) 
solution2:exportMsh(string.format("outputMultirate/adv_mr2a-%06d", 0)) 
solution3:exportMsh(string.format("outputMultirate/adv_mr43-%06d", 0))
solution4:exportMsh(string.format("outputMultirate/adv_mr2b-%06d", 0))
print'*** solve ***'

LC = 0.1*.1
print('DT=',dt0)

norm0=solution0:norm()
norm1=solution1:norm()
norm2=solution2:norm()
norm3=solution3:norm()
norm4=solution4:norm()

print('Norm: ', norm0, norm1, norm2, norm3, norm4)
time0=0
time1=0
time2=0
time3=0
time4=0
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

while i<100 do
	  --iterate 
		norm0 = RK2a:iterate22(law, dt0, solution0)
    norm1 = RK43:iterate43SchlegelJCAM2009(law, dt1, solution1)
    norm2 = multirateRK2a:iterate(dt2, solution2)
		norm3 = multirateRK43:iterate(dt3, solution3)
		norm4 = multirateRK2b:iterate(dt4, solution4)
    
		--updating time
		time0=time0+dt0
    time1=time1+dt1
    time2=time2+dt2
    time3=time3+dt3
    time4=time4+dt4
    
		if (i % 10 == 0) then 
       print('*** ITER ***',i)
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


