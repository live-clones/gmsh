// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshUI.h"
#include "GmshDefines.h"
#include "Message.h"
#include "Draw.h"
#include "Context.h"
#include "Numeric.h"
#include "GModel.h"
#include "PView.h"
#include "PViewOptions.h"

extern Context_T CTX;

int NeedPolygonOffset()
{
  GModel *m = GModel::current();
  if(m->getMeshStatus() == 2 &&
     (CTX.mesh.surfaces_edges || CTX.geom.lines || CTX.geom.surfaces))
    return 1;
  if(m->getMeshStatus() == 3 && 
     (CTX.mesh.surfaces_edges || CTX.mesh.volumes_edges))
    return 1;
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PViewOptions *opt = PView::list[i]->getOptions();
    if(opt->Visible && opt->ShowElement) return 1;
  }
  return 0;
}

void Draw3d()
{
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
  glPolygonOffset(CTX.polygon_offset_factor, CTX.polygon_offset_units);
  if(CTX.polygon_offset_factor || CTX.polygon_offset_units)
    CTX.polygon_offset = CTX.polygon_offset_always ? 1 : NeedPolygonOffset();
  else
    CTX.polygon_offset = 0;

  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);

  InitProjection();
  InitRenderModel();
  InitPosition();
  Draw_Geom();
  Draw_Mesh();
  Draw_Post();
}

void Draw2d()
{
  glDisable(GL_DEPTH_TEST);
  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho((double)CTX.viewport[0], (double)CTX.viewport[2],
          (double)CTX.viewport[1], (double)CTX.viewport[3], -1., 1.);
  // hack to make the 2D primitives appear "in front" in GL2PS
  glTranslated(0., 0., CTX.clip_factor > 1. ? 1./CTX.clip_factor : CTX.clip_factor);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  Draw_Graph2D();
  Draw_Text2D();
  Draw_OnScreenMessages();
  if(CTX.post.draw) Draw_Scales();

  if(CTX.small_axes)
    Draw_SmallAxes();
}

void DrawPlugin(void (*draw)())
{
  CTX.post.plugin_draw_function = draw;
  int old = CTX.draw_bbox;
  CTX.draw_bbox = 1;
  if(CTX.fast_redraw){
    CTX.post.draw = 0;
    CTX.mesh.draw = 0;
  }
  if(!CTX.batch) 
    Draw();
  // this is reset in each plugin run/cancel callback:
  // CTX.post.plugin_draw_function = NULL;
  CTX.draw_bbox = old;
  CTX.post.draw = 1;
  CTX.mesh.draw = 1;
}

void ClearOpengl()
{
  glClearColor(CTX.UNPACK_RED(CTX.color.bg) / 255.,
               CTX.UNPACK_GREEN(CTX.color.bg) / 255.,
               CTX.UNPACK_BLUE(CTX.color.bg) / 255., 0.);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void InitProjection(int xpick, int ypick, int wpick, int hpick)
{
  double Va = 
    (GLdouble) (CTX.viewport[3] - CTX.viewport[1]) /
    (GLdouble) (CTX.viewport[2] - CTX.viewport[0]);
  double Wa = (CTX.max[1] - CTX.min[1]) / (CTX.max[0] - CTX.min[0]);

  // compute the viewport in World coordinates (with margins)
  if(Va > Wa) {
    CTX.vxmin = CTX.min[0];
    CTX.vxmax = CTX.max[0];
    CTX.vymin = 0.5 * (CTX.min[1] + CTX.max[1] - Va * (CTX.max[0] - CTX.min[0]));
    CTX.vymax = 0.5 * (CTX.min[1] + CTX.max[1] + Va * (CTX.max[0] - CTX.min[0]));
  }
  else {
    CTX.vxmin = 0.5 * (CTX.min[0] + CTX.max[0] - (CTX.max[1] - CTX.min[1]) / Va);
    CTX.vxmax = 0.5 * (CTX.min[0] + CTX.max[0] + (CTX.max[1] - CTX.min[1]) / Va);
    CTX.vymin = CTX.min[1];
    CTX.vymax = CTX.max[1];
  }
  CTX.vxmin -= (CTX.vxmax - CTX.vxmin) / 3.;
  CTX.vxmax += 0.25 * (CTX.vxmax - CTX.vxmin);
  CTX.vymin -= (CTX.vymax - CTX.vymin) / 3.;
  CTX.vymax += 0.25 * (CTX.vymax - CTX.vymin);

  // store what one pixel represents in world coordinates
  CTX.pixel_equiv_x = (CTX.vxmax - CTX.vxmin) / (CTX.viewport[2] - CTX.viewport[0]);
  CTX.pixel_equiv_y = (CTX.vymax - CTX.vymin) / (CTX.viewport[3] - CTX.viewport[1]);

  // no initial translation of the model
  CTX.t_init[0] = CTX.t_init[1] = CTX.t_init[2] = 0.;

  // setup ortho or perspective projection matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // restrict picking to a rectangular region around xpick,ypick in SELECT mode
  if(CTX.render_mode == GMSH_SELECT)
    gluPickMatrix((GLdouble)xpick, (GLdouble)(CTX.viewport[3] - ypick),
                  (GLdouble)wpick, (GLdouble)hpick, (GLint *)CTX.viewport);

  double grad_z, grad_xy;
  double zmax = std::max(fabs(CTX.min[2]), fabs(CTX.max[2]));
  if(zmax < CTX.lc) zmax = CTX.lc;

  if(CTX.ortho) {
    // setting up the near and far clipping planes so that the box is
    // large enough to manipulate the model and zoom, but not too big
    // (the z-buffer resolution, e.g., on software Mesa can become
    // insufficient)
    double clip = zmax * CTX.s[2] * CTX.clip_factor;
    glOrtho(CTX.vxmin, CTX.vxmax, CTX.vymin, CTX.vymax, -clip, clip);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    grad_z = 0.99 * clip;
    grad_xy = 1.;
  }
  else {
    double clip_near = 0.75 * CTX.clip_factor * zmax;
    double clip_far = 75. * CTX.clip_factor * zmax;
    double coef = (75./0.75) / 3.;
    // recenter the model such that the perspective is always at the
    // center of gravity (we should maybe add an option to choose
    // this, as we do for the rotation center)
    CTX.t_init[0] = CTX.cg[0];
    CTX.t_init[1] = CTX.cg[1];
    CTX.vxmin -= CTX.t_init[0];
    CTX.vxmax -= CTX.t_init[0];
    CTX.vymin -= CTX.t_init[1];
    CTX.vymax -= CTX.t_init[1];
    glFrustum(CTX.vxmin, CTX.vxmax, CTX.vymin, CTX.vymax, clip_near, clip_far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(-coef * CTX.t_init[0], -coef * CTX.t_init[1], -coef * clip_near);
    glScaled(coef, coef, coef);
    grad_z = 0.99 * clip_far;
    grad_xy = clip_far / clip_near;
  }

  // draw background gradient
  if(CTX.render_mode != GMSH_SELECT && CTX.bg_gradient){
    glPushMatrix();
    glLoadIdentity();
    glTranslated(0., 0., -grad_z);
    if(CTX.bg_gradient == 1){ // vertical
      glBegin(GL_QUADS);
      glColor4ubv((GLubyte *) & CTX.color.bg);
      glVertex3d(grad_xy * CTX.vxmin, grad_xy * CTX.vymin, 0.);
      glVertex3d(grad_xy * CTX.vxmax, grad_xy * CTX.vymin, 0.);
      glColor4ubv((GLubyte *) & CTX.color.bg_grad);
      glVertex3d(grad_xy * CTX.vxmax, grad_xy * CTX.vymax, 0.);
      glVertex3d(grad_xy * CTX.vxmin, grad_xy * CTX.vymax, 0.);
      glEnd();
    }
    else if(CTX.bg_gradient == 2){ // horizontal
      glBegin(GL_QUADS);
      glColor4ubv((GLubyte *) & CTX.color.bg);
      glVertex3d(grad_xy * CTX.vxmax, grad_xy * CTX.vymin, 0.);
      glVertex3d(grad_xy * CTX.vxmax, grad_xy * CTX.vymax, 0.);
      glColor4ubv((GLubyte *) & CTX.color.bg_grad);
      glVertex3d(grad_xy * CTX.vxmin, grad_xy * CTX.vymax, 0.);
      glVertex3d(grad_xy * CTX.vxmin, grad_xy * CTX.vymin, 0.);
      glEnd();
    }
    else{ // radial
      double cx = grad_xy * (CTX.vxmin + CTX.vxmax) / 2.;
      double cy = grad_xy * (CTX.vymin + CTX.vymax) / 2.;
      double r = grad_xy * std::max(CTX.vxmax - CTX.vxmin, CTX.vymax - CTX.vymin) / 2.;
      glBegin(GL_TRIANGLE_FAN);
      glColor4ubv((GLubyte *) & CTX.color.bg_grad);
      glVertex3d(cx, cy, 0.);
      glColor4ubv((GLubyte *) & CTX.color.bg);
      glVertex3d(cx + r, cy, 0.);
      int ntheta = 36;
      for(int i = 1; i < ntheta + 1; i ++){
        double theta = i * 2 * M_PI / (double)ntheta;
        glVertex3d(cx + r * cos(theta), cy + r * sin(theta), 0.);       
      }
      glEnd();
    }
    glPopMatrix();
  }
}

void InitRenderModel()
{
  GLfloat r, g, b;

  glPushMatrix();
  glLoadIdentity();
  glScaled(CTX.s[0], CTX.s[1], CTX.s[2]);
  glTranslated(CTX.t[0], CTX.t[1], CTX.t[2]);
  
  for(int i = 0; i < 6; i++) {
    if(CTX.light[i]) {
      GLfloat position[4] = {(GLfloat)CTX.light_position[i][0],
                             (GLfloat)CTX.light_position[i][1],
                             (GLfloat)CTX.light_position[i][2],
                             (GLfloat)CTX.light_position[i][3]};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_POSITION, position);

      r = CTX.UNPACK_RED(CTX.color.ambient_light[i])/255.;
      g = CTX.UNPACK_GREEN(CTX.color.ambient_light[i])/255.;
      b = CTX.UNPACK_BLUE(CTX.color.ambient_light[i])/255.;
      GLfloat ambient[4] = {r, g, b, 1.0};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_AMBIENT, ambient);

      r = CTX.UNPACK_RED(CTX.color.diffuse_light[i])/255.;
      g = CTX.UNPACK_GREEN(CTX.color.diffuse_light[i])/255.;
      b = CTX.UNPACK_BLUE(CTX.color.diffuse_light[i])/255.;
      GLfloat diffuse[4] = {r, g, b, 1.0};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_DIFFUSE, diffuse);

      r = CTX.UNPACK_RED(CTX.color.specular_light[i])/255.;
      g = CTX.UNPACK_GREEN(CTX.color.specular_light[i])/255.;
      b = CTX.UNPACK_BLUE(CTX.color.specular_light[i])/255.;
      GLfloat specular[4] = {r, g, b, 1.0};
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
  GLfloat spec[4] = {CTX.shine, CTX.shine, CTX.shine, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
  // specular exponent in [0,128] (larger means more "focused"
  // reflection)
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, CTX.shine_exponent);

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

void InitPosition()
{
  glScaled(CTX.s[0], CTX.s[1], CTX.s[2]);
  glTranslated(CTX.t[0], CTX.t[1], CTX.t[2]);

  if(CTX.rotation_center_cg)
    glTranslated(CTX.cg[0], CTX.cg[1], CTX.cg[2]);
  else
    glTranslated(CTX.rotation_center[0],
                 CTX.rotation_center[1],
                 CTX.rotation_center[2]);
  
  CTX.buildRotationMatrix();
  glMultMatrixd(CTX.rot);

  if(CTX.rotation_center_cg)
    glTranslated(-CTX.cg[0], -CTX.cg[1], -CTX.cg[2]);
  else
    glTranslated(-CTX.rotation_center[0],
                 -CTX.rotation_center[1],
                 -CTX.rotation_center[2]);

  // store the projection and modelview matrices at this precise
  // moment (so that we can use them at any later time, even if the
  // context has changed, i.e., even if we are out of Draw())
  glGetDoublev(GL_PROJECTION_MATRIX, CTX.proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, CTX.model);

  for(int i = 0; i < 6; i++)
    glClipPlane((GLenum)(GL_CLIP_PLANE0 + i), CTX.clip_plane[i]);
}

// Takes a cursor position in window coordinates and returns the line
// (given by a point and a unit direction vector), in real space, that
// corresponds to that cursor position

void Unproject(double x, double y, double p[3], double d[3])
{
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  y = viewport[3]-y;

  GLdouble x0, y0, z0, x1, y1, z1;

  // we use CTX.model and CTX.proj instead of directly getGetDouble'ing
  // the matrices since unproject can be called in or after Draw2D
  
  if(!gluUnProject(x, y, 0.0, CTX.model, CTX.proj, viewport, &x0, &y0, &z0))
    Msg::Warning("unproject1 failed");
  if(!gluUnProject(x, y, 1.0, CTX.model, CTX.proj, viewport, &x1, &y1, &z1))
    Msg::Warning("unproject2 failed");
  
  p[0] = x0;
  p[1] = y0;
  p[2] = z0;
  d[0] = x1-x0;
  d[1] = y1-y0;
  d[2] = z1-z0;
  double len = sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);
  d[0] /= len;
  d[1] /= len;
  d[2] /= len;
}

void Viewport2World(double win[3], double xyz[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluUnProject(win[0], win[1], win[2], model, proj, viewport, &xyz[0], &xyz[1], &xyz[2]);
}

void World2Viewport(double xyz[3], double win[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluProject(xyz[0], xyz[1], xyz[2], model, proj, viewport, &win[0], &win[1], &win[2]);
}
