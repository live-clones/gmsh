// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_SMOOTH_HIGHORDER_H_
#define _GMSH_SMOOTH_HIGHORDER_H_

#include <map>
#include <vector>
#include "SVector3.h"
class MVertex;
class MElement;
class GFace;
class GRegion;

class gmshHighOrderSmoother 
{
  const int _tag;
  std::map<MVertex*,SVector3> _displ;
  int _dim;
  void _clean () {_displ.clear();}
public:  
  gmshHighOrderSmoother (int dim) : _tag(111), _dim(dim) {_clean();}
  void add ( MVertex * v, const SVector3 &d ) {_displ[v] = d;}  
  void smooth ( std::vector<MElement*> & );
  void smooth ( GFace* );
  void smooth ( GRegion* );
  int getTag() const {return _tag;}
};

#endif
