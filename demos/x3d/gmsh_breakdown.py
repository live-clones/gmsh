import gmsh
import argparse

# python gmsh_breakdown.py --split 1 will create separate x3d files for each volume
parser = argparse.ArgumentParser(description='x3d print options')
parser.add_argument('--surface_mode',default=2,type=int)
parser.add_argument('--split',default=0,type=int)
args = parser.parse_args()

x3dsurface = args.surface_mode
x3dvolume = args.split

gmsh.initialize()
gmsh.open('Geom.stp') # change to any input stp in directory

E  = gmsh.model.getEntities()
E2 = [e for e in E if e[0] == 2]
E3 = [e for e in E if e[0] == 3]

gmsh.option.setNumber('Print.X3dSurfaces',x3dsurface)
gmsh.option.setNumber('Print.X3dVolumes',x3dvolume)


gmsh.write('geom_phys.x3d')
gmsh.clear()
gmsh.finalize()