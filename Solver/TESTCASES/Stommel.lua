model = GModel()
model:load ('stommel_square.msh')
order=1
dimension = 2

CFunctions =[[
void wind (fullMatrix<double> &sol, fullMatrix<double> &xyz) {
  for (size_t i = 0; i< sol.size1(); i++) {
    sol.set(i,0,sin(xyz(i,1)/1e6)/1e6);
    sol.set(i,1,0);
  }
}
void coriolis (fullMatrix<double> &sol, fullMatrix<double> &xyz) {
  for (size_t i = 0; i< sol.size1(); i++) {
    sol.set(i,0,1e-4+2e-11*xyz(i,1));
  }
}
]]

if (Msg.getCommRank() == 0 ) then
  cfile = io.popen("g++-4.2 -O3 -pipe -m32 -shared -o tmp.dylib -I ../../Numeric -I../../Common -I../../build/Common -x c++ - ","w");
  cfile:write("#include\"fullMatrix.h\"\nextern \"C\" {")
  cfile:write(CFunctions)
  cfile:write("}")
  cfile:close()
end

Msg.barrier()

claw = dgConservationLawShallowWater2d()
claw:addBoundaryCondition('Wall',claw:newBoundaryWall())
zero = functionConstant({0}):getName();
claw:setCoriolisFactor(functionC("tmp.dylib","coriolis",1,{"XYZ"}):getName())
claw:setQuadraticDissipation(zero)
claw:setLinearDissipation(functionConstant({1e-6}):getName())
claw:setSource(functionC("tmp.dylib","wind",2,{"XYZ"}):getName())
claw:setBathymetry(functionConstant({1000}):getName())
groups = dgGroupCollection(model, dimension, order)
groups:buildGroupsOfInterfaces()
solution = dgDofContainer(groups, claw:getNbFields())
solution:exportMsh('output/init')
rk=dgRungeKutta()

for i=1,60000 do
  norm = rk:iterate33(claw,150*(3/(2.*order+1)/2),solution)
  if ( i%100 ==0 ) then
    print ('iter ', i, norm)
  end
  if ( i%100 ==0 ) then
    solution:exportMsh(string.format('output/solution-%06d',i))
  end
end
