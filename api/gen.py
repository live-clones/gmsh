from GenApi import *

api = API()

#add_function("","Initialize",[iintp("argc"),arg("char **","argv")])
gmsh = api.add_module("")

gmsh.add("Finalize")
gmsh.add("Open",istring("fileName"))
gmsh.add("Merge",istring("fileName"))
gmsh.add("Export",istring("fileName"))
gmsh.add("Clear")

options = api.add_module("Option")
options.add("SetNumber",istring("name"),idouble("value"))
options.add("GetNumber",istring("name"),odouble("value"))
options.add("SetString",istring("name"),istring("value"))
options.add("GetString",istring("name"),ostring("value"))

model = api.add_module("Model")
model.add("Create",istring("name"))
model.add("SetCurrent",istring("name"))
model.add("Destroy")

model.add("GetEntities",ovectorpair("dimTags"),iint("dim","-1"))
model.add("GetPhysicalGroups",ovectorpair("dimTags"),iint("dim","-1"))
model.add("AddPhysicalGroup",iint("dim"),iint("tag"),ivectorint("tags"))
model.add("GetEntitiesForPhysicalGroup",iint("dim"),iint("tag"),ovectorint("tags"))
model.add("SetPhysicalName",iint("dim"),iint("tag"),istring("name"))
model.add("GetPhysicalName",iint("dim"),iint("tag"),ostring("name"))
model.add("GetVertexCoordinates",iint("tag"),odouble("x"),odouble("y"),odouble("z"))
model.add("GetBoundary",ivectorpair("inDimTags"),ovectorpair("outDimTags"),
        ibool("combined","true"),ibool("oriented","true"),ibool("recursive","false"))
model.add("GetEntitiesInBoundingBox",
        idouble("x1"),idouble("y1"),idouble("z1"),
        idouble("x2"),idouble("y2"),idouble("z2"),
        ovectorpair("tags"),iint("dim","-1"))

model.add("GetBoundingBox",iint("dim"),iint("tag"),odouble("x1"),odouble("y1"),
        odouble("z1"),odouble("x2"),odouble("y2"),odouble("z2"))
model.add("Remove",ivectorpair("dimTags"),ibool("recursive","false"))
model.add("Mesh",iint("dim"))
model.add("GetMeshVertices",iint("dim"),iint("tag"),
        ovectorint("vertexTags"),
        ovectordouble("coords"))
model.add("GetMeshElements",iint("dim"),iint("tag"),
        ovectorint("types"),
        ovectorvectorint("elementTags"),
        ovectorvectorint("vertexTags"))
model.add("SetMeshSize",ivectorpair("dimTags"),idouble("size"))
model.add("SetTransfiniteLine",iint("tag"),iint("nPoints"),
        istring("type","Progression"),
        idouble("coef","1."))
model.add("SetTransfiniteSurface",iint("tag"),
        istring("arrangement","Left"),
        ivectorint("cornerTags","std::vector<int>()"))
model.add("SetTransfiniteVolume",iint("tag"),
        ivectorint("cornerTags","std::vector<int>()"))
model.add("SetRecombine",iint("dim"),iint("tag"),idouble("angle","45."))
model.add("SetSmoothing",iint("dim"),iint("tag"),iint("val"))
model.add("SetReverseMesh",iint("dim"),iint("tag"),ibool("val","true"))
model.add("Embed",iint("dim"),ivectorint("tags"),iint("inDim"),
        iint("inTag"))

model_geo = api.add_module("ModelGeo")
model_geo.add("AddPoint",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("meshSize","0."))
model_geo.add("AddLine",iint("tag"),iint("startTag"),iint("endTag"))
model_geo.add("AddCircleArc",iint("tag"),iint("startTag"),
        iint("centerTag"),iint("endTag"),
        idouble("nx","0."),idouble("ny","0."),
        idouble("nz","0."))
model_geo.add("AddEllipseArc",iint("tag"),iint("startTag"),iint("centerTag"),
        iint("majorTag"),iint("endTag"),
        idouble("nx","0."),idouble("ny","0."),
        idouble("nz","0."))
model_geo.add("AddSpline",iint("tag"),ivectorint("vertexTags"))
model_geo.add("AddBSpline",iint("tag"),ivectorint("vertexTags"))
model_geo.add("AddBezier",iint("tag"),ivectorint("vertexTags"))
model_geo.add("AddLineLoop",iint("tag"),ivectorint("edgeTags"))
model_geo.add("AddPlaneSurface",iint("tag"),ivectorint("wireTags"))
model_geo.add("AddSurfaceFilling",iint("tag"),ivectorint("wireTags"),
        iint("sphereCenterTag","-1"))
model_geo.add("AddSurfaceLoop",iint("tag"),ivectorint("faceTags"))
model_geo.add("AddVolume",iint("tag"),ivectorint("shellTags"))
model_geo.add("Extrude",ivectorpair("inDimTags"),
        idouble("dx"),idouble("dy"),idouble("dz"),
        ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_geo.add("Revolve",ivectorpair("inDimTags"),
        idouble("x"),idouble("y"),idouble("z"),
        idouble("ax"),idouble("ay"),
        idouble("az"),idouble("angle"),
        ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_geo.add("Twist",ivectorpair("inDimTags"),
        idouble("x"),idouble("y"),idouble("z"),
        idouble("dx"),idouble("dy"),idouble("dz"),
        idouble("ax"),idouble("ay"),idouble("az"),
        idouble("angle"),
        ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_geo.add("Translate",ivectorpair("dimTags"),
        idouble("dx"),idouble("dy"),idouble("dz"))
model_geo.add("Rotate",ivectorpair("dimTags"),idouble("x"),idouble("y"),
        idouble("z"),idouble("ax"),idouble("ay"),
        idouble("az"),idouble("angle"))
model_geo.add("Dilate",ivectorpair("dimTags"),idouble("x"),idouble("y"),
        idouble("z"),idouble("a"),idouble("b"),
        idouble("c"))
model_geo.add("Symmetry",ivectorpair("dimTags"),idouble("a"),idouble("b"),
        idouble("c"),idouble("d"))
model_geo.add("Copy",ivectorpair("inDimTags"),ovectorpair("outDimTags"))
model_geo.add("Remove",ivectorpair("dimTags"),ibool("recursive","false"))
model_geo.add("RemoveAllDuplicates")
model_geo.add("SetMeshSize",ivectorpair("dimTags"),idouble("size"))
model_geo.add("SetTransfiniteLine",iint("tag"),iint("nPoints"),
        istring("type","Progression"),
        idouble("coef","1."))
model_geo.add("SetTransfiniteSurface",iint("tag"),
        istring("arrangement","Left"),
        ivectorint("cornerTags = std::vector<int>()"))
model_geo.add("SetTransfiniteVolume",iint("tag"),
        ivectorint("cornerTags = std::vector<int>()"))
model_geo.add("SetRecombine",iint("dim"),iint("tag"),idouble("angle","45."))
model_geo.add("SetSmoothing",iint("dim"),iint("tag"),iint("val"))
model_geo.add("SetReverseMesh",iint("dim"),iint("tag"),ibool("val","true"))
model_geo.add("Synchronize")

model_occ = api.add_module("ModelOcc")
model_occ.add("AddPoint",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("meshSize","0."))
model_occ.add("AddLine",iint("tag"),iint("startTag"),iint("endTag"))
model_occ.add("AddCircleArc",iint("tag"),iint("startTag"),iint("centerTag"),
        iint("endTag"))
model_occ.add("AddCircle",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("r"),
        idouble("angle1","0."),idouble("angle2","2*M_PI"))
model_occ.add("AddEllipseArc",iint("tag"),iint("startTag"),iint("centerTag"),
        iint("endTag"))
model_occ.add("AddEllipse",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("r1"),idouble("r2"),
        idouble("angle1","0."),
        idouble("angle2","2*M_PI"))
model_occ.add("AddSpline",iint("tag"),ivectorint("vertexTags"))
model_occ.add("AddBezier",iint("tag"),ivectorint("vertexTags"))
model_occ.add("AddBSpline",iint("tag"),ivectorint("vertexTags"))
model_occ.add("AddWire",iint("tag"),ivectorint("edgeTags"),
        ibool("checkClosed","false"))
model_occ.add("AddLineLoop",iint("tag"),ivectorint("edgeTags"))
model_occ.add("AddRectangle",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("dx"),idouble("dy"),
        idouble("roundedRadius","0."))
model_occ.add("AddDisk",iint("tag"),idouble("xc"),idouble("yc"),
        idouble("zc"),idouble("rx"),idouble("ry"))
model_occ.add("AddPlaneSurface",iint("tag"),ivectorint("wireTags"))
model_occ.add("AddSurfaceFilling",iint("tag"),iint("wireTag"))
model_occ.add("AddSurfaceLoop",iint("tag"),ivectorint("faceTags"))
model_occ.add("AddVolume",iint("tag"),ivectorint("shellTags"))
model_occ.add("AddSphere",iint("tag"),idouble("xc"),idouble("yc"),
        idouble("zc"),idouble("radius"),
        idouble("angle1","-M_PI/2"),
        idouble("angle2","M_PI/2"),
        idouble("angle3","2*M_PI"))
model_occ.add("AddBox",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("dx"),idouble("dy"),
        idouble("dz"))
model_occ.add("AddCylinder",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("dx"),idouble("dy"),
        idouble("dz"),idouble("r"),
        idouble("angle","2*M_PI"))
model_occ.add("AddCone",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("dx"),idouble("dy"),
        idouble("dz"),idouble("r1"),idouble("r2"),
        idouble("angle","2*M_PI"))
model_occ.add("AddWedge",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("dx"),idouble("dy"),
        idouble("dz"),idouble("ltx","0."))
model_occ.add("AddTorus",iint("tag"),idouble("x"),idouble("y"),
        idouble("z"),idouble("r1"),idouble("r2"),
        idouble("angle","2*M_PI"))
model_occ.add("AddThruSections",iint("tag"),ivectorint("wireTags"),
        ovectorpair("outDimTags"),ibool("makeSolid","true"),
        ibool("makeRuled","false"))
#GMSH_API addThickSolid"",iint("tag"),iint("solidTag"),
#                       ivectorint("excludeFaceTags"),
#                       idouble("offset"),ovectorpair("outDimTags"))
model_occ.add("Extrude",ivectorpair("inDimTags"),idouble("dx"),idouble("dy"),
        idouble("dz"),ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_occ.add("Revolve",ivectorpair("inDimTags"),
        idouble("x"),idouble("y"),idouble("z"),
        idouble("ax"),idouble("ay"),idouble("az"),
        idouble("angle"),ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_occ.add("AddPipe",ivectorpair("inDimTags"),iint("wireTag"),
        ovectorpair("outDimTags"))
model_occ.add("Fillet",ivectorint("regionTags"),
        ivectorint("edgeTags"),
        idouble("radius"),ovectorpair("outDimTags"),
        ibool("removeRegion","true"))
model_occ.add("BooleanUnion",iint("tag"),ivectorpair("objectDimTags"),
        ivectorpair("toolDimTags"),
        ovectorpair("outDimTags"),
        ovectorvectorpair("outDimTagsMap"),
        ibool("removeObject","true"),
        ibool("removeTool","true"))
model_occ.add("BooleanIntersection",iint("tag"),ivectorpair("objectDimTags"),
        ivectorpair("toolDimTags"),
        ovectorpair("outDimTags"),
        ovectorvectorpair("outDimTagsMap"),
        ibool("removeObject","true"),
        ibool("removeTool","true"))
model_occ.add("BooleanDifference",iint("tag"),ivectorpair("objectDimTags"),
        ivectorpair("toolDimTags"),
        ovectorpair("outDimTags"),
        ovectorvectorpair("outDimTagsMap"),
        ibool("removeObject","true"),
        ibool("removeTool","true"))
model_occ.add("BooleanFragments",iint("tag"),ivectorpair("objectDimTags"),
        ivectorpair("toolDimTags"),
        ovectorpair("outDimTags"),
        ovectorvectorpair("outDimTagsMap"),
        ibool("removeObject","true"),
        ibool("removeTool","true"))
model_occ.add("Translate",ivectorpair("dimTags"),idouble("dx"),
        idouble("dy"),idouble("dz"))
model_occ.add("Rotate",ivectorpair("dimTags"),idouble("x"),
        idouble("y"),idouble("z"),idouble("ax"),
        idouble("ay"),idouble("az"),idouble("angle"))
model_occ.add("Dilate",ivectorpair("dimTags"),idouble("x"),
        idouble("y"),idouble("z"),idouble("a"),
        idouble("b"),idouble("c"))
model_occ.add("Symmetry",ivectorpair("dimTags"),idouble("a"),
        idouble("b"),idouble("c"),idouble("d"))
model_occ.add("Copy",ivectorpair("inDimTags"),ovectorpair("outDimTags"))
model_occ.add("Remove",ivectorpair("dimTags"),ibool("recursive","false"))
model_occ.add("RemoveAllDuplicates")
model_occ.add("ImportShapes",istring("fileName"),ovectorpair("outDimTags"),
        ibool("highestDimOnly","true"),
        istring("format",""))
model_occ.add("SetMeshSize",ivectorpair("dimTags"),idouble("size"))
model_occ.add("Synchronize")

model_field = api.add_module("ModelField")
model_field.add("Create",iint("tag"),istring("type"))
model_field.add("SetNumber",iint("tag"),istring("option"),idouble("value"))
model_field.add("SetString",iint("tag"),istring("option"),istring("value"))
model_field.add("SetNumbers",iint("tag"),istring("option"),ivectordouble("value"))
model_field.add("SetAsBackground",iint("tag"))
model_field.add("Delete",iint("tag"))

api.add_module("View")
api.add_module("Plugin")
api.add_module("Graphics")

api.write_cpp("gmsh")
#api.write_c("gmshc")
