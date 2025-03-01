// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Tristan Carrier
//   François Henrotte

#ifndef DIRECTION_3D_H
#define DIRECTION_3D_H

#include "GSurface.h"
#include "MEdge.h"
#include "MElementOctree.h"
#if defined(HAVE_ANN)
class ANNkd_tree;
#endif
#include "yamakawa.h"
#include "STensor3.h"

struct lowerThan {
  bool operator()(const std::pair<int, STensor3> &lhs,
                  const std::pair<int, STensor3> &rhs) const
  {
    return lhs.first < rhs.first;
  }
};

class Frame_field {
private:
  static std::vector<std::pair<SPoint3, STensor3> > field;
  static std::vector<int> labels;
  static std::map<MNode *, STensor3> crossField;
  static std::map<MNode *, double> crossFieldSmoothness;
  static std::map<MEdge, double, MEdgeLessThan> crossDist;
  static std::vector<MNode *> listVertices;
#if defined(HAVE_ANN)
  static ANNkd_tree *kd_tree;
  static ANNkd_tree *annTree;
#endif
  Frame_field();
  static std::map<MNode *, std::set<MNode *> > vertex_to_vertices;
  static std::map<MNode *, std::set<MElement *> > vertex_to_elements;

public:
  static void init_region(GVolume *);
  static void init_face(GSurface *);
  static STensor3 search(double, double, double);
  static STensor3 combine(double, double, double);
  static void print_field1();
  static void print_field2(GVolume *);
  static void print_segment(const SPoint3 &, const SPoint3 &, double, double,
                            std::ofstream &);
  static int build_vertex_to_vertices(GEntity *gr, int onWhat,
                                      bool initialize = true);
  static int build_vertex_to_elements(GEntity *gr, bool initialize = true);
  static void build_listVertices(GEntity *gr, int dim, bool initialize = true);
  static int buildAnnData(GEntity *ge, int dim);
  static void deleteAnnData();
  static int findAnnIndex(const SPoint3 &p);
  static STensor3 findCross(double x, double y, double z);
  static void initFace(GSurface *gf);
  static void initRegion(GVolume *gr, int n);
  static void buildSmoothness();
  static double smoothFace(GSurface *gf, int n);
  static double smoothRegion(GVolume *gr, int n);
  static double smooth();
  static double
  findBarycenter(std::map<MNode *, std::set<MNode *> >::const_iterator iter,
                 STensor3 &m0);
  static void save(const std::vector<std::pair<SPoint3, STensor3> > &data,
                   const std::string &filename);
  static void saveCrossField(const std::string &filename, double scale,
                             bool full = true);
  static void continuousCrossField(GVolume *gr, GSurface *gf);
  static void recur_connect_vert(FILE *fi, int count, MNode *v,
                                 STensor3 &cross,
                                 std::multimap<MNode *, MNode *> &v2v,
                                 std::set<MNode *> &touched);
  static void save_energy(GVolume *gr, const std::string &filename);
  static void save_dist(const std::string &filename);
  static void checkAnnData(GEntity *ge, const std::string &filename);
  static GVolume *test();
  static void clear();
};

class Size_field {
private:
  static std::vector<std::pair<SPoint3, double> > field;
  static std::map<MNode *, double> boundary;
  static MElementOctree *octree;
#if defined(HAVE_ANN)
  static ANNkd_tree *kd_tree;
#endif
  Size_field();

public:
  static void init_region(GVolume *);
  static void solve(GVolume *);
  static double search(double, double, double);
  static void print_field(GVolume *);
  static GVolume *test();
  static void clear();
};

class Nearest_point {
private:
  static std::vector<SPoint3> field;
  static std::vector<MElement *> vicinity;
#if defined(HAVE_ANN)
  static ANNkd_tree *kd_tree;
#endif
  Nearest_point();

public:
  static void init_region(GVolume *);
  static bool search(double, double, double, SVector3 &);
  static double T(double, double, double, double, double);
  static SPoint3 closest(MElement *, const SPoint3 &);
  static double clamp(double, double, double);
  static void print_field(GVolume *);
  static void print_segment(const SPoint3 &, const SPoint3 &, std::ofstream &);
  static GVolume *test();
  static void clear();
};

#endif
