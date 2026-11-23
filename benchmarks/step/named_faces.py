# Checks the colours and the names imported from two STEP files, the cube of
# examples/api/step_boundary_colors.stp with five of its faces and one of its
# edges named, as a solid (named_faces.stp) and as an open shell
# (named_open_shell.stp):
#
#   python named_faces.py
#
# Three faces have a colour of their own, the three others the one of the
# solid or of the shell.

import gmsh
import os
import sys
from collections import Counter

gmsh.initialize(sys.argv)
path = os.path.dirname(os.path.abspath(__file__))

# (the colours and the names are read with the OCAF module of OpenCASCADE)
if 'OpenCASCADE-CAF' not in gmsh.option.getString('General.BuildOptions'):
    print('Skipped: Gmsh was built without OpenCASCADE-CAF')
    gmsh.finalize()
    sys.exit(77)

colors = {(0, 255, 0, 255): 1, (255, 0, 0, 255): 1, (0, 128, 255, 255): 1,
          (225, 225, 225, 255): 3}
surfaces = {'Shapes/inlet': 1, 'Shapes/outlet': 1, 'Shapes/wall': 2,
            'Shapes/symmetry': 1, '': 1}
curves = {'Shapes/rim': 1, '': 11}

ok = True
for name in ['named_faces.stp', 'named_open_shell.stp']:
    gmsh.clear()
    gmsh.model.occ.importShapes(os.path.join(path, name))
    gmsh.model.occ.synchronize()
    s = gmsh.model.getEntities(2)
    c = gmsh.model.getEntities(1)
    got = [dict(Counter(gmsh.model.getColor(*e) for e in s)),
           dict(Counter(gmsh.model.getEntityName(*e) for e in s)),
           dict(Counter(gmsh.model.getEntityName(*e) for e in c))]
    for what, g, e in zip(['surface colors', 'surface names', 'curve names'],
                          got, [colors, surfaces, curves]):
        if g != e:
            ok = False
            gmsh.logger.write('%s: wrong %s: %s instead of %s' %
                              (name, what, g, e), 'error')

gmsh.finalize()
sys.exit(0 if ok else 1)
