import gmsh
l = 8.e-2
gmsh.initialize()
gmsh.merge('dlr_f6.geo')
#gmsh.option.setNumber('Mesh.MeshSizeFactor',.05);
gmsh.model.mesh.generate(3)


gmsh.plugin.setString('BoundaryLayer','Surfaces','88, 74, 104, 105, 120, 119, 103, 118, 102, 8, 130, 123, 117, 121, 101, 95, 7, 116, 94, 106, 100, 122, 99, 96, 92, 97, 83, 84, 87, 85, 86, 81, 107, 93, 82, 73, 79, 5, 53, 4, 57, 89, 72, 52, 112, 1, 113, 69, 111, 6, 91, 51, 58, 50,\
 110, 60, 71, 3, 55, 49, 59, 109, 114, 48, 54, 68, 38, 90, 2, 108, 70, 39, 47, 37, 9, 56, 98, 10, 115, 75, 76, 77, 80, 61, 78, 62, 63, 64, 46, 65, 66, 67, 45, 44, 15, 43, 42, 14, 41, 13, 40, 12, 11, 16, 34, 35, 17, 36, 30, 31, 32, 26, 33, 25, 21, 27, 23,\
 18, 22, 28, 24, 29, 19, 20')
gmsh.plugin.setString('BoundaryLayer','Volumes','1')
gmsh.plugin.setNumber('BoundaryLayer','Thickness', 5.)
gmsh.plugin.setNumber('BoundaryLayer','Size',.1)

gmsh.plugin.run('BoundaryLayer')


#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
