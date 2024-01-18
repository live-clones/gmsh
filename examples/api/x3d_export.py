import gmsh
import argparse
import os

# python gmsh_breakdown.py --split 1 will create separate x3d files for each volume
parser = argparse.ArgumentParser(description='x3d print options')
parser.add_argument('--surface_mode',default=2,type=int)
parser.add_argument('--split',default=0,type=int)
parser.add_argument('--colorize', default=1,type=int)
parser.add_argument('-nopopup', action='store_true')
args = parser.parse_args()

x3dsurface = args.surface_mode
x3dvolume = args.split
x3dcolorize = args.colorize

gmsh.initialize()

path = os.path.dirname(os.path.abspath(__file__))
gmsh.open(os.path.join(path, 'as1-tu-203.stp'))

path = os.path.join(os.curdir,"x3d_output")
if not os.path.exists(path):
    os.makedirs(path)

gmsh.option.setNumber('Print.X3dSurfaces',x3dsurface)
gmsh.option.setNumber('Print.X3dVolumes',x3dvolume)
gmsh.option.setNumber('Print.X3dColorize',x3dcolorize)

outfile = os.path.join(path, 'out.x3d')
gmsh.write(outfile)
gmsh.clear()
gmsh.finalize()
