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
  // elements already added, when the "unique" filter is on: the filter can be
  // shared with other vertex arrays, in which case it is not owned
  UniqueElementFilter *_filter;
  bool _ownsFilter;
  // OpenGL buffer objects holding a copy of the arrays (vertices, normals,
  // colors). They are created and filled by the graphics code, which is the
  // only place where a GL context is current
  unsigned int _vbo[3];
  bool _vboDirty;
  // buffer objects belong to a GL context: they all become invalid when it is
  // recreated, e.g. when the antialiasing or the double buffering changes
  unsigned int _vboContext;
  long int _statUniqueIn, _statUniqueKept;

  // add stuff in the arrays
  void _addVertex(float x, float y, float z);
  void _addNormal(float nx, float ny, float nz);
  void _addColor(unsigned char r, unsigned char g, unsigned char b,
                 unsigned char a);
  void _addElement(MElement *ele);

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
  // were the buffers created in the GL context that is current?
  bool getVboValid() { return _vboContext == vboContext; }
  void setVboValid() { _vboContext = vboContext; }
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
  // Merge another vertex array into this one. If a color is given it replaces
  // the colors of the merged data, which is how the arrays of several entities
  // drawn each in their own single color are concatenated.
  void merge(VertexArray *va, const unsigned char *color = nullptr);
  // the element pointers are only needed for picking, which uses the arrays of
  // the entities themselves
  void clearElementPointers() { std::vector<MElement *>().swap(_elements); }

  // buffer objects whose vertex array has been deleted: they can only be freed
  // when a GL context is current, i.e. at the beginning of the next frame
  static std::vector<unsigned int> vboToDelete;

  // Identifies the GL context the buffer objects were created in. Call
  // invalidateBuffers() when the context has been recreated: the buffer names
  // then mean nothing any more and have to be created again.
  static unsigned int vboContext;
  static void invalidateBuffers()
  {
    vboContext++;
    vboToDelete.clear();
  }

  // statistics gathered by the unique element filter
  static long int statUniqueIn, statUniqueKept;
  static void printStats();
};

#endif
