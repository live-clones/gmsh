#ifndef H_GEntity
#define H_GEntity

class GModel;
class MeshRep;

/** A geometric model entity. All enitites are owned by a GModel. */
class GEntity {
  int tag;
  GModel *model;
  DiscreteRep *mesh, *modelMesh;
public:
  GEntity(GModel *model, int tag);
  virtual ~GEntity();

  /** Return a renderable representation of the entity.*/
  virtual MeshRep * getGeometry() ;
  /** Return a mesh of the entity */
  virtual MeshRep * getMesh()  ;

  /// Spatial dimension of the entity. 
  virtual int dim() const = 0;

  /** Returns true if ent is in the closure of this entity */
  virtual int inClosure(GEntity *ent) const =0; 

  /// Regions that bound this entity or that this entity bounds.
  virtual std::list<GRegion*> regions() const;

  /// Faces that bound this entity or that this entity bounds.
  virtual std::list<GFace*> faces() const;

  /// Edges that bound this entity or that this entity bounds.
  virtual std::list<GEdge*> edges() const;

  /// Vertices that bound this entity.
  virtual std::list<GVertex*> vertices() const;

  /// Underlying geometric representation of this entity.
  virtual GeomType geomType() const = 0;

  /// True if parametric space is continuous in the "dim" direction.
  virtual bool continuous(int dim) const;

  /// True if entity is periodic in the "dim" direction.
  virtual bool periodic(int dim) const;

  /// True if there are parametric degeneracies in the "dim" direction.
  virtual bool degenerate(int dim) const;

  /// Orientation of the parametric space w.r.t. the entity.
  virtual int geomDirection() const;

  /// Parametric bounds of the entity in the "i" direction.
  virtual Range<double> parBounds(int i) const;

  /// Modeler tolerance for the entity.
  virtual double tolerance() const;

  /// True if the entity contains the given point to within tolerance.
  virtual int containsPoint(const SPoint3 &pt) const;

  /// Get the native pointer of the particular representation
  virtual void * getNativePtr() const= 0;

  /// The model owning this entity.
  GModel *model() const;
};


#endif


