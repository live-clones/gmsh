// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "drawContext.h"
#include "Trackball.h"
#include "Context.h"
#include "Numeric.h"
#include "GModel.h"
#include "PView.h"
#include "PViewOptions.h"
#include "gl2ps.h"

#if defined(HAVE_FLTK)
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#endif

drawContext::drawContext(drawTransform *transform) 
  : _transform(transform)
{
  // initialize from temp values in global context
  for(int i = 0; i < 3; i++){
    r[i] = CTX::instance()->tmpRotation[i];
    t[i] = CTX::instance()->tmpTranslation[i];
    s[i] = CTX::instance()->tmpScale[i];
  }
  for(int i = 0; i < 4; i++){
    quaternion[i] = CTX::instance()->tmpQuaternion[i];
  }
  viewport[0] = viewport[1] = 0;
  viewport[2] = CTX::instance()->glSize[0];
  viewport[3] = CTX::instance()->glSize[1];

  render_mode = GMSH_RENDER;
  vxmin = vymin = vxmax = vymax = 0.;
  pixel_equiv_x = pixel_equiv_y = 0.;

  _bgImageSize[0] = _bgImageSize[1] = 0;

  _quadric = 0; // cannot create it here: needs valid opengl context
  _displayLists = 0;
}

drawContext::~drawContext()
{
  if(_quadric) gluDeleteQuadric(_quadric);
  if(_displayLists) glDeleteLists(_displayLists, 2);
}

void drawContext::createQuadricsAndDisplayLists()
{
  if(!_quadric) _quadric = gluNewQuadric();
  if(!_quadric){
    Msg::Error("Could not create quadric");
    return;
  }

  if(!_displayLists) _displayLists = glGenLists(2);
  if(!_displayLists){
    Msg::Error("Could not generate display lists");
    return;
  }

  // display list 0 (sphere)
  glNewList(_displayLists + 0, GL_COMPILE);
  gluSphere(_quadric, 1., 
            CTX::instance()->quadricSubdivisions, 
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
     CTX::instance()->arrowRelStemLength > 0){
    gluCylinder(_quadric, CTX::instance()->arrowRelStemRadius, 
                CTX::instance()->arrowRelStemRadius,
                CTX::instance()->arrowRelStemLength,
                CTX::instance()->quadricSubdivisions, 1);
    gluDisk(_quadric, 0, CTX::instance()->arrowRelStemRadius,
            CTX::instance()->quadricSubdivisions, 1);
  }
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
    rot[0] = C*E; rot[1] = BD*E+A*F; rot[2] =-AD*E+B*F; rot[3] = 0.;
    rot[4] =-C*F; rot[5] =-BD*F+A*E; rot[6] = AD*F+B*E; rot[7] = 0.;
    rot[8] = D;   rot[9] =-B*C;      rot[10] = A*C;     rot[11] = 0.;
    rot[12] = 0.; rot[13] = 0.;      rot[14] = 0.;      rot[15] = 1.;
    setQuaternionFromEulerAngles();
  }
}

void drawContext::addQuaternion(double p1x, double p1y, double p2x, double p2y)
{
  double quat[4];
  trackball(quat, p1x, p1y, p2x, p2y);
  add_quats(quat, quaternion, quaternion);
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
  double xx[3] = {1.,0.,0.};
  double yy[3] = {0.,1.,0.};
  double zz[3] = {0.,0.,1.};
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
  double C =  cos(r[1]);
  r[1] *= 180. / M_PI;
  if(fabs(C) > 0.005){ // Gimball lock?
    double tmpx =  rot[10] / C; // No, so get X-axis angle
    double tmpy = -rot[9] / C;
    r[0] = atan2(tmpy, tmpx) * 180. / M_PI;
    tmpx =  rot[0] / C; // Get Z-axis angle
    tmpy = -rot[4] / C;
    r[2] = atan2(tmpy, tmpx) * 180. / M_PI;
  }
  else{ // Gimball lock has occurred
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
     (CTX::instance()->mesh.surfacesEdges || CTX::instance()->geom.lines || 
      CTX::instance()->geom.surfaces))
    return 1;
  if(m->getMeshStatus() == 3 && 
     (CTX::instance()->mesh.surfacesEdges || CTX::instance()->mesh.volumesEdges))
    return 1;
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PViewOptions *opt = PView::list[i]->getOptions();
    if(opt->visible && opt->showElement) return 1;
  }
  return 0;
}

void drawContext::draw3d()
{
  // We can only create this when a valid opengl context exists. (It's
  // cheap to create so we just do it at each redraw: this makes it
  // much simpler to deal with option changes, e.g. arrow shape
  // changes)
  createQuadricsAndDisplayLists();

  // We should only enable the polygon offset when there is a mix of
  // lines and polygons to be drawn; enabling it all the time can lead
  // to very small but annoying artifacts in the picture. Since there
  // are so many ways in Gmsh to combine polygons and lines
  // (geometries + meshes + views...), we do our best here to
  // automatically detect if we should enable it. Note: the formula
  // for the offset is "offset = factor*DZ+r*units", where DZ is a
  // measurement of the change in depth relative to the screen area of
  // the polygon, and r is the smallest value that is guaranteed to
  // produce a resolvable offset for a given implementation.
  glPolygonOffset((float)CTX::instance()->polygonOffsetFactor, 
                  (float)CTX::instance()->polygonOffsetUnits);
  if(CTX::instance()->polygonOffsetFactor || CTX::instance()->polygonOffsetUnits)
    CTX::instance()->polygonOffset = CTX::instance()->polygonOffsetAlways ? 1 : 
      needPolygonOffset();
  else
    CTX::instance()->polygonOffset = 0;

  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  initProjection();
  initRenderModel();
  initPosition();
  drawAxes();
  drawGeom();
  drawMesh();
  drawPost();
}

void drawContext::draw2d()
{
  glDisable(GL_DEPTH_TEST);
  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho((double)viewport[0], (double)viewport[2],
          (double)viewport[1], (double)viewport[3], -1., 1.);

  // hack to make the 2D primitives appear "in front" in GL2PS
  glTranslated(0., 0., CTX::instance()->clipFactor > 1. ? 
               1. / CTX::instance()->clipFactor : CTX::instance()->clipFactor);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  drawGraph2d();
  drawText2d();
  if(CTX::instance()->post.draw) 
    drawScales();
  if(CTX::instance()->smallAxes)
    drawSmallAxes();
}

void drawContext::initProjection(int xpick, int ypick, int wpick, int hpick)
{
  double Va = 
    (double) (viewport[3] - viewport[1]) /
    (double) (viewport[2] - viewport[0]);
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
  vxmin -= (vxmax - vxmin) / 3.;
  vxmax += 0.25 * (vxmax - vxmin);
  vymin -= (vymax - vymin) / 3.;
  vymax += 0.25 * (vymax - vymin);

  // store what one pixel represents in world coordinates
  pixel_equiv_x = (vxmax - vxmin) / (viewport[2] - viewport[0]);
  pixel_equiv_y = (vymax - vymin) / (viewport[3] - viewport[1]);

  // no initial translation of the model
  t_init[0] = t_init[1] = t_init[2] = 0.;

  // set up the near and far clipping planes so that the box is large
  // enough to manipulate the model and zoom, but not too big
  // (otherwise the z-buffer resolution e.g. with Mesa can become
  // insufficient)
  double zmax = std::max(fabs(CTX::instance()->min[2]),
                         fabs(CTX::instance()->max[2]));
  if(zmax < CTX::instance()->lc) zmax = CTX::instance()->lc;

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
  if(render_mode != GMSH_SELECT && (CTX::instance()->bgGradient || 
                                    CTX::instance()->bgImageFileName.size())){
    glDisable(GL_DEPTH_TEST);
    glPushMatrix();
    glLoadIdentity();
    // the z values and the translation are only needed for GL2PS,
    // which does not understand "no depth test" (hence we must make
    // sure that we draw the background behind the rest of the scene)
    glOrtho((double)viewport[0], (double)viewport[2],
            (double)viewport[1], (double)viewport[3], 
            clip_near, clip_far);
    glTranslated(0., 0., -0.99 * clip_far);

    // background gradient
    if(CTX::instance()->bgGradient == 1){ // vertical
      glBegin(GL_QUADS);
      glColor4ubv((GLubyte *) & CTX::instance()->color.bg);
      glVertex2i(viewport[0], viewport[1]);
      glVertex2i(viewport[2], viewport[1]);
      glColor4ubv((GLubyte *) & CTX::instance()->color.bgGrad);
      glVertex2i(viewport[2], viewport[3]);
      glVertex2i(viewport[0], viewport[3]);
      glEnd();
    }
    else if(CTX::instance()->bgGradient == 2){ // horizontal
      glBegin(GL_QUADS);
      glColor4ubv((GLubyte *) & CTX::instance()->color.bg);
      glVertex2i(viewport[2], viewport[1]);
      glVertex2i(viewport[2], viewport[3]);
      glColor4ubv((GLubyte *) & CTX::instance()->color.bgGrad);
      glVertex2i(viewport[0], viewport[3]);
      glVertex2i(viewport[0], viewport[1]);
      glEnd();
    }
    else if(CTX::instance()->bgGradient == 3){ // radial
      double cx = 0.5 * (viewport[0] + viewport[2]);
      double cy = 0.5 * (viewport[1] + viewport[3]);
      double r = 0.5 * std::max(viewport[2] - viewport[0],
                                viewport[3] - viewport[1]);
      glBegin(GL_TRIANGLE_FAN);
      glColor4ubv((GLubyte *) & CTX::instance()->color.bgGrad);
      glVertex2d(cx, cy);
      glColor4ubv((GLubyte *) & CTX::instance()->color.bg);
      glVertex2d(cx + r, cy);
      int ntheta = 36;
      for(int i = 1; i < ntheta + 1; i ++){
        double theta = i * 2 * M_PI / (double)ntheta;
        glVertex2d(cx + r * cos(theta), cy + r * sin(theta));       
      }
      glEnd();
    }

    // hack for GL2PS (to make sure that the image is in front of the
    // gradient)
    glTranslated(0., 0., 0.01 * clip_far);

    // background image
    if(CTX::instance()->bgImageFileName.size()){
#if defined(HAVE_FLTK)
      if(_bgImage.empty()){
        int idot = CTX::instance()->bgImageFileName.find_last_of('.');
        std::string ext;
        if(idot > 0 && idot < (int)CTX::instance()->bgImageFileName.size())
          ext = CTX::instance()->bgImageFileName.substr(idot + 1);
        Fl_RGB_Image *img = 0;
        if(ext == "jpg" || ext == "JPG" || ext == "jpeg" || ext == "JPEG")
          img = new Fl_JPEG_Image(CTX::instance()->bgImageFileName.c_str());
        else if(ext == "png" || ext == "PNG")
          img = new Fl_PNG_Image(CTX::instance()->bgImageFileName.c_str());
        if(img && img->d() >= 3){
          const unsigned char *data = img->array;
          for(int j = img->h() - 1; j >= 0; j--) {
            for(int i = 0; i < img->w(); i++) {
              int idx = j * img->w() * img->d() + i * img->d();
              _bgImage.push_back((GLfloat)data[idx] / 255.F);
              _bgImage.push_back((GLfloat)data[idx + 1] / 255.F);
              _bgImage.push_back((GLfloat)data[idx + 2] / 255.F);
            }
          }
          _bgImageSize[0] = img->w();
          _bgImageSize[1] = img->h();
        }
        if(!_bgImageSize[0] || !_bgImageSize[1]){
          Msg::Error("Could not load valid background image");
          // make sure we don't try to load it again
          for(int i = 0; i < 3; i++) _bgImage.push_back(0);
          _bgImageSize[0] = _bgImageSize[1] = 1;
        }
        if(img) delete img;
      }
      double x = CTX::instance()->bgImagePosition[0];
      double y = CTX::instance()->bgImagePosition[1];
      int c = fix2dCoordinates(&x, &y);
      if(c & 1) x -= _bgImageSize[0] / 2.;
      if(c & 2) y -= _bgImageSize[1] / 2.;
      if(x < viewport[0]) x = viewport[0];
      if(y < viewport[1]) y = viewport[1];
      glRasterPos2d(x, y);
      glPixelStorei(GL_PACK_ALIGNMENT, 1);
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glDrawPixels(_bgImageSize[0], _bgImageSize[1], GL_RGB, GL_FLOAT,
                   (void*)&_bgImage[0]);
      gl2psDrawPixels(_bgImageSize[0], _bgImageSize[1], 0, 0, GL_RGB, GL_FLOAT,
                      (void*)&_bgImage[0]);
#endif
    }

    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
  }

  if(CTX::instance()->ortho) {
    glOrtho(vxmin, vxmax, vymin, vymax, clip_near, clip_far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  }
  else {
    // recenter the model such that the perspective is always at the
    // center of gravity (we should maybe add an option to choose
    // this, as we do for the rotation center)
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

      GLfloat r = (GLfloat)(CTX::instance()->unpackRed
                            (CTX::instance()->color.ambientLight[i]) / 255.);
      GLfloat g = (GLfloat)(CTX::instance()->unpackGreen
                            (CTX::instance()->color.ambientLight[i]) / 255.);
      GLfloat b = (GLfloat)(CTX::instance()->unpackBlue
                            (CTX::instance()->color.ambientLight[i]) / 255.);
      GLfloat ambient[4] = {r, g, b, 1.0F};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_AMBIENT, ambient);

      r = (GLfloat)(CTX::instance()->unpackRed
                    (CTX::instance()->color.diffuseLight[i]) / 255.);
      g = (GLfloat)(CTX::instance()->unpackGreen
                    (CTX::instance()->color.diffuseLight[i]) / 255.);
      b = (GLfloat)(CTX::instance()->unpackBlue
                    (CTX::instance()->color.diffuseLight[i]) / 255.);
      GLfloat diffuse[4] = {r, g, b, 1.0F};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_DIFFUSE, diffuse);

      r = (GLfloat)(CTX::instance()->unpackRed
                    (CTX::instance()->color.specularLight[i]) / 255.);
      g = (GLfloat)(CTX::instance()->unpackGreen
                    (CTX::instance()->color.specularLight[i]) / 255.);
      b = (GLfloat)(CTX::instance()->unpackBlue
                    (CTX::instance()->color.specularLight[i]) / 255.);
      GLfloat specular[4] = {r, g, b, 1.0F};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_SPECULAR, specular);

      glEnable((GLenum)(GL_LIGHT0 + i));
    }
    else{
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

  // Normalize the normals automatically. We could use the more
  // efficient glEnable(GL_RESCALE_NORMAL) instead (since we initially
  // specify unit normals), but GL_RESCALE_NORMAL does only work with
  // isotropic scalings (and we allow anistotropic scalings in
  // myZoom). Note that GL_RESCALE_NORMAL is only available in
  // GL_VERSION_1_2.
  glEnable(GL_NORMALIZE);

  // lighting is enabled/disabled for each particular primitive later
  glDisable(GL_LIGHTING);
}

void drawContext::initPosition()
{
  glScaled(s[0], s[1], s[2]);
  glTranslated(t[0], t[1], t[2]);

  if(CTX::instance()->rotationCenterCg)
    glTranslated(CTX::instance()->cg[0], 
                 CTX::instance()->cg[1], 
                 CTX::instance()->cg[2]);
  else
    glTranslated(CTX::instance()->rotationCenter[0],
                 CTX::instance()->rotationCenter[1],
                 CTX::instance()->rotationCenter[2]);
  
  buildRotationMatrix();
  glMultMatrixd(rot);

  if(CTX::instance()->rotationCenterCg)
    glTranslated(-CTX::instance()->cg[0], 
                 -CTX::instance()->cg[1], 
                 -CTX::instance()->cg[2]);
  else
    glTranslated(-CTX::instance()->rotationCenter[0],
                 -CTX::instance()->rotationCenter[1],
                 -CTX::instance()->rotationCenter[2]);

  // store the projection and modelview matrices at this precise
  // moment (so that we can use them at any later time, even if the
  // context has changed, i.e., even if we are out of draw())
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);

  for(int i = 0; i < 6; i++)
    glClipPlane((GLenum)(GL_CLIP_PLANE0 + i), CTX::instance()->clipPlane[i]);
}

// Takes a cursor position in window coordinates and returns the line
// (given by a point and a unit direction vector), in real space, that
// corresponds to that cursor position
void drawContext::unproject(double x, double y, double p[3], double d[3])
{
  GLint vp[4];
  glGetIntegerv(GL_VIEWPORT, vp);

  y = vp[3] - y;

  GLdouble x0, y0, z0, x1, y1, z1;

  // we use the stored model and proj matrices instead of directly
  // getGetDouble'ing the matrices since unproject can be called in or
  // after draw2d
  if(!gluUnProject(x, y, 0.0, model, proj, vp, &x0, &y0, &z0))
    Msg::Warning("unproject1 failed");
  if(!gluUnProject(x, y, 1.0, model, proj, vp, &x1, &y1, &z1))
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

void drawContext::viewport2World(double win[3], double xyz[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluUnProject(win[0], win[1], win[2], model, proj, viewport, &xyz[0], &xyz[1], &xyz[2]);
}

void drawContext::world2Viewport(double xyz[3], double win[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluProject(xyz[0], xyz[1], xyz[2], model, proj, viewport, &win[0], &win[1], &win[2]);
}
