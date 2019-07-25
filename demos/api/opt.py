import gmsh
import sys

if len(sys.argv) < 2:
    print "Usage: " + sys.argv[0] + " file.msh"
    exit(0)

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)
gmsh.open(sys.argv[1])

# Second arg force optimization of discrete volumes
gmsh.model.mesh.optimize('Optimize', True)
# gmsh.model.mesh.optimize('OptimizeNetgen', True)

gmsh.write('opt.msh')
