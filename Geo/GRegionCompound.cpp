// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Emilie Marchandise
//

#include <stdlib.h>
#include "GmshConfig.h"
#include "GRegionCompound.h"
#include "Numeric.h"

GRegionCompound::GRegionCompound(GModel *m, int tag, std::vector<GRegion*> &compound)
  : GRegion(m, tag),  _compound(compound)
{
  printf("********* In GRegion compound size =%d  \n", _compound.size());
  getBoundingFaces();
}

GRegionCompound::~GRegionCompound()
{
}

void GRegionCompound::getBoundingFaces(){

  std::set<GFace*> _unique;
  std::multiset<GFace*> _touched;
  std::vector<GRegion*>::iterator it = _compound.begin();
  for ( ; it != _compound.end(); ++it){
    printf("face %d \n", (*it)->tag());
    std::list<GFace*> ed = (*it)->faces();
   std::list<GFace*> :: iterator ite = ed.begin();
    for ( ; ite != ed.end(); ++ite){
     _touched.insert(*ite);
    }    
  }    
  it = _compound.begin();
  for ( ; it != _compound.end(); ++it){
    std::list<GFace*> ed = (*it)->faces();
    std::list<GFace*> :: iterator ite = ed.begin();
    for ( ; ite != ed.end() ; ++ite){
      if (!(*ite)->degenerate(0) && _touched.count(*ite) == 1) {	
	_unique.insert(*ite);      }
    }    
  }    

  std::set<GFace*>::iterator itf = _unique.begin();
  for ( ; itf != _unique.end(); ++itf){
    l_faces.push_back(*itf);
    printf("for face %d, add region %d \n", (*itf)->tag(), this->tag());
    (*itf)->addRegion(this);
  }

}


SBoundingBox3d  GRegionCompound::bounds() const { 
  Msg::Error("Cannot evaluate bounds on GRegion Compound");
  return SBoundingBox3d(SPoint3()); 
}

double GRegionCompound::curvature(double par) const
{

  double k = 0.0;
  Msg::Error("Cannot evaluate curvature on GRegionCompound");
  return k;
}

GPoint GRegionCompound::point(double par) const
{

  Msg::Error("Cannot evaluate point on GRegionCompound");
  return GPoint();
}

SVector3 GRegionCompound::firstDer(double par) const
{

  Msg::Error("Cannot evaluate firstDeriv on GRegionCompound");
  return SVector3();
} 
