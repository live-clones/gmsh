// for the symmetric falcon:

gmsh falcon_surface.script - // generates remeshed falcon boundary mesh(es)
gmsh falcon_volume.script -  // generates volume mesh in box around falcon(s)
gmsh partition.script -  // partitions the mesh and saves using new physicals
gmsh split.script - // splits the partitionned mesh into separate files

// for the full falcon(s)

gmsh CreateFullInitialMesh.geo - // generates the intial falcon boundary mesh
gmsh fullfalcon_surface.script - // generates remeshed falcon boundary mesh(es)
gmsh fullfalcon_volume.script - // generates volume mesh in box around falcon(s)
gmsh partition.script -  // partitions the mesh and saves using new physicals
gmsh fullsplit.script - // splits the partitionned mesh into separate files
