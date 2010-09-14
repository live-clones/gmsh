

options = gmshOptions()
options:initOptions()

options:numberSet('Mesh', 0, 'Algorithm3D', 4.0)
options:numberSet('Mesh', 0, 'Optimize', 1.0)
--options:numberSet('Mesh', 0, 'CharacteristicLengthFactor', 0.2)
options:numberSet('Mesh', 0, 'Mesh.CharacteristicLengthExtendFromBoundary',  1)

print'*** create GModel from stl ***'
model = GModel()
model:load ('aortaADAPT.stl')

print'*** create Topology ***'
model:createTopology()

e1 = model:getEdgeByTag(1)
e2 = model:getEdgeByTag(2)
e3 = model:getEdgeByTag(3)
e4 = model:getEdgeByTag(4)
e5 = model:getEdgeByTag(5)

print'*** add Planar face ***'
f0 = model:getFaceByTag(1) 

f1 = model:addGeoPlanarFace({{e1}})
f2 = model:addGeoPlanarFace({{e2}}) 
f3 = model:addGeoPlanarFace({{e3}}) 
f4 = model:addGeoPlanarFace({{e4}}) 
f5 = model:addGeoPlanarFace({{e5}}) 

print'*** add Volume ***'
r1 = model:addGeoVolume({{f0,f1,f2,f3,f4,f5}});

print'*** meshing ***'
model:mesh(3);
model:save("aorta_bound_lua.msh")



