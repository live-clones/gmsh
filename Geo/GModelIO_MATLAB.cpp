// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GModel.h"
#include "OS.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "StringUtils.h"

int GModel::writeMATLAB(const std::string &name, bool binary, bool saveAll, double scalingFactor)
{
  if(binary)
    {
      Msg::Warning("Binary format not available for Matlab, saving into ASCII format");
      binary = false;
      //TODO !
    }

  FILE *fp = Fopen(name.c_str(), binary ? "wb":"w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll);

  fprintf(fp, "\%\%  Matlab mesh\n");
  fprintf(fp, "\%\% %s, Created by Gmsh\n", getName().c_str());
  if(binary)
    fprintf(fp, "\%\% BINARY\n"); 
  else
    fprintf(fp, "\%\% ASCII\n");

  // get all the entities in the model
  std::vector<GEntity*> entities;
  getEntities(entities);

  // write mesh vertices
  fprintf(fp, "gVertices = %d;\n", numVertices);
  fprintf(fp, "gX = zeros(gVertices,1);\n", numVertices);
  fprintf(fp, "gY = zeros(gVertices,1);\n", numVertices);
  fprintf(fp, "gZ = zeros(gVertices,1);\n", numVertices);
  int cpt = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++)
      {
	cpt ++;
	entities[i]->mesh_vertices[j]->writeMATLAB(fp, cpt, scalingFactor);
      }
  fprintf(fp, "\n");

  // loop over all elements we need to save and count vertices
  int numElements = 0, totalNumInt = 0;
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->physicals.size() || saveAll){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        if(entities[i]->getMeshElement(j)->getTypeForMATLAB()){
          numElements++;
          totalNumInt += entities[i]->getMeshElement(j)->getNumVertices() + 1;
        }
      }
    }
  }

  // print vertex indices in ascii or binary
  fprintf(fp, "\%\%\n");
  fprintf(fp, "nTri=%d;\n", numElements);  
  fprintf(fp, "gTri=[\n");
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->physicals.size() || saveAll){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        if(entities[i]->getMeshElement(j)->getTypeForMATLAB())
          entities[i]->getMeshElement(j)->writeMATLAB(fp, binary);
      }
    }
  }
  fprintf(fp, "];\n");

  fclose(fp);
  return 1;
}
