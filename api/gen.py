# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
#  - gmsh.f90: the Gmsh Fortran API module
#  - api.texi: the texinfo API documentation
#
# By design, the Gmsh API is purely functional, and only uses elementary types
# from the target language.
#
# See `tutorials/{c++,c,python,julia,fortran}' and `examples/api' for tutorials and
# examples on how to use the Gmsh API.

import os
from GenApi import *

dirname = os.path.dirname(os.path.realpath(__file__))

with open(os.path.join(dirname, '..', 'CMakeLists.txt'), 'rt') as f:
    contents = f.read()
    start = contents.find('GMSH_MAJOR_VERSION') + 18
    end = contents.find(')', start)
    version_major = int(contents[start:end])
    start = contents.find('GMSH_MINOR_VERSION') + 18
    end = contents.find(')', start)
    version_minor = int(contents[start:end])
    start = contents.find('GMSH_PATCH_VERSION') + 18
    end = contents.find(')', start)
    version_patch = int(contents[start:end])

api = API(version_major, version_minor, version_patch)

################################################################################

gmsh = api.add_module('gmsh', 'top-level functions')

doc = '''Initialize the Gmsh API. This must be called before any call to the other functions in the API. If `argc' and `argv' (or just `argv' in Python or Julia) are provided, they will be handled in the same way as the command line arguments in the Gmsh app. If `readConfigFiles' is set, read system Gmsh configuration files (gmshrc and gmsh-options). If `run' is set, run in the same way as the Gmsh app, either interactively or in batch mode depending on the command line arguments. If `run' is not set, initializing the API sets the options "General.AbortOnError" to 2 and "General.Terminal" to 1.'''
gmsh.add('initialize', doc, None, iargcargv(), ibool('readConfigFiles', 'true', 'True', 'true'), ibool('run', 'false', 'False'))

doc = '''Return 1 if the Gmsh API is initialized, and 0 if not.'''
gmsh.add('isInitialized', doc, oint)

doc = '''Finalize the Gmsh API. This must be called when you are done using the Gmsh API.'''
gmsh.add('finalize', doc, None)

doc = '''Open a file. Equivalent to the `File->Open' menu in the Gmsh app. Handling of the file depends on its extension and/or its contents: opening a file with model data will create a new model.'''
gmsh.add('open', doc, None, istring('fileName'))

doc = '''Merge a file. Equivalent to the `File->Merge' menu in the Gmsh app. Handling of the file depends on its extension and/or its contents. Merging a file with model data will add the data to the current model.'''
gmsh.add('merge', doc, None, istring('fileName'))

doc = '''Write a file. The export format is determined by the file extension.'''
gmsh.add('write', doc, None, istring('fileName'))

doc = '''Clear all loaded models and post-processing data, and add a new empty model.'''
gmsh.add('clear', doc, None)

################################################################################

option = gmsh.add_module('option', 'option handling functions')

doc = '''Set a numerical option to `value'. `name' is of the form "Category.Option" or "Category[num].Option". Available categories and options are listed in the "Gmsh options" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-options).'''
option.add('setNumber', doc, None, istring('name'), idouble('value'))

doc = '''Get the `value' of a numerical option. `name' is of the form "Category.Option" or "Category[num].Option". Available categories and options are listed in the "Gmsh options" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-options).'''
option.add('getNumber', doc, None, istring('name'), odouble('value'))

doc = '''Set a string option to `value'. `name' is of the form "Category.Option" or "Category[num].Option". Available categories and options are listed in the "Gmsh options" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-options).'''
option.add('setString', doc, None, istring('name'), istring('value'))

doc = '''Get the `value' of a string option. `name' is of the form "Category.Option" or "Category[num].Option". Available categories and options are listed in the "Gmsh options" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-options).'''
option.add('getString', doc, None, istring('name'), ostring('value'))

doc = '''Set a color option to the RGBA value (`r', `g', `b', `a'), where where `r', `g', `b' and `a' should be integers between 0 and 255. `name' is of the form "Category.Color.Option" or "Category[num].Color.Option". Available categories and options are listed in the "Gmsh options" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-options). For conciseness "Color." can be ommitted in `name'.'''
option.add('setColor', doc, None, istring('name'), iint('r'), iint('g'), iint('b'), iint('a', '255'))

doc = '''Get the `r', `g', `b', `a' value of a color option. `name' is of the form "Category.Color.Option" or "Category[num].Color.Option". Available categories and options are listed in the "Gmsh options" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-options). For conciseness "Color." can be ommitted in `name'.'''
option.add('getColor', doc, None, istring('name'), oint('r'), oint('g'), oint('b'), oint('a'))

doc = '''Restore all options to default settings.'''
option.add('restoreDefaults', doc, None)

################################################################################

model = gmsh.add_module('model', 'model functions')

doc = '''Add a new model, with name `name', and set it as the current model.'''
model.add('add', doc, None, istring('name'))

doc = '''Remove the current model.'''
model.add('remove', doc, None)

doc = '''List the names of all models.'''
model.add('list', doc, None, ovectorstring('names'))

doc = '''Get the name of the current model.'''
model.add('getCurrent', doc, None, ostring('name'))

doc = '''Set the current model to the model with name `name'. If several models have the same name, select the one that was added first.'''
model.add('setCurrent', doc, None, istring('name'))

doc = '''Get the file name (if any) associated with the current model. A file name is associated when a model is read from a file on disk.'''
model.add('getFileName', doc, None, ostring('fileName'))

doc = '''Set the file name associated with the current model.'''
model.add('setFileName', doc, None, istring('fileName'))

doc = '''Get all the entities in the current model. A model entity is represented by two integers: its dimension (dim == 0, 1, 2 or 3) and its tag (its unique, strictly positive identifier). If `dim' is >= 0, return only the entities of the specified dimension (e.g. points if `dim' == 0). The entities are returned as a vector of (dim, tag) pairs.'''
model.add('getEntities', doc, None, ovectorpair('dimTags'), iint('dim', '-1'))

doc = '''Set the name of the entity of dimension `dim' and tag `tag'.'''
model.add('setEntityName', doc, None, iint('dim'), iint('tag'), istring('name'))

doc = '''Get the name of the entity of dimension `dim' and tag `tag'.'''
model.add('getEntityName', doc, None, iint('dim'), iint('tag'), ostring('name'))

doc = '''Remove the entity name `name' from the current model.'''
model.add('removeEntityName', doc, None, istring('name'))

doc = '''Get all the physical groups in the current model. If `dim' is >= 0, return only the entities of the specified dimension (e.g. physical points if `dim' == 0). The entities are returned as a vector of (dim, tag) pairs.'''
model.add('getPhysicalGroups', doc, None, ovectorpair('dimTags'), iint('dim', '-1'))

doc = '''Get the tags of the model entities making up the physical group of dimension `dim' and tag `tag'.'''
model.add('getEntitiesForPhysicalGroup', doc, None, iint('dim'), iint('tag'), ovectorint('tags'))

doc = '''Get the model entities (as a vector (dim, tag) pairs) making up the physical group with name `name'.'''
model.add('getEntitiesForPhysicalName', doc, None, istring('name'), ovectorpair('dimTags'))

doc = '''Get the tags of the physical groups (if any) to which the model entity of dimension `dim' and tag `tag' belongs.'''
model.add('getPhysicalGroupsForEntity', doc, None, iint('dim'), iint('tag'), ovectorint('physicalTags'))

doc = '''Add a physical group of dimension `dim', grouping the model entities with tags `tags'. Return the tag of the physical group, equal to `tag' if `tag' is positive, or a new tag if `tag' < 0. Set the name of the physical group if `name' is not empty.'''
model.add('addPhysicalGroup', doc, oint, iint('dim'), ivectorint('tags'), iint('tag', '-1'), istring('name', '""'))

doc = '''Remove the physical groups `dimTags' (given as a vector of (dim, tag) pairs) from the current model. If `dimTags' is empty, remove all groups.'''
model.add('removePhysicalGroups', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Set the name of the physical group of dimension `dim' and tag `tag'.'''
model.add('setPhysicalName', doc, None, iint('dim'), iint('tag'), istring('name'))

doc = '''Get the name of the physical group of dimension `dim' and tag `tag'.'''
model.add('getPhysicalName', doc, None, iint('dim'), iint('tag'), ostring('name'))

doc = '''Remove the physical name `name' from the current model.'''
model.add('removePhysicalName', doc, None, istring('name'))

doc = '''Set the tag of the entity of dimension `dim' and tag `tag' to the new value `newTag'.'''
model.add('setTag', doc, None, iint('dim'), iint('tag'), iint('newTag'))

doc = '''Get the boundary of the model entities `dimTags', given as a vector of (dim, tag) pairs. Return in `outDimTags' the boundary of the individual entities (if `combined' is false) or the boundary of the combined geometrical shape formed by all input entities (if `combined' is true). Return tags multiplied by the sign of the boundary entity if `oriented' is true. Apply the boundary operator recursively down to dimension 0 (i.e. to points) if `recursive' is true.'''
model.add('getBoundary', doc, None, ivectorpair('dimTags'), ovectorpair('outDimTags'), ibool('combined', 'true', 'True'), ibool('oriented', 'true', 'True'), ibool('recursive', 'false', 'False'))

doc = '''Get the upward and downward adjacencies of the model entity of dimension `dim' and tag `tag'. The `upward' vector returns the tags of adjacent entities of dimension `dim' + 1; the `downward' vector returns the tags of adjacent entities of dimension `dim' - 1.'''
model.add('getAdjacencies', doc, None, iint('dim'), iint('tag'), ovectorint('upward'), ovectorint('downward'))

doc = '''Get the model entities in the bounding box defined by the two points (`xmin', `ymin', `zmin') and (`xmax', `ymax', `zmax'). If `dim' is >= 0, return only the entities of the specified dimension (e.g. points if `dim' == 0).'''
model.add('getEntitiesInBoundingBox', doc, None, idouble('xmin'), idouble('ymin'), idouble('zmin'), idouble('xmax'), idouble('ymax'), idouble('zmax'), ovectorpair('dimTags'), iint('dim', '-1'))

doc = '''Get the bounding box (`xmin', `ymin', `zmin'), (`xmax', `ymax', `zmax') of the model entity of dimension `dim' and tag `tag'. If `dim' and `tag' are negative, get the bounding box of the whole model.'''
model.add('getBoundingBox', doc, None, iint('dim'), iint('tag'), odouble('xmin'), odouble('ymin'), odouble('zmin'), odouble('xmax'), odouble('ymax'), odouble('zmax'))

doc = '''Return the geometrical dimension of the current model.'''
model.add('getDimension', doc, oint)

doc = '''Add a discrete model entity (defined by a mesh) of dimension `dim' in the current model. Return the tag of the new discrete entity, equal to `tag' if `tag' is positive, or a new tag if `tag' < 0. `boundary' specifies the tags of the entities on the boundary of the discrete entity, if any. Specifying `boundary' allows Gmsh to construct the topology of the overall model.'''
model.add('addDiscreteEntity', doc, oint, iint('dim'), iint('tag', '-1'), ivectorint('boundary', 'std::vector<int>()', '[]', '[]'))

doc = '''Remove the entities `dimTags' (given as a vector of (dim, tag) pairs) of the current model, provided that they are not on the boundary of (or embedded in) higher-dimensional entities. If `recursive' is true, remove all the entities on their boundaries, down to dimension 0.'''
model.add('removeEntities', doc, None, ivectorpair('dimTags'), ibool('recursive', 'false', 'False'))

doc = '''Get the type of the entity of dimension `dim' and tag `tag'.'''
model.add('getType', doc, None, iint('dim'), iint('tag'), ostring('entityType'))

doc = '''In a partitioned model, get the parent of the entity of dimension `dim' and tag `tag', i.e. from which the entity is a part of, if any. `parentDim' and `parentTag' are set to -1 if the entity has no parent.'''
model.add('getParent', doc, None, iint('dim'), iint('tag'), oint('parentDim'), oint('parentTag'))

doc = '''Return the number of partitions in the model.'''
model.add('getNumberOfPartitions', doc, oint)

doc = '''In a partitioned model, return the tags of the partition(s) to which the entity belongs.'''
model.add('getPartitions', doc, None, iint('dim'), iint('tag'), ovectorint('partitions'))

doc = '''Evaluate the parametrization of the entity of dimension `dim' and tag `tag' at the parametric coordinates `parametricCoord'. Only valid for `dim' equal to 0 (with empty `parametricCoord'), 1 (with `parametricCoord' containing parametric coordinates on the curve) or 2 (with `parametricCoord' containing u, v parametric coordinates on the surface, concatenated: [p1u, p1v, p2u, ...]). Return x, y, z coordinates in `coord', concatenated: [p1x, p1y, p1z, p2x, ...].'''
model.add('getValue', doc, None, iint('dim'), iint('tag'), ivectordouble('parametricCoord'), ovectordouble('coord'))

doc = '''Evaluate the derivative of the parametrization of the entity of dimension `dim' and tag `tag' at the parametric coordinates `parametricCoord'. Only valid for `dim' equal to 1 (with `parametricCoord' containing parametric coordinates on the curve) or 2 (with `parametricCoord' containing u, v parametric coordinates on the surface, concatenated: [p1u, p1v, p2u, ...]). For `dim' equal to 1 return the x, y, z components of the derivative with respect to u [d1ux, d1uy, d1uz, d2ux, ...]; for `dim' equal to 2 return the x, y, z components of the derivative with respect to u and v: [d1ux, d1uy, d1uz, d1vx, d1vy, d1vz, d2ux, ...].'''
model.add('getDerivative', doc, None, iint('dim'), iint('tag'), ivectordouble('parametricCoord'), ovectordouble('derivatives'))

doc = '''Evaluate the second derivative of the parametrization of the entity of dimension `dim' and tag `tag' at the parametric coordinates `parametricCoord'. Only valid for `dim' equal to 1 (with `parametricCoord' containing parametric coordinates on the curve) or 2 (with `parametricCoord' containing u, v parametric coordinates on the surface, concatenated: [p1u, p1v, p2u, ...]). For `dim' equal to 1 return the x, y, z components of the second derivative with respect to u [d1uux, d1uuy, d1uuz, d2uux, ...]; for `dim' equal to 2 return the x, y, z components of the second derivative with respect to u and v, and the mixed derivative with respect to u and v: [d1uux, d1uuy, d1uuz, d1vvx, d1vvy, d1vvz, d1uvx, d1uvy, d1uvz, d2uux, ...].'''
model.add('getSecondDerivative', doc, None, iint('dim'), iint('tag'), ivectordouble('parametricCoord'), ovectordouble('derivatives'))

doc = '''Evaluate the (maximum) curvature of the entity of dimension `dim' and tag `tag' at the parametric coordinates `parametricCoord'. Only valid for `dim' equal to 1 (with `parametricCoord' containing parametric coordinates on the curve) or 2 (with `parametricCoord' containing u, v parametric coordinates on the surface, concatenated: [p1u, p1v, p2u, ...]).'''
model.add('getCurvature', doc, None, iint('dim'), iint('tag'), ivectordouble('parametricCoord'), ovectordouble('curvatures'))

doc = '''Evaluate the principal curvatures of the surface with tag `tag' at the parametric coordinates `parametricCoord', as well as their respective directions. `parametricCoord' are given by pair of u and v coordinates, concatenated: [p1u, p1v, p2u, ...].'''
model.add('getPrincipalCurvatures', doc, None, iint('tag'), ivectordouble('parametricCoord'), ovectordouble('curvatureMax'), ovectordouble('curvatureMin'), ovectordouble('directionMax'), ovectordouble('directionMin'))

doc = '''Get the normal to the surface with tag `tag' at the parametric coordinates `parametricCoord'. The `parametricCoord' vector should contain u and v coordinates, concatenated: [p1u, p1v, p2u, ...]. `normals' are returned as a vector of x, y, z components, concatenated: [n1x, n1y, n1z, n2x, ...].'''
model.add('getNormal', doc, None, iint('tag'), ivectordouble('parametricCoord'), ovectordouble('normals'))

doc = '''Get the parametric coordinates `parametricCoord' for the points `coord' on the entity of dimension `dim' and tag `tag'. `coord' are given as x, y, z coordinates, concatenated: [p1x, p1y, p1z, p2x, ...]. `parametricCoord' returns the parametric coordinates t on the curve (if `dim' = 1) or u and v coordinates concatenated on the surface (if `dim' == 2), i.e. [p1t, p2t, ...] or [p1u, p1v, p2u, ...].'''
model.add('getParametrization', doc, None, iint('dim'), iint('tag'), ivectordouble('coord'), ovectordouble('parametricCoord'))

doc = '''Get the `min' and `max' bounds of the parametric coordinates for the entity of dimension `dim' and tag `tag'.'''
model.add('getParametrizationBounds', doc, None, iint('dim'), iint('tag'), ovectordouble('min'), ovectordouble('max'))

doc = '''Check if the coordinates (or the parametric coordinates if `parametric' is set) provided in `coord' correspond to points inside the entity of dimension `dim' and tag `tag', and return the number of points inside. This feature is only available for a subset of entities, depending on the underlying geometrical representation.'''
model.add('isInside', doc, oint, iint('dim'), iint('tag'), ivectordouble('coord'), ibool('parametric', 'false', 'False'))

doc = '''Get the points `closestCoord' on the entity of dimension `dim' and tag `tag' to the points `coord', by orthogonal projection. `coord' and `closestCoord' are given as x, y, z coordinates, concatenated: [p1x, p1y, p1z, p2x, ...]. `parametricCoord' returns the parametric coordinates t on the curve (if `dim' == 1) or u and v coordinates concatenated on the surface (if `dim' = 2), i.e. [p1t, p2t, ...] or [p1u, p1v, p2u, ...].'''
model.add('getClosestPoint', doc, None, iint('dim'), iint('tag'), ivectordouble('coord'), ovectordouble('closestCoord'), ovectordouble('parametricCoord'))

doc = '''Reparametrize the boundary entity (point or curve, i.e. with `dim' == 0 or `dim' == 1) of tag `tag' on the surface `surfaceTag'. If `dim' == 1, reparametrize all the points corresponding to the parametric coordinates `parametricCoord'. Multiple matches in case of periodic surfaces can be selected with `which'. This feature is only available for a subset of entities, depending on the underlying geometrical representation.'''
model.add('reparametrizeOnSurface', doc, None, iint('dim'), iint('tag'), ivectordouble('parametricCoord'), iint('surfaceTag'), ovectordouble('surfaceParametricCoord'), iint('which', '0'))

doc = '''Set the visibility of the model entities `dimTags' (given as a vector of (dim, tag) pairs) to `value'. Apply the visibility setting recursively if `recursive' is true.'''
model.add('setVisibility', doc, None, ivectorpair('dimTags'), iint('value'), ibool('recursive', 'false', 'False'))

doc = '''Get the visibility of the model entity of dimension `dim' and tag `tag'.'''
model.add('getVisibility', doc, None, iint('dim'), iint('tag'), oint('value'))

doc = '''Set the global visibility of the model per window to `value', where `windowIndex' identifies the window in the window list.'''
model.add('setVisibilityPerWindow', doc, None, iint('value'), iint('windowIndex', '0'))

doc = '''Set the color of the model entities `dimTags' (given as a vector of (dim, tag) pairs) to the RGBA value (`r', `g', `b', `a'), where `r', `g', `b' and `a' should be integers between 0 and 255. Apply the color setting recursively if `recursive' is true.'''
model.add('setColor', doc, None, ivectorpair('dimTags'), iint('r'), iint('g'), iint('b'), iint('a', '255'), ibool('recursive', 'false', 'False'))

doc = '''Get the color of the model entity of dimension `dim' and tag `tag'. If no color is specified for the entity, return fully transparent blue, i.e. (0, 0, 255, 0).'''
model.add('getColor', doc, None, iint('dim'), iint('tag'), oint('r'), oint('g'), oint('b'), oint('a'))

doc = '''Set the `x', `y', `z' coordinates of a geometrical point.'''
model.add('setCoordinates', doc, None, iint('tag'), idouble('x'), idouble('y'), idouble('z'))

doc = '''Set the values of the attribute with name `name'.'''
model.add('setAttribute', doc, None, istring('name'), ivectorstring('values'))

doc = '''Get the values of the attribute with name `name'.'''
model.add('getAttribute', doc, None, istring('name'), ovectorstring('values'))

doc = '''Get the names of any optional attributes stored in the model.'''
model.add('getAttributeNames', doc, None, ovectorstring('names'))

doc = '''Remove the attribute with name `name'.'''
model.add('removeAttribute', doc, None, istring('name'))

################################################################################

mesh = model.add_module('mesh', 'mesh functions')

doc = '''Generate a mesh of the current model, up to dimension `dim' (0, 1, 2 or 3).'''
mesh.add('generate', doc, None, iint('dim', '3'))

doc = '''Partition the mesh of the current model into `numPart' partitions. Optionally, `elementTags' and `partitions' can be provided to specify the partition of each element explicitly.'''
mesh.add('partition', doc, None, iint('numPart'), ivectorsize('elementTags', 'std::vector<std::size_t>()','[]', '[]'), ivectorint('partitions', 'std::vector<int>()','[]', '[]'))

doc = '''Unpartition the mesh of the current model.'''
mesh.add('unpartition', doc, None)

doc = '''Optimize the mesh of the current model using `method' (empty for default tetrahedral mesh optimizer, "Netgen" for Netgen optimizer, "HighOrder" for direct high-order mesh optimizer, "HighOrderElastic" for high-order elastic smoother, "HighOrderFastCurving" for fast curving algorithm, "Laplace2D" for Laplace smoothing, "Relocate2D" and "Relocate3D" for node relocation, "QuadQuasiStructured" for quad mesh optimization, "UntangleMeshGeometry" for untangling). If `force' is set apply the optimization also to discrete entities. If `dimTags' (given as a vector of (dim, tag) pairs) is given, only apply the optimizer to the given entities.'''
mesh.add('optimize', doc, None, istring('method', '""'), ibool('force', 'false', 'False'), iint('niter', '1'), ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Recombine the mesh of the current model.'''
mesh.add('recombine', doc, None)

doc = '''Refine the mesh of the current model by uniformly splitting the elements.'''
mesh.add('refine', doc, None)

doc = '''Change the order of the elements in the mesh of the current model to `order'.'''
mesh.add('setOrder', doc, None, iint('order'))

doc = '''Get the last entities `dimTags' (as a vector of (dim, tag) pairs) where a meshing error occurred. Currently only populated by the new 3D meshing algorithms.'''
mesh.add('getLastEntityError', doc, None, ovectorpair('dimTags'))

doc = '''Get the last node tags `nodeTags' where a meshing error occurred. Currently only populated by the new 3D meshing algorithms.'''
mesh.add('getLastNodeError', doc, None, ovectorsize('nodeTags'))

doc = '''Clear the mesh, i.e. delete all the nodes and elements, for the entities `dimTags', given as a vector of (dim, tag) pairs. If `dimTags' is empty, clear the whole mesh. Note that the mesh of an entity can only be cleared if this entity is not on the boundary of another entity with a non-empty mesh.'''
mesh.add('clear', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Remove the elements with tags `elementTags' from the entity of dimension `dim' and tag `tag'. If `elementTags' is empty, remove all the elements classified on the entity. To get consistent node classification on model entities, `reclassifyNodes()' should be called afterwards.'''
mesh.add('removeElements', doc, None, iint('dim'), iint('tag'), ivectorsize('elementTags', 'std::vector<std::size_t>()', '[]', '[]'))

doc = '''Reverse the orientation of the elements in the entities `dimTags', given as a vector of (dim, tag) pairs. If `dimTags' is empty, reverse the orientation of the elements in the whole mesh.'''
mesh.add('reverse', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Reverse the orientation of the elements with tags `elementTags'.'''
mesh.add('reverseElements', doc, None, ivectorsize('elementTags'))

doc = '''Apply the affine transformation `affineTransform' (16 entries of a 4x4 matrix, by row; only the 12 first can be provided for convenience) to the coordinates of the nodes classified on the entities `dimTags', given as a vector of (dim, tag) pairs. If `dimTags' is empty, transform all the nodes in the mesh.'''
mesh.add('affineTransform', doc, None, ivectordouble('affineTransform'), ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Get the nodes classified on the entity of dimension `dim' and tag `tag'. If `tag' < 0, get the nodes for all entities of dimension `dim'. If `dim' and `tag' are negative, get all the nodes in the mesh. `nodeTags' contains the node tags (their unique, strictly positive identification numbers). `coord' is a vector of length 3 times the length of `nodeTags' that contains the x, y, z coordinates of the nodes, concatenated: [n1x, n1y, n1z, n2x, ...]. If `dim' >= 0 and `returnParamtricCoord' is set, `parametricCoord' contains the parametric coordinates ([u1, u2, ...] or [u1, v1, u2, ...]) of the nodes, if available. The length of `parametricCoord' can be 0 or `dim' times the length of `nodeTags'. If `includeBoundary' is set, also return the nodes classified on the boundary of the entity (which will be reparametrized on the entity if `dim' >= 0 in order to compute their parametric coordinates).'''
mesh.add('getNodes', doc, None, ovectorsize('nodeTags'), ovectordouble('coord'), ovectordouble('parametricCoord'), iint('dim', '-1'), iint('tag', '-1'), ibool('includeBoundary', 'false', 'False'), ibool('returnParametricCoord', 'true', 'True'))

doc = '''Get the nodes classified on the entity of tag `tag', for all the elements of type `elementType'. The other arguments are treated as in `getNodes'.'''
mesh.add('getNodesByElementType', doc, None, iint('elementType'),  ovectorsize('nodeTags'), ovectordouble('coord'), ovectordouble('parametricCoord'), iint('tag', '-1'), ibool('returnParametricCoord', 'true', 'True'))

doc = '''Get the coordinates and the parametric coordinates (if any) of the node with tag `tag', as well as the dimension `dim' and tag `tag' of the entity on which the node is classified. This function relies on an internal cache (a vector in case of dense node numbering, a map otherwise); for large meshes accessing nodes in bulk is often preferable.'''
mesh.add('getNode', doc, None, isize('nodeTag'), ovectordouble('coord'), ovectordouble('parametricCoord'), oint('dim'), oint('tag'))

doc = '''Set the coordinates and the parametric coordinates (if any) of the node with tag `tag'. This function relies on an internal cache (a vector in case of dense node numbering, a map otherwise); for large meshes accessing nodes in bulk is often preferable.'''
mesh.add('setNode', doc, None, isize('nodeTag'), ivectordouble('coord'), ivectordouble('parametricCoord'))

doc = '''Rebuild the node cache.'''
mesh.add('rebuildNodeCache', doc, None, ibool('onlyIfNecessary', 'true', 'True'))

doc = '''Rebuild the element cache.'''
mesh.add('rebuildElementCache', doc, None, ibool('onlyIfNecessary', 'true', 'True'))

doc = '''Get the nodes from all the elements belonging to the physical group of dimension `dim' and tag `tag'. `nodeTags' contains the node tags; `coord' is a vector of length 3 times the length of `nodeTags' that contains the x, y, z coordinates of the nodes, concatenated: [n1x, n1y, n1z, n2x, ...].'''
mesh.add('getNodesForPhysicalGroup', doc, None, iint('dim'), iint('tag'), ovectorsize('nodeTags'), ovectordouble('coord'))

doc = '''Get the maximum tag `maxTag' of a node in the mesh.'''
mesh.add('getMaxNodeTag', doc, None, osize('maxTag'))

doc = '''Add nodes classified on the model entity of dimension `dim' and tag `tag'. `nodeTags' contains the node tags (their unique, strictly positive identification numbers). `coord' is a vector of length 3 times the length of `nodeTags' that contains the x, y, z coordinates of the nodes, concatenated: [n1x, n1y, n1z, n2x, ...]. The optional `parametricCoord' vector contains the parametric coordinates of the nodes, if any. The length of `parametricCoord' can be 0 or `dim' times the length of `nodeTags'. If the `nodeTags' vector is empty, new tags are automatically assigned to the nodes.'''
mesh.add('addNodes', doc, None, iint('dim'), iint('tag'), ivectorsize('nodeTags'), ivectordouble('coord'), ivectordouble('parametricCoord', 'std::vector<double>()', '[]', '[]'))

doc = '''Reclassify all nodes on their associated model entity, based on the elements. Can be used when importing nodes in bulk (e.g. by associating them all to a single volume), to reclassify them correctly on model surfaces, curves, etc. after the elements have been set.'''
mesh.add('reclassifyNodes', doc, None)

doc = '''Relocate the nodes classified on the entity of dimension `dim' and tag `tag' using their parametric coordinates. If `tag' < 0, relocate the nodes for all entities of dimension `dim'. If `dim' and `tag' are negative, relocate all the nodes in the mesh.'''
mesh.add('relocateNodes', doc, None, iint('dim', '-1'), iint('tag', '-1'))

doc = '''Get the elements classified on the entity of dimension `dim' and tag `tag'. If `tag' < 0, get the elements for all entities of dimension `dim'. If `dim' and `tag' are negative, get all the elements in the mesh. `elementTypes' contains the MSH types of the elements (e.g. `2' for 3-node triangles: see `getElementProperties' to obtain the properties for a given element type). `elementTags' is a vector of the same length as `elementTypes'; each entry is a vector containing the tags (unique, strictly positive identifiers) of the elements of the corresponding type. `nodeTags' is also a vector of the same length as `elementTypes'; each entry is a vector of length equal to the number of elements of the given type times the number N of nodes for this type of element, that contains the node tags of all the elements of the given type, concatenated: [e1n1, e1n2, ..., e1nN, e2n1, ...].'''
mesh.add('getElements', doc, None, ovectorint('elementTypes'), ovectorvectorsize('elementTags'), ovectorvectorsize('nodeTags'), iint('dim', '-1'), iint('tag', '-1'))

doc = '''Get the type and node tags of the element with tag `tag', as well as the dimension `dim' and tag `tag' of the entity on which the element is classified. This function relies on an internal cache (a vector in case of dense element numbering, a map otherwise); for large meshes accessing elements in bulk is often preferable.'''
mesh.add('getElement', doc, None, isize('elementTag'), oint('elementType'), ovectorsize('nodeTags'), oint('dim'), oint('tag'))

doc = '''Search the mesh for an element located at coordinates (`x', `y', `z'). This function performs a search in a spatial octree. If an element is found, return its tag, type and node tags, as well as the local coordinates (`u', `v', `w') within the reference element corresponding to search location. If `dim' is >= 0, only search for elements of the given dimension. If `strict' is not set, use a tolerance to find elements near the search location.'''
mesh.add('getElementByCoordinates', doc, None, idouble('x'), idouble('y'), idouble('z'), osize('elementTag'), oint('elementType'), ovectorsize('nodeTags'), odouble('u'), odouble('v'), odouble('w'), iint('dim', '-1'), ibool('strict', 'false', 'False'))

doc = '''Search the mesh for element(s) located at coordinates (`x', `y', `z'). This function performs a search in a spatial octree. Return the tags of all found elements in `elementTags'. Additional information about the elements can be accessed through `getElement' and `getLocalCoordinatesInElement'. If `dim' is >= 0, only search for elements of the given dimension. If `strict' is not set, use a tolerance to find elements near the search location.'''
mesh.add('getElementsByCoordinates', doc, None, idouble('x'), idouble('y'), idouble('z'), ovectorsize('elementTags'), iint('dim', '-1'), ibool('strict', 'false', 'False'))

doc = '''Return the local coordinates (`u', `v', `w') within the element `elementTag' corresponding to the model coordinates (`x', `y', `z'). This function relies on an internal cache (a vector in case of dense element numbering, a map otherwise); for large meshes accessing elements in bulk is often preferable.'''
mesh.add('getLocalCoordinatesInElement', doc, None, isize('elementTag'), idouble('x'), idouble('y'), idouble('z'), odouble('u'), odouble('v'), odouble('w'))

doc = '''Get the types of elements in the entity of dimension `dim' and tag `tag'. If `tag' < 0, get the types for all entities of dimension `dim'. If `dim' and `tag' are negative, get all the types in the mesh.'''
mesh.add('getElementTypes', doc, None, ovectorint('elementTypes'), iint('dim', '-1'), iint('tag', '-1'))

doc = '''Return an element type given its family name `familyName' ("Point", "Line", "Triangle", "Quadrangle", "Tetrahedron", "Pyramid", "Prism", "Hexahedron") and polynomial order `order'. If `serendip' is true, return the corresponding serendip element type (element without interior nodes).'''
mesh.add('getElementType', doc, oint, istring('familyName'), iint('order'), ibool('serendip', 'false', 'False'))

doc = '''Get the properties of an element of type `elementType': its name (`elementName'), dimension (`dim'), order (`order'), number of nodes (`numNodes'), local coordinates of the nodes in the reference element (`localNodeCoord' vector, of length `dim' times `numNodes') and number of primary (first order) nodes (`numPrimaryNodes').'''
mesh.add('getElementProperties', doc, None, iint('elementType'), ostring('elementName'), oint('dim'), oint('order'), oint('numNodes'), ovectordouble('localNodeCoord'), oint('numPrimaryNodes'))

doc = '''Get the elements of type `elementType' classified on the entity of tag `tag'. If `tag' < 0, get the elements for all entities. `elementTags' is a vector containing the tags (unique, strictly positive identifiers) of the elements of the corresponding type. `nodeTags' is a vector of length equal to the number of elements of the given type times the number N of nodes for this type of element, that contains the node tags of all the elements of the given type, concatenated: [e1n1, e1n2, ..., e1nN, e2n1, ...]. If `numTasks' > 1, only compute and return the part of the data indexed by `task' (for C++ only; output vectors must be preallocated).'''
mesh.add('getElementsByType', doc, None, iint('elementType'), ovectorsize('elementTags'), ovectorsize('nodeTags'), iint('tag', '-1'), isize('task', '0'), isize('numTasks', '1'))

doc = '''Get the maximum tag `maxTag' of an element in the mesh.'''
mesh.add('getMaxElementTag', doc, None, osize('maxTag'))

doc = '''Preallocate data before calling `getElementsByType' with `numTasks' > 1. For C++ only.'''
mesh.add_special('preallocateElementsByType', doc, ['onlycc++'], None, iint('elementType'), ibool('elementTag'), ibool('nodeTag'), ovectorsize('elementTags'), ovectorsize('nodeTags'), iint('tag', '-1'))

doc = '''Get the quality `elementQualities' of the elements with tags `elementTags'. `qualityType' is the requested quality measure: "minDetJac" and "maxDetJac" for the adaptively computed minimal and maximal Jacobian determinant, "minSJ" for the sampled minimal scaled jacobien, "minSICN" for the sampled minimal signed inverted condition number, "minSIGE" for the sampled signed inverted gradient error, "gamma" for the ratio of the inscribed to circumcribed sphere radius, "innerRadius" for the inner radius, "outerRadius" for the outerRadius, "minIsotropy" for the minimum isotropy measure, "angleShape" for the angle shape measure, "minEdge" for the minimum straight edge length, "maxEdge" for the maximum straight edge length, "volume" for the volume. If `numTasks' > 1, only compute and return the part of the data indexed by `task' (for C++ only; output vector must be preallocated).'''
mesh.add('getElementQualities', doc, None, ivectorsize('elementTags'), ovectordouble('elementsQuality'), istring('qualityName', '"minSICN"'), isize('task', '0'), isize('numTasks', '1'))

doc = '''Add elements classified on the entity of dimension `dim' and tag `tag'. `types' contains the MSH types of the elements (e.g. `2' for 3-node triangles: see the Gmsh reference manual). `elementTags' is a vector of the same length as `types'; each entry is a vector containing the tags (unique, strictly positive identifiers) of the elements of the corresponding type. `nodeTags' is also a vector of the same length as `types'; each entry is a vector of length equal to the number of elements of the given type times the number N of nodes per element, that contains the node tags of all the elements of the given type, concatenated: [e1n1, e1n2, ..., e1nN, e2n1, ...].'''
mesh.add('addElements', doc, None, iint('dim'), iint('tag'), ivectorint('elementTypes'), ivectorvectorsize('elementTags'), ivectorvectorsize('nodeTags'))

doc = '''Add elements of type `elementType' classified on the entity of tag `tag'. `elementTags' contains the tags (unique, strictly positive identifiers) of the elements of the corresponding type. `nodeTags' is a vector of length equal to the number of elements times the number N of nodes per element, that contains the node tags of all the elements, concatenated: [e1n1, e1n2, ..., e1nN, e2n1, ...]. If the `elementTag' vector is empty, new tags are automatically assigned to the elements.'''
mesh.add('addElementsByType', doc, None, iint('tag'), iint('elementType'), ivectorsize('elementTags'), ivectorsize('nodeTags'))

doc = '''Get the numerical quadrature information for the given element type `elementType' and integration rule `integrationType', where `integrationType' concatenates the integration rule family name with the desired order (e.g. "Gauss4" for a quadrature suited for integrating 4th order polynomials). The "CompositeGauss" family uses tensor-product rules based the 1D Gauss-Legendre rule; the "Gauss" family uses an economic scheme when available (i.e. with a minimal number of points), and falls back to "CompositeGauss" otherwise. Note that integration points for the "Gauss" family can fall outside of the reference element for high-order rules. `localCoord' contains the u, v, w coordinates of the G integration points in the reference element: [g1u, g1v, g1w, ..., gGu, gGv, gGw]. `weights' contains the associated weights: [g1q, ..., gGq].'''
mesh.add('getIntegrationPoints', doc, None, iint('elementType'), istring('integrationType'), ovectordouble('localCoord'), ovectordouble('weights'))

doc = '''Get the Jacobians of all the elements of type `elementType' classified on the entity of tag `tag', at the G evaluation points `localCoord' given as concatenated u, v, w coordinates in the reference element [g1u, g1v, g1w, ..., gGu, gGv, gGw]. Data is returned by element, with elements in the same order as in `getElements' and `getElementsByType'. `jacobians' contains for each element the 9 entries of the 3x3 Jacobian matrix at each evaluation point. The matrix is returned by column: [e1g1Jxu, e1g1Jyu, e1g1Jzu, e1g1Jxv, ..., e1g1Jzw, e1g2Jxu, ..., e1gGJzw, e2g1Jxu, ...], with Jxu = dx/du, Jyu = dy/du, etc. `determinants' contains for each element the determinant of the Jacobian matrix at each evaluation point: [e1g1, e1g2, ... e1gG, e2g1, ...]. `coord' contains for each element the x, y, z coordinates of the evaluation points. If `tag' < 0, get the Jacobian data for all entities. If `numTasks' > 1, only compute and return the part of the data indexed by `task' (for C++ only; output vectors must be preallocated).'''
mesh.add('getJacobians', doc, None, iint('elementType'), ivectordouble('localCoord'), ovectordouble('jacobians'), ovectordouble('determinants'), ovectordouble('coord'), iint('tag', '-1'), isize('task', '0'), isize('numTasks', '1'))

doc = '''Preallocate data before calling `getJacobians' with `numTasks' > 1. For C++ only.'''
mesh.add_special('preallocateJacobians', doc, ['onlycc++'], None, iint('elementType'), iint('numEvaluationPoints'), ibool('allocateJacobians'), ibool('allocateDeterminants'), ibool('allocateCoord'), ovectordouble('jacobians'), ovectordouble('determinants'), ovectordouble('coord'), iint('tag', '-1'))

doc = '''Get the Jacobian for a single element `elementTag', at the G evaluation points `localCoord' given as concatenated u, v, w coordinates in the reference element [g1u, g1v, g1w, ..., gGu, gGv, gGw]. `jacobians' contains the 9 entries of the 3x3 Jacobian matrix at each evaluation point. The matrix is returned by column: [e1g1Jxu, e1g1Jyu, e1g1Jzu, e1g1Jxv, ..., e1g1Jzw, e1g2Jxu, ..., e1gGJzw, e2g1Jxu, ...], with Jxu = dx/du, Jyu = dy/du, etc. `determinants' contains the determinant of the Jacobian matrix at each evaluation point. `coord' contains the x, y, z coordinates of the evaluation points. This function relies on an internal cache (a vector in case of dense element numbering, a map otherwise); for large meshes accessing Jacobians in bulk is often preferable.'''
mesh.add('getJacobian', doc, None, isize('elementTag'), ivectordouble('localCoord'), ovectordouble('jacobians'), ovectordouble('determinants'), ovectordouble('coord'))

doc = '''Get the basis functions of the element of type `elementType' at the evaluation points `localCoord' (given as concatenated u, v, w coordinates in the reference element [g1u, g1v, g1w, ..., gGu, gGv, gGw]), for the function space `functionSpaceType'. Currently supported function spaces include "Lagrange" and "GradLagrange" for isoparametric Lagrange basis functions and their gradient in the u, v, w coordinates of the reference element; "LagrangeN" and "GradLagrangeN", with N = 1, 2, ..., for N-th order Lagrange basis functions; "H1LegendreN" and "GradH1LegendreN", with N = 1, 2, ..., for N-th order hierarchical H1 Legendre functions; "HcurlLegendreN" and "CurlHcurlLegendreN", with N = 1, 2, ..., for N-th order curl-conforming basis functions. `numComponents' returns the number C of components of a basis function (e.g. 1 for scalar functions and 3 for vector functions). `basisFunctions' returns the value of the N basis functions at the evaluation points, i.e. [g1f1, g1f2, ..., g1fN, g2f1, ...] when C == 1 or [g1f1u, g1f1v, g1f1w, g1f2u, ..., g1fNw, g2f1u, ...] when C == 3. For basis functions that depend on the orientation of the elements, all values for the first orientation are returned first, followed by values for the second, etc. `numOrientations' returns the overall number of orientations. If the `wantedOrientations' vector is not empty, only return the values for the desired orientation indices.'''
mesh.add('getBasisFunctions', doc, None, iint('elementType'), ivectordouble('localCoord'), istring('functionSpaceType'), oint('numComponents'), ovectordouble('basisFunctions'), oint('numOrientations'), ivectorint('wantedOrientations', 'std::vector<int>()', '[]', '[]'))

doc = '''Get the orientation index of the elements of type `elementType' in the entity of tag `tag'. The arguments have the same meaning as in `getBasisFunctions'. `basisFunctionsOrientation' is a vector giving for each element the orientation index in the values returned by `getBasisFunctions'. For Lagrange basis functions the call is superfluous as it will return a vector of zeros. If `numTasks' > 1, only compute and return the part of the data indexed by `task' (for C++ only; output vector must be preallocated).'''
mesh.add('getBasisFunctionsOrientation', doc, None, iint('elementType'), istring('functionSpaceType'), ovectorint('basisFunctionsOrientation'), iint('tag','-1'), isize('task', '0'), isize('numTasks', '1'))

doc = '''Get the orientation of a single element `elementTag'.'''
mesh.add('getBasisFunctionsOrientationForElement', doc, None, isize('elementTag'), istring('functionSpaceType'), oint('basisFunctionsOrientation'))

doc = '''Get the number of possible orientations for elements of type `elementType' and function space named `functionSpaceType'.'''
mesh.add('getNumberOfOrientations', doc, oint, iint('elementType'), istring('functionSpaceType'))

doc = '''Preallocate data before calling `getBasisFunctionsOrientation' with `numTasks' > 1. For C++ only.'''
mesh.add_special('preallocateBasisFunctionsOrientation', doc, ['onlycc++'], None, iint('elementType'), ovectorint('basisFunctionsOrientation'), iint('tag', '-1'))

doc = '''Get the global unique mesh edge identifiers `edgeTags' and orientations `edgeOrientation' for an input list of node tag pairs defining these edges, concatenated in the vector `nodeTags'. Mesh edges are created e.g. by `createEdges()', `getKeys()' or `addEdges()'. The reference positive orientation is n1 < n2, where n1 and n2 are the tags of the two edge nodes, which corresponds to the local orientation of edge-based basis functions as well.'''
mesh.add('getEdges', doc, None, ivectorsize('nodeTags'), ovectorsize('edgeTags'), ovectorint('edgeOrientations'))

doc = '''Get the global unique mesh face identifiers `faceTags' and orientations `faceOrientations' for an input list of a multiple of three (if `faceType' == 3) or four (if `faceType' == 4) node tags defining these faces, concatenated in the vector `nodeTags'. Mesh faces are created e.g. by `createFaces()', `getKeys()' or `addFaces()'.'''
mesh.add('getFaces', doc, None, iint('faceType'), ivectorsize('nodeTags'), ovectorsize('faceTags'), ovectorint('faceOrientations'))

doc = '''Create unique mesh edges for the entities `dimTags', given as a vector of (dim, tag) pairs.'''
mesh.add('createEdges', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Create unique mesh faces for the entities `dimTags', given as a vector of (dim, tag) pairs.'''
mesh.add('createFaces', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Get the global unique identifiers `edgeTags' and the nodes `edgeNodes' of the edges in the mesh. Mesh edges are created e.g. by `createEdges()', `getKeys()' or addEdges().'''
mesh.add('getAllEdges', doc, None, ovectorsize('edgeTags'), ovectorsize('edgeNodes'))

doc = '''Get the global unique identifiers `faceTags' and the nodes `faceNodes' of the faces of type `faceType' in the mesh. Mesh faces are created e.g. by `createFaces()', `getKeys()' or addFaces().'''
mesh.add('getAllFaces', doc, None, iint('faceType'), ovectorsize('faceTags'), ovectorsize('faceNodes'))

doc = '''Add mesh edges defined by their global unique identifiers `edgeTags' and their nodes `edgeNodes'.'''
mesh.add('addEdges', doc, None, ivectorsize('edgeTags'), ivectorsize('edgeNodes'))

doc = '''Add mesh faces of type `faceType' defined by their global unique identifiers `faceTags' and their nodes `faceNodes'.'''
mesh.add('addFaces', doc, None, iint('faceType'), ivectorsize('faceTags'), ivectorsize('faceNodes'))

doc = '''Generate the pair of keys for the elements of type `elementType' in the entity of tag `tag', for the `functionSpaceType' function space. Each pair (`typeKey', `entityKey') uniquely identifies a basis function in the function space. If `returnCoord' is set, the `coord' vector contains the x, y, z coordinates locating basis functions for sorting purposes. Warning: this is an experimental feature and will probably change in a future release.'''
mesh.add('getKeys', doc, None, iint('elementType'), istring('functionSpaceType'), ovectorint('typeKeys'), ovectorsize('entityKeys'), ovectordouble('coord'), iint('tag', '-1'), ibool('returnCoord', 'true', 'True'))

doc = '''Get the pair of keys for a single element `elementTag'.'''
mesh.add('getKeysForElement', doc, None, isize('elementTag'), istring('functionSpaceType'), ovectorint('typeKeys'), ovectorsize('entityKeys'), ovectordouble('coord'), ibool('returnCoord', 'true', 'True'))

doc = '''Get the number of keys by elements of type `elementType' for function space named `functionSpaceType'.'''
mesh.add('getNumberOfKeys', doc, oint, iint('elementType'), istring('functionSpaceType'))

doc = '''Get information about the pair of `keys'. `infoKeys' returns information about the functions associated with the pairs (`typeKeys', `entityKey'). `infoKeys[0].first' describes the type of function (0 for  vertex function, 1 for edge function, 2 for face function and 3 for bubble function). `infoKeys[0].second' gives the order of the function associated with the key. Warning: this is an experimental feature and will probably change in a future release.'''
mesh.add('getKeysInformation', doc, None, ivectorint('typeKeys'), ivectorsize('entityKeys'), iint('elementType'), istring('functionSpaceType'), ovectorpair('infoKeys'))

doc = '''Get the barycenters of all elements of type `elementType' classified on the entity of tag `tag'. If `primary' is set, only the primary nodes of the elements are taken into account for the barycenter calculation. If `fast' is set, the function returns the sum of the primary node coordinates (without normalizing by the number of nodes). If `tag' < 0, get the barycenters for all entities. If `numTasks' > 1, only compute and return the part of the data indexed by `task' (for C++ only; output vector must be preallocated).'''
mesh.add('getBarycenters', doc, None, iint('elementType'), iint('tag'), ibool('fast'), ibool('primary'), ovectordouble('barycenters'), isize('task', '0'), isize('numTasks', '1'))

doc = '''Preallocate data before calling `getBarycenters' with `numTasks' > 1. For C++ only.'''
mesh.add_special('preallocateBarycenters', doc, ['onlycc++'], None, iint('elementType'), ovectordouble('barycenters'), iint('tag', '-1'))

doc = '''Get the nodes on the edges of all elements of type `elementType' classified on the entity of tag `tag'. `nodeTags' contains the node tags of the edges for all the elements: [e1a1n1, e1a1n2, e1a2n1, ...]. Data is returned by element, with elements in the same order as in `getElements' and `getElementsByType'. If `primary' is set, only the primary (begin/end) nodes of the edges are returned. If `tag' < 0, get the edge nodes for all entities. If `numTasks' > 1, only compute and return the part of the data indexed by `task' (for C++ only; output vector must be preallocated).'''
mesh.add('getElementEdgeNodes', doc, None, iint('elementType'), ovectorsize('nodeTags'), iint('tag', '-1'), ibool('primary', 'false', 'False'), isize('task', '0'), isize('numTasks', '1'))

doc = '''Get the nodes on the faces of type `faceType' (3 for triangular faces, 4 for quadrangular faces) of all elements of type `elementType' classified on the entity of tag `tag'. `nodeTags' contains the node tags of the faces for all elements: [e1f1n1, ..., e1f1nFaceType, e1f2n1, ...]. Data is returned by element, with elements in the same order as in `getElements' and `getElementsByType'. If `primary' is set, only the primary (corner) nodes of the faces are returned. If `tag' < 0, get the face nodes for all entities. If `numTasks' > 1, only compute and return the part of the data indexed by `task' (for C++ only; output vector must be preallocated).'''
mesh.add('getElementFaceNodes', doc, None, iint('elementType'), iint('faceType'), ovectorsize('nodeTags'), iint('tag', '-1'), ibool('primary', 'false', 'False'), isize('task', '0'), isize('numTasks', '1'))

doc = '''Get the ghost elements `elementTags' and their associated `partitions' stored in the ghost entity of dimension `dim' and tag `tag'.'''
mesh.add('getGhostElements', doc, None, iint('dim'), iint('tag'), ovectorsize('elementTags'), ovectorint('partitions'))

doc = '''Set a mesh size constraint on the model entities `dimTags', given as a vector of (dim, tag) pairs. Currently only entities of dimension 0 (points) are handled.'''
mesh.add('setSize', doc, None, ivectorpair('dimTags'), idouble('size'))

doc = '''Get the mesh size constraints (if any) associated with the model entities `dimTags', given as a vector of (dim, tag) pairs. A zero entry in the output `sizes' vector indicates that no size constraint is specified on the corresponding entity.'''
mesh.add('getSizes', doc, None, ivectorpair('dimTags'), ovectordouble('sizes'))

doc = '''Set mesh size constraints at the given parametric points `parametricCoord' on the model entity of dimension `dim' and tag `tag'. Currently only entities of dimension 1 (lines) are handled.'''
mesh.add('setSizeAtParametricPoints', doc, None, iint('dim'), iint('tag'), ivectordouble('parametricCoord'), ivectordouble('sizes'))

doc = '''Set a mesh size callback for the current model. The callback function should take six arguments as input (`dim', `tag', `x', `y', `z' and `lc'). The first two integer arguments correspond to the dimension `dim' and tag `tag' of the entity being meshed. The next four double precision arguments correspond to the coordinates `x', `y' and `z' around which to prescribe the mesh size and to the mesh size `lc' that would be prescribed if the callback had not been called. The callback function should return a double precision number specifying the desired mesh size; returning `lc' is equivalent to a no-op.'''
mesh.add('setSizeCallback', doc, None, isizefun('callback'))

doc = '''Remove the mesh size callback from the current model.'''
mesh.add('removeSizeCallback', doc, None)

doc = '''Set a transfinite meshing constraint on the curve `tag', with `numNodes' nodes distributed according to `meshType' and `coef'. Currently supported types are "Progression" (geometrical progression with power `coef'), "Bump" (refinement toward both extremities of the curve) and "Beta" (beta law).'''
mesh.add('setTransfiniteCurve', doc, None, iint('tag'), iint('numNodes'), istring('meshType', '"Progression"'), idouble('coef', '1.'))

doc = '''Set a transfinite meshing constraint on the surface `tag'. `arrangement' describes the arrangement of the triangles when the surface is not flagged as recombined: currently supported values are "Left", "Right", "AlternateLeft" and "AlternateRight". `cornerTags' can be used to specify the (3 or 4) corners of the transfinite interpolation explicitly; specifying the corners explicitly is mandatory if the surface has more that 3 or 4 points on its boundary.'''
mesh.add('setTransfiniteSurface', doc, None, iint('tag'), istring('arrangement', '"Left"'), ivectorint('cornerTags', 'std::vector<int>()', '[]', '[]'))

doc = '''Set a transfinite meshing constraint on the surface `tag'. `cornerTags' can be used to specify the (6 or 8) corners of the transfinite interpolation explicitly.'''
mesh.add('setTransfiniteVolume', doc, None, iint('tag'), ivectorint('cornerTags', 'std::vector<int>()', '[]', '[]'))

doc = '''Set transfinite meshing constraints on the model entities in `dimTags', given as a vector of (dim, tag) pairs. Transfinite meshing constraints are added to the curves of the quadrangular surfaces and to the faces of 6-sided volumes. Quadragular faces with a corner angle superior to `cornerAngle' (in radians) are ignored. The number of points is automatically determined from the sizing constraints. If `dimTag' is empty, the constraints are applied to all entities in the model. If `recombine' is true, the recombine flag is automatically set on the transfinite surfaces.  '''
mesh.add('setTransfiniteAutomatic', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'), idouble('cornerAngle', '2.35', '2.35', '2.35'), ibool('recombine', 'true', 'True'))

doc = '''Set a recombination meshing constraint on the model entity of dimension `dim' and tag `tag'. Currently only entities of dimension 2 (to recombine triangles into quadrangles) are supported; `angle' specifies the threshold angle for the simple recombination algorithm..'''
mesh.add('setRecombine', doc, None, iint('dim'), iint('tag'), idouble('angle', '45.'))

doc = '''Set a smoothing meshing constraint on the model entity of dimension `dim' and tag `tag'. `val' iterations of a Laplace smoother are applied.'''
mesh.add('setSmoothing', doc, None, iint('dim'), iint('tag'), iint('val'))

doc = '''Set a reverse meshing constraint on the model entity of dimension `dim' and tag `tag'. If `val' is true, the mesh orientation will be reversed with respect to the natural mesh orientation (i.e. the orientation consistent with the orientation of the geometry). If `val' is false, the mesh is left as-is.'''
mesh.add('setReverse', doc, None, iint('dim'), iint('tag'), ibool('val', 'true', 'True'))

doc = '''Set the meshing algorithm on the model entity of dimension `dim' and tag `tag'. Supported values are those of the `Mesh.Algorithm' option, as listed in the Gmsh reference manual. Currently only supported for `dim' == 2.'''
mesh.add('setAlgorithm', doc, None, iint('dim'), iint('tag'), iint('val'))

doc = '''Force the mesh size to be extended from the boundary, or not, for the model entity of dimension `dim' and tag `tag'. Currently only supported for `dim' == 2.'''
mesh.add('setSizeFromBoundary', doc, None, iint('dim'), iint('tag'), iint('val'))

doc = '''Set a compound meshing constraint on the model entities of dimension `dim' and tags `tags'. During meshing, compound entities are treated as a single discrete entity, which is automatically reparametrized.'''
mesh.add('setCompound', doc, None, iint('dim'), ivectorint('tags'))

doc = '''Set meshing constraints on the bounding surfaces of the volume of tag `tag' so that all surfaces are oriented with outward pointing normals; and if a mesh already exists, reorient it. Currently only available with the OpenCASCADE kernel, as it relies on the STL triangulation.'''
mesh.add('setOutwardOrientation', doc, None, iint('tag'))

doc = '''Remove all meshing constraints from the model entities `dimTags', given as a vector of (dim, tag) pairs. If `dimTags' is empty, remove all constraings.'''
mesh.add('removeConstraints', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Embed the model entities of dimension `dim' and tags `tags' in the (`inDim', `inTag') model entity. The dimension `dim' can 0, 1 or 2 and must be strictly smaller than `inDim', which must be either 2 or 3. The embedded entities should not intersect each other or be part of the boundary of the entity `inTag', whose mesh will conform to the mesh of the embedded entities. With the OpenCASCADE kernel, if the `fragment' operation is applied to entities of different dimensions, the lower dimensional entities will be automatically embedded in the higher dimensional entities if they are not on their boundary.'''
mesh.add('embed', doc, None, iint('dim'), ivectorint('tags'), iint('inDim'), iint('inTag'))

doc = '''Remove embedded entities from the model entities `dimTags', given as a vector of (dim, tag) pairs. if `dim' is >= 0, only remove embedded entities of the given dimension (e.g. embedded points if `dim' == 0).'''
mesh.add('removeEmbedded', doc, None, ivectorpair('dimTags'), iint('dim', '-1'))

doc = '''Get the entities (if any) embedded in the model entity of dimension `dim' and tag `tag'.'''
mesh.add('getEmbedded', doc, None, iint('dim'), iint('tag'), ovectorpair('dimTags'))

doc = '''Reorder the elements of type `elementType' classified on the entity of tag `tag' according to the `ordering' vector.'''
mesh.add('reorderElements', doc, None, iint('elementType'), iint('tag'), ivectorsize('ordering'))

doc = '''Compute a renumbering vector `newTags' corresponding to the input tags `oldTags' for a given list of element tags `elementTags'. If `elementTags' is empty, compute the renumbering on the full mesh. If `method' is equal to "RCMK", compute a node renumering with Reverse Cuthill McKee. If `method' is equal to "Hilbert", compute a node renumering along a Hilbert curve. If `method' is equal to "Metis", compute a node renumering using Metis. Element renumbering is not available yet.'''
mesh.add('computeRenumbering', doc, None, ovectorsize('oldTags'), ovectorsize('newTags'), istring('method', '"RCMK"'), ivectorsize('elementTags', 'std::vector<std::size_t>()', '[]', '[]'))

doc = '''Renumber the node tags. If no explicit renumbering is provided through the `oldTags' and `newTags' vectors, renumber the nodes in a continuous sequence, taking into account the subset of elements to be saved later on if the option "Mesh.SaveAll" is not set.'''
mesh.add('renumberNodes', doc, None, ivectorsize('oldTags', 'std::vector<std::size_t>()', '[]', '[]'), ivectorsize('newTags', 'std::vector<std::size_t>()', '[]', '[]'))

doc = '''Renumber the element tags in a continuous sequence. If no explicit renumbering is provided through the `oldTags' and `newTags' vectors, renumber the elements in a continuous sequence, taking into account the subset of elements to be saved later on if the option "Mesh.SaveAll" is not set.'''
mesh.add('renumberElements', doc, None, ivectorsize('oldTags', 'std::vector<std::size_t>()', '[]', '[]'), ivectorsize('newTags', 'std::vector<std::size_t>()', '[]', '[]'))

doc = '''Set the meshes of the entities of dimension `dim' and tag `tags' as periodic copies of the meshes of entities `tagsMaster', using the affine transformation specified in `affineTransformation' (16 entries of a 4x4 matrix, by row). If used after meshing, generate the periodic node correspondence information assuming the meshes of entities `tags' effectively match the meshes of entities `tagsMaster' (useful for structured and extruded meshes). Currently only available for @code{dim} == 1 and @code{dim} == 2.'''
mesh.add('setPeriodic', doc, None, iint('dim'), ivectorint('tags'), ivectorint('tagsMaster'), ivectordouble('affineTransform'))

doc = '''Get master entities `tagsMaster' for the entities of dimension `dim' and tags `tags'.'''
mesh.add('getPeriodic', doc, None, iint('dim'), ivectorint('tags'), ovectorint('tagMaster'))

doc = '''Get the master entity `tagMaster', the node tags `nodeTags' and their corresponding master node tags `nodeTagsMaster', and the affine transform `affineTransform' for the entity of dimension `dim' and tag `tag'. If `includeHighOrderNodes' is set, include high-order nodes in the returned data.'''
mesh.add('getPeriodicNodes', doc, None, iint('dim'), iint('tag'), oint('tagMaster'), ovectorsize('nodeTags'), ovectorsize('nodeTagsMaster'), ovectordouble('affineTransform'), ibool('includeHighOrderNodes', 'false', 'False'))

doc = '''Get the master entity `tagMaster' and the key pairs (`typeKeyMaster', `entityKeyMaster') corresponding to the entity `tag' and the key pairs (`typeKey', `entityKey') for the elements of type `elementType' and function space type `functionSpaceType'. If `returnCoord' is set, the `coord' and `coordMaster' vectors contain the x, y, z coordinates locating basis functions for sorting purposes.'''
mesh.add('getPeriodicKeys', doc, None, iint('elementType'), istring('functionSpaceType'), iint('tag'), oint('tagMaster'), ovectorint('typeKeys'), ovectorint('typeKeysMaster'), ovectorsize('entityKeys'), ovectorsize('entityKeysMaster'), ovectordouble('coord'), ovectordouble('coordMaster'), ibool('returnCoord', 'true', 'True'))

doc = '''Import the model STL representation (if available) as the current mesh.'''
mesh.add('importStl', doc, None)

doc = '''Get the `tags' of any duplicate nodes in the mesh of the entities `dimTags', given as a vector of (dim, tag) pairs. If `dimTags' is empty, consider the whole mesh.'''
mesh.add('getDuplicateNodes', doc, None, ovectorsize('tags'), ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Remove duplicate nodes in the mesh of the entities `dimTags', given as a vector of (dim, tag) pairs. If `dimTags' is empty, consider the whole mesh.'''
mesh.add('removeDuplicateNodes', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Remove duplicate elements (defined by the same nodes, in the same entity) in the mesh of the entities `dimTags', given as a vector of (dim, tag) pairs. If `dimTags' is empty, consider the whole mesh.'''
mesh.add('removeDuplicateElements', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Split (into two triangles) all quadrangles in surface `tag' whose quality is lower than `quality'. If `tag' < 0, split quadrangles in all surfaces.'''
mesh.add('splitQuadrangles', doc, None, idouble('quality', '1.'), iint('tag', '-1'))

doc = '''Set the visibility of the elements of tags `elementTags' to `value'.'''
mesh.add('setVisibility', doc, None, ivectorsize('elementTags'), iint('value'))

doc = '''Get the visibility of the elements of tags `elementTags'.'''
mesh.add('getVisibility', doc, None, ivectorsize('elementTags'), ovectorint('values'))

doc = '''Classify ("color") the surface mesh based on the angle threshold `angle' (in radians), and create new discrete surfaces, curves and points accordingly. If `boundary' is set, also create discrete curves on the boundary if the surface is open. If `forReparametrization' is set, create curves and surfaces that can be reparametrized using a single map. If `curveAngle' is less than Pi, also force curves to be split according to `curveAngle'. If `exportDiscrete' is set, clear any built-in CAD kernel entities and export the discrete entities in the built-in CAD kernel.'''
mesh.add('classifySurfaces', doc, None, idouble('angle'), ibool('boundary', 'true', 'True'), ibool('forReparametrization', 'false', 'False'), idouble('curveAngle', 'M_PI', 'pi', 'pi'), ibool('exportDiscrete', 'true', 'True'))

doc = '''Create a geometry for the discrete entities `dimTags' (given as a vector of (dim, tag) pairs) represented solely by a mesh (without an underlying CAD description), i.e. create a parametrization for discrete curves and surfaces, assuming that each can be parametrized with a single map. If `dimTags' is empty, create a geometry for all the discrete entities.'''
mesh.add('createGeometry', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Create a boundary representation from the mesh if the model does not have one (e.g. when imported from mesh file formats with no BRep representation of the underlying model). If `makeSimplyConnected' is set, enforce simply connected discrete surfaces and volumes. If `exportDiscrete' is set, clear any built-in CAD kernel entities and export the discrete entities in the built-in CAD kernel.'''
mesh.add('createTopology', doc, None, ibool('makeSimplyConnected', 'true', 'True'), ibool('exportDiscrete', 'true', 'True'))

doc = '''Add a request to compute a basis representation for homology spaces (if `type' == "Homology") or cohomology spaces (if `type' == "Cohomology"). The computation domain is given in a list of physical group tags `domainTags'; if empty, the whole mesh is the domain. The computation subdomain for relative (co)homology computation is given in a list of physical group tags `subdomainTags'; if empty, absolute (co)homology is computed. The dimensions of the (co)homology bases to be computed are given in the list `dim'; if empty, all bases are computed. Resulting basis representation (co)chains are stored as physical groups in the mesh. If the request is added before mesh generation, the computation will be performed at the end of the meshing pipeline.'''
mesh.add('addHomologyRequest', doc, None, istring('type', '"Homology"'), ivectorint('domainTags', 'std::vector<int>()', '[]', '[]'), ivectorint('subdomainTags', 'std::vector<int>()', '[]', '[]'), ivectorint('dims', 'std::vector<int>()', '[]', '[]'))

doc = '''Clear all (co)homology computation requests.'''
mesh.add('clearHomologyRequests', doc, None)

doc = '''Perform the (co)homology computations requested by addHomologyRequest(). The newly created physical groups are returned in `dimTags' as a vector of (dim, tag) pairs.'''
mesh.add('computeHomology', doc, None, ovectorpair('dimTags'))

doc = '''Compute a cross field for the current mesh. The function creates 3 views: the H function, the Theta function and cross directions. Return the tags of the views.'''
mesh.add('computeCrossField', doc, None, ovectorint('viewTags'))

doc = '''Triangulate the points given in the `coord' vector as pairs of u, v coordinates, and return the node tags (with numbering starting at 1) of the resulting triangles in `tri'.'''
mesh.add('triangulate', doc, None, ivectordouble('coord'), ovectorsize('tri'))

doc = '''Tetrahedralize the points given in the `coord' vector as x, y, z coordinates, concatenated, and return the node tags (with numbering starting at 1) of the resulting tetrahedra in `tetra'.'''
mesh.add('tetrahedralize', doc, None, ivectordouble('coord'), ovectorsize('tetra'))

################################################################################

field = mesh.add_module('field', 'mesh size field functions')

doc = '''Add a new mesh size field of type `fieldType'. If `tag' is positive, assign the tag explicitly; otherwise a new tag is assigned automatically. Return the field tag. Available field types are listed in the "Gmsh mesh size fields" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-mesh-size-fields).'''
field.add('add', doc, oint, istring('fieldType'), iint('tag', '-1'))

doc = '''Remove the field with tag `tag'.'''
field.add('remove', doc, None, iint('tag'))

doc = '''Get the list of all fields.'''
field.add('list', doc, None, ovectorint('tags'))

doc = '''Get the type `fieldType' of the field with tag `tag'.'''
field.add('getType', doc, None, iint('tag'), ostring('fileType'))

doc = '''Set the numerical option `option' to value `value' for field `tag'.'''
field.add('setNumber', doc, None, iint('tag'), istring('option'), idouble('value'))

doc = '''Get the value of the numerical option `option' for field `tag'.'''
field.add('getNumber', doc, None, iint('tag'), istring('option'), odouble('value'))

doc = '''Set the string option `option' to value `value' for field `tag'.'''
field.add('setString', doc, None, iint('tag'), istring('option'), istring('value'))

doc = '''Get the value of the string option `option' for field `tag'.'''
field.add('getString', doc, None, iint('tag'), istring('option'), ostring('value'))

doc = '''Set the numerical list option `option' to value `values' for field `tag'.'''
field.add('setNumbers', doc, None, iint('tag'), istring('option'), ivectordouble('values'))

doc = '''Get the value of the numerical list option `option' for field `tag'.'''
field.add('getNumbers', doc, None, iint('tag'), istring('option'), ovectordouble('values'))

doc = '''Set the field `tag' as the background mesh size field.'''
field.add('setAsBackgroundMesh', doc, None, iint('tag'))

doc = '''Set the field `tag' as a boundary layer size field.'''
field.add('setAsBoundaryLayer', doc, None, iint('tag'))

################################################################################

geo = model.add_module('geo', 'built-in CAD kernel functions')

doc = '''Add a geometrical point in the built-in CAD representation, at coordinates (`x', `y', `z'). If `meshSize' is > 0, add a meshing constraint at that point. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the point. (Note that the point will be added in the current model only after `synchronize' is called. This behavior holds for all the entities added in the geo module.)'''
geo.add('addPoint', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('meshSize', '0.'), iint('tag', '-1'))

doc = '''Add a straight line segment in the built-in CAD representation, between the two points with tags `startTag' and `endTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the line.'''
geo.add('addLine', doc, oint, iint('startTag'), iint('endTag'), iint('tag', '-1'))

doc = '''Add a circle arc (strictly smaller than Pi) in the built-in CAD representation, between the two points with tags `startTag' and `endTag', and with center `centerTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If (`nx', `ny', `nz') != (0, 0, 0), explicitly set the plane of the circle arc. Return the tag of the circle arc.'''
geo.add('addCircleArc', doc, oint, iint('startTag'), iint('centerTag'), iint('endTag'), iint('tag', '-1'), idouble('nx', '0.'), idouble('ny', '0.'), idouble('nz', '0.'))

doc = '''Add an ellipse arc (strictly smaller than Pi) in the built-in CAD representation, between the two points `startTag' and `endTag', and with center `centerTag' and major axis point `majorTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If (`nx', `ny', `nz') != (0, 0, 0), explicitly set the plane of the circle arc. Return the tag of the ellipse arc.'''
geo.add('addEllipseArc', doc, oint, iint('startTag'), iint('centerTag'), iint('majorTag'), iint('endTag'), iint('tag', '-1'), idouble('nx', '0.'), idouble('ny', '0.'), idouble('nz', '0.'))

doc = '''Add a spline (Catmull-Rom) curve in the built-in CAD representation, going through the points `pointTags'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Create a periodic curve if the first and last points are the same. Return the tag of the spline curve.'''
geo.add('addSpline', doc, oint, ivectorint('pointTags'), iint('tag', '-1'))

doc = '''Add a cubic b-spline curve in the built-in CAD representation, with `pointTags' control points. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Creates a periodic curve if the first and last points are the same. Return the tag of the b-spline curve.'''
geo.add('addBSpline', doc, oint, ivectorint('pointTags'), iint('tag', '-1'))

doc = '''Add a Bezier curve in the built-in CAD representation, with `pointTags' control points. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically.  Return the tag of the Bezier curve.'''
geo.add('addBezier', doc, oint, ivectorint('pointTags'), iint('tag', '-1'))

doc = '''Add a polyline curve in the built-in CAD representation, going through the points `pointTags'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Create a periodic curve if the first and last points are the same. Return the tag of the polyline curve.'''
geo.add('addPolyline', doc, oint, ivectorint('pointTags'), iint('tag', '-1'))

doc = '''Add a spline (Catmull-Rom) curve in the built-in CAD representation, going through points sampling the curves in `curveTags'. The density of sampling points on each curve is governed by `numIntervals'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the spline.'''
geo.add('addCompoundSpline', doc, oint, ivectorint('curveTags'), iint('numIntervals', '5'), iint('tag', '-1'))

doc = '''Add a b-spline curve in the built-in CAD representation, with control points sampling the curves in `curveTags'. The density of sampling points on each curve is governed by `numIntervals'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the b-spline.'''
geo.add('addCompoundBSpline', doc, oint, ivectorint('curveTags'), iint('numIntervals', '20'), iint('tag', '-1'))

doc = '''Add a curve loop (a closed wire) in the built-in CAD representation, formed by the curves `curveTags'. `curveTags' should contain (signed) tags of model entities of dimension 1 forming a closed loop: a negative tag signifies that the underlying curve is considered with reversed orientation. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If `reorient' is set, automatically reorient the curves if necessary. Return the tag of the curve loop.'''
geo.add('addCurveLoop', doc, oint, ivectorint('curveTags'), iint('tag', '-1'), ibool('reorient', 'false', 'False'))

doc = '''Add curve loops in the built-in CAD representation based on the curves `curveTags'. Return the `tags' of found curve loops, if any.'''
geo.add('addCurveLoops', doc, None, ivectorint('curveTags'), ovectorint('tags'))

doc = '''Add a plane surface in the built-in CAD representation, defined by one or more curve loops `wireTags'. The first curve loop defines the exterior contour; additional curve loop define holes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface.'''
geo.add('addPlaneSurface', doc, oint, ivectorint('wireTags'), iint('tag', '-1'))

doc = '''Add a surface in the built-in CAD representation, filling the curve loops in `wireTags' using transfinite interpolation. Currently only a single curve loop is supported; this curve loop should be composed by 3 or 4 curves only. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface.'''
geo.add('addSurfaceFilling', doc, oint, ivectorint('wireTags'), iint('tag', '-1'), iint('sphereCenterTag', '-1'))

doc = '''Add a surface loop (a closed shell) formed by `surfaceTags' in the built-in CAD representation.  If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the shell.'''
geo.add('addSurfaceLoop', doc, oint, ivectorint('surfaceTags'), iint('tag', '-1'))

doc = '''Add a volume (a region) in the built-in CAD representation, defined by one or more shells `shellTags'. The first surface loop defines the exterior boundary; additional surface loop define holes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the volume.'''
geo.add('addVolume', doc, oint, ivectorint('shellTags'), iint('tag', '-1'))

doc = '''Add a `geometry' in the built-in CAD representation. `geometry' can currently be one of "Sphere" or "PolarSphere" (where `numbers' should contain the x, y, z coordinates of the center, followed by the radius), or "Parametric" (where `strings' should contains three expression evaluating to the x, y and z coordinates. If `tag' is positive, set the tag of the geometry explicitly; otherwise a new tag is selected automatically. Return the tag of the geometry.'''
geo.add('addGeometry', doc, oint, istring('geometry'), ivectordouble('numbers', 'std::vector<double>()', '[]', '[]'), ivectorstring('strings', 'std::vector<std::string>()', '[]', '[]'), iint('tag', '-1'))

doc = '''Add a point in the built-in CAD representation, at coordinates (`x', `y', `z') on the geometry `geometryTag'. If `meshSize' is > 0, add a meshing constraint at that point. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the point. For surface geometries, only the `x' and `y' coordinates are used.'''
geo.add('addPointOnGeometry', doc, oint, iint('geometryTag'), idouble('x'), idouble('y'), idouble('z', '0.'), idouble('meshSize', '0.'), iint('tag', '-1'))

doc = '''Extrude the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation, using a translation along (`dx', `dy', `dz'). Return extruded entities in `outDimTags'. If the `numElements' vector is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If the `height' vector is not empty, it provides the (cumulative) height of the different layers, normalized to 1. If `recombine' is set, recombine the mesh in the layers.'''
geo.add('extrude', doc, None, ivectorpair('dimTags'), idouble('dx'), idouble('dy'), idouble('dz'), ovectorpair('outDimTags'), ivectorint('numElements', 'std::vector<int>()', '[]', '[]'), ivectordouble('heights', 'std::vector<double>()', '[]', '[]'), ibool('recombine', 'false', 'False'))

doc = '''Extrude the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation, using a rotation of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az'). The angle should be strictly smaller than Pi. Return extruded entities in `outDimTags'. If the `numElements' vector is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If the `height' vector is not empty, it provides the (cumulative) height of the different layers, normalized to 1. If `recombine' is set, recombine the mesh in the layers.'''
geo.add('revolve', doc, None, ivectorpair('dimTags'), idouble('x'), idouble('y'), idouble('z'), idouble('ax'), idouble('ay'), idouble('az'), idouble('angle'), ovectorpair('outDimTags'), ivectorint('numElements', 'std::vector<int>()', '[]', '[]'), ivectordouble('heights', 'std::vector<double>()', '[]', '[]'), ibool('recombine', 'false', 'False'))

doc = '''Extrude the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation, using a combined translation and rotation of `angle' radians, along (`dx', `dy', `dz') and around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az'). The angle should be strictly smaller than Pi. Return extruded entities in `outDimTags'. If the `numElements' vector is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If the `height' vector is not empty, it provides the (cumulative) height of the different layers, normalized to 1. If `recombine' is set, recombine the mesh in the layers.'''
geo.add('twist', doc, None, ivectorpair('dimTags'), idouble('x'), idouble('y'), idouble('z'), idouble('dx'), idouble('dy'), idouble('dz'), idouble('ax'), idouble('ay'), idouble('az'), idouble('angle'), ovectorpair('outDimTags'), ivectorint('numElements', 'std::vector<int>()', '[]', '[]'), ivectordouble('heights', 'std::vector<double>()', '[]', '[]'), ibool('recombine', 'false', 'False'))

doc = '''Extrude the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation along the normals of the mesh, creating discrete boundary layer entities. Return extruded entities in `outDimTags'. The entries in `numElements' give the number of elements in each layer. If the `height' vector is not empty, it provides the (cumulative) height of the different layers. If `recombine' is set, recombine the mesh in the layers. A second boundary layer can be created from the same entities if `second' is set. If `viewIndex' is >= 0, use the corresponding view to either specify the normals (if the view contains a vector field) or scale the normals (if the view is scalar).'''
geo.add('extrudeBoundaryLayer', doc, None, ivectorpair('dimTags'), ovectorpair('outDimTags'), ivectorint('numElements', 'std::vector<int>(1, 1)', "[1]", "[1]"), ivectordouble('heights', 'std::vector<double>()', '[]', '[]'), ibool('recombine', 'false', 'False'), ibool('second', 'false', 'False'), iint('viewIndex', '-1'))

doc = '''Translate the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation along (`dx', `dy', `dz').'''
geo.add('translate', doc, None, ivectorpair('dimTags'), idouble('dx'), idouble('dy'), idouble('dz'))

doc = '''Rotate the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation by `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az').'''
geo.add('rotate', doc, None, ivectorpair('dimTags'), idouble('x'), idouble('y'), idouble('z'), idouble('ax'), idouble('ay'), idouble('az'), idouble('angle'))

doc = '''Scale the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation by factors `a', `b' and `c' along the three coordinate axes; use (`x', `y', `z') as the center of the homothetic transformation.'''
geo.add('dilate', doc, None, ivectorpair('dimTags'), idouble('x'), idouble('y'), idouble('z'), idouble('a'), idouble('b'), idouble('c'))

doc = '''Mirror the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation, with respect to the plane of equation `a' * x + `b' * y + `c' * z + `d' = 0.'''
geo.add('mirror', doc, None, ivectorpair('dimTags'), idouble('a'), idouble('b'), idouble('c'), idouble('d'))
doc += ''' (This is a synonym for `mirror', which will be deprecated in a future release.)'''
geo.add('symmetrize', doc, None, ivectorpair('dimTags'), idouble('a'), idouble('b'), idouble('c'), idouble('d'))

doc = '''Copy the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation; the new entities are returned in `outDimTags'.'''
geo.add('copy', doc, None, ivectorpair('dimTags'), ovectorpair('outDimTags'))

doc = '''Remove the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD representation, provided that they are not on the boundary of higher-dimensional entities. If `recursive' is true, remove all the entities on their boundaries, down to dimension 0.'''
geo.add('remove', doc, None, ivectorpair('dimTags'), ibool('recursive', 'false', 'False'))

doc = '''Remove all duplicate entities in the built-in CAD representation (different entities at the same geometrical location).'''
geo.add('removeAllDuplicates', doc, None)

doc = '''Split the curve of tag `tag' in the built-in CAD representation, on the specified control points `pointTags'. This feature is only available for lines, splines and b-splines. Return the tag(s) `curveTags' of the newly created curve(s).'''
geo.add('splitCurve', doc, None, iint('tag'), ivectorint('pointTags'), ovectorint('curveTags'))

doc = '''Get the maximum tag of entities of dimension `dim' in the built-in CAD representation.'''
geo.add('getMaxTag', doc, oint, iint('dim'))

doc = '''Set the maximum tag `maxTag' for entities of dimension `dim' in the built-in CAD representation.'''
geo.add('setMaxTag', doc, None, iint('dim'), iint('maxTag'))

doc = '''Add a physical group of dimension `dim', grouping the entities with tags `tags' in the built-in CAD representation. Return the tag of the physical group, equal to `tag' if `tag' is positive, or a new tag if `tag' < 0. Set the name of the physical group if `name' is not empty.'''
geo.add('addPhysicalGroup', doc, oint, iint('dim'), ivectorint('tags'), iint('tag', '-1'), istring('name', '""'))

doc = '''Remove the physical groups `dimTags' (given as a vector of (dim, tag) pairs) from the built-in CAD representation. If `dimTags' is empty, remove all groups.'''
geo.add('removePhysicalGroups', doc, None, ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'))

doc = '''Synchronize the built-in CAD representation with the current Gmsh model. This can be called at any time, but since it involves a non trivial amount of processing, the number of synchronization points should normally be minimized. Without synchronization the entities in the built-in CAD representation are not available to any function outside of the built-in CAD kernel functions.'''
geo.add('synchronize', doc, None)

################################################################################

mesh = geo.add_module('mesh', 'built-in CAD kernel meshing constraints')

doc = '''Set a mesh size constraint on the entities `dimTags' (given as a vector of (dim, tag) pairs) in the built-in CAD kernel representation. Currently only entities of dimension 0 (points) are handled.'''
mesh.add('setSize', doc, None, ivectorpair('dimTags'), idouble('size'))

doc = '''Set a transfinite meshing constraint on the curve `tag' in the built-in CAD kernel representation, with `numNodes' nodes distributed according to `meshType' and `coef'. Currently supported types are "Progression" (geometrical progression with power `coef') and "Bump" (refinement toward both extremities of the curve).'''
mesh.add('setTransfiniteCurve', doc, None, iint('tag'), iint('nPoints'), istring('meshType', '"Progression"'), idouble('coef', '1.'))

doc = '''Set a transfinite meshing constraint on the surface `tag' in the built-in CAD kernel representation. `arrangement' describes the arrangement of the triangles when the surface is not flagged as recombined: currently supported values are "Left", "Right", "AlternateLeft" and "AlternateRight". `cornerTags' can be used to specify the (3 or 4) corners of the transfinite interpolation explicitly; specifying the corners explicitly is mandatory if the surface has more that 3 or 4 points on its boundary.'''
mesh.add('setTransfiniteSurface', doc, None, iint('tag'), istring('arrangement', '"Left"'), ivectorint('cornerTags', 'std::vector<int>()', '[]', '[]'))

doc = '''Set a transfinite meshing constraint on the surface `tag' in the built-in CAD kernel representation. `cornerTags' can be used to specify the (6 or 8) corners of the transfinite interpolation explicitly.'''
mesh.add('setTransfiniteVolume', doc, None, iint('tag'), ivectorint('cornerTags', 'std::vector<int>()', '[]', '[]'))

doc = '''Set a recombination meshing constraint on the entity of dimension `dim' and tag `tag' in the built-in CAD kernel representation. Currently only entities of dimension 2 (to recombine triangles into quadrangles) are supported; `angle' specifies the threshold angle for the simple recombination algorithm.'''
mesh.add('setRecombine', doc, None, iint('dim'), iint('tag'), idouble('angle', '45.'))

doc = '''Set a smoothing meshing constraint on the entity of dimension `dim' and tag `tag' in the built-in CAD kernel representation. `val' iterations of a Laplace smoother are applied.'''
mesh.add('setSmoothing', doc, None, iint('dim'), iint('tag'), iint('val'))

doc = '''Set a reverse meshing constraint on the entity of dimension `dim' and tag `tag' in the built-in CAD kernel representation. If `val' is true, the mesh orientation will be reversed with respect to the natural mesh orientation (i.e. the orientation consistent with the orientation of the geometry). If `val' is false, the mesh is left as-is.'''
mesh.add('setReverse', doc, None, iint('dim'), iint('tag'), ibool('val', 'true', 'True'))

doc = '''Set the meshing algorithm on the entity of dimension `dim' and tag `tag' in the built-in CAD kernel representation. Currently only supported for `dim' == 2.'''
mesh.add('setAlgorithm', doc, None, iint('dim'), iint('tag'), iint('val'))

doc = '''Force the mesh size to be extended from the boundary, or not, for the entity of dimension `dim' and tag `tag' in the built-in CAD kernel representation. Currently only supported for `dim' == 2.'''
mesh.add('setSizeFromBoundary', doc, None, iint('dim'), iint('tag'), iint('val'))

################################################################################

occ = model.add_module('occ', 'OpenCASCADE CAD kernel functions')

doc = '''Add a geometrical point in the OpenCASCADE CAD representation, at coordinates (`x', `y', `z'). If `meshSize' is > 0, add a meshing constraint at that point. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the point. (Note that the point will be added in the current model only after `synchronize' is called. This behavior holds for all the entities added in the occ module.)'''
occ.add('addPoint', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('meshSize', '0.'), iint('tag', '-1'))

doc = '''Add a straight line segment in the OpenCASCADE CAD representation, between the two points with tags `startTag' and `endTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the line.'''
occ.add('addLine', doc, oint, iint('startTag'), iint('endTag'), iint('tag', '-1'))

doc = '''Add a circle arc in the OpenCASCADE CAD representation, between the two points with tags `startTag' and `endTag', with middle point `middleTag'. If `center' is true, the middle point is the center of the circle; otherwise the circle goes through the middle point. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the circle arc.'''
occ.add('addCircleArc', doc, oint, iint('startTag'), iint('middleTag'), iint('endTag'), iint('tag', '-1'), ibool('center', 'true', 'True'))

doc = '''Add a circle of center (`x', `y', `z') and radius `r' in the OpenCASCADE CAD representation. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If `angle1' and `angle2' are specified, create a circle arc between the two angles. If a vector `zAxis' of size 3 is provided, use it as the normal to the circle plane (z-axis). If a vector `xAxis' of size 3 is provided in addition to `zAxis', use it to define the x-axis. Return the tag of the circle.'''
occ.add('addCircle', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('r'), iint('tag', '-1'), idouble('angle1', '0.'), idouble('angle2', '2*M_PI', '2*pi', '2*pi'), ivectordouble('zAxis', 'std::vector<double>()', '[]', '[]'), ivectordouble('xAxis', 'std::vector<double>()', '[]', '[]'))

doc = '''Add an ellipse arc in the OpenCASCADE CAD representation, between the two points `startTag' and `endTag', and with center `centerTag' and major axis point `majorTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the ellipse arc. Note that OpenCASCADE does not allow creating ellipse arcs with the major radius smaller than the minor radius.'''
occ.add('addEllipseArc', doc, oint, iint('startTag'), iint('centerTag'), iint('majorTag'), iint('endTag'), iint('tag', '-1'))

doc = '''Add an ellipse of center (`x', `y', `z') and radii `r1' and `r2' (with `r1' >= `r2') along the x- and y-axes, respectively, in the OpenCASCADE CAD representation. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If `angle1' and `angle2' are specified, create an ellipse arc between the two angles. If a vector `zAxis' of size 3 is provided, use it as the normal to the ellipse plane (z-axis). If a vector `xAxis' of size 3 is provided in addition to `zAxis', use it to define the x-axis. Return the tag of the ellipse.'''
occ.add('addEllipse', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('r1'), idouble('r2'), iint('tag', '-1'), idouble('angle1', '0.'), idouble('angle2', '2*M_PI', '2*pi', '2*pi'), ivectordouble('zAxis', 'std::vector<double>()', '[]', '[]'), ivectordouble('xAxis', 'std::vector<double>()', '[]', '[]'))

doc = '''Add a spline (C2 b-spline) curve in the OpenCASCADE CAD representation, going through the points `pointTags'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Create a periodic curve if the first and last points are the same. Return the tag of the spline curve. If the `tangents' vector contains 6 entries, use them as concatenated x, y, z components of the initial and final tangents of the b-spline; if it contains 3 times as many entries as the number of points, use them as concatenated x, y, z components of the tangents at each point, unless the norm of the tangent is zero.'''
occ.add('addSpline', doc, oint, ivectorint('pointTags'), iint('tag', '-1'), ivectordouble('tangents', 'std::vector<double>()', '[]', '[]'))

doc = '''Add a b-spline curve of degree `degree' in the OpenCASCADE CAD representation, with `pointTags' control points. If `weights', `knots' or `multiplicities' are not provided, default parameters are computed automatically. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Create a periodic curve if the first and last points are the same. Return the tag of the b-spline curve.'''
occ.add('addBSpline', doc, oint, ivectorint('pointTags'), iint('tag', '-1'), iint('degree', '3'), ivectordouble('weights', 'std::vector<double>()', '[]', '[]'), ivectordouble('knots', 'std::vector<double>()', '[]', '[]'), ivectorint('multiplicities', 'std::vector<int>()', '[]', '[]'))

doc = '''Add a Bezier curve in the OpenCASCADE CAD representation, with `pointTags' control points. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the Bezier curve.'''
occ.add('addBezier', doc, oint, ivectorint('pointTags'), iint('tag', '-1'))

doc = '''Add a wire (open or closed) in the OpenCASCADE CAD representation, formed by the curves `curveTags'. Note that an OpenCASCADE wire can be made of curves that share geometrically identical (but topologically different) points. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the wire.'''
occ.add('addWire', doc, oint, ivectorint('curveTags'), iint('tag', '-1'), ibool('checkClosed', 'false', 'False'))

doc = '''Add a curve loop (a closed wire) in the OpenCASCADE CAD representation, formed by the curves `curveTags'. `curveTags' should contain tags of curves forming a closed loop. Negative tags can be specified for compatibility with the built-in kernel, but are simply ignored: the wire is oriented according to the orientation of its first curve. Note that an OpenCASCADE curve loop can be made of curves that share geometrically identical (but topologically different) points. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the curve loop.'''
occ.add('addCurveLoop', doc, oint, ivectorint('curveTags'), iint('tag', '-1'))

doc = '''Add a rectangle in the OpenCASCADE CAD representation, with lower left corner at (`x', `y', `z') and upper right corner at (`x' + `dx', `y' + `dy', `z'). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Round the corners if `roundedRadius' is nonzero. Return the tag of the rectangle.'''
occ.add('addRectangle', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('dx'), idouble('dy'), iint('tag', '-1'), idouble('roundedRadius', '0.'))

doc = '''Add a disk in the OpenCASCADE CAD representation, with center (`xc', `yc', `zc') and radius `rx' along the x-axis and `ry' along the y-axis (`rx' >= `ry'). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If a vector `zAxis' of size 3 is provided, use it as the normal to the disk (z-axis). If a vector `xAxis' of size 3 is provided in addition to `zAxis', use it to define the x-axis. Return the tag of the disk.'''
occ.add('addDisk', doc, oint, idouble('xc'), idouble('yc'), idouble('zc'), idouble('rx'), idouble('ry'), iint('tag', '-1'), ivectordouble('zAxis', 'std::vector<double>()', '[]', '[]'), ivectordouble('xAxis', 'std::vector<double>()', '[]', '[]'))

doc = '''Add a plane surface in the OpenCASCADE CAD representation, defined by one or more curve loops (or closed wires) `wireTags'. The first curve loop defines the exterior contour; additional curve loop define holes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface.'''
occ.add('addPlaneSurface', doc, oint, ivectorint('wireTags'), iint('tag', '-1'))

doc = '''Add a surface in the OpenCASCADE CAD representation, filling the curve loop `wireTag'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface. If `pointTags' are provided, force the surface to pass through the given points. The other optional arguments are `degree' (the degree of the energy criterion to minimize for computing the deformation of the surface), `numPointsOnCurves' (the average number of points for discretisation of the bounding curves), `numIter' (the maximum number of iterations of the optimization process), `anisotropic' (improve performance when the ratio of the length along the two parametric coordinates of the surface is high), `tol2d' (tolerance to the constraints in the parametric plane of the surface), `tol3d' (the maximum distance allowed between the support surface and the constraints), `tolAng' (the maximum angle allowed between the normal of the surface and the constraints), `tolCurv' (the maximum difference of curvature allowed between the surface and the constraint), `maxDegree' (the highest degree which the polynomial defining the filling surface can have) and, `maxSegments' (the largest number of segments which the filling surface can have).'''
occ.add('addSurfaceFilling', doc, oint, iint('wireTag'), iint('tag', '-1'), ivectorint('pointTags', 'std::vector<int>()', '[]', '[]'), iint('degree', '2'), iint('numPointsOnCurves', '15'), iint('numIter', '2'), ibool('anisotropic', 'false', 'False'), idouble('tol2d', '0.00001'), idouble('tol3d', '0.0001'), idouble('tolAng', '0.01'), idouble('tolCurv', '0.1'), iint('maxDegree', '8'), iint('maxSegments', '9'))

doc = '''Add a BSpline surface in the OpenCASCADE CAD representation, filling the curve loop `wireTag'. The curve loop should be made of 2, 3 or 4 curves. The optional `type' argument specifies the type of filling: "Stretch" creates the flattest patch, "Curved" (the default) creates the most rounded patch, and "Coons" creates a rounded patch with less depth than "Curved". If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface.'''
occ.add('addBSplineFilling', doc, oint, iint('wireTag'), iint('tag', '-1'), istring('type', '""'))

doc = '''Add a Bezier surface in the OpenCASCADE CAD representation, filling the curve loop `wireTag'. The curve loop should be made of 2, 3 or 4 Bezier curves. The optional `type' argument specifies the type of filling: "Stretch" creates the flattest patch, "Curved" (the default) creates the most rounded patch, and "Coons" creates a rounded patch with less depth than "Curved". If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface.'''
occ.add('addBezierFilling', doc, oint, iint('wireTag'), iint('tag', '-1'), istring('type', '""'))

doc = '''Add a b-spline surface of degree `degreeU' x `degreeV' in the OpenCASCADE CAD representation, with `pointTags' control points given as a single vector [Pu1v1, ... Pu`numPointsU'v1, Pu1v2, ...]. If `weights', `knotsU', `knotsV', `multiplicitiesU' or `multiplicitiesV' are not provided, default parameters are computed automatically. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If `wireTags' is provided, trim the b-spline patch using the provided wires: the first wire defines the external contour, the others define holes. If `wire3D' is set, consider wire curves as 3D curves and project them on the b-spline surface; otherwise consider the wire curves as defined in the parametric space of the surface. Return the tag of the b-spline surface.'''
occ.add('addBSplineSurface', doc, oint, ivectorint('pointTags'), iint('numPointsU'), iint('tag', '-1'), iint('degreeU', '3'), iint('degreeV', '3'), ivectordouble('weights', 'std::vector<double>()', '[]', '[]'), ivectordouble('knotsU', 'std::vector<double>()', '[]', '[]'), ivectordouble('knotsV', 'std::vector<double>()', '[]', '[]'), ivectorint('multiplicitiesU', 'std::vector<int>()', '[]', '[]'), ivectorint('multiplicitiesV', 'std::vector<int>()', '[]', '[]'), ivectorint('wireTags', 'std::vector<int>()', '[]', '[]'), ibool('wire3D', 'false', 'False'))

doc = '''Add a Bezier surface in the OpenCASCADE CAD representation, with `pointTags' control points given as a single vector [Pu1v1, ... Pu`numPointsU'v1, Pu1v2, ...]. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. If `wireTags' is provided, trim the Bezier patch using the provided wires: the first wire defines the external contour, the others define holes. If `wire3D' is set, consider wire curves as 3D curves and project them on the Bezier surface; otherwise consider the wire curves as defined in the parametric space of the surface. Return the tag of the Bezier surface.'''
occ.add('addBezierSurface', doc, oint, ivectorint('pointTags'), iint('numPointsU'), iint('tag', '-1'), ivectorint('wireTags', 'std::vector<int>()', '[]', '[]'), ibool('wire3D', 'false', 'False'))

doc = '''Trim the surface `surfaceTag' with the wires `wireTags', replacing any existing trimming curves. The first wire defines the external contour, the others define holes. If `wire3D' is set, consider wire curves as 3D curves and project them on the surface; otherwise consider the wire curves as defined in the parametric space of the surface. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the trimmed surface.'''
occ.add('addTrimmedSurface', doc, oint, iint('surfaceTag'), ivectorint('wireTags', 'std::vector<int>()', '[]', '[]'), ibool('wire3D', 'false', 'False'), iint('tag', '-1'))

doc = '''Add a surface loop (a closed shell) in the OpenCASCADE CAD representation, formed by `surfaceTags'.  If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the surface loop. Setting `sewing' allows one to build a shell made of surfaces that share geometrically identical (but topologically different) curves.'''
occ.add('addSurfaceLoop', doc, oint, ivectorint('surfaceTags'), iint('tag', '-1'), ibool('sewing', 'false', 'False'))

doc = '''Add a volume (a region) in the OpenCASCADE CAD representation, defined by one or more surface loops `shellTags'. The first surface loop defines the exterior boundary; additional surface loop define holes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the volume.'''
occ.add('addVolume', doc, oint, ivectorint('shellTags'), iint('tag', '-1'))

doc = '''Add a sphere of center (`xc', `yc', `zc') and radius `r' in the OpenCASCADE CAD representation. The optional `angle1' and `angle2' arguments define the polar angle opening (from -Pi/2 to Pi/2). The optional `angle3' argument defines the azimuthal opening (from 0 to 2*Pi). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the sphere.'''
occ.add('addSphere', doc, oint, idouble('xc'), idouble('yc'), idouble('zc'), idouble('radius'), iint('tag', '-1'), idouble('angle1', '-M_PI/2', '-pi/2', '-pi/2'), idouble('angle2', 'M_PI/2', 'pi/2', 'pi/2'), idouble('angle3', '2*M_PI', '2*pi', '2*pi'))

doc = '''Add a parallelepipedic box in the OpenCASCADE CAD representation, defined by a point (`x', `y', `z') and the extents along the x-, y- and z-axes. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the box.'''
occ.add('addBox', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('dx'), idouble('dy'), idouble('dz'), iint('tag', '-1'))

doc = '''Add a cylinder in the OpenCASCADE CAD representation, defined by the center (`x', `y', `z') of its first circular face, the 3 components (`dx', `dy', `dz') of the vector defining its axis and its radius `r'. The optional `angle' argument defines the angular opening (from 0 to 2*Pi). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. Return the tag of the cylinder.'''
occ.add('addCylinder', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('dx'), idouble('dy'), idouble('dz'), idouble('r'), iint('tag', '-1'), idouble('angle', '2*M_PI', '2*pi', '2*pi'))

doc = '''Add a cone in the OpenCASCADE CAD representation, defined by the center (`x', `y', `z') of its first circular face, the 3 components of the vector (`dx', `dy', `dz') defining its axis and the two radii `r1' and `r2' of the faces (these radii can be zero). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. `angle' defines the optional angular opening (from 0 to 2*Pi). Return the tag of the cone.'''
occ.add('addCone', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('dx'), idouble('dy'), idouble('dz'), idouble('r1'), idouble('r2'), iint('tag', '-1'), idouble('angle', '2*M_PI', '2*pi', '2*pi'))

doc = '''Add a right angular wedge in the OpenCASCADE CAD representation, defined by the right-angle point (`x', `y', `z') and the 3 extends along the x-, y- and z-axes (`dx', `dy', `dz'). If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. The optional argument `ltx' defines the top extent along the x-axis. If a vector `zAxis' of size 3 is provided, use it to define the z-axis. Return the tag of the wedge.'''
occ.add('addWedge', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('dx'), idouble('dy'), idouble('dz'), iint('tag', '-1'), idouble('ltx', '0.'), ivectordouble('zAxis', 'std::vector<double>()', '[]', '[]'))

doc = '''Add a torus in the OpenCASCADE CAD representation, defined by its center (`x', `y', `z') and its 2 radii `r' and `r2'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. The optional argument `angle' defines the angular opening (from 0 to 2*Pi). If a vector `zAxis' of size 3 is provided, use it to define the z-axis. Return the tag of the torus.'''
occ.add('addTorus', doc, oint, idouble('x'), idouble('y'), idouble('z'), idouble('r1'), idouble('r2'), iint('tag', '-1'), idouble('angle', '2*M_PI', '2*pi', '2*pi'), ivectordouble('zAxis', 'std::vector<double>()', '[]', '[]'))

doc = '''Add a volume (if the optional argument `makeSolid' is set) or surfaces in the OpenCASCADE CAD representation, defined through the open or closed wires `wireTags'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically. The new entities are returned in `outDimTags' as a vector of (dim, tag) pairs. If the optional argument `makeRuled' is set, the surfaces created on the boundary are forced to be ruled surfaces. If `maxDegree' is positive, set the maximal degree of resulting surface. The optional argument `continuity' allows to specify the continuity of the resulting shape ("C0", "G1", "C1", "G2", "C2", "C3", "CN"). The optional argument `parametrization' sets the parametrization type ("ChordLength", "Centripetal", "IsoParametric"). The optional argument `smoothing' determines if smoothing is applied.'''
occ.add('addThruSections', doc, None, ivectorint('wireTags'), ovectorpair('outDimTags'), iint('tag', '-1'), ibool('makeSolid', 'true', 'True'), ibool('makeRuled', 'false', 'False'), iint('maxDegree', '-1'), istring('continuity', '""'), istring('parametrization', '""'), ibool('smoothing', 'false', 'False'))

doc = '''Add a hollowed volume in the OpenCASCADE CAD representation, built from an initial volume `volumeTag' and a set of faces from this volume `excludeSurfaceTags', which are to be removed. The remaining faces of the volume become the walls of the hollowed solid, with thickness `offset'. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically.'''
occ.add('addThickSolid', doc, None, iint('volumeTag'), ivectorint('excludeSurfaceTags'), idouble('offset'), ovectorpair('outDimTags'), iint('tag', '-1'))

doc = '''Extrude the entities `dimTags' (given as a vector of (dim, tag) pairs) in the OpenCASCADE CAD representation, using a translation along (`dx', `dy', `dz'). Return extruded entities in `outDimTags'. If the `numElements' vector is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If the `height' vector is not empty, it provides the (cumulative) height of the different layers, normalized to 1. If `recombine' is set, recombine the mesh in the layers.'''
occ.add('extrude', doc, None, ivectorpair('dimTags'), idouble('dx'), idouble('dy'), idouble('dz'), ovectorpair('outDimTags'), ivectorint('numElements', 'std::vector<int>()', '[]', '[]'), ivectordouble('heights', 'std::vector<double>()', '[]', '[]'), ibool('recombine', 'false', 'False'))

doc = '''Extrude the entities `dimTags' (given as a vector of (dim, tag) pairs) in the OpenCASCADE CAD representation, using a rotation of `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az'). Return extruded entities in `outDimTags'. If the `numElements' vector is not empty, also extrude the mesh: the entries in `numElements' give the number of elements in each layer. If the `height' vector is not empty, it provides the (cumulative) height of the different layers, normalized to 1. When the mesh is extruded the angle should be strictly smaller than 2*Pi. If `recombine' is set, recombine the mesh in the layers.'''
occ.add('revolve', doc, None, ivectorpair('dimTags'), idouble('x'), idouble('y'), idouble('z'), idouble('ax'), idouble('ay'), idouble('az'), idouble('angle'), ovectorpair('outDimTags'), ivectorint('numElements', 'std::vector<int>()', '[]', '[]'), ivectordouble('heights', 'std::vector<double>()', '[]', '[]'), ibool('recombine', 'false', 'False'))

doc = '''Add a pipe in the OpenCASCADE CAD representation, by extruding the entities `dimTags' (given as a vector of (dim, tag) pairs) along the wire `wireTag'. The type of sweep can be specified with `trihedron' (possible values: "DiscreteTrihedron", "CorrectedFrenet", "Fixed", "Frenet", "ConstantNormal", "Darboux", "GuideAC", "GuidePlan", "GuideACWithContact", "GuidePlanWithContact"). If `trihedron' is not provided, "DiscreteTrihedron" is assumed. Return the pipe in `outDimTags'.'''
occ.add('addPipe', doc, None, ivectorpair('dimTags'), iint('wireTag'), ovectorpair('outDimTags'), istring('trihedron', '""'))

doc = '''Fillet the volumes `volumeTags' on the curves `curveTags' with radii `radii'. The `radii' vector can either contain a single radius, as many radii as `curveTags', or twice as many as `curveTags' (in which case different radii are provided for the begin and end points of the curves). Return the filleted entities in `outDimTags' as a vector of (dim, tag) pairs. Remove the original volume if `removeVolume' is set.'''
occ.add('fillet', doc, None, ivectorint('volumeTags'), ivectorint('curveTags'), ivectordouble('radii'), ovectorpair('outDimTags'), ibool('removeVolume', 'true', 'True'))

doc = '''Chamfer the volumes `volumeTags' on the curves `curveTags' with distances `distances' measured on surfaces `surfaceTags'. The `distances' vector can either contain a single distance, as many distances as `curveTags' and `surfaceTags', or twice as many as `curveTags' and `surfaceTags' (in which case the first in each pair is measured on the corresponding surface in `surfaceTags', the other on the other adjacent surface). Return the chamfered entities in `outDimTags'. Remove the original volume if `removeVolume' is set.'''
occ.add('chamfer', doc, None, ivectorint('volumeTags'), ivectorint('curveTags'), ivectorint('surfaceTags'), ivectordouble('distances'), ovectorpair('outDimTags'), ibool('removeVolume', 'true', 'True'))

doc = '''Defeature the volumes `volumeTags' by removing the surfaces `surfaceTags'. Return the defeatured entities in `outDimTags'. Remove the original volume if `removeVolume' is set.'''
occ.add('defeature', doc, None, ivectorint('volumeTags'), ivectorint('surfaceTags'), ovectorpair('outDimTags'), ibool('removeVolume', 'true', 'True'))

doc = '''Create a fillet edge between edges `edgeTag1' and `edgeTag2' with radius `radius'. The modifed edges keep their tag. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically.'''
occ.add('fillet2D', doc, oint, iint('edgeTag1'), iint('edgeTag2'), idouble('radius'), iint('tag', '-1'))

doc = '''Create a chamfer edge between edges `edgeTag1' and `edgeTag2' with distance1 `distance1' and distance2 `distance2'. The modifed edges keep their tag. If `tag' is positive, set the tag explicitly; otherwise a new tag is selected automatically.'''
occ.add('chamfer2D', doc, oint, iint('edgeTag1'), iint('edgeTag2'), idouble('distance1'), idouble('distance2'), iint('tag', '-1'))

doc = '''Create an offset curve based on the curve loop `curveLoopTag' with offset `offset'. Return the offset curves in `outDimTags' as a vector of (dim, tag) pairs.'''
occ.add('offsetCurve', doc, None, iint('curveLoopTag'), idouble('offset'), ovectorpair('outDimTags'))

doc = '''Find the minimal distance between shape with `dim1' and `tag1' and shape with `dim2' and `tag2' and the according coordinates. Return the distance in `distance' and the coordinate of the points as `x1', `y1', `z1' and `x2', `y2', `z2'. '''
occ.add('getDistance', doc, None, iint('dim1'), iint('tag1'), iint('dim2'), iint('tag2'), odouble('distance'), odouble('x1'), odouble('y1'), odouble('z1'), odouble('x2'), odouble('y2'), odouble('z2'))

doc = '''Compute the boolean union (the fusion) of the entities `objectDimTags' and `toolDimTags' (vectors of (dim, tag) pairs) in the OpenCASCADE CAD representation. Return the resulting entities in `outDimTags'. If `tag' is positive, try to set the tag explicitly (only valid if the boolean operation results in a single entity). Remove the object if `removeObject' is set. Remove the tool if `removeTool' is set.'''
occ.add('fuse', doc, None, ivectorpair('objectDimTags'), ivectorpair('toolDimTags'), ovectorpair('outDimTags'), ovectorvectorpair('outDimTagsMap'), iint('tag', '-1'), ibool('removeObject', 'true', 'True'), ibool('removeTool', 'true', 'True'))

doc = '''Compute the boolean intersection (the common parts) of the entities `objectDimTags' and `toolDimTags' (vectors of (dim, tag) pairs) in the OpenCASCADE CAD representation. Return the resulting entities in `outDimTags'. If `tag' is positive, try to set the tag explicitly (only valid if the boolean operation results in a single entity). Remove the object if `removeObject' is set. Remove the tool if `removeTool' is set.'''
occ.add('intersect', doc, None, ivectorpair('objectDimTags'), ivectorpair('toolDimTags'), ovectorpair('outDimTags'), ovectorvectorpair('outDimTagsMap'), iint('tag', '-1'), ibool('removeObject', 'true', 'True'), ibool('removeTool', 'true', 'True'))

doc = '''Compute the boolean difference between the entities `objectDimTags' and `toolDimTags' (given as vectors of (dim, tag) pairs) in the OpenCASCADE CAD representation. Return the resulting entities in `outDimTags'. If `tag' is positive, try to set the tag explicitly (only valid if the boolean operation results in a single entity). Remove the object if `removeObject' is set. Remove the tool if `removeTool' is set.'''
occ.add('cut', doc, None, ivectorpair('objectDimTags'), ivectorpair('toolDimTags'), ovectorpair('outDimTags'), ovectorvectorpair('outDimTagsMap'), iint('tag', '-1'), ibool('removeObject', 'true', 'True'), ibool('removeTool', 'true', 'True'))

doc = '''Compute the boolean fragments (general fuse) resulting from the intersection of the entities `objectDimTags' and `toolDimTags' (given as vectors of (dim, tag) pairs) in the OpenCASCADE CAD representation, making all interfaces conformal. When applied to entities of different dimensions, the lower dimensional entities will be automatically embedded in the higher dimensional entities if they are not on their boundary. Return the resulting entities in `outDimTags'. If `tag' is positive, try to set the tag explicitly (only valid if the boolean operation results in a single entity). Remove the object if `removeObject' is set. Remove the tool if `removeTool' is set.'''
occ.add('fragment', doc, None, ivectorpair('objectDimTags'), ivectorpair('toolDimTags'), ovectorpair('outDimTags'), ovectorvectorpair('outDimTagsMap'), iint('tag', '-1'), ibool('removeObject', 'true', 'True'), ibool('removeTool', 'true', 'True'))

doc = '''Translate the entities `dimTags' (given as a vector of (dim, tag) pairs) in the OpenCASCADE CAD representation along (`dx', `dy', `dz').'''
occ.add('translate', doc, None, ivectorpair('dimTags'), idouble('dx'), idouble('dy'), idouble('dz'))

doc = '''Rotate the entities `dimTags' (given as a vector of (dim, tag) pairs) in the OpenCASCADE CAD representation by `angle' radians around the axis of revolution defined by the point (`x', `y', `z') and the direction (`ax', `ay', `az').'''
occ.add('rotate', doc, None, ivectorpair('dimTags'), idouble('x'), idouble('y'), idouble('z'), idouble('ax'), idouble('ay'), idouble('az'), idouble('angle'))

doc = '''Scale the entities `dimTags' (given as a vector of (dim, tag) pairs) in the OpenCASCADE CAD representation by factors `a', `b' and `c' along the three coordinate axes; use (`x', `y', `z') as the center of the homothetic transformation.'''
occ.add('dilate', doc, None, ivectorpair('dimTags'), idouble('x'), idouble('y'), idouble('z'), idouble('a'), idouble('b'), idouble('c'))

doc = '''Mirror the entities `dimTags' (given as a vector of (dim, tag) pairs) in the OpenCASCADE CAD representation, with respect to the plane of equation `a' * x + `b' * y + `c' * z + `d' = 0.'''
occ.add('mirror', doc, None, ivectorpair('dimTags'), idouble('a'), idouble('b'), idouble('c'), idouble('d'))
doc += ''' (This is a deprecated synonym for `mirror'.)'''
occ.add('symmetrize', doc, None, ivectorpair('dimTags'), idouble('a'), idouble('b'), idouble('c'), idouble('d'))

doc = '''Apply a general affine transformation matrix `affineTransform' (16 entries of a 4x4 matrix, by row; only the 12 first can be provided for convenience) to the entities `dimTags' (given as a vector of (dim, tag) pairs) in the OpenCASCADE CAD representation.'''
occ.add('affineTransform', doc, None, ivectorpair('dimTags'), ivectordouble('affineTransform'))

doc = '''Copy the entities `dimTags' in the OpenCASCADE CAD representation; the new entities are returned in `outDimTags'.'''
occ.add('copy', doc, None, ivectorpair('dimTags'), ovectorpair('outDimTags'))

doc = '''Remove the entities `dimTags' (given as a vector of (dim, tag) pairs) in the OpenCASCADE CAD representation, provided that they are not on the boundary of higher-dimensional entities. If `recursive' is true, remove all the entities on their boundaries, down to dimension 0.'''
occ.add('remove', doc, None, ivectorpair('dimTags'), ibool('recursive', 'false', 'False'))

doc = '''Remove all duplicate entities in the OpenCASCADE CAD representation (different entities at the same geometrical location) after intersecting (using boolean fragments) all highest dimensional entities.'''
occ.add('removeAllDuplicates', doc, None)

doc = '''Apply various healing procedures to the entities `dimTags' (given as a vector of (dim, tag) pairs), or to all the entities in the model if `dimTags' is empty, in the OpenCASCADE CAD representation. Return the healed entities in `outDimTags'.'''
occ.add('healShapes', doc, None, ovectorpair('outDimTags'), ivectorpair('dimTags', 'gmsh::vectorpair()', '[]', '[]'), idouble('tolerance', '1e-8'), ibool('fixDegenerated', 'true', 'True'), ibool('fixSmallEdges', 'true', 'True'), ibool('fixSmallFaces', 'true', 'True'), ibool('sewFaces', 'true', 'True'), ibool('makeSolids', 'true', 'True'))

doc = '''Convert the entities `dimTags' to NURBS.'''
occ.add('convertToNURBS', doc, None, ivectorpair('dimTags'))

doc = '''Import BREP, STEP or IGES shapes from the file `fileName' in the OpenCASCADE CAD representation. The imported entities are returned in `outDimTags', as a vector of (dim, tag) pairs. If the optional argument `highestDimOnly' is set, only import the highest dimensional entities in the file. The optional argument `format' can be used to force the format of the file (currently "brep", "step" or "iges").'''
occ.add('importShapes', doc, None, istring('fileName'), ovectorpair('outDimTags'), ibool('highestDimOnly', 'true', 'True'), istring('format', '""'))

doc = '''Import an OpenCASCADE `shape' by providing a pointer to a native OpenCASCADE `TopoDS_Shape' object (passed as a pointer to void). The imported entities are returned in `outDimTags' as a vector of (dim, tag) pairs. If the optional argument `highestDimOnly' is set, only import the highest dimensional entities in `shape'. In Python, this function can be used for integration with PythonOCC, in which the SwigPyObject pointer of `TopoDS_Shape' must be passed as an int to `shape', i.e., `shape = int(pythonocc_shape.this)'. Warning: this function is unsafe, as providing an invalid pointer will lead to undefined behavior.'''
occ.add('importShapesNativePointer', doc, None, ivoidstar('shape'), ovectorpair('outDimTags'), ibool('highestDimOnly', 'true', 'True'))

doc = '''Get all the OpenCASCADE entities. If `dim' is >= 0, return only the entities of the specified dimension (e.g. points if `dim' == 0). The entities are returned as a vector of (dim, tag) pairs.'''
occ.add('getEntities', doc, None, ovectorpair('dimTags'), iint('dim', '-1'))

doc = '''Get the OpenCASCADE entities in the bounding box defined by the two points (`xmin', `ymin', `zmin') and (`xmax', `ymax', `zmax'). If `dim' is >= 0, return only the entities of the specified dimension (e.g. points if `dim' == 0).'''
occ.add('getEntitiesInBoundingBox', doc, None, idouble('xmin'), idouble('ymin'), idouble('zmin'), idouble('xmax'), idouble('ymax'), idouble('zmax'), ovectorpair('dimTags'), iint('dim', '-1'))

doc = '''Get the bounding box (`xmin', `ymin', `zmin'), (`xmax', `ymax', `zmax') of the OpenCASCADE entity of dimension `dim' and tag `tag'.'''
occ.add('getBoundingBox', doc, None, iint('dim'), iint('tag'), odouble('xmin'), odouble('ymin'), odouble('zmin'), odouble('xmax'), odouble('ymax'), odouble('zmax'))

doc = '''Get the tags `curveLoopTags' of the curve loops making up the surface of tag `surfaceTag', as well as the tags `curveTags' of the curves making up each curve loop.'''
occ.add('getCurveLoops', doc, None, iint('surfaceTag'), ovectorint('curveLoopTags'), ovectorvectorint('curveTags'))

doc = '''Get the tags `surfaceLoopTags' of the surface loops making up the volume of tag `volumeTag', as well as the tags `surfaceTags' of the surfaces making up each surface loop.'''
occ.add('getSurfaceLoops', doc, None, iint('volumeTag'), ovectorint('surfaceLoopTags'), ovectorvectorint('surfaceTags'))

doc = '''Get the mass of the OpenCASCADE entity of dimension `dim' and tag `tag'. If no density is attached to the entity (the default), the value corresponds respectively to the length, area and volume for `dim' = 1, 2 and 3.'''
occ.add('getMass', doc, None, iint('dim'), iint('tag'), odouble('mass'))

doc = '''Get the center of mass of the OpenCASCADE entity of dimension `dim' and tag `tag'.'''
occ.add('getCenterOfMass', doc, None, iint('dim'), iint('tag'), odouble('x'), odouble('y'), odouble('z'))

doc = '''Get the matrix of inertia (by row) of the OpenCASCADE entity of dimension `dim' and tag `tag'.'''
occ.add('getMatrixOfInertia', doc, None, iint('dim'), iint('tag'), ovectordouble('mat'))

doc = '''Get the maximum tag of entities of dimension `dim' in the OpenCASCADE CAD representation.'''
occ.add('getMaxTag', doc, oint, iint('dim'))

doc = '''Set the maximum tag `maxTag' for entities of dimension `dim' in the OpenCASCADE CAD representation.'''
occ.add('setMaxTag', doc, None, iint('dim'), iint('maxTag'))

doc = '''Synchronize the OpenCASCADE CAD representation with the current Gmsh model. This can be called at any time, but since it involves a non trivial amount of processing, the number of synchronization points should normally be minimized. Without synchronization the entities in the OpenCASCADE CAD representation are not available to any function outside of the OpenCASCADE CAD kernel functions.'''
occ.add('synchronize', doc, None)

################################################################################

mesh = occ.add_module('mesh', 'OpenCASCADE CAD kernel meshing constraints')

doc = '''Set a mesh size constraint on the entities `dimTags' (given as a vector of (dim, tag) pairs) in the OpenCASCADE CAD representation. Currently only entities of dimension 0 (points) are handled.'''
mesh.add('setSize', doc, None, ivectorpair('dimTags'), idouble('size'))

################################################################################

view = gmsh.add_module('view', 'post-processing view functions')

doc = '''Add a new post-processing view, with name `name'. If `tag' is positive use it (and remove the view with that tag if it already exists), otherwise associate a new tag. Return the view tag.'''
view.add('add', doc, oint, istring('name'), iint('tag', '-1'))

doc = '''Remove the view with tag `tag'.'''
view.add('remove', doc, None, iint('tag'))

doc = '''Get the index of the view with tag `tag' in the list of currently loaded views. This dynamic index (it can change when views are removed) is used to access view options.'''
view.add('getIndex', doc, oint, iint('tag'))

doc = '''Get the tags of all views.'''
view.add('getTags', doc, None, ovectorint('tags'))

doc = '''Add model-based post-processing data to the view with tag `tag'. `modelName' identifies the model the data is attached to. `dataType' specifies the type of data, currently either "NodeData", "ElementData" or "ElementNodeData". `step' specifies the identifier (>= 0) of the data in a sequence. `tags' gives the tags of the nodes or elements in the mesh to which the data is associated. `data' is a vector of the same length as `tags': each entry is the vector of double precision numbers representing the data associated with the corresponding tag. The optional `time' argument associate a time value with the data. `numComponents' gives the number of data components (1 for scalar data, 3 for vector data, etc.) per entity; if negative, it is automatically inferred (when possible) from the input data. `partition' allows one to specify data in several sub-sets.'''
view.add('addModelData', doc, None, iint('tag'), iint('step'), istring('modelName'), istring('dataType'), ivectorsize('tags'), ivectorvectordouble('data'), idouble('time', '0.'), iint('numComponents', '-1'), iint('partition', '0'))

doc = '''Add homogeneous model-based post-processing data to the view with tag `tag'. The arguments have the same meaning as in `addModelData', except that `data' is supposed to be homogeneous and is thus flattened in a single vector. For data types that can lead to different data sizes per tag (like "ElementNodeData"), the data should be padded.'''
view.add('addHomogeneousModelData', doc, None, iint('tag'), iint('step'), istring('modelName'), istring('dataType'), ivectorsize('tags'), ivectordouble('data'), idouble('time', '0.'), iint('numComponents', '-1'), iint('partition', '0'))

doc = '''Get model-based post-processing data from the view with tag `tag' at step `step'. Return the `data' associated to the nodes or the elements with tags `tags', as well as the `dataType' and the number of components `numComponents'.'''
view.add_special('getModelData', doc, ['rawc'], None, iint('tag'), iint('step'), ostring('dataType'), ovectorsize('tags'), ovectorvectordouble('data'), odouble('time'), oint('numComponents'))

doc = '''Get homogeneous model-based post-processing data from the view with tag `tag' at step `step'. The arguments have the same meaning as in `getModelData', except that `data' is returned flattened in a single vector, with the appropriate padding if necessary.'''
view.add('getHomogeneousModelData', doc, None, iint('tag'), iint('step'), ostring('dataType'), ovectorsize('tags'), ovectordouble('data'), odouble('time'), oint('numComponents'))

doc = '''Add list-based post-processing data to the view with tag `tag'. List-based datasets are independent from any model and any mesh. `dataType' identifies the data by concatenating the field type ("S" for scalar, "V" for vector, "T" for tensor) and the element type ("P" for point, "L" for line, "T" for triangle, "S" for tetrahedron, "I" for prism, "H" for hexaHedron, "Y" for pyramid). For example `dataType' should be "ST" for a scalar field on triangles. `numEle' gives the number of elements in the data. `data' contains the data for the `numEle' elements, concatenated, with node coordinates followed by values per node, repeated for each step: [e1x1, ..., e1xn, e1y1, ..., e1yn, e1z1, ..., e1zn, e1v1..., e1vN, e2x1, ...].'''
view.add('addListData', doc, None, iint('tag'), istring('dataType'), iint('numEle'), ivectordouble('data'))

doc = '''Get list-based post-processing data from the view with tag `tag'. Return the types `dataTypes', the number of elements `numElements' for each data type and the `data' for each data type. If `returnAdaptive' is set, return the data obtained after adaptive refinement, if available.'''
view.add('getListData', doc, None, iint('tag'), ovectorstring('dataType'), ovectorint('numElements'), ovectorvectordouble('data'), ibool('returnAdaptive', 'false', 'False'))

doc = '''Add a string to a list-based post-processing view with tag `tag'. If `coord' contains 3 coordinates the string is positioned in the 3D model space ("3D string"); if it contains 2 coordinates it is positioned in the 2D graphics viewport ("2D string"). `data' contains one or more (for multistep views) strings. `style' contains key-value pairs of styling parameters, concatenated. Available keys are "Font" (possible values: "Times-Roman", "Times-Bold", "Times-Italic", "Times-BoldItalic", "Helvetica", "Helvetica-Bold", "Helvetica-Oblique", "Helvetica-BoldOblique", "Courier", "Courier-Bold", "Courier-Oblique", "Courier-BoldOblique", "Symbol", "ZapfDingbats", "Screen"), "FontSize" and "Align" (possible values: "Left" or "BottomLeft", "Center" or "BottomCenter", "Right" or "BottomRight", "TopLeft", "TopCenter", "TopRight", "CenterLeft", "CenterCenter", "CenterRight").'''
view.add('addListDataString', doc, None, iint('tag'), ivectordouble('coord'), ivectorstring('data'), ivectorstring('style', 'std::vector<std::string>()', '[]', '[]'))

doc = '''Get list-based post-processing data strings (2D strings if `dim' == 2, 3D strings if `dim' = 3) from the view with tag `tag'. Return the coordinates in `coord', the strings in `data' and the styles in `style'.'''
view.add('getListDataStrings', doc, None, iint('tag'), iint('dim'), ovectordouble('coord'), ovectorstring('data'), ovectorstring('style'))

doc = '''Set interpolation matrices for the element family `type' ("Line", "Triangle", "Quadrangle", "Tetrahedron", "Hexahedron", "Prism", "Pyramid") in the view `tag'. The approximation of the values over an element is written as a linear combination of `d' basis functions f_i(u, v, w) = sum_(j = 0, ..., `d' - 1) `coef'[i][j] u^`exp'[j][0] v^`exp'[j][1] w^`exp'[j][2], i = 0, ..., `d'-1, with u, v, w the coordinates in the reference element. The `coef' matrix (of size `d' x `d') and the `exp' matrix (of size `d' x 3) are stored as vectors, by row. If `dGeo' is positive, use `coefGeo' and `expGeo' to define the interpolation of the x, y, z coordinates of the element in terms of the u, v, w coordinates, in exactly the same way. If `d' < 0, remove the interpolation matrices.'''
view.add('setInterpolationMatrices', doc, None, iint('tag'), istring('type'), iint('d'), ivectordouble('coef'), ivectordouble('exp'), iint('dGeo', '0'), ivectordouble('coefGeo', 'std::vector<double>()', '[]', '[]'), ivectordouble('expGeo', 'std::vector<double>()', '[]', '[]'))

doc = '''Add a post-processing view as an `alias' of the reference view with tag `refTag'. If `copyOptions' is set, copy the options of the reference view. If `tag' is positive use it (and remove the view with that tag if it already exists), otherwise associate a new tag. Return the view tag.'''
view.add('addAlias', doc, oint, iint('refTag'), ibool('copyOptions', 'false', 'False'), iint('tag', '-1'))

doc = '''Combine elements (if `what' == "elements") or steps (if `what' == "steps") of all views (`how' == "all"), all visible views (`how' == "visible") or all views having the same name (`how' == "name"). Remove original views if `remove' is set.'''
view.add('combine', doc, None, istring('what'), istring('how'), ibool('remove', 'true', 'True'), ibool('copyOptions', 'true', 'True'))

doc = '''Probe the view `tag' for its `values' at point (`x', `y', `z'). If no match is found, `value' is returned empty. Return only the value at step `step' is `step' is positive. Return only values with `numComp' if `numComp' is positive. Return the gradient of the `values' if `gradient' is set. If `distanceMax' is zero, only return a result if an exact match inside an element in the view is found; if `distanceMax' is positive and an exact match is not found, return the value at the closest node if it is closer than `distanceMax'; if `distanceMax' is negative and an exact match is not found, always return the value at the closest node. The distance to the match is returned in `distance'. Return the result from the element described by its coordinates if `xElementCoord', `yElementCoord' and `zElementCoord' are provided. If `dim' is >= 0, return only matches from elements of the specified dimension.'''
view.add('probe', doc, None, iint('tag'), idouble('x'), idouble('y'), idouble('z'), ovectordouble('values'), odouble('distance'), iint('step', '-1'), iint('numComp', '-1'), ibool('gradient', 'false', 'False'), idouble('distanceMax', '0.'), ivectordouble('xElemCoord', 'std::vector<double>()', '[]', '[]'), ivectordouble('yElemCoord', 'std::vector<double>()', '[]', '[]'), ivectordouble('zElemCoord', 'std::vector<double>()', '[]', '[]'), iint('dim', '-1'))

doc = '''Write the view to a file `fileName'. The export format is determined by the file extension. Append to the file if `append' is set.'''
view.add('write', doc, None, iint('tag'), istring('fileName'), ibool('append', 'false', 'False'))

doc = '''Set the global visibility of the view `tag' per window to `value', where `windowIndex' identifies the window in the window list.'''
view.add('setVisibilityPerWindow', doc, None, iint('tag'), iint('value'), iint('windowIndex', '0'))

################################################################################

option = view.add_module('option', 'view option handling functions')

doc = '''Set the numerical option `name' to value `value' for the view with tag `tag'.'''
option.add('setNumber', doc, None, iint('tag'), istring('name'), idouble('value'))

doc = '''Get the `value' of the numerical option `name' for the view with tag `tag'.'''
option.add('getNumber', doc, None, iint('tag'), istring('name'), odouble('value'))

doc = '''Set the string option `name' to value `value' for the view with tag `tag'.'''
option.add('setString', doc, None, iint('tag'), istring('name'), istring('value'))

doc = '''Get the `value' of the string option `name' for the view with tag `tag'.'''
option.add('getString', doc, None, iint('tag'), istring('name'), ostring('value'))

doc = '''Set the color option `name' to the RGBA value (`r', `g', `b', `a') for the view with tag `tag', where where `r', `g', `b' and `a' should be integers between 0 and 255.'''
option.add('setColor', doc, None, iint('tag'), istring('name'), iint('r'), iint('g'), iint('b'), iint('a', '255'))

doc = '''Get the `r', `g', `b', `a' value of the color option `name' for the view with tag `tag'.'''
option.add('getColor', doc, None, iint('tag'), istring('name'), oint('r'), oint('g'), oint('b'), oint('a'))

doc = '''Copy the options from the view with tag `refTag' to the view with tag `tag'.'''
option.add('copy', doc, None, iint('refTag'), iint('tag'))

################################################################################

plugin = gmsh.add_module('plugin', 'plugin functions')

doc = '''Set the numerical option `option' to the value `value' for plugin `name'. Plugins available in the official Gmsh release are listed in the "Gmsh plugins" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-plugins).'''
plugin.add('setNumber', doc, None, istring('name'), istring('option'), idouble('value'))

doc = '''Set the string option `option' to the value `value' for plugin `name'. Plugins available in the official Gmsh release are listed in the "Gmsh plugins" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-plugins).'''
plugin.add('setString', doc, None, istring('name'), istring('option'), istring('value'))

doc = '''Run the plugin `name'. Return the tag of the created view (if any). Plugins available in the official Gmsh release are listed in the "Gmsh plugins" chapter of the Gmsh reference manual (https://gmsh.info/doc/texinfo/gmsh.html#Gmsh-plugins).'''
plugin.add('run', doc, oint, istring('name'))

################################################################################

graphics = gmsh.add_module('graphics', 'graphics functions')

doc = '''Draw all the OpenGL scenes.'''
graphics.add('draw', doc, None)

################################################################################

fltk = gmsh.add_module('fltk', 'FLTK graphical user interface functions')

doc = '''Create the FLTK graphical user interface. Can only be called in the main thread.'''
fltk.add('initialize', doc, None)

doc = '''Close the FLTK graphical user interface. Can only be called in the main thread.'''
fltk.add('finalize', doc, None)

doc = '''Wait at most `time' seconds for user interface events and return. If `time' < 0, wait indefinitely. First automatically create the user interface if it has not yet been initialized. Can only be called in the main thread.'''
fltk.add('wait', doc, None, idouble('time', '-1.'))

doc = '''Update the user interface (potentially creating new widgets and windows). First automatically create the user interface if it has not yet been initialized. Can only be called in the main thread: use `awake("update")' to trigger an update of the user interface from another thread.'''
fltk.add('update', doc, None)

doc = '''Awake the main user interface thread and process pending events, and optionally perform an action (currently the only `action' allowed is "update"). '''
fltk.add('awake', doc, None, istring('action', '""'))

doc = '''Block the current thread until it can safely modify the user interface.'''
fltk.add('lock', doc, None)

doc = '''Release the lock that was set using lock.'''
fltk.add('unlock', doc, None)

doc = '''Run the event loop of the graphical user interface, i.e. repeatedly call `wait()'. First automatically create the user interface if it has not yet been initialized. Can only be called in the main thread.'''
fltk.add('run', doc, None)

doc = '''Check if the user interface is available (e.g. to detect if it has been closed).'''
fltk.add('isAvailable', doc, oint)

doc = '''Select entities in the user interface. Return the selected entities as a vector of (dim, tag) pairs. If `dim' is >= 0, return only the entities of the specified dimension (e.g. points if `dim' == 0).'''
fltk.add('selectEntities', doc, oint, ovectorpair('dimTags'), iint('dim', '-1'))

doc = '''Select elements in the user interface.'''
fltk.add('selectElements', doc, oint, ovectorsize('elementTags'))

doc = '''Select views in the user interface.'''
fltk.add('selectViews', doc, oint, ovectorint('viewTags'))

doc = '''Split the current window horizontally (if `how' == "h") or vertically (if `how' == "v"), using ratio `ratio'. If `how' == "u", restore a single window.'''
fltk.add('splitCurrentWindow', doc, None, istring('how', '"v"'), idouble('ratio', '0.5'))

doc = '''Set the current window by speficying its index (starting at 0) in the list of all windows. When new windows are created by splits, new windows are appended at the end of the list.'''
fltk.add('setCurrentWindow', doc, None, iint('windowIndex', '0'))

doc = '''Set a status message in the current window. If `graphics' is set, display the message inside the graphic window instead of the status bar.'''
fltk.add('setStatusMessage', doc, None, istring('message'), ibool('graphics', 'false', 'False'))

doc = '''Show context window for the entity of dimension `dim' and tag `tag'.'''
fltk.add('showContextWindow', doc, None, iint('dim'), iint('tag'))

doc = '''Open the `name' item in the menu tree.'''
fltk.add('openTreeItem', doc, None, istring('name'))

doc = '''Close the `name' item in the menu tree.'''
fltk.add('closeTreeItem', doc, None, istring('name'))

################################################################################

parser = gmsh.add_module('parser', 'parser functions')

doc = '''Get the names of the variables in the Gmsh parser matching the `search' regular expression. If `search' is empty, return all the names.'''
parser.add('getNames', doc, None, ovectorstring('names'), istring('search', '""'))

doc = '''Set the value of the number variable `name' in the Gmsh parser. Create the variable if it does not exist; update the value if the variable exists.'''
parser.add('setNumber', doc, None, istring('name'), ivectordouble('value'))

doc = '''Set the value of the string variable `name' in the Gmsh parser. Create the variable if it does not exist; update the value if the variable exists.'''
parser.add('setString', doc, None, istring('name'), ivectorstring('value'))

doc = '''Get the value of the number variable `name' from the Gmsh parser. Return an empty vector if the variable does not exist.'''
parser.add('getNumber', doc, None, istring('name'), ovectordouble('value'))

doc = '''Get the value of the string variable `name' from the Gmsh parser. Return an empty vector if the variable does not exist.'''
parser.add('getString', doc, None, istring('name'), ovectorstring('value'))

doc = '''Clear all the Gmsh parser variables, or remove a single variable if `name' is given.'''
parser.add('clear', doc, None, istring('name', '""'))

doc = '''Parse the file `fileName' with the Gmsh parser.'''
parser.add('parse', doc, None, istring('fileName'))

################################################################################

onelab = gmsh.add_module('onelab', 'ONELAB server functions')

doc = '''Set one or more parameters in the ONELAB database, encoded in `format'.'''
onelab.add('set', doc, None, istring('data'), istring('format', '"json"'))

doc = '''Get all the parameters (or a single one if `name' is specified) from the ONELAB database, encoded in `format'.'''
onelab.add('get', doc, None, ostring('data'), istring('name', '""'), istring('format', '"json"'))

doc = '''Get the names of the parameters in the ONELAB database matching the `search' regular expression. If `search' is empty, return all the names.'''
onelab.add('getNames', doc, None, ovectorstring('names'), istring('search', '""'))

doc = '''Set the value of the number parameter `name' in the ONELAB database. Create the parameter if it does not exist; update the value if the parameter exists.'''
onelab.add('setNumber', doc, None, istring('name'), ivectordouble('value'))

doc = '''Set the value of the string parameter `name' in the ONELAB database. Create the parameter if it does not exist; update the value if the parameter exists.'''
onelab.add('setString', doc, None, istring('name'), ivectorstring('value'))

doc = '''Get the value of the number parameter `name' from the ONELAB database. Return an empty vector if the parameter does not exist.'''
onelab.add('getNumber', doc, None, istring('name'), ovectordouble('value'))

doc = '''Get the value of the string parameter `name' from the ONELAB database. Return an empty vector if the parameter does not exist.'''
onelab.add('getString', doc, None, istring('name'), ovectorstring('value'))

doc = '''Check if any parameters in the ONELAB database used by the client `name' have been changed.'''
onelab.add('getChanged', doc, oint, istring('name'))

doc = '''Set the changed flag to value `value' for all the parameters in the ONELAB database used by the client `name'.'''
onelab.add('setChanged', doc, None, istring('name'), iint('value'))

doc = '''Clear the ONELAB database, or remove a single parameter if `name' is given.'''
onelab.add('clear', doc, None, istring('name', '""'))

doc = '''Run a ONELAB client. If `name' is provided, create a new ONELAB client with name `name' and executes `command'. If not, try to run a client that might be linked to the processed input files.'''
onelab.add('run', doc, None, istring('name', '""'), istring('command', '""'))

################################################################################

logger = gmsh.add_module('logger', 'information logging functions')

doc = '''Write a `message'. `level' can be "info", "warning" or "error".'''
logger.add('write', doc, None, istring('message'), istring('level', '"info"'))

doc = '''Start logging messages.'''
logger.add('start', doc, None)

doc = '''Get logged messages.'''
logger.add('get', doc, None, ovectorstring('log'))

doc = '''Stop logging messages.'''
logger.add('stop', doc, None)

doc = '''Return wall clock time (in s).'''
logger.add('getWallTime', doc, odouble)

doc = '''Return CPU time (in s).'''
logger.add('getCpuTime', doc, odouble)

doc = '''Return memory usage (in Mb).'''
logger.add('getMemory', doc, odouble)

doc = '''Return total available memory (in Mb).'''
logger.add('getTotalMemory', doc, odouble)

doc = '''Return last error message, if any.'''
logger.add('getLastError', doc, None, ostring('error'))

################################################################################

api.write_cpp()
api.write_c()
api.write_python()
api.write_julia()
api.write_fortran()
api.write_texi()
