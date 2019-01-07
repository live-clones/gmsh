import gmsh
import sys
import json

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

# set a full onelab db
gmsh.onelab.set("""
{ "onelab":{
  "creator":"My app",
  "version":"1.3",
  "parameters":[
    { "type":"number", "name":"number 1", "values":[ 1 ]  },
    { "type":"string", "name":"string 1", "values":[ "hello" ]  }
  ] }
}
""")

# set a list of parameters
gmsh.onelab.set("""
[
  { "type":"number", "name":"number 2", "values":[ 3.141592 ],
    "attributes":{ "Highlight":"Red" }  },
  { "type":"string", "name":"string 2", "values":[ "hello again" ]  }
]
""")

# set a single parameter
gmsh.onelab.set("""
{ "type":"number", "name":"check 1", "values":[ 0 ], "choices":[0, 1]  }
""")

# get the full parameter, store it as a python dict, and change an attribute
p = json.loads(gmsh.onelab.get("check 1"))
p["attributes"] = {"Highlight":"Blue"}
gmsh.onelab.set(json.dumps(p))

# shorter way to just change the value, without json overhead
gmsh.onelab.setNumber("check 1", [1])
gmsh.onelab.setString("string 1", ["goodbye"])

# remove a parameter
gmsh.onelab.clear("string 2")

gmsh.option.setNumber("Solver.AutoMesh", 0.)
gmsh.option.setNumber("Solver.AutoSaveDatabase", 0.)

i = 1
gmsh.fltk.initialize()
while 1:
    gmsh.fltk.wait()
    a = gmsh.onelab.getString("Action")
    if "compute" in a:
        gmsh.onelab.setString("Action", [""])
        # do something here...
        n = gmsh.onelab.getNumber("number 1")
        msg = "Run {0} done with number 1 = {1}".format(i, n)
        gmsh.logger.write(msg)
        gmsh.onelab.setString("Result", [msg])
        i = i + 1
        gmsh.fltk.update()

gmsh.finalize()
