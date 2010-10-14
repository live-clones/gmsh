

options = gmshOptions()
options:initOptions()

options:numberSet('Mesh', 0, 'Algorithm3D', 4.0)
options:numberSet('Mesh', 0, 'Optimize', 1.0)
--options:numberSet('Mesh', 0, 'CharacteristicLengthFactor', 0.2)
options:numberSet('Mesh', 0, 'CharacteristicLengthExtendFromBoundary',  1)

print'*** create GModel from stl ***'
model = GModel()
model:load ('aortaADAPT.stl')

model:setFactory('Gmsh')

print'*** create Topology ***'
model:createTopology()

e1 = model:getEdgeByTag(1)
e2 = model:getEdgeByTag(2)
e3 = model:getEdgeByTag(3)
e4 = model:getEdgeByTag(4)
e5 = model:getEdgeByTag(5)

print'*** add Planar face ***'
f0 = model:getFaceByTag(1) 

f1 = model:addPlanarFace({{e1}})
f2 = model:addPlanarFace({{e2}}) 
f3 = model:addPlanarFace({{e3}}) 
f4 = model:addPlanarFace({{e4}}) 
f5 = model:addPlanarFace({{e5}}) 

print'*** add Volume ***'
r1 = model:addVolume({{f0,f1,f2,f3,f4,f5}});

print'*** meshing ***'
model:mesh(3);
model:save("aorta_bound_lua.msh")



