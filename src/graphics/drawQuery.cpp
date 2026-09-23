// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include "drawContext.h"
#include "Context.h"
#include "GModel.h"
#include "GEntity.h"
#include "MElement.h"
#include "MVertex.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewDataGModel.h"
#include "PViewOptions.h"
#include "SBoundingBox3d.h"

// A query says what the model holds at one point: the entity, the mesh
// element and node there, and the value of every view that covers it. The
// point comes from a pick (the depth the picking pass read back), the element
// and the node from the octree of the mesh, and the values from the octrees
// of the views. The first query of a large view builds its octree, which is
// why this is done on a click rather than while the mouse moves.
//
// What it found is said in a line for each thing ("Element: ...", "Node:
// ..."), followed by the detail of that thing, a line per number indented
// under it. The box over the picture shows the lines, the messages the detail
// as well: a line is as short as is read at a glance, the detail says every
// number exactly.

// as few figures as are read at a glance - six of a coordinate, three of a
// measure of quality - and as many as the number has
static const char *brief = "%.6g";
static const char *few = "%.3g";
static const char *full = "%.12g";

static std::string number(double d, const char *format = full)
{
  char tmp[64];
  sprintf(tmp, format, d);
  return std::string(tmp);
}

static std::string point(double x, double y, double z, const char *format)
{
  return "(" + number(x, format) + ", " + number(y, format) + ", " +
         number(z, format) + ")";
}

// a range as one number when it is one, and as an interval otherwise
static std::string range(double min, double max, const char *format)
{
  std::string a = number(min, format), b = number(max, format);
  return (a == b) ? a : (a + " to " + b);
}

// The node of the mesh closest to a point: the nodes of the elements around
// it, as the node a click is on often belongs to a neighbour of the element
// the pick returned (the point is on the node as it is drawn, a sphere or a
// square of a few pixels, rather than inside that element).
static MVertex *closestNode(const double xyz[3], MElement *element,
                            double &dist)
{
  SPoint3 p(xyz[0], xyz[1], xyz[2]);
  std::vector<MElement *> around =
    GModel::current()->getMeshElementsByCoord(p, -1, false);
  if(element) around.push_back(element);
  MVertex *v = nullptr;
  for(std::size_t i = 0; i < around.size(); i++) {
    for(std::size_t j = 0; j < around[i]->getNumVertices(); j++) {
      MVertex *w = around[i]->getVertex(j);
      double d = std::sqrt((w->x() - xyz[0]) * (w->x() - xyz[0]) +
                           (w->y() - xyz[1]) * (w->y() - xyz[1]) +
                           (w->z() - xyz[2]) * (w->z() - xyz[2]));
      if(!v || d < dist) {
        v = w;
        dist = d;
      }
    }
  }
  return v;
}

// How far from the point a view may be read when it holds nothing there. The
// point comes from what is drawn and lands on the face of an element rather
// than inside it, which the elements of a boundary layer are thin enough to
// fail, so the data is looked for a little around it: as far as the element
// the point is on reaches, when the mesh is known there (its data is at its
// nodes, an edge away at most), and a hundredth of the extent of the view
// otherwise - a measure of the view, not of the screen, as a magnified mesh
// has its nodes hundreds of pixels apart. For the view the click was on, as
// far as its glyphs reach as well: a glyph hangs from the data point and is
// as long as the arrow of a vector view (ArrowSizeMax, in pixels) or as wide
// as a point of a point view.
static double closestRange(PViewData *data, PViewOptions *opt, double pixel,
                           bool picked, double size)
{
  double px = 5.;
  if(picked) {
    px = std::max(px, opt->arrowSizeMax + 5.);
    px = std::max(px, opt->pointSize + 5.);
  }
  SBoundingBox3d bb = data->getBoundingBox();
  double extent = bb.empty() ? 0. : bb.diag();
  return std::max(std::max(px * pixel, size), 0.01 * extent);
}

// The value of a view at a point, and its detail, or nothing when the view
// holds nothing there. It is the value the view interpolates at the point
// whenever the point is inside one of its elements. It is not when the click
// landed on a glyph (the arrows of a vector view, the numbers of a scalar
// one), which hangs off the data it stands for, or when the view holds
// points, which are only ever hit exactly: the view is then read at its
// closest data point, and the line says so.
static std::vector<std::string> viewValue(PView *p, const double xyz[3],
                                          double pixel, bool picked,
                                          double size)
{
  std::vector<std::string> lines;
  PViewData *data = p->getData(true); // the adaptive data when there is one
  if(!data || data->empty()) return lines;
  PViewOptions *opt = p->getOptions();
  int step = opt->timeStep;
  if(step >= data->getNumTimeSteps()) step = data->getNumTimeSteps() - 1;
  if(step < 0) step = 0;

  std::string say, exactly;
  double reach = closestRange(data, opt, pixel, picked, size);
  double val[9], d = reach;
  if(data->searchScalarClosest(xyz[0], xyz[1], xyz[2], d, val, step)) {
    say = number(val[0], brief);
    exactly = number(val[0]);
  }
  else if(((d = reach),
           data->searchVectorClosest(xyz[0], xyz[1], xyz[2], d, val, step))) {
    double n = std::sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
    say = point(val[0], val[1], val[2], brief) + ", norm " + number(n, brief);
    exactly = point(val[0], val[1], val[2], full) + ", norm " + number(n);
  }
  else if(((d = reach),
           data->searchTensorClosest(xyz[0], xyz[1], xyz[2], d, val, step))) {
    for(int i = 0; i < 9; i++) {
      say += (i ? ", " : "(") + number(val[i], brief);
      exactly += (i ? ", " : "(") + number(val[i]);
    }
    say += ")";
    exactly += ")";
  }
  else {
    return lines;
  }

  // (a data point is a mesh node only when the view has a mesh)
  std::string what =
    dynamic_cast<PViewDataGModel *>(data) ? "node" : "data point";
  lines.push_back(
    "View[" + std::to_string(p->getIndex()) + "] \"" + data->getName() +
    "\": " + say +
    (d > 0. ? (" (closest " + what + ", " + number(d, few) + " away)") : ""));
  lines.push_back("  Value: " + exactly);
  if(data->getNumTimeSteps() > 1)
    lines.push_back("  Step: " + std::to_string(step) + ", time " +
                    number(data->getTime(step)));
  if(d > 0.)
    lines.push_back("  Read at: the closest " + what + ", " + number(d) +
                    " away");
  return lines;
}

std::vector<std::string> queryPoint(const double xyz[3], GEntity *entity,
                                    MElement *element, PView *view,
                                    double pixel)
{
  std::vector<std::string> lines;
  // (a "point" is a thing of the geometry: this is where the query asked,
  // said in the figures the depth it was read from holds and no more)
  lines.push_back("Query coordinates: " +
                  point(xyz[0], xyz[1], xyz[2], brief));

  if(entity) {
    lines.push_back("");
    lines.push_back("Entity: " + entity->getInfoString(false, false));
    SBoundingBox3d bb = entity->bounds();
    if(!bb.empty())
      lines.push_back("  Bounding box: " +
                      point(bb.min().x(), bb.min().y(), bb.min().z(), full) +
                      " to " +
                      point(bb.max().x(), bb.max().y(), bb.max().z(), full));
    lines.push_back("  Mesh: " + std::to_string(entity->getNumMeshElements()) +
                    " elements, " +
                    std::to_string(entity->mesh_vertices.size()) + " nodes");
  }

  if(element) {
    lines.push_back("");
    const char *name;
    MElement::getInfoMSH(element->getTypeForMSH(), &name);
    double sicnMin, sicnMax, sigeMin, sigeMax;
    element->signedInvCondNumRange(sicnMin, sicnMax);
    element->signedInvGradErrorRange(sigeMin, sigeMax);
    lines.push_back(
      "Element: " + std::to_string(element->getNum()) + ", " + name +
      ", Gamma " + number(element->gammaShapeMeasure(), few) + ", SICN " +
      range(sicnMin, sicnMax, few) + ", SIGE " + range(sigeMin, sigeMax, few) +
      ", edge length " + range(element->minEdge(), element->maxEdge(), few));
    lines.push_back("  Type: " + std::string(name) + " (MSH type " +
                    std::to_string(element->getTypeForMSH()) + ", dimension " +
                    std::to_string(element->getDim()) + ", order " +
                    std::to_string(element->getPolynomialOrder()) +
                    ", partition " + std::to_string(element->getPartition()) +
                    ")");
    std::string nodes = "  Nodes:";
    for(std::size_t i = 0; i < element->getNumVertices(); i++)
      nodes += " " + std::to_string(element->getVertex(i)->getNum());
    lines.push_back(nodes);
    SPoint3 bar = element->barycenter();
    lines.push_back("  Barycenter: " + point(bar.x(), bar.y(), bar.z(), full));
    lines.push_back("  Volume: " + number(element->getVolume()));
    lines.push_back("  Edge length: " +
                    range(element->minEdge(), element->maxEdge(), full));
    lines.push_back("  Inner / outer radius: " +
                    number(element->getInnerRadius()) + " / " +
                    number(element->getOuterRadius()));
    lines.push_back("  Gamma: " + number(element->gammaShapeMeasure()));
    lines.push_back("  SICN: " + range(sicnMin, sicnMax, full));
    lines.push_back("  SIGE: " + range(sigeMin, sigeMax, full));
  }

  double dist = 0.;
  MVertex *node = closestNode(xyz, element, dist);
  // a node of the element under the point is named however far it is; with
  // no element there, only a node the point is on (nodes are drawn a few
  // pixels wide)
  if(node && !element && dist > (CTX::instance()->mesh.nodeSize + 10.) * pixel)
    node = nullptr;
  if(node) {
    lines.push_back("");
    lines.push_back("Node: " + std::to_string(node->getNum()) + ", " +
                    point(node->x(), node->y(), node->z(), brief) + ", " +
                    number(dist, few) + " away");
    lines.push_back("  Coordinates: " +
                    point(node->x(), node->y(), node->z(), full));
    lines.push_back("  Distance: " + number(dist));
  }

  bool first = true;
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PView *p = PView::list[i];
    if(!p->getOptions()->visible) continue;
    std::vector<std::string> v =
      viewValue(p, xyz, pixel, p == view, element ? element->maxEdge() : 0.);
    if(v.empty()) continue;
    if(first) {
      lines.push_back("");
      first = false;
    }
    for(std::size_t j = 0; j < v.size(); j++) lines.push_back(v[j]);
  }

  return lines;
}

bool queryBehind(PView *view, const double xyz[3], const double behind[3],
                 double pixel)
{
  if(!view) return false;
  PViewData *data = view->getData(true);
  if(!data || data->empty()) return false;
  double d = std::sqrt((behind[0] - xyz[0]) * (behind[0] - xyz[0]) +
                       (behind[1] - xyz[1]) * (behind[1] - xyz[1]) +
                       (behind[2] - xyz[2]) * (behind[2] - xyz[2]));
  // what a view draws of itself lies on the model, a pixel or two off it at
  // most; a glyph, on the other hand, hangs off the data it stands for by as
  // much as its size, and the model under it is the place the query is about
  double reach = 5. * pixel;
  if(data->getNumVectors() || data->getNumTensors())
    reach = std::max(reach, (view->getOptions()->arrowSizeMax + 5.) * pixel);
  return d <= reach;
}

void drawContext::drawQueryPoint()
{
  if(!_queryPointValid || render_mode == GMSH_SELECT) return;

  double x = _queryPoint[0], y = _queryPoint[1], z = _queryPoint[2];
  // in a darker shade of the colour of the box the query leaves
  // (General.Color.Query, which the box wears washed out), twice as wide as a
  // line of the picture: the mark says where it asked, is read as one thing
  // with the box that answers, and stands out on what it is drawn on
  CTX *c = CTX::instance();
  const double shade = 0.85;
  unsigned int mark =
    c->packColor((int)(shade * c->unpackRed(c->color.query)),
                 (int)(shade * c->unpackGreen(c->color.query)),
                 (int)(shade * c->unpackBlue(c->color.query)), 255);
  gmshColor4ubv((GLubyte *)&mark);
  gmshLineWidth((float)(2. * CTX::instance()->lineWidth));
  // a cross of fourteen pixels, and a sphere half again the size of a point,
  // so that the point queried is visible whatever is drawn around it
  double d = 14 * pixel_equiv_x / s[0];
  gmshBegin(GL_LINES);
  gmshVertex3d(x - d, y, z);
  gmshVertex3d(x + d, y, z);
  gmshVertex3d(x, y - d, z);
  gmshVertex3d(x, y + d, z);
  gmshVertex3d(x, y, z - d);
  gmshVertex3d(x, y, z + d);
  gmshEnd();
  drawSphere(1.5 * CTX::instance()->pointSize, x, y, z, 1);
}
