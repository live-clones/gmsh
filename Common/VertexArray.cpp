// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <algorithm>
#include "GmshMessage.h"
#include "VertexArray.h"
#include "Context.h"
#include "Numeric.h"

template<int N> float ElementDataLessThan<N>::tolerance = 0.0F;
float BarycenterLessThan::tolerance = 0.0F;

VertexArray::VertexArray(int numVerticesPerElement, int numElements) 
  : _numVerticesPerElement(numVerticesPerElement)
{
  int nb = (numElements ? numElements : 1) * _numVerticesPerElement;
  _vertices.reserve(nb * 3);
  _normals.reserve(nb * 3);
  _colors.reserve(nb * 4);
}

void VertexArray::_addVertex(float x, float y, float z)
{
  _vertices.push_back(x);
  _vertices.push_back(y);
  _vertices.push_back(z);
}

void VertexArray::_addNormal(float nx, float ny, float nz)
{
  // storing the normals as bytes hurts rendering performance, but it
  // significantly reduces the memory footprint
  char cx = float2char(nx);
  char cy = float2char(ny);
  char cz = float2char(nz);
  _normals.push_back(cx);
  _normals.push_back(cy);
  _normals.push_back(cz);
}

void VertexArray::_addColor(unsigned char r, unsigned char g, unsigned char b,
                            unsigned char a)
{
  _colors.push_back(r);
  _colors.push_back(g);
  _colors.push_back(b);
  _colors.push_back(a);
}

void VertexArray::_addElement(MElement *ele)
{
  if(ele && CTX::instance()->pickElements) _elements.push_back(ele);
}

void VertexArray::add(double *x, double *y, double *z, SVector3 *n, 
                      unsigned int *col, MElement *ele, bool unique, bool boundary)
{
  if(col){
    unsigned char r[100], g[100], b[100], a[100];
    int npe = getNumVerticesPerElement();
    for(int i = 0; i < npe; i++){
      r[i] = CTX::instance()->unpackRed(col[i]);
      g[i] = CTX::instance()->unpackGreen(col[i]);
      b[i] = CTX::instance()->unpackBlue(col[i]);
      a[i] = CTX::instance()->unpackAlpha(col[i]);
    }
    add(x, y, z, n, r, g, b, a, ele, unique, boundary);
  }
  else
    add(x, y, z, n, 0, 0, 0, 0, ele, unique, boundary);
}

void VertexArray::add(double *x, double *y, double *z, SVector3 *n, unsigned char *r, 
                      unsigned char *g, unsigned char *b, unsigned char *a, 
                      MElement *ele, bool unique, bool boundary)
{
  int npe = getNumVerticesPerElement();

  if(boundary && npe == 3){
    ElementData<3> e(x, y, z, n, r, g, b, a, ele);
    ElementDataLessThan<3>::tolerance = (float)(CTX::instance()->lc * 1.e-12);
    std::set<ElementData<3>, ElementDataLessThan<3> >::iterator it = _data3.find(e);
    if(it == _data3.end())
      _data3.insert(e);
    else
      _data3.erase(it);
    return;
  }

  if(unique){
    Barycenter pc(0.0F, 0.0F, 0.0F);
    for(int i = 0; i < npe; i++)
      pc += Barycenter(x[i], y[i], z[i]);
    BarycenterLessThan::tolerance = (float)(CTX::instance()->lc * 1.e-12);
    if(_barycenters.find(pc) != _barycenters.end()) 
      return;
    _barycenters.insert(pc);
  }

  for(int i = 0; i < npe; i++){
    _addVertex((float)x[i], (float)y[i], (float)z[i]);
    if(n) _addNormal((float)n[i].x(), (float)n[i].y(), (float)n[i].z());
    if(r && g && b && a) _addColor(r[i], g[i], b[i], a[i]);
    _addElement(ele);
  }
}

void VertexArray::finalize()
{
  if(_data3.size()){
    std::set<ElementData<3>, ElementDataLessThan<3> >::iterator it = _data3.begin();
    for(; it != _data3.end(); it++){
      for(int i = 0; i < 3; i++){
        _addVertex(it->x(i), it->y(i), it->z(i));
        _addNormal(it->nx(i), it->ny(i), it->nz(i));
        _addColor(it->r(i), it->g(i), it->b(i), it->a(i));
        _addElement(it->ele());
      }
    }
    _data3.clear();
  }
  _barycenters.clear();
  //printf("vert array : %d Mb\n", getMemoryUsage());
}

class AlphaElement {
 public:
  AlphaElement(float *vp, char *np, unsigned char *cp) : v(vp), n(np), c(cp) {}
  float *v;
  char *n;
  unsigned char *c;
};

class AlphaElementLessThan {
 public:
  static int numVertices;
  static double eye[3];
  bool operator()(const AlphaElement &e1, const AlphaElement &e2) const
  {
    double cg1[3] = { 0., 0., 0. }, cg2[3] = { 0., 0., 0.};
    for(int i = 0; i < numVertices; i++) {
      cg1[0] += e1.v[3 * i];
      cg1[1] += e1.v[3 * i + 1];
      cg1[2] += e1.v[3 * i + 2];
      cg2[0] += e2.v[3 * i];
      cg2[1] += e2.v[3 * i + 1];
      cg2[2] += e2.v[3 * i + 2];
    }
    double d1, d2;
    prosca(eye, cg1, &d1);
    prosca(eye, cg2, &d2);
    if(d1 < d2)
      return true;
    return false;
  }
};

int AlphaElementLessThan::numVertices = 0;
double AlphaElementLessThan::eye[3] = {0., 0., 0.};

void VertexArray::sort(double x, double y, double z)
{
  // This simplementation is pretty bad: it copies the whole data
  // twice. We should think about a more efficient way to sort the
  // three arrays in place.

  int npe = getNumVerticesPerElement();
  int n = getNumVertices() / npe;

  AlphaElementLessThan::numVertices = npe;
  AlphaElementLessThan::eye[0] = x;
  AlphaElementLessThan::eye[1] = y;
  AlphaElementLessThan::eye[2] = z;

  std::vector<AlphaElement> elements;
  elements.reserve(n);
  for(int i = 0; i < n; i++){
    float *vp = &_vertices[3 * npe * i];
    char *np = _normals.empty() ? 0 : &_normals[3 * npe * i];
    unsigned char *cp = _colors.empty() ? 0 : &_colors[4 * npe * i];
    elements.push_back(AlphaElement(vp, np, cp));
  }  
  std::sort(elements.begin(), elements.end(), AlphaElementLessThan());

  std::vector<float> sortedVertices;
  std::vector<char> sortedNormals;
  std::vector<unsigned char> sortedColors;
  sortedVertices.reserve(_vertices.size());
  sortedNormals.reserve(_normals.size());
  sortedColors.reserve(_colors.size());

  for(int i = 0; i < n; i++){
    for(int j = 0; j < npe; j++){
      for(int k = 0; k < 3; k++)
        sortedVertices.push_back(elements[i].v[3 * j + k]);
      if(elements[i].n)
        for(int k = 0; k < 3; k++)
          sortedNormals.push_back(elements[i].n[3 * j + k]);
      if(elements[i].c)
        for(int k = 0; k < 4; k++)
          sortedColors.push_back(elements[i].c[4 * j + k]);
    }
  }
  
  _vertices = sortedVertices;
  _normals = sortedNormals;
  _colors = sortedColors;
}

int VertexArray::getMemoryUsage()
{
  int bytes = _vertices.size() * sizeof(float) + _normals.size() * sizeof(char) +
    _colors.size() * sizeof(unsigned char);
  return bytes / 1024 / 1024;
}

char *VertexArray::toChar(int num, std::string name, int type, double min, double max, 
                          int numsteps, double time, SBoundingBox3d bbox, int &len)
{
  int vn = _vertices.size(), nn = _normals.size(), cn = _colors.size();
  int vs = vn * sizeof(float), ns = nn * sizeof(char), cs = cn * sizeof(unsigned char);
  int is = sizeof(int), ds = sizeof(double);
  int ss = name.size();
  double xmin = bbox.min().x(), ymin = bbox.min().y(), zmin = bbox.min().z();
  double xmax = bbox.max().x(), ymax = bbox.max().y(), zmax = bbox.max().z();

  len = ss + 7 * is + 9 * ds + vs + ns + cs;
  char *bytes = new char[len];
  int index = 0;
  memcpy(&bytes[index], &num, is); index += is;
  memcpy(&bytes[index], &ss, is); index += is;
  memcpy(&bytes[index], name.c_str(), ss); index += ss;
  memcpy(&bytes[index], &type, is); index += is;
  memcpy(&bytes[index], &min, ds); index += ds;
  memcpy(&bytes[index], &max, ds); index += ds;
  memcpy(&bytes[index], &numsteps, is); index += is;
  memcpy(&bytes[index], &time, ds); index += ds;
  memcpy(&bytes[index], &xmin, ds); index += ds;
  memcpy(&bytes[index], &ymin, ds); index += ds;
  memcpy(&bytes[index], &zmin, ds); index += ds;
  memcpy(&bytes[index], &xmax, ds); index += ds;
  memcpy(&bytes[index], &ymax, ds); index += ds;
  memcpy(&bytes[index], &zmax, ds); index += ds;
  memcpy(&bytes[index], &vn, is); index += is;
  if(vs){ memcpy(&bytes[index], &_vertices[0], vs); index += vs; }
  memcpy(&bytes[index], &nn, is); index += is;
  if(ns){ memcpy(&bytes[index], &_normals[0], ns); index += ns; }
  memcpy(&bytes[index], &cn, is); index += is;
  if(cs){ memcpy(&bytes[index], &_colors[0], cs); index += cs; }
  return bytes;
}

void VertexArray::fromChar(const char *bytes)
{
  int is = sizeof(int), ds = sizeof(double), index = 0;

  int num; memcpy(&num, &bytes[index], is); index += is;

  if(num > 65535)
    Msg::Error("Should swap data in vertex array stream");

  int ss; memcpy(&ss, &bytes[index], is); index += is;
  if(ss){
    std::vector<char> name(ss); 
    memcpy(&name[0], &bytes[index], ss); index += ss;
  }

  int type; memcpy(&type, &bytes[index], is); index += is;
  double min; memcpy(&min, &bytes[index], ds); index += ds;
  double max; memcpy(&max, &bytes[index], ds); index += ds;
  int numsteps; memcpy(&numsteps, &bytes[index], is); index += is;
  double time; memcpy(&time, &bytes[index], ds); index += ds;
  double xmin; memcpy(&xmin, &bytes[index], ds); index += ds;
  double ymin; memcpy(&ymin, &bytes[index], ds); index += ds;
  double zmin; memcpy(&zmin, &bytes[index], ds); index += ds;
  double xmax; memcpy(&xmax, &bytes[index], ds); index += ds;
  double ymax; memcpy(&ymax, &bytes[index], ds); index += ds;
  double zmax; memcpy(&zmax, &bytes[index], ds); index += ds;

  int vn; memcpy(&vn, &bytes[index], is); index += is;
  if(vn){
    _vertices.resize(vn); int vs = vn * sizeof(float);
    memcpy(&_vertices[0], &bytes[index], vs); index += vs;
  }

  int nn; memcpy(&nn, &bytes[index], is); index += is;
  if(nn){
    _normals.resize(nn); int ns = nn * sizeof(char); 
    memcpy(&_normals[0], &bytes[index], ns); index += ns;
  }

  int cn; memcpy(&cn, &bytes[index], is); index += is;
  if(cn){
    _colors.resize(cn); int cs = cn * sizeof(unsigned char); 
    memcpy(&_colors[0], &bytes[index], cs); index += cs;
  }
}
