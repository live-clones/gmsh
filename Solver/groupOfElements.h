#ifndef _GROUPOFELEMENTS_H_
#define _GROUPOFELEMENTS_H_

#include <set>
#include "GFace.h"
#include "MElement.h"

class elementFilter {
public:
  virtual bool operator () (MElement *) const = 0;
};

class elementFilterTrivial : public elementFilter {
public:
  bool operator () (MElement *) const {return true;}
};

class groupOfElements {
public:
  typedef std::set<MElement*> elementContainer; 
  typedef std::set<MVertex*> vertexContainer; 
private:
  vertexContainer _vertices;
  elementContainer _elements;
  elementContainer _parents;
public:
  groupOfElements (int dim, int physical) {
    addPhysical (dim, physical);
  }   

  groupOfElements (GFace*); 

  void addPhysical(int dim, int physical) {
    elementFilterTrivial filter;
    addPhysical (dim, physical, filter);
  }

  void addElementary(GEntity *ge, const elementFilter &f);

  void addPhysical(int dim, int physical, const elementFilter &);

  vertexContainer::const_iterator vbegin () const {
    return _vertices.begin();
  }
  vertexContainer::const_iterator vend () const {
    return _vertices.end();
  }
  
  elementContainer::const_iterator begin () const {
    return _elements.begin();
  }
  elementContainer::const_iterator end () const {
    return _elements.end();
  }
  size_t size () const {
    return _elements.size();
  }
  // FIXME : NOT VERY ELEGANT !!!
  bool find (MElement *e) const {
    if (e->getParent() && _parents.find(e->getParent()) != _parents.end())return true;
    return (_elements.find(e) != _elements.end()) ;
  }
  inline void insert (MElement *e) {
    _elements.insert(e);
    if (e->getParent()){
      _parents.insert(e->getParent());      
      for (int i=0;i<e->getParent()->getNumVertices();i++){
	_vertices.insert(e->getParent()->getVertex(i));
      }
    }
    else{
      for (int i=0;i<e->getNumVertices();i++){
	_vertices.insert(e->getVertex(i));
      }
    }
  }
};

#endif
