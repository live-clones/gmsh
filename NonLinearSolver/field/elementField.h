//
// C++ Interface: terms
//
// Description: Base class to manage a field on element (All field are managed by element in full Dg so displacement is also
//                                                       considered like a field on element
//
// The base class contains archiving data (which is not dependent of the field)
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef ELEMENTFIELD_H_
#define ELEMENTFIELD_H_
#include <string>
#include <stdint.h>
#include "MElement.h"
#include <vector>
#include <iostream>
#include <fstream>
class partDomain;
#include "groupOfElements.h"
class elementField{
 protected :
  // data needed to archive displacement
  // enum for chosen is ElementData or ElementNodeData more ??
  enum dataType{ElementData, ElementNodeData};
  dataType type;
  bool view;
  std::string fileName; // name of file where the displacement are store
  long int totelem; // total number of element present in all elasticFields
  uint32_t fmaxsize; // Size max of file in bytes (if size of file is greater a new one is created) TODO Argument for this parameter ?
  int numfile; // numero of file
  int numcomp;
  std::string dataname;
  // function to update file name
  void updateFileName();
  void createFile();

 public :
  elementField(const std::string &fnn, const uint32_t fms, const int ncomp, const dataType dt,
               const bool view_);
  ~elementField(){};
  void setTotElem(const int ne){totelem=ne;}
  virtual void get(partDomain* dom, MElement *ele,std::vector<double> &fieldData,const int comp=-1)=0; // comp allow to use an enum
                                                                                         // in derivate class to choose which component to save
  virtual void buildView(std::vector<partDomain*> &vdom,const double time,
                  const int nstep, const std::string &valuename, const int cc,const bool binary);
};
#endif //

