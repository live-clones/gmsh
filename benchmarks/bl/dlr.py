import gmsh

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

tol = 1e-3

gmsh.option.setNumber("Geometry.Tolerance", tol)
gmsh.option.setNumber("Geometry.OCCFixDegenerated", 1)
gmsh.option.setNumber("Geometry.OCCFixSmallEdges", 1)
gmsh.option.setNumber("Geometry.OCCFixSmallFaces", 1)
gmsh.option.setNumber("Geometry.OCCSewFaces", 1)

gmsh.open("DLR_F6_V2_STEP1.stp")
gmsh.model.occ.synchronize()

# Important : supprimer les doublons AVANT le healing agressif
gmsh.model.occ.removeAllDuplicates()
gmsh.model.occ.synchronize()

# Healing léger, sans recréer de solide
gmsh.model.occ.healShapes(
    gmsh.model.occ.getEntities(),
    tolerance=tol,
    fixDegenerated=True,
    fixSmallEdges=True,
    fixSmallFaces=True,
    sewFaces=True,
    makeSolids=False
)

gmsh.model.occ.synchronize()

gmsh.write("DLR_F6_clean_nosolid.brep")
gmsh.write("DLR_F6_clean_nosolid.step")

gmsh.finalize()
