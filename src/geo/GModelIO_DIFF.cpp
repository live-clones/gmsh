// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <string.h>
#include "GModel.h"
#include "OS.h"
#include "MElement.h"

static bool getMeshVertices(int num, int *indices,
                            std::map<std::size_t, MVertex *> &map,
                            std::vector<MVertex *> &vertices)
{
  for(int i = 0; i < num; i++) {
    if(!map.count(indices[i])) {
      Msg::Error("Wrong node index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(map[indices[i]]);
  }
  return true;
}

static bool getMeshVertices(int num, int *indices, std::vector<MVertex *> &vec,
                            std::vector<MVertex *> &vertices, int minVertex = 0)
{
  for(int i = 0; i < num; i++) {
    if(indices[i] < minVertex ||
       indices[i] > (int)(vec.size() - 1 + minVertex)) {
      Msg::Error("Wrong node index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

int GModel::readDIFF(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "r");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "XXX";
  std::map<int, std::vector<MElement *> > elements[10];
  std::map<std::size_t, MVertex *> vertexMap;
  std::vector<MVertex *> vertexVector;

  {
    while(strstr(str, "Number of space dim. =") == nullptr) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }

    int dim;
    if(sscanf(str, "%*s %*s %*s %*s %*s %d", &dim) != 1) {
      fclose(fp);
      return 0;
    }
    Msg::Info("dimension %d", dim);

    int numElements;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    while(strstr(str, "Number of elements   =") == nullptr) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }
    if(sscanf(str, "%*s %*s %*s %*s %d", &numElements) != 1) {
      fclose(fp);
      return 0;
    }
    Msg::Info("%d elements", numElements);

    int numVertices;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    while(strstr(str, "Number of nodes      =") == nullptr) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }
    if(sscanf(str, "%*s %*s %*s %*s %d", &numVertices) != 1) {
      fclose(fp);
      return 0;
    }
    Msg::Info("%d nodes", numVertices);

    int numVerticesPerElement;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    while(strstr(str, "Max number of nodes in an element:") == nullptr) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }
    if(sscanf(str, "%*s %*s %*s %*s %*s %*s %*s %d", &numVerticesPerElement) !=
       1) {
      fclose(fp);
      return 0;
    }
    Msg::Info("numVerticesPerElement %d", numVerticesPerElement);

    bool severalSubdomains;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    if(!strncmp(&str[2], "Only one material", 17) ||
       !strncmp(&str[2], "Only one subdomain", 18)) {
      if(!strncmp(&str[37], "dpTRUE", 6) || !strncmp(&str[37], "true", 4) ||
         !strncmp(&str[36], "dpTRUE", 6) || !strncmp(&str[36], "true", 4)) {
        severalSubdomains = false;
      }
      else {
        severalSubdomains = true;
      }
      Msg::Info("several subdomains %x %s", severalSubdomains, str);
    }

    int nbi;
    std::vector<int> bi;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    while(strstr(str, "Boundary indicators:") == nullptr &&
          strstr(str, "boundary indicators:") == nullptr) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }
    if(sscanf(str, "%d %*s %*s", &nbi) != 1) {
      fclose(fp);
      return 0;
    }
    Msg::Info("nbi %d", nbi);
    if(nbi != 0) bi.resize(nbi);
    std::string format_read_bi = "%*d %*s %*s";
    for(int i = 0; i < nbi; i++) {
      if(format_read_bi[format_read_bi.size() - 1] == 'd') {
        format_read_bi[format_read_bi.size() - 1] = '*';
        format_read_bi += "d %d";
      }
      else
        format_read_bi += " %d";
      if(sscanf(str, format_read_bi.c_str(), &bi[i]) != 1) {
        fclose(fp);
        return 0;
      }
      Msg::Info("bi[%d]=%d", i, bi[i]);
    }

    while(str[0] != '#') {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }
    vertexVector.clear();
    vertexMap.clear();
    int minVertex = numVertices + 1, maxVertex = -1;
    int num = 0;
    std::vector<std::vector<int> > elementary(numVertices);

    Msg::StartProgressMeter(numVertices);
    for(int i = 0; i < numVertices; i++) {
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return 0;
      }
      double xyz[3];
      int tmp;
      if(sscanf(str, "%d ( %lf , %lf , %lf ) [%d]", &num, &xyz[0], &xyz[1],
                &xyz[2], &tmp) != 5) {
        fclose(fp);
        return 0;
      }
      elementary[i].resize(tmp + 1);
      elementary[i][0] = tmp;
      minVertex = std::min(minVertex, num);
      maxVertex = std::max(maxVertex, num);
      if(vertexMap.count(num))
        Msg::Warning("Skipping duplicate node %d", num);
      else
        vertexMap[num] = new MVertex(xyz[0], xyz[1], xyz[2], nullptr, num);
      if(numVertices > 100000) Msg::ProgressMeter(i + 1, true, "Reading nodes");
      // If the vertex numbering is dense, tranfer the map into a
      // vector to speed up element creation
      if((int)vertexMap.size() == numVertices &&
         ((minVertex == 1 && maxVertex == numVertices) ||
          (minVertex == 0 && maxVertex == numVertices - 1))) {
        Msg::Info("Vertex numbering is dense");
        vertexVector.resize(vertexMap.size() + 1);
        if(minVertex == 1)
          vertexVector[0] = nullptr;
        else
          vertexVector[numVertices] = nullptr;
        for(auto it = vertexMap.begin(); it != vertexMap.end(); ++it)
          vertexVector[it->first] = it->second;
        vertexMap.clear();
      }
      Msg::Info("%d ( %lf , %lf , %lf ) [%d]", i, xyz[0], xyz[1], xyz[2],
                elementary[i][0]);
      std::string format_read_bi = "%*d ( %*lf , %*lf , %*lf ) [%*d]";
      for(int j = 0; j < elementary[i][0]; j++) {
        if(format_read_bi[format_read_bi.size() - 1] == 'd') {
          format_read_bi[format_read_bi.size() - 1] = '*';
          format_read_bi += "d %d";
        }
        else
          format_read_bi += " %d";
        if(sscanf(str, format_read_bi.c_str(), &(elementary[i][j + 1])) != 1) {
          fclose(fp);
          return 0;
        }
        Msg::Info("elementary[%d][%d]=%d", i + 1, j + 1, elementary[i][j + 1]);
      }
    }
    Msg::StopProgressMeter();

    while(str[0] != '#') {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }
    std::vector<int> material(numElements);
    std::vector<std::vector<int> > ElementsNodes(numElements);
    for(int i = 0; i < numElements; i++) {
      ElementsNodes[i].resize(numVerticesPerElement);
    }
    char eleTypec[20] = "";
    std::string eleType;
    std::vector<int> mapping;

    Msg::StartProgressMeter(numElements);
    for(int i = 1; i <= numElements; i++) {
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return 0;
      }
      int num = 0, type;
      int indices[60];
      if(sscanf(str, "%*d %s %d", eleTypec, &material[i - 1]) != 2) {
        fclose(fp);
        return 0;
      }
      eleType = std::string(eleTypec);
      int k2; // local number for the element
      int NoVertices; // number of vertices per element
      if(eleType == "ElmT3n2D") {
        NoVertices = 3;
        static int map[3] = {0, 1, 2}; // identical to gmsh
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TRI_3;
      }
      else if(eleType == "ElmT6n2D") {
        NoVertices = 6;
        static int map[6] = {0, 1, 2, 3, 4, 5}; // identical to gmsh
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TRI_6;
      }
      else if(eleType == "ElmB4n2D") {
        NoVertices = 4;
        static int map[4] = {0, 1, 3, 2}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_QUA_4;
      }
      else if(eleType == "ElmB8n2D") {
        NoVertices = 8;
        static int map[8] = {0, 1, 3, 2, 4, 6, 7, 5}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_QUA_8;
      }
      else if(eleType == "ElmB9n2D") {
        NoVertices = 9;
        static int map[9] = {0, 4, 1, 7, 8, 5, 3, 6, 2}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_QUA_9;
      }
      else if(eleType == "ElmT4n3D") {
        NoVertices = 4;
        static int map[4] = {0, 1, 2, 3}; // identical to gmsh
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TET_4;
      }
      else if(eleType == "ElmT10n3D") {
        NoVertices = 10;
        static int map[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // local numbering
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_TET_10;
      }
      else if(eleType == "ElmB8n3D") {
        NoVertices = 8;
        static int map[8] = {4, 5, 0, 1, 7, 6, 3, 2};
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_HEX_8;
      }
      else if(eleType == "ElmB20n3D") {
        NoVertices = 20;
        static int map[20] = {4,  5,  0,  1,  7,  6,  3,  2, 16, 8,
                              19, 13, 15, 12, 14, 17, 18, 9, 11};
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_HEX_20;
      }
      else if(eleType == "ElmB27n3D") {
        NoVertices = 27;
        static int map[27] = {4,  16, 5,  10, 21, 12, 0, 8,  1,
                              17, 25, 18, 22, 26, 23, 9, 20, 11,
                              7,  19, 6,  15, 24, 14, 3, 13, 2};
        mapping = std::vector<int>(map, map + sizeof(map) / sizeof(int));
        type = MSH_HEX_27;
      }
      else {
        fclose(fp);
        return 0;
      }
      std::string format_read_vertices = "%*d %*s %*d";
      for(int k = 0; k < NoVertices; k++) {
        if(format_read_vertices[format_read_vertices.size() - 2] != '*') {
          format_read_vertices[format_read_vertices.size() - 1] = '*';
          format_read_vertices += "d %d";
        }
        else
          format_read_vertices += " %d";
        k2 = mapping[k];
        if(sscanf(str, format_read_vertices.c_str(),
                  &ElementsNodes[i - 1][k2]) != 1) {
          fclose(fp);
          return 0;
        }
      }
      mapping.clear();
      for(int j = 0; j < NoVertices; j++) indices[j] = ElementsNodes[i - 1][j];
      std::vector<MVertex *> vertices;
      if(vertexVector.size()) {
        if(!getMeshVertices(numVerticesPerElement, indices, vertexVector,
                            vertices)) {
          fclose(fp);
          return 0;
        }
      }
      else {
        if(!getMeshVertices(numVerticesPerElement, indices, vertexMap,
                            vertices)) {
          fclose(fp);
          return 0;
        }
      }

      MElementFactory f;
      MElement *e = f.create(type, vertices, num);
      if(!e) {
        Msg::Error("Unknown type of element %d", type);
        fclose(fp);
        return 0;
      }
      int reg = material[i - 1];
      switch(e->getType()) {
      case TYPE_PNT: elements[0][reg].push_back(e); break;
      case TYPE_LIN: elements[1][reg].push_back(e); break;
      case TYPE_TRI: elements[2][reg].push_back(e); break;
      case TYPE_QUA: elements[3][reg].push_back(e); break;
      case TYPE_TET: elements[4][reg].push_back(e); break;
      case TYPE_HEX: elements[5][reg].push_back(e); break;
      case TYPE_PRI: elements[6][reg].push_back(e); break;
      case TYPE_PYR: elements[7][reg].push_back(e); break;
      default:
        Msg::Error("Wrong type of element");
        fclose(fp);
        return 0;
      }
      if(numElements > 100000)
        Msg::ProgressMeter(i + 1, true, "Reading elements");
    }
    Msg::StopProgressMeter();
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

  fclose(fp);
  return 1;
}

int GModel::writeDIFF(const std::string &name, bool binary, bool saveAll,
                      double scalingFactor)
{
  if(binary) {
    Msg::Error("Binary DIFF output is not implemented");
    return 0;
  }

  FILE *fp = Fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // make this an option?
  bool usePhysicalTags = true;

  if(noPhysicalGroups()) {
    saveAll = true;
    usePhysicalTags = false;
  }

  // get the number of vertices and flag vertices to skip
  int numVertices = indexMeshVertices(saveAll, 0, false);

  // get all the entities in the model
  std::vector<GEntity *> entities;
  getEntities(entities);

  // find max dimension of mesh elements we need to save
  int dim = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    if((entities[i]->physicals.size() || saveAll) &&
       entities[i]->getNumMeshElements()) {
      dim = std::max(dim, entities[i]->dim());
    }
  }

  // tag the vertices according to which boundary entity they belong to (note
  // that we use a brute force approach here, so that we can deal with models
  // with incomplete topology)
  std::vector<std::list<int> > vertexTags(numVertices);
  std::list<int> boundaryIndicators;
  for(std::size_t ient = 0; ient < entities.size(); ient++) {
    GEntity *ge = entities[ient];
    if(ge->dim() != dim - 1) continue;
    // we are on a "boundary"
    if(usePhysicalTags) {
      for(auto p : ge->physicals) boundaryIndicators.push_back(p);
    }
    else {
      boundaryIndicators.push_back(ge->tag());
    }
    for(std::size_t i = 0; i < ge->getNumMeshElements(); i++) {
      MElement *e = ge->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        MVertex *v = e->getVertex(j);
        if(v->getIndex() > 0) {
          if(usePhysicalTags) {
            for(auto p : ge->physicals)
              vertexTags[v->getIndex() - 1].push_back(p);
          }
          else {
            vertexTags[v->getIndex() - 1].push_back(ge->tag());
          }
        }
      }
    }
  }
  boundaryIndicators.sort();
  boundaryIndicators.unique();
  for(int i = 0; i < numVertices; i++) {
    vertexTags[i].sort();
    vertexTags[i].unique();
  }

  // loop over all elements we need to save
  std::size_t numElements = 0;
  std::size_t maxNumNodesPerElement = 0, minNumNodesPerElement = 1000;
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(entities[i]->physicals.size() || saveAll) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        if(e->getStringForDIFF() && e->getDim() == dim) {
          numElements++;
          maxNumNodesPerElement =
            std::max(maxNumNodesPerElement, e->getNumVertices());
          minNumNodesPerElement =
            std::min(minNumNodesPerElement, e->getNumVertices());
        }
      }
    }
  }

  fprintf(fp, "\n\n");
  fprintf(fp, " Finite element mesh (GridFE):\n\n");
  fprintf(fp, " Number of space dim. =   3\n");
  fprintf(fp, " Number of elements   =  %lu\n", numElements);
  fprintf(fp, " Number of nodes      =  %d\n\n", numVertices);
  fprintf(fp, " All elements are of the same type: %s\n",
          (maxNumNodesPerElement != minNumNodesPerElement) ? "dpFALSE" : "dpTRUE");
  fprintf(fp, " Max number of nodes in an element: %lu \n",
          maxNumNodesPerElement);
  fprintf(fp, " Only one subdomain               : dpFALSE\n");
  fprintf(fp, " Lattice data                     ? 0\n\n\n\n");
  fprintf(fp, " %d Boundary indicators:  ", (int)boundaryIndicators.size());
  for(auto it = boundaryIndicators.begin(); it != boundaryIndicators.end();
      it++)
    fprintf(fp, " %d", *it);

  fprintf(fp, "\n\n\n");
  fprintf(fp, "  Nodal coordinates and nodal boundary indicators,\n");
  fprintf(fp, "  the columns contain:\n");
  fprintf(fp, "   - node number\n");
  fprintf(fp, "   - coordinates\n");
  fprintf(fp, "   - no of boundary indicators that are set (ON)\n");
  fprintf(fp, "   - the boundary indicators that are set (ON) if any.\n");
  fprintf(fp, "#\n");

  // write mesh vertices
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *v = entities[i]->mesh_vertices[j];
      if(v->getIndex() > 0) {
        v->writeDIFF(fp, binary, scalingFactor);
        fprintf(fp, " [%d] ", (int)vertexTags[v->getIndex() - 1].size());
        for(auto it = vertexTags[v->getIndex() - 1].begin();
            it != vertexTags[v->getIndex() - 1].end(); it++)
          fprintf(fp, " %d ", *it);
        fprintf(fp, "\n");
      }
    }
  }

  fprintf(fp, "\n");
  fprintf(fp, "\n");
  fprintf(fp, "  Element types and connectivity\n");
  fprintf(fp, "  the columns contain:\n");
  fprintf(fp, "   - element number\n");
  fprintf(fp, "   - element type\n");
  fprintf(fp, "   - subdomain number \n");
  fprintf(fp, "   - the global node numbers of the nodes in the element.\n");
  fprintf(fp, "#\n");

  // write mesh elements
  int num = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(entities[i]->physicals.size() || saveAll) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        if(e->getStringForDIFF() && e->getDim() == dim) {
          if(usePhysicalTags) {
            for(auto p : entities[i]->physicals)
              e->writeDIFF(fp, ++num, binary, p);
          }
          else {
            e->writeDIFF(fp, ++num, binary, entities[i]->tag());
          }
        }
      }
    }
  }
  fprintf(fp, "\n");

  fclose(fp);
  return 1;
}
