// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSH_H_
#define _GMSH_H_

// This is the embryo of what will become the Gmsh API.
//
// Don't use it yet, it's not ready :-) We plan to release a first version in
// Gmsh 3.1, and something more complete in Gmsh 4.0.
//
// Your input is welcome: please contribute your ideas on
// https://gitlab.onelab.info/gmsh/gmsh/issues/188
//
// By design, the API is purely functional, and only uses elementary C++ types
// from the standard library. This design should not and will not change.

// All functions return 0 as the first entry of the returned vector on
// successful completion. Additional integer results can be appended to this
// returned value, depending on context.

#include <cmath>
#include <vector>
#include <string>

#if defined(WIN32)
#define GMSH_API __declspec(dllexport) std::vector<int>
#else
#define GMSH_API std::vector<int>
#endif

typedef std::vector<std::pair<int, int> > vector_pair;

// gmsh
GMSH_API gmshInitialize(int argc = 0, char **argv = 0);
GMSH_API gmshFinalize();
GMSH_API gmshOpen(const std::string &fileName);
GMSH_API gmshMerge(const std::string &fileName);
GMSH_API gmshExport(const std::string &fileName);
GMSH_API gmshClear();

// gmshOption
GMSH_API gmshOptionSetNumber(const std::string &name, const double value);
GMSH_API gmshOptionGetNumber(const std::string &name, double &value);
GMSH_API gmshOptionSetString(const std::string &name, const std::string &value);
GMSH_API gmshOptionGetString(const std::string &name, std::string &value);

// gmshModel
GMSH_API gmshModelCreate(const std::string &name);
GMSH_API gmshModelDelete();
GMSH_API gmshModelSetCurrent(const std::string &name);
GMSH_API gmshModelGetEntities(vector_pair &dimTags, const int dim=-1);
GMSH_API gmshModelGetPhysicalGroups(vector_pair &dimTags, const int dim=-1);
GMSH_API gmshModelAddPhysicalGroup(const int dim, const int tag,
                                   const std::vector<int> &tags);
GMSH_API gmshModelGetEntitiesForPhysicalGroup(const int dim, const int tag,
                                              std::vector<int> &tags);
GMSH_API gmshModelSetPhysicalName(const int dim, const int tag,
                                  const std::string &name);
GMSH_API gmshModelGetPhysicalName(const int dim, const int tag,
                                  std::string &name);
GMSH_API gmshModelGetBoundary(const vector_pair &inDimTags, vector_pair &outDimTags,
                              const bool combined = true, const bool oriented = true,
                              const bool recursive = false);
GMSH_API gmshModelGetEntitiesInBoundingBox(const double x1, const double y1,
                                           const double z1, const double x2,
                                           const double y2, const double z2,
                                           vector_pair &tags, const int dim=-1);
GMSH_API gmshModelGetBoundingBox(const int dim, const int tag, double &x1, double &y1,
                                 double &z1, double &x2, double &y2, double &z2);
GMSH_API gmshModelRemove(const vector_pair &dimTags, const bool recursive = false);
GMSH_API gmshModelMesh(const int dim);
GMSH_API gmshModelGetMeshVertices(const int dim, const int tag,
                                  std::vector<int> &vertexTags,
                                  std::vector<double> &coordinates,
                                  std::vector<double> &parametricCoordinates);
GMSH_API gmshModelGetMeshElements(const int dim, const int tag,
                                  std::vector<int> &types,
                                  std::vector<std::vector<int> > &elementTags,
                                  std::vector<std::vector<int> > &vertexTags);
GMSH_API gmshModelSetMeshSize(const vector_pair &dimTags, const double size);
GMSH_API gmshModelSetTransfiniteLine(const int tag, const int nPoints,
                                     const std::string &type = "Progression",
                                     const double coef = 1.);
GMSH_API gmshModelSetTransfiniteSurface(const int tag,
                                        const std::string &arrangement = "Left",
                                        const std::vector<int> &cornerTags =
                                        std::vector<int>());
GMSH_API gmshModelSetTransfiniteVolume(const int tag,
                                       const std::vector<int> &cornerTags =
                                       std::vector<int>());
GMSH_API gmshModelSetRecombine(const int dim, const int tag, const double angle = 45.);
GMSH_API gmshModelSetSmoothing(const int dim, const int tag, const int val);
GMSH_API gmshModelSetReverseMesh(const int dim, const int tag, const bool val = true);
GMSH_API gmshModelEmbed(const int dim, const std::vector<int> &tags, const int inDim,
                        const int inTag);

// gmshModelGeo
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
GMSH_API gmshModelGeoExtrude(const vector_pair &inDimTags,
                             const double dx, const double dy, const double dz,
                             vector_pair &outDimTags,
                             const std::vector<int> &numElements = std::vector<int>(),
                             const std::vector<double> &heights = std::vector<double>(),
                             const bool recombine = false);
GMSH_API gmshModelGeoRevolve(const vector_pair &inDimTags,
                             const double x, const double y, const double z,
                             const double ax, const double ay,
                             const double az, const double angle,
                             vector_pair &outDimTags,
                             const std::vector<int> &numElements = std::vector<int>(),
                             const std::vector<double> &heights = std::vector<double>(),
                             const bool recombine = false);
GMSH_API gmshModelGeoTwist(const vector_pair &inDimTags,
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
GMSH_API gmshModelGeoCopy(const vector_pair &inDimTags, vector_pair &outDimTags);
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

// gmshModelOcc
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
GMSH_API gmshModelOccExtrude(const vector_pair &inDimTags, const double dx, const double dy,
                             const double dz, vector_pair &outDimTags,
                             const std::vector<int> &numElements = std::vector<int>(),
                             const std::vector<double> &heights = std::vector<double>(),
                             const bool recombine = false);
GMSH_API gmshModelOccRevolve(const vector_pair &inDimTags,
                             const double x, const double y, const double z,
                             const double ax, const double ay, const double az,
                             const double angle, vector_pair &outDimTags,
                             const std::vector<int> &numElements = std::vector<int>(),
                             const std::vector<double> &heights = std::vector<double>(),
                             const bool recombine = false);
GMSH_API gmshModelOccAddPipe(const vector_pair &inDimTags, int wireTag,
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
GMSH_API gmshModelOccCopy(const vector_pair &inDimTags, vector_pair &outDimTags);
GMSH_API gmshModelOccRemove(const vector_pair &dimTags, const bool recursive = false);
GMSH_API gmshModelOccRemoveAllDuplicates();
GMSH_API gmshModelOccImportShapes(const std::string &fileName, vector_pair &outDimTags,
                                  const bool highestDimOnly = true,
                                  const std::string &format = "");
GMSH_API gmshModelOccSetMeshSize(const vector_pair &dimTags, const double size);
GMSH_API gmshModelOccSynchronize();

// gmshModelField

GMSH_API gmshModelFieldCreate(const int tag, const std::string &type);
GMSH_API gmshModelFieldDelete(const int tag);
GMSH_API gmshModelFieldSetNumber(const int tag, const std::string &option,
                                 const double value);
GMSH_API gmshModelFieldSetString(const int tag, const std::string &option,
                                 const std::string &value);
GMSH_API gmshModelFieldSetNumbers(const int tag, const std::string &option,
                                  const std::vector<double> &value);
GMSH_API gmshModelFieldSetAsBackground(const int tag);

// gmshView

// gmshPlugin

// gmshGraphics

#undef GMSH_API

#endif
