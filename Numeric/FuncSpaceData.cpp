// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-B-> Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "FuncSpaceData.h"
#include "MElement.h"

FuncSpaceData::FuncSpaceData(const FuncSpaceData &fsd,
                             int order,
                             const bool *serendip) :
  _tag(fsd._tag), _spaceOrder(order),
  _serendipity(serendip ? *serendip : fsd._serendipity),
  _nij(0), _nk(_spaceOrder), _pyramidalSpace(fsd._pyramidalSpace)
{}

FuncSpaceData::FuncSpaceData(const FuncSpaceData &fsd,
                             int nij, int nk,
                             const bool *serendip) :
  _tag(fsd._tag), _spaceOrder(fsd._pyramidalSpace ? nij+nk : std::max(nij, nk)),
  _serendipity(serendip ? *serendip : fsd._serendipity),
  _nij(nij), _nk(nk), _pyramidalSpace(fsd._pyramidalSpace)
{}

FuncSpaceData::FuncSpaceData(const MElement *el, const bool *serendip) :
  _tag(el->getTypeForMSH()), _spaceOrder(el->getPolynomialOrder()),
  _serendipity(serendip ? *serendip : el->getIsOnlySerendipity()),
  _nij(0), _nk(_spaceOrder), _pyramidalSpace(el->getType() == TYPE_PYR)
{}

FuncSpaceData::FuncSpaceData(const MElement *el, int order, const bool *serendip) :
  _tag(el->getTypeForMSH()), _spaceOrder(order),
  _serendipity(serendip ? *serendip : el->getIsOnlySerendipity()),
  _nij(0), _nk(_spaceOrder), _pyramidalSpace(el->getType() == TYPE_PYR)
{}

FuncSpaceData::FuncSpaceData(const MElement *el, bool pyr, int nij, int nk,
                             const bool *serendip) :
  _tag(el->getTypeForMSH()), _spaceOrder(pyr ? nij+nk : std::max(nij, nk)),
  _serendipity(serendip ? *serendip : el->getIsOnlySerendipity()),
  _nij(nij), _nk(nk), _pyramidalSpace(pyr)
{
  if (el->getType() != TYPE_PYR)
    Msg::Error("Creation of pyramidal space data for a non-pyramid element !");
}

FuncSpaceData::FuncSpaceData(int tag, const bool *serendip) :
  _tag(tag), _spaceOrder(ElementType::OrderFromTag(tag)),
  _serendipity(serendip ? *serendip : ElementType::SerendipityFromTag(_tag) > 1),
  _nij(0), _nk(_spaceOrder),
  _pyramidalSpace(ElementType::ParentTypeFromTag(tag) == TYPE_PYR)
{}

FuncSpaceData::FuncSpaceData(bool isTag, int tagOrType, int order,
                             const bool *serendip, bool elemIsSerendip) :
  _tag(isTag ? tagOrType : ElementType::getTag(tagOrType, order, elemIsSerendip)),
  _spaceOrder(order),
  _serendipity(serendip ? *serendip : ElementType::SerendipityFromTag(_tag) > 1),
  _nij(0), _nk(_spaceOrder),
  _pyramidalSpace(isTag ?
      ElementType::ParentTypeFromTag(tagOrType) == TYPE_PYR :
      tagOrType == TYPE_PYR)
{}

FuncSpaceData::FuncSpaceData(bool isTag, int tagOrType, bool pyr, int nij,
                             int nk, const bool *serendip, bool elemIsSerendip) :
  _tag(isTag ? tagOrType :
       ElementType::getTag(tagOrType, pyr ? nij+nk : std::max(nij, nk), elemIsSerendip)),
  _spaceOrder(pyr ? nij+nk : std::max(nij, nk)),
  _serendipity(serendip ? *serendip : ElementType::SerendipityFromTag(_tag) > 1),
  _nij(nij), _nk(nk), _pyramidalSpace(pyr)
{
  if (ElementType::ParentTypeFromTag(_tag) != TYPE_PYR)
    Msg::Error("Creation of pyramidal space data for a non-pyramid element!");
}

void FuncSpaceData::getOrderForBezier(int order[3], int exponentZ) const
{
  if (_pyramidalSpace && exponentZ < 0) {
    Msg::Error("getOrderForBezier needs third exponent for pyramidal space!");
    order[0] = order[1] = order[2] = -1;
    return;
  }
  if (elementType() == TYPE_PYR) {
    if (_pyramidalSpace) {
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

FuncSpaceData FuncSpaceData::getForPrimaryElement() const
{
  int type = elementType();
  int primTag = ElementType::getTag(type, 1, elementIsOnlySerendipity());

  if (primTag == _tag) return *this;

  if (type == TYPE_PYR)
    return FuncSpaceData(true, primTag, _pyramidalSpace, _nij, _nk, &_serendipity);
  else
    return FuncSpaceData(true, primTag, _spaceOrder, &_serendipity);
}

FuncSpaceData FuncSpaceData::getForNonSerendipitySpace() const
{
  if (!_serendipity) return *this;

  int type = elementType();
  bool serendip = false;
  if (type == TYPE_PYR)
    return FuncSpaceData(true, _tag, _pyramidalSpace, _nij, _nk, &serendip);
  else
    return FuncSpaceData(true, _tag, _spaceOrder, &serendip);
}
