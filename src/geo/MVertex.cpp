// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <cmath>
#include "MVertex.h"
#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GmshMessage.h"
#include "StringUtils.h"

double angle3Vertices(const MVertex *p1, const MVertex *p2, const MVertex *p3)
{
  SVector3 a(p1->x() - p2->x(), p1->y() - p2->y(), p1->z() - p2->z());
  SVector3 b(p3->x() - p2->x(), p3->y() - p2->y(), p3->z() - p2->z());
  SVector3 c = crossprod(a, b);
  double sinA = c.norm();
  double cosA = dot(a, b);
  return std::atan2(sinA, cosA);
}

MVertex::MVertex(double x, double y, double z, GEntity *ge, std::size_t num)
  : _visible(1), _order(1), _x(x), _y(y), _z(z), _ge(ge)
{
  // we should make GModel a mandatory argument to the constructor
  GModel *m = GModel::current();
  if(num) {
    _num = num;
    m->setMaxVertexNumber(_num);
  }
  else {
    _num = m->incrementAndGetMaxVertexNumber();
  }
  _index = (long int)num;
}

void MVertex::deleteLast()
{
  GModel *m = GModel::current();
  if(_num == m->getMaxVertexNumber()) m->decrementMaxVertexNumber();
  delete this;
}

void MVertex::forceNum(std::size_t num)
{
  GModel *m = GModel::current();
  _num = num;
  m->setMaxVertexNumber(_num);
}

void MVertex::writeMSH(FILE *fp, bool binary, bool saveParametric,
                       double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  if(!binary) {
    fprintf(fp, "%ld %.16g %.16g %.16g ", _index, x() * scalingFactor,
            y() * scalingFactor, z() * scalingFactor);
  }
  else {
    int i = (int)_index;
    fwrite(&i, sizeof(int), 1, fp);
    double data[3] = {x() * scalingFactor, y() * scalingFactor,
                      z() * scalingFactor};
    fwrite(data, sizeof(double), 3, fp);
  }

  int zero = 0;
  if(!onWhat() || !saveParametric) {
    if(!binary)
      fprintf(fp, "0\n");
    else
      fwrite(&zero, sizeof(int), 1, fp);
  }
  else {
    int entity = onWhat()->tag();
    int dim = onWhat()->dim();
    if(!binary)
      fprintf(fp, "%d %d ", entity, dim);
    else {
      fwrite(&entity, sizeof(int), 1, fp);
      fwrite(&dim, sizeof(int), 1, fp);
    }
    switch(dim) {
    case 0:
      if(!binary) fprintf(fp, "\n");
      break;
    case 1: {
      double _u;
      getParameter(0, _u);
      if(!binary)
        fprintf(fp, "%.16g\n", _u);
      else
        fwrite(&_u, sizeof(double), 1, fp);
    } break;
    case 2: {
      double _u, _v;
      getParameter(0, _u);
      getParameter(1, _v);
      if(!binary)
        fprintf(fp, "%.16g %.16g\n", _u, _v);
      else {
        fwrite(&_u, sizeof(double), 1, fp);
        fwrite(&_v, sizeof(double), 1, fp);
      }
    } break;
    default:
      if(!binary)
        fprintf(fp, "0 0 0\n");
      else {
        fwrite(&zero, sizeof(int), 1, fp);
        fwrite(&zero, sizeof(int), 1, fp);
        fwrite(&zero, sizeof(int), 1, fp);
      }
      break;
    }
  }
}

void MVertex::writeMSH2(FILE *fp, bool binary, bool saveParametric,
                        double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  int myDim = 0, myTag = 0;
  if(saveParametric) {
    if(onWhat()) {
      myDim = onWhat()->dim();
      myTag = onWhat()->tag();
    }
    else
      saveParametric = false;
  }

  if(!binary) {
    if(!saveParametric)
      fprintf(fp, "%ld %.16g %.16g %.16g\n", _index, x() * scalingFactor,
              y() * scalingFactor, z() * scalingFactor);
    else
      fprintf(fp, "%ld %.16g %.16g %.16g %d %d", _index, x() * scalingFactor,
              y() * scalingFactor, z() * scalingFactor, myDim, myTag);
  }
  else {
    int i = (int)_index;
    fwrite(&i, sizeof(int), 1, fp);
    double data[3] = {x() * scalingFactor, y() * scalingFactor,
                      z() * scalingFactor};
    fwrite(data, sizeof(double), 3, fp);
    if(saveParametric) {
      fwrite(&myDim, sizeof(int), 1, fp);
      fwrite(&myTag, sizeof(int), 1, fp);
    }
  }

  if(saveParametric) {
    if(myDim == 1) {
      double _u;
      getParameter(0, _u);
      if(!binary)
        fprintf(fp, " %.16g\n", _u);
      else
        fwrite(&_u, sizeof(double), 1, fp);
    }
    else if(myDim == 2) {
      double _u, _v;
      getParameter(0, _u);
      getParameter(1, _v);
      if(!binary)
        fprintf(fp, " %.16g %.16g\n", _u, _v);
      else {
        fwrite(&_u, sizeof(double), 1, fp);
        fwrite(&_v, sizeof(double), 1, fp);
      }
    }
    else if(!binary)
      fprintf(fp, "\n");
  }
}

void MVertex::writePLY2(FILE *fp)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, "%.16g %.16g %.16g\n", x(), y(), z());
}

void MVertex::writeVRML(FILE *fp, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, "%.16g %.16g %.16g,\n", x() * scalingFactor, y() * scalingFactor,
          z() * scalingFactor);
}

void MVertex::writeUNV(FILE *fp, bool officialExponentFormat,
                       double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  int coord_sys = 1;
  int displacement_coord_sys = 1;
  int color = 11;
  fprintf(fp, "%10ld%10d%10d%10d\n", _index, coord_sys, displacement_coord_sys,
          color);

  if(officialExponentFormat) {
    // hack to print the numbers with "D+XX" exponents
    char tmp[128];
    sprintf(tmp, "%25.16E%25.16E%25.16E\n", x() * scalingFactor,
            y() * scalingFactor, z() * scalingFactor);
    for(std::size_t i = 0; i < strlen(tmp); i++)
      if(tmp[i] == 'E') tmp[i] = 'D';
    fprintf(fp, "%s", tmp);
  }
  else {
    fprintf(fp, "%25.16E%25.16E%25.16E\n", x() * scalingFactor,
            y() * scalingFactor, z() * scalingFactor);
  }
}

void MVertex::writeVTK(FILE *fp, bool binary, double scalingFactor,
                       bool bigEndian)
{
  if(_index < 0) return; // negative index vertices are never saved

  if(binary) {
    double data[3] = {x() * scalingFactor, y() * scalingFactor,
                      z() * scalingFactor};
    // VTK always expects big endian binary data
    if(!bigEndian) SwapBytes((char *)data, sizeof(double), 3);
    fwrite(data, sizeof(double), 3, fp);
  }
  else {
    fprintf(fp, "%.16g %.16g %.16g\n", x() * scalingFactor, y() * scalingFactor,
            z() * scalingFactor);
  }
}

void MVertex::writeMATLAB(FILE *fp, int filetype, bool binary,
                          double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved
  if(binary) {
    Msg::Warning("Binary format not available for Matlab, saving in ASCII");
    binary = false;
  }
  fprintf(fp, "%.16g %.16g %.16g;\n", x() * scalingFactor, y() * scalingFactor,
          z() * scalingFactor);
}

void MVertex::writeTOCHNOG(FILE *fp, int dim, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved
  if(dim == 2) {
    fprintf(fp, "node %ld %.16g %.16g\n", _index, x() * scalingFactor,
            y() * scalingFactor);
  }
  else if(dim == 3) {
    fprintf(fp, "node %ld %.16g %.16g %.16g\n", _index, x() * scalingFactor,
            y() * scalingFactor, z() * scalingFactor);
  }
  else if(dim == 1) {
    fprintf(fp, "node %ld %.16g\n", _index, x() * scalingFactor);
  }
  else {
    fprintf(fp, "ERROR -- unsupported dimension: %d\n", dim);
  }
}

void MVertex::writeMESH(FILE *fp, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, " %20.14G      %20.14G      %20.14G      %d\n",
          x() * scalingFactor, y() * scalingFactor, z() * scalingFactor,
          _ge ? _ge->tag() : 0);
}

void MVertex::writeOFF(FILE *fp, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, "%g %g %g\n", x() * scalingFactor, y() * scalingFactor,
          z() * scalingFactor);
}

void MVertex::writeNEU(FILE *fp, int dim, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  switch(dim) {
  case 3:
    fprintf(fp, "%10ld%20.11e%20.11e%20.11e\n", _index, x() * scalingFactor,
            y() * scalingFactor, z() * scalingFactor);
    break;
  case 2:
    fprintf(fp, "%10ld%20.11e%20.11e\n", _index, x() * scalingFactor,
            y() * scalingFactor);
    break;
  case 1: fprintf(fp, "%10ld%20.11e\n", _index, x() * scalingFactor); break;
  }
}

static void double_to_char8(double val, char *str)
{
  if(val >= 1.e6)
    sprintf(str, "%.2E", val);
  else if(val >= 1.e-3)
    sprintf(str, "%f", val);
  else if(val >= 0)
    sprintf(str, "%.2E", val);
  else if(val >= -1.e-3)
    sprintf(str, "%.1E", val);
  else if(val >= -1.e6)
    sprintf(str, "%f", val);
  else
    sprintf(str, "%.1E", val);

#if defined(WIN32)
  // Windows uses 3 digits in the exponent (which apparently does not
  // conform with ANSI C): remove the extra 0
  if(strlen(str) == 9 && (str[4] == 'E' || str[5] == 'E')) {
    str[6] = str[7];
    str[7] = str[8];
  }
#endif

  str[8] = '\0';
}

void MVertex::writeBDF(FILE *fp, int format, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  char xs[17], ys[17], zs[17];
  double x1 = x() * scalingFactor;
  double y1 = y() * scalingFactor;
  double z1 = z() * scalingFactor;
  if(format == 0) {
    // free field format (max 8 char per field, comma separated, 10 per line)
    double_to_char8(x1, xs);
    double_to_char8(y1, ys);
    double_to_char8(z1, zs);
    fprintf(fp, "GRID,%ld,%d,%s,%s,%s\n", _index, 0, xs, ys, zs);
  }
  else if(format == 1) {
    // small field format (8 char par field, 10 per line)
    double_to_char8(x1, xs);
    double_to_char8(y1, ys);
    double_to_char8(z1, zs);
    fprintf(fp, "GRID    %-8ld%-8d%-8s%-8s%-8s\n", _index, 0, xs, ys, zs);
  }
  else {
    // large field format (8 char first/last field, 16 char middle, 6 per line)
    fprintf(fp, "GRID*   %-16ld%-16d%-16.9G%-16.9G\n", _index, 0, x1, y1);
    fprintf(fp, "*       %-16.9G\n", z1);
  }
}

void MVertex::writeINP(FILE *fp, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, "%ld, %.14g, %.14g, %.14g\n", _index, x() * scalingFactor,
          y() * scalingFactor, z() * scalingFactor);
}

void MVertex::writeKEY(FILE *fp, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, "%ld, %.12g, %.12g, %.12g\n", _index, x() * scalingFactor,
          y() * scalingFactor, z() * scalingFactor);
}

void MVertex::writeRAD(FILE *fp, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, "%10ld%20g%20g%20g\n", _index, x() * scalingFactor,
          y() * scalingFactor, z() * scalingFactor);
}

void MVertex::writeDIFF(FILE *fp, bool binary, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, " %ld ( %25.16E , %25.16E , %25.16E )", _index,
          x() * scalingFactor, y() * scalingFactor, z() * scalingFactor);
}

void MVertex::writeSU2(FILE *fp, int dim, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  if(dim == 2)
    fprintf(fp, "%.16g %.16g %ld\n", x() * scalingFactor, y() * scalingFactor,
            _index - 1);
  else
    fprintf(fp, "%.16g %.16g %.16g %ld\n", x() * scalingFactor,
            y() * scalingFactor, z() * scalingFactor, _index - 1);
}

double MVertexPtrLessThanLexicographic::tolerance = 1.e-6;

double MVertexPtrLessThanLexicographic::getTolerance() { return tolerance; }

bool MVertexPtrLessThanLexicographic::operator()(const MVertex *v1,
                                                 const MVertex *v2) const
{
  // you should not use this unless you know what you are doing; to create
  // unique vertices, use MVertexRTree
  if(v1->x() - v2->x() > tolerance) return true;
  if(v1->x() - v2->x() < -tolerance) return false;
  if(v1->y() - v2->y() > tolerance) return true;
  if(v1->y() - v2->y() < -tolerance) return false;
  if(v1->z() - v2->z() > tolerance) return true;
  return false;
}

static void getAllParameters(MVertex *v, GFace *gf,
                             std::vector<SPoint2> &params)
{
  params.clear();

  if(gf->geomType() == GEntity::DiscreteSurface) {
    params.push_back(gf->parFromPoint(SPoint3(v->x(), v->y(), v->z())));
    return;
  }

  if(v->onWhat()->dim() == 0) {
    GVertex *gv = (GVertex *)v->onWhat();
    std::vector<GEdge *> const &ed = gv->edges();
    bool seam = false;
    for(auto it = ed.begin(); it != ed.end(); it++) {
      if((*it)->isSeam(gf)) {
        Range<double> range = (*it)->parBounds(0);
        if(gv == (*it)->getBeginVertex()) {
          params.push_back((*it)->reparamOnFace(gf, range.low(), -1));
          params.push_back((*it)->reparamOnFace(gf, range.low(), 1));
        }
        if(gv == (*it)->getEndVertex()) {
          params.push_back((*it)->reparamOnFace(gf, range.high(), -1));
          params.push_back((*it)->reparamOnFace(gf, range.high(), 1));
        }
        if(gv != (*it)->getBeginVertex() && gv != (*it)->getEndVertex()) {
          Msg::Warning("Strange!");
        }
        seam = true;
      }
    }
    if(!seam) params.push_back(gv->reparamOnFace(gf, 1));
  }
  else if(v->onWhat()->dim() == 1) {
    GEdge *ge = (GEdge *)v->onWhat();
    if(!ge->haveParametrization()) return;
    double UU;
    v->getParameter(0, UU);
    if(UU == 0.0) UU = ge->parFromPoint(v->point());
    params.push_back(ge->reparamOnFace(gf, UU, 1));
    if(ge->isSeam(gf)) params.push_back(ge->reparamOnFace(gf, UU, -1));
  }
  else {
    double UU, VV;
    if(v->onWhat() == gf && v->getParameter(0, UU) && v->getParameter(1, VV))
      params.push_back(SPoint2(UU, VV));
  }
}

bool reparamMeshEdgeOnFace(MVertex *v1, MVertex *v2, GFace *gf, SPoint2 &param1,
                           SPoint2 &param2)
{
  std::vector<SPoint2> p1, p2;
  getAllParameters(v1, gf, p1);
  getAllParameters(v2, gf, p2);
  if(p1.size() == 1 && p2.size() == 1) {
    param1 = p1[0];
    param2 = p2[0];
  }
  else if(p1.size() >= 1 && p2.size() >= 1) {
    int imin = 0;
    int jmin = 0;
    {
      double d = (p2[0].x() - p1[0].x()) * (p2[0].x() - p1[0].x()) +
                 (p2[0].y() - p1[0].y()) * (p2[0].y() - p1[0].y());
      for(std::size_t i = 0; i < p2.size(); i++) {
        double d1 = (p2[i].x() - p1[0].x()) * (p2[i].x() - p1[0].x()) +
                    (p2[i].y() - p1[0].y()) * (p2[i].y() - p1[0].y());
        if(d1 < d) {
          imin = i;
          d = d1;
        }
      }
    }
    {
      double d = (p2[0].x() - p1[0].x()) * (p2[0].x() - p1[0].x()) +
                 (p2[0].y() - p1[0].y()) * (p2[0].y() - p1[0].y());
      for(std::size_t i = 0; i < p1.size(); i++) {
        double d1 = (p2[0].x() - p1[i].x()) * (p2[0].x() - p1[i].x()) +
                    (p2[0].y() - p1[i].y()) * (p2[0].y() - p1[i].y());
        if(d1 < d) {
          jmin = i;
          d = d1;
        }
      }
    }
    param1 = p1[jmin];
    param2 = p2[imin];
  }
  else {
    // brute force!
    param1 = gf->parFromPoint(SPoint3(v1->x(), v1->y(), v1->z()));
    param2 = gf->parFromPoint(SPoint3(v2->x(), v2->y(), v2->z()));
  }
  return true;
}

bool reparamMeshVertexOnFace(MVertex const *v, const GFace *gf, SPoint2 &param,
                             bool onSurface, bool failOnSeam, int dir)
{
  if(!v->onWhat()) {
    Msg::Error("Mesh node %d is not classified: cannot reparametrize",
               v->getNum());
    return false;
  }

  if(v->onWhat()->geomType() == GEntity::DiscreteCurve ||
     v->onWhat()->geomType() == GEntity::BoundaryLayerCurve) {
    param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()), onSurface);
    return true;
  }

  if(v->onWhat()->dim() == 0) {
    if(gf->geomType() == GEntity::DiscreteSurface) {
      param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()));
      return true;
    }

    GVertex *gv = (GVertex *)v->onWhat();
    // hack for bug in periodic curves
    if(gv->getNativeType() == GEntity::GmshModel &&
       gf->geomType() == GEntity::Plane)
      param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()), onSurface);
    else
      param = gv->reparamOnFace(gf, dir);
    if(failOnSeam) {
      // shout, we could be on a seam
      std::vector<GEdge *> const &ed = gv->edges();
      for(auto it = ed.begin(); it != ed.end(); it++)
        if((*it)->isSeam(gf)) return false;
    }
  }
  else if(v->onWhat()->dim() == 1) {
    if(gf->geomType() == GEntity::DiscreteSurface) {
      param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()));
      return true;
    }

    GEdge *ge = (GEdge *)v->onWhat();
    double t;
    v->getParameter(0, t);
    param = ge->reparamOnFace(gf, t, dir);
    if(!v->getParameter(0, t)) {
      Msg::Warning("No parametric coordinate on node %d classified on curve %d",
                   v->getNum(), ge->tag());
      return false;
      // param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()), onSurface);
    }

    if(failOnSeam) {
      // shout, we are on a seam
      if(ge->isSeam(gf)) return false;
    }
  }
  else {
    double uu, vv;
    if(v->onWhat() == gf && v->getParameter(0, uu) && v->getParameter(1, vv)) {
      param = SPoint2(uu, vv);
    }
    else {
      // brute force!
      param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()), onSurface);
    }
  }
  return true;
}

bool reparamMeshVertexOnEdge(MVertex *v, const GEdge *ge, double &param)
{
  param = 1.e6;
  Range<double> bounds = ge->parBounds(0);
  bool ok = true;
  if(ge->getBeginVertex() && ge->getBeginVertex()->mesh_vertices[0] == v)
    param = bounds.low();
  else if(ge->getEndVertex() && ge->getEndVertex()->mesh_vertices[0] == v)
    param = bounds.high();
  else
    ok = v->getParameter(0, param);

  if(!ok || param == 1.e6)
    param = ge->parFromPoint(SPoint3(v->x(), v->y(), v->z()));

  if(param < 1.e6) return true;
  return false;
}
