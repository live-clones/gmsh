// g++ -I/usr/local/opencascade/inc driverOCC.cpp -lGmsh -L/usr/local/opencascade/lib -lTKSTEP -lTKSTEP209 -lTKSTEPAttr -lTKSTEPBase -lTKIGES -lTKXSBase -lTKOffset -lTKFeat -lTKFillet -lTKBool -lTKShHealing -lTKMesh -lTKHLR -lTKBO -lTKPrim -lTKTopAlgo -lTKGeomAlgo -lTKBRep -lTKGeomBase -lTKG3d -lTKG2d -lTKAdvTools -lTKMath -lTKernel -lm

#if !defined(WIN32) || defined(__CYGWIN__)
#include "config.h"
#endif
#include "TopoDS_Shape.hxx"
#include "BRep_Tool.hxx"
#include "BRep_Builder.hxx"
#include "BRepTools.hxx"

#include <stdio.h>
#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>

int main(int argc, char **argv)
{
  // create an OCC shape (by loading it from a brep file)
  TopoDS_Shape shape;
  BRep_Builder builder;
  BRepTools::Read(shape, argv[1], builder);
  BRepTools::Clean(shape);

  // import the shape in gmsh and mesh it
  GmshInitialize(argc, argv);
  GModel *m = new GModel();
  m->importOCCShape((void*)&shape, 0);
  m->mesh(2);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    GRegion *r = *it;
    printf("volume %d contains %d elements:\n", r->tag(), r->getNumMeshElements());
    for(unsigned int i = 0; i < r->getNumMeshElements(); i++)
      printf(" %d", r->getMeshElement(i)->getNum());
    printf("\n");
  }
  m->writeMSH("test.msh");
  delete m;
  GmshFinalize();
}
