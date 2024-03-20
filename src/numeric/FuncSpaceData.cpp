// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "FuncSpaceData.h"
#include "MElement.h"

FuncSpaceData::FuncSpaceData(const FuncSpaceData &fsd, int order)
  : _parentType(fsd._parentType), _spaceOrder(order),
    _serendipity(fsd._serendipity), _nij(0), _nk(_spaceOrder),
    _pyramidalSpace(fsd._pyramidalSpace)
{
}

FuncSpaceData::FuncSpaceData(const FuncSpaceData &fsd, int nij, int nk)
  : _parentType(fsd._parentType),
    _spaceOrder(fsd._pyramidalSpace ? nij + nk : std::max(nij, nk)),
    _serendipity(fsd._serendipity), _nij(nij), _nk(nk),
    _pyramidalSpace(fsd._pyramidalSpace)
{
}

FuncSpaceData::FuncSpaceData(const MElement *el)
  : _parentType(el->getType()), _spaceOrder(el->getPolynomialOrder()),
    _serendipity(el->getIsOnlySerendipity()), _nij(0), _nk(_spaceOrder),
    _pyramidalSpace(el->getType() == TYPE_PYR)
{
}

FuncSpaceData::FuncSpaceData(const MElement *el, int order, bool serendip)
  : _parentType(el->getType()), _spaceOrder(order), _serendipity(serendip),
    _nij(0), _nk(_spaceOrder), _pyramidalSpace(el->getType() == TYPE_PYR)
{
}

FuncSpaceData::FuncSpaceData(const MElement *el, bool pyr, int nij, int nk,
                             bool serendip)
  : _parentType(el->getType()), _spaceOrder(pyr ? nij + nk : std::max(nij, nk)),
    _serendipity(serendip), _nij(nij), _nk(nk), _pyramidalSpace(pyr)
{
  if(el->getType() != TYPE_PYR)
    Msg::Error("Creation of pyramidal space data for a non-pyramid element !");
}

FuncSpaceData::FuncSpaceData(int tag)
  : _parentType(ElementType::getParentType(tag)),
    _spaceOrder(ElementType::getOrder(tag)),
    _serendipity(ElementType::getSerendipity(tag) > 1), _nij(0),
    _nk(_spaceOrder),
    _pyramidalSpace(ElementType::getParentType(tag) == TYPE_PYR)
{
}

FuncSpaceData::FuncSpaceData(int type, int order, bool serendip)
  : _parentType(type), _spaceOrder(order), _serendipity(serendip), _nij(0),
    _nk(_spaceOrder), _pyramidalSpace(type == TYPE_PYR)
{
}

FuncSpaceData::FuncSpaceData(int type, bool pyr, int nij, int nk, bool serendip)
  : _parentType(type), _spaceOrder(pyr ? nij + nk : std::max(nij, nk)),
    _serendipity(serendip), _nij(nij), _nk(nk), _pyramidalSpace(pyr)
{
  if(_parentType != TYPE_PYR)
    Msg::Error("Creation of pyramidal space data for a non-pyramid element!");
}

void FuncSpaceData::getOrderForBezier(int order[3], int exponentZ) const
{
  if(_pyramidalSpace && exponentZ < 0) {
    Msg::Error("getOrderForBezier needs third exponent for pyramidal space!");
    order[0] = order[1] = order[2] = -1;
    return;
  }
  if(getType() == TYPE_PYR) {
    if(_pyramidalSpace) {
      order[0] = order[1] = _nij + exponentZ;
      order[2] = _nk;
    }
    else {
      order[0] = order[1] = _nij;
      order[2] = _nk;
    }
  }
  else
    order[0] = order[1] = order[2] = _spaceOrder;
}

FuncSpaceData FuncSpaceData::getForNonSerendipitySpace() const
{
  if(!_serendipity) return *this;

  if(_parentType == TYPE_PYR)
    return FuncSpaceData(_parentType, _pyramidalSpace, _nij, _nk, false);
  else
    return FuncSpaceData(_parentType, _spaceOrder, false);
}
