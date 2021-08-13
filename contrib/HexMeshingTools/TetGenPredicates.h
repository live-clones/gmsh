// This file is part of Tetgen/BR, the Boundary Recovery code of TetGen
//
// Copyright 2015-2016 Weierstrass Institute for Applied Analysis and
// Stochastics
//
// This file is relicensed under the terms of LICENSE.txt for use in Gmsh thanks
// to a Software License Agreement between Weierstrass Institute for Applied
// Analysis and Stochastics and GMESH SPRL.


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TetGen                                                                    //
//                                                                           //
// A Quality Tetrahedral Mesh Generator and A 3D Delaunay Triangulator       //
//                                                                           //
// Version 1.5                                                               //
// May 31, 2014                                                              //
//                                                                           //
// Copyright (C) 2002--2016                                                  //
//                                                                           //
// TetGen is freely available through the website: http://www.tetgen.org.    //
//   It may be copied, modified, and redistributed for non-commercial use.   //
//   Please consult the file LICENSE for the detailed copyright notices.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math.h>

namespace TetGenPredicates {
  using REAL = double;
  using point = REAL*;

  // Labels that signify the result of triangle-triangle intersection test.
  enum interresult {
    DISJOINT,
    INTERSECT,
    SHAREVERT,
    SHAREEDGE,
    SHAREFACE,
    TOUCHEDGE,
    TOUCHFACE,
    ACROSSVERT,
    ACROSSEDGE,
    ACROSSFACE
  };

  // Triangle-edge intersection test (robust)
  int tri_edge_2d(point, point, point, point, point, point, int, int *, int *);
  int tri_edge_tail(point, point, point, point, point, point, REAL, REAL, int,
                    int *, int *);
  int tri_edge_test(point, point, point, point, point, point, int, int *,
                    int *);

  // Triangle-triangle intersection test (robust)
  int tri_edge_inter_tail(point, point, point, point, point, REAL, REAL);
  int tri_tri_inter(point, point, point, point, point, point);


}
