// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle and Jeremy Theler
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jeremy Theler

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

static void writeX3Dfaces(FILE *fp, std::vector<GFace *> &faces,
                          bool useIndexedSet, double scalingFactor,
                          const std::string &name)
{
  bool useGeoX3D = false;
  unsigned int nfacets = 0;
  for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
      ++it) {
    nfacets += (*it)->triangles.size() + 2 * (*it)->quadrangles.size();
  }
  if(!nfacets) { // use CAD X3D if there is no mesh
    useGeoX3D = true;
    for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
        ++it) {
      (*it)->buildSTLTriangulation();
      nfacets += (*it)->stl_triangles.size() / 3;
    }
  }

  fprintf(fp, "    <Shape DEF=\"%s\">\n", name.c_str());
  fprintf(fp,
          "     <Appearance><Material DEF=\"mat%s\"></Material></Appearance>\n",
          name.c_str());

  if(useIndexedSet) {
    // create faces with a list of nodes and a set of integers (no
    // floating-point data will be duplicated)
    fprintf(fp, "     <IndexedTriangleSet DEF=\"set%s\" index=\"\n",
            name.c_str());
    for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
        ++it) {
      if(useGeoX3D && (*it)->stl_triangles.size()) {
        for(std::size_t i = 0; i < (*it)->stl_triangles.size(); i++) {
          fprintf(fp, "%d ", (*it)->stl_triangles[i]);
        }
        fprintf(fp, "\n");
      }
    }
    fprintf(fp, "\">\n");

    fprintf(fp, "      <Coordinate point=\"\n");
    for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
        ++it) {
      if(useGeoX3D && (*it)->stl_vertices_uv.size()) {
        for(std::size_t i = 0; i < (*it)->stl_vertices_uv.size(); i++) {
          SPoint2 &p((*it)->stl_vertices_uv[i]);
          GPoint gp = (*it)->point(p);

          fprintf(fp, "%g %g %g\n", gp.x() * scalingFactor,
                  gp.y() * scalingFactor, gp.z() * scalingFactor);
        }
      }
      else {
        Msg::Warning("X3D not implemented yet without STL");
      }
    }
    fprintf(fp, "\"></Coordinate>\n");

    fprintf(fp, "      <Normal vector=\"\n");
    for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
        ++it) {
      if(useGeoX3D && (*it)->stl_normals.size()) {
        for(std::size_t i = 0; i < (*it)->stl_normals.size(); i++) {
          SVector3 &n((*it)->stl_normals[i]);
          fprintf(fp, "%g %g %g\n", n.x(), n.y(), n.z());
        }
      }
      else {
        Msg::Warning("X3D not implemented yet without STL");
      }
    }
    fprintf(fp, "\"></Normal>\n");

    fprintf(fp, "     </IndexedTriangleSet>\n");
  }
  else {
    // create faces with a explicit list or vertices (will duplicate
    // floating-point data)
    fprintf(fp, "     <TriangleSet DEF=\"set%s\">\n", name.c_str());

    fprintf(fp, "      <Coordinate point=\"\n");
    for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
        ++it) {
      if(useGeoX3D && (*it)->stl_vertices_uv.size()) {
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

          for(int j = 0; j < 3; j++) {
            fprintf(fp, "%g %g %g\n", x[j] * scalingFactor,
                    y[j] * scalingFactor, z[j] * scalingFactor);
          }
        }
      }
      else {
        Msg::Warning("X3D not implemented yet without STL");
      }
    }
    fprintf(fp, "\"></Coordinate>\n");

    fprintf(fp, "      <Normal vector=\"\n");
    for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
        ++it) {
      if(useGeoX3D && (*it)->stl_normals.size()) {
        for(std::size_t i = 0; i < (*it)->stl_triangles.size(); i++) {
          SVector3 &n((*it)->stl_normals[(*it)->stl_triangles[i]]);
          fprintf(fp, "%g %g %g\n", n.x(), n.y(), n.z());
        }
      }
      else {
        Msg::Warning("X3D not implemented yet without STL");
      }
    }
    fprintf(fp, "\"></Normal>\n");

    fprintf(fp, "     </TriangleSet>\n");
  }

  fprintf(fp, "    </Shape>\n");
}

int GModel::writeX3D(const std::string &name, bool saveAll,
                     double scalingFactor, int oneSolidPerSurface)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // X3D Header
  fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  fprintf(fp, "<!DOCTYPE X3D PUBLIC \"ISO//Web3D//DTD X3D 3.3//EN\" "
              "\"http://www.web3d.org/specifications/x3d-3.3.dtd\">\n");
  fprintf(fp, "<X3D profile='Interchange' version='3.3'  "
              "xmlns:xsd='http://www.w3.org/2001/XMLSchema-instance' >\n");
  fprintf(fp, "  <head>\n");
  fprintf(fp, "    <meta name='creator' content='gmsh'/> \n");
  fprintf(fp, "  </head>\n");
  fprintf(fp, "  <Scene>\n");

  fprintf(fp, "   <Group DEF=\"faces\">\n");

  if(noPhysicalGroups()) saveAll = true;

  if(oneSolidPerSurface == 1) { // one x3d node per surface
    for(fiter it = firstFace(); it != lastFace(); ++it) {
      if(saveAll || (*it)->physicals.size()) {
        std::vector<GFace *> faces(1, *it);
        std::string name = getElementaryName(2, (*it)->tag());
        if(name.empty()) {
          std::ostringstream s;
          s << "face" << (*it)->tag();
          name = s.str();
        }
        writeX3Dfaces(fp, faces, true, scalingFactor, name);
      }
    }
  }
  else if(oneSolidPerSurface == 2) { // one x3d node  per physical surface
    std::map<int, std::vector<GEntity *> > phys;
    getPhysicalGroups(2, phys);
    for(std::map<int, std::vector<GEntity *> >::iterator it = phys.begin();
        it != phys.end(); it++) {
      std::vector<GFace *> faces;
      for(std::size_t i = 0; i < it->second.size(); i++) {
        faces.push_back(static_cast<GFace *>(it->second[i]));
      }
      std::string name = getPhysicalName(2, it->first);
      if(name.empty()) {
        std::ostringstream s;
        s << "physical" << it->first;
        name = s.str();
      }
      writeX3Dfaces(fp, faces, false, scalingFactor, name);
    }
  }
  else { // everything into one single x3d node
    std::vector<GFace *> faces;
    for(fiter it = firstFace(); it != lastFace(); ++it) {
      if(saveAll || (*it)->physicals.size()) { faces.push_back(*it); }
    }
    std::string name = "f";
    writeX3Dfaces(fp, faces, false, scalingFactor, name);
  }

  fprintf(fp, "   </Group>\n");

  // vertices
  if(true) {
    fprintf(fp, "   <Group DEF=\"vertices\" render=\"false\">\n");
    for(viter it = firstVertex(); it != lastVertex(); ++it) {
      fprintf(fp, "   <Transform DEF=\"vertex%d\" translation=\"%g %g %g\">\n",
              (*it)->tag(), (*it)->x(), (*it)->y(), (*it)->z());
      fprintf(fp, "    <Shape>\n");
      fprintf(fp,
              "     <Appearance><Material "
              "DEF=\"matvertex%d\"></Material></Appearance>\n",
              (*it)->tag());
      fprintf(fp, "     <Sphere></Sphere>\n");
      fprintf(fp, "    </Shape>\n");
      fprintf(fp, "   </Transform>\n");
    }
    fprintf(fp, "   </Group>\n");
  }

  fprintf(fp, "  </Scene>\n");
  fprintf(fp, "</X3D>\n");

  fclose(fp);
  return 1;
}
