// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <string>
#include <algorithm>
#include <sstream>
#include "GModel.h"
#include "OS.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MVertexRTree.h"
#include "discreteFace.h"
#include "StringUtils.h"
#include "Context.h"

static bool invalidChar(char c) { return !(c >= 32 && c <= 126); }

int GModel::readSTL(const std::string &name, double tolerance)
{
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // store triplets of points for each solid found in the file
  std::vector<std::vector<SPoint3> > points;
  SBoundingBox3d bbox;
  std::vector<std::string> names;

  // "solid", or binary data header
  char buffer[256];
  if(!fgets(buffer, sizeof(buffer), fp)) {
    fclose(fp);
    return 0;
  }

  // SPoint3 p0(1.9e6, 4e6, 0);

  bool binary = strncmp(buffer, "solid", 5) && strncmp(buffer, "SOLID", 5);

  // ASCII STL
  if(!binary) {
    if(strlen(buffer) > 6)
      names.push_back(&buffer[6]);
    else
      names.push_back("");
    points.resize(1);
    while(!feof(fp)) {
      // "facet normal x y z" or "endsolid"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      if(!strncmp(buffer, "endsolid", 8) || !strncmp(buffer, "ENDSOLID", 8)) {
        // "solid"
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        if(!strncmp(buffer, "solid", 5) || !strncmp(buffer, "SOLID", 5)) {
          if(strlen(buffer) > 6)
            names.push_back(&buffer[6]);
          else
            names.push_back("");
          points.resize(points.size() + 1);
          // "facet normal x y z"
          if(!fgets(buffer, sizeof(buffer), fp)) break;
        }
      }
      // "outer loop"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      // "vertex x y z"
      for(int i = 0; i < 3; i++) {
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        char s1[256];
        double x, y, z;
        if(sscanf(buffer, "%s %lf %lf %lf", s1, &x, &y, &z) != 4) break;
        SPoint3 p(x, y, z);
        // p -= p0;
        points.back().push_back(p);
        bbox += p;
      }
      // "endloop"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      // "endfacet"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
    }
  }

  // check if we could parse something
  bool empty = true;
  for(std::size_t i = 0; i < points.size(); i++) {
    if(points[i].size()) {
      empty = false;
      break;
    }
  }
  if(empty) points.clear();

  // binary STL (we also try to read in binary mode if the header told
  // us the format was ASCII but we could not read any vertices)
  if(binary || empty) {
    if(binary)
      Msg::Info("Mesh is in binary format");
    else
      Msg::Info("Wrong ASCII header or empty file: trying binary read");
    rewind(fp);
    while(!feof(fp)) {
      char header[80];
      if(!fread(header, sizeof(char), 80, fp)) break;
      unsigned int nfacets = 0;
      size_t ret = fread(&nfacets, sizeof(unsigned int), 1, fp);
      bool swap = false;
      if(nfacets > 100000000) {
        Msg::Info("Swapping bytes from binary file");
        swap = true;
        SwapBytes((char *)&nfacets, sizeof(unsigned int), 1);
      }
      if(ret && nfacets) {
        names.push_back(header);
        points.resize(points.size() + 1);
        char *data = new char[nfacets * 50 * sizeof(char)];
        ret = fread(data, sizeof(char), nfacets * 50, fp);
        if(ret == nfacets * 50) {
          for(std::size_t i = 0; i < nfacets; i++) {
            float *xyz = (float *)&data[i * 50 * sizeof(char)];
            if(swap) SwapBytes((char *)xyz, sizeof(float), 12);
            for(int j = 0; j < 3; j++) {
              SPoint3 p(xyz[3 + 3 * j], xyz[3 + 3 * j + 1], xyz[3 + 3 * j + 2]);
              // p -= p0;
              points.back().push_back(p);
              bbox += p;
            }
          }
        }
        delete[] data;
      }
    }
  }

  // cleanup names
  if(names.size() != points.size()) {
    Msg::Debug("Invalid number of names in STL file - should never happen");
    names.resize(points.size());
  }
  for(std::size_t i = 0; i < names.size(); i++) {
    names[i].erase(remove_if(names[i].begin(), names[i].end(), invalidChar),
                   names[i].end());
  }

  std::vector<GFace *> faces;
  for(std::size_t i = 0; i < points.size(); i++) {
    if(points[i].empty()) {
      Msg::Error("No facets found in STL file for solid %d %s", i,
                 names[i].c_str());
      fclose(fp);
      return 0;
    }
    if(points[i].size() % 3) {
      Msg::Error("Wrong number of points (%d) in STL file for solid %d %s",
                 points[i].size(), i, names[i].c_str());
      fclose(fp);
      return 0;
    }
    Msg::Info("%d facets in solid %d %s", points[i].size() / 3, i,
              names[i].c_str());
    // create face
    GFace *face = new discreteFace(this, getMaxElementaryNumber(2) + 1);
    faces.push_back(face);
    add(face);
    if(!names[i].empty()) setElementaryName(2, face->tag(), names[i]);
  }

  // create triangles using unique vertices
  double eps = norm(SVector3(bbox.max(), bbox.min())) * tolerance;
  std::vector<MVertex *> vertices;
  for(std::size_t i = 0; i < points.size(); i++)
    for(std::size_t j = 0; j < points[i].size(); j++)
      vertices.push_back(
        new MVertex(points[i][j].x(), points[i][j].y(), points[i][j].z()));
  MVertexRTree pos(eps);
  pos.insert(vertices);

  std::set<MFace, MFaceLessThan> unique;
  int nbDuplic = 0, nbDegen = 0;
  for(std::size_t i = 0; i < points.size(); i++) {
    for(std::size_t j = 0; j < points[i].size(); j += 3) {
      MVertex *v[3];
      for(int k = 0; k < 3; k++) {
        double x = points[i][j + k].x();
        double y = points[i][j + k].y();
        double z = points[i][j + k].z();
        v[k] = pos.find(x, y, z);
        if(!v[k])
          Msg::Error("Could not find node at position (%.16g, %.16g, %.16g) "
                     "with tol=%.16g",
                     x, y, z, eps);
      }
      if(!v[0] || !v[1] || !v[2]) {
        // error
      }
      else if(v[0] == v[1] || v[0] == v[2] || v[1] == v[2]) {
        Msg::Debug("Skipping degenerated triangle %lu %lu %lu", v[0]->getNum(),
                   v[1]->getNum(), v[2]->getNum());
        nbDegen++;
      }
      else if(CTX::instance()->mesh.stlRemoveDuplicateTriangles) {
        MFace mf(v[0], v[1], v[2]);
        if(unique.find(mf) == unique.end()) {
          faces[i]->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
          unique.insert(mf);
        }
        else {
          nbDuplic++;
        }
      }
      else {
        faces[i]->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
      }
    }
  }
  if(nbDuplic || nbDegen)
    Msg::Warning("%d duplicate/%d degenerate triangles in STL file", nbDuplic,
                 nbDegen);

  _associateEntityWithMeshVertices();

  _storeVerticesInEntities(vertices); // will delete unused vertices

  fclose(fp);
  return 1;
}

static void writeSTLfaces(FILE *fp, std::vector<GFace *> &faces, bool binary,
                          double scalingFactor, const std::string &name)
{
  bool useGeoSTL = false;
  unsigned int nfacets = 0;
  for(auto it = faces.begin(); it != faces.end(); ++it) {
    nfacets += (*it)->triangles.size() + 2 * (*it)->quadrangles.size();
  }
  if(!nfacets) { // use CAD STL if there is no mesh
    useGeoSTL = true;
    for(auto it = faces.begin(); it != faces.end(); ++it) {
      (*it)->buildSTLTriangulation();
      nfacets += (*it)->stl_triangles.size() / 3;
    }
  }

  if(!binary) { fprintf(fp, "solid %s\n", name.c_str()); }
  else {
    char header[80];
    strncpy(header, name.c_str(), 79);
    header[79] = '\0';
    fwrite(header, sizeof(char), 80, fp);
    fwrite(&nfacets, sizeof(unsigned int), 1, fp);
  }

  for(auto it = faces.begin(); it != faces.end(); ++it) {
    if(useGeoSTL && (*it)->stl_vertices_uv.size()) {
      for(std::size_t i = 0; i < (*it)->stl_triangles.size(); i += 3) {
        SPoint2 &p1((*it)->stl_vertices_uv[(*it)->stl_triangles[i]]);
        SPoint2 &p2((*it)->stl_vertices_uv[(*it)->stl_triangles[i + 1]]);
        SPoint2 &p3((*it)->stl_vertices_uv[(*it)->stl_triangles[i + 2]]);
        GPoint gp1 = (*it)->point(p1);
        GPoint gp2 = (*it)->point(p2);
        GPoint gp3 = (*it)->point(p3);
        double x[3] = {gp1.x(), gp2.x(), gp3.x()};
        double y[3] = {gp1.y(), gp2.y(), gp3.y()};
        double z[3] = {gp1.z(), gp2.z(), gp3.z()};
        double n[3];
        normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
        if(!binary) {
          fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
          fprintf(fp, "  outer loop\n");
          for(int j = 0; j < 3; j++)
            fprintf(fp, "    vertex %.16g %.16g %.16g\n", x[j] * scalingFactor,
                    y[j] * scalingFactor, z[j] * scalingFactor);
          fprintf(fp, "  endloop\n");
          fprintf(fp, "endfacet\n");
        }
        else {
          char data[50];
          float *coords = (float *)data;
          coords[0] = (float)n[0];
          coords[1] = (float)n[1];
          coords[2] = (float)n[2];
          for(int j = 0; j < 3; j++) {
            coords[3 + 3 * j] = (float)(x[j] * scalingFactor);
            coords[3 + 3 * j + 1] = (float)(y[j] * scalingFactor);
            coords[3 + 3 * j + 2] = (float)(z[j] * scalingFactor);
          }
          data[48] = data[49] = 0;
          fwrite(data, sizeof(char), 50, fp);
        }
      }
    }
    else {
      for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
        (*it)->triangles[i]->writeSTL(fp, binary, scalingFactor);
      for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++)
        (*it)->quadrangles[i]->writeSTL(fp, binary, scalingFactor);
    }
  }

  if(!binary) fprintf(fp, "endsolid %s\n", name.c_str());
}

int GModel::writeSTL(const std::string &name, bool binary, bool saveAll,
                     double scalingFactor, int oneSolidPerSurface)
{
  FILE *fp = Fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  if(oneSolidPerSurface == 1) { // one solid per surface
    for(auto it = firstFace(); it != lastFace(); ++it) {
      if(saveAll || (*it)->physicals.size()) {
        std::vector<GFace *> faces(1, *it);
        std::string name = getElementaryName(2, (*it)->tag());
        if(name.empty()) {
          std::ostringstream s;
          s << "Gmsh Surface " << (*it)->tag();
          name = s.str();
        }
        writeSTLfaces(fp, faces, binary, scalingFactor, name);
      }
    }
  }
  else if(oneSolidPerSurface == 2) { // one solid per physical surface
    std::map<int, std::vector<GEntity *> > phys;
    getPhysicalGroups(2, phys);
    for(auto it = phys.begin(); it != phys.end(); it++) {
      std::vector<GFace *> faces;
      for(std::size_t i = 0; i < it->second.size(); i++) {
        faces.push_back(static_cast<GFace *>(it->second[i]));
      }
      std::string name = getPhysicalName(2, it->first);
      if(name.empty()) {
        std::ostringstream s;
        s << "Gmsh Physical Surface " << it->first;
        name = s.str();
      }
      writeSTLfaces(fp, faces, binary, scalingFactor, name);
    }
  }
  else { // one solid
    std::vector<GFace *> faces;
    for(auto it = firstFace(); it != lastFace(); ++it) {
      if(saveAll || (*it)->physicals.size()) { faces.push_back(*it); }
    }
    std::string name = "Created by Gmsh";
    writeSTLfaces(fp, faces, binary, scalingFactor, name);
  }

  fclose(fp);
  return 1;
}
