import gmsh
import math
import sys

# This example shows how to implement a simple interactive pre-processor for a
# finite element solver, i.e. by interactively specifying boundary conditions
# and material properties on parts of the model

gmsh.initialize(sys.argv)
if len(sys.argv) > 1:
    gmsh.open(sys.argv[1])

# For Gmsh to know which types of boundary conditions/materials are available,
# we define "template" ONELAB variables, whose names contains the following
# substrings:
#
# - 'ONELAB Context/Point Template/'
# - 'ONELAB Context/Curve Template/'
# - 'ONELAB Context/Surface Template/'
# - 'ONELAB Context/Volume Template/'
#
# Double- (or right-) clicking on an entity in the GUI will pop-up a window
# where instances of these variables for the given entity can be edited. For
# example, if the 'ONELAB Context/Curve Template/0Boundary condition' exists,
# double-clicking on curve 123 in the model will create 'ONELAB Context/Curve
# 123/0Boundary condition' (or 'ONELAB Context/Physical Curve 1000/0Boundary
# condition' depending on the choice in the window, if Curve 123 belongs to the
# Physical Curve 1000)
#
parameters = """
[
  {
    "type":"number",
    "name":"ONELAB Context/Curve Template/0Boundary condition",
    "values":[0],
    "choices":[0, 1],
    "valueLabels":{"Temperature [℃]":0, "Flux [Wm⁻²]":1}
  },
  {
    "type":"number",
    "name":"ONELAB Context/Curve Template/1Value",
    "values":[20],
    "min":0,
    "max":100,
    "step":0.1
  },
  {
    "type":"number",
    "name":"ONELAB Context/Surface Template/0Material",
    "values":[1],
    "choices":[0, 1, 2],
    "valueLabels":{"User-defined":0, "Steel":1, "Concrete":2},
    "attributes":{"ServerActionHide":"ONELAB Context/Surface Template/1.*",
                  "ServerActionShow 0":"ONELAB Context/Surface Template/1.*"}
  },
  {
    "type":"number",
    "name":"ONELAB Context/Surface Template/10Conductivity [Wm⁻¹K⁻¹]",
    "values":[205],
    "min":0.1,
    "max":500,
    "step":0.1,
    "visible":false
  },
  {
    "type":"number",
    "name":"ONELAB Context/Surface Template/11Diffusivity [mm²s⁻¹]",
    "values":[97],
    "min":10,
    "max":1200,
    "step":0.1,
    "visible":false
  },
  {
    "type":"string",
    "name":"ONELAB/Button",
    "values":["Run", "run"],
    "visible":false
  }
]"""

gmsh.onelab.set(parameters)

def runSolver():
    print('parameters =', gmsh.onelab.get())
    print('running the solver with the given parameters...')

def eventLoop():
    # terminate the event loop if the GUI was closed
    if gmsh.fltk.isAvailable() == 0: return 0
    # wait for an event
    gmsh.fltk.wait()
    # check if an action is requested
    action = gmsh.onelab.getString("ONELAB/Action")
    if len(action) < 1:
        # no action requested
        pass
    elif action[0] == "check":
        # database was changed: update/define new parameters depending on new
        # state
        gmsh.onelab.setString("ONELAB/Action", [""])
        # print('parameters = ', gmsh.onelab.get())
        gmsh.fltk.update()
    elif action[0] == "reset":
        # user clicked on "Reset database"
        gmsh.onelab.setString("ONELAB/Action", [""])
        gmsh.onelab.set(parameters)
        gmsh.fltk.update()
    elif action[0] == "run":
        # user clicked on "Run"
        gmsh.onelab.setString("ONELAB/Action", [""])
        runSolver()
    return 1

if '-nopopup' not in sys.argv:
    gmsh.fltk.initialize()
    while eventLoop():
        pass
else:
    runSolver()

gmsh.finalize()
