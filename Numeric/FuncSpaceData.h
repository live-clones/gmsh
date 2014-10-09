// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef FUNCSPACEDATA_H
#define FUNCSPACEDATA_H

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "ElementType.h"
#include <cstddef>
class MElement;

class FuncSpaceData
{
  // Store data that allow to easily know how to construct gradient, jacobian,
  // bezier and metric bases.

private:
  const int _tag, _spaceOrder, _nij, _nk;
  const bool _pyramidalSpace, _serendipity;
  // When '_parentType' == TYPE_PYR,
  // if _pyramidalSpace == true, then the space is {X^i Y^j Z^k | i,j <= k+'_nij', k <= '_nk'},
  // otherwise, the space is {X^i Y^j Z^k | i,j <= '_nij', k <= '_nk'},
  // where X = xi/(1-zeta), Y = eta/(1-zeta) and Z = 1-zeta.

public:

  // Constructors using MElement*
  FuncSpaceData(MElement *el, int *serendip = NULL);
  FuncSpaceData(MElement *el, int order, int *serendip = NULL);
  FuncSpaceData(MElement *el, bool pyr, int nij, int nk, int *serendip = NULL);

  // Constructors using element tag
  FuncSpaceData(int tag, int *serendip = NULL);

  // constructors using element tag or element type
  FuncSpaceData(bool isTag, int tagOrType, int order,
                const bool *serendip = NULL, bool elemIsSerendip = false);

  FuncSpaceData(bool isTag, int tagOrType, bool pyr, int nij, int nk,
                const bool *serendip = NULL, bool elemIsSerendip = false);

  // Print
  void print() const {
    Msg::Info("FuncSpaceData: tag%d, order%d, nij%d, nk%d, pyr%d, serendip%d",
        _tag, _spaceOrder, _nij, _nk, _pyramidalSpace, _serendipity);
  }

  // Get methods
  int elementTag() const {return _tag;}
  int elementType() const {return ElementType::ParentTypeFromTag(_tag);}
  int elementOrder() const {return ElementType::OrderFromTag(_tag);}
  int dimension() const {return ElementType::DimensionFromTag(_tag);}
  int spaceOrder() const {return _spaceOrder;}
  int nij() const {return _nij;}
  int nk() const {return _nk;}
  bool elementIsOnlySerendipity() const {
    return ElementType::SerendipityFromTag(_tag) > 1;
  }
  bool spaceIsSerendipity() const {return _serendipity;}
  bool isPyramidalSpace() const {return _pyramidalSpace;}

  void getOrderForBezier(int[3], int exponentZ = -1) const;

  // Change space
  FuncSpaceData getForPrimaryElement() const;
  FuncSpaceData getForNonSerendipitySpace() const;

  //
  inline bool operator<(const FuncSpaceData &other) const {
    if (_tag == other._tag) {
      if (_spaceOrder == other._spaceOrder) {
        if (_nij == other._nij) {
          if (_nk == other._nk) {
            return _pyramidalSpace == true ? false : other._pyramidalSpace;
          }
          else return _nk < other._nk;
        }
        else return _nij < other._nij;
      }
      else return _spaceOrder < other._spaceOrder;
    }
    else return _tag < other._tag;
  }
  inline bool operator==(const FuncSpaceData &other) const {
    return _tag == other._tag && _spaceOrder == other._spaceOrder &&
           _nij == other._nij && _nk == other._nk &&
           _pyramidalSpace == other._pyramidalSpace;
  }
};




#endif
