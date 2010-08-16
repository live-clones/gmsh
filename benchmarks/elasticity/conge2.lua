function neumannCondition (x,y,z)
  return {-100e6,0,0}
end


function errorOnView (view, dim)
  basis = polynomialBasis.find(2)
  gaussPoints = fullMatrix(1,1)
  gaussWeights = fullMatrix(1,1)
  gaussIntegration.getTriangle(3,gaussPoints,gaussWeights)

  nnodes = 3 -- only triangles
  viewData = view:getData()
  values = fullMatrix(nnodes,dim)
  nodes = fullMatrix(nnodes,3)
  gaussXYZ = fullMatrix(gaussPoints:size1(),3)
  gaussValues = fullMatrix(gaussPoints:size1(),dim)
  nEntities = viewData:getNumEntities(-1)
  psi = fullMatrix(gaussPoints:size1(),3)
  basis:f(gaussPoints,psi)
  for i=0,nEntities-1 do 
    nElements = viewData:getNumElements(-1,i)
    for j=0,nElements-1 do
      if(viewData:getNumNodes(0,i,j)==nnodes) then
        viewData:getAllValuesForElement(0,i,j,values)
        viewData:getAllNodesForElement(0,i,j,nodes)
      end
      gaussXYZ:gemm(psi,nodes,1,0)
      gaussValues:gemm(psi,values,1,0)
    end
  end
end



m = GModel()
m:load("conge.geo")
m:load("conge.msh")

print('---> creating elastic solver')
e = elasticitySolver(m,1)
e:addElasticDomain (7, 200e9, 0.3)
e:addDirichletBC (1,8,0,0)
e:addDirichletBC (1,8,1,0)
e:addDirichletBC (1,8,2,0)
e:addNeumannBCLua (1,9,"neumannCondition")
sys = linearSystemPETSc()
--sys = linearSystemCSRTaucs()

print('----------> assembling')
e:assemble(sys)

print('----------> solving')
--sys:systemSolve()
e:solve()

print('----------> writing results')
format = 5 --gmsh format
--view = e:buildVonMisesView("vonMises")
--view = e:buildDisplacementView("displacement")
view = e:buildStressesView("stresses")
view:write("post.msh",format,false)

errorOnView(view,3)
