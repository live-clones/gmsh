// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_REVOROPT)

#include "CVTRemesh.h"

#include "Revoropt/Mesh/builder_def.hpp"
#include "Revoropt/Mesh/sampling_def.hpp"
#include "Revoropt/Mesh/normals_def.hpp"

#include "Revoropt/RVD/rvd.hpp"
#include "Revoropt/RVD/rdt.hpp"

#include "Revoropt/CVT/minimizer.hpp"

#include "Revoropt/Solver/alglib_lbfgs.hpp"

#include "GModel.h"
#include "MTriangle.h"
#include "discreteFace.h"

#include <vector>
#include <iostream>

StringXNumber CVTRemeshOptions_Number[] = {
  {GMSH_FULLRC, "Sites", nullptr, 20000.},
  {GMSH_FULLRC, "Iterations", nullptr, 20.},
  {GMSH_FULLRC, "Anisotropy", nullptr, 0.03},
  {GMSH_FULLRC, "Variable density", nullptr, 0.3},
  {GMSH_FULLRC, "Feature sensitivity", nullptr, 5.},
  {GMSH_FULLRC, "Normal computation radius", nullptr, 0.005}};

extern "C" {
GMSH_Plugin *GMSH_RegisterCVTRemeshPlugin()
{
  return new GMSH_CVTRemeshPlugin();
}
}

std::string GMSH_CVTRemeshPlugin::getHelp() const
{
  return "Plugin(CVTRemesh) triangulates an input geometry using"
         "centroïdal Voronoï tesselations. The STL mesh of the geometry"
         "is generated and randomly sampled. An objective function derived"
         "from centroïdal Voronoï tesselations is then defined on the"
         "generated sampling, and optimized through LBFGS to obtain a"
         "regular sampling of the surface. The triangulation is extracted"
         "as the restricted Delaunay triangulation of the samples and the"
         "STL mesh.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(CVTRemesh) creates one new view.";
}

int GMSH_CVTRemeshPlugin::getNbOptions() const
{
  return sizeof(CVTRemeshOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CVTRemeshPlugin::getOption(int iopt)
{
  return &CVTRemeshOptions_Number[iopt];
}

// solver callback
class SolverCallback {
public:
  template <typename Data> void operator()(Data *data)
  {
    // Output current iteration data
    Msg::Info("[CVTRemesh] : iteration %d, objective function value is %f",
              data->k, data->fx);
  }
};

PView *GMSH_CVTRemeshPlugin::execute(PView *v)
{
  // TODO normalization

  GModel *m = GModel::current();

  std::vector<double> vertices;
  std::vector<unsigned int> faces;

  unsigned int offset = 0;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    (*it)->buildSTLTriangulation();
    for(std::size_t i = 0; i < (*it)->stl_vertices_uv.size(); ++i) {
      GPoint p = (*it)->point((*it)->stl_vertices_uv[i]);
      vertices.push_back(p.x());
      vertices.push_back(p.y());
      vertices.push_back(p.z());
    }
    for(std::size_t i = 0; i < (*it)->stl_triangles.size(); ++i) {
      faces.push_back((*it)->stl_triangles[i] + offset);
    }
    offset += (*it)->stl_vertices_uv.size();
  }

  Revoropt::MeshBuilder<3> mesh;
  mesh.swap_vertices(vertices);
  mesh.swap_faces(faces);

  double mesh_center[3];
  double mesh_scale;
  Revoropt::normalize_mesh(&mesh, mesh_center, &mesh_scale);

  double nradius = (double)CVTRemeshOptions_Number[5].def;

  // normals
  std::vector<double> normals(3 * mesh.vertices_size());
  Revoropt::full_robust_vertex_normals(&mesh, nradius, normals.data());

  // lifted vertices
  std::vector<double> lifted_vertices(6 * mesh.vertices_size(), 0);
  for(std::size_t vertex = 0; vertex < mesh.vertices_size(); ++vertex) {
    std::copy(mesh.vertex(vertex), mesh.vertex(vertex) + 3,
              lifted_vertices.data() + 6 * vertex);
    std::copy(normals.data() + 3 * vertex, normals.data() + 3 * vertex + 3,
              lifted_vertices.data() + 6 * vertex + 3);
  }

  // setup lifted mesh
  Revoropt::ROMeshWrapper<3, 6> lifted_mesh(lifted_vertices.data(),
                                            lifted_vertices.size() / 6, &mesh);

  // triangle weight factor
  double twfactor = (double)CVTRemeshOptions_Number[3].def;

  // face ratios
  std::vector<double> triangle_weights(lifted_mesh.faces_size());
  if(twfactor > 0) {
    for(std::size_t f = 0; f < lifted_mesh.faces_size(); ++f) {
      // vertices of the initial triangle
      const unsigned int *fverts = mesh.face(f);

      // positions
      const double *x[3];
      for(int i = 0; i < 3; ++i) { x[i] = lifted_mesh.vertex(fverts[i]); }

      // ratio
      double ratio = 1;

      // vectors
      typedef Eigen::Matrix<double, 3, 1> Vector3;

      Eigen::Map<const Vector3> v0(x[0]);
      Eigen::Map<const Vector3> v1(x[1]);
      Eigen::Map<const Vector3> v2(x[2]);

      // triangle frame
      Vector3 U = (v1 - v0);
      const double U_len = U.norm();
      if(U_len > 0) {
        U /= U_len;
        Vector3 H = (v2 - v0);
        H = H - H.dot(U) * U;
        const double H_len = H.norm();
        if(H_len > 0) {
          // we know that the triangle is not flat
          H /= H_len;

          // gradient of the barycentric weights in the triangle
          Eigen::Matrix<double, 3, 2> bar_grads;
          bar_grads(2, 0) = 0;
          bar_grads(2, 1) = 1 / H_len;

          // gradient norms of every normal component
          for(int i = 0; i < 2; ++i) {
            // reference frame for the vertex
            Eigen::Map<const Vector3> vi0(x[(i + 1) % 3]);
            Eigen::Map<const Vector3> vi1(x[(i + 2) % 3]);
            Eigen::Map<const Vector3> vi2(x[i]);

            Vector3 Ui = (vi1 - vi0);
            Ui /= Ui.norm();
            Vector3 Hi = (vi2 - vi0);
            Hi = Hi - Hi.dot(Ui) * Ui;
            const double Hi_invlen = 1 / Hi.norm();
            Hi *= Hi_invlen;
            bar_grads(i, 0) = Hi.dot(U) * Hi_invlen;
            bar_grads(i, 1) = Hi.dot(H) * Hi_invlen;
          }

          // gradient of each component of the normal
          Eigen::Map<const Vector3> n0(x[0] + 3);
          Eigen::Map<const Vector3> n1(x[1] + 3);
          Eigen::Map<const Vector3> n2(x[2] + 3);

          Eigen::Matrix<double, 3, 2> n_grads =
            Eigen::Matrix<double, 3, 2>::Zero();

          n_grads = n0 * bar_grads.row(0);
          n_grads += n1 * bar_grads.row(1);
          n_grads += n2 * bar_grads.row(2);

          // maximal gradient norm
          double g_max = n_grads.row(0).dot(n_grads.row(0));
          double g_other = n_grads.row(1).dot(n_grads.row(1));
          g_max = g_max > g_other ? g_max : g_other;
          g_other = n_grads.row(2).dot(n_grads.row(2));
          g_max = g_max > g_other ? g_max : g_other;

          if(g_max == g_max) { // prevent nan
            ratio += g_max;
          }
        }
      }
      triangle_weights[f] = pow(ratio, twfactor);
    }
  }

  // normal factor
  double nfactor = (double)CVTRemeshOptions_Number[2].def;
  ;

  // weight the normal component by the provided factor
  for(std::size_t i = 0; i < lifted_mesh.vertices_size(); ++i) {
    double *v = lifted_vertices.data() + 6 * i;
    v[3] *= nfactor;
    v[4] *= nfactor;
    v[5] *= nfactor;
  }

  // number of sites
  unsigned int nsites = (unsigned int)CVTRemeshOptions_Number[0].def;

  // lifted sites
  std::vector<double> lifted_sites(6 * nsites);
  if(twfactor > 0) {
    Revoropt::generate_random_sites<Revoropt::ROMesh<3, 6> >(
      &lifted_mesh, nsites, lifted_sites.data(), triangle_weights.data());
  }
  else {
    Revoropt::generate_random_sites<Revoropt::ROMesh<3, 6> >(
      &lifted_mesh, nsites, lifted_sites.data());
  }

  // setup the cvt minimizer
  Revoropt::CVT::DirectMinimizer<Revoropt::ROMesh<3, 6> > cvt;
  cvt.set_sites(lifted_sites.data(), nsites);
  cvt.set_mesh(&lifted_mesh);
  if(twfactor > 0) { cvt.set_triangle_weights(triangle_weights.data()); }

  // setup the callback
  SolverCallback callback;

  // number of iterations
  unsigned int niter = (unsigned int)CVTRemeshOptions_Number[1].def;
  ;
  unsigned int aniso_niter = std::min<unsigned int>(10, niter);

  // solver status
  int status = 0;

  // isotropic iterations
  if(niter > 10) {
    aniso_niter = std::max(aniso_niter, niter * 10 / 100);
    cvt.set_anisotropy(1);
    status =
      cvt.minimize<Revoropt::Solver::AlgLBFGS>(niter - aniso_niter, &callback);
  }

  // anisotropic iterations
  if(niter > 0) {
    // tangent space anisotropy
    double tanisotropy = (double)CVTRemeshOptions_Number[4].def;
    ;

    // anisotropic iterations
    cvt.set_anisotropy(tanisotropy);
    status = cvt.minimize<Revoropt::Solver::AlgLBFGS>(aniso_niter, &callback);
  }

  // rdt
  std::vector<unsigned int> rdt_triangles;
  Revoropt::RDTBuilder<Revoropt::ROMesh<3, 6> > build_rdt(rdt_triangles);
  Revoropt::RVD<Revoropt::ROMesh<3, 6> > rvd;
  rvd.set_sites(lifted_sites.data(), nsites);
  rvd.set_mesh(&lifted_mesh);
  rvd.compute(build_rdt);

  GFace *res_face = new discreteFace(m, m->getMaxElementaryNumber(2) + 1);
  m->add(res_face);

  // scale back and transfer to gmsh
  std::vector<MVertex *> m_verts(nsites);
  for(std::size_t i = 0; i < nsites; ++i) {
    m_verts[i] =
      new MVertex(lifted_sites[6 * i] * mesh_scale + mesh_center[0],
                  lifted_sites[6 * i + 1] * mesh_scale + mesh_center[1],
                  lifted_sites[6 * i + 2] * mesh_scale + mesh_center[2]);
    res_face->addMeshVertex(m_verts[i]);
  }
  for(std::size_t i = 0; i < rdt_triangles.size() / 3; ++i) {
    res_face->addTriangle(new MTriangle(m_verts[rdt_triangles[3 * i]],
                                        m_verts[rdt_triangles[3 * i + 1]],
                                        m_verts[rdt_triangles[3 * i + 2]]));
  }

  res_face->setAllElementsVisible(true);

  return v;
}

#endif
