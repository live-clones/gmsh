// $Id: 2D_BGMesh.cpp,v 1.10 2002-05-18 07:56:49 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"
#include "2D_Mesh.h"

extern Mesh *THEM;

// Compute Calcul the charact. length on 1 pt by interpolating in the
// background mesh

double find_quality (MPoint center, DocRecord * BGMESH){

  int i;
  Delaunay *del;
  PointRecord *pPointArray;
  PointNumero a, b, c;
  double qual, q1, q2, q3, X[3], Y[3], u, v, det, Xp, Yp;
  double Exp = 2., r, deno, nume;

  if ((del = Find_Triangle (center, BGMESH, BOF)) == NULL){
    Msg(GERROR, "Exterior point (%g,%g)", center.v, center.h);
    return 1.e-15;
  }

  pPointArray = BGMESH->points;

  a = del->t.a;
  b = del->t.b;
  c = del->t.c;

  Xp = center.h;
  Yp = center.v;

  X[0] = pPointArray[a].where.h;
  X[1] = pPointArray[b].where.h;
  X[2] = pPointArray[c].where.h;

  Y[0] = pPointArray[a].where.v;
  Y[1] = pPointArray[b].where.v;
  Y[2] = pPointArray[c].where.v;

  q1 = pPointArray[a].quality;
  q2 = pPointArray[b].quality;
  q3 = pPointArray[c].quality;

  det = (X[2] - X[0]) * (Y[1] - Y[0]) - (Y[2] - Y[0]) * (X[1] - X[0]);

  if (det != 0.0){
    u = ((Xp - X[0]) * (Y[1] - Y[0]) - (Yp - Y[0]) * (X[1] - X[0])) / det;
    v = ((X[2] - X[0]) * (Yp - Y[0]) - (Y[2] - Y[0]) * (Xp - X[0])) / det;
  }
  else{
    Msg(WARNING, "Degenerated triangle (det=%g)", det);
    u = v = 0.0;
  }
  
  if (u >= -1.e-8 && v >= -1.e-8 && 1. - u - v >= -1.e-8){
    qual = q1 * (1. - u - v) + q2 * v + q3 * u;
    return (qual);
  }
  else{
    pPointArray = BGMESH->points;
    deno = nume = 0.0;
    for (i = 0; i < BGMESH->numPoints; i++){
      r = sqrt (DSQR (center.h - pPointArray[i].where.h) +
                DSQR (center.v - pPointArray[i].where.v));
      r = pow (r, Exp);
      if (r < 1.e-10)
        return (pPointArray[i].quality);
      nume += pPointArray[i].quality / r;
      deno += 1. / r;
    }
    return (nume / deno);
  }
}
