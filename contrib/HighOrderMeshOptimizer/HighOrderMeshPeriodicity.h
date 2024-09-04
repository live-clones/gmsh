// HighOrderMeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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
// Contributors: Amaury Johnen

#ifndef HIGH_ORDER_MESH_PERIODICITY_H
#define HIGH_ORDER_MESH_PERIODICITY_H

#include <map>
#include <vector>

class GEntity;
class GFace;
class GPoint;

#include "MVertex.h"

class HighOrderMeshPeriodicity {
private:
  std::multimap<GEntity *, GEntity *> _master2slave;
  // std::map<GEntity*, std::map<MVertex*, MVertex*> > _ent2vv;

public:
  HighOrderMeshPeriodicity(std::vector<GEntity *> &);

  void fixPeriodicity();

private:
  void _relocateMasterVertices();
  void _copyBackMasterVertices();

  static SPoint3 _transform(MVertex *, const std::vector<double> &);
  static std::vector<double> _inverse(const std::vector<double> &);
};

#endif
