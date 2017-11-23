from GenApi import *

api = API()

#add_function("","Initialize",[iintp("argc"),arg("char **","argv")])
gmsh = api.add_module("")

gmsh.add(None,"Finalize")
gmsh.add(None,"Open",istring("fileName"))
gmsh.add(None,"Merge",istring("fileName"))
gmsh.add(None,"Export",istring("fileName"))
gmsh.add(None,"Clear")

options = api.add_module("Option")
options.add(None,"SetNumber",istring("name"),idouble("value"))
options.add(None,"GetNumber",istring("name"),odouble("value"))
options.add(None,"SetString",istring("name"),istring("value"))
options.add(None,"GetString",istring("name"),ostring("value"))

model = api.add_module("Model")
model.add(None,"Create",istring("name"))
model.add(None,"SetCurrent",istring("name"))
model.add(None,"Delete")

model.add(None,"GetEntities",ovectorpair("dimTags"),iint("dim","-1"))
model.add(None,"GetPhysicalGroups",ovectorpair("dimTags"),iint("dim","-1"))
model.add(oint,"AddPhysicalGroup",iint("dim"),ivectorint("tags"),iint("tag","-1"))
model.add(None,"GetEntitiesForPhysicalGroup",iint("dim"),iint("tag"),ovectorint("tags"))
model.add(None,"SetPhysicalName",iint("dim"),iint("tag"),istring("name"))
model.add(None,"GetPhysicalName",iint("dim"),iint("tag"),ostring("name"))
model.add(None,"GetBoundary",ivectorpair("inDimTags"),ovectorpair("outDimTags"),
        ibool("combined","true"),ibool("oriented","true"),ibool("recursive","false"))
model.add(None,"GetEntitiesInBoundingBox",
        idouble("x1"),idouble("y1"),idouble("z1"),
        idouble("x2"),idouble("y2"),idouble("z2"),
        ovectorpair("tags"),iint("dim","-1"))

model.add(None,"GetBoundingBox",iint("dim"),iint("tag"),odouble("x1"),odouble("y1"),
        odouble("z1"),odouble("x2"),odouble("y2"),odouble("z2"))
model.add(None,"Remove",ivectorpair("dimTags"),ibool("recursive","false"))
model.add(None,"Mesh",iint("dim"))
model.add(None,"GetMeshVertices",iint("dim"),iint("tag"),
        ovectorint("vertexTags"),
        ovectordouble("coords"),
        ovectordouble("parametricCoord")
        )
model.add(None,"GetMeshElements",iint("dim"),iint("tag"),
        ovectorint("types"),
        ovectorvectorint("elementTags"),
        ovectorvectorint("vertexTags"))
model.add(None,"SetMeshSize",ivectorpair("dimTags"),idouble("size"))
model.add(None,"SetTransfiniteLine",iint("tag"),iint("nPoints"),
        istring("type","Progression"),
        idouble("coef","1."))
model.add(None,"SetTransfiniteSurface",iint("tag"),
        istring("arrangement","Left"),
        ivectorint("cornerTags","std::vector<int>()"))
model.add(None,"SetTransfiniteVolume",iint("tag"),
        ivectorint("cornerTags","std::vector<int>()"))
model.add(None,"SetSmoothing",iint("dim"),iint("tag"),iint("val"))
model.add(None,"SetReverseMesh",iint("dim"),iint("tag"),ibool("val","true"))
model.add(None,"Embed",iint("dim"),ivectorint("tags"),iint("inDim"),
        iint("inTag"))

model_geo = api.add_module("ModelGeo")
model_geo.add(oint,"AddPoint",idouble("x"),idouble("y"), idouble("z"),idouble("meshSize","0."),iint("tag","-1"))
model_geo.add(oint,"AddLine",iint("startTag"),iint("endTag"),iint("tag","-1"))
model_geo.add(oint,"AddCircleArc",
        iint("startTag"), iint("centerTag"),iint("endTag"),
        iint("tag","-1"),
        idouble("nx","0."),idouble("ny","0."), idouble("nz","0."))
model_geo.add(oint,"AddEllipseArc",
        iint("startTag"),iint("centerTag"),iint("majorTag"),iint("endTag"),
        iint("tag","-1"),
        idouble("nx","0."),idouble("ny","0."), idouble("nz","0."))
model_geo.add(oint,"AddSpline",ivectorint("vertexTags"),iint("tag","-1"))
model_geo.add(oint,"AddBSpline",ivectorint("vertexTags"),iint("tag","-1"))
model_geo.add(oint,"AddBezier",ivectorint("vertexTags"),iint("tag","-1"))
model_geo.add(oint,"AddLineLoop",ivectorint("edgeTags"),iint("tag","-1"))
model_geo.add(oint,"AddPlaneSurface",ivectorint("wireTags"),iint("tag","-1"))
model_geo.add(oint,"AddSurfaceFilling",ivectorint("wireTags"), iint("sphereCenterTag","-1"),iint("tag","-1"))
model_geo.add(oint,"AddSurfaceLoop",ivectorint("faceTags"),iint("tag","-1"))
model_geo.add(oint,"AddVolume",ivectorint("shellTags"),iint("tag","-1"))
model_geo.add(None,"Extrude",ivectorpair("inDimTags"),
        idouble("dx"),idouble("dy"),idouble("dz"),
        ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_geo.add(None,"Revolve",ivectorpair("inDimTags"),
        idouble("x"),idouble("y"),idouble("z"),
        idouble("ax"),idouble("ay"),
        idouble("az"),idouble("angle"),
        ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_geo.add(None,"Twist",ivectorpair("inDimTags"),
        idouble("x"),idouble("y"),idouble("z"),
        idouble("dx"),idouble("dy"),idouble("dz"),
        idouble("ax"),idouble("ay"),idouble("az"),
        idouble("angle"),
        ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_geo.add(None,"Translate",ivectorpair("dimTags"),
        idouble("dx"),idouble("dy"),idouble("dz"))
model_geo.add(None,"Rotate",ivectorpair("dimTags"),idouble("x"),idouble("y"),
        idouble("z"),idouble("ax"),idouble("ay"),
        idouble("az"),idouble("angle"))
model_geo.add(None,"Dilate",ivectorpair("dimTags"),idouble("x"),idouble("y"),
        idouble("z"),idouble("a"),idouble("b"),
        idouble("c"))
model_geo.add(None,"Symmetry",ivectorpair("dimTags"),idouble("a"),idouble("b"),
        idouble("c"),idouble("d"))
model_geo.add(None,"Copy",ivectorpair("inDimTags"),ovectorpair("outDimTags"))
model_geo.add(None,"Remove",ivectorpair("dimTags"),ibool("recursive","false"))
model_geo.add(None,"RemoveAllDuplicates")
model_geo.add(None,"SetMeshSize",ivectorpair("dimTags"),idouble("size"))
model_geo.add(None,"SetTransfiniteLine",iint("tag"),iint("nPoints"),
        istring("type","Progression"),
        idouble("coef","1."))
model_geo.add(None,"SetTransfiniteSurface",iint("tag"),
        istring("arrangement","Left"),
        ivectorint("cornerTags","std::vector<int>()"))
model_geo.add(None,"SetTransfiniteVolume",iint("tag"),
        ivectorint("cornerTags","std::vector<int>()"))
model_geo.add(None,"SetRecombine",iint("dim"),iint("tag"),idouble("angle","45."))
model_geo.add(None,"SetSmoothing",iint("dim"),iint("tag"),iint("val"))
model_geo.add(None,"SetReverseMesh",iint("dim"),iint("tag"),ibool("val","true"))
model_geo.add(None,"Synchronize")

model_occ = api.add_module("ModelOcc")
#model_occ.add(oint,"AddPoint",iint("tag"),idouble("x"),idouble("y"),
#        idouble("z"),idouble("meshSize","0."))
#model_occ.add(oint,"AddLine",iint("tag"),iint("startTag"),iint("endTag"))
#model_occ.add(oint,"AddCircleArc",iint("tag"),iint("startTag"),iint("centerTag"),
#        iint("endTag"))
#model_occ.add(oint,"AddCircle",iint("tag"),idouble("x"),idouble("y"),
#        idouble("z"),idouble("r"),
#        idouble("angle1","0."),idouble("angle2","2*M_PI"))
#model_occ.add(oint,"AddEllipseArc",iint("tag"),iint("startTag"),iint("centerTag"),
#        iint("endTag"))
#model_occ.add(oint,"AddEllipse",iint("tag"),idouble("x"),idouble("y"),
#        idouble("z"),idouble("r1"),idouble("r2"),
#        idouble("angle1","0."),
#        idouble("angle2","2*M_PI"))
#model_occ.add(oint,"AddSpline",iint("tag"),ivectorint("vertexTags"))
#model_occ.add(oint,"AddBezier",iint("tag"),ivectorint("vertexTags"))
#model_occ.add(oint,"AddBSpline",iint("tag"),ivectorint("vertexTags"))
#model_occ.add(oint,"AddWire",iint("tag"),ivectorint("edgeTags"),
#        ibool("checkClosed","false"))
#model_occ.add(oint,"AddLineLoop",iint("tag"),ivectorint("edgeTags"))
#model_occ.add(oint,"AddRectangle",iint("tag"),idouble("x"),idouble("y"),
#        idouble("z"),idouble("dx"),idouble("dy"),
#        idouble("roundedRadius","0."))
#model_occ.add(oint,"AddDisk",iint("tag"),idouble("xc"),idouble("yc"),
#        idouble("zc"),idouble("rx"),idouble("ry"))
#model_occ.add(oint,"AddPlaneSurface",iint("tag"),ivectorint("wireTags"))
#model_occ.add(oint,"AddSurfaceFilling",iint("tag"),iint("wireTag"))
#model_occ.add(oint,"AddSurfaceLoop",iint("tag"),ivectorint("faceTags"))
#model_occ.add(oint,"AddVolume",iint("tag"),ivectorint("shellTags"))
#model_occ.add(oint,"AddSphere",iint("tag"),idouble("xc"),idouble("yc"),
#        idouble("zc"),idouble("radius"),
#        idouble("angle1","-M_PI/2"),
#        idouble("angle2","M_PI/2"),
#        idouble("angle3","2*M_PI"))
#model_occ.add(oint,"AddBox",iint("tag"),idouble("x"),idouble("y"),
#        idouble("z"),idouble("dx"),idouble("dy"),
#        idouble("dz"))
#model_occ.add(oint,"AddCylinder",iint("tag"),idouble("x"),idouble("y"),
#        idouble("z"),idouble("dx"),idouble("dy"),
#        idouble("dz"),idouble("r"),
#        idouble("angle","2*M_PI"))
#model_occ.add(oint,"AddCone",iint("tag"),idouble("x"),idouble("y"),
#        idouble("z"),idouble("dx"),idouble("dy"),
#        idouble("dz"),idouble("r1"),idouble("r2"),
#        idouble("angle","2*M_PI"))
#model_occ.add(oint,"AddWedge",iint("tag"),idouble("x"),idouble("y"),
#        idouble("z"),idouble("dx"),idouble("dy"),
#        idouble("dz"),idouble("ltx","0."))
#model_occ.add(oint,"AddTorus",iint("tag"),idouble("x"),idouble("y"),
#        idouble("z"),idouble("r1"),idouble("r2"),
#        idouble("angle","2*M_PI"))
#model_occ.add(oint,"AddThruSections",ivectorint("wireTags"),
#        ovectorpair("outDimTags"),
#        iint("tag"),
#        ibool("makeSolid","true"),
#        ibool("makeRuled","false"))
#GMSH_API addThickSolid"",iint("tag"),iint("solidTag"),
#                       ivectorint("excludeFaceTags"),
#                       idouble("offset"),ovectorpair("outDimTags"))
model_occ.add(None,"Extrude",ivectorpair("inDimTags"),idouble("dx"),idouble("dy"),
        idouble("dz"),ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_occ.add(None,"Revolve",ivectorpair("inDimTags"),
        idouble("x"),idouble("y"),idouble("z"),
        idouble("ax"),idouble("ay"),idouble("az"),
        idouble("angle"),ovectorpair("outDimTags"),
        ivectorint("numElements","std::vector<int>()"),
        ivectordouble("heights","std::vector<double>()"),
        ibool("recombine","false"))
model_occ.add(None,"AddPipe",ivectorpair("inDimTags"),iint("wireTag"),
        ovectorpair("outDimTags"))
model_occ.add(None,"Fillet",ivectorint("regionTags"),
        ivectorint("edgeTags"),
        idouble("radius"),ovectorpair("outDimTags"),
        ibool("removeRegion","true"))
model_occ.add(oint,"BooleanUnion",ivectorpair("objectDimTags"),
        ivectorpair("toolDimTags"),
        ovectorpair("outDimTags"),
        ovectorvectorpair("outDimTagsMap"),
        iint("tag","-1"),
        ibool("removeObject","true"),
        ibool("removeTool","true"))
model_occ.add(oint,"BooleanIntersection",ivectorpair("objectDimTags"),
        ivectorpair("toolDimTags"),
        ovectorpair("outDimTags"),
        ovectorvectorpair("outDimTagsMap"),
        iint("tag"),
        ibool("removeObject","true"),
        ibool("removeTool","true"))
model_occ.add(oint,"BooleanDifference",ivectorpair("objectDimTags"),
        ivectorpair("toolDimTags"),
        ovectorpair("outDimTags"),
        ovectorvectorpair("outDimTagsMap"),
        iint("tag","-1"),
        ibool("removeObject","true"),
        ibool("removeTool","true"))
model_occ.add(oint,"BooleanFragments",ivectorpair("objectDimTags"),
        ivectorpair("toolDimTags"),
        ovectorpair("outDimTags"),
        ovectorvectorpair("outDimTagsMap"),
        iint("tag","-1"),
        ibool("removeObject","true"),
        ibool("removeTool","true"))
model_occ.add(None,"Translate",ivectorpair("dimTags"),idouble("dx"),
        idouble("dy"),idouble("dz"))
model_occ.add(None,"Rotate",ivectorpair("dimTags"),idouble("x"),
        idouble("y"),idouble("z"),idouble("ax"),
        idouble("ay"),idouble("az"),idouble("angle"))
model_occ.add(None,"Dilate",ivectorpair("dimTags"),idouble("x"),
        idouble("y"),idouble("z"),idouble("a"),
        idouble("b"),idouble("c"))
model_occ.add(None,"Symmetry",ivectorpair("dimTags"),idouble("a"),
        idouble("b"),idouble("c"),idouble("d"))
model_occ.add(None,"Copy",ivectorpair("inDimTags"),ovectorpair("outDimTags"))
model_occ.add(None,"Remove",ivectorpair("dimTags"),ibool("recursive","false"))
model_occ.add(None,"RemoveAllDuplicates")
model_occ.add(None,"ImportShapes",istring("fileName"),ovectorpair("outDimTags"),
        ibool("highestDimOnly","true"),
        istring("format",""))
model_occ.add(None,"SetMeshSize",ivectorpair("dimTags"),idouble("size"))
model_occ.add(None,"Synchronize")

model_field = api.add_module("ModelField")
model_field.add(oint,"Create",istring("type"),iint("tag","-1"))
model_field.add(None,"SetNumber",iint("tag"),istring("option"),idouble("value"))
model_field.add(None,"SetString",iint("tag"),istring("option"),istring("value"))
model_field.add(None,"SetNumbers",iint("tag"),istring("option"),ivectordouble("value"))
model_field.add(None,"SetAsBackground",iint("tag"))
model_field.add(None,"Delete",iint("tag"))

api.add_module("View")
api.add_module("Plugin")
api.add_module("Graphics")

api.write_cpp("gmsh")
api.write_c("gmshc")
api.write_python()
