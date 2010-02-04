model = GModel()
model:load ('stommel_square.msh')
dg = dgSystemOfEquations (model)
order=3
dg:setOrder (order)
claw = dgConservationLawShallowWater2d()
claw:addBoundaryCondition('Wall',claw:newBoundaryWall())
dg:setConservationLaw(claw)
dg:setup()

dg:exportSolution('output/init')

for i=1,100000 do
  norm = dg:RK44(150*(3/(2.*order+1)))
  if ( i%100 ==0 ) then
    print ('iter ', i, norm)
  end
  if ( i%100 ==0 ) then
    dg:exportSolution(string.format('output/solution-%06d',i))
  end
end
