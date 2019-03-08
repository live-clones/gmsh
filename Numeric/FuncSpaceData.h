// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FUNCSPACEDATA_H
#define FUNCSPACEDATA_H

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "ElementType.h"
#include <cstddef>
class MElement;

class FuncSpaceData {
  // Store data that allows to easily know how to construct gradient, jacobian,
  // bezier and metric bases.

private:
  int _tag, _spaceOrder;
  bool _serendipity;
  // '_tag' determine the type and the order of the element and if it is
  // serendipity.
  //
  // For non-pyramidal elements, the space is the space of the same type element
  // at order '_spaceOrder'. It is a serendipity space if '_serendipity' is
  // true.
  //
  // Pyramids
  int _nij, _nk;
  bool _pyramidalSpace;
  // For pyramids, '_spaceOrder' is not used.
  // There are two possible spaces in function of '_pyramidalSpace'.
  // if '_pyramidalSpace' == true, the space is a pyramid-like space:
  //   {X^i Y^j Z^k | i,j <= k+'_nij', k <= '_nk'},
  // otherwise, the space is a hex-like space:
  //   {X^i Y^j Z^k | i,j <= '_nij', k <= '_nk'},
  // where X = xi/(1-zeta), Y = eta/(1-zeta) and Z = (1-zeta).

public:
  FuncSpaceData()
    : _tag(-1), _spaceOrder(-1), _serendipity(false), _nij(-1), _nk(-1),
      _pyramidalSpace(false)
  {
  }

  // Constructors for the function space of a different order
  FuncSpaceData(const FuncSpaceData &fsd, int order,
                const bool *serendip = NULL);
  FuncSpaceData(const FuncSpaceData &fsd, int nij, int nk,
                const bool *serendip = NULL);

  // Constructors using MElement*
  FuncSpaceData(const MElement *el, const bool *serendip = NULL);
  FuncSpaceData(const MElement *el, int order, const bool *serendip = NULL);
  FuncSpaceData(const MElement *el, bool pyr, int nij, int nk,
                const bool *serendip = NULL);

  // Constructor using element tag
  FuncSpaceData(int tag, const bool *serendip = NULL);

  // constructors using element tag or element type
  FuncSpaceData(bool isTag, int tagOrType, int order,
                const bool *serendip = NULL, bool elemIsSerendip = false);
  FuncSpaceData(bool isTag, int tagOrType, bool pyr, int nij, int nk,
                const bool *serendip = NULL, bool elemIsSerendip = false);

  // Print
  void print() const
  {
    Msg::Info("FuncSpaceData: tag%d, order%d, nij%d, nk%d, pyr%d, serendip%d",
              _tag, _spaceOrder, _nij, _nk, _pyramidalSpace, _serendipity);
  }

  // Get methods
  int elementTag() const { return _tag; }
  int elementType() const { return ElementType::getParentType(_tag); }
  int dimension() const { return ElementType::getDimension(_tag); }
  int spaceOrder() const { return _spaceOrder; }
  int nij() const { return _nij; }
  int nk() const { return _nk; }
  bool spaceIsSerendipity() const { return _serendipity; }
  bool isPyramidalSpace() const { return _pyramidalSpace; }

  void getOrderForBezier(int[3], int exponentZ = -1) const;

  // Change space
  FuncSpaceData getForNonSerendipitySpace() const;

  //
  inline bool operator<(const FuncSpaceData &other) const
  {
    if(_tag == other._tag) {
      if(_spaceOrder == other._spaceOrder) {
        if(_nij == other._nij) {
          if(_nk == other._nk) {
            return _pyramidalSpace == true ? false : other._pyramidalSpace;
          }
          else
            return _nk < other._nk;
        }
        else
          return _nij < other._nij;
      }
      else
        return _spaceOrder < other._spaceOrder;
    }
    else
      return _tag < other._tag;
  }
  inline bool operator==(const FuncSpaceData &other) const
  {
    return _tag == other._tag && _spaceOrder == other._spaceOrder &&
           _nij == other._nij && _nk == other._nk &&
           _pyramidalSpace == other._pyramidalSpace;
  }
};

#endif
