function neumannCondition (x,y,z)
  return {-100e6,0,0}
end

m = GModel()
m:load("conge.geo")
m:load("conge.msh")
e = elasticitySolver(m,1)
e:addElasticDomain (7, 200e9, 0.3)
e:addDirichletBC (1,8,0,0)
e:addDirichletBC (1,8,1,0)
e:addDirichletBC (1,8,2,0)
e:addNeumannBCLua (1,9,"neumannCondition")
sys = linearSystemCSRTaucs()
e:assemble(sys)
sys:systemSolve()
view = e:buildVonMisesView("vonMises")

view = e:buildDisplacementView("displacement")
view:write("displacement.msh",5,false)

viewData = view:getData()
nEntities = viewData:getNumEntities(-1)
v = fullMatrix(3,3)
nodes = fullMatrix(3,3)
for i=0,nEntities-1 do 
  nElements = viewData:getNumElements(-1,i)
  for j=0,nElements-1 do
    if(viewData:getNumNodes(0,i,j)==3) then
      viewData:getAllValuesForElement(0,i,j,v)
      viewData:getAllNodesForElement(0,i,j,nodes)
    end
  end
end

basis = polynomialBasis.find(2)
points = fullMatrix(3,3)
points:set(0,0,0);
points:set(0,1,0);
points:set(0,2,0);

points:set(1,0,1);
points:set(1,1,0);
points:set(1,2,0);

points:set(2,0,0);
points:set(2,1,1);
points:set(2,2,0);

basis:f(points,v)
v:print("f")
