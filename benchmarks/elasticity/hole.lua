a = 0.05
T = 10e9
E = 200e9
nu = 0.3
-- --[[
--pull on sides
function analyticalSolution(x,y,z)
  local r = math.sqrt(x*x+y*y)
  local theta = math.atan2(y,x)
  local ar = a/r
  local ur = T*r/(2*E) * (1-nu+(1+nu)*ar^2 + math.cos(2*theta)*((1+nu)*(1-ar^4)+4*ar^2))
  local utheta = - T*r/(2*E) * math.sin(2*theta)*((1+nu)*(1+ar^4)+2*(1-nu)*ar^2)
  return {ur*math.cos(theta)-utheta*math.sin(theta), ur*math.sin(theta)+utheta*math.cos(theta),0}
end
-- --]]

 --[[
--pull on corner
function analyticalSolution(x,y,z)
  local r = math.sqrt(x*x+y*y)
  local theta = math.atan2(y,x)
  local ar = a/r
  local ur = math.sin(2*theta)*T*r/E * (1+nu+4*ar^2-ar^4)
  local utheta = math.cos(2*theta)*T*r/E * (1+nu + 2*(1-nu)*ar^2+ar^4) 
  return {ur*math.cos(theta)-utheta*math.sin(theta), ur*math.sin(theta)+utheta*math.cos(theta),0}
end
 --]]

function analyticalSolutionX (x,y,z)
  return analyticalSolution(x,y,z)[1]
end

function analyticalSolutionY (x,y,z)
  return analyticalSolution(x,y,z)[2]
end


function errorOnView (view, dim, solutionFunction)
  local basis = polynomialBasis.find(2)
  local gaussPoints = fullMatrix(1,1)
  local gaussWeights = fullMatrix(1,1)
  gaussIntegration.getTriangle(3,gaussPoints,gaussWeights)

  local nnodes = 3 -- only triangles
  local viewData = view:getData()
  local values = fullMatrix(nnodes,dim)
  local nodes = fullMatrix(nnodes,3)
  local gaussXYZ = fullMatrix(gaussPoints:size1(),3)
  local gaussValues = fullMatrix(gaussPoints:size1(),dim)
  local nEntities = viewData:getNumEntities(-1)
  local psi = fullMatrix(gaussPoints:size1(),3)

  local face = m:getFaceByTag(1)

  local errorViewFactory = PViewFactory("error", "ElementNodeData",m, 0, 1)

  basis:f(gaussPoints,psi)
  local nGaussPoints = gaussPoints:size1()
  local totalError = 0
  local errMat = fullMatrix(3,1)
  for i=0,nEntities-1 do 
    local nElements = viewData:getNumElements(-1,i)
    for j=0,nElements-1 do
      local element = face:getMeshElement(j)
      if(viewData:getNumNodes(0,i,j)==nnodes) then
        viewData:getAllValuesForElement(0,i,j,values)
        viewData:getAllNodesForElement(0,i,j,nodes)
        gaussXYZ:gemm(psi,nodes,1,0)
        gaussValues:gemm(psi,values,1,0)
        for k=0,nGaussPoints-1 do
          local sol = solutionFunction(gaussXYZ:get(k,0),gaussXYZ:get(k,1),gaussXYZ:get(k,2))
          local err = 0
          for l=0,dim-1 do
            err = err + (sol[l+1]-gaussValues:get(k,l))^2
          end
          totalError = totalError + err*gaussWeights:get(k,0)*element:getJacobianDeterminant(gaussPoints:get(k,0),gaussPoints:get(k,1),gaussPoints:get(k,2))
        end
        local numVertices = element:getNumVertices()
        for k=0,numVertices-1 do
          local vertex = element:getVertex(k)
          local sol = solutionFunction(vertex:x(), vertex:y(), vertex:z())
          local err = 0
          for l=0,dim-1 do
            err = err + (sol[l+1]-values:get(k,l))^2
          end
          errMat:set(k,0,err)
        end
        errorViewFactory:setEntry(element:getNum(),errMat)
      end
    end
  end
  errorViewFactory:createView()
  return math.sqrt(totalError)
end

m = GModel()
m:load("hole.geo")
m:load("hole.msh")
e = elasticitySolver(m,1)
e:addElasticDomain (6, E, nu)

--e:addDirichletBCLua(1,5,0,"analyticalSolutionX")
--e:addDirichletBCLua(1,5,1,"analyticalSolutionY")
e:addNeumannBC (1,5,{0,0,0})
e:addDirichletBCLua(1,1,0,"analyticalSolutionX")
e:addDirichletBCLua(1,1,1,"analyticalSolutionY")
e:addDirichletBCLua(1,2,0,"analyticalSolutionX")
e:addDirichletBCLua(1,2,1,"analyticalSolutionY")
e:addDirichletBCLua(1,3,0,"analyticalSolutionX")
e:addDirichletBCLua(1,3,1,"analyticalSolutionY")
e:addDirichletBCLua(1,4,0,"analyticalSolutionX")
e:addDirichletBCLua(1,4,1,"analyticalSolutionY")

sys = linearSystemCSRTaucs()
e:assemble(sys)
sys:systemSolve()
e:postSolve()
--view = e:buildVonMisesView("vonMises")
view = e:buildDisplacementView("displacement")

print(errorOnView(view,3,analyticalSolution))
