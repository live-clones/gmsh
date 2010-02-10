// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <vector>
#include "GModel.h"
#include "GmshMessage.h"
#include "Tetrahedralize.h"

#if defined(HAVE_TETGEN)
#include "tetgen.h"
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
  std::vector<double> v;
  PointData(double x, double y, double z, int numVal)
  { 
    v.resize(3 + numVal); 
    v[0] = x;
    v[1] = y;
    v[2] = z;
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
          data1->getValue(step, ent, ele, 0, comp, p.v[3 + numComp * step + comp]);
      points.push_back(p);
    }
  }

  if(points.size() < 4){
    Msg::Error("Need at least 4 points to tetrahedralize");
    return v1;
  }

#if !defined(HAVE_TETGEN)
  Msg::Error("Gmsh has to be compiled with Tetgen support to run "
             "Plugin(Tetrahedralize)");
  return v1;
#else
  // fill tetgen structure
  tetgenio in, out;
  in.mesh_dim = 3;
  in.numberofpoints = points.size();
  in.pointlist = new REAL[in.numberofpoints * 3];
  for(unsigned int i = 0; i < points.size(); i++){
    in.pointlist[i * 3 + 0] = points[i].v[0];
    in.pointlist[i * 3 + 1] = points[i].v[1];
    in.pointlist[i * 3 + 2] = points[i].v[2];
  }
  try{
    tetrahedralize((char*)"Q", &in, &out);
  }
  catch (int error){
    Msg::Error("Could not tetrahedralize points");
    return v1;
  }

  if(out.numberofpoints != (int)points.size()){
    Msg::Error("Tetrahedralization added points (%d -> %d): aborting",
               points.size(), out.numberofpoints);
    return v1;
  }

  // create output
  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  for(int i = 0; i < out.numberoftetrahedra; i++){
    PointData *p[4];
    p[0] = &points[out.tetrahedronlist[i * 4 + 0]];
    p[1] = &points[out.tetrahedronlist[i * 4 + 1]];
    p[2] = &points[out.tetrahedronlist[i * 4 + 2]];
    p[3] = &points[out.tetrahedronlist[i * 4 + 3]];
    int numComp = 0;
    std::vector<double> *vec = 0;
    if((int)p[0]->v.size() == 3 + 9 * numSteps && 
       (int)p[1]->v.size() == 3 + 9 * numSteps &&
       (int)p[2]->v.size() == 3 + 9 * numSteps &&
       (int)p[3]->v.size() == 3 + 9 * numSteps){
      numComp = 9; data2->NbTS++; vec = &data2->TS;
    }
    else if((int)p[0]->v.size() == 3 + 3 * numSteps && 
            (int)p[1]->v.size() == 3 + 3 * numSteps &&
            (int)p[2]->v.size() == 3 + 3 * numSteps &&
            (int)p[2]->v.size() == 3 + 3 * numSteps){
      numComp = 3; data2->NbVS++; vec = &data2->VS;
    }
    else{
      numComp = 1; data2->NbSS++; vec = &data2->SS;
    }
    for(int nod = 0; nod < 4; nod++) vec->push_back(p[nod]->v[0]);
    for(int nod = 0; nod < 4; nod++) vec->push_back(p[nod]->v[1]);
    for(int nod = 0; nod < 4; nod++) vec->push_back(p[nod]->v[2]);
    for(int step = 0; step < numSteps; step++)
      for(int nod = 0; nod < 4; nod++)
        for(int comp = 0; comp < numComp; comp++) 
          vec->push_back(p[nod]->v[3 + numComp * step + comp]);
  }

  for(int i = 0; i < data1->getNumTimeSteps(); i++)
    data2->Time.push_back(data1->getTime(i));
  data2->setName(data1->getName() + "_Tetrahedralize");
  data2->setFileName(data1->getName() + "_Tetrahedralize.pos");
  data2->finalize();

  return v2;
#endif
}
