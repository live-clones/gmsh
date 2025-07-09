// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Giannis Nikiteas

#include "GModel.h"
#include "MElementCut.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "OS.h"
#include "discreteFace.h"

#define TINYOBJLOADER_IMPLEMENTATION
#define TINYOBJLOADER_USE_DOUBLE
#include <tiny_obj_loader.h>

#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace {
  inline void addFaceToGFace(GFace *gf, const std::vector<MVertex *> &verts)
  {
    if(verts.size() == 3) {
      gf->addTriangle(new MTriangle(verts[0], verts[1], verts[2]));
    }
    else if(verts.size() == 4) {
      gf->addQuadrangle(
        new MQuadrangle(verts[0], verts[1], verts[2], verts[3]));
    }
    else if(verts.size() > 4) {
      // Triangulate as a fan for convex polygons
      std::vector<MTriangle *> tris;
      for(size_t k = 1; k < verts.size() - 1; ++k) {
        tris.push_back(new MTriangle(verts[0], verts[k], verts[k + 1]));
      }
      gf->addPolygon(new MPolygon(tris));
    }
  }
  template <typename T> void writeFace(std::ofstream &ofs, const T *elem)
  {
    ofs << "f";
    for(size_t i = 0; i < elem->getNumVertices(); ++i) {
      ofs << " " << elem->getVertex(i)->getIndex();
    }
    ofs << "\n";
  }
  template <typename Severity>
  void logTinyObjReader(Severity logFunc, const std::string &message)
  {
    std::istringstream stream(message);
    std::string line;
    while(std::getline(stream, line))
      logFunc("tinyobjreader: %s", line.c_str());
  }
} // namespace

int GModel::readOBJ(const std::string &name)
{
  tinyobj::ObjReader reader;
  tinyobj::ObjReaderConfig config;
  config.triangulate = false;

  if(!reader.ParseFromFile(name, config)) {
    logTinyObjReader(Msg::Error, reader.Error());
    return 0;
  }

  if(!reader.Warning().empty()) {
    logTinyObjReader(Msg::Warning, reader.Warning());
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
      if(fv < 3) {
        Msg::Warning("Ignoring face with %d vertices", fv);
        index_offset += fv;
        continue;
      }
      std::vector<MVertex *> faceVerts;
      faceVerts.reserve(fv);
      for(int k = 0; k < fv; k++) {
        int idx = shape.mesh.indices[index_offset + k].vertex_index;
        faceVerts.push_back(vertices[idx]);
      }
      addFaceToGFace(gf, faceVerts);
      index_offset += fv;
    }
  }
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(vertices);
  return 1;
}

int GModel::writeOBJ(const std::string &name, bool saveAll,
                     double scalingFactor)
{
  std::ofstream ofs(name);
  if(!ofs) {
    Msg::Error("Unable to open file '%s' for writing", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;
  indexMeshVertices(saveAll);

  // Write vertices
  std::vector<GEntity *> entities;
  getEntities(entities);
  ofs << std::setprecision(16);
  ofs << "# Gmsh OBJ export\n";

  for(const auto &ent : entities) {
    for(const auto &v : ent->mesh_vertices) {
      SPoint3 p = v->point();
      ofs << "v " << scalingFactor * p.x() << " " << scalingFactor * p.y()
          << " " << scalingFactor * p.z() << "\n";
    }
  }

  for(const auto &face : faces) {
    if(!saveAll && face->physicals.empty()) continue;
    for(const auto &t : face->triangles) writeFace(ofs, t);
    for(const auto &q : face->quadrangles) writeFace(ofs, q);
    for(const auto &p : face->polygons) writeFace(ofs, p);
  }

  ofs.close();
  return 1;
}
