//
// Description : From Scalar Lagrange Function Space To XFEM on Tagged Vertex
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "SVector3.h"
#include "STensor3.h"
#include <vector>
#include <iterator>
#include <iostream>
#include "Numeric.h"
#include "MElement.h"
#include "dofManager.h"
#include <set>


#include "functionSpace.h"
#include "simpleFunction.h"


class ScalarLagrangeToXfemFS : public ScalarLagrangeFunctionSpace{
  public:

    typedef TensorialTraits<double>::ValType ValType;
    typedef TensorialTraits<double>::GradType GradType;

  protected:

    std::set<int > *_TagEnrichedVertex;
    simpleFunction<double> *_funcEnrichment;

  public:
//
    ScalarLagrangeToXfemFS(int i, std::set<int > &TagEnrichedVertex, simpleFunction<double> *funcEnrichment) : ScalarLagrangeFunctionSpace(i)
    {
      _TagEnrichedVertex = & TagEnrichedVertex;
      _funcEnrichment = funcEnrichment;
    }

    virtual int getId(void) const {return ScalarLagrangeFunctionSpace::_iField;};
    // Shape function value in element at uvw
    virtual void f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals);
    // Shape function value at vertex
    virtual void f(MVertex *ver, std::vector<ValType> &vals) ;
    // Grad Shape function value in element at uvw
    virtual void gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads) ;
    // Shape function Number for element (in one dimension (scalar))
    virtual int getNumKeys(MElement *ele);
    // Dof keys for the element
    virtual void getKeys(MElement *ele, std::vector<Dof> &keys) ;
    // Shape function Number associate with the vertex
    virtual int getNumKeys(MVertex *ver);
    // Get Dof keys for the vertex (in one dimension (scalar))
    virtual void getKeys(MVertex *ver, std::vector<Dof> &keys);
};


class ScalarXFEMToVectorFS : public ScalarToAnyFunctionSpace<SVector3>
{
  protected:

    static const SVector3 BasisVectors[3];

  public:
    enum Along { VECTOR_X=0, VECTOR_Y=1, VECTOR_Z=2 };

    typedef TensorialTraits<SVector3>::ValType ValType;
    typedef TensorialTraits<SVector3>::GradType GradType;


    ScalarXFEMToVectorFS(int id , std::set<int > & TagEnrichedVertex , simpleFunction<double> * funcEnrichment) :
          ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(ScalarLagrangeToXfemFS(id,TagEnrichedVertex,funcEnrichment),
          SVector3(1.,0.,0.),VECTOR_X, SVector3(0.,1.,0.),VECTOR_Y,SVector3(0.,0.,1.),VECTOR_Z) {}

    ScalarXFEMToVectorFS(int id,Along comp1, std::set<int > &TagEnrichedVertex , simpleFunction<double> * funcEnrichment) :
          ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(ScalarLagrangeToXfemFS(id,TagEnrichedVertex,funcEnrichment),
          BasisVectors[comp1],comp1) {}

    ScalarXFEMToVectorFS(int id,Along comp1,Along comp2, std::set<int > &TagEnrichedVertex,simpleFunction<double> *funcEnrichment) :
          ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(ScalarLagrangeToXfemFS(id,TagEnrichedVertex,funcEnrichment),
          BasisVectors[comp1],comp1, BasisVectors[comp2],comp2) {}

    ScalarXFEMToVectorFS(int id,Along comp1,Along comp2, Along comp3, std::set<int > &TagEnrichedVertex,simpleFunction<double> *funcEnrichment) :
          ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(ScalarLagrangeToXfemFS(id,TagEnrichedVertex,funcEnrichment),
          BasisVectors[comp1],comp1, BasisVectors[comp2],comp2, BasisVectors[comp3],comp3) {}
};

const SVector3 ScalarXFEMToVectorFS::BasisVectors[3]={SVector3(1,0,0),SVector3(0,1,0),SVector3(0,0,1)};
