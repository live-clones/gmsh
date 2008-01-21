#ifndef _FOURIER_FACE_H_
#define _FOURIER_FACE_H_

#include "GFace.h"
#include "GModel.h"
#include "Range.h"
#include "fourierEdge.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_TopoFace.h"

class fourierFace : public GFace {
 protected:
  FM::TopoFace *face;
 public:
  fourierFace(GModel *m, FM::TopoFace *face_, int tag, std::list<GEdge*> l_edges_);
  fourierFace(GModel *m, FM::TopoFace *face_, int tag, std::list<GEdge*> l_edges_,
	std::list<int> l_dirs_);
  virtual ~fourierFace() {}
  Range<double> parBounds(int i) const; 
  virtual GPoint point(double par1, double par2) const; 
  virtual SPoint2 parFromPoint(const SPoint3 &p) const;
  virtual int containsParam(const SPoint2 &pt) const; 
  virtual SVector3 normal(const SPoint2 &param) const; 
  virtual GEntity::GeomType geomType() const;
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const { throw; }
  ModelType getNativeType() const { return FourierModel; }
  void * getNativePtr() const { return face; } 
};

#endif

#endif

