#include <iostream>
#include <limits>
#include <cassert>
#include <algorithm>
#include <array>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "all.h"
#pragma omp declare reduction(vec_double_plus : std::vector<double> : \
        std::transform(omp_out.begin(), omp_out.end(), omp_in.begin(), omp_out.begin(), std::plus<double>())) \
        initializer(omp_priv = std::vector<double>(omp_orig.size(), 0))

using namespace UM;

#define EPS_FROM_THE_THEOREM 0

template <typename T> T square(T &number) { return number * number; }

void get_bbox(const PointSet &pts, vec3 &min, vec3 &max) {
    min = max = pts[0];
    for (auto const &p : pts) {
        for (int d : range(3)) {
            min[d] = std::min(min[d], p[d]);
            max[d] = std::max(max[d], p[d]);
        }
    }
}

double get_cell_average_edge_size(Volume &m) {
    double sum = 0;
    int nb = 0;
    for (int c : cell_iter(m))
        for (int lf : range(m.nfacets_per_cell()))
            for (int lv : range(m.facet_size(c, lf))) {
                int i = m.facet_vert(c, lf, lv);
                int j = m.facet_vert(c, lf, (lv+1)%m.facet_size(c, lf));
                sum += (m.points[i] - m.points[j]).norm();
                nb++;
            }
    assert(nb > 0);
    return sum / double(nb);
}

double tet_volume(const vec3 &A, const vec3 &B, const vec3 &C, const vec3 &D) {
    return ((A-D)*cross(B-D, C-D))/6.;
}

double tet_volume(const Tetrahedra &m, const int t) {
    return tet_volume(
            m.points[m.vert(t, 0)],
            m.points[m.vert(t, 1)],
            m.points[m.vert(t, 2)],
            m.points[m.vert(t, 3)]
            );
}

inline double chi(double eps, double det) {
    if (det>0)
        return (det + std::sqrt(eps*eps + det*det))*.5;
    return .5*eps*eps / (std::sqrt(eps*eps + det*det) - det);
}

inline double chi_deriv(double eps, double det) {
    return .5+det/(2.*std::sqrt(eps*eps + det*det));
}

struct Untangle3D {
    Untangle3D(Tetrahedra &mesh) : m(mesh), X(m.nverts()*3), lock(m.points), J(m), K(m), det(m) {
        scale();
        { // prepare the reference tetrahedron
            double volume = 0;
            for (int c : cell_iter(m)) {
                volume += tet_volume(m, c);
            }
            volume /= m.ncells();
            if (debug>0) std::cerr << "avg volume: " << volume << std::endl;

            Tetrahedra R; // regular tetrahedron with unit edge length, centered at the origin (sqrt(2)/12 volume)
            *R.points.data = {
                { .5,   0, -1./(2.*std::sqrt(2.))},
                {-.5,   0, -1./(2.*std::sqrt(2.))},
                {  0,  .5,  1./(2.*std::sqrt(2.))},
                {  0, -.5,  1./(2.*std::sqrt(2.))}
            };
            R.cells = {0,1,2,3};

            double a = std::cbrt(volume*6.*std::sqrt(2.));
            for (vec3 &p : R.points) // scale the tet
                p = p*a;

            for (int lf : range(4)) { // prepare the data for gradient processing: compute the normal vectors
                vec3 e0 = R.points[R.facet_vert(0, lf, 1)] - R.points[R.facet_vert(0, lf, 0)];
                vec3 e1 = R.points[R.facet_vert(0, lf, 2)] - R.points[R.facet_vert(0, lf, 0)];
                ref_tet[lf] = -(cross(e0, e1)/2.)/(3.*volume);
            }
        }

        { // mark the boundary verts
            VolumeConnectivity vec(m);
            for (int c : cell_iter(m))
                for (int lf : range(4))
                    if (vec.adjacent[m.facet(c, lf)]<0)
                        for (int lv : range(3))
                            lock[m.facet_vert(c, lf, lv)] = true;
        }
    }

    // normalize the mesh, place it well inside the [0,boxside]^2 square (max size will be boxside/shrink)
    void scale() {
        get_bbox(m.points, bbmin, bbmax);
        double maxside = std::max(bbmax.x-bbmin.x, bbmax.y-bbmin.y);
        for (vec3 &p : m.points)
            p = (p - (bbmax+bbmin)/2.)*boxsize/(shrink*maxside) + vec3(1,1,1)*boxsize/2;

        for (int v : vert_iter(m))
            for (int d : range(3))
                X[v*3+d] = m.points[v][d];
    }

    void restore_scale() {
        double maxside = std::max(bbmax.x-bbmin.x, bbmax.y-bbmin.y);
        for (int v : vert_iter(m)) {
            vec3 p = { X[v*3+0], X[v*3+1], X[v*3+2] };
            m.points[v] = (p - vec3(1,1,1)*boxsize/2)*shrink/boxsize*maxside +  (bbmax+bbmin)/2.;
        }
    }

    void evaluate_jacobian(const std::vector<double> &X) {
        if (debug>3) std::cerr << "evaluate the jacobian...";
        detmin = std::numeric_limits<double>::max();
        ninverted = 0;
#pragma omp parallel for reduction(min:detmin) reduction(+:ninverted)
        for (int c=0; c<m.ncells(); c++) {
            mat<3,3> &J = this->J[c];
            J = {};
            for (int i=0; i<4; i++)
                for (int d : range(3))
                    J[d] += ref_tet[i]*X[3*m.vert(c,i) + d];
            det[c] = J.det();
            detmin = std::min(detmin, det[c]);
            ninverted += (det[c]<=0);

            mat<3,3> &K = this->K[c];
            K = { // dual basis
                {{
                     J[1].y*J[2].z - J[1].z*J[2].y,
                     J[1].z*J[2].x - J[1].x*J[2].z,
                     J[1].x*J[2].y - J[1].y*J[2].x
                 },
                {
                    J[0].z*J[2].y - J[0].y*J[2].z,
                    J[0].x*J[2].z - J[0].z*J[2].x,
                    J[0].y*J[2].x - J[0].x*J[2].y
                },
                {
                    J[0].y*J[1].z - J[0].z*J[1].y,
                    J[0].z*J[1].x - J[0].x*J[1].z,
                    J[0].x*J[1].y - J[0].y*J[1].x
                }}
            };
        }
        if (debug>3) std::cerr << "ok" << std::endl;
    }

    double evaluate_energy(const std::vector<double> &X) {
        evaluate_jacobian(X);
        double E = 0;
#pragma omp parallel for reduction(+:E)
        for (int c=0; c<m.ncells(); c++) {
            double chi_ = chi(eps, det[c]);
            double f = (J[c][0]*J[c][0] + J[c][1]*J[c][1] + J[c][2]*J[c][2])/pow(chi_, 2./3.);
            double g = (1+square(det[c]))/chi_;
            E += (1-theta)*f + theta*g;
        }
        return E;
    }

    bool go() {
        evaluate_jacobian(X);
#if EPS_FROM_THE_THEOREM
        eps = 1.;
#else
        double e0 = 1e-3;
#endif

        for (int iter=0; iter<maxiter; iter++) {
            if (debug>0) std::cerr << "iteration #" << iter << std::endl;
#if !EPS_FROM_THE_THEOREM
            if (iter && iter%10==0 && e0>1e-8) e0 /= 2.;
            eps = detmin>0 ? e0 : std::sqrt(square(e0) + 0.04*square(detmin));
#endif
            if (debug>0) std::cerr << "E: " << evaluate_energy(X) << " eps: " << eps << " detmin: " << detmin << " ninv: " << ninverted << std::endl;

            const hlbfgs_optimizer::simplified_func_grad_eval func = [&](const std::vector<double>& X, double& F, std::vector<double>& G) {
                std::fill(G.begin(), G.end(), 0);
                F = evaluate_energy(X);
#pragma omp parallel for reduction(vec_double_plus:G)
                for (int t=0; t<m.ncells(); t++) {
                    mat<3,3> &a = this->J[t]; // tangent basis
                    mat<3,3> &b = this->K[t]; // dual basis
                    double c1 = chi(eps, det[t]);
                    double c2 = pow(c1, 2./3.);
                    double c3 = chi_deriv(eps, det[t]);

                    double f = (a[0]*a[0] + a[1]*a[1] + a[2]*a[2])/c2;
                    double g = (1+square(det[t]))/c1;

                    for (int dim : range(3)) {
                        vec3 dfda = a[dim]*(2./c2) - b[dim]*((2.*f*c3)/(3.*c1));
                        vec3 dgda = b[dim]*((2*det[t]-g*c3)/c1);

                        for (int i=0; i<4; i++) {
                            int v = m.vert(t,i);
                            if (!lock[v])
                                G[v*3+dim] += (dfda*(1.-theta) + dgda*theta)*ref_tet[i];
                        }
                    }
                }
            };

            double E_prev = evaluate_energy(X);

            hlbfgs_optimizer opt(func);
            opt.set_epsg(bfgs_threshold);
            opt.set_max_iter(bfgs_maxiter);
            opt.set_verbose(true);
            opt.optimize(X);

            double E = evaluate_energy(X);
#if EPS_FROM_THE_THEOREM
            double sigma = std::max(1.-E/E_prev, 1e-1);
            if (detmin>=0)
                eps *= (1-sigma);
            else
                eps *= 1 - (sigma*std::sqrt(square(detmin) + square(eps)))/(std::abs(detmin) + std::sqrt(square(detmin) + square(eps)));
#endif
            if  (detmin>0 && std::abs(E_prev - E)/E<1e-5) break;
        }

        if (debug>0) std::cerr << "E: " << evaluate_energy(X) << " detmin: " << detmin << " ninv: " << ninverted << std::endl;
        restore_scale();
        return !ninverted;
    }


    ////////////////////////////////
    // Untangle3D state variables //
    ////////////////////////////////

    // optimization input parameters
    Tetrahedra &m;          // the mesh to optimize
    double theta = 1./2.;   // the energy is (1-theta)*(shape energy) + theta*(area energy)
    int maxiter = 100;    // max number of outer iterations
    int bfgs_maxiter = 300; // max number of inner iterations
    double bfgs_threshold = .1;

    int debug = 1;          // verbose level
    vec3 ref_tet[4] = {};   // reference tetrahedron: array of 4 normal vectors to compute the gradients

    // optimization state variables

    std::vector<double> X;     // current geometry
    PointAttribute<bool> lock; // currently lock = boundary vertices
    CellAttribute<mat<3,3>> J; // per-tet Jacobian matrix = [[JX.x JX.y, JX.z], [JY.x, JY.y, JY.z], [JZ.x, JZ.y, JZ.z]]
    CellAttribute<mat<3,3>> K; // per-tet dual basis: det J = dot J[i] * K[i]
    CellAttribute<double> det; // per-tet determinant of the Jacobian matrix
    double eps;       // regularization parameter, depends on min(jacobian)

    double detmin;    // min(jacobian) over all tetrahedra
    int ninverted; // number of inverted tetrahedra

    vec3 bbmin, bbmax; // these are used to undo the scaling we apply to the model
    const double boxsize = 10.;
    const double shrink  = 1.3;
};

int untangle3dTet(std::vector<double>& verts,
		  std::vector<int>& tets, int nitermax) {

  Tetrahedra m = Tetrahedra();
  m.points.create_points(verts.size());
  for(size_t v = 0; v< verts.size();v++) m.points[v] = {verts[3*v], verts[3*v+1], verts[3*v+2]} ;
  m.create_cells(tets.size() / 4);
  for(size_t t = 0; t< m.ncells();t++){
    //    for(size_t tv = 0; tv< 4;tv++)
    m.vert(t, 0) = tets[4 * t + 0];
    m.vert(t, 1) = tets[4 * t + 1];
    m.vert(t, 2) = tets[4 * t + 3];
    m.vert(t, 3) = tets[4 * t + 2];
  }
  
  { // ascertain the mesh requirements
    double volume = 0;
    for (int c : cell_iter(m))
      volume += tet_volume(m, c);
    volume /= m.ncells();
    if (volume<=0) {
      std::cerr << "Error: the input mesh must have positive volume" << std::endl;
      return 1;
    }
  }

  Untangle3D opt(m);

  opt.maxiter = nitermax;
  
  bool success = opt.go();
  for(size_t v = 0; v< verts.size();v++) {      
    verts[3*v]   =  m.points[v][0];
    verts[3*v+1] =  m.points[v][1];
    verts[3*v+2] =  m.points[v][2];
  }

  if (success)
    return 0;
  else
    return -1;
}


/*
int main(int argc, char** argv) {
    if (2>argc) {
        std::cerr << "Usage: " << argv[0] << " model.mesh [result.mesh]" << std::endl;
        return 1;
    }
    std::string res_filename = "result.mesh";
    if (3<=argc) {
        res_filename = std::string(argv[2]);
    }

    Tetrahedra m;
    read_by_extension(argv[1], m);
    std::cerr << "Untangling " << argv[1] << "," << m.nverts() << "," << std::endl;

    { // ascertain the mesh requirements
        double volume = 0;
        for (int c : cell_iter(m))
            volume += tet_volume(m, c);
        volume /= m.ncells();
        if (volume<=0) {
            std::cerr << "Error: the input mesh must have positive volume" << std::endl;
            return 1;
        }
    }

    Untangle3D opt(m);

    auto t1 = std::chrono::high_resolution_clock::now();
    bool success = opt.go();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = t2 - t1;

    if (success)
        std::cerr << "SUCCESS; running time: " << time.count() << " s; min det J = " << opt.detmin << std::endl;
    else
        std::cerr << "FAIL TO UNTANGLE!" << std::endl;

    write_by_extension(res_filename, m, VolumeAttributes{ { {"selection", opt.lock.ptr} }, { {"det", opt.det.ptr} }, {}, {} });
    return 0;
}
*/
