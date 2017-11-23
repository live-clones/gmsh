// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSH_H_
#define _GMSH_H_

// This file defines the Gmsh API.
//
// A first beta version will be released in Gmsh 3.1. The first stable release
// in planned for Gmsh 4.0.
//
// By design, the API is purely functional, and only uses elementary C++ types
// from the standard library. Python wrappers are automatically generated; a
// JavaScript and a pure C version are also planned.
//
// See `gmsh/demos/api' for examples (in C++ and Python) on how to use the
// API. In particular, `gmsh/demos/api' contains C++ and Python versions of
// several of the .geo tutorials from `gmsh/tutorials'.
//
// Your input is very welcome: please contribute your ideas and suggestions on
// https://gitlab.onelab.info/gmsh/gmsh/issues/188

#include <cmath>
#include <vector>
#include <string>

#if defined(WIN32)
#define GMSH_API __declspec(dllexport)
#else
#define GMSH_API
#endif

// A geometrical entity in the Gmsh API is represented by two integers: its
// dimension (dim = 0, 1, 2 or 3) and its tag (its unique, strictly positive
// identifier). When dealing with multiple geometrical entities of possibly
// different dimensions, the entities are packed as a vector of (dim, tag)
// integer pairs.
typedef std::vector<std::pair<int, int> > vector_pair;

// -----------------------------------------------------------------------------
// Module gmsh: top-level functions
// -----------------------------------------------------------------------------

// Initializes Gmsh. This must be called before any call to the other functions
// in the API. If argc and argv are provided, they will be handled in the same
// way as the command line arguments in the Gmsh app.
GMSH_API void gmshInitialize(int argc = 0, char **argv = 0);

// Finalizes Gmsh. This must be called when you are done using the Gmsh API.
GMSH_API void gmshFinalize();

// Opens a file and creates one (or more) new model(s). Equivalent to the
// `File->Open' menu in the Gmsh app. Handling of the file depends on its
// extension and/or its contents.
GMSH_API void gmshOpen(const std::string &fileName);

// Merges a file. Equivalent to the `File->Merge' menu in the Gmsh app. Handling
// of the file depends on its extension and/or its contents.
GMSH_API void gmshMerge(const std::string &fileName);

// Exports a file. The export format is determined by the file extension.
GMSH_API void gmshExport(const std::string &fileName);

// Clears all loaded models and post-processing data, and creates a new empty
// model.
GMSH_API void gmshClear();

// -----------------------------------------------------------------------------
// Module gmshOption: global option handling functions
// -----------------------------------------------------------------------------

// Sets a numerical option to `value'. `name' is of the form "category.option"
// or "category[num].option". Available categories and options are listed in the
// Gmsh reference manual.
GMSH_API void gmshOptionSetNumber(const std::string &name, const double value);

// Gets the `value' of a numerical option.
GMSH_API void gmshOptionGetNumber(const std::string &name, double &value);

// Sets a string option to `value'.
GMSH_API void gmshOptionSetString(const std::string &name,
                                  const std::string &value);

// Gets the `value' of a string option.
GMSH_API void gmshOptionGetString(const std::string &name, std::string &value);

// -----------------------------------------------------------------------------
// Module gmshModel: per-model functions
// -----------------------------------------------------------------------------

// Creates a new model, with name `name', and sets it as the current model.
GMSH_API void gmshModelCreate(const std::string &name);

// Deletes the current model.
GMSH_API void gmshModelDelete();

// Lists the names of all models.
GMSH_API void gmshModelList(std::vector<std::string> &names);

// Sets the current model to the model with name `name'. If several models have
// the same name, selects the one that was created first.
GMSH_API void gmshModelSetCurrent(const std::string &name);

// Gets all the (elementary) geometrical entities in the current model. If `dim'
// is >= 0, returns only the entities of the specified dimension (e.g. points if
// `dim' == 0). The entities are returned as a vector of (dim, tag) integer
// pairs.
GMSH_API void gmshModelGetEntities(vector_pair &dimTags, const int dim = -1);

// Gets all the physical groups in the current model. If `dim' is >= 0, returns
// only the entities of the specified dimension (e.g. physical points if `dim'
// == 0). The entities are returned as a vector of (dim, tag) integer pairs.
GMSH_API void gmshModelGetPhysicalGroups(vector_pair &dimTags,
                                         const int dim = -1);

// Gets the tags of all the (elementary) geometrical entities making up the
// physical group of dimension `dim' and tag `tag'.
GMSH_API void gmshModelGetEntitiesForPhysicalGroup(const int dim, const int tag,
                                                   std::vector<int> &tags);

// Adds a physical group of dimension `dim', grouping the elementary entities
// with tags `tags'. The function returns the tag of the physical group, equal
// to `tag' if `tag' is positive, or a new tag if `tag' < 0.
GMSH_API int gmshModelAddPhysicalGroup(const int dim,
                                       const std::vector<int> &tags,
                                       int tag = -1);

// Sets the name of the physical group of dimension `dim' and tag `tag'.
GMSH_API void gmshModelSetPhysicalName(const int dim, const int tag,
                                       const std::string &name);

// Gets the name of the physical group of dimension `dim' and tag `tag'.
GMSH_API void gmshModelGetPhysicalName(const int dim, const int tag,
                                       std::string &name);

// Gets the boundary of the geometrical entities `dimTags'. Returns in
// `outDimTags' the boundary of the individual entities (if `combined' is false)
// or the boundary of the combined geometrical shape formed by all input
// entities (if `combined' is true). Returns tags multiplied by the sign of the
// boundary entity if `oriented' is true. Applies the boundary operator
// recursively down to dimension 0 (i.e. to points) if `recursive' is true.
GMSH_API void gmshModelGetBoundary(const vector_pair &dimTags,
                                   vector_pair &outDimTags,
                                   const bool combined = true,
                                   const bool oriented = true,
                                   const bool recursive = false);

// Gets the (elementary) geometrical entities in the bounding box defined by the
// two points (xmin, ymin, zmin) and (xmax, ymax, zmax). If `dim' is >= 0,
// returns only the entities of the specified dimension (e.g. points if `dim' ==
// 0).
GMSH_API void gmshModelGetEntitiesInBoundingBox(const double xmin,
                                                const double ymin,
                                                const double zmin,
                                                const double xmax,
                                                const double ymax,
                                                const double zmax,
                                                vector_pair &tags,
                                                const int dim = -1);

// Gets the bounding box (xmin, ymin, zmin), (xmax, ymax, zmax) of the
// geometrical entity of dimension `dim' and tag `tag'.
GMSH_API void gmshModelGetBoundingBox(const int dim, const int tag, double &xmin,
                                      double &ymin, double &zmin, double &xmax,
                                      double &ymax, double &zmax);

// Adds a discrete geometrical entity (defined by a mesh) of dimension `dim' in
// the current model. The function returns the tag of the new discrete entity,
// equal to `tag' if `tag' is positive, or a new tag if `tag' < 0. `boundary'
// specifies the tags of the entities on the boundary of the discrete entity, if
// any. Specyfing `boundary' allows Gmsh to construct the topology of the
// overall model.
GMSH_API int gmshModelAddDiscreteEntity(const int dim,
                                        const int tag = -1,
                                        const std::vector<int> &boundary =
                                        std::vector<int>());

// Removes the entities `dimTags' of the current model. If `recursive' is true,
// remove all the entities on their boundaries, down to dimension 0.
GMSH_API void gmshModelRemove(const vector_pair &dimTags,
                              const bool recursive = false);

// Generates a mesh of the current model, up to dimension `dim' (0, 1, 2 or 3).
GMSH_API void gmshModelMesh(const int dim);

// Gets the last entities (if any) where a meshing error occurred. Currently
// only populated by the new 3D meshing algorithms.
GMSH_API void gmshModelGetLastMeshEntityError(vector_pair &dimTags);

// Gets the last mesh vertices (if any) where a meshing error
// occurred. Currently only populated by the new 3D meshing algorithms.
GMSH_API void gmshModelGetLastMeshVertexError(std::vector<int> &vertexTags);

// Gets the mesh vertices of the entity of dimension `dim' and `tag'
// tag. `vertextags' contains the vertex tags (their unique, strictly positive
// identification numbers). `coord` is a vector of length `3 *
// vertexTags.size()' that contains the (x, y, z) coordinates of the vertices,
// concatenated. `parametricCoord` contains the parametric coordinates of the
// vertices, if available. The length of `parametricCoord` can be 0 or `dim *
// vertexTags.size()'.
GMSH_API void gmshModelGetMeshVertices(const int dim, const int tag,
                                       std::vector<int> &vertexTags,
                                       std::vector<double> &coord,
                                       std::vector<double> &parametricCoord);

// Gets the mesh elements of the entity of dimension `dim' and `tag'
// tag. `types' contains the MSH types of the elements (e.g. `2' for 3-node
// triangles: see the Gmsh reference manual). `elementTags' is a vector of
// length `types.size()'; each entry is a vector containing the tags (unique,
// strictly positive identifiers) of the elements of the corresponding
// type. `vertexTags' is also a vector of length `types.size()'; each entry is a
// vector of length equal to the number of elements of the given type times the
// number of vertices for this type of element, that contains the vertex tags of
// all the elements of the given type, concatenated.
GMSH_API void gmshModelGetMeshElements(const int dim, const int tag,
                                       std::vector<int> &types,
                                       std::vector<std::vector<int> > &elementTags,
                                       std::vector<std::vector<int> > &vertexTags);

// Sets the mesh vertices in the geometrical entity of dimension `dim' and tag
// `tag'. `vertextags' contains the vertex tags (their unique, strictly positive
// identification numbers). `coord` is a vector of length `3 *
// vertexTags.size()' that contains the (x, y, z) coordinates of the vertices,
// concatenated. The optional `parametricCoord` vector contains the parametric
// coordinates of the vertices, if any. The length of `parametricCoord` can be 0
// or `dim * vertexTags.size()'.
GMSH_API void gmshModelSetMeshVertices(const int dim, const int tag,
                                       const std::vector<int> &vertexTags,
                                       const std::vector<double> &coord,
                                       const std::vector<double> &parametricCoord =
                                       std::vector<double>());

// Sets the mesh elements of the entity of dimension `dim' and `tag'
// tag. `types' contains the MSH types of the elements (e.g. `2' for 3-node
// triangles: see the Gmsh reference manual). `elementTags' is a vector of
// length `types.size()'; each entry is a vector containing the tags (unique,
// strictly positive identifiers) of the elements of the corresponding
// type. `vertexTags' is also a vector of length `types.size()'; each entry is a
// vector of length equal to the number of elements of the give type times the
// number of vertices per element, that contains the vertex tags of all the
// elements of the given type, concatenated.
GMSH_API void gmshModelSetMeshElements(const int dim, const int tag,
                                       const std::vector<int> &types,
                                       const std::vector<std::vector<int> > &elementTags,
                                       const std::vector<std::vector<int> > &vertexTags);

// Gets the coordinates and the parametric coordinates (if any) of the mesh
// vertex with tag `tag'. This is a useful by inefficient way of accessing mesh
// vertex data, as it relies on a cache stored in the model. For large meshes
// all the vertices in the model should be numbered in a continuous sequence of
// tags from 1 to N to maintain reasonnable performance (in this case the
// internal cache is based on a vector; otherwise it uses a map).
GMSH_API void gmshModelGetMeshVertex(const int vertexTag,
                                     std::vector<double> &coord,
                                     std::vector<double> &parametricCoord);

// Gets the type and vertex tags of the mesh element with tag `tag'. This is a
// useful but inefficient way of accessing mesh element data, as it relies on a
// cache stored in the model. For large meshes all the elements in the model
// should be numbered in a continuous sequence of tags from 1 to N to maintain
// reasonnable performance (in this case the internal cache is based on a
// vector; otherwise it uses a map).
GMSH_API void gmshModelGetMeshElement(const int elementTag, int &type,
                                      std::vector<int> &vertexTags);

// Sets a mesh size constraint on the geometrical entities `dimTags'. Currently
// only entities of dimension 0 (points) are handled.
GMSH_API void gmshModelSetMeshSize(const vector_pair &dimTags, const double size);

// Sets a transfinite meshing constraint on the line `tag', with `numVertices'
// mesh vertices distributed according to `type' and `coef'. Currently supported
// types are "Progression" (geometrical progression with power `coef') and
// "Bump" (refinement toward both extreminties of the line).
GMSH_API void gmshModelSetTransfiniteLine(const int tag, const int numVertices,
                                          const std::string &type = "Progression",
                                          const double coef = 1.);

// Sets a transfinite meshing constraint on the surface `tag'. `arrangement'
// describes the arrangement of the triangles when the surface is not flagged as
// recombined: currently supported values are "Left", "Right", "AlternateLeft"
// and "AlternateRight". `cornerTags' can be used to specify the (3 or 4)
// corners of the transfinite interpolation explicitly; specifying the corners
// explicitly is mandatory if the surface has more that 3 or 4 points on its
// boundary.
GMSH_API void gmshModelSetTransfiniteSurface(const int tag,
                                             const std::string &arrangement = "Left",
                                             const std::vector<int> &cornerTags =
                                             std::vector<int>());

// Sets a transfinite meshing constraint on the surface `tag'. `cornerTags' can
// be used to specify the (6 or 8) corners of the transfinite interpolation
// explicitly.
GMSH_API void gmshModelSetTransfiniteVolume(const int tag,
                                            const std::vector<int> &cornerTags =
                                            std::vector<int>());

// Sets a recombination meshing constraint on the geometrical entity of
// dimension `dim' and tag `tag'. Currently only entities of dimension 2 (to
// recombine triangles into quadrangles) are supported.
GMSH_API void gmshModelSetRecombine(const int dim, const int tag);

// Sets a smoothing meshing constraint on the geometrical entity of dimension
// `dim' and tag `tag'. `val' iterations of a Laplace smoother are applied.
GMSH_API void gmshModelSetSmoothing(const int dim, const int tag, const int val);

// Sets a reverse meshing constraint on the geometrical entity of dimension
// `dim' and tag `tag'. If `val' is true, the mesh orientation will be reversed
// with respect to the natural mesh orientation (i.e. the orientation consistent
// with the orientation of the geometrical entity). If `val' is false, the mesh
// is left as-is.
GMSH_API void gmshModelSetReverseMesh(const int dim, const int tag,
                                      const bool val = true);

// Emebds the geometrical entities of dimension `dim' and tags `tags' in the
// (inDim, inTag) geometrical entity. `inDim' must be strictly greater than
// `dim'.
GMSH_API void gmshModelEmbed(const int dim, const std::vector<int> &tags,
                             const int inDim, const int inTag);

// -----------------------------------------------------------------------------
// Module gmshModelGeo: internal per-model GEO CAD kernel functions
// -----------------------------------------------------------------------------

// Adds a geometrical point in the internal GEO CAD representation, at
// coordinates (x, y, z). If `meshSize' is > 0, adds a meshing constraint at
// that point. If `tag' is positive, sets the tag explicitly; otherwise a new
// tag is selected automatically. Returns the tag of the point. (Note that the
// point will be added in the current model only after gmshModelGeoSynchronize()
// is called. This behavior holds for all the entities created in the
// gmshModelGeo module.)
GMSH_API int gmshModelGeoAddPoint(const double x, const double y, const double z,
                                  const double meshSize = 0., const int tag = -1);

// Adds a straight line segment between the two points with tags `startTag' and
// `endTag'. If `tag' is positive, sets the tag explicitly; otherwise a new tag
// is selected automatically. Returns the tag of the line.
GMSH_API int gmshModelGeoAddLine(const int startTag, const int endTag,
                                 const int tag = -1);

// Adds a circle arc (stricly smaller than Pi) between the two points with tags
// `startTag' and `endTag', with center `centertag'. If `tag' is positive, sets
// the tag explicitly; otherwise a new tag is selected automatically. If (`nx',
// `ny', `nz') != (0,0,0), explicitely sets the plane of the circle arc. Returns
// the tag of the circle arc.
GMSH_API int gmshModelGeoAddCircleArc(const int startTag, const int centerTag,
                                      const int endTag, const int tag = -1,
                                      const double nx = 0., const double ny = 0.,
                                      const double nz = 0.);

// Adds an ellipse arc (stricly smaller than Pi) between the two points
// `startTag' and `endTag', with center `centertag' and major axis point
// `majorTag'. If `tag' is positive, sets the tag explicitly; otherwise a new
// tag is selected automatically. If (`nx', `ny', `nz') != (0,0,0), explicitely
// sets the plane of the circle arc. Returns the tag of the ellipse arc.
GMSH_API int gmshModelGeoAddEllipseArc(const int startTag, const int centerTag,
                                       const int majorTag, const int endTag,
                                       const int tag = -1, const double nx = 0.,
                                       const double ny = 0., const double nz = 0.);

// Adds a spline curve going through `vertexTags' points. If `tag' is positive,
// sets the tag explicitly; otherwise a new tag is selected automatically.
// Returns the tag of the spline curve.
GMSH_API int gmshModelGeoAddSpline(const std::vector<int> &vertexTags,
                                   const int tag = -1);

// Adds a b-spline curve with `vertexTags' control points. If `tag' is positive,
// sets the tag explicitly; otherwise a new tag is selected automatically.
// Returns the tag of the b-spline curve.
GMSH_API int gmshModelGeoAddBSpline(const std::vector<int> &vertexTags,
                                    const int tag = -1);

// Adds a Bezier curve with `vertexTags' control points. If `tag' is positive,
// sets the tag explicitly; otherwise a new tag is selected automatically.
// Returns the tag of the Bezier curve.
GMSH_API int gmshModelGeoAddBezier(const std::vector<int> &vertexTags,
                                   const int tag = -1);

// Adds a line loop (a closed wire) formed by `edgeTags'. `edgeTags' should
// contain (signed) tags of geometrical enties of dimension 1 forming a closed
// loop: a negative tag signifies that the underlying edge is considered with
// reversed orientation. If `tag' is positive, sets the tag explicitly;
// otherwise a new tag is selected automatically. Returns the tag of the line
// loop.
GMSH_API int gmshModelGeoAddLineLoop(const std::vector<int> &edgeTags,
                                     const int tag = -1);

// Adds a plane surface defined by one or more line loops `wireTags'. The first
// line loop defines the exterior contour; additional line loop define holes. If
// `tag' is positive, sets the tag explicitly; otherwise a new tag is selected
// automatically. Returns the tag of the surface.
GMSH_API int gmshModelGeoAddPlaneSurface(const std::vector<int> &wireTags,
                                         const int tag = -1);

// Adds a surface filling the line loops in `wireTags'. Currently only a single
// line loop is supported; this line loop should be composed by 3 or 4 edges
// only. If `tag' is positive, sets the tag explicitly; otherwise a new tag is
// selected automatically. Returns the tag of the surface.
GMSH_API int gmshModelGeoAddSurfaceFilling(const std::vector<int> &wireTags,
                                           const int tag = -1,
                                           const int sphereCenterTag = -1);

// Adds a surface loop (a closed shell) formed by `faceTags'.  If `tag' is
// positive, sets the tag explicitly; otherwise a new tag is selected
// automatically. Returns the tag of the surface loop.
GMSH_API int gmshModelGeoAddSurfaceLoop(const std::vector<int> &faceTags,
                                        const int tag = -1);

// Adds a volume defined by one or more surface loops `shellTags'. The first
// surface loop defines the exterior boundary; additional surface loop define
// holes. If `tag' is positive, sets the tag explicitly; otherwise a new tag is
// selected automatically. Returns the tag of the volume.
GMSH_API int gmshModelGeoAddVolume(const std::vector<int> &shellTags,
                                   const int tag = -1);

// Extrudes the geometrical entities in `dimTags' by translation along (`dx',
// `dy', `dz'). Returns extruded entities in `outDimTags'. If `numElements' is
// not empty, also extrude the mesh: the entries in `numElements' give the
// number of elements in each layer. If `height' is not empty, it provides the
// (cummulative) height of the different layers, normalized to 1.
GMSH_API void gmshModelGeoExtrude(const vector_pair &dimTags,
                                  const double dx, const double dy, const double dz,
                                  vector_pair &outDimTags,
                                  const std::vector<int> &numElements =
                                  std::vector<int>(),
                                  const std::vector<double> &heights =
                                  std::vector<double>(),
                                  const bool recombine = false);

// Extrudes the geometrical entities in `dimTags' by rotation of `angle' radians
// around the axis of revolution defined by the point (`x', `y', `z') and the
// direction (`ax', `ay', `az'). Returns extruded entities in `outDimTags'. If
// `numElements' is not empty, also extrude the mesh: the entries in
// `numElements' give the number of elements in each layer. If `height' is not
// empty, it provides the (cummulative) height of the different layers,
// normalized to 1.
GMSH_API void gmshModelGeoRevolve(const vector_pair &dimTags,
                                  const double x, const double y, const double z,
                                  const double ax, const double ay,
                                  const double az, const double angle,
                                  vector_pair &outDimTags,
                                  const std::vector<int> &numElements =
                                  std::vector<int>(),
                                  const std::vector<double> &heights =
                                  std::vector<double>(),
                                  const bool recombine = false);

// Extrudes the geometrical entities in `dimTags' by a combined translation and
// rotation of `angle' radians, along (`dx', `dy', `dz') and around the axis of
// revolution defined by the point (`x', `y', `z') and the direction (`ax',
// `ay', `az'). Returns extruded entities in `outDimTags'. If `numElements' is
// not empty, also extrude the mesh: the entries in `numElements' give the
// number of elements in each layer. If `height' is not empty, it provides the
// (cummulative) height of the different layers, normalized to 1.
GMSH_API void gmshModelGeoTwist(const vector_pair &dimTags,
                                const double x, const double y, const double z,
                                const double dx, const double dy, const double dz,
                                const double ax, const double ay, const double az,
                                const double angle,
                                vector_pair &outDimTags,
                                const std::vector<int> &numElements =
                                std::vector<int>(),
                                const std::vector<double> &heights =
                                std::vector<double>(),
                                const bool recombine = false);

// Translates the geometrical entities in `dimTags' along (`dx', `dy', `dz').
GMSH_API void gmshModelGeoTranslate(const vector_pair &dimTags, const double dx,
                                    const double dy, const double dz);

// Rotates the geometrical entities in `dimTags' of `angle' radians around the
// axis of revolution defined by the point (`x', `y', `z') and the direction
// (`ax', `ay', `az').
GMSH_API void gmshModelGeoRotate(const vector_pair &dimTags, const double x,
                                 const double y, const double z, const double ax,
                                 const double ay, const double az,
                                 const double angle);


// Scales the geometrical entities in `dimTag' by factors `a', `b' and `c' along
// the three coordinate axes; use (`x', `y', `z') as the center of the
// homothetic transformation.
GMSH_API void gmshModelGeoDilate(const vector_pair &dimTags, const double x,
                                 const double y, const double z, const double a,
                                 const double b, const double c);

// Applies a symmetry transformation to the geometrical entities in `dimTag',
// with respect to the plane of equation `a' * x + `b' * y + `c' * z + `d' = 0.
GMSH_API void gmshModelGeoSymmetry(const vector_pair &dimTags, const double a,
                                   const double b, const double c, const double d);

// Copies the entities in `dimTags'; the new entities are returned in
// `outDimTags'.
GMSH_API void gmshModelGeoCopy(const vector_pair &dimTags, vector_pair &outDimTags);

// Removes the entities `dimTags'. If `recursive' is true, remove all the
// entities on their boundaries, down to dimension 0.
GMSH_API void gmshModelGeoRemove(const vector_pair &dimTags,
                                 const bool recursive = false);

// Remove all duplicate entities (different entities at the same geometrical
// location).
GMSH_API void gmshModelGeoRemoveAllDuplicates();


// Sets a mesh size constraint on the geometrical entities `dimTags'. Currently
// only entities of dimension 0 (points) are handled.
GMSH_API void gmshModelGeoSetMeshSize(const vector_pair &dimTags, const double size);

// Sets a transfinite meshing constraint on the line `tag', with `numVertices'
// mesh vertices distributed according to `type' and `coef'. Currently supported
// types are "Progression" (geometrical progression with power `coef') and
// "Bump" (refinement toward both extreminties of the line).
GMSH_API void gmshModelGeoSetTransfiniteLine(const int tag, const int nPoints,
                                             const std::string &type = "Progression",
                                             const double coef = 1.);

// Sets a transfinite meshing constraint on the surface `tag'. `arrangement'
// describes the arrangement of the triangles when the surface is not flagged as
// recombined: currently supported values are "Left", "Right", "AlternateLeft"
// and "AlternateRight". `cornerTags' can be used to specify the (3 or 4)
// corners of the transfinite interpolation explicitly; specifying the corners
// explicitly is mandatory if the surface has more that 3 or 4 points on its
// boundary.
GMSH_API void gmshModelGeoSetTransfiniteSurface(const int tag,
                                                const std::string &arrangement = "Left",
                                                const std::vector<int> &cornerTags =
                                                std::vector<int>());

// Sets a transfinite meshing constraint on the surface `tag'. `cornerTags' can
// be used to specify the (6 or 8) corners of the transfinite interpolation
// explicitly.
GMSH_API void gmshModelGeoSetTransfiniteVolume(const int tag,
                                               const std::vector<int> &cornerTags =
                                               std::vector<int>());

// Sets a recombination meshing constraint on the geometrical entity of
// dimension `dim' and tag `tag'. Currently only entities of dimension 2 (to
// recombine triangles into quadrangles) are supported.
GMSH_API void gmshModelGeoSetRecombine(const int dim, const int tag,
                                       const double angle = 45.);

// Sets a smoothing meshing constraint on the geometrical entity of dimension
// `dim' and tag `tag'. `val' iterations of a Laplace smoother are applied.
GMSH_API void gmshModelGeoSetSmoothing(const int dim, const int tag,
                                       const int val);

// Sets a reverse meshing constraint on the geometrical entity of dimension
// `dim' and tag `tag'. If `val' is true, the mesh orientation will be reversed
// with respect to the natural mesh orientation (i.e. the orientation consistent
// with the orientation of the geometrical entity). If `val' is false, the mesh
// is left as-is.
GMSH_API void gmshModelGeoSetReverseMesh(const int dim, const int tag,
                                         const bool val = true);

// Synchronize the internal GEO CAD representation with the current Gmsh
// model. This can be called at any time, but since it involves a non trivial
// amount of processing, the number of synchronization points should normally be
// minimized.
GMSH_API void gmshModelGeoSynchronize();

// -----------------------------------------------------------------------------
// Module gmshModelOcc: internal per-model OpenCASCADE CAD kernel functions
// -----------------------------------------------------------------------------

// Adds a geometrical point in the internal OpenCASCADE CAD representation, at
// coordinates (x, y, z). If `meshSize' is > 0, adds a meshing constraint at
// that point. If `tag' is positive, sets the tag explicitly; otherwise a new
// tag is selected automatically. Returns the tag of the point. (Note that the
// point will be added in the current model only after gmshModelGeoSynchronize()
// is called. This behavior holds for all the entities created in the
// gmshModelOcc module.)
GMSH_API int gmshModelOccAddPoint(const double x, const double y, const double z,
                                  const double meshSize = 0., const int tag = -1);

// Adds a straight line segment between the two points with tags `startTag' and
// `endTag'. If `tag' is positive, sets the tag explicitly; otherwise a new tag
// is selected automatically. Returns the tag of the line.
GMSH_API int gmshModelOccAddLine(const int startTag, const int endTag,
                                 const int tag = -1);

// Adds a circle arc between the two points with tags `startTag' and `endTag',
// with center `centertag'. If `tag' is positive, sets the tag explicitly;
// otherwise a new tag is selected automatically. Returns the tag of the circle
// arc.
GMSH_API int gmshModelOccAddCircleArc(const int startTag, const int centerTag,
                                      const int endTag, const int tag = -1);

// Adds a circle of center (`x', `y', `z') and radius `r'. If `tag' is positive,
// sets the tag explicitly; otherwise a new tag is selected
// automatically. `angle1' and `angle2' allow to create a circle arc. Returns
// the tag of the circle.
GMSH_API int gmshModelOccAddCircle(const double x, const double y, const double z,
                                   const double r, const int tag = -1,
                                   const double angle1 = 0.,
                                   const double angle2 = 2*M_PI);

GMSH_API int gmshModelOccAddEllipseArc(const int startTag, const int centerTag,
                                       const int endTag, const int tag = -1);
GMSH_API int gmshModelOccAddEllipse(const double x, const double y, const double z,
                                    const double r1, const double r2,
                                    const int tag = -1,
                                    const double angle1 = 0.,
                                    const double angle2 = 2*M_PI);
GMSH_API int gmshModelOccAddSpline(const std::vector<int> &vertexTags,
                                   const int tag = -1);
GMSH_API int gmshModelOccAddBezier(const std::vector<int> &vertexTags,
                                   const int tag = -1);
GMSH_API int gmshModelOccAddBSpline(const std::vector<int> &vertexTags,
                                    const int tag = -1);
GMSH_API int gmshModelOccAddWire(const std::vector<int> &edgeTags,
                                 const int tag = -1,
                                 const bool checkClosed = false);
GMSH_API int gmshModelOccAddLineLoop(const std::vector<int> &edgeTags,
                                     const int tag = -1);
GMSH_API int gmshModelOccAddRectangle(const double x, const double y,
                                      const double z, const double dx,
                                      const double dy,
                                      const int tag = -1,
                                      const double roundedRadius = 0.);
GMSH_API int gmshModelOccAddDisk(const double xc, const double yc,
                                 const double zc, const double rx,
                                 const double ry, const int tag = -1);
GMSH_API int gmshModelOccAddPlaneSurface(const std::vector<int> &wireTags,
                                         const int tag = -1);
GMSH_API int gmshModelOccAddSurfaceFilling(int wireTag, const int tag = -1);
GMSH_API int gmshModelOccAddSurfaceLoop(const std::vector<int> &faceTags,
                                        const int tag = -1);
GMSH_API int gmshModelOccAddVolume(const std::vector<int> &shellTags,
                                   const int tag = -1);
GMSH_API int gmshModelOccAddSphere(const double xc, const double yc,
                                   const double zc, const double radius,
                                   const int tag = -1,
                                   const double angle1 = -M_PI/2,
                                   const double angle2 = M_PI/2,
                                   const double angle3 = 2*M_PI);
GMSH_API int gmshModelOccAddBox(const double x, const double y, const double z,
                                const double dx, const double dy, const double dz,
                                const int tag = -1);
GMSH_API int gmshModelOccAddCylinder(const double x, const double y,
                                     const double z, const double dx,
                                     const double dy, const double dz,
                                     const double r, const int tag = -1,
                                     double angle = 2*M_PI);
GMSH_API int gmshModelOccAddCone(const double x, const double y, const double z,
                                 const double dx, const double dy, const double dz,
                                 const double r1, const double r2,
                                 const int tag = -1,
                                 const double angle = 2*M_PI);
GMSH_API int gmshModelOccAddWedge(const double x, const double y, const double z,
                                  const double dx, const double dy, const double dz,
                                  const int tag = -1, const double ltx = 0.);
GMSH_API int gmshModelOccAddTorus(const double x, const double y, const double z,
                                  const double r1, const double r2,
                                  const int tag = -1,
                                  const double angle = 2*M_PI);
GMSH_API int gmshModelOccAddThruSections(const std::vector<int> &wireTags,
                                         vector_pair &outDimTags,
                                         const int tag = -1,
                                         const bool makeSolid = true,
                                         const bool makeRuled = false);
GMSH_API int addThickSolid(const int solidTag,
                           const std::vector<int> &excludeFaceTags,
                           const double offset, vector_pair &outDimTags,
                           const int tag = -1);
GMSH_API void gmshModelOccExtrude(const vector_pair &dimTags, const double dx,
                                  const double dy, const double dz,
                                  vector_pair &outDimTags,
                                  const std::vector<int> &numElements =
                                  std::vector<int>(),
                                  const std::vector<double> &heights =
                                  std::vector<double>(),
                                  const bool recombine = false);
GMSH_API void gmshModelOccRevolve(const vector_pair &dimTags,
                                  const double x, const double y, const double z,
                                  const double ax, const double ay, const double az,
                                  const double angle, vector_pair &outDimTags,
                                  const std::vector<int> &numElements =
                                  std::vector<int>(),
                                  const std::vector<double> &heights =
                                  std::vector<double>(),
                                  const bool recombine = false);
GMSH_API void gmshModelOccAddPipe(const vector_pair &dimTags, int wireTag,
                                  vector_pair &outDimTags);
GMSH_API void gmshModelOccFillet(const std::vector<int> &regionTags,
                                 const std::vector<int> &edgeTags,
                                 const double radius, vector_pair &outDimTags,
                                 const bool removeRegion = true);
GMSH_API int gmshModelOccBooleanUnion(const vector_pair &objectDimTags,
                                      const vector_pair &toolDimTags,
                                      vector_pair &outDimTags,
                                      std::vector<vector_pair> &outDimTagsMap,
                                      const int tag = -1,
                                      const bool removeObject = true,
                                      const bool removeTool = true);
GMSH_API int gmshModelOccBooleanIntersection(const vector_pair &objectDimTags,
                                             const vector_pair &toolDimTags,
                                             vector_pair &outDimTags,
                                             std::vector<vector_pair> &outDimTagsMap,
                                             const int tag = -1,
                                             const bool removeObject = true,
                                             const bool removeTool = true);
GMSH_API int gmshModelOccBooleanDifference(const vector_pair &objectDimTags,
                                           const vector_pair &toolDimTags,
                                           vector_pair &outDimTags,
                                           std::vector<vector_pair> &outDimTagsMap,
                                           const int tag = -1,
                                           const bool removeObject = true,
                                           const bool removeTool = true);
GMSH_API int gmshModelOccBooleanFragments(const vector_pair &objectDimTags,
                                          const vector_pair &toolDimTags,
                                          vector_pair &outDimTags,
                                          std::vector<vector_pair> &outDimTagsMap,
                                          const int tag = -1,
                                          const bool removeObject = true,
                                          const bool removeTool = true);
GMSH_API void gmshModelOccTranslate(const vector_pair &dimTags, const double dx,
                                    const double dy, const double dz);
GMSH_API void gmshModelOccRotate(const vector_pair &dimTags, const double x,
                                 const double y, const double z, const double ax,
                                 const double ay, const double az, const double angle);
GMSH_API void gmshModelOccDilate(const vector_pair &dimTags, const double x,
                                 const double y, const double z, const double a,
                                 const double b, const double c);
GMSH_API void gmshModelOccSymmetry(const vector_pair &dimTags, const double a,
                                   const double b, const double c, const double d);
GMSH_API void gmshModelOccCopy(const vector_pair &dimTags, vector_pair &outDimTags);
GMSH_API void gmshModelOccRemove(const vector_pair &dimTags,
                                 const bool recursive = false);
GMSH_API void gmshModelOccRemoveAllDuplicates();
GMSH_API void gmshModelOccImportShapes(const std::string &fileName,
                                       vector_pair &outDimTags,
                                       const bool highestDimOnly = true,
                                       const std::string &format = "");

// Sets a mesh size constraint on the geometrical entities `dimTags'. Currently
// only entities of dimension 0 (points) are handled.
GMSH_API void gmshModelOccSetMeshSize(const vector_pair &dimTags, const double size);

// Synchronize the internal OpenCASCADE CAD representation with the current Gmsh
// model. This can be called at any time, but since it involves a non trivial
// amount of processing, the number of synchronization points should normally be
// minimized.
GMSH_API void gmshModelOccSynchronize();

// -----------------------------------------------------------------------------
// Module gmshModelField: per-model mesh size field functions
// -----------------------------------------------------------------------------

// Creates a new mesh size field of type `type'. If `tag' is positive, assign
// the tag explcitly; otherwise a new tag is assigned automatically. Returns the
// field tag.
GMSH_API int gmshModelFieldCreate(const std::string &type, const int tag = -1);

// Deletes the field with tag `tag'.
GMSH_API void gmshModelFieldDelete(const int tag);

// Sets the numerical option `option' to value `value' for field `tag'.
GMSH_API void gmshModelFieldSetNumber(const int tag, const std::string &option,
                                      const double value);

// Sets the string option `option' to value `value' for field `tag'.
GMSH_API void gmshModelFieldSetString(const int tag, const std::string &option,
                                      const std::string &value);

// Sets the numerical list option `option' to value `value' for field `tag'.
GMSH_API void gmshModelFieldSetNumbers(const int tag, const std::string &option,
                                       const std::vector<double> &value);

// Sets the field `tag' as background mesh size field.
GMSH_API void gmshModelFieldSetAsBackground(const int tag);

// -----------------------------------------------------------------------------
// Module gmshView: post-processing view functions
// -----------------------------------------------------------------------------

// Creates a new post-processing view, with name `name'. If `tag' is positive
// use it (and delete the view with that tag if it already exists), otherwise
// associate a new tag. Returns the view tag.
GMSH_API int gmshViewCreate(const std::string &name, const int tag = -1);

// Deletes the view with tag `tag'.
GMSH_API void gmshViewDelete(const int tag);

// Gets the index of the view with tag `tag' in the list of currently loaded
// views. This dynamic index (it can change when views are deleted) is used to
// access view options with the gmshOption functions.
GMSH_API int gmshViewGetIndex(const int tag);

// Gets the tags of all views.
GMSH_API void gmshViewGetTags(std::vector<int> &tags);

// Adds model-based post-processing data to the view with tag `tag'. `modelName'
// identifies the model the data is attached to. `dataType' specifies the type
// of data, currently either "NodeData", "ElementData" or
// "ElementNodeData". `tags' gives the tags of the vertices or elements in the
// mesh to which the data is associated. `data' is a vector of length
// `tags.size()`: each entry is the vector of double precision numbers
// representing the data associated with the corresponding tag. The optional
// `step` and `time` arguments associate a time step and time value with the
// data. `numComponents' gives the number of data components (1 for scalar data,
// 3 for vector data, etc.) per entity; if negative, it is automatically
// inferred (when possible) from the input data. `partition' allows to specify
// data in several sub-sets.
GMSH_API void gmshViewAddModelData(const int tag, const std::string &modelName,
                                   const std::string &dataType,
                                   const std::vector<int> &tags,
                                   const std::vector<std::vector<double> > &data,
                                   const int step = 0, const int time = 0.,
                                   const int numComponents = -1,
                                   const int partition = 0);

// Adds list-based post-processing data to the view with tag `tag'. `type'
// identifies the data: "SP" for scalar points, "VP", for vector points,
// etc. `numEle' gives the number of elements in the data. `data' contains the
// data for the `numEle' elements.
GMSH_API void gmshViewAddListData(const int tag, const std::string &type,
                                  const int numEle, const std::vector<double> &data);

// Probes the view `tag' for its `value' at point (`x', `y', `z').
GMSH_API void gmshViewProbe(const int tag, const double x, const double y,
                            const double z, std::vector<double> &value,
                            const int step = -1, const int numComp = -1,
                            const bool gradient = false,
                            const double tolerance = 0.,
                            const std::vector<double> xElemCoord
                            = std::vector<double>(),
                            const std::vector<double> yElemCoord
                            = std::vector<double>(),
                            const std::vector<double> zElemCoord
                            = std::vector<double>());

// Exports the view to a file. The export format is determined by the file
// extension.
GMSH_API void gmshViewExport(const int tag, const std::string &fileName,
                             const bool append = false);

// -----------------------------------------------------------------------------
// Module gmshPlugin: plugin functions
// -----------------------------------------------------------------------------

// Sets the numerical option `option` to the value `value' for plugin `name'.
GMSH_API void gmshPluginSetNumber(const std::string &name,
                                  const std::string &option,
                                  const double value);

// Sets the string option `option` to the value `value' for plugin `name'.
GMSH_API void gmshPluginSetString(const std::string &name,
                                  const std::string &option,
                                  const std::string &value);

// Runs the plugin `name'.
GMSH_API void gmshPluginRun(const std::string &name);

#undef GMSH_API

#endif
