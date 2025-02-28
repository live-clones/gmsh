// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Paul-Emile Bernard

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "pointInsertion.h"
#include "BackgroundMeshManager.h"
#include "BackgroundMesh2D.h"
#include "BackgroundMesh3D.h"
#include "GFace.h"
#include "GRegion.h"
#include "OS.h"
#include "Context.h"
#include "meshGRegion.h"
#include "pointInsertionRTreeTools.h"
#include "intersectCurveSurface.h"

//#include "google/profiler.h"

bool old_algo_hexa() { return true; }

void computeSixNeighbors(frameFieldBackgroundMesh3D *bgm, MVertex *parent,
                         std::vector<MVertex *> &spawns, STensor3 dir, double h)
{
  // using approximate size, RK1...
  double x = parent->x();
  double y = parent->y();
  double z = parent->z();
  double newx, newy, newz;
  GRegion *gr = dynamic_cast<GRegion *>(bgm->getBackgroundGEntity());

  for(int i = 0; i < 3; i++) {
    newx = x + h * dir(0, i);
    newy = y + h * dir(1, i);
    newz = z + h * dir(2, i);
    spawns[i * 2] = new MVertex(newx, newy, newz, gr, 0);

    newx = x - h * dir(0, i);
    newy = y - h * dir(1, i);
    newz = z - h * dir(2, i);
    spawns[i * 2 + 1] = new MVertex(newx, newy, newz, gr, 0);
  }
}

double Filler2D::time_bgm_and_smoothing = 0.;
double Filler2D::time_insertion = 0.;

Filler2D::Filler2D() {}

Filler2D::~Filler2D()
{
}

void Filler2D::pointInsertion2D(GFace *gf, std::vector<MVertex *> &packed,
                                std::vector<SMetric3> &metrics)
{
}

bool Filler3D::treat_region(GRegion *gr)
{
  BGMManager::set_use_cross_field(true);

  bool use_vectorial_smoothness;
  bool use_fifo;
  std::string algo;

  // readValue("param.dat","SMOOTHNESSALGO",algo);
  algo.assign("SCALAR");

  if(!algo.compare("SCALAR")) {
    use_vectorial_smoothness = false;
    use_fifo = false;
  }
  else if(!algo.compare("FIFO")) {
    use_vectorial_smoothness = false;
    use_fifo = true;
  }
  else {
    std::cout << "unknown SMOOTHNESSALGO !" << std::endl;
    throw;
  }

  const bool debug = false;
  const bool export_stuff = true;
  double a;

  std::cout << "ENTERING POINTINSERTION3D" << std::endl;

  // acquire background mesh
  std::cout << "pointInsertion3D: recover BGM" << std::endl;
  a = Cpu();
  frameFieldBackgroundMesh3D *bgm =
    dynamic_cast<frameFieldBackgroundMesh3D *>(BGMManager::get(gr));
  time_smoothing += (Cpu() - a);

  if(!bgm) {
    std::cout << "pointInsertion3D:: BGM dynamic cast failed ! " << std::endl;
    throw;
  }

  // export BGM fields
  if(export_stuff) {
    std::cout << "pointInsertion3D: export size field " << std::endl;
    std::stringstream ss;
    ss << "bg3D_sizefield_" << gr->tag() << ".pos";
    bgm->exportSizeField(ss.str());

    std::cout << "pointInsertion3D : export crossfield " << std::endl;
    std::stringstream sscf;
    sscf << "bg3D_crossfield_" << gr->tag() << ".pos";
    bgm->exportCrossField(sscf.str());

    std::cout << "pointInsertion3D : export smoothness " << std::endl;
    std::stringstream sss;
    sss << "bg3D_smoothness_" << gr->tag() << ".pos";
    bgm->exportSmoothness(sss.str());

    if(use_vectorial_smoothness) {
      std::cout << "pointInsertion3D : export vectorial smoothness "
                << std::endl;
      std::stringstream ssvs;
      ssvs << "bg3D_vectorial_smoothness_" << gr->tag() << ".pos";
      bgm->exportVectorialSmoothness(ssvs.str());
    }
  }

  // ---------------- START FILLING NEW POINTS ----------------
  std::cout << "pointInsertion3D : inserting points in region " << gr->tag()
            << std::endl;

  // ProfilerStart("/home/bernard/profile");
  a = Cpu();

  // ----- initialize fifo list -----

  RTree<MVertex *, double, 3, double> rtree;
  listOfPoints *fifo;
  if(use_fifo)
    fifo = new listOfPointsFifo();
  else if(use_vectorial_smoothness)
    fifo = new listOfPointsVectorialSmoothness();
  else
    fifo = new listOfPointsScalarSmoothness();

  std::set<MVertex *> temp;
  std::vector<MVertex *> boundary_vertices;
  std::map<MVertex *, int> vert_priority;
  std::map<MVertex *, double> smoothness_forplot;
  MElement *element;
  MVertex *vertex;
  std::vector<GFace *> faces = gr->faces();
  for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
      it++) {
    GFace *gf = *it;
    // int limit = code_kesskessai(gf->tag());
    for(unsigned int i = 0; i < gf->getNumMeshElements(); i++) {
      element = gf->getMeshElement(i);
      for(std::size_t j = 0; j < element->getNumVertices();
          j++) { // for all vertices
        vertex = element->getVertex(j);
        temp.insert(vertex);
        // limits.insert(make_pair(vertex,limit));
      }
    }
  }

  int geodim;
  for(std::set<MVertex *>::iterator it = temp.begin(); it != temp.end(); it++) {
    geodim = (*it)->onWhat()->dim();
    if((geodim == 0) || (geodim == 1) || (geodim == 2))
      boundary_vertices.push_back(*it);
  }

  double min[3], max[3], x, y, z, h;
  for(unsigned int i = 0; i < boundary_vertices.size(); i++) {
    x = boundary_vertices[i]->x();
    y = boundary_vertices[i]->y();
    z = boundary_vertices[i]->z();

    // "on boundary since working on boundary_vertices ...
    MVertex *closest =
      bgm->get_nearest_neighbor_on_boundary(boundary_vertices[i]);
    h = bgm->size(closest); // get approximate size, closest vertex, faster ?!

    fill_min_max(x, y, z, h, min, max);

    rtree.Insert(min, max, boundary_vertices[i]);

    if(!use_vectorial_smoothness) {
      smoothness_vertex_pair *svp = new smoothness_vertex_pair();
      svp->v = boundary_vertices[i];
      svp->rank = bgm->get_smoothness(x, y, z);
      svp->dir = 0;
      svp->layer = 0;
      svp->size = h;
      bgm->eval_approximate_crossfield(closest, svp->cf);

      fifo->insert(svp);
      if(debug) {
        smoothness_forplot[svp->v] = svp->rank;
      }
    }
    else {
      STensor3 temp;
      bgm->eval_approximate_crossfield(closest, temp);
      for(int idir = 0; idir < 3; idir++) {
        smoothness_vertex_pair *svp = new smoothness_vertex_pair();
        svp->v = boundary_vertices[i];
        svp->rank = bgm->get_vectorial_smoothness(idir, x, y, z);
        svp->dir = idir;
        svp->layer = 0;
        svp->size = h;
        svp->cf = temp;
        for(int k = 0; k < 3; k++) svp->direction(k) = temp(k, idir);

        // std::cout << "fifo size=" << fifo->size() << " inserting   "  ;
        fifo->insert(svp);
        // std::cout << " ->  fifo size=" << fifo->size() << std::endl;
      }
    }
  }

  // TODO: si fifo était list of *PTR -> pas de copies, gain temps ?
  Wrapper3D wrapper;
  wrapper.set_bgm(bgm);
  MVertex *parent, *individual;
  new_vertices.clear();
  bool spawn_created;
  int priority_counter = 0;
  STensor3 crossfield;
  int parent_layer;

  while(!fifo->empty()) {
    parent = fifo->get_first_vertex();
    //    parent_limit = fifo->get_first_limit();
    parent_layer = fifo->get_first_layer();

    //    if(parent_limit!=-1 && parent_layer>=parent_limit()){
    //      continue;
    //    }

    std::vector<MVertex *> spawns;
    spawns.resize(6);
    computeSixNeighbors(bgm, parent, spawns, fifo->get_first_crossfield(),
			fifo->get_first_size());
    fifo->erase_first();

    //    std::cout << "while, fifo->size()=" << fifo->size() << " parent=(" <<
    //    parent->x() << "," << parent->y() << "," << parent->z() << ")" <<
    //    std::endl;

    for(unsigned int i = 0; i < spawns.size(); i++) {
      spawn_created = false;
      individual = spawns[i];
      x = individual->x();
      y = individual->y();
      z = individual->z();
      //      std::cout << " working on candidate " << "(" << individual->x() <<
      //      ","
      //      << individual->y() << "," << individual->z() << ")" << std::endl;

      if(bgm->inDomain(x, y, z)) {
        //        std::cout << "   spawn " << i << " in domain" << std::endl;

        MVertex *closest = bgm->get_nearest_neighbor(individual);
        h =
          bgm->size(closest); // get approximate size, closest vertex, faster ?!

        if(far_from_boundary_3D(bgm, individual, h)) {
          //        std::cout << "   spawn " << i << " far from bnd" <<
          //        std::endl;
          bgm->eval_approximate_crossfield(closest, crossfield);
          wrapper.set_ok(true);
          wrapper.set_individual(individual);
          wrapper.set_parent(parent);
          wrapper.set_size(&h);
          wrapper.set_crossfield(&crossfield);

          fill_min_max(x, y, z, h, min, max);

          rtree.Search(min, max, rtree_callback_3D, &wrapper);

          if(wrapper.get_ok()) {
            //        std::cout << "   spawn " << i << " wrapper OK" <<
            //        std::endl;

            if(!use_vectorial_smoothness) {
              smoothness_vertex_pair *svp = new smoothness_vertex_pair();
              svp->v = individual;
              svp->rank = bgm->get_smoothness(individual->x(), individual->y(),
                                              individual->z());
              svp->dir = 0;
              svp->layer = parent_layer + 1;
              svp->size = h;
              svp->cf = crossfield;
              fifo->insert(svp);
              if(debug) {
                smoothness_forplot[svp->v] = svp->rank;
                vert_priority[individual] = priority_counter++;
              }
            }
            else {
              if(debug) vert_priority[individual] = priority_counter++;
              for(int idir = 0; idir < 3; idir++) {
                smoothness_vertex_pair *svp = new smoothness_vertex_pair();
                svp->v = individual;
                svp->rank = bgm->get_vectorial_smoothness(idir, x, y, z);
                svp->dir = idir;
                svp->layer = parent_layer + 1;
                svp->size = h;
                for(int k = 0; k < 3; k++)
                  svp->direction(k) = crossfield(k, idir);
                svp->cf = crossfield;
                fifo->insert(svp);
              }
            }

            rtree.Insert(min, max, individual);
            new_vertices.push_back(individual);
            spawn_created = true;
          }
        }
      }
      if(!spawn_created) {
        delete individual;
      }
    } // end loop on spawns
  }

  // ProfilerStop();

  time_insert_points += (Cpu() - a);


  // ------- meshing using new points
  std::cout << "tets in gr before= " << gr->tetrahedra.size() << std::endl;
  std::cout << "nb new vertices= " << new_vertices.size() << std::endl;
  a = Cpu();

  int option = CTX::instance()->mesh.algo3d;
  CTX::instance()->mesh.algo3d = ALGO_3D_DELAUNAY;

  deMeshGRegion deleter;
  deleter(gr);
  std::vector<GRegion *> regions;
  regions.push_back(gr);
  meshGRegion mesher(regions); //?
  mesher(gr); //?
  MeshDelaunayVolume(regions);
  time_meshing += (Cpu() - a);

  std::cout << "tets in gr after= " << gr->tetrahedra.size() << std::endl;
  std::cout << "gr tag=" << gr->tag() << std::endl;

  CTX::instance()->mesh.algo3d = option;

  delete fifo;
  for(unsigned int i = 0; i < new_vertices.size(); i++) delete new_vertices[i];
  new_vertices.clear();
  rtree.RemoveAll();

  return true;
}

int Filler3D::get_nbr_new_vertices() { return new_vertices.size(); }

MVertex *Filler3D::get_new_vertex(int i) { return new_vertices[i]; }

Filler3D::Filler3D() {}

Filler3D::~Filler3D()
{
  std::cout << "FILLER3D timing:" << std::endl;
  std::cout << "  ------- CUMULATIVE TIME3D bgm & smoothing  : "
            << time_smoothing << " s." << std::endl;
  std::cout << "  ------- CUMULATIVE TIME3D inserting points : "
            << time_insert_points << " s." << std::endl;
  std::cout << "  ------- CUMULATIVE TIME3D meshing region   : " << time_meshing
            << " s." << std::endl;
  std::cout << "  ------- CUMULATIVE TOTAL 3D TIME (new)   : "
            << time_meshing + time_smoothing + time_insert_points << " s."
            << std::endl;
}

std::vector<MVertex *> Filler3D::new_vertices;

double Filler3D::time_smoothing = 0.;
double Filler3D::time_insert_points = 0.;
double Filler3D::time_meshing = 0.;
