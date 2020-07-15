import gmsh

def getViewNames(view_tags):
        return [gmsh.option.getString(f'View[{gmsh.view.getIndex(tag)}].Name')
                for tag in view_tags]

gmsh.initialize()

gmsh.view.add("view 1")
gmsh.view.add("view 2")
gmsh.view.add("view 3")

for name in getViewNames(gmsh.view.getTags()):
    print(name)

gmsh.finalize()
