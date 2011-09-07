from dgpy import *

gmodel = GModel()
gmodel.load("Bifurcation3D.msh")

curvature = Curvature.getInstance()
curvature.setGModel(gmodel)
curvature.computeCurvature_Rusinkiewicz()

groups = dgGroupCollection(gmodel, 3, 1)

curvDof = dgDofContainer(groups, 1)
curvDof.setAll(10)

groups.buildGroupsOfInterfaces()

for iFG in range(groups.getNbFaceGroups()):
  fGroup = groups.getFaceGroup(iFG)
  cGroup = fGroup.getGroupOfConnections(0)
  if (fGroup.getPhysicalTag() == "Wall"):
    proxy = curvDof.getGroupProxy(cGroup.getGroupOfElements())
    for iFace in range (fGroup.getNbElements()):
      face = fGroup.getFace(iFace)
      elementId = cGroup.getElementId(iFace)
      element = cGroup.getElement(iFace)
      closure = cGroup.getClosure(iFace)
      for iVertex in range (face.getNumVertices()):
        vertex = face.getVertex(iVertex)
        curv = curvature.getAtVertex(vertex)
        proxy.set(closure[iVertex], elementId, curv)

curvDof.exportMsh("curv3D")


coefnu = functionConstant(1)
law = dgConservationLawAdvectionDiffusion.diffusionLaw(coefnu)
law.addBoundaryCondition('Wall',law.newOutsideValueBoundary("",curvDof.getFunction()))
law.addBoundaryCondition('Side',law.new0FluxBoundary())
law.addBoundaryCondition('none',law.new0FluxBoundary())

solution = dgDofContainer(groups, 1)
sys = linearSystemPETScBlockDouble()
sys.setParameter("petscOptions", "-pc_type ilu")
dof = dgDofManager.newDGBlock(groups, 1, sys)
solver = dgDIRK(law, dof, 2)
solver.getNewton().setVerb(10)
solver.getNewton().setAtol(1e-10)
solver.iterate(solution, 1 , 0)
solution.exportMsh("curv3D")
