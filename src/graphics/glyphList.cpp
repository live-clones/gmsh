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
#include "VertexArray.h"
#include "Numeric.h"
#include "Context.h"
#include "OS.h"

#if defined(_OPENMP)
#include <omp.h>
#endif

void glyphList::clear()
{
  for(int k = 0; k < GLYPH_NUMKINDS; k++)
    std::vector<instance>().swap(_inst[k]);
  if(_va) delete _va;
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

      for(int v = 0; v < num; v++) {
        const float *p = &tp[3 * v];
        xyz[3 * v] = (float)(m[0] * p[0] + m[3] * p[1] + m[6] * p[2] + m[9]);
        xyz[3 * v + 1] =
          (float)(m[1] * p[0] + m[4] * p[1] + m[7] * p[2] + m[10]);
        xyz[3 * v + 2] =
          (float)(m[2] * p[0] + m[5] * p[1] + m[8] * p[2] + m[11]);
        memcpy(&col[4 * v], &in.color, 4);
      }
      if(same) {
        // nothing turns them: the template's are the ones of this glyph, and
        // they are already encoded
        memcpy(nrm, tn, 3 * num * sizeof(normal_type));
      }
      else {
        for(int v = 0; v < num; v++) {
          const float *q = &tq[3 * v];
          double nx = n[0] * q[0] + n[3] * q[1] + n[6] * q[2];
          double ny = n[1] * q[0] + n[4] * q[1] + n[7] * q[2];
          double nz = n[2] * q[0] + n[5] * q[1] + n[8] * q[2];
          if(!unit) {
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

  int nthreads = CTX::instance()->numThreads;
  if(nthreads <= 0) nthreads = 1;
  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    std::size_t n = _inst[k].size();
    if(!n || !num[k]) continue;
    // The glyphs are independent of one another and each of them writes a
    // range of its own, so the range is shared out and nothing has to be put
    // back together afterwards.
    int nt = (n < 2000) ? 1 : nthreads;
    if((std::size_t)nt > n) nt = (int)n;
#if defined(_OPENMP)
#pragma omp parallel for num_threads(nt) schedule(static, 1) if(nt > 1)
#endif
    for(int t = 0; t < nt; t++) {
      std::size_t from = n * t / nt, to = n * (t + 1) / nt;
      expand(ctx, (glyphKind)k, _inst[k], from, to, _va,
             at + (int)(from * num[k]));
    }
    at += (int)(n * num[k]);
  }
  _va->finalize();
  return _va;
}

// How many triangles it is worth keeping. Past this the glyphs are drawn one
// at a time instead, which is what was done before there was a list at all -
// slower, but it costs nothing to keep.
//
// What is being traded: sixty thousand spheres are thirteen million vertices,
// which take about half a gigabyte - nineteen bytes here and as many again in
// the buffer object the graphics card is handed - and draw in nine
// milliseconds a frame instead of ninety-three. Ten times faster for half a
// gigabyte is worth it once; it is not worth it ten times over, hence a bound
// that is a fraction of the machine and a number both.
static long maxKeptVertices()
{
  double mb = TotalRam() / 32.;
  if(mb > 1024.) mb = 1024.;
  if(mb < 64.) mb = 64.;
  return (long)(mb * 1024. * 1024. / 38.);
}

void glyphList::draw(drawContext *ctx, bool light)
{
  if(!size()) return;

  ctx->updateGlyphTemplates();
  long total = 0;
  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    const float *tq;
    const normal_type *tn;
    int num = 0;
    if(_inst[k].size()) ctx->glyphTemplate(k, tq, tn, num);
    total += (long)num * (long)_inst[k].size();
  }

  if(total > maxKeptVertices()) {
    // Too many to keep the triangles of: draw them one at a time, which is
    // what was done before there was a list at all. Collecting them was not
    // wasted - it is where they go and what colour they are, which is what
    // walking the model to find them costs.
    if(light) gmshLighting(true);
    for(int k = 0; k < GLYPH_NUMKINDS; k++) {
      for(std::size_t g = 0; g < _inst[k].size(); g++) {
        const double *im = _inst[k][g].m;
        double m[16] = {im[0], im[1], im[2],  0., im[3],  im[4],  im[5],  0.,
                        im[6], im[7], im[8],  0., im[9],  im[10], im[11], 1.};
        ctx->drawGlyph(k, m, _inst[k][g].color);
      }
    }
    gmshLighting(false);
    return;
  }

  VertexArray *va = triangles(ctx);
  if(!va) return;
  bool normals = !ctx->inPickColorMode() && light && va->hasNormals();
  bool colors = !ctx->inPickColorMode() && va->hasColors();
  if(normals) gmshLighting(true);
  gmshBindVertexArray(va, normals, colors);
  drawVertexArray(va, GL_TRIANGLES);
  gmshUnbindArrays();
  gmshLighting(false);
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
