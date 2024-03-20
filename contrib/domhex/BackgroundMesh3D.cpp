// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <numeric>
#include "BackgroundMesh3D.h"
#include "MElement.h"
#include "GFace.h"
#include "GRegion.h"
#include "BackgroundMeshManager.h"
#include "BackgroundMesh2D.h"
#include "MElementOctree.h"
#include "MTetrahedron.h"
#include "OS.h"

#if defined(HAVE_SOLVER)
#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemPETSc.h"
#include "linearSystemFull.h"
#include "linearSystemCSR.h"
#endif

/// \return -1 if value is negative, +1 if positive and zero otherwise
template <class T> int signof(T const value)
{
  return (T(0) < value) - (value < T(0));
}

// TODO: virer les trucs "vertextorank", mettre cette classe-ci :

// class evalDiffusivity3DFunction : public simpleFunction<double>{
//  public:
//    evalDiffusivity3DFunction(frameFieldBackgroundMesh3D *_bgm, double
//    t=0.95):bgm(_bgm),threshold(t){}; double operator () (double u, double v,
//    double w) const{
//      return ((bgm->get_smoothness(u,v) >= threshold) ? 1. : 1.e-3);
//    }
//  private:
//    frameFieldBackgroundMesh2D *bgm;
//    const double threshold;
//};

backgroundMesh3D::backgroundMesh3D(GRegion *_gr)
  : BGMBase(3, _gr), debug(false), verbose(false)
{
  computeSizeField();
}

backgroundMesh3D::~backgroundMesh3D() {}

void backgroundMesh3D::computeSizeField()
{
  std::cout << "backgroundMesh3D::computeSizeField() " << std::endl;

  // fills dirichlet BC
  GRegion *region = dynamic_cast<GRegion *>(gf);
  if(!region) {
    Msg::Error("Entity is not a region in background mesh");
    return;
  }
  std::vector<GFace *> faces = region->faces();
  MVertex *v;
  MElement *e;

  for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
      it++) { // for all GFace
    GFace *face = *it;
    frameFieldBackgroundMesh2D *bgm2d =
      dynamic_cast<frameFieldBackgroundMesh2D *>(BGMManager::get(face));
    if(!bgm2d) {
      Msg::Error("Background mesh is not a 2D frame field");
      return;
    }
    for(unsigned int i = 0; i < face->getNumMeshElements();
        i++) { // for all elements
      e = face->getMeshElement(i);
      if(e->getDim() != 2) continue; // of dim=2
      for(std::size_t iv = 0; iv < e->getNumVertices(); iv++) {
        v = e->getVertex(iv);
        SPoint2 p;
        reparamMeshVertexOnFace(v, face, p);
        sizeField[v] = bgm2d->size(p.x(), p.y());
        //        std::cout << "sets sizefield for vertex " << v << std::endl;
      }
    }
  }

  // propagate
  simpleFunction<double> ONE(1.0);
  propagateValues(sizeField, ONE);

  //  std::cout << "backgroundMesh3D::size of sizeField: " << sizeField.size()
  //  << std::endl;
}

void backgroundMesh3D::propagateValues(DoubleStorageType &dirichlet,
                                       simpleFunction<double> &eval_diffusivity,
                                       bool in_parametric_plane)
{
  // same as Size_field::solve()
  GRegion *gr = dynamic_cast<GRegion *>(gf);
  if(!gr) {
    Msg::Error("Entity is not a region in background mesh");
    return;
  }

#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
  lsys->setGmres(1);
#else
   linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif

  size_t i;
  int count;
  int count2;
  double val;
  double volume;
  std::set<MVertex *> interior;
  std::set<MVertex *>::iterator it;
  DoubleStorageType::iterator it2;

  dofManager<double> assembler(lsys);

  count = 0;
  for(it2 = dirichlet.begin(); it2 != dirichlet.end(); it2++) {
    assembler.fixVertex(it2->first, 0, 1, it2->second);
    count++;
  }
  // printf("\n");
  // printf("number of boundary vertices = %d\n",count);

  for(i = 0; i < gr->tetrahedra.size(); i++) {
    interior.insert(gr->tetrahedra[i]->getVertex(0));
    interior.insert(gr->tetrahedra[i]->getVertex(1));
    interior.insert(gr->tetrahedra[i]->getVertex(2));
    interior.insert(gr->tetrahedra[i]->getVertex(3));
  }

  for(it = interior.begin(); it != interior.end(); it++) {
    it2 = dirichlet.find(*it);
    if(it2 == dirichlet.end()) {
      assembler.numberVertex(*it, 0, 1);
    }
  }

  for(i = 0; i < gr->tetrahedra.size(); i++) {
    gr->tetrahedra[i]->setVolumePositive();
  }

  count2 = 0;
  volume = 0.0;
  laplaceTerm term(0, 1, &eval_diffusivity);
  for(i = 0; i < gr->tetrahedra.size(); i++) {
    SElement se(gr->tetrahedra[i]);
    term.addToMatrix(assembler, &se);
    count2++;
    volume = volume + gr->tetrahedra[i]->getVolume();
  }
  // printf("number of tetrahedra = %d\n",count2);
  // printf("volume = %f\n",volume);

  if(assembler.sizeOfR()) {
    lsys->systemSolve();
  }

  for(it = interior.begin(); it != interior.end(); it++) {
    assembler.getDofValue(*it, 0, 1, val);
    dirichlet.insert(std::pair<MVertex *, double>(*it, val));
  }

  delete lsys;
#endif
}

GPoint backgroundMesh3D::get_GPoint_from_MVertex(const MVertex *v) const
{
  return GPoint(v->x(), v->y(), v->z(), dynamic_cast<GRegion *>(gf));
}

MVertex *backgroundMesh3D::get_nearest_neighbor(const MVertex *v)
{
  double distance;
  return get_nearest_neighbor(v->x(), v->y(), v->z(), distance);
}

MVertex *backgroundMesh3D::get_nearest_neighbor(const double *xyz)
{
  double distance;
  return get_nearest_neighbor(xyz, distance);
}

MVertex *backgroundMesh3D::get_nearest_neighbor(double x, double y, double z)
{
  double distance;
  return get_nearest_neighbor(x, y, z, distance);
}

MVertex *backgroundMesh3D::get_nearest_neighbor(double x, double y, double z,
                                                double &distance)
{
  double xyz[3] = {x, y, z};
  return get_nearest_neighbor(xyz, distance);
}

MElementOctree *backgroundMesh3D::getOctree()
{
  if(!octree) {
    GRegion *gr = dynamic_cast<GRegion *>(gf);
    if(!gr) {
      Msg::Error("Entity is not a region in background mesh");
      return 0;
    }
    Msg::Debug("Rebuilding BackgroundMesh element octree");
    std::vector<MElement *> copy(gr->tetrahedra.begin(), gr->tetrahedra.end());
    octree = new MElementOctree(copy);
  }
  return octree;
}

MVertex *backgroundMesh3D::get_nearest_neighbor(const double *xyz,
                                                double &distance)
{
  // using the octree instead of ANN, faster.
  MElement *elem = const_cast<MElement *>(findElement(xyz[0], xyz[1], xyz[2]));

  if(!elem) return NULL;

  std::vector<MVertex *> candidates(elem->getNumVertices());
  std::vector<double> distances(elem->getNumVertices());
  SPoint3 p(xyz[0], xyz[1], xyz[2]);
  for(std::size_t i = 0; i < elem->getNumVertices(); i++) {
    MVertex *const v = elem->getVertex(i);
    candidates[i] = v;
    distances[i] = p.distance(v->point());
  }
  std::vector<double>::iterator itmax =
    std::max_element(distances.begin(), distances.end());
  return candidates[std::distance(distances.begin(), itmax)];

  //  map<double,MVertex*> distances;
  //  SPoint3 p(xyz[0],xyz[1],xyz[2]);
  //  for (int i=0;i<elem->getNumVertices();i++){
  //    MVertex *v = elem->getVertex(i);
  //    distances.insert(make_pair(p.distance(v->point()),v));
  //  }
  //  map<double,MVertex*>::iterator it = distances.begin();
  //  distance = it->first;
  //  return it->second;
}

std::vector<montripletbis> frameFieldBackgroundMesh3D::permutation =
  std::vector<montripletbis>();

frameFieldBackgroundMesh3D::frameFieldBackgroundMesh3D(GRegion *_gr)
  : backgroundMesh3D(_gr)
{
  //  readValue("param.dat","SMOOTHCF",smooth_the_crossfield);
  smooth_the_crossfield = true;

  // for the different "quaternion" permutations...
  if(permutation.empty()) {
    permutation.push_back(montripletbis(1, 2, 3));
    permutation.push_back(montripletbis(2, -1, 3));
    permutation.push_back(montripletbis(-1, -2, 3));
    permutation.push_back(montripletbis(-2, 1, 3));
    permutation.push_back(montripletbis(2, 1, -3));
    permutation.push_back(montripletbis(-1, 2, -3));
    permutation.push_back(montripletbis(-2, -1, -3));
    permutation.push_back(montripletbis(1, -2, -3));
  }

  build_vertex_to_element_table();

  int max_recursion_level = 1;
  if((max_recursion_level > 3) || (max_recursion_level < 1)) throw;
  build_neighbors(max_recursion_level);

  initiate_ANN_research();
  initiate_crossfield();

  if(smooth_the_crossfield) {
    computeCrossField();
  }
  else {
    computeSmoothnessOnlyFromBoundaries();
  }
}

frameFieldBackgroundMesh3D::~frameFieldBackgroundMesh3D()
{
#if defined(HAVE_ANN)
  if(annTreeBnd) delete annTreeBnd;
  if(dataPtsBnd) annDeallocPts(dataPtsBnd);
#endif
}

void frameFieldBackgroundMesh3D::initiate_ANN_research()
{
#ifdef HAVE_ANN
  // ANN research for 2D !!!
  int maxPts = listOfBndVertices.size();
  dataPtsBnd = annAllocPts(maxPts, 3);
  int i = 0;
  MVertex *v;
  for(std::set<MVertex *>::iterator it = listOfBndVertices.begin();
      it != listOfBndVertices.end(); it++) {
    v = *it;
    for(int k = 0; k < 3; ++k) dataPtsBnd[i][k] = (v->point())[k];
    ++i;
  }
  annTreeBnd = new ANNkd_tree(dataPtsBnd, maxPts, 3);
#endif
  return;
}

void frameFieldBackgroundMesh3D::computeSmoothnessOnlyFromBoundaries()
{
  // this is used when the crossfield is not smoothed !!!
  // otherwise, the smoothness is computed on the fly while smoothing the cf !

  smoothness_threshold = 0.;

  std::set<MVertex const *> neighbors;
  std::multimap<double, MVertex const *> themap;
  SVector3 mean_axis(0.);
  double mean_angle = 0.;
  std::vector<double> vectorial_smoothness(3);

  for(vert2elemtype::iterator it_vertex = vert2elem.begin();
      it_vertex != vert2elem.end(); it_vertex++) { // for all vertices
    themap.clear();
    neighbors.clear();
    MVertex const *current = it_vertex->first;
    std::pair<graphtype::const_iterator, graphtype::iterator> range =
      graph.equal_range(current);
    graphtype::const_iterator itgraph = range.first;
    for(; itgraph != range.second; itgraph++) { // for all neighbors
      neighbors.insert(itgraph->second.second);
    }
    for(std::set<MVertex const *>::iterator it = neighbors.begin();
        it != neighbors.end(); it++) {
      themap.insert(std::make_pair(1., *it));
    }

    TensorStorageType::iterator itcurrent = crossField.find(current);
    STensor3 &ref = itcurrent->second;

    crossFieldSmoothness[current] =
      compare_to_neighbors(current->point(), ref, themap.begin(), themap.end(),
                           mean_axis, mean_angle, vectorial_smoothness);
  }
}

void frameFieldBackgroundMesh3D::computeCrossField()
{
  // TODO: mettre des parametres façon gmsh ???
  // reading parameters
  int Niter = 3;
  double norme_threshold = 1.;
  double localangle_threshold = 1.;

  Niter = 40;
  norme_threshold = 3.e-2;
  localangle_threshold = 5.e-3;
  smoothness_threshold = 0.85;
  double percentage_threshold = 0.98;

  std::vector<double> scal_prods, signs, angles;
  STensor3 identity(1.);

  if(debug) exportCrossField("cf_initial.pos");

  // initiation
  std::multimap<double, MVertex const *> rank, rank_temp;
  std::map<MVertex const *const, bool> vertex_is_still;
  std::map<MVertex const *const, double> vertex_movement;

  for(vert2elemtype::iterator it_vertex = vert2elem.begin();
      it_vertex != vert2elem.end(); it_vertex++) {
    MVertex const *const current = it_vertex->first;

    vertex_is_still[current] = current->onWhat()->dim() <= 2;

    rank.insert(std::make_pair(0., current));
  }

  // OLD - NEW COMPARISON
  std::map<MVertex const *, double> vertex_to_rank;
  for(vert2elemtype::iterator it_vertex = vert2elem.begin();
      it_vertex != vert2elem.end(); it_vertex++) { // for all vertices
    // vertex_to_rank[it_vertex->first] = 0.;
    vertex_to_rank[it_vertex->first] = 1.;
    rank.insert(std::make_pair(0., it_vertex->first));
  }
  // END OLD - NEW COMPARISON

  double percentage_not_done = 0.;
  double norme = 10. * norme_threshold;
  double norme_inf = 10. * norme_threshold;
  int iIter = 0;
  SVector3 mean_axis(0.);
  double mean_angle = 0.;
  std::vector<double> vectorial_smoothness(3);
  //  vector<int> nb_local_iterations;

  // main smoothing loop
  while(((norme_inf > norme_threshold) &&
         (percentage_not_done < percentage_threshold)) &&
        (iIter < Niter)) { // for maximum Niter iterations, or until convergence
    //    nb_local_iterations.clear();
    angles.clear();
    norme_inf = 0.;
    int counter_done = 0;
    int counter_not_done = 0;
    while(rank.size()) { // for all vertices, i.e. all cavities
      //    for (vert2elemtype::iterator
      // it_vertex=vert2elem.begin();it_vertex!=vert2elem.end();it_vertex++)//
      // for all vertices, i.e. all cavities MVertex *current =
      // it_vertex->first;

      MVertex const *const current = rank.begin()->second;
      rank.erase((rank.begin()));

      // smooth 3D vertices only
      if(current->onWhat()->dim() <= 2) {
        if(verbose)
          std::cout << "-------------------- discard point "
                    << current->getNum() << "  on dim "
                    << current->onWhat()->dim() << "   coord (" << current->x()
                    << "," << current->y() << "," << current->z() << ")"
                    << std::endl;
        continue;
      }

      TensorStorageType::iterator itcurrent = crossField.find(current);
      STensor3 &ref = itcurrent->second;
      if(verbose)
        std::cout << "-------------------- working on point "
                  << current->getNum() << "  on dim "
                  << current->onWhat()->dim() << "   coord (" << current->x()
                  << "," << current->y() << "," << current->z() << ")"
                  << std::endl;

      std::pair<graphtype::iterator, graphtype::iterator> range =
        graph.equal_range(current);
      graphtype::iterator itgraph = range.first;
      bool all_neighbors_still = true; // if nothing has changed since previous
                                       // iteration: nothing to do !
      for(; itgraph != range.second; itgraph++) { // for all neighbors
        if(vertex_is_still[itgraph->second.second] == false) {
          all_neighbors_still = false;
          break;
        }
      }

      // neighbors didn't move, and current didn't move either -> nothing to do
      // !
      if(all_neighbors_still && vertex_is_still[current]) {
        vertex_movement[current] = 0.;
        rank_temp.insert(std::make_pair(0., current));
        counter_not_done++;
        continue;
      }

      // OLD - NEW COMPARISON
      std::multimap<double, MVertex const *> neighbors_to_trust;
      itgraph = range.first;
      for(; itgraph != range.second; itgraph++) { // for all neighbors
        neighbors_to_trust.insert(std::make_pair(
          vertex_to_rank[itgraph->second.second], itgraph->second.second));

        //  if (vertex_to_rank[itgraph->second.second] <= 1. /180.*M_PI){
        //     neighbors_to_trust.insert(make_pair(vertex_to_rank[itgraph->second.second],
        //                                         itgraph->second.second));
        //  }
      }

      if(!neighbors_to_trust.size()) {
        rank_temp.insert(std::make_pair(M_PI, current));
        vertex_to_rank[current] = M_PI;
        continue;
      }
      // END OLD - NEW COMPARISON

      counter_done++;

      double angle_to_go;
      ;

      int Nlocaliter = 0;
      STensor3 ref_original(ref);

      // iterations, convergence of the local cavity...
      for(; Nlocaliter < 20; Nlocaliter++) {
        std::multimap<double, MVertex const *>::iterator it_neighbors_to_trust =
          neighbors_to_trust.begin();
        crossFieldSmoothness[current] =
          compare_to_neighbors(current->point(), ref, it_neighbors_to_trust,
                               neighbors_to_trust.end(), mean_axis, mean_angle,
                               vectorial_smoothness);
        //  crossFieldVectorialSmoothness[current] = vectorial_smoothness;

        // rotating directions to align closest vectors...
        angle_to_go = mean_angle;
        ref = apply_rotation(mean_axis, angle_to_go, ref);
        // std::cout << " iter " << Nlocaliter << ": mean_angle = " <<
        // mean_angle <<
        //                std::endl;
        if(std::abs(mean_angle) < localangle_threshold / 3.0) break;
      }
      //  nb_local_iterations.push_back(Nlocaliter+1);
      if(verbose)
        std::cout << "iIter " << iIter << ", Nlocaliter = " << Nlocaliter
                  << std::endl;

      // computing the total rotation
      // get_min_rotation_matrix(ref_original, ref, mean_angle,
      // mean_axis,localangle_threshold,true);
      get_min_rotation_matrix(ref_original, ref, mean_angle, mean_axis,
                              localangle_threshold); //,true);
      norme_inf = std::max(norme_inf, mean_angle);
      //            std::cout << "  #local_iter=" << Nlocaliter << "  final
      //            mean_angle = " << mean_angle << "  threshold=" <<
      //            localangle_threshold << "  condition :" << (mean_angle <=
      //            localangle_threshold) << std::endl;

      angles.push_back(mean_angle);
      vertex_is_still[current] = (mean_angle <= localangle_threshold);
      vertex_movement[current] = mean_angle;
      rank_temp.insert(std::make_pair(mean_angle, current));
      // OLD - NEW COMPARISON
      // vertex_to_rank[current] = mean_angle;
      vertex_to_rank[current] = crossFieldSmoothness[current];
      //      // HACK
      //        vertex_to_rank[current] = 0.;
      // END OLD - NEW COMPARISON

    } // end vertices loop

    // rank = rank_temp;
    rank_temp.clear();

    norme = std::accumulate(angles.begin(), angles.end(), 0.);
    if(angles.size()) norme = norme / M_PI * 180. / angles.size();
    percentage_not_done =
      ((double)counter_not_done) / (counter_done + counter_not_done);
    std::cout << "   --- iter " << iIter << " NormeInf=" << norme_inf
              << " mean Angle=" << norme
              << " counter_not_done=" << counter_not_done
              << " NotDone (%)=" << (percentage_not_done * 100.) << " %"
              << std::endl;
    //    std::cout << "Average number of local iterations: "
    //          << ((double)std::accumulate(nb_local_iterations.begin(),
    //               nb_local_iterations.end(),0))/nb_local_iterations.size() <<
    //               std::endl;

    // if (debug){
    double temp = std::log10(Niter);
    std::stringstream ss;
    ss << "cf_iter_" << std::setfill('0') << std::setw((int)(std::ceil(temp)))
       << iIter << ".pos";
    exportCrossField(ss.str().c_str());
    //}

    iIter++;
  } // end Niter iterations

  // also computes smoothness for boundary points
  for(vert2elemtype::iterator it_vertex = vert2elem.begin();
      it_vertex != vert2elem.end(); it_vertex++) {
    MVertex const *const current = it_vertex->first;
    if(current->onWhat()->dim() <= 2) {
      TensorStorageType::iterator itcurrent = crossField.find(current);
      STensor3 &ref = itcurrent->second;
      std::pair<graphtype::iterator, graphtype::iterator> range =
        graph.equal_range(current);
      graphtype::iterator itgraph = range.first;

      std::multimap<double, MVertex const *> neighbors_to_trust;
      itgraph = range.first;
      for(; itgraph != range.second; itgraph++) { // for all neighbors
        neighbors_to_trust.insert(std::make_pair(0., itgraph->second.second));
      }
      crossFieldSmoothness[current] = compare_to_neighbors(
        current->point(), ref, neighbors_to_trust.begin(),
        neighbors_to_trust.end(), mean_axis, mean_angle, vectorial_smoothness);

      // crossFieldSmoothness[current] = compare_to_neighbors
      //     (current->point(), ref, itgraph, range.second, mean_axis,
      //       mean_angle,vectorial_smoothness);
      //      crossFieldVectorialSmoothness[current] = vectorial_smoothness;
    }
  }
}

// STensor3 frameFieldBackgroundMesh3D::get_random_cross()const{
//  SVector3 vec1(rand()%10000/9999. , rand()%10000/9999. , rand()%10000/9999.
//  ); vec1.normalize(); SVector3 ref(1.,0.,0.); SVector3 vec2 =
//  crossprod(ref,vec1); vec2.normalize(); SVector3 vec3 = crossprod(vec1,vec2);
//  vec3.normalize();
//  STensor3 random_cross;
//  for (int j=0;j<3;j++){
//    random_cross(j,0) = vec1(j);
//    random_cross(j,1) = vec2(j);
//    random_cross(j,2) = vec3(j);
//  }
//  return random_cross;
//}

void frameFieldBackgroundMesh3D::initiate_crossfield()
{
  crossField.clear();
  MVertex *v;

  // first, for boundaries :
  GRegion *gr = dynamic_cast<GRegion *>(gf);
  if(!gr) {
    Msg::Error("Entity is not a region in background mesh");
    return;
  }
  std::vector<GFace *> faces = gr->faces();
  // here, not using the gm2D since we are interested by the new 2D vertices,
  // not the old (now erased) ones... alternative would be to reset the 2DBGM...
  for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
      it++) { // for all GFace
    GFace *face = *it;
    frameFieldBackgroundMesh2D *bgm2d =
      dynamic_cast<frameFieldBackgroundMesh2D *>(BGMManager::get(face));
    if(!bgm2d) {
      Msg::Error("Background mesh is not a 2D frame field");
      return;
    }
    // initializing the vertices on the faces
    for(unsigned int i = 0; i < face->getNumMeshElements();
        i++) { // for all elements
      MElement *e = face->getMeshElement(i);
      if(e->getDim() != 2) continue; // of dim=2

      for(std::size_t iv = 0; iv < e->getNumVertices(); iv++) {
        v = e->getVertex(iv);

        // if already done: continue
        TensorStorageType::iterator itfind = crossField.find(v);
        if(itfind != crossField.end()) continue;

        STensor3 cf;
        bgm2d->eval_crossfield(v, cf);
        crossField[v] = cf;
      }
    }
  }

  // then, for volume :
  for(unsigned int i = 0; i < gr->getNumMeshElements();
      i++) { // for all elements
    MElement *e = gr->getMeshElement(i);
    if(e->getDim() != 3) continue;

    for(std::size_t iv = 0; iv < e->getNumVertices(); iv++) {
      v = e->getVertex(iv);

      // if not in volume: continue
      if(v->onWhat()->dim() <= 2) continue;
      // if already done: continue
      TensorStorageType::iterator itfind = crossField.find(v);
      if(itfind != crossField.end()) continue;
      MVertex *closer_on_bnd = get_nearest_neighbor_on_boundary(v);
      crossField[v] =
        crossField[closer_on_bnd]; // prend l'info Bnd (ANN) la plus proche...
    }
  }
}

MVertex *
frameFieldBackgroundMesh3D::get_nearest_neighbor_on_boundary(MVertex *v)
{
  double distance;
  return get_nearest_neighbor_on_boundary(v, distance);
}

MVertex *
frameFieldBackgroundMesh3D::get_nearest_neighbor_on_boundary(MVertex *v,
                                                             double &distance)
{
#ifdef HAVE_ANN
  ANNpoint q = annAllocPt(3);
  for(int k = 0; k < 3; ++k) q[k] = v->point()[k];
  ANNidxArray nn_idx = new ANNidx[1];
  ANNdistArray dists = new ANNdist[1];
  annTreeBnd->annkSearch(q, 1, nn_idx, dists);
  distance = std::sqrt(dists[0]);
  int i = nn_idx[0];
  delete[] nn_idx;
  delete[] dists;
  annDeallocPt(q);

  std::set<MVertex *>::iterator it = listOfBndVertices.begin();
  std::advance(it, i);
  return (*it);
#else
  return NULL;
#endif
}

double frameFieldBackgroundMesh3D::get_smoothness(double x, double y, double z)
{
  return get_field_value(x, y, z, crossFieldSmoothness);
};

double frameFieldBackgroundMesh3D::get_approximate_smoothness(double x,
                                                              double y,
                                                              double z)
{
  return crossFieldSmoothness[get_nearest_neighbor(x, y, z)];
}

double frameFieldBackgroundMesh3D::get_approximate_smoothness(MVertex *v)
{
  return get_approximate_smoothness(v->x(), v->y(), v->z());
}

double frameFieldBackgroundMesh3D::get_smoothness(MVertex *v)
{
  return get_nodal_value(v, crossFieldSmoothness);
};

void frameFieldBackgroundMesh3D::eval_approximate_crossfield(double x, double y,
                                                             double z,
                                                             STensor3 &cf)
{
  cf = crossField[get_nearest_neighbor(x, y, z)];
};

void frameFieldBackgroundMesh3D::eval_approximate_crossfield(
  const MVertex *vert, STensor3 &cf)
{
  // check if vertex is ours...
  TensorStorageType::const_iterator itfind =
    crossField.find(const_cast<MVertex *>(vert));
  if(itfind != crossField.end())
    cf = itfind->second;
  else // if not, find closest
    eval_approximate_crossfield(vert->x(), vert->y(), vert->z(), cf);
}

void frameFieldBackgroundMesh3D::get_vectorial_smoothness(double x, double y,
                                                          double z,
                                                          SVector3 &cf)
{
  std::vector<double> res =
    get_field_value(x, y, z, crossFieldVectorialSmoothness);
  for(int i = 0; i < 3; i++) cf(i) = res[i];
}

void frameFieldBackgroundMesh3D::get_vectorial_smoothness(const MVertex *vert,
                                                          SVector3 &cf)
{
  std::vector<double> res =
    get_nodal_value(vert, crossFieldVectorialSmoothness);
  for(int i = 0; i < 3; i++) cf(i) = res[i];
}

double frameFieldBackgroundMesh3D::get_vectorial_smoothness(const int idir,
                                                            double x, double y,
                                                            double z)
{
  return get_field_value(x, y, z, crossFieldVectorialSmoothness)[idir];
}

double frameFieldBackgroundMesh3D::get_vectorial_smoothness(const int idir,
                                                            const MVertex *vert)
{
  return get_nodal_value(vert, crossFieldVectorialSmoothness)[idir];
}

void frameFieldBackgroundMesh3D::build_vertex_to_element_table()
{
  GRegion *gr = dynamic_cast<GRegion *>(gf);
  if(!gr) {
    Msg::Error("Entity is not a region in background mesh");
    return;
  }
  MElement *e;
  MVertex *v;

  //    std::cout << "build_vertex_to_element_table nbelem=" <<
  //    gr->getNumMeshElements() << std::endl;

  for(unsigned int i = 0; i < gr->getNumMeshElements();
      i++) { // for all elements
    e = gr->getMeshElement(i);
    if(e->getDim() != 3) continue; // of dim=3

    for(std::size_t iv = 0; iv < e->getNumVertices();
        iv++) { // for all vertices
      v = e->getVertex(iv);
      vert2elem[v].insert(e);
      elem2vert[e].insert(v);
      //      std::cout << "node " << iv << " on " << v->onWhat()->dim() <<
      //      std::endl;
      if(v->onWhat()->dim() <= 2) {
        //        std::cout << "adding " << std::endl;
        listOfBndVertices.insert(v);
      }
    }
  }
}

const MElement *backgroundMesh3D::getElement(unsigned int i) const
{
  GRegion *gr = dynamic_cast<GRegion *>(gf);
  if(!gr) {
    Msg::Error("Entity is not a region in background mesh");
    return 0;
  }
  return gr->getMeshElement(i);
}

unsigned int backgroundMesh3D::getNumMeshElements() const
{
  GRegion *gr = dynamic_cast<GRegion *>(gf);
  if(!gr) {
    Msg::Error("Entity is not a region in background mesh");
    return 0;
  }
  return gr->getNumMeshElements();
}

// this function fills the multimap "graph": vertex to direct neighbors, or
// indirect neighbors, depending on the "max_recursion_level".
void frameFieldBackgroundMesh3D::build_neighbors(const int &max_recursion_level)
{
  std::set<MVertex const *> visited, start;
  std::set<MElement const *> visited_elements;
  std::multimap<int, MVertex const *> proximity;
  // int counter=0;

  for(vert2elemtype::iterator it_vertex = vert2elem.begin();
      it_vertex != vert2elem.end(); it_vertex++) { // for all vertices
    MVertex const *const current_vertex = it_vertex->first;
    visited.clear();
    visited_elements.clear();
    visited.insert(current_vertex);
    start.clear();
    start.insert(current_vertex);
    proximity.clear();

    get_recursive_neighbors(start, visited, visited_elements, proximity,
                            max_recursion_level);

    for(std::multimap<int, MVertex const *>::iterator it1 = proximity.begin();
        it1 != proximity.end(); it1++) {
      graph.insert(std::make_pair(current_vertex,
                                  std::make_pair(it1->first, it1->second)));
    }

    //    if (debug){// check
    //      if (verbose) std::cout << "vertex (" << counter++ << "): " <<
    //      current_vertex->getNum() << "  connected to " <<
    //      it_vertex->second.size() << " elements, coord: (" <<
    //      current_vertex->x() << "," << current_vertex->y() << "," <<
    //      current_vertex->z() << ")" << std::endl; set<MVertex*> allvertex;
    //      for (multimap<int,MVertex*>::iterator it1 =
    //      proximity.begin();it1!=proximity.end();it1++){
    //        if (verbose) {
    //          for (int i=0;i<it1->first;i++) std::cout << "  ";
    //          std::cout << it1->first << "  :  " << it1->second->getNum() <<
    //          std::endl;
    //        }
    //        set<MVertex*>::iterator itfind = allvertex.find(it1->second);
    //        if (itfind!=allvertex.end()){
    //          cerr << " ERROR : vertex duplicate !!!" << std::endl;
    //          throw;
    //        }
    //        allvertex.insert(it1->second);
    //      }
    //    }// end check
  }
}

void frameFieldBackgroundMesh3D::get_recursive_neighbors(
  std::set<MVertex const *> &start, std::set<MVertex const *> &visited,
  std::set<MElement const *> &visited_elements,
  std::multimap<int, MVertex const *> &proximity, int max_level, int level)
{
  level++;
  if(level > max_level) return;

  std::set<MVertex const *> new_vertices;

  for(std::set<MVertex const *>::iterator it_start = start.begin();
      it_start != start.end(); it_start++) { // for all initial vertices
    MVertex const *current = *it_start;
    //      std::cout << "get_recursive_neighbors : on vertex " <<
    //      current->getNum()
    //      << " (" << current << ")" << std::endl;
    vert2elemtype::iterator itfind = vert2elem.find(current);
    if(itfind == vert2elem.end()) continue;

    std::set<MElement *>::iterator it_elem = itfind->second.begin();

    for(; it_elem != itfind->second.end();
        it_elem++) { // for all connected elements
      MElement *current_elem = *it_elem;

      if(visited_elements.find(current_elem) != visited_elements.end()) {
        continue;
      }
      //        std::cout << current_elem->getNum() << std::endl;
      for(std::size_t i = 0; i < current_elem->getNumVertices(); i++) {
        MVertex *ver = current_elem->getVertex(i);

        if(visited.find(ver) != visited.end()) continue;

        proximity.insert(std::make_pair(level, ver));
        new_vertices.insert(ver);
        visited.insert(ver);
      }
      visited_elements.insert(current_elem);
    }
  }

  get_recursive_neighbors(new_vertices, visited, visited_elements, proximity,
                          max_level, level);
}

double frameFieldBackgroundMesh3D::compare_to_neighbors(
  const SPoint3 &current, STensor3 &ref,
  std::multimap<double, MVertex const *>::iterator itbegin,
  std::multimap<double, MVertex const *>::iterator itend, SVector3 &mean_axis,
  double &mean_angle, std::vector<double> &vectorial_smoothness)
{
  for(int i = 0; i < 3; i++) mean_axis(i) = 0.;

  std::multimap<double, MVertex const *>::iterator it = itbegin;
  SVector3 rotation_axis;
  double minimum_angle;

  std::vector<double> all_angle;
  std::vector<SVector3> all_axis;
  TensorStorageType::iterator itneighbor;

  //  vectorial_smoothness.assign(3,0.);
  //  vector<double> temp(3);

  std::vector<double> ponderations_vec;

  std::vector<double> alternative;

  for(; it != itend; it++) { // for all trusted neighbors
    // neighbor = it->second.second;
    MVertex const *neighbor = it->second;
    // ponderations_vec.push_back(1.);
    ponderations_vec.push_back(
      (std::abs(it->first) >= smoothness_threshold) ? 1. : 1.e-3);
    // ponderations_vec.push_back(((std::abs(it->first) >= smoothness_threshold)
    // ?
    // 1. : 1.e-3) / (current.distance(neighbor->point())));
    itneighbor = crossField.find(neighbor);
    STensor3 &neibcross = itneighbor->second;

    get_min_rotation_matrix(neibcross, ref, minimum_angle, rotation_axis);
    all_axis.push_back(rotation_axis);
    all_angle.push_back(minimum_angle);
    alternative.push_back(std::abs(minimum_angle));

    //    // now, computing vectorial smoothness
    //    for (int j=0;j<3;j++){// for every cross field vector
    //      temp.assign(3,0.);
    //      for (int ivec=0;ivec<3;ivec++){// for every neighbor vector
    //        for (int k=0;k<3;k++){
    //          temp[ivec] += (neibcross(k,ivec)*ref(k,j));// scalar products
    //        }
    //        temp[ivec] = std::abs(temp[ivec]);
    //      }
    //      vectorial_smoothness[j] +=
    //      acos(fmin(*std::max_element(temp.begin(),temp.end()),1.));
    //    }
  }

  // Watch out !!!      acos(mean_angle)  !=  mean_acos    ->     second option
  // gives better results, better contrast between smooth and not smooth
  //  for (int j=0;j<3;j++){
  //    vectorial_smoothness[j] = (1. -
  //    (vectorial_smoothness[j]/all_angle.size())/M_PI*4.);// between 0 (not
  //    smooth) and 1 (smooth)
  //  }

  // ----------------------------------------------------------------------------
  // Watch out !!!  The following definition of smoothness may change A LOT !!!
  // ----------------------------------------------------------------------------
  // may seem against intuition in some case, but min gives much better results
  // finally... mean angle !!!

  //  double smoothness_scalar =
  //  (*std::max_element(vectorial_smoothness.begin(),vectorial_smoothness.end()));
  //  double smoothness_scalar =
  //  (*std::min_element(vectorial_smoothness.begin(),vectorial_smoothness.end()));
  double smoothness_scalar =
    1. - (std::accumulate(alternative.begin(), alternative.end(), 0.) /
          alternative.size()) /
           M_PI * 4.; // APPROXIMATELY between 0 (not smooth) and 1 (smooth),
                      // (sometimes <0, always > 1).

  std::vector<double>::iterator itan = all_angle.begin();
  std::vector<double>::iterator itpond = ponderations_vec.begin();

  for(std::vector<SVector3>::iterator ita = all_axis.begin();
      ita != all_axis.end(); ita++, itan++, itpond++) {
    // mean_axis += ((*ita)*(*itan));
    mean_axis += ((*ita) * (*itan)) * (*itpond);
  }

  // mean_angle = mean_axis.norm()/all_angle.size();
  double pond_total =
    std::accumulate(ponderations_vec.begin(), ponderations_vec.end(), 0.);
  mean_angle = mean_axis.norm() / pond_total;
  mean_axis.normalize();

  return smoothness_scalar;
}

STensor3 frameFieldBackgroundMesh3D::apply_rotation(const SVector3 &axis,
                                                    const double &angle,
                                                    const STensor3 &thecross)
{
  double rotmat[3][3];
  STensor3 res2;
  get_rotation_matrix(angle, axis, &rotmat[0][0]);

  //    std::cout << "from matrice, rotation of " << angle/M_PI*180 << "° axis("
  //    << axis(0) << "," << axis(1) << "," << axis(2) << ")" << std::endl;
  //        std::cout << "rotation matrix is :" << std::endl;
  //        for (int i=0;i<3;i++){
  //          for (int j=0;j<3;j++)
  //            std::cout << rotmat[i][j] << " ";
  //          std::cout << std::endl;
  //        }
  //

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++) res2(i, j) += rotmat[i][k] * thecross(k, j);
  //  return res;

  //  std::cout << "result:" << std::endl;
  //    for (int i=0;i<3;i++){
  //      for (int j=0;j<3;j++)
  //        std::cout << res2(i,j) << " ";
  //      std::cout << std::endl;
  //    }

  //  STensor3 res;
  //  double crossv[4],q[4],qconj[4],resq[4];
  //  double coss = cos(angle/2.);
  //  double sinn = sin(angle/2.);
  //  q[0] = coss;
  //  q[1] = sinn*axis[0];
  //  q[2] = sinn*axis[1];
  //  q[3] = sinn*axis[2];
  //  qconj[0] = q[0];
  //  for (int i=1;i<4;i++) qconj[i] = -q[i];
  //
  //  for (int i=0;i<3;i++){
  //    crossv[0] = 0.;
  //    crossv[1] = thecross(0,i);
  //    crossv[2] = thecross(1,i);
  //    crossv[3] = thecross(2,i);
  //
  ////    quat_prod(q,crossv,resq);
  ////    quat_prod(resq,qconj,resq);
  //    quat_prod(crossv,qconj,resq);
  //    quat_prod(q,resq,resq);
  //    for (int j=0;j<3;j++)
  //      res(j,i)=resq[j+1];
  //
  //  }
  //  std::cout << "from quat:" << std::endl;
  //  for (int i=0;i<3;i++){
  //    for (int j=0;j<3;j++)
  //      std::cout << res(j,i) << " ";
  //    std::cout << std::endl;
  //  }
  //  std::cout << "w="<<resq[0] << std::endl;
  return res2;

  //  STensor3 res;
  //  double coss = cos(angle);
  //  double sinn = sin(angle);
  //  SVector3 temp;
  //  for (int i=0;i<3;i++){
  //    SVector3 v(thecross(0,i),thecross(1,i),thecross(2,i));
  //    temp = axis*my_scal_prod(axis,v);
  //    SVector3 vres = (v - temp)*coss + crossprod(axis,v)*sinn + temp;
  //    for (int j=0;j<3;j++)
  //      res(j,i)=vres(j);
  //  }
  //  return res;
}

// TODO: ce genre de fct... mettre dans une classe FrameField ? Ou bien juste un
// set de fcts à part ? Parce que ça devient bizarre d'avoir ça dans un BGM ???
void frameFieldBackgroundMesh3D::get_rotation_matrix(const double &angle_to_go,
                                                     const SVector3 &rotvec,
                                                     double *rotmat)
{
  double c = std::cos(angle_to_go);
  double s = std::sin(angle_to_go);
  double temp01 = rotvec[0] * rotvec[1] * (1. - c);
  double temp02 = rotvec[0] * rotvec[2] * (1. - c);
  double temp12 = rotvec[1] * rotvec[2] * (1. - c);
  double square0 = rotvec[0] * rotvec[0];
  double square1 = rotvec[1] * rotvec[1];
  double square2 = rotvec[2] * rotvec[2];
  rotmat[0] = square0 + (1. - square0) * c;
  rotmat[1] = temp01 - rotvec[2] * s;
  rotmat[2] = temp02 + rotvec[1] * s;
  rotmat[3] = temp01 + rotvec[2] * s;
  rotmat[4] = square1 + (1. - square1) * c;
  rotmat[5] = temp12 - rotvec[0] * s;
  rotmat[6] = temp02 - rotvec[1] * s;
  rotmat[7] = temp12 + rotvec[0] * s;
  rotmat[8] = square2 + (1. - square2) * c;
}

void frameFieldBackgroundMesh3D::get_min_rotation_matrix(
  const STensor3 &reference, const STensor3 &thecross, double &minimum_angle,
  SVector3 &rotation_axis, double threshold, bool debugflag)
{
  minimum_angle = M_PI / 2.;
  std::pair<int, int> p;

  for(unsigned int iperm = 0; iperm < permutation.size(); iperm++) {
    if(minimum_angle < threshold) break;
    for(int i_rotation_perm = 0; i_rotation_perm < 3; i_rotation_perm++) {
      double a;
      SVector3 v;
      get_rotation_angle_and_axis(reference, thecross, a, v, i_rotation_perm,
                                  permutation[iperm]);
      if(debugflag) {
        if(std::abs(a) < M_PI / 2.) {
          std::cout << "     temp parameters:  angle=" << a * 180. / M_PI
                    << "pair=(" << iperm << "," << i_rotation_perm << ") axis=("
                    << v(0) << "," << v(1) << "," << v(2) << ")" << std::endl;
        }
        else
          std::cout << "     temp parameters:  angle=" << a * 180. / M_PI
                    << std::endl;
      }
      if(std::abs(a) < std::abs(minimum_angle)) {
        p = std::make_pair(iperm, i_rotation_perm);
        minimum_angle = a;
        rotation_axis = v;
      }

      if(minimum_angle < threshold) break;
    }
  }
  //  std::cout << "pair=(" << p.first << "," << p.second << ")" << std::endl;
  if(debugflag) {
    std::cout << " ---> MIN parameters:  angle=" << minimum_angle * 180. / M_PI
              << " axis=(" << rotation_axis(0) << "," << rotation_axis(1) << ","
              << rotation_axis(2) << ")" << std::endl;
  }
  return;
}

// compute the angle and axis of rotation between two (unit-orthogonal) cross
// fields using crossfield vectors permutations defined by modulo and trip The
// rotation matrix between cross fields C and M is R = C M^T
void frameFieldBackgroundMesh3D::get_rotation_angle_and_axis(
  const STensor3 &reference, const STensor3 &thecross, double &minimum_angle,
  SVector3 &rotation_axis, int modulo, montripletbis &trip)
{
  // double MT[3][3],C[3][3],R[3][3];
  double C[3][3], R[3][3];

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      C[i][j] =
        signof(trip(j)) * thecross(i, ((abs(trip(j)) - 1) + modulo) % 3);
      // MT[j][i] = reference(i,j);//transpose !
    }
  }

  //  ////////////////////
  //  for (int k=0;k<2;k++){
  //    double test1 = C[0][k]*C[0][k]*C[1][k]*C[1][k] +
  //    C[0][k]*C[0][k]*C[2][k]*C[2][k] +  C[2][k]*C[2][k]*C[1][k]*C[1][k];
  //    double test2 =
  //    reference(0,k)*reference(0,k)*reference(1,k)*reference(1,k) +
  //    reference(0,k)*reference(0,k)*reference(2,k)*reference(2,k) +
  //    reference(2,k)*reference(2,k)*reference(1,k)*reference(1,k); std::cout
  //    << "    --- k=" << k << " test1=" << test1 << std::endl; std::cout << "
  //    --- k=" << k << " test2=" << test2 << std::endl;
  //  }
  //  ////////////////////

  // computing the trace for the angle...
  // MT is transpose of reference !!!
  //  R[0][0] = C[0][0]*MT[0][0] + C[0][1]*MT[1][0] + C[0][2]*MT[2][0];
  //  R[1][1] = C[1][0]*MT[0][1] + C[1][1]*MT[1][1] + C[1][2]*MT[2][1];
  //  R[2][2] = C[2][0]*MT[0][2] + C[2][1]*MT[1][2] + C[2][2]*MT[2][2];
  R[0][0] = C[0][0] * reference(0, 0) + C[0][1] * reference(0, 1) +
            C[0][2] * reference(0, 2);
  R[1][1] = C[1][0] * reference(1, 0) + C[1][1] * reference(1, 1) +
            C[1][2] * reference(1, 2);
  R[2][2] = C[2][0] * reference(2, 0) + C[2][1] * reference(2, 1) +
            C[2][2] * reference(2, 2);

  // computing rotation angle
  double trace = R[0][0] + R[1][1] + R[2][2];
  minimum_angle =
    std::acos(std::max(std::min(0.5 * (trace - 1.), 1.), -1.)); // tjrs > 0

  //  std::cout << "minimum_angle=" << minimum_angle << " trace=" << trace <<
  //  std::endl;

  if(std::abs(minimum_angle) > M_PI / 2.) return; // no need to continue...

  // computing rotation axis
  // computing the remaining terms, not on diagonal
  if(std::abs(minimum_angle) < 1.e-6) {
    rotation_axis(0) = 0.;
    rotation_axis(1) = 0.;
    rotation_axis(2) = 1.;
    return;
  }

  R[0][1] = C[0][0] * reference(1, 0) + C[0][1] * reference(1, 1) +
            C[0][2] * reference(1, 2);
  R[0][2] = C[0][0] * reference(2, 0) + C[0][1] * reference(2, 1) +
            C[0][2] * reference(2, 2);
  R[1][0] = C[1][0] * reference(0, 0) + C[1][1] * reference(0, 1) +
            C[1][2] * reference(0, 2);
  R[1][2] = C[1][0] * reference(2, 0) + C[1][1] * reference(2, 1) +
            C[1][2] * reference(2, 2);
  R[2][0] = C[2][0] * reference(0, 0) + C[2][1] * reference(0, 1) +
            C[2][2] * reference(0, 2);
  R[2][1] = C[2][0] * reference(1, 0) + C[2][1] * reference(1, 1) +
            C[2][2] * reference(1, 2);

  double factor = -0.5 / std::sin(minimum_angle);
  rotation_axis(0) = (R[2][1] - R[1][2]) * factor;
  rotation_axis(1) = (R[0][2] - R[2][0]) * factor;
  rotation_axis(2) = (R[1][0] - R[0][1]) * factor;
  return;
}

void frameFieldBackgroundMesh3D::exportVectorialSmoothness(
  const std::string &filename)
{
  FILE *f = Fopen(filename.c_str(), "w");
  if(!f) {
    Msg::Error("Could not open file '%s'", filename.c_str());
    return;
  }

  fprintf(f, "View \"Background Mesh\"{\n");

  std::set<const MVertex *> done;

  for(unsigned int ie = 0; ie < getNumMeshElements();
      ie++) { // for all elements
    const MElement *e = getElement(ie);
    for(std::size_t iv = 0; iv < e->getNumVertices(); iv++) {
      const MVertex *v = e->getVertex(iv);
      std::set<const MVertex *>::iterator itfind = done.find(v);
      if(itfind != done.end()) continue;
      done.insert(v);
      STensor3 cf;
      eval_approximate_crossfield(v, cf);
      for(int i = 0; i < 3; i++) {
        double vs = get_vectorial_smoothness(i, v);
        fprintf(f, "VP(%g,%g,%g){%g,%g,%g};\n", v->x(), v->y(), v->z(),
                cf(0, i) * vs, cf(1, i) * vs, cf(2, i) * vs);
      }
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}
