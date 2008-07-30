// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <algorithm>
#include "VertexArray.h"
#include "Context.h"
#include "Numeric.h"

extern Context_T CTX;

template<int N> float ElementDataLessThan<N>::tolerance = 0.;
float BarycenterLessThan::tolerance = 0.;

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
  if(ele && CTX.pick_elements) _elements.push_back(ele);
}

void VertexArray::add(double *x, double *y, double *z, SVector3 *n, 
                      unsigned int *col, MElement *ele, bool unique, bool boundary)
{
  if(col){
    unsigned char r[100], g[100], b[100], a[100];
    int npe = getNumVerticesPerElement();
    for(int i = 0; i < npe; i++){
      r[i] = CTX.UNPACK_RED(col[i]);
      g[i] = CTX.UNPACK_GREEN(col[i]);
      b[i] = CTX.UNPACK_BLUE(col[i]);
      a[i] = CTX.UNPACK_ALPHA(col[i]);
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
    ElementDataLessThan<3>::tolerance = CTX.lc * 1.e-12;
    std::set<ElementData<3>, ElementDataLessThan<3> >::iterator it = _data3.find(e);
    if(it == _data3.end())
      _data3.insert(e);
    else
      _data3.erase(it);
    return;
  }

  if(unique){
    Barycenter pc(0., 0., 0.);
    for(int i = 0; i < npe; i++)
      pc += Barycenter(x[i], y[i], z[i]);
    BarycenterLessThan::tolerance = CTX.lc * 1.e-12;
    if(_barycenters.find(pc) != _barycenters.end()) 
      return;
    _barycenters.insert(pc);
  }

  for(int i = 0; i < npe; i++){
    _addVertex(x[i], y[i], z[i]);
    if(n) _addNormal(n[i].x(), n[i].y(), n[i].z());
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
