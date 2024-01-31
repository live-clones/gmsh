import gmsh
import os

gmsh.initialize()

# load step file
path = os.path.dirname(os.path.abspath(__file__))
gmsh.open(os.path.join(path, 'as1-tu-203.stp'))

# get all model entities
ent = gmsh.model.getEntities()

gmsh.model.occ.healShapes()

gmsh.model.occ.synchronize()

gmsh.finalize()
