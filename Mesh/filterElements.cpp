// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <algorithm>
#include <vector>
#include <set>
#include "GmshDefines.h"
#include "filterElements.h"
#include "fullMatrix.h"
#include "GaussIntegration.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MPrism.h"
#include "MHexahedron.h"

#if defined(HAVE_RTREE)
#include "rtree.h"
void MElementBB(void *a, double *min, double *max);
int MElementInEle(void *a, double *x);

struct MElement_Wrapper
{
  bool _overlap;
  MElement *_e;
  std::vector<MElement*> _notOverlap;
  MElement_Wrapper (MElement *e, std::vector<MElement*> notOverlap)
    : _overlap(false), _e(e), _notOverlap(notOverlap)
  {
    std::sort(_notOverlap.begin(),_notOverlap.end());
  }
};

static bool inBB (double *mi, double *ma, double *x){
  if (x[0] < mi[0])return false;
  if (x[1] < mi[1])return false;
  if (x[2] < mi[2])return false;
  if (x[0] > ma[0])return false;
  if (x[1] > ma[1])return false;
  if (x[2] > ma[2])return false;
  return true;
}

bool rtree_callback(MElement *e1,void* pe2)
{
  MElement_Wrapper *wrapper = static_cast<MElement_Wrapper*>(pe2);
  MElement *e2 = wrapper->_e;

  if (std::binary_search(wrapper->_notOverlap.begin(),wrapper->_notOverlap.end(),e1))
    return true;

  for (int i=0;i<e1->getNumVertices();i++){
    for (int j=0;j<e2->getNumVertices();j++){
      if(e1->getVertex(i) == e2->getVertex(j))return true;
    }
  }

  double min2[3],max2[3];
  MElementBB(e2,min2,max2);

  for (int i=0;i<e1->getNumVertices();i++){
    SPoint3 xyz (e1->getVertex(i)->x(),e1->getVertex(i)->y(),e1->getVertex(i)->z());
    if (inBB (min2,max2,xyz)){
      if (MElementInEle(e2,xyz)){
	wrapper->_overlap = true;
	return false;
      }
    }
  }

  double min1[3],max1[3];
  MElementBB(e1,min1,max1);
  for (int i=0;i<e2->getNumVertices();i++){
    SPoint3 xyz (e2->getVertex(i)->x(),e2->getVertex(i)->y(),e2->getVertex(i)->z());
    if (inBB(min1,max1,xyz)){
      if (MElementInEle(e1,xyz)){
	wrapper->_overlap = true;
	return false;
      }
    }
  }

  //  return false;

  fullMatrix<double> pts1,pts2;
  fullVector<double> weights;

  gaussIntegration::get (e1->getType(),1,pts1,weights);
  gaussIntegration::get (e2->getType(),1,pts2,weights);

  for (int i=0;i<pts1.size1();i++){
    double u = pts1(i,0);
    double v = pts1(i,1);
    double w = pts1(i,2);
    SPoint3 xyz;
    e1->pnt(u,v,w,xyz);
    if (inBB(min2,max2,xyz)){
      if (MElementInEle(e2,xyz)){
	wrapper->_overlap = true;
	return false;
      }
    }
  }
  for (int i=0;i<pts2.size1();i++){
    double u = pts2(i,0);
    double v = pts2(i,1);
    double w = pts2(i,2);
    SPoint3 xyz;
    e2->pnt(u,v,w,xyz);
    if (inBB(min1,max1,xyz)){
      if (MElementInEle(e1,xyz)){
	wrapper->_overlap = true;
	return false;
      }
    }
  }
  return true;
}

struct Less_Partition : public std::binary_function<MElement*, MElement*, bool> {
  bool operator()(const MElement *f1, const MElement *f2) const
  {
    return f1->getPartition() < f2->getPartition() ;
  }
};

void filterColumns(std::vector<MElement*> &elem,
		   std::map<MElement*,std::vector<MElement*> > &_elemColumns)
{
  std::sort(elem.begin(),elem.end());
  std::vector<MElement*> toKeep;
  for (std::map<MElement*,std::vector<MElement*> >::iterator it = _elemColumns.begin();
       it !=_elemColumns.end() ; ++it){
    const std::vector<MElement*> &c = it->second;
    unsigned int MAX = c.size() - 1;
    for (unsigned int i=0;i<c.size(); i++){
      if (!std::binary_search(elem.begin(),elem.end(),c[i])){
	MAX = i - 1;
	break;
      }
    }
    //    printf("MAX = %d c = %d\n",MAX,c.size());
    for (unsigned int i=0;i<MAX;i++){
      toKeep.push_back(c[i]);
    }
    for (unsigned int i=MAX;i<c.size();i++){
      /// FIXME !!!
      //      delete c[i];
    }
  }
  printf("%i --> %i\n",elem.size(),toKeep.size());
  elem = toKeep;
}


void filterOverlappingElements (std::vector<MTriangle*> &blTris,
				std::vector<MQuadrangle*>&blQuads,
				std::map<MElement*,std::vector<MElement*> > &_elemColumns,
				std::map<MElement*,MElement*> &_toFirst)
{
  std::vector<MElement*> vvv;
  vvv.insert(vvv.begin(),blTris.begin(),blTris.end());
  vvv.insert(vvv.begin(),blQuads.begin(),blQuads.end());
  Less_Partition lp;
  std::sort(vvv.begin(),vvv.end(), lp);
  filterOverlappingElements (vvv,_elemColumns,_toFirst);
  filterColumns (vvv,_elemColumns);
  blTris.clear();
  blQuads.clear();
  for (unsigned int i=0;i<vvv.size();i++){
    if (vvv[i]->getType() == TYPE_TRI)blTris.push_back((MTriangle*)vvv[i]);
    else if (vvv[i]->getType() == TYPE_QUA)blQuads.push_back((MQuadrangle*)vvv[i]);
  }
}

void filterOverlappingElements (std::vector<MPrism*> &blPrisms,
				std::vector<MHexahedron*>&blHexes,
				std::map<MElement*,std::vector<MElement*> > &_elemColumns,
				std::map<MElement*,MElement*> &_toFirst)
{
  printf("filtering !!\n");
  std::vector<MElement*> vvv;
  vvv.insert(vvv.begin(),blPrisms.begin(),blPrisms.end());
  vvv.insert(vvv.begin(),blHexes.begin(),blHexes.end());
  Less_Partition lp;
  std::sort(vvv.begin(),vvv.end(), lp);
  filterOverlappingElements (vvv,_elemColumns,_toFirst);
  filterColumns (vvv,_elemColumns);
  blPrisms.clear();
  blHexes.clear();
  for (unsigned int i=0;i<vvv.size();i++){
    if (vvv[i]->getType() == TYPE_PRI)blPrisms.push_back((MPrism*)vvv[i]);
    else if (vvv[i]->getType() == TYPE_HEX)blHexes.push_back((MHexahedron*)vvv[i]);
  }
}


void filterOverlappingElements (std::vector<MElement*> &els,
				std::map<MElement*,std::vector<MElement*> > &_elemColumns,
				std::map<MElement*,MElement*> &_toFirst )
{
  std::vector<MElement*> newEls;
  RTree<MElement*,double,3,double> rtree;
  for (unsigned int i=0;i<els.size();i++){
    MElement *e = els[i];
    double _min[3],_max[3];
    MElementBB(e,_min,_max);
    MElement *first = _toFirst[e];
    MElement_Wrapper w(e,_elemColumns[first]);
    rtree.Search(_min,_max,rtree_callback,&w);
    if (w._overlap){
      delete e;
    }
    else {
      rtree.Insert(_min,_max,e);
      newEls.push_back(e);
    }
  }
  els = newEls;
}

#else

void filterOverlappingElements (std::vector<MTriangle*> &blTris,
				std::vector<MQuadrangle*>&blQuads,
				std::map<MElement*,std::vector<MElement*> > &_elemColumns,
				std::map<MElement*,MElement*> &_toFirst)
{
  Msg::Error("Gmsh needs to be compiled with RTREE support for bonudary layers");
}

void filterOverlappingElements (std::vector<MPrism*> &blPrisms,
				std::vector<MHexahedron*>&blHexes,
				std::map<MElement*,std::vector<MElement*> > &_elemColumns,
				std::map<MElement*,MElement*> &_toFirst)
{
  Msg::Error("Gmsh needs to be compiled with RTREE support for bonudary layers");
}

void filterOverlappingElements (std::vector<MElement*> &els,
				std::map<MElement*,std::vector<MElement*> > &_elemColumns,
				std::map<MElement*,MElement*> &_toFirst )
{
  Msg::Error("Gmsh needs to be compiled with RTREE support for bonudary layers");
}

#endif
