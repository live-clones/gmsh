#ifndef _OCC_EDGE_H_
#define _OCC_EDGE_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GEdge.h"
#include "GModel.h"
#include "OCCVertex.h"
#include "Range.h"

class OCCFace;

#if defined(HAVE_OCC)

class OCCEdge : public GEdge {
 protected:
  TopoDS_Edge c;
  TopoDS_Edge c_rev;
  double s0, s1;
  Handle(Geom_Curve) curve;
  mutable Handle(Geom2d_Curve) curve2d;
  mutable GFace *trimmed;
 public:
  OCCEdge(GModel *model, TopoDS_Edge _e, int num, GVertex *v1, GVertex *v2);
  virtual ~OCCEdge() {}
  virtual Range<double> parBounds(int i) const;
  virtual GeomType geomType() const;
  virtual bool degenerate(int) const { return BRep_Tool::Degenerated(c); }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual double curvature (double par) const;
  virtual SPoint2 reparamOnFace(GFace * face, double epar, int dir) const ;
  ModelType getNativeType() const { return OpenCascadeModel; }
  void * getNativePtr() const { return (void*)&c; }
  virtual double parFromPoint(const SPoint3 &pt) const;
  virtual int minimumMeshSegments () const;
  virtual int minimumDrawSegments () const;
  bool is3D() const { return !curve.IsNull(); }
  void setTrimmed(OCCFace *);
  int isSeam(GFace *) const;
};

#endif

#endif
