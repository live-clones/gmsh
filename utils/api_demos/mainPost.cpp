#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MVertex.h>
#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/PluginManager.h>

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GmshSetOption("General", "Terminal", 1.);

  // load a geometry and mesh it
  GModel *m = new GModel();
  m->readGEO("../../tutorial/t1.geo");
  m->mesh(2);

  // create a node-based post-processing dataset
  std::vector<GEntity*> entities;
  m->getEntities(entities);
  std::map<int, std::vector<double> > d;
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->getNumMeshVertices(); j++){
      MVertex *v = entities[i]->getMeshVertex(j);
      d[v->getNum()].push_back(v->x());
    }
  }
  PView *p = new PView("f(x,y,z) = x", "NodeData", m, d);
  p->getData()->writeMSH("f.msh");
  
  // use a plugin on the dataset
  PluginManager::instance()->setPluginOption("CutPlane", "A", 0.); 
  PluginManager::instance()->setPluginOption("CutPlane", "B", 1.); 
  PluginManager::instance()->setPluginOption("CutPlane", "C", 0.); 
  PluginManager::instance()->setPluginOption("CutPlane", "D", -0.05); 
  PluginManager::instance()->setPluginOption("CutPlane", "iView", 0.); 
  PluginManager::instance()->action("CutPlane", "Run", 0);
  PView::list.back()->getData()->writeMSH("fcut.msh");

  GmshFinalize();
}
