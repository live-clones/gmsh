// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <string.h>
#include "GModel.h"
#include "OS.h"
#include "GmshConfig.h"

#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "Context.h"

//#define COMPRESSED_UNV
#if defined(COMPRESSED_UNV) && defined(HAVE_LIBZ)
#include <zlib.h>
typedef gzFile gmshFILE;
#define gmshopen gzopen
#define gmshgets(a, b, c) gzgets((c), (a), (b))
#define gmshclose gzclose
#define gmsheof gzeof
#else
typedef FILE *gmshFILE;
#define gmshopen Fopen
#define gmshgets fgets
#define gmshclose fclose
#define gmsheof feof
#endif

int GModel::readUNV(const std::string &name, bool readGroupsOfElements)
{
  gmshFILE fp = gmshopen(name.c_str(), "r");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  std::map<int, std::vector<MElement *> > elements[7];
  std::map<int, std::map<int, std::string> > physicals[4];
  std::map<int, MElement *> elementTags;
  std::map<MElement *, std::vector<int>, MElementPtrLessThan> elementGroups;
  std::map<int, std::string> groupNames;
  _vertexMapCache.clear();

  while(!gmsheof(fp)) {
    if(!gmshgets(buffer, sizeof(buffer), fp)) break;
    if(!strncmp(buffer, "    -1", 6)) {
      if(!gmshgets(buffer, sizeof(buffer), fp)) break;
      if(!strncmp(buffer, "    -1", 6))
        if(!gmshgets(buffer, sizeof(buffer), fp)) break;
      int record = 0;
      sscanf(buffer, "%d", &record);
      if(record == 2411) { // nodes
        Msg::Info("Reading nodes");
        while(gmshgets(buffer, sizeof(buffer), fp)) {
          if(!strncmp(buffer, "    -1", 6)) break;
          int num, dum;
          if(sscanf(buffer, "%d %d %d %d", &num, &dum, &dum, &dum) != 4) break;
          if(!gmshgets(buffer, sizeof(buffer), fp)) break;
          double x, y, z;
          for(std::size_t i = 0; i < strlen(buffer); i++)
            if(buffer[i] == 'D') buffer[i] = 'E';
          if(sscanf(buffer, "%lf %lf %lf", &x, &y, &z) != 3) break;
          _vertexMapCache[num] = new MVertex(x, y, z, nullptr, num);
        }
      }
      else if(record == 2412) { // elements
        Msg::Info("Reading elements");
        std::map<int, int> warn;
        while(gmshgets(buffer, sizeof(buffer), fp)) {
          if(strlen(buffer) < 3)
            continue; // possible line ending after last fgets
          if(!strncmp(buffer, "    -1", 6)) break;
          int num, type, elementary, physical, color, numNodes;
          if(!CTX::instance()->mesh.switchElementTags) {
            if(sscanf(buffer, "%d %d %d %d %d %d", &num, &type, &elementary,
                      &physical, &color, &numNodes) != 6)
              break;
          }
          else {
            if(sscanf(buffer, "%d %d %d %d %d %d", &num, &type, &physical,
                      &elementary, &color, &numNodes) != 6)
              break;
          }
          if(elementary < 0) elementary = getMaxElementaryNumber(-1) + 1;
          if(physical < 0) physical = 0;
          if(!type) {
            if(warn[type]++ == 1)
              Msg::Warning("No element type: guessing from number of nodes");
            switch(numNodes) {
            case 2: type = 11; break; // line
            case 3: type = 41; break; // tri
            case 4: type = 111; break; // tet
            }
          }

          switch(type) {
          case 11:
          case 21:
          case 22:
          case 31:
          case 23:
          case 24:
          case 32:
            // beam elements
            if(!gmshgets(buffer, sizeof(buffer), fp)) break;
            int dum;
            if(sscanf(buffer, "%d %d %d", &dum, &dum, &dum) != 3) break;
            break;
          }
          std::vector<MVertex *> vertices(numNodes);
          for(int i = 0; i < numNodes; i++) {
            int n;
            if(!gmshgets(buffer, 11, fp)) {
              gmshclose(fp);
              return 0;
            }
            if(strlen(buffer) < 10)
              if(!gmshgets(buffer, 11, fp)) {
                gmshclose(fp);
                return 0;
              }
            if(!sscanf(buffer, "%d", &n)) {
              gmshclose(fp);
              return 0;
            }
            vertices[i] = getMeshVertexByTag(n);
            if(!vertices[i]) {
              Msg::Error("Wrong node index %d", n);
              gmshclose(fp);
              return 0;
            }
          }
          int dim = -1;
          MElement *e = nullptr;
          switch(type) {
          case 11:
          case 21:
          case 22:
          case 31:
            e = new MLine(vertices, num);
            elements[0][elementary].push_back(e);
            dim = 1;
            break;
          case 23:
          case 24:
          case 32:
            e = new MLine3(vertices[0], vertices[2], vertices[1], num);
            elements[0][elementary].push_back(e);
            dim = 1;
            break;
          case 41:
          case 51:
          case 61:
          case 74:
          case 81:
          case 91:
            e = new MTriangle(vertices, num);
            elements[1][elementary].push_back(e);
            dim = 2;
            break;
          case 42:
          case 52:
          case 62:
          case 72:
          case 82:
          case 92:
            e = new MTriangle6(vertices[0], vertices[2], vertices[4],
                               vertices[1], vertices[3], vertices[5], num);
            elements[1][elementary].push_back(e);
            dim = 2;
            break;
          case 44:
          case 54:
          case 64:
          case 71:
          case 84:
          case 94:
            e = new MQuadrangle(vertices, num);
            elements[2][elementary].push_back(e);
            dim = 2;
            break;
          case 45:
          case 55:
          case 65:
          case 75:
          case 85:
          case 95:
            e = new MQuadrangle8(vertices[0], vertices[2], vertices[4],
                                 vertices[6], vertices[1], vertices[3],
                                 vertices[5], vertices[7], num);
            elements[2][elementary].push_back(e);
            dim = 2;
            break;
          case 111:
            e = new MTetrahedron(vertices, num);
            elements[3][elementary].push_back(e);
            dim = 3;
            break;
          case 118:
            e = new MTetrahedron10(vertices[0], vertices[2], vertices[4],
                                   vertices[9], vertices[1], vertices[3],
                                   vertices[5], vertices[6], vertices[8],
                                   vertices[7], num);
            elements[3][elementary].push_back(e);
            dim = 3;
            break;
          case 104:
          case 115:
            e = new MHexahedron(vertices, num);
            elements[4][elementary].push_back(e);
            dim = 3;
            break;
          case 105:
          case 116:
            e = new MHexahedron20(vertices[0], vertices[2], vertices[4],
                                  vertices[6], vertices[12], vertices[14],
                                  vertices[16], vertices[18], vertices[1],
                                  vertices[7], vertices[8], vertices[3],
                                  vertices[9], vertices[5], vertices[10],
                                  vertices[11], vertices[13], vertices[19],
                                  vertices[15], vertices[17], num);
            elements[4][elementary].push_back(e);
            dim = 3;
            break;
          case 101:
          case 112:
            e = new MPrism(vertices, num);
            elements[5][elementary].push_back(e);
            dim = 3;
            break;
          case 102:
          case 113:
            e = new MPrism15(vertices[0], vertices[2], vertices[4],
                             vertices[9], vertices[11], vertices[13],
                             vertices[1], vertices[5], vertices[6],
                             vertices[3], vertices[7], vertices[8],
                             vertices[10], vertices[14], vertices[12], num);
            elements[5][elementary].push_back(e);
            dim = 3;
            break;
          default:
            if(warn[type]++ == 1)
              Msg::Warning("Skipping unknown type of element %d", type);
            break;
          }

          if(dim >= 0 && physical &&
             (!physicals[dim].count(elementary) ||
              !physicals[dim][elementary].count(physical)))
            physicals[dim][elementary][physical] = "unnamed";

          if(e) {
            elementTags[num] = e;
            elementGroups[e].push_back(elementary);
            elementGroups[e].push_back(physical);
          }
        }
      }
      else if(record == 2477 || record == 2452 || record == 2435) {
        if(!readGroupsOfElements) {
          Msg::Info("Ignoring groups (set Mesh.ReadGroupsOfElements to read "
                    "groups of elements)");
        }
        else {
          Msg::Info("Reading groups");
          while(gmshgets(buffer, sizeof(buffer), fp)) {
            if(strlen(buffer) < 3)
              continue; // possible line ending after last fgets
            if(!strncmp(buffer, "    -1", 6)) break;
            int num, constraint, restraint, load, dof, temperature, contact, n;
            if(sscanf(buffer, "%d %d %d %d %d %d %d %d", &num, &constraint,
                      &restraint, &load, &dof, &temperature, &contact, &n) != 8)
              break;
            if(!gmshgets(buffer, sizeof(buffer), fp)) break;
            char name[256];
            if(!sscanf(buffer, "%s", name)) break;
            groupNames[num] = name;
            int e = 0;
            while(e < n) {
              if(!gmshgets(buffer, sizeof(buffer), fp)) break;
              int type, tag, leaf, comp, type2, tag2, leaf2, comp2;
              int r = sscanf(buffer, "%d %d %d %d %d %d %d %d", &type, &tag,
                             &leaf, &comp, &type2, &tag2, &leaf2, &comp2);
              if(r >= 4) {
                e++;
                if(type == 8) elementGroups[elementTags[tag]].push_back(num);
              }
              if(r == 8) {
                e++;
                if(type2 == 8) elementGroups[elementTags[tag2]].push_back(num);
              }
              if(r != 4 && r != 8) break;
            }
          }
        }
      }
    }
  }

  if(groupNames.size()) {
    // if element groups are given, create new elementary entity tags for each
    // unique combination of (elementary, physical, group(s)), as (elementary,
    // physical) has no garantee to be coherent with the element groups (and is
    // usually not - see e.g. the UNV files created by ANSA, where e.g. all
    // surface elements can be associated with the same (elementary, physical)
    // pair but be split amongst (possibly overlapping) element groups)
    std::map<std::vector<int>, int> entity;
    std::map<int, std::vector<MElement *> > elementsNew[7];

    int maxgroup = 0;
    for(auto g : groupNames) maxgroup = std::max(g.first, maxgroup);

    for(auto &it : elementGroups) {
      MElement *e = it.first;
      if(e) {
        int elementaryNew = 0;
        auto ent = entity.find(it.second);
        if(ent == entity.end()) {
          elementaryNew = entity.size() + 1;
          entity[it.second] = elementaryNew;
        }
        else
          elementaryNew = ent->second;
        int t = e->getType();
        int k = (t == TYPE_LIN) ? 0 :
                (t == TYPE_TRI) ? 1 :
                (t == TYPE_QUA) ? 2 :
                (t == TYPE_TET) ? 3 :
                (t == TYPE_HEX) ? 4 :
                (t == TYPE_PRI) ? 5 : -1;
        int dim = e->getDim();
        if(k >= 0) {
          elementsNew[k][elementaryNew].push_back(e);
          if(it.second.size() > 2) {
            // we have one or more element groups
            for(std::size_t g = 2; g < it.second.size(); g++) {
              int physicalNew = it.second[g];
              if(!physicals[dim].count(elementaryNew) ||
                 !physicals[dim][elementaryNew].count(physicalNew))
                physicals[dim][elementaryNew][physicalNew] =
                  groupNames[physicalNew];
            }
          }
          else if(it.second.size() > 1) {
            int physicalNew = CTX::instance()->mesh.switchElementTags ?
              it.second[0] : it.second[1];
            // if the group num exists, add an offset (we could also simply not
            // define physical groups other than those in the element
            // groups... not sure what's best)
            if(groupNames.count(physicalNew)) physicalNew += maxgroup;
            if(!physicals[dim].count(elementaryNew) ||
               !physicals[dim][elementaryNew].count(physicalNew))
              physicals[dim][elementaryNew][physicalNew] = "unnamed";
          }
        }
      }
    }
    for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
      elements[i] = elementsNew[i];
  }

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(_vertexMapCache);

  for(int i = 0; i < 4; i++) _storePhysicalTagsInEntities(i, physicals[i]);

  gmshclose(fp);
  return 1;
}

static std::string physicalName(GModel *m, int dim, int num)
{
  std::string name = m->getPhysicalName(dim, num);
  if(name.empty()) {
    char tmp[256];
    sprintf(tmp, "%s%d",
            (dim == 3) ? "PhysicalVolume" :
            (dim == 2) ? "PhysicalSurface" :
                         "PhysicalLine",
            num);
    name = tmp;
  }
  for(std::size_t i = 0; i < name.size(); i++)
    if(name[i] == ' ') name[i] = '_';
  return name;
}

int GModel::writeUNV(const std::string &name, bool saveAll,
                     int saveGroupsOfElements, int saveGroupsOfNodes,
                     double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  indexMeshVertices(saveAll, 0, false);

  std::vector<GEntity *> entities;
  getEntities(entities);

  // nodes
  fprintf(fp, "%6d\n", -1);
  fprintf(fp, "%6d\n", 2411);
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
      entities[i]->mesh_vertices[j]->writeUNV(
        fp, CTX::instance()->mesh.unvStrictFormat ? true : false,
        scalingFactor);
  fprintf(fp, "%6d\n", -1);

  // elements
  fprintf(fp, "%6d\n", -1);
  fprintf(fp, "%6d\n", 2412);
  for(std::size_t i = 0; i < entities.size(); i++) {
    if(saveAll || entities[i]->physicals.size()) {
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        e->writeUNV(fp, e->getNum(), entities[i]->tag(), 0);
      }
    }
  }
  fprintf(fp, "%6d\n", -1);

  // save groups of nodes (resp. elements) for each physical group if
  // saveGroupsOfNodes (resp. saveGroupsOfElements) is positive; if negative,
  // only save groups if the (dim+1)^th least significant digit of
  // -saveGroupsOfNodes (resp. -saveGroupsOfElements) is non-zero.
  if(saveGroupsOfNodes || saveGroupsOfElements) {
    std::map<int, std::vector<GEntity *> > groups[4];
    getPhysicalGroups(groups);

    fprintf(fp, "%6d\n", -1);
    fprintf(fp, "%6d\n", 2477);
    for(int dim = 0; dim <= 3; dim++) {
      bool saveNodes =
        (saveGroupsOfNodes > 0 ||
         (saveGroupsOfNodes < 0 &&
          ((-saveGroupsOfNodes / (int)std::pow(10, dim)) % 10) == 1));
      bool saveElements =
        (saveGroupsOfElements > 0 ||
         (saveGroupsOfElements < 0 &&
          ((-saveGroupsOfElements / (int)std::pow(10, dim)) % 10) == 1));

      for(auto it = groups[dim].begin(); it != groups[dim].end(); it++) {
        std::vector<GEntity *> &entities = it->second;

        std::set<MVertex *, MVertexPtrLessThan> nodes;
        if(saveNodes) {
          for(std::size_t i = 0; i < entities.size(); i++) {
            for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
              MElement *e = entities[i]->getMeshElement(j);
              for(std::size_t k = 0; k < e->getNumVertices(); k++)
                nodes.insert(e->getVertex(k));
            }
          }
        }

        int nele = 0;
        if(saveElements) {
          for(std::size_t i = 0; i < entities.size(); i++)
            nele += entities[i]->getNumMeshElements();
        }

        fprintf(fp, "%10d%10d%10d%10d%10d%10d%10d%10d\n", it->first, 0, 0, 0, 0,
                0, 0, (int)nodes.size() + nele);
        fprintf(fp, "%s\n", physicalName(this, dim, it->first).c_str());

        int row = 0;
        if(saveNodes) {
          for(auto it2 = nodes.begin(); it2 != nodes.end(); it2++) {
            if(row == 2) {
              fprintf(fp, "\n");
              row = 0;
            }
            fprintf(fp, "%10d%10ld%10d%10d", 7, (*it2)->getIndex(), 0, 0);
            row++;
          }
        }

        // this output will be consumed by legacy codes that rely on full lines,
        // each having two entities even if the first is a node and the second
        // is an element
        if(row == 2) {
          fprintf(fp, "\n");
          row = 0;
        }

        if(saveElements) {
          for(std::size_t i = 0; i < entities.size(); i++) {
            for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
              MElement *e = entities[i]->getMeshElement(j);
              if(row == 2) {
                fprintf(fp, "\n");
                row = 0;
              }
              fprintf(fp, "%10d%10lu%10d%10d", 8, e->getNum(), 0, 0);
              row++;
            }
          }
          fprintf(fp, "\n");
        }
        else {
          // print a final newline only if the count is odd
          if(row == 1) { fprintf(fp, "\n"); }
        }
      }
    }
    fprintf(fp, "%6d\n", -1);
  }

  fclose(fp);
  return 1;
}
