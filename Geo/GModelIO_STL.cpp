// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdio.h>
#include "GModel.h"
#include "OS.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MVertexRTree.h"
#include "discreteFace.h"
#include "StringUtils.h"

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

  // "solid", or binary data header
  char buffer[256];
  if(!fgets(buffer, sizeof(buffer), fp)) {
    fclose(fp);
    return 0;
  }

  bool binary = strncmp(buffer, "solid", 5) && strncmp(buffer, "SOLID", 5);

  // ASCII STL
  if(!binary) {
    points.resize(1);
    while(!feof(fp)) {
      // "facet normal x y z" or "endsolid"
      if(!fgets(buffer, sizeof(buffer), fp)) break;
      if(!strncmp(buffer, "endsolid", 8) || !strncmp(buffer, "ENDSOLID", 8)) {
        // "solid"
        if(!fgets(buffer, sizeof(buffer), fp)) break;
        if(!strncmp(buffer, "solid", 5) || !strncmp(buffer, "SOLID", 5)) {
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
  for(unsigned int i = 0; i < points.size(); i++) {
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
        points.resize(points.size() + 1);
        char *data = new char[nfacets * 50 * sizeof(char)];
        ret = fread(data, sizeof(char), nfacets * 50, fp);
        if(ret == nfacets * 50) {
          for(unsigned int i = 0; i < nfacets; i++) {
            float *xyz = (float *)&data[i * 50 * sizeof(char)];
            if(swap) SwapBytes((char *)xyz, sizeof(float), 12);
            for(int j = 0; j < 3; j++) {
              SPoint3 p(xyz[3 + 3 * j], xyz[3 + 3 * j + 1], xyz[3 + 3 * j + 2]);
              points.back().push_back(p);
              bbox += p;
            }
          }
        }
        delete[] data;
      }
    }
  }

  std::vector<GFace *> faces;
  for(unsigned int i = 0; i < points.size(); i++) {
    if(points[i].empty()) {
      Msg::Error("No facets found in STL file for solid %d", i);
      fclose(fp);
      return 0;
    }
    if(points[i].size() % 3) {
      Msg::Error("Wrong number of points (%d) in STL file for solid %d",
                 points[i].size(), i);
      fclose(fp);
      return 0;
    }
    Msg::Info("%d facets in solid %d", points[i].size() / 3, i);
    // create face
    GFace *face = new discreteFace(this, getMaxElementaryNumber(2) + 1);
    faces.push_back(face);
    add(face);
  }

  // create triangles using unique vertices
  double eps = norm(SVector3(bbox.max(), bbox.min())) * tolerance;
  std::vector<MVertex *> vertices;
  for(unsigned int i = 0; i < points.size(); i++)
    for(unsigned int j = 0; j < points[i].size(); j++)
      vertices.push_back(
        new MVertex(points[i][j].x(), points[i][j].y(), points[i][j].z()));
  MVertexRTree pos(eps);
  pos.insert(vertices);

  std::set<MFace, Less_Face> unique;
  int nbDuplic = 0;
  for(unsigned int i = 0; i < points.size(); i++) {
    for(unsigned int j = 0; j < points[i].size(); j += 3) {
      MVertex *v[3];
      for(int k = 0; k < 3; k++) {
        double x = points[i][j + k].x();
        double y = points[i][j + k].y();
        double z = points[i][j + k].z();
        v[k] = pos.find(x, y, z);
      }
      // FIXME: is this unicity test really useful? it slows down large STL
      // reads. It would be better to provide an API to detect/remove duplicate
      // elements
      MFace mf(v[0], v[1], v[2]);
      if(unique.find(mf) == unique.end()) {
        faces[i]->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
        unique.insert(mf);
      }
      else {
        nbDuplic++;
      }
    }
  }
  if(nbDuplic) Msg::Warning("%d duplicate triangles in STL file", nbDuplic);

  _associateEntityWithMeshVertices();

  _storeVerticesInEntities(vertices); // will delete unused vertices

  _createGeometryOfDiscreteEntities();

  fclose(fp);
  return 1;
}

int GModel::writeSTL(const std::string &name, bool binary, bool saveAll,
                     double scalingFactor)
{
  FILE *fp = Fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  bool useGeoSTL = false;
  unsigned int nfacets = 0;
  for(fiter it = firstFace(); it != lastFace(); ++it) {
    if(saveAll || (*it)->physicals.size()) {
      nfacets += (*it)->triangles.size() + 2 * (*it)->quadrangles.size();
    }
  }
  if(!nfacets) { // use CAD STL if there is no mesh
    useGeoSTL = true;
    for(fiter it = firstFace(); it != lastFace(); ++it) {
      (*it)->buildSTLTriangulation();
      if(saveAll || (*it)->physicals.size()) {
        nfacets += (*it)->stl_triangles.size() / 3;
      }
    }
  }

  if(!binary) {
    fprintf(fp, "solid Created by Gmsh\n");
  }
  else {
    char header[80];
    strncpy(header, "Created by Gmsh", 80);
    fwrite(header, sizeof(char), 80, fp);
    fwrite(&nfacets, sizeof(unsigned int), 1, fp);
  }

  for(fiter it = firstFace(); it != lastFace(); ++it) {
    if(saveAll || (*it)->physicals.size()) {
      if(useGeoSTL && (*it)->stl_vertices_uv.size()) {
        for(unsigned int i = 0; i < (*it)->stl_triangles.size(); i += 3) {
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
          normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2],
                        n);
          if(!binary) {
            fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
            fprintf(fp, "  outer loop\n");
            for(int j = 0; j < 3; j++)
              fprintf(fp, "    vertex %g %g %g\n", x[j] * scalingFactor,
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
        for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
          (*it)->triangles[i]->writeSTL(fp, binary, scalingFactor);
        for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
          (*it)->quadrangles[i]->writeSTL(fp, binary, scalingFactor);
      }
    }
  }

  if(!binary) fprintf(fp, "endsolid Created by Gmsh\n");

  fclose(fp);
  return 1;
}
