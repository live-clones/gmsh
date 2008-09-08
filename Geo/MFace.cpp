// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MFace.h"

#if defined(HAVE_GMSH_EMBEDDED)
#include "GmshEmbedded.h"
#else
#include "Numeric.h"
#include "Context.h"
#endif

extern Context_T CTX;

MFace::MFace() 
{ 
  for(int i = 0; i < 4; i++){
    _v[i] = 0; 
    _si[i] = 0;
  }
}

MFace::MFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3) 
{
  if(CTX.mesh.reverse_all_normals){
    // Note that we cannot simply change the normal computation,
    // since OpenGL wants the normal to a polygon to be coherent
    // with the ordering of its vertices
    if(v3){
      _v[0] = v0; _v[1] = v3; _v[2] = v2; _v[3] = v1;
    }
    else{
      _v[0] = v0; _v[1] = v2; _v[2] = v1; _v[3] = v3;
    }
  }
  else{
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
  }
  // This is simply an unrolled insertion sort (hopefully fast).  Note that if
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
    _si[3] = 3;
}

SVector3 MFace::normal() const
{
  double n[3];
  normal3points(_v[0]->x(), _v[0]->y(), _v[0]->z(),
                _v[1]->x(), _v[1]->y(), _v[1]->z(),
                _v[2]->x(), _v[2]->y(), _v[2]->z(), n);
  return SVector3(n[0], n[1], n[2]);
}

bool MFace::computeCorrespondence(const MFace& other,int& rotation,bool& swap) const {
  
  rotation = 0;
  swap = false;
  
  if (*this == other) {
    for (int i=0;i<getNumVertices();i++) {
      if (_v[0] == other.getVertex(i)) {
        rotation = i;
        break;
      }
    }
    if (_v[1] == other.getVertex((rotation+1)%getNumVertices())) swap = false;
    else                                                         swap = true;
    return true;
  }
  return false;
}

  
