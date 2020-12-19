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
    "valueLabels":{"Temperature [℃]":0, "Flux [W/m²]":1},
    "visible": false
  },
  {
    "type":"number",
    "name":"ONELAB Context/Curve Template/0Value",
    "values":[20],
    "min":0,
    "max":100,
    "step":0.1,
    "visible": false
  },
  {
    "type":"number",
    "name":"ONELAB Context/Surface Template/0Material choice",
    "values":[1],
    "choices":[0, 1, 2],
    "valueLabels":{"User-defined":0, "Steel":1, "Concrete":2},
    "visible": false
  },
  {
    "type":"string",
    "name":"ONELAB/Button",
    "values":["Run", "dump safir file"],
    "visible":false
  }
]"""

gmsh.onelab.set(parameters)

if '-nopopup' not in sys.argv:
    gmsh.fltk.initialize()

def eventLoop():
    # check if GUI has been closed
    if gmsh.fltk.isAvailable() == 0:
        return 0
    # wait for an event
    gmsh.fltk.wait()
    action = gmsh.onelab.getString("ONELAB/Action")
    if len(action) < 1:
        pass
    elif action[0] == "check":
        gmsh.onelab.setString("ONELAB/Action", [""])
        # could update/define new parameters depending on new state
        print(gmsh.onelab.get())
        # gmsh.fltk.update()
    elif action[0] == "dump safir file":
        # use clicked on "Run"
        gmsh.onelab.setString("ONELAB/Action", [""])
        print('dump file and run safir')
    elif action[0] == "reset":
        # user clicked on "Reset database"
        gmsh.onelab.setString("ONELAB/Action", [""])
        gmsh.onelab.set(parameters)
        gmsh.fltk.update()
    return 1

while eventLoop():
    pass

gmsh.finalize()
