// $Id: SmoothNormals.cpp,v 1.5 2006-01-14 16:24:53 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Gmsh.h"
#include "Numeric.h"
#include "SmoothNormals.h"

double xyzn::eps = 1.e-12;

float xyzn::angle(int i, float nx, float ny, float nz)
{
  // computes the angle between the ith normal stored at point xyz and
  // the new normal nx,ny,nz
  double a[3] = {n[i].nx, n[i].ny, n[i].nz};
  double b[3] = {nx, ny, nz};
  norme(a);
  norme(b);
  double c[3];
  prodve(a, b, c);
  double cosc; 
  prosca(a, b, &cosc);
  double sinc = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
  double angplan = myatan2(sinc, cosc);
  return (float)(angplan * 180. / Pi);
}

void xyzn::update(float nx, float ny, float nz, double tol)
{
  int N = n.size();

  if(N > 100){
    // just ignore it if we have more than 100 clusters (think "more
    // than 100 elements touching a single vertex")
    return;
  }

  // we average by clusters of normals separated by tol; the result of
  // the averaging depends on the order in which we average (since we
  // store the average value as the cluster center as we go), but it
  // seems to work very nicely in practice (and it's faster than
  // storing everyting and averaging at the end)
  for(int i = 0; i < N; i++){
    if(tol >= 180. || fabs(angle(i, nx, ny, nz)) < tol){
      float c1 = (float)(n[i].nb) / (float)(n[i].nb + 1);
      float c2 = 1. / (float)(n[i].nb + 1);
      n[i].nx = (c1 * n[i].nx + c2 * nx);
      n[i].ny = (c1 * n[i].ny + c2 * ny);
      n[i].nz = (c1 * n[i].nz + c2 * nz);
      n[i].nb++;
      return;
    }
  }

  // create a new cluster
  nnb nn = {nx, ny, nz, 0};
  n.push_back(nn);
}

void smooth_normals::add(double x, double y, double z,
			 double nx, double ny, double nz)
{
  xyzn xyz(x, y, z);
  xyzn_iter it = c.find(xyz);
  if(it == c.end()) {
    xyz.update((float)nx, (float)ny, (float)nz, tol);
    c.insert(xyz);
  }
  else {
    xyzn *p = (xyzn *) & (*it);
    p->update((float)nx, (float)ny, (float)nz, tol);
  }    
}

bool smooth_normals::get(double x, double y, double z,
			 double &nx, double &ny, double &nz)
{
  xyzn xyz(x, y, z);
  xyzn_iter it = c.find(xyz);
  if(it == c.end())
    return false;

  xyzn *p = (xyzn *) & (*it);
  for(unsigned int i = 0; i < p->n.size(); i++){
    if(fabs(p->angle(i, (float)nx, (float)ny, (float)nz)) < tol) {
      nx = p->n[i].nx;
      ny = p->n[i].ny;
      nz = p->n[i].nz;
      break;
    }
  }
  return true;
}
