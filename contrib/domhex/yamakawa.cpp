// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Tristan Carrier and Paul-Emile Bernard

#include <numeric>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cmath>
#include "yamakawa.h"
#include "GModel.h"
#include "OS.h"
#include "MVertex.h"
#include "MElement.h"
#include "MHexahedron.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "MPrism.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "GmshDefines.h"

#include "CondNumBasis.h"
#include "qualityMeasuresJacobian.h"

#include <cassert>

#ifdef EXTERNAL_MIN_WEIGHTED_SET_SEARCH
#include "mwis.hpp"
#endif

namespace {
  // Helper functions for the recombination of hex into hexes
  // No reason to put them in the already huge Recombinator class

  typedef std::map<MVertex *, std::set<MElement *> > Vertex2Elements;

  // Hex facet to hex vertex mapping
  // Previously explicitely built each time
  //   a, b, c, d
  //   e, f, g, h
  //   a, b, f, e
  //   b, c, g, f
  //   d, c, g, h
  //   d, a, e, h
  // WARNING: Looks like it is not the same used in other places in gmsh
  static unsigned int hex_facet_to_vertex[6][4] = {{0, 1, 2, 3}, {4, 5, 6, 7},
                                                   {0, 1, 5, 4}, {1, 2, 6, 5},
                                                   {3, 2, 6, 7}, {3, 0, 4, 7}};

  // Not ordered
  static unsigned int hex_edge_to_vertex[12][2] = {
    {0, 1}, {0, 3}, {0, 4}, {1, 2}, {1, 5}, {2, 3},
    {2, 6}, {3, 7}, {4, 5}, {4, 7}, {5, 6}, {6, 7}};

  // Possible triangles in a quad facet - 2 pairs of conformal triangles
  static unsigned int quad_facet_triangulation[4][3] = {
    {0, 1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2, 3}};

  static unsigned int hex_facet_diagonal[12][2] = {
    {0, 2}, {0, 5}, {0, 7}, {1, 3}, {1, 4}, {1, 6},
    {2, 5}, {2, 7}, {3, 4}, {3, 6}, {4, 6}, {5, 7}};

  // Returns the vertex index in the hex for a vertex index in a triangle taken
  // on a facet
  static unsigned int hex_facet_triangulation(unsigned int f,
                                              unsigned int triangle,
                                              unsigned int vtriangle)
  {
    unsigned int vfacet = quad_facet_triangulation[triangle][vtriangle];
    return hex_facet_to_vertex[f][vfacet];
  }

  // Is this vertex in that hex?
  // bool inclusion(MVertex* vertex, const Hex& hex) {
  //  return hex.contains(vertex);
  //}

  // Is that vertex in that tet?
  bool tet_contains_vertex(MElement *tet, MVertex *v)
  {
    return tet->getVertex(0) == v || tet->getVertex(1) == v ||
           tet->getVertex(2) == v || tet->getVertex(3) == v;
  }

  // Check the given 3 vertices are vertices of one of the tets given in
  // the input set
  bool inclusion(MVertex *v1, MVertex *v2, MVertex *v3,
                 const std::set<MElement *> &tets)
  {
    for(std::set<MElement *>::const_iterator it = tets.begin();
        it != tets.end(); it++) {
      if(tet_contains_vertex(*it, v1) && tet_contains_vertex(*it, v2) &&
         tet_contains_vertex(*it, v3)) {
        return true;
      }
    }
    return false;
  }

  // Return true if the 4 tet vertices are points of one
  // of the 6 hex facets
  bool is_combinatorially_sliver(MElement *tet, const Hex &hex)
  {
    for(unsigned int f = 0; f < 6; ++f) {
      bool tet_in_facet = true;
      for(unsigned int v = 0; v < 4; ++v) {
        MVertex *tet_vertex = tet->getVertex(v);
        bool vertex_found = false;
        for(unsigned int vface = 0; vface < 4; ++vface) {
          unsigned int v_hex = hex_facet_to_vertex[f][vface];
          if(hex.getVertex(v_hex) == tet_vertex) { vertex_found = true; }
        }
        if(!vertex_found) {
          tet_in_facet = false;
          break;
        }
      }
      if(tet_in_facet) { return true; }
    }
    return false;
  }

  // Return true if the input tet is combinatorially a sliver of
  // the input hex, i.e. its vertices are the same than those of
  // one of the hex facets
  bool sliver(MElement *tet, const Hex &hex)
  {
    return is_combinatorially_sliver(tet, hex);
  }

  /*
  double distance(MVertex* v1, MVertex* v2) {
    double val;
    double x, y, z;

    x = v2->x() - v1->x();
    y = v2->y() - v1->y();
    z = v2->z() - v1->z();

    val = sqrt(x*x + y*y + z*z);
    return val;
  }
  */

  double distance(MVertex *v, MVertex *v1, MVertex *v2)
  {
    double val;
    double x, y, z;

    x = 0.5 * (v2->x() + v1->x()) - v->x();
    y = 0.5 * (v2->y() + v1->y()) - v->y();
    z = 0.5 * (v2->z() + v1->z()) - v->z();

    val = sqrt(x * x + y * y + z * z);
    return val;
  }

  // Compute the longest edge of the tetrahedra
  // and get the indices (0 to 3) of its 2 extremities
  double diagonal(MElement *tet, int &index1, int &index2)
  {
    double max;
    double l1, l2, l3, l4, l5, l6;

    MVertex *a = tet->getVertex(0);
    MVertex *b = tet->getVertex(1);
    MVertex *c = tet->getVertex(2);
    MVertex *d = tet->getVertex(3);

    max = 1000000.0;
    l1 = ::distance(a, b);
    l2 = ::distance(a, c);
    l3 = ::distance(a, d);
    l4 = ::distance(b, c);
    l5 = ::distance(c, d);
    l6 = ::distance(d, b);

    if(l1 >= l2 && l1 >= l3 && l1 >= l4 && l1 >= l5 && l1 >= l6) {
      index1 = 0;
      index2 = 1;
      max = l1;
    }
    else if(l2 >= l1 && l2 >= l3 && l2 >= l4 && l2 >= l5 && l2 >= l6) {
      index1 = 0;
      index2 = 2;
      max = l2;
    }
    else if(l3 >= l1 && l3 >= l2 && l3 >= l4 && l3 >= l5 && l3 >= l6) {
      index1 = 0;
      index2 = 3;
      max = l3;
    }
    else if(l4 >= l1 && l4 >= l2 && l4 >= l3 && l4 >= l5 && l4 >= l6) {
      index1 = 1;
      index2 = 2;
      max = l4;
    }
    else if(l5 >= l1 && l5 >= l2 && l5 >= l3 && l5 >= l4 && l5 >= l6) {
      index1 = 2;
      index2 = 3;
      max = l5;
    }
    else if(l6 >= l1 && l6 >= l2 && l6 >= l3 && l6 >= l4 && l6 >= l5) {
      index1 = 3;
      index2 = 1;
      max = l6;
    }
    return max;
  }

  double scalar(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4)
  {
    SVector3 vec1(v1->point(), v2->point());
    SVector3 vec2(v3->point(), v4->point());

    double l1 = vec1.norm();
    double l2 = vec2.norm();

    double val = dot(vec1, vec2);
    return fabs(val) / (l1 * l2);
  }

  // TODO remove this stupid
  void two_others(int index1, int index2, int &index3, int &index4)
  {
    index3 = -1;
    index4 = -1;
    for(int i = 0; i < 4; i++) {
      if(i != index1 && i != index2) {
        if(index3 == -1)
          index3 = i;
        else
          index4 = i;
      }
    }
  }

  // Check that all the cube facets corresponds to facets
  // of the tests contitutive of that hex.
  // Apparently it might not always be the case, when a tet
  // is missing (e.g. 14 triangles define the external facets of the hex)
  // but when the number of points is correct
  // For each facet of the hex
  // Check that we can find the facets corresponding to one
  // triangulation of the quad in the input tets
  // TODO - Strange - Check that this test is really useful -
  //      It does look more like a bug to me. JP
  bool valid(const Hex &hex, const std::set<MElement *> &tets)
  {
    for(unsigned int f = 0; f < 6; f++) {
      std::vector<bool> triangle_found(4);
      for(unsigned int triangle = 0; triangle < 4; triangle++) {
        MVertex *v0 = hex.getVertex(hex_facet_triangulation(f, triangle, 0));
        MVertex *v1 = hex.getVertex(hex_facet_triangulation(f, triangle, 1));
        MVertex *v2 = hex.getVertex(hex_facet_triangulation(f, triangle, 2));

        triangle_found[triangle] = inclusion(v0, v1, v2, tets);
      }
      bool cur_facet_ok = (triangle_found[0] && triangle_found[1]) ||
                          (triangle_found[2] && triangle_found[3]);

      if(!cur_facet_ok) { return false; }
    }
    return true;
  }

  /*
  bool is_vertex_on_gmodel_boundary(MVertex* v) {
    return v->onWhat()->dim() < 3;
  }
  */
  /*
  bool is_hex_facet_on_gmodel_boundary(const Hex& hex, unsigned int f) {
    int count_boundary_vertices = 0;
    for (unsigned int i = 0; i < 4; ++i) {
      unsigned int v_index = hex_facet_to_vertex[f][i];
      MVertex* v = hex.getVertex(v_index);
      if (is_vertex_on_gmodel_boundary(v)) {
        count_boundary_vertices++;
      }
    }
    return count_boundary_vertices == 4;
  }
  */
  /*
  bool is_hex_facet_planar(const Hex& hex, unsigned int facet_id, double
  max_angle = 15.) { std::vector<SPoint3> points(4); for (unsigned int v = 0; v
  < 4; ++v) { unsigned int v_id = hex_facet_to_vertex[facet_id][v]; points[v] =
  hex.getVertex(v_id)->point();
    }
    SVector3 vec1 = SVector3(points[0], points[1]).unit();
    SVector3 vec2 = SVector3(points[0], points[2]).unit();
    SVector3 vec3 = SVector3(points[0], points[3]).unit();

    SVector3 crossVec1Vec2 = crossprod(vec1, vec2);
    double angle = fabs(acos(dot(crossVec1Vec2, vec3)) * 180. / M_PI);

    if (fabs(angle - 90) > max_angle) {
      return false;
    } else {
      return true;
    }
  }
  */
  unsigned int nb_tets_sharing_vertices(MVertex *v1, MVertex *v2, MVertex *v3,
                                        TetMeshConnectivity &tet_mesh)
  {
    TetMeshConnectivity::TetSet tets;
    tet_mesh.tets_around_vertices(v1, v2, v3, tets);
    return tets.size();
  }

  // Check that the given facet of the input hex
  // can be combinatorially built from two tet facets
  // i.e. we check that for either of the subdivision of the facet into
  // two triangles we can find at least one tet that have this triangle as a
  // facet The two triangles of the subdivided quad facet must be adjacent to
  // the same number of tets -- a face partly on the boundary and party inside
  // is invalid.
  bool validFace(const Hex &hex, unsigned int facet_id,
                 TetMeshConnectivity &tet_mesh)
  {
    int nb_tets_adjacent[4] = {0, 0, 0, 0};
    // Possible de ne pas faire tous les calculs, mais bon
    for(unsigned int t = 0; t < 4; ++t) {
      unsigned int nb = nb_tets_sharing_vertices(
        hex.getVertex(hex_facet_triangulation(facet_id, t, 0)),
        hex.getVertex(hex_facet_triangulation(facet_id, t, 1)),
        hex.getVertex(hex_facet_triangulation(facet_id, t, 2)), tet_mesh);
      nb_tets_adjacent[t] = nb;
    }
    bool valid_facet =
      (nb_tets_adjacent[0] > 0 && nb_tets_adjacent[1] == nb_tets_adjacent[0]) ||
      (nb_tets_adjacent[2] > 0 && nb_tets_adjacent[3] == nb_tets_adjacent[2]);

    return valid_facet;
  }

  // Check that the 6 facets of the hexahedra are valid
  // A facet is valid if
  // TODO Change the code to have const TetMeshConnectivity&  -- pb is []
  // operator on the maps
  bool validFaces(const Hex &hex, TetMeshConnectivity &tet_mesh)
  {
    for(unsigned int f = 0; f < 6; ++f) {
      bool valid_facet = validFace(hex, f, tet_mesh);
      if(!valid_facet) { return false; }
    }
    return true;
  }

  double eta(MVertex *a, MVertex *b, MVertex *c, MVertex *d)
  {
    MQuadrangle quad(a, b, c, d);
    return quad.etaShapeMeasure();
  }

  // If all etaShapeMeasure for the 6 hex facets are above the required min_eta
  // return the result of validFaces
  // otherwise return false
  bool valid(const Hex &hex, TetMeshConnectivity &tet_mesh,
             double min_eta = 0.000001)
  {
    for(unsigned int f = 0; f < 6; ++f) {
      double eta_value =
        eta(hex.vertex_in_facet(f, 0), hex.vertex_in_facet(f, 1),
            hex.vertex_in_facet(f, 2), hex.vertex_in_facet(f, 3));
      if(eta_value < min_eta) { return false; }
    }
    return validFaces(hex, tet_mesh);
  }

  // Returns true if the hex contains all the tet vertices
  bool hex_contains_tet(const Hex &hex, MElement *tet)
  {
    return hex.contains((tet)->getVertex(0)) &&
           hex.contains((tet)->getVertex(1)) &&
           hex.contains((tet)->getVertex(2)) &&
           hex.contains((tet)->getVertex(3));
  }

  // For all tets around the input vertex
  // Check if its 4 vertices are vertices of the input hex
  // Insert the tet in the final set if they are
  void find(MVertex *vertex, const Hex &hex, std::set<MElement *> &result,
            TetMeshConnectivity &tet_mesh)
  {
    TetMeshConnectivity::TetSet tets_around_v =
      tet_mesh.tets_around_vertex(vertex);
    for(TetMeshConnectivity::TetSet::const_iterator tet = tets_around_v.begin();
        tet != tets_around_v.end(); ++tet) {
      if(hex_contains_tet(hex, *tet)) { result.insert(*tet); }
    }
  }

  void find(const Hex &hex, std::set<MElement *> &result,
            TetMeshConnectivity &tet_mesh)
  {
    for(unsigned int v = 0; v < 8; ++v) {
      find(hex.getVertex(v), hex, result, tet_mesh);
    }
  }

  MVertex *last_tet_vertex(MElement *tet, MVertex *v1, MVertex *v2, MVertex *v3)
  {
    for(unsigned int i = 0; i < 4; ++i) {
      MVertex *v = tet->getVertex(i);
      if(v != v1 && v != v2 && v != v3) { return v; }
    }
    return NULL;
  }

  // Among the input tetrahedra find the first tet that contains v1, v2, and v3
  // BUT not v4 and return the vertex of tet that is neither v1, v2, or v3
  // Dis-donc c'est vraiment tordu !!
  // Tout ca pour avoir le voisin d'un tet la face opposée à v4 et prendre le
  // point opposé dans le tet voisin.
  MVertex *find(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                const std::set<MElement *> &tets)
  {
    for(std::set<MElement *>::const_iterator it = tets.begin();
        it != tets.end(); it++) {
      MElement *tet = *it;
      if(tet_contains_vertex(tet, v1) && tet_contains_vertex(tet, v2) &&
         tet_contains_vertex(tet, v3) && !tet_contains_vertex(tet, v4)) {
        return last_tet_vertex(tet, v1, v2, v3);
      }
    }
    return NULL;
  }

  template <class T>
  bool find_value_in_multiset(const std::multiset<T> &set, const T &value,
                              T &value_in_set)
  {
    typename std::multiset<T>::const_iterator it = set.find(value);
    for(; it != set.end() && it->get_hash() == value.get_hash(); ++it) {
      if(value.same_vertices(*it)) {
        value_in_set = *it;
        return true;
      }
    }
    return false;
  }

  // Check if one value exist in a multiset hash table of Recombinator
  template <class T>
  bool find_value_in_multiset(const std::multiset<T> &set, const T &value)
  {
    typename std::multiset<T>::const_iterator it = set.find(value);
    for(; it != set.end() && it->get_hash() == value.get_hash(); ++it) {
      if(value.same_vertices(*it)) { return true; }
    }
    return false;
  }

  // To insert values in multiset hash table of Recombinator
  template <class T>
  void add_value_to_multiset(std::multiset<T> &set, const T &value)
  {
    if(!find_value_in_multiset(set, value)) { set.insert(value); }
  }

  // Compute the intersection of bin1 and bin2
  // And add to final the elements that are not in the already vector
  // void Recombinator::intersection(const std::set<MVertex*>& bin1, const
  // std::set<MVertex*>& bin2,

  std::ostream &operator<<(std::ostream &os, const Hex &hex)
  {
    os << " vertices "
       << " A " << hex.getVertex(0)->getNum() << " B "
       << hex.getVertex(1)->getNum() << " C " << hex.getVertex(2)->getNum()
       << " D " << hex.getVertex(3)->getNum() << " E "
       << hex.getVertex(4)->getNum() << " F " << hex.getVertex(5)->getNum()
       << " G " << hex.getVertex(6)->getNum() << " H "
       << hex.getVertex(7)->getNum();
    return os;
  }

} // anonymous namespace

void export_gregion_mesh(GRegion *gr, const string &filename)
{
  // FIXME: use MElement::writeMSH

  // create set of all tets
  map<MVertex *, int> vertices;
  int counterv = 1;

  for(vector<MTetrahedron *>::iterator it = gr->tetrahedra.begin();
      it != gr->tetrahedra.end(); it++) {
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      vertices.insert(make_pair((*it)->getVertex(i), counterv));
      counterv++;
    }
  }
  for(vector<MHexahedron *>::iterator it = gr->hexahedra.begin();
      it != gr->hexahedra.end(); it++) {
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      vertices.insert(make_pair((*it)->getVertex(i), counterv));
      counterv++;
    }
  }
  for(vector<MPrism *>::iterator it = gr->prisms.begin();
      it != gr->prisms.end(); it++) {
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      vertices.insert(make_pair((*it)->getVertex(i), counterv));
      counterv++;
    }
  }
  for(vector<MPyramid *>::iterator it = gr->pyramids.begin();
      it != gr->pyramids.end(); it++) {
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      vertices.insert(make_pair((*it)->getVertex(i), counterv));
      counterv++;
    }
  }

  // export mesh
  ofstream out(filename.c_str());
  out << "$MeshFormat" << endl
      << "2.2 0 8" << endl
      << "$EndMeshFormat" << endl
      << "$Nodes" << endl
      << vertices.size() << endl;
  // write vertices
  for(map<MVertex *, int>::iterator it = vertices.begin(); it != vertices.end();
      it++)
    out << it->second << " " << it->first->x() << " " << it->first->y() << " "
        << it->first->z() << endl;
  out << "$EndNodes" << endl
      << "$Elements" << endl
      << (gr->tetrahedra.size() + gr->hexahedra.size() + gr->prisms.size() +
          gr->pyramids.size())
      << endl;

  // write elems
  int counter = 1;
  for(vector<MTetrahedron *>::iterator it = gr->tetrahedra.begin();
      it != gr->tetrahedra.end(); it++) {
    out << counter << " 4 2 0 26";
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }
  for(vector<MHexahedron *>::iterator it = gr->hexahedra.begin();
      it != gr->hexahedra.end(); it++) {
    out << counter << " 5 2 0 26";
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }
  for(vector<MPrism *>::iterator it = gr->prisms.begin();
      it != gr->prisms.end(); it++) {
    out << counter << " 6 2 0 26";
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }
  for(vector<MPyramid *>::iterator it = gr->pyramids.begin();
      it != gr->pyramids.end(); it++) {
    out << counter << " 7 2 0 26";
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }

  out << "$EndElements" << endl;
  out.close();
}

/**************************************************/
/****************class Recombinator****************/
/**************************************************/

MVertex *Hex::vertex_in_facet(unsigned int facet, unsigned int v_in_facet) const
{
  unsigned int v = hex_facet_to_vertex[facet][v_in_facet];
  return getVertex(v);
}

bool compare_hex_ptr_by_quality(Hex *a, Hex *b)
{
  return (a->get_quality() > (b->get_quality()));
}

Recombinator::~Recombinator()
{
  for(std::vector<Hex *>::iterator it = potential.begin();
      it != potential.end(); it++) {
    delete *it;
  }
}

void Recombinator::execute()
{
  GModel *model = GModel::current();
  // Backup the current mesh
  //  model->writeMSH("beforeyamakawa.msh");

  for(GModel::riter region_itr = model->firstRegion();
      region_itr != model->lastRegion(); region_itr++) {
    GRegion *region = *region_itr;

    if(region->getNumMeshElements() > 0) { execute(region); }
  }
}

void Recombinator::execute(GRegion *gr)
{
  Msg::Info(" ................HEXAHEDRA.... RECOMBINATOR................\n");

  initialize_structures(gr);

  compute_potential_hexes();

  merge();

  set_region_elements_positive();
  create_quads_on_boundary();

  print_statistics();
}

void Recombinator::print_all_potential_hex() const
{
  // SORTIE TOUS HEX POT
  std::cout
    << "__________________________ START POT HEX LISTING ____________________ "
    << endl;
  for(std::vector<Hex *>::const_iterator it = potential.begin();
      it != potential.end(); it++) {
    cout << "--- Potential hex : " << *(*it) << "   " << (*it)->get_quality()
         << endl;
  }
  std::cout
    << "__________________________ END POT HEX LISTING ____________________ "
    << endl;
  // END
}

// This way to flag the tets already included in
// one hex of the final mesh is probably quite pricy. JP
// TODO Replace by a big vector of booleans
void Recombinator::init_markings()
{
  markings.clear();
  for(unsigned int i = 0; i < current_region->getNumMeshElements(); i++) {
    MElement *element = current_region->getMeshElement(i);
    markings.insert(std::pair<MElement *, bool>(element, false));
  }
}

template <class T>
void remove_values_from_set(std::set<T> &input_set,
                            const std::vector<T> &values)
{
  for(unsigned int i = 0; i < values.size(); ++i) {
    input_set.erase(values[i]);
  }
}

// Compute the potential tets following the first pattern
// given in their paper by Yamakawa and Shimada
// Very very expensve - complexity is a nightmare -
// TODO - rewrite the vertex_to_vertices computation and access
// Sot that we only have big, easy to manipulate vectors and
// store only the neighbos whose index is superior JP
// TODO - Do not add potential hexes with a very bad quality
// TODO - Change the storage for the potential hexes - We need a big vector
// and a way to compare - sort them - lower getVertex index shoudl always be
// first
void Recombinator::pattern1()
{
  Msg::Info("Hex-merging pattern nb. 1...");
  for(unsigned int i = 0; i < current_region->getNumMeshElements(); i++) {
    MElement *tet = current_region->getMeshElement(i);

    for(int index = 0; index < 4; index++) {
      // max_scaled_jacobian(element,index);
      MVertex *a = tet->getVertex(index);
      MVertex *b = tet->getVertex((index + 1) % 4);
      MVertex *c = tet->getVertex((index + 2) % 4);
      MVertex *d = tet->getVertex((index + 3) % 4);

      std::vector<MVertex *> added(4);
      added[0] = a;
      added[1] = b;
      added[2] = c;
      added[3] = d;

      std::set<MVertex *> bin1;
      std::set<MVertex *> bin2;
      std::set<MVertex *> bin3;

      tet_mesh.vertices_around_vertices(b, d, bin1); // candidates for F - p
      tet_mesh.vertices_around_vertices(b, c, bin2); // candidates for C - q
      tet_mesh.vertices_around_vertices(c, d, bin3); // candidates for H - r

      // Neither smart nor efficient I know
      remove_values_from_set(bin1, added);
      remove_values_from_set(bin2, added);
      remove_values_from_set(bin3, added);

      added.resize(7);
      for(vertex_set_itr it1 = bin1.begin(); it1 != bin1.end(); it1++) {
        MVertex *p = *it1;
        added[4] = p;
        for(vertex_set_itr it2 = bin2.begin(); it2 != bin2.end(); it2++) {
          MVertex *q = *it2;
          added[5] = q;
          for(vertex_set_itr it3 = bin3.begin(); it3 != bin3.end(); it3++) {
            MVertex *r = *it3;
            added[6] = r;
            if(p != q && p != r && q != r) {
              std::set<MVertex *>
                bin4; // candidates for G - s vertices linked to p,q and r
              tet_mesh.vertices_around_vertices(p, q, r, bin4);
              remove_values_from_set(bin4, added);

              for(std::set<MVertex *>::iterator it4 = bin4.begin();
                  it4 != bin4.end(); it4++) {
                MVertex *s = *it4;
                Hex *hex = new Hex(a, b, q, c, d, p, s, r);

                add_or_free_potential_hex(hex);
              }
            }
          }
        }
      }
    }
  }
}

void Recombinator::pattern2()
{
  Msg::Info("Hex-merging pattern nb. 2...");

  for(unsigned int i = 0; i < current_region->getNumMeshElements(); i++) {
    MElement *tet = current_region->getMeshElement(i);
    // Only the longest edges is tested - to avoid looping on all the tet edges
    int index1 = -1;
    int index2 = -1;
    int index3 = -1;
    int index4 = -1;

    // I am not convinced by considering only the longest edge of
    // the tet -- Are we not missing some potential hexes?
    diagonal(tet, index1, index2);
    two_others(index1, index2, index3, index4);

    MVertex *b =
      tet->getVertex(index1); // b and d are the vertices of the longest edge
    MVertex *d = tet->getVertex(index2);
    MVertex *a = tet->getVertex(index3); // a and c are the other two vertices
    MVertex *c = tet->getVertex(index4);

    std::set<MElement *> verif;
    tet_mesh.tets_around_vertices(b, d, verif);

    // If there are 6 tets sharing the longest edge
    // of the input tet - proceed
    // And get the other 4 vertices of the hex
    if(verif.size() == 6) {
      MVertex *s = find(a, b, d, c, verif);
      MVertex *p = find(b, c, d, a, verif);

      if(s != NULL && p != NULL) {
        MVertex *r = find(s, b, d, a, verif);
        MVertex *q = find(p, b, d, c, verif);
        if(r != 0 && q != 0) {
          // 2 possible hexes
          Hex *hex = new Hex(a, s, b, c, d, r, q, p);
          add_or_free_potential_hex(hex);

          Hex *hex2 = new Hex(a, c, d, s, b, p, q, r);
          add_or_free_potential_hex(hex2);
        }
      }
    }
  }
}

void Recombinator::pattern3()
{
  Msg::Info("Hex-merging pattern nb. 3...");

  for(unsigned int i = 0; i < current_region->getNumMeshElements(); i++) {
    MElement *tet = current_region->getMeshElement(i);

    int index1 = -1;
    int index2 = -1;
    int index3 = -1;
    int index4 = -1;

    diagonal(tet, index1, index2);
    two_others(index1, index2, index3, index4);

    MVertex *b = tet->getVertex(index1);
    MVertex *d = tet->getVertex(index2);
    MVertex *a = tet->getVertex(index3);
    MVertex *c = tet->getVertex(index4);

    std::set<MElement *> verif1;
    std::set<MElement *> verif2;
    tet_mesh.tets_around_vertices(b, d, verif1);
    tet_mesh.tets_around_vertices(a, c, verif2);

    if(verif1.size() == 4 && verif2.size() == 4) {
      MVertex *fA = find(b, d, a, c, verif1);
      MVertex *fB = find(b, d, c, a, verif1);
      MVertex *bA = find(a, c, b, d, verif2);
      MVertex *bB = find(a, c, d, b, verif2);

      if(fA != 0 && fB != 0 && bA != 0 && bB != 0 && fA != fB && bA != bB) {
        if(scalar(fA, fB, a, b) > scalar(fA, fB, b, c) &&
           scalar(bA, bB, a, b) > scalar(bA, bB, b, c)) {
          MVertex *p = NULL;
          MVertex *q = NULL;
          if(distance(fA, b, c) < distance(fB, b, c)) {
            p = fA;
            q = fB;
          }
          else {
            p = fB;
            q = fA;
          }

          MVertex *r = NULL;
          MVertex *s = NULL;
          if(distance(bA, b, c) < distance(bB, b, c)) {
            r = bA;
            s = bB;
          }
          else {
            r = bB;
            s = bA;
          }

          bool c1 = tet_mesh.are_vertex_neighbors(b, p);
          bool c2 = tet_mesh.are_vertex_neighbors(c, p);
          bool c3 = tet_mesh.are_vertex_neighbors(p, q);
          bool c4 = tet_mesh.are_vertex_neighbors(a, q);
          bool c5 = tet_mesh.are_vertex_neighbors(d, q);

          bool c6 = tet_mesh.are_vertex_neighbors(b, r);
          bool c7 = tet_mesh.are_vertex_neighbors(c, r);
          bool c8 = tet_mesh.are_vertex_neighbors(r, s);
          bool c9 = tet_mesh.are_vertex_neighbors(a, s);
          bool c10 = tet_mesh.are_vertex_neighbors(d, s);

          if(c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9 && c10) {
            Hex *hex = new Hex(p, c, r, b, q, d, s, a);
            add_or_free_potential_hex(hex);
          }
        } // copy paste alert
        else if(scalar(fA, fB, a, b) <= scalar(fA, fB, b, c) &&
                scalar(bA, bB, a, b) <= scalar(bA, bB, b, c)) {
          MVertex *p = NULL;
          MVertex *q = NULL;
          if(distance(fA, a, b) < distance(fB, a, b)) {
            p = fA;
            q = fB;
          }
          else {
            p = fB;
            q = fA;
          }
          MVertex *r = NULL;
          MVertex *s = NULL;
          if(distance(bA, a, b) < distance(bB, a, b)) {
            r = bA;
            s = bB;
          }
          else {
            r = bB;
            s = bA;
          }

          bool c1 = tet_mesh.are_vertex_neighbors(b, p);
          bool c2 = tet_mesh.are_vertex_neighbors(a, p);
          bool c3 = tet_mesh.are_vertex_neighbors(p, q);
          bool c4 = tet_mesh.are_vertex_neighbors(c, q);
          bool c5 = tet_mesh.are_vertex_neighbors(d, q);

          bool c6 = tet_mesh.are_vertex_neighbors(b, r);
          bool c7 = tet_mesh.are_vertex_neighbors(a, r);
          bool c8 = tet_mesh.are_vertex_neighbors(r, s);
          bool c9 = tet_mesh.are_vertex_neighbors(c, s);
          bool c10 = tet_mesh.are_vertex_neighbors(d, s);

          if(c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9 && c10) {
            Hex *hex = new Hex(p, b, r, a, q, c, s, d);

            add_or_free_potential_hex(hex);
          }
        }
      }
    }
  }
}

void Recombinator::add_or_free_potential_hex(Hex *candidate)
{
  if(valid(*candidate, tet_mesh)) { potential.push_back(candidate); }
  else {
    delete candidate;
  }
}

void add_hex_to_region(GRegion *region, const Hex &hex)
{
  region->addHexahedron(new MHexahedron(hex.vertices()));
}

bool Recombinator::are_all_tets_free(const std::set<MElement *> &tets) const
{
  for(std::set<MElement *>::const_iterator it = tets.begin(); it != tets.end();
      it++) {
    MElement *tet = *it;
    std::map<MElement *, bool>::const_iterator it2 = markings.find(tet);
    if(it2->second == true) { return false; }
  }
  return true;
}

void Recombinator::mark_tets(const std::set<MElement *> &tets)
{
  for(std::set<MElement *>::const_iterator it = tets.begin(); it != tets.end();
      ++it) {
    std::map<MElement *, bool>::iterator it2 = markings.find(*it);
    it2->second = true;
  }
}

void remove_slivers(std::set<MElement *> &tets, const Hex &hex,
                    std::set<MElement *> &slivers)
{
  for(std::set<MElement *>::iterator it = tets.begin(); it != tets.end();
      ++it) {
    if(is_combinatorially_sliver(*it, hex)) {
      slivers.insert(*it);
      tets.erase(it);
      break;
    }
  }
}

// Delete the region tets and put back those which are not marked
// as being part of an hex
void Recombinator::delete_marked_tets_in_region() const
{
  std::vector<MTetrahedron *> copy_tets = current_region->tetrahedra;
  current_region->tetrahedra.clear();
  for(unsigned int i = 0; i < copy_tets.size(); i++) {
    MElement *element = (MElement *)(copy_tets[i]);
    std::map<MElement *, bool>::const_iterator it2 = markings.find(element);
    if(it2->second == false) {
      current_region->tetrahedra.push_back(copy_tets[i]);
    }
    else {
      delete copy_tets[i];
    }
  }
}

bool Recombinator::add_hex_to_region_if_valid(const Hex &hex)
{
  // Get the tets constituting that hex
  std::set<MElement *> hex_tets;
  find(hex, hex_tets, tet_mesh);
  std::set<MElement *> slivers;
  remove_slivers(hex_tets, hex, slivers);
  // Sanity checks
  assert(hex_tets.size() > 4 && hex_tets.size() < 7);
  assert(slivers.size() < 8);

  bool valid_hex = are_all_tets_free(hex_tets) && valid(hex, hex_tets) &&
                   is_potential_hex_conform(hex);

  if(valid_hex) {
    add_hex_to_region(current_region, hex);
    mark_tets(hex_tets);
    mark_tets(slivers);
    build_hash_tableA(hex);
    build_hash_tableB(hex);
    build_hash_tableC(hex);
  }
  return valid_hex;
}

void Recombinator::merge()
{
  clear_hash_tables();

  int nb_final_hex = 0;
  double total_quality = 0.0;

  std::sort(potential.begin(), potential.end(), compare_hex_ptr_by_quality);
  for(unsigned int i = 0; i < potential.size(); i++) {
    const Hex &hex = *potential[i];
    // TODO - Not storing low quality tets in the first place would be cheaper
    if(hex.get_quality() < hex_threshold_quality) { break; }
    bool hex_added = add_hex_to_region_if_valid(hex);

    // Compute tet quality statistics
    if(hex_added) {
      total_quality += hex.get_quality();
      nb_final_hex++;
    }
  }
  if(nb_final_hex > 0) { delete_marked_tets_in_region(); }

  Msg::Info("Number of hexaedra: %d", nb_final_hex);

  double average_quality = nb_final_hex == 0 ? 0 : total_quality / nb_final_hex;
  Msg::Info("hexahedra average quality (0->1) : %f\n", average_quality);
}

void Recombinator::set_region_elements_positive()
{
  for(unsigned int i = 0; i < current_region->getNumMeshElements(); i++) {
    MElement *element = current_region->getMeshElement(i);
    element->setVolumePositive();
  }
}

void Recombinator::print_statistics()
{
  unsigned int nb_hex = 0;
  double total_volume = 0.0;
  double hex_volume = 0.0;

  for(unsigned int i = 0; i < current_region->getNumMeshElements(); i++) {
    MElement *element = current_region->getMeshElement(i);
    double volume = element->getVolume();

    if(element->getNumVertices() == 8) {
      nb_hex++;
      hex_volume += volume;
    }
    total_volume += volume;
  }
  printf("percentage of hexahedra (number) : %.2f\n",
         nb_hex * 100.0 / current_region->getNumMeshElements());
  printf("percentage of hexahedra (volume) : %.2f\n",
         hex_volume * 100.0 / total_volume);
}

// Get all the triangle facets defining the boundary of the input region
// Each Tuple stores its 3 vertices, the triangle, and the GFace
// to which it belongs
void Recombinator::build_tuples()
{
  tuples.clear();
  triangles.clear();

  std::vector<GFace *> faces = current_region->faces();

  for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
      it++) {
    GFace *gf = *it;

    for(unsigned int i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *element = gf->getMeshElement(i);

      if(element->getNumVertices() == 3) {
        MVertex *a = element->getVertex(0);
        MVertex *b = element->getVertex(1);
        MVertex *c = element->getVertex(2);

        tuples.insert(Tuple(a, b, c, element, gf));
      }
    }
  }
}

void Recombinator::create_quads_on_boundary()
{
  for(unsigned int i = 0; i < current_region->getNumMeshElements(); i++) {
    MElement *element = current_region->getMeshElement(i);

    if(element->getNumVertices() == 8) {
      MVertex *a = element->getVertex(0);
      MVertex *b = element->getVertex(1);
      MVertex *c = element->getVertex(2);
      MVertex *d = element->getVertex(3);
      MVertex *e = element->getVertex(4);
      MVertex *f = element->getVertex(5);
      MVertex *g = element->getVertex(6);
      MVertex *h = element->getVertex(7);
      // WARNING: not the same facets than those used to build the hex !!
      create_quads_on_boundary(a, b, c, d);
      create_quads_on_boundary(e, f, g, h);
      create_quads_on_boundary(a, e, h, d);
      create_quads_on_boundary(b, f, g, c);
      create_quads_on_boundary(a, e, f, b);
      create_quads_on_boundary(d, h, g, c);
    }
  }
  delete_quad_triangles_in_boundary();
}

void Recombinator::delete_quad_triangles_in_boundary() const
{
  std::vector<GFace *> faces = current_region->faces();
  for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
      it++) {
    GFace *gf = *it;
    std::vector<MElement *> triangles_to_keep;
    triangles_to_keep.reserve(gf->triangles.size());

    // Why not directly iterate on the triangle list??
    for(unsigned int i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *element = gf->getMeshElement(i);
      bool is_triangle = element->getNumVertices() == 3;
      if(is_triangle) {
        bool is_in_quad = triangles.find(element) != triangles.end();
        if(!is_in_quad) { triangles_to_keep.push_back(element); }
      }
    }
    gf->triangles.clear();
    for(unsigned int i = 0; i < triangles_to_keep.size(); i++) {
      gf->triangles.push_back((MTriangle *)triangles_to_keep[i]);
    }
  }
}

// For the two possible triangulations
// of these 4 points - check if they are part of the input
// boundary of the region
// If they are, create the corrsponding quad in the GFace mesh.
// TODO - check and get out fast if the vertices are not on the boundary of the
// region
void Recombinator::create_quads_on_boundary(MVertex *a, MVertex *b, MVertex *c,
                                            MVertex *d)
{
  Tuple tuple0(a, b, c);
  Tuple tuple1(c, d, a);

  Tuple stored_tuple0;
  Tuple stored_tuple1;

  bool tuple0_found = find_value_in_multiset(tuples, tuple0, stored_tuple0);
  bool tuple1_found = find_value_in_multiset(tuples, tuple1, stored_tuple1);

  bool quad_added = false;
  if(tuple0_found && tuple1_found) {
    triangles.insert(stored_tuple0.get_element());
    triangles.insert(stored_tuple1.get_element());

    GFace *face = stored_tuple0.get_gf();
    assert(stored_tuple1.get_gf() == face);
    face->addQuadrangle(new MQuadrangle(a, b, c, d));
    quad_added = true;
  }

  // TODO - copy paste alert
  Tuple tuple2(a, b, d);
  Tuple tuple3(b, c, d);

  Tuple stored_tuple2;
  Tuple stored_tuple3;

  bool tuple2_found = find_value_in_multiset(tuples, tuple2, stored_tuple2);
  bool tuple3_found = find_value_in_multiset(tuples, tuple3, stored_tuple3);

  if(tuple2_found && tuple3_found) {
    triangles.insert(stored_tuple2.get_element());
    triangles.insert(stored_tuple3.get_element());

    GFace *face = stored_tuple2.get_gf();
    assert(stored_tuple3.get_gf() == face);
    if(!quad_added) { face->addQuadrangle(new MQuadrangle(a, b, c, d)); }
    else {
      // This should not happen. Even with slivers and whatever
      // the surface mesh is supposed to be valid at the beginning isn't it? JP
      throw;
    }
  }
}

// Tet is not compatible with previsouly built tets
// No need to check the slivers, they belong potentially to several hex.
bool Recombinator::is_potential_hex_conform(const Hex &hex)
{
  return conformityA(hex) && conformityB(hex) && conformityC(hex) &&
         faces_statuquo(hex);
}

// Return true if all the facets of the potential hex are conformA
// A facet is conformA if all or none of the 4 possible triangles are in TableA
bool Recombinator::conformityA(const Hex &hex)
{
  for(unsigned int f = 0; f < 6; ++f) {
    std::vector<bool> triangle_inA(4, false);
    for(unsigned int t = 0; t < 4; ++t) {
      Facet hex_facet_triangle(hex.getVertex(hex_facet_triangulation(f, t, 0)),
                               hex.getVertex(hex_facet_triangulation(f, t, 1)),
                               hex.getVertex(hex_facet_triangulation(f, t, 2)));

      triangle_inA[t] = find_value_in_multiset(hash_tableA, hex_facet_triangle);
    }
    unsigned int nb_triangles_inA =
      std::count(triangle_inA.begin(), triangle_inA.end(), true);
    if(nb_triangles_inA != 0 && nb_triangles_inA != 4) { return false; }
  }
  return true;
}

bool Recombinator::conformityB(const Hex &hex)
{
  // Check if one of the 12 hex edges is in tableB
  for(unsigned int edge = 0; edge < 12; ++edge) {
    Diagonal hex_edge(hex.getVertex(hex_edge_to_vertex[edge][0]),
                      hex.getVertex(hex_edge_to_vertex[edge][1]));
    bool is_already_diagonal = find_value_in_multiset(hash_tableB, hex_edge);
    if(is_already_diagonal) { return false; }
  }

  // And check that for each hex facet only one of the 2 diagonals is in tableB
  // Isn't it redondant with conformity A ???
  for(unsigned int facet = 0; facet < 6; ++facet) {
    Diagonal d0(hex.vertex_in_facet(facet, 0), hex.vertex_in_facet(facet, 2));
    Diagonal d1(hex.vertex_in_facet(facet, 1), hex.vertex_in_facet(facet, 3));
    bool is_already_diagonal0 = find_value_in_multiset(hash_tableB, d0);
    bool is_already_diagonal1 = find_value_in_multiset(hash_tableB, d1);

    if(is_already_diagonal0 != is_already_diagonal1) { return false; }
  }
  return true;
}

// Return true if one of the 12 facet diagonals of the hex is in tableC
// meaning that it was used as an hex edge.
bool Recombinator::conformityC(const Hex &hex)
{
  for(unsigned int i = 0; i < 12; ++i) {
    Diagonal facet_diagonal(hex.getVertex(hex_facet_diagonal[i][0]),
                            hex.getVertex(hex_facet_diagonal[i][1]));
    bool is_already_hex_edge =
      find_value_in_multiset(hash_tableC, facet_diagonal);
    if(is_already_hex_edge) { return false; }
  }
  return true;
}

// Check that all hex facets are consistent (2 triangle on the same boundary
// when the facet is on the region boundary)
bool Recombinator::faces_statuquo(const Hex &hex)
{
  for(unsigned int f = 0; f < 6; ++f) {
    bool status_quo =
      faces_statuquo(hex.vertex_in_facet(f, 0), hex.vertex_in_facet(f, 1),
                     hex.vertex_in_facet(f, 2), hex.vertex_in_facet(f, 3));
    if(!status_quo) return false;
  }
  return true;
}

// Return false when two triangles in the facets that are not
// on the same boundary (same GFace) of the region.
// In other words, when a geo edge is a diagonal of the current facet.
bool Recombinator::faces_statuquo(MVertex *a, MVertex *b, MVertex *c,
                                  MVertex *d)
{
  {
    Tuple tuple1(a, b, c);
    Tuple tuple2(c, d, a);

    std::multiset<Tuple>::iterator it1 = tuples.find(tuple1);
    std::multiset<Tuple>::iterator it2 = tuples.find(tuple2);

    GFace *gf1 = NULL;
    GFace *gf2 = NULL;

    while(it1 != tuples.end() && it1->get_hash() == tuple1.get_hash()) {
      if(tuple1.same_vertices(*it1)) { gf1 = it1->get_gf(); }
      it1++;
    }

    while(it2 != tuples.end() && it2->get_hash() == tuple2.get_hash()) {
      if(tuple2.same_vertices(*it2)) { gf2 = it2->get_gf(); }
      it2++;
    }
    // Normalement soit on a trouvé les 2 soit on en trouve aucune

    assert((gf1 == NULL && gf2 == NULL) || (gf1 != NULL && gf2 != NULL));

    if(gf1 != NULL && gf2 != NULL) {
      if(gf1 != gf2) { return false; }
      else
        return true;
    }
  }
  // Copy paste alert
  {
    // Now check the second possible triangulation for the facet
    Tuple tuple1(a, b, d);
    Tuple tuple2(b, c, d);

    std::multiset<Tuple>::iterator it1 = tuples.find(tuple1);
    std::multiset<Tuple>::iterator it2 = tuples.find(tuple2);

    GFace *gf1 = NULL;
    GFace *gf2 = NULL;

    while(it1 != tuples.end() && it1->get_hash() == tuple1.get_hash()) {
      if(tuple1.same_vertices(*it1)) { gf1 = it1->get_gf(); }
      it1++;
    }

    while(it2 != tuples.end() && it2->get_hash() == tuple2.get_hash()) {
      if(tuple2.same_vertices(*it2)) { gf2 = it2->get_gf(); }
      it2++;
    }

    if(gf1 != NULL && gf2 != NULL) {
      if(gf1 != gf2) { return false; }
      else
        return true;
    }
  }
  // The facet are not on the boundary
  return true;
}

// Store the hex facet triaangles (4 per facet) in TableA
void Recombinator::build_hash_tableA(const Hex &hex)
{
  for(unsigned int f = 0; f < 6; ++f) {
    for(unsigned int t = 0; t < 4; ++t) {
      MVertex *v0 = hex.getVertex(hex_facet_triangulation(f, t, 0));
      MVertex *v1 = hex.getVertex(hex_facet_triangulation(f, t, 1));
      MVertex *v2 = hex.getVertex(hex_facet_triangulation(f, t, 2));
      add_value_to_multiset(hash_tableA, Facet(v0, v1, v2));
    }
  }
}

// Store the hex facet diagonals in TableB
void Recombinator::build_hash_tableB(const Hex &hex)
{
  for(unsigned int i = 0; i < 12; ++i) {
    MVertex *v0 = hex.getVertex(hex_facet_diagonal[i][0]);
    MVertex *v1 = hex.getVertex(hex_facet_diagonal[i][1]);
    add_value_to_multiset(hash_tableB, Diagonal(v0, v1));
  }
}

// Store the hex edges in TableC
void Recombinator::build_hash_tableC(const Hex &hex)
{
  for(unsigned int e = 0; e < 12; ++e) {
    MVertex *v0 = hex.getVertex(hex_edge_to_vertex[e][0]);
    MVertex *v1 = hex.getVertex(hex_edge_to_vertex[e][1]);
    add_value_to_multiset(hash_tableC, Diagonal(v0, v1));
  }
}

void Recombinator::print_hash_tableA()
{
  std::multiset<Facet>::iterator it;

  for(it = hash_tableA.begin(); it != hash_tableA.end(); it++) {
    printf("%lld\n", it->get_hash());
  }
}

void Recombinator::print_segment(const SPoint3 &p1, const SPoint3 &p2,
                                 std::ofstream &file)
{
  file << "SL (" << p1.x() << ", " << p1.y() << ", " << p1.z() << ", " << p2.x()
       << ", " << p2.y() << ", " << p2.z() << ")"
       << "{10, 20};\n";
}

double Recombinator::scaled_jacobian(MVertex *a, MVertex *b, MVertex *c,
                                     MVertex *d)
{
  SVector3 ab(a->point(), b->point());
  SVector3 ac(a->point(), c->point());
  SVector3 ad(a->point(), d->point());

  double l_ab = ab.norm();
  double l_ac = ac.norm();
  double l_ad = ad.norm();

  double val = dot(ab, crossprod(ac, ad));
  return val / (l_ab * l_ac * l_ad);
}

/*double Recombinator::scaled_jacobian_face(MVertex* a,MVertex* b,MVertex*
c,MVertex* d){ double j1, j2, j3, j4;

  j1 = std::abs(scaled_jacobian(a,b,d,c));
  j2 = std::abs(scaled_jacobian(b,c,a,d));
  j3 = std::abs(scaled_jacobian(c,d,b,a));
  j4 = std::abs(scaled_jacobian(d,a,c,b));

  return 1-2*(j1+j2+j3+j4)/4;
}*/

double Recombinator::max_scaled_jacobian(MElement *element, int &index)
{
  double val;
  double j1, j2, j3, j4;
  MVertex *a, *b, *c, *d;

  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);

  j1 = scaled_jacobian(a, b, c, d);
  j2 = scaled_jacobian(b, c, d, a);
  j3 = scaled_jacobian(c, d, a, b);
  j4 = scaled_jacobian(d, a, b, c);

  if(j1 >= j2 && j1 >= j3 && j1 >= j4) {
    index = 0;
    val = j1;
  }
  else if(j2 >= j3 && j2 >= j4 && j2 >= j1) {
    index = 1;
    val = j2;
  }
  else if(j3 >= j4 && j3 >= j1 && j3 >= j2) {
    index = 2;
    val = j3;
  }
  else {
    index = 3;
    val = j4;
  }

  return val;
}

double Recombinator::min_scaled_jacobian(Hex &hex)
{
  MVertex *a = hex.getVertex(0);
  MVertex *b = hex.getVertex(1);
  MVertex *c = hex.getVertex(2);
  MVertex *d = hex.getVertex(3);
  MVertex *e = hex.getVertex(4);
  MVertex *f = hex.getVertex(5);
  MVertex *g = hex.getVertex(6);
  MVertex *h = hex.getVertex(7);

  double j1 = scaled_jacobian(a, b, d, e);
  double j2 = scaled_jacobian(b, c, a, f);
  double j3 = scaled_jacobian(c, d, b, g);
  double j4 = scaled_jacobian(d, a, c, h);
  double j5 = scaled_jacobian(e, h, f, a);
  double j6 = scaled_jacobian(f, e, g, b);
  double j7 = scaled_jacobian(g, f, h, c);
  double j8 = scaled_jacobian(h, g, e, d);

  std::vector<double> jacobians;
  jacobians.push_back(j1);
  jacobians.push_back(j2);
  jacobians.push_back(j3);
  jacobians.push_back(j4);
  jacobians.push_back(j5);
  jacobians.push_back(j6);
  jacobians.push_back(j7);
  jacobians.push_back(j8);

  double min = DBL_MAX;
  double max = DBL_MIN;
  for(unsigned int i = 0; i < 8; i++) {
    min = std::min(min, jacobians[i]);
    max = std::max(max, jacobians[i]);
  }
  if(max < 0) min = -max; // Why ? Why is there no test on min < -max ?? Jeanne

  /*MHexahedron *h1 = new MHexahedron(a, b, c, d, e, f, g, h);
  MHexahedron *h2 = new MHexahedron(e, f, g, h, a, b, c, d);
  double min1 = jacobianBasedQuality::minScaledJacobian(h1);
  double min2 = jacobianBasedQuality::minIGEMeasure(h2);
  for(i=0;i<8;i++){
    file << jacobians[i] << " ";
  }
  file << min << " " << min1 << " " << min2 << std::endl;
  //file << min << " " << min1 << " " << min2 << std::endl;
  delete h1;
  delete h2;

  double Min = std::max(min1,min2);*/ // fordebug

  // return min > Min+.2 ? min : 0;

  /*j1 = scaled_jacobian_face(a,b,c,d);
  j2 = scaled_jacobian_face(e,f,g,h);
  j3 = scaled_jacobian_face(a,b,f,e);
  j4 = scaled_jacobian_face(b,c,g,f);
  j5 = scaled_jacobian_face(c,d,h,g);
  j6 = scaled_jacobian_face(d,a,e,h);

  //Msg::Info("%g | %g %g %g %g %g %g", min, j1, j2, j3, j4, j5, j6);

  jacobians.clear();
  jacobians.push_back(j1);
  jacobians.push_back(j2);
  jacobians.push_back(j3);
  jacobians.push_back(j4);
  jacobians.push_back(j5);
  jacobians.push_back(j6);
  for(i=0;i<6;i++){
    min = std::min(min, jacobians[i]);
  }*/ // trying to have plane faces

  return min;
}

/*******************************************/
/****************class Prism****************/
/*******************************************/

Prism::Prism() {}

Prism::Prism(MVertex *a2, MVertex *b2, MVertex *c2, MVertex *d2, MVertex *e2,
             MVertex *f2)
{
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
}

Prism::~Prism() {}

double Prism::get_quality() const { return quality; }

void Prism::set_quality(double new_quality) { quality = new_quality; }

MVertex *Prism::get_a() { return a; }

MVertex *Prism::get_b() { return b; }

MVertex *Prism::get_c() { return c; }

MVertex *Prism::get_d() { return d; }

MVertex *Prism::get_e() { return e; }

MVertex *Prism::get_f() { return f; }

void Prism::set_vertices(MVertex *a2, MVertex *b2, MVertex *c2, MVertex *d2,
                         MVertex *e2, MVertex *f2)
{
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
}

bool Prism::operator<(const Prism &prism) const
{
  return quality > prism.get_quality();
}

/***************************************************/
/****************class Supplementary****************/
/***************************************************/

Supplementary::Supplementary() {}

Supplementary::~Supplementary() {}

void Supplementary::execute()
{
  GRegion *gr;
  GModel *model = GModel::current();
  GModel::riter it;

  for(it = model->firstRegion(); it != model->lastRegion(); it++) {
    gr = *it;
    if(gr->getNumMeshElements() > 0) { execute(gr); }
  }
}

void Supplementary::execute(GRegion *gr)
{
  unsigned int i;
  MElement *element;
  MVertex *a, *b, *c, *d;
  MVertex *e, *f, *g, *h;

  printf("................PRISMS................\n");
  build_tuples(gr);
  init_markings(gr);

  build_vertex_to_vertices(gr);
  build_vertex_to_tetrahedra(gr);
  printf("connectivity\n");

  // file.open("qualPri.txt", std::fstream::out); //fordebug

  potential.clear();
  pattern(gr);
  printf("pattern\n");

  // file.close(); //fordebug

  hash_tableA.clear();
  hash_tableB.clear();
  hash_tableC.clear();
  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(eight(element)) {
      a = element->getVertex(0);
      b = element->getVertex(1);
      c = element->getVertex(2);
      d = element->getVertex(3);
      e = element->getVertex(4);
      f = element->getVertex(5);
      g = element->getVertex(6);
      h = element->getVertex(7);

      build_hash_tableA(a, b, c, d);
      build_hash_tableA(e, f, g, h);
      build_hash_tableA(a, b, f, e);
      build_hash_tableA(b, c, g, f);
      build_hash_tableA(d, c, g, h);
      build_hash_tableA(d, a, e, h);

      build_hash_tableB(a, b, c, d);
      build_hash_tableB(e, f, g, h);
      build_hash_tableB(a, b, f, e);
      build_hash_tableB(b, c, g, f);
      build_hash_tableB(d, c, g, h);
      build_hash_tableB(d, a, e, h);

      build_hash_tableC(Diagonal(a, b));
      build_hash_tableC(Diagonal(b, c));
      build_hash_tableC(Diagonal(c, d));
      build_hash_tableC(Diagonal(d, a));
      build_hash_tableC(Diagonal(e, f));
      build_hash_tableC(Diagonal(f, g));
      build_hash_tableC(Diagonal(g, h));
      build_hash_tableC(Diagonal(h, e));
      build_hash_tableC(Diagonal(a, e));
      build_hash_tableC(Diagonal(b, f));
      build_hash_tableC(Diagonal(c, g));
      build_hash_tableC(Diagonal(d, h));
    }
  }

  std::sort(potential.begin(), potential.end());

  merge(gr);

  rearrange(gr);

  statistics(gr);

  create_quads_on_boundary(gr);
}

void Supplementary::init_markings(GRegion *gr)
{
  unsigned int i;
  MElement *element;

  markings.clear();

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(four(element)) {
      markings.insert(std::pair<MElement *, bool>(element, false));
    }
  }
}

void Supplementary::pattern(GRegion *gr)
{
  size_t i;
  int j, k;
  double quality;
  MElement *element;
  MVertex *a, *b, *c, *d;
  MVertex *p, *q;
  std::vector<MVertex *> vertices;
  std::vector<MVertex *> already;
  std::set<MVertex *> bin1;
  std::set<MVertex *> bin2;
  vertex_set_itr it1;
  vertex_set_itr it2;
  Prism prism;

  vertices.resize(3);

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(four(element)) {
      for(j = 0; j < 4; j++) {
        a = element->getVertex(j);
        vertices[0] = element->getVertex((j + 1) % 4);
        vertices[1] = element->getVertex((j + 2) % 4);
        vertices[2] = element->getVertex((j + 3) % 4);
        for(k = 0; k < 3; k++) {
          b = vertices[k % 3];
          c = vertices[(k + 1) % 3];
          d = vertices[(k + 2) % 3];
          already.clear();
          already.push_back(a);
          already.push_back(b);
          already.push_back(c);
          already.push_back(d);
          bin1.clear();
          bin2.clear();
          find(b, d, already, bin1);
          find(c, d, already, bin2);
          for(it1 = bin1.begin(); it1 != bin1.end(); it1++) {
            p = *it1;
            for(it2 = bin2.begin(); it2 != bin2.end(); it2++) {
              q = *it2;
              if(p != q && linked(p, q)) {
                prism = Prism(a, b, c, d, p, q);
                quality = min_scaled_jacobian(prism);
                prism.set_quality(quality);
                if(valid(prism)) { potential.push_back(prism); }
              }
            }
          }
        }
      }
    }
  }
}

void Supplementary::merge(GRegion *gr)
{
  unsigned int i;
  int count;
  bool flag;
  double threshold;
  double quality;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;
  MElement *element;
  std::set<MElement *> parts;
  std::vector<MTetrahedron *> opt;
  element_set_itr it;
  std::map<MElement *, bool>::iterator it2;
  Prism prism;

  count = 1;
  quality = 0.0;

  for(i = 0; i < potential.size(); i++) {
    prism = potential[i];

    threshold = 0.6;
    if(prism.get_quality() < threshold) { break; }

    a = prism.get_a();
    b = prism.get_b();
    c = prism.get_c();
    d = prism.get_d();
    e = prism.get_e();
    f = prism.get_f();

    parts.clear();
    find(a, prism, parts);
    find(b, prism, parts);
    find(c, prism, parts);
    find(d, prism, parts);
    find(e, prism, parts);
    find(f, prism, parts);

    flag = 1;
    for(it = parts.begin(); it != parts.end(); it++) {
      element = *it;
      it2 = markings.find(element);
      if(it2->second == 1 && !sliver(element, prism)) {
        flag = 0;
        break;
      }
    }
    if(!flag) continue;

    if(!valid(prism, parts)) { continue; }

    if(!conformityA(prism)) { continue; }

    if(!conformityB(prism)) { continue; }

    if(!conformityC(prism)) { continue; }

    if(!faces_statuquo(prism)) { continue; }

    // printf("%d - %d/%d -
    // %f\n",count,i,(int)potential.size(),prism.get_quality());
    quality = quality + prism.get_quality();
    for(it = parts.begin(); it != parts.end(); it++) {
      element = *it;
      it2 = markings.find(element);
      it2->second = 1;
    }
    gr->addPrism(new MPrism(a, b, c, d, e, f));
    build_hash_tableA(prism);
    build_hash_tableB(prism);
    build_hash_tableC(prism);
    count++;
  }

  opt.clear();
  opt.resize(gr->tetrahedra.size());
  opt = gr->tetrahedra;
  gr->tetrahedra.clear();

  for(i = 0; i < opt.size(); i++) {
    element = (MElement *)(opt[i]);
    it2 = markings.find(element);
    if(it2->second == 0) { gr->tetrahedra.push_back(opt[i]); }
    else {
      delete opt[i];
    }
  }

  printf("prisms average quality (0->1) : %f\n", quality / count);
}

void Supplementary::rearrange(GRegion *gr)
{
  size_t i;
  MElement *element;

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    element->setVolumePositive();
  }
}

void Supplementary::statistics(GRegion *gr)
{
  size_t i;
  int all_nbr, prism_nbr;
  double all_volume, prism_volume, volume;
  MElement *element;

  all_nbr = 0;
  prism_nbr = 0;
  all_volume = 0.0;
  prism_volume = 0.0;

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    volume = element->getVolume();

    if(six(element)) {
      prism_nbr = prism_nbr + 1;
      prism_volume = prism_volume + volume;
    }

    all_nbr = all_nbr + 1;
    all_volume = all_volume + volume;
  }

  printf("percentage of prisms (number) : %.2f\n", prism_nbr * 100.0 / all_nbr);
  printf("percentage of prisms (volume) : %.2f\n",
         prism_volume * 100.0 / all_volume);
}

void Supplementary::build_tuples(GRegion *gr)
{
  unsigned int i;
  MVertex *a, *b, *c;
  MElement *element;
  GFace *gf;

  tuples.clear();
  triangles.clear();

  std::vector<GFace *> faces = gr->faces();
  std::vector<GFace *>::iterator it;

  for(it = faces.begin(); it != faces.end(); it++) {
    gf = *it;

    for(i = 0; i < gf->getNumMeshElements(); i++) {
      element = gf->getMeshElement(i);

      if(element->getNumVertices() == 3) {
        a = element->getVertex(0);
        b = element->getVertex(1);
        c = element->getVertex(2);

        tuples.insert(Tuple(a, b, c, element, gf));
      }
    }
  }
}

void Supplementary::create_quads_on_boundary(GRegion *gr)
{
  unsigned int i;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;
  MElement *element;
  GFace *gf;
  std::vector<MElement *> opt;
  element_set_itr it2;

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);

    if(element->getNumVertices() == 6) {
      a = element->getVertex(0);
      b = element->getVertex(1);
      c = element->getVertex(2);
      d = element->getVertex(3);
      e = element->getVertex(4);
      f = element->getVertex(5);

      create_quads_on_boundary(a, d, e, b);
      create_quads_on_boundary(a, d, f, c);
      create_quads_on_boundary(b, e, f, c);
    }
  }

  std::vector<GFace *> faces = gr->faces();
  std::vector<GFace *>::iterator it;

  for(it = faces.begin(); it != faces.end(); it++) {
    gf = *it;

    opt.clear();

    for(i = 0; i < gf->getNumMeshElements(); i++) {
      element = gf->getMeshElement(i);

      if(element->getNumVertices() == 3) {
        it2 = triangles.find(element);
        if(it2 == triangles.end()) { opt.push_back(element); }
      }
    }

    gf->triangles.clear();

    for(i = 0; i < opt.size(); i++) {
      gf->triangles.push_back((MTriangle *)opt[i]);
    }
  }
}

void Supplementary::create_quads_on_boundary(MVertex *a, MVertex *b, MVertex *c,
                                             MVertex *d)
{
  bool flag1, flag2;
  MElement *element1, *element2;
  GFace *gf1; //,*gf2;
  Tuple tuple1, tuple2;
  std::multiset<Tuple>::iterator it1;
  std::multiset<Tuple>::iterator it2;

  gf1 = NULL;
  // gf2 = NULL;

  tuple1 = Tuple(a, b, c);
  tuple2 = Tuple(c, d, a);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1 != tuples.end()) {
    if(tuple1.get_hash() != it1->get_hash()) { break; }

    if(tuple1.same_vertices(*it1)) {
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2 != tuples.end()) {
    if(tuple2.get_hash() != it2->get_hash()) { break; }

    if(tuple2.same_vertices(*it2)) {
      flag2 = 1;
      element2 = it2->get_element();
      // gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2) {
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a, b, c, d));
  }

  tuple1 = Tuple(a, b, d);
  tuple2 = Tuple(b, c, d);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1 != tuples.end()) {
    if(tuple1.get_hash() != it1->get_hash()) { break; }

    if(tuple1.same_vertices(*it1)) {
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2 != tuples.end()) {
    if(tuple2.get_hash() != it2->get_hash()) { break; }

    if(tuple2.same_vertices(*it2)) {
      flag2 = 1;
      element2 = it2->get_element();
      // gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2) {
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a, b, c, d));
  }
}

bool Supplementary::four(MElement *element)
{
  if(element->getNumVertices() == 4)
    return 1;
  else
    return 0;
}

bool Supplementary::five(MElement *element)
{
  if(element->getNumVertices() == 5)
    return 1;
  else
    return 0;
}

bool Supplementary::six(MElement *element)
{
  if(element->getNumVertices() == 6)
    return 1;
  else
    return 0;
}

bool Supplementary::eight(MElement *element)
{
  if(element->getNumVertices() == 8)
    return 1;
  else
    return 0;
}

bool Supplementary::sliver(MElement *element, Prism prism)
{
  bool val;
  bool flag1, flag2, flag3, flag4;
  MVertex *a, *b, *c, *d;

  val = 0;
  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);

  flag1 =
    inclusion(a, prism.get_a(), prism.get_d(), prism.get_f(), prism.get_c());
  flag2 =
    inclusion(b, prism.get_a(), prism.get_d(), prism.get_f(), prism.get_c());
  flag3 =
    inclusion(c, prism.get_a(), prism.get_d(), prism.get_f(), prism.get_c());
  flag4 =
    inclusion(d, prism.get_a(), prism.get_d(), prism.get_f(), prism.get_c());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 =
    inclusion(a, prism.get_a(), prism.get_b(), prism.get_e(), prism.get_d());
  flag2 =
    inclusion(b, prism.get_a(), prism.get_b(), prism.get_e(), prism.get_d());
  flag3 =
    inclusion(c, prism.get_a(), prism.get_b(), prism.get_e(), prism.get_d());
  flag4 =
    inclusion(d, prism.get_a(), prism.get_b(), prism.get_e(), prism.get_d());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 =
    inclusion(a, prism.get_b(), prism.get_c(), prism.get_f(), prism.get_e());
  flag2 =
    inclusion(b, prism.get_b(), prism.get_c(), prism.get_f(), prism.get_e());
  flag3 =
    inclusion(c, prism.get_b(), prism.get_c(), prism.get_f(), prism.get_e());
  flag4 =
    inclusion(d, prism.get_b(), prism.get_c(), prism.get_f(), prism.get_e());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  return val;
}

bool Supplementary::valid(Prism prism, const std::set<MElement *> &parts)
{
  bool ok1, ok2, ok3, ok4;
  bool flag1A, flag1B, flag1C, flag1D;
  bool flag2A, flag2B, flag2C, flag2D;
  bool flag3A, flag3B, flag3C, flag3D;
  bool flag4, flag5;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  flag1A = inclusion(a, d, f, parts);
  flag1B = inclusion(a, f, c, parts);
  flag1C = inclusion(a, c, d, parts);
  flag1D = inclusion(c, d, f, parts);
  ok1 = (flag1A && flag1B) || (flag1C && flag1D);

  flag2A = inclusion(a, b, d, parts);
  flag2B = inclusion(b, d, e, parts);
  flag2C = inclusion(a, d, e, parts);
  flag2D = inclusion(a, b, e, parts);
  ok2 = (flag2A && flag2B) || (flag2C && flag2D);

  flag3A = inclusion(b, c, f, parts);
  flag3B = inclusion(b, e, f, parts);
  flag3C = inclusion(b, c, e, parts);
  flag3D = inclusion(c, e, f, parts);
  ok3 = (flag3A && flag3B) || (flag3C && flag3D);

  flag4 = inclusion(a, b, c, parts);
  flag5 = inclusion(d, e, f, parts);
  ok4 = flag4 && flag5;

  if(ok1 && ok2 && ok3 && ok4) { return 1; }
  else {
    return 0;
  }
}

// Need this awful terrible removed function from Recombinator for what is below
// ....
bool validFace(MVertex *a, MVertex *b, MVertex *c, MVertex *d,
               std::map<MVertex *, std::set<MElement *> > &vertexToElements)
{
  std::map<MVertex *, std::set<MElement *> >::iterator itElV[4];
  MVertex *faceV[4] = {a, b, c, d};
  for(int iV = 0; iV < 4; iV++) {
    itElV[iV] = vertexToElements.find(faceV[iV]);
  }
  size_t tris[4][3] = {{0, 1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2, 3}};
  size_t other[4] = {3, 1, 2, 0};
  size_t nbTris[4];
  std::set<MElement *> buf1, buf2;
  for(int iTri = 0; iTri < 4; iTri++) {
    // We count the number of elements sharing the considered triangle
    buf1.clear();
    std::set_intersection(
      itElV[tris[iTri][0]]->second.begin(), itElV[tris[iTri][0]]->second.end(),
      itElV[tris[iTri][1]]->second.begin(), itElV[tris[iTri][1]]->second.end(),
      std::inserter(buf1, buf1.end()));
    buf2.clear();
    std::set_intersection(
      buf1.begin(), buf1.end(), itElV[tris[iTri][2]]->second.begin(),
      itElV[tris[iTri][2]]->second.end(), std::inserter(buf2, buf2.end()));
    buf1.clear();
    std::set_difference(
      buf2.begin(), buf2.end(), itElV[other[iTri]]->second.begin(),
      itElV[other[iTri]]->second.end(), std::inserter(buf1, buf1.end()));
    nbTris[iTri] = buf1.size();
  }
  bool valid = false;
  // All sub-faces inside (2 elements)
  if(nbTris[0] == 2 && nbTris[1] == 2 && nbTris[2] == 0 && nbTris[3] == 0)
    valid = true;
  else if(nbTris[0] == 0 && nbTris[1] == 0 && nbTris[2] == 2 && nbTris[3] == 2)
    valid = true;
  // All sub-faces on the surface or facing a quad face (1 element)
  else if(nbTris[0] == 1 && nbTris[1] == 1 && nbTris[2] == 0 && nbTris[3] == 0)
    valid = true;
  else if(nbTris[0] == 0 && nbTris[1] == 0 && nbTris[2] == 1 && nbTris[3] == 1)
    valid = true;
  // Face is made of triangles on each side but they are nonconforming (OK for
  // recombination, but why do these exist??)
  else if(nbTris[0] == 1 && nbTris[1] == 1 && nbTris[2] == 1 && nbTris[3] == 1)
    valid = true;

  // Geometry: A face with 4 nodes on the boundary should be close enough to
  // planar
  int nbBndNodes = 0;
  if(a->onWhat()->dim() < 3) nbBndNodes++;
  if(b->onWhat()->dim() < 3) nbBndNodes++;
  if(c->onWhat()->dim() < 3) nbBndNodes++;
  if(d->onWhat()->dim() < 3) nbBndNodes++;
  if(nbBndNodes == 4) {
    SVector3 vec1 =
      SVector3(b->x() - a->x(), b->y() - a->y(), b->z() - a->z()).unit();
    SVector3 vec2 =
      SVector3(c->x() - a->x(), c->y() - a->y(), c->z() - a->z()).unit();
    SVector3 vec3 =
      SVector3(d->x() - a->x(), d->y() - a->y(), d->z() - a->z()).unit();

    SVector3 crossVec1Vec2 = crossprod(vec1, vec2);
    double angle = fabs(acos(dot(crossVec1Vec2, vec3)) * 180 / M_PI);
    double maxAngle = 15;
    if(fabs(angle - 90) > maxAngle) valid = false;
  }
  return valid;
}

bool validFaces(Prism &prism, Vertex2Elements &vertexToElements)
{
  bool v1, v2, v3;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  v1 = validFace(a, d, f, c, vertexToElements); // SHOULD CHECK GEOMETRY
  v2 = validFace(a, d, e, b, vertexToElements);
  v3 = validFace(b, c, f, e, vertexToElements);

  return v1 && v2 && v3;
}

bool Supplementary::valid(Prism prism)
{
  double k;
  double eta1, eta2, eta3;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  k = 0.000001;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  eta1 = eta(a, d, f, c);
  eta2 = eta(a, b, e, d);
  eta3 = eta(b, c, f, e);

  if(eta1 > k && eta2 > k && eta3 > k) {
    return validFaces(prism, vertex_to_tetrahedra);
  }
  else {
    return 0;
  }
}

double Supplementary::eta(MVertex *a, MVertex *b, MVertex *c, MVertex *d)
{
  double val;
  MQuadrangle *quad;

  quad = new MQuadrangle(a, b, c, d);
  val = quad->etaShapeMeasure();
  delete quad;
  return val;
}

bool Supplementary::linked(MVertex *v1, MVertex *v2)
{
  bool flag;
  Vertex2Vertices::iterator it;
  vertex_set_itr it2;

  it = vertex_to_vertices.find(v1);
  flag = 0;

  if(it != vertex_to_vertices.end()) {
    for(it2 = (it->second).begin(); it2 != (it->second).end(); it2++) {
      if(*it2 == v2) {
        flag = 1;
        break;
      }
    }
  }

  return flag;
}

void Supplementary::find(MVertex *v1, MVertex *v2,
                         const std::vector<MVertex *> &already,
                         std::set<MVertex *> &final)
{
  Vertex2Vertices::iterator it1;
  Vertex2Vertices::iterator it2;

  it1 = vertex_to_vertices.find(v1);
  it2 = vertex_to_vertices.find(v2);

  if(it1 != vertex_to_vertices.end() && it2 != vertex_to_vertices.end()) {
    intersection(it1->second, it2->second, already, final);
  }
}

void Supplementary::find(MVertex *getVertex, const Prism &prism,
                         std::set<MElement *> &final)
{
  bool flag1, flag2, flag3, flag4;
  MVertex *a, *b, *c, *d;
  Vertex2Elements::iterator it;
  element_set_itr it2;

  it = vertex_to_tetrahedra.find(getVertex);

  if(it != vertex_to_tetrahedra.end()) {
    for(it2 = (it->second).begin(); it2 != (it->second).end(); it2++) {
      a = (*it2)->getVertex(0);
      b = (*it2)->getVertex(1);
      c = (*it2)->getVertex(2);
      d = (*it2)->getVertex(3);

      flag1 = inclusion(a, prism);
      flag2 = inclusion(b, prism);
      flag3 = inclusion(c, prism);
      flag4 = inclusion(d, prism);

      if(flag1 && flag2 && flag3 && flag4) { final.insert(*it2); }
    }
  }
}

void Supplementary::intersection(const std::set<MVertex *> &bin1,
                                 const std::set<MVertex *> &bin2,
                                 const std::vector<MVertex *> &already,
                                 std::set<MVertex *> &final)
{
  size_t i;
  bool ok;
  std::set<MVertex *> temp;
  vertex_set_itr it;

  std::set_intersection(bin1.begin(), bin1.end(), bin2.begin(), bin2.end(),
                        std::inserter(temp, temp.end()));

  for(it = temp.begin(); it != temp.end(); it++) {
    ok = 1;

    for(i = 0; i < already.size(); i++) {
      if((*it) == already[i]) {
        ok = 0;
        break;
      }
    }

    if(ok) { final.insert(*it); }
  }
}

bool Supplementary::inclusion(MVertex *getVertex, Prism prism)
{
  bool flag;

  flag = 0;

  if(getVertex == prism.get_a())
    flag = 1;
  else if(getVertex == prism.get_b())
    flag = 1;
  else if(getVertex == prism.get_c())
    flag = 1;
  else if(getVertex == prism.get_d())
    flag = 1;
  else if(getVertex == prism.get_e())
    flag = 1;
  else if(getVertex == prism.get_f())
    flag = 1;

  return flag;
}

bool Supplementary::inclusion(MVertex *getVertex, MVertex *a, MVertex *b,
                              MVertex *c, MVertex *d)
{
  bool flag;

  flag = 0;

  if(getVertex == a)
    flag = 1;
  else if(getVertex == b)
    flag = 1;
  else if(getVertex == c)
    flag = 1;
  else if(getVertex == d)
    flag = 1;

  return flag;
}

bool Supplementary::inclusion(MVertex *v1, MVertex *v2, MVertex *v3,
                              const std::set<MElement *> &bin)
{
  bool ok;
  bool flag1, flag2, flag3;
  MVertex *a, *b, *c, *d;
  MElement *element;
  std::set<MElement *>::const_iterator it;

  ok = 0;

  for(it = bin.begin(); it != bin.end(); it++) {
    element = *it;

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);

    flag1 = inclusion(v1, a, b, c, d);
    flag2 = inclusion(v2, a, b, c, d);
    flag3 = inclusion(v3, a, b, c, d);

    if(flag1 && flag2 && flag3) {
      ok = 1;
      break;
    }
  }

  return ok;
}

bool Supplementary::inclusion(const Facet &facet)
{
  bool flag;
  std::multiset<Facet>::iterator it;

  it = hash_tableA.find(facet);
  flag = 0;

  while(it != hash_tableA.end()) {
    if(facet.get_hash() != it->get_hash()) { break; }

    if(facet.same_vertices(*it)) {
      flag = 1;
      break;
    }

    it++;
  }

  return flag;
}

bool Supplementary::inclusion(const Diagonal &diagonal)
{
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableB.find(diagonal);
  flag = 0;

  while(it != hash_tableB.end()) {
    if(diagonal.get_hash() != it->get_hash()) { break; }

    if(diagonal.same_vertices(*it)) {
      flag = 1;
      break;
    }

    it++;
  }

  return flag;
}

bool Supplementary::duplicate(const Diagonal &diagonal)
{
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableC.find(diagonal);
  flag = 0;

  while(it != hash_tableC.end()) {
    if(diagonal.get_hash() != it->get_hash()) { break; }

    if(diagonal.same_vertices(*it)) {
      flag = 1;
      break;
    }

    it++;
  }

  return flag;
}

bool Supplementary::conformityA(Prism prism)
{
  bool c1, c2, c3;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  c1 = conformityA(a, d, f, c);
  c2 = conformityA(a, d, e, b);
  c3 = conformityA(b, c, f, e);

  return c1 && c2 && c3;
}

bool Supplementary::conformityA(MVertex *a, MVertex *b, MVertex *c, MVertex *d)
{
  bool c1, c2, c3, c4;

  c1 = inclusion(Facet(a, b, c));
  c2 = inclusion(Facet(a, c, d));
  c3 = inclusion(Facet(a, b, d));
  c4 = inclusion(Facet(b, c, d));

  return (c1 && c2 && c3 && c4) || (!c1 && !c2 && !c3 && !c4);
}

bool Supplementary::conformityB(Prism prism)
{
  bool flag1;
  bool flag2;
  bool c1, c2, c3;
  bool c4, c5, c6;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  flag1 = inclusion(Diagonal(a, c));
  flag1 = flag1 || inclusion(Diagonal(d, f));
  flag1 = flag1 || inclusion(Diagonal(d, a));
  flag1 = flag1 || inclusion(Diagonal(f, c));
  flag1 = flag1 || inclusion(Diagonal(e, b));
  flag1 = flag1 || inclusion(Diagonal(d, e));
  flag1 = flag1 || inclusion(Diagonal(e, f));
  flag1 = flag1 || inclusion(Diagonal(a, b));
  flag1 = flag1 || inclusion(Diagonal(b, c));

  c1 = inclusion(Diagonal(a, f));
  c2 = inclusion(Diagonal(d, c));
  flag2 = (c1 && !c2) || (!c1 && c2);
  c3 = inclusion(Diagonal(a, e));
  c4 = inclusion(Diagonal(b, d));
  flag2 = flag2 || (c3 && !c4) || (!c3 && c4);
  c5 = inclusion(Diagonal(b, f));
  c6 = inclusion(Diagonal(c, e));
  flag2 = flag2 || (c5 && !c6) || (!c5 && c6);

  if(flag1 || flag2) { return 0; }
  else {
    return 1;
  }
}

bool Supplementary::conformityC(Prism prism)
{
  bool flag;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  flag = duplicate(Diagonal(a, f));
  flag = flag || duplicate(Diagonal(d, c));
  flag = flag || duplicate(Diagonal(a, e));
  flag = flag || duplicate(Diagonal(b, d));
  flag = flag || duplicate(Diagonal(b, f));
  flag = flag || duplicate(Diagonal(c, e));

  if(flag) { return 0; }
  else {
    return 1;
  }
}

bool Supplementary::faces_statuquo(Prism prism)
{
  bool c1, c2, c3;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  c1 = faces_statuquo(a, d, f, c);
  c2 = faces_statuquo(a, d, e, b);
  c3 = faces_statuquo(b, c, f, e);

  return c1 && c2 && c3;
}

bool Supplementary::faces_statuquo(MVertex *a, MVertex *b, MVertex *c,
                                   MVertex *d)
{
  bool flag1, flag2;
  GFace *gf1, *gf2;
  std::multiset<Tuple>::iterator it1;
  std::multiset<Tuple>::iterator it2;

  bool ok = 1;

  gf1 = NULL;
  gf2 = NULL;

  Tuple tuple1(a, b, c);
  Tuple tuple2(c, d, a);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1 != tuples.end()) {
    if(tuple1.get_hash() != it1->get_hash()) { break; }

    if(tuple1.same_vertices(*it1)) {
      flag1 = 1;
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2 != tuples.end()) {
    if(tuple2.get_hash() != it2->get_hash()) { break; }

    if(tuple2.same_vertices(*it2)) {
      flag2 = 1;
      gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2) {
    if(gf1 != gf2) { ok = 0; }
  }

  tuple1 = Tuple(a, b, d);
  tuple2 = Tuple(b, c, d);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1 != tuples.end()) {
    if(tuple1.get_hash() != it1->get_hash()) { break; }

    if(tuple1.same_vertices(*it1)) {
      flag1 = 1;
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2 != tuples.end()) {
    if(tuple2.get_hash() != it2->get_hash()) { break; }

    if(tuple2.same_vertices(*it2)) {
      flag2 = 1;
      gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2) {
    if(gf1 != gf2) { ok = 0; }
  }

  return ok;
}

void Supplementary::build_vertex_to_vertices(GRegion *gr)
{
  std::set<MVertex *> bin;
  vertex_to_vertices.clear();

  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *element = gr->getMeshElement(i);
    if(four(element)) {
      for(std::size_t j = 0; j < element->getNumVertices(); j++) {
        MVertex *a = element->getVertex(j);
        MVertex *b = element->getVertex((j + 1) % 4);
        MVertex *c = element->getVertex((j + 2) % 4);
        MVertex *d = element->getVertex((j + 3) % 4);

        Vertex2Vertices::iterator it = vertex_to_vertices.find(a);
        if(it != vertex_to_vertices.end()) {
          it->second.insert(b);
          it->second.insert(c);
          it->second.insert(d);
        }
        else {
          bin.clear();
          bin.insert(b);
          bin.insert(c);
          bin.insert(d);
          vertex_to_vertices.insert(
            std::pair<MVertex *, std::set<MVertex *> >(a, bin));
        }
      }
    }
  }
}

void Supplementary::build_vertex_to_tetrahedra(GRegion *gr)
{
  std::set<MElement *> bin;
  vertex_to_tetrahedra.clear();

  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *element = gr->getMeshElement(i);
    if(four(element)) {
      for(std::size_t j = 0; j < element->getNumVertices(); j++) {
        MVertex *getVertex = element->getVertex(j);

        Vertex2Elements::iterator it = vertex_to_tetrahedra.find(getVertex);
        if(it != vertex_to_tetrahedra.end()) { it->second.insert(element); }
        else {
          bin.clear();
          bin.insert(element);
          vertex_to_tetrahedra.insert(
            std::pair<MVertex *, std::set<MElement *> >(getVertex, bin));
        }
      }
    }
  }
}

void Supplementary::build_hash_tableA(Prism prism)
{
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  build_hash_tableA(a, d, f, c);
  build_hash_tableA(a, d, e, b);
  build_hash_tableA(b, c, f, e);
}

void Supplementary::build_hash_tableA(MVertex *a, MVertex *b, MVertex *c,
                                      MVertex *d)
{
  build_hash_tableA(Facet(a, b, c));
  build_hash_tableA(Facet(a, c, d));
  build_hash_tableA(Facet(a, b, d));
  build_hash_tableA(Facet(b, d, c));
}

void Supplementary::build_hash_tableA(const Facet &facet)
{
  bool flag;
  std::multiset<Facet>::iterator it;

  it = hash_tableA.find(facet);
  flag = 1;

  while(it != hash_tableA.end()) {
    if(facet.get_hash() != it->get_hash()) { break; }

    if(facet.same_vertices(*it)) {
      flag = 0;
      break;
    }

    it++;
  }

  if(flag) { hash_tableA.insert(facet); }
}

void Supplementary::build_hash_tableB(Prism prism)
{
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  build_hash_tableB(a, d, f, c);
  build_hash_tableB(a, d, e, b);
  build_hash_tableB(b, e, f, c);
}

void Supplementary::build_hash_tableB(MVertex *a, MVertex *b, MVertex *c,
                                      MVertex *d)
{
  build_hash_tableB(Diagonal(a, c));
  build_hash_tableB(Diagonal(b, d));
}

void Supplementary::build_hash_tableB(const Diagonal &diagonal)
{
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableB.find(diagonal);
  flag = 1;

  while(it != hash_tableB.end()) {
    if(diagonal.get_hash() != it->get_hash()) { break; }

    if(diagonal.same_vertices(*it)) {
      flag = 0;
      break;
    }

    it++;
  }

  if(flag) { hash_tableB.insert(diagonal); }
}

void Supplementary::build_hash_tableC(Prism prism)
{
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  build_hash_tableC(Diagonal(a, d));
  build_hash_tableC(Diagonal(d, f));
  build_hash_tableC(Diagonal(f, c));
  build_hash_tableC(Diagonal(a, c));
  build_hash_tableC(Diagonal(e, b));
  build_hash_tableC(Diagonal(d, e));
  build_hash_tableC(Diagonal(f, e));
  build_hash_tableC(Diagonal(a, b));
  build_hash_tableC(Diagonal(b, c));
}

void Supplementary::build_hash_tableC(const Diagonal &diagonal)
{
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableC.find(diagonal);
  flag = 1;

  while(it != hash_tableC.end()) {
    if(diagonal.get_hash() != it->get_hash()) { break; }

    if(diagonal.same_vertices(*it)) {
      flag = 0;
      break;
    }

    it++;
  }

  if(flag) { hash_tableC.insert(diagonal); }
}

double Supplementary::scaled_jacobian(MVertex *a, MVertex *b, MVertex *c,
                                      MVertex *d)
{
  double val;
  double l1, l2, l3, l4;
  SVector3 vec1, vec2, vec3, vec4;
  static double coeff = 2 / std::sqrt(3);

  vec1 = SVector3(b->x() - a->x(), b->y() - a->y(), b->z() - a->z());
  vec2 = SVector3(c->x() - a->x(), c->y() - a->y(), c->z() - a->z());
  vec3 = SVector3(d->x() - a->x(), d->y() - a->y(), d->z() - a->z());
  vec4 = SVector3(b->x() - c->x(), b->y() - c->y(), b->z() - c->z());

  l1 = vec1.norm();
  l2 = vec2.norm();
  l3 = vec3.norm();
  l4 = vec4.norm();

  val = dot(vec1, crossprod(vec2, vec3));
  return val * (1 / (l1 * l2 * l3) + 1 / (l1 * l4 * l3) + 1 / (l2 * l4 * l3)) /
         3 * coeff;
}

double Supplementary::min_scaled_jacobian(Prism prism)
{
  int i;
  double min, max;
  double j1, j2, j3, j4, j5, j6;
  MVertex *a, *b, *c;
  MVertex *d, *e, *f;
  std::vector<double> jacobians;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  j1 = scaled_jacobian(a, b, c, d);
  j2 = scaled_jacobian(b, c, a, e);
  j3 = scaled_jacobian(c, a, b, f);
  j4 = scaled_jacobian(d, f, e, a);
  j5 = scaled_jacobian(e, d, f, b);
  j6 = scaled_jacobian(f, e, d, c);

  jacobians.push_back(j1);
  jacobians.push_back(j2);
  jacobians.push_back(j3);
  jacobians.push_back(j4);
  jacobians.push_back(j5);
  jacobians.push_back(j6);

  min = 1000000000.0;
  max = -1000000000.0;
  for(i = 0; i < 6; i++) {
    min = std::min(min, jacobians[i]);
    max = std::max(max, jacobians[i]);
  }
  if(max < 0) min = -max;

  /*MPrism *p1 = new MPrism(a, b, c, d, e, f);
  MPrism *p2 = new MPrism(d, e, f, a, b, c);
  double min1 = jacobianBasedQuality::minScaledJacobian(p1);
  double min2 = jacobianBasedQuality::minIGEMeasure(p2);
  for(i=0;i<6;i++){
    file << jacobians[i] << " ";
  }
  file << min << " " << min1 << " " << min2 << std::endl;
  delete p1;
  delete p2;*/ // fordebug

  return min;
}

/********************************************/
/****************class PostOp****************/
/********************************************/

PostOp::PostOp() {}

PostOp::~PostOp() {}

void PostOp::execute(int level, int conformity)
{
  GRegion *gr;
  GModel *model = GModel::current();
  GModel::riter it;

  for(it = model->firstRegion(); it != model->lastRegion(); it++) {
    gr = *it;
    if(gr->getNumMeshElements() > 0) { execute(gr, level, conformity); }
  }
}

void PostOp::executeNew(GRegion *gr)
{
  printf("..............PYRAMIDS NEW................\n");
  build_vertex_to_tetrahedra(gr);
  build_vertex_to_hexPrism(gr);

  std::set<MElement *> tetrahedra;
  tetrahedra.insert(&(gr->tetrahedra[0]),
                    &(gr->tetrahedra[0]) + gr->tetrahedra.size());

  std::set<Facet> boundaryTriangles;
  std::set<Facet> pendingTriangles;
  std::vector<MElement *> mesh;

  int n = 0;

  while(tetrahedra.size()) {
    MElement *t = *tetrahedra.begin();

    MVertex *a = t->getVertex(0);
    MVertex *b = t->getVertex(1);
    MVertex *c = t->getVertex(2);
    MVertex *d = t->getVertex(3);

    boundaryTriangles.clear();
    pendingTriangles.clear();
    pendingTriangles.insert(Facet(a, b, c));
    pendingTriangles.insert(Facet(a, c, d));
    pendingTriangles.insert(Facet(a, d, b));
    pendingTriangles.insert(Facet(b, d, c));

    mesh.clear();
    tetrahedra.erase(t);

    while(pendingTriangles.size()) {
      Facet f = *pendingTriangles.begin();

      std::set<MElement *> potential;
      find_tetrahedra(f.get_a(), f.get_b(), f.get_c(), potential);

      element_set_itr it = potential.begin();
      while(it != potential.end()) {
        if(tetrahedra.find(*it) == tetrahedra.end())
          potential.erase(it++);
        else
          ++it;
      }

      if(potential.size() > 1) {
        Msg::Error("I didn't expect that. Aaaah, don't know what I should do");
      }
      else if(potential.size() == 1) {
        MElement *t = *potential.begin();

        MVertex *a = t->getVertex(0);
        MVertex *b = t->getVertex(1);
        MVertex *c = t->getVertex(2);
        MVertex *d = t->getVertex(3);

        removeElseAdd(pendingTriangles, a, b, c);
        removeElseAdd(pendingTriangles, a, c, d);
        removeElseAdd(pendingTriangles, a, d, b);
        removeElseAdd(pendingTriangles, b, d, c);

        tetrahedra.erase(t);
      }
      else {
        boundaryTriangles.insert(f);
        pendingTriangles.erase(f);
        mesh.push_back(new MTriangle(f.get_a(), f.get_b(), f.get_c()));
      }
    }

    std::ostringstream oss;
    oss << "boundary-" << ++n << ".msh";
    writeMSH(oss.str().c_str(), mesh);

    //////////////////////////
    mesh.clear();
    pendingTriangles = boundaryTriangles;

    while(pendingTriangles.size()) {
      Facet f = *pendingTriangles.begin();
      MFace quad = find_quadFace(f.get_a(), f.get_b(), f.get_c());
      if(!quad.getNumVertices()) {
        mesh.push_back(new MTriangle(f.get_a(), f.get_b(), f.get_c()));
        pendingTriangles.erase(f);
      }
      else {
        // TODO erase other pending triangle
        mesh.push_back(new MQuadrangle(quad.getVertex(0), quad.getVertex(1),
                                       quad.getVertex(2), quad.getVertex(3)));
        Facet f =
          Facet(quad.getVertex(0), quad.getVertex(1), quad.getVertex(2));
        pendingTriangles.erase(f);
        f = Facet(quad.getVertex(1), quad.getVertex(2), quad.getVertex(3));
        pendingTriangles.erase(f);
        f = Facet(quad.getVertex(2), quad.getVertex(3), quad.getVertex(0));
        pendingTriangles.erase(f);
        f = Facet(quad.getVertex(3), quad.getVertex(0), quad.getVertex(1));
        pendingTriangles.erase(f);
      }
    }

    std::ostringstream oss2;
    oss2 << "boundaryQ-" << n << ".msh";
    writeMSH(oss2.str().c_str(), mesh);

    // make pyramids
  }
}

void PostOp::removeElseAdd(std::set<Facet> &set, MVertex *a, MVertex *b,
                           MVertex *c)
{
  Facet f = Facet(a, b, c);
  if(set.find(f) != set.end()) { set.erase(f); }
  else {
    set.insert(f);
  }
}

void PostOp::writeMSH(const char *filename, std::vector<MElement *> &elements)
{
  std::set<MVertex *> vertices;
  for(std::size_t i = 0; i < elements.size(); ++i) {
    for(std::size_t k = 0; k < elements[i]->getNumVertices(); ++k)
      vertices.insert(elements[i]->getVertex(k));
  }

  FILE *f = fopen(filename, "w");

  fprintf(f, "$MeshFormat\n");
  fprintf(f, "2.2 0 8\n");
  fprintf(f, "$EndMeshFormat\n");

  fprintf(f, "$Nodes\n");
  fprintf(f, "%d\n", (int)vertices.size());
  vertex_set_itr it;
  int n = 0;
  for(it = vertices.begin(); it != vertices.end(); ++it) {
    fprintf(f, "%d %22.15E %22.15E %22.15E\n", ++n, (*it)->x(), (*it)->y(),
            (*it)->z());
    (*it)->setIndex(n);
  }
  fprintf(f, "$EndNodes\n");

  fprintf(f, "$Elements\n");
  fprintf(f, "%d\n", (int)elements.size());
  for(std::size_t i = 0; i < elements.size(); ++i) {
    fprintf(f, "%d %d 0", elements[i]->getNum(), elements[i]->getTypeForMSH());
    for(std::size_t k = 0; k < elements[i]->getNumVertices(); ++k)
      fprintf(f, " %d", elements[i]->getVertex(k)->getIndex());
    fprintf(f, "\n");
  }
  fprintf(f, "$EndElements\n");

  fclose(f);
}

MFace PostOp::find_quadFace(MVertex *v1, MVertex *v2, MVertex *v3)
{
  Vertex2Elements::iterator it1;
  Vertex2Elements::iterator it2;
  Vertex2Elements::iterator it3;

  it1 = vertex_to_hexPrism.find(v1);
  it2 = vertex_to_hexPrism.find(v2);
  it3 = vertex_to_hexPrism.find(v3);

  std::set<MElement *> buf, final;

  if(it1 != vertex_to_tetrahedra.end() && it2 != vertex_to_tetrahedra.end() &&
     it3 != vertex_to_tetrahedra.end()) {
    intersection(it1->second, it2->second, buf);
    intersection(buf, it3->second, final);
  }

  if(final.size() > 1) Msg::Error("This shouldn't happen ...");

  element_set_itr it;
  for(it = final.begin(); it != final.end(); ++it) {
    MElement *el = *it;
    if(el->getType() == TYPE_PRI) {
      for(int i = 2; i < 5; ++i) {
        MFace f = el->getFace(i);
        matchQuadFace(f, v1, v2, v3);
        if(f.getNumVertices()) { return f; }
      }
    }
    else if(el->getType() == TYPE_HEX) {
      for(int i = 0; i < 6; ++i) {
        MFace f = el->getFace(i);
        matchQuadFace(f, v1, v2, v3);
        if(f.getNumVertices()) { return f; }
      }
    }
  }
  return MFace();
}

MVertex *PostOp::otherVertexQuadFace(MFace &f, MVertex *v1, MVertex *v2,
                                     MVertex *v3)
{
  int n = 0;
  MVertex *v = 0;
  for(int i = 0; i < 4; ++i) {
    if(f.getVertex(i) != v1 && f.getVertex(i) != v2 && f.getVertex(i) != v3) {
      ++n;
      v = f.getVertex(i);
    }
  }
  if(n == 1) return v;
  return NULL;
}

void PostOp::matchQuadFace(MFace &f, MVertex *v1, MVertex *v2, MVertex *v3)
{
  MVertex *vertices[3] = {v1, v2, v3};
  int n = 0, ind = -1;
  // MVertex *v;
  for(int i = 0; i < 4; ++i) {
    if(f.getVertex(i) != v1 && f.getVertex(i) != v2 && f.getVertex(i) != v3) {
      ++n;
      // v = f.getVertex(i);
      ind = i;
    }
  }
  if(n != 1) {
    f = MFace();
    return;
  }

  for(int i = 0; i < 3; ++i) {
    if(f.getVertex(ind + 1 % 4) == vertices[i]) {
      if(f.getVertex(ind + 2 % 4) == vertices[i + 1 % 3]) { return; }
      else {
        f =
          MFace(f.getVertex(3), f.getVertex(2), f.getVertex(1), f.getVertex(0));
      }
    }
  }
}

void PostOp::execute(GRegion *gr, int level, int conformity)
{
  printf("................PYRAMIDS................\n");
  estimate1 = 0;
  estimate2 = 0;
  iterations = 0;

  build_tuples(gr);

  if(level >= 2) {
    init_markings(gr);
    build_vertex_to_tetrahedra(gr);
    pyramids1(gr);
    rearrange(gr);
  }

  if(conformity == 2 || conformity == 3) {
    init_markings(gr);
    build_vertex_to_tetrahedra(gr);
    build_vertex_to_pyramids(gr);
    pyramids2(gr);
    rearrange(gr);
  }

  if(conformity == 3 || conformity == 4) {
    init_markings_hex(gr);
    build_vertex_to_tetrahedra(gr);
    build_vertex_to_pyramids(gr);
    split_hexahedra(gr);
    rearrange(gr);

    init_markings_pri(gr);
    build_vertex_to_tetrahedra(gr);
    build_vertex_to_pyramids(gr);
    split_prisms(gr);
    rearrange(gr);

    init_markings_pyr(gr);
    build_vertex_to_tetrahedra(gr);
    build_vertex_to_pyramids(gr);
    split_pyramids(gr);
    rearrange(gr);
  }

  if(conformity >= 1) {
    init_markings(gr);
    build_vertex_to_tetrahedra(gr);
    build_vertex_to_pyramids(gr);
    trihedra(gr);
    rearrange(gr);
  }

  statistics(gr);

  create_quads_on_boundary(gr);
}

void PostOp::init_markings_hex(GRegion *gr)
{
  unsigned int i;
  MElement *element;
  markings.clear();
  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(eight(element)) {
      markings.insert(std::pair<MElement *, bool>(element, false));
    }
  }
}

void PostOp::init_markings_pri(GRegion *gr)
{
  unsigned int i;
  MElement *element;
  markings.clear();
  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(six(element)) {
      markings.insert(std::pair<MElement *, bool>(element, false));
    }
  }
}

void PostOp::init_markings_pyr(GRegion *gr)
{
  unsigned int i;
  MElement *element;
  markings.clear();
  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(five(element)) {
      markings.insert(std::pair<MElement *, bool>(element, false));
    }
  }
}

void PostOp::init_markings(GRegion *gr)
{
  unsigned int i;
  MElement *element;

  markings.clear();

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(four(element) || five(element)) {
      markings.insert(std::pair<MElement *, bool>(element, false));
    }
  }
}

void PostOp::split_hexahedra(GRegion *gr)
{
  std::vector<MElement *> hexahedra;
  std::vector<MHexahedron *> opt;
  std::map<MElement *, bool>::iterator it;

  hexahedra.clear();

  for(size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *element = gr->getMeshElement(i);
    if(eight(element)) { hexahedra.push_back(element); }
  }

  for(size_t i = 0; i < hexahedra.size(); i++) {
    MElement *element = hexahedra[i];
    MVertex *a = element->getVertex(0);
    MVertex *b = element->getVertex(1);
    MVertex *c = element->getVertex(2);
    MVertex *d = element->getVertex(3);
    MVertex *e = element->getVertex(4);
    MVertex *f = element->getVertex(5);
    MVertex *g = element->getVertex(6);
    MVertex *h = element->getVertex(7);

    bool conform = true;
    conform &= (nonConformDiag(b, a, d, c, gr) == 0);
    if(conform) conform &= (nonConformDiag(e, f, g, h, gr) == 0);
    if(conform) conform &= (nonConformDiag(a, b, f, e, gr) == 0);
    if(conform) conform &= (nonConformDiag(b, c, g, f, gr) == 0);
    if(conform) conform &= (nonConformDiag(c, d, h, g, gr) == 0);
    if(conform) conform &= (nonConformDiag(d, a, e, h, gr) == 0);
    if(!conform) {
      double x = (a->x() + b->x() + c->x() + d->x() + e->x() + f->x() + g->x() +
                  h->x()) /
                 8.0;
      double y = (a->y() + b->y() + c->y() + d->y() + e->y() + f->y() + g->y() +
                  h->y()) /
                 8.0;
      double z = (a->z() + b->z() + c->z() + d->z() + e->z() + f->z() + g->z() +
                  h->z()) /
                 8.0;
      MVertex *mid = new MVertex(x, y, z, gr);
      gr->addMeshVertex(mid);

      MPyramid *temp = new MPyramid(a, b, c, d, mid);
      gr->addPyramid(temp);
      temp = new MPyramid(h, g, f, e, mid);
      gr->addPyramid(temp);
      temp = new MPyramid(e, f, b, a, mid);
      gr->addPyramid(temp);
      temp = new MPyramid(f, g, c, b, mid);
      gr->addPyramid(temp);
      temp = new MPyramid(g, h, d, c, mid);
      gr->addPyramid(temp);
      temp = new MPyramid(h, e, a, d, mid);
      gr->addPyramid(temp);
      it = markings.find(element);
      it->second = true;
    }
  }

  opt.clear();
  opt.resize(gr->hexahedra.size());
  opt = gr->hexahedra;
  gr->hexahedra.clear();

  for(size_t i = 0; i < opt.size(); i++) {
    MElement *element = (MElement *)(opt[i]);
    it = markings.find(element);
    if(it->second == 0) { gr->hexahedra.push_back(opt[i]); }
    else {
      delete opt[i];
    }
  }
}

void PostOp::split_prisms(GRegion *gr)
{
  std::vector<MElement *> prisms;
  std::vector<MPrism *> opt;
  std::map<MElement *, bool>::iterator it;

  prisms.clear();

  for(size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *element = gr->getMeshElement(i);
    if(six(element)) { prisms.push_back(element); }
  }

  for(size_t i = 0; i < prisms.size(); i++) {
    MElement *element = prisms[i];
    MVertex *a = element->getVertex(0);
    MVertex *b = element->getVertex(1);
    MVertex *c = element->getVertex(2);
    MVertex *d = element->getVertex(3);
    MVertex *e = element->getVertex(4);
    MVertex *f = element->getVertex(5);

    pyramids1(a, d, f, c, gr);
    pyramids1(a, b, e, d, gr);
    pyramids1(b, c, f, e, gr);

    bool conform = true;
    conform &= (nonConformDiag(a, d, f, c, gr) == 0);
    if(conform) conform &= (nonConformDiag(a, b, e, d, gr) == 0);
    if(conform) conform &= (nonConformDiag(b, c, f, e, gr) == 0);
    if(!conform) {
      double x = (a->x() + b->x() + c->x() + d->x() + e->x() + f->x()) / 6.0;
      double y = (a->y() + b->y() + c->y() + d->y() + e->y() + f->y()) / 6.0;
      double z = (a->z() + b->z() + c->z() + d->z() + e->z() + f->z()) / 6.0;
      MVertex *mid = new MVertex(x, y, z, gr);
      gr->addMeshVertex(mid);

      MPyramid *temp = new MPyramid(c, f, d, a, mid);
      gr->addPyramid(temp);
      temp = new MPyramid(d, e, b, a, mid);
      gr->addPyramid(temp);
      temp = new MPyramid(e, f, c, b, mid);
      gr->addPyramid(temp);
      MTetrahedron *temp2 = new MTetrahedron(d, f, e, mid);
      gr->addTetrahedron(temp2);
      temp2 = new MTetrahedron(a, b, c, mid);
      gr->addTetrahedron(temp2);
      it = markings.find(element);
      it->second = true;
    }
  }

  opt.clear();
  opt.resize(gr->prisms.size());
  opt = gr->prisms;
  gr->prisms.clear();

  for(size_t i = 0; i < opt.size(); i++) {
    MElement *element = (MElement *)(opt[i]);
    it = markings.find(element);
    if(it->second == 0) { gr->prisms.push_back(opt[i]); }
    else {
      delete opt[i];
    }
  }
}

void PostOp::split_pyramids(GRegion *gr)
{
  std::vector<MElement *> pyramids;
  std::vector<MPyramid *> opt;
  std::map<MElement *, bool>::iterator it;

  pyramids.clear();

  for(size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *element = gr->getMeshElement(i);
    if(five(element)) { pyramids.push_back(element); }
  }

  for(size_t i = 0; i < pyramids.size(); i++) {
    MElement *element = pyramids[i];
    it = markings.find(element);
    if(it->second == 1) continue;

    MVertex *a = element->getVertex(0);
    MVertex *b = element->getVertex(1);
    MVertex *c = element->getVertex(2);
    MVertex *d = element->getVertex(3);
    MVertex *apex = element->getVertex(4);

    int nDiag = nonConformDiag(a, b, c, d, gr);
    if(nDiag == 1) {
      MTetrahedron *temp = new MTetrahedron(c, b, a, apex);
      gr->addTetrahedron(temp);
      temp = new MTetrahedron(c, a, d, apex);
      gr->addTetrahedron(temp);
      it = markings.find(element);
      it->second = 1;
    }
    else if(nDiag == 2) {
      MTetrahedron *temp = new MTetrahedron(b, a, d, apex);
      gr->addTetrahedron(temp);
      temp = new MTetrahedron(b, d, c, apex);
      gr->addTetrahedron(temp);
      it = markings.find(element);
      it->second = 1;
    }
    std::set<MElement *> otherPyr;
    find_pyramids_from_quad(a, b, c, d, otherPyr);
    if(otherPyr.size() == 2) {
      element_set_itr myit = otherPyr.begin();
      MElement *other = *myit;
      if(other == element) { other = *(++myit); }
      // TODO test also quality of tet after split of other pyr ?
      MTetrahedron *tempA1 = new MTetrahedron(a, b, c, apex);
      MTetrahedron *tempA2 = new MTetrahedron(a, c, d, apex);
      MTetrahedron *tempB1 = new MTetrahedron(a, b, d, apex);
      MTetrahedron *tempB2 = new MTetrahedron(b, c, d, apex);
      MVertex *a2 = other->getVertex(0);
      MVertex *b2 = other->getVertex(1);
      MVertex *c2 = other->getVertex(2);
      MVertex *d2 = other->getVertex(3);
      MVertex *apex2 = other->getVertex(4);
      MTetrahedron *tempA3, *tempA4, *tempB3, *tempB4;
      if(a2 == a || a2 == c) {
        tempA3 = new MTetrahedron(a2, b2, c2, apex2);
        tempA4 = new MTetrahedron(a2, c2, d2, apex2);
        tempB3 = new MTetrahedron(a2, b2, d2, apex2);
        tempB4 = new MTetrahedron(b2, c2, d2, apex2);
      }
      else {
        tempB3 = new MTetrahedron(a2, b2, c2, apex2);
        tempB4 = new MTetrahedron(a2, c2, d2, apex2);
        tempA3 = new MTetrahedron(a2, b2, d2, apex2);
        tempA4 = new MTetrahedron(b2, c2, d2, apex2);
      }
      MTetrahedron *tempC1 = new MTetrahedron(a, b, apex2, apex);
      MTetrahedron *tempC2 = new MTetrahedron(b, c, apex2, apex);
      MTetrahedron *tempC3 = new MTetrahedron(c, d, apex2, apex);
      MTetrahedron *tempC4 = new MTetrahedron(d, a, apex2, apex);
      if(tempA1->getVolumeSign() < 0 || tempA2->getVolumeSign() < 0 ||
         tempA3->getVolumeSign() < 0 || tempA4->getVolumeSign() < 0 ||
         tempB1->getVolumeSign() < 0 || tempB2->getVolumeSign() < 0 ||
         tempB3->getVolumeSign() < 0 || tempB4->getVolumeSign() < 0 ||
         tempC1->getVolumeSign() < 0 || tempC2->getVolumeSign() < 0 ||
         tempC3->getVolumeSign() < 0 || tempC4->getVolumeSign() < 0) {
        Msg::Error("%d %d %d %d %d %d %d %d %d %d %d %d",
                   tempA1->getVolumeSign(), tempA2->getVolumeSign(),
                   tempA3->getVolumeSign(), tempA4->getVolumeSign(),
                   tempB1->getVolumeSign(), tempB2->getVolumeSign(),
                   tempB3->getVolumeSign(), tempB4->getVolumeSign(),
                   tempC1->getVolumeSign(), tempC2->getVolumeSign(),
                   tempC3->getVolumeSign(), tempC4->getVolumeSign());
      }
      double qA = tempA1->minIsotropyMeasure() + tempA2->minIsotropyMeasure() +
                  tempA3->minIsotropyMeasure() + tempA4->minIsotropyMeasure();
      double qB = tempB1->minIsotropyMeasure() + tempB2->minIsotropyMeasure() +
                  tempB3->minIsotropyMeasure() + tempB4->minIsotropyMeasure();
      double qC = tempC1->minIsotropyMeasure() + tempC2->minIsotropyMeasure() +
                  tempC3->minIsotropyMeasure() + tempC4->minIsotropyMeasure();
      if(qA > qB && qA > qC) {
        Msg::Info("A");
        gr->addTetrahedron(tempA1);
        gr->addTetrahedron(tempA2);
        gr->addTetrahedron(tempA3);
        gr->addTetrahedron(tempA4);
        delete tempB1;
        delete tempB2;
        delete tempB3;
        delete tempB4;
        delete tempC1;
        delete tempC2;
        delete tempC3;
        delete tempC4;
      }
      else if(qB > qC) {
        Msg::Info("B");
        gr->addTetrahedron(tempB1);
        gr->addTetrahedron(tempB2);
        gr->addTetrahedron(tempB3);
        gr->addTetrahedron(tempB4);
        delete tempA1;
        delete tempA2;
        delete tempA3;
        delete tempA4;
        delete tempC1;
        delete tempC2;
        delete tempC3;
        delete tempC4;
      }
      else {
        Msg::Info("C");
        gr->addTetrahedron(tempC1);
        gr->addTetrahedron(tempC2);
        gr->addTetrahedron(tempC3);
        gr->addTetrahedron(tempC4);
        delete tempA1;
        delete tempA2;
        delete tempA3;
        delete tempA4;
        delete tempB1;
        delete tempB2;
        delete tempB3;
        delete tempB4;
      }
      it = markings.find(element);
      it->second = 1;
      it = markings.find(other);
      it->second = 1;
    }
  }

  opt.clear();
  opt.resize(gr->pyramids.size());
  opt = gr->pyramids;
  gr->pyramids.clear();

  for(size_t i = 0; i < opt.size(); i++) {
    MElement *element = (MElement *)(opt[i]);
    it = markings.find(element);
    if(it->second == 0) { gr->pyramids.push_back(opt[i]); }
    else {
      delete opt[i];
    }
  }
}

int PostOp::nonConformDiag(MVertex *a, MVertex *b, MVertex *c, MVertex *d,
                           GRegion *gr)
{
  std::set<MElement *> diag1a;
  std::set<MElement *> diag1b;
  std::set<MElement *> diag2a;
  std::set<MElement *> diag2b;

  find_tetrahedra(a, b, c, diag1a);
  find_tetrahedra(a, c, d, diag1b);
  find_tetrahedra(b, c, d, diag2a);
  find_tetrahedra(a, b, d, diag2b);
  find_pyramids_from_tri(a, b, c, diag1a);
  find_pyramids_from_tri(a, c, d, diag1b);
  find_pyramids_from_tri(b, c, d, diag2a);
  find_pyramids_from_tri(a, b, d, diag2b);
  if(diag1a.size() == 1 || diag1b.size() == 1) { return 1; }
  else if(diag2a.size() == 1 || diag2b.size() == 1) {
    return 2;
  }
  return 0;
}

void PostOp::pyramids1(GRegion *gr)
{
  unsigned int i;
  MVertex *a, *b, *c, *d;
  MVertex *e, *f, *g, *h;
  MElement *element;
  std::vector<MElement *> hexahedra;
  std::vector<MElement *> prisms;
  std::vector<MTetrahedron *> opt;
  std::map<MElement *, bool>::iterator it;

  hexahedra.clear();
  prisms.clear();

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(eight(element)) { hexahedra.push_back(element); }
    else if(six(element)) {
      prisms.push_back(element);
    }
  }

  for(i = 0; i < hexahedra.size(); i++) {
    element = hexahedra[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);
    g = element->getVertex(6);
    h = element->getVertex(7);

    pyramids1(b, a, d, c, gr);
    pyramids1(e, f, g, h, gr);
    pyramids1(a, b, f, e, gr);
    pyramids1(b, c, g, f, gr);
    pyramids1(c, d, h, g, gr);
    pyramids1(d, a, e, h, gr);
  }

  for(i = 0; i < prisms.size(); i++) {
    element = prisms[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);

    pyramids1(a, d, f, c, gr);
    pyramids1(a, b, e, d, gr);
    pyramids1(b, c, f, e, gr);
  }

  opt.clear();
  opt.resize(gr->tetrahedra.size());
  opt = gr->tetrahedra;
  gr->tetrahedra.clear();

  for(i = 0; i < opt.size(); i++) {
    element = (MElement *)(opt[i]);
    it = markings.find(element);
    if(it->second == 0) { gr->tetrahedra.push_back(opt[i]); }
    else {
      delete opt[i];
    }
  }
}

void PostOp::pyramids2(GRegion *gr, bool allowNonConforming)
{
  unsigned int i;
  MVertex *a, *b, *c, *d;
  MVertex *e, *f, *g, *h;
  MElement *element;
  std::vector<MElement *> hexahedra;
  std::vector<MElement *> prisms;
  std::vector<MTetrahedron *> opt1;
  std::vector<MPyramid *> opt2;
  std::map<MElement *, bool>::iterator it;

  hexahedra.clear();
  prisms.clear();

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(eight(element)) { hexahedra.push_back(element); }
    else if(six(element)) {
      prisms.push_back(element);
    }
  }

  for(i = 0; i < hexahedra.size(); i++) {
    element = hexahedra[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);
    g = element->getVertex(6);
    h = element->getVertex(7);

    pyramids2(b, a, d, c, gr, allowNonConforming);
    pyramids2(e, f, g, h, gr, allowNonConforming);
    pyramids2(a, b, f, e, gr, allowNonConforming);
    pyramids2(b, c, g, f, gr, allowNonConforming);
    pyramids2(c, d, h, g, gr, allowNonConforming);
    pyramids2(d, a, e, h, gr, allowNonConforming);
  }

  for(i = 0; i < prisms.size(); i++) {
    element = prisms[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);

    pyramids2(a, d, f, c, gr, allowNonConforming);
    pyramids2(a, b, e, d, gr, allowNonConforming);
    pyramids2(b, c, f, e, gr, allowNonConforming);
  }

  opt1.clear();
  opt1.resize(gr->tetrahedra.size());
  opt1 = gr->tetrahedra;
  gr->tetrahedra.clear();

  for(i = 0; i < opt1.size(); i++) {
    element = (MElement *)(opt1[i]);
    it = markings.find(element);
    if(it->second == 0) { gr->tetrahedra.push_back(opt1[i]); }
    else {
      delete opt1[i];
    }
  }

  opt2.clear();
  opt2.resize(gr->pyramids.size());
  opt2 = gr->pyramids;
  gr->pyramids.clear();

  for(i = 0; i < opt2.size(); i++) {
    element = (MElement *)(opt2[i]);
    it = markings.find(element);
    if(it->second == 0) { gr->pyramids.push_back(opt2[i]); }
    else {
      delete opt2[i];
    }
  }
}

void PostOp::pyramids1(MVertex *a, MVertex *b, MVertex *c, MVertex *d,
                       GRegion *gr)
{
  MVertex *getVertex;
  std::set<MElement *> bin;
  std::set<MElement *> bin1a;
  std::set<MElement *> bin2a;
  std::set<MElement *> bin1b;
  std::set<MElement *> bin2b;
  element_set_itr it;
  std::map<MElement *, bool>::iterator it1;
  std::map<MElement *, bool>::iterator it2;

  bin1a.clear();
  bin1b.clear();
  bin2a.clear();
  bin2b.clear();
  find_tetrahedra(a, c, d, bin1a);
  find_tetrahedra(a, b, c, bin1b);
  find_tetrahedra(b, d, a, bin2a);
  find_tetrahedra(b, c, d, bin2b);

  //  bin1.clear();
  //  bin2.clear();
  //  find_tetrahedra(a,c,bin1);
  //  find_tetrahedra(b,d,bin2);

  bin.clear();
  for(it = bin1a.begin(); it != bin1a.end(); it++) { bin.insert(*it); }
  for(it = bin1b.begin(); it != bin1b.end(); it++) { bin.insert(*it); }
  for(it = bin2a.begin(); it != bin2a.end(); it++) { bin.insert(*it); }
  for(it = bin2b.begin(); it != bin2b.end(); it++) { bin.insert(*it); }

  if(bin.size() == 2) { // 2 tetrahedra on face
    it = bin.begin();
    it1 = markings.find(*it); // 1st tetrahedra
    it++;
    it2 = markings.find(*it); // 2nd tetrahedra

    if(it1->second == 0 && it2->second == 0) {
      getVertex = find(a, b, c, d, *it);
      MVertex *vertex1 = find(a, b, c, d, *bin.begin());
      if(!getVertex || !vertex1) {
        Msg::Error("Topological error");
        return;
      }
      if(getVertex == vertex1) {
        MPyramid *pyr = new MPyramid(a, b, c, d, getVertex);
        if(valid(pyr)) {
          gr->addPyramid(pyr);
          it1->second = 1;
          it2->second = 1;
        }
      }
    }
  }
}

void PostOp::trihedra(GRegion *gr)
{
  unsigned int i;
  MVertex *a, *b, *c, *d;
  MVertex *e, *f, *g, *h;
  MElement *element;
  std::vector<MElement *> hexahedra;
  std::vector<MElement *> prisms;
  std::vector<MTetrahedron *> opt1;
  std::vector<MPyramid *> opt2;
  std::map<MElement *, bool>::iterator it;

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(eight(element)) { hexahedra.push_back(element); }
    else if(six(element)) {
      prisms.push_back(element);
    }
  }

  for(i = 0; i < hexahedra.size(); i++) {
    element = hexahedra[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);
    g = element->getVertex(6);
    h = element->getVertex(7);

    trihedra(b, a, d, c, gr);
    trihedra(e, f, g, h, gr);
    trihedra(a, b, f, e, gr);
    trihedra(b, c, g, f, gr);
    trihedra(c, d, h, g, gr);
    trihedra(d, a, e, h, gr);
  }

  for(i = 0; i < prisms.size(); i++) {
    element = prisms[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);

    trihedra(a, d, f, c, gr);
    trihedra(a, b, e, d, gr);
    trihedra(b, c, f, e, gr);
  }
}

void PostOp::trihedra(MVertex *a, MVertex *b, MVertex *c, MVertex *d,
                      GRegion *gr)
{
  std::set<MElement *> diag1a;
  std::set<MElement *> diag1b;
  std::set<MElement *> diag2a;
  std::set<MElement *> diag2b;

  find_tetrahedra(a, b, c, diag1a);
  find_tetrahedra(a, c, d, diag1b);
  find_tetrahedra(b, c, d, diag2a);
  find_tetrahedra(a, b, d, diag2b);
  find_pyramids_from_tri(a, b, c, diag1a);
  find_pyramids_from_tri(a, c, d, diag1b);
  find_pyramids_from_tri(b, c, d, diag2a);
  find_pyramids_from_tri(a, b, d, diag2b);
  if(diag1a.size() == 1 || diag1b.size() == 1) {
    MTrihedron *trih = new MTrihedron(b, c, d, a);
    if(diag1a.size() != 1 || diag1b.size() != 1 || diag2a.size() != 0 ||
       diag2b.size() != 0)
      Msg::Error("Quad face neighbor with %i+%i triangular faces (other "
                 "diagonal: %i+%i) Trihedron: %i",
                 diag1a.size(), diag1b.size(), diag2a.size(), diag2b.size(),
                 trih->getNum());
    gr->addTrihedron(trih);
  }
  else if(diag2a.size() == 1 || diag2b.size() == 1) {
    MTrihedron *trih = new MTrihedron(a, b, c, d);
    if(diag1a.size() != 0 || diag1b.size() != 0 || diag2a.size() != 1 ||
       diag2b.size() != 1)
      Msg::Error("Quad face neighbor with %i+%i triangular faces (other "
                 "diagonal: %i+%i) Trihedron: %i",
                 diag2a.size(), diag2b.size(), diag1a.size(), diag1b.size(),
                 trih->getNum());
    gr->addTrihedron(trih);
  }
}

void PostOp::pyramids2(MVertex *a, MVertex *b, MVertex *c, MVertex *d,
                       GRegion *gr, bool allowNonConforming)
{
  bool flag;
  double x, y, z;
  MVertex *mid;
  MVertex *diagA, *diagB, *nDiagA, *nDiagB;
  MVertex *N1, *N2;
  MVertex *v1, *v2, *v3, *v4, *v5;
  MTetrahedron *temp;
  MPyramid *temp2;
  std::vector<MElement *> movables;
  std::set<MVertex *> Ns;
  std::set<MElement *> bin1a, bin1b;
  std::set<MElement *> bin2a, bin2b;
  std::set<MElement *> bin3a, bin3b;
  std::set<MElement *> bin4a, bin4b;
  std::set<MElement *> tetrahedra;
  std::set<MElement *> pyramids;
  element_set_itr it;
  std::map<MElement *, bool>::iterator it2;

  flag = 0;

  bin1a.clear();
  bin1b.clear();
  bin2a.clear();
  bin2b.clear();
  find_tetrahedra(a, c, d, bin1a);
  find_tetrahedra(a, b, c, bin1b);
  find_tetrahedra(b, d, a, bin2a);
  find_tetrahedra(b, c, d, bin2b);

  bin3a.clear();
  bin3b.clear();
  bin4a.clear();
  bin4b.clear();
  find_pyramids_from_tri(a, c, d, bin3a);
  find_pyramids_from_tri(a, b, c, bin3b);
  find_pyramids_from_tri(b, d, a, bin4a);
  find_pyramids_from_tri(b, c, d, bin4b);

  tetrahedra.clear();
  pyramids.clear();
  if((bin1a.size() + bin3a.size() == 1) && (bin1b.size() + bin3b.size() == 1)) {
    flag = true;
    for(it = bin1a.begin(); it != bin1a.end(); it++) { tetrahedra.insert(*it); }
    for(it = bin1b.begin(); it != bin1b.end(); it++) { tetrahedra.insert(*it); }
    for(it = bin3a.begin(); it != bin3a.end(); it++) { pyramids.insert(*it); }
    for(it = bin3b.begin(); it != bin3b.end(); it++) { pyramids.insert(*it); }
  }
  else if((bin2a.size() + bin4a.size() == 1) &&
          (bin2b.size() + bin4b.size() == 1)) {
    for(it = bin2a.begin(); it != bin2a.end(); it++) { tetrahedra.insert(*it); }
    for(it = bin2b.begin(); it != bin2b.end(); it++) { tetrahedra.insert(*it); }
    for(it = bin4a.begin(); it != bin4a.end(); it++) { pyramids.insert(*it); }
    for(it = bin4b.begin(); it != bin4b.end(); it++) { pyramids.insert(*it); }
  }

  if(flag) {
    diagA = c;
    diagB = a;
    nDiagA = b;
    nDiagB = d;
  }
  else {
    diagA = b;
    diagB = d;
    nDiagA = c;
    nDiagB = a;
  }

  Ns.clear();
  Ns.insert(diagA);
  Ns.insert(diagB);

  // x = (diagA->x() + diagB->x())/2.0;
  // y = (diagA->y() + diagB->y())/2.0;
  // z = (diagA->z() + diagB->z())/2.0;

  mid = 0;
  movables.clear();

  if(tetrahedra.size() > 0 || pyramids.size() > 0) {
    // A quad face can share only one of those:
    // 2 triangles split by the first diagonal
    // 2 triangles split by the second diagonal
    // 0 triangle  with all nodes being on the boundary
    if((bin1a.size() + bin3a.size()) == 1 &&
       (bin1b.size() + bin3b.size()) == 1) {
      //      MTrihedron *trih = new MTrihedron(b, c, d, a);
      //      gr->addTrihedron(trih);
    }
    else if((bin2a.size() + bin4a.size()) == 1 &&
            (bin2b.size() + bin4b.size()) == 1) {
      //      MTrihedron *trih = new MTrihedron(a, b, c, d);
      //      gr->addTrihedron(trih);
    }
    else if(bin1a.size() != 0 || bin1b.size() != 0 || bin2a.size() != 0 ||
            bin2b.size() != 0 || bin3a.size() != 0 || bin3b.size() != 0 ||
            bin4a.size() != 0 || bin4b.size() != 0 || a->onWhat()->dim() > 2 ||
            b->onWhat()->dim() > 2 || c->onWhat()->dim() > 2 ||
            d->onWhat()->dim() > 2) {
      Msg::Error("Topological issue: inner quad face facing something else "
                 "than 2 triangles: %i %i %i %i %i %i %i %i dim %i %i %i",
                 bin1a.size(), bin1b.size(), bin2a.size(), bin2b.size(),
                 bin3a.size(), bin3b.size(), bin4a.size(), bin4b.size(),
                 a->onWhat()->dim(), b->onWhat()->dim(), c->onWhat()->dim(),
                 d->onWhat()->dim());
      return;
    }

    MVertex *otherV[2];
    int i = 0;
    for(it = tetrahedra.begin(); it != tetrahedra.end(); it++) {
      otherV[i++] = findInTriFace(diagA, diagB, nDiagA, nDiagB, *it);
    }
    for(it = pyramids.begin(); it != pyramids.end(); it++) {
      otherV[i++] = findInTriFace(diagA, diagB, nDiagA, nDiagB, *it);
    }
    if(!otherV[0] || !otherV[1]) {
      Msg::Error("Topological error");
      return;
    }

    MPyramid *pyr = new MPyramid(a, b, c, d, otherV[0]);
    bool pyrOk = valid(pyr);
    delete pyr;

    if(otherV[0] == otherV[1] && pyrOk) {
      estimate1 = estimate1 + tetrahedra.size() + 2 * pyramids.size();
      estimate2 = estimate2 + 1;

      // x = (diagA->x() + diagB->x() + otherV[0]->x())/3;
      // y = (diagA->y() + diagB->y() + otherV[0]->y())/3;
      // z = (diagA->z() + diagB->z() + otherV[0]->z())/3;

      // We create a flat pyramid and let the optimizer fix it
      x = (a->x() + b->x() + c->x() + d->x()) / 4;
      y = (a->y() + b->y() + c->y() + d->y()) / 4;
      z = (a->z() + b->z() + c->z() + d->z()) / 4;
      x = (x + otherV[0]->x()) / 2;
      y = (y + otherV[0]->y()) / 2;
      z = (z + otherV[0]->z()) / 2;

      mid = new MVertex(x, y, z, gr);
      gr->addMeshVertex(mid);

      temp2 = new MPyramid(a, b, c, d, mid);

      gr->addPyramid(temp2);
      markings.insert(std::pair<MElement *, bool>(temp2, false));
      build_vertex_to_pyramids(temp2);
      //      printf("Creating pyramid with vertices %i %i %i %i %i\n",
      //      a->getNum(), b->getNum(), c->getNum(), d->getNum(),
      //      mid->getNum());

      for(it = tetrahedra.begin(); it != tetrahedra.end(); it++) {
        MVertex *Nout = findInTriFace(diagA, diagB, nDiagA, nDiagB, *it);
        MVertex *Nin = other(*it, diagA, diagB, Nout);
        //        N1 = other(*it,diagA,diagB);

        if(Nout != 0 && Nin != 0) {
          Ns.insert(N1);
          Ns.insert(N2);

          temp = new MTetrahedron(mid, diagB, Nin, Nout);
          gr->addTetrahedron(temp);
          markings.insert(std::pair<MElement *, bool>(temp, false));
          build_vertex_to_tetrahedra(temp);
          movables.push_back(temp);
          //          printf("Creating tet with vertices %i %i %i %i\n",
          //          N1->getNum(), N2->getNum(), diagA->getNum(),
          //          mid->getNum());

          temp = new MTetrahedron(diagA, mid, Nin, Nout);
          gr->addTetrahedron(temp);
          markings.insert(std::pair<MElement *, bool>(temp, false));
          build_vertex_to_tetrahedra(temp);
          movables.push_back(temp);
          //          printf("Creating tet with vertices %i %i %i %i\n",
          //          N1->getNum(), N2->getNum(), diagB->getNum(),
          //          mid->getNum());

          it2 = markings.find(*it);
          it2->second = 1;
          erase_vertex_to_tetrahedra(*it);
        }
        else {
          Msg::Error("Wrong tetrahedron");
        }
      }

      for(it = pyramids.begin(); it != pyramids.end(); it++) {
        v1 = (*it)->getVertex(0);
        v2 = (*it)->getVertex(1);
        v3 = (*it)->getVertex(2);
        v4 = (*it)->getVertex(3);
        v5 = (*it)->getVertex(4); // apex

        // My version (sign-preserving)
        temp2 = new MPyramid(v1, v2, v3, v4, mid);
        gr->addPyramid(temp2);
        markings.insert(std::pair<MElement *, bool>(temp2, false));
        build_vertex_to_pyramids(temp2);

        MVertex *NoutDiag = findInTriFace(diagA, diagB, nDiagA, nDiagB, *it);
        MVertex *NoutNDiag = NULL;
        for(int iV = 0; iV < 5; iV++) {
          MVertex *v = (*it)->getVertex(iV);
          if(v != a && v != b && v != c && v != d && v != NoutDiag) {
            NoutNDiag = v;
            break;
          }
        }
        MVertex *NinNDiag =
          findInTriFace(diagA, diagB, NoutDiag, NoutNDiag, *it);
        if(v5 == diagA) {
          temp = new MTetrahedron(diagA, mid, NinNDiag, NoutNDiag);
          gr->addTetrahedron(temp);
          markings.insert(std::pair<MElement *, bool>(temp, false));
          build_vertex_to_tetrahedra(temp);
          movables.push_back(temp);
          temp = new MTetrahedron(diagA, mid, NoutNDiag, NoutDiag);
          gr->addTetrahedron(temp);
          markings.insert(std::pair<MElement *, bool>(temp, false));
          build_vertex_to_tetrahedra(temp);
          movables.push_back(temp);
        }
        else if(v5 == diagB) {
          temp = new MTetrahedron(mid, diagB, NinNDiag, NoutNDiag);
          gr->addTetrahedron(temp);
          markings.insert(std::pair<MElement *, bool>(temp, false));
          build_vertex_to_tetrahedra(temp);
          movables.push_back(temp);
          temp = new MTetrahedron(diagB, mid, NoutNDiag, NoutDiag);
          gr->addTetrahedron(temp);
          markings.insert(std::pair<MElement *, bool>(temp, false));
          build_vertex_to_tetrahedra(temp);
          movables.push_back(temp);
        }

        //        if(v1!=diagA && v1!=diagB){
        //          Ns.insert(v1);
        //        }
        //        if(v2!=diagA && v2!=diagB){
        //          Ns.insert(v2);
        //        }
        //        if(v3!=diagA && v3!=diagB){
        //          Ns.insert(v3);
        //        }
        //        if(v4!=diagA && v4!=diagB){
        //          Ns.insert(v4);
        //        }
        //        if(v5!=diagA && v5!=diagB){
        //          Ns.insert(v5);
        //        }
        //
        //        temp2 = new MPyramid(v1,v2,v3,v4,mid);
        //        gr->addPyramid(temp2);
        //        markings.insert(std::pair<MElement*,bool>(temp2,false));
        //        build_vertex_to_pyramids(temp2);
        //
        //        if(different(v1,v2,diagA,diagB)){
        //          temp = new MTetrahedron(v1,v2,mid,v5);
        //          gr->addTetrahedron(temp);
        //          markings.insert(std::pair<MElement*,bool>(temp,false));
        //          build_vertex_to_tetrahedra(temp);
        //          movables.push_back(temp);
        //        }
        //
        //        if(different(v2,v3,diagA,diagB)){
        //          temp = new MTetrahedron(v2,v3,mid,v5);
        //          gr->addTetrahedron(temp);
        //          markings.insert(std::pair<MElement*,bool>(temp,false));
        //          build_vertex_to_tetrahedra(temp);
        //          movables.push_back(temp);
        //        }
        //
        //        if(different(v3,v4,diagA,diagB)){
        //          temp = new MTetrahedron(v3,v4,mid,v5);
        //          gr->addTetrahedron(temp);
        //          markings.insert(std::pair<MElement*,bool>(temp,false));
        //          build_vertex_to_tetrahedra(temp);
        //          movables.push_back(temp);
        //        }
        //
        //        if(different(v4,v1,diagA,diagB)){
        //          temp = new MTetrahedron(v4,v1,mid,v5);
        //          gr->addTetrahedron(temp);
        //          markings.insert(std::pair<MElement*,bool>(temp,false));
        //          build_vertex_to_tetrahedra(temp);
        //          movables.push_back(temp);
        //        }

        it2 = markings.find(*it);
        it2->second = 1;
        erase_vertex_to_pyramids(*it);
      }

      //  mean(Ns,mid,movables);
    }
  }
}

void PostOp::rearrange(GRegion *gr)
{
  unsigned int i;
  MElement *element;

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    element->setVolumePositive();
  }
}

void PostOp::statistics(GRegion *gr)
{
  unsigned int i;
  MElement *element;

  nbr = 0;
  nbr8 = 0;
  nbr6 = 0;
  nbr5 = 0;
  nbr4 = 0;
  nbr4Trih = 0;
  vol = 0.0;
  vol8 = 0.0;
  vol6 = 0.0;
  vol5 = 0.0;
  vol4 = 0.0;

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);

    if(eight(element)) {
      nbr8 = nbr8 + 1;
      vol8 = vol8 + element->getVolume();
    }

    if(six(element)) {
      nbr6 = nbr6 + 1;
      vol6 = vol6 + element->getVolume();
    }

    if(five(element)) {
      nbr5 = nbr5 + 1;
      vol5 = vol5 + workaround(element);
    }

    if(four(element)) {
      nbr4 = nbr4 + 1;
      vol4 = vol4 + element->getVolume();
    }

    if(fourTrih(element)) { nbr4Trih = nbr4Trih + 1; }

    nbr = nbr + 1;

    if(!five(element)) { vol = vol + element->getVolume(); }
    else {
      // vol = vol + workaround(element);
      vol = vol + element->getVolume();
    }
  }

  printf("Number :\n");
  printf("  percentage of hexahedra : %.2f\n", nbr8 * 100.0 / nbr);
  printf("  percentage of prisms : %.2f\n", nbr6 * 100.0 / nbr);
  printf("  percentage of pyramids : %.2f\n", nbr5 * 100.0 / nbr);
  printf("  percentage of tetrahedra : %.2f\n", nbr4 * 100.0 / nbr);
  printf("  percentage of trihedra : %.2f\n", nbr4Trih * 100.0 / nbr);
  printf("Volume :\n");
  printf("  percentage of hexahedra : %.2f\n", vol8 * 100.0 / vol);
  printf("  percentage of prisms : %.2f\n", vol6 * 100.0 / vol);
  printf("  percentage of pyramids : %.2f\n", vol5 * 100.0 / vol);
  printf("  percentage of tetrahedra : %.2f\n", vol4 * 100.0 / vol);
  printf("Total number of elements : %lu\n", gr->getNumMeshElements());
  printf("Total volume : %f\n", vol);
  printf("Misc : %d %d %d\n", estimate1, estimate2, iterations);
}

void PostOp::build_tuples(GRegion *gr)
{
  unsigned int i;
  MVertex *a, *b, *c;
  MElement *element;
  GFace *gf;

  tuples.clear();
  triangles.clear();

  std::vector<GFace *> faces = gr->faces();
  std::vector<GFace *>::iterator it;

  for(it = faces.begin(); it != faces.end(); it++) {
    gf = *it;

    for(i = 0; i < gf->getNumMeshElements(); i++) {
      element = gf->getMeshElement(i);

      if(element->getNumVertices() == 3) {
        a = element->getVertex(0);
        b = element->getVertex(1);
        c = element->getVertex(2);

        tuples.insert(Tuple(a, b, c, element, gf));
      }
    }
  }
}

void PostOp::create_quads_on_boundary(GRegion *gr)
{
  unsigned int i;
  MVertex *a, *b, *c, *d; //,*e;
  MElement *element;
  GFace *gf;
  std::vector<MElement *> opt;
  element_set_itr it2;

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);

    if(element->getNumVertices() == 5) {
      a = element->getVertex(0);
      b = element->getVertex(1);
      c = element->getVertex(2);
      d = element->getVertex(3);
      // e = element->getVertex(4);

      create_quads_on_boundary(a, b, c, d);
    }
  }

  std::vector<GFace *> faces = gr->faces();
  std::vector<GFace *>::iterator it;

  for(it = faces.begin(); it != faces.end(); it++) {
    gf = *it;

    opt.clear();

    for(i = 0; i < gf->getNumMeshElements(); i++) {
      element = gf->getMeshElement(i);

      if(element->getNumVertices() == 3) {
        it2 = triangles.find(element);
        if(it2 == triangles.end()) { opt.push_back(element); }
      }
    }

    gf->triangles.clear();

    for(i = 0; i < opt.size(); i++) {
      gf->triangles.push_back((MTriangle *)opt[i]);
    }
  }
}

void PostOp::create_quads_on_boundary(MVertex *a, MVertex *b, MVertex *c,
                                      MVertex *d)
{
  bool flag1, flag2;
  MElement *element1, *element2;
  GFace *gf1; //,*gf2;
  Tuple tuple1, tuple2;
  std::multiset<Tuple>::iterator it1;
  std::multiset<Tuple>::iterator it2;

  gf1 = NULL;
  // gf2 = NULL;

  tuple1 = Tuple(a, b, c);
  tuple2 = Tuple(c, d, a);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1 != tuples.end()) {
    if(tuple1.get_hash() != it1->get_hash()) { break; }

    if(tuple1.same_vertices(*it1)) {
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2 != tuples.end()) {
    if(tuple2.get_hash() != it2->get_hash()) { break; }

    if(tuple2.same_vertices(*it2)) {
      flag2 = 1;
      element2 = it2->get_element();
      // gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2) {
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a, b, c, d));
  }

  tuple1 = Tuple(a, b, d);
  tuple2 = Tuple(b, c, d);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1 != tuples.end()) {
    if(tuple1.get_hash() != it1->get_hash()) { break; }

    if(tuple1.same_vertices(*it1)) {
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2 != tuples.end()) {
    if(tuple2.get_hash() != it2->get_hash()) { break; }

    if(tuple2.same_vertices(*it2)) {
      flag2 = 1;
      element2 = it2->get_element();
      // gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2) {
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a, b, c, d));
  }
}

bool PostOp::four(MElement *element)
{
  if(element->getNumVertices() == 4 && element->getNumFaces() == 4)
    return 1;
  else
    return 0;
}

bool PostOp::fourTrih(MElement *element)
{
  if(element->getNumVertices() == 4 && element->getNumFaces() == 3)
    return 1;
  else
    return 0;
}

bool PostOp::five(MElement *element)
{
  if(element->getNumVertices() == 5)
    return 1;
  else
    return 0;
}

bool PostOp::six(MElement *element)
{
  if(element->getNumVertices() == 6)
    return 1;
  else
    return 0;
}

bool PostOp::eight(MElement *element)
{
  if(element->getNumVertices() == 8)
    return 1;
  else
    return 0;
}

bool PostOp::equal(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4)
{
  if((v1 == v3 && v2 == v4) || (v1 == v4 && v2 == v3)) { return 1; }
  else {
    return 0;
  }
}
bool PostOp::equal(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                   MVertex *va, MVertex *vb, MVertex *vc, MVertex *vd)
{
  //  return (v1==vd && v2==vc && v3==vb && v4==va) ||
  //         (v1==vc && v2==vb && v3==va && v4==vd) ||
  //         (v1==vb && v2==va && v3==vd && v4==vc) ||
  //         (v1==va && v2==vd && v3==vc && v4==vb) || // should be enough
  //         (v1==vd && v2==vc && v3==va && v4==vb) ||
  //         (v1==vc && v2==vb && v3==vd && v4==va) ||
  //         (v1==vb && v2==va && v3==vc && v4==vd) ||
  //         (v1==va && v2==vd && v3==vb && v4==vc) ||
  //         (v1==vd && v2==vb && v3==vc && v4==va) ||
  //         (v1==vc && v2==va && v3==vb && v4==vd) ||
  //         (v1==vb && v2==vd && v3==va && v4==vc) ||
  //         (v1==va && v2==vc && v3==vd && v4==vb) ||
  //         (v1==vd && v2==vb && v3==va && v4==vc) ||
  //         (v1==vc && v2==va && v3==vd && v4==vb) ||
  //         (v1==vb && v2==vd && v3==vc && v4==va) ||
  //         (v1==va && v2==vc && v3==vb && v4==vd) ||
  //         (v1==vd && v2==va && v3==vb && v4==vc) ||
  //         (v1==vc && v2==vd && v3==va && v4==vb) ||
  //         (v1==vb && v2==vc && v3==vd && v4==va) ||
  //         (v1==va && v2==vb && v3==vc && v4==vd) ||
  //         (v1==vd && v2==va && v3==vc && v4==vb) ||
  //         (v1==vc && v2==vd && v3==vb && v4==va) ||
  //         (v1==vb && v2==vc && v3==va && v4==vd) ||
  //         (v1==va && v2==vb && v3==vd && v4==vc);
  // assuming that at least (v1,v2,v3,v4) are all different vertices
  //                     or (va,vb,vc,vd) are all different vertices
  return (v1 == va || v1 == vb || v1 == vc || v1 == vd) &&
         (v2 == va || v2 == vb || v2 == vc || v2 == vd) &&
         (v3 == va || v3 == vb || v3 == vc || v3 == vd) &&
         (v4 == va || v4 == vb || v4 == vc || v4 == vd);
}

bool PostOp::different(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4)
{
  if(v1 != v3 && v1 != v4 && v2 != v3 && v2 != v4) { return 1; }
  else {
    return 0;
  }
}

MVertex *PostOp::other(MElement *element, MVertex *v1, MVertex *v2)
{
  MVertex *pointer = NULL;

  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *getVertex = element->getVertex(i);
    if(getVertex != v1 && getVertex != v2) {
      pointer = getVertex;
      break;
    }
  }

  return pointer;
}

MVertex *PostOp::other(MElement *element, MVertex *v1, MVertex *v2, MVertex *v3)
{
  MVertex *pointer = NULL;

  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *getVertex = element->getVertex(i);
    if(getVertex != v1 && getVertex != v2 && getVertex != v3) {
      pointer = getVertex;
      break;
    }
  }

  return pointer;
}

void PostOp::mean(const std::set<MVertex *> &Ns, MVertex *mid,
                  const std::vector<MElement *> &movables)
{
  unsigned int i;
  int j;
  bool flag;
  double x, y, z;
  double init_x, init_y, init_z;
  std::set<MVertex *>::const_iterator it;

  x = 0.0;
  y = 0.0;
  z = 0.0;

  init_x = mid->x();
  init_y = mid->y();
  init_z = mid->z();

  for(it = Ns.begin(); it != Ns.end(); it++) {
    x = x + (*it)->x();
    y = y + (*it)->y();
    z = z + (*it)->z();
  }

  x = x / Ns.size();
  y = y / Ns.size();
  z = z / Ns.size();

  for(i = 0; i < movables.size(); i++) { movables[i]->setVolumePositive(); }

  mid->setXYZ(x, y, z);

  for(j = 0; j < 100; j++) {
    flag = 0;

    for(i = 0; i < movables.size(); i++) {
      if(movables[i]->getVolume() < 0.0) { flag = 1; }
    }

    if(!flag) { break; }

    x = 0.1 * init_x + 0.9 * mid->x();
    y = 0.1 * init_y + 0.9 * mid->y();
    z = 0.1 * init_z + 0.9 * mid->z();

    mid->setXYZ(x, y, z);
  }

  iterations = iterations + j;

  for(j = 0; j < 6; j++) {
    flag = 0;

    for(i = 0; i < movables.size(); i++) {
      if(movables[i]->gammaShapeMeasure() < 0.2) { flag = 1; }
    }

    if(!flag) { break; }

    x = 0.1 * init_x + 0.9 * mid->x();
    y = 0.1 * init_y + 0.9 * mid->y();
    z = 0.1 * init_z + 0.9 * mid->z();

    mid->setXYZ(x, y, z);
  }

  iterations = iterations + j;
}

double PostOp::workaround(MElement *element)
{
  double volume;
  MTetrahedron *temp1;
  MTetrahedron *temp2;

  volume = 0.0;

  if(five(element)) {
    temp1 = new MTetrahedron(element->getVertex(0), element->getVertex(1),
                             element->getVertex(2), element->getVertex(4));
    temp2 = new MTetrahedron(element->getVertex(2), element->getVertex(3),
                             element->getVertex(0), element->getVertex(4));
    volume = fabs(temp1->getVolume()) + fabs(temp2->getVolume());
    delete temp1;
    delete temp2;
  }

  return volume;
}

// For an element find a getVertex which is in a face inluding in but not out
MVertex *PostOp::findInTriFace(MVertex *in0, MVertex *in1, MVertex *out0,
                               MVertex *out1, MElement *element)
{
  for(int iF = 0; iF < element->getNumFaces(); iF++) {
    const MFace &face = element->getFace(iF);
    if(face.getNumVertices() != 3) continue;
    int nbIn = 0;
    int hasOut = false;
    for(int iV = 0; iV < 3; iV++) {
      if(face.getVertex(iV) == in0 || face.getVertex(iV) == in1) nbIn++;
      if(face.getVertex(iV) == out0 || face.getVertex(iV) == out1) {
        hasOut = true;
        continue;
      }
    }
    if(nbIn == 2 && !hasOut)
      for(int iV = 0; iV < 3; iV++)
        if(face.getVertex(iV) != in0 && face.getVertex(iV) != in1)
          return face.getVertex(iV);
  }
  return NULL;
}

MVertex *PostOp::find(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                      MElement *element)
{
  MVertex *pointer = NULL;

  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *getVertex = element->getVertex(i);
    if(getVertex != v1 && getVertex != v2 && getVertex != v3 &&
       getVertex != v4) {
      pointer = getVertex;
      break;
    }
  }

  return pointer;
}

void PostOp::find_tetrahedra(MVertex *v1, MVertex *v2,
                             std::set<MElement *> &final)
{
  Vertex2Elements::iterator it1;
  Vertex2Elements::iterator it2;

  it1 = vertex_to_tetrahedra.find(v1);
  it2 = vertex_to_tetrahedra.find(v2);

  if(it1 != vertex_to_tetrahedra.end() && it2 != vertex_to_tetrahedra.end()) {
    intersection(it1->second, it2->second, final);
  }
}

void PostOp::find_tetrahedra(MVertex *v1, MVertex *v2, MVertex *v3,
                             std::set<MElement *> &final)
{
  Vertex2Elements::iterator it1;
  Vertex2Elements::iterator it2;
  Vertex2Elements::iterator it3;

  it1 = vertex_to_tetrahedra.find(v1);
  it2 = vertex_to_tetrahedra.find(v2);
  it3 = vertex_to_tetrahedra.find(v3);

  std::set<MElement *> buf;

  if(it1 != vertex_to_tetrahedra.end() && it2 != vertex_to_tetrahedra.end() &&
     it3 != vertex_to_tetrahedra.end()) {
    intersection(it1->second, it2->second, buf);
    intersection(buf, it3->second, final);
  }
}

void PostOp::find_pyramids_from_tri(MVertex *v1, MVertex *v2, MVertex *v3,
                                    std::set<MElement *> &final)
{
  bool flag;
  element_set_itr it;
  Vertex2Elements::iterator it1;
  Vertex2Elements::iterator it2;
  Vertex2Elements::iterator it3;
  std::set<MElement *> temp1, temp2;

  it1 = vertex_to_pyramids.find(v1);
  it2 = vertex_to_pyramids.find(v2);
  it3 = vertex_to_pyramids.find(v3);

  temp1.clear();
  temp2.clear();

  if(it1 != vertex_to_pyramids.end() && it2 != vertex_to_pyramids.end() &&
     it3 != vertex_to_pyramids.end()) {
    intersection(it1->second, it2->second, temp1);
    intersection(temp1, it3->second, temp2);
  }
  // Now temp2 contains pyramids containing the 3 vertices
  // We check that one getVertex is on the summit and the others are neighbors
  // in the base
  for(it = temp2.begin(); it != temp2.end(); it++) {
    flag = false;
    if(v1 == (*it)->getVertex(4)) {
      flag = (equal(v2, v3, (*it)->getVertex(0), (*it)->getVertex(1)) ||
              equal(v2, v3, (*it)->getVertex(1), (*it)->getVertex(2)) ||
              equal(v2, v3, (*it)->getVertex(2), (*it)->getVertex(3)) ||
              equal(v2, v3, (*it)->getVertex(3), (*it)->getVertex(0)));
    }
    if(v2 == (*it)->getVertex(4)) {
      flag = (equal(v1, v3, (*it)->getVertex(0), (*it)->getVertex(1)) ||
              equal(v1, v3, (*it)->getVertex(1), (*it)->getVertex(2)) ||
              equal(v1, v3, (*it)->getVertex(2), (*it)->getVertex(3)) ||
              equal(v1, v3, (*it)->getVertex(3), (*it)->getVertex(0)));
    }
    if(v3 == (*it)->getVertex(4)) {
      flag = (equal(v1, v2, (*it)->getVertex(0), (*it)->getVertex(1)) ||
              equal(v1, v2, (*it)->getVertex(1), (*it)->getVertex(2)) ||
              equal(v1, v2, (*it)->getVertex(2), (*it)->getVertex(3)) ||
              equal(v1, v2, (*it)->getVertex(3), (*it)->getVertex(0)));
    }
    if(flag) { final.insert(*it); }
  }
}
void PostOp::find_pyramids_from_quad(MVertex *v1, MVertex *v2, MVertex *v3,
                                     MVertex *v4, std::set<MElement *> &final)
{
  element_set_itr it;
  Vertex2Elements::iterator it1;
  Vertex2Elements::iterator it2;
  Vertex2Elements::iterator it3;
  Vertex2Elements::iterator it4;
  std::set<MElement *> temp1, temp2, temp3;

  it1 = vertex_to_pyramids.find(v1);
  it2 = vertex_to_pyramids.find(v2);
  it3 = vertex_to_pyramids.find(v3);
  it4 = vertex_to_pyramids.find(v4);

  temp1.clear();
  temp2.clear();
  temp3.clear();

  if(it1 != vertex_to_pyramids.end() && it2 != vertex_to_pyramids.end() &&
     it3 != vertex_to_pyramids.end() && it4 != vertex_to_pyramids.end()) {
    intersection(it1->second, it2->second, temp1);
    intersection(temp1, it3->second, temp2);
    intersection(temp2, it4->second, temp3);
  }
  // Now temp3 contains pyramids containing the 4 vertices
  // We check that the 4 vertices are in the base
  // TODO: not necessary?
  for(it = temp2.begin(); it != temp2.end(); it++) {
    if(equal(v1, v2, v3, v4, (*it)->getVertex(0), (*it)->getVertex(1),
             (*it)->getVertex(2), (*it)->getVertex(3))) {
      final.insert(*it);
    }
  }
}

void PostOp::find_pyramids(MVertex *v1, MVertex *v2,
                           std::set<MElement *> &final)
{
  bool flag1, flag2, flag3, flag4;
  bool flag5, flag6, flag7, flag8;
  element_set_itr it;
  Vertex2Elements::iterator it1;
  Vertex2Elements::iterator it2;
  std::set<MElement *> temp;

  it1 = vertex_to_pyramids.find(v1);
  it2 = vertex_to_pyramids.find(v2);

  temp.clear();

  if(it1 != vertex_to_pyramids.end() && it2 != vertex_to_pyramids.end()) {
    intersection(it1->second, it2->second, temp);
  }

  for(it = temp.begin(); it != temp.end(); it++) {
    flag1 = equal(v1, v2, (*it)->getVertex(0), (*it)->getVertex(1));
    flag2 = equal(v1, v2, (*it)->getVertex(1), (*it)->getVertex(2));
    flag3 = equal(v1, v2, (*it)->getVertex(2), (*it)->getVertex(3));
    flag4 = equal(v1, v2, (*it)->getVertex(3), (*it)->getVertex(0));
    flag5 = equal(v1, v2, (*it)->getVertex(0), (*it)->getVertex(4));
    flag6 = equal(v1, v2, (*it)->getVertex(1), (*it)->getVertex(4));
    flag7 = equal(v1, v2, (*it)->getVertex(2), (*it)->getVertex(4));
    flag8 = equal(v1, v2, (*it)->getVertex(3), (*it)->getVertex(4));
    if(flag1 || flag2 || flag3 || flag4 || flag5 || flag6 || flag7 || flag8) {
      final.insert(*it);
    }
  }
}

// void PostOp::find_pyramids(MVertex* v1,MVertex* v2,std::set<MElement*>&
// final){
//  bool flag1,flag2,flag3,flag4;
//  bool flag5,flag6,flag7,flag8;
//  element_set_itr it;
//  std::map<MVertex*,std::set<MElement*> >::iterator it1;
//  std::map<MVertex*,std::set<MElement*> >::iterator it2;
//  std::set<MElement*> temp;
//
//  it1 = vertex_to_pyramids.find(v1);
//  it2 = vertex_to_pyramids.find(v2);
//
//  temp.clear();
//
//  if(it1!=vertex_to_pyramids.end() && it2!=vertex_to_pyramids.end()){
//    intersection(it1->second,it2->second,temp);
//  }
//
//  for(it=temp.begin();it!=temp.end();it++){
//    flag1 = equal(v1,v2,(*it)->getVertex(0),(*it)->getVertex(1));
//    flag2 = equal(v1,v2,(*it)->getVertex(1),(*it)->getVertex(2));
//    flag3 = equal(v1,v2,(*it)->getVertex(2),(*it)->getVertex(3));
//    flag4 = equal(v1,v2,(*it)->getVertex(3),(*it)->getVertex(0));
//    flag5 = equal(v1,v2,(*it)->getVertex(0),(*it)->getVertex(4));
//    flag6 = equal(v1,v2,(*it)->getVertex(1),(*it)->getVertex(4));
//    flag7 = equal(v1,v2,(*it)->getVertex(2),(*it)->getVertex(4));
//    flag8 = equal(v1,v2,(*it)->getVertex(3),(*it)->getVertex(4));
//    if(flag1 || flag2 || flag3 || flag4 || flag5 || flag6 || flag7 || flag8){
//      final.insert(*it);
//    }
//  }
//}

void PostOp::intersection(const std::set<MElement *> &bin1,
                          const std::set<MElement *> &bin2,
                          std::set<MElement *> &final)
{
  std::set_intersection(bin1.begin(), bin1.end(), bin2.begin(), bin2.end(),
                        std::inserter(final, final.end()));
}

void PostOp::build_vertex_to_tetrahedra(GRegion *gr)
{
  unsigned int i;
  MElement *element;

  vertex_to_tetrahedra.clear();

  for(i = 0; i < gr->getNumMeshElements(); i++) {
    element = gr->getMeshElement(i);
    if(four(element)) { build_vertex_to_tetrahedra(element); }
  }
}

void PostOp::build_vertex_to_tetrahedra(MElement *element)
{
  std::set<MElement *> bin;

  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *getVertex = element->getVertex(i);

    Vertex2Elements::iterator it = vertex_to_tetrahedra.find(getVertex);
    if(it != vertex_to_tetrahedra.end()) { it->second.insert(element); }
    else {
      bin.clear();
      bin.insert(element);
      vertex_to_tetrahedra.insert(
        std::pair<MVertex *, std::set<MElement *> >(getVertex, bin));
    }
  }
}

void PostOp::erase_vertex_to_tetrahedra(MElement *element)
{
  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *getVertex = element->getVertex(i);

    Vertex2Elements::iterator it = vertex_to_tetrahedra.find(getVertex);
    if(it != vertex_to_tetrahedra.end()) { it->second.erase(element); }
  }
}

void PostOp::build_vertex_to_pyramids(GRegion *gr)
{
  vertex_to_pyramids.clear();

  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *element = gr->getMeshElement(i);
    if(five(element)) { build_vertex_to_pyramids(element); }
  }
}

void PostOp::build_vertex_to_pyramids(MElement *element)
{
  std::set<MElement *> bin;

  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *getVertex = element->getVertex(i);

    Vertex2Elements::iterator it = vertex_to_pyramids.find(getVertex);
    if(it != vertex_to_pyramids.end()) { it->second.insert(element); }
    else {
      bin.clear();
      bin.insert(element);
      vertex_to_pyramids.insert(
        std::pair<MVertex *, std::set<MElement *> >(getVertex, bin));
    }
  }
}

void PostOp::erase_vertex_to_pyramids(MElement *element)
{
  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *getVertex = element->getVertex(i);

    Vertex2Elements::iterator it = vertex_to_pyramids.find(getVertex);
    if(it != vertex_to_pyramids.end()) { it->second.erase(element); }
  }
}

void PostOp::build_vertex_to_hexPrism(GRegion *gr)
{
  vertex_to_hexPrism.clear();

  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *element = gr->getMeshElement(i);
    if(six(element) || eight(element)) { build_vertex_to_hexPrism(element); }
  }
}

void PostOp::build_vertex_to_hexPrism(MElement *element)
{
  std::set<MElement *> bin;

  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *getVertex = element->getVertex(i);

    Vertex2Elements::iterator it = vertex_to_hexPrism.find(getVertex);
    if(it != vertex_to_hexPrism.end()) { it->second.insert(element); }
    else {
      bin.clear();
      bin.insert(element);
      vertex_to_hexPrism.insert(
        std::pair<MVertex *, std::set<MElement *> >(getVertex, bin));
    }
  }
}

void PostOp::erase_vertex_to_hexPrism(MElement *element)
{
  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *getVertex = element->getVertex(i);

    Vertex2Elements::iterator it = vertex_to_hexPrism.find(getVertex);
    if(it != vertex_to_hexPrism.end()) { it->second.erase(element); }
  }
}

// Angle between two triangular faces located on the boundary should be high
// enough
bool PostOp::valid(MPyramid *pyr)
{
  MVertex *V[4] = {pyr->getVertex(0), pyr->getVertex(1), pyr->getVertex(2),
                   pyr->getVertex(3)};
  MVertex *apex = pyr->getVertex(4);

  if(apex->onWhat()->dim() < 3) {
    for(int iP = 0; iP < 4; iP++) { // loop on pairs of triangles
      int nbBndNodes = 0;
      if(V[(0 + iP) % 4]->onWhat()->dim() < 3) nbBndNodes++;
      if(V[(1 + iP) % 4]->onWhat()->dim() < 3) nbBndNodes++;
      if(V[(2 + iP) % 4]->onWhat()->dim() < 3) nbBndNodes++;
      if(nbBndNodes == 3) {
        SVector3 vec1 = SVector3(V[(0 + iP) % 4]->x() - apex->x(),
                                 V[(0 + iP) % 4]->y() - apex->y(),
                                 V[(0 + iP) % 4]->z() - apex->z())
                          .unit();
        SVector3 vec2 = SVector3(V[(1 + iP) % 4]->x() - apex->x(),
                                 V[(1 + iP) % 4]->y() - apex->y(),
                                 V[(1 + iP) % 4]->z() - apex->z())
                          .unit();
        SVector3 vec3 = SVector3(V[(2 + iP) % 4]->x() - apex->x(),
                                 V[(2 + iP) % 4]->y() - apex->y(),
                                 V[(2 + iP) % 4]->z() - apex->z())
                          .unit();
        SVector3 crossVec1Vec2 = crossprod(vec1, vec2);
        double angle =
          std::abs(std::acos(dot(crossVec1Vec2, vec3)) * 180 / M_PI);
        double minAngle = 30;
        if(std::abs(angle - 90) < minAngle) return false;
      }
    }
  }
  return true;
}

// Why template?
template <class T>
void export_the_clique_graphviz_format(cliques_compatibility_graph<T> &cl,
                                       int clique_number,
                                       const std::string &filename)
{
  ofstream out(filename.c_str());
  out << "Graph G {" << endl;
  typename multimap<int, set<T> >::reverse_iterator it_all = cl.allQ.rbegin();

  for(int i = 0; i < clique_number; i++) { it_all++; }
  //  int clique_size = it_all->second.size();
  typename set<T>::iterator ithex = it_all->second.begin();
  typename set<T>::iterator ithexen = it_all->second.end();

  int counter = 1;
  map<T, int> visited_hex;
  multimap<int, int> done;

  // export all hex
  typename cliques_compatibility_graph<T>::graph::const_iterator itgraph =
    cl.begin_graph();
  typename cliques_compatibility_graph<T>::graph_data::const_iterator
    itgraphdata;

  for(; itgraph != cl.end_graph(); itgraph++) {
    T firsthex = itgraph->second.first;
    //    if (!post_check_validation(firsthex)) continue;

    typename map<T, int>::iterator itfind = visited_hex.find(firsthex);
    int num1 = 0;
    if(itfind == visited_hex.end()) {
      num1 = counter;
      visited_hex[firsthex] = counter++;
    }
    else {
      num1 = itfind->second;
    }
    itgraphdata = itgraph->second.second.begin();
    for(; itgraphdata != itgraph->second.second.end(); itgraphdata++) {
      T secondhex = itgraphdata->second;
      //      if (!post_check_validation(secondhex)) continue;
      itfind = visited_hex.find(secondhex);
      int num2 = 0;
      if(itfind == visited_hex.end()) {
        num2 = counter;
        visited_hex[secondhex] = counter++;
      }
      else {
        num2 = itfind->second;
      }
      // search if num1 - num2 has already been written...
      bool found = false;
      pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range =
        done.equal_range(num1);
      for(multimap<int, int>::iterator it = range.first; it != range.second;
          it++) {
        if(it->second == num2) {
          found = true;
          break;
        }
      }
      if(!found) {
        done.insert(make_pair(num1, num2));
        done.insert(make_pair(num2, num1));
        out << num1 << " -- " << num2 << " ;" << endl;
      }
    }
  }
  // export chosen hex with different color
  for(; ithex != ithexen;
      ithex++) { // brutal post-check: random pickup of hexahedra in clique
    typename map<T, int>::iterator itfind = visited_hex.find(*ithex);
    if(itfind == visited_hex.end()) {
      cout << "graph export: should not happen ! " << endl;
      throw;
      int num2 = 0;
      num2 = counter;
      visited_hex[itfind->first] = counter++;
      out << num2 << " [shape=circle, style=filled, fillcolor=red];" << endl;
    }
    else
      out << itfind->second << " [shape=circle, style=filled, fillcolor=red];"
          << endl;
  }

  out << "}" << endl;
  out.close();
}

template <class T>
clique_stop_criteria<T>::clique_stop_criteria(map<T, std::set<MElement *> > &_m,
                                              int _i)
  : hex_to_tet(_m), total_number_tet(_i){};

template <class T> clique_stop_criteria<T>::~clique_stop_criteria(){};

template <class T>
void clique_stop_criteria<T>::export_corresponding_mesh(
  const graph_data_no_hash &clique) const
{
  // NB: fct not often called...

  // filename
  string filename("best_clique_so_far.msh");
  string filenametets("best_clique_so_far_remaining_tets.msh");

  // create set of all tets
  set<MElement *> tets;
  set<MElement *> hexs;
  map<MVertex *, int> vertices;
  int counterv = 1;
  typename map<T, std::set<MElement *> >::const_iterator it =
    hex_to_tet.begin();
  for(; it != hex_to_tet.end(); it++) {
    std::set<MElement *>::const_iterator itt = it->second.begin();
    for(; itt != it->second.end(); itt++) {
      tets.insert(*itt);
      for(int i = 0; i < 4; i++) {
        vertices.insert(make_pair((*itt)->getVertex(i), counterv));
        counterv++;
      }
    }
  }

  // create MHexahedron, remove included tets from set "tets"
  for(typename graph_data_no_hash::const_iterator it = clique.begin();
      it != clique.end(); it++) {
    typename map<T, std::set<MElement *> >::const_iterator itfind =
      hex_to_tet.find(*it);
    if(itfind == hex_to_tet.end()) {
      cout << "clique_stop_criteria::void export_corresponding_mesh : not "
              "found !!!"
           << endl;
      throw;
    }
    // remove tets
    for(set<MElement *>::const_iterator ittet = itfind->second.begin();
        ittet != itfind->second.end(); ittet++) {
      tets.erase(*ittet);
    }
    // create MHexahedron
    Hex *hex = *it;
    MHexahedron *h =
      new MHexahedron(hex->getVertex(0), hex->getVertex(1), hex->getVertex(2),
                      hex->getVertex(3), hex->getVertex(4), hex->getVertex(5),
                      hex->getVertex(6), hex->getVertex(7));
    for(int i = 0; i < 8; i++) {
      vertices.insert(make_pair(hex->getVertex(i), counterv));
      counterv++;
    }
    hexs.insert(h);
  }

  // export mesh FIXME: why not use MElement::writeMSH
  ofstream out(filename.c_str());
  ofstream outtets(filenametets.c_str());
  out << "$MeshFormat" << endl
      << "2.2 0 8" << endl
      << "$EndMeshFormat" << endl
      << "$Nodes" << endl
      << vertices.size() << endl;
  outtets << "$MeshFormat" << endl
          << "2.2 0 8" << endl
          << "$EndMeshFormat" << endl
          << "$Nodes" << endl
          << vertices.size() << endl;
  // write vertices
  for(map<MVertex *, int>::iterator it = vertices.begin(); it != vertices.end();
      it++) {
    out << it->second << " " << it->first->x() << " " << it->first->y() << " "
        << it->first->z() << endl;
    outtets << it->second << " " << it->first->x() << " " << it->first->y()
            << " " << it->first->z() << endl;
  }
  out << "$EndNodes" << endl
      << "$Elements" << endl
      << (hexs.size() + tets.size()) << endl;
  outtets << "$EndNodes" << endl
          << "$Elements" << endl
          << (hexs.size() + tets.size()) << endl;
  // write hexs
  int counter = 1;
  int countertets = 1;
  for(set<MElement *>::iterator it = hexs.begin(); it != hexs.end(); it++) {
    out << counter << " 5 2 0 26";
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }
  // write tets
  for(set<MElement *>::iterator it = tets.begin(); it != tets.end(); it++) {
    out << counter << " 4 2 0 26";
    outtets << counter << " 4 2 0 26";
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
      outtets << " " << vertices[v];
    }
    out << endl;
    outtets << endl;
    counter++;
    countertets++;
  }
  out << "$EndElements" << endl;
  out.close();
  outtets << "$EndElements" << endl;
  outtets.close();
}

template <class T>
bool clique_stop_criteria<T>::stop(const graph_data_no_hash &clique) const
{
  unsigned int total = 0;

  // need to detect slivers !!!!!!!!!!!!!!!!!!!!!!!!!!

  // it seems like slivers are presents in different potential hex.
  // So, can be located by finding dupli!cates, instead of computing
  // volumes...??????

  set<MElement *> thetets;
  //  set<MElement*> slivers;
  for(typename graph_data_no_hash::const_iterator it = clique.begin();
      it != clique.end(); it++) {
    typename map<T, std::set<MElement *> >::const_iterator itfind =
      hex_to_tet.find(*it);
    if(itfind == hex_to_tet.end()) {
      cout << "clique_stop_criteria::bool stop : not found !!!" << endl;
      throw;
    }
    //    total += (itfind->second.size());
    //    cout << "volumes=" << endl;
    for(set<MElement *>::const_iterator ittet = itfind->second.begin();
        ittet != itfind->second.end(); ittet++) {
      //      set<MElement*>::iterator itfindtet = thetets.find(*ittet);
      //      if (itfindtet!=thetets.end()){
      //        cout << "Tet " << *ittet << " already done !!!" << endl;
      //        slivers.insert(*ittet);
      //      }
      thetets.insert(*ittet);
      // cout << (*ittet) << " : " << (*ittet)->getVolume()<< endl;;
    }
  }

  // to be sure, adding volume criteria...
  vector<double> volumes;
  for(set<MElement *>::iterator it = thetets.begin(); it != thetets.end();
      it++) {
    volumes.push_back((*it)->getVolume());
  }
  int meanvolume =
    (std::accumulate(volumes.begin(), volumes.end(), 0)) / volumes.size();
  int nb_slivers = 0;
  double threshold = 1.e-3 * meanvolume;
  for(set<MElement *>::iterator it = thetets.begin(); it != thetets.end();
      it++) {
    if((*it)->getVolume() < threshold) { nb_slivers++; }
  }

  total = thetets.size() - nb_slivers;

  //  cout << "# tet = " << total << " on " << total_number_tet << endl;
  //  cout << "#slivers = " << slivers.size() << endl;
  if(total >= total_number_tet) {
    cout << endl
         << " ************** criteria reached, domain is filled with hex !!! "
            "***************"
         << endl
         << endl;
    return true; // the maximum clique is maximum !!! only hex !!!
  }
  return false;
}

template <class T>
cliques_compatibility_graph<T>::cliques_compatibility_graph(
  graph &_g, const map<T, std::vector<double> > &_hex_ranks,
  unsigned int _max_nb_cliques, unsigned int _nb_hex_potentiels,
  clique_stop_criteria<T> *csc, ptrfunction_export fct)
  : found_the_ultimate_max_clique(false), export_clique_graph(fct),
    debug(false), max_nb_cliques(_max_nb_cliques),
    nb_hex_potentiels(_nb_hex_potentiels), max_clique_size(0), position(0),
    total_nodes_number(0), total_nb_of_cliques_searched(0),
    max_nb_of_stored_cliques(10), criteria(csc), cancel_search(false),
    hex_ranks(_hex_ranks), G(_g){};

template <class T>
cliques_compatibility_graph<T>::~cliques_compatibility_graph(){};

template <class T> void cliques_compatibility_graph<T>::find_cliques()
{
  // init
  graph_data s;
  for(typename graph::iterator it = G.begin(); it != G.end(); it++) {
    s.insert(make_pair(it->first, it->second.first));
  }
  find_cliques(s, 0);

  if(!cancel_search) {
    cout << total_nb_of_cliques_searched << " cliques have been found." << endl
         << flush;
  }
};

template <class T> void cliques_compatibility_graph<T>::export_cliques()
{
  typename multimap<int, set<T> >::reverse_iterator itstore = allQ.rbegin();
  for(; itstore != allQ.rend(); itstore++) {
    cout << "clique of size " << itstore->first << ": {";
    for(typename set<T>::iterator it = itstore->second.begin();
        it != itstore->second.end(); it++) {
      cout << *it << " ";
    }
    cout << "}" << endl;
  }
};

// A clique was found. Store it sometimes and decide what to do next.
// Shall we continue looking for better cliques or not.
template <class T> void cliques_compatibility_graph<T>::store_clique(int n)
{
  total_nb_of_cliques_searched++;

  // Should the search for other cliques be stopped?
  // --- Criteria on the number of cliques
  if((max_nb_cliques != 0) &&
     (total_nb_of_cliques_searched >= max_nb_cliques)) {
    cancel_search = true;
  }
  // --- Criteria on the space filling of the cliques - all tets are in a hex -
  // we filled the domain :)
  if(criteria->stop(Q)) {
    cancel_search = true;
    found_the_ultimate_max_clique = true;
  }

  // Should we store the clique and/or delete some other cliques?
  bool store_it = true;
  bool delete_worst = false;
  if(max_nb_of_stored_cliques && allQ.size() >= max_nb_of_stored_cliques) {
    // We have not enough space, a choice is to be made
    int worst_clique_size = (allQ.begin())->first;
    if((int)Q.size() <= worst_clique_size) {
      // The current clique is smaller than the smallest already stored
      store_it = false;
    }
    else {
      // We need to delete to smaller clique to make space for the current one
      delete_worst = true;
    }
  }
  if(store_it) {
    typename multimap<int, set<T> >::iterator itstore =
      allQ.insert(make_pair(Q.size(), set<T>()));
    itstore->second.insert(Q.begin(), Q.end());
    // for (typename graph_data_no_hash::iterator it = Q.begin(); it != Q.end();
    // it++) {
    //  itstore->second.insert(*it);
    //  if (debug) {
    //    //for (int i=0;i<n;i++) cout << " ";
    //    cout << *it << " ";
    //  }
    //}
  }
  // finally, possibly delete worst clique, to reduce memory footprint
  if(delete_worst) { allQ.erase(allQ.begin()); }

  bool found_best_clique_so_far = Q.size() > max_clique_size;
  if(found_best_clique_so_far) {
    max_clique_size = Q.size();
    cout << "found a maximum clique of size " << Q.size() << ", exporting"
         << endl;
  }

  if(found_best_clique_so_far) {
    string filename("best_clique_so_far.dot");
    export_clique_graph(const_cast<cliques_compatibility_graph<T> &>(*this), 0,
                        filename);
    criteria->export_corresponding_mesh(Q);
  }

  // Printing info mess
  const bool verbose = false;
  if(verbose)
    cout << "MAX CLIQUE found of size " << Q.size()
         << " # total cliques searched:" << total_nb_of_cliques_searched
         << endl;

  if(total_nb_of_cliques_searched % 10000 == 0) {
    if(max_nb_cliques > 0)
      cout << "found " << total_nb_of_cliques_searched << " cliques on "
           << max_nb_cliques << endl
           << flush;
    else
      cout << "found " << total_nb_of_cliques_searched << " cliques " << endl
           << flush;
  }

  if(debug) {
    for(int i = 0; i < n; i++) cout << " ";
    cout << "MAX CLIQUE found of size " << Q.size() << ": ";
  }
};

// Recursive function to find all maximal cliques in the input subgraph.
// Implements more or less the algorithm proposed in
//    "The worst-case complexity for generating all maximal cliques and
//    computational experiments"
//     Tomita et al., 2006. doi 10.1016/j.tcs.2006.06.015
//
// Very very very inefficient.
//
// What is n? the index of the clique being explored??.
template <class T>
void cliques_compatibility_graph<T>::find_cliques(graph_data &subgraph, int n)
{
  // possible end
  if(subgraph.size() == 0) {
    store_clique(n);
    return;
  }
  if(subgraph.size() == 1) {
    typename graph_data::iterator ittemp = subgraph.begin();
    T u = ittemp->second;
    Q.insert(u);
    store_clique(n);
    Q.erase(u);
    return;
  }

  T u = NULL; // Let's face it, this is a pointer.
  hash_key u_key = 0;
  // Choose the pivot: the node of the subgraph that
  // has a maximum number of adjacent nodes in the set of candidates
  // Maximize the number of black nodes.
  choose_u(subgraph, u, u_key);

  // The non-neighbors of u in the subgraph (but should be candidates)
  graph_data white;
  // The nodes adjacent to u in the subgraph (but should be candidates)
  graph_data black;
  split_set_BW(u, u_key, subgraph, white, black);

  // Explore all candidate and branches from there
  while(white.size() > 0) {
    Q.insert(u);
    if(n == 0) {
      total_nodes_number =
        std::max(total_nodes_number, (unsigned int)white.size());
      position++;
    }

    find_cliques(black, n + 1);
    if(cancel_search) { break; }

    erase_entry(white, u, u_key);
    erase_entry(subgraph, u, u_key);
    Q.erase(u);

    black.clear();
    if(white.size() > 0) {
      typename graph_data::iterator ittemp = white.begin();
      u = ittemp->second;
      u_key = ittemp->first;
      fill_black_set(u, u_key, subgraph, black); // building the black set only
    }
  }
}

template <class T>
void cliques_compatibility_graph<T>::erase_entry(graph_data &subgraph, T &u,
                                                 hash_key &key)
{
  pair<typename graph_data::iterator, typename graph_data::iterator> range =
    subgraph.equal_range(key);

  typename graph_data::iterator it = range.first;
  for(; it != range.second; it++) {
    if(it->second == u) {
      subgraph.erase(it);
      return;
    }
  }
}

// Chooses the node which ahs the maximum number of neighbors in the subgraph.
// Does not implement exactly what's is the paper [Tomita et al. 2006] where u
// is chosen to maximize the intersection of its neighbors in the CAND subset.
// No idea why. JP.
template <class T>
void cliques_compatibility_graph<T>::choose_u(const graph_data &subgraph, T &u,
                                              hash_key &u_key)
{
  double valuemax = -DBL_MAX;
  for(typename graph_data::const_iterator it = subgraph.begin();
      it != subgraph.end(); it++) {
    double value = function_to_maximize_for_u(it->second, it->first, subgraph);
    if(value > valuemax) {
      valuemax = value;
      u = it->second;
      u_key = it->first;
    }
  }
}

template <class T>
void cliques_compatibility_graph<T>::split_set_BW(const T &u,
                                                  const hash_key &u_key,
                                                  const graph_data &subgraph,
                                                  graph_data &white,
                                                  graph_data &black)
{
  // splitting set subgraph into white and black nodes
  white.insert(make_pair(u_key, u));
  typename graph_data::const_iterator it = subgraph.begin();
  for(; it != subgraph.end(); it++) {
    if(u == (it->second)) continue;
    if(!compatibility(u, u_key, it->second, it->first))
      white.insert(make_pair(it->first, it->second));
    else
      black.insert(make_pair(it->first, it->second));
  }
}

template <class T>
void cliques_compatibility_graph<T>::fill_black_set(const T &u,
                                                    const hash_key &u_key,
                                                    const graph_data &subgraph,
                                                    graph_data &black)
{
  // filling black set
  typename graph_data::const_iterator it = subgraph.begin();
  for(; it != subgraph.end(); it++) {
    if(u == (it->second)) continue;
    if(compatibility(u, u_key, it->second, it->first))
      black.insert(make_pair(it->first, it->second));
  }
}

// Count the number of neighbors of u in the input graph
// We are looking for the u that has a maximal number of adjacent nodes in the
// graph
template <class T>
double cliques_compatibility_graph<T>::function_to_maximize_for_u(
  const T &u, const hash_key &u_key, const graph_data &subgraph)
{
  int counter = 0;
  for(typename graph_data::const_iterator it = subgraph.begin();
      it != subgraph.end(); it++) {
    if((it->second) == u) continue;
    if(compatibility(u, u_key, it->second, it->first)) counter++;
  }
  return (double)counter;
}

// Returns true if v is adjacent to u in graph G
template <class T>
bool cliques_compatibility_graph<T>::compatibility(const T &u,
                                                   const hash_key &u_key,
                                                   const T &v,
                                                   const hash_key &v_key)
{
  // Find u data
  pair<typename graph::const_iterator, typename graph::const_iterator>
    range_ukey = G.equal_range(u_key);
  typename graph::const_iterator itfind_u = range_ukey.first;
  for(; itfind_u != range_ukey.second; itfind_u++) {
    if(itfind_u->second.first == u) break;
  }
  // Check if v is in u data
  pair<typename graph_data::const_iterator, typename graph_data::const_iterator>
    range_vkey = itfind_u->second.second.equal_range(v_key);
  for(typename graph_data::const_iterator itfind_v = range_vkey.first;
      itfind_v != range_vkey.second; itfind_v++) {
    if(itfind_v->second == v) { return true; }
  }
  return false;
}

// Returns true if v is NOT adjacent to u in graph G
template <class T>
bool cliques_losses_graph<T>::compatibility(const T &u, const hash_key &u_key,
                                            const T &v, const hash_key &v_key)
{
  return !cliques_compatibility_graph<T>::compatibility(u, u_key, v, v_key);
}

template <class T>
cliques_losses_graph<T>::cliques_losses_graph(
  graph &_g, const map<T, std::vector<double> > &_hex_ranks,
  unsigned int _max_nb_cliques, unsigned int _nb_hex_potentiels,
  clique_stop_criteria<T> *csc, ptrfunction_export fct)
  : cliques_compatibility_graph<T>(_g, _hex_ranks, _max_nb_cliques,
                                   _nb_hex_potentiels, csc, fct) /*, G(_g)*/
    {};

template <class T> cliques_losses_graph<T>::~cliques_losses_graph(){};

//////////////////////////////////////////////////////////////////////////////////////////////////////////

PEEntity::PEEntity(const vector<MVertex *> &_v) : vertices(_v)
{
  compute_hash();
}

// PEEntity::PEEntity(unsigned long long l):hash(l){
//}

void PEEntity::compute_hash()
{
  hash = 0;
  for(vector<MVertex *>::const_iterator it = vertices.begin();
      it != vertices.end(); it++)
    hash += (*it)->getNum();
}

size_t PEEntity::get_hash() const { return hash; }

PEEntity::~PEEntity() {}

MVertex *PEEntity::getVertex(size_t n) const
{
  if((n > get_max_nb_vertices()) || vertices.empty()) {
    cout << " PEEntity::getVertex : wrong getVertex number : int n = " << n
         << endl;
    throw;
  }
  return vertices[n];
}

bool PEEntity::hasVertex(MVertex *v) const
{
  return std::find(vertices.begin(), vertices.end(), v) != vertices.end();
}

bool PEEntity::same_vertices(const PEEntity *t) const
{
  for(vector<MVertex *>::const_iterator it = vertices.begin();
      it != vertices.end(); it++) {
    if(!(t->hasVertex(*it))) return false;
  }
  return true;
}

bool PEEntity::operator<(const PEEntity &t) const
{
  return hash < t.get_hash();
}

// bool PEEntity::operator==(const PEEntity& t) const{
//  return (hash==t.get_hash());
//}

// bool PEEntity::operator==(const size_t& l) const{
//  return (hash==l);
//}

PELine::~PELine(){};

PELine::PELine(const vector<MVertex *> &_v) : PEEntity(_v)
{
  if(vertices.size() != get_max_nb_vertices()) {
    cout << "PELine: wrong number of vertices given !!! aborting ! " << endl;
    throw;
  }
  compute_hash();
}

size_t PELine::get_max_nb_vertices() const { return 2; };

PETriangle::~PETriangle(){};

PETriangle::PETriangle(const vector<MVertex *> &_v) : PEEntity(_v)
{
  if(vertices.size() != get_max_nb_vertices()) {
    cout << "PETriangle: wrong number of vertices given !!! aborting ! "
         << endl;
    throw;
  }
  compute_hash();
}

// PETriangle::PETriangle(const unsigned long long l):PEEntity(l){
//}

size_t PETriangle::get_max_nb_vertices() const { return 3; };

PEQuadrangle::~PEQuadrangle(){};

PEQuadrangle::PEQuadrangle(const vector<MVertex *> &_v) : PEEntity(_v)
{
  if(vertices.size() != get_max_nb_vertices()) {
    cout << "PEQuadrangle: wrong number of vertices given !!! aborting ! "
         << endl;
    throw;
  }
  compute_hash();
}

// PEQuadrangle::PEQuadrangle(const unsigned long long l):PEEntity(l){
//}

size_t PEQuadrangle::get_max_nb_vertices() const { return 4; };

// Check the validity of the hex
// and add it to the potential hex.
// TODO -- WE NEED ASSERTIONS in release mode and a command line to print stuff
// TODO -- Implement clear validity checks - topological validity and
// geometrical validity WARNING this function seems to be a mess -- I expect it
// to do not work as expected. JP. Stuff are commented, the test to check if a
// potential exist seems does not work and is bypassed.
void Recombinator_Graph::fill_tet_to_hex_table(Hex *hex)
{
  const bool very_verbose = false;
  const bool bypass = true;

  if(very_verbose) {
    cout << " fill_tet_to_hex_table:: treating hex " << hex << " made of ";
    for(int i = 0; i < 8; i++) cout << "  " << hex->getVertex(i)->getNum();
    cout << endl;
  }

  if(!valid(*hex, tet_mesh)) {
    if(very_verbose) cout << "NOT VALID hex !!! " << endl;
    delete hex;
    return;
  }

  MElement *element;
  std::set<MElement *> parts;
  // recovering all the tets forming the current hex
  parts.clear();
  ::find(*hex, parts, tet_mesh);

  if(!valid(*hex, parts)) {
    if(very_verbose) cout << " NOT VALID hex (parts) " << endl;
    delete hex;
    return;
  }

  // storing all tets in tet_to_hex database (for use in indirect neighbors)
  // first, check if the hex has the right number of vertices (=8 !!!)
  // non, c'est pas toujours le cas !!! ???

  set<MVertex *> vertices;
  for(element_set_itr it = parts.begin(); it != parts.end(); it++) {
    element = *it;
    for(int i = 0; i < 4; i++) { vertices.insert(element->getVertex(i)); }
  }

  if(vertices.size() != 8) {
    if(very_verbose)
      cout << "------------- WARNING !!!!! An hex has " << vertices.size()
           << "vertices" << endl;
    delete hex;
    return;
  }

  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!! le test suivant déconne, cf. cube à 125
  // hex... sais pas pourquoi, mais ça élimine des hex potentiels tout à fait
  // valides (et nécessaires à la solution optimale)!!! dans le cas cube125: ce
  // test fait passer le #hex potentiels recensés par les patterns de
  // recombinaison d'environ 1000 à 2434 ??? !!!, ça double aussi le nbre d'hex
  // dans le graphe des pertes en fait, si les noeuds par exemple a b c d
  // deviennent b c d a, on a une rotation et un hex tout pourri... mais qui a
  // même hash et mêmes noeuds ?!?! now, check if the hex already exists...
  if(!bypass) {
    graph_data::const_iterator itfind =
      find_the_created_potential_hex(hex, created_potential_hex);
    if(itfind != created_potential_hex.end()) {
      delete hex;
      if(very_verbose)
        cout << " WARNING: current hex already exists in the created potentiel "
                "hex database. Not adding the hex."
             << endl;
      return;
    }
  }
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!

  // counting the number of triangular external faces. If different from 12,
  // discard the hex ! if not, build the face/hex table
  std::multimap<unsigned long long, pair<PETriangle *, int> > faces_temp;
  for(element_set_itr it_tet = parts.begin(); it_tet != parts.end();
      it_tet++) { // for all tets
    for(int i = 0; i < 4; i++) { // for all faces
      MFace f = (*it_tet)->getFace(i);
      add_face(f.getVertex(0), f.getVertex(1), f.getVertex(2), faces_temp);
    }
  }

  int count = 0;
  std::multimap<unsigned long long, pair<PETriangle *, int> >::iterator
    it_face = faces_temp.begin();
  std::multimap<unsigned long long, pair<PETriangle *, int> >::iterator
    it_faceen = faces_temp.end();
  for(; it_face != it_faceen; it_face++) // counting
    if(it_face->second.second == 1) count++;

  if(count != 12) {
    if(very_verbose)
      cout << "------------- WARNING !!!!! fill_tet_to_hex_table:: hex  has "
           << count << " faces ... discard the hex." << endl;
    delete hex;
    return;
  }

  it_face = faces_temp.begin();
  for(; it_face != it_faceen;
      it_face++) { // for all faces, storing the external faces
    PETriangle *t = it_face->second.first;
    if(it_face->second.second == 1)
      add_face(t->getVertex(0), t->getVertex(1), t->getVertex(2), hex);
    else
      delete t;
  }

  // We are keeping the tet. Store it and map it to the
  // constituve tets

  // The hex addition was in the loop on its constitutive tet. oups.
  // might be a source of the above problem... but I am quite unsure. JP.
  created_potential_hex.insert(make_pair(hex->get_hash(), hex));
  add_edges(hex);
  for(element_set_itr it = parts.begin(); it != parts.end(); it++) {
    element = *it;
    tet_to_hex[element].insert(hex);
    hex_to_tet[hex].insert(element);
  }

  if(very_verbose) { export_single_hex_all(hex, ""); }
}

void Recombinator_Graph::buildGraphOnly(unsigned int max_nb_cliques,
                                        string filename)
{
  GRegion *gr;
  GModel *model = GModel::current();
  GModel::riter it;

  for(it = model->firstRegion(); it != model->lastRegion(); it++) {
    gr = *it;
    if(gr->getNumMeshElements() > 0) {
      buildGraphOnly(gr, max_nb_cliques, filename);
    }
  }
}

void Recombinator_Graph::buildGraphOnly(GRegion *gr,
                                        unsigned int max_nb_cliques,
                                        string filename)
{
  set_current_region(gr);
  tet_mesh.initialize(current_region);

  hex_to_tet.clear();
  tet_to_hex.clear();
  created_potential_hex.clear();

  build_tuples();

  compute_potential_hexes();

  create_losses_graph(gr);
  compute_hex_ranks();
  found_the_ultimate_max_clique = false;
}

void Recombinator_Graph::execute_blossom(unsigned int max_nb_cliques,
                                         const std::string &filename)
{
  GRegion *gr;
  GModel *model = GModel::current();
  GModel::riter it;

  model->writeMSH("beforeyamakawa.msh");

  for(it = model->firstRegion(); it != model->lastRegion(); it++) {
    gr = *it;
    if(gr->getNumMeshElements() > 0) {
      execute_blossom(gr, max_nb_cliques, filename);
    }
  }
}

Recombinator_Graph::~Recombinator_Graph()
{
  for(iter it = triangular_faces.begin(); it != triangular_faces.end(); it++) {
    delete it->second;
  }
  for(linemap::iterator it = edges_and_diagonals.begin();
      it != edges_and_diagonals.end(); it++) {
    delete it->second;
  }

  // Check that all is deleted. It is such a mess
  // that it is hard to tell which pointers are actually owned by the class. JP
}

void Recombinator_Graph::createBlossomInfo()
{
  throw;

  GRegion *gr;
  GModel *model = GModel::current();
  GModel::riter it;

  for(it = model->firstRegion(); it != model->lastRegion(); it++) {
    gr = *it;
    //    if(gr->getNumMeshElements()>0){
    createBlossomInfo(gr);
    //    }
  }
}

void Recombinator_Graph::createBlossomInfo(GRegion *gr)
{
  throw;

  // remove quads, create triangles, and store blossom information (triangles
  // pairs)
  std::vector<GFace *> faces = gr->faces();
  GFace *gf;
  MElement *element;
  PETriangle *t11, *t12, *t21, *t22;

  cout << "recover blossom info" << endl;

  for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
      it++) {
    gf = *it;

    std::vector<MQuadrangle *>::iterator it_quad = gf->quadrangles.begin();

    for(; it_quad != gf->quadrangles.end(); it_quad++) {
      element = *it_quad;

      // recovering triangular faces
      t11 = get_triangle(element, 0, 1, 2);
      t12 = get_triangle(element, 0, 2, 3);
      t21 = get_triangle(element, 0, 1, 3);
      t22 = get_triangle(element, 1, 2, 3);

      // creating blossom info (pairs of triangles)
      blossom_info[t11] = t12;
      blossom_info[t12] = t11;
      blossom_info[t21] = t22;
      blossom_info[t22] = t21;

      tri_to_gface_info[t11] = gf;
      tri_to_gface_info[t12] = gf;
      tri_to_gface_info[t21] = gf;
      tri_to_gface_info[t22] = gf;

      // adding triangles
      gf->addTriangle(new MTriangle(
        element->getVertex(0), element->getVertex(1), element->getVertex(2)));
      gf->addTriangle(new MTriangle(
        element->getVertex(0), element->getVertex(2), element->getVertex(3)));
    }
    // deleting quads
    gf->quadrangles.clear();
  }

  //  // cut pyramids in 2 tets, remove pyramids
  //  std::vector<MPyramid*>::iterator it_pyramid = gr->pyramids.begin();
  //  MPyramid *p;
  //  vector<MVertex*>v;
  //  citer it_find_tri;
  //  cout << "start cutting pyramids" << endl;
  //  for (;it_pyramid!=gr->pyramids.end();it_pyramid++){
  //    // arbirary cut of the pyramid...
  //    p = *it_pyramid;
  //    // add tets
  //    gr->addTetrahedron(new MTetrahedron(p->getVertex(0),
  //    p->getVertex(1),p->getVertex(2),p->getVertex(4)));
  //    gr->addTetrahedron(new MTetrahedron(p->getVertex(0),
  //    p->getVertex(2),p->getVertex(3),p->getVertex(4)));
  //
  //    // add triangles to the right GFace
  //    v.clear();
  //    v.push_back(p->getVertex(0));
  //    v.push_back(p->getVertex(1));
  //    v.push_back(p->getVertex(2));
  //    t11 = new PETriangle(v);
  //    it_find_tri = find_the_triangle(t11, triangular_faces);
  //    if (it_find_tri != triangular_faces.end()){
  //      std::list<GFace*>::iterator it_find_face = std::find(faces.begin(),
  //      faces.end(),tri_to_gface_info[it_find_tri->second]); if
  //      (it_find_face!=faces.end()){
  //        (*it_find_face)->addTriangle(new MTriangle(p->getVertex(0),
  //        p->getVertex(1), p->getVertex(2)));
  //      }
  //      else
  //        cout << "WARNING blossom: face not found !  Can't add triangle !" <<
  //        endl;
  //    }
  //    else
  //      cout << "WARNING blossom: triangle not found ! " << endl;
  //    delete t11;
  //
  //    v.clear();
  //    v.push_back(p->getVertex(0));
  //    v.push_back(p->getVertex(2));
  //    v.push_back(p->getVertex(3));
  //    t11 = new PETriangle(v);
  //    it_find_tri = find_the_triangle(t11, triangular_faces);
  //    if (it_find_tri != triangular_faces.end()){
  //      std::list<GFace*>::iterator it_find_face = std::find(faces.begin(),
  //      faces.end(),tri_to_gface_info[it_find_tri->second]); if
  //      (it_find_face!=faces.end()){
  //        (*it_find_face)->addTriangle(new MTriangle(p->getVertex(0),
  //        p->getVertex(2),p->getVertex(3)));
  //      }
  //      else
  //        cout << "WARNING blossom: face not found ! Can't add triangle !" <<
  //        endl;
  //    }
  //    else
  //      cout << "WARNING blossom: triangle not found ! " << endl;
  //    delete t11;
  //  }
  //  // erase all pyramids
  //  cout << "erasing all pyramids" << endl;
  //  gr->pyramids.clear();
}

void Recombinator_Graph::execute_blossom(GRegion *gr,
                                         unsigned int max_nb_cliques,
                                         const std::string &filename)
{
  throw;

  initialize_structures(gr);

  hex_to_tet.clear();
  tet_to_hex.clear();
  created_potential_hex.clear();

  Msg::Info("Building Connectivity...");

  double a = Cpu();

  compute_potential_hexes();

  create_losses_graph(gr);
  // add points to potential hexas containing original blossom pairs of
  // triangles
  compute_hex_ranks_blossom();

  double time_building_graph = (Cpu() - a);

  a = Cpu();
  // a criteria to stop when the whole domain is exclusively composed of hex
  clique_stop_criteria<Hex *> criteria(hex_to_tet, gr->tetrahedra.size());

  cliques_losses_graph<Hex *> cl(incompatibility_graph, hex_ranks,
                                 max_nb_cliques, hex_to_tet.size(), &criteria,
                                 export_the_clique_graphviz_format);
  cl.find_cliques();
  // cl.export_cliques();

  double time_cliques = (Cpu() - a);

  cout << "RECOMBINATOR_GRAPH timing:" << endl;
  cout << "  ------- TIME BUILDING GRAPH : " << time_building_graph
       << " subgraph." << endl;
  cout << "  ------- TIME CLIQUE         : " << time_cliques << " subgraph."
       << endl;

  int clique_number = 0;

  //  export_clique_graphviz_format(cl,1,"mygraph2.dot");
  export_the_clique_graphviz_format(cl, clique_number, filename);

  merge_clique(gr, cl, clique_number);

  improve_final_mesh();

  print_statistics();

  return;
  //  create_indirect_neighbors_graph();
  //  update_degree(gr,true);
  //  create_compatibility_graph();
  //
  //
  //  cout << "size edges : " << edges.size() << endl;
  //  cout << "size degree : " << idegree.size() << endl;
  //  cout << "size hex_to_tet : " << hex_to_tet.size() << endl;
  //
  //  hash_tableA.clear();
  //  hash_tableB.clear();
  //  hash_tableC.clear();
  //
  //  export_direct_neighbor_table(50);
  //  merge(gr);
  //
  //  rearrange(gr);
  //
  //  statistics(gr);
  //
  //  create_quads_on_boundary(gr);
}

// return the triangular face ijk if it exists. If not, creates it and returns
// it.
PETriangle *Recombinator_Graph::get_triangle(MElement *element, int i, int j,
                                             int k)
{
  vector<MVertex *> v;
  PETriangle *t;
  v.push_back(element->getVertex(i));
  v.push_back(element->getVertex(j));
  v.push_back(element->getVertex(k));
  t = new PETriangle(v);
  citer itfind = find_the_triangle(t, triangular_faces);
  if(itfind == triangular_faces.end()) {
    itfind = triangular_faces.insert(make_pair(t->get_hash(), t));
  }
  else {
    delete t;
    t = itfind->second;
  }
  return t;
}

Recombinator_Graph::Recombinator_Graph(unsigned int _n,
                                       const std::string &filename)
  : max_nb_cliques(_n), graphfilename(filename)
{
}

void Recombinator_Graph::execute(GRegion *gr)
{
  printf("................HEXAHEDRA...GRAPH RECOMBINATOR................\n");

  initialize_structures(gr);
  compute_potential_hexes();

  create_losses_graph(gr);

#ifndef EXTERNAL_MIN_WEIGHTED_SET_SEARCH
  compute_hex_ranks();

  // a criteria to stop when the whole domain is exclusively composed of hex
  found_the_ultimate_max_clique = false;
  clique_stop_criteria<Hex *> criteria(hex_to_tet, gr->tetrahedra.size());
  cliques_losses_graph<Hex *> cl(incompatibility_graph, hex_ranks,
                                 max_nb_cliques, hex_to_tet.size(), &criteria,
                                 export_the_clique_graphviz_format);
  cl.find_cliques();

  found_the_ultimate_max_clique = cl.found_the_ultimate_max_clique;

  int clique_number = 0;
  if(graphfilename.empty()) graphfilename.assign("mygraph.dot");
  // export_clique_graphviz_format(cl,1,"mygraph2.dot");
  export_the_clique_graphviz_format(cl, clique_number, graphfilename);

  merge_clique(gr, cl, clique_number);
#else
  struct vertex {
    Hex *hex;
    double quality;
  };

  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
                                vertex>
    graph_type;

  typedef boost::graph_traits<graph_type>::vertex_descriptor vertex_id;

  graph_type graph;
  std::map<std::set<MElement *>, vertex_id> vertex_map;

  for(graph::iterator it = incompatibility_graph.begin();
      it != incompatibility_graph.end(); it++) {
    Hex *hex = it->second.first;
    const std::set<MElement *> &key = hex_to_tet[hex];
    if(vertex_map.find(key) == vertex_map.end()) {
      vertex_id vid = add_vertex(graph);
      graph[vid].hex = hex;
      graph[vid].quality = hex->get_quality();

      vertex_map[key] = vid;
    }
  }

  for(graph::iterator it = incompatibility_graph.begin();
      it != incompatibility_graph.end(); it++) {
    Hex *hex = it->second.first;
    vertex_id vid = vertex_map[hex_to_tet[hex]];

    for(graph_data::const_iterator data_it = it->second.second.begin();
        data_it != it->second.second.end(); data_it++) {
      Hex *other_hex = data_it->second;
      vertex_id other_vid = vertex_map[hex_to_tet[other_hex]];

      if(vid != other_vid && !edge(vid, other_vid, graph).second) {
        add_edge(vid, other_vid, graph);
      }
    }
  }

  typename boost::property_map<graph_type, double vertex::*>::type weight_map =
    get(&vertex::quality, graph);

  std::vector<vertex_id> vertices;
  maximum_weight_independent_set(graph, weight_map,
                                 std::back_inserter(vertices));

  hash_tableA.clear();
  hash_tableB.clear();
  hash_tableC.clear();

  for(std::vector<vertex_id>::const_iterator it = vertices.begin();
      it != vertices.end(); it++) {
    Hex *hex = graph[*it].hex;
    merge_hex(gr, hex);
  }
#endif

  // post-processing
  set_region_elements_positive();
  print_statistics();
  create_quads_on_boundary();
}

void Recombinator_Graph::merge_clique(GRegion *gr,
                                      cliques_losses_graph<Hex *> &cl,
                                      int clique_number)
{
  multimap<int, set<Hex *> >::reverse_iterator it_all = cl.allQ.rbegin();
  multimap<int, set<Hex *> >::reverse_iterator it_allen = cl.allQ.rend();
  int clique_counter = 0;
  std::set<MElement *> parts;
  // int clique_size = 0;

  for(int i = 0; i < clique_number; i++) { it_all++; }

  for(; it_all != it_allen; it_all++, clique_counter++) {
    if(clique_counter >= 1) break;

    // cout << "--------------------- clique " << clique_counter << " made of ";
    // clique_size = it_all->second.size();
    set<Hex *>::iterator ithex = it_all->second.begin();
    set<Hex *>::iterator ithexen = it_all->second.end();
    double quality = 0.;
    int count = 0;

    hash_tableA.clear();
    hash_tableB.clear();
    hash_tableC.clear();

    for(; ithex != ithexen;
        ithex++) { // brutal post-check: random pickup of hexahedra in clique
      Hex *current_hex = *ithex;
      if(merge_hex(gr, current_hex)) {
        quality = quality + current_hex->get_quality();
        count++;
      }
    }
  }
}

bool Recombinator_Graph::merge_hex(GRegion *gr, Hex *hex)
{
  if(!post_check_validation(hex)) return false;

  MHexahedron *h = new MHexahedron(hex->vertices());
  gr->addHexahedron(h);

  std::set<MElement *>::iterator it_tet_to_remove = hex_to_tet[hex].begin();
  std::vector<MTetrahedron *>::iterator itfind_tet_region;
  for(; it_tet_to_remove != hex_to_tet[hex].end(); it_tet_to_remove++) {
    itfind_tet_region = std::find(gr->tetrahedra.begin(), gr->tetrahedra.end(),
                                  (MTetrahedron *)(*it_tet_to_remove));

    if(itfind_tet_region != gr->tetrahedra.end()) {
      gr->tetrahedra.erase(itfind_tet_region);
      delete *it_tet_to_remove;
    }
  }

  build_hash_tableA(*hex);
  build_hash_tableB(*hex);
  build_hash_tableC(*hex);

  return true;
}

// Why derive then ?? this is quite stupid
void Recombinator_Graph::merge(GRegion *gr) { throw; }

void Recombinator_Graph::export_tets(set<MElement *> &tetset, Hex *hex,
                                     const string &s)
{
  stringstream ss;
  ss << s.c_str();
  ss << "hexptr_";
  ss << hex;
  ss << "_tetparts.pos";
  ofstream out(ss.str().c_str());

  out << "View \"hex tets parts\" {" << endl;
  element_set_itr it = tetset.begin();
  element_set_itr iten = tetset.end();
  int count = 0;
  for(; it != iten; it++, count++) {
    out << "SS(";
    for(int n = 0; n < 4; n++) {
      MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if(n != 3) out << ",";
    }
    out << "){";
    for(int n = 0; n < 4; n++) {
      out << count;
      if(n != 3) out << ",";
    }
    out << "};" << endl;
  }
  out << "};" << endl;
  out.close();
}

void Recombinator_Graph::export_single_hex_tet(Hex *hex, const string &s)
{
  stringstream ss;
  ss << s.c_str();
  ss << "hexptr_";
  ss << hex;
  ss << "_tet.pos";
  ofstream out(ss.str().c_str());

  out << "View \"hex tets\" {" << endl;
  element_set_itr it = hex_to_tet[hex].begin();
  element_set_itr iten = hex_to_tet[hex].end();
  int count = 0;
  for(; it != iten; it++, count++) {
    out << "SS(";
    for(int n = 0; n < 4; n++) {
      MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if(n != 3) out << ",";
    }
    out << "){";
    for(int n = 0; n < 4; n++) {
      out << count;
      if(n != 3) out << ",";
    }
    out << "};" << endl;
  }
  out << "};" << endl;
  out.close();
}

void Recombinator_Graph::export_single_hex_all(Hex *hex, const string &s)
{
  export_single_hex(hex, s);
  export_single_hex_tet(hex, s);
  export_single_hex_faces(hex, s);
}

void Recombinator_Graph::export_single_hex(Hex *hex, const string &s)
{
  stringstream ss;
  ss << s.c_str();
  ss << "hexptr_";
  ss << hex;
  ss << ".pos";
  ofstream out(ss.str().c_str());

  out << "View \"hex\" {" << endl;
  out << "SH(";
  for(int n = 0; n < 8; n++) {
    MVertex *v = hex->getVertex(n);
    out << v->x() << "," << v->y() << "," << v->z();
    if(n != 7) out << ",";
  }
  out << "){";
  for(int n = 0; n < 8; n++) {
    out << "0.";
    if(n != 7) out << ",";
  }
  out << "};" << endl;

  out << "};" << endl;
  out.close();
}

void Recombinator_Graph::export_single_hex_faces(Hex *hex, const string &s)
{
  stringstream ss;
  ss << s.c_str();
  ss << "hexptr_";
  ss << hex;
  ss << "_face.pos";
  ofstream out(ss.str().c_str());

  out << "View \"hex faces\" {" << endl;
  std::set<PETriangle *>::iterator it = hex_to_faces[hex].begin();
  std::set<PETriangle *>::iterator iten = hex_to_faces[hex].end();
  int count = 0;
  for(; it != iten; it++, count++) {
    out << "ST(";
    for(int n = 0; n < 3; n++) {
      MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if(n != 2) out << ",";
    }
    out << "){";
    for(int n = 0; n < 3; n++) {
      out << count;
      if(n != 2) out << ",";
    }
    out << "};" << endl;
  }
  out << "};" << endl;
  out.close();
}

void Recombinator_Graph::export_hex_init_degree(
  GRegion *gr, const std::map<Hex *, int> &init_degree,
  const vector<Hex *> &chosen_hex)
{
  stringstream ss;
  ss << "init_degree";
  ss << ".pos";
  ofstream out(ss.str().c_str());

  std::vector<Hex *>::const_iterator it = chosen_hex.begin();
  out << "View \"hex\" {" << endl;
  for(; it != chosen_hex.end(); it++) {
    out << "SH(";
    for(int n = 0; n < 8; n++) {
      MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if(n != 7) out << ",";
    }
    map<Hex *, int>::const_iterator itfind = init_degree.find(*it);
    out << "){";
    for(int n = 0; n < 8; n++) {
      out << itfind->second;
      if(n != 7) out << ",";
    }
    out << "};" << endl;
  }
  out << "};" << endl;

  out.close();
}

void Recombinator_Graph::export_hexmesh_so_far(int &file)
{
  stringstream ss;
  stringstream ssinit;
  ss << "hex_mesh_temp";
  char chose[256];
  sprintf(chose, "_%0*d", 6, file);
  ss << chose;
  ss << ".msh";
  ofstream out(ss.str().c_str());

  GModel *model = GModel::current();
  model->save(ss.str().c_str());

  out.close();
}

void Recombinator_Graph::export_all_hex(int &file, GRegion *gr)
{
  stringstream ss;
  stringstream ssinit;
  ss << "hex_progression";
  ssinit << "hex_progression_initdegree";
  //  ss << file;
  char chose[256];
  sprintf(chose, "_%0*d", 6, file);
  ss << chose;
  ss << ".pos";
  ssinit << chose;
  ssinit << ".pos";
  ofstream out(ss.str().c_str());

  std::vector<MHexahedron *>::iterator it = gr->hexahedra.begin();
  int i = 1;
  out << "View \"hex\" {" << endl;
  for(; it != gr->hexahedra.end(); it++, i++) {
    out << "SH(";
    for(int n = 0; n < 8; n++) {
      MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if(n != 7) out << ",";
    }
    out << "){";
    for(int n = 0; n < 8; n++) {
      out << i;
      if(n != 7) out << ",";
    }
    out << "};" << endl;
  }
  out << "};" << endl;

  out.close();
}

// check if the hex is good enough to be put into the graph. If not in the
// graph, it cannot be chosen...
bool Recombinator_Graph::is_not_good_enough(Hex *hex)
{
  double quality_threshold = 0.5;
  return hex->get_quality() < quality_threshold || !faces_statuquo(*hex);
}

// Add entries in the incompatibility_graph for all hexes sharing a non-sliver
// tetrahedra For the entry to be added the hex also have to be good_enough
void Recombinator_Graph::create_indirect_neighbors_graph()
{
  std::map<MElement *, std::set<Hex *> >::iterator it_tet = tet_to_hex.begin();
  for(; it_tet != tet_to_hex.end(); it_tet++) {
    std::set<Hex *>::iterator it_hex1 = it_tet->second.begin();
    for(; it_hex1 != it_tet->second.end(); it_hex1++) {
      Hex *hex = *it_hex1;

      if(sliver(it_tet->first, *hex)) {
        // Slivers may be shared by several hex and do not define an
        // incompatibility relationship
        continue;
      }
      if(is_not_good_enough(hex)) { continue; }
      graph::iterator itfind_graph = find_hex_in_graph(hex);
      if(itfind_graph == incompatibility_graph.end()) {
        // Add the hex to the graph
        itfind_graph = incompatibility_graph.insert(
          make_pair(hex->get_hash(), make_pair(hex, graph_data())));
        set_of_all_hex_in_graph.insert(hex);
      }
      // Link the hex as incompatible to all the good enough hex
      // that share the current tet
      for(std::set<Hex *>::iterator it_hex2 = it_tet->second.begin();
          it_hex2 != it_tet->second.end(); it_hex2++) {
        Hex *hex2 = *it_hex2;
        if(hex != hex2 && !is_not_good_enough(hex2)) {
          // Add the pair hex-hex2 to the graph
          itfind_graph->second.second.insert(make_pair(hex2->get_hash(), hex2));
        }
      }
    }
  }
}

std::multimap<unsigned long long, Hex *>::const_iterator
Recombinator_Graph::find_the_created_potential_hex(
  Hex *hex, const std::multimap<unsigned long long, Hex *> &list)
{
  std::pair<graph_data::const_iterator, graph_data::const_iterator> range =
    list.equal_range(hex->get_hash());
  for(graph_data::const_iterator it = range.first; it != range.second; it++) {
    Hex *candidate = it->second;
    if(candidate->same_vertices(hex)) { return it; }
  }
  return list.end();
}

std::multimap<unsigned long long, pair<PETriangle *, int> >::iterator
Recombinator_Graph::find_the_triangle(
  PETriangle *t,
  std::multimap<unsigned long long, pair<PETriangle *, int> > &list)
{
  std::pair<
    std::multimap<unsigned long long, pair<PETriangle *, int> >::iterator,
    std::multimap<unsigned long long, pair<PETriangle *, int> >::iterator>
    range = list.equal_range(t->get_hash());
  for(std::multimap<unsigned long long, pair<PETriangle *, int> >::iterator it =
        range.first;
      it != range.second; it++) {
    PETriangle *candidate = it->second.first;
    if(candidate->same_vertices(t)) {
      it->second.second++;
      return it;
    }
  }
  return list.end();
}

Recombinator_Graph::citer
Recombinator_Graph::find_the_triangle(PETriangle *t, const trimap &list)
{
  std::pair<citer, citer> range = list.equal_range(t->get_hash());
  for(citer it = range.first; it != range.second; it++) {
    if(it->second->same_vertices(t)) return it;
  }
  return list.end();
}

Recombinator_Graph::linemap::const_iterator
Recombinator_Graph::find_the_line(PELine *t, const linemap &list)
{
  std::pair<linemap::const_iterator, linemap::const_iterator> range =
    list.equal_range(t->get_hash());
  for(linemap::const_iterator it = range.first; it != range.second; it++) {
    if(it->second->same_vertices(t)) return it;
  }
  return list.end();
}

void Recombinator_Graph::export_direct_neighbor_table(int max)
{
  stringstream ss;
  ss << "neighbors_table";
  ofstream out(ss.str().c_str());

  std::multimap<int, Hex *>::iterator it = ndegree.begin();

  int counter = 0;
  out << " n  neighbors_rank hex* quality" << endl;
  for(; it != ndegree.end(); it++, counter++) {
    if(counter >= max) break;
    Hex *hex = it->second;
    out << counter << "  " << it->first << "  " << hex << "  "
        << hex->get_quality() << endl;
    stringstream ss2;
    ss2 << "neighbors_table_hex";
    char chose[256];
    sprintf(chose, "_%0*d", 2, counter);
    ss2 << chose;
    ss2 << ".pos";
    ofstream out2(ss2.str().c_str());
    out2 << "View \"hex\" {" << endl;
    out2 << "SH(";
    for(int n = 0; n < 8; n++) {
      MVertex *v = hex->getVertex(n);
      out2 << v->x() << "," << v->y() << "," << v->z();
      if(n != 7) out2 << ",";
    }
    out2 << "){";
    for(int n = 0; n < 8; n++) {
      out2 << it->first;
      if(n != 7) out2 << ",";
    }
    out2 << "};" << endl;
    out2 << "};" << endl;
    out2.close();
  }
  out.close();
}

void print_stats_graph(const Recombinator_Graph::graph &in)
{
  int total = 0;
  for(Recombinator_Graph::graph::const_iterator it = in.begin(); it != in.end();
      it++) {
    total += it->second.second.size();
  }
  size_t nb_entries = in.size();
  cout << "Total number of entries in graph:" << total << endl;
  cout << "Number of hexes: " << nb_entries << endl;
  double average_connectivity = total / ((double)(nb_entries));
  cout << "#hex potentiels recensés dans le graphe des pertes: " << nb_entries
       << "   #connectivité moyenne: " << average_connectivity << endl;
}

void Recombinator_Graph::create_losses_graph(GRegion *gr)
{
  incompatibility_graph.clear();
  create_indirect_neighbors_graph();
  create_direct_neighbors_incompatibility_graph();

  print_stats_graph(incompatibility_graph);
};

// fills incompatibility_graph if two hex are incompatible direct neighbors,
// i.e. (they DO NOT have one tet in common) and (they are neighbors (face(s) in
// common) but DO NOT pass the compatibility tests)
void Recombinator_Graph::create_direct_neighbors_incompatibility_graph()
{
  for(std::map<Hex *, std::set<MElement *> >::iterator it_hex =
        hex_to_tet.begin();
      it_hex != hex_to_tet.end(); it_hex++) {
    Hex *hex = it_hex->first;
    if(is_not_good_enough(hex)) {
      // Why is it even there in the first place? JP
      continue;
    }

    // Find or create the hex data in the incompatibility graph
    graph::iterator itfind_graph = find_hex_in_graph(hex);
    if(itfind_graph == incompatibility_graph.end()) {
      incompatibility_graph.insert(
        make_pair(hex->get_hash(), make_pair(hex, graph_data())));
      set_of_all_hex_in_graph.insert(hex);
    }

    // For each hex the hash tables are rebuit
    clear_and_build_hash_tables(*hex);

    std::vector<Hex *> visited_hex;
    // Check compatibility with the that share an facet with hex
    const std::set<PETriangle *> &hex_faces = hex_to_faces[hex];
    for(std::set<PETriangle *>::const_iterator it_faces = hex_faces.begin();
        it_faces != hex_faces.end(); it_faces++) {
      PETriangle *face = *it_faces;

      const std::set<Hex *> &hex_sharing_triangle = faces_to_hex[face];
      for(std::set<Hex *>::const_iterator it_neighbors =
            hex_sharing_triangle.begin();
          it_neighbors != hex_sharing_triangle.end(); it_neighbors++) {
        Hex *other_hex = *it_neighbors;
        if(other_hex == hex) continue;

        if(std::count(visited_hex.begin(), visited_hex.end(), other_hex) > 0) {
          continue;
        }
        else {
          visited_hex.push_back(other_hex);
        }

        evaluate_hex_couple(hex, other_hex);
      }
    }
    // Check compatibility with the hex that share a edges (2 vertices) with hex
    // change following...

    const std::set<PELine *> &hex_edges = hex_to_edges[hex];
    for(std::set<PELine *>::const_iterator it_line = hex_edges.begin();
        it_line != hex_edges.end(); it_line++) {
      PELine *line = *it_line;
      const std::set<Hex *> &hex_sharing_edge = edges_to_hex[line];
      for(std::set<Hex *>::const_iterator it_neighbors =
            hex_sharing_edge.begin();
          it_neighbors != hex_sharing_edge.end(); it_neighbors++) {
        Hex *other_hex = *it_neighbors;
        if(other_hex == hex) continue;
        if(std::count(visited_hex.begin(), visited_hex.end(), other_hex) > 0) {
          continue;
        }
        else {
          visited_hex.push_back(other_hex);
        }

        evaluate_hex_couple(hex, other_hex);
      }
    }
  }
}

// Check the compatibility of the two input hex
// And add one graph entry when they are incompatible
// WHAT IS IN THE TABLES when this function is called ????? JP
// Nothing is checked between the hex - most evaluation are done on the
// other_hex ...
void Recombinator_Graph::evaluate_hex_couple(Hex *hex, Hex *other_hex)
{
  // Why are the not good enough hex here in the first place? JP
  if(is_not_good_enough(other_hex)) { return; }

  if(find_hex_couple_in_graph(hex, other_hex)) { return; }
  if(!conformityA(*other_hex)) {
    add_graph_entry(hex, other_hex);
    return;
  }
  if(!conformityB(*other_hex)) {
    add_graph_entry(hex, other_hex);
    return;
  }

  if(!conformityC(*other_hex)) {
    add_graph_entry(hex, other_hex);
    return;
  }

  if(!faces_statuquo(*other_hex)) {
    add_graph_entry(hex, other_hex);
    return;
  }
}

bool Recombinator_Graph::post_check_validation(Hex *current_hex)
{
  if(!conformityA(*current_hex)) { return false; }

  if(!conformityB(*current_hex)) { return false; }

  if(!conformityC(*current_hex)) { return false; }

  if(!faces_statuquo(*current_hex)) { return false; }
  return true;
}

void Recombinator_Graph::add_face(
  MVertex *a, MVertex *b, MVertex *c,
  std::multimap<unsigned long long, pair<PETriangle *, int> > &f)
{
  vector<MVertex *> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  PETriangle *q = new PETriangle(v);
  std::multimap<unsigned long long, pair<PETriangle *, int> >::iterator itfind =
    find_the_triangle(q, f);
  if(itfind == f.end()) { f.insert(make_pair(q->get_hash(), make_pair(q, 1))); }
  else {
    delete q;
  }
}

void Recombinator_Graph::add_face(MVertex *a, MVertex *b, MVertex *c, Hex *hex)
{
  vector<MVertex *> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  PETriangle *q = new PETriangle(v);
  citer itfind = find_the_triangle(q, triangular_faces);
  if(itfind == triangular_faces.end()) {
    itfind = triangular_faces.insert(make_pair(q->get_hash(), q));
  }
  else {
    delete q;
    q = itfind->second;
  }

  hex_to_faces[hex].insert(q);
  faces_to_hex[q].insert(hex);
}

void Recombinator_Graph::add_edges(Hex *hex)
{
  for(unsigned int f = 0; f < 6; ++f) {
    std::vector<MVertex *> facet_vertices(4);
    for(unsigned int v = 0; v < 4; ++v) {
      facet_vertices[v] = hex->vertex_in_facet(f, v);
    }
    fill_edges_table(facet_vertices, hex);
  }
}

// For all pairs of two vertices among the 4 input vertices
// set the mapping between the edge (PELine) and the input hex.
void Recombinator_Graph::fill_edges_table(
  const std::vector<MVertex *> &quad_vertices, Hex *hex)
{
  for(unsigned int i = 0; i < 4; ++i) {
    for(unsigned int j = i + 1; j < 4; ++j) {
      std::vector<MVertex *> edge;
      edge.push_back(quad_vertices[i]);
      edge.push_back(quad_vertices[j]);

      // see if already exists or not...
      PELine *l = new PELine(edge);
      linemap::const_iterator itfind = find_the_line(l, edges_and_diagonals);
      if(itfind == edges_and_diagonals.end()) {
        itfind = edges_and_diagonals.insert(make_pair(l->get_hash(), l));
      }
      else {
        delete l;
        l = itfind->second;
      }

      hex_to_edges[hex].insert(l);
      edges_to_hex[l].insert(hex);
    }
  }
}

Recombinator_Graph::graph::iterator
Recombinator_Graph::find_hex_in_graph(Hex *hex)
{
  pair<graph::iterator, graph::iterator> range =
    incompatibility_graph.equal_range(hex->get_hash());
  if(range.first == range.second) return incompatibility_graph.end();

  graph::iterator it = range.first;
  for(; it != range.second; it++) {
    if(it->second.first == hex) { return it; }
  }
  return incompatibility_graph.end();
}

Recombinator_Graph::graph_data::iterator
Recombinator_Graph::find_hex_in_graphrow(Hex *hex, graph_data &row)
{
  pair<graph_data::iterator, graph_data::iterator> range =
    row.equal_range(hex->get_hash());
  if(range.first == range.second) return row.end();

  graph_data::iterator it = range.first;
  for(; it != range.second; it++) {
    if(it->second == hex) { return it; }
  }
  return row.end();
}

bool Recombinator_Graph::find_hex_couple_in_graph(Hex *hex, Hex *other_hex)
{
  graph::iterator it = find_hex_in_graph(hex);
  if(it == incompatibility_graph.end()) return false;

  graph_data::iterator itt = find_hex_in_graphrow(other_hex, it->second.second);
  if(itt == it->second.second.end()) return false;
  return true;
}

void Recombinator_Graph::add_graph_entry(Hex *hex, Hex *other_hex)
{
  graph::iterator itfind_graph = find_hex_in_graph(hex);

  if(itfind_graph == incompatibility_graph.end()) {
    itfind_graph = incompatibility_graph.insert(
      make_pair(hex->get_hash(), make_pair(hex, graph_data())));
    itfind_graph->second.second.insert(
      make_pair(other_hex->get_hash(), other_hex));
    set_of_all_hex_in_graph.insert(hex);
  }
  else {
    itfind_graph->second.second.insert(
      make_pair(other_hex->get_hash(), other_hex));
  }
}

void Recombinator_Graph::compute_hex_ranks()
{
  create_faces_connectivity();

  for(std::map<Hex *, set<PETriangle *> >::iterator it = hex_to_faces.begin();
      it != hex_to_faces.end(); it++) {
    Hex *hex = it->first;
    // Count the number of facets on boundary for the hex
    int boundary_count = 0.;
    for(set<PETriangle *>::iterator itf = it->second.begin();
        itf != it->second.end(); itf++) {
      PETriangle *face = *itf;
      if(faces_connectivity[face] == 1) boundary_count += 1.;
    }

    vector<double> hex_rank(2);
    hex_rank[0] = boundary_count;
    hex_rank[1] = hex->get_quality();
    hex_ranks.insert(make_pair(hex, hex_rank));
  }
}

// Complex way to get the number of tets around a triangular facet
void Recombinator_Graph::create_faces_connectivity()
{
  for(std::map<MElement *, std::set<Hex *> >::iterator it_tet =
        tet_to_hex.begin();
      it_tet != tet_to_hex.end(); it_tet++) {
    add_face_connectivity(it_tet->first, 0, 1, 2);
    add_face_connectivity(it_tet->first, 0, 1, 3);
    add_face_connectivity(it_tet->first, 0, 2, 3);
    add_face_connectivity(it_tet->first, 1, 2, 3);
  }
}

// Complex way to get the number of tets around a triangular facet
void Recombinator_Graph::add_face_connectivity(MElement *tet, int i, int j,
                                               int k)
{
  vector<MVertex *> v;
  PETriangle *t;
  v.push_back(tet->getVertex(i));
  v.push_back(tet->getVertex(j));
  v.push_back(tet->getVertex(k));
  t = new PETriangle(v);
  citer itfind = find_the_triangle(t, triangular_faces);
  if(itfind != triangular_faces.end()) { faces_connectivity[itfind->second]++; }
  delete t;
}

void Recombinator_Graph::compute_hex_ranks_blossom()
{
  create_faces_connectivity();

  for(map<Hex *, set<PETriangle *> >::iterator it = hex_to_faces.begin();
      it != hex_to_faces.end(); it++) {
    Hex *hex = it->first;
    double nb_faces_on_boundary = 0.;
    for(set<PETriangle *>::iterator face = it->second.begin();
        face != it->second.end(); face++) {
      if(faces_connectivity[*face] == 1) nb_faces_on_boundary += 1.;
    }
    map<Hex *, vector<double> >::iterator itfind = hex_ranks.find(hex);
    if(itfind == hex_ranks.end())
      hex_ranks.insert(make_pair(hex, vector<double>(3)));
    hex_ranks[hex][0] = nb_faces_on_boundary;
    hex_ranks[hex][1] = hex->get_quality();

    int count_blossom = 0;
    for(unsigned int f = 0; f < 6; ++f) {
      bool face_in_blossom_info = find_face_in_blossom_info(
        hex->vertex_in_facet(f, 0), hex->vertex_in_facet(f, 1),
        hex->vertex_in_facet(f, 2), hex->vertex_in_facet(f, 3));
      if(face_in_blossom_info) count_blossom++;
    }
    hex_ranks[hex][2] = count_blossom;
  }
}

bool Recombinator_Graph::find_face_in_blossom_info(MVertex *a, MVertex *b,
                                                   MVertex *c, MVertex *d)
{
  PETriangle *t1, *t2;

  t1 = get_triangle(a, b, c);
  t2 = get_triangle(a, c, d);

  if(is_blossom_pair(t1, t2)) return true;

  t1 = get_triangle(a, b, d);
  t2 = get_triangle(b, c, d);
  if(is_blossom_pair(t1, t2)) return true;

  return false;
}

PETriangle *Recombinator_Graph::get_triangle(MVertex *a, MVertex *b, MVertex *c)
{
  vector<MVertex *> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  PETriangle *t = new PETriangle(v);
  citer it_find_tri = find_the_triangle(t, triangular_faces);
  delete t;
  return (it_find_tri->second);
}

bool Recombinator_Graph::is_blossom_pair(PETriangle *t1, PETriangle *t2)
{
  tripair::iterator itfind = blossom_info.find(t1);
  if(itfind != blossom_info.end()) {
    if(t2 == itfind->second) return true;
  }
  return false;
}
