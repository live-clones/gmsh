// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Boris Sedji
//

#ifndef FILTERS_H
#define FILTERS_H

#include "dofManager.h"
#include "GModel.h"
#include "groupOfElements.h"
#include "gmshLevelset.h"
template <class scalar> class simpleFunction;

class FilterNodeEnriched {
private:
  std::set<int> *_tagEnrichedVertex;
  std::set<int> *_enrichComp;

public:
  FilterNodeEnriched(std::set<int> *TagEnrichedVertex,
                     std::set<int> *EnrichComp)
  {
    _tagEnrichedVertex = TagEnrichedVertex;
    _enrichComp = EnrichComp;
  }
  virtual ~FilterNodeEnriched() {}

  virtual bool operator()(Dof &key) const
  {
    std::set<int>::iterator it1;
    std::set<int>::iterator it2;
    int i1, i2;
    Dof::getTwoIntsFromType(key.getType(), i1, i2);
    it2 = _enrichComp->find(i1);
    it1 = _tagEnrichedVertex->find(key.getEntity());
    if((it1 != _tagEnrichedVertex->end()) && (it2 != _enrichComp->end()))
      return true;
    else
      return false;
  }
  // std::vector<int> * getEnrichComp(){return _enrichComp;}

  //    void SetEnrichedVertex(MElement *elep, std::vector<int> &
  //    EnrichedVertex,int &nbdofs)
  //    {
  //      EnrichedVertex.clear();
  //      nbdofs = 0;
  //      for (int i=0 ;i<elep->getNumVertices();i++)
  //      {
  //        std::set<int>::iterator it;
  //        it = _tagEnrichedVertex->find(elep->getVertex(i)->getNum());
  //        if (it!=_tagEnrichedVertex->end())
  //        {
  //            EnrichedVertex.push_back(i);
  //            nbdofs = nbdofs + 1*_enrichComp->size(); // enriched dof
  //        }
  //      }
  //    }
};

class FilterElementsCutByLevelSet {
private:
  std::set<int> _tagEnrichedVertex;
  std::pair<int, int> _levelSetEntity;
  std::set<int> *_enrichComp;

public:
  FilterElementsCutByLevelSet(std::pair<int, int> LevelSetEntity,
                              std::set<int> *EnrichComp)
  {
    _enrichComp = EnrichComp;
    _levelSetEntity = LevelSetEntity;
    // groupOfElements to get all the elements associate with the level set --
    // (work with *current GModel)
    groupOfElements *LevelSetElements =
      new groupOfElements(_levelSetEntity.first, _levelSetEntity.second);
    // tag enriched vertex determination
    auto it = LevelSetElements->begin();
    for(; it != LevelSetElements->end(); it++) {
      MElement *e = *it;
      if(e->getParent()) { // if element got parents
        for(std::size_t k = 0; k < e->getParent()->getNumVertices();
            ++k) { // for all vertices in the element parent
          _tagEnrichedVertex.insert(e->getParent()->getVertex(k)->getNum());
        }
      }
    }
  }
  virtual ~FilterElementsCutByLevelSet() {}
  virtual bool operator()(Dof &key) const
  {
    std::set<int>::const_iterator it1;
    std::set<int>::const_iterator it2;
    int i1, i2;
    Dof::getTwoIntsFromType(key.getType(), i1, i2);
    it2 = _enrichComp->find(i1);
    it1 = _tagEnrichedVertex.find(key.getEntity());
    if((it1 != _tagEnrichedVertex.end()) && (it2 != _enrichComp->end())) {
      return true;
    }
    else
      return false;
  }
};

#endif
