// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GLYPH_LIST_H
#define GLYPH_LIST_H

#include <vector>
#include <cstddef>

class VertexArray;
class drawContext;

// The glyphs (spheres, arrows, cylinders, ellipsoids): one shape each, built
// once and drawn many times with a transform of its own. What is kept
// between frames is the placement (about a hundred bytes per glyph, in
// double precision so that nothing moves by rounding), not the triangles
// (several kilobytes per glyph).
enum glyphKind {
  GLYPH_SPHERE = 0,
  GLYPH_ARROW,
  GLYPH_DISK,
  // the side of a cylinder or cone; the two radii are parameters of the
  // glyph, not part of its transform
  GLYPH_CYLINDER,
  GLYPH_NUMKINDS
};

// what a list of glyphs was built from (pixel size, options, ...), so that
// it can be told whether it is still valid; cheap enough to build every frame
class glyphToken {
private:
  std::vector<double> _v;

public:
  void add(double v) { _v.push_back(v); }
  void add(const void *p) { _v.push_back((double)(std::size_t)p); }
  bool operator==(const glyphToken &o) const { return _v == o._v; }
  bool operator!=(const glyphToken &o) const { return !(_v == o._v); }
};

// a run of glyphs, collected instead of drawn
class glyphList {
public:
  // one glyph: an affine transform (three columns and an origin, column
  // major) and a colour
  class instance {
  public:
    double m[12];
    unsigned int color;
    // shape parameters (the two radii of a cylinder)
    float param[2];
  };

private:
  std::vector<instance> _inst[GLYPH_NUMKINDS];
  // the triangles of the instances, built on first request
  VertexArray *_va;
  // the glyphs packed for instanced drawing (glShader::GLYPH_STRIDE bytes
  // each), built on first use
  std::vector<unsigned char> _gpu[GLYPH_NUMKINDS];
  glyphToken _token;
  // has the list been filled with this token? (a filled list can be empty)
  bool _filled;

public:
  glyphList() : _va(nullptr), _filled(false) {}
  ~glyphList() { clear(); }
  void clear();
  std::size_t size() const;
  const glyphToken &token() const { return _token; }
  bool filled() const { return _filled; }
  void setToken(const glyphToken &t)
  {
    _token = t;
    _filled = true;
  }
  // how many of a kind are going to be added, when the caller knows
  void reserve(glyphKind kind, std::size_t n) { _inst[kind].reserve(n); }
  // the glyph placed by the transform m, which is 4x4 and column major
  void add(glyphKind kind, const double m[16], unsigned int color);
  // a sphere of a radius given in pixels
  void addSphere(drawContext *ctx, double size, double x, double y, double z,
                 unsigned int color);
  // an arrow from (x, y, z) along (dx, dy, dz), which are world lengths
  void addArrow(double x, double y, double z, double dx, double dy, double dz,
                unsigned int color);
  // the side of a cylinder from one point to the other, of the two radii
  // given in world lengths; equal radii make a cylinder, a zero one a cone
  void addCylinder(const double *x, const double *y, const double *z,
                   double r0, double r1, unsigned int color);
  // take the instances of another list, which is left empty (used to merge
  // the lists filled by several threads)
  void merge(glyphList *other);
  // the triangles of the instances, built on first request; null if there is
  // nothing to draw
  VertexArray *triangles(drawContext *ctx);
  // draw the glyphs: from the kept triangles below a memory bound, one at a
  // time past it
  void draw(drawContext *ctx, bool light);

private:
  void _draw(drawContext *ctx, VertexArray *va, bool light);
  void _stream(drawContext *ctx, bool light);
  // instanced drawing; false if not possible
  bool _instanced(drawContext *ctx, bool light);
  void _expandRange(drawContext *ctx, glyphKind kind, std::size_t first,
                    std::size_t last, VertexArray *va, int at);
};

// the current colour, packed as a glyph carries it
unsigned int glyphCurrentColor();

// what an owner keeps a list for
enum glyphSlot {
  GLYPH_POINTS = 0,
  GLYPH_LINES,
  // the lines the clipping planes add to a view
  GLYPH_CLIP_LINES,
  GLYPH_VECTORS,
  GLYPH_TENSORS,
  GLYPH_NODES,
  GLYPH_NUMSLOTS
};

// the lists kept between frames, keyed by owner (a view, a mesh entity, the
// geometry) and slot
namespace glyphCache {
  // the list of an owner and slot; true if it was built with this token and
  // can be drawn as is, false if it has to be filled again
  bool get(const void *owner, glyphSlot slot, const glyphToken &token,
           glyphList *&list);
  // throw away everything an owner has, e.g. because it is being deleted
  void clear(const void *owner);
  void clearAll();
} // namespace glyphCache

#endif
