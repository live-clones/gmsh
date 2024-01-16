import sys
from pathlib import Path

import gmsh

root = Path(__file__).parent

gmsh.initialize()

gmsh.model.occ.addTorus(0, 0, 0, 1, 0.2)
gmsh.model.occ.synchronize()

gmsh.option.setString("Geometry.OCCSTEPDescription", "A simple torus geometry")
gmsh.option.setString("Geometry.OCCSTEPModelName", "Torus")
gmsh.option.setString("Geometry.OCCSTEPAuthor", "gnikit")
gmsh.option.setString("Geometry.OCCSTEPOrganization", "Gmsh")
gmsh.option.setString("Geometry.OCCSTEPPreprocessorVersion", "Gmsh")
gmsh.option.setString("Geometry.OCCSTEPOriginatingSystem", "-")
gmsh.option.setString("Geometry.OCCSTEPAuthorization", "")
gmsh.write(str(root / "step_header_data.stp"))

if "-nopopup" not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
