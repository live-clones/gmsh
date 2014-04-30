// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "Gmsh.h"
#include "GModel.h"
#include "CurvedBndDist.h"
#include "MElement.h"
#include "PViewDataList.h"
#include "OptHomIntegralBoundaryDist.h"
#include "BasisFactory.h"

StringXNumber CurvedBndDistOptions_Number[] = {
 /* {GMSH_FULLRC, "Dim", NULL, -1},*/
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCurvedBndDistPlugin()
  {
    return new GMSH_CurvedBndDistPlugin();
  }
}
int GMSH_CurvedBndDistPlugin::getNbOptions() const
{
  return sizeof(CurvedBndDistOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CurvedBndDistPlugin::getOption(int iopt)
{
  return &CurvedBndDistOptions_Number[iopt];
}


std::string GMSH_CurvedBndDistPlugin::getHelp() const
{
  return "Plugin(CurvedBndDist) ...";
}

static void addLine(PViewDataList *data, const SVector3 &p0, const SVector3 &p1, double v0, double v1)
{
  data->NbSL ++;
  data->SL.push_back(p0.x()); data->SL.push_back(p1.x());
  data->SL.push_back(p0.y()); data->SL.push_back(p1.y());
  data->SL.push_back(p0.z()); data->SL.push_back(p1.z());
  data->SL.push_back(v0); data->SL.push_back(v1);
}

/*static void addQua(PViewDataList *data, const SVector3 &p0, const SVector3 &p1, const SVector3 &p2, const SVector3 &p3, double v)
{
  data->NbSQ ++;
  data->SQ.push_back(p0.x()); data->SQ.push_back(p1.x()); data->SQ.push_back(p2.x()); data->SQ.push_back(p3.x());
  data->SQ.push_back(p0.y()); data->SQ.push_back(p1.y()); data->SQ.push_back(p2.y()); data->SQ.push_back(p3.y());
  data->SQ.push_back(p0.z()); data->SQ.push_back(p1.z()); data->SQ.push_back(p2.z()); data->SQ.push_back(p3.z());
  data->SQ.push_back(v); data->SQ.push_back(v); data->SQ.push_back(v); data->SQ.push_back(v);
}
*/
static void addPoint(PViewDataList *data, const SVector3 &p0, double v0)
{
  data->NbSP ++;
  data->SP.push_back(p0.x());
  data->SP.push_back(p0.y());
  data->SP.push_back(p0.z());
  data->SP.push_back(v0);
}

static void addVP(PViewDataList *data, const SVector3 p0, SVector3 v)
{
  data->NbVP ++;
  data->VP.push_back(p0.x());
  data->VP.push_back(p0.y());
  data->VP.push_back(p0.z());
  data->VP.push_back(v.x());
  data->VP.push_back(v.y());
  data->VP.push_back(v.z());
}

#include <limits>
static void drawElementDist(PViewDataList *data, GEdge *edge, const std::vector<MVertex *>&vertices, const nodalBasis &basis)
{
  std::vector<double> gradient;
  std::vector<double> param(vertices.size());
  std::vector<bool> onEdge(vertices.size());
  std::vector<SPoint3> xyz(vertices.size());
  for (size_t i = 0; i < vertices.size(); ++i) {
    MVertex *v = vertices[i];
    reparamMeshVertexOnEdge(v, edge, param[i]);
    onEdge[i] = v->onWhat() == edge;
    xyz[i] = v->point();
  }
  parametricLineGEdge line0(edge, param[0], param[1]);
  parametricLineNodalBasis line1(basis, xyz);
  {
    SPoint3 p,p1;
    line0.hausdorffDistance(line1,p,p1);
    addLine(data, p, p1, 0., 1);
  }
}

static void drawElement(PViewDataList *data, GEdge *edge, const std::vector<MVertex *>&vertices, const nodalBasis &basis)
{
  std::vector<double> gradient;
  std::vector<double> param(vertices.size());
  std::vector<bool> onEdge(vertices.size());
  std::vector<SPoint3> xyz(vertices.size());
  for (size_t i = 0; i < vertices.size(); ++i) {
    MVertex *v = vertices[i];
    reparamMeshVertexOnEdge(v, edge, param[i]);
    onEdge[i] = v->onWhat() == edge;
    xyz[i] = v->point();
  }
  computeBndDistAndGradient(edge, param, vertices, basis, xyz, onEdge, gradient,1.e-6);
  for (size_t i = 0; i < vertices.size(); ++i) {
    double t0;
    reparamMeshVertexOnEdge(vertices[i], edge, t0);
    SPoint3 p = vertices[i]->point();
    GPoint gpt =  edge->point(t0 + 1e-8);
    SPoint3 pt(gpt.x(), gpt.y(), gpt.z());
    SVector3 t = (pt - p);
    t.normalize();
    //addPoint(data, p, 0);
    addVP(data, p, t * (-gradient[i]));
  }
}

PView *GMSH_CurvedBndDistPlugin::execute(PView *v)
{
  PView *pv = new PView();
  PViewDataList *data = getDataList(pv);
  data->Time.push_back(0.);
  _m = GModel::current();
  for (GModel::fiter iface = _m->firstFace(); iface != _m->lastFace(); ++iface) {
    GFace *face = *iface;
    for (size_t iElement = 0; iElement < face->getNumMeshElements(); ++iElement) {
      MElement *element = face->getMeshElement(iElement);
      const nodalBasis &elbasis = *element->getFunctionSpace();
      for (int iEdge = 0; iEdge < element->getNumEdges(); ++iEdge) {
	int clId = elbasis.getClosureId(iEdge, 1);
        const std::vector<int> &closure = elbasis.closures[clId];
        std::vector<MVertex *> vertices;
        GEdge *edge = NULL;
        for (size_t i = 0; i < closure.size(); ++i) {
          MVertex *v = element->getVertex(closure[i]);
          vertices.push_back(v);
          if ((int)i >= 2 && v->onWhat() && v->onWhat()->dim() == 1) {
            edge = v->onWhat()->cast2Edge();
          }
        }
        if (edge){
	  drawElementDist(data, edge, vertices, *BasisFactory::getNodalBasis(elbasis.getClosureType(clId)));
	}
      }
    }
  }
  data->finalize();
  return pv;
}

