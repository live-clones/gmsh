--[[ 
     Function for initial conditions
--]]

g = 9.81;

function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    if (x<0.0) then
     f:set (i, 0, 40)
     f:set (i, 1, 0)
    else
     f:set (i, 0, 20)
     f:set (i, 1, 0)
    end	
  end
end

function pressureFlux (solution,  f)
  for i=0,f:size1()-1 do
     p = g*solution:get(i,0)
     f:set (i, 0, p)
  end
end
function celerityFunction (solution, bathymetry, f)
  for i=0,f:size1()-1 do
    c = math.sqrt(g*(bathymetry:get(i,0)+solution:get(i,0)))
    f:set(i, 0, c)
  end
end


CFunctions =[[
void pressureFlux ( fullMatrix<double> &f, fullMatrix<double> &sol) {
  for (size_t i = 0; i< f.size1(); i++) {
    double p=9.81*sol(i,0);
    f.set(i,0,p);
  }
}
void celerityFunction (fullMatrix<double> &f , fullMatrix<double> &sol, fullMatrix<double> &bathymetry) {
  for (size_t i = 0; i< sol.size1(); i++) {
    double c =sqrt(9.81*(bathymetry(i,0)+sol(i,0)));
    f.set(i,0,c);
  }
}]]
if (Msg.getCommRank() == 0 ) then
  cfile = io.popen("g++-4.2 -O3 -pipe -m32 -shared -o tmp.dylib -I ../../Numeric -I../../Common -I../../build/Common -x c++ - ","w");
  cfile:write("#include\"fullMatrix.h\"\nextern \"C\" {")
  cfile:write(CFunctions)
  cfile:write("}")
  cfile:close()
end
Msg.barrier()


bathymetry = functionConstant({0})
dissipation = functionConstant({0})

--[[ 
     Example of a lua program driving the DG code
--]]

model = GModel()
model:load ('edge.msh')
order=1
dimension=1


-- boundary condition
law = dgConservationLawShallowWater1d()
law:addBoundaryCondition('Left',law:newBoundaryWall())
law:addBoundaryCondition('Right',law:newBoundaryWall())
law:setLinearDissipation(dissipation)
law:setBathymetry(bathymetry)
--law:setPressureFlux(functionLua(1,'pressureFlux',{functionSolution.get()}))
--law:setCelerity(functionLua(1,'celerityFunction',{functionSolution.get(), bathymetry}))
law:setPressureFlux(functionC("tmp.dylib","pressureFlux",1,{functionSolution.get()}))
law:setCelerity(functionC("tmp.dylib","celerityFunction",1,{functionSolution.get(), bathymetry}))

groups = dgGroupCollection(model, dimension, order)
groups:buildGroupsOfInterfaces()

rk=dgRungeKutta()
limiter = dgSlopeLimiter(law)
rk:setLimiter(limiter) 

-- build solution vector
FS = functionLua(2, 'initial_condition', {functionCoordinates.get()})
solution = dgDofContainer(groups, law:getNbFields())
solution:L2Projection(FS)

print'*** print initial sol ***'
--solution:exportMsh('output/init')
limiter:apply(solution)
solution:exportMsh('output/init_limit')

print'*** solve ***'



CFL = 0.2;
for i=1,15000 do 
    dt = CFL * rk:computeInvSpectralRadius(law,solution);  
    norm = rk:iterate44(law,dt,solution)
--  norm = rk:iterateEuler(law,dt,solution)
    if (i % 100 == 0) then 
       print('|ITER|',i,'|NORM|',norm,'|DT|',dt,'|CPU|',os.clock() - x)
    end
    if (i % 100 == 0) then 
       solution:exportMsh(string.format('output/solution-%06d', i)) 
    end
end
