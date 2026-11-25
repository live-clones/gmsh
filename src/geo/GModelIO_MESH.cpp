// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Florian Blachère

#include <stdlib.h>
#include <string.h>
#include "GModel.h"
#include "OS.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "Context.h"

static bool getMeshVertices(int num, int *indices, std::vector<MVertex *> &vec,
                            std::vector<MVertex *> &vertices)
{
  for(int i = 0; i < num; i++) {
    if(indices[i] < 0 || indices[i] > (int)(vec.size() - 1)) {
      Msg::Error("Wrong node index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

// The node of a Gmsh 18-node prism at each position of a Medit PrismsP2 (as
// given by the PrismsP2Ordering of libMeshb): corners, edges of the bottom and
// of the top triangle, vertical edges, then quadrangular faces
static const int meditPrism18[18] = {0,  1,  2,  3,  4,  5,  6,  9,  7,
                                     12, 14, 13, 8,  10, 11, 15, 17, 16};

// write an element in a section of a Medit file: its nodes at the positions
// given by nodes (if not null), or its first numNodes nodes
static void writeMeditElement(FILE *fp, MElement *e, const int *nodes,
                              int numNodes, int elementTagType, int elementary,
                              int physical)
{
  if(physical < 0) e->reverse();
  for(int j = 0; j < numNodes; j++)
    fprintf(fp, " %ld", e->getVertex(nodes ? nodes[j] : j)->getIndex());
  fprintf(fp, " %d\n",
          (elementTagType == 3) ? e->getPartition() :
          (elementTagType == 2) ? abs(physical) :
                                  elementary);
  if(physical < 0) e->reverse();
}

// The node of a Gmsh 10-node tetrahedron at each position of a Medit
// TetrahedraP2: the last two are swapped (see MElement::writeMESH())
static const int meditTet10[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

// The sections of elements of a Medit file: keyword, Gmsh element type, the
// Gmsh node at each Medit position (if not in the same order), the family of
// elements (lines, triangles, quadrangles, tetrahedra, hexahedra, prisms) and
// what they are, for the messages
struct meditSection {
  const char *keyword;
  int type;
  const int *nodes;
  int family;
  const char *what;
};
static const meditSection meditSections[] = {
  {"Edges", MSH_LIN_2, nullptr, 0, "edges"},
  {"EdgesP2", MSH_LIN_3, nullptr, 0, "edges"},
  {"EdgesP3", MSH_LIN_4, nullptr, 0, "edges"},
  {"EdgesP4", MSH_LIN_5, nullptr, 0, "edges"},
  {"Triangles", MSH_TRI_3, nullptr, 1, "triangles"},
  {"TrianglesP2", MSH_TRI_6, nullptr, 1, "triangles"},
  {"TrianglesP3", MSH_TRI_10, nullptr, 1, "triangles"},
  {"TrianglesP4", MSH_TRI_15, nullptr, 1, "triangles"},
  {"Quadrilaterals", MSH_QUA_4, nullptr, 2, "quadrangles"},
  // (the nodes ordered as in Gmsh: corners, edges, center)
  {"QuadrilateralsQ2", MSH_QUA_9, nullptr, 2, "quadrangles Q2"},
  {"Tetrahedra", MSH_TET_4, nullptr, 3, "tetrahedra"},
  {"TetrahedraP2", MSH_TET_10, meditTet10, 3, "tetrahedra"},
  {"TetrahedraP3", MSH_TET_20, nullptr, 3, "tetrahedra"},
  {"TetrahedraP4", MSH_TET_35, nullptr, 3, "tetrahedra"},
  {"Hexahedra", MSH_HEX_8, nullptr, 4, "hexahedra"},
  {"Prisms", MSH_PRI_6, nullptr, 5, "prisms"},
  {"PrismsP2", MSH_PRI_18, meditPrism18, 5, "prisms P2"},
};

int GModel::readMESH(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "r");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char buffer[256];
  if(!fgets(buffer, sizeof(buffer), fp)) {
    fclose(fp);
    return 0;
  }

  char str[256];
  int format;
  sscanf(buffer, "%s %d", str, &format);
  if(format < 1 || format > 4) {
    Msg::Error("Unknown Medit mesh format %d", format);
    fclose(fp);
    return 0;
  }

  std::vector<MVertex *> vertexVector;
  std::map<int, std::vector<MElement *>> elements[6];

  int Dimension = 3;

  while(!feof(fp)) {
    if(!fgets(buffer, 256, fp)) break;
    if(buffer[0] != '#') { // skip comments and empty lines
      str[0] = '\0';
      sscanf(buffer, "%s", str);
      if(!strcmp(str, "Dimension")) {
        // the value is on the next line, or on the same line (e.g. CGAL)
        int d = 0;
        if(sscanf(buffer, "%s %d", str, &d) != 2) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          sscanf(buffer, "%d", &d);
        }
        if(d == 2 || d == 3)
          Dimension = d;
        else
          Msg::Warning("Unknown dimension %d in Medit file, assuming 3", d);
      }
      else if(!strcmp(str, "Vertices")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbv;
        sscanf(buffer, "%d", &nbv);
        Msg::Info("%d nodes", nbv);
        vertexVector.resize(nbv);
        for(int i = 0; i < nbv; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int dum;
          double x, y, z = 0.;
          if(Dimension == 3)
            sscanf(buffer, "%lf %lf %lf %d", &x, &y, &z, &dum);
          else
            sscanf(buffer, "%lf %lf %d", &x, &y, &dum);
          vertexVector[i] = new MVertex(x, y, z);
        }
      }
      else {
        const meditSection *sec = nullptr;
        for(const meditSection &m : meditSections)
          if(!strcmp(str, m.keyword)) sec = &m;
        if(!sec) continue;
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe = 0;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d %s", nbe, sec->what);
        const int numNodes = ElementType::getNumVertices(sec->type);
        std::vector<int> n(numNodes);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          // the node indices (starting at 1), then the reference
          char *p = buffer;
          for(int j = 0; j < numNodes; j++)
            n[sec->nodes ? sec->nodes[j] : j] = strtol(p, &p, 10) - 1;
          int cl = strtol(p, &p, 10);
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(numNodes, n.data(), vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[sec->family][cl].push_back(
            MElementFactory().create(sec->type, vertices));
        }
      }
    }
  }

  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertexVector);

  fclose(fp);
  return 1;
}

int GModel::writeMESH(const std::string &name, int elementTagType, bool saveAll,
                      double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  int numVertices = indexMeshVertices(saveAll);

  int numEdges = 0, numTriangles = 0, numQuadrangles = 0;
  int numTetrahedra = 0, numHexahedra = 0, numPrisms = 0;
  for(auto it = firstEdge(); it != lastEdge(); ++it) {
    if(saveAll || (*it)->physicals.size()) { numEdges += (*it)->lines.size(); }
  }
  for(auto it = firstFace(); it != lastFace(); ++it) {
    if(saveAll || (*it)->physicals.size()) {
      numTriangles += (*it)->triangles.size();
      numQuadrangles += (*it)->quadrangles.size();
    }
  }
  for(auto it = firstRegion(); it != lastRegion(); ++it) {
    if(saveAll || (*it)->physicals.size()) {
      numTetrahedra += (*it)->tetrahedra.size();
      numHexahedra += (*it)->hexahedra.size();
      numPrisms += (*it)->prisms.size();
    }
  }

  // a mesh in the z = 0 plane without volume elements is saved as a 2D mesh,
  // with 2 coordinates per node
  std::vector<GEntity *> entities;
  getEntities(entities);
  bool planar = !numTetrahedra && !numHexahedra && !numPrisms;
  for(std::size_t i = 0; planar && i < entities.size(); i++)
    for(auto v : entities[i]->mesh_vertices)
      if(v->getIndex() >= 0 && v->z() != 0.) planar = false;

  fprintf(fp, " MeshVersionFormatted 2\n");
  fprintf(fp, " Dimension\n");
  fprintf(fp, " %d\n", planar ? 2 : 3);

  fprintf(fp, " Vertices\n");
  fprintf(fp, " %d\n", numVertices);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(auto v : entities[i]->mesh_vertices) {
      if(!planar)
        v->writeMESH(fp, scalingFactor);
      else if(v->getIndex() >= 0)
        fprintf(fp, " %20.14G      %20.14G      %d\n", v->x() * scalingFactor,
                v->y() * scalingFactor, v->onWhat() ? v->onWhat()->tag() : 0);
    }
  }

  if(numEdges) {
    int order = 1;
    for(auto it = firstEdge(); it != lastEdge(); ++it) {
      if(!(*it)->lines.empty()) {
        order = (*it)->lines[0]->getPolynomialOrder();
        break;
      }
    }
    if(order == 4)
      fprintf(fp, " EdgesP4\n");
    else if(order == 3)
      fprintf(fp, " EdgesP3\n");
    else if(order == 2)
      fprintf(fp, " EdgesP2\n");
    else if(order == 1)
      fprintf(fp, " Edges\n");
    else {
      Msg::Info("Order %d unknown for edges", order);
      fprintf(fp, " Edges\n");
    }
    fprintf(fp, " %d\n", numEdges);
    for(auto it = firstEdge(); it != lastEdge(); ++it) {
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys) {
        for(std::size_t i = 0; i < (*it)->lines.size(); i++)
          (*it)->lines[i]->writeMESH(fp, elementTagType, (*it)->tag(),
                                     numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }
  if(numTriangles) {
    // (the first surfaces can have quadrangles only)
    int order = 1;
    for(auto it = firstFace(); it != lastFace(); ++it) {
      if(!(*it)->triangles.empty()) {
        order = (*it)->triangles[0]->getPolynomialOrder();
        break;
      }
    }
    if(order == 4)
      fprintf(fp, " TrianglesP4\n");
    else if(order == 3)
      fprintf(fp, " TrianglesP3\n");
    else if(order == 2)
      fprintf(fp, " TrianglesP2\n");
    else if(order == 1)
      fprintf(fp, " Triangles\n");
    else {
      Msg::Info("Order %d unknown for triangles", order);
      fprintf(fp, " Triangles\n");
    }
    fprintf(fp, " %d\n", numTriangles);
    for(auto it = firstFace(); it != lastFace(); ++it) {
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys) {
        for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
          (*it)->triangles[i]->writeMESH(fp, elementTagType, (*it)->tag(),
                                         numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }
  if(numQuadrangles) {
    // 9-node quadrangles are saved as QuadrilateralsQ2 (nodes ordered as in
    // Gmsh) if all the quadrangles have 9 nodes, other high-order quadrangles
    // as linear ones
    bool q2 = true, highOrder = false;
    for(auto it = firstFace(); q2 && it != lastFace(); ++it)
      for(auto q : (*it)->quadrangles)
        if(q->getTypeForMSH() != MSH_QUA_9) q2 = false;
    fprintf(fp, q2 ? " QuadrilateralsQ2\n" : " Quadrilaterals\n");
    fprintf(fp, " %d\n", numQuadrangles);
    for(auto it = firstFace(); it != lastFace(); ++it) {
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys) {
        for(auto q : (*it)->quadrangles) {
          writeMeditElement(fp, q, nullptr, q2 ? 9 : 4, elementTagType,
                            (*it)->tag(), numPhys ? (*it)->physicals[0] : 0);
          if(!q2 && q->getNumVertices() > 4) highOrder = true;
        }
      }
    }
    if(highOrder)
      Msg::Warning("High-order quadrangles saved as linear quadrangles in "
                   "Medit format");
  }
  if(numTetrahedra) {
    // (the first volumes can have no tetrahedra)
    int order = 1;
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      if(!(*it)->tetrahedra.empty()) {
        order = (*it)->tetrahedra[0]->getPolynomialOrder();
        break;
      }
    }
    if(order == 4)
      fprintf(fp, " TetrahedraP4\n");
    else if(order == 3)
      fprintf(fp, " TetrahedraP3\n");
    else if(order == 2)
      fprintf(fp, " TetrahedraP2\n");
    else if(order == 1)
      fprintf(fp, " Tetrahedra\n");
    else {
      Msg::Info("Order %d unknown for tetrahedra", order);
      fprintf(fp, " Tetrahedra\n");
    }
    fprintf(fp, " %d\n", numTetrahedra);
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys) {
        for(std::size_t i = 0; i < (*it)->tetrahedra.size(); i++)
          (*it)->tetrahedra[i]->writeMESH(fp, elementTagType, (*it)->tag(),
                                          numPhys ? (*it)->physicals[0] : 0);
      }
    }
  }
  if(numHexahedra) {
    // high-order hexahedra are saved as linear ones
    fprintf(fp, " Hexahedra\n");
    fprintf(fp, " %d\n", numHexahedra);
    bool highOrder = false;
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys) {
        for(auto h : (*it)->hexahedra) {
          writeMeditElement(fp, h, nullptr, 8, elementTagType, (*it)->tag(),
                            numPhys ? (*it)->physicals[0] : 0);
          if(h->getNumVertices() > 8) highOrder = true;
        }
      }
    }
    if(highOrder)
      Msg::Warning("High-order hexahedra saved as linear hexahedra in Medit "
                   "format");
  }
  if(numPrisms) {
    // the corners of the prisms in Medit files are ordered as in Gmsh (bottom
    // triangle, then top triangle); 18-node prisms are saved as PrismsP2 if
    // all the prisms have 18 nodes, other high-order prisms as linear ones
    bool p2 = true;
    for(auto it = firstRegion(); p2 && it != lastRegion(); ++it)
      for(auto p : (*it)->prisms)
        if(p->getTypeForMSH() != MSH_PRI_18) p2 = false;
    fprintf(fp, p2 ? " PrismsP2\n" : " Prisms\n");
    fprintf(fp, " %d\n", numPrisms);
    bool highOrder = false;
    for(auto it = firstRegion(); it != lastRegion(); ++it) {
      int numPhys = (*it)->physicals.size();
      if(saveAll || numPhys) {
        int physical = numPhys ? (*it)->physicals[0] : 0;
        for(auto p : (*it)->prisms) {
          writeMeditElement(fp, p, p2 ? meditPrism18 : nullptr, p2 ? 18 : 6,
                            elementTagType, (*it)->tag(), physical);
          if(!p2 && p->getNumVertices() > 6) highOrder = true;
        }
      }
    }
    if(highOrder)
      Msg::Warning("High-order prisms saved as linear prisms in Medit format");
  }

  fprintf(fp, " End\n");

  fclose(fp);
  return 1;
}
