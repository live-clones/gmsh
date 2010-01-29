model = GModel  ()
print'*** Loading the geo ***'
model:load ('square_m.geo')
-- model:load ('square_p.geo')
print'*** Loading the mesh ***'
model:load ('square_m.msh')
-- model:load('square_p.msh')
print'*** mesh loaded ***'
dg = dgSystemOfEquations (model)
order=3
dg:setOrder(order)
print("*** order = " .. order .. " ***")
print'*** Model set ***'

print("*** set initial condition ***")
-- initial condition
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    f:set (i, 0, math.exp(-100*((x+0.2)^2 +(y+0.3)^2)))
  end
end

-- conservation law
-- advection speed
v=fullMatrix(3,1);
v:set(0,0,0.01)
v:set(1,0,0.025)
v:set(2,0,0)
--print("*** set advection speed to: v_x=" .. v:get(0,0) ..", v_y=" .. v:get(1,0) .. ", v_z=" .. v:get(2,0) .. "  ***")
law = dgConservationLawAdvectionDiffusion(functionConstant(v):getName(),'')
dg:setConservationLaw(law)

print("*** set boundary conditions *** ")
-- boundary condition
outside=fullMatrix(1,1)
outside:set(0,0,0.0)
bndcondition=law:newOutsideValueBoundary(functionConstant(outside):getName())
law:addBoundaryCondition('Border',bndcondition)

--dg:setup()
-- create 2 groups of elements; criterion=maxEdge 
dg:createGroups("maxEdge")
-- dg:createGroups("minEdge")
-- dg:createGroups("elementType")

dg:L2Projection(functionLua(1,'initial_condition',{'XYZ'}):getName())

dg:exportSolution('output/Advection_00000')

dg:computeInvSpectralRadius();
T=40
dt=0.1

print("***     default time step (dt)=" .. dt .. ",  Period (T)=" ..T .."    ***")

N=T/dt
print("***     Number of time steps=" .. N .. "          ***")
-- main loop
for i=1,N do
  norm = dg:multirateRK43(dt)
    print('iter',i,norm)
  if (i % 20 == 0) then 
    dg:exportSolution(string.format("output/Advection_%05d", i)) 
  end
end
print '*** adding the mesh and the model ***'
