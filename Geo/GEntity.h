#ifndef _GENTITY_H_
#define _GENTITY_H_

#include "Range.h"
#include "SPoint3.h"
#include "SBoundingBox3d.h"
#include "MVertex.h"
#include "GmshDefines.h"
#include <list>
#include <vector>
#include <string>

class GModel;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MRep;

// A geometric model entity. All enitites are owned by a GModel.
class GEntity {

 private:
  GModel *_model;
  int _tag;
  MRep *_geom, *_mesh;
  char _visible, _flag;

 public:

  // All known entity types
  enum GeomType {
    Unknown,
    Point,
    Line,
    Circle,
    Ellipse,
    ParametricCurve,
    DiscreteCurve,
    Plane,
    Nurb,
    Cylinder,
    Sphere,
    Cone,
    Torus,
    ParametricSurface,
    DiscreteSurface,
    Volume
  };

  virtual std::string getTypeString()
  {
    char *name[] = {
      "Unknown",
      "Point",
      "Line",
      "Circle",
      "Ellipse",
      "Parametric curve",
      "Discrete curve",
      "Plane",
      "Nurb",
      "Cylinder",
      "Sphere",
      "Cone",
      "Torus",
      "Parametric surface",
      "Discrete surface",
      "Volume"
    };
    unsigned int type = (unsigned int)geomType();
    if(type >= sizeof(name) / sizeof(name[0]))
      return "Undefined";
    else
      return name[type];
  }

  GEntity(GModel *m, int t) : _model(m), _tag(t), _visible(true), _flag(0) {}

  virtual ~GEntity() {};

  // Spatial dimension of the entity 
  virtual int dim() const {throw;}

  // Returns true if ent is in the closure of this entity
  virtual int inClosure(GEntity *ent) const {throw;} 

  // Regions that bound this entity or that this entity bounds.
  virtual std::list<GRegion*> regions() const{throw;}

  // Faces that bound this entity or that this entity bounds.
  virtual std::list<GFace*> faces() const{throw;}

  // Edges that bound this entity or that this entity bounds.
  virtual std::list<GEdge*> edges() const{throw;}

  // Vertices that bound this entity.
  virtual std::list<GVertex*> vertices() const{throw;}

  /// Underlying geometric representation of this entity.
  virtual GeomType geomType() const {throw;}

  // True if parametric space is continuous in the "dim" direction.
  virtual bool continuous(int dim) const {return true;}

  // True if entity is periodic in the "dim" direction.
  virtual bool periodic(int dim) const {return false;}

  // True if there are parametric degeneracies in the "dim" direction.
  virtual bool degenerate(int dim) const {return false;}

  // Parametric bounds of the entity in the "i" direction.
  virtual Range<double> parBounds(int i) const{throw;}

  // Modeler tolerance for the entity.
  virtual double tolerance() const {return 1.e-14;}

  // True if the entity contains the given point to within tolerance.
  virtual int containsPoint(const SPoint3 &pt) const{throw;}

  // Get the native pointer of the particular representation
  virtual void * getNativePtr() const {throw;}

  // The model owning this entity.
  GModel *model() const {return _model;}

  // The tag of the entity
  int tag () const {return _tag;}

  // The bounding box
  virtual SBoundingBox3d bounds() const{throw;}

  // get/set the visibility flag
  virtual char getVisibility(){ return _visible; }
  virtual void setVisibility(char val, bool recursive=false){ _visible = val; }

  // get/set the multi-purpose flag
  virtual char getFlag(){ return _flag; }
  virtual void setFlag(char val){ _flag = val; }

  // Returns a renderable representation of the geometry
  virtual MRep *geomRep(){ return _geom; }

  // Returns a renderable representation of the mesh
  virtual MRep *meshRep(){ return _mesh; }

  // Returns an information string for the entity
  virtual std::string getInfoString();

  // Returns a type-specific additional information string
  virtual std::string getAdditionalInfoString() { return std::string(""); }

  // The mesh vertices uniquely owned by the entity
  std::vector<MVertex*> mesh_vertices;

  // The physical entitites (if any) that contain this entity
  std::vector<int> physicals;
};

class GEntityLessThan {
 public:
  bool operator()(const GEntity *ent1, const GEntity *ent2) const
  {
    return ent1->tag() < ent2->tag();
  }
};

#endif
