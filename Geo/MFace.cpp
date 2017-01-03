// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <vector>
#include <algorithm>
#include "GmshConfig.h"
#include "MFace.h"
#include "Numeric.h"

bool compare(MVertex* v0, MVertex* v1){ return v0->getNum() < v1->getNum(); }

void sortVertices(const std::vector<MVertex*> &v, std::vector<char> &s)
{
  if (v.size() == 3){
    s.resize(3);
    if (v[0]->getNum() < v[1]->getNum() &&
	v[0]->getNum() < v[2]->getNum() ){
      s[0] = 0; s[1] = 1; s[2] = 2;
    }
    else if (v[1]->getNum() < v[0]->getNum() &&
	     v[1]->getNum() < v[2]->getNum() ){
      s[0] = 1; s[1] = 0; s[2] = 2;
    }
    else {
      s[0] = 2; s[1] = 0; s[2] = 1;
    }

    if (v[s[2]]->getNum() < v[s[1]]->getNum()){
      char temp = s[1];
      s[1] = s[2];
      s[2] = temp;
    }
    return;
  }

  std::vector<MVertex*> sorted = v;
  std::sort(sorted.begin(), sorted.end(), compare);
  for(unsigned int i = 0; i < sorted.size(); i++)
    s.push_back(std::distance(v.begin(), std::find(v.begin(), v.end(), sorted[i])));
}

MFace::MFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3)
{
  _v.push_back(v0);
  _v.push_back(v1);
  _v.push_back(v2);
  if(v3) _v.push_back(v3);
  sortVertices(_v, _si);
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

bool MFace::computeCorrespondence(const MFace &other,
                                  int &rotation,
                                  bool &swap) const
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
