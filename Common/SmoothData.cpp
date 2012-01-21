// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdio.h>
#include "SmoothData.h"
#include "Numeric.h"

// Basic coordinate-based floting point value averager

double xyzv::eps = 1.e-12;

xyzv::xyzv(const xyzv &other)
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

xyzv &xyzv::operator = (const xyzv &other)
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
  if(!vals) {
    vals = new double[n];
    for(int i = 0; i < n; i++)
      vals[i] = 0.0;
    nbvals = n;
    nboccurences = 0;
  }
  else if(nbvals != n)
    return; // error
  double x1 = (double)(nboccurences) / (double)(nboccurences + 1);
  double x2 = 1. / (double)(nboccurences + 1);
  for(int i = 0; i < nbvals; i++)
    vals[i] = (x1 * vals[i] + x2 * v[i]);
  nboccurences++;
}

void smooth_data::add(double x, double y, double z, int n, double *vals)
{
  xyzv xyz(x, y, z);
  std::set<xyzv, lessthanxyzv>::const_iterator it = c.find(xyz);
  if(it == c.end()) {
    xyz.update(n, vals);
    c.insert(xyz);
  }
  else {
    // we can do this because we know that it will not destroy the set
    // ordering
    xyzv *p = (xyzv *) & (*it);
    p->update(n, vals);
  }
}

bool smooth_data::get(double x, double y, double z, int n, double *vals)
{
  std::set<xyzv, lessthanxyzv>::const_iterator it = c.find(xyzv(x, y, z));
  if(it == c.end())
    return false;
  for(int k = 0; k < n; k++)
    vals[k] = it->vals[k];
  return true;
}

void smooth_data::normalize()
{
  std::set<xyzv, lessthanxyzv>::iterator it = c.begin();
  while(it != c.end()){
    if(it->nbvals == 3) norme(it->vals);
    it++;
  }
}

bool smooth_data::exportview(std::string filename)
{
  FILE *fp = fopen(filename.c_str(), "w");
  if(!fp) return false;
  fprintf(fp, "View \"data\" {\n");
  std::set<xyzv, lessthanxyzv>::iterator it = c.begin();
  while(it != c.end()){
    switch(it->nbvals){
    case 1: 
      fprintf(fp, "SP(%.16g,%.16g,%.16g){%.16g};\n", 
              it->x, it->y, it->z, it->vals[0]);
      break;
    case 3:
      fprintf(fp, "VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",
              it->x, it->y, it->z, it->vals[0], it->vals[1], it->vals[2]);
      break;
    }
    it++;
  }
  fprintf(fp, "};\n");
  fclose(fp);
  return true;
}

// Normal smoother

float xyzn::eps = 1.e-6F;

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
  return (float)(angplan * 180. / M_PI);
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
        float c2 = 1.0F / (float)(n[i].nb + 1);
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
  xyzn xyz((float)x, (float)y, (float)z);
  std::set<xyzn, lessthanxyzn>::const_iterator it = c.find(xyz);
  if(it == c.end()) {
    xyz.update(float2char((float)nx), 
               float2char((float)ny),
               float2char((float)nz), tol);
    c.insert(xyz);
  }
  else {
    // we can do this because we know that it will not destroy the set
    // ordering
    xyzn *p = (xyzn *) & (*it);
    p->update(float2char((float)nx), 
              float2char((float)ny), 
              float2char((float)nz), tol);
  }    
}

bool smooth_normals::get(double x, double y, double z,
                         double &nx, double &ny, double &nz)
{
  std::set<xyzn, lessthanxyzn>::const_iterator it = 
    c.find(xyzn((float)x, (float)y, (float)z));

  if(it == c.end()) return false;

  xyzn *p = (xyzn *) & (*it);
  for(unsigned int i = 0; i < p->n.size(); i++){
    if(fabs(p->angle(i, float2char((float)nx), 
                     float2char((float)ny),
                     float2char((float)nz))) < tol) {
      nx = char2float(p->n[i].nx);
      ny = char2float(p->n[i].ny);
      nz = char2float(p->n[i].nz);
      break;
    }
  }
  return true;
}
