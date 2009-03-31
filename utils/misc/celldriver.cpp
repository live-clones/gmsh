// configure, compile and install Gmsh as a library with
//
//   ./configure --disable-gui --disable-netgen --disable-chaco --prefix=/usr/local/
//   make install-lib
//
// Then compile this driver with "g++ celldriver.cpp -lGmsh -llapack -lblas -lgmp"
//
// This program creates .msh files reduced_complex.msh and coreduced_complex.msh
// of an two port transformer model to represent its relative homology groups.


#include <stdio.h>
#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>
#include <gmsh/CellComplex.h>


int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GModel *m = new GModel();
  m->readGEO("transformer.geo");
  m->mesh(3);
  m->writeMSH("transformer.msh");
  
  printf("This model has: %d GRegions, %d GFaces, %d GEdges and %d GVertices. \n" , m->getNumRegions(), m->getNumFaces(), m->getNumEdges(), m->getNumVertices());
  
  std::vector<GEntity*> domain;
  std::vector<GEntity*> subdomain;
  
  // whole model
  for(GModel::riter rit = m->firstRegion(); rit != m->lastRegion(); rit++){
    GEntity *r = *rit;
    domain.push_back(r);
  }

  // the ports
  GModel::fiter sub = m->firstFace();
  GEntity *s = *sub;
  subdomain.push_back(s);
  s = *(++sub);
  subdomain.push_back(s);
  s =*(++sub);
  subdomain.push_back(s);
  s= *(++sub);
  subdomain.push_back(s);
  
  CellComplex complex = CellComplex(domain, subdomain);

  printf("Cell complex of this model has: %d volumes, %d faces, %d edges and %d vertices\n",
         complex.getSize(3), complex.getSize(2), complex.getSize(1), complex.getSize(0));  
  
  complex.reduceComplex();
  complex.writeComplexMSH("reduced_complex.msh");
  complex.coreduceComplex();
  complex.writeComplexMSH("coreduced_complex.msh");
    
  delete m;
  GmshFinalize();
  
}




