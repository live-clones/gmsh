//
// Description : Filtered and xFem function space definition
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  02/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _XFEMFS_H_
#define _XFEMFS_H_

#include "simpleFunction.h"

class FilterNodeEnriched
{

  private :

    std::set<int> *_TagEnrichedVertex;
    std::set<int> * _EnrichComp;

  public :

    FilterNodeEnriched(std::set<int > * TagEnrichedVertex , std::set<int> * EnrichComp)
    {
      _TagEnrichedVertex = TagEnrichedVertex;
      _EnrichComp = EnrichComp;
    }

    virtual bool operator () (Dof & key) const
    {
      std::set<int>::iterator it1;
      std::set<int>::iterator it2;
      int i1,i2;
      Dof::getTwoIntsFromType(key.getType(), i1,i2);
       it2 = _EnrichComp->find(i1);
      it1 = _TagEnrichedVertex->find(key.getEntity());
      if (it1!=_TagEnrichedVertex->end() & it2 != _EnrichComp->end())
      {
        return true;
      }
      else return false;
    }

    //std::vector<int> * getEnrichComp(){return _EnrichComp;}

//    void SetEnrichedVertex(MElement *elep, std::vector<int> & EnrichedVertex,int &nbdofs)
//    {
//      EnrichedVertex.clear();
//      nbdofs = 0;
//      for (int i=0 ;i<elep->getNumVertices();i++)
//      {
//        std::set<int>::iterator it;
//        it = _TagEnrichedVertex->find(elep->getVertex(i)->getNum());
//        if (it!=_TagEnrichedVertex->end())
//        {
//            EnrichedVertex.push_back(i);
//            nbdofs = nbdofs + 1*_EnrichComp->size(); // enriched dof
//        }
//      }
//    }
};


template<class T>
class xFemFS : public xFemFunctionSpace<T>
{

 public :

 typedef typename TensorialTraits<T>::ValType ValType;
 typedef typename TensorialTraits<T>::GradType GradType;

 protected:

  simpleFunction<double> *_funcEnrichment;

 public:

  xFemFS(FunctionSpace<T>* spacebase, simpleFunction<double> *funcEnrichment) : xFemFunctionSpace<T>(spacebase),_funcEnrichment(funcEnrichment)
  {};

  virtual void f(MElement *ele, double u, double v, double w,std::vector<ValType> &vals);
  virtual void gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads);
  virtual int getNumKeys(MElement *ele);
  virtual void getKeys(MElement *ele, std::vector<Dof> &keys);
};



template<class T>
class FilteredFS : public FilteredFunctionSpace<T,FilterNodeEnriched>
{

 public :

  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;

 public:
  FilteredFS(FunctionSpace<T>* spacebase, FilterNodeEnriched *filter) : FilteredFunctionSpace<T,FilterNodeEnriched> (spacebase,filter)
  {}
  virtual void f(MElement *ele, double u, double v, double w,std::vector<ValType> &vals);
  virtual void gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads);
  virtual int getNumKeys(MElement *ele);
  virtual void getKeys(MElement *ele, std::vector<Dof> &keys);
};

#endif
