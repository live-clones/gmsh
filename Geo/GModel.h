#ifndef H_GModel
#define H_GModel

#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

/** A geometric model. The model is a non-manifold B-Rep. */

class GModel  
{
public:
  virtual ~GModel();

  typedef std::list<GRegion*>::const_iterator riter;
  typedef std::list<GFace*>::const_iterator   fiter;
  typedef std::list<GEdge*>::const_iterator   eiter;
  typedef std::list<GVertex*>::const_iterator viter;

  /** Returns the geometric tolerance for the entire model. */
  virtual double tolerance() const =0;

  /** Get the number of regions in this model. */
  int numRegion() const;
  int numFace  () const;
  int numEdge  () const;
  int numVertex() const;

  /** Get the nth region in this model. */
  GRegion * region(int n) const;
  GFace   * face  (int n) const;
  GEdge   * edge  (int n) const;
  GVertex * vertex(int n) const;

  /** Get an iterator initialized to the first entity in this model. */
  riter firstRegion() const {return regions.begin();}
  fiter firstFace() const {return faces.begin();}
  eiter firstEdge() const {return edges.begin();}
  viter firstVertex() const {return vertices.begin();}
  riter lastRegion() const {return regions.end();}
  fiter lastFace() const {return faces.end();}
  eiter lastEdge() const {return edges.end();}
  viter lastVertex() const {return vertices.end();}

  /** Find the region with the given tag. */
  virtual GRegion * regionByTag(int n) const;
  virtual GFace * faceByTag(int n) const;
  virtual GEdge * edgeByTag(int n) const;
  virtual GVertex * vertexByTag(int n) const;

  virtual GRegion * regionByID(int n) const;
  virtual GFace * faceByID(int n) const;
  virtual GEdge * edgeByID(int n) const;
  virtual GVertex * vertexByID(int n) const;

  virtual void setGeomTolerance(double) {};
  void setDisplayCoherence(int ); // default is coherent

  void add(GRegion *r){regions.push_back(r);}
  void add(GFace *f)  {regions.push_back(f);}
  void add(GEdge *e)  {regions.push_back(e);}
  void add(GVertex *v){regions.push_back(v);}

  void remove(GRegion *r){regions.erase(std::find(firstRegion(),lastRegion(),r));}
  void remove(GFace *f){faces.erase(std::find(firstFace(),lastFace(),f));}
  void remove(GEdge *e){edges.erase(std::find(firstEdge(),lastEdge(),e));}
  void remove(GVertex *v){vertices.erase(std::find(firstVertex(),lastVertex(),v));}

protected:
  GModel(const std::string &name);
  std::list<GRegion*> regions;
  std::list<GFace*> faces;
  std::list<GEdge*> edges;
  std::list<GVertex*> vertices;
};


#endif


