model = GModel()
model:load ('stommel_square.msh')
order=1
dimension = 2
claw = dgConservationLawShallowWater2d()
claw:addBoundaryCondition('Wall',claw:newBoundaryWall())
groups = dgGroupCollection(model, dimension, order)
-- groups:split...
groups:buildGroupsOfInterfaces()
solution = dgDofContainer(groups, claw:getNbFields())
solution:exportMsh('output/init')
rk=dgRungeKutta()

for i=1,100000 do
  norm = rk:iterate33(claw,150*(3/(2.*order+1)/2),solution)
  if ( i%100 ==0 ) then
    print ('iter ', i, norm)
  end
  if ( i%100 ==0 ) then
    solution:exportMsh(string.format('output/solution-%06d',i))
  end
end
