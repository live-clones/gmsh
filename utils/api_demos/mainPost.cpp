// configure, compile and install Gmsh as a library with
//
//   ./configure --disable-gui
//   make install-lib
//
// Then compile this driver with "g++ driver.cpp -lGmsh -llapack -lblas"

#include <stdio.h>
#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>

    std::vector<GEntity*> entities;
    GModel::current()->getEntities(entities);
    std::map<int, std::vector<double> > d;
    for(unsigned int i = 0; i < entities.size(); i++){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        d[e->getNum()].push_back(e->gammaShapeMeasure());
      }
    }
    new PView(name, "ElementData", GModel::current(), d);
    PluginManager::instance()->setPluginOption("CutPlane", "A", 1.); 
    PluginManager::instance()->setPluginOption("CutPlane", "B", 0.); 
    PluginManager::instance()->setPluginOption("CutPlane", "C", 0.); 
    PluginManager::instance()->setPluginOption("CutPlane", "D", -0.05); 
    PluginManager::instance()->setPluginOption("CutPlane", "iView", 0.); 
    PluginManager::instance()->action("CutPlane", "Run", 0);

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GmshSetOption("Mesh", "Algorithm", 5);
  GModel *m = new GModel();
  m->readGEO("../../tutorial/t5.geo");
  m->mesh(3);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    GRegion *r = *it;
    printf("volume %d contains %d elements:\n", r->tag(), r->getNumMeshElements());
    for(unsigned int i = 0; i < r->getNumMeshElements(); i++)
      printf(" %d", r->getMeshElement(i)->getNum());
    printf("\n");
  }
  m->writeMSH("test.msh");
  m->writeUNV("test.unv");
  delete m;
  GmshFinalize();
}
