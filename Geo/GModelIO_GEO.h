// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMODELIO_GEO_H
#define GMODELIO_GEO_H

class GModel;
class ExtrudeParams;
class gmshSurface;
class List_T;
class Tree_T;

class GEO_Internals {
public:
  // this will become private
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
  bool _transform(int mode, const std::vector<std::pair<int, int> > &dimTags,
                  double x, double y, double z, double dx, double dy, double dz,
                  double a, double b, double c, double d);
  bool _extrude(int mode, const std::vector<std::pair<int, int> > &inDimTags,
                double x, double y, double z, double dx, double dy, double dz,
                double ax, double ay, double az, double angle,
                std::vector<std::pair<int, int> > &outDimTags,
                ExtrudeParams *e = 0);
  bool _addCompoundSpline(int &tag, const std::vector<int> &curveTags,
                          int numPoints, bool bspline);

public:
  GEO_Internals() { _allocateAll(); }
  ~GEO_Internals() { _freeAll(); }
  void destroy()
  {
    _freeAll();
    _allocateAll();
  }

  // have the internals changed since the last synchronisation?
  bool getChanged() const { return _changed; }

  // set/get max tag of entity for each dimension (0, 1, 2, 3), as well as
  // -2 for shells and -1 for wires
  void setMaxTag(int dim, int val);
  int getMaxTag(int dim) const;

  // add shapes (if tag is < 0, a new tag is automatically created and returned)
  bool addVertex(int &tag, double x, double y, double z, double lc);
  bool addVertex(int &tag, double x, double y, gmshSurface *s, double lc);
  bool addLine(int &tag, int startTag, int endTag);
  bool addLine(int &tag, const std::vector<int> &pointTags);
  bool addCircleArc(int &tag, int startTag, int centerTag, int endTag,
                    double nx = 0., double ny = 0., double nz = 0.);
  bool addEllipseArc(int &tag, int startTag, int centerTag, int majorTag,
                     int endTag, double nx = 0., double ny = 0.,
                     double nz = 0.);
  bool addSpline(int &tag, const std::vector<int> &pointTags);
  bool addBezier(int &tag, const std::vector<int> &pointTags);
  bool addBSpline(int &tag, const std::vector<int> &pointTags,
                  const std::vector<double> &seqknots = std::vector<double>());
  bool addCompoundSpline(int &tag, const std::vector<int> &curveTags,
                         int numPoints);
  bool addCompoundBSpline(int &tag, const std::vector<int> &curveTags,
                          int numPoints);
  bool addCurveLoop(int &tag, const std::vector<int> &curveTags,
                    bool reorient = false);
  bool addCurveLoops(const std::vector<int> &curveTags,
                     std::vector<int> &curveLoopTags);
  bool addPlaneSurface(int &tag, const std::vector<int> &wireTags);
  bool addDiscreteSurface(int &tag);
  bool addSurfaceFilling(int &tag, const std::vector<int> &wireTags,
                         int sphereCenterTag = -1);
  bool addSurfaceLoop(int &tag, const std::vector<int> &surfaceTags);
  bool addVolume(int &tag, const std::vector<int> &shellTags);

  // extrude and revolve
  bool extrude(const std::vector<std::pair<int, int> > &inDimTags, double dx,
               double dy, double dz,
               std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e = 0);
  bool revolve(const std::vector<std::pair<int, int> > &inDimTags, double x,
               double y, double z, double ax, double ay, double az,
               double angle, std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e = 0);
  bool twist(const std::vector<std::pair<int, int> > &inDimTags, double x,
             double y, double z, double dx, double dy, double dz, double ax,
             double ay, double az, double angle,
             std::vector<std::pair<int, int> > &outDimTags,
             ExtrudeParams *e = 0);
  bool boundaryLayer(const std::vector<std::pair<int, int> > &inDimTags,
                     std::vector<std::pair<int, int> > &outDimTags,
                     ExtrudeParams *e = 0);

  // apply transformations
  bool translate(const std::vector<std::pair<int, int> > &dimTags, double dx,
                 double dy, double dz);
  bool rotate(const std::vector<std::pair<int, int> > &dimTags, double x,
              double y, double z, double ax, double ay, double az,
              double angle);
  bool dilate(const std::vector<std::pair<int, int> > &dimTags, double x,
              double y, double z, double a, double b, double c);
  bool symmetry(const std::vector<std::pair<int, int> > &dimTags, double a,
                double b, double c, double d);

  // split entities
  bool splitCurve(int tag, const std::vector<int> &pointTags,
                  std::vector<int> &curveTags);
  bool intersectCurvesWithSurface(const std::vector<int> &curveTags,
                                  int surfaceTag, std::vector<int> &pointTags);

  // copy and remove
  bool copy(const std::vector<std::pair<int, int> > &inDimTags,
            std::vector<std::pair<int, int> > &outDimTags);
  bool remove(int dim, int tag, bool recursive = false);
  bool remove(const std::vector<std::pair<int, int> > &dimTags,
              bool recursive = false);

  // manipulate physical groups
  void resetPhysicalGroups();
  bool modifyPhysicalGroup(int dim, int tag, int op,
                           const std::vector<int> &tags);
  int getMaxPhysicalTag() const { return _maxPhysicalNum; }
  void setMaxPhysicalTag(int val) { _maxPhysicalNum = val; }

  // coherence
  void removeAllDuplicates();
  bool mergeVertices(const std::vector<int> &tags);

  // set meshing constraints
  void setCompoundMesh(int dim, const std::vector<int> &tags);
  void setMeshSize(int dim, int tag, double size);
  void setDegenerated(int dim, int tag);
  void setTransfiniteLine(int tag, int nPoints, int type, double coef);
  void setTransfiniteSurface(int tag, int arrangement,
                             const std::vector<int> &cornerTags);
  void setTransfiniteVolume(int tag, const std::vector<int> &cornerTags);
  void setTransfiniteVolumeQuadTri(int tag);
  void setRecombine(int dim, int tag, double angle);
  void setSmoothing(int tag, int val);
  void setReverseMesh(int dim, int tag, bool val = 1);
  void setMeshAlgorithm(int dim, int tag, int val);
  void setMeshSizeFromBoundary(int dim, int tag, int val);

  // synchronize internal CAD data with the given GModel
  void synchronize(GModel *model, bool resetMeshAttributes = true);

  // queries
  bool getVertex(int tag, double &x, double &y, double &z);

  // create coordinate systems
  gmshSurface *newGeometrySphere(int tag, int centerTag, int pointTag);
  gmshSurface *newGeometryPolarSphere(int tag, int centerTag, int pointTag);
};

#endif
