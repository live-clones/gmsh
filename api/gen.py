# Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

# This is the master definition file for the Gmsh API.
#
# Running `python gen.py' will generate
#
#  - gmsh.h: the Gmsh C++ API header
#  - gmshc.h: the Gmsh C API header
#  - gmshc.cpp: the C to C++ wrapper code used by the Gmsh C API
#  - gmsh.h_cwrap: the Gmsh C++ API redefined in terms of the C API
#  - gmsh.py: the Gmsh Python API module
#  - gmsh.jl: the Gmsh Julia API module
#  - api.texi: the texinfo API documentation
#
# By design, the Gmsh API is purely functional, and only uses elementary types
# from the target language.
#
# See `demos/api' for examples on how to use the Gmsh API. In particular,
# `demos/api' contains C++, C, Python and Julia versions of several of the
# `.geo' tutorials from `tutorials'.

from GenApi import *

api = API('3.0')

################################################################################

gmsh = api.add_module('gmsh','Top-level functions')

doc = '''Initialize Gmsh. This must be called before any call to the other functions in the API. If `argc' and `argv' are provided, they will be handled in the same way as the command line arguments in the Gmsh app. If `readConfigFiles' is set, read system Gmsh configuration files (gmshrc and gmsh-options).'''
gmsh.add('initialize',doc,None,argcargv(),ibool('readConfigFiles','true','True'))

doc = '''Finalize Gmsh. This must be called when you are done using the Gmsh API.'''
gmsh.add('finalize',doc,None)

doc = '''Open a file. Equivalent to the `File->Open' menu in the Gmsh app. Handling of the file depends on its extension and/or its contents.'''
gmsh.add('open',doc,None,istring('fileName'))

doc = '''Merge a file. Equivalent to the `File->Merge' menu in the Gmsh app. Handling of the file depends on its extension and/or its contents.'''
gmsh.add('merge',doc,None,istring('fileName'))

doc = '''Write a file. The export format is determined by the file extension.'''
gmsh.add('write',doc,None,istring('fileName'))

doc = '''Clear all loaded models and post-processing data, and add a new empty model.'''
gmsh.add('clear',doc,None)

################################################################################

option = gmsh.add_module('option','Global option handling functions')

doc = '''Set a numerical option to `value'. `name' is of the form "category.option" or "category[num].option". Available categories and options are listed in the Gmsh reference manual.'''
option.add('setNumber',doc,None,istring('name'),idouble('value'))

doc = '''Get the `value' of a numerical option.'''
option.add('getNumber',doc,None,istring('name'),odouble('value'))

doc = '''Set a string option to `value'.'''
option.add('setString',doc,None,istring('name'),istring('value'))

doc = '''Get the `value' of a string option.'''
option.add('getString',doc,None,istring('name'),ostring('value'))

################################################################################

model = gmsh.add_module('model','Per-model functions')

doc = '''Add a new model, with name `name', and set it as the current model.'''
model.add('add',doc,None,istring('name'))

doc = '''Remove the current model.'''
model.add('remove',doc,None)

doc = '''List the names of all models.'''
model.add('list',doc,None,ovectorstring('names'))

doc = '''Set the current model to the model with name `name'. If several models have the same name, select the one that was added first.'''
model.add('setCurrent',doc,None,istring('name'))

doc = '''Get all the (elementary) geometrical entities in the current model. If `dim' is >= 0, return only the entities of the specified dimension (e.g. points if `dim' == 0). The entities are returned as a vector of (dim, tag) integer pairs.'''
model.add('getEntities',doc,None,ovectorpair('dimTags'),iint('dim','-1'))

doc = '''Get all the physical groups in the current model. If `dim' is >= 0, return only the entities of the specified dimension (e.g. physical points if `dim' == 0). The entities are returned as a vector of (dim, tag) integer pairs.'''
model.add('getPhysicalGroups',doc,None,ovectorpair('dimTags'),iint('dim','-1'))

doc = '''Get the tags of all the (elementary) geometrical entities making up the physical group of dimension `dim' and tag `tag'.'''
model.add('getEntitiesForPhysicalGroup',doc,None,iint('dim'),iint('tag'),ovectorint('tags'))

doc = '''Add a physical group of dimension `dim', grouping the elementary entities with tags `tags'. Return the tag of the physical group, equal to `tag' if `tag' is positive, or a new tag if `tag' < 0.'''
model.add('addPhysicalGroup',doc,oint,iint('dim'),ivectorint('tags'),iint('tag','-1'))

doc = '''Set the name of the physical group of dimension `dim' and tag `tag'.'''
model.add('setPhysicalName',doc,None,iint('dim'),iint('tag'),istring('name'))

doc = '''Get the name of the physical group of dimension `dim' and tag `tag'.'''
model.add('getPhysicalName',doc,None,iint('dim'),iint('tag'),ostring('name'))

doc = '''Get the boundary of the geometrical entities `dimTags'. Return in `outDimTags' the boundary of the individual entities (if `combined' is false) or the boundary of the combined geometrical shape formed by all input entities (if `combined' is true). Return tags multiplied by the sign of the boundary entity if `oriented' is true. Apply the boundary operator recursively down to dimension 0 (i.e. to points) if `recursive' is true.'''
model.add('getBoundary',doc,None,ivectorpair('dimTags'),ovectorpair('outDimTags'),ibool('combined','true','True'),ibool('oriented','true','True'),ibool('recursive','false','False'))

doc = '''Get the (elementary) geometrical entities in the bounding box defined by the two points (`xmin', `ymin', `zmin') and (`xmax', `ymax', `zmax'). If `dim' is >= 0, return only the entities of the specified dimension (e.g. points if `dim' == 0).'''
model.add('getEntitiesInBoundingBox',doc,None,idouble('xmin'),idouble('ymin'),idouble('zmin'),idouble('xmax'),idouble('ymax'),idouble('zmax'),ovectorpair('tags'),iint('dim','-1'))

doc = '''Get the bounding box (`xmin', `ymin', `zmin'), (`xmax', `ymax', `zmax') of the geometrical entity of dimension `dim' and tag `tag'.'''
model.add('getBoundingBox',doc,None,iint('dim'),iint('tag'),odouble('xmin'),odouble('ymin'),odouble('zmin'),odouble('xmax'),odouble('ymax'),odouble('zmax'))

doc = '''Get the geometrical dimension of the current model.'''
model.add('getDimension',doc,oint)

doc = '''Add a discrete geometrical entity (defined by a mesh) of dimension `dim' in the current model. Return the tag of the new discrete entity, equal to `tag' if `tag' is positive, or a new tag if `tag' < 0. `boundary' specifies the tags of the entities on the boundary of the discrete entity, if any. Specyfing `boundary' allows Gmsh to construct the topology of the overall model.'''
model.add('addDiscreteEntity',doc,oint,iint('dim'),iint('tag','-1'),ivectorint('boundary','std::vector<int>()',"[]","[]"))

doc = '''Remove the entities `dimTags' of the current model. If `recursive' is true, remove all the entities on their boundaries, down to dimension 0.'''
model.add('removeEntities',doc,None,ivectorpair('dimTags'),ibool('recursive','false','False'))

doc = '''Get the type of the entity of dimension `dim' and tag `tag'.'''
model.add('getType',doc,None,iint('dim'),iint('tag'),ostring('entityType'))

################################################################################

mesh = model.add_module('mesh','Per-model meshing functions')

doc = '''Generate a mesh of the current model, up to dimension `dim' (0, 1, 2 or 3).'''
mesh.add('generate',doc,None,iint('dim', '3'))

doc = '''Partition the mesh of the current model into `numPart' partitions.'''
mesh.add('partition',doc,None,iint('numPart'))

doc = '''Refine the mesh of the current model by uniformly splitting the elements.'''
mesh.add('refine',doc,None)

doc = '''Set the order of the elements in the mesh of the current model to `order'.'''
mesh.add('setOrder',doc,None,iint('order'))

doc = '''Get the last entities (if any) where a meshing error occurred. Currently only populated by the new 3D meshing algorithms.'''
mesh.add('getLastEntityError',doc,None,ovectorpair('dimTags'))

doc = '''Get the last nodes (if any) where a meshing error occurred. Currently only populated by the new 3D meshing algorithms.'''
mesh.add('getLastNodeError',doc,None,ovectorint('nodeTags'))

doc = '''Get the nodes classified on the entity of dimension `dim' and tag `tag'. If `tag' < 0, get the nodes for all entities of dimension `dim'. If `dim' and `tag' are negative, get all the nodes in the mesh. `nodeTags' contains the node tags (their unique, strictly positive identification numbers). `coord' is a vector of length 3 times the length of `nodeTags' that contains the (x, y, z) coordinates of the nodes, concatenated. If `dim' >= 0, `parametricCoord' contains the parametric coordinates of the nodes, if available. The length of `parametricCoord' can be 0 or `dim' times the length of `nodeTags'.'''
mesh.add('getNodes',doc,None,ovectorint('nodeTags'),ovectordouble('coord'),ovectordouble('parametricCoord'),iint('dim', '-1'),iint('tag', '-1'))

doc = '''Get the coordinates and the parametric coordinates (if any) of the node with tag `tag'. This is a sometimes useful but inefficient way of accessing node data, as it relies on a cache stored in the model. For large meshes all the nodes in the model should be numbered in a continuous sequence of tags from 1 to N to maintain reasonnable performance (in this case the internal cache is based on a vector; otherwise it uses a map).'''
mesh.add('getNode',doc,None,iint('nodeTag'),ovectordouble('coord'),ovectordouble('parametricCoord'))

doc = '''Rebuild the node cache.'''
mesh.add('rebuildNodeCache',doc,None,ibool('onlyIfNecessary', 'true', 'True'))

doc = '''Set the nodes classified on the geometrical entity of dimension `dim' and tag `tag'. `nodeTags' contains the node tags (their unique, strictly positive identification numbers). `coord' is a vector of length 3 times the length of `nodeTags' that contains the (x, y, z) coordinates of the nodes, concatenated. The optional `parametricCoord' vector contains the parametric coordinates of the nodes, if any. The length of `parametricCoord' can be 0 or `dim' times the length of `nodeTags'.'''
mesh.add('setNodes',doc,None,iint('dim'),iint('tag'),ivectorint('nodeTags'),ivectordouble('coord'),ivectordouble('parametricCoord','std::vector<double>()',"[]","[]"))

doc = '''Reclassify all nodes on their associated geometrical entity, based on the elements. Can be used when importing nodes in bulk (e.g. by associating them all to a single volume), to reclassify them correctly on model surfaces, curves, etc. after the elements have been set.'''
mesh.add('reclassifyNodes',doc,None)

doc = '''Get the elements classified on the entity of dimension `dim' and tag `tag'. If `tag' < 0, get the elements for all entities of dimension `dim'. If `dim' and `tag' are negative, get all the elements in the mesh. `elementTypes' contains the MSH types of the elements (e.g. `2' for 3-node triangles: see `getElementProperties' to obtain the properties for a given element type). `elementTags' is a vector of the same length as `elementTypes'; each entry is a vector containing the tags (unique, strictly positive identifiers) of the elements of the corresponding type. `nodeTags' is also a vector of the same length as `elementTypes'; each entry is a vector of length equal to the number of elements of the given type times the number of nodes for this type of element, that contains the node tags of all the elements of the given type, concatenated.'''
mesh.add('getElements',doc,None,ovectorint('elementTypes'),ovectorvectorint('elementTags'),ovectorvectorint('nodeTags'),iint('dim', '-1'),iint('tag', '-1'))

doc = '''Get the type and node tags of the element with tag `tag'. This is a useful but inefficient way of accessing element data, as it relies on a cache stored in the model. For large meshes all the elements in the model should be numbered in a continuous sequence of tags from 1 to N to maintain reasonnable performance (in this case the internal cache is based on a vector; otherwise it uses a map).'''
mesh.add('getElement',doc,None,iint('elementTag'),oint('elementType'),ovectorint('nodeTags'))

doc = '''Set the elements of the entity of dimension `dim' and tag `tag'. `types' contains the MSH types of the elements (e.g. `2' for 3-node triangles: see the Gmsh reference manual). `elementTags' is a vector of the same length as `types'; each entry is a vector containing the tags (unique, strictly positive identifiers) of the elements of the corresponding type. `nodeTags' is also a vector of the same length as `types'; each entry is a vector of length equal to the number of elements of the give type times the number of nodes per element, that contains the node tags of all the elements of the given type, concatenated.'''
mesh.add('setElements',doc,None,iint('dim'),iint('tag'),ivectorint('elementTypes'),ivectorvectorint('elementTags'),ivectorvectorint('nodeTags'))

doc = '''Get the types of elements in the entity of dimension `dim' and tag `tag'. If `tag' < 0, get the types for all entities of dimension `dim'. If `dim' and `tag' are negative, get all the types in the mesh.'''
mesh.add('getElementTypes',doc,None,ovectorint('elementTypes'),iint('dim', '-1'),iint('tag', '-1'))

doc = '''Get the properties of an element of type `elementType': its name (`elementName'), dimension (`dim'), order (`order'), number of nodes (`numNodes') and parametric node coordinates (`parametricCoord' vector, of length `dim' times `numNodes').'''
mesh.add('getElementProperties',doc,None,iint('elementType'),ostring('elementName'),oint('dim'),oint('order'),oint('numNodes'),ovectordouble('parametricCoord'))

doc = '''Get the elements of type `elementType' classified on the entity of of tag `tag'. If `tag' < 0, get the elements for all entities. `elementTags' is a vector containing the tags (unique, strictly positive identifiers) of the elements of the corresponding type. `nodeTags' is a vector of length equal to the number of elements of the given type times the number of nodes for this type of element, that contains the node tags of all the elements of the given type, concatenated. If `numTasks' > 1, only compute and return the part of the data indexed by `task'.'''
mesh.add('getElementsByType',doc,None,iint('elementType'),ovectorint('elementTags'),ovectorint('nodeTags'),iint('tag', '-1'),isize('task', '0'),isize('numTasks', '1'))

doc = '''Preallocate the data for `getElementsByType'. This is necessary only if `getElementsByType' is called with `numTasks' > 1.'''
mesh.add('preallocateElementsByType',doc,None,iint('elementType'),ibool('elementTag'),ibool('nodeTag'),ovectorint('elementTags'),ovectorint('nodeTags'),iint('tag', '-1'))

doc = '''Get the Jacobians of all the elements of type `elementType' classified on the entity of dimension `dim' and tag `tag', at the integration points required by the `integrationType' integration rule (e.g. \"Gauss4\"). Data is returned by element, in the same order as data returned by `getElementsByType'. `jacobians' contains for each element the 9 entries of a 3x3 Jacobian matrix (by row), for each integration point. `determinants' contains for each element the determinant of the Jacobian matrix for each integration point. `points' contains for each element the (x, y, z) coordinates of the integration points. If `tag' < 0, get the Jacobian data for all entities. If `numTasks' > 1, only compute and return the part of the data indexed by `task'.'''
mesh.add('getJacobians',doc,None,iint('elementType'),istring('integrationType'),ovectordouble('jacobians'),ovectordouble('determinants'),ovectordouble('points'),iint('tag', '-1'),isize('task', '0'),isize('numTasks', '1'))

doc = '''Preallocate the data required by `getJacobians'. This is necessary only if `getJacobians' is called with `numTasks' > 1.'''
mesh.add('preallocateJacobians',doc,None,iint('elementType'),istring('integrationType'),ibool('jacobian'),ibool('determinant'),ibool('point'),ovectordouble('jacobians'),ovectordouble('determinants'),ovectordouble('points'),iint('tag', '-1'))

doc = '''Get the basis functions of the element of type `elementType' for the given `integrationType' integration rule (e.g. \"Gauss4\") and `functionSpaceType' function space (e.g. \"IsoParametric\"). `integrationPoints' contains the parametric coordinates (u, v, w) and the weight for each integeration point, concatenated. `numComponents' returns the number of components of a basis function. `basisFunctions' contains the evaluation of the basis functions at the integration points.'''
mesh.add('getBasisFunctions',doc,None,iint('elementType'),istring('integrationType'),istring('functionSpaceType'),ovectordouble('integrationPoints'),oint('numComponents'),ovectordouble('basisFunctions'))

doc = '''Precomputes the basis functions corresponding to `elementType'.'''
mesh.add('precomputeBasisFunctions',doc,None,iint('elementType'))

doc = '''Get the barycenters of all elements of type `elementType' classified on the entity of tag `tag'. If `primary' is set, only the primary nodes of the elements are taken into account for the barycenter calculation. If `fast' is set, the function returns the sum of the primary node coordinates (without normalizing by the number of nodes). If `numTasks' > 1, only compute and return the part of the data indexed by `task'.'''
mesh.add('getBarycenters',doc,None,iint('elementType'),iint('tag'),ibool('fast'),ibool('primary'),ovectordouble('barycenters'),isize('task', '0'),isize('numTasks', '1'))

doc = '''Preallocate the data required by `getBarycenters'. This is necessary only if `getBarycenters' is called with `numTasks' > 1.'''
mesh.add('preallocateBarycenters',doc,None,iint('elementType'),ovectordouble('barycenters'),iint('tag', '-1'))

doc = '''Set a mesh size constraint on the geometrical entities `dimTags'. Currently only entities of dimension 0 (points) are handled.'''
mesh.add('setSize',doc,None,ivectorpair('dimTags'),idouble('size'))

doc = '''Set a transfinite meshing constraint on the curve `tag', with `numNodes' nodes distributed according to `meshType' and `coef'. Currently supported types are "Progression" (geometrical progression with power `coef') and "Bump" (refinement toward both extremities of the curve).'''
mesh.add('setTransfiniteCurve',doc,None,iint('tag'),iint('numNodes'),istring('meshType','"Progression"'),idouble('coef','1.'))

doc = '''Set a transfinite meshing constraint on the surface `tag'. `arrangement' describes the arrangement of the triangles when the surface is not flagged as recombined: currently supported values are "Left", "Right", "AlternateLeft" and "AlternateRight". `cornerTags' can be used to specify the (3 or 4) corners of the transfinite interpolation explicitly; specifying the corners explicitly is mandatory if the surface has more that 3 or 4 points on its boundary.'''
mesh.add('setTransfiniteSurface',doc,None,iint('tag'),istring('arrangement','"Left"'),ivectorint('cornerTags','std::vector<int>()',"[]","[]"))

doc = '''Set a transfinite meshing constraint on the surface `tag'. `cornerTags' can be used to specify the (6 or 8) corners of the transfinite interpolation explicitly.'''
mesh.add('setTransfiniteVolume',doc,None,iint('tag'),ivectorint('cornerTags','std::vector<int>()',"[]","[]"))

doc = '''Set a recombination meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. Currently only entities of dimension 2 (to recombine triangles into quadrangles) are supported.'''
mesh.add('setRecombine',doc,None,iint('dim'),iint('tag'))

doc = '''Set a smoothing meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. `val' iterations of a Laplace smoother are applied.'''
mesh.add('setSmoothing',doc,None,iint('dim'),iint('tag'),iint('val'))

doc = '''Set a reverse meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. If `val' is true, the mesh orientation will be reversed with respect to the natural mesh orientation (i.e. the orientation consistent with the orientation of the geometrical entity). If `val' is false, the mesh is left as-is.'''
mesh.add('setReverse',doc,None,iint('dim'),iint('tag'),ibool('val','true','True'))

doc = '''Set meshing constraints on the bounding surfaces of the volume of tag `tag' so that all surfaces are oriented with outward pointing normals. Currently only available with the OpenCASCADE kernel, as it relies on the STL triangulation.'''
mesh.add('setOutwardOrientation',doc,None,iint('tag'))

doc = '''Embed the geometrical entities of dimension `dim' and tags `tags' in the (inDim, inTag) geometrical entity. `inDim' must be strictly greater than `dim'.'''
mesh.add('embed',doc,None,iint('dim'),ivectorint('tags'),iint('inDim'),iint('inTag'))

doc = '''Reorder the elements of type `elementType' classified on the entity of tag `tag' according to `order'.'''
mesh.add('reorderElements',doc,None,iint('elementType'),iint('tag'),ivectorint('order'))

doc = '''Set the meshes of the entities of dimension `dim' and tag `tags' as periodic copies of the meshes of entities `tagsSource', using the affine transformation specified in `affineTransformation' (16 entries of a 4x4 matrix, by row). Currently only available for `dim' == 1 and `dim' == 2.'''
mesh.add('setPeriodic',doc,None,iint('dim'),ivectorint('tags'),ivectorint('tagsSource'),ivectordouble('affineTransformation'))

doc = '''Get the master entity, periodic node pairs and affine transform for the entity of dimension `dim' and tag `tag'.'''
mesh.add('getPeriodicNodes',doc,None,iint('dim'),iint('tag'),oint('tagMaster'),ovectorpair('nodes'),ovectordouble('affineTransform'))

doc = '''Remove duplicate nodes in the mesh of the current model.'''
mesh.add('removeDuplicateNodes',doc,None)

doc = '''Compute a basis representation for homology spaces after a mesh has been generated. The computation domain is given in a list of physical group tags `domainTags'; if empty, the whole mesh is the domain. The computation subdomain for relative homology computation is given in a list of physical group tags `subdomainTags'; if empty, absolute homology is computed. The dimensions homology bases to be computed are given in the list `dim'; if empty, all bases are computed. Resulting basis representation chains are stored as physical groups in the mesh.'''
mesh.add('homology',doc,None,ivectorint('domainTags','std::vector<int>()',"[]","[]"),ivectorint('subdomainTags','std::vector<int>()',"[]","[]"),ivectorint('dims','std::vector<int>()',"[]","[]"))

doc = '''Compute a basis representation for cohomology spaces after a mesh has been generated. The computation domain is given in a list of physical group tags `domainTags'; if empty, the whole mesh is the domain. The computation subdomain for relative cohomology computation is given in a list of physical group tags `subdomainTags'; if empty, absolute cohomology is computed. The dimensions homology bases to be computed are given in the list `dim'; if empty, all bases are computed. Resulting basis representation cochains are stored as physical groups in the mesh.'''
mesh.add('cohomology',doc,None,ivectorint('domainTags','std::vector<int>()',"[]","[]"),ivectorint('subdomainTags','std::vector<int>()',"[]","[]"),ivectorint('dims','std::vector<int>()',"[]","[]"))

################################################################################

field = mesh.add_module('field','Per-model mesh size field functions')

doc = '''Add a new mesh size field of type `fieldType'. If `tag' is positive, assign the tag explcitly; otherwise a new tag is assigned automatically. Return the field tag.'''
field.add('add',doc,oint,istring('fieldType'),iint('tag','-1'))

doc = '''Remove the field with tag `tag'.'''
field.add('remove',doc,None,iint('tag'))

doc = '''Set the numerical option `option' to value `value' for field `tag'.'''
field.add('setNumber',doc,None,iint('tag'),istring('option'),idouble('value'))

doc = '''Set the string option `option' to value `value' for field `tag'.'''
field.add('setString',doc,None,iint('tag'),istring('option'),istring('value'))

doc = '''Set the numerical list option `option' to value `value' for field `tag'.'''
field.add('setNumbers',doc,None,iint('tag'),istring('option'),ivectordouble('value'))

doc = '''Set the field `tag' as the background mesh size field.'''
field.add('setAsBackgroundMesh',doc,None,iint('tag'))

doc = '''Set the field `tag' as a boundary layer size field.'''
field.add('setAsBoundaryLayer',doc,None,iint('tag'))

################################################################################

geo = model.add_module('geo','Internal per-model GEO CAD kernel functions')

doc = '''Add a geometrical point in the internal GEO CAD representation, at coordinates (x, y, z). If `meshSize' is > 0, add a meshing constraint at that point. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the point. (Note that the point will be added in the current model only after `synchronize' is called. This behavior holds for all the entities added in the geo module.)'''
geo.add('addPoint',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('meshSize','0.'),iint('tag','-1'))

doc = '''Add a straight line segment between the two points with tags `startTag' and `endTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the line.'''
geo.add('addLine',doc,oint,iint('startTag'),iint('endTag'),iint('tag','-1'))

doc = '''Add a circle arc (stricly smaller than Pi) between the two points with tags `startTag' and `endTag', with center `centertag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If (`nx', `ny', `nz') != (0,0,0), explicitely set the plane of the circle arc. Return the tag of the circle arc.'''
geo.add('addCircleArc',doc,oint,iint('startTag'),iint('centerTag'),iint('endTag'),iint('tag','-1'),idouble('nx','0.'),idouble('ny','0.'),idouble('nz','0.'))

doc = '''Add an ellipse arc (stricly smaller than Pi) between the two points `startTag' and `endTag', with center `centertag' and major axis point `majorTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If (`nx', `ny', `nz') != (0,0,0), explicitely set the plane of the circle arc. Return the tag of the ellipse arc.'''
geo.add('addEllipseArc',doc,oint,iint('startTag'),iint('centerTag'),iint('majorTag'),iint('endTag'),iint('tag','-1'),idouble('nx','0.'),idouble('ny','0.'),idouble('nz','0.'))

doc = '''Add a spline (Catmull-Rom) curve going through the points `pointTags'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Create a periodic curve if the first and last points are the same. Return the tag of the spline curve.'''
geo.add('addSpline',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Add a cubic b-spline curve with `pointTags' control points. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Creates a periodic curve if the first and last points are the same. Return the tag of the b-spline curve.'''
geo.add('addBSpline',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Add a Bezier curve with `pointTags' control points. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically.  Return the tag of the Bezier curve.'''
geo.add('addBezier',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Add a curve loop (a closed wire) formed by the curves `curveTags'. `curveTags' should contain (signed) tags of geometrical enties of dimension 1 forming a closed loop: a negative tag signifies that the underlying curve is considered with reversed orientation. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the curve loop.'''
geo.add('addCurveLoop',doc,oint,ivectorint('curveTags'),iint('tag','-1'))

doc = '''Add a plane surface defined by one or more curve loops `wireTags'. The first curve loop defines the exterior contour; additional curve loop define holes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface.'''
geo.add('addPlaneSurface',doc,oint,ivectorint('wireTags'),iint('tag','-1'))

doc = '''Add a surface filling the curve loops in `wireTags'. Currently only a single curve loop is supported; this curve loop should be composed by 3 or 4 curves only. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface.'''
geo.add('addSurfaceFilling',doc,oint,ivectorint('wireTags'),iint('tag','-1'),iint('sphereCenterTag','-1'))

doc = '''Add a surface loop (a closed shell) formed by `surfaceTags'.  If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the shell.'''
geo.add('addSurfaceLoop',doc,oint,ivectorint('surfaceTags'),iint('tag','-1'))

doc = '''Add a volume (a region) defined by one or more shells `shellTags'. The first surface loop defines the exterior boundary; additional surface loop define holes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the volume.'''
geo.add('addVolume',doc,oint,ivectorint('shellTags'),iint('tag','-1'))

doc = '''Extrude the geometrical entities `dimTags' by translation along (`dx', `dy', `dz'). Return extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
geo.add('extrude',doc,None,ivectorpair('dimTags'),idouble('dx'),idouble('dy'),idouble('dz'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]","[]"),ivectordouble('heights','std::vector<double>()',"[]","[]"),ibool('recombine','false','False'))

doc = '''Extrude the geometrical entities `dimTags' by rotation of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az'). Return extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
geo.add('revolve',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]","[]"),ivectordouble('heights','std::vector<double>()',"[]","[]"),ibool('recombine','false','False'))

doc = '''Extrude the geometrical entities `dimTags' by a combined translation and rotation of `angle' radians, along (`dx', `dy', `dz') and around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az'). Return extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
geo.add('twist',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]","[]"),ivectordouble('heights','std::vector<double>()',"[]","[]"),ibool('recombine','false','False'))

doc = '''Translate the geometrical entities `dimTags' along (`dx', `dy', `dz').'''
geo.add('translate',doc,None,ivectorpair('dimTags'),idouble('dx'),idouble('dy'),idouble('dz'))

doc = '''Rotate the geometrical entities `dimTags' of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az').'''
geo.add('rotate',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'))

doc = '''Scale the geometrical entities `dimTag' by factors `a', `b' and `c' along the three coordinate axes; use (`x', `y', `z') as the center of the homothetic transformation.'''
geo.add('dilate',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('a'),idouble('b'),idouble('c'))

doc = '''Apply a symmetry transformation to the geometrical entities `dimTag', with respect to the plane of equation `a' * x + `b' * y + `c' * z + `d' = 0.'''
geo.add('symmetry',doc,None,ivectorpair('dimTags'),idouble('a'),idouble('b'),idouble('c'),idouble('d'))

doc = '''Copy the entities `dimTags'; the new entities are returned in `outDimTags'.'''
geo.add('copy',doc,None,ivectorpair('dimTags'),ovectorpair('outDimTags'))

doc = '''Remove the entities `dimTags'. If `recursive' is true, remove all the entities on their boundaries, down to dimension 0.'''
geo.add('remove',doc,None,ivectorpair('dimTags'),ibool('recursive','false','False'))

doc = '''Remove all duplicate entities (different entities at the same geometrical location).'''
geo.add('removeAllDuplicates',doc,None)

doc = '''Synchronize the internal GEO CAD representation with the current Gmsh model. This can be called at any time, but since it involves a non trivial amount of processing, the number of synchronization points should normally be minimized.'''
geo.add('synchronize',doc,None)

################################################################################

mesh = geo.add_module('mesh','GEO-specific meshing constraints')

doc = '''Set a mesh size constraint on the geometrical entities `dimTags'. Currently only entities of dimension 0 (points) are handled.'''
mesh.add('setSize',doc,None,ivectorpair('dimTags'),idouble('size'))

doc = '''Set a transfinite meshing constraint on the curve `tag', with `numNodes' nodes distributed according to `meshType' and `coef'. Currently supported types are "Progression" (geometrical progression with power `coef') and "Bump" (refinement toward both extreminties of the curve).'''
mesh.add('setTransfiniteCurve',doc,None,iint('tag'),iint('nPoints'),istring('meshType','"Progression"'),idouble('coef','1.'))

doc = '''Set a transfinite meshing constraint on the surface `tag'. `arrangement' describes the arrangement of the triangles when the surface is not flagged as recombined: currently supported values are "Left", "Right", "AlternateLeft" and "AlternateRight". `cornerTags' can be used to specify the (3 or 4) corners of the transfinite interpolation explicitly; specifying the corners explicitly is mandatory if the surface has more that 3 or 4 points on its boundary.'''
mesh.add('setTransfiniteSurface',doc,None,iint('tag'),istring('arrangement','"Left"'),ivectorint('cornerTags','std::vector<int>()',"[]","[]"))

doc = '''Set a transfinite meshing constraint on the surface `tag'. `cornerTags' can be used to specify the (6 or 8) corners of the transfinite interpolation explicitly.'''
mesh.add('setTransfiniteVolume',doc,None,iint('tag'),ivectorint('cornerTags','std::vector<int>()',"[]","[]"))

doc = '''Set a recombination meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. Currently only entities of dimension 2 (to recombine triangles into quadrangles) are supported.'''
mesh.add('setRecombine',doc,None,iint('dim'),iint('tag'),idouble('angle','45.'))

doc = '''Set a smoothing meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. `val' iterations of a Laplace smoother are applied.'''
mesh.add('setSmoothing',doc,None,iint('dim'),iint('tag'),iint('val'))

doc = '''Set a reverse meshing constraint on the geometrical entity of dimension `dim' and tag `tag'. If `val' is true, the mesh orientation will be reversed with respect to the natural mesh orientation (i.e. the orientation consistent with the orientation of the geometrical entity). If `val' is false, the mesh is left as-is.'''
mesh.add('setReverse',doc,None,iint('dim'),iint('tag'),ibool('val','true','True'))

################################################################################

occ = model.add_module('occ','Internal per-model OpenCASCADE CAD kernel functions')

doc = '''Add a geometrical point in the internal OpenCASCADE CAD representation, at coordinates (x, y, z). If `meshSize' is > 0, add a meshing constraint at that point. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the point. (Note that the point will be added in the current model only after `synchronize' is called. This behavior holds for all the entities added in the occ module.)'''
occ.add('addPoint',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('meshSize','0.'),iint('tag','-1'))

doc = '''Add a straight line segment between the two points with tags `startTag' and `endTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the line.'''
occ.add('addLine',doc,oint,iint('startTag'),iint('endTag'),iint('tag','-1'))

doc = '''Add a circle arc between the two points with tags `startTag' and `endTag', with center `centerTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the circle arc.'''
occ.add('addCircleArc',doc,oint,iint('startTag'),iint('centerTag'),iint('endTag'),iint('tag','-1'))

doc = '''Add a circle of center (`x', `y', `z') and radius `r'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If `angle1' and `angle2' are specified, create a circle arc between the two angles. Return the tag of the circle.'''
occ.add('addCircle',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('r'),iint('tag','-1'),idouble('angle1','0.'),idouble('angle2','2*M_PI','2*pi','2*pi'))

doc = '''Add an ellipse arc between the two points with tags `startTag' and `endTag', with center `centerTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the ellipse arc.'''
occ.add('addEllipseArc',doc,oint,iint('startTag'),iint('centerTag'),iint('endTag'),iint('tag','-1'))

doc = '''Add an ellipse of center (`x', `y', `z') and radii `r1' and `r2' along the x- and y-axes respectively. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If `angle1' and `angle2' are specified, create an ellipse arc between the two angles. Return the tag of the ellipse.'''
occ.add('addEllipse',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('r1'),idouble('r2'),iint('tag','-1'),idouble('angle1','0.'),idouble('angle2','2*M_PI','2*pi','2*pi'))

doc = '''Add a spline (C2 b-spline) curve going through the points `pointTags'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Create a periodic curve if the first and last points are the same. Return the tag of the spline curve.'''
occ.add('addSpline',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Add a b-spline curve of degree `degree' with `pointTags' control points. If `weights', `knots' or `multiplicities' are not provided, default parameters are computed automatically. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Create a periodic curve if the first and last points are the same. Return the tag of the b-spline curve.'''
occ.add('addBSpline',doc,oint,ivectorint('pointTags'),iint('tag','-1'),iint('degree','3'),ivectordouble('weights','std::vector<double>()',"[]","[]"),ivectordouble('knots','std::vector<double>()',"[]","[]"),ivectorint('multiplicities','std::vector<int>()',"[]","[]"))

doc = '''Add a Bezier curve with `pointTags' control points. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the Bezier curve.'''
occ.add('addBezier',doc,oint,ivectorint('pointTags'),iint('tag','-1'))

doc = '''Add a wire (open or closed) formed by the curves `curveTags'. `curveTags' should contain (signed) tags: a negative tag signifies that the underlying curve is considered with reversed orientation. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the wire.'''
occ.add('addWire',doc,oint,ivectorint('curveTags'),iint('tag','-1'),ibool('checkClosed','false','False'))

doc = '''Add a curve loop (a closed wire) formed by the curves `curveTags'. `curveTags' should contain (signed) tags of curves forming a closed loop: a negative tag signifies that the underlying curve is considered with reversed orientation. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the curve loop.'''
occ.add('addCurveLoop',doc,oint,ivectorint('curveTags'),iint('tag','-1'))

doc = '''Add a rectangle with lower left corner at (`x', `y', `z') and upper right corner at (`x' + `dx', `y' + `dy', `z'). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Round the corners if `roundedRadius' is nonzero. Return the tag of the rectangle.'''
occ.add('addRectangle',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),iint('tag','-1'),idouble('roundedRadius','0.'))

doc = '''Add a disk with center (`xc', `yc', `zc') and radius `rx' along the x-axis and `ry' along the y-axis. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the disk.'''
occ.add('addDisk',doc,oint,idouble('xc'),idouble('yc'),idouble('zc'),idouble('rx'),idouble('ry'),iint('tag','-1'))

doc = '''Add a plane surface defined by one or more curve loops (or closed wires) `wireTags'. The first curve loop defines the exterior contour; additional curve loop define holes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface.'''
occ.add('addPlaneSurface',doc,oint,ivectorint('wireTags'),iint('tag','-1'))

doc = '''Add a surface filling the curve loops in `wireTags'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface.'''
occ.add('addSurfaceFilling',doc,oint,iint('wireTag'),iint('tag','-1'))

doc = '''Add a surface loop (a closed shell) formed by `surfaceTags'.  If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface loop.'''
occ.add('addSurfaceLoop',doc,oint,ivectorint('surfaceTags'),iint('tag','-1'))

doc = '''Add a volume (a region) defined by one or more surface loops `shellTags'. The first surface loop defines the exterior boundary; additional surface loop define holes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the volume.'''
occ.add('addVolume',doc,oint,ivectorint('shellTags'),iint('tag','-1'))

doc = '''Add a sphere of center (`xc', `yc', `zc') and radius `r'. The optional `angle1' and `angle2' arguments define the polar angle opening (from -Pi/2 to Pi/2). The optional `angle3' argument defines the azimuthal opening (from 0 to 2*Pi). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the sphere.'''
occ.add('addSphere',doc,oint,idouble('xc'),idouble('yc'),idouble('zc'),idouble('radius'),iint('tag','-1'),idouble('angle1','-M_PI/2','-pi/2','-pi/2'),idouble('angle2','M_PI/2','pi/2','pi/2'),idouble('angle3','2*M_PI','2*pi','2*pi'))

doc = '''Add a parallelepipedic box defined by a point (`x', `y', `z') and the extents along the x-, y- and z-axes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the box.'''
occ.add('addBox',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),iint('tag','-1'))

doc = '''Add a cylinder, defined by the center (`x', `y', `z') of its first circular face, the 3 components (`dx', `dy', `dz') of the vector defining its axis and its radius `r'. The optional `angle' argument defines the angular opening (from 0 to 2*Pi). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the cylinder.'''
occ.add('addCylinder',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),idouble('r'),iint('tag','-1'),idouble('angle','2*M_PI','2*pi','2*pi'))

doc = '''Add a cone, defined by the center (`x', `y', `z') of its first circular face, the 3 components of the vector (`dx', `dy', `dz') defining its axis and the two radii `r1' and `r2' of the faces (these radii can be zero). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. `angle' defines the optional angular opening (from 0 to 2*Pi). Return the tag of the cone.'''
occ.add('addCone',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),idouble('r1'),idouble('r2'),iint('tag','-1'),idouble('angle','2*M_PI','2*pi','2*pi'))

doc = '''Add a right angular wedge, defined by the right-angle point (`x', `y', `z') and the 3 extends along the x-, y- and z-axes (`dx', `dy', `dz'). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. The optional argument `ltx' defines the top extent along the x-axis. Return the tag of the wedge.'''
occ.add('addWedge',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('dx'),idouble('dy'),idouble('dz'),iint('tag','-1'),idouble('ltx','0.'))

doc = '''Add a torus, defined by its center (`x', `y', `z') and its 2 radii `r' and `r2'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. The optional argument `angle' defines the angular opening (from 0 to 2*Pi). Return the tag of the wedge.'''
occ.add('addTorus',doc,oint,idouble('x'),idouble('y'),idouble('z'),idouble('r1'),idouble('r2'),iint('tag','-1'),idouble('angle','2*M_PI','2*pi','2*pi'))

doc = '''Add a volume (if the optional argument `makeSolid' is set) or surfaces defined through the open or closed wires `wireTags'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. The new entities are returned in `outDimTags'. If the optional argument `makeRuled' is set, the surfaces created on the boundary are forced to be ruled surfaces.'''
occ.add('addThruSections',doc,None,ivectorint('wireTags'),ovectorpair('outDimTags'),iint('tag','-1'),ibool('makeSolid','true','True'),ibool('makeRuled','false','False'))

doc = '''Add a hollowed volume built from an initial volume `volumeTag' and a set of faces from this volume `excludeSurfaceTags', which are to be removed. The remaining faces of the volume become the walls of the hollowed solid, with thickness `offset'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically.'''
occ.add('addThickSolid',doc,None,iint('volumeTag'),ivectorint('excludeSurfaceTags'),idouble('offset'),ovectorpair('outDimTags'),iint('tag','-1'))

doc = '''Extrude the geometrical entities `dimTags' by translation along (`dx', `dy', `dz'). Return extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
occ.add('extrude',doc,None,ivectorpair('dimTags'),idouble('dx'),idouble('dy'),idouble('dz'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]","[]"),ivectordouble('heights','std::vector<double>()',"[]","[]"),ibool('recombine','false','False'))

doc = '''Extrude the geometrical entities `dimTags' by rotation of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az'). Return extruded entities in `outDimTags'. If `numElements' is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If `height' is not empty, it provides the (cummulative) height of the different layers, normalized to 1.'''
occ.add('revolve',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'),ovectorpair('outDimTags'),ivectorint('numElements','std::vector<int>()',"[]","[]"),ivectordouble('heights','std::vector<double>()',"[]","[]"),ibool('recombine','false','False'))

doc = '''Add a pipe by extruding the entities `dimTags' along the wire `wireTag'. Return the pipe in `outDimTags'.'''
occ.add('addPipe',doc,None,ivectorpair('dimTags'),iint('wireTag'),ovectorpair('outDimTags'))

doc = '''Fillet the volumes `volumeTags' on the curves `curveTags' with radius `radius'. Return the filleted entities in `outDimTags'. Remove the original volume if `removeVolume' is set.'''
occ.add('fillet',doc,None,ivectorint('volumeTags'),ivectorint('curveTags'),idouble('radius'),ovectorpair('outDimTags'),ibool('removeVolume','true','True'))

doc = '''Compute the boolean union (the fusion) of the entities `objectDimTags' and `toolDimTags'. Return the resulting entities in `outDimTags'. If `tag' is positive, try to set the tag explicitly (ony valid if the boolean operation results in a single entity). Remove the object if `removeObject' is set. Remove the tool if `removeTool' is set.'''
occ.add('fuse',doc,None,ivectorpair('objectDimTags'),ivectorpair('toolDimTags'),ovectorpair('outDimTags'),ovectorvectorpair('outDimTagsMap'),iint('tag','-1'),ibool('removeObject','true','True'),ibool('removeTool','true','True'))

doc = '''Compute the boolean intersection (the common parts) of the entities `objectDimTags' and `toolDimTags'. Return the resulting entities in `outDimTags'. If `tag' is positive, try to set the tag explicitly (ony valid if the boolean operation results in a single entity). Remove the object if `removeObject' is set. Remove the tool if `removeTool' is set.'''
occ.add('intersect',doc,None,ivectorpair('objectDimTags'),ivectorpair('toolDimTags'),ovectorpair('outDimTags'),ovectorvectorpair('outDimTagsMap'),iint('tag','-1'),ibool('removeObject','true','True'),ibool('removeTool','true','True'))

doc = '''Compute the boolean difference between the entities `objectDimTags' and `toolDimTags'. Return the resulting entities in `outDimTags'. If `tag' is positive, try to set the tag explicitly (ony valid if the boolean operation results in a single entity). Remove the object if `removeObject' is set. Remove the tool if `removeTool' is set.'''
occ.add('cut',doc,None,ivectorpair('objectDimTags'),ivectorpair('toolDimTags'),ovectorpair('outDimTags'),ovectorvectorpair('outDimTagsMap'),iint('tag','-1'),ibool('removeObject','true','True'),ibool('removeTool','true','True'))

doc = '''Compute the boolean fragments (general fuse) of the entities `objectDimTags' and `toolDimTags'. Return the resulting entities in `outDimTags'. If `tag' is positive, try to set the tag explicitly (ony valid if the boolean operation results in a single entity). Remove the object if `removeObject' is set. Remove the tool if `removeTool' is set.'''
occ.add('fragment',doc,None,ivectorpair('objectDimTags'),ivectorpair('toolDimTags'),ovectorpair('outDimTags'),ovectorvectorpair('outDimTagsMap'),iint('tag','-1'),ibool('removeObject','true','True'),ibool('removeTool','true','True'))

doc = '''Translate the geometrical entities `dimTags' along (`dx', `dy', `dz').'''
occ.add('translate',doc,None,ivectorpair('dimTags'),idouble('dx'),idouble('dy'),idouble('dz'))

doc = '''Rotate the geometrical entities `dimTags' of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az').'''
occ.add('rotate',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('ax'),idouble('ay'),idouble('az'),idouble('angle'))

doc = '''Scale the geometrical entities `dimTag' by factors `a', `b' and `c' along the three coordinate axes; use (`x', `y', `z') as the center of the homothetic transformation.'''
occ.add('dilate',doc,None,ivectorpair('dimTags'),idouble('x'),idouble('y'),idouble('z'),idouble('a'),idouble('b'),idouble('c'))

doc = '''Apply a symmetry transformation to the geometrical entities `dimTag', with respect to the plane of equation `a' * x + `b' * y + `c' * z + `d' = 0.'''
occ.add('symmetry',doc,None,ivectorpair('dimTags'),idouble('a'),idouble('b'),idouble('c'),idouble('d'))

doc = '''Copy the entities `dimTags'; the new entities are returned in `outDimTags'.'''
occ.add('copy',doc,None,ivectorpair('dimTags'),ovectorpair('outDimTags'))

doc = '''Remove the entities `dimTags'. If `recursive' is true, remove all the entities on their boundaries, down to dimension 0.'''
occ.add('remove',doc,None,ivectorpair('dimTags'),ibool('recursive','false','False'))

doc = '''Remove all duplicate entities (different entities at the same geometrical location) after intersecting (using boolean fragments) all highest dimensional entities.'''
occ.add('removeAllDuplicates',doc,None)

doc = '''Import BREP, STEP or IGES shapes from the file `fileName'. The imported entities are returned in `outDimTags'. If the optional argument `highestDimOnly' is set, only import the highest dimensional entities in the file. The optional argument `format' can be used to force the format of the file (currently "brep", "step" or "iges").'''
occ.add('importShapes',doc,None,istring('fileName'),ovectorpair('outDimTags'),ibool('highestDimOnly','true','True'),istring('format','""'))

#doc = '''Imports native OpenCASCADE shapes by providing a raw pointer to a TopoDS_Shape. The imported entities are returned in `outDimTags'. If the optional argument `highestDimOnly' is set, only import the highest dimensional entities in the file.'''
#occ.add('importShapesNativePointer',doc,None,voidstar('shape'),ovectorpair('outDimTags'),ibool('highestDimOnly','true','True'))

doc = '''Set a mesh size constraint on the geometrical entities `dimTags'. Currently only entities of dimension 0 (points) are handled.'''
occ.add('setMeshSize',doc,None,ivectorpair('dimTags'),idouble('size'))

doc = '''Synchronize the internal OpenCASCADE CAD representation with the current Gmsh model. This can be called at any time, but since it involves a non trivial amount of processing, the number of synchronization points should normally be minimized.'''
occ.add('synchronize',doc,None)

################################################################################

view = gmsh.add_module('view','Post-processing view functions')

doc = '''Add a new post-processing view, with name `name'. If `tag' is positive use it (and remove the view with that tag if it already exists), otherwise associate a new tag. Return the view tag.'''
view.add('add',doc,oint,istring('name'),iint('tag','-1'))

doc = '''Remove the view with tag `tag'.'''
view.add('remove',doc,None,iint('tag'))

doc = '''Get the index of the view with tag `tag' in the list of currently loaded views. This dynamic index (it can change when views are removed) is used to access view options.'''
view.add('getIndex',doc,oint,iint('tag'))

doc = '''Get the tags of all views.'''
view.add('getTags',doc,None,ovectorint('tags'))

doc = '''Add model-based post-processing data to the view with tag `tag'. `modelName' identifies the model the data is attached to. `dataType' specifies the type of data, currently either "NodeData", "ElementData" or "ElementNodeData". `step' specifies the identifier (>= 0) of the data in a sequence. `tags' gives the tags of the nodes or elements in the mesh to which the data is associated. `data' is a vector of the same length as `tags': each entry is the vector of double precision numbers representing the data associated with the corresponding tag. The optional `time' argument associate a time value with the data. `numComponents' gives the number of data components (1 for scalar data, 3 for vector data, etc.) per entity; if negative, it is automatically inferred (when possible) from the input data. `partition' allows to specify data in several sub-sets.'''
view.add('addModelData',doc,None,iint('tag'),iint('step'),istring('modelName'),istring('dataType'),ivectorint('tags'),ivectorvectordouble('data'),idouble('time','0.'),iint('numComponents','-1'),iint('partition','0'))

doc = '''Get model-based post-processing data from the view with tag `tag' at step `step'. Return the `data' associated to the nodes or the elements with tags `tags', as well as the `dataType' and the number of components `numComponents'.'''
view.add_rawc('getModelData',doc,None,iint('tag'),iint('step'),ostring('dataType'),ovectorint('tags'),ovectorvectordouble('data'),odouble('time'),oint('numComponents'))

doc = '''Add list-based post-processing data to the view with tag `tag'. `dataType' identifies the data: "SP" for scalar points, "VP", for vector points, etc. `numEle' gives the number of elements in the data. `data' contains the data for the `numEle' elements.'''
view.add('addListData',doc,None,iint('tag'),istring('dataType'),iint('numEle'),ivectordouble('data'))

doc = '''Get list-based post-processing data from the view with tag `tag'. Return the types `dataTypes', the number of elements `numElements' for each data type and the `data' for each data type.'''
view.add('getListData',doc,None,iint('tag'),ovectorstring('dataType'),ovectorint('numElements'),ovectorvectordouble('data'))

doc = '''Probe the view `tag' for its `value' at point (`x', `y', `z'). Return only the value at step `step' is `step' is positive. Return only values with `numComp' if `numComp' is positive. Return the gradient of the `value' if `gradient' is set. Probes with a geometrical tolerance (in the reference unit cube) of `tolerance' if `tolerance' is not zero. Return the result from the element described by its coordinates if `xElementCoord', `yElementCoord' and `zElementCoord' are provided.'''
view.add('probe',doc,None,iint('tag'),idouble('x'),idouble('y'),idouble('z'),ovectordouble('value'),iint('step','-1'),iint('numComp','-1'),ibool('gradient','false','False'),idouble('tolerance','0.'),ivectordouble('xElemCoord','std::vector<double>()',"[]","[]"),ivectordouble('yElemCoord','std::vector<double>()',"[]","[]"),ivectordouble('zElemCoord','std::vector<double>()',"[]","[]"))

doc = '''Write the view to a file `fileName'. The export format is determined by the file extension. Append to the file if `append' is set.'''
view.add('write',doc,None,iint('tag'),istring('fileName'),ibool('append','false','False'))

################################################################################

plugin = gmsh.add_module('plugin','Plugin functions')

doc = '''Set the numerical option `option' to the value `value' for plugin `name'.'''
plugin.add('setNumber',doc,None,istring('name'),istring('option'),idouble('value'))

doc = '''Set the string option `option' to the value `value' for plugin `name'.'''
plugin.add('setString',doc,None,istring('name'),istring('option'),istring('value'))

doc = '''Run the plugin `name'.'''
plugin.add('run',doc,None,istring('name'))

################################################################################

graphics = gmsh.add_module('graphics','Graphics functions')

doc = '''Draw all the OpenGL scenes.'''
graphics.add('draw',doc,None)

################################################################################

fltk = gmsh.add_module('fltk','Fltk graphical user interface functions')

doc = '''Create the Fltk graphical user interface.'''
fltk.add('initialize',doc,None)

doc = '''Wait at most `time' seconds for user interface events and return. If `time' < 0, wait indefinitely. First automatically create the user interface if it has not yet been initialized.'''
fltk.add('wait',doc,None,idouble('time', '-1.'))

doc = '''Run the event loop of the Fltk graphical user interface, i.e. repeatedly calls `wait'. First automatically create the user interface if it has not yet been initialized.'''
fltk.add('run',doc,None)

################################################################################

onelab = gmsh.add_module('onelab','ONELAB server functions')

doc = '''Get `data' from the ONELAB server.'''
onelab.add('get',doc,None,ostring('data'),istring('format', '"json"'))

doc = '''Set `data' in the ONELAB server.'''
onelab.add('set',doc,None,istring('data'),istring('format', '"json"'))

doc = '''Run a ONELAB client. If `name' is provided, create a new ONELAB client with name `name' and executes `command'. If not, try to run a client that might be linked to the processed input files.'''
onelab.add('run',doc,None,istring('name', '""'),istring('command', '""'))

################################################################################

api.write_cpp()
api.write_c()
api.write_python()
api.write_julia()
api.write_texi()
