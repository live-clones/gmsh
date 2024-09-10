import gmsh
import numpy as np


gmsh.initialize()
pts = [
    [-0.034085297850175826, 0.05610177678812691, 0.0],
    [-0.025773123244386263, 0.055737574716152566, 0.0],
    [-0.01861002668738365, 0.049875155091285706, 0.0],
    [-0.020155801627512814, 0.04756111125307992, 0.0],
    [-0.0267215470989998, 0.04738179986178875, 0.0],
    [-0.02828876537948993, 0.04623366301018323, 0.0],
    [-0.02941742481905319, 0.04031772333946176, 0.0],
    [-0.033975317841607816, 0.03933049213305148, 0.0],
    [-0.03777569460804871, 0.04833597241423769, 0.0],
]

pt_ids = [gmsh.model.occ.addPoint(*pt) for pt in pts]
pt_ids1, pt_ids2 = np.array_split(np.array(pt_ids), 2)

pt_ids1 = pt_ids1.tolist()
pt_ids2 = [pt_ids1[-1]] + pt_ids2.tolist() + [pt_ids1[0]]
print("Point Ids 1: " + str(pt_ids1))
print("Point Ids 2: " + str(pt_ids2))
spline1 = gmsh.model.occ.addBSpline(pt_ids1)
spline2 = gmsh.model.occ.addBSpline(pt_ids2)

applyID = pt_ids1[-1]
print("Fillet will be applied to point " + str(applyID))

gmsh.model.occ.fillet2D(spline2, spline1, 0.01, -1, pt_ids1[-1], True)
gmsh.model.occ.synchronize()
gmsh.model.occ.fillet2D(spline1, spline2, 0.005, -1)


# gmsh.model.occ.addCurveLoop([spline1, spline2])
gmsh.model.occ.synchronize()
gmsh.fltk.run()

gmsh.finalize()
