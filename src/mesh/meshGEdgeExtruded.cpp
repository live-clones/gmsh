// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include "GModel.h"
#include "MLine.h"
#include "ExtrudeParams.h"
#include "GmshMessage.h"

static void createElements(GEdge *ge)
{
  // create elements
  for(std::size_t i = 0; i < ge->mesh_vertices.size() + 1; i++) {
    MVertex *v0 = (i == 0) ? ge->getBeginVertex()->mesh_vertices[0] :
                             ge->mesh_vertices[i - 1];
    MVertex *v1 = (i == ge->mesh_vertices.size()) ?
                    ge->getEndVertex()->mesh_vertices[0] :
                    ge->mesh_vertices[i];
    MLine *newElem = new MLine(v0, v1);
    ge->lines.push_back(newElem);
  }
}

static void extrudeMesh(GVertex *from, GEdge *to)
{
  ExtrudeParams *ep = to->meshAttributes.extrude;

  MVertex *v = from->mesh_vertices[0];
  for(int j = 0; j < ep->mesh.NbLayer; j++) {
    for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
      double x = v->x(), y = v->y(), z = v->z();
      ep->Extrude(j, k + 1, x, y, z);
      if(j != ep->mesh.NbLayer - 1 || k != ep->mesh.NbElmLayer[j] - 1) {
        Range<double> r = to->parBounds(0);
        double t = r.low() + ep->u(j, k + 1) * (r.high() - r.low());
        MEdgeVertex *newv = new MEdgeVertex(x, y, z, to, t);
        to->mesh_vertices.push_back(newv);
      }
    }
  }
  createElements(to);
}

static void copyMesh(GEdge *from, GEdge *to)
{
  ExtrudeParams *ep = to->meshAttributes.extrude;

  int direction = (ep->geo.Source > 0) ? 1 : -1;

  Range<double> u_bounds = from->parBounds(0);
  double u_min = u_bounds.low();
  double u_max = u_bounds.high();

#if 0
  // old version, which directly uses nodes; this can lead to unexpected results
  // if the nodes in from->mesh_vertices.size() are not sorted, which can happen
  // e.g. if createTopology() has been called
  for(std::size_t i = 0; i < from->mesh_vertices.size(); i++) {
    int index = (direction < 0) ? (from->mesh_vertices.size() - 1 - i) : i;
    MVertex *v = from->mesh_vertices[index];
    double x = v->x(), y = v->y(), z = v->z();
    ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
                x, y, z);
    double u;
    v->getParameter(0, u);
    double newu = (direction > 0) ? u : (u_max - u + u_min);
    MEdgeVertex *newv = new MEdgeVertex(x, y, z, to, newu);
    to->mesh_vertices.push_back(newv);
  }
#else
  // so it's better to go back to the elements, which are assumed to be stored
  // in the correct order
  for(int i = 0; i < (int)from->lines.size() - 1; i++) {
    int index = (direction < 0) ? (from->lines.size() - i - 2) : i;
    MVertex *v = from->lines[index]->getVertex(1);
    double x = v->x(), y = v->y(), z = v->z();
    ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
                x, y, z);
    double u;
    v->getParameter(0, u);
    double newu = (direction > 0) ? u : (u_max - u + u_min);
    MEdgeVertex *newv = new MEdgeVertex(x, y, z, to, newu);
    to->mesh_vertices.push_back(newv);
  }
#endif

  createElements(to);
}

int MeshExtrudedCurve(GEdge *ge)
{
  ExtrudeParams *ep = ge->meshAttributes.extrude;

  if(!ep || !ep->mesh.ExtrudeMesh) return 0;

  if(!ge->getBeginVertex() || !ge->getEndVertex()) {
    Msg::Error("Cannot extrude curve %d with no begin or end point", ge->tag());
    return 0;
  }

  Msg::Info("Meshing curve %d (Extruded)", ge->tag());

  if(ep->geo.Mode == EXTRUDED_ENTITY) {
    // curve is extruded from a point
    GVertex *from = ge->model()->getVertexByTag(std::abs(ep->geo.Source));
    if(!from) {
      Msg::Error("Unknown source point %d for extrusion", ep->geo.Source);
      return 0;
    }
    extrudeMesh(from, ge);
  }
  else {
    GEdge *from = ge->model()->getEdgeByTag(std::abs(ep->geo.Source));
    // curve is a copy of another curve (the "top" of the extrusion)
    if(!from) {
      Msg::Error("Unknown source curve %d for extrusion", ep->geo.Source);
      return 0;
    }
    else if(from->geomType() != GEntity::DiscreteCurve &&
            from->meshStatistics.status != GEdge::DONE) {
      // cannot mesh this edge yet: will do it later
      return 1;
    }
    else if(ge->getMeshMaster() != ge) {
      GEdge *gef = dynamic_cast<GEdge *>(ge->getMeshMaster());
      if(gef->meshStatistics.status != GEdge::DONE) {
        // there is a periodicity constraint, and the source has not been
        // meshed: will do it later
        return 1;
      }
    }

    copyMesh(from, ge);
    if(ge->getMeshMaster() == from) {
      // explicit periodic constraint, to store node correspondence
      ge->setMeshMaster(from, ge->affineTransform);
    }
  }

  ge->meshStatistics.status = GEdge::DONE;
  return 1;
}
