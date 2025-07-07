// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FUNCSPACEDATA_H
#define FUNCSPACEDATA_H

#include <cstddef>
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "ElementType.h"

class MElement;

class FuncSpaceData {
  // Store data that allows to easily know how to construct gradient, jacobian,
  // bezier and metric bases.

private:
  int _parentType, _spaceOrder;
  bool _isSerendipity;
  // For pyramids, '_spaceOrder' is not used.

  // Pyramids:
  int _xyOrder, _yOrder; // polynomial order in each direction
  bool _isPyramidalSpace;
  // There are two possible spaces in function of '_isPyramidalSpace'.
  // if '_isPyramidalSpace' == true, the space is a pyramid-like space:
  //   {X^i Y^j Z^k | i,j <= k+'_xyOrder', k <= '_yOrder'},
  // otherwise, the space is a hex-like space:
  //   {X^i Y^j Z^k | i,j <= '_xyOrder', k <= '_yOrder'},
  // where X = xi/(1-zeta), Y = eta/(1-zeta) and Z = (1-zeta).

public:
  FuncSpaceData()
    : _parentType(-1), _spaceOrder(-1), _isSerendipity(false), _xyOrder(-1), _yOrder(-1),
      _isPyramidalSpace(false)
  {
  }

  // Constructors for the function space of a different order
  FuncSpaceData(const FuncSpaceData &fsd, int order);
  FuncSpaceData(const FuncSpaceData &fsd, int nij, int nk);

  // Constructors using MElement*
  FuncSpaceData(const MElement *el);
  FuncSpaceData(const MElement *el, int order, bool serendip);
  FuncSpaceData(const MElement *el, bool pyr, int nij, int nk, bool serendip);

  // Constructor using element type or (parentType, order, serendip)
  FuncSpaceData(int tag);
  FuncSpaceData(int type, int order, bool serendip);
  FuncSpaceData(int type, bool pyr, int nij, int nk, bool serendip);

  // Print
  void print() const
  {
    Msg::Info("FuncSpaceData: type%d, order%d, nij%d, nk%d, pyr%d, serendip%d",
              _parentType, _spaceOrder, _xyOrder, _yOrder, _isPyramidalSpace,
              _isSerendipity);
  }

  // Get methods
  int getType() const { return _parentType; }
  int getDimension() const
  {
    switch(_parentType) {
    case TYPE_PNT: return 0;
    case TYPE_LIN: return 1;
    case TYPE_TRI:
    case TYPE_QUA: return 2;
    case TYPE_TET:
    case TYPE_PRI:
    case TYPE_HEX:
    case TYPE_PYR: return 3;
    default: return -1;
    }
  }
  int getSpaceOrder() const { return _spaceOrder; }
  int getXYOrder() const { return _xyOrder; }
  int getZOrder() const { return _yOrder; }
  bool getIsSerendipity() const { return _isSerendipity; }
  bool getIsPyramidalSpace() const { return _isPyramidalSpace; }

  void getOrderForBezier(int[3], int exponentZ = -1) const;

  // Change space
  FuncSpaceData getForNonSerendipitySpace() const;

  //
  inline bool operator<(const FuncSpaceData &other) const
  {
    if(_parentType == other._parentType) {
      if(_spaceOrder == other._spaceOrder) {
        if(_xyOrder == other._xyOrder) {
          if(_yOrder == other._yOrder) {
            return _isPyramidalSpace ? false : other._isPyramidalSpace;
          }
          else
            return _yOrder < other._yOrder;
        }
        else
          return _xyOrder < other._xyOrder;
      }
      else
        return _spaceOrder < other._spaceOrder;
    }
    else
      return _parentType < other._parentType;
  }
  inline bool operator==(const FuncSpaceData &other) const
  {
    return _parentType == other._parentType &&
           _spaceOrder == other._spaceOrder && _xyOrder == other._xyOrder &&
           _yOrder == other._yOrder && _isPyramidalSpace == other._isPyramidalSpace;
  }
};

#endif
