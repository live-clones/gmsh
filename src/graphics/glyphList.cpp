// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <cstring>
#include <map>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "OwnerCache.h"
#include "glyphList.h"
#include "glImmediate.h"
#include "glMatrix.h"
#include "drawContext.h"
#include "glShader.h"
#include "glApi.h"
#include "VertexArray.h"
#include "Numeric.h"
#include "Context.h"

#if defined(_OPENMP)
#include <omp.h>
#endif

// what all the lists together keep, in vertices (the bound is global, as a
// model has one list per entity)
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
  for(int i = 0; i < 3; i++) {
    delete _rec[i];
    _rec[i] = nullptr;
  }
  _filled = false;
}

void glyphList::recordBegin()
{
  for(int i = 0; i < 3; i++) {
    delete _rec[i];
    _rec[i] = new VertexArray(i + 1, 100);
  }
  gmshRecordBegin(_rec[0], _rec[1], _rec[2]);
}

void glyphList::recordEnd()
{
  gmshRecordEnd();
  for(int i = 0; i < 3; i++) _rec[i]->finalize();
}

std::size_t glyphList::size() const
{
  std::size_t n = 0;
  for(int k = 0; k < GLYPH_NUMKINDS; k++) n += _inst[k].size();
  for(int i = 0; i < 3; i++)
    if(_rec[i]) n += _rec[i]->getNumVertices();
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

  double vdir[3] = {dx / length, dy / length, dz / length};

  // translate, then scale, then rotate, applied to the point from the right
  double t[16], sc[16], r[16], a[16], m[16];
  glMatrix::translate(x, y, z, t);
  glMatrix::scale(length, length, length, sc);
  glMatrix::rotateZTo(vdir, r);
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

  double vdir[3] = {dx / length, dy / length, dz / length};

  // the length is in the transform, the radii are parameters
  double t[16], r[16], sc[16], a[16], m[16];
  glMatrix::translate(x[0], y[0], z[0], t);
  glMatrix::rotateZTo(vdir, r);
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
  // expand a run of glyphs of one kind into a vertex array from the vertex
  // first; thread safe, as everything it reads is read only
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
      // the normals follow the inverse transpose of the transform; for a
      // rotation with uniform scaling (a sphere, an arrow) that is the
      // rotation itself, and without rotation the template's normals can be
      // copied as they are
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
          double c[9], det = glMatrix::cofactors(m, c), d = det ? 1. / det : 1.;
          for(int i = 0; i < 9; i++) n[i] = c[i] * d;
        }
      }

      // a cylinder is the one shape whose corners are not the template's:
      // the radii widen it along its length and its side normal leans by as
      // much, both computed from the cosine and sine of each corner's angle
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
        // no rotation: the template's encoded normals are the glyph's
        memcpy(nrm, tn, 3 * num * sizeof(normal_type));
      }
      else {
        for(int v = 0; v < num; v++) {
          const float *q = &tq[3 * v];
          // the normal before the transform, leaning by the taper over the
          // length the transform gives
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
  int version = ctx->glyphTemplatesVersion();
  if(_va && _vaVersion != version) {
    // the shapes have changed (subdivisions, arrow proportions)
    _keptVertices -= _va->getNumVertices();
    delete _va;
    _va = nullptr;
  }
  if(_va) return _va;
  if(!size()) return nullptr;
  _vaVersion = version;

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

  // each thread writes a range of its own
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

// how many vertices it is worth keeping; past this the glyphs are expanded
// a batch at a time for every frame, which is slower but takes no memory
// (60000 spheres are 13 million vertices, about half a gigabyte with the
// buffer objects). Set by General.GraphicsCacheSize.
static long maxKeptVertices()
{
  return (long)(CTX::instance()->graphicsCacheMB() * 1024. * 1024. / 38.);
}

void glyphList::draw(drawContext *ctx, bool light)
{
  if(!size()) return;

  // pending immediate mode primitives come first, and the backends below
  // bind attributes of their own
  gmshFlushImmediate();

  // what was recorded: in its own colours but for a picking pass, the
  // triangles lit as asked
  for(int i = 0; i < 3; i++) {
    VertexArray *va = _rec[i];
    if(!va || !va->getNumVertices()) continue;
    gmshDrawVertexArray(va, (i == 0) ? GL_POINTS : (i == 1) ? GL_LINES :
                                                              GL_TRIANGLES,
                        ((i == 2 && light) ? GMSH_DRAW_LIGHT : 0) |
                          GMSH_DRAW_COLORS);
  }
  bool instances = false;
  for(int k = 0; k < GLYPH_NUMKINDS; k++)
    if(_inst[k].size()) instances = true;
  if(!instances) return;

  ctx->updateGlyphTemplates();

  // instanced drawing needs none of what follows
  if(_instanced(ctx, light)) return;

  // a list nobody keeps is refilled for the next frame anyway: do not keep
  // its triangles either
  if(!filled()) {
    _stream(ctx, light);
    return;
  }

  long total = 0;
  for(int k = 0; k < GLYPH_NUMKINDS; k++) {
    const float *tq;
    const normal_type *tn;
    int num = 0;
    if(_inst[k].size()) ctx->glyphTemplate(k, tq, tn, num);
    total += (long)num * (long)_inst[k].size();
  }

  // what is already kept stays kept
  if(!_va && _keptVertices + total > maxKeptVertices()) {
    _stream(ctx, light);
    return;
  }
  if(_va && _keptVertices > maxKeptVertices()) {
    // more is kept than allowed (e.g. the option was lowered)
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
        // the rows of the transform: placing a point is three dot products
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
  gmshDrawVertexArray(va, GL_TRIANGLES,
                      (light ? GMSH_DRAW_LIGHT : 0) | GMSH_DRAW_COLORS);
}

// how many vertices a scratch array holds at a time
static const int _chunkVertices = 1 << 18;

void glyphList::_stream(drawContext *ctx, bool light)
{
  // too many to keep: expand them a batch at a time into a scratch array of
  // fixed size, drawn and refilled. One scratch array for the whole program,
  // as only one list draws at a time and its buffer objects are worth
  // keeping.
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
  // the lists of an owner, one per slot
  struct slots {
    glyphList *list[GLYPH_NUMSLOTS] = {};
    slots() = default;
    slots(const slots &) = delete;
    ~slots()
    {
      for(auto l : list) delete l;
    }
  };
  static OwnerCache<slots> _lists;

  bool get(const void *owner, glyphSlot slot, const glyphToken &token,
           glyphList *&list)
  {
    glyphList *&l = _lists[owner].list[slot];
    if(!l) {
      l = new glyphList();
      l->setToken(token);
      list = l;
      return false;
    }
    list = l;
    if(list->filled() && list->token() == token) return true;
    list->clear();
    list->setToken(token);
    return false;
  }

  void clear(const void *owner) { _lists.erase(owner); }

  void clearAll() { _lists.clear(); }
} // namespace glyphCache
