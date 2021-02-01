// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "pointsGenerators.h"
#include "GmshDefines.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "FuncSpaceData.h"

// Points Generators

void gmshGeneratePoints(FuncSpaceData data, fullMatrix<double> &points)
{
  const int order = data.getSpaceOrder();
  const bool serendip = data.getSerendipity();
  switch(data.getType()) {
  case TYPE_PNT: points = gmshGeneratePointsLine(0); return;
  case TYPE_LIN: points = gmshGeneratePointsLine(order); return;
  case TYPE_TRI: points = gmshGeneratePointsTriangle(order, serendip); return;
  case TYPE_QUA: points = gmshGeneratePointsQuadrangle(order, serendip); return;
  case TYPE_TET:
    points = gmshGeneratePointsTetrahedron(order, serendip);
    return;
  case TYPE_PRI: points = gmshGeneratePointsPrism(order, serendip); return;
  case TYPE_HEX: points = gmshGeneratePointsHexahedron(order, serendip); return;
  case TYPE_PYR:
    points = gmshGeneratePointsPyramidGeneral(
      data.getPyramidalSpace(), data.getNij(), data.getNk(), serendip);
    return;
  default:
    Msg::Error("Unknown element type %d for points generation", data.getType());
    return;
  }
}

fullMatrix<double> gmshGeneratePointsLine(int order)
{
  fullMatrix<double> points = gmshGenerateMonomialsLine(order);
  if(order == 0) return points;
  points.scale(2. / order);
  points.add(-1.);
  return points;
}

fullMatrix<double> gmshGeneratePointsTriangle(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsTriangle(order, serendip);
  if(order == 0) return points;
  points.scale(1. / order);
  return points;
}

fullMatrix<double> gmshGeneratePointsQuadrangle(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsQuadrangle(order, serendip);
  if(order == 0) return points;
  points.scale(2. / order);
  points.add(-1.);
  return points;
}

fullMatrix<double> gmshGeneratePointsTetrahedron(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsTetrahedron(order, serendip);
  if(order == 0) return points;
  points.scale(1. / order);
  return points;
}

fullMatrix<double> gmshGeneratePointsHexahedron(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsHexahedron(order, serendip);
  if(order == 0) return points;
  points.scale(2. / order);
  points.add(-1.);
  return points;
}

fullMatrix<double> gmshGeneratePointsPrism(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsPrism(order, serendip);
  if(order == 0) return points;
  fullMatrix<double> tmp;
  tmp.setAsProxy(points, 0, 2);
  tmp.scale(1. / order);
  tmp.setAsProxy(points, 2, 1);
  tmp.scale(2. / order);
  tmp.add(-1.);
  return points;
}

fullMatrix<double> gmshGeneratePointsPyramid(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsPyramid(order, serendip);
  if(order == 0) return points;
  for(int i = 0; i < points.size1(); ++i) {
    points(i, 2) = 1 - points(i, 2) / order;
    const double duv = -1. + points(i, 2);
    points(i, 0) = duv + points(i, 0) * 2. / order;
    points(i, 1) = duv + points(i, 1) * 2. / order;
  }
  return points;
}

fullMatrix<double> gmshGeneratePointsPyramidGeneral(bool pyr, int nij, int nk,
                                                    bool forSerendipPoints)
{
  // if pyr:
  //   div = nk + nij
  //   monomial(i, j, k) -> (-(1-k')+2*i/div, -(1-k')+2*j/div, (nk-k)/div)
  // else:
  //   div = max(nij, nk)
  //   monomial(i, j, k) -> (-1+2*i/nij)*(1-k'), (-1+2*j/nij)*(1-k'),
  //   (nk-k)/div)
  fullMatrix<double> points =
    gmshGenerateMonomialsPyramidGeneral(pyr, nij, nk, forSerendipPoints);
  if(points.size1() == 1) return points;
  const int div = pyr ? nk + nij : std::max(nij, nk);
  double scale = 2. / div;
  for(int i = 0; i < points.size1(); ++i) {
    points(i, 2) = (nk - points(i, 2)) / div;
    const double duv = 1. - points(i, 2);
    if(!pyr) scale = 2. / nij * duv;
    points(i, 0) = -duv + points(i, 0) * scale;
    points(i, 1) = -duv + points(i, 1) * scale;
  }
  return points;
}

// Monomials Generators

void gmshGenerateMonomials(FuncSpaceData data, fullMatrix<double> &monomials)
{
  const int order = data.getSpaceOrder();
  const bool serendip = data.getSerendipity();
  switch(data.getType()) {
  case TYPE_PNT: monomials = gmshGenerateMonomialsLine(0); return;
  case TYPE_LIN: monomials = gmshGenerateMonomialsLine(order); return;
  case TYPE_TRI:
    monomials = gmshGenerateMonomialsTriangle(order, serendip);
    return;
  case TYPE_QUA:
    monomials = gmshGenerateMonomialsQuadrangle(order, serendip);
    return;
  case TYPE_TET:
    monomials = gmshGenerateMonomialsTetrahedron(order, serendip);
    return;
  case TYPE_PRI:
    monomials = gmshGenerateMonomialsPrism(order, serendip);
    return;
  case TYPE_HEX:
    monomials = gmshGenerateMonomialsHexahedron(order, serendip);
    return;
  case TYPE_PYR:
    monomials = gmshGenerateMonomialsPyramidGeneral(
      data.getPyramidalSpace(), data.getNij(), data.getNk(), serendip);
    return;
  default:
    Msg::Error("Unknown element type %d for monomials generation",
               data.getType());
    return;
  }
}

fullMatrix<double> gmshGenerateMonomialsLine(int order, bool serendip)
{
  fullMatrix<double> monomials(order + 1, 1);
  monomials(0, 0) = 0;
  if(order > 0) {
    monomials(1, 0) = order;
    for(int i = 2; i < order + 1; i++) monomials(i, 0) = i - 1;
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsTriangle(int order, bool serendip)
{
  int nbMonomials = serendip ? 3 * order : (order + 1) * (order + 2) / 2;
  if(serendip && !order) nbMonomials = 1;
  fullMatrix<double> monomials(nbMonomials, 2);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;

  if(order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;

    monomials(2, 0) = 0;
    monomials(2, 1) = order;

    if(order > 1) {
      int index = 3;
      for(int iedge = 0; iedge < 3; ++iedge) {
        int i0 = MTriangle::edges_tri(iedge, 0);
        int i1 = MTriangle::edges_tri(iedge, 1);

        int u_0 = (monomials(i1, 0) - monomials(i0, 0)) / order;
        int u_1 = (monomials(i1, 1) - monomials(i0, 1)) / order;

        for(int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + u_0 * i;
          monomials(index, 1) = monomials(i0, 1) + u_1 * i;
        }
      }
      if(!serendip && order > 2) {
        fullMatrix<double> inner = gmshGenerateMonomialsTriangle(order - 3);
        inner.add(1);
        monomials.copy(inner, 0, nbMonomials - index, 0, 2, index, 0);
      }
    }
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsQuadrangle(int order,
                                                   bool forSerendipPoints)
{
  int nbMonomials = forSerendipPoints ? order * 4 : (order + 1) * (order + 1);
  if(forSerendipPoints && !order) nbMonomials = 1;
  fullMatrix<double> monomials(nbMonomials, 2);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;

  if(order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;

    monomials(2, 0) = order;
    monomials(2, 1) = order;

    monomials(3, 0) = 0;
    monomials(3, 1) = order;

    if(order > 1) {
      int index = 4;
      for(int iedge = 0; iedge < 4; ++iedge) {
        int i0 = MQuadrangle::edges_quad(iedge, 0);
        int i1 = MQuadrangle::edges_quad(iedge, 1);

        int u_0 = (monomials(i1, 0) - monomials(i0, 0)) / order;
        int u_1 = (monomials(i1, 1) - monomials(i0, 1)) / order;

        for(int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + u_0 * i;
          monomials(index, 1) = monomials(i0, 1) + u_1 * i;
        }
      }

      if(!forSerendipPoints) {
        fullMatrix<double> inner = gmshGenerateMonomialsQuadrangle(order - 2);
        inner.add(1);
        monomials.copy(inner, 0, nbMonomials - index, 0, 2, index, 0);
      }
    }
  }
  return monomials;
}

/*
00 10 20 30 40 ...
01 11 21 31 41 ...
02 12
03 13
04 14
...
*/

fullMatrix<double> gmshGenerateMonomialsQuadSerendipity(int order)
{
  int nbMonomials = order ? order * 4 : 1;
  fullMatrix<double> monomials(nbMonomials, 2);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;

  if(order > 0) {
    monomials(1, 0) = 1;
    monomials(1, 1) = 0;

    monomials(2, 0) = 1;
    monomials(2, 1) = 1;

    monomials(3, 0) = 0;
    monomials(3, 1) = 1;

    if(order > 1) {
      int index = 3;
      for(int p = 2; p <= order; ++p) {
        monomials(++index, 0) = p;
        monomials(index, 1) = 0;

        monomials(++index, 0) = p;
        monomials(index, 1) = 1;

        monomials(++index, 0) = 1;
        monomials(index, 1) = p;

        monomials(++index, 0) = 0;
        monomials(index, 1) = p;
      }
    }
  }
  return monomials;
}

// KH : caveat : node coordinates are not yet coherent with node numbering
// associated
//              to numbering of principal vertices of face !!!!
fullMatrix<double> gmshGenerateMonomialsTetrahedron(int order, bool serendip)
{
  int nbMonomials = serendip ? 4 + (order - 1) * 6 :
                               (order + 1) * (order + 2) * (order + 3) / 6;
  if(serendip && !order) nbMonomials = 1;
  fullMatrix<double> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if(order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;
    monomials(1, 2) = 0;

    monomials(2, 0) = 0;
    monomials(2, 1) = order;
    monomials(2, 2) = 0;

    monomials(3, 0) = 0;
    monomials(3, 1) = 0;
    monomials(3, 2) = order;

    // the template has been defined in table edges_tetra and faces_tetra
    // (MElement.h)

    if(order > 1) {
      int index = 4;
      for(int iedge = 0; iedge < 6; ++iedge) {
        int i0 = MTetrahedron::edges_tetra(iedge, 0);
        int i1 = MTetrahedron::edges_tetra(iedge, 1);

        int u[3];
        u[0] = (monomials(i1, 0) - monomials(i0, 0)) / order;
        u[1] = (monomials(i1, 1) - monomials(i0, 1)) / order;
        u[2] = (monomials(i1, 2) - monomials(i0, 2)) / order;

        for(int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + u[0] * i;
          monomials(index, 1) = monomials(i0, 1) + u[1] * i;
          monomials(index, 2) = monomials(i0, 2) + u[2] * i;
        }
      }

      if(!serendip && order > 2) {
        fullMatrix<double> dudv = gmshGenerateMonomialsTriangle(order - 3);
        dudv.add(1);

        for(int iface = 0; iface < 4; ++iface) {
          int i0 = MTetrahedron::faces_tetra(iface, 0);
          int i1 = MTetrahedron::faces_tetra(iface, 1);
          int i2 = MTetrahedron::faces_tetra(iface, 2);

          int u[3];
          u[0] = (monomials(i1, 0) - monomials(i0, 0)) / order;
          u[1] = (monomials(i1, 1) - monomials(i0, 1)) / order;
          u[2] = (monomials(i1, 2) - monomials(i0, 2)) / order;
          int v[3];
          v[0] = (monomials(i2, 0) - monomials(i0, 0)) / order;
          v[1] = (monomials(i2, 1) - monomials(i0, 1)) / order;
          v[2] = (monomials(i2, 2) - monomials(i0, 2)) / order;

          for(int i = 0; i < dudv.size1(); ++i, ++index) {
            monomials(index, 0) =
              monomials(i0, 0) + u[0] * dudv(i, 0) + v[0] * dudv(i, 1);
            monomials(index, 1) =
              monomials(i0, 1) + u[1] * dudv(i, 0) + v[1] * dudv(i, 1);
            monomials(index, 2) =
              monomials(i0, 2) + u[2] * dudv(i, 0) + v[2] * dudv(i, 1);
          }
        }

        if(order > 3) {
          fullMatrix<double> inner =
            gmshGenerateMonomialsTetrahedron(order - 4);
          inner.add(1);
          monomials.copy(inner, 0, nbMonomials - index, 0, 3, index, 0);
        }
      }
    }
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsPrism(int order, bool forSerendipPoints)
{
  int nbMonomials = forSerendipPoints ?
                      6 + (order - 1) * 9 :
                      (order + 1) * (order + 1) * (order + 2) / 2;
  if(forSerendipPoints && !order) nbMonomials = 1;
  fullMatrix<double> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if(order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;
    monomials(1, 2) = 0;

    monomials(2, 0) = 0;
    monomials(2, 1) = order;
    monomials(2, 2) = 0;

    monomials(3, 0) = 0;
    monomials(3, 1) = 0;
    monomials(3, 2) = order;

    monomials(4, 0) = order;
    monomials(4, 1) = 0;
    monomials(4, 2) = order;

    monomials(5, 0) = 0;
    monomials(5, 1) = order;
    monomials(5, 2) = order;

    if(order > 1) {
      int index = 6;
      for(int iedge = 0; iedge < 9; ++iedge) {
        int i0 = MPrism::edges_prism(iedge, 0);
        int i1 = MPrism::edges_prism(iedge, 1);

        int u_1 = (monomials(i1, 0) - monomials(i0, 0)) / order;
        int u_2 = (monomials(i1, 1) - monomials(i0, 1)) / order;
        int u_3 = (monomials(i1, 2) - monomials(i0, 2)) / order;

        for(int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + i * u_1;
          monomials(index, 1) = monomials(i0, 1) + i * u_2;
          monomials(index, 2) = monomials(i0, 2) + i * u_3;
        }
      }

      if(!forSerendipPoints) {
        fullMatrix<double> dudvQ = gmshGenerateMonomialsQuadrangle(order - 2);
        dudvQ.add(1);

        fullMatrix<double> dudvT;
        if(order > 2) {
          dudvT = gmshGenerateMonomialsTriangle(order - 3);
          dudvT.add(1);
        }

        for(int iface = 0; iface < 5; ++iface) {
          int i0, i1, i2;
          i0 = MPrism::faces_prism(iface, 0);
          i1 = MPrism::faces_prism(iface, 1);
          fullMatrix<double> dudv;
          if(MPrism::faces_prism(iface, 3) != -1) {
            i2 = MPrism::faces_prism(iface, 3);
            dudv.setAsProxy(dudvQ);
          }
          else if(order > 2) {
            i2 = MPrism::faces_prism(iface, 2);
            dudv.setAsProxy(dudvT);
          }
          else
            continue;

          int u[3];
          u[0] = (monomials(i1, 0) - monomials(i0, 0)) / order;
          u[1] = (monomials(i1, 1) - monomials(i0, 1)) / order;
          u[2] = (monomials(i1, 2) - monomials(i0, 2)) / order;
          int v[3];
          v[0] = (monomials(i2, 0) - monomials(i0, 0)) / order;
          v[1] = (monomials(i2, 1) - monomials(i0, 1)) / order;
          v[2] = (monomials(i2, 2) - monomials(i0, 2)) / order;

          for(int i = 0; i < dudv.size1(); ++i, ++index) {
            monomials(index, 0) =
              monomials(i0, 0) + u[0] * dudv(i, 0) + v[0] * dudv(i, 1);
            monomials(index, 1) =
              monomials(i0, 1) + u[1] * dudv(i, 0) + v[1] * dudv(i, 1);
            monomials(index, 2) =
              monomials(i0, 2) + u[2] * dudv(i, 0) + v[2] * dudv(i, 1);
          }
        }

        if(order > 2) {
          fullMatrix<double> triMonomials =
            gmshGenerateMonomialsTriangle(order - 3);
          fullMatrix<double> lineMonomials =
            gmshGenerateMonomialsLine(order - 2);

          for(int i = 0; i < triMonomials.size1(); ++i) {
            for(int j = 0; j < lineMonomials.size1(); ++j, ++index) {
              monomials(index, 0) = 1 + triMonomials(i, 0);
              monomials(index, 1) = 1 + triMonomials(i, 1);
              monomials(index, 2) = 1 + lineMonomials(j, 0);
            }
          }
        }
      }
    }
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsPrismSerendipity(int order)
{
  int nbMonomials = order ? 6 + (order - 1) * 9 : 1;
  fullMatrix<double> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if(order > 0) {
    monomials(1, 0) = 1;
    monomials(1, 1) = 0;
    monomials(1, 2) = 0;

    monomials(2, 0) = 0;
    monomials(2, 1) = 1;
    monomials(2, 2) = 0;

    monomials(3, 0) = 0;
    monomials(3, 1) = 0;
    monomials(3, 2) = 1;

    monomials(4, 0) = 1;
    monomials(4, 1) = 0;
    monomials(4, 2) = 1;

    monomials(5, 0) = 0;
    monomials(5, 1) = 1;
    monomials(5, 2) = 1;

    if(order > 1) {
      const int ind[7][3] = {{2, 0, 0}, {2, 0, 1},

                             {0, 2, 0}, {0, 2, 1},

                             {0, 0, 2}, {1, 0, 2}, {0, 1, 2}};
      int val[3] = {0, 1, -1};
      int index = 5;
      for(int p = 2; p <= order; ++p) {
        val[2] = p;
        for(int i = 0; i < 7; ++i) {
          monomials(++index, 0) = val[ind[i][0]];
          monomials(index, 1) = val[ind[i][1]];
          monomials(index, 2) = val[ind[i][2]];
        }
      }

      int val0 = 1;
      int val1 = order - 1;
      for(int p = 2; p <= order; ++p) {
        monomials(++index, 0) = val0;
        monomials(index, 1) = val1;
        monomials(index, 2) = 0;

        monomials(++index, 0) = val0;
        monomials(index, 1) = val1;
        monomials(index, 2) = 1;

        ++val0;
        --val1;
      }
    }
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsHexahedron(int order,
                                                   bool forSerendipPoints)
{
  int nbMonomials = forSerendipPoints ? 8 + (order - 1) * 12 :
                                        (order + 1) * (order + 1) * (order + 1);
  if(forSerendipPoints && !order) nbMonomials = 1;
  fullMatrix<double> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if(order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;
    monomials(1, 2) = 0;

    monomials(2, 0) = order;
    monomials(2, 1) = order;
    monomials(2, 2) = 0;

    monomials(3, 0) = 0;
    monomials(3, 1) = order;
    monomials(3, 2) = 0;

    monomials(4, 0) = 0;
    monomials(4, 1) = 0;
    monomials(4, 2) = order;

    monomials(5, 0) = order;
    monomials(5, 1) = 0;
    monomials(5, 2) = order;

    monomials(6, 0) = order;
    monomials(6, 1) = order;
    monomials(6, 2) = order;

    monomials(7, 0) = 0;
    monomials(7, 1) = order;
    monomials(7, 2) = order;

    if(order > 1) {
      int index = 8;
      for(int iedge = 0; iedge < 12; ++iedge) {
        int i0 = MHexahedron::edges_hexa(iedge, 0);
        int i1 = MHexahedron::edges_hexa(iedge, 1);

        int u_1 = (monomials(i1, 0) - monomials(i0, 0)) / order;
        int u_2 = (monomials(i1, 1) - monomials(i0, 1)) / order;
        int u_3 = (monomials(i1, 2) - monomials(i0, 2)) / order;

        for(int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + i * u_1;
          monomials(index, 1) = monomials(i0, 1) + i * u_2;
          monomials(index, 2) = monomials(i0, 2) + i * u_3;
        }
      }

      if(!forSerendipPoints) {
        fullMatrix<double> dudv = gmshGenerateMonomialsQuadrangle(order - 2);
        dudv.add(1);

        for(int iface = 0; iface < 6; ++iface) {
          int i0 = MHexahedron::faces_hexa(iface, 0);
          int i1 = MHexahedron::faces_hexa(iface, 1);
          int i3 = MHexahedron::faces_hexa(iface, 3);

          int u[3];
          u[0] = (monomials(i1, 0) - monomials(i0, 0)) / order;
          u[1] = (monomials(i1, 1) - monomials(i0, 1)) / order;
          u[2] = (monomials(i1, 2) - monomials(i0, 2)) / order;
          int v[3];
          v[0] = (monomials(i3, 0) - monomials(i0, 0)) / order;
          v[1] = (monomials(i3, 1) - monomials(i0, 1)) / order;
          v[2] = (monomials(i3, 2) - monomials(i0, 2)) / order;

          for(int i = 0; i < dudv.size1(); ++i, ++index) {
            monomials(index, 0) =
              monomials(i0, 0) + u[0] * dudv(i, 0) + v[0] * dudv(i, 1);
            monomials(index, 1) =
              monomials(i0, 1) + u[1] * dudv(i, 0) + v[1] * dudv(i, 1);
            monomials(index, 2) =
              monomials(i0, 2) + u[2] * dudv(i, 0) + v[2] * dudv(i, 1);
          }
        }

        fullMatrix<double> inner = gmshGenerateMonomialsHexahedron(order - 2);
        inner.add(1);
        monomials.copy(inner, 0, nbMonomials - index, 0, 3, index, 0);
      }
    }
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsHexaSerendipity(int order)
{
  int nbMonomials = order ? 8 + (order - 1) * 12 : 1;
  fullMatrix<double> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if(order > 0) {
    monomials(1, 0) = 1;
    monomials(1, 1) = 0;
    monomials(1, 2) = 0;

    monomials(2, 0) = 1;
    monomials(2, 1) = 1;
    monomials(2, 2) = 0;

    monomials(3, 0) = 0;
    monomials(3, 1) = 1;
    monomials(3, 2) = 0;

    monomials(4, 0) = 0;
    monomials(4, 1) = 0;
    monomials(4, 2) = 1;

    monomials(5, 0) = 1;
    monomials(5, 1) = 0;
    monomials(5, 2) = 1;

    monomials(6, 0) = 1;
    monomials(6, 1) = 1;
    monomials(6, 2) = 1;

    monomials(7, 0) = 0;
    monomials(7, 1) = 1;
    monomials(7, 2) = 1;

    if(order > 1) {
      const int ind[12][3] = {{2, 0, 0}, {2, 0, 1}, {2, 1, 1}, {2, 1, 0},

                              {0, 2, 0}, {0, 2, 1}, {1, 2, 1}, {1, 2, 0},

                              {0, 0, 2}, {0, 1, 2}, {1, 1, 2}, {1, 0, 2}};
      int val[3] = {0, 1, -1};
      int index = 7;
      for(int p = 2; p <= order; ++p) {
        val[2] = p;
        for(int i = 0; i < 12; ++i) {
          monomials(++index, 0) = val[ind[i][0]];
          monomials(index, 1) = val[ind[i][1]];
          monomials(index, 2) = val[ind[i][2]];
        }
      }
    }
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsPyramid(int order,
                                                bool forSerendipPoints)
{
  int nbMonomials = forSerendipPoints ? 5 + (order - 1) * 8 :
                                        (order + 1) * ((order + 1) + 1) *
                                          (2 * (order + 1) + 1) / 6;
  if(forSerendipPoints && !order) nbMonomials = 1;

  fullMatrix<double> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = order;

  if(order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;
    monomials(1, 2) = order;

    monomials(2, 0) = order;
    monomials(2, 1) = order;
    monomials(2, 2) = order;

    monomials(3, 0) = 0;
    monomials(3, 1) = order;
    monomials(3, 2) = order;

    monomials(4, 0) = 0;
    monomials(4, 1) = 0;
    monomials(4, 2) = 0;

    if(order > 1) {
      int index = 5;
      for(int iedge = 0; iedge < 8; ++iedge) {
        int i0 = MPyramid::edges_pyramid(iedge, 0);
        int i1 = MPyramid::edges_pyramid(iedge, 1);

        int u_1 = (monomials(i1, 0) - monomials(i0, 0)) / order;
        int u_2 = (monomials(i1, 1) - monomials(i0, 1)) / order;
        int u_3 = (monomials(i1, 2) - monomials(i0, 2)) / order;

        for(int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + i * u_1;
          monomials(index, 1) = monomials(i0, 1) + i * u_2;
          monomials(index, 2) = monomials(i0, 2) + i * u_3;
        }
      }

      if(!forSerendipPoints) {
        fullMatrix<double> dudvQ = gmshGenerateMonomialsQuadrangle(order - 2);
        dudvQ.add(1);

        fullMatrix<double> dudvT;
        if(order > 2) {
          dudvT = gmshGenerateMonomialsTriangle(order - 3);
          dudvT.add(1);
        }

        for(int iface = 0; iface < 5; ++iface) {
          int i0, i1, i2;
          i0 = MPyramid::faces_pyramid(iface, 0);
          i1 = MPyramid::faces_pyramid(iface, 1);
          fullMatrix<double> dudv;
          if(MPyramid::faces_pyramid(iface, 3) != -1) {
            i2 = MPyramid::faces_pyramid(iface, 3);
            dudv.setAsProxy(dudvQ);
          }
          else if(order > 2) {
            i2 = MPyramid::faces_pyramid(iface, 2);
            dudv.setAsProxy(dudvT);
          }
          else
            continue;

          int u[3];
          u[0] = (monomials(i1, 0) - monomials(i0, 0)) / order;
          u[1] = (monomials(i1, 1) - monomials(i0, 1)) / order;
          u[2] = (monomials(i1, 2) - monomials(i0, 2)) / order;
          int v[3];
          v[0] = (monomials(i2, 0) - monomials(i0, 0)) / order;
          v[1] = (monomials(i2, 1) - monomials(i0, 1)) / order;
          v[2] = (monomials(i2, 2) - monomials(i0, 2)) / order;

          for(int i = 0; i < dudv.size1(); ++i, ++index) {
            monomials(index, 0) =
              monomials(i0, 0) + u[0] * dudv(i, 0) + v[0] * dudv(i, 1);
            monomials(index, 1) =
              monomials(i0, 1) + u[1] * dudv(i, 0) + v[1] * dudv(i, 1);
            monomials(index, 2) =
              monomials(i0, 2) + u[2] * dudv(i, 0) + v[2] * dudv(i, 1);
          }
        }

        if(order > 2) {
          fullMatrix<double> inner = gmshGenerateMonomialsPyramid(order - 3);
          fullMatrix<double> prox;
          prox.setAsProxy(inner, 0, 2);
          prox.add(1);
          prox.setAsProxy(inner, 2, 1);
          prox.add(2);
          monomials.copy(inner, 0, nbMonomials - index, 0, 3, index, 0);
        }
      }
    }
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsPyramidSerendipity(int order)
{
  // WARNING: Is it correct?
  int nbMonomials = order ? 5 + (order - 1) * 8 : 1;

  fullMatrix<double> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if(order > 0) {
    monomials(1, 0) = 0;
    monomials(1, 1) = 0;
    monomials(1, 2) = 1;

    monomials(2, 0) = 1;
    monomials(2, 1) = 0;
    monomials(2, 2) = 1;

    monomials(3, 0) = 0;
    monomials(3, 1) = 1;
    monomials(3, 2) = 1;

    monomials(4, 0) = 1;
    monomials(4, 1) = 1;
    monomials(4, 2) = 1;

    // monomials of tetrahedra plus a bit more
    if(order > 1) {
      int idx = 5;
      for(int i = 2; i <= order; ++i, ++idx) {
        monomials(idx, 0) = 0;
        monomials(idx, 1) = 0;
        monomials(idx, 2) = i;
      }
      for(int i = 2; i <= order; ++i, ++idx) {
        monomials(idx, 0) = i;
        monomials(idx, 1) = 0;
        monomials(idx, 2) = i;
      }
      for(int i = 2; i <= order; ++i, ++idx) {
        monomials(idx, 0) = 0;
        monomials(idx, 1) = i;
        monomials(idx, 2) = i;
      }
      for(int i = 1; i < order; ++i, ++idx) {
        monomials(idx, 0) = i;
        monomials(idx, 1) = 0;
        monomials(idx, 2) = order;
      }
      for(int i = 1; i < order; ++i, ++idx) {
        monomials(idx, 0) = 0;
        monomials(idx, 1) = i;
        monomials(idx, 2) = order;
      }
      for(int i = 1; i < order; ++i, ++idx) {
        monomials(idx, 0) = i;
        monomials(idx, 1) = order - i;
        monomials(idx, 2) = order;
      }
      for(int i = 2; i <= order; ++i, ++idx) {
        monomials(idx, 0) = i;
        monomials(idx, 1) = 1;
        monomials(idx, 2) = i;
      }
      for(int i = 2; i <= order; ++i, ++idx) {
        monomials(idx, 0) = 1;
        monomials(idx, 1) = i;
        monomials(idx, 2) = i;
      }
    }
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsPyramidGeneral(bool pyr, int nij,
                                                       int nk,
                                                       bool forSerendipPoints)
{
  if(nij < 0 || nk < 0) {
    Msg::Error("Wrong arguments for pyramid's monomials generation ! (%d & %d)",
               nij, nk);
    nij = nk = 1;
  }
  if(!pyr && nk > 0 && nij == 0) {
    Msg::Error("Wrong argument association for pyramid's monomials generation! "
               "Setting nij to 1");
    nij = 1;
  }

  // If monomials for pyramidal space, generate them in gmsh convention.
  if(forSerendipPoints || (pyr && nij == 0))
    return gmshGenerateMonomialsPyramid(nk, forSerendipPoints);

  // Otherwise, just put corners at first places,
  // order of others having no importance.

  int nbMonomials;
  if(pyr) {
    nbMonomials = 0;
    for(int k = 0; k <= nk; ++k) {
      nbMonomials += (k + nij + 1) * (k + nij + 1);
    }
  }
  else
    nbMonomials = (nij + 1) * (nij + 1) * (nk + 1);

  fullMatrix<double> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = nk;

  if(nk == 0 && nij == 0) return monomials;

  // Here, nij > 0
  int nijBase = pyr ? nk + nij : nij;

  // Corners
  monomials(1, 0) = nijBase;
  monomials(1, 1) = 0;
  monomials(1, 2) = nk;

  monomials(2, 0) = nijBase;
  monomials(2, 1) = nijBase;
  monomials(2, 2) = nk;

  monomials(3, 0) = 0;
  monomials(3, 1) = nijBase;
  monomials(3, 2) = nk;

  int index = 4;

  if(nk > 0) {
    monomials(4, 0) = 0;
    monomials(4, 1) = 0;
    monomials(4, 2) = 0;

    monomials(5, 0) = nij;
    monomials(5, 1) = 0;
    monomials(5, 2) = 0;

    monomials(6, 0) = nij;
    monomials(6, 1) = nij;
    monomials(6, 2) = 0;

    monomials(7, 0) = 0;
    monomials(7, 1) = nij;
    monomials(7, 2) = 0;

    index = 8;
  }

  // Base
  if(nijBase > 1) {
    for(int iedge = 0; iedge < 4; ++iedge) {
      int i0 = iedge;
      int i1 = (iedge + 1) % 4;

      int u0 =
        static_cast<int>((monomials(i1, 0) - monomials(i0, 0)) / nijBase);
      int u1 =
        static_cast<int>((monomials(i1, 1) - monomials(i0, 1)) / nijBase);

      for(int i = 1; i < nijBase; ++i, ++index) {
        monomials(index, 0) = monomials(i0, 0) + i * u0;
        monomials(index, 1) = monomials(i0, 1) + i * u1;
        monomials(index, 2) = nk;
      }
    }

    for(int i = 1; i < nijBase; ++i) {
      for(int j = 1; j < nijBase; ++j, ++index) {
        monomials(index, 0) = i;
        monomials(index, 1) = j;
        monomials(index, 2) = nk;
      }
    }
  }

  // Above base
  if(nk > 0) {
    // Top
    if(nij > 1) {
      for(int iedge = 0; iedge < 4; ++iedge) {
        int i0 = 4 + iedge;
        int i1 = 4 + (iedge + 1) % 4;

        int u0 = static_cast<int>((monomials(i1, 0) - monomials(i0, 0)) / nij);
        int u1 = static_cast<int>((monomials(i1, 1) - monomials(i0, 1)) / nij);

        for(int i = 1; i < nij; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + i * u0;
          monomials(index, 1) = monomials(i0, 1) + i * u1;
          monomials(index, 2) = 0;
        }
      }

      for(int i = 1; i < nij; ++i) {
        for(int j = 1; j < nij; ++j, ++index) {
          monomials(index, 0) = i;
          monomials(index, 1) = j;
          monomials(index, 2) = 0;
        }
      }
    }

    // Between bottom & top
    for(int k = nk - 1; k > 0; --k) {
      int currentnij = pyr ? k + nij : nij;
      for(int i = 0; i <= currentnij; ++i) {
        for(int j = 0; j <= currentnij; ++j, ++index) {
          monomials(index, 0) = i;
          monomials(index, 1) = j;
          monomials(index, 2) = k;
        }
      }
    }
  }

  return monomials;
}

// Ordered points and monomials

void gmshGenerateOrderedPointsLine(int order, fullVector<double> &points)
{
  points.resize(order + 1);
  for(int i = 0; i < order + 1; ++i) {
    points(i) = i / static_cast<double>(order);
  }
  return;
}

void gmshGenerateOrderedPoints(FuncSpaceData data, fullMatrix<double> &points,
                               bool bezierSpace)
{
  gmshGenerateOrderedMonomials(data, points);
  if(points.size1() == 1) return;

  const int type = data.getType();
  const int order = data.getSpaceOrder();
  const bool pyr = data.getPyramidalSpace();

  if(bezierSpace) {
    if(type != TYPE_PYR) {
      points.scale(1. / order);
      return;
    }
    else {
      // This is used for creating the matrices bez2lag and lag2bez and we want
      // the points of the "unshrinked" pyramid. In other words, we want them
      // mapped from the pyramid to the cube.
      // if pyr:
      //   div = nk + nij
      //   monomial(i, j, k) -> (i/div/(1-k'), j/div/(1-k'), (nk-k)/div)
      // else:
      //   div = max(nij, nk)
      //   monomial(i, j, k) -> (i/nij, j/nij, (nk-k)/div)
      const int nij = data.getNij();
      const int nk = data.getNk();
      const int div = pyr ? nij + nk : std::max(nij, nk);
      double scale = 1. / nij;
      for(int i = 0; i < points.size1(); ++i) {
        points(i, 2) = (nk - points(i, 2)) / div;
        if(pyr) scale = 1. / div / (1 - points(i, 2));
        points(i, 0) = points(i, 0) * scale;
        points(i, 1) = points(i, 1) * scale;
      }
    }
    return;
  }

  switch(type) {
  case TYPE_PNT: return;
  case TYPE_LIN:
  case TYPE_QUA:
  case TYPE_HEX:
    points.scale(2. / order);
    points.add(-1.);
    return;
  case TYPE_TRI:
  case TYPE_TET: points.scale(1. / order); return;
  case TYPE_PRI: {
    fullMatrix<double> tmp;
    tmp.setAsProxy(points, 0, 2);
    tmp.scale(1. / order);
    tmp.setAsProxy(points, 2, 1);
    tmp.scale(2. / order);
    tmp.add(-1.);
    return;
  }
  case TYPE_PYR: {
    // This is used e.g. for creating sampling points. We want the points to be
    // inside the reference pyramids.
    // if pyr:
    //   div = nk + nij
    //   monomial(i, j, k) -> (-(1-k')+2*i/div, -(1-k')+2*j/div, (nk-k)/div)
    // else:
    //   div = max(nij, nk)
    //   monomial(i, j, k) -> (-1+2*i/nij)*(1-k'), (-1+2*j/nij)*(1-k'),
    //   (nk-k)/div)
    const int nij = data.getNij();
    const int nk = data.getNk();
    const int div = pyr ? nij + nk : std::max(nij, nk);
    double scale = 2. / div;
    for(int i = 0; i < points.size1(); ++i) {
      points(i, 2) = (nk - points(i, 2)) / div;
      const double duv = 1. - points(i, 2);
      if(!pyr) scale = 2. / nij * duv;
      points(i, 0) = -duv + points(i, 0) * scale;
      points(i, 1) = -duv + points(i, 1) * scale;
    }
    return;
  }
  default: return;
  }
}

void gmshGenerateOrderedMonomials(FuncSpaceData data,
                                  fullMatrix<double> &monomials)
{
  if(data.getSerendipity())
    Msg::Warning("Ordered monomials for serendipity elements not implemented");

  int idx, order = data.getSpaceOrder();

  switch(data.getType()) {
  case TYPE_LIN:
    monomials.resize(order + 1, 1);
    idx = 0;
    for(int i = 0; i < order + 1; ++i) {
      monomials(idx, 0) = i;
      ++idx;
    }
    return;
  case TYPE_TRI:
    monomials.resize((order + 1) * (order + 2) / 2, 2);
    idx = 0;
    for(int j = 0; j < order + 1; ++j) {
      for(int i = 0; i < order + 1 - j; ++i) {
        monomials(idx, 0) = i;
        monomials(idx, 1) = j;
        ++idx;
      }
    }
    return;
  case TYPE_QUA:
    monomials.resize((order + 1) * (order + 1), 2);
    idx = 0;
    for(int j = 0; j < order + 1; ++j) {
      for(int i = 0; i < order + 1; ++i) {
        monomials(idx, 0) = i;
        monomials(idx, 1) = j;
        ++idx;
      }
    }
    return;
  case TYPE_TET:
    monomials.resize((order + 1) * (order + 2) * (order + 3) / 6, 3);
    idx = 0;
    for(int k = 0; k < order + 1; ++k) {
      for(int j = 0; j < order + 1 - k; ++j) {
        for(int i = 0; i < order + 1 - j - k; ++i) {
          monomials(idx, 0) = i;
          monomials(idx, 1) = j;
          monomials(idx, 2) = k;
          ++idx;
        }
      }
    }
    return;
  case TYPE_PRI:
    monomials.resize((order + 1) * (order + 1) * (order + 2) / 2, 3);
    idx = 0;
    for(int k = 0; k < order + 1; ++k) {
      for(int j = 0; j < order + 1; ++j) {
        for(int i = 0; i < order + 1 - j; ++i) {
          monomials(idx, 0) = i;
          monomials(idx, 1) = j;
          monomials(idx, 2) = k;
          ++idx;
        }
      }
    }
    return;
  case TYPE_HEX:
    monomials.resize((order + 1) * (order + 1) * (order + 1), 3);
    idx = 0;
    for(int k = 0; k < order + 1; ++k) {
      for(int j = 0; j < order + 1; ++j) {
        for(int i = 0; i < order + 1; ++i) {
          monomials(idx, 0) = i;
          monomials(idx, 1) = j;
          monomials(idx, 2) = k;
          ++idx;
        }
      }
    }
    return;
  case TYPE_PYR: {
    const int nij = data.getNij();
    const int nk = data.getNk();
    if(data.getPyramidalSpace()) {
      int n = nk + nij;
      int numMonomials = (n + 1) * (n + 2) * (2 * n + 3) / 6;
      numMonomials -= nij * (nij + 1) * (2 * nij + 1) / 6;
      monomials.resize(numMonomials, 3);
      idx = 0;
      for(int k = nk; k >= 0; --k) {
        for(int j = 0; j < k + nij + 1; ++j) {
          for(int i = 0; i < k + nij + 1; ++i) {
            monomials(idx, 0) = i;
            monomials(idx, 1) = j;
            monomials(idx, 2) = k;
            ++idx;
          }
        }
      }
    }
    else {
      monomials.resize((nij + 1) * (nij + 1) * (nk + 1), 3);
      idx = 0;
      for(int k = nk; k >= 0; --k) {
        for(int j = 0; j < nij + 1; ++j) {
          for(int i = 0; i < nij + 1; ++i) {
            monomials(idx, 0) = i;
            monomials(idx, 1) = j;
            monomials(idx, 2) = k;
            ++idx;
          }
        }
      }
    }
    return;
  }
  default:
    Msg::Error("Unknown element type for ordered monomials: %d",
               data.getType());
    monomials.resize(1, 1);
    return;
  }
}
