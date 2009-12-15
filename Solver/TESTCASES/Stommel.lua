

model = GModel()
model:load ('stommel_square.msh')
print('load..')

dg = dgSystemOfEquations (model)
dg:setOrder (3)


dg:setConservationLaw('ShallowWater2d')
dg:addBoundaryCondition('Wall','Wall')
dg:setup()

dg:exportSolution('output/solution_00000')

for i=1,1000 do
  norm = dg:RK44(80*(3/(2.*order+1)))
  if ( i%10 ==0 ) then
    print ('iter ', i, norm)
  end
  if ( i%100 ==0 ) then
    dg:exportSolution(string.format('output/solution-%05d',i))
  end
end
