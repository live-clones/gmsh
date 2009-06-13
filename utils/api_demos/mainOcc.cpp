// g++ -I/usr/local/opencascade/inc driverOCC.cpp -lGmsh -L/usr/local/opencascade/lib -lTKSTEP -lTKSTEP209 -lTKSTEPAttr -lTKSTEPBase -lTKIGES -lTKXSBase -lTKOffset -lTKFeat -lTKFillet -lTKBool -lTKShHealing -lTKMesh -lTKHLR -lTKBO -lTKPrim -lTKTopAlgo -lTKGeomAlgo -lTKBRep -lTKGeomBase -lTKG3d -lTKG2d -lTKAdvTools -lTKMath -lTKernel -lm

#include <stdio.h>
#include <gmsh/Gmsh.h>
#include <gmsh/GmshConfig.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>

#if !defined(HAVE_NO_OCC_CONFIG_H)
#include "config.h"
#endif
#include <TopoDS_Shape.hxx>
#include <BRep_Tool.hxx>
#include <BRep_Builder.hxx>
#include <BRepTools.hxx>

class mymsg : public GmshMessage{
private:
  GModel *_model;
public:
  mymsg(GModel *model) : _model(model), GmshMessage() {}
  void operator()(std::string level, std::string msg)
  {
    printf("level=%s msg=%s\n", level.c_str(), msg.c_str());

    if(level == "Fatal" || level == "Error"){
      GEntity *e = _model->getCurrentMeshEntity();
      if(e){
	printf("error occurred while meshing entity:\n");
	printf("  tag=%d\n", e->tag());
	printf("  dimension=%d\n", e->dim());
	printf("  native pointer=%p\n", e->getNativePtr());
      }
    }
    if(level == "Fatal") throw "Fatal error in Gmsh";
  }
};

int main(int argc, char **argv)
{
  // create an OCC shape (by loading it from a brep file)
  TopoDS_Shape shape;
  BRep_Builder builder;
  BRepTools::Read(shape, argv[1], builder);
  BRepTools::Clean(shape);

  // initialize gmsh
  GmshInitialize(argc, argv);

  // create a model and set error handler 
  GModel m;
  mymsg c(&m);
  GmshSetMessageHandler(&c);

  // import the shape, and mesh it
  m.importOCCShape((void*)&shape, 0);
  try{
    m.mesh(2);
  }
  catch(...){
    printf("Unrecoverable error in gmsh--aborting mesh!\n");
  }

  for(GModel::fiter it = m.firstFace(); it != m.lastFace(); ++it){
    GFace *f = *it;
    printf("Surface %d contains %d elements:\n", f->tag(), f->getNumMeshElements());
    for(unsigned int i = 0; i < f->getNumMeshElements(); i++){
      MElement *e = f->getMeshElement(i);
      printf("  element %d:", e->getNum());
      for(unsigned int j = 0; j < e->getNumVertices(); j++){
	MVertex *v = e->getVertex(j);
	printf(" %d (%g,%g,%g)", v->getNum(), v->x(), v->y(), v->z());
      }
      printf("\n");
    }
    printf("\n");
  }

  m.writeMSH("test.msh");

  GmshFinalize();
}
