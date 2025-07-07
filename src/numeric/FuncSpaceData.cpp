// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "FuncSpaceData.h"
#include "MElement.h"

FuncSpaceData::FuncSpaceData(const FuncSpaceData &fsd, int order)
  : _parentType(fsd._parentType), _spaceOrder(order),
    _isSerendipity(fsd._isSerendipity), _xyOrder(0), _yOrder(_spaceOrder),
    _isPyramidalSpace(fsd._isPyramidalSpace)
{
}

FuncSpaceData::FuncSpaceData(const FuncSpaceData &fsd, int nij, int nk)
  : _parentType(fsd._parentType),
    _spaceOrder(fsd._isPyramidalSpace ? nij + nk : std::max(nij, nk)),
    _isSerendipity(fsd._isSerendipity), _xyOrder(nij), _yOrder(nk),
    _isPyramidalSpace(fsd._isPyramidalSpace)
{
}

FuncSpaceData::FuncSpaceData(const MElement *el)
  : _parentType(el->getType()), _spaceOrder(el->getPolynomialOrder()),
    _isSerendipity(el->getIsOnlySerendipity()), _xyOrder(0), _yOrder(_spaceOrder),
    _isPyramidalSpace(_parentType == TYPE_PYR)
{
}

FuncSpaceData::FuncSpaceData(const MElement *el, int order, bool serendip)
  : _parentType(el->getType()), _spaceOrder(order), _isSerendipity(serendip),
    _xyOrder(0), _yOrder(_spaceOrder), _isPyramidalSpace(_parentType == TYPE_PYR)
{
}

FuncSpaceData::FuncSpaceData(const MElement *el, bool pyr, int nij, int nk,
                             bool serendip)
  : _parentType(el->getType()), _spaceOrder(pyr ? nij + nk : std::max(nij, nk)),
    _isSerendipity(serendip), _xyOrder(nij), _yOrder(nk), _isPyramidalSpace(pyr)
{
  if(el->getType() != TYPE_PYR)
    Msg::Error("Creation of pyramidal space data for a non-pyramid element !");
}

FuncSpaceData::FuncSpaceData(int tag)
  : _parentType(ElementType::getParentType(tag)),
    _spaceOrder(ElementType::getOrder(tag)),
    _isSerendipity(ElementType::getSerendipity(tag) > 1), _xyOrder(0),
    _yOrder(_spaceOrder),
    _isPyramidalSpace(_parentType == TYPE_PYR)
{
}

FuncSpaceData::FuncSpaceData(int type, int order, bool serendip)
  : _parentType(type), _spaceOrder(order), _isSerendipity(serendip), _xyOrder(0),
    _yOrder(_spaceOrder), _isPyramidalSpace(type == TYPE_PYR)
{
}

FuncSpaceData::FuncSpaceData(int type, bool pyr, int nij, int nk, bool serendip)
  : _parentType(type), _spaceOrder(pyr ? nij + nk : std::max(nij, nk)),
    _isSerendipity(serendip), _xyOrder(nij), _yOrder(nk), _isPyramidalSpace(pyr)
{
  if(_parentType != TYPE_PYR)
    Msg::Error("Creation of pyramidal space data for a non-pyramid element!");
}

void FuncSpaceData::getOrderForBezier(int order[3], int exponentZ) const
{
  if(_isPyramidalSpace && exponentZ < 0) {
    Msg::Error("getOrderForBezier needs third exponent for pyramidal space!");
    order[0] = order[1] = order[2] = -1;
    return;
  }
  if(getType() == TYPE_PYR) {
    if(_isPyramidalSpace) {
      order[0] = order[1] = _xyOrder + exponentZ;
      order[2] = _yOrder;
    }
    else {
      order[0] = order[1] = _xyOrder;
      order[2] = _yOrder;
    }
  }
  else
    order[0] = order[1] = order[2] = _spaceOrder;
}

FuncSpaceData FuncSpaceData::getForNonSerendipitySpace() const
{
  if(!_isSerendipity) return *this;

  if(_parentType == TYPE_PYR)
    return FuncSpaceData(_parentType, _isPyramidalSpace, _xyOrder, _yOrder, false);
  else
    return FuncSpaceData(_parentType, _spaceOrder, false);
}
