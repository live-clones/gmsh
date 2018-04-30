# Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

# This is the master definition file for the Gmsh API.
#
# Running `python gen.py' will generate
#
#  - gmsh.h: the Gmsh C++ API header
#  - gmsh.py: the Gmsh Python API module
#  - gmshc.h: the Gmsh C API header
#  - gmsh.h_cwrap: the Gmsh C++ API refined in terms of the C API
#  - gmshc.cpp: the C to C++ wrapper code used by the Gmsh C API
#  - api.texi: the texinfo API documentation
#
# By design, the Gmsh API is purely functional, and only uses elementary types
# of the target language.
#
# See `demos/api' for examples on how to use the Gmsh API. In particular, this
# directory contains C++ and Python versions of several of the `.geo' tutorials
# from `tutorials'.

from GenApi import *

api = API('3.0')

################################################################################

gmsh = api.add_module('gmsh','Top-level functions')

doc = '''Initializes Gmsh. This must be called before any call to the other functions in the API. If `argc' and `argv' are provided, they will be handled in the same way as the command line arguments in the Gmsh app. If `readConfigFiles' is set, reads system Gmsh configuration files (gmshrc and gmsh-options).'''
gmsh.add('initialize',doc,None,argcargv(),ibool('readConfigFiles','true','True'))

doc = '''Finalizes Gmsh. This must be called when you are done using the Gmsh API.'''
gmsh.add('finalize',doc,None)

doc = '''Opens a file. Equivalent to the `File->Open' menu in the Gmsh app. Handling of the file depends on its extension and/or its contents.'''
gmsh.add('open',doc,None,istring('fileName'))

doc = '''Merges a file. Equivalent to the `File->Merge' menu in the Gmsh app. Handling of the file depends on its extension and/or its contents.'''
gmsh.add('merge',doc,None,istring('fileName'))

doc = '''Writes a file. The export format is determined by the file extension.'''
gmsh.add('write',doc,None,istring('fileName'))

doc = '''Clears all loaded models and post-processing data, and adds a new empty model.'''
gmsh.add('clear',doc,None)

################################################################################

option = gmsh.add_module('option','Global option handling functions')

doc = '''Sets a numerical option to `value'. `name' is of the form "category.option" or "category[num].option". Available categories and options are listed in the Gmsh reference manual.'''
option.add('setNumber',doc,None,istring('name'),idouble('value'))

doc = '''Gets the `value' of a numerical option.'''
option.add('getNumber',doc,None,istring('name'),odouble('value'))

doc = '''Sets a string option to `value'.'''
option.add('setString',doc,None,istring('name'),istring('value'))

doc = '''Gets the `value' of a string option.'''
option.add('getString',doc,None,istring('name'),ostring('value'))

################################################################################

model = gmsh.add_module('model','Per-model functions')

doc = '''Adds a new model, with name `name', and sets it as the current model.'''
model.add('add',doc,None,istring('name'))

doc = '''Removes the current model.'''
model.add('remove',doc,None)

doc = '''Lists the names of all models.'''
model.add('list',doc,None,ovectorstring('names'))

doc = '''Sets the current model to the model with name `name'. If several models have the same name, selects the one that was added first.'''
model.add('setCurrent',doc,None,istring('name'))

doc = '''Gets all the (elementary) geometrical entities in the current model. If `dim' is >= 0, returns only the entities of the specified dimension (e.g. points if `dim' == 0). The entities are returned as a vector of (dim, tag) integer pairs.'''
model.add('getEntities',doc,None,ovectorpair('dimTags'),iint('dim','-1'))

doc = '''Gets all the physical groups in the current model. If `dim' is >= 0, returns only the entities of the specified dimension (e.g. physical points if `dim' == 0). The entities are returned as a vector of (dim, tag) integer pairs.'''
model.add('getPhysicalGroups',doc,None,ovectorpair('dimTags'),iint('dim','-1'))

doc = '''Gets the tags of all the (elementary) geometrical entities making up the physical group of dimension `dim' and tag `tag'.'''
model.add('getEntitiesForPhysicalGroup',doc,None,iint('dim'),iint('tag'),ovectorint('tags'))

doc = '''Adds a physical group of dimension `dim', grouping the elementary entities with tags `tags'. The function returns the tag of the physical group, equal to `tag' if `tag' is positive, or a new tag if `tag' < 0.'''
model.add('addPhysicalGroup',doc,oint,iint('dim'),ivectorint('tags'),iint('tag','-1'))

doc = '''Sets the name of the physical group of dimension `dim' and tag `tag'.'''
model.add('setPhysicalName',doc,None,iint('dim'),iint('tag'),istring('name'))

doc = '''Gets the name of the physical group of dimension `dim' and tag `tag'.'''
model.add('getPhysicalName',doc,None,iint('dim'),iint('tag'),ostring('name'))

doc = '''Gets the boundary of the geometrical entities `dimTags'. Returns in `outDimTags' the boundary of the individual entities (if `combined' is false) or the boundary of the combined geometrical shape formed by all input entities (if `combined' is true). Returns tags multiplied by the sign of the boundary entity if `oriented' is true. Applies the boundary operator recursively down to dimension 0 (i.e. to points) if `recursive' is true.'''
model.add('getBoundary',doc,None,ivectorpair('dimTags'),ovectorpair('outDimTags'),ibool('combined','true','True'),ibool('oriented','true','True'),ibool('recursive','false','False'))

doc = '''Gets the (elementary) geometrical entities in the bounding box defined by the two points (`xmin', `ymin', `zmin') and (`xmax', `ymax', `zmax'). If `dim' is >= 0, returns only the entities of the specified dimension (e.g. points if `dim' == 0).'''
model.add('getEntitiesInBoundingBox',doc,None,idouble('xmin'),idouble('ymin'),idouble('zmin'),idouble('xmax'),idouble('ymax'),idouble('zmax'),ovectorpair('tags'),iint('dim','-1'))

doc = '''Gets the bounding box (`xmin', `ymin', `zmin'), (`xmax', `ymax', `zmax') of the geometrical entity of dimension `dim' and tag `tag'.'''
model.add('getBoundingBox',doc,None,iint('dim'),iint('tag'),odouble('xmin'),odouble('ymin'),odouble('zmin'),odouble('xmax'),odouble('ymax'),odouble('zmax'))

doc = '''Adds a discrete geometrical entity (defined by a mesh) of dimension `dim' in the current model. The function returns the tag of the new discrete entity, equal to `tag' if `tag' is positive, or a new tag if `tag' < 0. `boundary' specifies the tags of the entities on the boundary of the discrete entity, if any. Specyfing `boundary' allows Gmsh to construct the topology of the overall model.'''
model.add('addDiscreteEntity',doc,oint,iint('dim'),iint('tag','-1'),ivectorint('boundary','std::vector<int>()',"[]"))

doc = '''Removes the entities `dimTags' of the current model. If `recursive' is true, removes all the entities on their boundaries, down to dimension 0.'''
model.add('removeEntities',doc,None,ivectorpair('dimTags'),ibool('recursive','false','False'))

doc = '''Gets the type of the entity of dimension `dim' and tag `tag'.'''
model.add('getType',doc,None,iint('dim'),iint('tag'),ostring('type'))

################################################################################

mesh = model.add_module('mesh','Per-model meshing functions')

doc = '''Generates a mesh of the current model, up to dimension `dim' (0, 1, 2 or 3).'''
mesh.add('generate',doc,None,iint('dim'))

doc = '''Partitions the mesh of the current model into `numPart' partitions.'''
mesh.add('partition',doc,None,iint('numPart'))

doc = '''Refines the mesh of the current model by uniformly splitting the elements.'''
mesh.add('refine',doc,None)

doc = '''Sets the order of the elements in the mesh of the current model to `order'.'''
mesh.add('setOrder',doc,None,iint('order'))

doc = '''Removes duplicate mesh nodes in the mesh of the current model.'''
mesh.add('removeDuplicateNodes',doc,None)

doc = '''Gets the last entities (if any) where a meshing error occurred. Currently only populated by the new 3D meshing algorithms.'''
mesh.add('getLastEntityError',doc,None,ovectorpair('dimTags'))

doc = '''Gets the last mesh nodes (if any) where a meshing error occurred. Currently only populated by the new 3D meshing algorithms.'''
mesh.add('getLastNodeError',doc,None,ovectorint('nodeTags'))

doc = '''Gets the mesh nodes of the entity of dimension `dim' and `tag' tag. If `tag' < 0, gets the nodes for all entities of dimension `dim'. If `dim' and `tag' are negative, gets all the nodes in the mesh. `nodeTags' contains the node tags (their unique, strictly positive identification numbers). `coord' is a vector of length 3 times the length of `nodeTags' that contains the (x, y, z) coordinates of the nodes, concatenated. If `dim' >= 0, `parametricCoord' contains the parametric coordinates of the nodes, if available. The length of `parametricCoord' can be 0 or `dim' times the length of `nodeTags'.'''
mesh.add('getNodes',doc,None,ovectorint('nodeTags'),ovectordouble('coord'),ovectordouble('parametricCoord'),iint('dim', '-1'),iint('tag', '-1'))

doc = '''Gets the mesh elements of the entity of dimension `dim' and `tag' tag. If `tag' < 0, gets the elements for all entities of dimension `dim'. If `dim' and `tag' are negative, gets all the elements in the mesh. `elementTypes' contains the MSH types of the elements (e.g. `2' for 3-node triangles: see `getElementProperties' to obtain the properties for a given element type). `elementTags' is a vector of the same length as `elementTypes'; each entry is a vector containing the tags (unique, strictly positive identifiers) of the elements of the corresponding type. `nodeTags' is also a vector of the same length as `elementTypes'; each entry is a vector of length equal to the number of elements of the given type times the number of nodes for this type of element, that contains the node tags of all the elements of the given type, concatenated.'''
mesh.add('getElements',doc,None,ovectorint('elementTypes'),ovectorvectorint('elementTags'),ovectorvectorint('nodeTags'),iint('dim', '-1'),iint('tag', '-1'))

doc = '''Gets the properties of an element of type `elementType': its name (`elementName'), dimension (`dim'), order (`order'), number of nodes (`numNodes') and parametric coordinates of nodes (`parametricCoord' vector, of length `dim' times `numNodes').'''
mesh.add('getElementProperties',doc,None,iint('elementType'),ostring('elementName'),oint('dim'),oint('order'),oint('numNodes'),ovectordouble('parametricCoord'))

doc = '''Gets the integration data for mesh elements of the entity of dimension `dim' and `tag' tag. The data is returned by element type and by element, in the same order as the data returned by `getElements'. `integrationType' specifies the type of integration (e.g. \"Gauss4\") and `functionSpaceType' specifies the function space (e.g. \"IsoParametric\"). `integrationPoints' contains for each element type a vector (of length 4 times the number of integration points) containing the parametric coordinates (u, v, w) and the weight associated to the integration points. `integrationData' contains for each element type a vector (of size 13 times the number of integration points) containing the (x, y, z) coordinates of the integration point, the determinant of the Jacobian and the 9 entries (by row) of the 3x3 Jacobian matrix. If `functionSpaceType' is provided, `functionSpaceNumComponents' returns the number of components returned by the evaluation of a basis function in the space and `functionSpaceData' contains for each element type the evaluation of the basis functions at the integration points.'''
mesh.add('getIntegrationData',doc,None,istring('integrationType'),istring('functionSpaceType'),ovectorvectordouble('integrationPoints'),ovectorvectordouble('integrationData'),oint('functionSpaceNumComponents'),ovectorvectordouble('functionSpaceData'),iint('dim', '-1'),iint('tag', '-1'))

doc = '''Gets the types of mesh elements in the entity of dimension `dim' and `tag' tag. If `tag' < 0, gets the types for all entities of dimension `dim'. If `dim' and `tag' are negative, gets all the types in the mesh.'''
mesh.add('getElementTypes',doc,None,ovectorint('elementTypes'),iint('dim', '-1'),iint('tag', '-1'))

doc = '''Gets the mesh elements in the same way as `getElements', but for a single `elementType'.'''
mesh.add('getElementsByType',doc,None,iint('elementType'),ovectorint('elementTags'),ovectorint('nodeTags'),iint('dim', '-1'),iint('tag', '-1'))

doc = '''Gets the integration data for mesh elements in the same way as `getIntegrationData', but for a single `elementType'.'''
mesh.add('getIntegrationDataByType',doc,None,iint('elementType'),istring('integrationType'),istring('functionSpaceType'),ovectordouble('integrationPoints'),ovectordouble('integrationData'),oint('functionSpaceNumComponents'),ovectordouble('functionSpaceData'),iint('dim', '-1'),iint('tag', '-1'))

doc = '''Sets the mesh nodes in the geometrical entity of dimension `dim' and tag `tag'. `nodetags' contains the node tags (their unique, strictly positive identification numbers). `coord' is a vector of length 3 times the length of `nodeTags' that contains the (x, y, z) coordinates of the nodes, concatenated. The optional `parametricCoord' vector contains the parametric coordinates of the nodes, if any. The length of `parametricCoord' can be 0 or `dim' times the length of `nodeTags'.'''
mesh.add('setNodes',doc,None,iint('dim'),iint('tag'),ivectorint('nodeTags'),ivectordouble('coord'),ivectordouble('parametricCoord','std::vector<double>()',"[]"))

doc = '''Sets the mesh elements of the entity of dimension `dim' and `tag' tag. `types' contains the MSH types of the elements (e.g. `2' for 3-node triangles: see the Gmsh reference manual). `elementTags' is a vector of the same length as `types'; each entry is a vector containing the tags (unique, strictly positive identifiers) of the elements of the corresponding type. `nodeTags' is also a vector of the same length as `types'; each entry is a vector of length equal to the number of elements of the give type times the number of nodes per element, that contains the node tags of all the elements of the given type, concatenated.'''
mesh.add('setElements',doc,None,iint('dim'),iint('tag'),ivectorint('types'),ivectorvectorint('elementTags'),ivectorvectorint('nodeTags'))

doc = '''Redistributes all mesh nodes on their associated geometrical entity, based on the mesh elements. Can be used when importing mesh nodes in bulk (e.g. by associating them all to a single volume), to reclassify them correctly on model surfaces, curves, etc.'''
mesh.add('reclassifyNodes',doc,None)

doc = '''Gets the coordinates and the parametric coordinates (if any) of the mesh node with tag `tag'. This is a useful by inefficient way of accessing mesh node data, as it relies on a cache stored in the model. For large meshes all the nodes in the model should be numbered in a continuous sequence of tags from 1 to N to maintain reasonnable performance (in this case the internal cache is based on a vector; otherwise it uses a map).'''
mesh.add('getNode',doc,None,iint('nodeTag'),ovectordouble('coord'),ovectordouble('parametricCoord'))

doc = '''Gets the type and node tags of the mesh element with tag `tag'. This is a useful but inefficient way of accessing mesh element data, as it relies on a cache stored in the model. For large meshes all the elements in the model should be numbered in a continuous sequence of tags from 1 to N to maintain reasonnable performance (in this case the internal cache is based on a vector; otherwise it uses a map).'''
mesh.add('getElement',doc,None,iint('elementTag'),oint('type'),ovectorint('nodeTags'))

doc = '''Sets a mesh size constraint on the geometrical entities `dimTags'. Currently only entities of dimension 0 (points) are handled.'''
mesh.add('setSize',doc,None,ivectorpair('dimTags'),idouble('size'))

doc = '''Sets a transfinite meshing constraint on the curve `tag', with `numNodes' mesh nodes distributed according to `type' and `coef'. Currently supported types are "Progression" (geometrical progression with power `coef') and "Bump" (refinement toward both extremities of the curve).'''
mesh.add('setTransfiniteCurve',doc,None,iint('tag'),iint('numNodes'),istring('type','"Progression"'),idouble('coef','1.'))

doc = '''Sets a transfinite meshing constraint on the surface `tag'. `arrangement' describes the arrangement of the triangles when the surface is not flagged as recombined: currently supported values are "Left", "Right", "AlternateLeft" and "AlternateRight". `cornerTags' can be used to specify the (3 or 4) corners of the transfinite interpolation explicitly; specifying the corners explicitly is mandatory if the surface has more that 3 or 4 points on its boundary.'''
mesh.add('setTransfiniteSurface',doc,None,iint('tag'),istring('arrangement','"Left"'),ivectorint('cornerTags','std::vector<int>()',"[]"))

doc = '''Sets a transfinite meshing constraint on the surface `tag'. `cornerTags' can be used to specify the (6 or 8) corners of the transfinite interpolation explicitly.'''
mesh.add('setTransfiniteVolume',doc,None,iint('tag'),ivectorint('cornerTags','std::vector<int>()',"[]"))

doc = '''Sets a recombination meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. Currently only entities of dimension 2 (to recombine triangles into quadrangles) are supported.'''
mesh.add('setRecombine',doc,None,iint('dim'),iint('tag'))

doc = '''Sets a smoothing meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. `val' iterations of a Laplace smoother are applied.'''
mesh.add('setSmoothing',doc,None,iint('dim'),iint('tag'),iint('val'))

doc = '''Sets a reverse meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. If `val' is true, the mesh orientation will be reversed with respect to the natural mesh orientation (i.e. the orientation consistent with the orientation of the geometrical entity). If `val' is false, the mesh is left as-is.'''
mesh.add('setReverse',doc,None,iint('dim'),iint('tag'),ibool('val','true','True'))

doc = '''Embeds the geometrical entities of dimension `dim' and tags `tags' in the (inDim, inTag) geometrical entity. `inDim' must be strictly greater than `dim'.'''
mesh.add('embed',doc,None,iint('dim'),ivectorint('tags'),iint('inDim'),iint('inTag'))

doc = '''Sets the meshes of the entities of dimension `dim' and tag `tags' as periodic copies of the meshes of entities `tagsSource', using the affine transformation specified in `affineTransformation' (16 entries of a 4x4 matrix, by row). Currently only available for `dim' == 1 and `dim' == 2.'''
mesh.add('setPeriodic',doc,None,iint('dim'),ivectorint('tags'),ivectorint('tagsSource'),ivectordouble('affineTransformation'))

################################################################################

field = mesh.add_module('field','Per-model mesh size field functions')

doc = '''Adds a new mesh size field of type `type'. If `tag' is positive, assigns the tag explcitly; otherwise a new tag is assigned automatically. Returns the field tag.'''
field.add('add',doc,oint,istring('type'),iint('tag','-1'))

doc = '''Removes the field with tag `tag'.'''
field.add('remove',doc,None,iint('tag'))

doc = '''Sets the numerical option `option' to value `value' for field `tag'.'''
field.add('setNumber',doc,None,iint('tag'),istring('option'),idouble('value'))

doc = '''Sets the string option `option' to value `value' for field `tag'.'''
field.add('setString',doc,None,iint('tag'),istring('option'),istring('value'))

doc = '''Sets the numerical list option `option' to value `value' for field `tag'.'''
field.add('setNumbers',doc,None,iint('tag'),istring('option'),ivectordouble('value'))

doc = '''Sets the field `tag' as the background mesh size field.'''
field.add('setAsBackgroundMesh',doc,None,iint('tag'))

doc = '''Sets the field `tag' as a boundary layer size field.'''
field.add('setAsBoundaryLayer',doc,None,iint('tag'))

################################################################################

geo = model.add_module('geo','Internal per-model GEO CAD kernel functions')

doc = '''Adds a geometrical point in the internal GEO CAD representation, at coordinates (x, y, z). If `meshSize' is > 0, adds a meshing constraint at that point. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the point. (Note that the point will be added in the current model only after `synchronize' is called. This behavior holds for all the entities added in the geo module.)'''
geo.add('addPoint',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('meshSize','0.'),iint('tag','-1'))

doc = '''Adds a straight line segment between the two points with tags `startTag' and `endTag'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the line.'''
geo.add('addLine',doc,oint,iint('startTag'),iint('endTag'),iint('tag','-1'))

doc = '''Adds a circle arc (stricly smaller than Pi) between the two points with tags `startTag' and `endTag', with center `centertag'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. If (`nx', `ny', `nz') != (0,0,0), explicitely sets the plane of the circle arc. Returns the tag of the circle arc.'''
geo.add('addCircleArc',doc,oint,iint('startTag'),iint('centerTag'),iint('endTag'),iint('tag','-1'),idouble('nx','0.'),idouble('ny','0.'),idouble('nz','0.'))

doc = '''Adds an ellipse arc (stricly smaller than Pi) between the two points `startTag' and `endTag', with center `centertag' and major axis point `majorTag'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. If (`nx', `ny', `nz') != (0,0,0), explicitely sets the plane of the circle arc. Returns the tag of the ellipse arc.'''
geo.add('addEllipseArc',doc,oint,iint('startTag'),iint('centerTag'),iint('majorTag'),iint('endTag'),iint('tag','-1'),idouble('nx','0.'),idouble('ny','0.'),idouble('nz','0.'))

doc = '''Adds a spline (Catmull-Rom) curve going through the points `pointTags'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Creates a periodic curve if the first and last points are the same. Returns the tag of the spline curve.'''
geo.add('addSpline',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Adds a cubic b-spline curve with `pointTags' control points. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Creates a periodic curve if the first and last points are the same. Returns the tag of the b-spline curve.'''
geo.add('addBSpline',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Adds a Bezier curve with `pointTags' control points. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically.  Returns the tag of the Bezier curve.'''
geo.add('addBezier',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Adds a curve loop (a closed wire) formed by the curves `curveTags'. `curveTags' should contain (signed) tags of geometrical enties of dimension 1 forming a closed loop: a negative tag signifies that the underlying curve is considered with reversed orientation. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the curve loop.'''
geo.add('addCurveLoop',doc,oint,ivectorint('curveTags'),iint('tag','-1'))

doc = '''Adds a plane surface defined by one or more curve loops `wireTags'. The first curve loop defines the exterior contour; additional curve loop define holes. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the surface.'''
geo.add('addPlaneSurface',doc,oint,ivectorint('wireTags'),iint('tag','-1'))

doc = '''Adds a surface filling the curve loops in `wireTags'. Currently only a single curve loop is supported; this curve loop should be composed by 3 or 4 curves only. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the surface.'''
geo.add('addSurfaceFilling',doc,oint,ivectorint('wireTags'),iint('tag','-1'),iint('sphereCenterTag','-1'))

doc = '''Adds a surface loop (a closed shell) formed by `surfaceTags'.  If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the shell.'''
geo.add('addSurfaceLoop',doc,oint,ivectorint('surfaceTags'),iint('tag','-1'))

doc = '''Adds a volume (a region) defined by one or more shells `shellTags'. The first surface loop defines the exterior boundary; additional surface loop define holes. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the volume.'''
geo.add('addVolume',doc,oint,ivectorint('shellTags'),iint('tag','-1'))

doc = '''Extrudes the geometrical entities `dimTags' by translation along (`dx', `dy', `dz'). Returns extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
geo.add('extrude',doc,None,ivectorpair('dimTags'),idouble('dx'),idouble('dy'),idouble('dz'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]"),ivectordouble('heights','std::vector<double>()',"[]"),ibool('recombine','false','False'))

doc = '''Extrudes the geometrical entities `dimTags' by rotation of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az'). Returns extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
geo.add('revolve',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]"),ivectordouble('heights','std::vector<double>()',"[]"),ibool('recombine','false','False'))

doc = '''Extrudes the geometrical entities `dimTags' by a combined translation and rotation of `angle' radians, along (`dx', `dy', `dz') and around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az'). Returns extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
geo.add('twist',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]"),ivectordouble('heights','std::vector<double>()',"[]"),ibool('recombine','false','False'))

doc = '''Translates the geometrical entities `dimTags' along (`dx', `dy', `dz').'''
geo.add('translate',doc,None,ivectorpair('dimTags'),idouble('dx'),idouble('dy'),idouble('dz'))

doc = '''Rotates the geometrical entities `dimTags' of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az').'''
geo.add('rotate',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'))

doc = '''Scales the geometrical entities `dimTag' by factors `a', `b' and `c' along the three coordinate axes; use (`x', `y', `z') as the center of the homothetic transformation.'''
geo.add('dilate',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('a'),idouble('b'),idouble('c'))

doc = '''Applies a symmetry transformation to the geometrical entities `dimTag', with respect to the plane of equation `a' * x + `b' * y + `c' * z + `d' = 0.'''
geo.add('symmetry',doc,None,ivectorpair('dimTags'),idouble('a'),idouble('b'),idouble('c'),idouble('d'))

doc = '''Copies the entities `dimTags'; the new entities are returned in `outDimTags'.'''
geo.add('copy',doc,None,ivectorpair('dimTags'),ovectorpair('outDimTags'))

doc = '''Removes the entities `dimTags'. If `recursive' is true, removes all the entities on their boundaries, down to dimension 0.'''
geo.add('remove',doc,None,ivectorpair('dimTags'),ibool('recursive','false','False'))

doc = '''Removes all duplicate entities (different entities at the same geometrical location).'''
geo.add('removeAllDuplicates',doc,None)

doc = '''Synchronize the internal GEO CAD representation with the current Gmsh model. This can be called at any time, but since it involves a non trivial amount of processing, the number of synchronization points should normally be minimized.'''
geo.add('synchronize',doc,None)

################################################################################

mesh = geo.add_module('mesh','geo-specific meshing constraints')

doc = '''Sets a mesh size constraint on the geometrical entities `dimTags'. Currently only entities of dimension 0 (points) are handled.'''
mesh.add('setSize',doc,None,ivectorpair('dimTags'),idouble('size'))

doc = '''Sets a transfinite meshing constraint on the curve `tag', with `numNodes' mesh nodes distributed according to `type' and `coef'. Currently supported types are "Progression" (geometrical progression with power `coef') and "Bump" (refinement toward both extreminties of the curve).'''
mesh.add('setTransfiniteCurve',doc,None,iint('tag'),iint('nPoints'),istring('type','"Progression"'),idouble('coef','1.'))

doc = '''Sets a transfinite meshing constraint on the surface `tag'. `arrangement' describes the arrangement of the triangles when the surface is not flagged as recombined: currently supported values are "Left", "Right", "AlternateLeft" and "AlternateRight". `cornerTags' can be used to specify the (3 or 4) corners of the transfinite interpolation explicitly; specifying the corners explicitly is mandatory if the surface has more that 3 or 4 points on its boundary.'''
mesh.add('setTransfiniteSurface',doc,None,iint('tag'),istring('arrangement','"Left"'),ivectorint('cornerTags','std::vector<int>()',"[]"))

doc = '''Sets a transfinite meshing constraint on the surface `tag'. `cornerTags' can be used to specify the (6 or 8) corners of the transfinite interpolation explicitly.'''
mesh.add('setTransfiniteVolume',doc,None,iint('tag'),ivectorint('cornerTags','std::vector<int>()',"[]"))

doc = '''Sets a recombination meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. Currently only entities of dimension 2 (to recombine triangles into quadrangles) are supported.'''
mesh.add('setRecombine',doc,None,iint('dim'),iint('tag'),idouble('angle','45.'))

doc = '''Sets a smoothing meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. `val' iterations of a Laplace smoother are applied.'''
mesh.add('setSmoothing',doc,None,iint('dim'),iint('tag'),iint('val'))

doc = '''Sets a reverse meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. If `val' is true, the mesh orientation will be reversed with respect to the natural mesh orientation (i.e. the orientation consistent with the orientation of the geometrical entity). If `val' is false, the mesh is left as-is.'''
mesh.add('setReverse',doc,None,iint('dim'),iint('tag'),ibool('val','true','True'))

################################################################################

occ = model.add_module('occ','Internal per-model OpenCASCADE CAD kernel functions')

doc = '''Adds a geometrical point in the internal OpenCASCADE CAD representation, at coordinates (x, y, z). If `meshSize' is > 0, adds a meshing constraint at that point. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the point. (Note that the point will be added in the current model only after `synchronize' is called. This behavior holds for all the entities added in the occ module.)'''
occ.add('addPoint',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('meshSize','0.'),iint('tag','-1'))

doc = '''Adds a straight line segment between the two points with tags `startTag' and `endTag'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the line.'''
occ.add('addLine',doc,oint,iint('startTag'),iint('endTag'),iint('tag','-1'))

doc = '''Adds a circle arc between the two points with tags `startTag' and `endTag', with center `centerTag'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the circle arc.'''
occ.add('addCircleArc',doc,oint,iint('startTag'),iint('centerTag'),iint('endTag'),iint('tag','-1'))

doc = '''Adds a circle of center (`x', `y', `z') and radius `r'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. If `angle1' and `angle2' are specified, creates a circle arc between the two angles. Returns the tag of the circle.'''
occ.add('addCircle',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('r'),iint('tag','-1'),idouble('angle1','0.'),idouble('angle2','2*M_PI','2*pi'))

doc = '''Adds an ellipse arc between the two points with tags `startTag' and `endTag', with center `centerTag'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the ellipse arc.'''
occ.add('addEllipseArc',doc,oint,iint('startTag'),iint('centerTag'),iint('endTag'),iint('tag','-1'))

doc = '''Adds an ellipse of center (`x', `y', `z') and radii `r1' and `r2' along the x- and y-axes respectively. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. If `angle1' and `angle2' are specified, creates an ellipse arc between the two angles. Returns the tag of the ellipse.'''
occ.add('addEllipse',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('r1'),idouble('r2'),iint('tag','-1'),idouble('angle1','0.'),idouble('angle2','2*M_PI','2*pi'))

doc = '''Adds a spline (C2 b-spline) curve going through the points `pointTags'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Creates a periodic curve if the first and last points are the same. Returns the tag of the spline curve.'''
occ.add('addSpline',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Adds a b-spline curve of degree `degree' with `pointTags' control points. If `weights', `knots' or `multiplicities' are not provided, default parameters are computed automatically. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Creates a periodic curve if the first and last points are the same. Returns the tag of the b-spline curve.'''
occ.add('addBSpline',doc,oint,ivectorint('pointTags'),iint('tag','-1'),iint('degree','3'),ivectordouble('weights','std::vector<double>()',"[]"),ivectordouble('knots','std::vector<double>()',"[]"),ivectorint('multiplicities','std::vector<int>()',"[]"))

doc = '''Adds a Bezier curve with `pointTags' control points. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the Bezier curve.'''
occ.add('addBezier',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Adds a wire (open or closed) formed by the curves `curveTags'. `curveTags' should contain (signed) tags: a negative tag signifies that the underlying curve is considered with reversed orientation. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the wire.'''
occ.add('addWire',doc,oint,ivectorint('curveTags'),iint('tag','-1'),ibool('checkClosed','false','False'))

doc = '''Adds a curve loop (a closed wire) formed by the curves `curveTags'. `curveTags' should contain (signed) tags of curves forming a closed loop: a negative tag signifies that the underlying curve is considered with reversed orientation. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the curve loop.'''
occ.add('addCurveLoop',doc,oint,ivectorint('curveTags'),iint('tag','-1'))

doc = '''Adds a rectangle with lower left corner at (`x', `y', `z') and upper right corner at (`x' + `dx', `y' + `dy', `z'). If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Rounds the corners if `roundedRadius' is nonzero. Returns the tag of the rectangle.'''
occ.add('addRectangle',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),iint('tag','-1'),idouble('roundedRadius','0.'))

doc = '''Adds a disk with center (`xc', `yc', `zc') and radius `rx' along the x-axis and `ry' along the y-axis. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the disk.'''
occ.add('addDisk',doc,oint,idouble('xc'),idouble('yc'),idouble('zc'),idouble('rx'),idouble('ry'),iint('tag','-1'))

doc = '''Adds a plane surface defined by one or more curve loops (or closed wires) `wireTags'. The first curve loop defines the exterior contour; additional curve loop define holes. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the surface.'''
occ.add('addPlaneSurface',doc,oint,ivectorint('wireTags'),iint('tag','-1'))

doc = '''Adds a surface filling the curve loops in `wireTags'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the surface.'''
occ.add('addSurfaceFilling',doc,oint,iint('wireTag'),iint('tag','-1'))

doc = '''Adds a surface loop (a closed shell) formed by `surfaceTags'.  If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the surface loop.'''
occ.add('addSurfaceLoop',doc,oint,ivectorint('surfaceTags'),iint('tag','-1'))

doc = '''Adds a volume (a region) defined by one or more surface loops `shellTags'. The first surface loop defines the exterior boundary; additional surface loop define holes. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the volume.'''
occ.add('addVolume',doc,oint,ivectorint('shellTags'),iint('tag','-1'))

doc = '''Adds a sphere of center (`xc', `yc', `zc') and radius `r'. The optional `angle1' and `angle2' arguments define the polar angle opening (from -Pi/2 to Pi/2). The optional `angle3' argument defines the azimuthal opening (from 0 to 2*Pi). If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the sphere.'''
occ.add('addSphere',doc,oint,idouble('xc'),idouble('yc'),idouble('zc'),idouble('radius'),iint('tag','-1'),idouble('angle1','-M_PI/2','-pi/2'),idouble('angle2','M_PI/2','pi/2'),idouble('angle3','2*M_PI','2*pi'))

doc = '''Adds a parallelepipedic box defined by a point (`x', `y', `z') and the extents along the x-, y- and z-axes. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the box.'''
occ.add('addBox',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),iint('tag','-1'))

doc = '''Adds a cylinder, defined by the center (`x', `y', `z') of its first circular face, the 3 components (`dx', `dy', `dz') of the vector defining its axis and its radius `r'. The optional `angle' argument defines the angular opening (from 0 to 2*Pi). If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. Returns the tag of the cylinder.'''
occ.add('addCylinder',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),idouble('r'),iint('tag','-1'),idouble('angle','2*M_PI','2*pi'))

doc = '''Adds a cone, defined by the center (`x', `y', `z') of its first circular face, the 3 components of the vector (`dx', `dy', `dz') defining its axis and the two radii `r1' and `r2' of the faces (these radii can be zero). If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. `angle' defines the optional angular opening (from 0 to 2*Pi). Returns the tag of the cone.'''
occ.add('addCone',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),idouble('r1'),idouble('r2'),iint('tag','-1'),idouble('angle','2*M_PI','2*pi'))

doc = '''Adds a right angular wedge, defined by the right-angle point (`x', `y', `z') and the 3 extends along the x-, y- and z-axes (`dx', `dy', `dz'). If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. The optional argument `ltx' defines the top extent along the x-axis. Returns the tag of the wedge.'''
occ.add('addWedge',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),iint('tag','-1'),idouble('ltx','0.'))

doc = '''Adds a torus, defined by its center (`x', `y', `z') and its 2 radii `r' and `r2'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. The optional argument `angle' defines the angular opening (from 0 to 2*Pi). Returns the tag of the wedge.'''
occ.add('addTorus',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('r1'),idouble('r2'),iint('tag','-1'),idouble('angle','2*M_PI','2*pi'))

doc = '''Adds a volume (if the optional argument `makeSolid' is set) or surfaces defined through the open or closed wires `wireTags'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically. The new entities are returned in `outDimTags'. If the optional argument `makeRuled' is set, the surfaces created on the boundary are forced to be ruled surfaces.'''
occ.add('addThruSections',doc,None,ivectorint('wireTags'),ovectorpair('outDimTags'),iint('tag','-1'),ibool('makeSolid','true','True'),ibool('makeRuled','false','False'))

doc = '''Adds a hollowed volume built from an initial volume `volumeTag' and a set of faces from this volume `excludeSurfaceTags', which are to be removed. The remaining faces of the volume become the walls of the hollowed solid, with thickness `offset'. If `tag' is positive, sets the tag explicitly; otherwise a new tag is selected automatically.'''
occ.add('addThickSolid',doc,None,iint('volumeTag'),ivectorint('excludeSurfaceTags'),idouble('offset'),ovectorpair('outDimTags'),iint('tag','-1'))

doc = '''Extrudes the geometrical entities `dimTags' by translation along (`dx', `dy', `dz'). Returns extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
occ.add('extrude',doc,None,ivectorpair('dimTags'),idouble('dx'),idouble('dy'),idouble('dz'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]"),ivectordouble('heights','std::vector<double>()',"[]"),ibool('recombine','false','False'))

doc = '''Extrudes the geometrical entities `dimTags' by rotation of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az'). Returns extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
occ.add('revolve',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]"),ivectordouble('heights','std::vector<double>()',"[]"),ibool('recombine','false','False'))

doc = '''Adds a pipe by extruding the entities `dimTags' along the wire `wireTag'. Returns the pipe in `outDimTags'.'''
occ.add('addPipe',doc,None,ivectorpair('dimTags'),iint('wireTag'),ovectorpair('outDimTags'))

doc = '''Fillets the volumes `volumeTags' on the curves `curveTags' with radius `radius'. Returns the filleted entities in `outDimTags'. Removes the original volume if `removeVolume' is set.'''
occ.add('fillet',doc,None,ivectorint('volumeTags'),ivectorint('curveTags'),idouble('radius'),ovectorpair('outDimTags'),ibool('removeVolume','true','True'))

doc = '''Computes the boolean union (the fusion) of the entities `objectDimTags' and `toolDimTags'. Returns the resulting entities in `outDimTags'. If `tag' is positive, attemps to set the tag explicitly (ony valid if the boolean operation results in a single entity). Removes the object if `removeObject' is set. Removes the tool if `removeTool' is set.'''
occ.add('fuse',doc,None,ivectorpair('objectDimTags'),ivectorpair('toolDimTags'),ovectorpair('outDimTags'),ovectorvectorpair('outDimTagsMap'),iint('tag','-1'),ibool('removeObject','true','True'),ibool('removeTool','true','True'))

doc = '''Computes the boolean intersection (the common parts) of the entities `objectDimTags' and `toolDimTags'. Returns the resulting entities in `outDimTags'. If `tag' is positive, attemps to set the tag explicitly (ony valid if the boolean operation results in a single entity). Removes the object if `removeObject' is set. Removes the tool if `removeTool' is set.'''
occ.add('intersect',doc,None,ivectorpair('objectDimTags'),ivectorpair('toolDimTags'),ovectorpair('outDimTags'),ovectorvectorpair('outDimTagsMap'),iint('tag','-1'),ibool('removeObject','true','True'),ibool('removeTool','true','True'))

doc = '''Computes the boolean difference between the entities `objectDimTags' and `toolDimTags'. Returns the resulting entities in `outDimTags'. If `tag' is positive, attemps to set the tag explicitly (ony valid if the boolean operation results in a single entity). Removes the object if `removeObject' is set. Removes the tool if `removeTool' is set.'''
occ.add('cut',doc,None,ivectorpair('objectDimTags'),ivectorpair('toolDimTags'),ovectorpair('outDimTags'),ovectorvectorpair('outDimTagsMap'),iint('tag','-1'),ibool('removeObject','true','True'),ibool('removeTool','true','True'))

doc = '''Copmutes the boolean fragments (general fuse) of the entities `objectDimTags' and `toolDimTags'. Returns the resulting entities in `outDimTags'. If `tag' is positive, attemps to set the tag explicitly (ony valid if the boolean operation results in a single entity). Removes the object if `removeObject' is set. Removes the tool if `removeTool' is set.'''
occ.add('fragment',doc,None,ivectorpair('objectDimTags'),ivectorpair('toolDimTags'),ovectorpair('outDimTags'),ovectorvectorpair('outDimTagsMap'),iint('tag','-1'),ibool('removeObject','true','True'),ibool('removeTool','true','True'))

doc = '''Translates the geometrical entities `dimTags' along (`dx', `dy', `dz').'''
occ.add('translate',doc,None,ivectorpair('dimTags'),idouble('dx'),idouble('dy'),idouble('dz'))

doc = '''Rotates the geometrical entities `dimTags' of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az').'''
occ.add('rotate',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'))

doc = '''Scales the geometrical entities `dimTag' by factors `a', `b' and `c' along the three coordinate axes; use (`x', `y', `z') as the center of the homothetic transformation.'''
occ.add('dilate',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('a'),idouble('b'),idouble('c'))

doc = '''Applies a symmetry transformation to the geometrical entities `dimTag', with respect to the plane of equation `a' * x + `b' * y + `c' * z + `d' = 0.'''
occ.add('symmetry',doc,None,ivectorpair('dimTags'),idouble('a'),idouble('b'),idouble('c'),idouble('d'))

doc = '''Copies the entities `dimTags'; the new entities are returned in `outDimTags'.'''
occ.add('copy',doc,None,ivectorpair('dimTags'),ovectorpair('outDimTags'))

doc = '''Removes the entities `dimTags'. If `recursive' is true, removes all the entities on their boundaries, down to dimension 0.'''
occ.add('remove',doc,None,ivectorpair('dimTags'),ibool('recursive','false','False'))

doc = '''Removes all duplicate entities (different entities at the same geometrical location) after intersecting (using boolean fragments) all highest dimensional entities.'''
occ.add('removeAllDuplicates',doc,None)

doc = '''Imports BREP, STEP or IGES shapes from the file `fileName'. The imported entities are returned in `outDimTags'. If the optional argument `highestDimOnly' is set, only import the highest dimensional entities in the file. The optional argument `format' can be used to force the format of the file (currently "brep", "step" or "iges").'''
occ.add('importShapes',doc,None,istring('fileName'),ovectorpair('outDimTags'),ibool('highestDimOnly','true','True'),istring('format','""'))

#doc = '''Imports native OpenCASCADE shapes by providing a raw pointer to a TopoDS_Shape. The imported entities are returned in `outDimTags'. If the optional argument `highestDimOnly' is set, only import the highest dimensional entities in the file.'''
#occ.add('importShapesNativePointer',doc,None,voidstar('shape'),ovectorpair('outDimTags'),ibool('highestDimOnly','true','True'))

doc = '''Sets a mesh size constraint on the geometrical entities `dimTags'. Currently only entities of dimension 0 (points) are handled.'''
occ.add('setMeshSize',doc,None,ivectorpair('dimTags'),idouble('size'))

doc = '''Synchronize the internal OpenCASCADE CAD representation with the current Gmsh model. This can be called at any time, but since it involves a non trivial amount of processing, the number of synchronization points should normally be minimized.'''
occ.add('synchronize',doc,None)

################################################################################

view = gmsh.add_module('view','Post-processing view functions')

doc = '''Adds a new post-processing view, with name `name'. If `tag' is positive use it (and remove the view with that tag if it already exists), otherwise associate a new tag. Returns the view tag.'''
view.add('add',doc,oint,istring('name'),iint('tag','-1'))

doc = '''Removes the view with tag `tag'.'''
view.add('remove',doc,None,iint('tag'))

doc = '''Gets the index of the view with tag `tag' in the list of currently loaded views. This dynamic index (it can change when views are removed) is used to access view options.'''
view.add('getIndex',doc,oint,iint('tag'))

doc = '''Gets the tags of all views.'''
view.add('getTags',doc,None,ovectorint('tags'))

doc = '''Adds model-based post-processing data to the view with tag `tag'. `modelName' identifies the model the data is attached to. `dataType' specifies the type of data, currently either "NodeData", "ElementData" or "ElementNodeData". `step' specifies the identifier (>= 0) of the data in a sequence. `tags' gives the tags of the nodes or elements in the mesh to which the data is associated. `data' is a vector of the same length as `tags': each entry is the vector of double precision numbers representing the data associated with the corresponding tag. The optional `time' argument associate a time value with the data. `numComponents' gives the number of data components (1 for scalar data, 3 for vector data, etc.) per entity; if negative, it is automatically inferred (when possible) from the input data. `partition' allows to specify data in several sub-sets.'''
view.add('addModelData',doc,None,iint('tag'),iint('step'),istring('modelName'),istring('dataType'),ivectorint('tags'),ivectorvectordouble('data'),idouble('time','0.'),iint('numComponents','-1'),iint('partition','0'))

doc = '''Gets model-based post-processing data from the view with tag `tag' at step `step'. Returns the `data' associated to the nodes or the elements with tags `tags', as well as the `dataType' and the number of components `numComponents'.'''
view.add_rawc('getModelData',doc,None,iint('tag'),iint('step'),ostring('dataType'),ovectorint('tags'),ovectorvectordouble('data'),odouble('time'),oint('numComponents'))

doc = '''Adds list-based post-processing data to the view with tag `tag'. `type' identifies the data: "SP" for scalar points, "VP", for vector points, etc. `numEle' gives the number of elements in the data. `data' contains the data for the `numEle' elements.'''
view.add('addListData',doc,None,iint('tag'),istring('type'),iint('numEle'),ivectordouble('data'))

doc = '''Gets list-based post-processing data from the view with tag `tag'. Returns the types `dataTypes', the number of elements `numElements' for each data type and the `data' for each data type.'''
view.add('getListData',doc,None,iint('tag'),ovectorstring('dataType'),ovectorint('numElements'),ovectorvectordouble('data'))

doc = '''Probes the view `tag' for its `value' at point (`x', `y', `z'). Returns only the value at step `step' is `step' is positive. Returns only values with `numComp' if `numComp' is positive. Returns the gradient of the `value' if `gradient' is set. Probes with a geometrical tolerance (in the reference unit cube) of `tolerance' if `tolerance' is not zero. Returns the result from the element described by its coordinates if `xElementCoord', `yElementCoord' and `zElementCoord' are provided.'''
view.add('probe',doc,None,iint('tag'),idouble('x'),idouble('y'),idouble('z'),ovectordouble('value'),iint('step','-1'),iint('numComp','-1'),ibool('gradient','false','False'),idouble('tolerance','0.'),ivectordouble('xElemCoord','std::vector<double>()',"[]"),ivectordouble('yElemCoord','std::vector<double>()',"[]"),ivectordouble('zElemCoord','std::vector<double>()',"[]"))

doc = '''Writes the view to a file `fileName'. The export format is determined by the file extension. Appends to the file if `append' is set.'''
view.add('write',doc,None,iint('tag'),istring('fileName'),ibool('append','false','False'))

################################################################################

plugin = gmsh.add_module('plugin','Plugin functions')

doc = '''Sets the numerical option `option' to the value `value' for plugin `name'.'''
plugin.add('setNumber',doc,None,istring('name'),istring('option'),idouble('value'))

doc = '''Sets the string option `option' to the value `value' for plugin `name'.'''
plugin.add('setString',doc,None,istring('name'),istring('option'),istring('value'))

doc = '''Runs the plugin `name'.'''
plugin.add('run',doc,None,istring('name'))

################################################################################

graphics = gmsh.add_module('graphics','Graphics functions')

doc = '''Draws all the OpenGL scenes.'''
graphics.add('draw',doc,None)

################################################################################

fltk = gmsh.add_module('fltk','Fltk graphical user interface functions')

doc = '''Creates the Fltk graphical user interface.'''
fltk.add('initialize',doc,None)

doc = '''Waits at most `time' seconds for user interface events and returns. If `time' < 0, waits indefinitely. First automatically creates the user interface if it has not yet been initialized.'''
fltk.add('wait',doc,None,idouble('time', '-1.'))

doc = '''Runs the event loop of the Fltk graphical user interface, i.e. repeatedly calls `wait'. First automatically creates the user interface if it has not yet been initialized.'''
fltk.add('run',doc,None)

################################################################################

onelab = gmsh.add_module('onelab','ONELAB server functions')

doc = '''Gets `data' from the ONELAB server.'''
onelab.add('get',doc,None,ostring('data'),istring('format', '"json"'))

doc = '''Sets `data' in the ONELAB server.'''
onelab.add('set',doc,None,istring('data'),istring('format', '"json"'))

doc = '''Runs a ONELAB client. If `name' is provided, creates a new ONELAB client with name `name' and executes `command'. If not, attemps to run a client that might be linked to the processed input files.'''
onelab.add('run',doc,None,istring('name', '""'),istring('command', '""'))

################################################################################

api.write_cpp()
api.write_c()
api.write_python()
api.write_texi()
