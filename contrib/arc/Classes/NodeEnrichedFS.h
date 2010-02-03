//
// Description : From function space to node enriched composant function space
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _NODEENRICHEDFS_H_
#define _NODEENRICHEDFS_H_

#include "SPoint3.h"
#include "SVector3.h"
#include "STensor3.h"
#include <vector>
#include <iterator>
#include <iostream>
#include "Numeric.h"
#include "MElement.h"
#include "MVertex.h"
#include "MPoint.h"
#include "dofManager.h"
#include "functionSpace.h"
#include "simpleFunction.h"
#include "FuncGradDisc.h"
#include <set>


template<class T>
class NodeEnrichedFS : public FunctionSpace<T>
{

public:

    typedef typename TensorialTraits<T>::ValType ValType;
    typedef typename TensorialTraits<T>::GradType GradType;


protected:

    std::set<int > *_TagEnrichedVertex;
    std::vector<int> * _EnrichComp;
    //simpleFunction<double> *_funcEnrichment;
    FuncGradDisc *_funcEnrichment;
    FunctionSpace<T> *_SupportFS;

public:

    NodeEnrichedFS(FunctionSpace<T> * SupportFS, std::set<int > * TagEnrichedVertex , std::vector<int> * EnrichComp,  FuncGradDisc *funcEnrichment)
    {
        _SupportFS = SupportFS;
        _TagEnrichedVertex = TagEnrichedVertex;
        _funcEnrichment = funcEnrichment;
        _EnrichComp = EnrichComp;
    }
    virtual ~NodeEnrichedFS() {}
    // Shape function value in element at uvw
    virtual void f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals);
    // Grad Shape function value in element at uvw
    virtual void gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads) ;
    // Shape function number for element
    virtual int getNumKeys(MElement *ele);
    // Dof keys for the element
    virtual void getKeys(MElement *ele, std::vector<Dof> &keys) ;
};

#endif
