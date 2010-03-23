model = GModel()
model:load ('square2.msh')
order = 1
dimension = 2

law = dgConservationLawAdvectionDiffusion:diffusionLaw(functionConstant({1}))
law:addBoundaryCondition('Border',law:new0FluxBoundary())
groups = dgGroupCollection(model, dimension, order)
groups:buildGroupsOfInterfaces()
solution = dgDofContainer(groups, law:getNbFields())
residual = dgDofContainer(groups, law:getNbFields())
r = dgResidualVolume (law)
g = groups:getElementGroup(0)
j = fullMatrix(3,3*g:getNbElements())
r:compute1GroupWithJacobian(g,solution:getGroupProxy(0),residual:getGroupProxy(0),j)
j:print("test")
