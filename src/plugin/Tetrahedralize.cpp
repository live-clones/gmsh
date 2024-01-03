// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GmshConfig.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "Tetrahedralize.h"

#if defined(HAVE_MESH)
#include "meshGRegionDelaunayInsertion.h"
#endif

StringXNumber TetrahedralizeOptions_Number[] = {
  {GMSH_FULLRC, "View", nullptr, -1.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterTetrahedralizePlugin()
{
  return new GMSH_TetrahedralizePlugin();
}
}

std::string GMSH_TetrahedralizePlugin::getHelp() const
{
  return "Plugin(Tetrahedralize) tetrahedralizes the points in "
         "the view `View'.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Tetrahedralize) creates one new list-based view.";
}

int GMSH_TetrahedralizePlugin::getNbOptions() const
{
  return sizeof(TetrahedralizeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_TetrahedralizePlugin::getOption(int iopt)
{
  return &TetrahedralizeOptions_Number[iopt];
}

#if defined(HAVE_MESH)

namespace {
  class PointData : public MVertex {
  public:
    std::vector<double> val;
    PointData(double x, double y, double z, int numVal) : MVertex(x, y, z)
    {
      val.resize(numVal);
    }
  };
} // namespace

PView *GMSH_TetrahedralizePlugin::execute(PView *v)
{
  int iView = (int)TetrahedralizeOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  if(data1->hasMultipleMeshes()) {
    Msg::Error("Tetrahedralize plugin cannot be applied to multi-mesh views");
    return v1;
  }

  // create list of points with associated data
  std::vector<MVertex *> points;
  int numSteps = data1->getNumTimeSteps();
  for(int ent = 0; ent < data1->getNumEntities(0); ent++) {
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++) {
      if(data1->skipElement(0, ent, ele)) continue;
      if(data1->getNumNodes(0, ent, ele) != 1) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      double x, y, z;
      data1->getNode(0, ent, ele, 0, x, y, z);
      PointData *p = new PointData(x, y, z, numComp * numSteps);
      for(int step = 0; step < numSteps; step++)
        for(int comp = 0; comp < numComp; comp++)
          data1->getValue(step, ent, ele, 0, comp,
                          p->val[numComp * step + comp]);
      points.push_back(p);
    }
  }

  if(points.size() < 4) {
    Msg::Error("Need at least 4 points to tetrahedralize");
    for(std::size_t i = 0; i < points.size(); i++) delete points[i];
    return v1;
  }

  std::vector<MTetrahedron *> tets;
  delaunayMeshIn3D(points, tets); // adds 8 enclosing box vertices

  // create output
  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  for(std::size_t i = 0; i < tets.size(); i++) {
    bool ok = true;
    PointData *p[4];
    for(int j = 0; j < 4; j++) {
      p[j] = dynamic_cast<PointData *>(tets[i]->getVertex(j));
      if(!p[j]) { // tet connected to enclosing box
        ok = false;
        break;
      }
    }
    if(!ok) continue;
    int numComp = 0;
    std::vector<double> *vec = nullptr;
    if((int)p[0]->val.size() == 9 * numSteps &&
       (int)p[1]->val.size() == 9 * numSteps &&
       (int)p[2]->val.size() == 9 * numSteps &&
       (int)p[3]->val.size() == 9 * numSteps) {
      numComp = 9;
      data2->NbTS++;
      vec = &data2->TS;
    }
    else if((int)p[0]->val.size() == 3 * numSteps &&
            (int)p[1]->val.size() == 3 * numSteps &&
            (int)p[2]->val.size() == 3 * numSteps &&
            (int)p[3]->val.size() == 3 * numSteps) {
      numComp = 3;
      data2->NbVS++;
      vec = &data2->VS;
    }
    else if((int)p[0]->val.size() == numSteps &&
            (int)p[1]->val.size() == numSteps &&
            (int)p[2]->val.size() == numSteps &&
            (int)p[3]->val.size() == numSteps) {
      numComp = 1;
      data2->NbSS++;
      vec = &data2->SS;
    }
    else {
      Msg::Warning("Skipping unknown type of data");
      continue;
    }
    for(int nod = 0; nod < 4; nod++) vec->push_back(p[nod]->x());
    for(int nod = 0; nod < 4; nod++) vec->push_back(p[nod]->y());
    for(int nod = 0; nod < 4; nod++) vec->push_back(p[nod]->z());
    for(int step = 0; step < numSteps; step++)
      for(int nod = 0; nod < 4; nod++)
        for(int comp = 0; comp < numComp; comp++)
          vec->push_back(p[nod]->val[numComp * step + comp]);
  }

  for(std::size_t i = 0; i < tets.size(); i++) delete tets[i];
  for(std::size_t i = 0; i < points.size(); i++) delete points[i];

  for(int i = 0; i < data1->getNumTimeSteps(); i++)
    data2->Time.push_back(data1->getTime(i));
  data2->setName(data1->getName() + "_Tetrahedralize");
  data2->setFileName(data1->getName() + "_Tetrahedralize.pos");
  data2->finalize();
  return v2;
}

#else

PView *GMSH_TetrahedralizePlugin::execute(PView *v)
{
  Msg::Error("Plugin(Tetrahedralize) requires mesh module");
  return v;
}

#endif
