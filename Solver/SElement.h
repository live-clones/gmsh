// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SELEMENT_H_
#define _SELEMENT_H_

#include "MElement.h"
#include "simpleFunction.h"

// A solver element.

// FIXME: this will change in the future (the base SElement should no
// contain anything except the MElement). More advanced solvers will
// derive and/or add containers for additional storage

class SElement
{
 private:
  // the underlying mesh element
  MElement *_e;
  // store discrete function space and other data here
  // ...
  static simpleFunction<double> *_enrichement_s, *_enrichement_t;
  // gradient of functions (possibly enriched)
  void nodalFunctions (double u, double v, double w, double s[],
                       simpleFunction<double> *_enrichement);
  void gradNodalFunctions (double u, double v, double w, double invjac[3][3],
                           double grad[][3], simpleFunction<double> *_enrichment);
 public:
 SElement(MElement *e) : _e(e) {}
  ~SElement(){}
  MElement *getMeshElement() const { return _e; }
  static void setShapeEnrichement(simpleFunction<double>*f) {_enrichement_s = f;}
  static void setTestEnrichement(simpleFunction<double>*f) {_enrichement_t = f;}
  static const simpleFunction<double>* getShapeEnrichement() {return _enrichement_s;}
  static const simpleFunction<double>* getTestEnrichement() {return _enrichement_t;}
  int getNumNodalShapeFunctions() const;
  inline MVertex *getVertex(int i) const {return _e->getParent() ? _e->getParent()->getVertex(i) : _e->getVertex(i);}
  int getNumNodalTestFunctions() const;
  void nodalShapeFunctions (double u, double v, double w, double s[]);
  void gradNodalShapeFunctions (double u, double v, double w, double invjac[3][3],
                                double grad[][3]);
  void nodalTestFunctions (double u, double v, double w, double s[]);
  void gradNodalTestFunctions (double u, double v, double w, double invjac[3][3],
                               double grad[][3]);
};

#endif
