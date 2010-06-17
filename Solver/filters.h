//
// Description : Filters for function space dof selection
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  02/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _FILTERS_H_
#define _FILTERS_H_

#include "simpleFunction.h"
#include "dofManager.h"
#include "GModel.h"
#include "groupOfElements.h"
#include "DILevelset.h"

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
      if ((it1!=_TagEnrichedVertex->end()) && (it2 != _EnrichComp->end()))
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

class FilterElementsCutByLevelSet
{

  private :

		std::set<int> _TagEnrichedVertex;
    std::pair<int,int> _LevelSetEntity;
    std::set<int> *_EnrichComp;

  public :

    FilterElementsCutByLevelSet(std::pair<int,int> LevelSetEntity , std::set<int> * EnrichComp)
    {

			_EnrichComp = EnrichComp;
      _LevelSetEntity = LevelSetEntity;

			// groupOfElements to get all the elements associate with the level set -- (work with *current GModel)
			groupOfElements *LevelSetElements = new groupOfElements (_LevelSetEntity.first, _LevelSetEntity.second);

			// tag enriched vertex determination
			std::set<MElement*>::const_iterator it = LevelSetElements->begin();
			for (; it != LevelSetElements->end(); it++)
			{
				MElement *e = *it;
				if (e->getParent()) // if element got parents
				{
					for (int k = 0; k < e->getParent()->getNumVertices(); ++k)
					{  // for all vertices in the element parent
						_TagEnrichedVertex.insert(e->getParent()->getVertex(k)->getNum());
					}
				}
			}

    }

    virtual bool operator () (Dof & key) const
    {
      std::set<int>::const_iterator it1;
      std::set<int>::const_iterator it2;
      int i1,i2;
      Dof::getTwoIntsFromType(key.getType(), i1,i2);
       it2 = _EnrichComp->find(i1);
      it1 = _TagEnrichedVertex.find(key.getEntity());
      if ((it1!=_TagEnrichedVertex.end()) && (it2 != _EnrichComp->end()))
      {
        return true;
      }
      else return false;
    }


};


#endif
