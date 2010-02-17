model = GModel()
model:load ('stommel_square.msh')
order=3
dimension = 2
claw = dgConservationLawShallowWater2d()
claw:addBoundaryCondition('Wall',claw:newBoundaryWall())
groups = dgGroupCollection(model, dimension, order)
-- groups:split...
groups:buildGroupsOfInterfaces()
solution = dgDofContainer(groups, claw:getNbFields())
--[[
a = fullMatrix(3,1);
a:set(0,0, 1.);
a:set(1,0, 2.);
a:set(2,0, 3.);
f = functionConstant(a):getName()
solution:L2Projection(f)
solution:exportMsh('output/init')
]]--

for i=1,00000 do
  norm = dg:RK44(150*(3/(2.*order+1)))
  if ( i%100 ==0 ) then
    print ('iter ', i, norm)
  end
  if ( i%100 ==0 ) then
    solution:exportMsh(string.format('output/solution-%06d',i))
  end
end
