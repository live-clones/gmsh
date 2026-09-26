// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
// Contributor(s):
//   Tristan Carrier
//   Maxime Melchior

#include <vector>
#include <fstream>
#include <algorithm>
#include "GmshConfig.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "MElement.h"
#include "VoroMetal.h"

std::string GMSH_VoroMetalPlugin::getHelp() const
{
  return "Plugin(VoroMetal) creates microstructures using Voronoi "
         "diagrams.\n\n";
}

#if defined(HAVE_MESH) && defined(HAVE_VOROPP)

#include "meshGRegion.h"
#include "voro++.hh"

GMSH_VoroMetalPlugin::GMSH_VoroMetalPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "ComputeBestSeeds", nullptr, 0., ""},
                     {GMSH_FULLRC, "ComputeMicrostructure", nullptr, 1., ""}},
                    {
                      {GMSH_FULLRC, "SeedsFile", nullptr, "seeds.txt", ""},
                    })
{
}

using namespace voro;

void voroMetal3D::execute(std::vector<double> &properties, int radical,
                          double h, double xMax, double yMax, double zMax)
{
  std::size_t i;
  std::vector<SPoint3> vertices;
  std::vector<double> radii;
  for(i = 0; i < properties.size() / 4; i++) {
    vertices.push_back(
      SPoint3(properties[4 * i], properties[4 * i + 1], properties[4 * i + 2]));
    radii.push_back(properties[4 * i + 3]);
  }
  execute(vertices, radii, radical, h, xMax, yMax, zMax);
}

void voroMetal3D::execute(std::vector<SPoint3> &vertices,
                          std::vector<double> &radii, int radical, double h,
                          double xMax, double yMax, double zMax)
{
  std::size_t i;
  std::size_t j;
  std::size_t k;
  int start;
  std::size_t end;
  int index1;
  int index2;
  int val;
  int face_number;
  int last;
  int mem;
  int number;
  double x, y, z;
  double x1, y1, z1;
  double x2, y2, z2;
  double delta;
  double min_x, max_x;
  double min_y, max_y;
  double min_z, max_z;
  double min_area;
  voronoicell_neighbor *pointer;
  voronoicell_neighbor cell;
  std::vector<int> faces;
  std::vector<double> voronoi_vertices;
  std::vector<voronoicell_neighbor *> pointers;
  std::vector<SPoint3> generators;
  std::vector<int> temp;
  std::vector<int> temp2;
  std::vector<double> areas;
  std::map<int, int> table;
  geo_cell obj;

  if(vertices.empty()) return;

  min_x = 1000000000.0;
  max_x = -1000000000.0;
  min_y = 1000000000.0;
  max_y = -1000000000.0;
  min_z = 1000000000.0;
  max_z = -1000000000.0;
  for(i = 0; i < vertices.size(); i++) {
    min_x = std::min(vertices[i].x(), min_x);
    max_x = std::max(vertices[i].x(), max_x);
    min_y = std::min(vertices[i].y(), min_y);
    max_y = std::max(vertices[i].y(), max_y);
    min_z = std::min(vertices[i].z(), min_z);
    max_z = std::max(vertices[i].z(), max_z);
  }

  delta = 0.2 * (max_x - min_x);
  min_x = min_y = min_z = 0;
  // max_x=max_y=max_z = 1;
  max_x = xMax;
  max_y = yMax;
  max_z = zMax;
  delta = 0;

  container contA(min_x - delta, max_x + delta, min_y - delta, max_y + delta,
                  min_z - delta, max_z + delta, 6, 6, 6, true, true, true,
                  vertices.size());
  container_poly contB(min_x - delta, max_x + delta, min_y - delta,
                       max_y + delta, min_z - delta, max_z + delta, 6, 6, 6,
                       true, true, true, vertices.size());

  for(i = 0; i < vertices.size(); i++) {
    if(radical == 0) {
      contA.put(i, vertices[i].x(), vertices[i].y(), vertices[i].z());
    }
    else {
      contB.put(i, vertices[i].x(), vertices[i].y(), vertices[i].z(), radii[i]);
    }
  }

  number = 0;

  c_loop_all loopA(contA);
  c_loop_all loopB(contB);

  if(radical == 0) {
    loopA.start();
    do {
      contA.compute_cell(cell, loopA);
      loopA.pos(x, y, z);
      pointer = new voronoicell_neighbor();
      *pointer = cell;
      pointers.push_back(pointer);
      generators.push_back(SPoint3(x, y, z));
      table.insert(std::make_pair(loopA.pid(), number));
      number++;
    } while(loopA.inc());
  }
  else {
    loopB.start();
    do {
      contB.compute_cell(cell, loopB);
      loopB.pos(x, y, z);
      pointer = new voronoicell_neighbor();
      *pointer = cell;
      pointers.push_back(pointer);
      generators.push_back(SPoint3(x, y, z));
      table.insert(std::make_pair(loopB.pid(), number));
      number++;
    } while(loopB.inc());
  }

  std::ofstream file6("table.txt");
  if(!file6.is_open()) {
    Msg::Error("Could not open file 'table.txt'");
    return;
  }

  for(i = 0; i < vertices.size(); i++) {
    file6 << i + 1 << " " << table[i] + 1 << "\n";
  }

  initialize_counter();

  min_area = 1000000000.0;

  for(i = 0; i < pointers.size(); i++) {
    areas.clear();
    pointers[i]->face_areas(areas);
    for(j = 0; j < areas.size(); j++) {
      if(areas[j] < min_area) { min_area = areas[j]; }
    }
  }

  std::ofstream file("MicrostructurePolycrystal3D.pos");
  if(!file.is_open()) {
    Msg::Error("Could not open file 'MicrostructurePolycrystal3D.pos'");
    return;
  }
  file << "View \"test\" {\n";

  std::ofstream file2("MicrostructurePolycrystal3D.geo");
  if(!file2.is_open()) {
    Msg::Error("Could not open file 'MicrostructurePolycrystal3D.geo'");
    return;
  }
  std::ofstream file5("SET.map");
  if(!file5.is_open()) {
    Msg::Error("Could not open file 'SET.map'");
    return;
  }
  file2 << "c=" << h << ";\n";
  int countPeriodSurf = 0;
  int countVolume = 0;
  for(i = 0; i < pointers.size(); i++) {
    obj = geo_cell();
    faces.clear();
    voronoi_vertices.clear();
    pointers[i]->face_vertices(faces);
    pointers[i]->vertices(generators[i].x(), generators[i].y(),
                          generators[i].z(), voronoi_vertices);
    obj.line_loops.resize(pointers[i]->number_of_faces());
    obj.orientations.resize(pointers[i]->number_of_faces());
    face_number = 0;
    end = 0;
    while(end < faces.size()) {
      start = end + 1;
      end = start + faces[end];
      for(j = start; j < end; j++) {
        if(j < end - 1) {
          index1 = faces[j];
          index2 = faces[j + 1];
        }
        else {
          index1 = faces[end - 1];
          index2 = faces[start];
        }
        x1 = voronoi_vertices[3 * index1];
        y1 = voronoi_vertices[3 * index1 + 1];
        z1 = voronoi_vertices[3 * index1 + 2];
        x2 = voronoi_vertices[3 * index2];
        y2 = voronoi_vertices[3 * index2 + 1];
        z2 = voronoi_vertices[3 * index2 + 2];
        print_segment(SPoint3(x1, y1, z1), SPoint3(x2, y2, z2), file);

        val = obj.search_line(std::make_pair(index1, index2));
        if(val == -1) {
          obj.lines.push_back(std::make_pair(index1, index2));
          obj.line_loops[face_number].push_back(obj.lines.size() - 1);
          val = obj.lines.size() - 1;
        }
        else {
          obj.line_loops[face_number].push_back(val);
        }

        last = obj.line_loops[face_number].size() - 1;
        if(last == 0) { obj.orientations[face_number].push_back(0); }
        else if(obj.lines[obj.line_loops[face_number][last - 1]].second ==
                obj.lines[val].first) {
          obj.orientations[face_number][last - 1] = 0;
          obj.orientations[face_number].push_back(0);
        }
        else if(obj.lines[obj.line_loops[face_number][last - 1]].first ==
                obj.lines[val].first) {
          obj.orientations[face_number][last - 1] = 1;
          obj.orientations[face_number].push_back(0);
        }
        else if(obj.lines[obj.line_loops[face_number][last - 1]].second ==
                obj.lines[val].second) {
          obj.orientations[face_number][last - 1] = 0;
          obj.orientations[face_number].push_back(1);
        }
        else {
          obj.orientations[face_number][last - 1] = 1;
          obj.orientations[face_number].push_back(1);
        }
      }

      face_number++;
    }

    for(j = 0; j < voronoi_vertices.size() / 3; j++) {
      print_geo_point(get_counter(), voronoi_vertices[3 * j],
                      voronoi_vertices[3 * j + 1], voronoi_vertices[3 * j + 2],
                      file2);
      obj.points2.push_back(get_counter());
      increase_counter();
    }

    for(j = 0; j < obj.lines.size(); j++) {
      print_geo_line(get_counter(), obj.points2[obj.lines[j].first],
                     obj.points2[obj.lines[j].second], file2);
      obj.lines2.push_back(get_counter());
      increase_counter();
    }

    for(j = 0; j < obj.line_loops.size(); j++) {
      temp.clear();
      temp2.clear();
      for(k = 0; k < obj.line_loops[j].size(); k++) {
        temp.push_back(obj.lines2[obj.line_loops[j][k]]);
        temp2.push_back(obj.orientations[j][k]);
      }
      print_geo_line_loop(get_counter(), temp, temp2, file2);
      obj.line_loops2.push_back(get_counter());
      increase_counter();
    }

    for(j = 0; j < obj.line_loops2.size(); j++) {
      print_geo_face(get_counter(), obj.line_loops2[j], file2);
      countPeriodSurf++;
      file5 << get_counter() << "\t"
            << "SURFACE" << get_counter() << "\t"
            << "NSET\n";
      obj.faces2.push_back(get_counter());
      increase_counter();
    }

    print_geo_face_loop(get_counter(), obj.faces2, file2);
    obj.face_loops2 = get_counter();
    increase_counter();

    print_geo_volume(get_counter(), obj.face_loops2, file2);
    mem = get_counter();
    countVolume++;
    file5 << get_counter() << "\t"
          << "GRAIN" << countVolume << "\t"
          << "ELSET\n";
    increase_counter();
    print_geo_physical_volume(get_counter(), mem, file2);
    increase_counter();
  }

  file2 << "Coherence;\n";
  file << "};\n";

  for(i = 0; i < pointers.size(); i++) delete pointers[i];
}

void voroMetal3D::print_segment(SPoint3 p1, SPoint3 p2, std::ofstream &file)
{
  file << "SL (" << p1.x() << ", " << p1.y() << ", " << p1.z() << ", " << p2.x()
       << ", " << p2.y() << ", " << p2.z() << "){10, 20};\n";
}

void voroMetal3D::initialize_counter() { counter = 12; }

void voroMetal3D::increase_counter() { counter = counter + 1; }

int voroMetal3D::get_counter() { return counter; }

void voroMetal3D::print_geo_point(int index, double x, double y, double z,
                                  std::ofstream &file)
{
  file.precision(17);

  file << "Point(" << index << ")={" << x << "," << y << "," << z << ",c};\n";
}

void voroMetal3D::print_geo_line(int index1, int index2, int index3,
                                 std::ofstream &file)
{
  file << "Line(" << index1 << ")={" << index2 << "," << index3 << "};\n";
}

void voroMetal3D::print_geo_face(int index1, int index2, std::ofstream &file)
{
  file << "Plane Surface(" << index1 << ")={" << index2 << "};\n";
}

void voroMetal3D::print_geo_volume(int index1, int index2, std::ofstream &file)
{
  file << "Volume(" << index1 << ")={" << index2 << "};\n";
}

void voroMetal3D::print_geo_physical_volume(int index1, int index2,
                                            std::ofstream &file)
{
  file << "Physical Volume(" << index1 << ")={" << index2 << "};\n";
}

void voroMetal3D::print_geo_line_loop(int index, std::vector<int> &indices,
                                      std::vector<int> &orientations,
                                      std::ofstream &file)
{
  std::size_t i;
  file << "Curve Loop(" << index << ")={";
  for(i = 0; i < indices.size(); i++) {
    if(orientations[i] == 1) file << "-";
    file << indices[i];
    if(i < indices.size() - 1) file << ",";
  }
  file << "};\n";
}

void voroMetal3D::print_geo_face_loop(int index, std::vector<int> &indices,
                                      std::ofstream &file)
{
  std::size_t i;
  file << "Surface Loop(" << index << ")={";
  for(i = 0; i < indices.size(); i++) {
    file << indices[i];
    if(i < indices.size() - 1) file << ",";
  }
  file << "};\n";
}

void voroMetal3D::correspondence(double e, double xMax, double yMax,
                                 double zMax)
{
  std::size_t i;
  std::size_t j;
  int count;
  int val;
  bool flag;
  bool flag1;
  bool flag2;
  bool flag3;
  bool flag4;
  double x, y, z;
  double delta_x;
  double delta_y;
  double delta_z;
  SPoint3 p1;
  SPoint3 p2;
  GFace *gf;
  GFace *gf1;
  GFace *gf2;
  GVertex *v1;
  GVertex *v2;
  GVertex *v3;
  GVertex *v4;
  GModel *model = GModel::current();
  GModel::fiter it;
  std::vector<GFace *> faces;
  std::vector<std::pair<GFace *, GFace *> > pairs;
  std::vector<int> categories;
  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges1;
  std::vector<GEdge *> edges2;
  std::map<GFace *, SPoint3> centers;
  std::map<GFace *, bool> markings;
  std::vector<GVertex *>::iterator it2;
  std::map<GFace *, SPoint3>::iterator it3;
  std::map<GFace *, SPoint3>::iterator it4;
  std::map<GFace *, bool>::iterator it5;
  std::map<GFace *, bool>::iterator it6;
  std::vector<GEdge *>::iterator it7;
  std::vector<GEdge *>::iterator it8;

  faces.clear();

  for(it = model->firstFace(); it != model->lastFace(); it++) {
    gf = *it;
    if(gf->numRegions() == 1) { faces.push_back(gf); }
  }

  centers.clear();
  markings.clear();
  pairs.clear();
  categories.clear();

  for(i = 0; i < faces.size(); i++) {
    x = 0.0;
    y = 0.0;
    z = 0.0;
    vertices.clear();
    vertices = faces[i]->vertices();
    for(it2 = vertices.begin(); it2 != vertices.end(); it2++) {
      x = x + (*it2)->x();
      y = y + (*it2)->y();
      z = z + (*it2)->z();
    }
    x = x / vertices.size();
    y = y / vertices.size();
    z = z / vertices.size();
    centers.insert(std::make_pair(faces[i], SPoint3(x, y, z)));
  }

  for(i = 0; i < faces.size(); i++) {
    markings.insert(std::make_pair(faces[i], false));
  }

  count = 0;
  std::ofstream file("MicrostructurePolycrystal3D.pos");
  if(!file.is_open()) {
    Msg::Error("Could not open file 'MicrostructurePolycrystal3D.pos'");
    return;
  }
  file << "View \"test\" {\n";

  std::ofstream file2("PERIODIC.map");
  if(!file2.is_open()) {
    Msg::Error("Could not open file 'PERIODIC.map'");
    return;
  }

  for(i = 0; i < faces.size(); i++) {
    for(j = 0; j < faces.size(); j++) {
      it3 = centers.find(faces[i]);
      it4 = centers.find(faces[j]);
      p1 = it3->second;
      p2 = it4->second;
      delta_x = std::abs(p2.x() - p1.x());
      delta_y = std::abs(p2.y() - p1.y());
      delta_z = std::abs(p2.z() - p1.z());
      flag =
        correspondence(delta_x, delta_y, delta_z, e, val, xMax, yMax, zMax);
      if(flag) {
        it5 = markings.find(faces[i]);
        it6 = markings.find(faces[j]);
        if(it5->second == 0 && it6->second == 0) {
          it5->second = 1;
          it6->second = 1;
          pairs.push_back(std::make_pair(faces[i], faces[j]));
          categories.push_back(val);
          print_segment(p1, p2, file);
          if(std::abs((p2.x() - p1.x() - 1.0)) < 0.0001) {
            if(std::abs((p2.y() - p1.y())) < 0.0001) {
              if(std::abs((p2.z() - p1.z())) < 0.0001) {
                file2 << "NSET\tFRONT = FRONT + SURFACE" << faces[j]->tag()
                      << "\n";
                file2 << "NSET\tBACK = BACK + SURFACE" << faces[i]->tag()
                      << "\n";
              }
              else if(std::abs((p2.z() - p1.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"
                      << faces[i]->tag() << "\n";
              }
              else if(std::abs((p1.z() - p2.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tBACKTOP = BACKTOP + SURFACE" << faces[i]->tag()
                      << "\n";
              }
            }
            else if(std::abs((p2.y() - p1.y() - 1.0)) < 0.0001) {
              if(std::abs((p2.z() - p1.z())) < 0.0001) {
                file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"
                      << faces[i]->tag() << "\n";
              }
              else if(std::abs((p2.z() - p1.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"
                      << faces[i]->tag() << "\n";
              }
              else if(std::abs((p1.z() - p2.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"
                      << faces[i]->tag() << "\n";
              }
            }
            else if(std::abs((p1.y() - p2.y() - 1.0)) < 0.0001) {
              if(std::abs((p2.z() - p1.z())) < 0.0001) {
                file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"
                      << faces[i]->tag() << "\n";
              }
              else if(std::abs((p2.z() - p1.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"
                      << faces[i]->tag() << "\n";
              }
              else if(std::abs((p1.z() - p2.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"
                      << faces[i]->tag() << "\n";
              }
            }
          }
          else if(std::abs((p1.x() - p2.x() - 1.0)) < 0.0001) {
            if(std::abs((p2.y() - p1.y())) < 0.0001) {
              if(std::abs((p2.z() - p1.z())) < 0.0001) {
                file2 << "NSET\tFRONT = FRONT + SURFACE" << faces[i]->tag()
                      << "\n";
                file2 << "NSET\tBACK = BACK + SURFACE" << faces[j]->tag()
                      << "\n";
              }
              else if(std::abs((p2.z() - p1.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tBACKTOP = BACKTOP + SURFACE" << faces[j]->tag()
                      << "\n";
              }
              else if(std::abs((p1.z() - p2.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"
                      << faces[j]->tag() << "\n";
              }
            }
            else if(std::abs((p2.y() - p1.y() - 1.0)) < 0.0001) {
              if(std::abs((p2.z() - p1.z())) < 0.0001) {
                file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"
                      << faces[j]->tag() << "\n";
              }
              else if(std::abs((p2.z() - p1.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"
                      << faces[j]->tag() << "\n";
              }
              else if(std::abs((p1.z() - p2.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"
                      << faces[j]->tag() << "\n";
              }
            }
            else if(std::abs((p1.y() - p2.y() - 1.0)) < 0.0001) {
              if(std::abs((p2.z() - p1.z())) < 0.0001) {
                file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"
                      << faces[j]->tag() << "\n";
              }
              else if(std::abs((p2.z() - p1.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"
                      << faces[j]->tag() << "\n";
              }
              else if(std::abs((p1.z() - p2.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"
                      << faces[j]->tag() << "\n";
              }
            }
          }
          else if(std::abs((p1.x() - p2.x())) < 0.0001) {
            if(std::abs((p2.y() - p1.y() - 1.0)) < 0.0001) {
              if(std::abs((p2.z() - p1.z())) < 0.0001) {
                file2 << "NSET\tRIGHT = RIGHT + SURFACE" << faces[j]->tag()
                      << "\n";
                file2 << "NSET\tLEFT = LEFT + SURFACE" << faces[i]->tag()
                      << "\n";
              }
              else if(std::abs((p2.z() - p1.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"
                      << faces[i]->tag() << "\n";
              }
              else if(std::abs((p1.z() - p2.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"
                      << faces[j]->tag() << "\n";
                file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE" << faces[i]->tag()
                      << "\n";
              }
            }
            else if(std::abs((p1.y() - p2.y() - 1.0)) < 0.0001) {
              if(std::abs((p2.z() - p1.z())) < 0.0001) {
                file2 << "NSET\tRIGHT = RIGHT + SURFACE" << faces[i]->tag()
                      << "\n";
                file2 << "NSET\tLEFT = LEFT + SURFACE" << faces[j]->tag()
                      << "\n";
              }
              else if(std::abs((p2.z() - p1.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE" << faces[j]->tag()
                      << "\n";
              }
              else if(std::abs((p1.z() - p2.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"
                      << faces[i]->tag() << "\n";
                file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"
                      << faces[j]->tag() << "\n";
              }
            }
            else if(std::abs((p1.y() - p2.y())) < 0.0001) {
              if(std::abs((p2.z() - p1.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tTOP = TOP + SURFACE" << faces[j]->tag() << "\n";
                file2 << "NSET\tBOTTOM = BOTTOM + SURFACE" << faces[i]->tag()
                      << "\n";
              }
              else if(std::abs((p1.z() - p2.z() - 1.0)) < 0.0001) {
                file2 << "NSET\tTOP = TOP + SURFACE" << faces[i]->tag() << "\n";
                file2 << "NSET\tBOTTOM = BOTTOM + SURFACE" << faces[j]->tag()
                      << "\n";
              }
            }
          }
          count++;
        }
      }
    }
  }

  file << "};\n";

  std::ofstream file3;
  file3.open("MicrostructurePolycrystal3D.geo", std::ios::out | std::ios::app);
  if(!file3.is_open()) {
    Msg::Error("Could not open file 'MicrostructurePolycrystal3D.geo'");
    return;
  }
  file3.precision(17);

  std::ofstream file4("MicrostructurePolycrystal3D2.pos");
  if(!file4.is_open()) {
    Msg::Error("Could not open file 'MicrostructurePolycrystal3D2.pos'");
    return;
  }
  file4 << "View \"test\" {\n";

  file3 << "Physical Surface(11)={";

  count = 0;
  for(it = model->firstFace(); it != model->lastFace(); it++) {
    gf = *it;
    if(count > 0) file3 << ",";
    file3 << gf->tag();
    count++;
  }

  file3 << "};\n";

  for(i = 0; i < pairs.size(); i++) {
    gf1 = pairs[i].first;
    gf2 = pairs[i].second;
    // the translation between the centers of the two faces
    SPoint3 cg1(0, 0, 0), cg2(0, 0, 0);
    for(auto v : gf1->vertices()) cg1 += v->xyz();
    for(auto v : gf2->vertices()) cg2 += v->xyz();
    double n1 = gf1->vertices().size(), n2 = gf2->vertices().size();
    SVector3 dx = (n1 == n2) ? SVector3(cg2 - cg1) * (1. / n1) :
                               SVector3(cg2 * (1. / n2) - cg1 * (1. / n1));
    edges1 = gf1->edges();
    edges2 = gf2->edges();
    // draw the matching edges of the two faces, and check that each edge of
    // the first face has one
    std::size_t matched = 0;
    for(it7 = edges1.begin(); it7 != edges1.end(); it7++) {
      v1 = (*it7)->getBeginVertex();
      v2 = (*it7)->getEndVertex();
      flag1 = 0;
      flag2 = 0;
      flag3 = 0;
      flag4 = 0;
      for(it8 = edges2.begin(); it8 != edges2.end(); it8++) {
        v3 = (*it8)->getBeginVertex();
        v4 = (*it8)->getEndVertex();
        correspondence(fabs(v3->x() - v1->x()), fabs(v3->y() - v1->y()),
                       fabs(v3->z() - v1->z()), e, categories[i], flag1, xMax,
                       yMax, zMax);
        correspondence(fabs(v4->x() - v2->x()), fabs(v4->y() - v2->y()),
                       fabs(v4->z() - v2->z()), e, categories[i], flag2, xMax,
                       yMax, zMax);

        correspondence(fabs(v4->x() - v1->x()), fabs(v4->y() - v1->y()),
                       fabs(v4->z() - v1->z()), e, categories[i], flag3, xMax,
                       yMax, zMax);
        correspondence(fabs(v3->x() - v2->x()), fabs(v3->y() - v2->y()),
                       fabs(v3->z() - v2->z()), e, categories[i], flag4, xMax,
                       yMax, zMax);
        if(flag1 && flag2) {
          matched++;
          print_segment(SPoint3(v3->x(), v3->y(), v3->z()),
                        SPoint3(v1->x(), v1->y(), v1->z()), file4);
          print_segment(SPoint3(v4->x(), v4->y(), v4->z()),
                        SPoint3(v2->x(), v2->y(), v2->z()), file4);
        }
        else if(flag3 && flag4) {
          matched++;
          print_segment(SPoint3(v4->x(), v4->y(), v4->z()),
                        SPoint3(v1->x(), v1->y(), v1->z()), file4);
          print_segment(SPoint3(v3->x(), v3->y(), v3->z()),
                        SPoint3(v2->x(), v2->y(), v2->z()), file4);
        }
      }
    }

    if(matched != edges1.size())
      Msg::Warning("Surfaces %d and %d do not have matching edges", gf1->tag(),
                   gf2->tag());
    file3 << "Periodic Surface {" << gf1->tag() << " }={ " << gf2->tag()
          << " } Translate { " << -dx.x() << "," << -dx.y() << "," << -dx.z()
          << "};\n";
  }
  file4 << "};\n";
}

bool voroMetal3D::correspondence(double delta_x, double delta_y, double delta_z,
                                 double e, int &val, double xMax, double yMax,
                                 double zMax)
{
  bool flag;

  flag = 0;
  val = 1000;

  if(equal(delta_x, xMax, e) && equal(delta_y, 0.0, e) &&
     equal(delta_z, 0.0, e)) {
    flag = 1;
    val = 1;
  }
  if(equal(delta_x, 0.0, e) && equal(delta_y, yMax, e) &&
     equal(delta_z, 0.0, e)) {
    flag = 1;
    val = 2;
  }
  if(equal(delta_x, 0.0, e) && equal(delta_y, 0.0, e) &&
     equal(delta_z, zMax, e)) {
    flag = 1;
    val = 3;
  }

  if(equal(delta_x, xMax, e) && equal(delta_y, yMax, e) &&
     equal(delta_z, 0.0, e)) {
    flag = 1;
    val = 4;
  }
  if(equal(delta_x, 0.0, e) && equal(delta_y, yMax, e) &&
     equal(delta_z, zMax, e)) {
    flag = 1;
    val = 5;
  }
  if(equal(delta_x, xMax, e) && equal(delta_y, 0.0, e) &&
     equal(delta_z, zMax, e)) {
    flag = 1;
    val = 6;
  }

  if(equal(delta_x, xMax, e) && equal(delta_y, yMax, e) &&
     equal(delta_z, zMax, e)) {
    flag = 1;
    val = 7;
  }
  return flag;
}

void voroMetal3D::correspondence(double delta_x, double delta_y, double delta_z,
                                 double e, int val, bool &flag, double xMax,
                                 double yMax, double zMax)
{
  flag = 0;

  if(val == 1 && equal(delta_x, xMax, e) && equal(delta_y, 0.0, e) &&
     equal(delta_z, 0.0, e)) {
    flag = 1;
  }
  if(val == 2 && equal(delta_x, 0.0, e) && equal(delta_y, yMax, e) &&
     equal(delta_z, 0.0, e)) {
    flag = 1;
  }
  if(val == 3 && equal(delta_x, 0.0, e) && equal(delta_y, 0.0, e) &&
     equal(delta_z, zMax, e)) {
    flag = 1;
  }

  if(val == 4 && equal(delta_x, xMax, e) && equal(delta_y, yMax, e) &&
     equal(delta_z, 0.0, e)) {
    flag = 1;
  }
  if(val == 5 && equal(delta_x, 0.0, e) && equal(delta_y, yMax, e) &&
     equal(delta_z, zMax, e)) {
    flag = 1;
  }
  if(val == 6 && equal(delta_x, xMax, e) && equal(delta_y, 0.0, e) &&
     equal(delta_z, zMax, e)) {
    flag = 1;
  }

  if(val == 7 && equal(delta_x, xMax, e) && equal(delta_y, yMax, e) &&
     equal(delta_z, zMax, e)) {
    flag = 1;
  }
}

bool voroMetal3D::equal(double x, double y, double e)
{
  bool flag;
  if(x > y - e && x < y + e) { flag = 1; }
  else {
    flag = 0;
  }
  return flag;
}

// the seeds file: number of seeds, radical (0 or 1), box size along x, y, z,
// then x, y, z and radius of each seed
static bool readSeeds(const char *filename, std::vector<double> &properties,
                      int &radical, double &xMax, double &yMax, double &zMax)
{
  std::ifstream file(filename);
  if(!file.is_open()) {
    Msg::Error("Could not open file '%s'", filename);
    return false;
  }
  double max;
  file >> max;
  file >> radical;
  file >> xMax;
  file >> yMax;
  file >> zMax;
  if(!file || max < 1) {
    Msg::Error("Could not read the number of seeds in '%s'", filename);
    return false;
  }
  properties.clear();
  properties.resize(4 * max);
  for(int j = 0; j < max; j++) {
    file >> properties[4 * j];
    file >> properties[4 * j + 1];
    file >> properties[4 * j + 2];
    file >> properties[4 * j + 3];
  }
  return true;
}

static void microstructure(const char *filename)
{
  int radical;
  double xMax, yMax, zMax;
  std::vector<double> properties;
  if(!readSeeds(filename, properties, radical, xMax, yMax, zMax)) return;
  voroMetal3D vm1;
  vm1.execute(properties, radical, 0.1, xMax, yMax, zMax);
  GModel::current()->load("MicrostructurePolycrystal3D.geo");
  voroMetal3D vm2;
  vm2.correspondence(0.00001, xMax, yMax, zMax);
}

// the length of the shortest edge of the microstructure of the seeds
static double shortestEdge(std::vector<double> &properties, int radical,
                           double xMax, double yMax, double zMax)
{
  voroMetal3D vm;
  vm.execute(properties, radical, 0.1, xMax, yMax, zMax);
  GModel *m = new GModel();
  m->load("MicrostructurePolycrystal3D.geo");
  double dist = 1000.0;
  for(auto ite = m->firstEdge(); ite != m->lastEdge(); ite++) {
    GVertex *v1 = (*ite)->getBeginVertex(), *v2 = (*ite)->getEndVertex();
    double d = sqrt((v1->x() - v2->x()) * (v1->x() - v2->x()) +
                    (v1->y() - v2->y()) * (v1->y() - v2->y()) +
                    (v1->z() - v2->z()) * (v1->z() - v2->z()));
    if(d < dist) dist = d;
  }
  delete m;
  return dist;
}

// move the seeds, one by 0.01 along x, y or z at a time, 17 times, each time
// the move that makes the shortest edge of the microstructure the longest
static void computeBestSeeds(const char *filename)
{
  int radical;
  double xMax, yMax, zMax;
  std::vector<double> properties;
  if(!readSeeds(filename, properties, radical, xMax, yMax, zMax)) return;
  int numSeeds = properties.size() / 4;
  for(int count = 0; count < 17; count++) {
    double best = 0.0, move = 0.;
    int index = -1;
    for(double sign : {1., -1.}) {
      for(int d = 0; d < 3; d++) {
        for(int j = 0; j < numSeeds; j++) {
          std::vector<double> modified(properties);
          modified[4 * j + d] += sign * 0.01;
          double dist = shortestEdge(modified, radical, xMax, yMax, zMax);
          if(dist > best) {
            best = dist;
            index = 4 * j + d;
            move = sign * 0.01;
          }
        }
      }
    }
    Msg::Info("VoroMetal: shortest edge %g after move %d", best, count + 1);
    if(index >= 0) properties[index] += move;
  }
  voroMetal3D vm1;
  vm1.execute(properties, radical, 0.1, xMax, yMax, zMax);
  GModel::current()->load("MicrostructurePolycrystal3D.geo");
  voroMetal3D vm2;
  vm2.correspondence(0.00001, xMax, yMax, zMax);
  Msg::Info("VoroMetal: new seeds (x y z radius):");
  for(int j = 0; j < numSeeds; j++)
    Msg::Info("%g %g %g %g", properties[4 * j], properties[4 * j + 1],
              properties[4 * j + 2], properties[4 * j + 3]);
}

PView *GMSH_VoroMetalPlugin::execute(PView *v)
{
  int runBestSeeds = (int)option(0);
  int runMicrostructure = (int)option(1);
  std::string seedsFile = optionStr(0);
  if(runBestSeeds) computeBestSeeds(seedsFile.c_str());
  if(runMicrostructure) microstructure(seedsFile.c_str());
  return v;
}

#else

PView *GMSH_VoroMetalPlugin::execute(PView *v)
{
  Msg::Error("Plugin(VoroMetal) requires mesh module and voro++");
  return v;
}

#endif
