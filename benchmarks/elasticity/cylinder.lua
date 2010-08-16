function neumann( XYZ, NXYZ, FCT )
  for i=0,FCT:size1()-1 do
    nx = NXYZ:get(i,0)
    ny = NXYZ:get(i,1)
    nz = NXYZ:get(i,2)
    print('nx= ', nx, 'ny= ', ny, 'nz= ',nz);
    FCT:set(i,0, nx)
    FCT:set(i,1, ny)
    FCT:set(i,2, nz) 
  end
end

E = 200e5
nu = 0.3
xyz = functionCoordinates.get()
nxyz = functionNormals.get()

NEUM = functionLua(3, 'neumann', {xyz,nxyz})


m = GModel()
m:load("cylinder.geo")
m:load("cylinder.msh")
e = elasticitySolver(m,1)
e:addElasticDomain (6, E, nu)

print('---> creating elastic solver')
e = elasticitySolver(m,1)
e:addElasticDomain (1, E, nu)
e:addDirichletBC (2,100,0,1)
e:addDirichletBC (2,100,1,0)
e:addDirichletBC (2,100,2,0)
e:addDirichletBC (2,200,0,0)
e:addDirichletBC (2,200,1,0)
e:addDirichletBC (2,200,2,0)
--e:addNeumannBC (2,300,{10,0,0})
--e:addNeumannBC (2,300,{0,0,0})
--e:addNeumannBCFct (2,300,NEUM)


sys = linearSystemCSRTaucs()

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

view2 = e:buildDisplacementView("displacements")
view2:write("disp.msh",format,false)

