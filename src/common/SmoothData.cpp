// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include "SmoothData.h"
#include "Numeric.h"
#include "OS.h"

// Basic coordinate-based floting point value averager

double xyzv::eps = 1.e-12;

xyzv::xyzv(const xyzv &other)
{
  x = other.x;
  y = other.y;
  z = other.z;
  scaleValue = other.scaleValue; // Added by Trevor Strickler 07/10/2013
  scale_numvals = other.scale_numvals; // Added by Trevor Strickler 07/10/2013
  nbvals = other.nbvals;
  nboccurrences = other.nboccurrences;
  if(other.vals && other.nbvals) {
    vals = new double[other.nbvals];
    for(int i = 0; i < nbvals; i++) vals[i] = other.vals[i];
  }
  else
    vals = nullptr;
}

xyzv &xyzv::operator=(const xyzv &other)
{
  if(this != &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    scaleValue = other.scaleValue; // Added by Trevor Strickler 07/10/2013
    scale_numvals = other.scale_numvals; // Added by Trevor Strickler 07/10/2013
    nbvals = other.nbvals;
    nboccurrences = other.nboccurrences;
    if(other.vals && other.nbvals) {
      vals = new double[other.nbvals];
      for(int i = 0; i < nbvals; i++) vals[i] = other.vals[i];
    }
  }
  return *this;
}

void xyzv::update(int n, double *v)
{
  if(!vals) {
    vals = new double[n];
    for(int i = 0; i < n; i++) vals[i] = 0.0;
    nbvals = n;
    nboccurrences = 0;
  }
  else if(nbvals != n)
    return; // error
  double x1 = (double)(nboccurrences) / (double)(nboccurrences + 1);
  double x2 = 1. / (double)(nboccurrences + 1);
  for(int i = 0; i < nbvals; i++) vals[i] = (x1 * vals[i] + x2 * v[i]);
  nboccurrences++;
}

// Added by Trevor Strickler
void xyzv::scale_update(double scale_inp)
{
  if(std::abs(1.0 - scale_inp) <= eps) scale_inp = 1.0;
  if(scale_inp != 1.0 || scaleValue != 1.0) {
    double x1 = (double)(scale_numvals) / (double)(scale_numvals + 1);
    double x2 = 1.0 / (double)(scale_numvals + 1);
    scaleValue = (x1 * scaleValue + x2 * scale_inp);
  }
  if(std::abs(1.0 - scaleValue) <= eps) scaleValue = 1.0;
  scale_numvals++;
}

void smooth_data::add(double x, double y, double z, int n, double *vals)
{
  xyzv xyz(x, y, z);
  auto it = c.find(xyz);
  if(it == c.end()) {
    xyz.update(n, vals);
    c.insert(xyz);
  }
  else {
    // we can do this because we know that it will not destroy the set
    // ordering
    xyzv *p = (xyzv *)&(*it);
    p->update(n, vals);
  }
}

// added by Trevor Strickler
void smooth_data::add_scale(double x, double y, double z, double scale_val)
{
  xyzv xyz(x, y, z);
  auto it = c.find(xyz);
  if(it == c.end()) {
    xyz.scale_update(scale_val);
    c.insert(xyz);
  }
  else {
    // we can do this because we know that it will not destroy the set
    // ordering
    xyzv *p = (xyzv *)&(*it);
    p->scale_update(scale_val);
  }
}

bool smooth_data::get(double x, double y, double z, int n, double *vals) const
{
  auto it = c.find(xyzv(x, y, z));
  if(it == c.end()) return false;
  for(int k = 0; k < n; k++) vals[k] = it->vals[k];
  return true;
}

// added by Trevor Strickler
bool smooth_data::get_scale(double x, double y, double z, double *scale_val) const
{
  auto it = c.find(xyzv(x, y, z));
  if(it == c.end()) return false;
  (*scale_val) = it->scaleValue;
  return true;
}

void smooth_data::normalize()
{
  auto it = c.begin();
  while(it != c.end()) {
    if(it->nbvals == 3) norme(it->vals);
    it++;
  }
}

bool smooth_data::exportview(const std::string &filename) const
{
  FILE *fp = Fopen(filename.c_str(), "w");
  if(!fp) return false;
  fprintf(fp, "View \"data\" {\n");
  auto it = c.begin();
  while(it != c.end()) {
    switch(it->nbvals) {
    case 1:
      fprintf(fp, "SP(%.16g,%.16g,%.16g){%.16g};\n", it->x, it->y, it->z,
              it->vals[0]);
      break;
    case 3:
      fprintf(fp, "VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n", it->x, it->y,
              it->z, it->vals[0], it->vals[1], it->vals[2]);
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
  double a[3] = {char2float(n[i].nx), char2float(n[i].ny), char2float(n[i].nz)};
  double b[3] = {char2float(nx), char2float(ny), char2float(nz)};
  norme(a);
  norme(b);

  double c[3];
  prodve(a, b, c);

  double const cosc = prosca(a, b);
  double const sinc = std::sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
  double const angplan = myatan2(sinc, cosc);
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
  for(std::size_t i = 0; i < n.size(); i++) {
    if(tol >= 180. || std::abs(angle(i, nx, ny, nz)) < tol) {
      // just ignore it if we have more than 100 contributions to a
      // single point...
      if(n[i].nb < 100) {
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

void smooth_normals::add(double x, double y, double z, double nx, double ny,
                         double nz)
{
  xyzn xyz((float)x, (float)y, (float)z);
  auto it = c.find(xyz);
  if(it == c.end()) {
    xyz.update(float2char((float)nx), float2char((float)ny),
               float2char((float)nz), tol);
    c.insert(xyz);
  }
  else {
    // we can do this because we know that it will not destroy the set
    // ordering
    xyzn *p = (xyzn *)&(*it);
    p->update(float2char((float)nx), float2char((float)ny),
              float2char((float)nz), tol);
  }
}

bool smooth_normals::get(double x, double y, double z, double &nx, double &ny,
                         double &nz) const
{
  auto it =
    c.find(xyzn((float)x, (float)y, (float)z));

  if(it == c.end()) return false;

  xyzn *p = (xyzn *)&(*it);
  for(std::size_t i = 0; i < p->n.size(); i++) {
    if(std::abs(p->angle(i, float2char((float)nx), float2char((float)ny),
                         float2char((float)nz))) < tol) {
      nx = char2float(p->n[i].nx);
      ny = char2float(p->n[i].ny);
      nz = char2float(p->n[i].nz);
      break;
    }
  }
  return true;
}
