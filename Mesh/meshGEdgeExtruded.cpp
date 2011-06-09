// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <set>
#include "GModel.h"
#include "MLine.h"
#include "ExtrudeParams.h"
#include "GmshMessage.h"

static void extrudeMesh(GVertex *from, GEdge *to)
{
  ExtrudeParams *ep = to->meshAttributes.extrude;

  MVertex *v = from->mesh_vertices[0];
  for(int j = 0; j < ep->mesh.NbLayer; j++) {
    for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
      double x = v->x(), y = v->y(), z = v->z();
      ep->Extrude(j, k + 1, x, y, z);
      if(j != ep->mesh.NbLayer - 1 || k != ep->mesh.NbElmLayer[j] - 1)
        to->mesh_vertices.push_back(new MEdgeVertex(x, y, z, to, ep->u(j, k + 1)));
    }
  }
}

static void copyMesh(GEdge *from, GEdge *to)
{
  ExtrudeParams *ep = to->meshAttributes.extrude;

  int direction = (ep->geo.Source > 0) ? 1 : -1;

  Range<double> u_bounds = from->parBounds(0);
  double u_min = u_bounds.low();
  double u_max = u_bounds.high();

  for(unsigned int i = 0; i < from->mesh_vertices.size(); i++){
    int index = (direction < 0) ? (from->mesh_vertices.size() - 1 - i) : i;
    MVertex *v = from->mesh_vertices[index];
    double x = v->x(), y = v->y(), z = v->z();
    ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1], 
                x, y, z);
    double u;
    v->getParameter(0, u);
    double newu = (direction > 0) ? u : (u_max - u + u_min);
    to->mesh_vertices.push_back(new MEdgeVertex(x, y, z, to, newu));
  }
}

int MeshExtrudedCurve(GEdge *ge)
{
  ExtrudeParams *ep = ge->meshAttributes.extrude;

  if(!ep || !ep->mesh.ExtrudeMesh)
    return 0;

  Msg::Info("Meshing curve %d (extruded)", ge->tag());

  if(ep->geo.Mode == EXTRUDED_ENTITY) {
    // curve is extruded from a point
    extrudeMesh(ge->getBeginVertex(), ge);
  }
  else {
    GEdge *from = ge->model()->getEdgeByTag(std::abs(ep->geo.Source));
    // curve is a copy of another curve (the "top" of the extrusion)
    if(!from){
      Msg::Error("Unknown source curve %d for extrusion", ep->geo.Source);
      return 0;
    }
    else if(from->geomType() != GEntity::DiscreteCurve &&
            from->meshStatistics.status != GEdge::DONE){
      // cannot mesh this edge yet: will do it later
      return 1;
    }
    copyMesh(from, ge);
  }

  // create elements
  for(unsigned int i = 0; i < ge->mesh_vertices.size() + 1; i++){
    MVertex *v0 = (i == 0) ? 
      ge->getBeginVertex()->mesh_vertices[0] : ge->mesh_vertices[i - 1];
    MVertex *v1 = (i == ge->mesh_vertices.size()) ? 
      ge->getEndVertex()->mesh_vertices[0] : ge->mesh_vertices[i];
    MLine* newElem = new MLine(v0, v1);
    ge->lines.push_back(newElem);
  }

  ge->meshStatistics.status = GEdge::DONE;
  return 1;
}
