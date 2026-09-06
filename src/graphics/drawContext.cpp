// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include <cstring>
#include <stdio.h>
#include "GmshGlobal.h"
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "drawContext.h"
#include "glMatrix.h"
#include "glShader.h"
#include "Trackball.h"
#include "Context.h"
#include "Numeric.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewOptions.h"
#include "VertexArray.h"
#include "StringUtils.h"
#include "OS.h"
#include "gl2ps.h"

// the background image is still read with FLTK, which is the last thing this
// file asks of a widget toolkit
#if defined(HAVE_FLTK)
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#endif

#if defined(HAVE_POPPLER)
#include "gmshPopplerWrapper.h"
#endif

drawContextGlobal *drawContext::_global = nullptr;
void (*drawContext::drawGeomTransient)(void *) = nullptr;

void drawContext::setDrawGeomTransientFunction(void (*fct)(void *))
{
  drawGeomTransient = fct;
}

extern SPoint2 getGraph2dDataPointForTag(unsigned int);

bool drawContext::_pickColorActive = false;

drawContext::drawContext(drawTransform *transform)
  : _transform(transform), _highResolutionPixelFactor(1.), _pickColor(false)
{
  // initialize from temp values in global context
  for(int i = 0; i < 3; i++) {
    r[i] = CTX::instance()->tmpRotation[i];
    t[i] = CTX::instance()->tmpTranslation[i];
    s[i] = CTX::instance()->tmpScale[i];
  }
  for(int i = 0; i < 4; i++) {
    quaternion[i] = CTX::instance()->tmpQuaternion[i];
  }
  viewport[0] = viewport[1] = 0;
  viewport[2] = CTX::instance()->glSize[0];
  viewport[3] = CTX::instance()->glSize[1];

  render_mode = GMSH_RENDER;
  vxmin = vymin = vxmax = vymax = 0.;
  pixel_equiv_x = pixel_equiv_y = 0.;

  glMatrix::identity(_projection);
  glMatrix::identity(_modelBase);

  _pickCacheValid = _pickCacheMesh = _pickCachePost = _pickCacheElements = false;
  _pickCacheX = _pickCacheY = _pickCacheWidth = _pickCacheHeight = 0;

  _bgImageTexture = _bgImageW = _bgImageH = 0;

  _quadric = nullptr; // cannot create it here: needs valid opengl context
  _displayLists = 0;
}

drawContext::~drawContext() { invalidateQuadricsAndDisplayLists(); }

int drawContextGlobal::getFontAlign(const char *alignstr)
{
  if(alignstr) {
    if(!strcmp(alignstr, "BottomLeft") || !strcmp(alignstr, "Left") ||
       !strcmp(alignstr, "left"))
      return 0;
    else if(!strcmp(alignstr, "BottomCenter") || !strcmp(alignstr, "Center") ||
            !strcmp(alignstr, "center"))
      return 1;
    else if(!strcmp(alignstr, "BottomRight") || !strcmp(alignstr, "Right") ||
            !strcmp(alignstr, "right"))
      return 2;
    else if(!strcmp(alignstr, "TopLeft"))
      return 3;
    else if(!strcmp(alignstr, "TopCenter"))
      return 4;
    else if(!strcmp(alignstr, "TopRight"))
      return 5;
    else if(!strcmp(alignstr, "CenterLeft"))
      return 6;
    else if(!strcmp(alignstr, "CenterCenter"))
      return 7;
    else if(!strcmp(alignstr, "CenterRight"))
      return 8;
  }
  Msg::Error("Unknown font alignment \"%s\" (using \"Left\" instead)",
             alignstr);
  Msg::Info("Available font alignments:");
  Msg::Info("  \"Left\" (or \"BottomLeft\")");
  Msg::Info("  \"Center\" (or \"BottomCenter\")");
  Msg::Info("  \"Right\" (or \"BottomRight\")");
  Msg::Info("  \"TopLeft\"");
  Msg::Info("  \"TopCenter\"");
  Msg::Info("  \"TopRight\"");
  Msg::Info("  \"CenterLeft\"");
  Msg::Info("  \"CenterCenter\"");
  Msg::Info("  \"CenterRight\"");
  return 0;
}

drawContextGlobal *drawContext::global()
{
  if(!_global) _global = new drawContextGlobal(); // create dummy default
  return _global;
}

void drawContext::invalidateQuadricsAndDisplayLists()
{
  if(_quadric) {
    gluDeleteQuadric(_quadric);
    _quadric = nullptr;
  }
  if(_displayLists) {
    glDeleteLists(_displayLists, 3);
    _displayLists = 0;
  }
}

void drawContext::createQuadricsAndDisplayLists()
{
  if(!_quadric) _quadric = gluNewQuadric();
  if(!_quadric) {
    Msg::Error("Could not create quadric");
    return;
  }

  if(!_displayLists) _displayLists = glGenLists(3);
  if(!_displayLists) {
    Msg::Error("Could not generate display lists");
    return;
  }

  // display list 0 (sphere)
  glNewList(_displayLists + 0, GL_COMPILE);
  gluSphere(_quadric, 1., CTX::instance()->quadricSubdivisions,
            CTX::instance()->quadricSubdivisions);
  glEndList();

  // display list 1 (arrow). The two translations below are the one place where
  // a matrix operation is a command rather than state: they are recorded into
  // the list and replayed against whatever matrix is current when it is
  // called, which is not something gmshTranslate() can do, as it composes the
  // matrix here and now. They go when the display lists do - a core profile
  // has neither.
  glNewList(_displayLists + 1, GL_COMPILE);
  glTranslated(0., 0., CTX::instance()->arrowRelStemLength);
  if(CTX::instance()->arrowRelHeadRadius > 0 &&
     CTX::instance()->arrowRelStemLength < 1)
    gluCylinder(_quadric, CTX::instance()->arrowRelHeadRadius, 0.,
                (1. - CTX::instance()->arrowRelStemLength),
                CTX::instance()->quadricSubdivisions, 1);
  if(CTX::instance()->arrowRelHeadRadius > CTX::instance()->arrowRelStemRadius)
    gluDisk(_quadric, CTX::instance()->arrowRelStemRadius,
            CTX::instance()->arrowRelHeadRadius,
            CTX::instance()->quadricSubdivisions, 1);
  else
    gluDisk(_quadric, CTX::instance()->arrowRelHeadRadius,
            CTX::instance()->arrowRelStemRadius,
            CTX::instance()->quadricSubdivisions, 1);
  glTranslated(0., 0., -CTX::instance()->arrowRelStemLength);
  if(CTX::instance()->arrowRelStemRadius > 0 &&
     CTX::instance()->arrowRelStemLength > 0) {
    gluCylinder(_quadric, CTX::instance()->arrowRelStemRadius,
                CTX::instance()->arrowRelStemRadius,
                CTX::instance()->arrowRelStemLength,
                CTX::instance()->quadricSubdivisions, 1);
    gluDisk(_quadric, 0, CTX::instance()->arrowRelStemRadius,
            CTX::instance()->quadricSubdivisions, 1);
  }
  glEndList();

  // display list 2 (disk)
  glNewList(_displayLists + 2, GL_COMPILE);
  gluDisk(_quadric, 0, 1, CTX::instance()->quadricSubdivisions, 1);
  glEndList();
}

void drawContext::buildRotationMatrix()
{
  if(CTX::instance()->useTrackball) {
    build_rotmatrix(rot, quaternion);
    setEulerAnglesFromRotationMatrix();
  }
  else {
    double x = r[0] * M_PI / 180.;
    double y = r[1] * M_PI / 180.;
    double z = r[2] * M_PI / 180.;
    double A = cos(x);
    double B = sin(x);
    double C = cos(y);
    double D = sin(y);
    double E = cos(z);
    double F = sin(z);
    double AD = A * D;
    double BD = B * D;
    rot[0] = C * E;
    rot[1] = BD * E + A * F;
    rot[2] = -AD * E + B * F;
    rot[3] = 0.;
    rot[4] = -C * F;
    rot[5] = -BD * F + A * E;
    rot[6] = AD * F + B * E;
    rot[7] = 0.;
    rot[8] = D;
    rot[9] = -B * C;
    rot[10] = A * C;
    rot[11] = 0.;
    rot[12] = 0.;
    rot[13] = 0.;
    rot[14] = 0.;
    rot[15] = 1.;
    setQuaternionFromEulerAngles();
  }
}

void drawContext::addQuaternion(double p1x, double p1y, double p2x, double p2y)
{
  double quat[4];
  trackball(quat, p1x, p1y, p2x, p2y);
  add_quats(quat, quaternion, quaternion);
  if(CTX::instance()->camera) camera.rotate(quat);
}

void drawContext::addQuaternionFromAxisAndAngle(double axis[3], double angle)
{
  double a = angle * M_PI / 180.;
  double quat[4];
  axis_to_quat(axis, a, quat);
  add_quats(quat, quaternion, quaternion);
}

void drawContext::setQuaternion(double q0, double q1, double q2, double q3)
{
  quaternion[0] = q0;
  quaternion[1] = q1;
  quaternion[2] = q2;
  quaternion[3] = q3;
}

void drawContext::setQuaternionFromEulerAngles()
{
  double x = r[0] * M_PI / 180.;
  double y = r[1] * M_PI / 180.;
  double z = r[2] * M_PI / 180.;
  double xx[3] = {1., 0., 0.};
  double yy[3] = {0., 1., 0.};
  double zz[3] = {0., 0., 1.};
  double q1[4], q2[4], q3[4], tmp[4];
  axis_to_quat(xx, -x, q1);
  axis_to_quat(yy, -y, q2);
  axis_to_quat(zz, -z, q3);
  add_quats(q1, q2, tmp);
  add_quats(tmp, q3, quaternion);
}

void drawContext::setEulerAnglesFromRotationMatrix()
{
  r[1] = asin(rot[8]); // Calculate Y-axis angle
  double C = cos(r[1]);
  r[1] *= 180. / M_PI;
  if(fabs(C) > 0.005) { // Gimball lock?
    double tmpx = rot[10] / C; // No, so get X-axis angle
    double tmpy = -rot[9] / C;
    r[0] = atan2(tmpy, tmpx) * 180. / M_PI;
    tmpx = rot[0] / C; // Get Z-axis angle
    tmpy = -rot[4] / C;
    r[2] = atan2(tmpy, tmpx) * 180. / M_PI;
  }
  else { // Gimball lock has occurred
    r[0] = 0.; // Set X-axis angle to zero
    double tmpx = rot[5]; // And calculate Z-axis angle
    double tmpy = rot[1];
    r[2] = atan2(tmpy, tmpx) * 180. / M_PI;
  }
  // return only positive angles in [0,360]
  if(r[0] < 0.) r[0] += 360.;
  if(r[1] < 0.) r[1] += 360.;
  if(r[2] < 0.) r[2] += 360.;
}

static int needPolygonOffset()
{
  GModel *m = GModel::current();
  if(m->getMeshStatus() == 2 &&
     (CTX::instance()->mesh.surfaceEdges || CTX::instance()->geom.curves ||
      CTX::instance()->geom.surfaces))
    return 1;
  if(m->getMeshStatus() == 3 && (CTX::instance()->mesh.surfaceEdges ||
                                 CTX::instance()->mesh.volumeEdges))
    return 1;
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PViewOptions *opt = PView::list[i]->getOptions();
    if(opt->visible && opt->showElement) return 1;
  }
  return 0;
}

// is what is drawn next drawn with the shader pipeline?
static bool useShaders()
{
  return CTX::instance()->shaders && glShader::available();
}

static bool useVertexBufferObjects()
{
  // a core profile has no client arrays at all, so the shader pipeline has to
  // have the buffer objects whatever the option says
  if(useShaders()) return true;
  return CTX::instance()->vertexBufferObjects && glApi::haveBufferObjects();
}

// statistics on the data uploaded to the GPU since the last frame
static double vboBytes = 0., vboTime = 0.;

void deleteOrphanVertexArrayBuffers()
{
  if(vboBytes > 0.) {
    Msg::Debug("Uploaded %.1f Mb to buffer objects in %g s",
               vboBytes / 1024. / 1024., vboTime);
    vboBytes = vboTime = 0.;
  }

  if(VertexArray::vboToDelete.empty()) return;
  if(glApi::haveBufferObjects())
    glApi::DeleteBuffers((GLsizei)VertexArray::vboToDelete.size(),
                         &VertexArray::vboToDelete[0]);
  VertexArray::vboToDelete.clear();
}

// copy the arrays into buffer objects, if this has not been done yet or if the
// arrays have changed since
static void uploadVertexArray(VertexArray *va)
{
  unsigned int *id = va->getVboIds();
  if(id[0] && !va->getVboValid()) {
    // the context that owned these buffers is gone and took them with it: the
    // names do not designate anything any more
    id[0] = id[1] = id[2] = 0;
  }
  if(!id[0]) {
    glApi::GenBuffers(3, id);
    va->setVboValid();
    va->setVboDirty(true);
  }
  if(!va->getVboDirty()) return;

  double t1 = TimeOfDay();
  int n = va->getNumVertices();
  glApi::BindBuffer(GL_ARRAY_BUFFER, id[0]);
  glApi::BufferData(GL_ARRAY_BUFFER, n * 3 * sizeof(float),
                    n ? va->getVertexArray() : nullptr, GL_STATIC_DRAW);
  if(va->hasNormals()) {
    glApi::BindBuffer(GL_ARRAY_BUFFER, id[1]);
    glApi::BufferData(GL_ARRAY_BUFFER, n * 3 * sizeof(normal_type),
                      va->getNormalArray(), GL_STATIC_DRAW);
  }
  if(va->hasColors()) {
    glApi::BindBuffer(GL_ARRAY_BUFFER, id[2]);
    glApi::BufferData(GL_ARRAY_BUFFER, n * 4 * sizeof(unsigned char),
                      va->getColorArray(), GL_STATIC_DRAW);
  }
  va->setVboDirty(false);

  vboBytes += n * 3. * sizeof(float) +
              (va->hasNormals() ? n * 3. * sizeof(normal_type) : 0.) +
              (va->hasColors() ? n * 4. : 0.);
  vboTime += TimeOfDay() - t1;
}

const GLvoid *vaVertexPointer(VertexArray *va)
{
  if(!useVertexBufferObjects()) {
    // make sure a buffer left bound by a previous frame does not turn the
    // client-side pointer below into an offset
    if(glApi::haveBufferObjects()) glApi::BindBuffer(GL_ARRAY_BUFFER, 0);
    return va->getVertexArray();
  }
  uploadVertexArray(va);
  glApi::BindBuffer(GL_ARRAY_BUFFER, va->getVboIds()[0]);
  return nullptr;
}

const GLvoid *vaNormalPointer(VertexArray *va)
{
  if(!useVertexBufferObjects()) {
    // make sure a buffer left bound by a previous frame does not turn the
    // client-side pointer below into an offset
    if(glApi::haveBufferObjects()) glApi::BindBuffer(GL_ARRAY_BUFFER, 0);
    return va->getNormalArray();
  }
  uploadVertexArray(va);
  glApi::BindBuffer(GL_ARRAY_BUFFER, va->getVboIds()[1]);
  return nullptr;
}

const GLvoid *vaColorPointer(VertexArray *va)
{
  if(!useVertexBufferObjects()) {
    // make sure a buffer left bound by a previous frame does not turn the
    // client-side pointer below into an offset
    if(glApi::haveBufferObjects()) glApi::BindBuffer(GL_ARRAY_BUFFER, 0);
    return va->getColorArray();
  }
  uploadVertexArray(va);
  glApi::BindBuffer(GL_ARRAY_BUFFER, va->getVboIds()[2]);
  return nullptr;
}

// what the last bind left for the draw to use: the client arrays a caller
// holds itself have to be uploaded, and the count is only known at the draw
static const float *_clientVertices = nullptr;
static const unsigned char *_clientColors = nullptr;
static bool _boundColors = false;

void gmshBindVertexArray(VertexArray *va, bool normals, bool colors)
{
  _clientVertices = nullptr;
  _clientColors = nullptr;
  _boundColors = colors;

  if(useShaders()) {
    glApi::EnableVertexAttribArray(glShader::ATTRIB_VERTEX);
    glApi::VertexAttribPointer(glShader::ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE,
                               0, vaVertexPointer(va));
    if(normals) {
      glApi::EnableVertexAttribArray(glShader::ATTRIB_NORMAL);
      // the normals are stored as bytes, and are the unit vectors they were
      // when they went in: they have to be scaled back on the way out
      glApi::VertexAttribPointer(glShader::ATTRIB_NORMAL, 3, NORMAL_GLTYPE,
                                 GL_TRUE, 0, vaNormalPointer(va));
    }
    else {
      glApi::DisableVertexAttribArray(glShader::ATTRIB_NORMAL);
    }
    if(colors) {
      glApi::EnableVertexAttribArray(glShader::ATTRIB_COLOR);
      glApi::VertexAttribPointer(glShader::ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE,
                                 GL_TRUE, 0, vaColorPointer(va));
    }
    else {
      glApi::DisableVertexAttribArray(glShader::ATTRIB_COLOR);
    }
    return;
  }

  glVertexPointer(3, GL_FLOAT, 0, vaVertexPointer(va));
  glEnableClientState(GL_VERTEX_ARRAY);
  if(normals) {
    glNormalPointer(NORMAL_GLTYPE, 0, vaNormalPointer(va));
    glEnableClientState(GL_NORMAL_ARRAY);
  }
  else {
    glDisableClientState(GL_NORMAL_ARRAY);
  }
  if(colors) {
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, vaColorPointer(va));
    glEnableClientState(GL_COLOR_ARRAY);
  }
  else {
    glDisableClientState(GL_COLOR_ARRAY);
  }
}

void gmshBindArrays(const float *vertices, const unsigned char *colors)
{
  _boundColors = (colors != nullptr);

  if(useShaders()) {
    // kept for the draw, which is where the number of vertices is known and
    // the arrays can be uploaded
    _clientVertices = vertices;
    _clientColors = colors;
    return;
  }

  _clientVertices = nullptr;
  _clientColors = nullptr;
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glEnableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  if(colors) {
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);
    glEnableClientState(GL_COLOR_ARRAY);
  }
  else {
    glDisableClientState(GL_COLOR_ARRAY);
  }
}

void gmshUnbindArrays()
{
  _clientVertices = nullptr;
  _clientColors = nullptr;
  if(useShaders()) {
    glApi::DisableVertexAttribArray(glShader::ATTRIB_VERTEX);
    glApi::DisableVertexAttribArray(glShader::ATTRIB_NORMAL);
    glApi::DisableVertexAttribArray(glShader::ATTRIB_COLOR);
    return;
  }
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
}

// hand the program everything it needs that the fixed function pipeline kept
// as state of its own, and draw
void gmshDrawArrays(GLenum type, int count)
{
  if(count <= 0) return;

  if(useShaders()) {
    if(!glShader::use()) return;
    if(_clientVertices) {
      glShader::streamArrays(_clientVertices, _clientColors, count);
    }
    glShader::setColorArray(_boundColors);
    gmshPushShaderState();
  }

  glDrawArrays(type, 0, count);
}

void drawVertexArray(VertexArray *va, GLenum type)
{
  gmshDrawArrays(type, va->getNumVertices());

  if(useVertexBufferObjects()) glApi::BindBuffer(GL_ARRAY_BUFFER, 0);
}

// The section a clipping plane cuts out of a 3D element is part of the vertex
// arrays, so they have to be built again when a plane moves, or when the set of
// planes that clip a view changes. The planes can be moved from the clipping
// window, from a script or from the API, so notice it here rather than at every
// place that sets them
static void checkClipPlanesChanged()
{
  // While the user is dragging - a clipping plane, an option slider - the fast
  // representation is drawn, and the arrays are left as they are however many
  // times the scene is redrawn in between. The planes below are only remembered
  // once the change has been acted upon, so the first frame after the mouse is
  // released picks it up and rebuilds once
  if(drawContext::global()->mouseIsPressed()) return;

  static double planes[6][4] = {{0.}};
  static int capping = -1, whole = -1;
  static std::vector<int> clip;

  bool changed = (capping != CTX::instance()->clipCapping) ||
                 (whole != CTX::instance()->clipWholeElements);
  capping = CTX::instance()->clipCapping;
  whole = CTX::instance()->clipWholeElements;
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 4; j++)
      if(planes[i][j] != CTX::instance()->clipPlane[i][j]) {
        planes[i][j] = CTX::instance()->clipPlane[i][j];
        changed = true;
      }

#if defined(HAVE_POST)
  if(clip.size() != PView::list.size()) {
    clip.resize(PView::list.size(), -1);
    changed = true;
  }
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    int c = PView::list[i]->getOptions()->clip;
    if(clip[i] != c) {
      clip[i] = c;
      changed = true;
    }
  }
  if(!changed || !capping || whole) return;
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(PView::list[i]->getOptions()->clip) PView::list[i]->setChanged(true);
#else
  if(!changed || !capping || whole) return;
#endif
  if(CTX::instance()->mesh.clip && GModel::current())
    GModel::current()->clipPlanesChanged();
}

void drawContext::draw3d()
{
  checkClipPlanesChanged();

  deleteOrphanVertexArrayBuffers();

  // We can only create this when a valid opengl context exists. (It's cheap to
  // create so we just do it at each redraw: this makes it much simpler to deal
  // with option changes, e.g. arrow shape changes)
  createQuadricsAndDisplayLists();

  // We should only enable the polygon offset when there is a mix of lines and
  // polygons to be drawn; enabling it all the time can lead to very small but
  // annoying artifacts in the picture. Since there are so many ways in Gmsh to
  // combine polygons and lines (geometries + meshes + views...), we do our best
  // here to automatically detect if we should enable it. Note: the formula for
  // the offset is "offset = factor*DZ+r*units", where DZ is a measurement of
  // the change in depth relative to the screen area of the polygon, and r is
  // the smallest value that is guaranteed to produce a resolvable offset for a
  // given implementation.
  glPolygonOffset((float)CTX::instance()->polygonOffsetFactor,
                  (float)CTX::instance()->polygonOffsetUnits);
  if(CTX::instance()->polygonOffsetFactor ||
     CTX::instance()->polygonOffsetUnits)
    CTX::instance()->polygonOffset =
      CTX::instance()->polygonOffsetAlways ? 1 : needPolygonOffset();
  else
    CTX::instance()->polygonOffset = 0;

    // speedup drawing of textured fonts on cocoa mac version
#if defined(__APPLE__)
  std::size_t numStrings = GModel::current()->getNumVertices();
  if(CTX::instance()->mesh.nodeLabels)
    numStrings = std::max(numStrings, GModel::current()->getNumMeshVertices());
  if(CTX::instance()->mesh.lineLabels || CTX::instance()->mesh.surfaceLabels ||
     CTX::instance()->mesh.volumeLabels)
    numStrings = std::max(numStrings, GModel::current()->getNumMeshElements());
  numStrings *= 2;
  global()->reserveStringTextures(numStrings);
#endif

  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  initProjection();
  initRenderModel();

  if(!CTX::instance()->camera) initPosition(true);
  drawAxes();
  drawGeom();
  drawBackgroundImage(true);
  drawMesh();
  drawPost();
  // drawAxes();
  drawGraph2d(true);
}

void drawContext::draw2d()
{
  glDisable(GL_DEPTH_TEST);
  for(int i = 0; i < 6; i++) gmshClipPlaneOn(i, false);

  gmshMatrixMode(GMSH_PROJECTION);

  // in pixels, so we can draw some 3D glyphs, and with a shift that makes the
  // 2D primitives appear "in front" in GL2PS
  double px[16], front[16], m[16];
  glMatrix::ortho(viewport[0], viewport[2], viewport[1], viewport[3], -100.,
                  100., px);
  glMatrix::translate(0., 0.,
                      CTX::instance()->clipFactor > 1. ?
                        1. / CTX::instance()->clipFactor :
                        CTX::instance()->clipFactor,
                      front);
  glMatrix::multiply(px, front, m);
  gmshLoadMatrix(m);
  gmshMatrixMode(GMSH_MODELVIEW);

  gmshLoadIdentity();
  drawGraph2d(false);
  drawText2d();
  if(CTX::instance()->post.draw && !CTX::instance()->stereo) drawScales();
  if(CTX::instance()->smallAxes) drawSmallAxes();
}

void drawContext::drawBackgroundGradient()
{
  if(CTX::instance()->bgGradient == 1) { // vertical
    gmshBegin(GL_QUADS);
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.bg);
    gmshVertex2i(viewport[0], viewport[1]);
    gmshVertex2i(viewport[2], viewport[1]);
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.bgGrad);
    gmshVertex2i(viewport[2], viewport[3]);
    gmshVertex2i(viewport[0], viewport[3]);
    gmshEnd();
  }
  else if(CTX::instance()->bgGradient == 2) { // horizontal
    gmshBegin(GL_QUADS);
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.bg);
    gmshVertex2i(viewport[2], viewport[1]);
    gmshVertex2i(viewport[2], viewport[3]);
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.bgGrad);
    gmshVertex2i(viewport[0], viewport[3]);
    gmshVertex2i(viewport[0], viewport[1]);
    gmshEnd();
  }
  else if(CTX::instance()->bgGradient == 3) { // radial
    double cx = 0.5 * (viewport[0] + viewport[2]);
    double cy = 0.5 * (viewport[1] + viewport[3]);
    double r =
      0.5 * std::max(viewport[2] - viewport[0], viewport[3] - viewport[1]);
    gmshBegin(GL_TRIANGLE_FAN);
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.bgGrad);
    gmshVertex2d(cx, cy);
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.bg);
    gmshVertex2d(cx + r, cy);
    int ntheta = 36;
    for(int i = 1; i < ntheta + 1; i++) {
      double theta = i * 2 * M_PI / (double)ntheta;
      gmshVertex2d(cx + r * cos(theta), cy + r * sin(theta));
    }
    gmshEnd();
  }
}

void drawContext::invalidateBgImageTexture()
{
  if(_bgImageTexture) glDeleteTextures(1, &_bgImageTexture);
  _bgImageTexture = 0;
}

bool drawContext::generateTextureForImage(const std::string &name, int page,
                                          GLuint &imageTexture, GLuint &imageW,
                                          GLuint &imageH)
{
  if(StatFile(name)) {
    Msg::Error("Could not open file `%s'", name.c_str());
    return false;
  }

  std::string ext = SplitFileName(name)[2];
  if(ext == ".pdf" || ext == ".PDF") {
#if defined(HAVE_POPPLER)
    if(!imageTexture) {
      if(!gmshPopplerWrapper::instance()->loadFromFile(name)) {
        Msg::Error("Could not load PDF file '%s'", name.c_str());
        return false;
      }
    }
    gmshPopplerWrapper::instance()->setCurrentPage(page);
    imageTexture = gmshPopplerWrapper::instance()->getTextureForPage(300, 300);
    imageW = gmshPopplerWrapper::instance()->width();
    imageH = gmshPopplerWrapper::instance()->height();
#else
    Msg::Error("Gmsh must be compiled with Poppler support to load PDFs");
    return false;
#endif
  }
  else {
#if defined(HAVE_FLTK)
    if(!imageTexture) {
      Fl_RGB_Image *img = nullptr;
      if(ext == ".jpg" || ext == ".JPG" || ext == ".jpeg" || ext == ".JPEG")
        img = new Fl_JPEG_Image(name.c_str());
      else if(ext == ".png" || ext == ".PNG")
        img = new Fl_PNG_Image(name.c_str());
      if(!img) {
        Msg::Error("Could not load background image '%s'", name.c_str());
        return false;
      }
      Fl_RGB_Image *img2 = (Fl_RGB_Image *)img->copy(2048, 2048);
      glPixelStorei(GL_UNPACK_ROW_LENGTH, img2->w());
      glGenTextures(1, &imageTexture);
      glBindTexture(GL_TEXTURE_2D, imageTexture);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img2->w(), img2->h(), 0,
                   (img2->d() == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE,
                   img2->array);
      glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
      imageW = img->w();
      imageH = img->h();
      delete img;
      delete img2;
    }
#else
    Msg::Error("Gmsh must be compiled with FLTK support to load JPEGs or PNGs");
    return false;
#endif
  }
  return true;
}

void drawContext::drawBackgroundImage(bool threeD)
{
  if(CTX::instance()->bgImageFileName.empty() ||
     (CTX::instance()->bgImage3d && !threeD) ||
     (!CTX::instance()->bgImage3d && threeD))
    return;

  std::string name = FixRelativePath(GModel::current()->getFileName(),
                                     CTX::instance()->bgImageFileName);

  double x = CTX::instance()->bgImagePosition[0];
  double y = CTX::instance()->bgImagePosition[1];
  double w = CTX::instance()->bgImageSize[0];
  double h = CTX::instance()->bgImageSize[1];

  if(!generateTextureForImage(name, CTX::instance()->bgImagePage,
                              _bgImageTexture, _bgImageW, _bgImageH)) {
    CTX::instance()->bgImageFileName.clear();
    return;
  }

  if(!_bgImageTexture) return;

  if(w < 0 && h < 0) {
    w = viewport[2] - viewport[0];
    h = viewport[3] - viewport[1];
  }
  else if(w < 0 && h == 0) {
    w = viewport[2] - viewport[0];
    h = w * _bgImageH / _bgImageW;
  }
  else if(w < 0) {
    w = viewport[2] - viewport[0];
  }
  else if(w == 0 && h < 0) {
    h = viewport[3] - viewport[1];
    w = h * _bgImageW / _bgImageH;
  }
  else if(h < 0) {
    h = viewport[3] - viewport[1];
  }
  else if(w == 0 && h == 0) {
    w = _bgImageW;
    h = _bgImageH;
  }
  else if(h == 0) {
    h = w * _bgImageH / _bgImageW;
  }
  else if(w == 0) {
    w = h * _bgImageW / _bgImageH;
  }

  Msg::Debug("Background image: x=%g y=%g w=%g h=%g", x, y, w, h);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, _bgImageTexture);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  gmshBegin(GL_QUADS);
  if(threeD) {
    gmshTexCoord2f(1.0f, 1.0f);
    gmshVertex2d(x + w, y);
    gmshTexCoord2f(1.0f, 0.0f);
    gmshVertex2d(x + w, y + h);
    gmshTexCoord2f(0.0f, 0.0f);
    gmshVertex2d(x, y + h);
    gmshTexCoord2f(0.0f, 1.0f);
    gmshVertex2d(x, y);
  }
  else {
    int c = fix2dCoordinates(&x, &y); // y=0 now means top
    if(c & 1) x -= w / 2.;
    if(c & 2) y += h / 2.;
    if(x < viewport[0]) x = viewport[0];
    if(y < viewport[1]) y = viewport[1];
    gmshTexCoord2f(1.0f, 1.0f);
    gmshVertex2d(x + w, y - h);
    gmshTexCoord2f(1.0f, 0.0f);
    gmshVertex2d(x + w, y);
    gmshTexCoord2f(0.0f, 0.0f);
    gmshVertex2d(x, y);
    gmshTexCoord2f(0.0f, 1.0f);
    gmshVertex2d(x, y - h);
  }
  gmshEnd();
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_BLEND);
}

void drawContext::initProjection(int xpick, int ypick, int wpick, int hpick)
{
  double Va =
    (double)(viewport[3] - viewport[1]) / (double)(viewport[2] - viewport[0]);
  double Wa = (CTX::instance()->max[1] - CTX::instance()->min[1]) /
              (CTX::instance()->max[0] - CTX::instance()->min[0]);

  // compute the viewport in World coordinates (with margins)
  if(Va > Wa) {
    vxmin = CTX::instance()->min[0];
    vxmax = CTX::instance()->max[0];
    vymin = 0.5 * (CTX::instance()->min[1] + CTX::instance()->max[1] -
                   Va * (CTX::instance()->max[0] - CTX::instance()->min[0]));
    vymax = 0.5 * (CTX::instance()->min[1] + CTX::instance()->max[1] +
                   Va * (CTX::instance()->max[0] - CTX::instance()->min[0]));
  }
  else {
    vxmin = 0.5 * (CTX::instance()->min[0] + CTX::instance()->max[0] -
                   (CTX::instance()->max[1] - CTX::instance()->min[1]) / Va);
    vxmax = 0.5 * (CTX::instance()->min[0] + CTX::instance()->max[0] +
                   (CTX::instance()->max[1] - CTX::instance()->min[1]) / Va);
    vymin = CTX::instance()->min[1];
    vymax = CTX::instance()->max[1];
  }
  double fact = CTX::instance()->displayBorderFactor;
  double xborder = fact * (vxmax - vxmin), yborder = fact * (vymax - vymin);
  vxmin -= xborder;
  vxmax += xborder;
  vymin -= yborder;
  vymax += yborder;

  // Put the origin of World coordinates at center of viewport
  // (this is necessary for the scaling to be applied at center of viewport
  // instead of at initial position of center of gravity)
  vxmin -= CTX::instance()->cg[0];
  vxmax -= CTX::instance()->cg[0];
  vymin -= CTX::instance()->cg[1];
  vymax -= CTX::instance()->cg[1];

  // store what one pixel represents in world coordinates
  pixel_equiv_x = (vxmax - vxmin) / (viewport[2] - viewport[0]);
  pixel_equiv_y = (vymax - vymin) / (viewport[3] - viewport[1]);

  // no initial translation of the model
  t_init[0] = t_init[1] = t_init[2] = 0.;

  // set up the near and far clipping planes so that the box is large enough to
  // manipulate the model and zoom, but not too big (otherwise the z-buffer
  // resolution e.g. with Mesa can become insufficient)
  double zmax =
    std::max(fabs(CTX::instance()->min[2]), fabs(CTX::instance()->max[2]));
  if(zmax < CTX::instance()->lc) zmax = CTX::instance()->lc;

  if(CTX::instance()->camera) { // if we use the camera mode
    glDisable(GL_DEPTH_TEST);
    gmshPushMatrix();
    gmshLoadIdentity();
    double w = (double)viewport[2];
    double h = (double)viewport[3];
    double ratio = w / h;
    double dx = 1.5 * tan(camera.radians) * w * ratio;
    double dy = 1.5 * tan(camera.radians) * w;
    double dz = -w * 1.25;
    gmshBegin(GL_QUADS);
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.bg);
    gmshVertex3i((int)-dx, (int)-dy, (int)dz);
    gmshVertex3i((int)dx, (int)-dy, (int)dz);
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.bgGrad);
    gmshVertex3i((int)dx, (int)dy, (int)dz);
    gmshVertex3i((int)-dx, (int)dy, (int)dz);
    gmshEnd();
    gmshPopMatrix();
    glEnable(GL_DEPTH_TEST);
  }
  else if(!CTX::instance()->camera) { // if not in camera mode

    double clip_near, clip_far;
    if(CTX::instance()->ortho) {
      clip_near = -zmax * s[2] * CTX::instance()->clipFactor;
      clip_far = -clip_near;
    }
    else {
      clip_near = 0.75 * CTX::instance()->clipFactor * zmax;
      clip_far = 75. * CTX::instance()->clipFactor * zmax;
    }
    // setup projection matrix
    gmshMatrixMode(GMSH_PROJECTION);

    // restrict picking to a rectangular region around xpick,ypick
    double pick[16];
    glMatrix::identity(pick);
    if(render_mode == GMSH_SELECT)
      glMatrix::pickRegion(xpick, viewport[3] - ypick, wpick, hpick, viewport,
                           pick);

    // draw background if not in selection mode
    if(render_mode != GMSH_SELECT &&
       (CTX::instance()->bgGradient ||
        CTX::instance()->bgImageFileName.size()) &&
       (!CTX::instance()->printing || CTX::instance()->print.background)) {
      glDisable(GL_DEPTH_TEST);
      gmshPushMatrix();
      // the z values and the translation are only needed for GL2PS, which does
      // not understand "no depth test" (hence we must make sure that we draw
      // the background behind the rest of the scene)
      double bg[16], back[16], m[16];
      glMatrix::ortho(viewport[0], viewport[2], viewport[1], viewport[3],
                      clip_near, clip_far, bg);
      glMatrix::translate(0., 0., -0.99 * clip_far, back);
      glMatrix::multiply(bg, back, m);
      gmshLoadMatrix(m);
      drawBackgroundGradient();
      // hack for GL2PS (to make sure that the image is in front of the
      // gradient)
      glMatrix::translate(0., 0., -0.98 * clip_far, back);
      glMatrix::multiply(bg, back, m);
      gmshLoadMatrix(m);
      drawBackgroundImage(false);
      gmshPopMatrix();
      glEnable(GL_DEPTH_TEST);
    }

    double projection[16];
    if(CTX::instance()->ortho) {
      glMatrix::ortho(vxmin, vxmax, vymin, vymax, clip_near, clip_far,
                      projection);
      glMatrix::multiply(pick, projection, _projection);
      gmshLoadMatrix(_projection);
      gmshMatrixMode(GMSH_MODELVIEW);
      glMatrix::identity(_modelBase);
      gmshLoadMatrix(_modelBase);
    }
    else {
      // recenter the model such that the perspective is always at the center of
      // gravity (we should maybe add an option to choose this, as we do for the
      // rotation center)
      t_init[0] = CTX::instance()->cg[0];
      t_init[1] = CTX::instance()->cg[1];
      vxmin -= t_init[0];
      vxmax -= t_init[0];
      vymin -= t_init[1];
      vymax -= t_init[1];
      glMatrix::frustum(vxmin, vxmax, vymin, vymax, clip_near, clip_far,
                        projection);
      glMatrix::multiply(pick, projection, _projection);
      gmshLoadMatrix(_projection);
      gmshMatrixMode(GMSH_MODELVIEW);
      double coef = (clip_far / clip_near) / 3.;
      double tr[16], sc[16];
      glMatrix::translate(-coef * t_init[0], -coef * t_init[1],
                          -coef * clip_near, tr);
      glMatrix::scale(coef, coef, coef, sc);
      glMatrix::multiply(tr, sc, _modelBase);
      gmshLoadMatrix(_modelBase);
    }
  }
}

void drawContext::initRenderModel()
{
  gmshPushMatrix();
  gmshLoadIdentity();
  gmshScale(s[0], s[1], s[2]);
  gmshTranslate(t[0], t[1], t[2]);

  for(int i = 0; i < 6; i++) {
    if(CTX::instance()->light[i]) {
      GLfloat position[4] = {(GLfloat)CTX::instance()->lightPosition[i][0],
                             (GLfloat)CTX::instance()->lightPosition[i][1],
                             (GLfloat)CTX::instance()->lightPosition[i][2],
                             (GLfloat)CTX::instance()->lightPosition[i][3]};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_POSITION, position);
      // OpenGL puts the position through the modelview matrix that is current
      // here, which is the scale and the translation alone: the lights follow
      // neither the rotation nor the camera. The shader is handed the result
      // of that same transform, so that it lights the scene the same way.
      double pos[4] = {position[0], position[1], position[2], position[3]};
      double eye[4];
      glMatrix::transform(gmshMatrix(GMSH_MODELVIEW), pos, eye);

      GLfloat r = (GLfloat)(
        CTX::instance()->unpackRed(CTX::instance()->color.ambientLight[i]) /
        255.);
      GLfloat g = (GLfloat)(
        CTX::instance()->unpackGreen(CTX::instance()->color.ambientLight[i]) /
        255.);
      GLfloat b = (GLfloat)(
        CTX::instance()->unpackBlue(CTX::instance()->color.ambientLight[i]) /
        255.);
      GLfloat ambient[4] = {r, g, b, 1.0F};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_AMBIENT, ambient);

      r = (GLfloat)(
        CTX::instance()->unpackRed(CTX::instance()->color.diffuseLight[i]) /
        255.);
      g = (GLfloat)(
        CTX::instance()->unpackGreen(CTX::instance()->color.diffuseLight[i]) /
        255.);
      b = (GLfloat)(
        CTX::instance()->unpackBlue(CTX::instance()->color.diffuseLight[i]) /
        255.);
      GLfloat diffuse[4] = {r, g, b, 1.0F};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_DIFFUSE, diffuse);

      r = (GLfloat)(
        CTX::instance()->unpackRed(CTX::instance()->color.specularLight[i]) /
        255.);
      g = (GLfloat)(
        CTX::instance()->unpackGreen(CTX::instance()->color.specularLight[i]) /
        255.);
      b = (GLfloat)(
        CTX::instance()->unpackBlue(CTX::instance()->color.specularLight[i]) /
        255.);
      GLfloat specular[4] = {r, g, b, 1.0F};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_SPECULAR, specular);

      glEnable((GLenum)(GL_LIGHT0 + i));
      glShader::setLight(i, eye, ambient, diffuse, specular);
    }
    else {
      glDisable((GLenum)(GL_LIGHT0 + i));
      glShader::setLightOff(i);
    }
  }

  gmshPopMatrix();

  // ambient and diffuse material colors track the current colour automatically
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
  // "white"-only specular material reflection color
  GLfloat spec[4] = {(GLfloat)CTX::instance()->shine,
                     (GLfloat)CTX::instance()->shine,
                     (GLfloat)CTX::instance()->shine, 1.0F};
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
  // specular exponent in [0,128] (larger means more "focused"
  // reflection)
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,
              (GLfloat)CTX::instance()->shineExponent);

  glShadeModel(GL_SMOOTH);

  // Normalize the normals automatically. Using glEnable(GL_RESCALE_NORMAL)
  // instead of glEnable(GL_NORMALIZE) (since we initially specify unit normals)
  // is more efficient, but will only work with isotropic scalings (and we allow
  // anistotropic scalings in myZoom...). Note that GL_RESCALE_NORMAL is only
  // available in GL_VERSION_1_2.
#if defined(WIN32)
  glEnable(GL_NORMALIZE);
#else
  glEnable(GL_RESCALE_NORMAL);
#endif

  // lighting is enabled/disabled for each particular primitive later
  gmshLighting(false);
}

void drawContext::initPosition(bool saveMatrices)
{
  // NB: Those operations are applied to the model in the view coordinates
  // (in opposite order), on top of the modelview left by initProjection()
  const double *rc = CTX::instance()->rotationCenterCg ?
                       CTX::instance()->cg :
                       CTX::instance()->rotationCenter;
  double sc[16], tr[16], toCenter[16], fromCenter[16], a[16], b[16];
  glMatrix::scale(s[0], s[1], s[2], sc);
  glMatrix::translate(t[0] - CTX::instance()->cg[0],
                      t[1] - CTX::instance()->cg[1],
                      t[2] - CTX::instance()->cg[2], tr);
  glMatrix::translate(rc[0], rc[1], rc[2], toCenter);
  glMatrix::translate(-rc[0], -rc[1], -rc[2], fromCenter);

  buildRotationMatrix();

  glMatrix::multiply(_modelBase, sc, a);
  glMatrix::multiply(a, tr, b);
  glMatrix::multiply(b, toCenter, a);
  glMatrix::multiply(a, rot, b);
  glMatrix::multiply(b, fromCenter, a);
  gmshMatrixMode(GMSH_MODELVIEW);
  gmshLoadMatrix(a);

  // store the projection and modelview matrices at this precise moment (so that
  // we can use them at any later time, even if the context has changed, i.e.,
  // even if we are out of draw())
  if(saveMatrices) {
    for(int i = 0; i < 16; i++) {
      proj[i] = _projection[i];
      model[i] = a[i];
    }
  }

  for(int i = 0; i < 6; i++)
    gmshClipPlane(i, CTX::instance()->clipPlane[i]);
}

// Takes a cursor position in window coordinates and returns the line (given by
// a point and a unit direction vector), in real space, that corresponds to that
// cursor position
void drawContext::unproject(double winx, double winy, double p[3], double d[3])
{
  // get true pixels
  double fact = highResolutionPixelFactor();
  winx *= fact;
  winy *= fact;

  GLint glvp[4];
  glGetIntegerv(GL_VIEWPORT, glvp);
  int vp[4] = {glvp[0], glvp[1], glvp[2], glvp[3]};

  winy = vp[3] - winy;

  // we use the stored model and proj matrices instead of directly
  // getGetDouble'ing the matrices since unproject can be called in or after
  // draw2d
  double onNear[3] = {0., 0., 0.}, onFar[3] = {0., 0., 0.};
  double win[3] = {winx, winy, 0.};
  if(!glMatrix::unProject(win, model, proj, vp, onNear))
    Msg::Warning("unproject1 failed");
  win[2] = 1.;
  if(!glMatrix::unProject(win, model, proj, vp, onFar))
    Msg::Warning("unproject2 failed");

  p[0] = onNear[0];
  p[1] = onNear[1];
  p[2] = onNear[2];
  d[0] = onFar[0] - onNear[0];
  d[1] = onFar[1] - onNear[1];
  d[2] = onFar[2] - onNear[2];
  double len = sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
  d[0] /= len;
  d[1] /= len;
  d[2] /= len;
}

void drawContext::viewport2World(double vp[3], double xyz[3])
{
  GLint glvp[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, glvp);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  int viewport[4] = {glvp[0], glvp[1], glvp[2], glvp[3]};
  glMatrix::unProject(vp, model, proj, viewport, xyz);
}

void drawContext::world2Viewport(double xyz[3], double vp[3])
{
  GLint glvp[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, glvp);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  int viewport[4] = {glvp[0], glvp[1], glvp[2], glvp[3]};
  glMatrix::project(xyz, model, proj, viewport, vp);
}

// returns the element at a given position in a vertex array (element pointers
// are not always stored: returning 0 is not an error)
static MElement *getElement(GEntity *e, int va_type, int index)
{
  switch(va_type) {
  case 2:
    if(e->va_lines && index < e->va_lines->getNumElementPointers())
      return *e->va_lines->getElementPointerArray(index);
    break;
  case 3:
    if(e->va_triangles && index < e->va_triangles->getNumElementPointers())
      return *e->va_triangles->getElementPointerArray(index);
    break;
  }
  return nullptr;
}

void drawContext::setPickColor(int type, int ient, int type2, int ient2)
{
  if(!_pickColor) return;
  _pickObjects.push_back(pickObject(type, ient, type2, ient2));
  // 0 is the background: 24 bits give 16 million pickable objects per pass
  std::size_t id = _pickObjects.size() - 1;
  GLubyte c[4] = {(GLubyte)(id & 0xff), (GLubyte)((id >> 8) & 0xff),
                  (GLubyte)((id >> 16) & 0xff), 255};
  glDisableClientState(GL_COLOR_ARRAY);
  gmshPickColor4ubv(c);

  // The selection buffer reported every primitive in the picking frustum, so a
  // point or a curve hidden behind a surface could still be selected. Depth
  // testing would hide them here, so give each dimension its own depth range,
  // the lower ones in front: this keeps the depth order inside a dimension
  // while letting a point be picked through a surface.
  int d = (type < 0) ? 4 : (type > 4 ? 4 : type);
  glDepthRange(0.2 * d, 0.2 * d + 0.2);
}

void drawContext::unsetPickColor()
{
  if(!_pickColor) return;
  // 0 is the background: what is drawn now belongs to no pickable object
  GLubyte c[4] = {0, 0, 0, 255};
  glDisableClientState(GL_COLOR_ARRAY);
  gmshPickColor4ubv(c);
}

// Side of the region, in real pixels, that a picking pass draws and keeps
// around the point that was asked for. Big enough that the pointer usually
// stays inside it while hovering, small enough that drawing it costs a
// fraction of what the whole window would.
static const int PICK_CACHE_SIZE = 512;

// Draw a region of the window with every pickable object in the flat colour
// that encodes it, and keep the result: the picks that follow are then lookups
// in that image, so hovering does not redraw the scene on every mouse move.
bool drawContext::_fillPickCache(bool mesh, bool post, int fx, int fy, int fw,
                                 int fh)
{
  if(fw < 1 || fh < 1) return false;

  _pickObjects.clear();
  _pickObjects.push_back(pickObject()); // 0: background
  _pickColor = _pickColorActive = true;
  render_mode = drawContext::GMSH_SELECT;

  bool oldLighting = gmshLightingEnabled();
  GLboolean oldBlend = glIsEnabled(GL_BLEND);
  GLfloat oldClear[4];
  glGetFloatv(GL_COLOR_CLEAR_VALUE, oldClear);

  glDrawBuffer(GL_BACK);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  gmshLighting(false);
  glDisable(GL_BLEND);
  glShadeModel(GL_FLAT);
  // only rasterise the region the image covers
  glEnable(GL_SCISSOR_TEST);
  glScissor(fx, fy, fw, fh);
  glClearColor(0., 0., 0., 0.);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  gmshPushMatrix();
  initProjection();
  initPosition(false);
  drawGeom();
  if(mesh) drawMesh();
  if(post) drawPost();
  drawGraph2d(true);

  // 2d stuff, drawn in pixel coordinates
  // as in draw2d(): the 2D overlay is painted on top, in the order it is drawn,
  // so the depth test has to go. Leaving it on would make the graph frame and
  // the axes, drawn before the data points and in the depth range that was
  // current at the time, hide the points from the picking pass.
  glDisable(GL_DEPTH_TEST);
  for(int i = 0; i < 6; i++) gmshClipPlaneOn(i, false);
  gmshMatrixMode(GMSH_PROJECTION);
  double px2d[16];
  glMatrix::ortho(viewport[0], viewport[2], viewport[1], viewport[3], -100.,
                  100., px2d);
  gmshLoadMatrix(px2d);
  gmshMatrixMode(GMSH_MODELVIEW);
  gmshLoadIdentity();
  drawGraph2d(false);
  drawText2d();
  gmshPopMatrix();

  _pickCache.assign((std::size_t)4 * fw * fh, 0);
  _pickCacheDepth.assign((std::size_t)fw * fh, 1.f);
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glReadBuffer(GL_BACK);
  glReadPixels(fx, fy, fw, fh, GL_RGBA, GL_UNSIGNED_BYTE, &_pickCache[0]);
  glReadPixels(fx, fy, fw, fh, GL_DEPTH_COMPONENT, GL_FLOAT,
               &_pickCacheDepth[0]);

  glDisable(GL_SCISSOR_TEST);
  glDepthRange(0., 1.);
  glClearColor(oldClear[0], oldClear[1], oldClear[2], oldClear[3]);
  if(oldLighting) gmshLighting(true);
  if(oldBlend) glEnable(GL_BLEND);
  glShadeModel(GL_SMOOTH);
  _pickColor = _pickColorActive = false;
  render_mode = drawContext::GMSH_RENDER;

  _pickCacheX = fx;
  _pickCacheY = fy;
  _pickCacheWidth = fw;
  _pickCacheHeight = fh;
  _pickCacheMesh = mesh;
  _pickCachePost = post;
  _pickCacheElements = CTX::instance()->pickElements ? true : false;
  _pickCacheValid = true;
  Msg::Debug("Colour picking: drew %d objects into a %dx%d image",
             (int)_pickObjects.size(), fw, fh);
  return true;
}

// Find the objects whose colour shows up in the picking rectangle, and return
// them ordered by depth.
bool drawContext::_selectColor(int type, bool multiple, bool mesh, bool post,
                               int x, int y, int w, int h,
                               std::vector<GVertex *> &vertices,
                               std::vector<GEdge *> &edges,
                               std::vector<GFace *> &faces,
                               std::vector<GRegion *> &regions,
                               std::vector<MElement *> &elements,
                               std::vector<SPoint2> &points,
                               std::vector<PView *> &views)
{
  if(w < 1) w = 1;
  if(h < 1) h = 1;
  // the rectangle is given by its centre
  int x0 = x - w / 2, y0 = (viewport[3] - y) - h / 2;
  if(x0 < viewport[0]) x0 = viewport[0];
  if(y0 < viewport[1]) y0 = viewport[1];
  if(x0 + w > viewport[2]) w = viewport[2] - x0;
  if(y0 + h > viewport[3]) h = viewport[3] - y0;
  if(w < 1 || h < 1) return false;

  // the viewport is in logical points, but the image is in real pixels, which
  // differ on a high resolution display
  double hr = highResolutionPixelFactor();
  int fx0 = (int)(x0 * hr), fy0 = (int)(y0 * hr);
  int fw = (int)(w * hr), fh = (int)(h * hr);
  if(fw < 1) fw = 1;
  if(fh < 1) fh = 1;
  int winW = (int)((viewport[2] - viewport[0]) * hr);
  int winH = (int)((viewport[3] - viewport[1]) * hr);

  bool pickElements = CTX::instance()->pickElements ? true : false;
  bool inside = _pickCacheValid && fx0 >= _pickCacheX && fy0 >= _pickCacheY &&
                fx0 + fw <= _pickCacheX + _pickCacheWidth &&
                fy0 + fh <= _pickCacheY + _pickCacheHeight;
  if(!inside || _pickCacheMesh != mesh || _pickCachePost != post ||
     _pickCacheElements != pickElements) {
    // a region around the query, big enough that the pointer has to travel a
    // long way before the image has to be drawn again
    int cw = std::min(winW, PICK_CACHE_SIZE), ch = std::min(winH, PICK_CACHE_SIZE);
    if(cw < fw) cw = fw;
    if(ch < fh) ch = fh;
    int cx = fx0 + fw / 2 - cw / 2, cy = fy0 + fh / 2 - ch / 2;
    if(cx < 0) cx = 0;
    if(cy < 0) cy = 0;
    if(cx + cw > winW) cx = winW - cw;
    if(cy + ch > winH) cy = winH - ch;
    if(cx < 0 || cy < 0) return false;
    if(!_fillPickCache(mesh, post, cx, cy, cw, ch)) return false;
  }

  const unsigned char *pixels = &_pickCache[0];
  const float *depths = &_pickCacheDepth[0];
  const int stride = _pickCacheWidth;
  fx0 -= _pickCacheX;
  fy0 -= _pickCacheY;
  if(fx0 < 0 || fy0 < 0 || fx0 + fw > _pickCacheWidth ||
     fy0 + fh > _pickCacheHeight)
    return false;

  // gather the objects that show up, keeping the smallest depth for each. The
  // 2D overlay is painted on top of the scene without depth testing, so it
  // wrote no depth of its own and the buffer holds whatever is underneath it:
  // rank it in front, which is where it is drawn.
  std::map<std::size_t, float> found;
  for(int r = 0; r < fh; r++) {
    for(int c = 0; c < fw; c++) {
      std::size_t i = (std::size_t)(fy0 + r) * stride + (fx0 + c);
      std::size_t id = (std::size_t)pixels[4 * i] |
                       ((std::size_t)pixels[4 * i + 1] << 8) |
                       ((std::size_t)pixels[4 * i + 2] << 16);
      if(!id || id >= _pickObjects.size()) continue;
      float z = (_pickObjects[id].type >= 4) ? -1.f : depths[i];
      auto it = found.find(id);
      if(it == found.end() || z < it->second) found[id] = z;
    }
  }
  Msg::Debug("Colour picking: %d found in a %dx%d rectangle",
             (int)found.size(), fw, fh);
  if(found.empty()) return false;

  // order by depth, and prefer the entities of lowest dimension, as the
  // selection buffer based code did
  std::vector<std::pair<float, std::size_t> > sorted;
  for(auto &p : found) sorted.push_back(std::make_pair(p.second, p.first));
  std::sort(sorted.begin(), sorted.end());

  int typmin = 10;
  for(auto &p : sorted) typmin = std::min(typmin, _pickObjects[p.second].type);

  GModel *m = GModel::current();
  for(auto &p : sorted) {
    const pickObject &o = _pickObjects[p.second];
    if(o.type < 4 &&
       !((type == ENT_ALL) || (type == ENT_NONE && o.type == typmin) ||
         (type == ENT_POINT && o.type == 0) ||
         (type == ENT_CURVE && o.type == 1) ||
         (type == ENT_SURFACE && o.type == 2) ||
         (type == ENT_VOLUME && o.type == 3)))
      continue;
    switch(o.type) {
    case 0: {
      GVertex *v = m->getVertexByTag(o.ient);
      if(v) vertices.push_back(v);
      break;
    }
    case 1: {
      GEdge *e = m->getEdgeByTag(o.ient);
      if(e) {
        MElement *ele = getElement(e, o.type2, o.ient2);
        if(ele)
          elements.push_back(ele);
        else
          edges.push_back(e);
      }
      break;
    }
    case 2: {
      GFace *f = m->getFaceByTag(o.ient);
      if(f) {
        MElement *ele = getElement(f, o.type2, o.ient2);
        if(ele)
          elements.push_back(ele);
        else
          faces.push_back(f);
      }
      break;
    }
    case 3: {
      GRegion *r = m->getRegionByTag(o.ient);
      if(r) {
        MElement *ele = getElement(r, o.type2, o.ient2);
        if(ele)
          elements.push_back(ele);
        else
          regions.push_back(r);
      }
      break;
    }
    case 4: {
      points.push_back(getGraph2dDataPointForTag(o.ient));
      break;
    }
    case 5: {
      if(o.ient >= 0 && o.ient < (int)PView::list.size())
        views.push_back(PView::list[o.ient]);
      break;
    }
    default: break;
    }
    if(!multiple && (vertices.size() || edges.size() || faces.size() ||
                     regions.size() || elements.size() || points.size() ||
                     views.size()))
      return true;
  }

  return (vertices.size() || edges.size() || faces.size() || regions.size() ||
          elements.size() || points.size() || views.size());
}

bool drawContext::select(int type, bool multiple, bool mesh, bool post, int x,
                         int y, int w, int h, std::vector<GVertex *> &vertices,
                         std::vector<GEdge *> &edges,
                         std::vector<GFace *> &faces,
                         std::vector<GRegion *> &regions,
                         std::vector<MElement *> &elements,
                         std::vector<SPoint2> &points,
                         std::vector<PView *> &views)
{
  vertices.clear();
  edges.clear();
  faces.clear();
  regions.clear();
  elements.clear();
  points.clear();
  views.clear();

  return _selectColor(type, multiple, mesh, post, x, y, w, h, vertices, edges,
                      faces, regions, elements, points, views);
}

void drawContext::recenterForRotationCenterChange(SPoint3 newRotationCenter)
{
  // Recompute model translation so that the view is not changed
  SPoint3 &p = newRotationCenter;
  double vp[3], xyz[3] = {p.x(), p.y(), p.z()};
  glMatrix::project(xyz, model, proj, viewport, vp);
  double wnr[3]; // look at mousePosition::recenter()
  const double &width = viewport[2];
  const double &height = viewport[3];
  wnr[0] =
    (vxmin + vp[0] / width * (vxmax - vxmin)) / s[0] - t[0] + t_init[0] / s[0];
  wnr[1] =
    (vymin + vp[1] / height * (vymax - vymin)) / s[1] - t[1] + t_init[1] / s[1];
  t[0] += wnr[0] + CTX::instance()->cg[0] - p.x();
  t[1] += wnr[1] + CTX::instance()->cg[1] - p.y();
}
