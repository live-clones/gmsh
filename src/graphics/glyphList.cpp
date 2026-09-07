// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <cstring>
#include <map>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "glyphList.h"
#include "glImmediate.h"
#include "glMatrix.h"
#include "drawContext.h"
#include "glShader.h"
#include "glApi.h"
#include "VertexArray.h"
#include "Numeric.h"
#include "Context.h"
#include "OS.h"

#if defined(_OPENMP)
#include <omp.h>
#endif

// What all the lists together are keeping, in vertices. The bound below is on
// the whole of it rather than on each of them: a model has one list per entity
// and a bound that each of them may reach on its own is not a bound at all.
static long _keptVertices = 0;

unsigned int glyphCurrentColor()
{
  unsigned int col;
  memcpy(&col, gmshCurrentColor(), 4);
  return col;
}

void glyphList::clear()
{
  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    std::vector<instance>().swap(_inst[k]);
    std::vector<unsigned char>().swap(_gpu[k]);
  }
  if(_va) {
    _keptVertices -= _va->getNumVertices();
    delete _va;
  }
  _va = nullptr;
  _filled = false;
}

std::size_t glyphList::size() const
{
  std::size_t n = 0;
  for(int k = 0; k < GLYPH_NUMKINDS; k++) n += _inst[k].size();
  return n;
}

void glyphList::add(glyphKind kind, const double m[16], unsigned int color)
{
  instance i;
  i.m[0] = m[0];
  i.m[1] = m[1];
  i.m[2] = m[2];
  i.m[3] = m[4];
  i.m[4] = m[5];
  i.m[5] = m[6];
  i.m[6] = m[8];
  i.m[7] = m[9];
  i.m[8] = m[10];
  i.m[9] = m[12];
  i.m[10] = m[13];
  i.m[11] = m[14];
  i.color = color;
  i.param[0] = i.param[1] = 0.f;
  _inst[kind].push_back(i);
}

void glyphList::addSphere(drawContext *ctx, double size, double x, double y,
                          double z, unsigned int color)
{
  double r = size * ctx->pixel_equiv_x / ctx->s[0]; // the size is in pixels
  instance i;
  i.m[0] = r;
  i.m[1] = 0.;
  i.m[2] = 0.;
  i.m[3] = 0.;
  i.m[4] = r;
  i.m[5] = 0.;
  i.m[6] = 0.;
  i.m[7] = 0.;
  i.m[8] = r;
  i.m[9] = x;
  i.m[10] = y;
  i.m[11] = z;
  i.color = color;
  i.param[0] = i.param[1] = 0.f;
  _inst[GLYPH_SPHERE].push_back(i);
}

void glyphList::addArrow(double x, double y, double z, double dx, double dy,
                         double dz, unsigned int color)
{
  double length = std::sqrt(dx * dx + dy * dy + dz * dz);
  if(length == 0.) return;

  double zdir[3] = {0., 0., 1.};
  double vdir[3] = {dx / length, dy / length, dz / length};
  double axis[3];
  prodve(zdir, vdir, axis);
  double const cosphi = prosca(zdir, vdir);
  if(!norme(axis)) {
    axis[0] = 0.;
    axis[1] = 1.;
    axis[2] = 0.;
  }
  double phi = 180. * myacos(cosphi) / M_PI;

  // the transform the matrix stack used to carry: translate, then scale, then
  // rotate, applied to the point in that order from the right
  double t[16], sc[16], r[16], a[16], m[16];
  glMatrix::translate(x, y, z, t);
  glMatrix::scale(length, length, length, sc);
  glMatrix::rotate(phi, axis[0], axis[1], axis[2], r);
  glMatrix::multiply(t, sc, a);
  glMatrix::multiply(a, r, m);
  add(GLYPH_ARROW, m, color);
}

void glyphList::addCylinder(const double *x, const double *y, const double *z,
                            double r0, double r1, unsigned int color)
{
  double dx = x[1] - x[0], dy = y[1] - y[0], dz = z[1] - z[0];
  double length = std::sqrt(dx * dx + dy * dy + dz * dz);
  if(length == 0. || (r0 == 0. && r1 == 0.)) return;

  double zdir[3] = {0., 0., 1.};
  double vdir[3] = {dx / length, dy / length, dz / length};
  double axis[3];
  prodve(zdir, vdir, axis);
  double const cosphi = prosca(zdir, vdir);
  if(!norme(axis)) {
    axis[0] = 0.;
    axis[1] = 1.;
    axis[2] = 0.;
  }
  double phi = 180. * myacos(cosphi) / M_PI;

  // the length is in the transform, which stretches the unit cylinder along
  // its axis; the radii are not, as a cone of one taper is not a cone of
  // another one stretched
  double t[16], r[16], sc[16], a[16], m[16];
  glMatrix::translate(x[0], y[0], z[0], t);
  glMatrix::rotate(phi, axis[0], axis[1], axis[2], r);
  glMatrix::scale(1., 1., length, sc);
  glMatrix::multiply(t, r, a);
  glMatrix::multiply(a, sc, m);
  add(GLYPH_CYLINDER, m, color);
  instance &i = _inst[GLYPH_CYLINDER].back();
  i.param[0] = (float)r0;
  i.param[1] = (float)r1;
}

void glyphList::merge(glyphList *other)
{
  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    _inst[k].insert(_inst[k].end(), other->_inst[k].begin(),
                    other->_inst[k].end());
    std::vector<instance>().swap(other->_inst[k]);
  }
}

namespace {
  // Expand a run of glyphs of one kind into a vertex array, starting at the
  // vertex first. Everything it needs is read only, so several threads can be
  // in here at once, each on a range of its own.
  void expand(drawContext *ctx, glyphKind kind,
              const std::vector<glyphList::instance> &inst, std::size_t from,
              std::size_t to, VertexArray *va, int first)
  {
    const float *tq;
    const normal_type *tn;
    int num;
    const float *tp = ctx->glyphTemplate(kind, tq, tn, num);
    if(!tp) return;

    float *xyz = va->getVertexArray(3 * first);
    normal_type *nrm = va->getNormalArray(3 * first);
    unsigned char *col = va->getColorArray(4 * first);

    for(std::size_t g = from; g < to; g++) {
      const glyphList::instance &in = inst[g];
      const double *m = in.m;
      // The normals follow the transform, but not the way the coordinates do:
      // what they are turned by is the inverse transpose of it. When the
      // transform is a rotation and the same scaling in every direction -
      // which is what a sphere and an arrow are - that is the rotation again,
      // so the result is already unit length and the template's own normals
      // can be handed over as they are when there is not even a rotation.
      double n[9];
      bool unit = false, same = false;
      {
        double c0 = m[0] * m[0] + m[1] * m[1] + m[2] * m[2];
        double c1 = m[3] * m[3] + m[4] * m[4] + m[5] * m[5];
        double c2 = m[6] * m[6] + m[7] * m[7] + m[8] * m[8];
        double d01 = m[0] * m[3] + m[1] * m[4] + m[2] * m[5];
        double d02 = m[0] * m[6] + m[1] * m[7] + m[2] * m[8];
        double d12 = m[3] * m[6] + m[4] * m[7] + m[5] * m[8];
        double tol = 1e-6 * c0;
        if(c0 > 0. && std::fabs(c1 - c0) < tol && std::fabs(c2 - c0) < tol &&
           std::fabs(d01) < tol && std::fabs(d02) < tol &&
           std::fabs(d12) < tol) {
          double d = 1. / std::sqrt(c0);
          for(int i = 0; i < 9; i++) n[i] = m[i] * d;
          unit = true;
          same = (n[0] == 1. && n[4] == 1. && n[8] == 1. && n[1] == 0. &&
                  n[2] == 0. && n[3] == 0. && n[5] == 0. && n[6] == 0. &&
                  n[7] == 0.);
        }
        else {
          double det = m[0] * (m[4] * m[8] - m[5] * m[7]) -
                       m[3] * (m[1] * m[8] - m[2] * m[7]) +
                       m[6] * (m[1] * m[5] - m[2] * m[4]);
          double d = det ? 1. / det : 1.;
          n[0] = (m[4] * m[8] - m[5] * m[7]) * d;
          n[1] = (m[6] * m[5] - m[3] * m[8]) * d;
          n[2] = (m[3] * m[7] - m[6] * m[4]) * d;
          n[3] = (m[7] * m[2] - m[1] * m[8]) * d;
          n[4] = (m[0] * m[8] - m[6] * m[2]) * d;
          n[5] = (m[6] * m[1] - m[0] * m[7]) * d;
          n[6] = (m[1] * m[5] - m[4] * m[2]) * d;
          n[7] = (m[3] * m[2] - m[0] * m[5]) * d;
          n[8] = (m[0] * m[4] - m[3] * m[1]) * d;
        }
      }

      // Where the corners of the template go. A cylinder is the one shape
      // whose corners are not the template's own: its two radii widen or
      // narrow it as it goes along, and the normal of its side leans over by
      // as much - the template carries the cosine and the sine of the angle
      // each corner is at, which is what both are worked out from.
      const bool taper = (kind == GLYPH_CYLINDER);
      double r0 = in.param[0], r1 = in.param[1];
      for(int v = 0; v < num; v++) {
        const float *p = &tp[3 * v];
        double px = p[0], py = p[1], pz = p[2];
        if(taper) {
          double r = r0 + pz * (r1 - r0);
          px *= r;
          py *= r;
        }
        xyz[3 * v] = (float)(m[0] * px + m[3] * py + m[6] * pz + m[9]);
        xyz[3 * v + 1] = (float)(m[1] * px + m[4] * py + m[7] * pz + m[10]);
        xyz[3 * v + 2] = (float)(m[2] * px + m[5] * py + m[8] * pz + m[11]);
        memcpy(&col[4 * v], &in.color, 4);
      }
      if(same && !taper) {
        // nothing turns them: the template's are the ones of this glyph, and
        // they are already encoded
        memcpy(nrm, tn, 3 * num * sizeof(normal_type));
      }
      else {
        for(int v = 0; v < num; v++) {
          const float *q = &tq[3 * v];
          // the side of a cone leans over by its taper, over the length the
          // transform gives it; what is worked out here is that normal
          // before the transform, which then turns it like any other
          double q0 = q[0], q1 = q[1], q2 = q[2];
          if(taper) {
            q0 = tp[3 * v];
            q1 = tp[3 * v + 1];
            q2 = r0 - r1;
          }
          double nx = n[0] * q0 + n[3] * q1 + n[6] * q2;
          double ny = n[1] * q0 + n[4] * q1 + n[7] * q2;
          double nz = n[2] * q0 + n[5] * q1 + n[8] * q2;
          if(!unit || taper) {
            double l = std::sqrt(nx * nx + ny * ny + nz * nz);
            if(l > 0.) {
              nx /= l;
              ny /= l;
              nz /= l;
            }
          }
          nrm[3 * v] = float2char((float)nx);
          nrm[3 * v + 1] = float2char((float)ny);
          nrm[3 * v + 2] = float2char((float)nz);
        }
      }
      xyz += 3 * num;
      nrm += 3 * num;
      col += 4 * num;
    }
  }
} // namespace

VertexArray *glyphList::triangles(drawContext *ctx)
{
  if(_va) return _va;
  if(!size()) return nullptr;

  ctx->updateGlyphTemplates();
  int num[GLYPH_NUMKINDS];
  long total = 0;
  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    const float *tq;
    const normal_type *tn;
    num[k] = 0;
    if(_inst[k].size()) ctx->glyphTemplate(k, tq, tn, num[k]);
    total += (long)num[k] * (long)_inst[k].size();
  }
  if(!total) return nullptr;

  _va = new VertexArray(3, (int)(total / 3));
  int at = _va->addBlock((int)total);

  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    std::size_t n = _inst[k].size();
    if(!n || !num[k]) continue;
    _expandRange(ctx, (glyphKind)k, 0, n, _va, at);
    at += (int)(n * num[k]);
  }
  _va->finalize();
  _keptVertices += _va->getNumVertices();
  return _va;
}

void glyphList::_expandRange(drawContext *ctx, glyphKind kind,
                             std::size_t first, std::size_t last,
                             VertexArray *va, int at)
{
  const float *tq;
  const normal_type *tn;
  int num = 0;
  ctx->glyphTemplate(kind, tq, tn, num);
  if(!num || last <= first) return;

  // The glyphs are independent of one another and each of them writes a range
  // of its own, so the range is shared out and nothing has to be put back
  // together afterwards.
  std::size_t n = last - first;
  int nthreads = CTX::instance()->numThreads;
  if(nthreads <= 0) nthreads = 1;
  int nt = (n < 2000) ? 1 : nthreads;
  if((std::size_t)nt > n) nt = (int)n;
#if defined(_OPENMP)
#pragma omp parallel for num_threads(nt) schedule(static, 1) if(nt > 1)
#endif
  for(int t = 0; t < nt; t++) {
    std::size_t from = first + n * t / nt, to = first + n * (t + 1) / nt;
    expand(ctx, kind, _inst[kind], from, to, va, at + (int)((from - first) * num));
  }
}

// How many triangles it is worth keeping. Past this they are expanded a batch
// at a time for every frame instead, which is slower but takes no memory.
//
// What is being traded: sixty thousand spheres are thirteen million vertices,
// which take about half a gigabyte - nineteen bytes here and as many again in
// the buffer object the graphics card is handed - and draw in nine
// milliseconds a frame instead of thirty. Ten times faster for half a
// gigabyte is worth it once; it is not worth it ten times over, hence a bound,
// which General.GlyphCacheSize sets and which is otherwise a fraction of the
// machine and a number both.
static long maxKeptVertices()
{
  double mb = CTX::instance()->glyphCacheSize;
  if(mb <= 0.) {
    mb = TotalRam() / 32.;
    if(mb > 1024.) mb = 1024.;
    if(mb < 64.) mb = 64.;
  }
  return (long)(mb * 1024. * 1024. / 38.);
}

void glyphList::draw(drawContext *ctx, bool light)
{
  if(!size()) return;

  // Whatever was collected before these glyphs was asked for before them and
  // has to reach the window first; the instanced and streamed backends bind
  // attributes of their own, so nothing may be left waiting behind them.
  gmshFlushImmediate();

  ctx->updateGlyphTemplates();
  long total = 0;
  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    const float *tq;
    const normal_type *tn;
    int num = 0;
    if(_inst[k].size()) ctx->glyphTemplate(k, tq, tn, num);
    total += (long)num * (long)_inst[k].size();
  }

  // The pipeline that can place a shape itself needs none of this: it is
  // handed the shape once and the glyphs as they are
  if(_instanced(ctx, light)) return;

  // A list that nobody keeps is filled again for the next frame anyway, so
  // there is nothing to be had from keeping the triangles it comes to: they
  // would be given up and built again just the same, only with an allocation
  // the size of the whole scene in between.
  if(!filled()) {
    _stream(ctx, light);
    return;
  }

  // What is already kept stays kept - it is counted in the total below, and
  // throwing it away to make room for this one would only move the problem.
  if(!_va && _keptVertices + total > maxKeptVertices()) {
    _stream(ctx, light);
    return;
  }
  if(_va && _keptVertices > maxKeptVertices()) {
    // more is kept than is allowed now, e.g. because the option that bounds
    // it has been lowered
    _keptVertices -= _va->getNumVertices();
    delete _va;
    _va = nullptr;
    _stream(ctx, light);
    return;
  }

  VertexArray *va = triangles(ctx);
  if(!va) return;
  _draw(ctx, va, light);
}

bool glyphList::_instanced(drawContext *ctx, bool light)
{
  if(!gmshUseShaders() || !glApi::haveInstancing()) return false;
  if(!glShader::available()) return false;

  ctx->updateGlyphTemplates();
  bool colors = !ctx->inPickColorMode();
  if(light) gmshLighting(true);
  gmshPushShaderState();
  glShader::setAlphaScale(gmshAlphaScaleFor(GL_POINTS));

  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    std::size_t n = _inst[k].size();
    if(!n) continue;
    const float *tq;
    const normal_type *tn;
    int num = 0;
    const float *tp = ctx->glyphTemplate(k, tq, tn, num);
    if(!tp || !num) continue;

    // pack them the way the card takes them, once
    if(_gpu[k].size() != n * glShader::GLYPH_STRIDE) {
      _gpu[k].resize(n * glShader::GLYPH_STRIDE);
      for(std::size_t g = 0; g < n; g++) {
        const instance &in = _inst[k][g];
        unsigned char *at = &_gpu[k][g * glShader::GLYPH_STRIDE];
        float *f = (float *)at;
        // the rows of the transform, so that placing a point is three dot
        // products
        for(int r = 0; r < 3; r++) {
          f[4 * r] = (float)in.m[r];
          f[4 * r + 1] = (float)in.m[3 + r];
          f[4 * r + 2] = (float)in.m[6 + r];
          f[4 * r + 3] = (float)in.m[9 + r];
        }
        memcpy(at + 48, &in.color, 4);
        memcpy(at + 52, in.param, 2 * sizeof(float));
      }
    }

    if(!glShader::drawGlyphs(tp, tq, num, &_gpu[k][0], (int)n,
                             k == GLYPH_CYLINDER, colors)) {
      gmshLighting(false);
      return false;
    }
  }
  gmshLighting(false);
  return true;
}

void glyphList::_draw(drawContext *ctx, VertexArray *va, bool light)
{
  if(!va || !va->getNumVertices()) return;
  bool normals = !ctx->inPickColorMode() && light && va->hasNormals();
  bool colors = !ctx->inPickColorMode() && va->hasColors();
  if(normals) gmshLighting(true);
  gmshBindVertexArray(va, normals, colors);
  drawVertexArray(va, GL_TRIANGLES);
  gmshUnbindArrays();
  gmshLighting(false);
}

// How many vertices a scratch array holds at a time. Big enough that what it
// costs to fill and hand over is spread over plenty of them, small enough that
// it is nothing to keep between frames.
static const int _chunkVertices = 1 << 18;

void glyphList::_stream(drawContext *ctx, bool light)
{
  // Too many to keep the triangles of, so they are expanded a batch at a time
  // into an array of a size that does not depend on how many there are, drawn,
  // and expanded over again. Nothing is kept, and the whole of it happens for
  // every frame - but it is still the arrays doing the drawing, which is what
  // the glyphs being collected in the first place buys.
  //
  // There is one of these for the whole program: only one list draws at a
  // time, and its buffer objects are worth holding on to between the batches
  // and between the frames.
  static VertexArray *scratch = nullptr;
  if(!scratch) scratch = new VertexArray(3, _chunkVertices / 3);

  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    std::size_t n = _inst[k].size();
    if(!n) continue;
    const float *tq;
    const normal_type *tn;
    int num = 0;
    ctx->glyphTemplate(k, tq, tn, num);
    if(!num) continue;
    std::size_t per = _chunkVertices / num;
    if(per < 1) per = 1;
    for(std::size_t first = 0; first < n; first += per) {
      std::size_t last = std::min(first + per, n);
      scratch->clearData();
      int at = scratch->addBlock((int)((last - first) * num));
      _expandRange(ctx, (glyphKind)k, first, last, scratch, at);
      _draw(ctx, scratch, light);
    }
  }
}

namespace glyphCache {
  typedef std::pair<const void *, int> key;
  static std::map<key, glyphList *> _lists;

  bool get(const void *owner, glyphSlot slot, const glyphToken &token,
           glyphList *&list)
  {
    auto it = _lists.find(key(owner, slot));
    if(it == _lists.end()) {
      list = new glyphList();
      _lists[key(owner, slot)] = list;
      list->setToken(token);
      return false;
    }
    list = it->second;
    if(list->filled() && list->token() == token) return true;
    list->clear();
    list->setToken(token);
    return false;
  }

  void clear(const void *owner)
  {
    for(int s = 0; s < GLYPH_NUMSLOTS; s++) {
      auto it = _lists.find(key(owner, s));
      if(it != _lists.end()) {
        delete it->second;
        _lists.erase(it);
      }
    }
  }

  void clearAll()
  {
    for(auto &p : _lists) delete p.second;
    _lists.clear();
  }
} // namespace glyphCache
