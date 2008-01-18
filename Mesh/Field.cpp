// $Id: Field.cpp,v 1.10 2008-01-18 20:41:33 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include <fstream>
#include <math.h>
#include <BDS.h>
#include "Gmsh.h"
#include "Field.h"
#include "Context.h"
#include "GeoInterpolation.h"
#include "BackgroundMesh.h"
#include "GModel.h"
#ifdef HAVE_MATH_EVAL
#include "matheval.h"
#endif

#define MAX_LC 1.e22

extern Context_T CTX;
FieldManager fields;

void FieldManager::reset()
{
  for(std::map<int,Field*>::iterator it = id_map.begin(); it != id_map.end(); it++){
    delete it->second;
  }
  id_map.clear();
}

Field *FieldManager::get(int id)
{
  std::map<int,Field*>::iterator it = id_map.find(id);
  if(it == id_map.end()){
    Msg(GERROR, "Field id %i does not exist", id);
    return NULL;
  }
  return it->second;
}

int FieldManager::insert(Field *field, int id)
{
  if(id == -1){ // get an automatic negative id starting from -1
    if(id_map.begin() != id_map.end()){
      id = id_map.begin()->first - 1;
    }
  }
  if(id > 0){
    if(id_map.find(id) != id_map.end()){
      Msg(GERROR, "Field id %i is already defined, it will be deleted");
      delete id_map[id];
    }
    id_map[id] = field;
  }
  return id;
}

// StructuredField
StructuredField::StructuredField(const char *filename)
{
  std::ifstream input(filename);
  input.read((char*)o, 3 * sizeof(double));
  input.read((char*)d, 3 * sizeof(double));
  input.read((char*)n, 3 * sizeof(int));
  int nt = n[0] * n[1] * n[2];
  data = new double[nt];
  input.read((char*)data, nt * sizeof(double));
  input.close();
}

StructuredField::~StructuredField()
{
  delete []data;
}

double StructuredField::operator()(double x,double y,double z)
{
  //tri-linear
  int id[2][3];
  double xi[3];
  double xyz[3]={x,y,z};
  for(int i = 0; i < 3; i++){
    id[0][i] = (int)floor((xyz[i] - o[i]) / d[i]);
    id[1][i] = id[0][i] + 1;
    id[0][i] = std::max(std::min(id[0][i], n[i] - 1), 0);
    id[1][i] = std::max(std::min(id[1][i], n[i] - 1), 0);
    xi[i] = xyz[i] - (o[i] + id[0][i] * d[i]);
    xi[i] = std::max(std::min(xi[i], 1.), 0.);
  }
  double v = 0;
  for(int i = 0; i < 2; i++) 
    for(int j = 0;j < 2; j++)
      for(int k = 0; k < 2; k++){
	v += data[id[i][0] * n[1] * n[2] + id[j][1] * n[2] + id[j][2]]
	  * (i * xi[0] + (1 - i) * (1 - xi[0]))
	  * (j * xi[1] + (1 - j) * (1 - xi[1]))
	  * (k * xi[2] + (1 - k) * (1 - xi[2]));
      }
  return v;
}

// LatLonField
double LatLonField::operator()(double x, double y, double z)
{
  return (*field)(asin(z / sqrt(x * x + y * y + z * z)), atan2(y, x), 0);
}

// ThresholdField
ThresholdField::ThresholdField(Field *_field,
			       double _dmin, double _dmax, double _lcmin, double _lcmax)
  : field(_field), dmin(_dmin), dmax(_dmax), lcmin(_lcmin), lcmax(_lcmax)
{
}

double ThresholdField::operator()(double x, double y, double z)
{
  double r = ((*field)(x, y, z) - dmin) / (dmax - dmin);
  r = std::max(std::min(r, 1.), 0.);
  double lc = lcmin * (1 - r) + lcmax * r;
  return lc;
}

//GradField
GradField::GradField(Field *_field, int _kind, double _delta)
  : field(_field), kind(_kind), delta(_delta)
{
  if(delta < 0) delta = CTX.lc / 10000;
}

double GradField::operator()(double x, double y, double z)
{
  double gx, gy, gz;
  switch(kind){
  case 0 : /* x */
    return ((*field)(x + delta / 2, y, z) - (*field)(x - delta / 2, y, z)) / delta;
  case 1 : /* y */
    return ((*field)(x, y + delta / 2, z) - (*field)(x, y - delta / 2, z)) / delta;
  case 2 : /* z */
    return ((*field)(x, y, z + delta / 2) - (*field)(x, y, z - delta / 2)) / delta;
  case 3 : /* max */
    gx = ((*field)(x + delta / 2, y, z) - (*field)(x - delta / 2, y, z)) / delta;
    gy = ((*field)(x, y + delta / 2, z) - (*field)(x, y - delta / 2, z)) / delta;
    gz = ((*field)(x, y, z + delta / 2) - (*field)(x, y, z - delta / 2)) / delta;
    return sqrt(gx * gx + gy * gy + gz * gz);
  default :
    Msg(GERROR, "Unknown kind (%i) for GradField", kind);
    return 0;
  }
}

// ParametricField
ParametricField::ParametricField(Field *_field, 
				 const char *strX, const char *strY, const char *strZ)
  : field(_field)
{
  char *sx = strdup(strX), *sy = strdup(strY), *sz = strdup(strZ);
#if !defined(HAVE_MATH_EVAL)
  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");
#else
  evalX = evaluator_create(sx);
  evalY = evaluator_create(sy);
  evalZ = evaluator_create(sz);
#endif
}

ParametricField::~ParametricField()
{
#if !defined(HAVE_MATH_EVAL)
  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");
#else
  evaluator_destroy(evalX);
  evaluator_destroy(evalY);
  evaluator_destroy(evalZ);
#endif
}

double ParametricField::operator()(double x, double y, double z)
{
#if !defined(HAVE_MATH_EVAL)
  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");
  return 0.;
#else
  static char *names[3] = {"x", "y", "z"};
  double values [3] = {x, y, z};
  const double nx = evaluator_evaluate(evalX, 3, names, values);
  const double ny = evaluator_evaluate(evalY, 3, names, values);
  const double nz = evaluator_evaluate(evalZ, 3, names, values);
  return (*field)(nx, ny, nz);
#endif
}

// FunctionField
FunctionField::FunctionField(std::list<Field*> *_list, const char *str)
  : list(_list)
{
#if !defined(HAVE_MATH_EVAL)
  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");
#else
  char *s = strdup(str);
  eval = evaluator_create(s);
  values = new double[3 + list->size()];
  names = new char*[3 + list->size()];
  names[0] = strdup("x");
  names[1] = strdup("y");
  names[2] = strdup("z");
  int p = 3;
  for(std::list<Field*>::iterator it = list->begin(); it != list->end(); it++){
    char tmp[256] ; 
    sprintf(tmp, "f%i", p - 3);
    names[p] = strdup(tmp);
    p++;
  }
#endif
}

double FunctionField::operator()(double x, double y, double z)
{
#if !defined(HAVE_MATH_EVAL)
  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");
  return 0.;
#else
  values[0] = x;
  values[1] = y;
  values[2] = z;
  int p = 3;
  for(std::list<Field*>::iterator it = list->begin(); it != list->end(); it++){
    values[p]=(**it)(x, y ,z);
    p++;
  }
  return evaluator_evaluate(eval, p, names, values);
#endif
}

FunctionField::~FunctionField()
{
#if !defined(HAVE_MATH_EVAL)
  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");
#else
  int n = 3 + list->size();
  for(int i = 0; i < n; i++){
    free(names[i]);
  }
  delete [] names;
  delete [] values;
  delete list;
  evaluator_destroy(eval);
#endif
}

// PostViewField
double PostViewField::operator()(double x, double y, double z) 
{
  // FIXME: should test unique view num instead, but that would be slower
  if(view_index < 0 || view_index >= (int)PView::list.size()) return MAX_LC;

  double l = 0.;
  if(!octree->searchScalar(x, y, z, &l, 0)){
    // uncomment the following to try really hard to find an element
    // around the point
    /*
    double fact[9] = {0.001, 0.0025, 0.005, 0.0075, 0.01, 0.025, 0.05, 0.075, 0.1};
    for(int i = 0; i < 9; i++){
      double eps = CTX.lc * fact[i];
      if(octree->searchScalar(x + eps, y, z, &l, 0)) break;
      if(octree->searchScalar(x - eps, y, z, &l, 0)) break;
      if(octree->searchScalar(x, y + eps, z, &l, 0)) break;
      if(octree->searchScalar(x, y - eps, z, &l, 0)) break;
      if(octree->searchScalar(x, y, z + eps, &l, 0)) break;
      if(octree->searchScalar(x, y, z - eps, &l, 0)) break;
      if(octree->searchScalar(x + eps, y - eps, z - eps, &l, 0)) break;
      if(octree->searchScalar(x + eps, y + eps, z - eps, &l, 0)) break;
      if(octree->searchScalar(x - eps, y - eps, z - eps, &l, 0)) break;
      if(octree->searchScalar(x - eps, y + eps, z - eps, &l, 0)) break;
      if(octree->searchScalar(x + eps, y - eps, z + eps, &l, 0)) break;
      if(octree->searchScalar(x + eps, y + eps, z + eps, &l, 0)) break;
      if(octree->searchScalar(x - eps, y - eps, z + eps, &l, 0)) break;
      if(octree->searchScalar(x - eps, y + eps, z + eps, &l, 0)) break;
    }
    */
  }
  if(l <= 0) return MAX_LC;
  return l;
}

PostViewField::PostViewField(PView *view)
{
  Msg(INFO, "Field from '%s'", view->getData()->getName().c_str());
  octree = new OctreePost(view);
  view_index = view->getIndex();
}

PostViewField::~PostViewField()
{
  delete octree;
}

// Min Field
double MinField::operator()(double x, double y, double z)
{
  if(size() == 0){
    Msg(GERROR, "Requesting minimum of a void list of field");
    return 0;
  }
  iterator it = begin();
  double v = (**it++)(x, y, z);
  while(it != end()){
    v = std::min(v, (**it++)(x, y, z));
  }
  return v;
}

// Attractor Field
#define maxpts  1
void AttractorField::addPoint(double X, double Y, double Z)
{
  attractorPoints.push_back(SPoint3(X, Y, Z));
}

AttractorField::~AttractorField()
{
#ifdef HAVE_ANN_
  if(kdtree) delete kdtree;
  if(zeronodes) annDeallocPts(zeronodes);
  delete [] index;
  delete [] dist;
#endif
}

AttractorField::AttractorField()
#ifdef HAVE_ANN_
  : kdtree (0), zeronodes(0)
#endif
{
#ifdef HAVE_ANN_
  index = new ANNidx[maxpts];
  dist = new ANNdist[maxpts];
#endif
}

void AttractorField::buildFastSearchStructures()
{
#ifdef HAVE_ANN_
  if(zeronodes){
    annDeallocPts(zeronodes);
    delete kdtree;
  }
  int totpoints = attractorPoints.size();
  if (totpoints)
    zeronodes = annAllocPts(totpoints, 4);
  int k = 0;
  for(std::list <SPoint3>::iterator it2 = attractorPoints.begin();
      it2 != attractorPoints.end(); ++it2){
    zeronodes[k][0]=it2->x();
    zeronodes[k][1]=it2->y();
    zeronodes[k++][2]=it2->z();
  }
  kdtree = new ANNkd_tree(zeronodes, totpoints, 3);
#endif
}

double AttractorField::operator()(double X, double Y, double Z)
{
  double xyz[3] = {X, Y, Z};
  if(attractorPoints.size() == 1){
    SPoint3 p = *(attractorPoints.begin());
    return sqrt((p.x() - X) * (p.x() - X) + 
		(p.y() - Y) * (p.y() - Y) + 
		(p.z() - Z) * (p.z() - Z));
  }
  else{
#ifdef HAVE_ANN_
    kdtree->annkSearch(xyz, maxpts, index, dist);
    return sqrt(dist[0]);
#else
    Msg(GERROR,"GMSH should be compiled with ANN in order to enable attractors");
    return 0.;
#endif
  }
}

void AttractorField::addCurve(Curve *c, int N) 
{
  for(int i = 0; i < N; i++){
    double u = (double)i / (N - 1);
    Vertex V = InterpolateCurve(c, u, 0);
    addPoint(V.Pos.X, V.Pos.Y, V.Pos.Z);
  }
}

void AttractorField::addGEdge(GEdge *c, int N) 
{
  for(int i = 0; i < N; i++){
    double u = (double)i / (N - 1);
    Range<double> b = c->parBounds(0);
    double t = b.low() + u * (b.high() - b.low());
    GPoint gp = c->point(t);
    addPoint(gp.x(), gp.y(), gp.z());
  }
}

void addMapLc (std::map<MVertex*, double> &maplc, MVertex *v, double l)
{
  std::map<MVertex*, double>::iterator it = maplc.find(v);
  if(it == maplc.end()) maplc[v] = l;
  else if(it->second > l) it->second = l;
}

AttractorField_1DMesh::AttractorField_1DMesh(GModel *m, double dmax, double dmin, 
					     double lcmax)
  : _dmax(dmax), _dmin(dmin), _lcmax(lcmax)
{
  GModel::eiter it = m->firstEdge();

  std::map<MVertex*, double> maplc;

  while(it != m->lastEdge()){
    MVertex *first = (*it)->getBeginVertex()->mesh_vertices[0];
    for(unsigned int i = 1; i <= (*it)->mesh_vertices.size(); ++i){
      MVertex *last = (i == (*it)->mesh_vertices.size()) ? 
	(*it)->getEndVertex()->mesh_vertices[0] : (*it)->mesh_vertices[i];
      double l = sqrt((first->x() - last->x()) * (first->x() - last->x()) +
		      (first->y() - last->y()) * (first->y() - last->y()) +
		      (first->z() - last->z()) * (first->z() - last->z()));
      addMapLc(maplc, first, l);
      addMapLc(maplc, last, l);
      first = last;
    }
  }      
  
  std::map<MVertex*, double>::iterator itm = maplc.begin();
  
  while(itm != maplc.end()){
    addPoint(itm->first->x(), itm->first->y(), itm->first->z());
    lcs.push_back(itm->second);
  }
}

AttractorField_1DMesh::AttractorField_1DMesh(GFace *gf, double dmax, double dmin, 
					     double lcmax)
  : _dmax(dmax), _dmin(dmin), _lcmax(lcmax)
{
  std::list<GEdge*> edges = gf->edges(); 
  std::list<GEdge*>::iterator it = edges.begin();

  std::map<MVertex*, double> maplc;
  std::map<MVertex*, double> maplc2;

  while(it != edges.end()){
    MVertex *first = (*it)->getBeginVertex()->mesh_vertices[0];
    for(unsigned int i = 1; i <= (*it)->mesh_vertices.size(); ++i){
      MVertex *last = (i == (*it)->mesh_vertices.size()) ? 
	(*it)->getEndVertex()->mesh_vertices[0] : (*it)->mesh_vertices[i];
      double l = sqrt((first->x() - last->x()) * (first->x() - last->x()) +
		      (first->y() - last->y()) * (first->y() - last->y()) +
		      (first->z() - last->z()) * (first->z() - last->z()));
      double t;
      last->getParameter(0,t);
      double l2 = LC_MVertex_PNTS(last->onWhat(),t,0);
      addMapLc(maplc, first, l);
      addMapLc(maplc, last, l);
      addMapLc(maplc2, first, l2);
      addMapLc(maplc2, last, l2);
      first = last;      
    }
    ++it;
  }      
  
  std::map<MVertex*, double>::iterator itm = maplc.begin();  
  while(itm != maplc.end()){
    addPoint(itm->first->x(), itm->first->y(), itm->first->z());
    lcs.push_back(itm->second);
    ++itm;
  }
  itm = maplc2.begin();  
  while(itm != maplc2.end()){
    lcs2.push_back(itm->second);
    ++itm;
  }
}


double AttractorField_1DMesh::operator()(double X, double Y, double Z)
{
#ifdef HAVE_ANN_
  double xyz[3] = {X, Y, Z};
  kdtree->annkSearch(xyz, maxpts, index, dist);
  double d = sqrt(dist[0]);
  double lcmin = lcs[index[0]];
  double r = (d - _dmin) / (_dmax - _dmin);
  r = std::max(std::min(r, 1.), 0.);
  double lc = lcmin * (1 - r) + _lcmax * r;
  return lc;
#else
  Msg(GERROR,"GMSH should be compiled with ANN in order to enable attractors");
  return 1.e22;
#endif
}

void AttractorField_1DMesh::eval(double X, double Y, double Z, double &lcmin, double &lcpt, double &d)
{
#ifdef HAVE_ANN_
  double xyz[3] = {X, Y, Z};
  kdtree->annkSearch(xyz, maxpts, index, dist);
  d = sqrt(dist[0]);
  lcmin = lcs[index[0]];
  lcpt  = lcs2[index[0]] * CTX.mesh.lc_factor;
#else
  Msg(GERROR,"GMSH should be compiled with ANN in order to enable attractors");
#endif
}
