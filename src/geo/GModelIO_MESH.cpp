// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Florian Blachère

#include <sstream>
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
      else if(!strcmp(str, "Edges")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d edges", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[2], cl;
          sscanf(buffer, "%d %d %d", &n[0], &n[1], &cl);
          for(int j = 0; j < 2; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(2, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[0][cl].push_back(new MLine(vertices));
        }
      }
      else if(!strcmp(str, "EdgesP2")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d edges", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[3], cl;
          sscanf(buffer, "%d %d %d %d", &n[0], &n[1], &n[2], &cl);
          for(int j = 0; j < 3; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(3, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[0][cl].push_back(new MLine3(vertices));
        }
      }
      else if(!strcmp(str, "EdgesP3")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d edges", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[4], cl;
          sscanf(buffer, "%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &cl);
          for(int j = 0; j < 4; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(4, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[0][cl].push_back(new MLineN(vertices));
        }
      }
      else if(!strcmp(str, "EdgesP4")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d edges", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[5], cl;
          sscanf(buffer, "%d %d %d %d %d  %d", &n[0], &n[1], &n[2], &n[3],
                 &n[4], &cl);
          for(int j = 0; j < 5; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(5, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[0][cl].push_back(new MLineN(vertices));
        }
      }
      else if(!strcmp(str, "Triangles")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d triangles", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[3], cl;
          sscanf(buffer, "%d %d %d %d", &n[0], &n[1], &n[2], &cl);
          for(int j = 0; j < 3; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(3, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[1][cl].push_back(new MTriangle(vertices));
        }
      }
      else if(!strcmp(str, "TrianglesP2")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d triangles", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[6], cl;
          sscanf(buffer, "%d %d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3],
                 &n[4], &n[5], &cl);
          for(int j = 0; j < 6; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(6, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[1][cl].push_back(new MTriangle6(vertices));
        }
      }
      else if(!strcmp(str, "TrianglesP3")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d triangles", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[10], cl;
          sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d %d", &n[0], &n[1],
                 &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8], &n[9], &cl);
          for(int j = 0; j < 10; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(10, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[1][cl].push_back(new MTriangleN(vertices, 3));
        }
      }
      else if(!strcmp(str, "TrianglesP4")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d triangles", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[15], cl;
          sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                 &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8],
                 &n[9], &n[10], &n[11], &n[12], &n[13], &n[14], &cl);
          for(int j = 0; j < 15; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(15, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[1][cl].push_back(new MTriangleN(vertices, 4));
        }
      }
      else if(!strcmp(str, "Quadrilaterals")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d quadrangles", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[4], cl;
          sscanf(buffer, "%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &cl);
          for(int j = 0; j < 4; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(4, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[2][cl].push_back(new MQuadrangle(vertices));
        }
      }
      else if(!strcmp(str, "QuadrilateralsQ2")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d quadrangles Q2", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          // the nodes are ordered as in Gmsh (corners, edges, center)
          int n[9], cl;
          sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d", &n[0], &n[1], &n[2],
                 &n[3], &n[4], &n[5], &n[6], &n[7], &n[8], &cl);
          for(int j = 0; j < 9; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(9, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[2][cl].push_back(new MQuadrangle9(vertices));
        }
      }
      else if(!strcmp(str, "Tetrahedra")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d tetrahedra", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[4], cl;
          sscanf(buffer, "%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &cl);
          for(int j = 0; j < 4; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(4, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[3][cl].push_back(new MTetrahedron(vertices));
        }
      }
      else if(!strcmp(str, "TetrahedraP2")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d tetrahedra", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[10], cl;
          // vertices 8 and 9 are reversed, see MElement::writeMESH()
          sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d %d", &n[0], &n[1],
                 &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[9], &n[8], &cl);
          for(int j = 0; j < 10; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(10, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[3][cl].push_back(new MTetrahedron10(vertices));
        }
      }
      else if(!strcmp(str, "TetrahedraP3")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d tetrahedra", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[20], cl;
          sscanf(
            buffer,
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8],
            &n[9], &n[10], &n[11], &n[12], &n[13], &n[14], &n[15], &n[16],
            &n[17], &n[18], &n[19], &cl);
          for(int j = 0; j < 20; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(20, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[3][cl].push_back(new MTetrahedronN(vertices, 3));
        }
      }
      else if(!strcmp(str, "TetrahedraP4")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d tetrahedra", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[35], cl;
          sscanf(buffer,
                 "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
                 "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                 &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7], &n[8],
                 &n[9], &n[10], &n[11], &n[12], &n[13], &n[14], &n[15], &n[16],
                 &n[17], &n[18], &n[19], &n[20], &n[21], &n[22], &n[23], &n[24],
                 &n[25], &n[26], &n[27], &n[28], &n[29], &n[30], &n[31], &n[32],
                 &n[33], &n[34], &cl);
          for(int j = 0; j < 35; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(35, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[3][cl].push_back(new MTetrahedronN(vertices, 4));
        }
      }
      else if(!strcmp(str, "Hexahedra")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d hexahedra", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[8], cl;
          sscanf(buffer, "%d %d %d %d %d %d %d %d %d", &n[0], &n[1], &n[2],
                 &n[3], &n[4], &n[5], &n[6], &n[7], &cl);
          for(int j = 0; j < 8; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(8, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[4][cl].push_back(new MHexahedron(vertices));
        }
      }
      else if(!strcmp(str, "Prisms")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d prisms", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          int n[6], cl;
          sscanf(buffer, "%d %d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3],
                 &n[4], &n[5], &cl);
          for(int j = 0; j < 6; j++) n[j]--;
          std::vector<MVertex *> vertices;
          if(!getMeshVertices(6, n, vertexVector, vertices)) {
            fclose(fp);
            return 0;
          }
          elements[5][cl].push_back(new MPrism(vertices));
        }
      }
      else if(!strcmp(str, "PrismsP2")) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        int nbe;
        sscanf(buffer, "%d", &nbe);
        Msg::Info("%d prisms P2", nbe);
        for(int i = 0; i < nbe; i++) {
          if(!fgets(buffer, sizeof(buffer), fp)) break;
          std::istringstream line(buffer);
          int n[18], cl = 0;
          for(int j = 0; j < 18; j++) {
            line >> n[j];
            n[j]--;
          }
          line >> cl;
          std::vector<MVertex *> medit, vertices(18);
          if(!getMeshVertices(18, n, vertexVector, medit)) {
            fclose(fp);
            return 0;
          }
          for(int j = 0; j < 18; j++) vertices[meditPrism18[j]] = medit[j];
          elements[5][cl].push_back(new MPrism18(vertices));
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
