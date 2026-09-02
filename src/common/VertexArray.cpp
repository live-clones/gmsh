// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "VertexArray.h"
#include "Context.h"
#include "Numeric.h"
#include "OS.h"

template<int N> float ElementDataLessThan<N>::tolerance = 0.0F;
float BarycenterLessThan::tolerance = 0.0F;

int VertexArray::indexing = -1;
long int VertexArray::statCorners = 0;
long int VertexArray::statVertices = 0;
long int VertexArray::statVerticesNoNormal = 0;
double VertexArray::statTime = 0.;

// key used to merge identical vertices: two corners are merged only if their
// coordinates, normal and color are bit-for-bit identical, so that indexing
// never changes what is drawn
namespace {
  struct VertexKey {
    float x, y, z;
    normal_type nx, ny, nz;
    unsigned char r, g, b, a;
  };
  struct VertexKeyHash {
    std::size_t operator()(const VertexKey &k) const
    {
      const unsigned char *p = (const unsigned char *)&k;
      std::size_t h = 14695981039346656037ULL;
      for(std::size_t i = 0; i < sizeof(VertexKey); i++) {
        h ^= p[i];
        h *= 1099511628211ULL;
      }
      return h;
    }
  };
  struct VertexKeyEqual {
    bool operator()(const VertexKey &a, const VertexKey &b) const
    {
      return !memcmp(&a, &b, sizeof(VertexKey));
    }
  };
  typedef std::unordered_map<VertexKey, unsigned int, VertexKeyHash,
                             VertexKeyEqual> VertexKeyMap;
}

VertexArray::VertexArray(int numVerticesPerElement, int numElements)
  : _numVerticesPerElement(numVerticesPerElement)
{
  int nb = (numElements ? numElements : 1) * _numVerticesPerElement;

  double memv = (nb * 3. * sizeof(float)) / 1024. / 1024.;
  double memmax = TotalRam() / 3.;
  if(memv > memmax){
    int old = nb;
    nb = memmax / (3. * sizeof(float)) * 1024 * 1024;
    Msg::Debug("Reduce preallocation of vertex array (%d -> %d)", old, nb);
  }
  _vertices.reserve(nb * 3);
  _normals.reserve(nb * 3);
  _colors.reserve(nb * 4);
}

double VertexArray::getMemoryInMB()
{
  std::size_t bytes = _vertices.size() * sizeof(float) +
                      _normals.size() * sizeof(normal_type) +
                      _colors.size() * sizeof(unsigned char) +
                      _indices.size() * sizeof(unsigned int);
  return (double)bytes / 1024. / 1024.;
}

void VertexArray::_addVertex(float x, float y, float z)
{
  _vertices.push_back(x);
  _vertices.push_back(y);
  _vertices.push_back(z);
}

void VertexArray::_addNormal(float nx, float ny, float nz)
{
#if defined(HAVE_VISUDEV)
  _normals.push_back(nx);
  _normals.push_back(ny);
  _normals.push_back(nz);
#else
  // storing the normals as bytes hurts rendering performance, but it
  // significantly reduces the memory footprint
  char cx = float2char(nx);
  char cy = float2char(ny);
  char cz = float2char(nz);
  _normals.push_back(cx);
  _normals.push_back(cy);
  _normals.push_back(cz);
#endif
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
    add(x, y, z, n, nullptr, nullptr, nullptr, nullptr, ele, unique, boundary);
}

void VertexArray::add(double *x, double *y, double *z, SVector3 *n, unsigned char *r,
                      unsigned char *g, unsigned char *b, unsigned char *a,
                      MElement *ele, bool unique, bool boundary)
{
  int npe = getNumVerticesPerElement();

  if(boundary && npe == 3){
    ElementData<3> e(x, y, z, n, r, g, b, a, ele);
    ElementDataLessThan<3>::tolerance = (float)(CTX::instance()->lc * 1.e-12);
    auto it = _data3.find(e);
    if(it == _data3.end())
      _data3.insert(e);
    else
      _data3.erase(it);
    return;
  }

  // enabling this will reduce memory and rendering time; but will increase the
  // time it takes to create the vertex array
#if 0
  if(unique){
    Barycenter pc(0.0F, 0.0F, 0.0F);
    for(int i = 0; i < npe; i++)
      pc += Barycenter(x[i], y[i], z[i]);
    BarycenterLessThan::tolerance = (float)(CTX::instance()->lc * 1.e-12);
    if(_barycenters.find(pc) != _barycenters.end())
      return;
    _barycenters.insert(pc);
  }
#endif

  for(int i = 0; i < npe; i++){
    _addVertex((float)x[i], (float)y[i], (float)z[i]);
    if(n) _addNormal((float)n[i].x(), (float)n[i].y(), (float)n[i].z());
    if(r && g && b && a) _addColor(r[i], g[i], b[i], a[i]);
    _addElement(ele);
  }
}

static int getIndexingMode()
{
  if(VertexArray::indexing < 0) {
    const char *s = getenv("GMSH_INDEXED_VA");
    VertexArray::indexing = s ? atoi(s) : 0;
  }
  return VertexArray::indexing;
}

// number of bytes stored per vertex in the arrays
static std::size_t bytesPerVertex(bool normals, bool colors)
{
  return 3 * sizeof(float) + (normals ? 3 * sizeof(normal_type) : 0) +
         (colors ? 4 * sizeof(unsigned char) : 0);
}

void VertexArray::_buildIndex()
{
  int mode = getIndexingMode();
  if(!mode || isIndexed()) return;

  int n = getNumVertices();
  if(!n) return;

  bool hasN = ((int)_normals.size() == 3 * n);
  bool hasC = ((int)_colors.size() == 4 * n);

  double t1 = TimeOfDay();

  VertexKeyMap map;
  map.reserve(n);
  std::vector<unsigned int> ind(n);
  std::vector<float> v;
  std::vector<normal_type> nor;
  std::vector<unsigned char> col;

  for(int i = 0; i < n; i++) {
    VertexKey k;
    memset(&k, 0, sizeof(VertexKey));
    k.x = _vertices[3 * i];
    k.y = _vertices[3 * i + 1];
    k.z = _vertices[3 * i + 2];
    if(hasN) {
      k.nx = _normals[3 * i];
      k.ny = _normals[3 * i + 1];
      k.nz = _normals[3 * i + 2];
    }
    if(hasC) {
      k.r = _colors[4 * i];
      k.g = _colors[4 * i + 1];
      k.b = _colors[4 * i + 2];
      k.a = _colors[4 * i + 3];
    }
    auto it = map.find(k);
    if(it != map.end()) {
      ind[i] = it->second;
      continue;
    }
    unsigned int id = (unsigned int)(v.size() / 3);
    map[k] = id;
    ind[i] = id;
    v.push_back(k.x);
    v.push_back(k.y);
    v.push_back(k.z);
    if(hasN) {
      nor.push_back(k.nx);
      nor.push_back(k.ny);
      nor.push_back(k.nz);
    }
    if(hasC) {
      col.push_back(k.r);
      col.push_back(k.g);
      col.push_back(k.b);
      col.push_back(k.a);
    }
  }

  int nu = (int)(v.size() / 3);
  statTime += TimeOfDay() - t1;
  statCorners += n;
  statVertices += nu;

  if(mode == 3) {
    // measurement only: also compute how many vertices would remain if the
    // normals were not stored (i.e. computed in a shader), then leave the
    // arrays untouched
    VertexKeyMap map2;
    map2.reserve(n);
    int nu2 = 0;
    for(int i = 0; i < n; i++) {
      VertexKey k;
      memset(&k, 0, sizeof(VertexKey));
      k.x = _vertices[3 * i];
      k.y = _vertices[3 * i + 1];
      k.z = _vertices[3 * i + 2];
      if(hasC) {
        k.r = _colors[4 * i];
        k.g = _colors[4 * i + 1];
        k.b = _colors[4 * i + 2];
        k.a = _colors[4 * i + 3];
      }
      if(map2.find(k) == map2.end()) map2[k] = nu2++;
    }
    statVerticesNoNormal += nu2;
    return;
  }

  if(mode == 1) {
    // only keep the index array if it actually saves memory: each corner costs
    // an extra 4-byte index, which is not paid back unless enough vertices are
    // shared
    std::size_t bpv = bytesPerVertex(hasN, hasC);
    std::size_t flat = (std::size_t)n * bpv;
    std::size_t indexed =
      (std::size_t)nu * bpv + (std::size_t)n * sizeof(unsigned int);
    if(indexed >= flat) return;
  }

  _vertices.swap(v);
  _normals.swap(nor);
  _colors.swap(col);
  _indices.swap(ind);
}

void VertexArray::_deindex()
{
  if(!isIndexed()) return;

  int n = getNumVertices();
  bool hasN = ((int)_normals.size() == 3 * n);
  bool hasC = ((int)_colors.size() == 4 * n);
  int nc = (int)_indices.size();

  std::vector<float> v;
  std::vector<normal_type> nor;
  std::vector<unsigned char> col;
  v.reserve(3 * nc);
  if(hasN) nor.reserve(3 * nc);
  if(hasC) col.reserve(4 * nc);

  for(int i = 0; i < nc; i++) {
    unsigned int j = _indices[i];
    for(int k = 0; k < 3; k++) v.push_back(_vertices[3 * j + k]);
    if(hasN)
      for(int k = 0; k < 3; k++) nor.push_back(_normals[3 * j + k]);
    if(hasC)
      for(int k = 0; k < 4; k++) col.push_back(_colors[4 * j + k]);
  }

  _vertices.swap(v);
  _normals.swap(nor);
  _colors.swap(col);
  _indices.clear();
}

void VertexArray::printStats()
{
  if(!statCorners) return;
  double bpc = 3. * sizeof(float) + 3. * sizeof(normal_type) +
               4. * sizeof(unsigned char);
  double flat = statCorners * bpc / 1024. / 1024.;
  double idx = (statVertices * bpc + statCorners * sizeof(unsigned int)) /
               1024. / 1024.;
  Msg::Info("Vertex array indexing: %ld corners -> %ld vertices (%.2fx), "
            "%.1f -> %.1f Mb (%.2fx), %g s",
            statCorners, statVertices, (double)statCorners / statVertices,
            flat, idx, flat / idx, statTime);
  if(statVerticesNoNormal)
    Msg::Info("Vertex array indexing without normals: %ld corners -> %ld "
              "vertices (%.2fx)",
              statCorners, statVerticesNoNormal,
              (double)statCorners / statVerticesNoNormal);
  statCorners = statVertices = statVerticesNoNormal = 0;
  statTime = 0.;
}

void VertexArray::finalize()
{
  if(_data3.size()){
    auto it = _data3.begin();
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
  _buildIndex();
}

class AlphaElement {
 public:
  AlphaElement(float *vp, normal_type *np, unsigned char *cp) : v(vp), n(np), c(cp) {}
  float *v;
  normal_type *n;
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
    return prosca(eye, cg1) < prosca(eye, cg2);
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

  if(isIndexed()) {
    // only the index array (and the element pointers) need to be permuted: the
    // vertex, normal and color arrays are left untouched
    int n = (int)_indices.size() / npe;
    if(!n) return;
    double eye[3] = {x, y, z};
    std::vector<double> key(n);
    std::vector<int> perm(n);
    for(int i = 0; i < n; i++) {
      perm[i] = i;
      double cg[3] = {0., 0., 0.};
      for(int j = 0; j < npe; j++) {
        unsigned int k = _indices[npe * i + j];
        cg[0] += _vertices[3 * k];
        cg[1] += _vertices[3 * k + 1];
        cg[2] += _vertices[3 * k + 2];
      }
      key[i] = prosca(eye, cg);
    }
    std::sort(perm.begin(), perm.end(),
              [&key](int a, int b) { return key[a] < key[b]; });
    std::vector<unsigned int> ind(_indices.size());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < npe; j++)
        ind[npe * i + j] = _indices[npe * perm[i] + j];
    _indices.swap(ind);
    if((int)_elements.size() == npe * n) {
      std::vector<MElement *> ele(_elements.size());
      for(int i = 0; i < n; i++)
        for(int j = 0; j < npe; j++)
          ele[npe * i + j] = _elements[npe * perm[i] + j];
      _elements.swap(ele);
    }
    return;
  }

  int n = getNumVertices() / npe;

  AlphaElementLessThan::numVertices = npe;
  AlphaElementLessThan::eye[0] = x;
  AlphaElementLessThan::eye[1] = y;
  AlphaElementLessThan::eye[2] = z;

  std::vector<AlphaElement> elements;
  elements.reserve(n);
  for(int i = 0; i < n; i++){
    float *vp = &_vertices[3 * npe * i];
    normal_type *np = _normals.empty() ? nullptr : &_normals[3 * npe * i];
    unsigned char *cp = _colors.empty() ? nullptr : &_colors[4 * npe * i];
    elements.push_back(AlphaElement(vp, np, cp));
  }
  std::sort(elements.begin(), elements.end(), AlphaElementLessThan());

  std::vector<float> sortedVertices;
  std::vector<normal_type> sortedNormals;
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

char *VertexArray::toChar(int num, const std::string &name, int type,
                          double min, double max, int numsteps, double time,
                          const SBoundingBox3d &bbox, int &len)
{
  if(isIndexed()) {
    // the wire format does not carry an index array
    VertexArray tmp(*this);
    tmp._deindex();
    return tmp.toChar(num, name, type, min, max, numsteps, time, bbox, len);
  }

  int vn = _vertices.size(), nn = _normals.size(), cn = _colors.size();
  int vs = vn * sizeof(float),
      ns = nn * sizeof(normal_type),
      cs = cn * sizeof(unsigned char);
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
  if(cs){ memcpy(&bytes[index], &_colors[0], cs); /* index += cs; */ }
  return bytes;
}

int VertexArray::decodeHeader(int length, const char *bytes, int swap,
                              std::string &name, int &tag, int &type,
                              double &min, double &max, int &numSteps, double &time,
                              double &xmin, double &ymin, double &zmin,
                              double &xmax, double &ymax, double &zmax)
{
  int is = sizeof(int), ds = sizeof(double);

  if(length < 4 * is + 9 * ds){
    Msg::Error("Too few bytes to create vertex array: %d", length);
    return 0;
  }

  if(swap){
    Msg::Error("Should swap bytes in vertex array--not implemented yet");
    return 0;
  }

  int index = 0;
  memcpy(&tag, &bytes[index], is); index += is;
  int ss; memcpy(&ss, &bytes[index], is); index += is;
  if(ss){
    std::vector<char> n(ss);
    memcpy(&n[0], &bytes[index], ss); index += ss;
    for(std::size_t i = 0; i < n.size(); i++) name += n[i];
  }
  memcpy(&type, &bytes[index], is); index += is;
  memcpy(&min, &bytes[index], ds); index += ds;
  memcpy(&max, &bytes[index], ds); index += ds;
  memcpy(&numSteps, &bytes[index], is); index += is;
  memcpy(&time, &bytes[index], ds); index += ds;
  memcpy(&xmin, &bytes[index], ds); index += ds;
  memcpy(&ymin, &bytes[index], ds); index += ds;
  memcpy(&zmin, &bytes[index], ds); index += ds;
  memcpy(&xmax, &bytes[index], ds); index += ds;
  memcpy(&ymax, &bytes[index], ds); index += ds;
  memcpy(&zmax, &bytes[index], ds); index += ds;
  return index;
}

void VertexArray::fromChar(int length, const char *bytes, int swap)
{
  std::string name;
  int tag, type, numSteps;
  double min, max, time, xmin, ymin, zmin, xmax, ymax, zmax;
  int index = decodeHeader(length, bytes, swap, name, tag, type, min, max,
                           numSteps, time, xmin, ymin, zmin, xmax, ymax, zmax);
  if(!index) return;

  int is = sizeof(int);
  int vn; memcpy(&vn, &bytes[index], is); index += is;
  if(vn){
    _vertices.resize(vn); int vs = vn * sizeof(float);
    memcpy(&_vertices[0], &bytes[index], vs); index += vs;
  }

  int nn; memcpy(&nn, &bytes[index], is); index += is;
  if(nn){
    _normals.resize(nn);
    int ns = nn * sizeof(normal_type);
    memcpy(&_normals[0], &bytes[index], ns); index += ns;
  }

  int cn; memcpy(&cn, &bytes[index], is); index += is;
  if(cn){
    _colors.resize(cn); int cs = cn * sizeof(unsigned char);
    memcpy(&_colors[0], &bytes[index], cs); /* index += cs; */
  }
}

void VertexArray::merge(VertexArray* va)
{
  _deindex();
  va->_deindex();
  if(va->getNumVertices() != 0) {
    _vertices.insert(_vertices.end(), va->firstVertex(), va->lastVertex());
    _normals.insert(_normals.end(), va->firstNormal(), va->lastNormal());
    _colors.insert(_colors.end(), va->firstColor(), va->lastColor());
    _elements.insert(_elements.end(), va->firstElementPointer(),
                     va->lastElementPointer());
  }
}
