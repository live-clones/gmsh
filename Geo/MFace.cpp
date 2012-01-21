// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <vector>
#include <algorithm>
#include "GmshConfig.h"
#include "MFace.h"
#include "Numeric.h"
#include "Context.h"

void sortVertices(std::vector<MVertex*> v, std::vector<char> &si)
{
  std::vector<MVertex*> sorted = v;
  std::sort(sorted.begin(), sorted.end());
  for(unsigned int i = 0; i < sorted.size(); i++)
    si.push_back(std::distance(v.begin(), std::find(v.begin(), v.end(), sorted[i])));
}

MFace::MFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3) 
{
  _v.push_back(v0);
  if(CTX::instance()->mesh.reverseAllNormals){
    // Note that we cannot simply change the normal computation,
    // since OpenGL wants the normal to a polygon to be coherent
    // with the ordering of its vertices
    if(v3) _v.push_back(v3);
    _v.push_back(v2);
    _v.push_back(v1);
  }
  else{
    _v.push_back(v1);
    _v.push_back(v2);
    if(v3) _v.push_back(v3);
  }
  sortVertices(_v, _si);
  /*// This is simply an unrolled insertion sort (hopefully fast).  Note that if
  // _v[3] == 0, _v[3] is not sorted.
  if(_v[1] < _v[0]) {
    _si[0] = 1;
    _si[1] = 0;
  }
  else {
    _si[0] = 0;
    _si[1] = 1;
  }
  if(_v[2] < _v[int(_si[1])]) {
    _si[2] = _si[1];
    if(_v[2] < _v[int(_si[0])]) {
      _si[1] = _si[0];
      _si[0] = 2;
    }
    else
      _si[1] = 2;
  }
  else
    _si[2] = 2;
  if( _v[3] && _v[3] < _v[int(_si[2])]) {
    _si[3] = _si[2];
    if(_v[3] < _v[int(_si[1])]) {
      _si[2] = _si[1];
      if(_v[3] < _v[int(_si[0])]) {
        _si[1] = _si[0];
        _si[0] = 3;
      }
      else
        _si[1] = 3;
    }
    else
      _si[2] = 3;
  }
  else
    _si[3] = 3;*/
    
}
MFace::MFace(std::vector<MVertex*> v)
{
  for(unsigned int i = 0; i < v.size(); i++)
    _v.push_back(v[i]);
  sortVertices(_v,_si);
}

SVector3 MFace::normal() const
{
  double n[3];
  normal3points(_v[0]->x(), _v[0]->y(), _v[0]->z(),
                _v[1]->x(), _v[1]->y(), _v[1]->z(),
                _v[2]->x(), _v[2]->y(), _v[2]->z(), n);
  return SVector3(n[0], n[1], n[2]);
}

bool MFace::computeCorrespondence(const MFace &other, int &rotation, bool &swap) const
{
  rotation = 0;
  swap = false;
  
  if (*this == other) {
    for (int i = 0; i < getNumVertices(); i++) {
      if (_v[0] == other.getVertex(i)) {
        rotation = i;
        break;
      }
    }
    if (_v[1] == other.getVertex((rotation + 1) % getNumVertices())) swap = false;
    else swap = true;
    return true;
  }
  return false;
}

  
