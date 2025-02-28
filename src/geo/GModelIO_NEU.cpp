// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Larry Price and Michael Ermakov

#include <time.h>
#include <algorithm>
#include <iterator>
#include <limits>
#include <unordered_map>
#include <cstring>
#include "GModel.h"
#include "OS.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "GmshVersion.h"

namespace {
  // static const unsigned GAMBIT_TYPE_EDGE = 1;
  // static const unsigned GAMBIT_TYPE_QUAD = 2;
  // static const unsigned GAMBIT_TYPE_TRI  = 3;
  static const unsigned GAMBIT_TYPE_HEX = 4;
  static const unsigned GAMBIT_TYPE_PRI = 5;
  static const unsigned GAMBIT_TYPE_TET = 6;
  static const unsigned GAMBIT_TYPE_PYR = 7;

  // This struct allows us to take advantage of C++11 unordered_map while
  // maintaining backwards compatibility with C++03
  template <typename Key, typename Value> struct hashMap {
    typedef std::unordered_map<Key, Value> _;
  };

  const hashMap<std::string, unsigned>::_::value_type rawData[] = {
    hashMap<std::string, unsigned>::_::value_type("UNSPECIFIED", 0),
    hashMap<std::string, unsigned>::_::value_type("AXIS", 1),
    hashMap<std::string, unsigned>::_::value_type("CONJUGATE", 2),
    hashMap<std::string, unsigned>::_::value_type("CONVECTION", 3),
    hashMap<std::string, unsigned>::_::value_type("CYCLIC", 4),
    hashMap<std::string, unsigned>::_::value_type("DEAD", 5),
    hashMap<std::string, unsigned>::_::value_type("ELEMENT_SID", 6),
    hashMap<std::string, unsigned>::_::value_type("ESPECIES", 7),
    hashMap<std::string, unsigned>::_::value_type("EXHAUST_FAN", 8),
    hashMap<std::string, unsigned>::_::value_type("FAN", 9),
    hashMap<std::string, unsigned>::_::value_type("FREE_SURFACE", 10),
    hashMap<std::string, unsigned>::_::value_type("GAP", 11),
    hashMap<std::string, unsigned>::_::value_type("INFLOW", 12),
    hashMap<std::string, unsigned>::_::value_type("INLET", 13),
    hashMap<std::string, unsigned>::_::value_type("INLET_VENT", 14),
    hashMap<std::string, unsigned>::_::value_type("INTAKE_FAN", 15),
    hashMap<std::string, unsigned>::_::value_type("INTERFACE", 16),
    hashMap<std::string, unsigned>::_::value_type("INTERIOR", 17),
    hashMap<std::string, unsigned>::_::value_type("INTERNAL", 18),
    hashMap<std::string, unsigned>::_::value_type("LIVE", 19),
    hashMap<std::string, unsigned>::_::value_type("MASS_FLOW_INLET", 20),
    hashMap<std::string, unsigned>::_::value_type("MELT", 21),
    hashMap<std::string, unsigned>::_::value_type("MELT_INTERFACE", 22),
    hashMap<std::string, unsigned>::_::value_type("MOVING_BOUNDARY", 23),
    hashMap<std::string, unsigned>::_::value_type("NODE", 24),
    hashMap<std::string, unsigned>::_::value_type("OUTFLOW", 25),
    hashMap<std::string, unsigned>::_::value_type("OUTLET", 26),
    hashMap<std::string, unsigned>::_::value_type("OUTLET_VENT", 27),
    hashMap<std::string, unsigned>::_::value_type("PERIODIC", 28),
    hashMap<std::string, unsigned>::_::value_type("PLOT", 29),
    hashMap<std::string, unsigned>::_::value_type("POROUS", 30),
    hashMap<std::string, unsigned>::_::value_type("POROUS_JUMP", 31),
    hashMap<std::string, unsigned>::_::value_type("PRESSURE", 32),
    hashMap<std::string, unsigned>::_::value_type("PRESSURE_FAR_FIELD", 33),
    hashMap<std::string, unsigned>::_::value_type("PRESSURE_INFLOW", 34),
    hashMap<std::string, unsigned>::_::value_type("PRESSURE_INLET", 35),
    hashMap<std::string, unsigned>::_::value_type("PRESSURE_OUTFLOW", 36),
    hashMap<std::string, unsigned>::_::value_type("PRESSURE_OUTLET", 37),
    hashMap<std::string, unsigned>::_::value_type("RADIATION", 38),
    hashMap<std::string, unsigned>::_::value_type("RADIATOR", 39),
    hashMap<std::string, unsigned>::_::value_type("RECIRCULATION_INLET", 40),
    hashMap<std::string, unsigned>::_::value_type("RECIRCULATION_OUTLET", 41),
    hashMap<std::string, unsigned>::_::value_type("SLIP", 42),
    hashMap<std::string, unsigned>::_::value_type("SREACTION", 43),
    hashMap<std::string, unsigned>::_::value_type("SURFACE", 44),
    hashMap<std::string, unsigned>::_::value_type("SYMMETRY", 45),
    hashMap<std::string, unsigned>::_::value_type("TRACTION", 46),
    hashMap<std::string, unsigned>::_::value_type("TRAJECTORY", 47),
    hashMap<std::string, unsigned>::_::value_type("VELOCITY", 48),
    hashMap<std::string, unsigned>::_::value_type("VELOCITY_INLET", 49),
    hashMap<std::string, unsigned>::_::value_type("VENT", 50),
    hashMap<std::string, unsigned>::_::value_type("WALL", 51),
    hashMap<std::string, unsigned>::_::value_type("SPRING", 52),
  };
  static const hashMap<std::string, unsigned>::_
    boundaryCodeMap(rawData, rawData + (sizeof rawData / sizeof rawData[0]));

  // Gambit numbers its faces slightly differently
  static const unsigned GAMBIT_FACE_TET_MAP[4] = {1, 2, 4, 3};
  static const unsigned GAMBIT_FACE_PYR_MAP[5] = {2, 5, 3, 4, 1};
  static const unsigned GAMBIT_FACE_PRI_MAP[5] = {4, 5, 1, 3, 2};
  static const unsigned GAMBIT_FACE_HEX_MAP[6] = {5, 1, 4, 2, 3, 6};

  unsigned const gambitBoundaryCode(std::string name)
  {
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    auto code = boundaryCodeMap.find(name);
    return code == boundaryCodeMap.end() ? 0 : code->second;
  }

  typedef std::pair<unsigned, unsigned> FacePair;
  typedef hashMap<unsigned, std::vector<FacePair>>::_ IDFaceMap;

  bool const sortBCs(FacePair const &lhs, FacePair const &rhs)
  {
    return lhs.first < rhs.first;
  }

} // namespace

// for a specification of the GAMBIT neutral format:
//   http://web.stanford.edu/class/me469b/handouts/gambit_write.pdf
int GModel::writeNEU(const std::string &name, bool saveAll,
                     double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // gather tetrahedra and id normalization information
  unsigned numTetrahedra = 0;
  unsigned numHexahedra = 0;
  unsigned numPrisms = 0;
  unsigned numPyramids = 0;

  unsigned lowestId = std::numeric_limits<int>::max();
  hashMap<unsigned, std::vector<unsigned>>::_ elementGroups;

  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    if(saveAll || (*it)->physicals.size()) {
      numTetrahedra += (*it)->tetrahedra.size();
      numHexahedra += (*it)->hexahedra.size();
      numPrisms += (*it)->prisms.size();
      numPyramids += (*it)->pyramids.size();

      for(std::size_t phys = 0; phys < (*it)->physicals.size(); ++phys) {
        for(std::size_t i = 0; i < (*it)->getNumMeshElements(); ++i) {
          MElement *elem = (*it)->getMeshElement(i);
          unsigned n = (unsigned)elem->getNum();
          elementGroups[(*it)->physicals[phys]].push_back(n);
          if(n < lowestId) lowestId = n - 1;
        }
      }
    }
  }

  if(lowestId == std::numeric_limits<int>::max()) {
    Msg::Warning("No 3d-physicals");
    fclose(fp);
    return 1;
  }

  unsigned numElements = numTetrahedra + numHexahedra + numPrisms + numPyramids;
  // known problem : all the volumes have to be set as Physical Volumes
  // otherwise set saveAll = true (20.10.2023)
  indexMeshVertices(saveAll, 0, false);
  // create association map for vertices and faces
  hashMap<unsigned, std::vector<unsigned>>::_ vertmap;
  for(auto it = firstFace(); it != lastFace(); ++it) {
    for(auto &tri : (*it)->triangles) {
      for(std::size_t j = 0; j < tri->getNumVertices(); ++j) {
        unsigned numVertex = tri->getVertex(j)->getNum();
        vertmap[numVertex].push_back(tri->getNum());
      }
    }

    for(auto &quad : (*it)->quadrangles) {
      for(std::size_t j = 0; j < quad->getNumVertices(); ++j) {
        unsigned numVertex = quad->getVertex(j)->getNum();
        vertmap[numVertex].push_back(quad->getNum());
      }
    }
  }

  // because we use a set_intersection later on, the vectors of vertmap should
  // be sorted
  for(auto &it : vertmap) { std::sort(it.second.begin(), it.second.end()); }

  std::vector<unsigned char> elem_phys(numElements);
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    if(saveAll || (*it)->physicals.size()) {
      for(std::size_t i = 0; i < (*it)->getNumMeshElements(); ++i) {
        unsigned num = (*it)->getMeshElement(i)->getNum();
        unsigned sum = 0;
        for(unsigned j = 0; j < (*it)->getMeshElement(i)->getNumVertices();
            ++j) {
          unsigned vertex = (*it)->getMeshElement(i)->getVertex(j)->getNum();
          if(vertmap[vertex].size()) { sum++; }
        }
        if(sum >= 3) { elem_phys[num - lowestId - 1] = 1; }
      }
    }
  }

  // determine which faces belong to which element by comparing vertices
  IDFaceMap facemap;
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); ++i) {
      MElement *element = (*it)->getMeshElement(i);
      unsigned num = element->getNum();
      if(elem_phys[num - lowestId - 1]) {
        unsigned numFaces = element->getNumFaces();

        for(unsigned faceNum = 0; faceNum < numFaces; ++faceNum) {
          std::vector<MVertex *> verts;
          element->getFaceVertices(faceNum, verts);

          std::vector<unsigned> current = vertmap[verts[0]->getNum()];
          for(std::size_t j = 1; j < verts.size() && current.size() != 0; ++j) {
            std::vector<unsigned> common_data;
            set_intersection(current.begin(), current.end(),
                             vertmap[verts[j]->getNum()].begin(),
                             vertmap[verts[j]->getNum()].end(),
                             std::back_inserter(common_data));
            current = common_data;
          }

          if(current.size() == 1) {
            unsigned type = element->getType();
            unsigned face = 0;
            switch(type) {
            case TYPE_TET: face = GAMBIT_FACE_TET_MAP[faceNum]; break;
            case TYPE_HEX: face = GAMBIT_FACE_HEX_MAP[faceNum]; break;
            case TYPE_PRI: face = GAMBIT_FACE_PRI_MAP[faceNum]; break;
            case TYPE_PYR: face = GAMBIT_FACE_PYR_MAP[faceNum]; break;
            default: Msg::Warning("type = %d", type); break;
            }
            facemap[current[0]].push_back(FacePair(num, face));
          }
        }
      }
    }
  }
  // populate boundary conditions for tetrahedra given triangle physicals
  IDFaceMap boundaryConditions;
  for(auto it = firstFace(); it != lastFace(); ++it) {
    if((*it)->physicals.size()) {
      for(std::size_t i = 0; i < (*it)->physicals.size(); ++i) {
        unsigned phys = (*it)->physicals[i];

        for(std::size_t j = 0; j < (*it)->triangles.size(); ++j) {
          MTriangle *tri = (*it)->triangles[j];
          auto tets = facemap.find(tri->getNum());
          if(tets != facemap.end()) {
            for(std::size_t tet = 0; tet < tets->second.size(); ++tet) {
              boundaryConditions[phys].push_back(tets->second[tet]);
            }
          }
        }

        for(std::size_t j = 0; j < (*it)->quadrangles.size(); ++j) {
          MQuadrangle *quad = (*it)->quadrangles[j];
          auto tets = facemap.find(quad->getNum());
          if(tets != facemap.end()) {
            for(std::size_t tet = 0; tet < tets->second.size(); ++tet) {
              boundaryConditions[phys].push_back(tets->second[tet]);
            }
          }
        }
      }
    }
  }

  // Metadata
  fprintf(fp, "        CONTROL INFO 2.0.0\n");
  fprintf(fp, "** GAMBIT NEUTRAL FILE\n");
  fprintf(fp, "Gmsh mesh in GAMBIT neutral file format\n");
  fprintf(fp, "PROGRAM:                  Gmsh     VERSION:  %s\n",
          GMSH_VERSION);

  time_t rawtime;
  time(&rawtime);
  fprintf(fp, "%s", ctime(&rawtime));
  fprintf(fp, "     NUMNP     NELEM     NGRPS    NBSETS     NDFCD     NDFVL\n");
  fprintf(fp, " %9ld %9d %9lu %9lu %9d %9d\n",
          indexMeshVertices(saveAll, 0, false), numElements,
          elementGroups.size(), boundaryConditions.size(), getDim(), getDim());
  fprintf(fp, "ENDOFSECTION\n");

  // Nodes
  fprintf(fp, "   NODAL COORDINATES 2.0.0\n");
  std::vector<GEntity *> entities;
  getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); ++i) {
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); ++j) {
      entities[i]->mesh_vertices[j]->writeNEU(fp, getDim(), scalingFactor);
    }
  }
  fprintf(fp, "ENDOFSECTION\n");

  // Elements
  fprintf(fp, "      ELEMENTS/CELLS 2.0.0\n");
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    std::size_t numPhys = (*it)->physicals.size();
    if(saveAll || numPhys) {
      for(auto cell : (*it)->tetrahedra) {
        cell->writeNEU(fp, GAMBIT_TYPE_TET, lowestId,
                       numPhys ? (*it)->physicals[0] : 0);
      }
      for(auto cell : (*it)->hexahedra) {
        cell->writeNEU(fp, GAMBIT_TYPE_HEX, lowestId,
                       numPhys ? (*it)->physicals[0] : 0);
      }
      for(auto cell : (*it)->prisms) {
        cell->writeNEU(fp, GAMBIT_TYPE_PRI, lowestId,
                       numPhys ? (*it)->physicals[0] : 0);
      }
      for(auto cell : (*it)->pyramids) {
        cell->writeNEU(fp, GAMBIT_TYPE_PYR, lowestId,
                       numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }
  fprintf(fp, "ENDOFSECTION\n");

  // Element Groups
  for(auto it = elementGroups.begin(); it != elementGroups.end(); ++it) {
    fprintf(fp, "       ELEMENT GROUP 2.0.0\n");
    fprintf(fp,
            "GROUP: %10d ELEMENTS: %10lu MATERIAL:          0 NFLAGS: %10d\n",
            it->first, it->second.size(), 1);
    std::string volumeName = getPhysicalName(3, it->first);
    if(volumeName.empty()) {
      char tmp[256];
      sprintf(tmp, "Material group %d", it->first);
      volumeName = tmp;
    }
    fprintf(fp, "%32s\n", volumeName.c_str());
    fprintf(fp, "       0");
    for(unsigned i = 0; i < it->second.size(); ++i) {
      if(i % 10 == 0) { fprintf(fp, "\n"); }
      fprintf(fp, "%8d", it->second[i] - lowestId);
    }
    fprintf(fp, "\n");
    fprintf(fp, "ENDOFSECTION\n");
  }

  // Boundary Conditions
  unsigned nphys = getMaxPhysicalNumber(2);
  for(unsigned iphys = 1; iphys <= nphys; ++iphys) {
    for(auto it = boundaryConditions.begin(); it != boundaryConditions.end();
        ++it) {
      if(it->first == iphys) {
        fprintf(fp, "       BOUNDARY CONDITIONS 2.0.0\n");
        std::string regionName = getPhysicalName(2, it->first);
        if(regionName.empty()) {
          char tmp[256];
          sprintf(tmp, "PhysicalSurface%d", it->first);
          regionName = tmp;
        }

        fprintf(fp, "%32s%8d%8lu%8d%8d\n", regionName.c_str(), 1,
                it->second.size(), 0, gambitBoundaryCode(regionName));
        std::sort(it->second.begin(), it->second.end(), sortBCs);
        for(auto tfp = it->second.begin(); tfp != it->second.end(); ++tfp) {
          MElement *element = getMeshElementByTag(tfp->first);
          unsigned type = element->getType();
          unsigned gambit_type = 0;
          switch(type) {
          case TYPE_TET: gambit_type = GAMBIT_TYPE_TET; break;
          case TYPE_PYR: gambit_type = GAMBIT_TYPE_PYR; break;
          case TYPE_PRI: gambit_type = GAMBIT_TYPE_PRI; break;
          case TYPE_HEX: gambit_type = GAMBIT_TYPE_HEX; break;
          default: Msg::Warning("type = %d", type); break;
          }
          fprintf(fp, "%10d%5d%5d\n", tfp->first - lowestId, gambit_type,
                  tfp->second);
        }
      }
    }

    fprintf(fp, "ENDOFSECTION\n");
  }

  fclose(fp);
  return 1;
}

int GModel::readNEU(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "r");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "XXX";
  int ic = 0;
  while(strstr(str, "NUMNP") == nullptr) {
    if(ic++ > 5) {
      fclose(fp);
      return 0;
    }
    if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
  }

  if(!fgets(str, sizeof(str), fp) || feof(fp)) {
    fclose(fp);
    return 0;
  }
  int numVertices, numElements, ng, nb;
  if(sscanf(str, "%d %d %d %d", &numVertices, &numElements, &ng, &nb) != 4) {
    fclose(fp);
    return 0;
  }

  if(!fgets(str, sizeof(str), fp) || feof(fp)) {
    fclose(fp);
    return 0;
  }
  if(strstr(str, "ENDOFSECTION") == nullptr) {
    fclose(fp);
    return 0;
  }

  Msg::Info("%d nodes", numVertices);
  Msg::StartProgressMeter(numVertices);

  if(!fgets(str, sizeof(str), fp) || feof(fp)) {
    fclose(fp);
    return 0;
  }
  if(strstr(str, "NODAL COORDINATES") == nullptr) {
    fclose(fp);
    return 0;
  }

  std::vector<MVertex *> vertexVector;
  vertexVector.resize(numVertices);

  for(int i = 0; i < numVertices; i++) {
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    int p;
    double x, y, z;
    if(sscanf(str, "%d %le %le %le", &p, &x, &y, &z) != 4) {
      fclose(fp);
      return 0;
    }

    if(p > 0 && p <= (int)vertexVector.size()) {
      vertexVector[p - 1] = new MVertex(x, y, z);
    }
    else {
      Msg::Error("Node tag %d out of range", p);
      return 0;
    }
    if(numVertices > 100000) Msg::ProgressMeter(i + 1, true, "Reading nodes");
  }

  if(!fgets(str, sizeof(str), fp) || feof(fp)) {
    fclose(fp);
    return 0;
  }
  if(strstr(str, "ENDOFSECTION") == nullptr) {
    fclose(fp);
    return 0;
  }

  Msg::StopProgressMeter();

  Msg::Info("%d elements", numElements);
  Msg::StartProgressMeter(numElements);

  if(!fgets(str, sizeof(str), fp) || feof(fp)) {
    fclose(fp);
    return 0;
  }
  if(strstr(str, "ELEMENTS/CELLS") == nullptr) {
    fclose(fp);
    return 0;
  }

  std::vector<MElement *> elementVector;
  elementVector.reserve(numElements);
  std::vector<int> elementTypeVector;
  elementTypeVector.reserve(numElements);

  for(int num = 1; num <= numElements; num++) {
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }

    int ne, ntype, ndp;
    if(sscanf(str, "%d %d %d", &ne, &ntype, &ndp) != 3) {
      fclose(fp);
      return 0;
    }

    int p[8];
    int len_p = -1;
    std::vector<MVertex *> vertices;
    std::string sstr(str);
    switch(ntype) {
    case GAMBIT_TYPE_HEX:
      len_p = 8;
      for(int i = len_p - 1; i > 1; --i) sstr.insert(23 + (i - 2) * 8, " ");
      if(sscanf(sstr.c_str(), "%*d%*d%*d%d%d%d%d%d%d%d", p, p + 1, p + 3, p + 2,
                p + 4, p + 5, p + 7) != len_p - 1) {
        fclose(fp);
        return 0;
      }
      if(!fgets(str, sizeof(str), fp) || feof(fp)) {
        fclose(fp);
        return 0;
      }
      if(sscanf(str, "%d", p + 6) != 1) {
        fclose(fp);
        return 0;
      }
      for(int ip = 0; ip < len_p; ip++)
        vertices.push_back(vertexVector[p[ip] - 1]);
      elementVector.push_back(new MHexahedron(vertices, num));
      elementTypeVector.push_back(6); // 6
      break;
    case GAMBIT_TYPE_PRI:
      len_p = 6;
      for(int i = len_p; i > 1; --i) sstr.insert(23 + (i - 2) * 8, " ");
      if(sscanf(str, "%*d%*d%*d%d%d%d%d%d%d", p, p + 1, p + 2, p + 3, p + 4,
                p + 5) != len_p) {
        fclose(fp);
        return 0;
      }
      for(int ip = 0; ip < len_p; ip++)
        vertices.push_back(vertexVector[p[ip] - 1]);
      elementVector.push_back(new MPrism(vertices, num));
      elementTypeVector.push_back(TYPE_PRI); // 7
      break;

    case GAMBIT_TYPE_TET:
      len_p = 4;
      for(int i = len_p; i > 1; --i) sstr.insert(23 + (i - 2) * 8, " ");
      if(sscanf(sstr.c_str(), "%*d%*d%*d%d%d%d%d", p, p + 1, p + 2, p + 3) !=
         len_p) {
        fclose(fp);
        return 0;
      }
      for(int ip = 0; ip < len_p; ip++)
        vertices.push_back(vertexVector[p[ip] - 1]);
      elementVector.push_back(new MTetrahedron(vertices, num));
      elementTypeVector.push_back(TYPE_TET); // 5
      break;
    case GAMBIT_TYPE_PYR:
      len_p = 5;
      for(int i = len_p; i > 1; --i) sstr.insert(23 + (i - 2) * 8, " ");
      if(sscanf(str, "%*d%*d%*d%d%d%d%d%d", p, p + 1, p + 3, p + 2, p + 4) !=
         len_p) {
        fclose(fp);
        return 0;
      }
      for(int ip = 0; ip < len_p; ip++)
        vertices.push_back(vertexVector[p[ip] - 1]);
      elementVector.push_back(new MPyramid(vertices, num));
      elementTypeVector.push_back(8); // 8
      break;
    default:
      Msg::Error("Wrong type %d of element %d", ntype, num + 1);
      fclose(fp);
      return 0;
    }

    if(numElements > 100000)
      Msg::ProgressMeter(num + 1, true, "Reading elements");
  }

  if(!fgets(str, sizeof(str), fp) || feof(fp)) {
    fclose(fp);
    return 0;
  }
  if(strstr(str, "ENDOFSECTION") == nullptr) {
    fclose(fp);
    return 0;
  }

  Msg::StopProgressMeter();

  const int num_elements = 9;
  std::map<int, std::vector<MElement *>> elements[num_elements];
  std::map<int, std::map<int, std::string>> physicals[4];
  for(int ig = 0; ig < ng; ig++) {
    int reg = ig + 1;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    if(strstr(str, "ELEMENT GROUP") == nullptr) {
      fclose(fp);
      return 0;
    }
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    int neg, phys;
    if(sscanf(str, "%*s %d %*s %d", &phys, &neg) != 2) {
      fclose(fp);
      return 0;
    }
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    char phys_name[80] = "XXX";
    if(sscanf(str, "%s ", phys_name) != 1) {
      fclose(fp);
      return 0;
    }
    physicals[3][reg][phys] = phys_name;

    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }

    // read group (region) elements
    while(neg > 0) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) {
        fclose(fp);
        return 0;
      }
      int e[10];
      int nelem = std::min(10, neg);

      std::string sstr(str);
      for(int i = nelem; i > 1; --i) sstr.insert(8 * (i - 1), " ");
      if(sscanf(sstr.c_str(), "%d%d%d%d%d%d%d%d%d%d", e, e + 1, e + 2, e + 3,
                e + 4, e + 5, e + 6, e + 7, e + 8, e + 9) != nelem) {
        fclose(fp);
        return 0;
      }
      for(int i = 0; i < nelem; i++) {
        int ei = e[i] - 1;
        elements[elementTypeVector[ei]][reg].push_back(elementVector[ei]);
      }
      neg = neg - 10;
    }

    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    if(strstr(str, "ENDOFSECTION") == nullptr) {
      fclose(fp);
      return 0;
    }
  }

  for(int ib = 0; ib < nb; ib++) {
    int reg = ib + 1;
    int phys = reg;
    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    if(strstr(str, "BOUNDARY CONDITIONS") == nullptr) {
      fclose(fp);
      return 0;
    }

    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    char phys_name[80] = "XXX";
    int neb = -1;
    if(sscanf(str, "%s %*d %d", phys_name, &neb) != 2) {
      fclose(fp);
      return 0;
    }
    physicals[2][reg][phys] = phys_name;

    int num, type, side;
    for(int i = 0; i < neb; i++) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) {
        fclose(fp);
        return 0;
      }
      if(sscanf(str, "%d %d %d", &num, &type, &side) != 3) {
        fclose(fp);
        return 0;
      }

      std::vector<int> sub(4);
      switch(type) {
      case GAMBIT_TYPE_TET:
        switch(side) {
        case 1: sub = {0, 1, 2}; break;
        case 2: sub = {0, 1, 3}; break;
        case 3: sub = {1, 2, 3}; break;
        case 4: sub = {0, 2, 3}; break;
        default: Msg::Warning("  side = %d", side); return 0;
        }
        break;
      case GAMBIT_TYPE_HEX:
        switch(side) {
        case 1: sub = {0, 1, 5, 4}; break;
        case 2: sub = {1, 2, 6, 5}; break;
        case 3: sub = {3, 2, 6, 7}; break;
        case 4: sub = {0, 3, 7, 4}; break;
        case 5: sub = {0, 1, 2, 3}; break;
        case 6: sub = {4, 5, 6, 7}; break;
        default: Msg::Warning("  side = %d", side); return 0;
        }
        break;
      case GAMBIT_TYPE_PRI:
        switch(side) {
        case 1: sub = {0, 1, 4, 3}; break;
        case 2: sub = {1, 2, 5, 4}; break;
        case 3: sub = {0, 2, 5, 3}; break;
        case 4: sub = {0, 1, 2}; break;
        case 5: sub = {3, 4, 5}; break;
        default: Msg::Warning("  side = %d", side); return 0;
        }
        break;
      case GAMBIT_TYPE_PYR:
        switch(side) {
        case 1: sub = {0, 1, 2, 3}; break;
        case 2: sub = {0, 1, 4}; break;
        case 3: sub = {1, 2, 4}; break;
        case 4: sub = {3, 2, 4}; break;
        case 5: sub = {0, 3, 4}; break;
        default: Msg::Warning("  side = %d", side); return 0;
        }
        break;
      default:
        Msg::Error("Wrong type %d of element %d", type, num + 1);
        fclose(fp);
        return 0;
      }

      std::vector<MVertex *> vertices;
      for(std::size_t i = 0; i < sub.size(); i++)
        vertices.push_back(elementVector[num - 1]->getVertex(sub[i]));
      if(sub.size() == 3)
        elements[TYPE_TRI][reg].push_back(new MTriangle(vertices));
      else
        elements[TYPE_QUA][reg].push_back(new MQuadrangle(vertices));
    }

    if(!fgets(str, sizeof(str), fp) || feof(fp)) {
      fclose(fp);
      return 0;
    }
    if(strstr(str, "ENDOFSECTION") == nullptr) {
      fclose(fp);
      return 0;
    }
  }

  // store the elements in their associated elementary entity. If the
  // entity does not exist, create a new (discrete) one.
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);

  // associate the correct geometrical entity with each mesh vertex
  _associateEntityWithMeshVertices();

  // store the vertices in their associated geometrical entity
  _storeVerticesInEntities(vertexVector);

  // store the physical tags
  for(int i = 0; i < 4; i++) _storePhysicalTagsInEntities(i, physicals[i]);

  fclose(fp);

  return 1;
}
