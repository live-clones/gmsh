import gmsh
import sys

gmsh.initialize()

# load step file
gmsh.open('as1-tu-203.stp')

# get all model entities
ent = gmsh.model.getEntities()

physicals = {}
for e in ent:
    n = gmsh.model.getEntityName(e[0], e[1])
    # get entity labels read from STEP and create a physical group for all
    # entities having the same 3rd label in the /-separated label path
    if n:
        print('Entity ' + str(e) + ' has label ' + n + ' (and mass ' +
              str(gmsh.model.occ.getMass(e[0], e[1])) + ')')
        path = n.split('/')
        if e[0] == 3 and len(path) > 3:
            if (path[2] not in physicals):
                physicals[path[2]] = []
            physicals[path[2]].append(e[1])

# create the physical groups
for name, tags in physicals.items():
    p = gmsh.model.addPhysicalGroup(3, tags)
    gmsh.model.setPhysicalName(3, p, name)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
