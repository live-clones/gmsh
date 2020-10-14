// HighOrderMeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
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
// Contributor: Thomas Toulorge

#ifndef METAEL_H
#define METAEL_H

#include <string>
#include "MElement.h"
#include "fullMatrix.h"

class MetaEl {
public:
  MetaEl(int type, int order, const std::vector<MVertex *> &baseVert,
         const std::vector<MVertex *> &topPrimVert);
  ~MetaEl();
  void placeOtherNodes();
  void setCurvedTop(double factor);
  void setFlatTop();
  bool isOK() const { return _metaEl; }
  bool isPointIn(const SPoint3 &p) const;
  bool straightToCurved(double *xyzS, double *xyzC) const;
  std::string printPOS();
  void printCoord()
  {
    std::cout << "DBGTT: metaEl -> ";
    for(int i = 0; i < _metaVert.size(); i++) {
      std::cout << "v" << i << " = (" << _metaVert[i]->x() << ","
                << _metaVert[i]->y() << "," << _metaVert[i]->z() << ")";
      if(i == _metaVert.size() - 1)
        std::cout << "\n";
      else
        std::cout << ", ";
    }
  }
  MElement *getMElement() { return _metaEl; }

private:
  struct metaInfoType {
    int dim, nbVert;
    fullMatrix<double> points;
    fullMatrix<double> baseLinShapeFuncVal, baseGradShapeFuncVal;
    const nodalBasis *baseFaceBasis, *linBaseFaceBasis;
    std::vector<int> baseInd, topInd, freeTopInd, edgeInd, otherInd;
    std::vector<int> freeTop2Base, other2Base, other2Top;
    metaInfoType(int type, int order);
  };
  static std::map<int, metaInfoType> _metaInfo;

  const metaInfoType &_mInfo;
  std::vector<MVertex *> _metaVert;
  MElement *_metaEl, *_metaEl0;
  std::vector<SVector3> _baseNorm;

  const metaInfoType &getMetaInfo(int elType, int order);
  void computeBaseNorm(const SVector3 &metaNorm,
                       const std::vector<MVertex *> &baseVert,
                       const std::vector<MVertex *> &topPrimVert,
                       std::vector<SVector3> &baseNorm);
};

#endif
