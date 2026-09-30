# A test case for adaptive views: a field sampled at the nodes of a cube meshed
# with tetrahedra or hexahedra of any order, and shown through an
# adaptive view. The field is chosen for what the refinement has to do:
#
# - gyroid: oscillating everywhere, so that what has to be recovered is
#   controlled by the spatial frequency relative to the mesh size
# - spikes: Gaussian peaks at random places, flat in between, so that the
#   refinement should concentrate on the peaks and leave the rest alone
# - shells: concentric spherical fronts, i.e. jumps along curved surfaces,
#   which cut through elements in every direction
#
# How sharp the features are is set apart from their spacing: the width of
# the peaks and of the fronts, and, for the gyroid, the width of the
# transition between the two phases its surface separates (the field is
# tanh(gyroid / width): a smooth gyroid when the width is large, two phases
# with a sharp interface when it is small).
#
#   python view_adaptive_cube.py [-structured] [-order n] [-size h]
#                                [-field gyroid|spikes|shells] [-freq f]
#                                [-width w] [-level l] [-tol t] [-nt n]
#                                [-save file.vtu|.pvtu|.msh] [-nopopup]
#
# -structured: hexahedra (transfinite and recombined) instead of tetrahedra
# -order:      order of the elements (default 3)
# -size:       mesh size (default 0.1)
# -field:      the field (default shells)
# -freq:       periods of the gyroid across the cube, number of spikes along
#              each direction of the cube, or number of shells; default 2
# -width:      width of the transitions as a fraction of the spacing of the
#              features, i.e. of the period of the gyroid, of the distance
#              between spikes or between shells (default 0.05; 1 gives the
#              plain gyroid)
# -level:      View.MaxRecursionLevel (default 4)
# -tol:        View.TargetError (default: the default of the option); a
#              negative value refines everything down to the level
# -nt:         number of threads
# -save:       also write the view refined (PostProcessing.SaveAdapted): each
#              time step on a mesh of its own, in a file of its own
#
# The time taken by the first adaptation and by a change of time step is
# printed, with the number of refined elements.
#
# For example:
#
#   python view_adaptive_cube.py
#     two spherical fronts through 5000 tetrahedra of order 3: 3.5M refined
#     elements, 17% of a full refinement down to level 4
#   python view_adaptive_cube.py -tol 0.01
#     the same with a looser target error: 1.5M elements
#   python view_adaptive_cube.py -structured -freq 3
#     three fronts through 1000 hexahedra of order 3
#   python view_adaptive_cube.py -level 5 -nt 8
#     the default case down to level 5, adapted by 8 threads: about 21M
#     elements (the mesh made by 8 threads varies a little)
#   python view_adaptive_cube.py -field spikes -freq 3 -level 5
#     27 peaks between the nodes of 5000 tetrahedra: 5M elements, 3% of a full
#     refinement
#   python view_adaptive_cube.py -field gyroid -width 1 -size 0.2 -freq 1
#     the plain gyroid, smooth everywhere: nearly everything is refined
#   python view_adaptive_cube.py -field gyroid -width 0.02 -freq 1
#     two phases separated by the gyroid surface, with a sharp interface
#   python view_adaptive_cube.py -tol -1 -save cube.pvtu -nopopup
#     uniform refinement, written to VTK files

import gmsh
import sys
import math
import time

def arg(name, default, convert=float):
    if name in sys.argv:
        return convert(sys.argv[sys.argv.index(name) + 1])
    return default

structured = '-structured' in sys.argv
order = arg('-order', 3, int)
size = arg('-size', 0.1)
kind = arg('-field', 'shells', str)
freq = arg('-freq', 2.)
width = arg('-width', 0.05)
level = arg('-level', 4, int)
tol = arg('-tol', None)
nt = arg('-nt', 0, int)
save = arg('-save', None, str)
if kind not in ('gyroid', 'spikes', 'shells'):
    print('Unknown field ' + kind)
    sys.exit(1)

gmsh.initialize()
if nt:
    gmsh.option.setNumber('General.NumThreads', nt)

# the cube
gmsh.model.add('cube')
gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
gmsh.model.occ.synchronize()
gmsh.option.setNumber('Mesh.MeshSizeMin', size)
gmsh.option.setNumber('Mesh.MeshSizeMax', size)
if structured:
    n = max(int(round(1 / size)), 1) + 1
    for c in gmsh.model.getEntities(1):
        gmsh.model.mesh.setTransfiniteCurve(c[1], n)
    for s in gmsh.model.getEntities(2):
        gmsh.model.mesh.setTransfiniteSurface(s[1])
        gmsh.model.mesh.setRecombine(2, s[1])
    gmsh.model.mesh.setTransfiniteVolume(1)
gmsh.option.setNumber('Mesh.ElementOrder', order)
gmsh.model.mesh.generate(3)

# the field at the nodes
tags, xyz, _ = gmsh.model.mesh.getNodes()
n = max(int(round(freq)), 1)
if kind == 'spikes':
    # n^3 Gaussian peaks, each at a random place in its cell of the cube, with
    # a random sign
    import random
    random.seed(1)
    peaks = [((i + random.random()) / n, (j + random.random()) / n,
              (k + random.random()) / n, random.choice((-1, 1)))
             for i in range(n) for j in range(n) for k in range(n)]
    w = width / n
    def field(x, y, z):
        v = 0.
        for px, py, pz, sign in peaks:
            d2 = (x - px) ** 2 + (y - py) ** 2 + (z - pz) ** 2
            if d2 < 25 * w * w:
                v += sign * math.exp(-d2 / (2 * w * w))
        return v
    what = '%d spikes' % len(peaks)
elif kind == 'shells':
    # n spherical fronts around the origin, a corner of the cube, at which the
    # field goes from +1 to -1 and back
    def field(x, y, z):
        # the distance to the corner in units of the spacing of the fronts:
        # they are at r = 1/2, 3/2, ...
        r = math.sqrt(x * x + y * y + z * z) / math.sqrt(3) * n
        return math.tanh((round(r) - r) * 2 / width) * \
            (1 if round(r) % 2 == 0 else -1)
    what = '%d shells' % n
else:
    # the gyroid g(x, y, z) = sin(kx) cos(ky) + sin(ky) cos(kz) +
    # sin(kz) cos(kx), with k = 2 pi freq, whose gradient is about k where
    # it vanishes: tanh(g / (k w)) goes from -1 to 1 over a width w
    k = 2 * math.pi * freq
    w = width / freq
    def field(x, y, z):
        g = (math.sin(k * x) * math.cos(k * y) +
             math.sin(k * y) * math.cos(k * z) +
             math.sin(k * z) * math.cos(k * x))
        return math.tanh(g / (k * w))
    what = 'gyroid with %g periods' % freq
data = [field(xyz[3 * i], xyz[3 * i + 1], xyz[3 * i + 2])
        for i in range(len(tags))]

# two time steps, so that a change of step can be timed as well
v = gmsh.view.add(kind)
gmsh.view.addHomogeneousModelData(v, 0, 'cube', 'NodeData', tags, data, time=0)
gmsh.view.addHomogeneousModelData(v, 1, 'cube', 'NodeData', tags,
                                  [-d for d in data], time=1)

num3 = gmsh.model.mesh.getElements(3)[1][0].size
num2 = sum(e.size for e in gmsh.model.mesh.getElements(2)[1])
num1 = sum(e.size for e in gmsh.model.mesh.getElements(1)[1])
num0 = sum(e.size for e in gmsh.model.mesh.getElements(0)[1])
print('%d %s of order %d, %s' % (num3, 'hexahedra' if structured else
      'tetrahedra', order, what))

# the adaptive view (the view is adapted as soon as the option is set)
gmsh.view.option.setNumber(v, 'MaxRecursionLevel', level)
if tol is not None:
    gmsh.view.option.setNumber(v, 'TargetError', tol)
print('level %d, target error %g' %
      (level, gmsh.view.option.getNumber(v, 'TargetError')))
t = time.time()
gmsh.view.option.setNumber(v, 'AdaptVisualizationGrid', 1)
print('first adaptation: %.3f s' % (time.time() - t))
types, numElements, _ = gmsh.view.getListData(v, returnAdaptive=True)
print('%d refined elements (%d if all were refined down to the level)' %
      (sum(numElements),
       num3 * 8 ** level + num2 * 4 ** level + num1 * 2 ** level + num0))

t = time.time()
gmsh.view.option.setNumber(v, 'TimeStep', 1)
gmsh.view.getListData(v, returnAdaptive=True)
print('change of time step: %.3f s' % (time.time() - t))
gmsh.view.option.setNumber(v, 'TimeStep', 0)

if save:
    t = time.time()
    gmsh.option.setNumber('PostProcessing.SaveAdapted', 1)
    gmsh.view.write(v, save)
    print('written to %s: %.3f s' % (save, time.time() - t))

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
