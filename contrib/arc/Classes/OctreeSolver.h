//
// Description :
//
//
// Author:  <Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _OCTREE_SOLVER_H_
#define _OCTREE_SOLVER_H_

#include "elasticitySolver.h"
#include "simpleFunction.h"
//#include "QuadtreeLSImage.h"

#include "gLevelSetMesh.cpp"
#include "FuncGradDisc.h"

class OctreeSolver : public elasticitySolver
{
  protected :

    // map containing the tag of vertex and enriched status
    std::set<int > _TagEnrichedVertex;
    // enriched comp
    std::set<int>  _EnrichComp;
    // simple multiplying function enrichment to enrich the space function
    simpleFunction<double> *_funcEnrichment;
    // level set value
    std::map<int, double > _LevelSetValue;
    // level set
    gLevelSetMesh *_ls;

  public :

    OctreeSolver(int tag) : elasticitySolver(tag) {}
    ~OctreeSolver();
    //
    virtual void readInputFile(const std::string &fn);
    // create a GModel and determine de dimension of mesh in meshFileName
    virtual void setMesh(const std::string &meshFileName);
    // set the map _LevelSetValue
    void setLevelSetValue(const std::string &LevelSetValueFileName);
    // system solve, read the .dat file, fill tagEnrichedVertex, fill funcEnrichment, solve
    virtual void solve();
    virtual PView *buildDisplacementView(const std::string &postFileName);
};

#endif

