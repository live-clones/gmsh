// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "meshGFaceOptimize.h"
#include "ExtractEdges.h"

StringXNumber ExtractEdgesOptions_Number[] = {
  {GMSH_FULLRC, "Angle", NULL, 40.},
  {GMSH_FULLRC, "IncludeBoundary", NULL, 1.},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractEdgesPlugin()
  {
    return new GMSH_ExtractEdgesPlugin();
  }
}

std::string GMSH_ExtractEdgesPlugin::getHelp() const
{
  return "Plugin(ExtractEdges) extracts sharp edges "
    "from a triangular mesh.\n\n"
    "Plugin(ExtractEdges) creates one new view.";
}

int GMSH_ExtractEdgesPlugin::getNbOptions() const
{
  return sizeof(ExtractEdgesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ExtractEdgesPlugin::getOption(int iopt)
{
  return &ExtractEdgesOptions_Number[iopt];
}

static void add_edge(edge_angle &ea, PViewDataList *data)
{
  data->SL.push_back(ea.v1->x());
  data->SL.push_back(ea.v2->x());
  data->SL.push_back(ea.v1->y());
  data->SL.push_back(ea.v2->y());
  data->SL.push_back(ea.v1->z());
  data->SL.push_back(ea.v2->z());
  data->SL.push_back(1.);
  data->SL.push_back(1.);
  data->NbSL++;
}

PView *GMSH_ExtractEdgesPlugin::execute(PView *v)
{
  std::vector<MTriangle*> elements;
  for(GModel::fiter it = GModel::current()->firstFace(); 
      it != GModel::current()->lastFace(); ++it)
    elements.insert(elements.end(), (*it)->triangles.begin(), 
                    (*it)->triangles.end());
  
  if(elements.empty()){
    Msg::Error("No triangles in mesh to extract edges from");
    return 0;
  }

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  e2t_cont adj;
  buildEdgeToTriangle(elements, adj);
  std::vector<edge_angle> edges_detected, edges_lonly;
  buildListOfEdgeAngle(adj, edges_detected, edges_lonly);

  double threshold = ExtractEdgesOptions_Number[0].def / 180. * M_PI;
  for(unsigned int i = 0; i < edges_detected.size(); i++){
    if(edges_detected[i].angle <= threshold) break;
    add_edge(edges_detected[i], data2);
  } 

  if(ExtractEdgesOptions_Number[1].def){
    for(unsigned int i = 0; i < edges_lonly.size(); i++){
      add_edge(edges_lonly[i], data2);
    } 
  }

  data2->setName("ExtractEdges");
  data2->setFileName("ExtractEdges.pos");
  data2->finalize();

  return v2;
}
