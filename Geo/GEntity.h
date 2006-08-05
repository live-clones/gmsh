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

  virtual std::string getSpecificInfoString() 
  {
    return "";
  }

  virtual std::string getInfoString() 
  {
    char str[256];
    sprintf(str, "%s %d", getTypeString().c_str(), tag());
    std::string specific = getSpecificInfoString();
    if(specific.size()){
      strcat(str, " ");
      strcat(str, specific.c_str());
    }
    if(physicals.size()){
      char str2[256] = " [";
      for(unsigned int i = 0; i < physicals.size(); i++){
	char str3[256];
	sprintf(str3, "%d", physicals[i]);
	if(i) strcat(str2, " ");
	strcat(str2, str3);
      }
      strcat(str2, "]");
      strcat(str, str2);
    }
    return std::string(str);
  }

  GEntity(GModel *m, int t) : _model(m), _tag(t)
  {
    drawAttributes.Visible = VIS_GEOM | VIS_MESH; 
    drawAttributes.Frozen = 0; 
  }

  virtual ~GEntity() {};

  // Spatial dimension of the entity 
  virtual int dim() const = 0;

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
  virtual GeomType geomType() const = 0;

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
  virtual void * getNativePtr() const= 0;

  // The model owning this entity.
  GModel *model() const {return _model;}

  // The tag of the entity
  int tag () const {return _tag;}

  // The bounding box
  virtual SBoundingBox3d bounds() const{throw;}

  // The mesh vertices uniquely owned by the entity
  std::vector<MVertex*> mesh_vertices;

  // The physical entitites (if any) that contain this entity
  std::vector<int> physicals;

  // The standard drawing attributes of the entity
  struct {
    char Visible, Frozen;
  } drawAttributes ;

  // Returns a renderable representation of the geometry
  virtual MRep *geomRep(){ return _geom; }

  // Returns a renderable representation of the mesh
  virtual MRep *meshRep(){ return _mesh; }
};

// A minimal, non-abstract entity that can be used for sorting
class dummyEntity : public GEntity {
public:
  dummyEntity(GModel *model, int tag) : GEntity(model, tag){}
  virtual int dim() const {return -1;}
  virtual GeomType geomType() const {return Unknown;}
  virtual void * getNativePtr() const {return 0;}
};

class EntityLessThan {
 public:
  bool operator()(const GEntity *ent1, const GEntity *ent2) const
  {
    return ent1->tag() < ent2->tag();
  }
};

#endif
