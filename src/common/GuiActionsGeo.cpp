// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The interactive geometry and mesh-definition actions of the modules tree: the
// ones that let the user pick entities in the 3D view and write what they mean
// into the .geo script. They are the shared implementation of what used to be
// the elementary, physical, transform and mesh callbacks of
// src/fltk/graphicWindow.cpp, so that both interfaces behave identically.
//
// They all follow the same shape: loop on Gui::selectEntity(), gather what was
// picked, and act on 'e'. 'u' takes the last pick back, 'q' leaves. The
// parameters come from a getter rather than from a copy, so that the panel they
// are typed in stays live while the loop runs.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <algorithm>
#include <string>
#include <vector>

#include "GuiActions.h"
#include "GuiDialogs.h"
#include "Gui.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "Context.h"
#include "ListUtils.h"
#include "OpenFile.h"
#include "Options.h"
#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "Geo.h"
#include "MallocUtils.h"
#include "VertexArray.h"
#include "mathEvaluator.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "Numeric.h"
#include "scriptStringInterface.h"
#include "drawContext.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

#if defined(HAVE_OCC)
#include "GModelIO_OCC.h"
#endif

geometryParameters::geometryParameters()
  : selection(ENT_ALL), tx("0"), ty("0"), tz("1"), ax("0"), ay("1"), az("0"),
    px("0"), py("0"), pz("0"), angle("Pi/4"), cx("0"), cy("0"), cz("0"),
    sx("0.5"), sy("0.5"), sz("0.5"), sa("1"), sb("0"), sc("0"), sd("1"),
    duplicate(false), extrudeMesh(false), layers("5"), recombineMesh(true),
    recursive(true), meshSize("0.1"), transfinitePoints("10"),
    transfiniteType("Progression"), transfiniteParameter("1"),
    transfiniteArrangement("Left"), radius("0.1"), deleteObject(true),
    deleteTool(true), physicalTag(0), physicalAppend(false),
    physicalMode("Add"), physicalAutomatic(true)
{
}

// --- the values the context dialogs hold
//
// Fixed storage rather than a vector: the dialogs bind widgets to the address
// of each field, so those addresses must not move.

geometryParameters &geometryStore()
{
  static geometryParameters store;
  return store;
}

static std::string _elementary[12][9];
static int _elementaryPane = 0;

std::string &elementaryStore(int pane, int field)
{
  static std::string nowhere;
  if(pane < 0 || pane > 11 || field < 0 || field > 8) return nowhere;
  return _elementary[pane][field];
}

int &elementaryPaneStore() { return _elementaryPane; }

bool &elementaryFrozen(int coord)
{
  static bool frozen[3] = {false, false, false};
  static bool nowhere = false;
  if(coord < 0 || coord > 2) return nowhere;
  return frozen[coord];
}

elementaryParameters elementaryStoreParameters()
{
  elementaryParameters p;
  p.pane = _elementaryPane;
  int n = geometryElementaryFieldCount(p.pane);
  for(int i = 0; i < n; i++) p.value.push_back(_elementary[p.pane][i]);
  return p;
}

// Make the entities one is about to pick visible, as the FLTK callbacks always
// did: picking something one cannot see is not much use.
static void _showEntities(int what)
{
  switch(what) {
  case ENT_POINT: opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1); break;
  case ENT_CURVE: opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1); break;
  case ENT_SURFACE: opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1); break;
  case ENT_VOLUME: opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1); break;
  }
}

// --- placing a new entity with the mouse
//
// The counterpart of the "add point mode" of the FLTK openglWindow: while it is
// on, the pointer drives the first three fields of the pane, the entity being
// built is previewed on top of the model, and 'e' writes it into the script.

// how many fields each pane of the elementary context has
static const int _elementaryFields[] = {4, 4, 6, 7, 5, 6, 7, 8, 6, 6, 9, 7};

int geometryElementaryFieldCount(int pane)
{
  if(pane < 0 || pane > 11) return 0;
  return _elementaryFields[pane];
}

bool geometryEvaluate(const std::string &str, double &val)
{
  std::vector<std::string> var;
  std::vector<double> valVar;
#if defined(HAVE_PARSER)
  for(auto it = gmsh_yysymbols.begin(); it != gmsh_yysymbols.end(); it++) {
    if(it->second.value.size() == 1) {
      var.push_back(it->first);
      valVar.push_back(it->second.value[0]);
    }
  }
#endif
  std::vector<std::string> expr(1, str);
  std::vector<double> res(1);
  mathEvaluator f(expr, var);
  if(expr.empty()) return false;
  if(!f.eval(valVar, res)) return false;
  val = res[0];
  return true;
}

// read the n first fields of the pane; false as soon as one is not a number
static bool _values(const elementaryParameters &p, int n,
                    std::vector<double> &v)
{
  if((int)p.value.size() < n) return false;
  v.resize(n);
  for(int i = 0; i < n; i++)
    if(!geometryEvaluate(p.value[i], v[i])) return false;
  return true;
}

static void _drawSTL(std::vector<SPoint3> &vertices,
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
    SVector3 nn[3] = {normals[triangles[i]], normals[triangles[i + 1]],
                      normals[triangles[i + 2]]};
    double x[3] = {p1.x(), p2.x(), p3.x()};
    double y[3] = {p1.y(), p2.y(), p3.y()};
    double z[3] = {p1.z(), p2.z(), p3.z()};
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

// an arc of circle or of ellipse, which needs no geometry kernel to preview
static void _drawArc(double xc, double yc, double zc, double rx, double ry,
                     double a1, double a2)
{
  if(a2 <= a1) return;
  glColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);
  glBegin(GL_LINE_STRIP);
  const int N = 30;
  for(int i = 0; i < N; i++) {
    double t = a1 + (double)i / (double)(N - 1) * (a2 - a1);
    glVertex3d(xc + rx * cos(t), yc + ry * sin(t), zc);
  }
  glEnd();
}

static void _drawTransientShape(void *context)
{
  elementaryParameters p = elementaryStoreParameters();
  std::vector<double> v;

  if(p.pane == 2) { // circle
    if(_values(p, 6, v)) _drawArc(v[0], v[1], v[2], v[3], v[3], v[4], v[5]);
    return;
  }
  if(p.pane == 3) { // ellipse
    if(_values(p, 7, v)) _drawArc(v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
    return;
  }

#if defined(HAVE_OCC)
  if(!GModel::current()->getOCCInternals())
    GModel::current()->createOCCInternals();
  OCC_Internals *occ = GModel::current()->getOCCInternals();
  if(!occ) return;

  std::vector<SPoint3> vertices;
  std::vector<SVector3> normals;
  std::vector<int> triangles;
  bool ok = false;
  switch(p.pane) {
  case 4: // disk
    ok = _values(p, 5, v) &&
         occ->makeDiskSTL(v[0], v[1], v[2], v[3], v[4], vertices, normals,
                          triangles);
    break;
  case 5: // rectangle
    ok = _values(p, 6, v) &&
         occ->makeRectangleSTL(v[0], v[1], v[2], v[3], v[4], v[5], vertices,
                               normals, triangles);
    break;
  case 6: // sphere
    ok = _values(p, 7, v) &&
         occ->makeSphereSTL(v[0], v[1], v[2], v[3], v[4], v[5], v[6], vertices,
                            normals, triangles);
    break;
  case 7: // cylinder
    ok = _values(p, 8, v) &&
         occ->makeCylinderSTL(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7],
                              vertices, normals, triangles);
    break;
  case 8: // box
    ok = _values(p, 6, v) &&
         occ->makeBoxSTL(v[0], v[1], v[2], v[3], v[4], v[5], vertices, normals,
                         triangles);
    break;
  case 9: // torus
    ok = _values(p, 6, v) &&
         occ->makeTorusSTL(v[0], v[1], v[2], v[3], v[4], v[5], vertices,
                           normals, triangles);
    break;
  case 10: // cone
    ok = _values(p, 9, v) &&
         occ->makeConeSTL(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
                          vertices, normals, triangles);
    break;
  case 11: // wedge
    ok = _values(p, 7, v) &&
         occ->makeWedgeSTL(v[0], v[1], v[2], v[3], v[4], v[5], v[6], vertices,
                           normals, triangles);
    break;
  default: break;
  }
  if(ok) _drawSTL(vertices, normals, triangles);
#endif
}

void geometrySetTransientShape(bool on)
{
  drawContext::setDrawGeomTransientFunction(on ? _drawTransientShape : nullptr);
}

void geometryPointUnderCursor(drawContext *ctx, int winX, int winY,
                              const bool frozen[3], double point[3])
{
  if(!ctx) return;
  // the line in real space that the cursor points along
  double p[3], d[3];
  ctx->unproject(winX, winY, p, d);
  // the point of that line closest to the centre of gravity of the model
  double r[3] = {CTX::instance()->cg[0] - p[0], CTX::instance()->cg[1] - p[1],
                 CTX::instance()->cg[2] - p[2]};
  double t = prosca(r, d);
  for(int i = 0; i < 3; i++) {
    if(frozen[i]) continue;
    point[i] = p[i] + t * d[i];
    if(CTX::instance()->geom.snap[i]) {
      double q = point[i] / CTX::instance()->geom.snap[i];
      double f = floor(q), c = ceil(q);
      point[i] = ((q - f < c - q) ? f : c) * CTX::instance()->geom.snap[i];
    }
  }
}

// what each pane creates, once the user is happy with the fields
void geometryAddElementary(const elementaryParameters &p)
{
  const std::string &f = GModel::current()->getFileName();
  const std::vector<std::string> &v = p.value;
  if((int)v.size() < geometryElementaryFieldCount(p.pane)) return;
  switch(p.pane) {
  case 0: scriptAddParameter(v[0], v[1], v[2], v[3], f); break;
  case 1: scriptAddPoint(f, v[0], v[1], v[2], v[3]); break;
  case 2: scriptAddCircle(f, v[0], v[1], v[2], v[3], v[4], v[5]); break;
  case 3: scriptAddEllipse(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6]); break;
  case 4: scriptAddDisk(f, v[0], v[1], v[2], v[3], v[4]); break;
  case 5: scriptAddRectangle(f, v[0], v[1], v[2], v[3], v[4], v[5]); break;
  case 6:
    scriptAddSphere(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
    break;
  case 7:
    scriptAddCylinder(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
    break;
  case 8: scriptAddBox(f, v[0], v[1], v[2], v[3], v[4], v[5]); break;
  case 9: scriptAddTorus(f, v[0], v[1], v[2], v[3], v[4], v[5]); break;
  case 10:
    scriptAddCone(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
    break;
  case 11:
    scriptAddWedge(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
    break;
  default: Msg::Error("Unknown entity to create"); break;
  }
  Gui::resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
}

static const char *const _elementaryName[] = {
  "parameter", "point",    "circle", "ellipse", "disk", "rectangle",
  "sphere",    "cylinder", "box",    "torus",   "cone", "wedge"};

void geometryAddPointBasedEntity(int pane)
{
  if(pane < 0 || pane > 11) return;

  // Say which shape is being placed. Everything downstream reads it from here:
  // the pointer writes the coordinates into that pane's fields, the preview is
  // drawn from them, and 'e' adds that shape. Only the "Add" button used to set
  // it, so a tool started from the tree drove whatever pane was left over.
  elementaryPaneStore() = pane;

  opt_general_axes(0, GMSH_SET | GMSH_GUI, 3);
  _showEntities(ENT_POINT);
  drawContext::global()->draw();
  geometrySetTransientShape(true);

  while(1) {
    if(!Gui::available()) break;

    // the mode is set again at every turn: ending a selection clears it
    Gui::setAddPointMode(true);
    Msg::StatusGl(
      "Move mouse and/or enter coordinates\n"
      "[Press 'Shift' to hold position, 'e' to add %s or 'q' to abort]",
      _elementaryName[pane]);
    char ib = Gui::selectEntity(ENT_NONE);
    if(!Gui::available()) break;
    if(ib == 'e') {
      geometryAddElementary(elementaryStoreParameters());
      drawContext::global()->draw();
    }
    if(ib == 'q') break;
  }

  Gui::setAddPointMode(false);
  geometrySetTransientShape(false);

  // at the end, not while placing, so that things do not jump around
  SetBoundingBox();
  drawContext::global()->draw();
  Msg::StatusGl("");
}

// --- creating curves out of points

static void _deselectLast(std::vector<int> &p)
{
  if(p.empty()) return;
  GVertex *gv = GModel::current()->getVertexByTag(p.back());
  if(gv) gv->setSelection(0);
  drawContext::global()->draw();
  p.pop_back();
}

// The three "pick N points and make something out of them" actions only differ
// by how many points they need and what they call once they have them.
pickedEntities &geometryPicked()
{
  static pickedEntities picked;
  return picked;
}

void geometryUnpick(int index)
{
  pickedEntities &picked = geometryPicked();
  if(index < 0 || index >= (int)picked.tags.size()) return;
  int tag = picked.tags[index];
  GEntity *e = nullptr;
  switch(picked.kind) {
  case ENT_POINT: e = GModel::current()->getVertexByTag(tag); break;
  case ENT_CURVE: e = GModel::current()->getEdgeByTag(std::abs(tag)); break;
  case ENT_SURFACE: e = GModel::current()->getFaceByTag(std::abs(tag)); break;
  default: break;
  }
  if(e) e->setSelection(0);
  picked.tags.erase(picked.tags.begin() + index);
  drawContext::global()->draw();
}

// what the picking loops accumulate into, so that a dialog can watch it
static std::vector<int> &_picking(int kind, const char *what, bool editable)
{
  pickedEntities &picked = geometryPicked();
  picked.kind = kind;
  picked.what = what;
  picked.editable = editable;
  picked.tags.clear();
  return picked.tags;
}

static void _donePicking()
{
  geometryPicked() = pickedEntities();
  Gui::refreshDialog(Dialog::Elementary);
}

// the dialog shows what has been picked, so it has to be told
static void _pickedChanged() { Gui::refreshDialog(Dialog::Elementary); }

static void _addPointBasedCurve(int numPoints, const char *const *prompts,
                                void (*create)(const std::vector<int> &))
{
  _showEntities(ENT_POINT);
  _showEntities(ENT_CURVE);
  drawContext::global()->draw();

  std::vector<int> &p = _picking(ENT_POINT, "Point", true);
  while(1) {
    if(!Gui::available()) return;

    if((int)p.size() < numPoints) {
      if(p.empty())
        Msg::StatusGl("%s\n[Press 'q' to abort]", prompts[0]);
      else
        Msg::StatusGl("%s\n[Press 'u' to undo last selection or 'q' to abort]",
                      prompts[p.size()]);
    }
    char ib = Gui::selectEntity(ENT_POINT);
    if(!Gui::available()) return;
    if(ib == 'l' && Gui::selectedVertices().size()) {
      Gui::selectedVertices()[0]->setSelection(1);
      drawContext::global()->draw();
      p.push_back(Gui::selectedVertices()[0]->tag());
      _pickedChanged();
    }
    if(ib == 'r')
      Msg::Warning("Entity de-selection not supported yet during curve "
                   "creation");
    if(ib == 'u') {
      _deselectLast(p);
      _pickedChanged();
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
    if((int)p.size() == numPoints) {
      create(p);
      Gui::resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
      _pickedChanged();
    }
  }

  _donePicking();
  Msg::StatusGl("");
}

// the type of the curve the "as many points as you like" flavour creates
static std::string _multiLineType;

static void _addMultiLine()
{
  _showEntities(ENT_POINT);
  _showEntities(ENT_CURVE);
  drawContext::global()->draw();

  std::vector<int> &p = _picking(ENT_POINT, "Point", true);
  while(1) {
    if(!Gui::available()) return;

    if(p.empty())
      Msg::StatusGl("Select control points\n"
                    "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg::StatusGl("Select control points\n"
                    "[Press 'e' to end selection, 'u' to undo last selection "
                    "or 'q' to abort]");
    char ib = Gui::selectEntity(ENT_POINT);
    if(!Gui::available()) return;
    if(ib == 'l') {
      for(auto v : Gui::selectedVertices()) {
        v->setSelection(1);
        p.push_back(v->tag());
      }
      _pickedChanged();
      drawContext::global()->draw();
    }
    if(ib == 'r')
      Msg::Warning("Entity de-selection not supported yet during multi-line "
                   "creation");
    if(ib == 'e') {
      if(p.size() >= 2)
        scriptAddCurve(_multiLineType, p, GModel::current()->getFileName());
      Gui::resetVisibility();
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
    if(ib == 'u') {
      _deselectLast(p);
      _pickedChanged();
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
  }

  _donePicking();
  Msg::StatusGl("");
}

void geometryAddCurve(const std::string &type)
{
  if(type == "Line") {
    static const char *const prompts[] = {"Select start point",
                                          "Select end point"};
    _addPointBasedCurve(2, prompts, [](const std::vector<int> &p) {
      std::vector<int> q(p);
      scriptAddCurve("Line", q, GModel::current()->getFileName());
    });
  }
  else {
    _multiLineType = type;
    _addMultiLine();
  }
}

void geometryAddCircleArc()
{
  static const char *const prompts[] = {"Select start point",
                                        "Select center point",
                                        "Select end point"};
  _addPointBasedCurve(3, prompts, [](const std::vector<int> &p) {
    scriptAddCircleArc(p[0], p[1], p[2], GModel::current()->getFileName());
  });
}

void geometryAddEllipseArc()
{
  static const char *const prompts[] = {
    "Select start point", "Select center point", "Select major axis point",
    "Select end point"};
  _addPointBasedCurve(4, prompts, [](const std::vector<int> &p) {
    scriptAddEllipseArc(p[0], p[1], p[2], p[3],
                        GModel::current()->getFileName());
  });
}

// --- creating surfaces and volumes out of their boundary

// Gather the whole contour the given entity belongs to, and select it.
static int _selectContour(int type, int num, List_T *list)
{
  int k = 0;

  switch(type) {
  case ENT_CURVE:
    k = allEdgesLinked(num, list);
    for(int i = 0; i < List_Nbr(list); i++) {
      int ip;
      List_Read(list, i, &ip);
      GEdge *ge = GModel::current()->getEdgeByTag(std::abs(ip));
      if(ge) ge->setSelection(1);
    }
    break;
  case ENT_SURFACE:
    k = allFacesLinked(num, list);
    for(int i = 0; i < List_Nbr(list); i++) {
      int ip;
      List_Read(list, i, &ip);
      GFace *gf = GModel::current()->getFaceByTag(std::abs(ip));
      if(gf) gf->setSelection(1);
    }
    break;
  }

  drawContext::global()->draw();
  return k;
}

static void _deselectLastOfContour(int type, List_T *list)
{
  if(List_Nbr(list) <= 0) return;
  int num;
  List_Read(list, List_Nbr(list) - 1, &num);
  if(type == ENT_CURVE) {
    GEdge *ge = GModel::current()->getEdgeByTag(std::abs(num));
    if(ge) ge->setSelection(0);
  }
  else {
    GFace *gf = GModel::current()->getFaceByTag(std::abs(num));
    if(gf) gf->setSelection(0);
  }
  List_Pop(list);
  drawContext::global()->draw();
}

// Which tool each pane of the elementary dialog runs. The first twelve place a
// shape whose parameters are typed; the rest pick their entities in the view.
static void _runElementaryPane(int pane)
{
  static const char *const curves[] = {"Line", "Spline", "Bezier", "BSpline"};
  if(pane >= 0 && pane <= 11)
    geometryAddPointBasedEntity(pane);
  else if(pane >= 12 && pane <= 15)
    geometryAddCurve(curves[pane - 12]);
  else if(pane == 16)
    geometryAddCircleArc();
  else if(pane == 17)
    geometryAddEllipseArc();
  else if(pane >= 18 && pane <= 20)
    geometryAddSurfaceVolume(pane - 18);
}

// the pane asked for while a tool is running, -1 when none is
static int _nextElementaryPane = -1;

void geometryElementaryRestart(int pane)
{
  if(pane < 0 || pane > 20) return;
  _nextElementaryPane = pane;
  // the running tool ends as if 'q' had been pressed, and geometryElementary()
  // starts the one that was asked for
  Gui::abortSelection();
}

void geometryElementary(int pane)
{
  while(pane >= 0) {
    _nextElementaryPane = -1;
    Dialog::show(Dialog::Elementary, pane);
    _runElementaryPane(pane);
    if(!Gui::available()) return;
    pane = _nextElementaryPane;
  }
}

void geometryAddSurfaceVolume(int mode)
{
  List_T *contour = List_Create(10, 10, sizeof(int));
  List_T *loops = List_Create(10, 10, sizeof(int));

  // What the dialog shows: the loops gathered so far, the first being the
  // outer boundary and the rest the holes. They are written to the script as
  // they are closed, so there is nothing to take back from here.
  std::vector<int> &shown =
    _picking(0, (mode == 2) ? "Surface loop" : "Curve loop", false);
  geometryPicked().memberWhat = (mode == 2) ? "Surface" : "Curve";
  // what each loop closed, kept as it is closed: the contour is reset straight
  // afterwards, so this is the only moment it is known
  std::vector<std::vector<int> > gathered;
  auto keepContour = [&]() {
    std::vector<int> one;
    for(int i = 0; i < List_Nbr(contour); i++) {
      int t;
      List_Read(contour, i, &t);
      one.push_back(t);
    }
    gathered.push_back(one);
  };
  auto showLoops = [&]() {
    shown.clear();
    for(int i = 0; i < List_Nbr(loops); i++) {
      int t;
      List_Read(loops, i, &t);
      shown.push_back(t);
    }
    if(shown.empty()) gathered.clear();
    geometryPicked().members = gathered;
    _pickedChanged();
  };

  int type;
  if(mode == 2) {
    type = ENT_SURFACE;
    _showEntities(ENT_SURFACE);
    _showEntities(ENT_VOLUME);
  }
  else {
    type = ENT_CURVE;
    _showEntities(ENT_CURVE);
    _showEntities(ENT_SURFACE);
  }
  drawContext::global()->draw();

  const char *boundary =
    (type == ENT_CURVE) ? "Select surface boundary" : "Select volume boundary";

  while(1) {
    if(!Gui::available()) goto stopall;

    List_Reset(contour);
    List_Reset(loops);
    showLoops();

    while(1) {
      if(!Gui::available()) goto stopall;

      if(!List_Nbr(contour))
        Msg::StatusGl("%s\n[Press 'q' to abort]", boundary);
      else
        Msg::StatusGl("%s\n[Press 'u' to undo last selection or 'q' to abort]",
                      boundary);

      char ib = Gui::selectEntity(type);
      if(!Gui::available()) goto stopall;
      if(ib == 'q') {
        GModel::current()->setSelection(0);
        drawContext::global()->draw();
        goto stopall;
      }
      if(ib == 'u') _deselectLastOfContour(type, contour);
      if(ib == 'r')
        Msg::Warning("Entity de-selection not supported yet during "
                     "surface/volume creation");
      if(ib == 'l') {
        bool empty = (type == ENT_CURVE) ? Gui::selectedEdges().empty() :
                                           Gui::selectedFaces().empty();
        if(empty) continue;
        int num = (type == ENT_CURVE) ? Gui::selectedEdges()[0]->tag() :
                                        Gui::selectedFaces()[0]->tag();
        if(!_selectContour(type, num, contour)) continue;

        if(type == ENT_CURVE)
          scriptAddCurveLoop(contour, GModel::current()->getFileName(), &num);
        else
          scriptAddSurfaceLoop(contour, GModel::current()->getFileName(), &num);
        keepContour();
        List_Reset(contour);
        List_Add(loops, &num);
        showLoops();

        // the contours picked from now on are the holes
        while(1) {
          if(!Gui::available()) goto stopall;

          if(!List_Nbr(contour))
            Msg::StatusGl("Select hole boundaries (if none, press 'e')\n"
                          "[Press 'e' to end selection or 'q' to abort]");
          else
            Msg::StatusGl(
              "Select hole boundaries\n"
              "[Press 'e' to end selection, 'u' to undo last selection "
              "or 'q' to abort]");
          ib = Gui::selectEntity(type);
          if(!Gui::available()) goto stopall;
          if(ib == 'q') {
            GModel::current()->setSelection(0);
            drawContext::global()->draw();
            goto stopall;
          }
          if(ib == 'e') {
            GModel::current()->setSelection(0);
            drawContext::global()->draw();
            List_Reset(contour);
            break;
          }
          if(ib == 'u') _deselectLastOfContour(type, contour);
          if(ib == 'l') {
            std::size_t n = (type == ENT_CURVE) ? Gui::selectedEdges().size() :
                                                  Gui::selectedFaces().size();
            for(std::size_t i = 0; i < n; i++) {
              int t = (type == ENT_CURVE) ? Gui::selectedEdges()[i]->tag() :
                                            Gui::selectedFaces()[i]->tag();
              if(_selectContour(type, t, contour)) {
                if(type == ENT_CURVE)
                  scriptAddCurveLoop(contour, GModel::current()->getFileName(),
                                     &t);
                else
                  scriptAddSurfaceLoop(contour,
                                       GModel::current()->getFileName(), &t);
                keepContour();
                List_Reset(contour);
                List_Add(loops, &t);
                showLoops();
              }
            }
          }
          if(ib == 'r')
            Msg::Warning("Entity de-selection not supported yet during "
                         "surface/volume creation");
        }

        List_Unique(loops, fcmp_absint);
        if(List_Nbr(loops)) {
          switch(mode) {
          case 0:
            scriptAddSurface("Plane Surface", loops,
                             GModel::current()->getFileName());
            break;
          case 1:
            scriptAddSurface("Surface", loops,
                             GModel::current()->getFileName());
            break;
          case 2: scriptAddVolume(loops, GModel::current()->getFileName()); break;
          }
          Gui::resetVisibility();
          GModel::current()->setSelection(0);
          drawContext::global()->draw();
          break;
        }
      }
    }
  }

stopall:
  List_Delete(contour);
  List_Delete(loops);
  _donePicking();
  Msg::StatusGl("");
}

// --- splitting a curve

void geometrySplitCurve()
{
  _showEntities(ENT_CURVE);
  drawContext::global()->draw();
  Msg::StatusGl("Select curve to split\n[Press 'q' to abort]");

  GEdge *toSplit = nullptr;
  while(1) {
    if(!Gui::available()) return;
    char ib = Gui::selectEntity(ENT_CURVE);
    if(!Gui::available()) return;
    if(ib == 'q') break;
    if(!Gui::selectedEdges().empty()) {
      toSplit = Gui::selectedEdges()[0];
      toSplit->setSelection(1);
      break;
    }
  }
  Msg::StatusGl("");
  if(!toSplit) return;

  List_T *points = List_Create(5, 5, sizeof(int));
  Msg::StatusGl("Select break points\n"
                "[Press 'e' to end selection or 'q' to abort]");
  _showEntities(ENT_POINT);
  drawContext::global()->draw();
  while(1) {
    if(!Gui::available()) {
      List_Delete(points);
      return;
    }
    char ib = Gui::selectEntity(ENT_POINT);
    if(!Gui::available()) {
      List_Delete(points);
      return;
    }
    if(ib == 'q') break;
    if(ib == 'e') {
      scriptSplitCurve(toSplit->tag(), points,
                       GModel::current()->getFileName());
      break;
    }
    for(auto v : Gui::selectedVertices()) {
      int tag = v->tag();
      if(List_ISearchSeq(points, &tag, fcmp_int) < 0) List_Add(points, &tag);
      v->setSelection(1);
    }
  }
  List_Delete(points);

  Msg::StatusGl("");
  Gui::resetVisibility();
  GModel::current()->setSelection(0);
  drawContext::global()->draw();
}

// --- boolean operations and fillets

void geometryBoolean(const std::string &op)
{
  bool selectObject = true;
  std::vector<std::pair<int, int> > object, tool;

  while(1) {
    if(!Gui::available()) return;

    if(selectObject)
      Msg::StatusGl("Select object\n"
                    "[Press 'e' to end selection%s or 'q' to abort]",
                    object.empty() ? "" : ", 'u' to undo last selection");
    else
      Msg::StatusGl("Select tool\n"
                    "[Press 'e' to end selection%s or 'q' to abort]",
                    tool.empty() ? "" : ", 'u' to undo last selection");

    char ib = Gui::selectEntity(geometryStore().selection);
    if(!Gui::available()) return;

    if(ib == 'l') {
      std::vector<GEntity *> picked;
      for(auto v : Gui::selectedVertices()) picked.push_back(v);
      for(auto e : Gui::selectedEdges()) picked.push_back(e);
      for(auto f : Gui::selectedFaces()) picked.push_back(f);
      for(auto r : Gui::selectedRegions()) picked.push_back(r);
      for(auto g : picked) {
        if(g->getSelection() == 1) continue;
        g->setSelection(1);
        std::pair<int, int> t(g->dim(), g->tag());
        if(selectObject)
          object.push_back(t);
        else
          tool.push_back(t);
      }
    }
    if(ib == 'r')
      Msg::Warning("Entity de-selection not supported yet during boolean "
                   "operation");
    if(ib == 'u') {
      std::vector<std::pair<int, int> > *l = nullptr;
      if(selectObject && object.size())
        l = &object;
      else if(tool.size())
        l = &tool;
      if(l) {
        GEntity *ge = GModel::current()->getEntityByTag(l->back().first,
                                                        l->back().second);
        if(ge) ge->setSelection(0);
        l->pop_back();
      }
    }
    if(ib == 'e') {
      if(selectObject) {
        if(object.empty())
          Msg::Error("At least one object must be selected");
        else
          selectObject = false;
      }
      else if(tool.empty() && op != "BooleanFragments") {
        Msg::Error("At least one tool must be selected");
      }
      else {
        geometryParameters p = geometryStore();
        scriptBoolean(GModel::current()->getFileName(), op, object, tool,
                      p.deleteObject ? 1 : 0, p.deleteTool ? 1 : 0);
        GModel::current()->setSelection(0);
        selectObject = true;
        object.clear();
        tool.clear();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  drawContext::global()->draw();
  Msg::StatusGl("");
}

void geometryFillet()
{
  _showEntities(ENT_VOLUME);
  _showEntities(ENT_CURVE);

  bool selectRegions = true;
  std::vector<int> regions, edges;

  while(1) {
    if(!Gui::available()) return;

    if(selectRegions)
      Msg::StatusGl("Select volume\n"
                    "[Press 'e' to end selection%s or 'q' to abort]",
                    regions.empty() ? "" : ", 'u' to undo last selection");
    else
      Msg::StatusGl("Select curve\n"
                    "[Press 'e' to end selection%s or 'q' to abort]",
                    edges.empty() ? "" : ", 'u' to undo last selection");

    char ib = Gui::selectEntity(selectRegions ? ENT_VOLUME : ENT_CURVE);
    if(!Gui::available()) return;
    if(ib == 'l') {
      for(auto e : Gui::selectedEdges()) {
        if(e->getSelection() != 1) {
          e->setSelection(1);
          edges.push_back(e->tag());
        }
      }
      for(auto r : Gui::selectedRegions()) {
        if(r->getSelection() != 1) {
          r->setSelection(1);
          regions.push_back(r->tag());
        }
      }
    }
    if(ib == 'r')
      Msg::Warning("Entity de-selection not supported yet during fillet");
    if(ib == 'u') {
      if(selectRegions && regions.size()) {
        GRegion *gr = GModel::current()->getRegionByTag(regions.back());
        if(gr) gr->setSelection(0);
        regions.pop_back();
      }
      else if(edges.size()) {
        GEdge *ge = GModel::current()->getEdgeByTag(edges.back());
        if(ge) ge->setSelection(0);
        edges.pop_back();
      }
    }
    if(ib == 'e') {
      if(selectRegions) {
        if(regions.empty())
          Msg::Error("At least one volume must be selected");
        else
          selectRegions = false;
      }
      else if(edges.empty()) {
        Msg::Error("At least one curve must be selected");
      }
      else {
        scriptFillet(GModel::current()->getFileName(), regions, edges,
                     geometryStore().radius);
        GModel::current()->setSelection(0);
        selectRegions = true;
        regions.clear();
        edges.clear();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  drawContext::global()->draw();
  Msg::StatusGl("");
}

// --- everything that is "pick entities, then do this to them"

void geometryActOnSelection(int action, const std::string &whatIn)
{
  drawContext::global()->draw();

  std::string what(whatIn);
  if(what == "Point")
    _showEntities(ENT_POINT);
  else if(what == "Curve")
    _showEntities(ENT_CURVE);
  else if(what == "Surface")
    _showEntities(ENT_SURFACE);
  else if(what == "Volume")
    _showEntities(ENT_VOLUME);

  std::vector<std::pair<int, int> > dimTags, dimTagsSaved;

  while(1) {
    if(!Gui::available()) return;

    std::string str;
    int type;
    if(what == "Point") {
      str = "points";
      type = ENT_POINT;
    }
    else if(what == "Curve") {
      str = "curves";
      type = ENT_CURVE;
    }
    else if(what == "Surface") {
      str = "surfaces";
      type = ENT_SURFACE;
    }
    else if(what == "Volume") {
      str = "volumes";
      type = ENT_VOLUME;
    }
    else {
      type = geometryStore().selection;
      switch(type) {
      case ENT_POINT: str = "points"; break;
      case ENT_CURVE: str = "curves"; break;
      case ENT_SURFACE: str = "surfaces"; break;
      case ENT_VOLUME: str = "volumes"; break;
      default: str = "entities"; break;
      }
    }

    if(dimTags.empty())
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection or 'q' to abort]",
                    str.c_str());
    else
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection, 'u' to undo last selection "
                    "or 'q' to abort]",
                    str.c_str());

    char ib = Gui::selectEntity(type);
    if(!Gui::available()) return;

    if(ib == 'l') {
      std::vector<GEntity *> picked;
      for(auto v : Gui::selectedVertices()) picked.push_back(v);
      for(auto e : Gui::selectedEdges()) picked.push_back(e);
      for(auto f : Gui::selectedFaces()) picked.push_back(f);
      for(auto r : Gui::selectedRegions()) picked.push_back(r);
      for(auto g : picked) {
        g->setSelection(1);
        std::pair<int, int> t(g->dim(), g->tag());
        if(std::find(dimTags.begin(), dimTags.end(), t) == dimTags.end())
          dimTags.push_back(t);
      }
      drawContext::global()->draw();
    }
    if(ib == 'r') {
      std::vector<GEntity *> picked;
      for(auto v : Gui::selectedVertices()) picked.push_back(v);
      for(auto e : Gui::selectedEdges()) picked.push_back(e);
      for(auto f : Gui::selectedFaces()) picked.push_back(f);
      for(auto r : Gui::selectedRegions()) picked.push_back(r);
      for(auto g : picked) {
        std::pair<int, int> t(g->dim(), g->tag());
        auto it = std::find(dimTags.begin(), dimTags.end(), t);
        if(it != dimTags.end()) {
          dimTags.erase(it);
          g->setSelection(0);
        }
      }
      drawContext::global()->draw();
    }
    if(ib == 'u') {
      if(dimTags.size()) {
        std::pair<int, int> t = dimTags.back();
        GEntity *ge = GModel::current()->getEntityByTag(t.first, t.second);
        if(ge) ge->setSelection(0);
        dimTags.pop_back();
        drawContext::global()->draw();
      }
    }
    if(ib == 'i') Msg::Error("Inverting selection!");
    if(ib == 'e' && dimTags.size()) {
      geometryParameters p = geometryStore();
      const std::string &f = GModel::current()->getFileName();
      switch(action) {
      case GEO_ACTION_TRANSLATE:
        scriptTranslate(f, dimTags, p.tx, p.ty, p.tz, p.duplicate);
        break;
      case GEO_ACTION_ROTATE:
        scriptRotate(f, dimTags, p.ax, p.ay, p.az, p.px, p.py, p.pz, p.angle,
                     p.duplicate);
        break;
      case GEO_ACTION_SCALE:
        scriptDilate(f, dimTags, p.cx, p.cy, p.cz, p.sx, p.sy, p.sz,
                     p.duplicate);
        break;
      case GEO_ACTION_SYMMETRY:
        scriptMirror(f, dimTags, p.sa, p.sb, p.sc, p.sd, p.duplicate);
        break;
      case GEO_ACTION_EXTRUDE_TRANSLATE:
        scriptExtrude(f, dimTags, p.tx, p.ty, p.tz, p.extrudeMesh, p.layers,
                      p.recombineMesh);
        break;
      case GEO_ACTION_EXTRUDE_ROTATE:
        scriptProtude(f, dimTags, p.ax, p.ay, p.az, p.px, p.py, p.pz, p.angle,
                      p.extrudeMesh, p.layers, p.recombineMesh);
        break;
      case GEO_ACTION_DELETE:
        scriptDeleteEntities(f, dimTags, p.recursive);
        break;
      case GEO_ACTION_PHYSICAL_ADD:
      case GEO_ACTION_PHYSICAL_REMOVE: {
        std::vector<int> tags;
        int dim = 0;
        for(std::size_t i = 0; i < dimTags.size(); i++) {
          if((dimTags[i].first == 0 && what == "Point") ||
             (dimTags[i].first == 1 && what == "Curve") ||
             (dimTags[i].first == 2 && what == "Surface") ||
             (dimTags[i].first == 3 && what == "Volume")) {
            dim = dimTags[i].first;
            tags.push_back(dimTags[i].second);
          }
        }
        scriptAddRemovePhysicalGroup(f, what, tags, p.physicalName,
                                     p.physicalTag, p.physicalAppend,
                                     p.physicalMode);
        if(!Gui::available()) return;

        // let the clients know about the new physical definition
        Gui::onelabAction("check");

        // If per-entity ONELAB parameters are defined for that kind of physical
        // group, show the window that fills them in -- and leave the selection
        // loop, because staying in it would keep outside codes from being
        // served through the API.
        bool hasTemplate = false;
#if defined(HAVE_ONELAB)
        std::vector<std::string> param;
        onelab::server::instance()->getParameterNames(
          param, "ONELAB Context/" + what + " Template");
        hasTemplate = !param.empty();
#endif
        if(tags.size() && hasTemplate && action == GEO_ACTION_PHYSICAL_ADD) {
          Gui::abortSelection();
          GModel::current()->setSelection(0);
          Gui::showContextWindow(dim, tags[0]);
          ib = 'z';
        }
        else {
          Dialog::showPhysical(what, action == GEO_ACTION_PHYSICAL_REMOVE);
        }
      } break;
      case GEO_ACTION_MESH_SIZE: {
        std::vector<int> tags;
        for(std::size_t i = 0; i < dimTags.size(); i++)
          if(dimTags[i].first == 0 && what == "Point")
            tags.push_back(dimTags[i].second);
        if(tags.size()) scriptSetMeshSize(f, tags, p.meshSize);
      } break;
      case GEO_ACTION_RECOMBINE: {
        std::vector<int> tags;
        for(std::size_t i = 0; i < dimTags.size(); i++)
          if(dimTags[i].first == 2 && what == "Surface")
            tags.push_back(dimTags[i].second);
        scriptRecombineSurface(f, tags);
      } break;
      case GEO_ACTION_COMPOUND: {
        std::vector<int> tags;
        for(std::size_t i = 0; i < dimTags.size(); i++)
          if((dimTags[i].first == 1 && what == "Curve") ||
             (dimTags[i].first == 2 && what == "Surface") ||
             (dimTags[i].first == 3 && what == "Volume"))
            tags.push_back(dimTags[i].second);
        scriptSetCompound(f, what, tags);
      } break;
      case GEO_ACTION_PIPE:
        // the first selection is what is swept, the second the curve to sweep
        // it along
        if(dimTagsSaved.empty()) {
          dimTagsSaved = dimTags;
          dimTags.clear();
          what = "Curve";
          continue;
        }
        else {
          std::vector<int> l;
          for(std::size_t i = 0; i < dimTags.size(); i++)
            if(dimTags[i].first == 1) l.push_back(dimTags[i].second);
          scriptAddPipe(f, dimTagsSaved, l);
          dimTagsSaved.clear();
        }
        break;
      default: Msg::Error("Unknown action on selected entities"); break;
      }
      dimTags.clear();
      Gui::resetVisibility();
      if(ib == 'z') break; // done: the onelab context is shown instead
      GModel::current()->setSelection(0);
      if(action <= GEO_ACTION_DELETE || action >= GEO_ACTION_PIPE)
        SetBoundingBox();
      drawContext::global()->draw();
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
  }

  Msg::StatusGl("");
}

// --- mesh constraints that need a selection of their own

void meshDefineEmbedded(const std::string &what)
{
  int type;
  const char *str = "";
  if(what == "Surface") {
    type = ENT_SURFACE;
    str = "surfaces";
  }
  else if(what == "Curve") {
    type = ENT_CURVE;
    str = "curves";
  }
  else if(what == "Point") {
    type = ENT_POINT;
    str = "points";
  }
  else {
    Msg::Error("Unknown type of entity to embed: %s", what.c_str());
    return;
  }
  _showEntities(type);

  std::vector<int> entities;
  bool selectEntities = true;

  while(1) {
    if(!Gui::available()) return;

    if(!selectEntities)
      Msg::StatusGl("Select entity in which to embed the %s\n"
                    "[Press 'q' to abort]",
                    str);
    else if(entities.empty())
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection or 'q' to abort]",
                    str);
    else
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection, 'u' to undo last selection "
                    "or 'q' to abort]",
                    str);

    int t = type;
    if(!selectEntities) {
      switch(geometryStore().selection) {
      case ENT_CURVE: t = ENT_CURVE; break;
      case ENT_SURFACE: t = ENT_SURFACE; break;
      case ENT_VOLUME: t = ENT_VOLUME; break;
      default: t = ENT_ALL; break;
      }
    }
    char ib = Gui::selectEntity(t);
    if(!Gui::available()) return;

    if(ib == 'l') {
      if(selectEntities) {
        std::vector<GEntity *> picked;
        if(what == "Point")
          for(auto v : Gui::selectedVertices()) picked.push_back(v);
        else if(what == "Curve")
          for(auto e : Gui::selectedEdges()) picked.push_back(e);
        else
          for(auto f : Gui::selectedFaces()) picked.push_back(f);
        for(auto g : picked) {
          if(g->getSelection() != 1) {
            g->setSelection(1);
            entities.push_back(g->tag());
          }
        }
      }
      else if(Gui::selectedFaces().size() || Gui::selectedRegions().size()) {
        int dim = Gui::selectedFaces().size() ? 2 : 3;
        GEntity *ge = (dim == 2) ? (GEntity *)Gui::selectedFaces()[0] :
                                   (GEntity *)Gui::selectedRegions()[0];
        ge->setSelection(1);
        drawContext::global()->draw();
        scriptEmbed(GModel::current()->getFileName(), what, entities, dim,
                    ge->tag());
        GModel::current()->setSelection(0);
        selectEntities = true;
        entities.clear();
      }
    }
    if(ib == 'r')
      Msg::Warning("Entity de-selection not supported yet while embedding");
    if(ib == 'u') {
      if(selectEntities && entities.size()) {
        int dim = (what == "Surface") ? 2 : (what == "Curve") ? 1 : 0;
        GEntity *ge = GModel::current()->getEntityByTag(dim, entities.back());
        if(ge) ge->setSelection(0);
        entities.pop_back();
      }
    }
    if(ib == 'e') {
      if(selectEntities) {
        if(entities.empty())
          Msg::Error("At least one entity must be selected");
        else
          selectEntities = false;
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  drawContext::global()->draw();
  Msg::StatusGl("");
}

void meshDefineTransfinite(int dim)
{
  _showEntities(ENT_POINT);
  switch(dim) {
  case 1: _showEntities(ENT_CURVE); break;
  case 2: _showEntities(ENT_SURFACE); break;
  case 3: _showEntities(ENT_VOLUME); break;
  }
  drawContext::global()->draw();

  std::vector<int> p;
  char ib;
  while(1) {
    if(!Gui::available()) return;

    switch(dim) {
    case 1:
      if(p.empty())
        Msg::StatusGl("Select curves\n"
                      "[Press 'e' to end selection or 'q' to abort]");
      else
        Msg::StatusGl("Select curves\n"
                      "[Press 'e' to end selection, 'u' to undo last selection "
                      "or 'q' to abort]");
      ib = Gui::selectEntity(ENT_CURVE);
      break;
    case 2:
      Msg::StatusGl("Select surface\n[Press 'q' to abort]");
      ib = Gui::selectEntity(ENT_SURFACE);
      break;
    case 3:
      Msg::StatusGl("Select volume\n[Press 'q' to abort]");
      ib = Gui::selectEntity(ENT_VOLUME);
      break;
    default: ib = 'l'; break;
    }
    if(!Gui::available()) return;

    if(ib == 'e') {
      if(dim == 1 && p.size()) {
        geometryParameters par = geometryStore();
        scriptSetTransfiniteLine(p, GModel::current()->getFileName(),
                                 par.transfiniteType,
                                 par.transfiniteParameter,
                                 par.transfinitePoints);
      }
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      p.clear();
    }
    if(ib == 'u') {
      if(dim == 1 && p.size()) {
        GEdge *ge = GModel::current()->getEdgeByTag(p.back());
        if(ge) ge->setSelection(0);
        drawContext::global()->draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
      break;
    }
    if(ib == 'r')
      Msg::Warning("Entity de-selection not supported yet during transfinite "
                   "definition");
    if(ib == 'l') {
      if(dim == 1) {
        for(auto e : Gui::selectedEdges()) {
          e->setSelection(1);
          p.push_back(e->tag());
        }
        drawContext::global()->draw();
        continue;
      }

      if(dim == 2) {
        if(Gui::selectedFaces().empty()) continue;
        Gui::selectedFaces()[0]->setSelection(1);
        p.push_back(Gui::selectedFaces()[0]->tag());
      }
      else {
        if(Gui::selectedRegions().empty()) continue;
        Gui::selectedRegions()[0]->setSelection(1);
        p.push_back(Gui::selectedRegions()[0]->tag());
      }
      drawContext::global()->draw();

      // then the corners, in order
      while(1) {
        if(!Gui::available()) return;

        if(p.size() == 1)
          Msg::StatusGl("Select (ordered) boundary points\n"
                        "[Press 'e' to end selection or 'q' to abort]");
        else
          Msg::StatusGl("Select (ordered) boundary points\n"
                        "[Press 'e' to end selection, 'u' to undo last "
                        "selection or 'q' to abort]");
        ib = Gui::selectEntity(ENT_POINT);
        if(!Gui::available()) return;
        if(ib == 'l') {
          for(auto v : Gui::selectedVertices()) {
            v->setSelection(1);
            p.push_back(v->tag());
            break;
          }
          drawContext::global()->draw();
        }
        if(ib == 'u') {
          if(p.size() > 1) {
            GVertex *gv = GModel::current()->getVertexByTag(p.back());
            if(gv) gv->setSelection(0);
            drawContext::global()->draw();
            p.pop_back();
          }
        }
        if(ib == 'r')
          Msg::Warning("Entity de-selection not supported yet during "
                       "transfinite definition");
        if(ib == 'e') {
          if(dim == 2) {
            if(p.size() == 1 || p.size() == 4 || p.size() == 5)
              scriptSetTransfiniteSurface(p, GModel::current()->getFileName(),
                                          geometryStore().transfiniteArrangement);
            else
              Msg::Error("Wrong number of points for mesh constraint");
          }
          else {
            if(p.size() == 1 || p.size() == 7 || p.size() == 9)
              scriptSetTransfiniteVolume(p, GModel::current()->getFileName());
            else
              Msg::Error("Wrong number of points for transfinite volume");
          }
          GModel::current()->setSelection(0);
          drawContext::global()->draw();
          p.clear();
          break;
        }
        if(ib == 'q') {
          GModel::current()->setSelection(0);
          drawContext::global()->draw();
          goto stopall;
        }
      }
    }
  }

stopall:
  Msg::StatusGl("");
}

#endif
