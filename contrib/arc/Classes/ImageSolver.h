//
// Description :
//
//
// Author:  <Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _IMAGE_SOLVER_H_
#define _IMAGE_SOLVER_H_

#include "elasticitySolver.h"
#include "simpleFunction.h"
//#include "QuadtreeLSImage.h"

#include "gLevelSetMesh.cpp"
#include "FuncGradDisc.h"

class ImageSolver : public elasticitySolver
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
    // hanging nodes
    std::map< int ,std::vector<int> > *_ListHangingNodes;
    // level set
    gLevelSetMesh *_ls;

  public :

    ImageSolver(int tag) : elasticitySolver(tag) {}
    ~ImageSolver();
    //
    virtual void readInputFile(const std::string &fn);
    // create a GModel and determine de dimension of mesh in meshFileName
    //virtual void setMesh(const std::string &meshFileName);
    void setMesh(GModel *m, int dim, std::vector< float > &ListLSValue, std::map< int ,std::vector<int> > & ListHangingNodes);
    // system solve, read the .dat file, fill tagEnrichedVertex, fill funcEnrichment, solve
    virtual void solve();
    virtual PView *buildDisplacementView(const std::string &postFileName);
};

#endif

