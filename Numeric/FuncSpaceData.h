// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
  bool _serendipity;
  // For pyramids, '_spaceOrder' is not used.

  // Pyramids:
  int _nij, _nk;
  bool _pyramidalSpace;
  // There are two possible spaces in function of '_pyramidalSpace'.
  // if '_pyramidalSpace' == true, the space is a pyramid-like space:
  //   {X^i Y^j Z^k | i,j <= k+'_nij', k <= '_nk'},
  // otherwise, the space is a hex-like space:
  //   {X^i Y^j Z^k | i,j <= '_nij', k <= '_nk'},
  // where X = xi/(1-zeta), Y = eta/(1-zeta) and Z = (1-zeta).

public:
  FuncSpaceData()
    : _parentType(-1), _spaceOrder(-1), _serendipity(false), _nij(-1), _nk(-1),
      _pyramidalSpace(false)
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
              _parentType, _spaceOrder, _nij, _nk, _pyramidalSpace,
              _serendipity);
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
  int getNij() const { return _nij; }
  int getNk() const { return _nk; }
  bool getSerendipity() const { return _serendipity; }
  bool getPyramidalSpace() const { return _pyramidalSpace; }

  void getOrderForBezier(int[3], int exponentZ = -1) const;

  // Change space
  FuncSpaceData getForNonSerendipitySpace() const;

  //
  inline bool operator<(const FuncSpaceData &other) const
  {
    if(_parentType == other._parentType) {
      if(_spaceOrder == other._spaceOrder) {
        if(_nij == other._nij) {
          if(_nk == other._nk) {
            return _pyramidalSpace ? false : other._pyramidalSpace;
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
      return _parentType < other._parentType;
  }
  inline bool operator==(const FuncSpaceData &other) const
  {
    return _parentType == other._parentType &&
           _spaceOrder == other._spaceOrder && _nij == other._nij &&
           _nk == other._nk && _pyramidalSpace == other._pyramidalSpace;
  }
};

#endif
