// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshGlobal.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "OS.h"
#include "Distance.h"
#include "Context.h"
#include "Numeric.h"

#if defined(HAVE_SOLVER)
#include "dofManager.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#include "distanceTerm.h"
#endif

template <class scalar> class simpleFunction;

StringXNumber DistanceOptions_Number[] = {
  {GMSH_FULLRC, "PhysicalPoint", nullptr, 0.},
  {GMSH_FULLRC, "PhysicalLine", nullptr, 0.},
  {GMSH_FULLRC, "PhysicalSurface", nullptr, 0.},
  {GMSH_FULLRC, "DistanceType", nullptr, 0},
  {GMSH_FULLRC, "MinScale", nullptr, 0},
  {GMSH_FULLRC, "MaxScale", nullptr, 0}};

extern "C" {
GMSH_Plugin *GMSH_RegisterDistancePlugin() { return new GMSH_DistancePlugin(); }
}

GMSH_DistancePlugin::GMSH_DistancePlugin()
{
  _maxDim = 0;
  _data = nullptr;
}

std::string GMSH_DistancePlugin::getHelp() const
{
  return "Plugin(Distance) computes distances to entities in a mesh.\n\n"
         "If `PhysicalPoint', `PhysicalLine' and `PhysicalSurface' are 0, the "
         "distance is computed to all the boundaries. Otherwise the distance "
         "is computed to the given physical group.\n\n"
         "If `DistanceType' is 0, the plugin computes the geometrical "
         "Euclidean "
         "distance using the naive O(N^2) algorithm. If `DistanceType' > 0, "
         "the plugin computes an approximate distance by solving a PDE with "
         "a diffusion constant equal to `DistanceType' time the maximum size "
         "of the bounding box of the mesh as in [Legrand et al. 2006].\n\n"
         "Positive `MinScale' and `MaxScale' scale the distance function.\n\n"
         "Plugin(Distance) creates one new list-based view.";
}

int GMSH_DistancePlugin::getNbOptions() const
{
  return sizeof(DistanceOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DistancePlugin::getOption(int iopt)
{
  return &DistanceOptions_Number[iopt];
}

void GMSH_DistancePlugin::printView(std::vector<GEntity *> &entities,
                                    std::map<MVertex *, double> &distanceMap)
{
  double minScale = (double)DistanceOptions_Number[4].def;
  double maxScale = (double)DistanceOptions_Number[5].def;

  double minDist = 1.e22;
  double maxDist = 0.0;
  for(auto itv = distanceMap.begin(); itv != distanceMap.end(); ++itv) {
    double dist = itv->second;
    if(dist > maxDist) maxDist = dist;
    if(dist < minDist) minDist = dist;
    itv->second = dist;
  }

  for(std::size_t ii = 0; ii < entities.size(); ii++) {
    if(entities[ii]->dim() == _maxDim) {
      for(std::size_t i = 0; i < entities[ii]->getNumMeshElements(); i++) {
        MElement *e = entities[ii]->getMeshElement(i);
        std::size_t numNodes = e->getNumPrimaryVertices();
        if(e->getNumChildren())
          numNodes = e->getNumChildren() * e->getChild(0)->getNumVertices();
        std::vector<double> x(numNodes), y(numNodes), z(numNodes);
        std::vector<double> *out =
          _data->incrementList(1, e->getType(), numNodes);
        std::vector<MVertex *> nods;

        if(!e->getNumChildren())
          for(std::size_t i = 0; i < numNodes; i++)
            nods.push_back(e->getVertex(i));
        else
          for(int i = 0; i < e->getNumChildren(); i++)
            for(std::size_t j = 0; j < e->getChild(i)->getNumVertices(); j++)
              nods.push_back(e->getChild(i)->getVertex(j));

        for(std::size_t nod = 0; nod < numNodes; nod++)
          out->push_back((nods[nod])->x());
        for(std::size_t nod = 0; nod < numNodes; nod++)
          out->push_back((nods[nod])->y());
        for(std::size_t nod = 0; nod < numNodes; nod++)
          out->push_back((nods[nod])->z());

        std::vector<double> dist;
        for(std::size_t j = 0; j < numNodes; j++) {
          MVertex *v = nods[j];
          auto it = distanceMap.find(v);
          dist.push_back(it->second);
        }

        for(std::size_t i = 0; i < dist.size(); i++) {
          if(minScale > 0 && maxScale > 0 && maxDist != minDist)
            dist[i] = minScale + ((dist[i] - minDist) / (maxDist - minDist)) *
                                   (maxScale - minScale);
          else if(minScale > 0)
            dist[i] = minScale + dist[i];
          out->push_back(dist[i]);
        }
      }
    }
  }
}

PView *GMSH_DistancePlugin::execute(PView *v)
{
  int id_point = (int)DistanceOptions_Number[0].def;
  int id_line = (int)DistanceOptions_Number[1].def;
  int id_face = (int)DistanceOptions_Number[2].def;
  double type = (double)DistanceOptions_Number[3].def;

  GModel *m = GModel::current();
  int totNumNodes = m->getNumMeshVertices();
  if(!totNumNodes) {
    Msg::Error("Plugin(Distance) needs a mesh");
    return v;
  }

  PView *view = new PView();
  _data = getDataList(view);

  _maxDim = m->getMeshDim();

  std::vector<GEntity *> entities;
  m->getEntities(entities);

  std::vector<SPoint3> pts(totNumNodes);
  std::vector<double> distances(totNumNodes, 1.e22);
  std::vector<MVertex *> pt2Vertex(totNumNodes);
  std::map<MVertex *, double> distanceMap;

  std::size_t k = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      pts[k] = SPoint3(v->x(), v->y(), v->z());
      pt2Vertex[k] = v;
      distanceMap.insert(std::make_pair(v, 0.0));
      k++;
    }
  }

  if(type <= 0.0) { // Compute geometrical distance to mesh boundaries
    bool existEntity = false;
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *g2 = entities[i];
      int gDim = g2->dim();
      bool computeForEntity = false;
      if(!id_point && !id_line && !id_face && gDim == _maxDim - 1) {
        computeForEntity = true;
      }
      else {
        std::vector<int> phys = g2->getPhysicalEntities();
        for(std::size_t k = 0; k < phys.size(); k++) {
          if((phys[k] == id_point && gDim == 0) ||
             (phys[k] == id_line && gDim == 1) ||
             (phys[k] == id_face && gDim == 2)) {
            computeForEntity = true;
            break;
          }
        }
      }
      if(computeForEntity) {
        existEntity = true;
        for(std::size_t k = 0; k < g2->getNumMeshElements(); k++) {
          std::vector<double> iDistances;
          std::vector<SPoint3> iClosePts;
          std::vector<double> iDistancesE;
          MElement *e = g2->getMeshElement(k);
          MVertex *v1 = e->getVertex(0);
          MVertex *v2 = e->getVertex(1);
          SPoint3 p1(v1->x(), v1->y(), v1->z());
          SPoint3 p2(v2->x(), v2->y(), v2->z());
          if(e->getType() == TYPE_LIN) {
            signedDistancesPointsLine(iDistances, iClosePts, pts, p1, p2);
          }
          else if(e->getType() == TYPE_TRI) {
            MVertex *v3 = e->getVertex(2);
            SPoint3 p3(v3->x(), v3->y(), v3->z());
            signedDistancesPointsTriangle(iDistances, iClosePts, pts, p1, p2,
                                          p3);
          }
          for(std::size_t kk = 0; kk < pts.size(); kk++) {
            if(std::abs(iDistances[kk]) < distances[kk]) {
              distances[kk] = std::abs(iDistances[kk]);
              MVertex *v = pt2Vertex[kk];
              distanceMap[v] = distances[kk];
            }
          }
        }
      }
    }
    if(!existEntity) {
      if(id_point) Msg::Warning("Physical Point %d does not exist", id_point);
      if(id_line) Msg::Warning("Physical Line %d does not exist", id_line);
      if(id_face) Msg::Warning("Physical Surface %d does not exist", id_face);
    }
    else {
      printView(entities, distanceMap);
    }
  }
  else { // Compute PDE for distance function
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
    linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
    linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
    linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif
    dofManager<double> *dofView = new dofManager<double>(lsys);

    bool existEntity = false;
    SBoundingBox3d bbox;
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      int gDim = ge->dim();
      bool fixForEntity = false;
      if(!id_point && !id_line && !id_face && gDim == _maxDim - 1) {
        fixForEntity = true;
      }
      else {
        std::vector<int> phys = ge->getPhysicalEntities();
        for(std::size_t k = 0; k < phys.size(); k++) {
          if((phys[k] == id_point && gDim == 0) ||
             (phys[k] == id_line && gDim == 1) ||
             (phys[k] == id_face && gDim == 2)) {
            fixForEntity = true;
            break;
          }
        }
      }
      if(fixForEntity) {
        existEntity = true;
        for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
          MElement *t = ge->getMeshElement(i);
          for(std::size_t k = 0; k < t->getNumVertices(); k++) {
            MVertex *v = t->getVertex(k);
            dofView->fixVertex(v, 0, 1, 0.);
            bbox += SPoint3(v->x(), v->y(), v->z());
          }
        }
      }
    }
    if(!existEntity) {
      if(id_point) Msg::Warning("Physical Point %d does not exist", id_point);
      if(id_line) Msg::Warning("Physical Line %d does not exist", id_line);
      if(id_face) Msg::Warning("Physical Surface %d does not exist", id_face);
    }
    else {
      std::vector<MElement *> allElems;
      for(std::size_t ii = 0; ii < entities.size(); ii++) {
        if(entities[ii]->dim() == _maxDim) {
          GEntity *ge = entities[ii];
          for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
            MElement *t = ge->getMeshElement(i);
            allElems.push_back(t);
            for(std::size_t k = 0; k < t->getNumVertices(); k++)
              dofView->numberVertex(t->getVertex(k), 0, 1);
          }
        }
      }
      double L = norm(SVector3(bbox.max(), bbox.min()));
      double mu = type * L;
      simpleFunction<double> DIFF(mu * mu), ONE(1.0);
      distanceTerm distance(GModel::current(), 1, &DIFF, &ONE);
      for(auto it = allElems.begin(); it != allElems.end(); it++) {
        SElement se((*it));
        distance.addToMatrix(*dofView, &se);
      }
      groupOfElements gr(allElems);
      distance.addToRightHandSide(*dofView, gr);
      lsys->systemSolve();
      for(auto itv = distanceMap.begin(); itv != distanceMap.end(); ++itv) {
        MVertex *v = itv->first;
        double value;
        dofView->getDofValue(v, 0, 1, value);
        value = std::min(0.9999, value);
        double dist = -mu * log(1. - value);
        itv->second = dist;
      }
      printView(entities, distanceMap);
    }
    delete lsys;
    delete dofView;
#endif
  }

  _data->setName("distance");
  _data->Time.push_back(0);
  _data->setFileName("distance.pos");
  _data->finalize();
  return view;
}
