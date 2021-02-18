import gmsh
import sys

gmsh.initialize(sys.argv)

gmsh.model.occ.addBox(0,0,0, 1,1,1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(3)

gmsh.plugin.setNumber("AnalyseMeshQuality", "ICNMeasure", 1.)
gmsh.plugin.setNumber("AnalyseMeshQuality", "CreateView", 1.)
gmsh.plugin.run("AnalyseMeshQuality")

dataType, tags, data, time, numComp = gmsh.view.getModelData(0, 0)

print('ICN for element {0} = {1}'.format(tags[0], data[0]))

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
