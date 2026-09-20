// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdio>
#include <unordered_map>
#include "drawContextFltkQueued.h"
#include "glImmediate.h"
#include "glShader.h"
#include "VertexArray.h"

namespace {

  // The atlas: pages of kSize x kSize pixels of one channel (the size OpenGL
  // ES 3 guarantees, 4 MB), as many as General.GraphicsCacheSize allows,
  // made when they are needed. Each string sits in a
  // cell of a shelf, with a pixel of blank around it so that the linear
  // filtering of a quad does not pick up its neighbours; a string wider than
  // a page is cut into several cells. When the pages are full, everything is
  // forgotten and the atlas starts again from the strings that come next.
  const int kSize = 2048;

  struct cell {
    int page, x, y, w, h;
  };
  struct entry {
    std::vector<cell> cells;
    int below;
  };
  struct shelf {
    int y, h, x;
  };

  class atlas {
    std::vector<unsigned int> _textures;
    std::vector<std::vector<shelf> > _shelves;
    std::vector<int> _top;
    std::unordered_map<std::string, entry> _entries;
    // the context generation (the textures are shared by all the windows,
    // see VertexArray::vboContext) and the pipeline the pages were made for:
    // one channel in alpha for the fixed function one, in red for shaders
    unsigned int _context = 0;
    bool _shaders = false;

    bool _newPage()
    {
      int pages = (int)(CTX::instance()->graphicsCacheMB() / 4.);
      if((int)_textures.size() >= std::max(1, pages)) return false;
      unsigned int id;
      glGenTextures(1, &id);
      glBindTexture(GL_TEXTURE_2D, id);
      // left undefined: a cell is always filled with the blank around it,
      // which is all the filtering of its quad reads
      glTexImage2D(GL_TEXTURE_2D, 0, _shaders ? GL_R8 : GL_ALPHA, kSize, kSize,
                   0, _shaders ? GL_RED : GL_ALPHA, GL_UNSIGNED_BYTE, nullptr);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      _textures.push_back(id);
      _shelves.push_back(std::vector<shelf>());
      _top.push_back(0);
      return true;
    }
    // room for w x h pixels and the blank around them, in the last page
    bool _place(int w, int h, cell &c)
    {
      int aw = w + 2, ah = h + 2;
      for(int pass = 0; pass < 2; pass++) {
        if(_textures.empty() || pass) {
          if(!_newPage()) return false;
        }
        int p = (int)_textures.size() - 1;
        std::vector<shelf> &s = _shelves[p];
        // a shelf of about that height with room left, or a new one
        shelf *found = nullptr;
        for(auto &sh : s) {
          if(sh.h >= ah && sh.h <= ah + ah / 4 && sh.x + aw <= kSize) {
            found = &sh;
            break;
          }
        }
        if(!found && _top[p] + ah <= kSize) {
          s.push_back({_top[p], ah, 0});
          _top[p] += ah;
          found = &s.back();
        }
        if(!found) continue;
        c = {p, found->x + 1, found->y + 1, w, h};
        found->x += aw;
        return true;
      }
      return false;
    }

  public:
    unsigned int texture(int page) { return _textures[page]; }
    int pages() { return (int)_textures.size(); }
    // the pages are kept, empty
    void clear()
    {
      for(std::size_t p = 0; p < _shelves.size(); p++) {
        _shelves[p].clear();
        _top[p] = 0;
      }
      if(_textures.size()) {
        // start again from the first page
        _shelves.resize(1);
        _top.resize(1);
        if(_textures.size() > 1)
          glDeleteTextures((GLsizei)_textures.size() - 1, &_textures[1]);
        _textures.resize(1);
      }
      _entries.clear();
    }
    void check(bool shaders)
    {
      if(_context == VertexArray::vboContext && _shaders == shaders) return;
      // textures of a context that is gone are forgotten, not deleted
      if(_context == VertexArray::vboContext && _textures.size())
        glDeleteTextures((GLsizei)_textures.size(), _textures.data());
      _textures.clear();
      _shelves.clear();
      _top.clear();
      _entries.clear();
      _context = VertexArray::vboContext;
      _shaders = shaders;
    }
    const entry *find(const std::string &key)
    {
      auto it = _entries.find(key);
      return (it == _entries.end()) ? nullptr : &it->second;
    }
    // cells for a string of w x h pixels, or nothing if the atlas is full
    const entry *insert(const std::string &key, int w, int h, int below)
    {
      entry e;
      e.below = below;
      for(int x = 0; x < w || !x; x += kSize - 2) {
        cell c;
        if(!_place(std::min(w - x, kSize - 2), h, c)) return nullptr;
        e.cells.push_back(c);
      }
      return &(_entries[key] = e);
    }
  };

  atlas _atlas;

  // a cell to fill from what the engine rasterised
  struct pending {
    const drawContextFltkQueued::element *e;
    drawContextFltkQueued::extent ext;
    cell c;
    int shift;
  };
  std::vector<pending> _pending;

} // namespace

void drawContextFltkQueued::setFont(int fontid, int fontsize)
{
  drawContextFltk::setFont(fontid, fontsize);
  _currentFontId = fontid;
  _currentFontSize = fontsize;
}

void drawContextFltkQueued::drawString(const char *str)
{
  GLfloat pos[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
  double win[3] = {pos[0], pos[1], pos[2]};
  drawString(str, win);
}

// the position and colour are passed in, as a core profile has neither a
// raster position nor a current colour to query
void drawContextFltkQueued::drawString(const char *str, const double win[3])
{
  const unsigned char *c = gmshCurrentColor();
  _queue.push_back({str, (float)win[0], (float)win[1], (float)win[2],
                    c[0] / 255.f, c[1] / 255.f, c[2] / 255.f, c[3] / 255.f,
                    _currentFontId, _currentFontSize, stringHalo(),
                    glIsEnabled(GL_DEPTH_TEST) ? true : false});
}

// Rasterise the pending cells, packed in rows of an image of the width of a
// page, and copy each into its page. The image is drawn and copied in pieces
// of at most a page.
void drawContextFltkQueued::_upload(double f)
{
  std::size_t i = 0;
  while(i < _pending.size()) {
    std::vector<slot> slots;
    std::vector<const pending *> which;
    int x = 0, y = 0, rowH = 0;
    for(; i < _pending.size(); i++) {
      const pending &p = _pending[i];
      int aw = p.c.w + 2, ah = p.c.h + 2;
      if(x + aw > kSize) {
        x = 0;
        y += rowH;
        rowH = 0;
      }
      if(y + ah > kSize) break;
      slots.push_back({p.e, p.ext, x + 1, y + 1, p.c.w, p.c.h, p.shift});
      which.push_back(&p);
      x += aw;
      rowH = std::max(rowH, ah);
    }
    int h = y + rowH;
    std::vector<unsigned char> image(kSize * h, 0);
    rasterise(slots, f, kSize, h, image.data());
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, kSize);
    for(std::size_t k = 0; k < slots.size(); k++) {
      const cell &c = which[k]->c;
      // the cell and the blank around it
      glBindTexture(GL_TEXTURE_2D, _atlas.texture(c.page));
      glPixelStorei(GL_UNPACK_SKIP_PIXELS, slots[k].x - 1);
      glPixelStorei(GL_UNPACK_SKIP_ROWS, slots[k].y - 1);
      glTexSubImage2D(GL_TEXTURE_2D, 0, c.x - 1, c.y - 1, c.w + 2, c.h + 2,
                      gmshUseShaders() ? GL_RED : GL_ALPHA, GL_UNSIGNED_BYTE,
                      image.data());
    }
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
    glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
  }
  _pending.clear();
}

void drawContextFltkQueued::flushString()
{
  if(_queue.empty()) return;

  // everything below is in true pixels, and the strings are rasterised at
  // that scale so that they are sharp on a high resolution screen: the
  // window's scale, or the picture's being printed
  double f = drawContext::global()->pixelFactor();
  bool shaders = gmshUseShaders();
  // measuring the strings sets their fonts: the caller's comes back
  int fontId = _currentFontId, fontSize = _currentFontSize;
  _atlas.check(shaders);

  // setup matrices: the whole window, in the true pixels the positions are
  // given in
  int matrixMode = gmshMatrixMode();
  gmshMatrixMode(GMSH_PROJECTION);
  gmshPushMatrix();
  gmshLoadIdentity();
  gmshMatrixMode(GMSH_MODELVIEW);
  gmshPushMatrix();
  gmshLoadIdentity();
  GLint vp[4];
  glGetIntegerv(GL_VIEWPORT, vp);
  gmshScale(2. / vp[2], 2. / vp[3], 1.);
  gmshTranslate(-vp[2] / 2., -vp[3] / 2., 0.);

  bool wasLit = gmshLightingEnabled();
  // the colour is set per string below: what the caller had comes back
  const unsigned char *cc = gmshCurrentColor();
  unsigned char savedColor[4] = {cc[0], cc[1], cc[2], cc[3]};
  unsigned int bg = CTX::instance()->color.bg;
  float bgf[3] = {CTX::instance()->unpackRed(bg) / 255.f,
                  CTX::instance()->unpackGreen(bg) / 255.f,
                  CTX::instance()->unpackBlue(bg) / 255.f};
  // the state changed here is put back afterwards: through the attribute
  // stack with the fixed function pipeline, by hand with the shader one. The
  // transparency pass keeps its own blending.
  GLboolean wasDepth = glIsEnabled(GL_DEPTH_TEST);
  GLboolean wasBlend = glIsEnabled(GL_BLEND);
  bool ownBlend = !glShader::transparentPass();
  if(!shaders) {
    // glPopAttrib() does not restore the lighting we remember ourselves
    glPushAttrib(GL_ENABLE_BIT | GL_TEXTURE_BIT | GL_COLOR_BUFFER_BIT);
  }
  GLboolean wasMask = GL_TRUE;
  GLint wasFunc = GL_LESS;
  glGetBooleanv(GL_DEPTH_WRITEMASK, &wasMask);
  glGetIntegerv(GL_DEPTH_FUNC, &wasFunc);
  // the quads below are in window coordinates: the clipping planes, which
  // are in the coordinates of the scene, would cut them at random
  bool wasClip[6];
  for(int i = 0; i < 6; i++) {
    wasClip[i] = gmshClipPlaneEnabled(i);
    if(wasClip[i]) gmshClipPlaneOn(i, false);
  }
  gmshLighting(false);
  glDisable(GL_DEPTH_TEST);
  if(ownBlend) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  }

  // the strings in [start, end), found in the atlas: the strings of the scene
  // first, depth tested, then the 2D overlay on top of everything, page by
  // page
  std::vector<const entry *> found(_queue.size(), nullptr);
  auto draw = [&](std::size_t start, std::size_t end) {
    float halo[12][2];
    for(int pass = 0; pass < 2; pass++) {
      bool depth = (pass == 0);
      bool any = false;
      for(std::size_t i = start; i < end; i++)
        if(_queue[i].depth == depth) any = true;
      if(!any) continue;
      if(depth) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        // a string does not hide the strings drawn after it
        glDepthMask(GL_FALSE);
      }
      else
        glDisable(GL_DEPTH_TEST);
      for(int page = 0; page < _atlas.pages(); page++) {
        gmshTexture(_atlas.texture(page));
        for(std::size_t i = start; i < end; i++) {
          const element &e = _queue[i];
          const entry *en = found[i];
          if(e.depth != depth || !en) continue;
          // the depth of the point the string is anchored to, in the [-1, 1]
          // the identity projection expects, a little towards the eye so that
          // a label is not eaten by the surface it names
          float z = 2.f * e.z - 1.f - 2.e-3f;
          // the string, and before it, if it has a halo, copies of it around
          // it in the background colour
          int nh = e.halo ? drawContextGlobal::stringHaloOffsets(halo) : 0;
          float x0 = e.x;
          for(const cell &c : en->cells) {
            if(c.page == page) {
              float s0 = c.x / (float)kSize, s1 = (c.x + c.w) / (float)kSize;
              float t0 = c.y / (float)kSize, t1 = (c.y + c.h) / (float)kSize;
              for(int k = 0; k <= nh; k++) {
                float x = x0, y = e.y - en->below;
                if(k < nh) {
                  x += halo[k][0];
                  y += halo[k][1];
                  gmshColor4f(bgf[0], bgf[1], bgf[2], e.a);
                }
                else
                  gmshColor4f(e.r, e.g, e.b, e.a);
                gmshBegin(GL_QUADS);
                gmshTexCoord2f(s0, t0);
                gmshVertex3f(x, y + c.h, z);
                gmshTexCoord2f(s1, t0);
                gmshVertex3f(x + c.w, y + c.h, z);
                gmshTexCoord2f(s1, t1);
                gmshVertex3f(x + c.w, y, z);
                gmshTexCoord2f(s0, t1);
                gmshVertex3f(x, y, z);
                gmshEnd();
              }
            }
            x0 += c.w;
          }
        }
        // whatever is waiting was collected to be drawn through this page
        gmshFlushImmediate();
      }
    }
    // the pages are bound directly when filled
    gmshTexture(0);
  };

  // the strings not in the atlas are added to it, and rasterised together;
  // if it is full, what is found so far is drawn and it starts again
  std::size_t start = 0;
  char prefix[64];
  for(std::size_t i = 0; i < _queue.size(); i++) {
    const element &e = _queue[i];
    snprintf(prefix, sizeof(prefix), "%c%d %d %g ", engine(), e.fontId,
             e.fontSize, f);
    std::string key = prefix + e.text;
    const entry *en = _atlas.find(key);
    if(!en) {
      extent ext = measure(e, f);
      en = _atlas.insert(key, ext.w, ext.h, ext.below);
      if(!en) {
        _upload(f);
        draw(start, i);
        _atlas.clear();
        start = i;
        // a string larger than the whole atlas is not drawn
        en = _atlas.insert(key, ext.w, ext.h, ext.below);
      }
      if(en) {
        int shift = 0;
        for(const cell &c : en->cells) {
          _pending.push_back({&e, ext, c, shift});
          shift += c.w;
        }
      }
    }
    found[i] = en;
  }
  _upload(f);
  draw(start, _queue.size());

  glDepthMask(wasMask);
  glDepthFunc(wasFunc);
  if(!shaders)
    glPopAttrib();
  else {
    if(wasDepth) glEnable(GL_DEPTH_TEST);
    if(ownBlend && !wasBlend) glDisable(GL_BLEND);
  }
  gmshLighting(wasLit);
  for(int i = 0; i < 6; i++)
    if(wasClip[i]) gmshClipPlaneOn(i, true);
  gmshColor4ubv(savedColor);

  // reset original matrices
  gmshPopMatrix(); // GL_MODELVIEW
  gmshMatrixMode(GMSH_PROJECTION);
  gmshPopMatrix();
  gmshMatrixMode(matrixMode);
  _queue.clear();
  if(fontId >= 0) {
    _currentFontId = -1;
    setFont(fontId, fontSize);
  }
}
