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
#include "dofManager.h"
#include "functionSpace.h"
#include "simpleFunction.h"
#include <set>


template<class T>
class NodeEnrichedFS : public FunctionSpace<T>
{

public:

    typedef typename TensorialTraits<T>::ValType ValType;
    typedef typename TensorialTraits<T>::GradType GradType;
    typedef typename TensorialTraits<T>::HessType HessType;
    typedef typename TensorialTraits<T>::DivType DivType;
    typedef typename TensorialTraits<T>::CurlType CurlType;

protected:

    std::set<int > *_TagEnrichedVertex;
    std::vector<int> * _EnrichComp;
    simpleFunction<double> *_funcEnrichment;
    FunctionSpace<T> *_SupportFS;

public:

    NodeEnrichedFS(FunctionSpace<T> * SupportFS, std::set<int > * TagEnrichedVertex , std::vector<int> * EnrichComp,  simpleFunction<double> *funcEnrichment)
    {
        _SupportFS = SupportFS;
        _TagEnrichedVertex = TagEnrichedVertex;
        _funcEnrichment = funcEnrichment;
        _EnrichComp = EnrichComp;
    }
    virtual ~NodeEnrichedFS() {}
    // Shape function value in element at uvw
    virtual void f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals);
    // Shape function value at vertex
    virtual void f(MVertex *ver, std::vector<ValType> &vals) ;
    // Grad Shape function value in element at uvw
    virtual void gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads) ;
    // Shape function number for element
    virtual int getNumKeys(MElement *ele);
    // Dof keys for the element
    virtual void getKeys(MElement *ele, std::vector<Dof> &keys) ;
    // Shape function Number associate with the vertex
    virtual int getNumKeys(MVertex *ver);
    // Get Dof keys for the vertex
    virtual void getKeys(MVertex *ver, std::vector<Dof> &keys);
};

#endif
