#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 19 11:37:14 2019

@author: badia
"""
import gmsh
import sys
import numpy as np

INTEGRATION = 'Gauss2'
model = gmsh.model
factory = model.occ
order=2
#gmsh.initialize()
#gmsh.option.setNumber("General.Terminal", 1)
#
#gmsh.model.add("square_element");
#
## add discrete surface with tag 1
#gmsh.model.addDiscreteEntity(2, 1)
#
## add 4 mesh nodes
#gmsh.model.mesh.setNodes(2, 1,
#                         [1, 2, 3, 4], # node tags: 1, 2, 3, and 4
#                         [0., 0., 0., # coordinates of node 1
#                          1., 0., 0., # coordinates of node 2
#                          1., 1., 0., # ...
#                          0., 1., 0.])
#
## add 1 quadrangle
#gmsh.model.mesh.setElements(2, 1,
#                            [3], # single type : 4-node Quadrangle
#                            [[1]], # Quadrangle tag: 1 
#                            [[1, 2, 3,4]]) #Quadrangle 1: nodes 1, 2, 3,4
#                              
#
## export the mesh ; use explore.py to read and examine the mesh
#gmsh.write("square_element.msh")
#vElementTypes = model.mesh.getElementTypes(2,1)
#elementType=vElementTypes[0]
#bs, we ,ky=model.mesh.getHierarchicalBasisForElements(INTEGRATION,vElementTypes[0], 'Legendre',order) 
#print(bs)
#print(ky)
#info=model.mesh.getInformationForElements(ky,order, "Legendre")
#print(info)
#gmsh.finalize()


#test_2

#gmsh.initialize(sys.argv)
#gmsh.model.add("square_element")
#factory = model.occ
#model.add("mesh_square")
#surf = factory.addRectangle(0, 0, 0, 1, 1)
#factory.synchronize()
#model.addPhysicalGroup(2, [surf], 4)
#model.setPhysicalName(2, 4, 'Domain')
#
#model.mesh.setRecombine(2,1)
#model.mesh.generate(2)
#gmsh.write("mesh_square.msh")
#bs, we ,ky=model.mesh.getHierarchicalBasisForElements(INTEGRATION,3, 'Legendre',order) 
#print(len(bs))
#print(bs)
#print(len(ky))
#print(ky)
#info=model.mesh.getInformationForElements(ky,order, "Legendre")
#print(info)
#gmsh.finalize()

#test3
#
def create_geometry():
    model.add("poisson")
    surf = []
   
    surf.append((2, factory.addRectangle(0, 0, 0, 1, 1)))
    surf.append((2, factory.addDisk(0.7, 0.5, 0, 0.1, 0.1)))
   
    surf.append((2, factory.addRectangle(0.2, 0.4, 0, 0.2, 0.2)))
    
    surf, _ = factory.fragment(surf, [])
    
    factory.synchronize()
    
    bnd = model.getBoundary(surf, combined=True, oriented=False, recursive=False)
    bnd = np.array(bnd)
    
    model.addPhysicalGroup(2, [surf[0][1]], 2)
    model.setPhysicalName(2, 2, 'SourceCircle')
    model.addPhysicalGroup(2, [surf[1][1]], 3)
    model.setPhysicalName(2, 3, 'SourceSquare')
    model.addPhysicalGroup(2, [surf[2][1]], 4)
    model.setPhysicalName(2, 4, 'Domain')
    model.addPhysicalGroup(1, bnd[:,1], 11)
    model.setPhysicalName(1, 11, 'Boundary')
    model.mesh.setSize(model.getEntities(0), 0.1);
    return


gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 0 )
create_geometry()
model.mesh.setRecombine(2,2)
model.mesh.setRecombine(2,3)
model.mesh.setRecombine(2,4)
model.mesh.generate(2)
gmsh.write("poisson.msh")
   
sf, weights ,ky = model.mesh.getHierarchicalBasisForElements(INTEGRATION,3, 'Legendre',
                                                                                order)           
#print(sf)
print(len(sf))
#print(ky)
info=model.mesh.getInformationForElements(ky,order, "Legendre")
#print(info)
gmsh.finalize()
