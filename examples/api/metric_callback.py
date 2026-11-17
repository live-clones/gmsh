import gmsh
import math
import sys

gmsh.initialize(sys.argv)

gmsh.model.add("metric_callback")
gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
gmsh.model.occ.synchronize()

# A metric callback prescribes anisotropic mesh sizes: here small elements
# across the circle of radius 0.5 centered on the origin, and large ones along
# it. The callback gets the metric that would be prescribed without it (`m', as
# the 6 components M11, M21, M22, M31, M32, M33) and its smallest size `lc'; it
# either modifies `m' in place or returns the new metric, as a single number
# (an isotropic mesh size), 6 components or a 3x3 matrix.
def metric(dim, tag, x, y, z, lc, m):
    r = math.hypot(x, y)
    if r == 0.: return 0.1
    nx, ny = x / r, y / r # radial direction
    a = 1. / (0.005 + 0.1 * abs(r - 0.5))**2 # 1 / h^2 along the radius
    b = 1. / 0.1**2 # 1 / h^2 along the circle
    return [[a * nx * nx + b * ny * ny, (a - b) * nx * ny, 0],
            [(a - b) * nx * ny, a * ny * ny + b * nx * nx, 0],
            [0, 0, b]]

gmsh.model.mesh.setMetricCallback(metric)

# Anisotropic sizes need an anisotropic algorithm (here BAMG); the other
# algorithms use the smallest size prescribed by the metric
gmsh.option.setNumber("Mesh.Algorithm", 7)

gmsh.model.mesh.generate(2)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
