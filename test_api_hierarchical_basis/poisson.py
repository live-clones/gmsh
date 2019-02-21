import gmsh
import numpy as np
import scipy.sparse
import scipy.sparse.linalg
import sys

# This scripts solves the 2D Poisson equation '-\Delta u = f' with homogeneous
# boundary conditions using the finite element method.

# Simply run the script with
# $ python poisson.py


INTEGRATION = 'Gauss1'
RECOMBINE = 1
order=1 #polynomial order
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

def fem_solve():
    mshNodes = np.array(model.mesh.getNodes()[0])
    numMeshNodes = len(mshNodes)
   
    maxNodeTag = np.amax(mshNodes)
    # typNodes[tag] = {0:does not exist, 1:internal node, 2:boundary node}
    # Existing node tags are defined here. Boundary node tag are identified later.
    typNodes = np.zeros(maxNodeTag+1, dtype=np.int32)
    for tagNode in mshNodes:
        typNodes[tagNode] = 1
    # initializations of global assembly arrays iteratively filled-in during
    # assembly
    matrowflat = np.array([], dtype=np.int32)
    matcolflat = np.array([], dtype=np.int32)
    matflat    = np.array([], dtype=np.int32)
    rhsrowflat = np.array([], dtype=np.int32)
    rhsflat    = np.array([], dtype=np.int32)

    # The read-in mesh is iterated over, looping successively (nested loops) over:
    # Physical groups/Geometrical entities/Element types/Elements
    vGroups = model.getPhysicalGroups()
    for iGroup in vGroups:
        dimGroup = iGroup[0] # 1D, 2D or 3D
        tagGroup = iGroup[1]
        namGroup = model.getPhysicalName(dimGroup, tagGroup)
#        print("Nom groupe")
#        print(namGroup)
#        print(dimGroup)
        vEntities = model.getEntitiesForPhysicalGroup(dimGroup, tagGroup)

        for tagEntity in vEntities:
            # FIXME dimEntity should be optional when tagEntity given
            dimEntity = dimGroup
            vElementTypes = model.mesh.getElementTypes(dimEntity,tagEntity)
#            print("Entitee")
#            print(tagEntity)
            for elementType in vElementTypes:

                vTags, vNodes = model.mesh.getElementsByType(elementType, tagEntity)
                numElements = len(vTags)
                enode = np.array(vNodes).reshape((numElements,-1))
                numElementNodes = enode.shape[1]
#                print("type element")
#                print(elementType)
#            
                # Assembly of stiffness matrix for all 2 dimensional elements
                # (triangles or quadrangles)
                if dimEntity==2 :
                    #uvwo, numcomp, sf
                    sf, weights ,ky = model.mesh.getHierarchicalBasisForElements(INTEGRATION,elementType, 'Legendre',
                                                                                 order,tagEntity)                              
                    # only keep the Gauss weights
                    print(sf)
                    numGaussPoints = len(weights)
                    weights=np.array(weights)
                    sf = np.array(sf).reshape((numGaussPoints, -1))
                    print(sf)

#                    dsf,_, _ = model.mesh.getHierarchicalBasisForElements(INTEGRATION,elementType,
#                                                                         'GradLegendre',order,tagEntity)    
#                    
#                    dsf = np.array(dsf).reshape(
#                        (numGaussPoints,numElementNodes,2))
#                   
#                    qjac, qdet, qpoint = model.mesh.getJacobians(
#                        elementType, INTEGRATION, tagEntity)
#                  
#                    qdet = np.array(qdet).reshape((numElements, numGaussPoints))
#                  
#                    # remove components of dxdu useless in dimEntity dimensions (here 2D)
#                    dxdu = np.array(qjac).reshape(
#                        (numElements, numGaussPoints, 3, 3))[:,:,:-1,:-1]
#                    # jacobien store by row, so dxdu[i][j] = dxdu_ij = dxi/duj
#                 
#                    # dudx[j][k] = dudx_jk = duj/dxk
#                    dudx = np.linalg.inv(dxdu)
#                   
#                    # sum over u = dot product
#                    dsfdx  = np.einsum("egxu,gnu->egnx",dudx,dsfdu);
#                   
#                    # Gauss integration
#                    localmat = np.einsum("egik,egjk,eg,g->eij", dsfdx, dsfdx, qdet,
#                                         weights)
#                    
#                    # The next two lines are rather obscure. See explanations at
#                    # the bottom of the file.
#                    matcol = np.repeat(enode[:,:,None],numElementNodes,axis=2)
#                    matrow = np.repeat(enode[:,None,:],numElementNodes,axis=1)
#
#                    matcolflat = np.append(matcolflat, matcol.flatten())
#                    matrowflat = np.append(matrowflat, matrow.flatten())
#                    matflat = np.append(matflat, localmat.flatten())
#                    if namGroup == 'SourceCircle' or namGroup == 'SourceSquare':
#                        if namGroup == 'SourceCircle':
#                            load = -1
#                        else:
#                            load = 1
#                        localrhs = load * np.einsum("gn,eg,g->en", sf, qdet, weights)
#                        rhsrowflat = np.append(rhsrowflat, enode.flatten())
#                        rhsflat = np.append(rhsflat, localrhs.flatten())
#
#                # identify boundary node
#                if namGroup == 'Boundary':
#                    for tagNode in vNodes:
#                        typNodes[tagNode] = 2
#
#    # Associate to all mesh nodes a line number in the system matrix, reserving
#    # top lines for internal nodes and bottom lines for fixed nodes (boundary
#    # nodes).
#    node2unknown = np.zeros(maxNodeTag+1, dtype=np.int32)
#    index = 0
#    for tagNode,typ in enumerate(typNodes):
#        if  typ == 1: # not fixed
#            index += 1
#            node2unknown[tagNode] = index
#    numUnknowns = index
#   
#    for tagNode,typ in enumerate(typNodes):
#        if  typ == 2: # fixed
#            index += 1
#            node2unknown[tagNode] = index
#
#  
#    unknown2node = np.zeros(numMeshNodes+1, dtype=np.int32)
#    for node, unkn in enumerate(node2unknown):
#        unknown2node[unkn] = node
#
#    # Generate system matrix A=globalmat and right hand side b=globalrhs
#
#    # docs.scipy.org/doc/scipy/reference/generated/scipy.sparse.coo_matrix.html
#    # 'node2unknown-1' are because python numbers rows and columns from 0
#    globalmat = scipy.sparse.coo_matrix(
#        (matflat, (node2unknown[matcolflat]-1,node2unknown[matrowflat]-1) ),
#        shape=(numMeshNodes, numMeshNodes)).tocsr()
#
#    globalrhs = np.zeros(numMeshNodes)
#    for index,node in enumerate(rhsrowflat):
#        globalrhs[node2unknown[node]-1] += rhsflat[index]
#
#    # Solve linear system Ax=b
#    sol = scipy.sparse.linalg.spsolve(globalmat[:numUnknowns,:numUnknowns],
#                                      globalrhs[:numUnknowns])
#    sol = np.append(sol, np.zeros(numMeshNodes-numUnknowns))
#   
#    # Export solution
#    sview = gmsh.view.add("solution")
#    gmsh.view.addModelData(sview, 0, "", "NodeData", unknown2node[1:],
#                           sol[:,None])
    return


model = gmsh.model
factory = model.occ
gmsh.initialize()
create_geometry()
if RECOMBINE:
    model.mesh.setRecombine(2,2)
    model.mesh.setRecombine(2,3)
    model.mesh.setRecombine(2,4)
model.mesh.generate(2)
gmsh.write("poisson.msh")
fem_solve()
#gmsh.option.setNumber("View[0].IntervalsType", 3)
#gmsh.option.setNumber("View[0].NbIso", 20)
#gmsh.fltk.run()

gmsh.finalize()
