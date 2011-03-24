//
// contact stiffness
//
// Description: Class to manage the Dof for which the stiffness must be computed
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef CONTACTNODESTIFFNESS_H_
#define CONTACTNODESTIFFNESS_H_
#include "MElement.h"
#include "SVector3.h"

struct dataContactStiffnessNode{
 public:
  MElement *_ele;
  int _verIndex;
  SVector3 _normal;
  dataContactStiffnessNode() : _ele(NULL), _verIndex(0), _normal(0.,0.,0.){};
  dataContactStiffnessNode(MElement *ele, const int ind, const SVector3 &nor) : _ele(ele), _verIndex(ind), _normal(nor){}
  dataContactStiffnessNode(const dataContactStiffnessNode &source){
    _ele = source._ele;
    _verIndex = source._verIndex;
    _normal = source._normal;
  }
};

class contactNodeStiffness{
 public:
  typedef std::vector<dataContactStiffnessNode> nodeContainer;
 protected:
  nodeContainer _nodeInContact;
  groupOfElements *_g; // group with elements in contact
 public:
  contactNodeStiffness(){_g = new groupOfElements();}
  contactNodeStiffness(const contactNodeStiffness &source){
    _nodeInContact = source._nodeInContact;
    _g = source._g;
  }
  ~contactNodeStiffness()
  {
    if(_g !=NULL) delete _g;
  };

  void insert(MElement *ele,const int i, SVector3 &normal){
    _nodeInContact.push_back(dataContactStiffnessNode(ele,i,normal));
    _g->insert(ele);
  }
  void clear(){
    _nodeInContact.clear();
    if(_g != NULL) delete _g;
    _g = new groupOfElements();
  }
  nodeContainer::const_iterator nBegin() const{return _nodeInContact.begin();}
  nodeContainer::const_iterator nEnd() const{return _nodeInContact.end();}
  groupOfElements::elementContainer::const_iterator elemBegin() const{return _g->begin();}
  groupOfElements::elementContainer::const_iterator elemEnd() const{return _g->end();}
};
#endif // contactNodeStiffness
