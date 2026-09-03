// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <string.h>
#include <vector>
#include <set>
#include <unordered_map>
#include <mutex>
#include <cstdint>
#include "SVector3.h"
#include "SBoundingBox3d.h"

#include "GmshConfig.h"
#if defined(HAVE_VISUDEV)
typedef float normal_type;
#else
typedef char normal_type;
#endif

class MElement;

// key used by the "unique" filter to detect elements that are drawn several
// times, e.g. an edge shared by several tetrahedra: the N corners are stored in
// canonical (sorted) order, together with the color, so that an element added
// twice with the same geometry and the same color maps to the same key. The
// size is padded to a multiple of 8 bytes so that it can be hashed word by word
template <int N> class alignas(8) CornerKey {
public:
  float p[3 * N];
  unsigned char c[4];
  unsigned char pad[8 - ((12 * N + 4) % 8)];
};

// filter used to detect elements that are drawn several times. The keys are
// spread over several shards, each with its own lock, so that the filter can be
// shared by the threads that fill the vertex arrays of a given entity.
class UniqueElementFilter {
private:
  enum { NUM_SHARDS = 256 };
  // open addressing table of 64 bit hashes, with 0 marking an empty slot: only
  // the hash is stored, so two elements whose keys collide on 64 bits are
  // wrongly merged. With 20 million elements this happens with probability
  // ~1e-5, i.e. much less often than one dropped edge per mesh
  class Shard {
  public:
    std::vector<std::uint64_t> table;
    std::size_t num;
    Shard() : num(0) {}
    void reserve(std::size_t n);
    bool insert(std::uint64_t h);
    bool contains(std::uint64_t h) const;
    // insert the key, or erase it if it is already there
    bool insertOrErase(std::uint64_t h);
    void erase(std::size_t i);
  };
  Shard _shard[NUM_SHARDS];
  std::mutex _mutex[NUM_SHARDS];
  bool _threaded;

public:
  UniqueElementFilter(bool threaded) : _threaded(threaded) {}
  // hint at the total number of elements that will be filtered
  void reserve(std::size_t n);
  // switch on the locks: this must be called before the filter is shared, e.g.
  // when a first, small batch of elements has been treated serially
  void setThreaded() { _threaded = true; }
  // return true if an element with the same corners and the same color has
  // already been seen
  bool isDuplicate(int npe, double *x, double *y, double *z, unsigned char *r,
                   unsigned char *g, unsigned char *b, unsigned char *a);
  // same, for data that has a topology: the element is identified by its
  // vertices (any opaque, stable pointer or index) instead of by the
  // coordinates of its corners, which avoids building and hashing a large key.
  // Pass the color as well, as two elements sharing an edge or a face can be
  // drawn with different colors
  bool isDuplicate(unsigned int col, const void *v0, const void *v1,
                   const void *v2 = nullptr, const void *v3 = nullptr);
  // most general form: the caller builds the key itself, e.g. from node
  // identifiers paired with the color of each node
  bool isDuplicate(const std::uint64_t *key, int n);
  bool contains(const std::uint64_t *key, int n);
  void insertOrErase(const std::uint64_t *key, int n);
  // test without inserting: used to ask whether a face has been seen twice,
  // i.e. whether it is interior to the mesh
  bool contains(unsigned int col, const void *v0, const void *v1,
                const void *v2 = nullptr, const void *v3 = nullptr);
  // insert the element, or remove it if it has already been seen: after all the
  // elements have been passed, the filter holds exactly those seen an odd
  // number of times, i.e. the faces that bound the mesh
  void insertOrErase(unsigned int col, const void *v0, const void *v1,
                     const void *v2 = nullptr, const void *v3 = nullptr);
};

class VertexArray {
private:
  int _numVerticesPerElement;
  std::vector<float> _vertices;
  std::vector<normal_type> _normals;
  std::vector<unsigned char> _colors;
  std::vector<MElement *> _elements;
  // optional index array: when non-empty, the vertex/normal/color arrays hold
  // unique vertices only, and _indices lists the vertices of each drawn corner
  std::vector<unsigned int> _indices;
  // elements already added, when the "unique" filter is on: the filter can be
  // shared with other vertex arrays, in which case it is not owned
  UniqueElementFilter *_filter;
  bool _ownsFilter;
  // OpenGL buffer objects holding a copy of the arrays (vertices, normals,
  // colors, indices). They are created and filled by the graphics code, which
  // is the only place where a GL context is current
  unsigned int _vbo[4];
  bool _vboDirty;
  long int _statUniqueIn, _statUniqueKept;

  // add stuff in the arrays
  void _addVertex(float x, float y, float z);
  void _addNormal(float nx, float ny, float nz);
  void _addColor(unsigned char r, unsigned char g, unsigned char b,
                 unsigned char a);
  void _addElement(MElement *ele);
  // build (resp. undo) the index array by merging identical vertices
  void _buildIndex();
  void _deindex();

public:
  VertexArray(int numVerticesPerElement, int numElements);
  ~VertexArray();
  // return the filter used to drop elements that are drawn several times,
  // creating it if necessary
  UniqueElementFilter *getUniqueFilter(bool threaded);
  // use a filter owned by somebody else
  void setUniqueFilter(UniqueElementFilter *f);
  // return the number of vertices in the array
  int getNumVertices() { return (int)_vertices.size() / 3; }
  // return the number of vertices per element
  int getNumVerticesPerElement() { return _numVerticesPerElement; }
  // return true if the array is indexed
  bool isIndexed() { return !_indices.empty(); }
  // return the number of drawn corners: this is the number of indices if the
  // array is indexed, and the number of vertices otherwise
  int getNumCorners()
  {
    return isIndexed() ? (int)_indices.size() : getNumVertices();
  }
  // return the position, in the vertex arrays, of the i-th drawn corner
  int getCornerIndex(int i) { return isIndexed() ? (int)_indices[i] : i; }
  // return the number of indices, and a pointer to the raw index array
  int getNumIndices() { return (int)_indices.size(); }
  unsigned int *getIndexArray(int i = 0) { return &_indices[i]; }
  // return the number of element pointers
  int getNumElementPointers() { return (int)_elements.size(); }
  // return a pointer to the raw vertex array (warning: 1) we don't
  // range check 2) calling this if _vertices.size() == 0 will cause
  // some compilers to throw an exception)
  float *getVertexArray(int i = 0) { return &_vertices[i]; }
  std::vector<float>::iterator firstVertex() { return _vertices.begin(); }
  std::vector<float>::iterator lastVertex() { return _vertices.end(); }

  // return true if the array stores normals (resp. colors)
  bool hasNormals() { return (int)_normals.size() == 3 * getNumVertices(); }
  bool hasColors() { return (int)_colors.size() == 4 * getNumVertices(); }
  // buffer objects: the ids are 0 as long as nothing has been uploaded
  unsigned int *getVboIds() { return _vbo; }
  bool getVboDirty() { return _vboDirty; }
  void setVboDirty(bool dirty) { _vboDirty = dirty; }
  // return a pointer to the raw normal array
  normal_type *getNormalArray(int i = 0) { return &_normals[i]; }
  std::vector<normal_type>::iterator firstNormal() { return _normals.begin(); }
  std::vector<normal_type>::iterator lastNormal() { return _normals.end(); }

  // return a pointer to the raw color array
  unsigned char *getColorArray(int i = 0) { return &_colors[i]; }
  std::vector<unsigned char>::iterator firstColor() { return _colors.begin(); }
  std::vector<unsigned char>::iterator lastColor() { return _colors.end(); }

  // return a pointer to the raw element array
  MElement **getElementPointerArray(int i = 0) { return &_elements[i]; }
  std::vector<MElement *>::iterator firstElementPointer()
  {
    return _elements.begin();
  }
  std::vector<MElement *>::iterator lastElementPointer()
  {
    return _elements.end();
  }

  // add element data in the arrays (if unique is set, only add the element if
  // an identical one has not already been added)
  void add(double *x, double *y, double *z, SVector3 *n, unsigned int *col,
           MElement *ele = nullptr, bool unique = true);
  void add(double *x, double *y, double *z, SVector3 *n, unsigned char *r = nullptr,
           unsigned char *g = nullptr, unsigned char *b = nullptr, unsigned char *a = nullptr,
           MElement *ele = nullptr, bool unique = true);
  // finalize the arrays
  void finalize();
  // sort the arrays with elements back to front wrt the eye position
  void sort(double x, double y, double z);
  // estimate the size of the vertex array in megabytes
  double getMemoryInMB();
  // serialize the vertex array into a string (for sending over the
  // network)
  char *toChar(int num, const std::string &name, int type, double min,
               double max, int numsteps, double time,
               const SBoundingBox3d &bbox, int &len);
  void fromChar(int length, const char *bytes, int swap);
  static int decodeHeader(int length, const char *bytes, int swap,
                          std::string &name, int &tag, int &type, double &min,
                          double &max, int &numSteps, double &time,
                          double &xmin, double &ymin, double &zmin,
                          double &xmax, double &ymax, double &zmax);
  // merge another vertex array into this one
  void merge(VertexArray *va);

  // buffer objects whose vertex array has been deleted: they can only be freed
  // when a GL context is current, i.e. at the beginning of the next frame
  static std::vector<unsigned int> vboToDelete;

  // index the arrays in finalize() (set from the GMSH_INDEXED_VA env variable)
  static int indexing;
  // statistics gathered while indexing
  static long int statCorners, statVertices, statVerticesNoNormal;
  static long int statUniqueIn, statUniqueKept;
  static double statTime, statUniqueTime;
  static void printStats();
};

#endif
