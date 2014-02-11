// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <vector>
#include "GmshConfig.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "Tetrahedralize.h"

#if defined(HAVE_MESH)
#include "meshGRegionDelaunayInsertion.h"
#endif

StringXNumber TetrahedralizeOptions_Number[] = {
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
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
    "Plugin(Tetrahedralize) creates one new view.";
}

int GMSH_TetrahedralizePlugin::getNbOptions() const
{
  return sizeof(TetrahedralizeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_TetrahedralizePlugin::getOption(int iopt)
{
  return &TetrahedralizeOptions_Number[iopt];
}

class PointData {
 public:
  MVertex *v;
  std::vector<double> val;
  PointData(double x, double y, double z, int numVal)
  {
    v = new MVertex(x, y, z);
    val.resize(numVal);
  }
};

PView *GMSH_TetrahedralizePlugin::execute(PView *v)
{
  int iView = (int)TetrahedralizeOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  if(data1->hasMultipleMeshes()){
    Msg::Error("Tetrahedralize plugin cannot be applied to multi-mesh views");
    return v1;
  }

  // create list of points with associated data
  std::vector<PointData> points;
  int numSteps = data1->getNumTimeSteps();
  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      if(data1->getNumNodes(0, ent, ele) != 1) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      double x, y, z;
      data1->getNode(0, ent, ele, 0, x, y, z);
      PointData p(x, y, z, numComp * numSteps);
      for(int step = 0; step < numSteps; step++)
        for(int comp = 0; comp < numComp; comp++)
          data1->getValue(step, ent, ele, 0, comp, p.val[numComp * step + comp]);
      points.push_back(p);
    }
  }

  if(points.size() < 4){
    Msg::Error("Need at least 4 points to tetrahedralize");
    return v1;
  }

#if !defined(HAVE_MESH)
  Msg::Error("Gmsh has to be compiled with Mesh support to run "
             "Plugin(Tetrahedralize)");
  return v1;
#else
  std::vector<MVertex*> vertices(points.size());
  for(unsigned int i = 0; i < points.size(); i++){
    MVertex *v = points[i].v;
    v->setIndex(i);
    vertices[i] = v;
  }
  std::vector<MTetrahedron*> tets;
  delaunayMeshIn3D(vertices, tets);

  // create output
  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  for(unsigned int i = 0; i < tets.size(); i++){
    MTetrahedron *t = tets[i];
    int i0 = t->getVertex(0)->getIndex();
    int i1 = t->getVertex(1)->getIndex();
    int i2 = t->getVertex(2)->getIndex();
    int i3 = t->getVertex(3)->getIndex();
    int n = points.size();
    if(i0 < 0 || i0 >= n || i1 < 0 || i1 >= n ||
       i2 < 0 || i2 >= n || i3 < 0 || i3 >= n){
      Msg::Warning("Bad vertex in tetrahedralization");
      continue;
    }
    PointData *p[4] = {&points[i0], &points[i1],
                       &points[i2], &points[i3]};
    int numComp = 0;
    std::vector<double> *vec = 0;
    if((int)p[0]->val.size() == 9 * numSteps &&
       (int)p[1]->val.size() == 9 * numSteps &&
       (int)p[2]->val.size() == 9 * numSteps &&
       (int)p[3]->val.size() == 9 * numSteps){
      numComp = 9; data2->NbTS++; vec = &data2->TS;
    }
    else if((int)p[0]->val.size() == 3 * numSteps &&
            (int)p[1]->val.size() == 3 * numSteps &&
            (int)p[2]->val.size() == 3 * numSteps &&
            (int)p[3]->val.size() == 3 * numSteps){
      numComp = 3; data2->NbVS++; vec = &data2->VS;
    }
    else if((int)p[0]->val.size() == numSteps &&
            (int)p[1]->val.size() == numSteps &&
            (int)p[2]->val.size() == numSteps &&
            (int)p[3]->val.size() == numSteps){
      numComp = 1; data2->NbSS++; vec = &data2->SS;
    }
    else{
      Msg::Warning("Bad data in tetrahedralization");
      continue;
    }
    for(int nod = 0; nod < 4; nod++) vec->push_back(p[nod]->v->x());
    for(int nod = 0; nod < 4; nod++) vec->push_back(p[nod]->v->y());
    for(int nod = 0; nod < 4; nod++) vec->push_back(p[nod]->v->z());
    for(int step = 0; step < numSteps; step++)
      for(int nod = 0; nod < 4; nod++)
        for(int comp = 0; comp < numComp; comp++)
          vec->push_back(p[nod]->val[numComp * step + comp]);
  }

  for(unsigned int i = 0; i < tets.size(); i++)
    delete tets[i];
  for(unsigned int i = 0; i < vertices.size(); i++)
    delete vertices[i];

  for(int i = 0; i < data1->getNumTimeSteps(); i++)
    data2->Time.push_back(data1->getTime(i));
  data2->setName(data1->getName() + "_Tetrahedralize");
  data2->setFileName(data1->getName() + "_Tetrahedralize.pos");
  data2->finalize();
  return v2;
#endif
}
