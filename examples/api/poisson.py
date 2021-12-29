import gmsh
import numpy as np
import scipy.sparse
import scipy.sparse.linalg
import sys

# This scripts solves the 2D Poisson equation '-\Delta u = f' with homogeneous
# boundary conditions using the finite element method.

# Simply run the script with
# $ python examples/api/poisson.py
# with usual gmsh line arguments, e.g., -clscale 0.5 -order 2

DEBUG = 0
RECOMBINE = 0


def debug(*args):
    if not DEBUG: return
    if sys.version_info.major == 3:
        exec ("print( *args )")
    else:
        for item in args:
            exec ("print item,")
        exec ("print")


def error(argv):
    debug(argv)
    exit(1)


def create_geometry():
    gmsh.model.add("poisson")
    surf = []
    surf.append((2, gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)))
    surf.append((2, gmsh.model.occ.addDisk(0.7, 0.5, 0, 0.1, 0.1)))
    surf.append((2, gmsh.model.occ.addRectangle(0.2, 0.4, 0, 0.2, 0.2)))
    surf, _ = gmsh.model.occ.fragment(surf, [])
    gmsh.model.occ.synchronize()

    bnd = gmsh.model.getBoundary(surf,
                                 combined=True,
                                 oriented=False,
                                 recursive=False)
    bnd = np.array(bnd)

    gmsh.model.addPhysicalGroup(2, [surf[0][1]], 2)
    gmsh.model.setPhysicalName(2, 2, 'SourceCircle')
    gmsh.model.addPhysicalGroup(2, [surf[1][1]], 3)
    gmsh.model.setPhysicalName(2, 3, 'SourceSquare')
    gmsh.model.addPhysicalGroup(2, [surf[2][1]], 4)
    gmsh.model.setPhysicalName(2, 4, 'Domain')
    gmsh.model.addPhysicalGroup(1, bnd[:, 1], 11)
    gmsh.model.setPhysicalName(1, 11, 'Boundary')

    gmsh.model.mesh.setSize(gmsh.model.getEntities(0), 0.1)
    return


def fem_solve():
    mshNodes = np.array(gmsh.model.mesh.getNodes()[0])
    numMeshNodes = len(mshNodes)
    maxNodeTag = int(np.amax(mshNodes))
    debug('numMeshNodes =', numMeshNodes, ' maxNodeTag =', maxNodeTag)

    # typNodes[tag] = {0:does not exist, 1:internal node, 2:boundary node}
    # Existing node tags are defined here. Boundary node tag are identified later.
    typNodes = np.zeros(maxNodeTag + 1, dtype=np.int32)
    for tagNode in mshNodes:
        typNodes[tagNode] = 1

    # initializations of global assembly arrays iteratively filled-in during
    # assembly
    matrowflat = np.array([], dtype=np.int32)
    matcolflat = np.array([], dtype=np.int32)
    matflat = np.array([], dtype=np.int32)
    rhsrowflat = np.array([], dtype=np.int32)
    rhsflat = np.array([], dtype=np.int32)

    # The read-in mesh is iterated over, looping successively (nested loops) over:
    # Physical groups/Geometrical entities/Element types/Elements
    vGroups = gmsh.model.getPhysicalGroups()
    for iGroup in vGroups:
        dimGroup = iGroup[0]  # 1D, 2D or 3D
        tagGroup = iGroup[1]
        namGroup = gmsh.model.getPhysicalName(dimGroup, tagGroup)
        vEntities = gmsh.model.getEntitiesForPhysicalGroup(dimGroup, tagGroup)
        for tagEntity in vEntities:
            # FIXME dimEntity should be optional when tagEntity given
            dimEntity = dimGroup
            vElementTypes = gmsh.model.mesh.getElementTypes(
                dimEntity, tagEntity)
            for elementType in vElementTypes:
                vTags, vNodes = gmsh.model.mesh.getElementsByType(
                    elementType, tagEntity)
                numElements = len(vTags)
                numGroupNodes = len(vNodes)
                enode = np.array(vNodes, dtype=np.int32).reshape(
                    (numElements, -1))
                numElementNodes = enode.shape[1]
                debug('\nIn group', namGroup, ' with tag ', tagGroup,
                      ', numElements = e =', numElements)
                debug('numGroupNodes =', numGroupNodes,
                      ', numElementNodes = n =', numElementNodes)
                debug('%enodes (e,n) =', enode.shape)

                # Assembly of stiffness matrix for all 2 dimensional elements
                # (triangles or quadrangles)
                if dimEntity == 2:
                    prop = gmsh.model.mesh.getElementProperties(elementType)
                    uvw, weights = gmsh.model.mesh.getIntegrationPoints(
                        elementType, "Gauss" + str(2 * prop[2]))
                    numcomp, sf, _ = gmsh.model.mesh.getBasisFunctions(
                        elementType, uvw, 'Lagrange')
                    weights = np.array(weights)
                    numGaussPoints = len(weights)
                    debug('numGaussPoints = g =', numGaussPoints,
                          ', %weights (g) =', weights.shape)
                    sf = np.array(sf).reshape((numGaussPoints, -1))
                    debug('%sf (g,n) =', sf.shape)
                    if sf.shape[1] != numElementNodes:
                        error('Something went wrong')
                    numcomp, dsfdu, _ = gmsh.model.mesh.getBasisFunctions(
                        elementType, uvw, 'GradLagrange')
                    # remove useless dsfdw
                    dsfdu = np.array(dsfdu).reshape(
                        (numGaussPoints, numElementNodes, 3))[:, :, :-1]
                    debug('%dsfdu (g,n,u) =', dsfdu.shape)

                    qjac, qdet, qpoint = gmsh.model.mesh.getJacobians(
                        elementType, uvw, tagEntity)
                    debug('Gauss integr:', len(qjac), len(qdet), len(qpoint),
                          '= (9, 1, 3) x', numGaussPoints, 'x', numElements)
                    qdet = np.array(qdet).reshape(
                        (numElements, numGaussPoints))
                    debug('%qdet (e,g) =', qdet.shape)
                    # remove components of dxdu useless in dimEntity dimensions (here 2D)
                    dxdu = np.array(qjac).reshape(
                        (numElements, numGaussPoints, 3, 3))[:, :, :-1, :-1]
                    # jacobian stored by row, so dxdu[i][j] = dxdu_ij = dxi/duj
                    debug('%dxdu (e,g,x,u)=', dxdu.shape)

                    # dudx[j][k] = dudx_jk = duj/dxk
                    dudx = np.linalg.inv(dxdu)
                    debug('%dudx (e,g,u,x) =', dudx.shape)
                    # sum over u = dot product
                    dsfdx = np.einsum("egxu,gnu->egnx", dudx, dsfdu)
                    debug('%dsfdx (e,g,n,x) =', dsfdx.shape)
                    # Gauss integration
                    localmat = np.einsum("egik,egjk,eg,g->eij", dsfdx, dsfdx,
                                         qdet, weights)
                    debug('%localmat (e,n,n) =', localmat.shape)

                    # The next two lines are rather obscure. See explanations at
                    # the bottom of the file.
                    matcol = np.repeat(enode[:, :, None],
                                       numElementNodes,
                                       axis=2)
                    matrow = np.repeat(enode[:, None, :],
                                       numElementNodes,
                                       axis=1)

                    matcolflat = np.append(matcolflat, matcol.flatten())
                    matrowflat = np.append(matrowflat, matrow.flatten())
                    matflat = np.append(matflat, localmat.flatten())

                    if namGroup == 'SourceCircle' or namGroup == 'SourceSquare':
                        if namGroup == 'SourceCircle':
                            load = -1
                        else:
                            load = 1
                        localrhs = load * np.einsum("gn,eg,g->en", sf, qdet,
                                                    weights)
                        rhsrowflat = np.append(rhsrowflat, enode.flatten())
                        rhsflat = np.append(rhsflat, localrhs.flatten())

                # identify boundary node
                if namGroup == 'Boundary':
                    for tagNode in vNodes:
                        typNodes[tagNode] = 2

    # Associate to all mesh nodes a line number in the system matrix, reserving
    # top lines for internal nodes and bottom lines for fixed nodes (boundary
    # nodes).
    node2unknown = np.zeros(maxNodeTag + 1, dtype=np.int32)
    index = 0
    for tagNode, typ in enumerate(typNodes):
        if typ == 1:  # not fixed
            index += 1
            node2unknown[tagNode] = index
    numUnknowns = index
    debug('numUnknowns =', numUnknowns)
    for tagNode, typ in enumerate(typNodes):
        if typ == 2:  # fixed
            index += 1
            node2unknown[tagNode] = index

    if index != numMeshNodes:
        error('Something went wrong')

    unknown2node = np.zeros(numMeshNodes + 1, dtype=np.int32)
    for node, unkn in enumerate(node2unknown):
        unknown2node[unkn] = node

    # Generate system matrix A=globalmat and right hand side b=globalrhs

    # docs.scipy.org/doc/scipy/reference/generated/scipy.sparse.coo_matrix.html
    # 'node2unknown-1' are because python numbers rows and columns from 0
    globalmat = scipy.sparse.coo_matrix(
        (matflat,
         (node2unknown[matcolflat] - 1, node2unknown[matrowflat] - 1)),
        shape=(numMeshNodes, numMeshNodes)).tocsr()

    globalrhs = np.zeros(numMeshNodes)
    for index, node in enumerate(rhsrowflat):
        globalrhs[node2unknown[node] - 1] += rhsflat[index]

    debug('%globalmat =', globalmat.shape, ' %globalrhs =', globalrhs.shape)

    # Solve linear system Ax=b
    sol = scipy.sparse.linalg.spsolve(globalmat[:numUnknowns, :numUnknowns],
                                      globalrhs[:numUnknowns])
    sol = np.append(sol, np.zeros(numMeshNodes - numUnknowns))
    debug('%sol =', sol.shape)

    # Export solution
    sview = gmsh.view.add("solution")
    gmsh.view.addModelData(sview, 0, "", "NodeData", unknown2node[1:],
                           sol[:, None])
    return


gmsh.initialize(sys.argv)
create_geometry()

if RECOMBINE:
    gmsh.model.mesh.setRecombine(2, 2)
    gmsh.model.mesh.setRecombine(2, 3)
    gmsh.model.mesh.setRecombine(2, 4)

gmsh.model.mesh.generate(2)

if DEBUG:
    gmsh.write('poisson.msh')

fem_solve()

gmsh.option.setNumber("View[0].IntervalsType", 3)
gmsh.option.setNumber("View[0].NbIso", 20)
if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()

## Explanation for the serialization of elementary matrices.
##
## node = numpy.array([[1,2,3]]) # one element with nodes 1,2 and 3
## col = numpy.repeat(enode[:,:,None],3,axis=2)
## row = numpy.repeat(enode[:,None,:],3,axis=1)
## >>> col
## array([[[1, 1, 1],
##         [2, 2, 2],
##         [3, 3, 3]]])
## >>> row
## array([[[1, 2, 3],
##         [1, 2, 3],
##         [1, 2, 3]]])
