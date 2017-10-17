// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <time.h>
#include <algorithm>
#include <limits>
#if __cplusplus >= 201103L
#include <unordered_map>
#else
#include <map>
#endif
#include "GModel.h"
#include "OS.h"
#include "MTriangle.h"
#include "MTetrahedron.h"

namespace
{
  static const unsigned GAMBIT_TYPE_EDGE = 1;
  static const unsigned GAMBIT_TYPE_QUAD = 2;
  static const unsigned GAMBIT_TYPE_TRI  = 3;
  static const unsigned GAMBIT_TYPE_TET  = 6;

  // This struct allows us to take advantage of C++11 unordered_map while
  // maintaining backwards compatibility with C++03
  template<typename Key, typename Value>
  struct hashMap {
    #if __cplusplus >= 201103L
    typedef std::unordered_map<Key, Value> _;
    #else
    typedef std::map<Key, Value> _;
    #endif
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
  static const hashMap<std::string, unsigned>::_ boundaryCodeMap
  (rawData, rawData + (sizeof rawData / sizeof rawData[0]));

  // Gambit numbers its faces slightly differently
  static const unsigned GAMBIT_FACE_MAP[4] = {1,2,4,3};

  unsigned const gambitBoundaryCode(std::string name)
  {
    std::transform(name.begin(), name.end(),name.begin(), ::toupper);
    hashMap<std::string, unsigned>::_::const_iterator code = boundaryCodeMap.find(name);
    return code == boundaryCodeMap.end() ? 0 : code->second;
  }

  typedef std::pair<unsigned, unsigned> TetFacePair;
  typedef hashMap<unsigned, std::vector<TetFacePair> >::_ IDTetFaceMap;

  bool const sortBCs(TetFacePair const& lhs, TetFacePair const& rhs)
  {
    return lhs.first < rhs.first;
  }

  IDTetFaceMap const gatherBC(GModel* gm)
  {
    // create association map for vertices and faces
    hashMap<unsigned, std::vector<unsigned> >::_ vertmap;
    for (GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
      for (unsigned i = 0; i < (*it)->triangles.size(); ++i) {
        MTriangle* tri = (*it)->triangles[i];
        for (int j = 0; j < tri->getNumVertices(); ++j) {
          vertmap[tri->getVertex(j)->getNum()].push_back(tri->getNum());
        }
      }
    }

    // determine which faces belong to which tetrahedra by comparing vertices
    IDTetFaceMap tetfacemap;
    for (GModel::riter it = gm->firstRegion(); it != gm->lastRegion(); ++it) {
      for (unsigned i = 0; i < (*it)->tetrahedra.size(); ++i) {
        MTetrahedron* tet = (*it)->tetrahedra[i];
        for (int faceNum = 0; faceNum < tet->getNumFaces(); ++faceNum) {
          std::vector<MVertex*> verts;
          tet->getFaceVertices(faceNum, verts);

          std::vector<unsigned> current = vertmap[verts[0]->getNum()];
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
    for (GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
      if ((*it)->physicals.size()) {
        for (unsigned i = 0; i < (*it)->physicals.size(); ++i) {
          unsigned phys = (*it)->physicals[i];
          for (unsigned j = 0; j < (*it)->triangles.size(); ++j) {
            MTriangle* tri = (*it)->triangles[j];
            IDTetFaceMap::iterator tets = tetfacemap.find(tri->getNum());
            if (tets != tetfacemap.end()) {
              for (unsigned tet = 0; tet < tets->second.size(); ++tet) {
                boundaryConditions[phys].push_back(tets->second[tet]);
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
  FILE* fp = Fopen(name.c_str(), "w");
  if (!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // gather tetrahedra and id normalization information
  unsigned numTetrahedra = 0;
  int lowestId = std::numeric_limits<int>::max();
  hashMap<unsigned, std::vector<unsigned> >::_ elementGroups;
  for (riter it = firstRegion(); it != lastRegion(); ++it) {
    if (saveAll || (*it)->physicals.size()) {
      numTetrahedra += (*it)->tetrahedra.size();

      for (unsigned phys = 0; phys < (*it)->physicals.size(); ++phys) {
        for (unsigned i = 0; i < (*it)->tetrahedra.size(); ++i) {
          MTetrahedron* tet = (*it)->tetrahedra[i];
          elementGroups[(*it)->physicals[phys]].push_back(tet->getNum());

          if (tet->getNum() < lowestId) lowestId = tet->getNum()-1;
        }
      }
    }
  }

  IDTetFaceMap boundaryConditions = gatherBC(this);

  // Metadata
  fprintf(fp, "        CONTROL INFO 2.0.0\n");
  fprintf(fp, "** GAMBIT NEUTRAL FILE\n");
  fprintf(fp, "Gmsh mesh in GAMBIT neutral file format\n");
  fprintf(fp, "PROGRAM:                Gambit     VERSION:  2.0.0\n");

  time_t rawtime;
  time(&rawtime);
  fprintf(fp, "%s", ctime(&rawtime));

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
    unsigned numPhys = (*it)->physicals.size();
    if (saveAll || numPhys) {
      for (unsigned i = 0; i < (*it)->tetrahedra.size(); ++i) {
        (*it)->tetrahedra[i]->writeNEU(fp, GAMBIT_TYPE_TET, lowestId,
                                        numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }
  fprintf(fp, "ENDOFSECTION\n");

  // Element Groups

  for (hashMap<unsigned, std::vector<unsigned> >::_::const_iterator
        it = elementGroups.begin(); it != elementGroups.end(); ++it) {
    fprintf(fp, "       ELEMENT GROUP 2.0.0\n");
    fprintf(fp, "GROUP: %10d ELEMENTS: %10lu MATERIAL: 0 NFLAGS: %10d\n",
            it->first, it->second.size(), 1);
    fprintf(fp, "Material group %d\n", it->first);
    fprintf(fp, "       0");

    for (unsigned i = 0; i < it->second.size(); ++i) {
      if (i % 10 == 0) {
        fprintf(fp, "\n");
      }
      fprintf(fp, "%8d", it->second[i] - lowestId);
    }
    fprintf(fp, "\n");
    fprintf(fp, "ENDOFSECTION\n");
  }

  // Boundary Conditions
  for (IDTetFaceMap::iterator it = boundaryConditions.begin();
        it != boundaryConditions.end(); ++it) {
    fprintf(fp, "       BOUNDARY CONDITIONS 2.0.0\n");

    std::string const regionName = getPhysicalName(2, it->first);
    fprintf(fp, "%32s%8d%8lu%8d%8d\n", regionName.c_str(), 1, it->second.size(), 0,
            gambitBoundaryCode(regionName));
    std::sort(it->second.begin(), it->second.end(), sortBCs);
    for (std::vector<TetFacePair>::iterator tfp = it->second.begin();
         tfp != it->second.end(); ++tfp) {
      fprintf(fp, "%10d %5d %5d\n", tfp->first-lowestId, GAMBIT_TYPE_TET, tfp->second);
    }

    fprintf(fp, "ENDOFSECTION\n");
  }

  fclose(fp);
  return 1;
}
