// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include "FlGui.h"
#include "drawContext.h"
#include "contextWindow.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "Parser.h"
#include "GModel.h"
#ifdef Convex // can be defined by Xlib
#undef Convex
#endif
#include "GModelIO_OCC.h"
#include "scriptStringInterface.h"
#include "OpenFile.h"
#include "Context.h"
#include "Options.h"
#include "MallocUtils.h"
#include "StringUtils.h"
#include "Geo.h"
#include "VertexArray.h"
#include "mathEvaluator.h"

static bool getval(const char *str, double &val)
{
  std::vector<std::string> var;
  std::vector<double> valVar;

  // we should probably use the actual .geo parser instead...
  for(auto it = gmsh_yysymbols.begin(); it != gmsh_yysymbols.end(); it++) {
    if(it->second.value.size() == 1) {
      var.push_back(it->first);
      valVar.push_back(it->second.value[0]);
    }
  }

  std::vector<std::string> expr(1);
  expr[0] = str;
  std::vector<double> res(1);
  mathEvaluator f(expr, var);
  if(expr.empty()) return false;
  if(!f.eval(valVar, res)) return false;
  val = res[0];
  return true;
}

static void draw_stl(std::vector<SPoint3> &vertices,
                     std::vector<SVector3> &normals,
                     std::vector<int> &triangles)
{
  GLint mode[2];
  glGetIntegerv(GL_POLYGON_MODE, mode);
  if(CTX::instance()->geom.surfaceType == 1)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  else
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_LIGHTING);
  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);

  VertexArray va(3, triangles.size());
  for(std::size_t i = 0; i < triangles.size(); i += 3) {
    SPoint3 p1 = vertices[triangles[i]];
    SPoint3 p2 = vertices[triangles[i + 1]];
    SPoint3 p3 = vertices[triangles[i + 2]];
    SVector3 n1 = normals[triangles[i]];
    SVector3 n2 = normals[triangles[i + 1]];
    SVector3 n3 = normals[triangles[i + 2]];
    double x[3] = {p1.x(), p2.x(), p3.x()};
    double y[3] = {p1.y(), p2.y(), p3.y()};
    double z[3] = {p1.z(), p2.z(), p3.z()};
    SVector3 nn[3] = {n1, n2, n3};
    va.add(x, y, z, nn);
  }
  va.finalize();

  glVertexPointer(3, GL_FLOAT, 0, va.getVertexArray());
  glEnableClientState(GL_VERTEX_ARRAY);
  glNormalPointer(NORMAL_GLTYPE, 0, va.getNormalArray());
  glEnableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  glDrawArrays(GL_TRIANGLES, 0, va.getNumVertices());
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);

  glDisable(GL_LIGHTING);
  glPolygonMode(GL_FRONT_AND_BACK, mode[1]);
}

static void elementary_add_parameter_cb(Fl_Widget *w, void *data)
{
  scriptAddParameter(FlGui::instance()->elementaryContext->input[0]->value(),
                     FlGui::instance()->elementaryContext->input[1]->value(),
                     FlGui::instance()->elementaryContext->input[2]->value(),
                     FlGui::instance()->elementaryContext->input[3]->value(),
                     GModel::current()->getFileName());
  FlGui::instance()->resetVisibility();
  FlGui::instance()->rebuildTree(true);
}

static void elementary_draw_point_cb(Fl_Widget *w, void *data)
{
  if(data) return; // we are here from do_callback()
  double x, y, z;
  if(!getval(FlGui::instance()->elementaryContext->input[4]->value(), x))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[5]->value(), y))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[6]->value(), z))
    return;
  FlGui::instance()->getCurrentOpenglWindow()->setPoint(x, y, z);
  drawContext::global()->draw();
}

static void elementary_add_point_cb(Fl_Widget *w, void *data)
{
  scriptAddPoint(GModel::current()->getFileName(),
                 FlGui::instance()->elementaryContext->input[4]->value(),
                 FlGui::instance()->elementaryContext->input[5]->value(),
                 FlGui::instance()->elementaryContext->input[6]->value(),
                 FlGui::instance()->elementaryContext->input[7]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_circle(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double xc, yc, zc, r, angle1, angle2;
  if(!getval(FlGui::instance()->elementaryContext->input[8]->value(), xc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[9]->value(), yc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[10]->value(), zc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[11]->value(), r))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[12]->value(), angle1))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[13]->value(), angle2))
    return;

  if(angle2 <= angle1) return;
  glColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);
  glBegin(GL_LINE_STRIP);
  const int N = 30;
  for(int i = 0; i < N; i++) {
    double t = angle1 + (double)i / (double)(N - 1) * (angle2 - angle1);
    double x = xc + r * cos(t);
    double y = yc + r * sin(t);
    double z = zc;
    glVertex3d(x, y, z);
  }
  glEnd();
}

static void elementary_draw_circle_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_circle);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_circle_cb(Fl_Widget *w, void *data)
{
  scriptAddCircle(GModel::current()->getFileName(),
                  FlGui::instance()->elementaryContext->input[8]->value(),
                  FlGui::instance()->elementaryContext->input[9]->value(),
                  FlGui::instance()->elementaryContext->input[10]->value(),
                  FlGui::instance()->elementaryContext->input[11]->value(),
                  FlGui::instance()->elementaryContext->input[12]->value(),
                  FlGui::instance()->elementaryContext->input[13]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_ellipse(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double xc, yc, zc, rx, ry, angle1, angle2;
  if(!getval(FlGui::instance()->elementaryContext->input[14]->value(), xc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[15]->value(), yc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[16]->value(), zc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[17]->value(), rx))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[18]->value(), ry))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[19]->value(), angle1))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[20]->value(), angle2))
    return;
  if(angle2 <= angle1) return;
  glColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);
  glBegin(GL_LINE_STRIP);
  const int N = 30;
  for(int i = 0; i < N; i++) {
    double t = angle1 + (double)i / (double)(N - 1) * (angle2 - angle1);
    double x = xc + rx * cos(t);
    double y = yc + ry * sin(t);
    double z = zc;
    glVertex3d(x, y, z);
  }
  glEnd();
}

static void elementary_draw_ellipse_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_ellipse);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_ellipse_cb(Fl_Widget *w, void *data)
{
  scriptAddEllipse(GModel::current()->getFileName(),
                   FlGui::instance()->elementaryContext->input[14]->value(),
                   FlGui::instance()->elementaryContext->input[15]->value(),
                   FlGui::instance()->elementaryContext->input[16]->value(),
                   FlGui::instance()->elementaryContext->input[17]->value(),
                   FlGui::instance()->elementaryContext->input[18]->value(),
                   FlGui::instance()->elementaryContext->input[19]->value(),
                   FlGui::instance()->elementaryContext->input[20]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_disk(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double xc, yc, zc, rx, ry;
  if(!getval(FlGui::instance()->elementaryContext->input[21]->value(), xc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[22]->value(), yc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[23]->value(), zc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[24]->value(), rx))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[25]->value(), ry))
    return;
  std::vector<SPoint3> vertices;
  std::vector<SVector3> normals;
  std::vector<int> triangles;
  if(!GModel::current()->getOCCInternals()->makeDiskSTL(
       xc, yc, zc, rx, ry, vertices, normals, triangles))
    return;
  draw_stl(vertices, normals, triangles);
}

static void elementary_draw_disk_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_disk);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_disk_cb(Fl_Widget *w, void *data)
{
  scriptAddDisk(GModel::current()->getFileName(),
                FlGui::instance()->elementaryContext->input[21]->value(),
                FlGui::instance()->elementaryContext->input[22]->value(),
                FlGui::instance()->elementaryContext->input[23]->value(),
                FlGui::instance()->elementaryContext->input[24]->value(),
                FlGui::instance()->elementaryContext->input[25]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_rectangle(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double x, y, z, dx, dy, r;
  if(!getval(FlGui::instance()->elementaryContext->input[26]->value(), x))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[27]->value(), y))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[28]->value(), z))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[29]->value(), dx))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[30]->value(), dy))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[31]->value(), r))
    return;
  std::vector<SPoint3> vertices;
  std::vector<SVector3> normals;
  std::vector<int> triangles;
  if(!GModel::current()->getOCCInternals()->makeRectangleSTL(
       x, y, z, dx, dy, r, vertices, normals, triangles))
    return;
  draw_stl(vertices, normals, triangles);
}

static void elementary_draw_rectangle_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_rectangle);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_rectangle_cb(Fl_Widget *w, void *data)
{
  scriptAddRectangle(GModel::current()->getFileName(),
                     FlGui::instance()->elementaryContext->input[26]->value(),
                     FlGui::instance()->elementaryContext->input[27]->value(),
                     FlGui::instance()->elementaryContext->input[28]->value(),
                     FlGui::instance()->elementaryContext->input[29]->value(),
                     FlGui::instance()->elementaryContext->input[30]->value(),
                     FlGui::instance()->elementaryContext->input[31]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_sphere(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double xc, yc, zc, r, angle1, angle2, angle3;
  if(!getval(FlGui::instance()->elementaryContext->input[32]->value(), xc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[33]->value(), yc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[34]->value(), zc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[35]->value(), r))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[36]->value(), angle1))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[37]->value(), angle2))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[38]->value(), angle3))
    return;
  std::vector<SPoint3> vertices;
  std::vector<SVector3> normals;
  std::vector<int> triangles;
  if(!GModel::current()->getOCCInternals()->makeSphereSTL(
       xc, yc, zc, r, angle1, angle2, angle3, vertices, normals, triangles))
    return;
  draw_stl(vertices, normals, triangles);
}

static void elementary_draw_sphere_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_sphere);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_sphere_cb(Fl_Widget *w, void *data)
{
  scriptAddSphere(GModel::current()->getFileName(),
                  FlGui::instance()->elementaryContext->input[32]->value(),
                  FlGui::instance()->elementaryContext->input[33]->value(),
                  FlGui::instance()->elementaryContext->input[34]->value(),
                  FlGui::instance()->elementaryContext->input[35]->value(),
                  FlGui::instance()->elementaryContext->input[36]->value(),
                  FlGui::instance()->elementaryContext->input[37]->value(),
                  FlGui::instance()->elementaryContext->input[38]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  drawContext::setDrawGeomTransientFunction(nullptr);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_cylinder(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double xc, yc, zc, dx, dy, dz, r, angle;
  if(!getval(FlGui::instance()->elementaryContext->input[39]->value(), xc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[40]->value(), yc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[41]->value(), zc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[42]->value(), dx))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[43]->value(), dy))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[44]->value(), dz))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[45]->value(), r))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[46]->value(), angle))
    return;
  std::vector<SPoint3> vertices;
  std::vector<SVector3> normals;
  std::vector<int> triangles;
  if(!GModel::current()->getOCCInternals()->makeCylinderSTL(
       xc, yc, zc, dx, dy, dz, r, angle, vertices, normals, triangles))
    return;
  draw_stl(vertices, normals, triangles);
}

static void elementary_draw_cylinder_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_cylinder);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_cylinder_cb(Fl_Widget *w, void *data)
{
  scriptAddCylinder(GModel::current()->getFileName(),
                    FlGui::instance()->elementaryContext->input[39]->value(),
                    FlGui::instance()->elementaryContext->input[40]->value(),
                    FlGui::instance()->elementaryContext->input[41]->value(),
                    FlGui::instance()->elementaryContext->input[42]->value(),
                    FlGui::instance()->elementaryContext->input[43]->value(),
                    FlGui::instance()->elementaryContext->input[44]->value(),
                    FlGui::instance()->elementaryContext->input[45]->value(),
                    FlGui::instance()->elementaryContext->input[46]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_box(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double x, y, z, dx, dy, dz;
  if(!getval(FlGui::instance()->elementaryContext->input[47]->value(), x))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[48]->value(), y))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[49]->value(), z))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[50]->value(), dx))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[51]->value(), dy))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[52]->value(), dz))
    return;
  std::vector<SPoint3> vertices;
  std::vector<SVector3> normals;
  std::vector<int> triangles;
  if(!GModel::current()->getOCCInternals()->makeBoxSTL(
       x, y, z, dx, dy, dz, vertices, normals, triangles))
    return;
  draw_stl(vertices, normals, triangles);
}

static void elementary_draw_box_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_box);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_box_cb(Fl_Widget *w, void *data)
{
  scriptAddBox(GModel::current()->getFileName(),
               FlGui::instance()->elementaryContext->input[47]->value(),
               FlGui::instance()->elementaryContext->input[48]->value(),
               FlGui::instance()->elementaryContext->input[49]->value(),
               FlGui::instance()->elementaryContext->input[50]->value(),
               FlGui::instance()->elementaryContext->input[51]->value(),
               FlGui::instance()->elementaryContext->input[52]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_torus(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double xc, yc, zc, r1, r2, angle;
  if(!getval(FlGui::instance()->elementaryContext->input[53]->value(), xc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[54]->value(), yc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[55]->value(), zc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[56]->value(), r1))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[57]->value(), r2))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[58]->value(), angle))
    return;
  std::vector<SPoint3> vertices;
  std::vector<SVector3> normals;
  std::vector<int> triangles;
  if(!GModel::current()->getOCCInternals()->makeTorusSTL(
       xc, yc, zc, r1, r2, angle, vertices, normals, triangles))
    return;
  draw_stl(vertices, normals, triangles);
}

static void elementary_draw_torus_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_torus);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_torus_cb(Fl_Widget *w, void *data)
{
  scriptAddTorus(GModel::current()->getFileName(),
                 FlGui::instance()->elementaryContext->input[53]->value(),
                 FlGui::instance()->elementaryContext->input[54]->value(),
                 FlGui::instance()->elementaryContext->input[55]->value(),
                 FlGui::instance()->elementaryContext->input[56]->value(),
                 FlGui::instance()->elementaryContext->input[57]->value(),
                 FlGui::instance()->elementaryContext->input[58]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_cone(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double xc, yc, zc, dx, dy, dz, r1, r2, angle;
  if(!getval(FlGui::instance()->elementaryContext->input[59]->value(), xc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[60]->value(), yc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[61]->value(), zc))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[62]->value(), dx))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[63]->value(), dy))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[64]->value(), dz))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[65]->value(), r1))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[66]->value(), r2))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[67]->value(), angle))
    return;
  std::vector<SPoint3> vertices;
  std::vector<SVector3> normals;
  std::vector<int> triangles;
  if(!GModel::current()->getOCCInternals()->makeConeSTL(
       xc, yc, zc, dx, dy, dz, r1, r2, angle, vertices, normals, triangles))
    return;
  draw_stl(vertices, normals, triangles);
}

static void elementary_draw_cone_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_cone);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_cone_cb(Fl_Widget *w, void *data)
{
  scriptAddCone(GModel::current()->getFileName(),
                FlGui::instance()->elementaryContext->input[59]->value(),
                FlGui::instance()->elementaryContext->input[60]->value(),
                FlGui::instance()->elementaryContext->input[61]->value(),
                FlGui::instance()->elementaryContext->input[62]->value(),
                FlGui::instance()->elementaryContext->input[63]->value(),
                FlGui::instance()->elementaryContext->input[64]->value(),
                FlGui::instance()->elementaryContext->input[65]->value(),
                FlGui::instance()->elementaryContext->input[66]->value(),
                FlGui::instance()->elementaryContext->input[67]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void draw_wedge(void *context)
{
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  double x, y, z, dx, dy, dz, ltx;
  if(!getval(FlGui::instance()->elementaryContext->input[68]->value(), x))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[69]->value(), y))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[70]->value(), z))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[71]->value(), dx))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[72]->value(), dy))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[73]->value(), dz))
    return;
  if(!getval(FlGui::instance()->elementaryContext->input[74]->value(), ltx))
    return;
  std::vector<SPoint3> vertices;
  std::vector<SVector3> normals;
  std::vector<int> triangles;
  if(!GModel::current()->getOCCInternals()->makeWedgeSTL(
       x, y, z, dx, dy, dz, ltx, vertices, normals, triangles))
    return;
  draw_stl(vertices, normals, triangles);
}

static void elementary_draw_wedge_cb(Fl_Widget *w, void *data)
{
  drawContext::setDrawGeomTransientFunction(draw_wedge);
  if(!data) drawContext::global()->draw();
}

static void elementary_add_wedge_cb(Fl_Widget *w, void *data)
{
  scriptAddWedge(GModel::current()->getFileName(),
                 FlGui::instance()->elementaryContext->input[68]->value(),
                 FlGui::instance()->elementaryContext->input[69]->value(),
                 FlGui::instance()->elementaryContext->input[70]->value(),
                 FlGui::instance()->elementaryContext->input[71]->value(),
                 FlGui::instance()->elementaryContext->input[72]->value(),
                 FlGui::instance()->elementaryContext->input[73]->value(),
                 FlGui::instance()->elementaryContext->input[74]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void elementary_switch_tabs_cb(Fl_Widget *w, void *data)
{
  if(FlGui::instance()->elementaryContext->tab1->visible()) {
    FlGui::instance()->elementaryContext->tab1->hide();
    FlGui::instance()->elementaryContext->tab2->show();
  }
  else {
    FlGui::instance()->elementaryContext->tab2->hide();
    FlGui::instance()->elementaryContext->tab1->show();
  }
}

static void elementary_snap_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->geom.snap[0] =
    FlGui::instance()->elementaryContext->value[0]->value();
  CTX::instance()->geom.snap[1] =
    FlGui::instance()->elementaryContext->value[1]->value();
  CTX::instance()->geom.snap[2] =
    FlGui::instance()->elementaryContext->value[2]->value();
}

elementaryContextWindow::elementaryContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 34 * FL_NORMAL_SIZE;
  int height = 5 * WB + 10 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Elementary Entity Context");
  win->box(GMSH_WINDOW_BOX);
  {
    tab1 = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
    // 0: Parameter
    {
      group[0] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Parameter");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Name");
      input[0]->value("lc");
      input[1] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Value");
      input[1]->value("0.1");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Label");
      input[2]->value("");
      input[3] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Path");
      input[3]->value("Parameters");
      for(int i = 0; i < 4; i++) { input[i]->align(FL_ALIGN_RIGHT); }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_parameter_cb);
      }
      group[0]->end();
    }
    // 1: Point
    {
      group[1] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Point");
      input[4] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X");
      input[4]->value("0");
      input[5] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y");
      input[5]->value("0");
      input[6] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z");
      input[6]->value("0");
      input[7] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH,
                              "Prescribed mesh size at point");
      input[7]->value("1.0");
      for(int i = 4; i < 8; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_point_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_point_cb);
      }
      group[1]->end();
    }
    // 2: Circle
    {
      group[2] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Circle");
      input[8] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X");
      input[8]->value("0");
      input[9] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y");
      input[9]->value("0");
      input[10] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z");
      input[10]->value("0");
      input[11] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Radius");
      input[11]->value("0.5");
      input[12] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Angle 1");
      input[12]->value("0");
      input[13] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Angle 2");
      input[13]->value("2*Pi");
      for(int i = 8; i < 14; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_circle_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_circle_cb);
      }
      group[2]->end();
    }
    // 3: Ellipse
    {
      group[3] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Ellipse");
      input[14] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X");
      input[14]->value("0");
      input[15] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y");
      input[15]->value("0");
      input[16] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z");
      input[16]->value("0");
      input[17] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Radius X");
      input[17]->value("0.5");
      input[18] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Radius Y");
      input[18]->value("0.25");
      input[19] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Angle 1");
      input[19]->value("0");
      input[20] = new Fl_Input(2 * WB, 2 * WB + 7 * BH, IW, BH, "Angle 2");
      input[20]->value("2*Pi");
      for(int i = 14; i < 21; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_ellipse_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_ellipse_cb);
      }
      group[3]->end();
    }
    // 4: Disk
    {
      group[4] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Disk");
      input[21] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X");
      input[21]->value("0");
      input[22] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y");
      input[22]->value("0");
      input[23] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z");
      input[23]->value("0");
      input[24] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Radius X");
      input[24]->value("0.5");
      input[25] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Radius Y");
      input[25]->value("0.25");
      for(int i = 21; i < 26; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_disk_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_disk_cb);
      }
      group[4]->end();
    }
    // 5: Rectangle
    {
      group[5] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Rectangle");
      input[26] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X");
      input[26]->value("0");
      input[27] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y");
      input[27]->value("0");
      input[28] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z");
      input[28]->value("0");
      input[29] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "DX");
      input[29]->value("1");
      input[30] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "DY");
      input[30]->value("0.5");
      input[31] =
        new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Rounded radius");
      input[31]->value("0");
      for(int i = 26; i < 32; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_rectangle_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_rectangle_cb);
      }
      group[5]->end();
    }
    tab1->end();
  }
  {
    tab2 = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
    // 6: Sphere
    {
      group[6] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Sphere");
      input[32] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X");
      input[32]->value("0");
      input[33] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y");
      input[33]->value("0");
      input[34] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z");
      input[34]->value("0");
      input[35] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Radius");
      input[35]->value("0.5");
      input[36] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Angle 1");
      input[36]->value("-Pi/2");
      input[37] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Angle 2");
      input[37]->value("Pi/2");
      input[38] = new Fl_Input(2 * WB, 2 * WB + 7 * BH, IW, BH, "Angle 3");
      input[38]->value("2*Pi");
      for(int i = 32; i < 39; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_sphere_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_sphere_cb);
      }
      group[6]->end();
    }
    // 7: Cylinder
    {
      group[7] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Cylinder");
      input[39] =
        new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center base X");
      input[39]->value("0");
      input[40] =
        new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center base Y");
      input[40]->value("0");
      input[41] =
        new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center base Z");
      input[41]->value("0");
      input[42] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Axis DX");
      input[42]->value("1");
      input[43] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Axis DY");
      input[43]->value("0");
      input[44] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Axis DZ");
      input[44]->value("0");
      input[45] = new Fl_Input(2 * WB, 2 * WB + 7 * BH, IW, BH, "Radius");
      input[45]->value("0.5");
      input[46] = new Fl_Input(2 * WB, 2 * WB + 8 * BH, IW, BH, "Angle");
      input[46]->value("2*Pi");
      for(int i = 39; i < 47; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_cylinder_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_cylinder_cb);
      }
      group[7]->end();
    }
    // 8: Box
    {
      group[8] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Box");
      input[47] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X");
      input[47]->value("0");
      input[48] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y");
      input[48]->value("0");
      input[49] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z");
      input[49]->value("0");
      input[50] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "DX");
      input[50]->value("1");
      input[51] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "DY");
      input[51]->value("1");
      input[52] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "DZ");
      input[52]->value("1");
      for(int i = 47; i < 53; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_box_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_box_cb);
      }
      group[8]->end();
    }
    // 9: Torus
    {
      group[9] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Torus");
      input[53] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X");
      input[53]->value("0");
      input[54] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y");
      input[54]->value("0");
      input[55] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z");
      input[55]->value("0");
      input[56] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Radius 1");
      input[56]->value("0.5");
      input[57] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Radius 2");
      input[57]->value("0.2");
      input[58] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Angle");
      input[58]->value("2*Pi");
      for(int i = 53; i < 59; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_torus_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_torus_cb);
      }
      group[9]->end();
    }
    // 10: Cone
    {
      group[10] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                               height - 3 * WB - 2 * BH, "Cone");
      input[59] =
        new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center base X");
      input[59]->value("0");
      input[60] =
        new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center base Y");
      input[60]->value("0");
      input[61] =
        new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center base Z");
      input[61]->value("0");
      input[62] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Axis DX");
      input[62]->value("1");
      input[63] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Axis DY");
      input[63]->value("0");
      input[64] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Axis DZ");
      input[64]->value("0");
      input[65] = new Fl_Input(2 * WB + (width - 2 * WB) / 2, 2 * WB + 4 * BH,
                               IW, BH, "Radius 1");
      input[65]->value("0.5");
      input[66] = new Fl_Input(2 * WB + (width - 2 * WB) / 2, 2 * WB + 5 * BH,
                               IW, BH, "Radius 2");
      input[66]->value("0.1");
      input[67] = new Fl_Input(2 * WB + (width - 2 * WB) / 2, 2 * WB + 6 * BH,
                               IW, BH, "Angle");
      input[67]->value("2*Pi");
      for(int i = 59; i < 68; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_cone_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_cone_cb);
      }
      group[10]->end();
    }
    // 11: Wedge
    {
      group[11] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                               height - 3 * WB - 2 * BH, "Wedge");
      input[68] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X");
      input[68]->value("0");
      input[69] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y");
      input[69]->value("0");
      input[70] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z");
      input[70]->value("0");
      input[71] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "DX");
      input[71]->value("0.5");
      input[72] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "DY");
      input[72]->value("0.5");
      input[73] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "DZ");
      input[73]->value("0.5");
      input[74] = new Fl_Input(2 * WB, 2 * WB + 7 * BH, IW, BH, "Top DX");
      input[74]->value("0");
      for(int i = 68; i < 75; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->callback(elementary_draw_wedge_cb);
      }
      {
        Fl_Button *o = new Fl_Button(width - BB - 2 * WB,
                                     height - 3 * WB - 2 * BH, BB, BH, "Add");
        o->callback(elementary_add_wedge_cb);
      }
      group[11]->end();
    }
    tab2->end();
  }

  {
    Fl_Button *o = new Fl_Button(width - 4 * WB, WB, 3 * WB, 3 * WB, "...");
    o->callback(elementary_switch_tabs_cb);
  }
  {
    value[0] = new Fl_Value_Input(WB, height - WB - BH, IW / 3, BH, "X");
    value[1] =
      new Fl_Value_Input(WB + IW / 2, height - WB - BH, IW / 3, BH, "Y");
    value[2] =
      new Fl_Value_Input(WB + IW, height - WB - BH, IW / 3, BH, "Z snap");
    for(int i = 0; i < 3; i++) {
      value[i]->align(FL_ALIGN_RIGHT);
      value[i]->callback(elementary_snap_cb);
    }
    butt[0] =
      new Fl_Check_Button(width - 6 * BH, height - WB - BH, 1.2 * BH, BH, "X");
    butt[0]->tooltip("Toggle (x) or exclusive unselect (Shift+x)");
    butt[1] = new Fl_Check_Button(width - 6 * BH + 1.2 * BH, height - WB - BH,
                                  1.2 * BH, BH, "Y");
    butt[1]->tooltip("Toggle (y) or exclusive unselect (Shift+y)");
    butt[2] = new Fl_Check_Button(width - 6 * BH + 2.4 * BH, height - WB - BH,
                                  (6 - 2 * 1.2) * BH - WB, BH, "Z freeze");
    butt[2]->tooltip("Toggle (z) or exclusive unselect (Shift+z)");
  }

  tab1->show();
  tab2->hide();

  win->position(CTX::instance()->ctxPosition[0],
                CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

bool elementaryContextWindow::frozenPointCoord(int coord)
{
  if(coord < 0 || coord > 2) return false;
  return butt[coord]->value() ? true : false;
}

void elementaryContextWindow::updatePoint(double pt[3], int which)
{
  for(int i = 0; i < 3; i++) {
    if(!frozenPointCoord(i)) {
      char str[32];
      sprintf(str, "%g", pt[i]);
      if(which == 1) {
        int start[11] = {4, 8, 14, 21, 26, 32, 39, 47, 53, 59, 68};
        for(int k = 0; k < 11; k++) {
          input[start[k] + i]->value(str);
          if(input[start[k] + i]->parent()->active()) {
            input[start[k] + i]->do_callback(nullptr, (void *)"no_redraw");
          }
        }
      }
    }
  }
}

void elementaryContextWindow::show(int pane)
{
  FlGui::instance()->lastContextWindow = 0;

  if(pane < 0 || pane > 11) return;

  for(int i = 0; i < 12; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }

  if(pane < 6) {
    tab1->show();
    tab2->hide();
  }
  else {
    tab1->hide();
    tab2->show();
  }

  group[pane]->show();
  group[pane]->activate();
  win->show();
}

static void physical_add_cb(Fl_Widget *w, void *data)
{
  std::string what = data ? (const char *)data : "";

  physicalContextWindow *pc = FlGui::instance()->physicalContext;
  std::string name = pc->input[0]->value();
  int tag = pc->value[0]->value();
  std::string existingName = "";
  int existingTag = 0;
  if(what != "Tag") {
    auto it = pc->physicalNames.find(name);
    if(it != pc->physicalNames.end()) {
      existingName = name;
      existingTag = it->second;
    }
  }
  if(what != "Name") {
    auto it = pc->physicalTags.find(tag);
    if(it != pc->physicalTags.end()) {
      existingTag = tag;
      existingName = it->second;
    }
  }

  if(existingName.size() || existingTag) {
    // change color to warn that the group exists
    Fl_Color c = (!CTX::instance()->guiColorScheme ? FL_DARK_BLUE : FL_BLUE);
    pc->input[0]->textcolor(c);
    pc->value[0]->textcolor(c);
    if(what != "Name" && !strlen(pc->input[0]->value()))
      pc->input[0]->value(existingName.c_str());
    if(what != "Tag") pc->value[0]->value(existingTag);
    pc->append = true;
  }
  else {
    pc->input[0]->textcolor(FL_FOREGROUND_COLOR);
    pc->value[0]->textcolor(FL_FOREGROUND_COLOR);
    if(what != "Tag") pc->value[0]->value(NEWPHYSICAL());
    pc->append = false;
  }

  if(pc->butt[0]->active()) {
    if(pc->butt[0]->value())
      pc->value[0]->deactivate();
    else
      pc->value[0]->activate();
  }

  pc->input[0]->redraw();
  pc->value[0]->redraw();

  pc->selectedName = pc->input[0]->value();
  pc->selectedTag = pc->value[0]->value();
}

static void physical_remove_cb(Fl_Widget *w, void *data)
{
  physicalContextWindow *pc = FlGui::instance()->physicalContext;
  int tag = 0;
  std::string name = "";
  if(pc->choice[0]->text()) {
    std::vector<std::string> tmp = SplitString(pc->choice[0]->text(), ':');
    tag = (tmp.size() > 0) ? atoi(tmp[0].c_str()) : 0;
    name = (tmp.size() > 1) ? tmp[1] : "";
  }

  pc->selectedName = name;
  pc->selectedTag = tag;
}

physicalContextWindow::physicalContextWindow(int deltaFontSize)
  : selectedTag(0), type(""), mode("Add"), selectedName(""), append(false)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 30 * FL_NORMAL_SIZE;
  int height = 5 * WB + 4 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Physical Group Context");
  win->box(GMSH_WINDOW_BOX);

  {
    tab = new Fl_Tabs(WB, WB, width - 2 * WB, 4 * BH + 3 * WB);
    // 0: Add
    {
      group[0] =
        new Fl_Group(WB, WB + BH, width - 2 * WB, 3 * BH + 3 * WB, "Add");

      box[0] = new Fl_Box(2 * WB, 2 * WB + 1 * BH, width, BH);
      box[0]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      input[0] = new Fl_Input_Choice(2 * WB, 2 * WB + 2 * BH,
                                     (int)(0.6 * width), BH, "Name");
      input[0]->value("");
      input[0]->align(FL_ALIGN_RIGHT);
      input[0]->callback(physical_add_cb, (void *)"Name");
      input[0]->when(FL_WHEN_CHANGED);

      value[0] = new Fl_Value_Input(2 * WB, 2 * WB + 3 * BH, (int)(0.6 * width),
                                    BH, "Tag");
      value[0]->value(0);
      value[0]->deactivate();
      value[0]->align(FL_ALIGN_RIGHT);
      value[0]->callback(physical_add_cb, (void *)"Tag");
      value[0]->when(FL_WHEN_CHANGED);

      butt[0] = new Fl_Check_Button(width - width / 4, 2 * WB + 3 * BH,
                                    width / 4 - 2 * WB, BH, "Automatic");
      butt[0]->value(1);
      butt[0]->callback(physical_add_cb);

      group[0]->end();
    }
    // 1: Remove
    {
      group[1] =
        new Fl_Group(WB, WB + BH, width - 2 * WB, 3 * BH + 3 * WB, "Remove");

      box[1] = new Fl_Box(2 * WB, 2 * WB + 1 * BH, width, BH);
      box[1]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      choice[0] =
        new Fl_Choice(2 * WB, 2 * WB + 2 * BH, (int)(0.6 * width), BH);
      choice[0]->align(FL_ALIGN_RIGHT);
      choice[0]->callback(physical_remove_cb);

      group[1]->end();
    }
    tab->end();
  }

  win->position(CTX::instance()->ctxPosition[0],
                CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void physicalContextWindow::show(const std::string &what, bool remove)
{
  FlGui::instance()->lastContextWindow = 3;

  // update window title and labels
  type = what;
  int dim;
  if(type == "Volume")
    dim = 3;
  else if(type == "Surface")
    dim = 2;
  else if(type == "Curve")
    dim = 1;
  else if(type == "Point")
    dim = 0;
  else {
    Msg::Error("Unknown physical context '%s'", type.c_str());
    return;
  }
  win->copy_label(std::string("Physical " + type + " Context").c_str());
  std::string s(" and select " + type + "(s) to ");
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  box[0]->copy_label(
    std::string("Create or choose group," + s + "add").c_str());
  box[1]->copy_label(std::string("Choose group" + s + "remove").c_str());

  // get all physical group tags and names (this is relatively expensive - so we
  // shouldn't do it in the callbacks)
  std::map<int, std::vector<GEntity *> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  physicalTags.clear();
  physicalNames.clear();
  for(auto &p : groups) {
    std::string name = GModel::current()->getPhysicalName(dim, p.first);
    physicalTags[p.first] = name;
    if(name.size()) physicalNames[name] = p.first;
  }

  // create menus with existing physicals
  std::vector<Fl_Menu_Item> menuAdd, menuRemove;
  static std::vector<char *> toFree;
  for(std::size_t i = 0; i < toFree.size(); i++) free(toFree[i]);
  toFree.clear();
  {
    for(auto &p : physicalNames) {
      char *str = strdup(p.first.c_str());
      Fl_Menu_Item item = {str, 0, nullptr, nullptr, 0};
      toFree.push_back(str);
      menuAdd.push_back(item);
    }
    Fl_Menu_Item item = {nullptr};
    menuAdd.push_back(item);
    input[0]->menubutton()->copy(&menuAdd[0]);
  }
  {
    for(auto &p : physicalTags) {
      std::string label = std::to_string(p.first);
      if(p.second.size()) label += ": " + p.second;
      char *str = strdup(label.c_str());
      Fl_Menu_Item item = {str, 0, nullptr, nullptr, 0};
      toFree.push_back(str);
      menuRemove.push_back(item);
    }
    Fl_Menu_Item item = {nullptr};
    menuRemove.push_back(item);
    choice[0]->copy(&menuRemove[0]);
  }

  // activate the relevant tabs and widgets
  for(int i = 0; i < 2; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }
  if(remove) {
    mode = "Remove";
    group[1]->show();
    group[1]->activate();
    physical_remove_cb(nullptr, nullptr);
  }
  else {
    mode = "Add";
    group[0]->show();
    group[0]->activate();
    if(butt[0]->value())
      value[0]->deactivate();
    else
      value[0]->activate();
    physical_add_cb(nullptr, (void *)"Name");
  }

  if(!win->shown()) win->show();
}

static Fl_Menu_Item menu_selection_mode[] = {
  {"All entities", 0, nullptr, nullptr}, {"Points", 0, nullptr, nullptr},
  {"Curves", 0, nullptr, nullptr},       {"Surfaces", 0, nullptr, nullptr},
  {"Volumes", 0, nullptr, nullptr},      {nullptr}};

static void selection_mode_cb(Fl_Widget *w, void *data)
{
  Fl_Choice *c = (Fl_Choice *)w;
  int mode = ENT_ALL;
  switch(c->value()) {
  case 1:
    mode = ENT_POINT;
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
    break;
  case 2:
    mode = ENT_CURVE;
    opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
    break;
  case 3:
    mode = ENT_SURFACE;
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
    break;
  case 4:
    mode = ENT_VOLUME;
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
    break;
  }
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
    for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
      FlGui::instance()->graph[i]->gl[j]->changeSelection = mode;
  drawContext::global()->draw();
}

transformContextWindow::transformContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 36 * FL_NORMAL_SIZE;
  int height = 5 * WB + 10 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Elementary Operation Context");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
    // 0: Translate
    {
      group[0] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Translate");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "DX");
      input[0]->value("0");
      input[1] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "DY");
      input[1]->value("0");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "DZ");
      input[2]->value("1");
      for(int i = 0; i < 3; i++) { input[i]->align(FL_ALIGN_RIGHT); }
      butt[0] = new Fl_Check_Button(2 * WB, 2 * WB + 4 * BH, width - 4 * WB, BH,
                                    "Apply translation on copy");
      butt[0]->value(0);
      butt[7] = new Fl_Check_Button(2 * WB, 2 * WB + 5 * BH, width - 4 * WB, BH,
                                    "Extrude mesh");
      butt[7]->value(0);
      input[21] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Mesh layers");
      input[21]->value("5");
      input[21]->align(FL_ALIGN_RIGHT);
      butt[8] = new Fl_Check_Button(width / 2 + 2 * WB, 2 * WB + 6 * BH,
                                    width / 2 - 4 * WB, BH, "Recombine");
      butt[8]->value(1);
      group[0]->end();
    }
    // 1: Rotate
    {
      group[1] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Rotate");
      input[3] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Axis point X");
      input[3]->value("0");
      input[4] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Axis point Y");
      input[4]->value("0");
      input[5] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Axis point Z");
      input[5]->value("0");
      input[6] =
        new Fl_Input(width / 2 + 2 * WB, 2 * WB + 1 * BH, IW/2, BH, "Axis direction DX");
      input[6]->value("0");
      input[7] =
        new Fl_Input(width / 2 + 2 * WB, 2 * WB + 2 * BH, IW/2, BH, "Axis direction DY");
      input[7]->value("1");
      input[8] =
        new Fl_Input(width / 2 + 2 * WB, 2 * WB + 3 * BH, IW/2, BH, "Axis direction DZ");
      input[8]->value("0");
      input[9] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Angle");
      input[9]->value("Pi/4");
      for(int i = 3; i < 10; i++) { input[i]->align(FL_ALIGN_RIGHT); }
      butt[1] = new Fl_Check_Button(2 * WB, 2 * WB + 5 * BH, width - 4 * WB, BH,
                                    "Apply rotation on copy");
      butt[1]->value(0);
      butt[9] = new Fl_Check_Button(2 * WB, 2 * WB + 6 * BH, width - 4 * WB, BH,
                                    "Extrude mesh");
      butt[9]->value(0);
      input[22] = new Fl_Input(2 * WB, 2 * WB + 7 * BH, IW, BH, "Mesh layers");
      input[22]->value("5");
      input[22]->align(FL_ALIGN_RIGHT);
      butt[10] = new Fl_Check_Button(width / 2 + 2 * WB, 2 * WB + 7 * BH,
                                     width / 2 - 4 * WB, BH, "Recombine");
      butt[10]->value(1);
      group[1]->end();
    }
    // 2: Scale
    {
      group[2] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Scale");
      input[10] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X");
      input[10]->value("0");
      input[11] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y");
      input[11]->value("0");
      input[12] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z");
      input[12]->value("0");
      input[13] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Scaling X");
      input[13]->value("0.5");
      input[14] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Scaling Y");
      input[14]->value("0.5");
      input[15] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Scaling Z");
      input[15]->value("0.5");
      for(int i = 10; i < 16; i++) { input[i]->align(FL_ALIGN_RIGHT); }
      butt[2] = new Fl_Check_Button(2 * WB, 2 * WB + 7 * BH, width - 4 * WB, BH,
                                    "Apply scaling on copy");
      butt[2]->value(0);
      group[2]->end();
    }
    // 3: Symmetry
    {
      group[3] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Symmetry");
      input[16] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Symmetry plane coefficient A");
      input[16]->value("1");
      input[17] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Symmetry plane coefficient B");
      input[17]->value("0");
      input[18] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Symmetry plane coefficient C");
      input[18]->value("0");
      input[19] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Symmetry plane coefficient D");
      input[19]->value("1");
      for(int i = 16; i < 20; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->tooltip("A * X + B * Y + C * Z + D = 0");
      }
      butt[3] = new Fl_Check_Button(2 * WB, 2 * WB + 5 * BH, width - 4 * WB, BH,
                                    "Apply symmetry on copy");
      butt[3]->value(0);
      group[3]->end();
    }
    // 4: Boolean
    {
      group[4] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Boolean");
      butt[4] = new Fl_Check_Button(2 * WB, 2 * WB + 1 * BH, width - 4 * WB, BH,
                                    "Delete object");
      butt[4]->value(1);
      butt[5] = new Fl_Check_Button(2 * WB, 2 * WB + 2 * BH, width - 4 * WB, BH,
                                    "Delete tool");
      butt[5]->value(1);
      group[4]->end();
    }
    // 5: Fillet
    {
      group[5] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Fillet");
      input[20] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Radius");
      input[20]->value("0.1");
      input[20]->align(FL_ALIGN_RIGHT);
      group[5]->end();
    }
    // 6: Delete
    {
      group[6] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Delete");
      butt[6] = new Fl_Check_Button(2 * WB, 2 * WB + 1 * BH, width - 4 * WB, BH,
                                    "Recursive");
      butt[6]->value(1);
      group[6]->end();
    }
    o->end();
  }

  choice = new Fl_Choice(WB, height - WB - BH, IW, BH, "Selection mode");
  choice->menu(menu_selection_mode);
  choice->align(FL_ALIGN_RIGHT);
  choice->callback(selection_mode_cb);

  win->position(CTX::instance()->ctxPosition[0],
                CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void transformContextWindow::show(int pane, bool extrude, bool selection)
{
  FlGui::instance()->lastContextWindow = 1;

  for(int i = 0; i < 7; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }
  for(int i = 0; i < 4; i++) {
    if(extrude)
      butt[i]->deactivate();
    else
      butt[i]->activate();
  }
  for(int i = 7; i < 11; i++) {
    if(!extrude)
      butt[i]->deactivate();
    else
      butt[i]->activate();
  }
  for(int i = 21; i < 23; i++) {
    if(!extrude)
      input[i]->deactivate();
    else
      input[i]->activate();
  }
  if(selection)
    choice->activate();
  else
    choice->deactivate();
  if(pane < 0 || pane > 6) { group[0]->show(); }
  else {
    group[pane]->show();
    group[pane]->activate();
  }
  win->show();
}

meshContextWindow::meshContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  static Fl_Menu menu_transfinite_dir[] = {{"Left", 0, nullptr, nullptr},
                                           {"Right", 0, nullptr, nullptr},
                                           {"Alternated", 0, nullptr, nullptr},
                                           {nullptr}};

  int width = 29 * FL_NORMAL_SIZE;
  int height = 4 * WB + 4 * BH;

  win = new paletteWindow(width, height, CTX::instance()->nonModalWindows,
                          "Mesh Context");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 2 * WB);
    // 0: Element size at points
    {
      group[0] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Element size");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Value");
      input[0]->value("0.1");
      input[0]->align(FL_ALIGN_RIGHT);
      group[0]->end();
    }
    // 1: Transfinite line
    {
      group[1] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Transfinite curve");
      input[1] =
        new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Number of points");
      input[1]->value("10");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Parameter");
      input[2]->value("1");
      for(int i = 1; i < 3; i++) { input[i]->align(FL_ALIGN_RIGHT); }
      static Fl_Menu_Item menu_trsf_mesh[] = {
        {"Progression", 0, nullptr, nullptr},
        {"Bump", 0, nullptr, nullptr},
        {"Beta", 0, nullptr, nullptr},
        {nullptr}};
      choice[0] = new Fl_Choice(2 * WB, 2 * WB + 2 * BH, IW, BH, "Type");
      choice[0]->menu(menu_trsf_mesh);
      choice[0]->align(FL_ALIGN_RIGHT);
      group[1]->end();
    }

    // 2: Transfinite surface
    {
      group[2] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Transfinite Surface");

      choice[1] = new Fl_Choice(2 * WB, 2 * WB + 1 * BH, IW, BH,
                                "Transfinite Arrangement");
      choice[1]->menu(menu_transfinite_dir);
      choice[1]->align(FL_ALIGN_RIGHT);

      group[2]->end();
    }
    o->end();
  }

  win->position(CTX::instance()->ctxPosition[0],
                CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void meshContextWindow::show(int pane)
{
  FlGui::instance()->lastContextWindow = 2;

  for(int i = 0; i < 3; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }
  group[pane]->show();
  group[pane]->activate();
  win->show();
}
