// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GROUPOFELEMENTS_H_
#define _GROUPOFELEMENTS_H_

#include <set>
#include "GFace.h"
#include "MElement.h"

class elementFilter {
 public:
  virtual ~elementFilter(){}
  virtual bool operator() (MElement *) const = 0;
};

class elementFilterTrivial : public elementFilter {
 public:
  bool operator() (MElement *) const {return true;}
};

class groupOfElements {
 public:
  typedef std::set<MElement*> elementContainer;
  typedef std::set<MVertex*> vertexContainer;

 protected:
  vertexContainer _vertices;
  elementContainer _elements;
  elementContainer _parents;

 public:
  groupOfElements(){}
  groupOfElements (int dim, int physical) { addPhysical (dim, physical); }
  groupOfElements (GFace*);
  groupOfElements (GRegion*);
  groupOfElements(std::vector<MElement*> &elems);

  virtual ~groupOfElements(){}

  virtual void addPhysical(int dim, int physical) 
  {
    elementFilterTrivial filter;
    addPhysical (dim, physical, filter);
  }

  virtual void addElementary(GEntity *ge, const elementFilter &f);

  virtual void addPhysical(int dim, int physical, const elementFilter &);
  
  vertexContainer::const_iterator vbegin() const { return _vertices.begin(); }
  vertexContainer::const_iterator vend() const { return _vertices.end(); }
  elementContainer::const_iterator begin() const { return _elements.begin(); }
  elementContainer::const_iterator end() const { return _elements.end(); }

  size_t size() const { return _elements.size(); }
  size_t vsize() const { return _vertices.size(); }

  // FIXME : NOT VERY ELEGANT !!!
  bool find (MElement *e) const       // if same parent but different physicals return true ?!
  {
    if (e->getParent() && _parents.find(e->getParent()) != _parents.end()) return true;
    return (_elements.find(e) != _elements.end());
  }
  
  inline void insert (MElement *e)
  {
    _elements.insert(e);
    
    if (e->getParent()){
      _parents.insert(e->getParent());
      for (int i = 0; i < e->getParent()->getNumVertices(); i++){
	_vertices.insert(e->getParent()->getVertex(i));
      }
    }
    else{
      for (int i = 0; i < e->getNumVertices(); i++){
	_vertices.insert(e->getVertex(i));
      }
    }
  }
  
  inline void clearAll()
  {
    _vertices.clear();
    _elements.clear();
    _parents.clear();
  }
};

// child elements in pElem restricted to elements who have parent in sElem
class groupOfLagMultElements : public groupOfElements
{
 private :
  void fillElementContainer(groupOfElements &pElem, groupOfElements &sElem)
  {
    groupOfElements::elementContainer::const_iterator itp = pElem.begin();
    for (;itp!=pElem.end(); itp++)
    {
      if ((*itp)->getParent())
      {
        if (sElem.find(*itp)) insert((*itp)) ;  // warning : find method used to check if parent is in sElem
      }
      else std::cout << "groupOfLagMultElements : Warning, level set element has no parent ?! " << std::endl;
    }
  }

 public :
  groupOfLagMultElements(int dim, int physical, groupOfElements &sElem) : groupOfElements()
  {
    groupOfElements  pElem(dim , physical);
    fillElementContainer(pElem,sElem);
  }

  groupOfLagMultElements(int dim, int physical, std::vector < groupOfElements *>  sElem) : groupOfElements()
  {
    groupOfElements  pElem(dim , physical);
    for (unsigned int i = 0 ;i < sElem.size() ; i ++)
    {
     fillElementContainer(pElem,(*sElem[i]));
    }
  }

};

#endif
