// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle and Jeremy Theler
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
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

static void writeX3dHeader(FILE *fp, std::vector<std::string> &metadata)
{
  // X3D Header
  fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  fprintf(fp, "<!DOCTYPE X3D PUBLIC \"ISO//Web3D//DTD X3D 3.3//EN\" "
              "\"http://www.web3d.org/specifications/x3d-3.3.dtd\">\n");
  fprintf(fp, "<X3D profile='Interchange' version='3.3'  "
              "xmlns:xsd='http://www.w3.org/2001/XMLSchema-instance' >\n");
  fprintf(fp, "  <head>\n");
  fprintf(fp, "    <meta name='creator' content='gmsh'/> \n");
  for(auto it = metadata.begin(); it != metadata.end(); ++it){
    fprintf(fp, "    <meta name='metadata_%s' content='%s'/> \n",
            std::to_string(std::distance(metadata.begin(), it)).c_str(),
            (*it).c_str());
  }
  fprintf(fp, "  </head>\n");
  fprintf(fp, "  <Scene>\n");
}

static void writeX3dTrailer(FILE *fp){
  fprintf(fp, "  </Scene>\n");
  fprintf(fp, "</X3D>\n");
}

static void writeX3dFaces(FILE *fp, std::vector<GFace *> &faces,
                          bool useIndexedSet, double scalingFactor,
                          const std::string &name,
                          bool useColor,
                          std::vector<unsigned int> &colors)
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

  if(!useColor){
    fprintf(fp, "    <Shape DEF=\"%s\">\n", name.c_str());
    fprintf(fp,
            "     <Appearance><Material DEF=\"mat%s\"></Material></Appearance>\n",
            name.c_str());
  }
  else{
    if(colors.size()==1){
      unsigned int cvalue = colors[0];
      float r = static_cast<float>(CTX::instance()->unpackRed(cvalue)) / 255.0;
      float g = static_cast<float>(CTX::instance()->unpackGreen(cvalue)) / 255.0;
      float b = static_cast<float>(CTX::instance()->unpackBlue(cvalue)) / 255.0;
      int a = CTX::instance()->unpackAlpha(cvalue);
      fprintf(fp, "    <Shape DEF=\"%s\">\n", name.c_str());
      fprintf(fp,
              "     <Appearance><Material DEF=\"mat%s\" id=\"color\" diffuseColor=\"%s %s %s\" shininess=\"0.9\" specularColor=\"0.2 0.2 0.2\" transparency=\"0\"></Material></Appearance>\n",
              name.c_str(),
              std::to_string(r).c_str(),
              std::to_string(g).c_str(),
              std::to_string(b).c_str());
    }
    else{
      std::cout << "Error in x3d coloring" << std::endl;
    }
  }

  if(useGeoSTL) {
    if(useIndexedSet) {
      // create faces with a list of nodes and a set of integers (no
      // floating-point data will be duplicated)
      fprintf(fp, "     <IndexedTriangleSet DEF=\"set%s\" index=\"\n",
              name.c_str());
      for(auto it = faces.begin(); it != faces.end(); ++it) {
        if((*it)->stl_triangles.size()) {
          for(std::size_t i = 0; i < (*it)->stl_triangles.size(); i++) {
            fprintf(fp, "%d ", (*it)->stl_triangles[i]);
          }
          fprintf(fp, "\n");
        }
      }
      fprintf(fp, "\">\n");

      fprintf(fp, "      <Coordinate point=\"\n");
      for(auto it = faces.begin(); it != faces.end(); ++it) {
        if((*it)->stl_vertices_uv.size()) {
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
      for(auto it = faces.begin(); it != faces.end(); ++it) {
        if((*it)->stl_normals.size()) {
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
      for(auto it = faces.begin(); it != faces.end(); ++it) {
        if((*it)->stl_vertices_uv.size()) {
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
      for(auto it = faces.begin(); it != faces.end(); ++it) {
        if((*it)->stl_normals.size()) {
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
  }
  else {
    fprintf(fp, "     <TriangleSet DEF=\"set%s\">\n", name.c_str());
    fprintf(fp, "      <Coordinate point=\"\n");
    for(auto it = faces.begin(); it != faces.end(); ++it) {
      for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
        (*it)->triangles[i]->writeX3D(fp, scalingFactor);
      for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++)
        (*it)->quadrangles[i]->writeX3D(fp, scalingFactor);
    }
    fprintf(fp, "\"></Coordinate>\n");
    fprintf(fp, "     </TriangleSet>\n");
  }

  fprintf(fp, "    </Shape>\n");
}

static void writeX3dEdges(FILE *fp, std::vector<GEdge *> &edges,
                          double scalingFactor, const std::string &name)
{
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    if((*it)->stl_vertices_xyz.size()) {
      fprintf(fp, "    <Shape DEF=\"%s\">\n", name.c_str());
      fprintf(fp,
              "     <Appearance><Material "
              "DEF=\"mat%s\"></Material><LineProperties "
              "id=\"prop%s\"></LineProperties></Appearance>\n",
              name.c_str(), name.c_str());
      fprintf(fp, "     <LineSet vertexCount=\"%ld\">\n",
              (*it)->stl_vertices_xyz.size());
      fprintf(fp, "      <Coordinate point=\"\n");
      for(std::size_t i = 0; i < (*it)->stl_vertices_xyz.size(); i++) {
        SPoint3 &p((*it)->stl_vertices_xyz[i]);

        fprintf(fp, "%g %g %g\n", p.x() * scalingFactor, p.y() * scalingFactor,
                p.z() * scalingFactor);
      }
      fprintf(fp, "\"/>\n");
      fprintf(fp, "     </LineSet>\n");
      fprintf(fp, "    </Shape>\n");
    }
    else {
      Msg::Warning("X3D not implemented yet without STL");
    }
  }
}

int GModel::_writeX3dFile(FILE* fp, bool saveAll,
                     double scalingFactor, int x3dsurfaces, int x3dedges,
                     int x3dvertices, std::vector<GFace *>& customFaces)
{
  if(noPhysicalGroups()) saveAll = true;

  /*if(customFaces.size() > 0){
    //fiter first_face = firstFace();
    //fiter last_face = lastFace();
    fiter it = firstFace();
    fiter end = lastFace();
  }
  else{
    //std::vector<GFace *>::iterator first_face = customFaces.begin();
    //std::vector<GFace *>::iterator last_face = customFaces.end();
    std::vector<GFace *>::iterator it = customFaces.begin();
    std::vector<GFace *>::iterator end = customFaces.end();
  }*/
  std::vector<GFace *> modelFaces;
  if(customFaces.size() > 0)
  {
    for(auto it = customFaces.begin(); it != customFaces.end(); ++it){
      modelFaces.push_back(*it);
    }
  }
  else{
    for(auto it = firstFace(); it != lastFace(); ++it){
      modelFaces.push_back(*it);
    }
  }

  if(x3dsurfaces != 0) {
    fprintf(fp, "   <Group DEF=\"faces\">\n");
    if(x3dsurfaces == 1) {
      // all surfaces in a single x3d object
      std::vector<GFace *> faces;
      std::vector<unsigned int> colors;
      //for(auto it = first_face; it != last_face; ++it) {
      for(auto it = modelFaces.begin(); it != modelFaces.end(); ++it) {
        if(saveAll || (*it)->physicals.size()) { faces.push_back(*it); }
      }
      std::string name = "face";
      writeX3dFaces(fp, faces, false, scalingFactor, name, false, colors);
    }
    else if(x3dsurfaces == 2) {
      // one x3d object for each physical surface
      //for(auto it = first_face; it != last_face; ++it) {
      for(auto it = modelFaces.begin(); it != modelFaces.end(); ++it) {
        if(saveAll || (*it)->physicals.size()) {
          std::vector<GFace *> faces(1, *it);
          std::vector<unsigned int> colors;
          std::string name = getElementaryName(2, (*it)->tag());
          // get color info
          GEntity *ge = GModel::current()->getEntityByTag(2, (*it)->tag());
          unsigned int cvalue = ge->getColor();
          colors.push_back(cvalue);
          if(name.empty()) {
            std::ostringstream s;
            s << "face" << (*it)->tag();
            name = s.str();
          }
          writeX3dFaces(fp, faces, true, scalingFactor, name, true, colors);
        }
      }
    }
    else if(x3dsurfaces == 3) {
      // one x3d object per physical surface
      std::map<int, std::vector<GEntity *> > phys;
      std::vector<unsigned int> colors;
      getPhysicalGroups(2, phys);
      for(auto it = phys.begin(); it != phys.end(); it++) {
        std::vector<GFace *> faces;
        for(std::size_t i = 0; i < it->second.size(); i++) {
          faces.push_back(static_cast<GFace *>(it->second[i]));
        }
        std::string name = getPhysicalName(2, it->first);
        if(name.empty()) {
          std::ostringstream s;
          s << "physicalsurface" << it->first;
          name = s.str();
        }
        writeX3dFaces(fp, faces, false, scalingFactor, name, false, colors);
      }
    }

    fprintf(fp, "   </Group>\n");
  }

  // edges
  if(x3dedges != 0) {
    fprintf(fp, "   <Group DEF=\"edges\">\n");
    if(x3dedges == 1) {
      // all edges in a single x3d object
      std::vector<GEdge *> edges;
      for(auto it = firstEdge(); it != lastEdge(); ++it) {
        if(saveAll || (*it)->physicals.size()) { edges.push_back(*it); }
      }
      std::string name = "edge";
      writeX3dEdges(fp, edges, scalingFactor, name);
    }
    else if(x3dedges == 2) {
      // one x3d object for each physical edge
      for(auto it = firstEdge(); it != lastEdge(); ++it) {
        if(saveAll || (*it)->physicals.size()) {
          std::vector<GEdge *> edges(1, *it);
          std::string name = getElementaryName(1, (*it)->tag());
          if(name.empty()) {
            std::ostringstream s;
            s << "edge" << (*it)->tag();
            name = s.str();
          }
          writeX3dEdges(fp, edges, scalingFactor, name);
        }
      }
    }
    else if(x3dedges == 3) {
      // one x3d object per physical edge
      std::map<int, std::vector<GEntity *> > phys;
      getPhysicalGroups(1, phys);
      for(auto it = phys.begin(); it != phys.end(); it++) {
        std::vector<GEdge *> edges;
        for(std::size_t i = 0; i < it->second.size(); i++) {
          edges.push_back(static_cast<GEdge *>(it->second[i]));
        }
        std::string name = getPhysicalName(1, it->first);
        if(name.empty()) {
          std::ostringstream s;
          s << "physicaledge" << it->first;
          name = s.str();
        }
        writeX3dEdges(fp, edges, scalingFactor, name);
      }
    }
    fprintf(fp, "   </Group>\n");
  }

  // vertices
  if(x3dvertices != 0) {
    fprintf(fp, "   <Group DEF=\"vertices\" render=\"false\">\n");

    for(auto it = firstVertex(); it != lastVertex(); ++it) {
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
  return 1;
}

static std::string TagFileName(std::string const & name, int tag)
{
  std::vector<std::string> split = SplitFileName(name); //<path>/<name>.<ext>
  std::string new_name = split[1] + "_" + std::to_string(tag);
  return split[0] + new_name + split[2];
}

int GModel::writeX3D(const std::string &name, bool saveAll,
                     double scalingFactor, int x3dsurfaces, int x3dedges,
                     int x3dvertices, int x3dvolumes)
{
  FILE *fp;
  std::vector<std::string> metadata;
  if(x3dsurfaces == 0 && x3dedges == 0 && x3dvertices == 0) {
    Msg::Info("no surfaces, edges or vertices to write into '%s'",
              name.c_str());
    return 0;
  }

  std::vector<GFace *> faces;
  if(x3dvolumes == 1) {
    Msg::Info("separating volumes into separate files");
    std::vector<GEntity *> volumes;
    getEntities(volumes, 3);
    
    // if volumes present in model, else continue to single file mode
    if(volumes.size() > 0){
      for(auto it = volumes.begin(); it != volumes.end(); ++it){
        faces = (*it)->bindingsGetFaces();
        std::string _vol_name = getElementaryName((*it)->dim(), (*it)->tag());
        metadata.push_back(_vol_name);
        std::string _filename = TagFileName(name, (*it)->tag());
        fp = Fopen(_filename.c_str(), "w");
        if(!fp) {
          Msg::Warning("Unable to open file '%s'", name.c_str());
          return 0;
        }
        writeX3dHeader(fp,metadata);
        _writeX3dFile(fp, saveAll, scalingFactor, x3dsurfaces, x3dedges, x3dvertices, faces);
        writeX3dTrailer(fp);
        fclose(fp);
        metadata.clear();
      }
      return 1;
    }
  }

  Msg::Info("writing single file");
  fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Warning("Unable to open file '%s'", name.c_str());
    return 0;
  }
  writeX3dHeader(fp,metadata);
  // main write function
  _writeX3dFile(fp, saveAll, scalingFactor, x3dsurfaces, x3dedges, x3dvertices, faces);
  writeX3dTrailer(fp);
  fclose(fp);

  // X3D Header
  /*fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  fprintf(fp, "<!DOCTYPE X3D PUBLIC \"ISO//Web3D//DTD X3D 3.3//EN\" "
              "\"http://www.web3d.org/specifications/x3d-3.3.dtd\">\n");
  fprintf(fp, "<X3D profile='Interchange' version='3.3'  "
              "xmlns:xsd='http://www.w3.org/2001/XMLSchema-instance' >\n");
  fprintf(fp, "  <head>\n");
  fprintf(fp, "    <meta name='creator' content='gmsh'/> \n");
  fprintf(fp, "  </head>\n");
  fprintf(fp, "  <Scene>\n");
  */

  return 1;
}
