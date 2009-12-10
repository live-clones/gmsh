
model = GModel()
model:load ('stommel_square.msh')
dg = dgSystemOfEquations (model)
dg:setOrder (1)
dg:setConservationLaw('ShallowWater2d')
dg:addBoundaryCondition('Wall','Wall')
dg:setup()

dg:exportSolution('output/solution_00000')

for i=1,1000 do
  norm = dg:RK44(50)
  if ( i%100 ==0 ) then
    print ('iter ', i, norm)
    dg:exportSolution(string.format('output/solution-%05d',i))
  end
end
