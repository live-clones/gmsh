# Loads Plugin(ElementAverage) from the shared library given on the command
# line and runs it on a view (see README.txt)

import gmsh
import sys

if len(sys.argv) < 2:
    print('Usage: python element_average.py libElementAverage.so')
    exit(0)

gmsh.initialize()
gmsh.plugin.load(sys.argv[1])

# a view with two triangles
t = gmsh.view.add('values')
gmsh.view.addListData(t, 'ST', 2, [0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 2, 3,
                                   1, 1, 0, 0, 1, 1, 0, 0, 0, 2, 4, 6])

gmsh.plugin.setNumber('ElementAverage', 'View', gmsh.view.getIndex(t))
gmsh.plugin.setNumber('ElementAverage', 'Scale', 10)
t2 = gmsh.plugin.run('ElementAverage')
print(gmsh.view.getListData(t2))

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
