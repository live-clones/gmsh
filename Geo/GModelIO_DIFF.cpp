// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <string.h>
#include "GModel.h"
#include "MElement.h"

static bool getVertices(int num, int *indices, std::map<int, MVertex*> &map,
                        std::vector<MVertex*> &vertices)
{
  for(int i = 0; i < num; i++){
    if(!map.count(indices[i])){
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(map[indices[i]]);
  }
  return true;
}

static bool getVertices(int num, int *indices, std::vector<MVertex*> &vec,
                        std::vector<MVertex*> &vertices, int minVertex = 0)
{
  for(int i = 0; i < num; i++){
    if(indices[i] < minVertex || indices[i] > (int)(vec.size() - 1 + minVertex)){
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

int GModel::readDIFF(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "XXX";
  std::map<int, std::vector<MElement*> > elements[10];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::map<int, MVertex*> vertexMap;
  std::vector<MVertex*> vertexVector;

  {
    while(strstr(str, "Number of space dim. =") == NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }

    int dim;
    if(sscanf(str, "%*s %*s %*s %*s %*s %d", &dim) != 1) return 0;
    Msg::Info("dimension %d", dim);

    int numElements;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) return 0;
    while(strstr(str, "Number of elements   =") == NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    if(sscanf(str, "%*s %*s %*s %*s %d", &numElements) != 1) return 0;
    Msg::Info("%d elements", numElements);

    int numVertices;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) return 0;
    while(strstr(str, "Number of nodes      =") == NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    if(sscanf(str, "%*s %*s %*s %*s %d", &numVertices) != 1) return 0;
    Msg::Info("%d vertices", numVertices);

    int numVerticesPerElement;
    if(!fgets(str, sizeof(str), fp)||feof(fp)) return 0;
    while(strstr(str, "Max number of nodes in an element:")==NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    if(sscanf(str, "%*s %*s %*s %*s %*s %*s %*s %d", &numVerticesPerElement) != 1)
      return 0;
    Msg::Info("numVerticesPerElement %d", numVerticesPerElement);

    bool several_subdomains;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) return 0;
    if(!strncmp(&str[2], "Only one material", 17) ||
       !strncmp(&str[2], "Only one subdomain", 18)){
      if(!strncmp(&str[37], "dpTRUE", 6) || !strncmp(&str[37], "true", 4) ||
         !strncmp(&str[36], "dpTRUE", 6) || !strncmp(&str[36], "true", 4)){
        several_subdomains = false;
      }
      else{
        several_subdomains = true;
      }
      Msg::Info("several_subdomains %x %s", several_subdomains, str);
    }

    int nbi;
    std::vector<int> bi;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) return 0;
    while(strstr(str, "Boundary indicators:") == NULL &&
          strstr(str, "boundary indicators:") == NULL){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    if(sscanf(str, "%d %*s %*s", &nbi) != 1) return 0;
    Msg::Info("nbi %d", nbi);
    if(nbi != 0)
      bi.resize(nbi);
    std::string format_read_bi = "%*d %*s %*s";
    for(int i = 0; i < nbi; i++){
      if(format_read_bi[format_read_bi.size()-1] == 'd') {
        format_read_bi[format_read_bi.size()-1] = '*';
        format_read_bi += "d %d";
      }
      else
        format_read_bi += " %d";
      if(sscanf(str, format_read_bi.c_str(), &bi[i]) != 1) return 0;
      Msg::Info("bi[%d]=%d", i, bi[i]);
    }

    while(str[0] != '#'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    vertexVector.clear();
    vertexMap.clear();
    int minVertex = numVertices + 1, maxVertex = -1;
    int num = 0;
    std::vector<std::vector<int> > elementary(numVertices);

    Msg::ResetProgressMeter();
    for(int i = 0; i < numVertices; i++){
      if(!fgets(str, sizeof(str), fp)) return 0;
      double xyz[3];
      int tmp;
      if(sscanf(str, "%d ( %lf , %lf , %lf ) [%d]", &num,
                &xyz[0], &xyz[1], &xyz[2], &tmp) != 5) return 0;
      elementary[i].resize(tmp + 1);
      elementary[i][0] = tmp;
      minVertex = std::min(minVertex, num);
      maxVertex = std::max(maxVertex, num);
      if(vertexMap.count(num))
        Msg::Warning("Skipping duplicate vertex %d", num);
      else
        vertexMap[num] = new MVertex(xyz[0], xyz[1], xyz[2], 0, num);
      if(numVertices > 100000)
        Msg::ProgressMeter(i + 1, numVertices, true, "Reading nodes");
      // If the vertex numbering is dense, tranfer the map into a
      // vector to speed up element creation
      if((int)vertexMap.size() == numVertices &&
         ((minVertex == 1 && maxVertex == numVertices) ||
          (minVertex == 0 && maxVertex == numVertices - 1))){
        Msg::Info("Vertex numbering is dense");
        vertexVector.resize(vertexMap.size() + 1);
        if(minVertex == 1)
          vertexVector[0] = 0;
        else
          vertexVector[numVertices] = 0;
        std::map<int, MVertex*>::const_iterator it = vertexMap.begin();
        for(; it != vertexMap.end(); ++it)
          vertexVector[it->first] = it->second;
        vertexMap.clear();
      }
      Msg::Info("%d ( %lf , %lf , %lf ) [%d]",i, xyz[0], xyz[1], xyz[2],
                elementary[i][0]);
      std::string format_read_bi = "%*d ( %*lf , %*lf , %*lf ) [%*d]";
      for(int j = 0; j < elementary[i][0]; j++){
        if(format_read_bi[format_read_bi.size() - 1] == 'd') {
          format_read_bi[format_read_bi.size() - 1] = '*';
          format_read_bi += "d %d";
        }
        else
          format_read_bi += " %d";
        if(sscanf(str, format_read_bi.c_str(), &(elementary[i][j + 1])) != 1)
          return 0;
        Msg::Info("elementary[%d][%d]=%d", i + 1, j + 1, elementary[i][j + 1]);
      }
    }
    while(str[0] != '#'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    std::vector<int> material(numElements);
    std::vector<std::vector<int> > ElementsNodes(numElements);
    for(int i = 0; i < numElements; i++){
      ElementsNodes[i].resize(numVerticesPerElement);
    }
    char eleTypec[20]="";
    std::string eleType;
    Msg::ResetProgressMeter();
    std::vector<int> mapping;
    for(int i = 1; i <= numElements; i++){
      if(!fgets(str, sizeof(str), fp)) return 0;
      int num = 0, type, physical = 0, partition = 0;
      int indices[60];
      if(sscanf(str, "%*d %s %d", eleTypec, &material[i-1]) != 2) return 0;
      eleType = std::string(eleTypec);
      int k2; // local number for the element
      int NoVertices; // number of vertices per element
      if(eleType == "ElmT3n2D"){
        NoVertices = 3;
        static int map[3] = {0, 1, 2}; // identical to gmsh
        mapping=std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TRI_3;
      }
      else if(eleType == "ElmT6n2D"){
        NoVertices = 6;
        static int map[6] = {0, 1, 2, 3, 4, 5}; // identical to gmsh
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TRI_6;
      }
      else if(eleType == "ElmB4n2D"){
        NoVertices = 4;
        static int map[4] = {0, 1, 3, 2}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_QUA_4;
      }
      else if(eleType == "ElmB8n2D"){
        NoVertices = 8;
        static int map[8] = {0, 1, 3, 2, 4, 6, 7, 5}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_QUA_8;
      }
      else if(eleType == "ElmB9n2D"){
        NoVertices = 9;
        static int map[9] = {0, 4, 1, 7, 8, 5, 3, 6, 2}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_QUA_9;
      }
      else if(eleType == "ElmT4n3D"){
        NoVertices = 4;
        static int map[4] = {0, 1, 2, 3}; // identical to gmsh
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TET_4;
      }
      else if(eleType == "ElmT10n3D"){
        NoVertices = 10;
        static int map[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TET_10;
      }
      else if(eleType == "ElmB8n3D"){
        NoVertices = 8;
        static int map[8] = {4, 5, 0, 1, 7, 6, 3, 2};
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_HEX_8;
      }
      else if(eleType == "ElmB20n3D"){
        NoVertices = 20;
        static int map[20] = {4, 5, 0, 1, 7, 6, 3, 2, 16, 8, 19, 13, 15, 12,
                              14, 17, 18, 9, 11};
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_HEX_20;
      }
      else if(eleType == "ElmB27n3D"){
        NoVertices = 27;
        static int map[27] = {4, 16, 5, 10, 21, 12, 0, 8, 1, 17, 25, 18, 22,
                              26, 23, 9, 20, 11, 7, 19, 6, 15, 24, 14, 3, 13, 2};
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_HEX_27;
      }
      else{
        return 0;
      }
      std::string format_read_vertices = "%*d %*s %*d";
      for(int k = 0; k < NoVertices; k++){
        if(format_read_vertices[format_read_vertices.size()-2] != '*') {
          format_read_vertices[format_read_vertices.size()-1] = '*';
          format_read_vertices += "d %d";
        }
        else
          format_read_vertices += " %d";
        k2 = mapping[k];
        if(sscanf(str, format_read_vertices.c_str(), &ElementsNodes[i-1][k2]) != 1)
          return 0;
      }
      mapping.clear();
      for(int j = 0; j < NoVertices; j++)
        indices[j] = ElementsNodes[i - 1][j];
      std::vector<MVertex*> vertices;
      if(vertexVector.size()){
        if(!getVertices(numVerticesPerElement, indices, vertexVector, vertices))
          return 0;
      }
      else{
        if(!getVertices(numVerticesPerElement, indices, vertexMap, vertices))
          return 0;
      }
      _createElementMSH(num, type, physical, elementary[i-1][1], partition,
                        vertices, elements, physicals);
      // trouble if elementary[i-1][0]>1 nodal post-processing needed ?
      if(numElements > 100000)
        Msg::ProgressMeter(i + 1, numElements, true, "Reading elements");
    }
  }

  // store the elements in their associated elementary entity. If the
  // entity does not exist, create a new (discrete) one.
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);

  // associate the correct geometrical entity with each mesh vertex
  _associateEntityWithMeshVertices();

  // store the vertices in their associated geometrical entity
  if(vertexVector.size())
    _storeVerticesInEntities(vertexVector);
  else
    _storeVerticesInEntities(vertexMap);

  // store the physical tags
  for(int i = 0; i < 4; i++)
    _storePhysicalTagsInEntities(i, physicals[i]);

  fclose(fp);
  return 1;
}

int GModel::writeDIFF(const std::string &name, bool binary, bool saveAll,
                      double scalingFactor)
{
  if(binary){
    Msg::Error("Binary DIFF output is not implemented");
    return 0;
  }

  FILE *fp = fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll);

  // tag the vertices according to which surface they belong to (Note
  // that we use a brute force approach here, so that we can deal with
  // models with incomplete topology. For example, when we merge 2 STL
  // triangulations we don't have the boundary information between the
  // faces, and the vertices would end up categorized on either one.)
  std::vector<std::list<int> > vertexTags(numVertices);
  std::list<int> boundaryIndicators;
  for(riter it = firstRegion(); it != lastRegion(); it++){
    std::list<GFace*> faces = (*it)->faces();
    for(std::list<GFace*>::iterator itf = faces.begin(); itf != faces.end(); itf++){
      GFace *gf = *itf;
      boundaryIndicators.push_back(gf->tag());
      for(unsigned int i = 0; i < gf->getNumMeshElements(); i++){
        MElement *e = gf->getMeshElement(i);
        for(int j = 0; j < e->getNumVertices(); j++){
          MVertex *v = e->getVertex(j);
          if(v->getIndex() > 0)
            vertexTags[v->getIndex() - 1].push_back(gf->tag());
        }
      }
    }
  }
  boundaryIndicators.sort();
  boundaryIndicators.unique();
  for(int i = 0; i < numVertices; i++){
    vertexTags[i].sort();
    vertexTags[i].unique();
  }

  // get all the entities in the model
  std::vector<GEntity*> entities;
  getEntities(entities);

  // find max dimension of mesh elements we need to save
  int dim = 0;
  for(unsigned int i = 0; i < entities.size(); i++)
    if(entities[i]->physicals.size() || saveAll)
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
        dim = std::max(dim, entities[i]->getMeshElement(j)->getDim());

  // loop over all elements we need to save
  int numElements = 0, maxNumNodesPerElement = 0;
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->physicals.size() || saveAll){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        if(e->getStringForDIFF() && e->getDim() == dim){
          numElements++;
          maxNumNodesPerElement = std::max(maxNumNodesPerElement, e->getNumVertices());
        }
      }
    }
  }

  fprintf(fp, "\n\n");
  fprintf(fp, " Finite element mesh (GridFE):\n\n");
  fprintf(fp, " Number of space dim. =   3\n");
  fprintf(fp, " Number of elements   =  %d\n", numElements);
  fprintf(fp, " Number of nodes      =  %d\n\n", numVertices);
  fprintf(fp, " All elements are of the same type : dpTRUE\n");
  fprintf(fp, " Max number of nodes in an element: %d \n", maxNumNodesPerElement);
  fprintf(fp, " Only one subdomain               : dpFALSE\n");
  fprintf(fp, " Lattice data                     ? 0\n\n\n\n");
  fprintf(fp, " %d Boundary indicators:  ", (int)boundaryIndicators.size());
  for(std::list<int>::iterator it = boundaryIndicators.begin();
      it != boundaryIndicators.end(); it++)
    fprintf(fp, " %d", *it);

  fprintf(fp, "\n\n\n");
  fprintf(fp,"  Nodal coordinates and nodal boundary indicators,\n");
  fprintf(fp,"  the columns contain:\n");
  fprintf(fp,"   - node number\n");
  fprintf(fp,"   - coordinates\n");
  fprintf(fp,"   - no of boundary indicators that are set (ON)\n");
  fprintf(fp,"   - the boundary indicators that are set (ON) if any.\n");
  fprintf(fp,"#\n");

  // write mesh vertices
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      if(v->getIndex() > 0){
        v->writeDIFF(fp, binary, scalingFactor);
        fprintf(fp, " [%d] ", (int)vertexTags[v->getIndex() - 1].size());
        for(std::list<int>::iterator it = vertexTags[v->getIndex() - 1].begin();
            it != vertexTags[v->getIndex() - 1].end(); it++)
          fprintf(fp," %d ", *it);
        fprintf(fp,"\n");
      }
    }
  }

  fprintf(fp, "\n");
  fprintf(fp, "\n");
  fprintf(fp,     "  Element types and connectivity\n");
  fprintf(fp,     "  the columns contain:\n");
  fprintf(fp,     "   - element number\n");
  fprintf(fp,     "   - element type\n");
  fprintf(fp,     "   - subdomain number \n");
  fprintf(fp,     "   - the global node numbers of the nodes in the element.\n");
  fprintf(fp,     "#\n");

  // write mesh elements
  int num = 0;
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->physicals.size() || saveAll){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        if(e->getStringForDIFF() && e->getDim() == dim)
          e->writeDIFF(fp, ++num, binary, entities[i]->tag());
      }
    }
  }
  fprintf(fp, "\n");

  fclose(fp);
  return 1;
}
