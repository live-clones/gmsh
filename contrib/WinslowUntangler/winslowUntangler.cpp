// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author : Maxence Reberol
//        : JF Remacle added the support of P2 triangles
// This module re-implements the constrained 2d/3d untangler described in the
// paper:
//
//      Foldover-free maps in 50 lines of code.
//      Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., &
//      Sokolov, D. (2021). arXiv preprint arXiv:2102.03069.
//      reference implementation: https://github.com/ssloy/invertible-maps

#include "winslowUntangler.h"

#include <math.h>
#include <iostream> // debugging
#include <cfloat>

#include "Context.h"
#include "GmshMessage.h"
#include "OS.h"

#if defined(HAVE_EIGEN)
#include <Eigen/Core>
#include <Eigen/Dense>
#endif

#if defined(HAVE_ALGLIB)
#include <stdafx.h>
#include <optimization.h>
#endif

#if defined(HAVE_QUADMESHINGTOOLS)
#include "arrayGeometry.h"
#include "cppUtils.h"
#endif

size_t perTriangleP2 = 19;

#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB) && defined(HAVE_QUADMESHINGTOOLS)

using namespace ArrayGeometry;

namespace WinslowUntangler {

  template <size_t D>
  void bbox_minmax(const std::vector<std::array<double, D> > &points,
                   std::array<double, D> &bmin, std::array<double, D> &bmax)
  {
    bmin.fill(DBL_MAX);
    bmax.fill(-DBL_MAX);
    for(size_t i = 0; i < points.size(); ++i) {
      for(size_t d = 0; d < D; ++d) {
        bmin[d] = std::min(points[i][d], bmin[d]);
        bmax[d] = std::max(points[i][d], bmax[d]);
      }
    }
  }

  inline double tri_area(vec2 a, vec2 b, vec2 c)
  {
    return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
                 (a[1] - c[1]) * (a[0] + c[0]));
  }

  double area(const std::vector<std::array<double, 2> > &points,
              const std::vector<std::array<uint32_t, 3> > &triangles)
  {
    double sum = 0.;
    for(size_t i = 0; i < triangles.size(); ++i) {
      sum += tri_area(points[triangles[i][0]], points[triangles[i][1]],
                      points[triangles[i][2]]);
    }
    return sum;
  }

  inline double tet_volume(vec3 a, vec3 b, vec3 c, vec3 d)
  {
    return dot((a - d), cross(b - d, c - d)) / 6.;
  }

  double volume(const std::vector<std::array<double, 3> > &points,
                const std::vector<std::array<uint32_t, 4> > &tets)
  {
    double sum = 0.;
    for(size_t i = 0; i < tets.size(); ++i) {
      double tvol = tet_volume(points[tets[i][0]], points[tets[i][1]],
                               points[tets[i][2]], points[tets[i][3]]);
      sum += tvol;
    }
    return sum;
  }

  inline double coef_chi(double D, double eps)
  {
    return 0.5 * (D + std::sqrt(eps * eps + D * D));
  }

  inline double coef_chip(double D, double eps)
  {
    return 0.5 + D / (2. * std::sqrt(eps * eps + D * D));
  }

  // Data of the problem, which are passed to
  // and updated by the callback in the solver
  struct UntanglerData {
    // Parameters
    size_t dim = 2;
    double eps = 0.;
    double lambda = 1.;
    std::vector<bool> locked;
    const std::function<void (const std::vector<std::array<double, 2> > &points,
			      const std::vector<std::array<uint32_t, 3> > &triangles,
			      std::vector<double> &s, // size and grad sizes at nodes
			      std::vector<std::array<double, 3> > &grads)> & sizeField;
    UntanglerData (const std::function<void (const std::vector<std::array<double, 2> > &points,
					     const std::vector<std::array<uint32_t, 3> > &triangles,
					     std::vector<double> &s, // size and grad sizes at nodes
					     std::vector<std::array<double, 3> > &grads)> & sf) : sizeField(sf) {}

    // Data for 2D planar
    // ---------------------------------------------------
    // -- THIS IS A QUICK FIX --
    // In case of p2 triangles, half of the triangles
    // are used in a standard fashion and the other
    // half is only used for ensuring jacobian positivity
    bool isP2 = false;
    // ---------------------------------------------------
    std::vector<std::array<uint32_t, 3> > triangles;
    std::vector<Eigen::Matrix<double, 3, 2> > tri_normals;

    // Data for 3D volume
    std::vector<std::array<uint32_t, 4> > tetrahedra;
    std::vector<Eigen::Matrix<double, 4, 3> > tet_normals;

    // Data updated during computations
    std::vector<Eigen::Matrix2d> J_mat_2D;
    std::vector<Eigen::Matrix<double, 3, 3> > J_mat_3D;
    std::vector<double> J_det;

    // Stats
    double J_det_min = 0;
    int nb_invalid = 0;
    double energy = 0.;
  };


  // each triangle has gradients of shape functions
  // ((d_xi phi_1, d_eta phi_1)
  //  (d_xi phi_2, d_eta phi_2)
  //  (d_xi phi_3, d_eta phi_3))
  void update_all_jacobians_2D (size_t nElements,
				UntanglerData &w,
				std::vector<double> &dets,
				const alglib::real_1d_array &X){
    double j11, j12, j21, J22;
    dets.resize(nElements);
    for(size_t t = 0; t < nElements; t++){
      size_t t0 =  w.triangles[t][0];
      size_t t1 =  w.triangles[t][1];
      size_t t2 =  w.triangles[t][2];
      double x0 = X[2*t0];
      double x1 = X[2*t1];
      double x2 = X[2*t2];
      double y0 = X[2*t0+1];
      double y1 = X[2*t1+1];
      double y2 = X[2*t2+1];
      Eigen::Matrix<double, 3, 2> &N = w.tri_normals[t];
      double j00 = x0 * N(0,0) + x1 * N(1,0) + x2 * N(2,0);
      double j10 = y0 * N(0,0) + y1 * N(1,0) + y2 * N(2,0);
      double j01 = x0 * N(0,1) + x1 * N(1,1) + x2 * N(2,1);
      double j11 = y0 * N(0,1) + y1 * N(1,1) + y2 * N(2,1);
      dets[t] = j00*j11 - j01*j10;
      w.J_det[t] = dets[t];
      Eigen::Matrix<double, 2, 2> &J = w.J_mat_2D[t];
      J(0,0) = j00;
      J(1,0) = j01;
      J(0,1) = j10;
      J(1,1) = j11;
    }
  }

  double update_jacobian_matrix(size_t t, UntanglerData &w,
                                const alglib::real_1d_array &X)
  {
    if(w.dim == 2) {
      Eigen::Matrix<double, 2, 3> coords;
      for(size_t k = 0; k < 3; ++k) {
        coords(0, k) = X[2 * w.triangles[t][k] + 0];
        coords(1, k) = X[2 * w.triangles[t][k] + 1];
      }
      w.J_mat_2D[t] = (coords * w.tri_normals[t]).transpose();
      const double det = w.J_mat_2D[t].determinant();
      w.J_det[t] = det;
      return det;
    }
    else if(w.dim == 3) {
      Eigen::Matrix<double, 3, 4> coords;
      for(size_t k = 0; k < 4; ++k) {
        coords(0, k) = X[3 * w.tetrahedra[t][k] + 0];
        coords(1, k) = X[3 * w.tetrahedra[t][k] + 1];
        coords(2, k) = X[3 * w.tetrahedra[t][k] + 2];
      }
      w.J_mat_3D[t] = (coords * w.tet_normals[t]).transpose();
      const double det = w.J_mat_3D[t].determinant();
      w.J_det[t] = det;
      // if (det < 0.) {
      //   DBG(t, det);
      //   std::cout << "tet_normals" << std::endl;
      //   std::cout << w.tet_normals[t] << std::endl;
      //   std::cout << "J" << std::endl;
      //   std::cout << w.J_mat_3D[t] << std::endl;
      //   abort();
      // }
      return det;
    }
    return -DBL_MAX;
  }

  inline void print_array(const alglib::real_1d_array &x,
                          const std::string &name = "")
  {
    std::cout << name << ": ";
    for(size_t i = 0; i < x.length(); ++i) { std::cout << " " << x[i]; }
    std::cout << std::endl;
  }

  double compute_energy_and_gradient(UntanglerData &w,
                                     const alglib::real_1d_array &X,
                                     alglib::real_1d_array &grad)
  {
    // Initial values
    w.J_det_min = DBL_MAX;
    w.nb_invalid = 0;
    double energy = 0.;
    Eigen::Vector2d a_i,b_i;

    std::vector<double> sizes;
    std::vector<std::array<double, 2> > positions (grad.length());
    std::vector<std::array<double, 3> > grads;

    //    if (w.sizeField) {
    //      for (size_t i=0 ; i<grad.length() ; i+=2){
    //	positions[i/2] = {X[i],X[i+1]};
    //      }
    //      w.sizeField(positions,w.triangles,sizes,grads);
      //      printf("%zu sizes\n",sizes.size());
    //    }

    for(size_t i = 0; i < grad.length(); ++i) grad[i] = 0.;

    // Loop over triangle/tet contributions
    const size_t nElements =
      w.isP2 ? 4*(w.triangles.size()/perTriangleP2) : ((w.dim == 2) ? w.triangles.size() : w.tetrahedra.size());

    //    std::vector<double> dets;
    //    update_all_jacobians_2D (w.triangles.size(),w,dets,X);

    //    int nthreads = CTX::instance()->numThreads;
    int nthreads = 1;
    std::vector<double> GL(nthreads*  grad.length());
    std::vector<double> DM(nthreads);
    std::vector<double> EN(nthreads);
    for(size_t i = 0; i < GL.size(); ++i) GL[i] = 0.;
    for(size_t i = 0; i < nthreads; ++i) DM[i] = 1.e22;
    for(size_t i = 0; i < nthreads; ++i) EN[i] = 0.0;

    //#pragma omp parallel num_threads(nthreads) private (a_i,b_i)
    {
#if defined(_OPENMP)
      int thread_num = omp_get_thread_num();
#else
      int thread_num = 0;
#endif

      //#pragma omp for schedule(dynamic)
      for(size_t t = 0; t < nElements; t++) {
	// Update jacobian with current triangle coordinates
	const double det = /*dets[t];//*/update_jacobian_matrix(t, w, X);//
	//	printf("det = %12.5E\n",det);
	double OneOverSize2 = 1.0;
	if (!sizes.empty()){
	  double size = (sizes[w.triangles[t][0]]+sizes[w.triangles[t][1]]+sizes[w.triangles[t][2]])/3.0;
	  OneOverSize2 = 1./(size*size);
	}

	// Compute energy contribution from triangle
	const double chi = coef_chi(det, w.eps);
	const double chip = coef_chip(det, w.eps);
	const double f_eps =
	  (w.dim == 2) ?
          (w.J_mat_2D[t].transpose() * w.J_mat_2D[t]).trace() / chi :
          (w.J_mat_3D[t].transpose() * w.J_mat_3D[t]).trace() /
	  std::pow(chi, 2. / 3.);
	const double g_eps = (det * det * OneOverSize2 * OneOverSize2 + 1.) / (chi*OneOverSize2);
	const double Ec = f_eps + w.lambda * g_eps;
	//	printf("%12.5E %12.5E %12.5E %12.5E\n",f_eps,g_eps,det,chi);

	if(det < DM[thread_num]) DM[thread_num]= det;
	//      if(det <= 0.) w.nb_invalid += 1;
	EN[thread_num] += Ec;

	// Compute contribution to global gradient
	for(size_t i = 0; i < w.dim; ++i) {
	  if(w.dim == 2) { // Planar case
	    a_i = w.J_mat_2D[t].col(i);
	    if(i == 0) {
	      b_i(0) = w.J_mat_2D[t](1, 1);
	      b_i(1) = -w.J_mat_2D[t](0, 1);
	    }
	    else {
	      b_i(0) = -w.J_mat_2D[t](1, 0);
	      b_i(1) = w.J_mat_2D[t](0, 0);
	    };

	    Eigen::Vector2d dphi_da =
	      2. / chi * a_i -
	      1. / chi *
              (f_eps * chip - 2. * w.lambda * det + w.lambda * g_eps * chip) *
              b_i;

	    for(size_t k = 0; k < 3; ++k) {
	      uint32_t v = w.triangles[t][k];
	      double gc = 0;
	      if(!w.locked[v])
		gc = dphi_da.dot(w.tri_normals[t].row(k));
	      GL[(thread_num*grad.length()) + 2 * v + i] += gc;
	    }
	  }
	  else if(w.dim == 3) { // Volume case
	    Eigen::Vector3d a_i = w.J_mat_3D[t].col(i);
	    Eigen::Vector3d b_i = w.J_mat_3D[t]
	      .col((i + 1) % 3)
	      .cross(w.J_mat_3D[t].col((i + 2) % 3));
	    Eigen::Vector3d dphi_da =
	      2. / std::pow(chi, 2. / 3.) * a_i -
	      1. / chi *
              (2. / 3. * f_eps * chip - 2. * w.lambda * det +
               w.lambda * g_eps * chip) *
              b_i;
	    for(size_t k = 0; k < 4; ++k) {
	      uint32_t v = w.tetrahedra[t][k];
	      if(w.locked[v]) continue;
	      double gc = dphi_da.dot(w.tet_normals[t].row(k));
#pragma omp critical
	      grad[3 * v + i] += gc;
	    }
	  }
	}
      }
    }
#pragma omp barrier

    for(size_t i = 0; i < GL.size(); ++i) grad[i%grad.length()] += GL[i];
    for(size_t i = 0; i < nthreads; ++i) if(DM[i] <w.J_det_min) w.J_det_min = DM[i];
    for(size_t i = 0; i < nthreads; ++i) energy += EN[i];


    //    printf("COMPUTING ENERGY eps = %22.15E\n",w.eps);

    if (w.isP2 && 0){
      size_t dT = (perTriangleP2 - 4)/3;
      //      printf("%zu %zu\n",(w.triangles.size()-nElements)/dT,nElements);
      double signs[5] = {1,1,-1,-1,-1};
#pragma omp parallel for schedule(dynamic) num_threads(1) private (a_i,b_i) shared (energy)
      for(size_t tg = 0; tg < (w.triangles.size()-nElements)/dT; tg++) {
	// Update jacobian with current triangle coordinates
	double det=0.0;
	for (size_t l=0;l<dT;l++){
	  size_t t = nElements + tg*dT;
	  double D = update_jacobian_matrix(t+l, w, X);//
	  det += signs[l] * D;
	}
	//	printf("det = %12.5E\n",det);

	// Compute energy contribution from
	// combination of 5 triangles (3 for the moment)
	const double chi = coef_chi(det, w.eps);
	const double chip = coef_chip(det, w.eps);
	const double g_eps = (det * det + 1.) / chi;
	const double Ec = w.lambda * g_eps;

#pragma omp critical
	{
	  if(det < w.J_det_min) w.J_det_min = det;
	  if(det <= 0.) w.nb_invalid += 1;
	  energy += Ec;
	}
	// Compute contribution to global gradient
	for (size_t j=0;j<dT;j++){
	  size_t t = nElements + tg*dT;

	  for(size_t i = 0; i < w.dim; ++i) {
	    Eigen::Vector2d a_i = w.J_mat_2D[t+j].col(i);
	    Eigen::Vector2d b_i;
	    if(i == 0) {
	      b_i(0) = w.J_mat_2D[t+j](1, 1);
	      b_i(1) = -w.J_mat_2D[t+j](0, 1);
	    }
	    else {
	      b_i(0) = -w.J_mat_2D[t+j](1, 0);
	      b_i(1) = w.J_mat_2D[t+j](0, 0);
	    };

	    Eigen::Vector2d dphi_da =
	      w.lambda * signs[j] / chi * (2. * det - g_eps * chip) * b_i;

	    for(size_t k = 0; k < 3; ++k) {
	      uint32_t v = w.triangles[t+j][k];
	      double gc = 0;
	      if(!w.locked[v])
		gc = dphi_da.dot(w.tri_normals[t+j].row(k));
#pragma omp critical
	      grad[2 * v + i] += gc;
	    }
	  }
	}
      }
    }

#pragma omp barrier

    //    printf("energy = %12.5E\n",energy);
    //    exit(1);
    if(std::isnan(energy)) energy = std::numeric_limits<double>::max();
    w.energy = energy;
    return w.energy;
  }

  void lbfgs_callback(const alglib::real_1d_array &x, double &f,
                      alglib::real_1d_array &grad, void *ptr)
  {
    UntanglerData *wp = static_cast<UntanglerData *>(ptr);
    UntanglerData &w = *wp;
    //        double t1 = Cpu();
    f = compute_energy_and_gradient(w, x, grad);
    //        printf("%22.15E\n",Cpu()-t1);
  }

  void checkIfP2(UntanglerData &data, std::vector<size_t> &permut) {
    if (perTriangleP2 < 10)return;
    // if P2 triangles are considered, I send to
    // the optimizer the three "bezier corner" triangles
    if (data.triangles.size() % perTriangleP2 != 0) return;
    // Three successive triangles should always be numbered as
    // (a,d,f)(b,e,d)(c,f,e) which correspond to bezier triangles
    for (size_t i=0; i<data.triangles.size(); i+=perTriangleP2){
      auto t1 = data.triangles[i+0];
      auto t2 = data.triangles[i+1];
      auto t3 = data.triangles[i+2];
      if (t1[1] != t2[2])return;
      if (t2[1] != t3[2])return;
      if (t3[1] != t1[2])return;
    }
    auto xxx = data.triangles;
    data.triangles.clear();
    for (size_t i=0; i<xxx.size(); i+=perTriangleP2){
      for (size_t j=0;j<4;j++){
	permut.push_back(i+j);
	data.triangles.push_back(xxx[i+j]);
      }
    }
    for (size_t i=0; i<xxx.size(); i+=perTriangleP2){
      for (size_t j=4;j<perTriangleP2;j++){
	permut.push_back(i+j);
	data.triangles.push_back(xxx[i+j]);
      }
    }

    data.isP2 = true;
    //    for (auto i : permut)printf("%zu ",i);
    printf(" --- > FOUND A P2 MESH\n");
  }

  bool prepareData2D(
    const std::vector<std::array<double, 2> > &points,
    const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 3> > &tris,
    const std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes,
    UntanglerData &data)
  {
    if(triIdealShapes.size() != 0 &&
       triIdealShapes.size() != (size_t)tris.size()) {
      Msg::Error(
        "Winslow untangler 2D: incoherent sizes in triangles / triIdealShapes");
      return false;
    }
    data.dim = 2;
    data.triangles = tris;
    // ----------------------------------------------------
    // Quick FIX -- verify if the structure of P2 triangles
    // given here correspond to a P2 mesh
    // If it is true, add additional triangles that allow
    // to verify the positivity of P2 triangles ...
    std::vector<size_t> permut;
    checkIfP2 (data,permut);
    // ----------------------------------------------------
    data.locked = locked;
    data.J_mat_2D.resize(data.triangles.size());
    data.J_det.resize(data.triangles.size(), 0.);
    data.tri_normals.resize(data.triangles.size());
    double avg_tri_area = area(points, data.triangles) / double(data.triangles.size());
    if(avg_tri_area <= 0) {
      Msg::Warning(
        "Winslow untangler 2D: average triangle area is negative: %.3e",
        avg_tri_area);
    }

    // Build equilateral triangle centered in origin
    // with unit area
    vec2 equi[3] = {{1., 0.},
                    {cos(2. * M_PI / 3.), sin(2 * M_PI / 3.)},
                    {cos(4. * M_PI / 3.), sin(4 * M_PI / 3.)}};
    const vec3 N = {0, 0, -1};
    for(size_t tt = 0; tt < data.triangles.size(); ++tt) {
      size_t t = permut.empty() ? tt : permut[tt];
      vec2 shape[3] = {equi[0], equi[1], equi[2]};
      if(triIdealShapes.size() > 0.) {
        shape[0] = triIdealShapes[t][0];
        shape[1] = triIdealShapes[t][1];
        shape[2] = triIdealShapes[t][2];
      }

      double area = tri_area(shape[0], shape[1], shape[2]);
      if(std::isnan(area)) {
        Msg::Warning("Winslow untangler 2D: area of ideal shape for tri %li: "
                     "%f, cancel smoothing",
                     t, area);
        return false;
      }
      else if(area <= 0.) {
        Msg::Warning(
          "Winslow untangler 2D: area of ideal shape for tri %li: %f", t, area);
      }

      // Compute normals
      for(size_t le = 0; le < 3; ++le) {
        vec2 td = (shape[(le + 2) % 3] - shape[(le + 1) % 3]);
        vec3 n = cross(std::array<double, 3>{td[0], td[1], 0.}, N) *
                 (1. / (2. * area));
        data.tri_normals[tt](le, 0) = n[0];
        data.tri_normals[tt](le, 1) = n[1];
      }
    }

    // Update jacobian matrices with current triangle coordinates
    alglib::real_1d_array x0;
    x0.setcontent(2 * points.size(), points.front().data());
    data.J_det_min = DBL_MAX;
    data.nb_invalid = 0;
    data.energy = 0.;
    for(size_t t = 0; t < data.triangles.size(); t++) {
      const double det = update_jacobian_matrix(t, data, x0);
      if(det < data.J_det_min) data.J_det_min = det;
      if(det <= 0.) data.nb_invalid += 1;
    }
    data.eps =
      std::sqrt(1.e-12 + 0.04 * std::pow(std::min(data.J_det_min, 0.), 2));

    // Compute initial energy
    size_t max_t = data.isP2 ? 4*(data.triangles.size()/perTriangleP2) : data.triangles.size();
    for(size_t t = 0; t < max_t; t++) {
      //      printf("%zu %g\n",t,data.J_det[t]);
      const double det = data.J_det[t];
      const double chi = coef_chi(det, data.eps);
      const double chip = coef_chip(det, data.eps);
      const double f_eps =
        (data.J_mat_2D[t].transpose() * data.J_mat_2D[t]).trace() / chi;
      const double g_eps = (det * det + 1.) / chi;
      const double Ec = f_eps + data.lambda * g_eps;
      data.energy += Ec;
    }
    // P2 extension

    size_t dT = (perTriangleP2 - 4)/3;
    double signs[5] = {1,1,-1,-1,-1};
    for(size_t t = max_t; t < data.triangles.size(); t+=dT) {
      double det = 0;
      for (size_t l=0;l<dT;l++)det += signs[l] * data.J_det[t+l];

      const double chi = coef_chi(det, data.eps);
      const double g_eps = (det * det + 1.) / chi;
      const double Ec = data.lambda * g_eps;
      data.energy += Ec;
    }
    //    printf("FOUND A P2 MESH -- ENERGY %g\n",data.energy);
    return true;
  }

  bool prepareData3D(
    const std::vector<std::array<double, 3> > &points,
    const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 4> > &tets,
    const std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
    UntanglerData &data)
  {
    if(tetIdealShapes.size() != 0 &&
       tetIdealShapes.size() != (size_t)tets.size()) {
      Msg::Error(
        "Winslow untangler 3D: incoherent sizes in tets / tetIdealShapes");
      return false;
    }
    data.dim = 3;
    data.tetrahedra = tets;
    data.locked = locked;
    data.J_mat_3D.resize(tets.size());
    data.J_det.resize(tets.size(), 0.);
    data.tet_normals.resize(tets.size());
    double avg_tet_vol = volume(points, tets) / double(tets.size());
    if(avg_tet_vol <= 0) {
      Msg::Warning("Winslow untangler 3D: average tet area is negative: %.3e",
                   avg_tet_vol);
    }

    // Build regular tet centered in origin
    // with unit volume
    vec3 equi[4] = {{.5, 0, -1. / (2. * std::sqrt(2.))},
                    {-.5, 0, -1. / (2. * std::sqrt(2.))},
                    {0, .5, 1. / (2. * std::sqrt(2.))},
                    {0, -.5, 1. / (2. * std::sqrt(2.))}};
    double reg_vol = tet_volume(equi[0], equi[1], equi[2], equi[3]);

    for(size_t lv = 0; lv < 4; ++lv) {
      equi[lv] = equi[lv] * (1. / std::pow(reg_vol, 1. / 3.));
    }

    constexpr int facet_vertex[4][3] = {
      {1, 3, 2}, {0, 2, 3}, {3, 1, 0}, {0, 1, 2}};

    //    double avg_ideal_vol = 1.;
    //    if(tetIdealShapes.size() > 0.) {
    //      for(size_t t = 0; t < tetIdealShapes.size(); ++t) {
    //        avg_ideal_vol += tet_volume(tetIdealShapes[t][0], tetIdealShapes[t][1],
    //                                    tetIdealShapes[t][2], tetIdealShapes[t][3]);
    //      }
    //      avg_ideal_vol /= double(tetIdealShapes.size());
    //    }

    // Build ideal tet normals
    for(size_t t = 0; t < tets.size(); ++t) {
      vec3 shape[4] = {equi[0], equi[1], equi[2], equi[3]};
      if(tetIdealShapes.size() > 0.) {
        shape[0] = tetIdealShapes[t][0];
        shape[1] = tetIdealShapes[t][1];
        shape[2] = tetIdealShapes[t][2];
        shape[3] = tetIdealShapes[t][3];
      }

      //      for(size_t lv = 0; lv < 4; ++lv) {
      //        shape[lv] = shape[lv] * (1. / std::pow(avg_ideal_vol, 1. / 3.) *
      //                                 std::pow(avg_tet_vol, 1. / 3.));
      //      }

      double vol = tet_volume(shape[0], shape[1], shape[2], shape[3]);
      if(std::isnan(vol)) {
        Msg::Warning("Winslow untangler 3D: volume of ideal shape for tet %li: "
                     "%f, cancel smoothing",
                     t, vol);
        return false;
      }
      else if(vol < 0.) {
        Msg::Warning(
          "Winslow untangler 3D: volume of ideal shape for tet %li: %f", t,
          vol);
      }

      // Compute normals
      for(size_t lf = 0; lf < 4; ++lf) {
        vec3 e0 = shape[facet_vertex[lf][1]] - shape[facet_vertex[lf][0]];
        vec3 e1 = shape[facet_vertex[lf][2]] - shape[facet_vertex[lf][0]];
        vec3 n = 0.5 * cross(e1, e0) * (1. / (3. * avg_tet_vol));

        data.tet_normals[t](lf, 0) = n[0];
        data.tet_normals[t](lf, 1) = n[1];
        data.tet_normals[t](lf, 2) = n[2];
      }
    }

    // Update jacobian matrices with current triangle coordinates
    alglib::real_1d_array x0;
    x0.setcontent(3 * points.size(), points.front().data());
    data.J_det_min = DBL_MAX;
    data.nb_invalid = 0;
    data.energy = 0.;
    for(size_t t = 0; t < data.tetrahedra.size(); t++) {
      const double det = update_jacobian_matrix(t, data, x0);
      //      printf("det = %12.5E\n",det);
      if(det < data.J_det_min) data.J_det_min = det;
      if(det <= 0.) data.nb_invalid += 1;
    }
    data.eps =
      std::sqrt(1.e-12 + 0.04 * std::pow(std::min(data.J_det_min, 0.), 2));

    // Compute initial energy
    for(size_t t = 0; t < data.tetrahedra.size(); t++) {
      const double det = data.J_det[t];
      const double chi = coef_chi(det, data.eps);
      const double chip = coef_chip(det, data.eps);
      const double f_eps =
        (data.J_mat_3D[t].transpose() * data.J_mat_3D[t]).trace() /
        std::pow(chi, 2. / 3.);
      const double g_eps = (det * det + 1.) / chi;
      const double Ec = f_eps + data.lambda * g_eps;
      data.energy += Ec;
    }

    return true;
  }

  template <size_t D>
  bool scaleToUnit(
    std::vector<std::array<double, D> > &points,
    std::vector<std::array<std::array<double, D>, D + 1> > &idealShapes,
    std::array<double, D> &bbmin, std::array<double, D> &bbmax)
  {
    bbox_minmax(points, bbmin, bbmax);
    std::array<double, D> center = (bbmin + bbmax) * 0.5;
    double L = std::max(bbmax[0] - bbmin[0], bbmax[1] - bbmin[1]);
    if(D == 3) L = std::max(L, bbmax[2] - bbmin[2]);

    for(size_t v = 0; v < points.size(); ++v) {
      points[v] = (points[v] - center) * (1. / L);
    }
    for(size_t e = 0; e < idealShapes.size(); ++e) {
      for(size_t lv = 0; lv < idealShapes[e].size(); ++lv) {
        idealShapes[e][lv] = (idealShapes[e][lv] - center) * (1. / L);
      }
    }
    return true;
  }

  template <size_t D>
  bool scaleToInitial(std::vector<std::array<double, D> > &points,
                      std::array<double, D> bbmin, std::array<double, D> bbmax)
  {
    std::array<double, D> center = (bbmin + bbmax) * 0.5;
    double L = std::max(bbmax[0] - bbmin[0], bbmax[1] - bbmin[1]);
    if(D == 3) L = std::max(L, bbmax[2] - bbmin[2]);

    for(size_t v = 0; v < points.size(); ++v) {
      points[v] = points[v] * L + center;
    }
    return true;
  }

  void  optional_lbfgs_callback(const alglib::real_1d_array &x, double func, void *ptr) {
    printf("F = %12.5E\n",func);
  }

  // same function for 2D and 3D to avoid redundant code
  // only the structs of the appropriate dimension are used
  bool untangle_simplex_elements(
    size_t dim, std::vector<std::array<double, 2> > &points2D,
    std::vector<std::array<double, 3> > &points3D,
    const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 3> > &triangles,
    const std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes,
    const std::vector<std::array<uint32_t, 4> > &tetrahedra,
    const std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
    double lambda, int iterMaxInner, int iterMaxOuter, int iterFailMax,
    double timeMax,
    const std::function<void (const std::vector<std::array<double, 2> > &points,
    			      const std::vector<std::array<uint32_t, 3> > &triangles,
    			      std::vector<double> &s, // size and grad sizes at nodes
    			      std::vector<std::array<double, 3> > &grads)> & sizeField,
    const std::function<void (const std::vector<std::array<double, 2> > &points,
			      const std::vector<std::array<uint32_t, 3> > &triangles,
			      std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes)> &updateIdealTriangularShapes)
  {
    if(dim != 2 && dim != 3) return false;
    if(dim == 2 && (points2D.size() == 0 || triangles.size() == 0)) {
      Msg::Warning(
        "Wrong input sizes (%li vertices, %li triangles) in 2D Winslow untangler",
        points2D.size(), triangles.size());
      return false;
    }
    if(dim == 3 && (points3D.size() == 0 || tetrahedra.size() == 0)) {
      Msg::Warning(
        "Wrong input sizes (%li vertices, %li tetrahedra) in 3D Windlow untangler",
        points2D.size(), triangles.size());
      return false;
    }

    // Save initial positions, in case they need to be restored
    bool restore = false;
    std::vector<std::array<double, 2> > backup2D = points2D;
    std::vector<std::array<double, 3> > backup3D = points3D;

    UntanglerData data(sizeField);
    data.lambda = lambda;

    /* Scale the mesh to unit box,
       Transfer/preprocess data */
    size_t NV = (dim == 2) ? points2D.size() : points3D.size();
    vec2 bbmin2D, bbmax2D;
    vec3 bbmin3D, bbmax3D;
    if(dim == 2) {
      auto triIdealShapesS = triIdealShapes;
      if (updateIdealTriangularShapes)
      	updateIdealTriangularShapes (points2D,triangles,triIdealShapesS);

      bool okp =
        prepareData2D(points2D, locked, triangles, triIdealShapesS, data);
      if(!okp) return false;
    }
    else if(dim == 3) {
      auto tetIdealShapesS = tetIdealShapes;
      scaleToUnit(points3D, tetIdealShapesS, bbmin3D, bbmax3D);
      bool okp =
        prepareData3D(points3D, locked, tetrahedra, tetIdealShapesS, data);
      if(!okp) return false;
    }
    double *points =
      (dim == 2) ? points2D.front().data() : points3D.front().data();

    /* Optimization loop */
    bool converged = false;
    int nFail = 0;
    double t0 = Cpu();
    double E_prev = data.energy;
    // Copy positions in solver array
    alglib::real_1d_array x;
    x.setcontent(dim * NV, points);
    alglib::real_1d_array grad;
    grad.setcontent(dim * NV, points);

    for(int iter = 0; iter < iterMaxOuter; iter++) {
      // Update regularized epsilon parameter
      data.eps = std::sqrt(1.e-12 + 0.04 * std::pow(std::min(data.J_det_min, 0.), 2));

      double epsg = 1.e-4;
      double epsf = 1.e-12;
      double epsx = 1.e-12;
      // LBFGS from ALGLIB
      int lbfgsIter = 0;
      try {

        // Setup of the LBFGS solver
        alglib::ae_int_t N = dim * NV;
        alglib::ae_int_t corr = N < 15 ? N : 15; // Num of corrections in the scheme in [3,7]
        alglib::minlbfgsstate state;
        alglib::minlbfgsreport rep;
	minlbfgscreate(N, corr, x, state);
        // LBFGS stopping criteria
	minlbfgssetcond(state, epsg, epsf, epsx,
                        (alglib::ae_int_t)iterMaxInner);
        // Run LBFGS
	minlbfgsoptimize(state, lbfgs_callback, optional_lbfgs_callback, &data);

        // Extract coordinates
	minlbfgsresults(state, x, rep);

	for(size_t v = 0; v < NV; ++v) {
          for(size_t d = 0; d < dim; ++d) {
            points[dim * v + d] = x[dim * v + d];
          }
        }

	if (updateIdealTriangularShapes){
	  auto triIdealShapesS = triIdealShapes;
	  updateIdealTriangularShapes (points2D,triangles,triIdealShapesS);
	  prepareData2D(points2D, locked, triangles, triIdealShapesS, data);
	}

        if(rep.terminationtype != 4 && rep.terminationtype != 5) { nFail += 1; }
        lbfgsIter = rep.iterationscount;
        Msg::Info(" detmin = %22.15E eps= %22.15E %zu iter term %zu",
                  data.J_det_min, data.eps, rep.iterationscount,
                  rep.terminationtype);
      } catch(alglib::ap_error e) {
        Msg::Warning("Winslow untangler, iter %i: Alglib exception thrown in "
                     "LBFGS step, error: %s",
                     iter, e.msg.c_str());
        restore = true;
        converged = false;
        nFail += 1;
        break;
      } catch(...) {
        Msg::Warning(
          "Winslow untangler, iter %i: Alglib exception thrown in LBFGS step",
          iter);
        restore = true;
        converged = false;
        nFail += 1;
        break;
      }

      // Check outer loop stopping criteria
      double dErel =
        data.energy > 0 ? std::abs(data.energy - E_prev) / data.energy : 0.;

      Msg::Debug("- iter %i: eps = %f, E: %.3e, dE/E=%.3e, min(detJ)=%f, "
                 "#(det<0)=%i (LBFGS: %i iters)",
                 iter, data.eps, data.energy, dErel, data.J_det_min,
                 data.nb_invalid, lbfgsIter);

      if(data.J_det_min > 0 && dErel < 1e-5) {
        converged = true;
        Msg::Debug("- iter %i: converged |E-E_prev|/E = %.3e < 1.e-5", iter,
                   dErel);
        break;
      }
      if(nFail > iterFailMax) {
        Msg::Debug("- iter %i: reached maximum number of failures (%i)", iter,
                   nFail);
        break;
      }
      if(Cpu() - t0 > timeMax) {
        Msg::Debug("- iter %i: reached time max (%f sec)", iter, Cpu() - t0);
        break;
      }
      E_prev = data.energy;
    }

    /* Scale the mesh to initial size */
    if(dim == 2) { /*scaleToInitial(points2D, bbmin2D, bbmax2D);*/ }
    else if(dim == 3) {
      scaleToInitial(points3D, bbmin3D, bbmax3D);
    }

    if(restore) {
      points2D = backup2D;
      points3D = backup3D;
    }

#if 0 // TEST OF GRADIENT !!
    {
      alglib::real_1d_array GRAD,GRAD2;
      GRAD.setcontent(dim * NV, points);
      GRAD2.setcontent(dim * NV, points);
      double EN  = compute_energy_and_gradient(data, x, GRAD);
      for (size_t i=0;i<dim * NV;i++){
	x[i]+=1.e-8;
	double EN2 = compute_energy_and_gradient(data, x, GRAD2);
	x[i]-=1.e-8;
	printf("%zu GRAD %12.5E DIFF %12.5E\n",i,GRAD[i],1.e8*(EN2-EN));
      }
    }
#endif


    return converged;
  }
} // namespace WinslowUntangler

using namespace WinslowUntangler;

#endif

bool untangle_triangles_2D(
  std::vector<std::array<double, 2> > &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 3> > &triangles,
  const std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes,
  double lambda, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax,
  const std::function<void (const std::vector<std::array<double, 2> > &points,
			    const std::vector<std::array<uint32_t, 3> > &triangles,
			    std::vector<double> &s, // size and grad sizes at nodes
			    std::vector<std::array<double, 3> > &grads)> & sizeField,
  const std::function<void (const std::vector<std::array<double, 2> > &points,
			    const std::vector<std::array<uint32_t, 3> > &triangles,
			    std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes)> &updateIdealTriangularShapes)
{
#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB) && defined(HAVE_QUADMESHINGTOOLS)
  std::vector<std::array<double, 3> > points3D;
  const std::vector<std::array<uint32_t, 4> > tetrahedra;
  const std::vector<std::array<std::array<double, 3>, 4> > tetIdealShapes;
  return untangle_simplex_elements(
    2, points, points3D, locked, triangles, triIdealShapes, tetrahedra,
    tetIdealShapes, lambda, iterMaxInner, iterMaxOuter, iterFailMax, timeMax,
    sizeField,updateIdealTriangularShapes);
#else
  Msg::Error(
    "Winslow untangler requires modules Eigen, Alglib and QuadMeshingTools");
  return false;
#endif
}

bool untangle_tetrahedra(
  std::vector<std::array<double, 3> > &points,
  const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 4> > &tets,
  const std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
  double lambda, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax)
{
#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB) && defined(HAVE_QUADMESHINGTOOLS)
  std::vector<std::array<double, 2> > points2D;
  const std::vector<std::array<uint32_t, 3> > tris;
  const std::vector<std::array<std::array<double, 2>, 3> > triIdealShapes;
  return untangle_simplex_elements(
    3, points2D, points, locked, tris, triIdealShapes, tets, tetIdealShapes,
    lambda, iterMaxInner, iterMaxOuter, iterFailMax, timeMax, nullptr, nullptr);
#else
  Msg::Error(
    "Winslow untangler requires modules Eigen, Alglib and QuadMeshingTools");
  return false;
#endif
}
