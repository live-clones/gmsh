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

// The glyphs the drawing code places: the spheres a node or a point is drawn
// with, the arrows of a vector field, the cylinders of a curve, the ellipsoids
// of a tensor. Each of them is one shape, built once, drawn many times over,
// moved and scaled by a transform of its own.
//
// A glyph comes to several thousand triangles - a sphere alone is four
// kilobytes of them - and a model can hold one per mesh node, so the triangles
// are what a frame builds and throws away, not what is kept between frames.
// What is kept is the placement: where each glyph goes and what colour it is,
// which is a hundred bytes. That is the whole point of collecting them here.
//
// The placement is kept in double precision, as the drawing code works it out:
// rounding it to what the vertex arrays hold would move a glyph by a fraction
// of the length a pixel stands for, which is invisible but not nothing - it
// changes which side of a normal's quantization step a highlight falls on.
enum glyphKind {
  GLYPH_SPHERE = 0,
  GLYPH_ARROW,
  GLYPH_DISK,
  // the side of a cylinder or of a cone, which is one shape: the two radii
  // are the parameters of the glyph rather than part of its transform, as a
  // cone of one taper is not a cone of another one stretched
  GLYPH_CYLINDER,
  GLYPH_NUMKINDS
};

// What a list of glyphs was built from, so that it can be told whether it
// still stands: the length a pixel stands for, the sizes and the types the
// options give them, a counter bumped when the model changes - whatever the
// caller's glyphs depend on. Two tokens that compare equal stand for the same
// glyphs; a token is cheap enough to build for every frame.
class glyphToken {
private:
  std::vector<double> _v;

public:
  void add(double v) { _v.push_back(v); }
  void add(const void *p) { _v.push_back((double)(std::size_t)p); }
  bool operator==(const glyphToken &o) const { return _v == o._v; }
  bool operator!=(const glyphToken &o) const { return !(_v == o._v); }
};

// A run of glyphs, collected instead of drawn.
class glyphList {
public:
  // one glyph: its shape placed by an affine transform - three columns and an
  // origin, column major like every other matrix here - and drawn in one
  // colour
  class instance {
  public:
    double m[12];
    unsigned int color;
    // what the shape of this glyph needs beyond its transform: the two radii
    // of a cylinder. Unused by the kinds that are one shape however they are
    // placed, which is most of them.
    float param[2];
  };

private:
  std::vector<instance> _inst[GLYPH_NUMKINDS];
  // The triangles the instances come to, built the first time they are asked
  // for. A pipeline that can draw the same shape many times over from one
  // instance buffer would not need them at all.
  VertexArray *_va;
  // The glyphs packed the way the graphics card takes them, built the first
  // time they are drawn that way and kept with the instances they come from.
  // This is what a pipeline that can draw one shape many times over is handed,
  // and it is the whole of what it needs: sixty bytes a glyph instead of the
  // several thousand its triangles come to.
  std::vector<unsigned char> _gpu[GLYPH_NUMKINDS];
  glyphToken _token;
  // Has the list been filled with this token? A list can legitimately come to
  // no glyphs at all - nothing visible, everything smaller than a pixel - and
  // finding that out again for every frame is what the cache is there to
  // avoid.
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
  // Take the instances of another list, which is left empty. This is how the
  // threads that fill a list of their own are put back together, in an order
  // that does not depend on how many of them there were.
  void merge(glyphList *other);
  // The triangles the instances come to, built if that has not been done yet
  // and kept until the list is cleared. Null if there is nothing to draw.
  VertexArray *triangles(drawContext *ctx);
  // Draw the glyphs. Below a bound on what they come to this is the triangles
  // above, kept and drawn as one array; past it they are drawn one at a time,
  // which is slower but costs nothing to keep - a mesh can hold a glyph per
  // node, and a sphere is four kilobytes of triangles.
  void draw(drawContext *ctx, bool light);

private:
  void _draw(drawContext *ctx, VertexArray *va, bool light);
  void _stream(drawContext *ctx, bool light);
  // draw them by handing the shape and the glyphs over and letting the
  // graphics card place them; false if it cannot
  bool _instanced(drawContext *ctx, bool light);
  void _expandRange(drawContext *ctx, glyphKind kind, std::size_t first,
                    std::size_t last, VertexArray *va, int at);
};

// The colour that is current, packed the way a glyph carries it: what the
// drawing code sets before it draws something, and what a glyph collected
// instead of drawn is to be given.
unsigned int glyphCurrentColor();

// What an owner keeps a list for: a view draws both its points and its
// vectors with glyphs, a mesh entity its nodes.
enum glyphSlot {
  GLYPH_POINTS = 0,
  GLYPH_LINES,
  // the lines of what the clipping planes add to a view, which are drawn from
  // an array of their own and so need a list of their own
  GLYPH_CLIP_LINES,
  GLYPH_VECTORS,
  GLYPH_TENSORS,
  GLYPH_NODES,
  GLYPH_NUMSLOTS
};

// The lists kept between frames, told apart by whoever owns them - a view, a
// mesh entity, the geometry - and by what they are for. This is the one place
// they are kept, so that there is one answer to when they are thrown away and
// one place to count what they cost.
namespace glyphCache {
  // The list an owner keeps in a slot. True if it was built with this token
  // and can be drawn as it is; false if it was cleared and has to be filled
  // again.
  bool get(const void *owner, glyphSlot slot, const glyphToken &token,
           glyphList *&list);
  // throw away everything an owner has, e.g. because it is being deleted
  void clear(const void *owner);
  void clearAll();
} // namespace glyphCache

#endif
