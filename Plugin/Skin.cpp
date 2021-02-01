// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include "Skin.h"
#include "Context.h"
#include "GmshDefines.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "MFace.h"
#include "MEdge.h"
#include "discreteFace.h"
#include "discreteEdge.h"

StringXNumber SkinOptions_Number[] = {{GMSH_FULLRC, "Visible", nullptr, 1.},
                                      {GMSH_FULLRC, "FromMesh", nullptr, 0.},
                                      {GMSH_FULLRC, "View", nullptr, -1.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterSkinPlugin() { return new GMSH_SkinPlugin(); }
}

std::string GMSH_SkinPlugin::getHelp() const
{
  return "Plugin(Skin) extracts the boundary (skin) of the current "
         "mesh (if `FromMesh' = 1), or from the the view `View' (in which "
         "case it creates a new view). If `View' < 0 and `FromMesh' = 0, "
         "the plugin is run on the current view.\n"
         "If `Visible' is set, the plugin only extracts the skin of visible "
         "entities.";
}

int GMSH_SkinPlugin::getNbOptions() const
{
  return sizeof(SkinOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SkinPlugin::getOption(int iopt)
{
  return &SkinOptions_Number[iopt];
}

class ElmData {
public:
  int numComp;
  std::vector<double> x, y, z;
  std::vector<double> v;
  ElmData(int n) : numComp(n) {}
  SPoint3 barycenter() const
  {
    SPoint3 p(0., 0., 0.);
    int N = x.size();
    for(int i = 0; i < N; i++) {
      p[0] += x[i];
      p[1] += y[i];
      p[2] += z[i];
    }
    p[0] /= (double)N;
    p[1] /= (double)N;
    p[2] /= (double)N;
    return p;
  }
  void addInView(PViewDataList *data) const
  {
    std::vector<double> *vec = nullptr;
    switch(x.size()) {
    case 1:
      if(numComp == 1) {
        data->NbSP++;
        vec = &data->SP;
        break;
      }
      else if(numComp == 3) {
        data->NbVP++;
        vec = &data->VP;
        break;
      }
      else if(numComp == 9) {
        data->NbTP++;
        vec = &data->TP;
        break;
      }
      break;
    case 2:
      if(numComp == 1) {
        data->NbSL++;
        vec = &data->SL;
        break;
      }
      else if(numComp == 3) {
        data->NbVL++;
        vec = &data->VL;
        break;
      }
      else if(numComp == 9) {
        data->NbTL++;
        vec = &data->TL;
        break;
      }
      break;
    case 3:
      if(numComp == 1) {
        data->NbST++;
        vec = &data->ST;
        break;
      }
      else if(numComp == 3) {
        data->NbVT++;
        vec = &data->VT;
        break;
      }
      else if(numComp == 9) {
        data->NbTT++;
        vec = &data->TT;
        break;
      }
      break;
    case 4:
      if(numComp == 1) {
        data->NbSQ++;
        vec = &data->SQ;
        break;
      }
      else if(numComp == 3) {
        data->NbVQ++;
        vec = &data->VQ;
        break;
      }
      else if(numComp == 9) {
        data->NbTQ++;
        vec = &data->TQ;
        break;
      }
      break;
    }
    if(!vec) return;
    for(std::size_t i = 0; i < x.size(); i++) vec->push_back(x[i]);
    for(std::size_t i = 0; i < y.size(); i++) vec->push_back(y[i]);
    for(std::size_t i = 0; i < z.size(); i++) vec->push_back(z[i]);
    for(std::size_t i = 0; i < v.size(); i++) vec->push_back(v[i]);
  }
};

class ElmDataLessThan {
public:
  static double tolerance;
  bool operator()(const ElmData &e1, const ElmData &e2) const
  {
    SPoint3 p1 = e1.barycenter();
    SPoint3 p2 = e2.barycenter();
    if(p1.x() - p2.x() > tolerance) return true;
    if(p1.x() - p2.x() < -tolerance) return false;
    if(p1.y() - p2.y() > tolerance) return true;
    if(p1.y() - p2.y() < -tolerance) return false;
    if(p1.z() - p2.z() > tolerance) return true;
    return false;
  }
};

double ElmDataLessThan::tolerance = 1.e-12;

static int getBoundary(int type, const int (**boundary)[6][4])
{
  static const int tri[6][4] = {{0, 1, -1, -1}, {1, 2, -1, -1}, {2, 0, -1, -1}};
  static const int qua[6][4] = {
    {0, 1, -1, -1}, {1, 2, -1, -1}, {2, 3, -1, -1}, {3, 0, -1, -1}};
  static const int tet[6][4] = {
    {0, 1, 3, -1}, {0, 2, 1, -1}, {0, 3, 2, -1}, {1, 2, 3, -1}};
  static const int hex[6][4] = {{0, 1, 5, 4}, {0, 3, 2, 1}, {0, 4, 7, 3},
                                {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
  static const int pri[6][4] = {
    {0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}, {0, 2, 1, -1}, {3, 4, 5, -1}};
  static const int pyr[6][4] = {
    {0, 3, 2, 1}, {0, 1, 4, -1}, {0, 4, 3, -1}, {1, 2, 4, -1}, {2, 3, 4, -1}};
  switch(type) {
  case TYPE_TRI: *boundary = &tri; return 3;
  case TYPE_QUA: *boundary = &qua; return 4;
  case TYPE_TET: *boundary = &tet; return 4;
  case TYPE_HEX: *boundary = &hex; return 6;
  case TYPE_PRI: *boundary = &pri; return 5;
  case TYPE_PYR: *boundary = &pyr; return 5;
  default: return 0;
  }
}

static void getBoundaryFromMesh(GModel *m, int visible)
{
  int dim = m->getDim();
  std::vector<GEntity *> entities;
  m->getEntities(entities);
  std::set<MFace, MFaceLessThan> bndFaces;
  std::set<MEdge, MEdgeLessThan> bndEdges;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    if(ge->dim() != dim) continue;
    if(visible && !ge->getVisibility()) continue;
    for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
      MElement *e = ge->getMeshElement(j);
      if(dim == 2) {
        for(int i = 0; i < e->getNumEdges(); i++) {
          MEdge f = e->getEdge(i);
          if(bndEdges.find(f) == bndEdges.end())
            bndEdges.insert(f);
          else
            bndEdges.erase(f);
        }
      }
      else if(dim == 3) {
        for(int i = 0; i < e->getNumFaces(); i++) {
          MFace f = e->getFace(i);
          if(bndFaces.find(f) == bndFaces.end())
            bndFaces.insert(f);
          else
            bndFaces.erase(f);
        }
      }
    }
  }

  if(dim == 2) {
    discreteEdge *e =
      new discreteEdge(m, m->getMaxElementaryNumber(1) + 1, nullptr, nullptr);
    m->add(e);
    for(auto it = bndEdges.begin(); it != bndEdges.end(); it++) {
      e->lines.push_back(new MLine(it->getVertex(0), it->getVertex(1)));
    }
  }
  else if(dim == 3) {
    discreteFace *f = new discreteFace(m, m->getMaxElementaryNumber(2) + 1);
    m->add(f);
    for(auto it = bndFaces.begin(); it != bndFaces.end(); it++) {
      if(it->getNumVertices() == 3)
        f->triangles.push_back(
          new MTriangle(it->getVertex(0), it->getVertex(1), it->getVertex(2)));
      else if(it->getNumVertices() == 4)
        f->quadrangles.push_back(
          new MQuadrangle(it->getVertex(0), it->getVertex(1), it->getVertex(2),
                          it->getVertex(3)));
    }
  }
}

PView *GMSH_SkinPlugin::execute(PView *v)
{
  int visible = (int)SkinOptions_Number[0].def;
  int fromMesh = (int)SkinOptions_Number[1].def;
  int iView = (int)SkinOptions_Number[2].def;

  // compute boundary of current mesh
  if(fromMesh) {
    getBoundaryFromMesh(GModel::current(), visible);
    return v;
  }

  // compute boundary of post-processing data set
  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = getPossiblyAdaptiveData(v1);

  if(data1->hasMultipleMeshes()) {
    Msg::Error("Skin plugin cannot be applied to multi-mesh views");
    return v;
  }

  Msg::Info("Extracting boundary from View[%d]", v1->getIndex());

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  std::set<ElmData, ElmDataLessThan> skin;
  ElmDataLessThan::tolerance = CTX::instance()->lc * 1.e-12;

  int firstNonEmptyStep = data1->getFirstNonEmptyTimeStep();
  for(int ent = 0; ent < data1->getNumEntities(firstNonEmptyStep); ent++) {
    if(visible && data1->skipEntity(firstNonEmptyStep, ent)) continue;
    for(int ele = 0; ele < data1->getNumElements(firstNonEmptyStep, ent);
        ele++) {
      if(data1->skipElement(firstNonEmptyStep, ent, ele, visible)) continue;
      int numComp = data1->getNumComponents(firstNonEmptyStep, ent, ele);
      int type = data1->getType(firstNonEmptyStep, ent, ele);
      const int(*boundary)[6][4];
      int numBoundary = getBoundary(type, &boundary);
      if(!numBoundary) continue;
      for(int i = 0; i < numBoundary; i++) {
        ElmData e(numComp);
        for(int j = 0; j < 4; j++) {
          int nod = (*boundary)[i][j];
          if(nod < 0) continue;
          double x, y, z;
          data1->getNode(firstNonEmptyStep, ent, ele, nod, x, y, z);
          e.x.push_back(x);
          e.y.push_back(y);
          e.z.push_back(z);
        }
        auto it = skin.find(e);
        if(it == skin.end()) {
          for(int step = 0; step < data1->getNumTimeSteps(); step++) {
            if(data1->hasTimeStep(step)) {
              for(int j = 0; j < 4; j++) {
                int nod = (*boundary)[i][j];
                if(nod < 0) continue;
                double v;
                for(int comp = 0; comp < numComp; comp++) {
                  data1->getValue(step, ent, ele, nod, comp, v);
                  e.v.push_back(v);
                }
              }
            }
          }
          skin.insert(e);
        }
        else
          skin.erase(it);
      }
    }
  }

  for(auto it = skin.begin(); it != skin.end(); it++) it->addInView(data2);

  for(int i = 0; i < data1->getNumTimeSteps(); i++)
    if(data1->hasTimeStep(i)) data2->Time.push_back(data1->getTime(i));
  data2->setName(data1->getName() + "_Skin");
  data2->setFileName(data1->getName() + "_Skin.pos");
  data2->finalize();

  return v2;
}
