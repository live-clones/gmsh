// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Larry Price and Michael Ermakov

#include <time.h>
#include <algorithm>
#include <iterator>
#include <limits>
#include <unordered_map>
#include "GModel.h"
#include "OS.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"

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
  static const unsigned GAMBIT_FACE_PYR_MAP[5] = {5, 2, 4, 3, 1};
  static const unsigned GAMBIT_FACE_PRI_MAP[5] = {4, 5, 1, 3, 2};
  static const unsigned GAMBIT_FACE_HEX_MAP[6] = {5, 1, 4, 2, 3, 6};

  unsigned const gambitBoundaryCode(std::string name)
  {
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    auto code = boundaryCodeMap.find(name);
    return code == boundaryCodeMap.end() ? 0 : code->second;
  }

  typedef std::pair<unsigned, unsigned> FacePair;
  typedef hashMap<unsigned, std::vector<FacePair> >::_ IDFaceMap;

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
  hashMap<unsigned, std::vector<unsigned> >::_ elementGroups;

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
    return 1;
  }

  unsigned numElements = numTetrahedra + numHexahedra + numPrisms + numPyramids;

  unsigned nVertex = indexMeshVertices(saveAll, 0, false);
  std::vector<unsigned char> vertex_phys(nVertex);
  // create association map for vertices and faces
  hashMap<unsigned, std::vector<unsigned> >::_ vertmap;
  for(auto it = firstFace(); it != lastFace(); ++it) {
    for(auto &tri : (*it)->triangles) {
      for(std::size_t j = 0; j < tri->getNumVertices(); ++j) {
        unsigned numVertex = tri->getVertex(j)->getNum();
        vertmap[numVertex].push_back(tri->getNum());
        vertex_phys[numVertex] = 1;
      }
    }

    for(auto &quad : (*it)->quadrangles) {
      for(std::size_t j = 0; j < quad->getNumVertices(); ++j) {
        unsigned numVertex = quad->getVertex(j)->getNum();
        vertmap[numVertex].push_back(quad->getNum());
        vertex_phys[numVertex] = 1;
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

          if(vertex_phys[vertex]) { sum++; }
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
            default: break;
            }
            facemap[current[0]].push_back(FacePair(num, face));
          }
        }
      }
    }
  }

  //  return 1;

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
  fprintf(fp, "PROGRAM:                Gambit     VERSION:  2.0.0\n");

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
          default: break;
          }

          fprintf(fp, "%10d %5d %5d\n", tfp->first - lowestId, gambit_type,
                  tfp->second);
        }
      }
    }

    fprintf(fp, "ENDOFSECTION\n");
  }

  fclose(fp);
  return 1;
}
