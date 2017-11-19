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
// JavaScript and a pure C version are also planned. All the API functions
// return 0 as the first entry of the returned integer vector on successful
// completion, and nonzero values on error. Additional integers can be appended
// to this first value, depending on context.
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

// All Gmsh API functions return a vector of integers of size > 1. The first
// entry in the returned vector is 0 on success and nonzero on error. Current
// error codes are -1 (API not initialized), 1 (generic error) and 2 (bad input
// arguments). Additional integers can be returned depending on context.
#if defined(WIN32)
#define GMSH_API __declspec(dllexport) std::vector<int>
#else
#define GMSH_API std::vector<int>
#endif

// An geometrical entity in the Gmsh API is represented by two integers: its
// dimension (dim = 0, 1, 2 or 3) and its tag (its unique identifier). When
// dealing with multiple geometrical entities of possibly different dimensions
// (e.g. points and surfaces), the entities are packed as a list of (dim, tag)
// integer pairs.
typedef std::vector<std::pair<int, int> > vector_pair;

// -----------------------------------------------------------------------------
// Section "gmsh": top-level functions
// -----------------------------------------------------------------------------

// Initializes Gmsh. `gmshInitialize()' must be called before any call to the
// other functions in the API. If argc and argv are are provided, they will be
// handled in the same way as the command line arguments in the Gmsh app.
GMSH_API gmshInitialize(int argc = 0, char **argv = 0);

// Finalizes Gmsh. This must be called when you are done using the Gmsh API.
GMSH_API gmshFinalize();

// Opens a file and creates one (or more) new model(s). Equivalent to the
// File->Open menu in the Gmsh app. Handling of the file depends on its
// extension and/or its contents.
GMSH_API gmshOpen(const std::string &fileName);

// Merges a file. Equivalent to the File->Merge menu in the Gmsh app. Handling
// of the file depends on its extension and/or its contents.
GMSH_API gmshMerge(const std::string &fileName);

// Exports a file. The export format is determined by the file extension.
GMSH_API gmshExport(const std::string &fileName);

// Clears all loaded models and post-processing data, and creates a new empty
// model.
GMSH_API gmshClear();

// -----------------------------------------------------------------------------
// Section "gmshOption": global option handling functions
// -----------------------------------------------------------------------------

// Sets a numerical option to `value'. `name' is of the form "category.option"
// or "category[num].option". Available categories and options are listed in the
// Gmsh reference manual.
GMSH_API gmshOptionSetNumber(const std::string &name, const double value);

// Gets the `value' of a numerical option.
GMSH_API gmshOptionGetNumber(const std::string &name, double &value);

// Sets a string option to `value'.
GMSH_API gmshOptionSetString(const std::string &name, const std::string &value);

// Gets the `value' of a string option.
GMSH_API gmshOptionGetString(const std::string &name, std::string &value);

// -----------------------------------------------------------------------------
// Section "gmshModel": per-model functions
// -----------------------------------------------------------------------------

// Creates a new model, with name `name', and sets it as the current model.
GMSH_API gmshModelCreate(const std::string &name);

// Deletes the current model.
GMSH_API gmshModelDelete();

// Lists the names of all models.
GMSH_API gmshModelList(std::vector<std::string> &names);

// Sets the current model to the model with name `name'. If several models have
// the same name, selects the one that was created first.
GMSH_API gmshModelSetCurrent(const std::string &name);

// Gets all the (elementary) geometrical entities in the current model. If `dim'
// is >= 0, returns only the entities of the specified dimension (e.g. points if
// `dim' == 0). The entities are returned as a vector of (dim, tag) integer
// pairs.
GMSH_API gmshModelGetEntities(vector_pair &dimTags, const int dim = -1);

// Gets all the physical groups in the current model. If `dim' is >= 0, returns
// only the entities of the specified dimension (e.g. physical points if `dim'
// == 0). The entities are returned as a vector of (dim, tag) integer pairs.
GMSH_API gmshModelGetPhysicalGroups(vector_pair &dimTags, const int dim = -1);

// Gets the tags of all the (elementary) geometrical entities grouped in the
// physical group of dimension `dim' and tag `tag'.
GMSH_API gmshModelGetEntitiesForPhysicalGroup(const int dim, const int tag,
                                              std::vector<int> &tags);

// Adds a physical group of dimension `dim' and tag `tag', grouping the
// elementary entities with tags `tags'
GMSH_API gmshModelAddPhysicalGroup(const int dim, const int tag,
                                   const std::vector<int> &tags);

// Sets the name of the physical group of dimension `dim' and tag `tag'.
GMSH_API gmshModelSetPhysicalName(const int dim, const int tag,
                                  const std::string &name);

// Gets the name of the physical group of dimension `dim' and tag `tag'.
GMSH_API gmshModelGetPhysicalName(const int dim, const int tag,
                                  std::string &name);

// Gets the boundary of the geometrical entities `dimTags'. Returns in
// `outDimTags' the boundary of the individual entities (if `combined' is false)
// or the boundary of the combined geometrical shape formed by all input
// entities (if `combined' is true). Returns tags multiplied by the sign of the
// boundary entity if `oriented' is true. Applies the boundary operator
// recursively down to dimension 0 (i.e. to points) if `recursive' is true.
GMSH_API gmshModelGetBoundary(const vector_pair &dimTags, vector_pair &outDimTags,
                              const bool combined = true, const bool oriented = true,
                              const bool recursive = false);

// Gets the (elementary) geometrical entities in the bounding box defined by two
// points (xmin, ymin, zmin) and (xmax, ymax, zmax).
GMSH_API gmshModelGetEntitiesInBoundingBox(const double xmin, const double ymin,
                                           const double zmin, const double xmax,
                                           const double ymax, const double zmax2,
                                           vector_pair &tags, const int dim=-1);

// Gets the bounding box (xmin, ymin, zmin), (xmax, ymax, zmax) of the
// geometrical entity of dimension `dim' and tag `tag'.
GMSH_API gmshModelGetBoundingBox(const int dim, const int tag, double &xmin,
                                 double &ymin, double &zmin, double &xmax,
                                 double &ymax, double &zmax);

// Adds a discrete geometrical entity (defined by a mesh) of dimension `dim' and
// tag `tag' in the current model.
GMSH_API gmshModelAddDiscreteEntity(const int dim, const int tag,
                                    const std::vector<int> &boundary
                                    = std::vector<int>());

// Removes the entities `dimTags' of the current model. If `recursive' is true,
// remove all the entities on their bundaries, down to dimension 0.
GMSH_API gmshModelRemove(const vector_pair &dimTags, const bool recursive = false);

// Generates a mesh of the current model, up to dimension `dim' (0, 1, 2 or 3).
GMSH_API gmshModelMesh(const int dim);

// Gets the mesh vertices of the entity of dimension `dim' and `tag'
// tag. `vertextags' contains the vertex tags (unique identification
// numbers). `coordinates` is a vector of length `3 * vertexTags.size()' that
// contains the (x, y, z) coordinates of the vertices. `parametricCoordinates`
// contains the parametric coordinates of the vertices, if available. The length
// of `parametricCoordinates` can be 0, `vertexTags.size()' or `2 *
// vertexTags.size()'.
GMSH_API gmshModelGetMeshVertices(const int dim, const int tag,
                                  std::vector<int> &vertexTags,
                                  std::vector<double> &coordinates,
                                  std::vector<double> &parametricCoordinates);

// Gets the mesh elements of the entity of dimension `dim' and `tag'
// tag. `types' contains the MSH types (e.g. 2 for 3-node triangles -- see the
// Gmsh reference manual). `elementTags' is a vector of length `types.size()';
// each entry is a vector containing the tags (unique identifiers) of the
// elements of the corresponding type. `vertexTags' is a vector of length
// `types.size()'; each entry is a vector (length = number of elements of the
// give type times number of vertices per element) contains the vertex tags of
// all the elements of the given type.
GMSH_API gmshModelGetMeshElements(const int dim, const int tag,
                                  std::vector<int> &types,
                                  std::vector<std::vector<int> > &elementTags,
                                  std::vector<std::vector<int> > &vertexTags);

GMSH_API gmshModelSetMeshVertices(const int dim, const int tag,
                                  const std::vector<int> &vertexTags,
                                  const std::vector<double> &coordinates,
                                  const std::vector<double> &parametricCoordinates =
                                  std::vector<double>());
GMSH_API gmshModelSetMeshElements(const int dim, const int tag,
                                  const std::vector<int> &types,
                                  const std::vector<std::vector<int> > &elementTags,
                                  const std::vector<std::vector<int> > &vertexTags);

// Gets the coordinates and the parametric coordinates (if any) of the mesh
// vertex with tag `tag'. This is an inefficient way of accessing mesh vertex
// data, as it relies on a dynamic cache stored in the model. For large meshes
// all the vertices in the model should be numbered in a continuous sequence of
// tags from 1 to N to maintain reasonnable performance (in this case the
// internal cache is based on a vector; otherwise it uses a map).
GMSH_API gmshModelGetMeshVertex(const int vertexTag,
                                std::vector<double> &coordinates,
                                std::vector<double> &parametricCoordinates);

// Gets the type and vertex tags of the mesh element with tag `tag'. This is an
// inefficient way of accessing mesh element data, as it relies on a dynamic
// cache stored in the model. For large meshes all the elements in the model
// should be numbered in a continuous sequence of tags from 1 to N to maintain
// reasonnable performance (in this case the internal cache is based on a
// vector; otherwise it uses a map).
GMSH_API gmshModelGetMeshElement(const int elementTag, int &type,
                                 std::vector<int> &vertexTags);

// Sets a mesh size constraint on the geometrical entities `dimTags'. Currently
// only entities of dimension 0 (points) are handled.
GMSH_API gmshModelSetMeshSize(const vector_pair &dimTags, const double size);

// Sets a transfinite meshing constraint on the line `tag', with `numVertices'
// mesh vertices distributed according to `type' and `coef'. Currently supported
// types are "Progression" (geometrical progression with power `coef') and
// "Bump" (refinement toward both extreminties of the line0.
GMSH_API gmshModelSetTransfiniteLine(const int tag, const int numVertices,
                                     const std::string &type = "Progression",
                                     const double coef = 1.);

// Sets a transfinite meshing constraint on the surface `tag'. `arrangement'
// describes the arrangement of the triangles when the surface is not flagged as
// recombined: currently supported values are "Left", "Right", "AlternateLeft"
// and "AlternateRight". `cornerTags' can be used to specify the (3 or 4)
// corners of the transfinite interpolation explicitly; specifying the corners
// explicitly is mandatory if the surface has more that 3 or 4 points on its
// boundary.
GMSH_API gmshModelSetTransfiniteSurface(const int tag,
                                        const std::string &arrangement = "Left",
                                        const std::vector<int> &cornerTags =
                                        std::vector<int>());

// Sets a transfinite meshing constraint on the surface `tag'. `cornerTags' can
// be used to specify the (6 or 8) corners of the transfinite interpolation
// explicitly.
GMSH_API gmshModelSetTransfiniteVolume(const int tag,
                                       const std::vector<int> &cornerTags =
                                       std::vector<int>());

// Sets a recombination meshing constraint on the geometrical entity of
// dimension `dim' and tag `tag'. Currently only entities of dimension 2 (to
// recombine triangles into quadrangles) are supported.
GMSH_API gmshModelSetRecombine(const int dim, const int tag);

// Sets a smoothing meshing constraint on the geometrical entity of dimension
// `dim' and tag `tag'. `val' iterations of a Laplace smoother will be applied.
GMSH_API gmshModelSetSmoothing(const int dim, const int tag, const int val);

// Sets a reverse meshing constraint on the geometrical entity of dimension
// `dim' and tag `tag'. If `val' is true, the mesh orientation will be reverse
// with respect to the natural mesh orientation (i.e. the orientation consistent
// with the orientation of the geometrical entity). If `val' is false, the mesh
// is left as-is.
GMSH_API gmshModelSetReverseMesh(const int dim, const int tag, const bool val = true);

// Emebds the geometrical entities of dimension `dim' and tags `tags' in the
// (inDim, inTag) geometrical entity. `inDim' must be strictly greater than
// `dim'.
GMSH_API gmshModelEmbed(const int dim, const std::vector<int> &tags, const int inDim,
                        const int inTag);

// -----------------------------------------------------------------------------
// Section "gmshModelGeo": built-in CAD kernel functions for current model
// -----------------------------------------------------------------------------

GMSH_API gmshModelGeoAddPoint(const int tag, const double x, const double y,
                              const double z, const double meshSize = 0.);
GMSH_API gmshModelGeoAddLine(const int tag, const int startTag, const int endTag);
GMSH_API gmshModelGeoAddCircleArc(const int tag, const int startTag,
                                  const int centerTag, const int endTag,
                                  const double nx = 0., const double ny = 0.,
                                  const double nz = 0.);
GMSH_API gmshModelGeoAddEllipseArc(const int tag, const int startTag, const int centerTag,
                                   const int majorTag, const int endTag,
                                   const double nx = 0., const double ny = 0.,
                                   const double nz = 0.);
GMSH_API gmshModelGeoAddSpline(const int tag, const std::vector<int> &vertexTags);
GMSH_API gmshModelGeoAddBSpline(const int tag, const std::vector<int> &vertexTags);
GMSH_API gmshModelGeoAddBezier(const int tag, const std::vector<int> &vertexTags);
GMSH_API gmshModelGeoAddLineLoop(const int tag, const std::vector<int> &edgeTags);
GMSH_API gmshModelGeoAddPlaneSurface(const int tag, const std::vector<int> &wireTags);
GMSH_API gmshModelGeoAddSurfaceFilling(const int tag, const std::vector<int> &wireTags,
                                       const int sphereCenterTag = -1);
GMSH_API gmshModelGeoAddSurfaceLoop(const int tag, const std::vector<int> &faceTags);
GMSH_API gmshModelGeoAddVolume(const int tag, const std::vector<int> &shellTags);
GMSH_API gmshModelGeoExtrude(const vector_pair &dimTags,
                             const double dx, const double dy, const double dz,
                             vector_pair &outDimTags,
                             const std::vector<int> &numElements = std::vector<int>(),
                             const std::vector<double> &heights = std::vector<double>(),
                             const bool recombine = false);
GMSH_API gmshModelGeoRevolve(const vector_pair &dimTags,
                             const double x, const double y, const double z,
                             const double ax, const double ay,
                             const double az, const double angle,
                             vector_pair &outDimTags,
                             const std::vector<int> &numElements = std::vector<int>(),
                             const std::vector<double> &heights = std::vector<double>(),
                             const bool recombine = false);
GMSH_API gmshModelGeoTwist(const vector_pair &dimTags,
                           const double x, const double y, const double z,
                           const double dx, const double dy, const double dz,
                           const double ax, const double ay, const double az,
                           const double angle,
                           vector_pair &outDimTags,
                           const std::vector<int> &numElements = std::vector<int>(),
                           const std::vector<double> &heights = std::vector<double>(),
                           const bool recombine = false);
GMSH_API gmshModelGeoTranslate(const vector_pair &dimTags,
                               const double dx, const double dy, const double dz);
GMSH_API gmshModelGeoRotate(const vector_pair &dimTags, const double x, const double y,
                            const double z, const double ax, const double ay,
                            const double az, const double angle);
GMSH_API gmshModelGeoDilate(const vector_pair &dimTags, const double x, const double y,
                            const double z, const double a, const double b,
                            const double c);
GMSH_API gmshModelGeoSymmetry(const vector_pair &dimTags, const double a, const double b,
                              const double c, const double d);
GMSH_API gmshModelGeoCopy(const vector_pair &dimTags, vector_pair &outDimTags);
GMSH_API gmshModelGeoRemove(const vector_pair &dimTags, const bool recursive = false);
GMSH_API gmshModelGeoRemoveAllDuplicates();
GMSH_API gmshModelGeoSetMeshSize(const vector_pair &dimTags, const double size);
GMSH_API gmshModelGeoSetTransfiniteLine(const int tag, const int nPoints,
                                        const std::string &type = "Progression",
                                        const double coef = 1.);
GMSH_API gmshModelGeoSetTransfiniteSurface(const int tag,
                                           const std::string &arrangement = "Left",
                                           const std::vector<int> &cornerTags =
                                           std::vector<int>());
GMSH_API gmshModelGeoSetTransfiniteVolume(const int tag,
                                          const std::vector<int> &cornerTags =
                                          std::vector<int>());
GMSH_API gmshModelGeoSetRecombine(const int dim, const int tag, const double angle = 45.);
GMSH_API gmshModelGeoSetSmoothing(const int dim, const int tag, const int val);
GMSH_API gmshModelGeoSetReverseMesh(const int dim, const int tag, const bool val = true);
GMSH_API gmshModelGeoSynchronize();

// -----------------------------------------------------------------------------
// Section "gmshModelOcc": OpenCASCADE CAD kernel functions for current model
// -----------------------------------------------------------------------------

GMSH_API gmshModelOccAddPoint(const int tag, const double x, const double y,
                              const double z, const double meshSize = 0.);
GMSH_API gmshModelOccAddLine(const int tag, const int startTag, const int endTag);
GMSH_API gmshModelOccAddCircleArc(const int tag, const int startTag, const int centerTag,
                                  const int endTag);
GMSH_API gmshModelOccAddCircle(const int tag, const double x, const double y,
                               const double z, const double r,
                               const double angle1 = 0., const double angle2 = 2*M_PI);
GMSH_API gmshModelOccAddEllipseArc(const int tag, const int startTag, const int centerTag,
                                   const int endTag);
GMSH_API gmshModelOccAddEllipse(const int tag, const double x, const double y,
                                const double z, const double r1, const double r2,
                                const double angle1 = 0.,
                                const double angle2 = 2*M_PI);
GMSH_API gmshModelOccAddSpline(const int tag, const std::vector<int> &vertexTags);
GMSH_API gmshModelOccAddBezier(const int tag, const std::vector<int> &vertexTags);
GMSH_API gmshModelOccAddBSpline(const int tag, const std::vector<int> &vertexTags);
GMSH_API gmshModelOccAddWire(const int tag, const std::vector<int> &edgeTags,
                             const bool checkClosed = false);
GMSH_API gmshModelOccAddLineLoop(const int tag, const std::vector<int> &edgeTags);
GMSH_API gmshModelOccAddRectangle(const int tag, const double x, const double y,
                                  const double z, const double dx, const double dy,
                                  const double roundedRadius = 0.);
GMSH_API gmshModelOccAddDisk(const int tag, const double xc, const double yc,
                             const double zc, const double rx, const double ry);
GMSH_API gmshModelOccAddPlaneSurface(const int tag, const std::vector<int> &wireTags);
GMSH_API gmshModelOccAddSurfaceFilling(const int tag, int wireTag);
GMSH_API gmshModelOccAddSurfaceLoop(const int tag, const std::vector<int> &faceTags);
GMSH_API gmshModelOccAddVolume(const int tag, const std::vector<int> &shellTags);
GMSH_API gmshModelOccAddSphere(const int tag, const double xc, const double yc,
                               const double zc, const double radius,
                               const double angle1 = -M_PI/2,
                               const double angle2 = M_PI/2,
                               const double angle3 = 2*M_PI);
GMSH_API gmshModelOccAddBox(const int tag, const double x, const double y,
                            const double z, const double dx, const double dy,
                            const double dz);
GMSH_API gmshModelOccAddCylinder(const int tag, const double x, const double y,
                                 const double z, const double dx, const double dy,
                                 const double dz, const double r,
                                 double angle = 2*M_PI);
GMSH_API gmshModelOccAddCone(const int tag, const double x, const double y,
                             const double z, const double dx, const double dy,
                             const double dz, const double r1, const double r2,
                             const double angle = 2*M_PI);
GMSH_API gmshModelOccAddWedge(const int tag, const double x, const double y,
                              const double z, const double dx, const double dy,
                              const double dz, const double ltx = 0.);
GMSH_API gmshModelOccAddTorus(const int tag, const double x, const double y,
                              const double z, const double r1, const double r2,
                              const double angle = 2*M_PI);
GMSH_API gmshModelOccAddThruSections(const int tag, const std::vector<int> &wireTags,
                                     vector_pair &outDimTags, const bool makeSolid = true,
                                     const bool makeRuled = false);
GMSH_API addThickSolid(const int tag, const int solidTag,
                       const std::vector<int> &excludeFaceTags,
                       const double offset, vector_pair &outDimTags);
GMSH_API gmshModelOccExtrude(const vector_pair &dimTags, const double dx, const double dy,
                             const double dz, vector_pair &outDimTags,
                             const std::vector<int> &numElements = std::vector<int>(),
                             const std::vector<double> &heights = std::vector<double>(),
                             const bool recombine = false);
GMSH_API gmshModelOccRevolve(const vector_pair &dimTags,
                             const double x, const double y, const double z,
                             const double ax, const double ay, const double az,
                             const double angle, vector_pair &outDimTags,
                             const std::vector<int> &numElements = std::vector<int>(),
                             const std::vector<double> &heights = std::vector<double>(),
                             const bool recombine = false);
GMSH_API gmshModelOccAddPipe(const vector_pair &dimTags, int wireTag,
                             vector_pair &outDimTags);
GMSH_API gmshModelOccFillet(const std::vector<int> &regionTags,
                            const std::vector<int> &edgeTags,
                            const double radius, vector_pair &outDimTags,
                            const bool removeRegion = true);
GMSH_API gmshModelOccBooleanUnion(const int tag, const vector_pair &objectDimTags,
                                  const vector_pair &toolDimTags,
                                  vector_pair &outDimTags,
                                  std::vector<vector_pair> &outDimTagsMap,
                                  const bool removeObject = true,
                                  const bool removeTool = true);
GMSH_API gmshModelOccBooleanIntersection(const int tag, const vector_pair &objectDimTags,
                                         const vector_pair &toolDimTags,
                                         vector_pair &outDimTags,
                                         std::vector<vector_pair > &outDimTagsMap,
                                         const bool removeObject = true,
                                         const bool removeTool = true);
GMSH_API gmshModelOccBooleanDifference(const int tag, const vector_pair &objectDimTags,
                                       const vector_pair &toolDimTags,
                                       vector_pair &outDimTags,
                                       std::vector<vector_pair > &outDimTagsMap,
                                       const bool removeObject = true,
                                       const bool removeTool = true);
GMSH_API gmshModelOccBooleanFragments(const int tag, const vector_pair &objectDimTags,
                                      const vector_pair &toolDimTags,
                                      vector_pair &outDimTags,
                                      std::vector<vector_pair> &outDimTagsMap,
                                      const bool removeObject = true,
                                      const bool removeTool = true);
GMSH_API gmshModelOccTranslate(const vector_pair &dimTags, const double dx,
                               const double dy, const double dz);
GMSH_API gmshModelOccRotate(const vector_pair &dimTags, const double x,
                            const double y, const double z, const double ax,
                            const double ay, const double az, const double angle);
GMSH_API gmshModelOccDilate(const vector_pair &dimTags, const double x,
                            const double y, const double z, const double a,
                            const double b, const double c);
GMSH_API gmshModelOccSymmetry(const vector_pair &dimTags, const double a,
                              const double b, const double c, const double d);
GMSH_API gmshModelOccCopy(const vector_pair &dimTags, vector_pair &outDimTags);
GMSH_API gmshModelOccRemove(const vector_pair &dimTags, const bool recursive = false);
GMSH_API gmshModelOccRemoveAllDuplicates();
GMSH_API gmshModelOccImportShapes(const std::string &fileName, vector_pair &outDimTags,
                                  const bool highestDimOnly = true,
                                  const std::string &format = "");
GMSH_API gmshModelOccSetMeshSize(const vector_pair &dimTags, const double size);
GMSH_API gmshModelOccSynchronize();

// -----------------------------------------------------------------------------
// Section "gmshModelField": mesh size field functions for current model
// -----------------------------------------------------------------------------

GMSH_API gmshModelFieldCreate(const int tag, const std::string &type);
GMSH_API gmshModelFieldDelete(const int tag);
GMSH_API gmshModelFieldSetNumber(const int tag, const std::string &option,
                                 const double value);
GMSH_API gmshModelFieldSetString(const int tag, const std::string &option,
                                 const std::string &value);
GMSH_API gmshModelFieldSetNumbers(const int tag, const std::string &option,
                                  const std::vector<double> &value);
GMSH_API gmshModelFieldSetAsBackground(const int tag);

#undef GMSH_API

#endif
