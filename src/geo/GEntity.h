// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GENTITY_H
#define GENTITY_H

#include <list>
#include <string>
#include <vector>
#include <set>
#include "Range.h"
#include "SPoint3.h"
#include "SBoundingBox3d.h"
#include "SOrientedBoundingBox.h"
#include "affineTransformation.h"

#define MAX_LC 1.e22

class GModel;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MVertex;
class MElement;
class VertexArray;

// A geometric model entity.
class GEntity {
private:
  // all entities are owned by a GModel
  GModel *_model;

  // the tag (the number) of this entity
  int _tag;

  // points to the master entity in periodic mesh, or 'this' if non-periodic
  GEntity *_meshMaster;

  // the visibility and the selection flag
  char _visible, _selection;

  // flag storing if only some mesh elements are visible
  char _onlySomeElementsVisible;

  // the color of the entity (ignored if set to transparent blue)
  unsigned int _color;

protected:
  // the oriented bounding box of the entity
  SOrientedBoundingBox *_obb;

public: // these will become protected at some point
  // the mesh vertices uniquely owned by the entity
  std::vector<MVertex *> mesh_vertices;

  // a list of geometrical entities that form a compound mesh
  std::vector<GEntity *> compound;

  // the corresponding principal points of the entity in case of periodic mesh
  std::map<GVertex *, GVertex *> vertexCounterparts;

  // the physical groups that contain this entity
  std::vector<int> physicals;

  // the vertex arrays to draw the mesh of the entity efficiently
  VertexArray *va_lines, *va_triangles;

  // the set of high-order elements fixed by the "fast curving" boundary layer
  // optimization
  std::set<MElement *> curvedBLElements;

public:
  // make a set of all the vertices in the entity, with/without closure
  void addVerticesInSet(std::set<MVertex *> &, bool closure) const;

public:
  // all known native model types
  enum ModelType {
    UnknownModel,
    GmshModel,
    OpenCascadeModel,
    AcisModel,
    ParasolidModel
  };

  // all known entity types
  enum GeomType {
    Unknown,
    Point,
    BoundaryLayerPoint,
    Line,
    Circle,
    Ellipse,
    Conic,
    Parabola,
    Hyperbola,
    TrimmedCurve,
    OffsetCurve,
    BSpline,
    Bezier,
    ParametricCurve,
    BoundaryLayerCurve,
    DiscreteCurve,
    Plane,
    Nurb,
    Cylinder,
    Sphere,
    Cone,
    Torus,
    RuledSurface,
    ParametricSurface,
    BSplineSurface,
    BezierSurface,
    SurfaceOfRevolution,
    BoundaryLayerSurface,
    DiscreteSurface,
    DiscreteDiskSurface,
    Volume,
    DiscreteVolume,
    PartitionPoint,
    PartitionCurve,
    PartitionSurface,
    PartitionVolume,
    GhostCurve,
    GhostSurface,
    GhostVolume
  };

  // the mesh generation status
  enum MeshGenerationStatus { PENDING, DONE, FAILED };

  // return a string describing the entity type
  virtual std::string getTypeString()
  {
    const char *name[] = {
      "Unknown",
      "Point",
      "Boundary layer point",
      "Line",
      "Circle",
      "Ellipse",
      "Conic",
      "Parabola",
      "Hyperbola",
      "TrimmedCurve",
      "OffsetCurve",
      "BSpline",
      "Bezier",
      "Parametric curve",
      "Boundary layer curve",
      "Discrete curve",
      "Plane",
      "Nurb",
      "Cylinder",
      "Sphere",
      "Cone",
      "Torus",
      "Surface",
      "Parametric surface",
      "BSpline surface",
      "Bezier surface",
      "Surface of Revolution",
      "Boundary layer surface",
      "Discrete surface",
      "Discrete surface (parametrizable, isomorphic to a disk)",
      "Volume",
      "Discrete volume",
      "Partition point",
      "Partition curve",
      "Partition surface",
      "Partition volume",
      "Ghost curve",
      "Ghost surface",
      "Ghost volume"};
    unsigned int type = (unsigned int)geomType();
    if(type >= sizeof(name) / sizeof(name[0]))
      return "Undefined";
    else
      return name[type];
  }

  GEntity(GModel *m, int t);

  virtual ~GEntity() {}

  // mesh generation of the entity
  virtual void mesh(bool verbose) {}

  // delete the mesh data
  virtual void deleteMesh() {}

  // delete the mesh vertex arrays, used to to draw the mesh efficiently
  void deleteVertexArrays();

  // delete the geometry vertex arrays, used to to draw the geometry efficiently
  virtual void deleteGeometryVertexArrays() {}

  // spatial dimension of the entity
  virtual int dim() const { return -1; }

  // returns the parent entity for partitioned entities
  virtual GEntity *getParentEntity() { return nullptr; }

  // regions that bound this entity or that this entity bounds
  virtual std::list<GRegion *> regions() const
  {
    return std::list<GRegion *>();
  }

  // faces that bound this entity or that this entity bounds
  virtual std::vector<GFace *> faces() const { return std::vector<GFace *>(); }

  // edges that bound this entity or that this entity bounds
  virtual std::vector<GEdge *> const &edges() const
  {
    static std::vector<GEdge *> i;
    return i;
  }

  // vertices that bound this entity
  virtual std::vector<GVertex *> vertices() const
  {
    return std::vector<GVertex *>();
  }

  // is this entity an orphan?
  virtual bool isOrphan() { return false; }

  // for Python, temporary solution while iterators are not binded
  std::vector<GRegion *> bindingsGetRegions()
  {
    // NOTE: two-line to not create two different lists with diff pointers
    std::list<GRegion *> r = regions();
    return std::vector<GRegion *>(r.begin(), r.end());
  }
  std::vector<GFace *> bindingsGetFaces() { return faces(); }
  std::vector<GEdge *> bindingsGetEdges() const { return edges(); }
  std::vector<GVertex *> bindingsGetVertices() { return vertices(); }

  // underlying geometric representation of this entity
  virtual GeomType geomType() const { return Unknown; }

  // true if parametric space is continuous in the "dim" direction
  virtual bool continuous(int dim) const { return true; }

  // true if entity is periodic in the "dim" direction
  virtual bool periodic(int dim) const { return false; }
  virtual double period(int dim) const { return 0.0; }

  // true if there are parametric degeneracies in the "dim" direction
  virtual bool degenerate(int dim) const { return false; }

  // does the entity have a parametrization?
  virtual bool haveParametrization() { return true; }

  // is the entity and its bounding entities fully discrete (i.e. without
  // parametrization for curves and surfaces), and should thus not be
  // (re)meshed?
  virtual bool isFullyDiscrete() { return !haveParametrization(); }

  // parametric bounds of the entity in the "i" direction
  virtual Range<double> parBounds(int i) const { return Range<double>(0., 0.); }

  // modeler tolerance for the entity
  virtual double tolerance() const { return 1.e-14; }

  // true if the entity contains the given point to within tolerance
  virtual bool containsPoint(const SPoint3 &pt) const { return false; }

  // get the native type of the particular representation
  virtual ModelType getNativeType() const { return UnknownModel; }

  // get the native pointer of the particular representation
  virtual void *getNativePtr() const { return nullptr; }

  // get the native id (int) of the particular representation
  virtual int getNativeInt() const { return 0; }

  // the model owning this entity
  GModel *model() const { return _model; }

  // get/set the tag of the entity
  int tag() const { return _tag; }
  void setTag(int tag) { _tag = tag; }

  // get/set physical entities
  virtual void addPhysicalEntity(int physicalTag)
  {
    physicals.push_back(physicalTag);
  }
  virtual std::vector<int> getPhysicalEntities() { return physicals; }

  // handle the master entity for periodic meshes
  GEntity *getMeshMaster() const { return _meshMaster; }
  void setMeshMaster(GEntity *);
  void setMeshMaster(GEntity *, const std::vector<double> &,
                     bool updateCorrespondingVertices = true);
  void updateCorrespondingVertices();
  void copyMasterCoordinates();
  virtual void alignElementsWithMaster() {}

  // get the bounding box
  virtual SBoundingBox3d bounds(bool fast = false) { return SBoundingBox3d(); }

  // get the oriented bounding box
  virtual SOrientedBoundingBox getOBB() { return SOrientedBoundingBox(); }

  // get/set the visibility flag
  virtual char getVisibility();
  virtual void setVisibility(char val, bool recursive = false)
  {
    _visible = val;
  }

  // get/set the selection flag
  virtual char getSelection() { return _selection; }
  virtual void setSelection(char val) { _selection = val; }

  // get/set the color
  virtual unsigned int getColor() { return _color; }
  virtual void setColor(unsigned color, bool recursive = false)
  {
    _color = color;
  }

  // return true if we should use this color to represent the entity
  virtual bool useColor();

  // return an information string for the entity
  virtual std::string getInfoString(bool additional = true,
                                    bool multiline = false);

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString(bool multline = false)
  {
    return "";
  }

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes() { return; }

  // global mesh size constraint for the entity
  virtual double getMeshSize() const { return MAX_LC; }
  virtual double getMeshSizeFactor() const { return 1.; }

  // get the family types of elements that could mesh this entity
  virtual void getElementTypes(std::vector<int> &types) const {};

  // get the number of mesh elements (total and by type) in the entity
  virtual std::size_t getNumMeshElements() const { return 0; }
  virtual std::size_t getNumMeshElementsByType(const int familyType) const
  {
    return 0;
  }
  virtual std::size_t getNumMeshParentElements() { return 0; }
  virtual void getNumMeshElements(unsigned *const c) const {}

  // get the start of the array of a type of element
  virtual MElement *const *getStartElementType(int type) const
  {
    return nullptr;
  }

  // get the element at the given index
  virtual MElement *getMeshElement(std::size_t index) const { return nullptr; }
  // get the element at the given index for a given familyType
  virtual MElement *getMeshElementByType(const int familyType,
                                         const std::size_t index) const
  {
    return nullptr;
  }

  // get/set only some mesh element visibility flag
  bool getOnlySomeElementsVisible()
  {
    return _onlySomeElementsVisible ? true : false;
  }
  void setOnlySomeElementsVisible(bool val)
  {
    _onlySomeElementsVisible = val ? 1 : 0;
  }

  // get the number of mesh vertices in the entity
  std::size_t getNumMeshVertices() { return mesh_vertices.size(); }

  // get the mesh vertex at the given index
  MVertex *getMeshVertex(std::size_t index) { return mesh_vertices[index]; }

  // add a mesh vertex
  void addMeshVertex(MVertex *v) { mesh_vertices.push_back(v); }
  // remove a mesh vertex, and delete it as well if del=true (warning: this does
  // not invalidate the mesh cache and vertex arrays, which should be taken care
  // of after a delete)
  void removeMeshVertex(MVertex *v, bool del=false);

  // add a mesh element
  virtual void addElement(MElement *e) {}
  // remove an element or all the elements, and delete as well if del=true
  // (warning: this does not invalidate the mesh cache and vertex arrays, which
  // should be taken care of after a delete)
  virtual void removeElement(MElement *e, bool del=false) {}
  virtual void removeElements(bool del=false) {}

  // relocate mesh vertices using their parametric coordinates
  virtual void relocateMeshVertices() {}

  // clean downcasts
  GVertex *cast2Vertex();
  GEdge *cast2Edge();
  GFace *cast2Face();
  GRegion *cast2Region();

  // transformation from master
  std::vector<double> affineTransform;

  // corresponding mesh vertices
  std::map<MVertex *, MVertex *> correspondingVertices;

  // corresponding high order mesh vertices
  std::map<MVertex *, MVertex *> correspondingHighOrderVertices;

  // reorder the mesh elements of the given type, according to ordering
  virtual bool reorder(const int elementType,
                       const std::vector<std::size_t> &ordering)
  {
    return false;
  }
};

struct GEntityPtrLessThan {
  // beware that this comparison function does *not* compare the entity
  // dimension; this is on purpose
  bool operator()(const GEntity *ent1, const GEntity *ent2) const
  {
    return ent1->tag() < ent2->tag();
  }
};

struct GEntityPtrFullLessThan {
  bool operator()(const GEntity *ent1, const GEntity *ent2) const
  {
    if(ent1->dim() != ent2->dim()) return ent1->dim() < ent2->dim();
    return ent1->tag() < ent2->tag();
  }
};

struct GEntityPtrFullEqual {
  bool operator()(const GEntity *ent1, const GEntity *ent2) const
  {
    return (ent1->dim() == ent2->dim()) && (ent1->tag() == ent2->tag());
  }
};

struct GEntityPtrFullHash {
  size_t operator()(GEntity const *const ent) const
  {
    return 10 * ent->tag() + ent->dim();
  }
};

#endif
