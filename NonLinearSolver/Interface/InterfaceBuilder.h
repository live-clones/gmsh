//
// C++ Interface: terms
//
// Description: Class to manage the creation of interface
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef _INTERFACEBUILDER_H_
#define _INTERFACEBUILDER_H_
#include "mlaw.h"
#include "IElement.h"
class partDomain;
class manageInterface{
 public:
  typedef std::map<unsigned long int,IElement*> IelementContainer; // create IElement type and Iede derive from Iedge
  typedef std::pair<unsigned long int,IElement*> IelementPart;
 protected:
  IelementContainer mapinter;
  std::vector<partDomain*> *_vdom;
 public:
  static unsigned long int getKey(const int npdom1, const int npdom2){
    unsigned long int i;
    if(npdom1 == npdom2){
      return npdom1;
    }
    else{
      npdom1<npdom2 ? i = npdom2*100000+npdom1 : i = npdom1*100000+npdom2;
      return i;
    }
  }

  unsigned long int getKey(partDomain* dom1, partDomain *dom2);
  void insert(IElement *iele,partDomain *dom);

  // not optimal for internal interface pass current dom for more efficiency ??
  void createinter(MElement *ele, IElement *ie, const int phys2);

  manageInterface(std::vector<partDomain*> *vdom) : _vdom(vdom){}
  ~manageInterface()
  {
    for(IelementContainer::iterator it = mapinter.begin(); it!=mapinter.end(); ++it){
      delete it->second;
    }
  }
  void erase(IElement *ie){
    unsigned long int key = ie->getkey();
    IelementContainer::iterator it = mapinter.find(key);
    if(it != mapinter.end()){
      delete it->second;
      mapinter.erase(it);
    }
  }


  void create(partDomain *dom1, partDomain *dom2, const std::map<int,materialLaw*> &maplaw,const int lawnum=0);
  void createInterShell(partDomain *dom1, partDomain *dom2, const int lawnum,
                        const std::map<int,materialLaw*> &maplaw,const int ipert, const double eps=1e-8);
  IelementContainer::iterator begin(){return mapinter.begin();}
  IelementContainer::iterator end(){return mapinter.end();}

};
#endif //_INTERFACEBUILDER_H_
