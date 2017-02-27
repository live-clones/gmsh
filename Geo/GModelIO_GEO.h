// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMODELIO_GEO_H_
#define _GMODELIO_GEO_H_

#include "ListUtils.h"
#include "TreeUtils.h"

class gmshSurface;
class GModel;

class GEO_Internals{
 public:
  Tree_T *Points, *Curves, *EdgeLoops, *Surfaces, *SurfaceLoops, *Volumes;
  Tree_T *DelPoints, *DelCurves, *DelSurfaces, *DelVolumes;
  List_T *PhysicalGroups, *DelPhysicalGroups;
 private:
  std::multimap<int, std::vector<int> > _meshCompounds;
  int _maxPointNum, _maxLineNum, _maxLineLoopNum, _maxSurfaceNum;
  int _maxSurfaceLoopNum, _maxVolumeNum, _maxPhysicalNum;
  void _allocateAll();
  void _freeAll();
  bool _changed;
  void _transform(std::vector<int> tags[4], int mode,
                  double x, double y, double z,
                  double dx, double dy, double dz,
                  double a, double b, double c, double d);
 public:
  GEO_Internals(){ _allocateAll(); }
  ~GEO_Internals(){ _freeAll(); }
  void destroy(){ _freeAll(); _allocateAll(); }

  // have the internals changed since the last synchronisation?
  bool getChanged() const { return _changed; }

  // set/get max tag of entity for each dimension (0, 1, 2, 3), as well as
  // -2 for shells and -1 for wires
  void setMaxTag(int dim, int val);
  int getMaxTag(int dim) const;

  // add shapes
  void addVertex(int num, double x, double y, double z, double lc);
  void addVertex(int num, double x, double y, gmshSurface *s, double lc);
  void addLine(int num, int startTag, int endTag);
  void addLine(int num, std::vector<int> vertexTags);
  void addCircleArc(int num, int startTag, int centerTag, int EndTag,
                    double nx=0., double ny=0., double nz=0.);
  void addEllipseArc(int num, int startTag, int centerTag, int majorTag,
                     int endTag, double nx=0., double ny=0., double nz=0.);
  void addSpline(int num, std::vector<int> vertexTags);
  void addBSpline(int num, std::vector<int> vertexTags);
  void addBezier(int num, std::vector<int> vertexTags);
  void addNurbs(int num, std::vector<int> vertexTags, std::vector<double> knots);
  void addCompoundLine(int num, std::vector<int> edgeTags);
  void addLineLoop(int num, std::vector<int> edgeTags);
  void addPlaneSurface(int num, std::vector<int> wireTags);
  void addDiscreteSurface(int num);
  void addSurfaceFilling(int num, std::vector<int> wireTags, int sphereCenterTag=-1);
  void addSurfaceLoop(int num, std::vector<int> faceTags);
  void addCompoundSurface(int num, std::vector<int> faceTags,
                          std::vector<int> edgeTags[4]=0);
  void addVolume(int num, std::vector<int> shellTags);
  void addCompoundVolume(int num, std::vector<int> regionTags);

  // apply transformations
  void translate(std::vector<int> tags[4], double dx, double dy, double dz);
  void rotate(std::vector<int> tags[4], double x, double y, double z,
              double dx, double dy, double dz, double angle);
  void dilate(std::vector<int> tags[4], double x, double y, double z,
              double a, double b, double c);
  void symmetry(std::vector<int> tags[4], double a, double b, double c, double d);

  // copy and remove
  int copy(int dim, int tag);
  void remove(int dim, int tag);

  // manipulate physical groups
  void resetPhysicalGroups();
  void modifyPhysicalGroup(int dim, int num, int op, std::vector<int> tags);
  int getMaxPhysicalTag() const { return _maxPhysicalNum; }
  void setMaxPhysicalTag(int val) { _maxPhysicalNum = val; }

  // coherence
  void removeAllDuplicates();
  void mergeVertices(std::vector<int> tags);

  // set meshing constraints
  void setCompoundMesh(int dim, std::vector<int> tags);
  void setMeshSize(int dim, int tag, double size);
  void setDegenerated(int dim, int tag);
  void setTransfiniteLine(int tag, int nPoints, int type, double coef);
  void setTransfiniteSurface(int tag, int arrangement, std::vector<int> cornerTags);
  void setTransfiniteVolume(int tag, std::vector<int> cornerTags);
  void setTransfiniteVolumeQuadTri(int tag);
  void setRecombine(int dim, int tag, double angle);
  void setSmoothing(int tag, int val);
  void setReverseMesh(int dim, int tag);

  // synchronize internal CAD data with the given GModel
  void synchronize(GModel *model);

  // queries
  bool getVertex(int tag, double &x, double &y, double &z);

  // create coordinate systems
  gmshSurface *newGeometrySphere(int num, int centerTag, int pointTag);
  gmshSurface *newGeometryPolarSphere(int num, int centerTag, int pointTag);
};

#endif
