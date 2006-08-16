// $Id: SmoothNormals.cpp,v 1.7 2006-08-16 05:25:22 geuzaine Exp $
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

float xyzn::eps = 1.e-6;

float xyzn::angle(int i, char nx, char ny, char nz)
{
  // returns the angle (in [-180,180]) between the ith normal stored
  // at point xyz and the new normal nx,ny,nz
  double a[3] = {char2float(n[i].nx), 
		 char2float(n[i].ny), 
		 char2float(n[i].nz)};
  double b[3] = {char2float(nx), 
		 char2float(ny), 
		 char2float(nz)};
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

void xyzn::update(char nx, char ny, char nz, float tol)
{
  // just ignore it if we have more than 100 clusters
  if(n.size() > 100) return;

  // we average by clusters of normals separated by tol; the result of
  // the averaging depends on the order in which we average (since we
  // store the average value as the cluster center as we go), but it
  // seems to work very nicely in practice (and it's faster than
  // storing everyting and averaging at the end)
  for(unsigned int i = 0; i < n.size(); i++){
    if(tol >= 180. || fabs(angle(i, nx, ny, nz)) < tol){
      // just ignore it if we have more than 100 contributions to a
      // single point...
      if(n[i].nb < 100){
	float c1 = (float)(n[i].nb) / (float)(n[i].nb + 1);
	float c2 = 1. / (float)(n[i].nb + 1);
	n[i].nx = (char)(c1 * n[i].nx + c2 * nx);
	n[i].ny = (char)(c1 * n[i].ny + c2 * ny);
	n[i].nz = (char)(c1 * n[i].nz + c2 * nz);
	n[i].nb++;
      }
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

  std::set<xyzn, lessthanxyzn>::const_iterator it = c.find(xyz);
  if(it == c.end()) {
    xyz.update(float2char(nx), 
	       float2char(ny), 
	       float2char(nz), tol);
    c.insert(xyz);
  }
  else {
    xyzn *p = (xyzn *) & (*it);
    p->update(float2char(nx), 
	      float2char(ny), 
	      float2char(nz), tol);
  }    
}

bool smooth_normals::get(double x, double y, double z,
			 double &nx, double &ny, double &nz)
{
  std::set<xyzn, lessthanxyzn>::const_iterator it = c.find(xyzn(x, y, z));
  if(it == c.end())
    return false;

  xyzn *p = (xyzn *) & (*it);
  for(unsigned int i = 0; i < p->n.size(); i++){
    if(fabs(p->angle(i, float2char(nx), float2char(ny), float2char(nz))) < tol) {
      nx = char2float(p->n[i].nx);
      ny = char2float(p->n[i].ny);
      nz = char2float(p->n[i].nz);
      break;
    }
  }
  return true;
}
