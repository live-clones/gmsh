// Copyright (C) 2013 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributor: Thomas Toulorge

#ifndef _SUPEREL_H_
#define _SUPEREL_H_

#include <string>
#include "MElement.h"

class SuperEl
{
 public:
  SuperEl(int type, int order, const std::vector<MVertex*> &baseVert,
          const std::vector<MVertex*> &topPrimVert);
  ~SuperEl();
  bool isOK() const { return _superEl; }
  bool isPointIn(const SPoint3 p) const;
  bool straightToCurved(double *xyzS, double *xyzC) const;
  std::string printPOS();
  void printCoord()
  {
    std::cout << "DBGTT: superEl -> ";
    for(int i = 0; i < _superVert.size(); i++){
      std::cout << "v" << i << " = (" << _superVert[i]->x() << ","
                <<  _superVert[i]->y() << "," <<  _superVert[i]->z() << ")";
      if (i == _superVert.size()-1) std::cout << "\n"; else std::cout << ", ";
    }
  }
 private:
  struct superInfoType {
    int nV;
    fullMatrix<double> points;
    std::vector<int> baseInd, topInd, otherInd;
    superInfoType(int type, int order);
  };
  static std::map<int,superInfoType> _superInfo;
  std::vector<MVertex*> _superVert;
  MElement *_superEl, *_superEl0;
};

#endif
