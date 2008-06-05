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

  GModel m;
  m.importOCCShape((void*)&shape, 0);
  m.mesh(2);

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
