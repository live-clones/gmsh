#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sat Feb 23 19:33:36 2019

@author: badia
"""

import gmsh
import numpy as np
import scipy.sparse
import scipy.sparse.linalg
import sys

# This scripts solves the 2D Poisson equation '-\Delta u = f' with homogeneous
# boundary conditions using the finite element method and the Legendre Basis.

# Simply run the script with
# $ python poisson.py


INTEGRATION = 'Gauss8'
RECOMBINE = 1
order=4#polynomial order

def create_geometry_legendre():
    model.add("poisson_legendre")
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

def nodeBelongsBoundary(node,table): #identify boundary node
    for i in range(len(table)):
        if(node==table[i]):
            return 1;
    return 0;
def assignNumberToFunction(tableConnectivity,key):
    for clee, value in tableConnectivity.items():
       if(clee[0]==key[0] and clee[1]==key[1]):
           return value
    return len(tableConnectivity)
        



def fem_solve_legendre():
    # initializations of global assembly arrays iteratively filled-in during
    # assembly
    row = []
    col= []
    mat   = []
    rhsflat=[]
    rhsrow=[]
    rhscol=[]
    globalrhs=[]
    dimGroup = 1 
    tagGroup = 11
    if RECOMBINE :
        nddl=4+4*(order-1)+(order-1)*(order-1)
        nEdge=4
        nVertex=4
    else :
        nddl=3+3*(order-1)+int((order-1)*(order-2)/2)
        nEdge=3
        nVertex=3
    vEntities = model.getEntitiesForPhysicalGroup(dimGroup, tagGroup)
    tagNodeInBoundary=[]
    for tagEntity in vEntities:
          dimEntity = dimGroup
          vElementTypes = model.mesh.getElementTypes(dimEntity,tagEntity)
          for elementType in vElementTypes:
             vTags, vNodes = model.mesh.getElementsByType(elementType, tagEntity)
             for r in range( len(vNodes)):
                 tagNodeInBoundary.append(vNodes[r]);
    
    vGroups = model.getPhysicalGroups()
    allConnectivity={}#assign a number to each key 
    # The read-in mesh is iterated over, looping successively (nested loops) over:
    # Physical groups/Geometrical entities/Element types/Elements
    for iGroup in vGroups:
        dimGroup = iGroup[0] # 1D, 2D or 3D
        tagGroup = iGroup[1]
        namGroup = model.getPhysicalName(dimGroup, tagGroup)
        vEntities = model.getEntitiesForPhysicalGroup(dimGroup, tagGroup)
        for tagEntity in vEntities:
            # FIXME dimEntity should be optional when tagEntity given
            dimEntity = dimGroup
            vElementTypes = model.mesh.getElementTypes(dimEntity,tagEntity)
            for elementType in vElementTypes:
                vTags, vNodes = model.mesh.getElementsByType(elementType, tagEntity)
                numElements = len(vTags)
                # Assembly of stiffness matrix for all 2 dimensional elements
                # (triangles or quadrangles)
                if dimEntity==2 :
                    sf, weights ,ky = model.mesh.getBasisFunctionsForElements(INTEGRATION,elementType, 'Legendre',
                                                                                 order,tagEntity)            
                   
                    numGaussPoints = len(weights)
                    weights=np.array(weights)
                    sf = np.array(sf).reshape((numGaussPoints,numElements,-1))    
                    dsf,_, _ = model.mesh.getBasisFunctionsForElements(INTEGRATION,elementType,
                                                                         'GradLegendre',order,tagEntity) 
                 
                   
                    dsf = np.array(dsf).reshape((numGaussPoints,numElements,-1))
                    qjac, qdet, qpoint = model.mesh.getJacobians(
                        elementType, INTEGRATION, tagEntity)
                    qdet = np.array(qdet).reshape((numElements, numGaussPoints))
                    dxdu = np.array(qjac).reshape((numElements, numGaussPoints, 3, 3))[:,:,:-1,:-1]
                    dudx = np.linalg.inv(dxdu)
                    dsfdx=[] 
                    for k1 in range(  numElements):
                        b=[]
                        for k2 in range(  numGaussPoints):       
                             li=[]
                             a=dudx[k1][k2]
                             gradientVector=dsf[k2][k1]
                             k3=0
                             while (k3< len(gradientVector)):
                                 gradient=np.array([gradientVector[k3],gradientVector[k3+1]])
                                 k3=k3+3
                                 produit=np.array([a[0][0]*gradient[0]+a[0][1]*gradient[1],a[1][0]*gradient[0]+a[1][1]*gradient[1] ])
                                 li.append(produit)
                             b.append(li)
                        dsfdx.append(b)
                    dsfdx=np.array(dsfdx)
                    # Gauss integration
                    localmat = np.einsum("egik,egjk,eg,g->eij", dsfdx, dsfdx, qdet, weights)
                    #connectivity information
                    connectivityinEntity=[]
                    belongBoundaryEntity=[]
                    for i in range(numElements):
                        Elementconnectivity=[]
                        belongBoundary=[]
                        for j in range(nVertex):
                                   if(nodeBelongsBoundary(ky[j+i*nddl][1], tagNodeInBoundary)):
                                        belongBoundary.append(-1)
                                   else:
                                        belongBoundary.append(0)
                                   num=assignNumberToFunction(allConnectivity, ky[j+i*nddl])
                                   Elementconnectivity.append(num)
                                   allConnectivity[tuple(ky[j+i*nddl])]=num
                                  
                        for k in range(nEdge):
                            for j in range(nVertex+k*(order-1),nVertex+(k+1)*(order-1)):
                                
                                 if(nodeBelongsBoundary(ky[k][1], tagNodeInBoundary) and nodeBelongsBoundary(ky[(k+1)%4][1], tagNodeInBoundary) ):
                                     belongBoundary.append(-1)
                                 else:
                                     belongBoundary.append(0)
                                 num=assignNumberToFunction(allConnectivity, ky[j+i*nddl])
                                 Elementconnectivity.append(num)
                                 allConnectivity[tuple(ky[j+i*nddl])]=num
                        
                        for j in range(nVertex+nEdge*(order-1),nddl):
                                belongBoundary.append(0)
                                num=assignNumberToFunction(allConnectivity, ky[j+i*nddl])
                                Elementconnectivity.append(num)
                                allConnectivity[tuple(ky[j+i*nddl])]=num   
                        connectivityinEntity.append(Elementconnectivity)
                        belongBoundaryEntity.append(belongBoundary)
                    if namGroup == 'SourceCircle' or namGroup == 'SourceSquare':
                        if namGroup == 'SourceCircle':
                            load = -1
                        else:
                            load = 1
                        localrhs = load * np.einsum("gen,eg,g->en", sf, qdet, weights)
                    #assembling
                    for e in range (numElements):
                        for iloc in range(nddl):
                            igl=connectivityinEntity[e][iloc]
                            for jloc in range(nddl):
                                jgl=connectivityinEntity[e][jloc]
                                row.append(igl)
                                col.append(jgl)
                                if (belongBoundaryEntity[e][iloc]!=-1 and belongBoundaryEntity[e][jloc]!=-1 ):       
                                    mat.append(localmat[e][iloc][jloc])
                                else:
                                    if(igl!=jgl):
                                        mat.append(0.)
                                    else:
                                        mat.append(1)
                            if (belongBoundaryEntity[e][iloc]!=-1):
                                 if(  namGroup == 'SourceCircle' or namGroup == 'SourceSquare'):
                                     rhsflat.append( localrhs[e][iloc])
                                 else:
                                     rhsflat.append( 0)                               
                            else:
                                 rhsflat.append( 0.)
                            rhsrow.append(igl)
                            rhscol.append(0)
             
                            
    mat=np.array(mat)
    row=np.array(row)
    col=np.array(col)
    rhsflat=np.array(rhsflat)
    rhsrow=np.array(rhsrow)
    rhscol=np.array(rhscol)
    globalmat = scipy.sparse.coo_matrix((mat,(row,col) ),  shape=(len(allConnectivity), len(allConnectivity))).tocsr() 
    globalrhs = scipy.sparse.coo_matrix(
        (rhsflat, (rhsrow,rhscol) )).toarray()
    # Solve linear system Ax=b
    sol =scipy.sparse.linalg.spsolve(globalmat,  globalrhs)
#    # Export solution. Keep only the vertices value
    solgraph=[]
    nodegraph=[]
    for i in range(len(sol)):
        if (list(allConnectivity)[i][0]==2):
            solgraph.append([sol[i]])
            nodegraph.append(list(allConnectivity)[i][1])
    solgraph=np.array(solgraph)
    nodegraph=np.array(nodegraph)
    sview = gmsh.view.add("solution")
    gmsh.view.addModelData(sview, 0, "", "NodeData", nodegraph,        solgraph)
    return


model = gmsh.model
factory = model.occ
gmsh.initialize(sys.argv)
create_geometry_legendre()
if RECOMBINE:
    model.mesh.setRecombine(2,2)
    model.mesh.setRecombine(2,3)
    model.mesh.setRecombine(2,4)
model.mesh.generate(2)
gmsh.write("poisson_legendre.msh")
fem_solve_legendre()
sview= gmsh.view.add("solution")
gmsh.option.setNumber("View[0].IntervalsType", 3)
gmsh.option.setNumber("View[0].NbIso", 20)
gmsh.fltk.run()

gmsh.finalize()