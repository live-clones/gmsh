# contributed by Zoltan Csati

import gmsh
import sys

gmsh.initialize()

tag = gmsh.view.add(f'Quadratic field on a quadratic segment')

# Coordinates of the quadratic segment (a single element) in the physical space ...
segment = [-2,  3,  -1,    # x
            9, 14,  12.5,  # y
            0,  0,   0]    # z

# ... appended with the 3 function values of the defined field
u = [1, 3.5, -1]
segment.extend(u)

# Define the canonical polynomial basis for the field interpolation
P = [0, 0, 0,  # xi^0 eta^0 zeta^0
     1, 0, 0,  # xi^1 eta^0 zeta^0
     2, 0, 0]  # xi^2 eta^0 zeta^0
# From monomial to Lagrange basis
Phi = [0, -1/2, 1/2,  # shape function at xi = -1:  phi_1 = 1/2*(-xi + xi^2)
       0,  1/2, 1/2,  # shape function at xi =  1:  phi_2 = 1/2*( xi + xi^2)
       1,  0,  -1]    # shape function at xi =  0:  phi_3 = 1 - xi^2
# Three monomials (1, xi, xi^2) for the geometrical mapping
P_g = P
# Geometrical mapping in the parametric space  -1 <= xi <= 1
Phi_g = Phi

# Adapt Gmsh to the input basis
gmsh.view.setInterpolationMatrices(tag, 'Line', 3, Phi, P, 3, Phi_g, P_g)

gmsh.view.addListData(tag,
                      'SL',     # S: scalar, L: line
                      1,        # number of elements
                      segment)  # data

# Create the adaptive visualization mesh
gmsh.view.option.setNumber(tag, "AdaptVisualizationGrid", 1)
gmsh.view.option.setNumber(tag, "TargetError", 1e-3)
gmsh.view.option.setNumber(tag, "MaxRecursionLevel", 7)

# Settings for displaying the results in the Gmsh GUI
gmsh.view.option.setNumber(tag, 'LineWidth', 10)
gmsh.view.option.setNumber(tag, 'IntervalsType', 3)
gmsh.view.option.setNumber(tag, 'LineType', 1)
gmsh.view.option.setNumber(tag, 'GlyphLocation', 2)
gmsh.view.option.setNumber(tag, 'Axes', 2)
gmsh.view.option.setNumber(tag, 'Explode', 0.8)  # shrink factor

# Run the GUI
if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

# We are done using the Gmsh API
gmsh.finalize()
