// $Id: SmoothNormals.cpp,v 1.3 2005-01-01 19:35:27 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

double xyzv::eps = 1.e-12;

xyzv::xyzv(double xx, double yy, double zz)
  : x(xx), y(yy), z(zz), vals(0), nbvals(0), nboccurences(0)
{
}

xyzv::~xyzv()
{
  if(vals)
    delete [] vals;
}

xyzv::xyzv(const xyzv & other)
{
  x = other.x;
  y = other.y;
  z = other.z;
  nbvals = other.nbvals;
  nboccurences = other.nboccurences;
  if(other.vals && other.nbvals) {
    vals = new double[other.nbvals];
    for(int i = 0; i < nbvals; i++)
      vals[i] = other.vals[i];
  }
}

xyzv & xyzv::operator =(const xyzv & other)
{
  if(this != &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    nbvals = other.nbvals;
    nboccurences = other.nboccurences;
    if(other.vals && other.nbvals) {
      vals = new double[other.nbvals];
      for(int i = 0; i < nbvals; i++)
        vals[i] = other.vals[i];
    }
  }
  return *this;
}

void xyzv::update(int n, double *v)
{
  int i;
  if(!vals) {
    vals = new double[n];
    for(i = 0; i < n; i++)
      vals[i] = 0.0;
    nbvals = n;
    nboccurences = 0;
  }
  else if(nbvals != n) {
    throw n;
  }

  double x1 = (double)(nboccurences) / (double)(nboccurences + 1);
  double x2 = 1. / (double)(nboccurences + 1);
  for(i = 0; i < nbvals; i++)
    vals[i] = (x1 * vals[i] + x2 * v[i]);
  nboccurences++;

  //printf("val(%d,%f,%f,%f) = %f\n",nboccurences,x,y,z,vals[0]);
}

double smooth_normals::get_angle(double *aa, double *bb)
{
  double angplan, cosc, sinc, a[3], b[3], c[3];
  if(!aa || !bb)
    return 0.;
  a[0] = aa[0];
  a[1] = aa[1];
  a[2] = aa[2];
  b[0] = bb[0];
  b[1] = bb[1];
  b[2] = bb[2];
  norme(a);
  norme(b);
  prodve(a, b, c);
  prosca(a, b, &cosc);
  sinc = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
  angplan = myatan2(sinc, cosc);
  return angplan * 180. / Pi;
}

void smooth_normals::add(double x, double y, double z,
			 double nx, double ny, double nz)
{
  double n[3] = { nx, ny, nz };
  xyzv xyz(x, y, z);
  xyziter it = c.find(xyz);
  if(it == c.end()) {
    xyz.update(3, n);
    c.insert(xyz);
  }
  else {
    xyzv *xx = (xyzv *) & (*it);
    xx->update(3, n);
  }    
}

bool smooth_normals::get(double x, double y, double z,
			 double &nx, double &ny, double &nz, double tol)
{
  double n[3] = { nx, ny, nz };
  xyzv xyz(x, y, z);
  xyziter it = c.find(xyz);
  if(it == c.end())
    return false;
  double angle = get_angle((*it).vals, n);
  if(fabs(angle) < tol) {
    nx = (*it).vals[0];
    ny = (*it).vals[1];
    nz = (*it).vals[2];
  }
  return true;
}

