// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <algorithm>
#include <limits>
#include <unordered_map>
#include "GModel.h"
#include "OS.h"
#include "MTriangle.h"
#include "MTetrahedron.h"

namespace
{
  static const auto GAMBIT_TYPE_EDGE = 1;
  static const auto GAMBIT_TYPE_QUAD = 2;
  static const auto GAMBIT_TYPE_TRI  = 3;
  static const auto GAMBIT_TYPE_TET  = 6;

  static const std::unordered_map<std::string, unsigned> BOUNDARY_CODES {
    {"UNSPECIFIED", 0},
    {"AXIS", 1},
    {"CONJUGATE", 2},
    {"CONVECTION", 3},
    {"CYCLIC", 4},
    {"DEAD", 5},
    {"ELEMENT_SID", 6},
    {"ESPECIES", 7},
    {"EXHAUST_FAN", 8},
    {"FAN", 9},
    {"FREE_SURFACE", 10},
    {"GAP", 11},
    {"INFLOW", 12},
    {"INLET", 13},
    {"INLET_VENT", 14},
    {"INTAKE_FAN", 15},
    {"INTERFACE", 16},
    {"INTERIOR", 17},
    {"INTERNAL", 18},
    {"LIVE", 19},
    {"MASS_FLOW_INLET", 20},
    {"MELT", 21},
    {"MELT_INTERFACE", 22},
    {"MOVING_BOUNDARY", 23},
    {"NODE", 24},
    {"OUTFLOW", 25},
    {"OUTLET", 26},
    {"OUTLET_VENT", 27},
    {"PERIODIC", 28},
    {"PLOT", 29},
    {"POROUS", 30},
    {"POROUS_JUMP", 31},
    {"PRESSURE", 32},
    {"PRESSURE_FAR_FIELD", 33},
    {"PRESSURE_INFLOW", 34},
    {"PRESSURE_INLET", 35},
    {"PRESSURE_OUTFLOW", 36},
    {"PRESSURE_OUTLET", 37},
    {"RADIATION", 38},
    {"RADIATOR", 39},
    {"RECIRCULATION_INLET", 40},
    {"RECIRCULATION_OUTLET", 41},
    {"SLIP", 42},
    {"SREACTION", 43},
    {"SURFACE", 44},
    {"SYMMETRY", 45},
    {"TRACTION", 46},
    {"TRAJECTORY", 47},
    {"VELOCITY", 48},
    {"VELOCITY_INLET", 49},
    {"VENT", 50},
    {"WALL", 51},
    {"SPRING", 52},
  };

  // Gambit numbers its faces slightly differently
  static const unsigned GAMBIT_FACE_MAP[4] = {1,2,4,3};

  unsigned const gambitBoundaryCode(std::string name)
  {
    std::transform(name.begin(), name.end(),name.begin(), ::toupper);
    auto code = BOUNDARY_CODES.find(name);
    return code == BOUNDARY_CODES.end() ? 0 : code->second;
  }

  typedef std::pair<unsigned, unsigned> TetFacePair;
  typedef std::unordered_map<unsigned, std::vector<TetFacePair> > IDTetFaceMap;

  bool const sortBCs(TetFacePair const& lhs, TetFacePair const& rhs)
  {
    return lhs.first < rhs.first;
  }

  IDTetFaceMap const gatherBC(GModel* gm)
  {
    // create association map for vertices and faces
    std::unordered_map<unsigned, std::vector<unsigned> > vertmap;
    for (auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
      for (auto const& tri: (*it)->triangles) {
        for (auto i = 0; i < tri->getNumVertices(); ++i) {
          vertmap[tri->getVertex(i)->getNum()].push_back(tri->getNum());
        }
      }
    }

    // determine which faces belong to which tetrahedra by comparing vertices
    IDTetFaceMap tetfacemap;
    for (auto it = gm->firstRegion(); it != gm->lastRegion(); ++it) {
      for (auto const& tet: (*it)->tetrahedra) {
        for (auto faceNum = 0; faceNum < tet->getNumFaces(); ++faceNum) {
          std::vector<MVertex*> verts;
          tet->getFaceVertices(faceNum, verts);

          auto current = vertmap[verts[0]->getNum()];
          for (unsigned j = 1; j < verts.size() && current.size() != 0; ++j) {
            std::vector<unsigned> common_data;
            set_intersection(current.begin(), current.end(),
                             vertmap[verts[j]->getNum()].begin(),
                             vertmap[verts[j]->getNum()].end(),
                             std::back_inserter(common_data));
            current = common_data;
          }
          if (current.size() == 1) {
            tetfacemap[current[0]].push_back(
                TetFacePair(tet->getNum(), GAMBIT_FACE_MAP[faceNum]));
          }
        }
      }
    }

    // populate boundary conditions for tetrahedra given triangle physicals
    IDTetFaceMap boundaryConditions;
    for (auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
      if ((*it)->physicals.size()) {
        for (auto const& phys: (*it)->physicals) {
          for (auto const& tri: (*it)->triangles) {
            auto tets = tetfacemap.find(tri->getNum());
            if (tets != tetfacemap.end()) {
              for (auto const& tet: tets->second) {
                boundaryConditions[phys].push_back(tet);
              }
            }
          }
        }
      }
    }

    return boundaryConditions;
  }
}

// for a specification of the GAMBIT neutral format:
//   http://web.stanford.edu/class/me469b/handouts/gambit_write.pdf
int GModel::writeNEU(const std::string &name, bool saveAll,
                     double scalingFactor)
{
  auto fp = Fopen(name.c_str(), "w");
  if (!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // gather tetrahedra and id normalization information
  auto numTetrahedra = 0;
  auto lowestId = std::numeric_limits<int>::max();
  std::unordered_map<unsigned, std::vector<unsigned> > elementGroups;
  for (riter it = firstRegion(); it != lastRegion(); ++it) {
    if (saveAll || (*it)->physicals.size()) {
      numTetrahedra += (*it)->tetrahedra.size();

      for (auto const& phys: (*it)->physicals) {
        for (auto const& tet: (*it)->tetrahedra) {
          elementGroups[phys].push_back(tet->getNum());

          if (tet->getNum() < lowestId) lowestId = tet->getNum()-1;
        }
      }
    }
  }

  auto boundaryConditions = gatherBC(this);

  // Metadata
  fprintf(fp, "        CONTROL INFO 2.0.0\n");
  fprintf(fp, "** GAMBIT NEUTRAL FILE\n");
  fprintf(fp, "Gmsh mesh in GAMBIT neutral file format\n");
  fprintf(fp, "PROGRAM:                Gambit     VERSION:  2.0.0\n");

  char datestring[256];
  time_t rawtime;
  struct tm* timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(datestring, sizeof(datestring), "%c", timeinfo);
  fprintf(fp, "%s\n", datestring);

  fprintf(fp, "     NUMNP     NELEM     NGRPS    NBSETS     NDFCD     NDFVL\n");
  fprintf(fp, " %9d %9d %9lu %9lu %9d %9d\n", indexMeshVertices(saveAll), numTetrahedra,
          elementGroups.size(), boundaryConditions.size(), getDim(),
          getDim());
  fprintf(fp, "ENDOFSECTION\n");

  // Nodes
  fprintf(fp, "   NODAL COORDINATES 2.0.0\n");
  std::vector<GEntity*> entities;
  getEntities(entities);
  for (unsigned i = 0; i < entities.size(); ++i) {
    for (unsigned j = 0; j < entities[i]->mesh_vertices.size(); ++j) {
      entities[i]->mesh_vertices[j]->writeNEU(fp, getDim(), scalingFactor);
    }
  }
  fprintf(fp, "ENDOFSECTION\n");

  // Elements
  fprintf(fp, "      ELEMENTS/CELLS 2.0.0\n");
  for (riter it = firstRegion(); it != lastRegion(); ++it) {
    auto numPhys = (*it)->physicals.size();
    if (saveAll || numPhys) {
      for (unsigned i = 0; i < (*it)->tetrahedra.size(); ++i) {
        (*it)->tetrahedra[i]->writeNEU(fp, GAMBIT_TYPE_TET, lowestId,
                                        numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }
  fprintf(fp, "ENDOFSECTION\n");

  // Element Groups
  for (auto const& kv: elementGroups) {
    fprintf(fp, "       ELEMENT GROUP 2.0.0\n");
    fprintf(fp, "GROUP: %10d ELEMENTS: %10lu MATERIAL: 0 NFLAGS: %10d\n", kv.first, kv.second.size(), 1);
    fprintf(fp, "Material group %d\n", kv.first);
    fprintf(fp, "       0");

    unsigned i = 0;
    for (auto const& elem: kv.second) {
      if (i++ % 10 == 0) {
        fprintf(fp, "\n");
      }
      fprintf(fp, "%8d", elem-lowestId);
    }
    fprintf(fp, "\n");
    fprintf(fp, "ENDOFSECTION\n");
  }

  // Boundary Conditions
  for (auto &kv: boundaryConditions) {
    fprintf(fp, "       BOUNDARY CONDITIONS 2.0.0\n");

    auto regionName = getPhysicalName(2, kv.first);
    fprintf(fp, "%32s%8d%8lu%8d%8d\n", regionName.c_str(), 1, kv.second.size(), 0, gambitBoundaryCode(regionName));
    std::sort(kv.second.begin(), kv.second.end(), sortBCs);
    for (auto const& boundary: kv.second) {
      fprintf(fp, "%10d %5d %5d\n", boundary.first-lowestId, GAMBIT_TYPE_TET, boundary.second);
    }

    fprintf(fp, "ENDOFSECTION\n");
  }

  fclose(fp);
  return 1;
}
