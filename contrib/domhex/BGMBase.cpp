// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "BGMBase.h"

#include <iostream>
#include "OS.h"
#include "GPoint.h"
#include "GFace.h"
#include "GmshDefines.h"
#include "MElementOctree.h"

void BGMBase::export_scalar(const std::string &filename,
                            const DoubleStorageType &_whatToPrint) const
{
  FILE *f = Fopen(filename.c_str(), "w");
  if(!f) {
    Msg::Error("Could not open file '%s'", filename.c_str());
    return;
  }

  fprintf(f, "View \"Background Mesh\"{\n");

  const MElement *elem;
  int nvertex;
  int type;

  for(unsigned int i = 0; i < getNumMeshElements(); i++) {
    elem = getElement(i);
    nvertex = elem->getNumVertices();
    type = elem->getType();
    const char *s = nullptr;
    switch(type) {
    case TYPE_PNT: s = "SP"; break;
    case TYPE_LIN: s = "SL"; break;
    case TYPE_TRI: s = "ST"; break;
    case TYPE_QUA: s = "SQ"; break;
    case TYPE_TET: s = "SS"; break;
    case TYPE_HEX: s = "SH"; break;
    case TYPE_PRI: s = "SI"; break;
    case TYPE_PYR: s = "SY"; break;
    default: throw;
    }

    fprintf(f, "%s(", s);
    const MVertex *v;
    std::vector<double> values(nvertex);
    for(int iv = 0; iv < nvertex; iv++) {
      v = elem->getVertex(iv);
      values[iv] = get_nodal_value(v, _whatToPrint);
      // GPoint p = gf->point(SPoint2(v->x(),v->y()));
      GPoint p = get_GPoint_from_MVertex(v);
      fprintf(f, "%g,%g,%g", p.x(), p.y(), p.z());
      if(iv != nvertex - 1)
        fprintf(f, ",");
      else
        fprintf(f, "){");
    }
    for(int iv = 0; iv < nvertex; iv++) {
      fprintf(f, "%g", values[iv]);
      if(iv != nvertex - 1)
        fprintf(f, ",");
      else
        fprintf(f, "};\n");
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}

void BGMBase::export_vector(const std::string &filename,
                            const VectorStorageType &_whatToPrint) const
{
  FILE *f = Fopen(filename.c_str(), "w");
  if(!f) {
    Msg::Error("Could not open file '%s'", filename.c_str());
    return;
  }

  fprintf(f, "View \"Background Mesh\"{\n");

  const MElement *elem;
  int nvertex;
  int type;

  for(unsigned int i = 0; i < getNumMeshElements(); i++) {
    elem = getElement(i);
    nvertex = elem->getNumVertices();
    type = elem->getType();
    const char *s = nullptr;
    switch(type) {
    case TYPE_PNT: s = "VP"; break;
    case TYPE_LIN: s = "VL"; break;
    case TYPE_TRI: s = "VT"; break;
    case TYPE_QUA: s = "VQ"; break;
    case TYPE_TET: s = "VS"; break;
    case TYPE_HEX: s = "VH"; break;
    case TYPE_PRI: s = "VI"; break;
    case TYPE_PYR: s = "VY"; break;
    default: throw;
    }

    fprintf(f, "%s(", s);
    const MVertex *v;
    std::vector<double> values(nvertex * 3);
    for(int iv = 0; iv < nvertex; iv++) {
      v = elem->getVertex(iv);
      std::vector<double> temp = get_nodal_value(v, _whatToPrint);
      for(int j = 0; j < 3; j++) values[iv * 3 + j] = temp[j];
      GPoint p = get_GPoint_from_MVertex(v);
      fprintf(f, "%g,%g,%g", p.x(), p.y(), p.z());
      if(iv != nvertex - 1)
        fprintf(f, ",");
      else
        fprintf(f, "){");
    }
    for(int iv = 0; iv < nvertex; iv++) {
      for(int j = 0; j < 3; j++) {
        fprintf(f, "%g", values[iv * 3 + j]);
        if(!((iv == nvertex - 1) && (j == 2)))
          fprintf(f, ",");
        else
          fprintf(f, "};\n");
      }
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}

void BGMBase::export_tensor_as_vectors(
  const std::string &filename, const TensorStorageType &_whatToPrint) const
{
  FILE *f = Fopen(filename.c_str(), "w");
  if(!f) {
    Msg::Error("Could not open file '%s'", filename.c_str());
    return;
  }

  fprintf(f, "View \"Background Mesh\"{\n");

  auto it = _whatToPrint.begin();
  const char *s = "VP";

  for(; it != _whatToPrint.end(); it++) { // for all vertices
    GPoint p = get_GPoint_from_MVertex(it->first);
    for(int i = 0; i < 3; i++) {
      fprintf(f, "%s(%g,%g,%g){%g,%g,%g};\n", s, p.x(), p.y(), p.z(),
              (it->second)(0, i), (it->second)(1, i), (it->second)(2, i));
      fprintf(f, "%s(%g,%g,%g){%g,%g,%g};\n", s, p.x(), p.y(), p.z(),
              -(it->second)(0, i), -(it->second)(1, i), -(it->second)(2, i));
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}

BGMBase::BGMBase(int dim, GEntity *_gf)
  : octree(nullptr), gf(_gf), DIM(dim), order(1)
{
}

BGMBase::~BGMBase() {}

bool BGMBase::inDomain(double u, double v, double w)
{
  return (findElement(u, v, w) != nullptr);
}

const MElement *BGMBase::findElement(double u, double v, double w, bool strict)
{
  return (getOctree()->find(u, v, w, DIM, strict));
}

std::vector<double> BGMBase::get_field_value(double u, double v, double w,
                                             const VectorStorageType &data)
{
  // TODO C++11 remove const_cast and enforce const-correctness otherwise
  MElement *e = const_cast<MElement *>(findElement(u, v, w));

  if(!e) return std::vector<double>(3, -1000.);

  std::vector<std::vector<double> > val = get_nodal_values(e, data);
  std::vector<double> element_uvw = get_element_uvw_from_xyz(e, u, v, w);

  std::vector<double> res(3);

  for(int j = 0; j < 3; j++) {
    std::vector<double> values(e->getNumVertices());

    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
      values[i] = val[i][j];
    }
    res[j] = e->interpolate(&values[0], element_uvw[0], element_uvw[1],
                            element_uvw[2], 1, order);
  }
  return res;
}

double BGMBase::get_field_value(double u, double v, double w,
                                const DoubleStorageType &data)
{
  // TODO C++11 Remove const_cast
  MElement *e = const_cast<MElement *>(findElement(u, v, w));
  if(!e) return -1000.;
  std::vector<double> val = get_nodal_values(e, data);
  std::vector<double> element_uvw = get_element_uvw_from_xyz(e, u, v, w);
  std::vector<double> values(e->getNumVertices());
  for(std::size_t i = 0; i < e->getNumVertices(); i++) values[i] = val[i];

  return e->interpolate(&values[0], element_uvw[0], element_uvw[1],
                        element_uvw[2], 1, order);
}

double BGMBase::size(double u, double v, double w)
{
  return get_field_value(u, v, w, sizeField);
}

double BGMBase::size(const MVertex *v) { return get_nodal_value(v, sizeField); }

std::vector<double>
BGMBase::get_nodal_value(const MVertex *v, const VectorStorageType &data) const
{
  auto itfind = data.find(v);
  if(itfind == data.end()) {
    Msg::Error("Unknown vertex %d in BGMBase::get_nodal_value", v->getNum());
    return std::vector<double>(3, 0.);
  }
  return itfind->second;
}

double BGMBase::get_nodal_value(const MVertex *v,
                                const DoubleStorageType &data) const
{
  auto itfind = data.find(v);
  if(itfind == data.end()) {
    Msg::Error("Unknown vertex %d in BGMBase::get_nodal_value", v->getNum());
    return 0.;
  }
  return itfind->second;
}

std::vector<std::vector<double> >
BGMBase::get_nodal_values(const MElement *e,
                          const VectorStorageType &data) const
{
  std::vector<std::vector<double> > res(e->getNumVertices());

  for(std::size_t i = 0; i < e->getNumVertices(); i++) {
    auto itfind = data.find(const_cast<MVertex *>(e->getVertex(i)));
    for(int j = 0; j < 3; j++) res[i].push_back((itfind->second)[j]);
  }
  return res;
}

std::vector<double>
BGMBase::get_nodal_values(const MElement *element,
                          const DoubleStorageType &data) const
{
  std::vector<double> res(element->getNumVertices(), 0.);

  for(std::size_t i = 0; i < element->getNumVertices(); i++)
    // res[i] = (data.find(const_cast<MVertex*>(e->getVertex(i))))->second;
    res[i] = data.find(element->getVertex(i))->second;
  return res;
}

std::vector<double> BGMBase::get_element_uvw_from_xyz(const MElement *e,
                                                      double x, double y,
                                                      double z) const
{
  std::vector<double> res(3);

  double xyz[3] = {x, y, z};
  e->xyz2uvw(xyz, &res[0]);

  return res;
}

std::set<MVertex *> BGMBase::get_vertices_of_maximum_dim(int dim)
{
  std::set<MVertex *> bnd_vertices;
  for(unsigned int i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *element = gf->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); j++) {
      MVertex *vertex = element->getVertex(j);
      if(vertex->onWhat()->dim() <= dim) bnd_vertices.insert(vertex);
    }
  }
  return bnd_vertices;
}

GEntity *BGMBase::getBackgroundGEntity() { return gf; }
