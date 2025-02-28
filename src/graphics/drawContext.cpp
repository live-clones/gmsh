// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include <stdio.h>
#include "GmshGlobal.h"
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "drawContext.h"
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

#if defined(HAVE_FLTK)
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/gl.h>
#include "openglWindow.h"
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

drawContext::drawContext(openglWindow *window, drawTransform *transform)
  : _transform(transform), _openglWindow(window)
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

  _bgImageTexture = _bgImageW = _bgImageH = 0;

  _quadric = nullptr; // cannot create it here: needs valid opengl context
  _displayLists = 0;
}

drawContext::~drawContext() { invalidateQuadricsAndDisplayLists(); }

double drawContext::highResolutionPixelFactor()
{
  // this must be dynamic: the high resolution can change when a window is moved
  // across displays
#if defined(HAVE_FLTK)
  if(_openglWindow && _openglWindow->w()) {
    return (double)_openglWindow->pixel_w() / (double)_openglWindow->w();
  }
#endif
  return 1.0;
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

  // display list 1 (arrow)
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

void drawContext::draw3d()
{
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
#if defined(HAVE_FLTK) && defined(__APPLE__)
  std::size_t numStrings = GModel::current()->getNumVertices();
  if(CTX::instance()->mesh.nodeLabels)
    numStrings = std::max(numStrings, GModel::current()->getNumMeshVertices());
  if(CTX::instance()->mesh.lineLabels || CTX::instance()->mesh.surfaceLabels ||
     CTX::instance()->mesh.volumeLabels)
    numStrings = std::max(numStrings, GModel::current()->getNumMeshElements());
  numStrings *= 2;
  if(gl_texture_pile_height() < numStrings) gl_texture_pile_height(numStrings);
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
  for(int i = 0; i < 6; i++) glDisable((GLenum)(GL_CLIP_PLANE0 + i));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho((double)viewport[0], (double)viewport[2], (double)viewport[1],
          (double)viewport[3], -100.,
          100.); // in pixels, so we can draw some 3D glyphs

  // hack to make the 2D primitives appear "in front" in GL2PS
  glTranslated(0., 0.,
               CTX::instance()->clipFactor > 1. ?
                 1. / CTX::instance()->clipFactor :
                 CTX::instance()->clipFactor);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  drawGraph2d(false);
  drawText2d();
  if(CTX::instance()->post.draw && !CTX::instance()->stereo) drawScales();
  if(CTX::instance()->smallAxes) drawSmallAxes();
}

void drawContext::drawBackgroundGradient()
{
  if(CTX::instance()->bgGradient == 1) { // vertical
    glBegin(GL_QUADS);
    glColor4ubv((GLubyte *)&CTX::instance()->color.bg);
    glVertex2i(viewport[0], viewport[1]);
    glVertex2i(viewport[2], viewport[1]);
    glColor4ubv((GLubyte *)&CTX::instance()->color.bgGrad);
    glVertex2i(viewport[2], viewport[3]);
    glVertex2i(viewport[0], viewport[3]);
    glEnd();
  }
  else if(CTX::instance()->bgGradient == 2) { // horizontal
    glBegin(GL_QUADS);
    glColor4ubv((GLubyte *)&CTX::instance()->color.bg);
    glVertex2i(viewport[2], viewport[1]);
    glVertex2i(viewport[2], viewport[3]);
    glColor4ubv((GLubyte *)&CTX::instance()->color.bgGrad);
    glVertex2i(viewport[0], viewport[3]);
    glVertex2i(viewport[0], viewport[1]);
    glEnd();
  }
  else if(CTX::instance()->bgGradient == 3) { // radial
    double cx = 0.5 * (viewport[0] + viewport[2]);
    double cy = 0.5 * (viewport[1] + viewport[3]);
    double r =
      0.5 * std::max(viewport[2] - viewport[0], viewport[3] - viewport[1]);
    glBegin(GL_TRIANGLE_FAN);
    glColor4ubv((GLubyte *)&CTX::instance()->color.bgGrad);
    glVertex2d(cx, cy);
    glColor4ubv((GLubyte *)&CTX::instance()->color.bg);
    glVertex2d(cx + r, cy);
    int ntheta = 36;
    for(int i = 1; i < ntheta + 1; i++) {
      double theta = i * 2 * M_PI / (double)ntheta;
      glVertex2d(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
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
  glBegin(GL_QUADS);
  if(threeD) {
    glTexCoord2f(1.0f, 1.0f);
    glVertex2d(x + w, y);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2d(x + w, y + h);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2d(x, y + h);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2d(x, y);
  }
  else {
    int c = fix2dCoordinates(&x, &y); // y=0 now means top
    if(c & 1) x -= w / 2.;
    if(c & 2) y += h / 2.;
    if(x < viewport[0]) x = viewport[0];
    if(y < viewport[1]) y = viewport[1];
    glTexCoord2f(1.0f, 1.0f);
    glVertex2d(x + w, y - h);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2d(x + w, y);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2d(x, y);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2d(x, y - h);
  }
  glEnd();
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
    glPushMatrix();
    glLoadIdentity();
    double w = (double)viewport[2];
    double h = (double)viewport[3];
    double ratio = w / h;
    double dx = 1.5 * tan(camera.radians) * w * ratio;
    double dy = 1.5 * tan(camera.radians) * w;
    double dz = -w * 1.25;
    glBegin(GL_QUADS);
    glColor4ubv((GLubyte *)&CTX::instance()->color.bg);
    glVertex3i((int)-dx, (int)-dy, (int)dz);
    glVertex3i((int)dx, (int)-dy, (int)dz);
    glColor4ubv((GLubyte *)&CTX::instance()->color.bgGrad);
    glVertex3i((int)dx, (int)dy, (int)dz);
    glVertex3i((int)-dx, (int)dy, (int)dz);
    glEnd();
    glPopMatrix();
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // restrict picking to a rectangular region around xpick,ypick
    if(render_mode == GMSH_SELECT)
      gluPickMatrix((GLdouble)xpick, (GLdouble)(viewport[3] - ypick),
                    (GLdouble)wpick, (GLdouble)hpick, (GLint *)viewport);

    // draw background if not in selection mode
    if(render_mode != GMSH_SELECT &&
       (CTX::instance()->bgGradient ||
        CTX::instance()->bgImageFileName.size()) &&
       (!CTX::instance()->printing || CTX::instance()->print.background)) {
      glDisable(GL_DEPTH_TEST);
      glPushMatrix();
      glLoadIdentity();
      // the z values and the translation are only needed for GL2PS, which does
      // not understand "no depth test" (hence we must make sure that we draw
      // the background behind the rest of the scene)
      glOrtho((double)viewport[0], (double)viewport[2], (double)viewport[1],
              (double)viewport[3], clip_near, clip_far);
      glTranslated(0., 0., -0.99 * clip_far);
      drawBackgroundGradient();
      // hack for GL2PS (to make sure that the image is in front of the
      // gradient)
      glTranslated(0., 0., 0.01 * clip_far);
      drawBackgroundImage(false);
      glPopMatrix();
      glEnable(GL_DEPTH_TEST);
    }

    if(CTX::instance()->ortho) {
      glOrtho(vxmin, vxmax, vymin, vymax, clip_near, clip_far);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
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
      glFrustum(vxmin, vxmax, vymin, vymax, clip_near, clip_far);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      double coef = (clip_far / clip_near) / 3.;
      glTranslated(-coef * t_init[0], -coef * t_init[1], -coef * clip_near);
      glScaled(coef, coef, coef);
    }
  }
}

void drawContext::initRenderModel()
{
  glPushMatrix();
  glLoadIdentity();
  glScaled(s[0], s[1], s[2]);
  glTranslated(t[0], t[1], t[2]);

  for(int i = 0; i < 6; i++) {
    if(CTX::instance()->light[i]) {
      GLfloat position[4] = {(GLfloat)CTX::instance()->lightPosition[i][0],
                             (GLfloat)CTX::instance()->lightPosition[i][1],
                             (GLfloat)CTX::instance()->lightPosition[i][2],
                             (GLfloat)CTX::instance()->lightPosition[i][3]};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_POSITION, position);

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
    }
    else {
      glDisable((GLenum)(GL_LIGHT0 + i));
    }
  }

  glPopMatrix();

  // ambient and diffuse material colors track glColor automatically
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
  glDisable(GL_LIGHTING);
}

void drawContext::initPosition(bool saveMatrices)
{
  // NB: Those operations are applied to the model in the view coordinates
  // (in opposite order)
  glScaled(s[0], s[1], s[2]);
  glTranslated(t[0] - CTX::instance()->cg[0], t[1] - CTX::instance()->cg[1],
               t[2] - CTX::instance()->cg[2]);
  if(CTX::instance()->rotationCenterCg)
    glTranslated(CTX::instance()->cg[0], CTX::instance()->cg[1],
                 CTX::instance()->cg[2]);
  else
    glTranslated(CTX::instance()->rotationCenter[0],
                 CTX::instance()->rotationCenter[1],
                 CTX::instance()->rotationCenter[2]);

  buildRotationMatrix();
  glMultMatrixd(rot);

  if(CTX::instance()->rotationCenterCg)
    glTranslated(-CTX::instance()->cg[0], -CTX::instance()->cg[1],
                 -CTX::instance()->cg[2]);
  else
    glTranslated(-CTX::instance()->rotationCenter[0],
                 -CTX::instance()->rotationCenter[1],
                 -CTX::instance()->rotationCenter[2]);

  // store the projection and modelview matrices at this precise moment (so that
  // we can use them at any later time, even if the context has changed, i.e.,
  // even if we are out of draw())
  if(saveMatrices) {
    glGetDoublev(GL_PROJECTION_MATRIX, proj);
    glGetDoublev(GL_MODELVIEW_MATRIX, model);
  }

  for(int i = 0; i < 6; i++)
    glClipPlane((GLenum)(GL_CLIP_PLANE0 + i), CTX::instance()->clipPlane[i]);
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

  GLint vp[4];
  glGetIntegerv(GL_VIEWPORT, vp);

  winy = vp[3] - winy;

  GLdouble x0, y0, z0, x1, y1, z1;

  // we use the stored model and proj matrices instead of directly
  // getGetDouble'ing the matrices since unproject can be called in or after
  // draw2d
  if(!gluUnProject(winx, winy, 0.0, model, proj, vp, &x0, &y0, &z0))
    Msg::Warning("unproject1 failed");
  if(!gluUnProject(winx, winy, 1.0, model, proj, vp, &x1, &y1, &z1))
    Msg::Warning("unproject2 failed");

  p[0] = x0;
  p[1] = y0;
  p[2] = z0;
  d[0] = x1 - x0;
  d[1] = y1 - y0;
  d[2] = z1 - z0;
  double len = sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
  d[0] /= len;
  d[1] /= len;
  d[2] /= len;
}

void drawContext::viewport2World(double vp[3], double xyz[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluUnProject(vp[0], vp[1], vp[2], model, proj, viewport, &xyz[0], &xyz[1],
               &xyz[2]);
}

void drawContext::world2Viewport(double xyz[3], double vp[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluProject(xyz[0], xyz[1], xyz[2], model, proj, viewport, &vp[0], &vp[1],
             &vp[2]);
}

class hit {
public:
  GLuint type, ient, depth, type2, ient2;
  hit(GLuint t, GLuint i, GLuint d, GLuint t2 = 0, GLuint i2 = 0)
    : type(t), ient(i), depth(d), type2(t2), ient2(i2)
  {
  }
};

class hitDepthLessThan {
public:
  bool operator()(const hit &h1, const hit &h2) const
  {
    return h1.depth < h2.depth;
  }
};

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

  // in our case the selection buffer size is equal to between 5 and 7 times the
  // maximum number of possible hits
  GModel *m = GModel::current();
  int eles =
    (mesh && CTX::instance()->pickElements) ? 4 * m->getNumMeshElements() : 0;
  int nviews = PView::list.size() * 100;
  int size = 7 * (m->getNumVertices() + m->getNumEdges() + m->getNumFaces() +
                  m->getNumRegions() + eles) +
             nviews;
  if(!size) return false; // the model is empty, don't bother!

  // allocate selection buffer
  size += 1000; // just to make sure
  GLuint *selectionBuffer = new GLuint[size];
  glSelectBuffer(size, selectionBuffer);

  // do one rendering pass in select mode
  render_mode = drawContext::GMSH_SELECT;
  glRenderMode(GL_SELECT);
  glInitNames();
  glPushMatrix();

  // 3d stuff
  initProjection(x, y, w, h);
  initPosition(false);
  drawGeom();
  if(mesh) drawMesh();
  if(post) drawPost();
  drawGraph2d(true);

  // 2d stuff
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), (GLdouble)w,
                (GLdouble)h, (GLint *)viewport);
  glOrtho((double)viewport[0], (double)viewport[2], (double)viewport[1],
          (double)viewport[3], -100.,
          100.); // in pixels, so we can draw some 3D glyphs
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  drawGraph2d(false);
  drawText2d();

  glPopMatrix();

  GLint numhits = glRenderMode(GL_RENDER);
  render_mode = drawContext::GMSH_RENDER;

  if(!numhits) { // no hits
    delete[] selectionBuffer;
    return false;
  }
  else if(numhits < 0) { // overflow
    delete[] selectionBuffer;
    Msg::Warning("Too many entities selected");
    return false;
  }

  // decode the hits
  std::vector<hit> hits;
  GLuint *ptr = selectionBuffer;
  for(int i = 0; i < numhits; i++) {
    // in Gmsh 'names' should always be 0, 2 or 4:
    // * names == 0 means that there is nothing on the stack
    // * if names == 2, the first name is the type of the entity (0 for point, 1
    //   for edge, 2 for face or 3 for volume) and the second is the entity
    //   number;
    // * if names == 4, the first name is the type of the entity, the second is
    //   the entity number, the third is the type of vertex array (2 for line, 3
    //   for triangle, 4 for quad) and the fourth is the index of the element in
    //   the vertex array
    GLuint names = *ptr++;
    GLuint mindepth = *ptr++;
    GLuint maxdepth = *ptr++;
    if(names == 2) {
      GLuint depth =
        maxdepth + 0 * mindepth; // could do something with mindepth
      GLuint type = *ptr++;
      GLuint ient = *ptr++;
      hits.push_back(hit(type, ient, depth));
    }
    else if(names == 4) {
      GLuint depth =
        maxdepth + 0 * mindepth; // could do something with mindepth
      GLuint type = *ptr++;
      GLuint ient = *ptr++;
      GLuint type2 = *ptr++;
      GLuint ient2 = *ptr++;
      hits.push_back(hit(type, ient, depth, type2, ient2));
    }
  }

  delete[] selectionBuffer;

  if(!hits.size()) { // no entities
    return false;
  }

  // sort hits to get closest entities first
  std::sort(hits.begin(), hits.end(), hitDepthLessThan());

  // filter result: if type == ENT_NONE, return the closest entity of "lowest
  // dimension" (point < line < surface < volume). Otherwise, return the closest
  // entity of type "type"
  GLuint typmin = 10;
  for(std::size_t i = 0; i < hits.size(); i++)
    typmin = std::min(typmin, hits[i].type);

  for(std::size_t i = 0; i < hits.size(); i++) {
    if((type == ENT_ALL) || (type == ENT_NONE && hits[i].type == typmin) ||
       (type == ENT_POINT && hits[i].type == 0) ||
       (type == ENT_CURVE && hits[i].type == 1) ||
       (type == ENT_SURFACE && hits[i].type == 2) ||
       (type == ENT_VOLUME && hits[i].type == 3)) {
      switch(hits[i].type) {
      case 0: {
        GVertex *v = m->getVertexByTag(hits[i].ient);
        if(!v) {
          Msg::Error("Problem in point selection processing");
          return false;
        }
        vertices.push_back(v);
        if(!multiple) return true;
      } break;
      case 1: {
        GEdge *e = m->getEdgeByTag(hits[i].ient);
        if(!e) {
          Msg::Error("Problem in line selection processing");
          return false;
        }
        if(hits[i].type2) {
          MElement *ele = getElement(e, hits[i].type2, hits[i].ient2);
          if(ele) elements.push_back(ele);
        }
        edges.push_back(e);
        if(!multiple) return true;
      } break;
      case 2: {
        GFace *f = m->getFaceByTag(hits[i].ient);
        if(!f) {
          Msg::Error("Problem in surface selection processing");
          return false;
        }
        if(hits[i].type2) {
          MElement *ele = getElement(f, hits[i].type2, hits[i].ient2);
          if(ele) elements.push_back(ele);
        }
        faces.push_back(f);
        if(!multiple) return true;
      } break;
      case 3: {
        GRegion *r = m->getRegionByTag(hits[i].ient);
        if(!r) {
          Msg::Error("Problem in volume selection processing");
          return false;
        }
        if(hits[i].type2) {
          MElement *ele = getElement(r, hits[i].type2, hits[i].ient2);
          if(ele) elements.push_back(ele);
        }
        regions.push_back(r);
        if(!multiple) return true;
      } break;
      case 4: {
        int tag = hits[i].ient;
        SPoint2 p = getGraph2dDataPointForTag(tag);
        points.push_back(p);
        if(!multiple) return true;
      } break;
      case 5: {
        int tag = hits[i].ient;
        if(tag >= 0 && tag < (int)PView::list.size())
          views.push_back(PView::list[tag]);
        if(!multiple) return true;
      } break;
      }
    }
  }

  if(vertices.size() || edges.size() || faces.size() || regions.size() ||
     elements.size() || points.size() || views.size())
    return true;
  return false;
}

void drawContext::recenterForRotationCenterChange(SPoint3 newRotationCenter)
{
  // Recompute model translation so that the view is not changed
  SPoint3 &p = newRotationCenter;
  double vp[3];
  gluProject(p.x(), p.y(), p.z(), model, proj, viewport, &vp[0], &vp[1],
             &vp[2]);
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
