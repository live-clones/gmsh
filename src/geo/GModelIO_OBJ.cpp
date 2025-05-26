// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "MElementCut.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "OS.h"
#include "discreteFace.h"

#define TINYOBJLOADER_IMPLEMENTATION
#define TINYOBJLOADER_USE_DOUBLE
#include <tiny_obj_loader.h>

#include <array>
#include <vector>
#include <string>

int GModel::readOBJ(const std::string &name)
{
  tinyobj::ObjReader reader;
  tinyobj::ObjReaderConfig config;
  config.triangulate = false;

  if(!reader.ParseFromFile(name, config)) {
    Msg::Error("Failed to read OBJ: %s", reader.Error().c_str());
    return 0;
  }

  if(!reader.Warning().empty()) {
    Msg::Warning("TinyObjReader: %s", reader.Warning().c_str());
  }

  const auto &attrib = reader.GetAttrib();
  const auto &shapes = reader.GetShapes();

  if(attrib.vertices.empty()) {
    Msg::Error("Empty OBJ mesh");
    return 0;
  }

  GFace *gf = new discreteFace(this, getMaxElementaryNumber(2) + 1);
  add(gf);

  std::vector<MVertex *> vertices;
  for(size_t i = 0; i < attrib.vertices.size(); i += 3) {
    vertices.push_back(new MVertex(attrib.vertices[i], attrib.vertices[i + 1],
                                   attrib.vertices[i + 2], gf));
  }

  for(const auto &shape : shapes) {
    size_t index_offset = 0;
    for(size_t f = 0; f < shape.mesh.num_face_vertices.size(); f++) {
      int fv = shape.mesh.num_face_vertices[f];
      if(fv == 3) {
        std::array<int, 3> v;
        for(size_t k = 0; k < v.size(); k++)
          v[k] = shape.mesh.indices[index_offset + k].vertex_index;
        gf->addTriangle(
          new MTriangle(vertices[v[0]], vertices[v[1]], vertices[v[2]]));
      }
      else if(fv == 4) {
        std::array<int, 4> v;
        for(size_t k = 0; k < v.size(); ++k)
          v[k] = shape.mesh.indices[index_offset + k].vertex_index;
        gf->addQuadrangle(new MQuadrangle(vertices[v[0]], vertices[v[1]],
                                          vertices[v[2]], vertices[v[3]]));
      }
      else if(fv > 4) {
        std::vector<MVertex *> polyVerts;
        polyVerts.reserve(fv);
        for(int k = 0; k < fv; k++) {
          int idx = shape.mesh.indices[index_offset + k].vertex_index;
          polyVerts.push_back(vertices[idx]);
        }
        // Triangulate as a fan for convex polygons
        std::vector<MTriangle *> tris;
        for(int k = 1; k < fv - 1; ++k) {
          tris.push_back(
            new MTriangle(polyVerts[0], polyVerts[k], polyVerts[k + 1]));
        }
        gf->addPolygon(new MPolygon(tris));
      }
      else {
        Msg::Warning("Ignoring face with %d vertices", fv);
      }
      index_offset += fv;
    }
  }
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertices);
  return 1;
}
