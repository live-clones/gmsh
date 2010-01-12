//
// Description : XFEM elasticity solver, element space function enriched on tagged vertex
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _XFEMELASTICITY_SOLVER_H_
#define _XFEMELASTICITY_SOLVER_H_

#include "elasticitySolver.h"
#include "simpleFunction.h"

class XFEMelasticitySolver : public elasticitySolver
{
  protected :
    // map containing the tag of vertex and enriched status
    std::set<int > _TagEnrichedVertex;
    // simple multiplying function enrichment to enrich the space function
    simpleFunction <double> *_funcEnrichment;

  public :

    XFEMelasticitySolver(int tag) : elasticitySolver(tag) {}
    ~XFEMelasticitySolver();
    // create a GModel and determine de dimension of mesh in meshFileName
    virtual void setMesh(const std::string &meshFileName);
    // system solve, read the .dat file, fill tagEnrichedVertex, fill funcEnrichment, solve
    virtual void solve();
    virtual PView *buildDisplacementView(const std::string &postFileName);
};

#endif
