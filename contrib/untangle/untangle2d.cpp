#include <iostream>
#include <limits>
#include <cassert>
#include <algorithm>
#include <array>
#include <chrono>
#include <sstream>
#include <iomanip>

#include <ultimaille/all.h>
#pragma omp declare reduction(vec_double_plus : std::vector<double> : \
        std::transform(omp_out.begin(), omp_out.end(), omp_in.begin(), omp_out.begin(), std::plus<double>())) \
        initializer(omp_priv = std::vector<double>(omp_orig.size(), 0))

using namespace UM;

#define EPS_FROM_THE_THEOREM 0

double get_average_edge_size(Surface &m) {
    double sum = 0;
    int nb = 0;
    for (int f : facet_iter(m))
        for (int i : facet_vert_iter(m, f)) {
            int j = m.vert(f, (i+1)%m.facet_size(f));
            sum += (m.points[i] - m.points[j]).norm();
            nb++;
        }
    assert(nb > 0);
    return sum / double(nb);
}

template <typename T> auto square(const T &number) { return number * number; }

double triangle_area_3d(Triangles &m, int f) {
    vec3 eij = m.points[m.vert(f, 1)] - m.points[m.vert(f, 0)];
    vec3 eik = m.points[m.vert(f, 0)] - m.points[m.vert(f, 2)];
    return 0.5*cross(eij, eik).norm();
}

double facet_area_2d(Surface &m, int f) {
    double area = 0;
    for (int v=0; v<m.facet_size(f); v++) {
        vec3 a = m.points[m.vert(f, v)];
        vec3 b = m.points[m.vert(f, (v+1)%m.facet_size(f))];
        area += (b.y-a.y)*(b.x+a.x)/2;
    }
    return area;
}

double triangle_area_2d(vec2 a, vec2 b, vec2 c) {
    return .5*((b.y-a.y)*(b.x+a.x) + (c.y-b.y)*(c.x+b.x) + (a.y-c.y)*(a.x+c.x));
}

double triangle_aspect_ratio_2d(vec2 a, vec2 b, vec2 c) {
    double l1 = (b-a).norm();
    double l2 = (c-b).norm();
    double l3 = (a-c).norm();
    double lmax = std::max(l1, std::max(l2, l3));
    return lmax*(l1+l2+l3)/(4.*std::sqrt(3.)*triangle_area_2d(a, b, c));
}

double project_triangle(const vec3& p0, const vec3& p1, const vec3& p2, vec2& z0, vec2& z1, vec2& z2) {
    vec3 X = (p1 - p0).normalize(); // construct an orthonormal 3d basis
    vec3 Z = cross(X, p2 - p0).normalize();
    vec3 Y = cross(Z, X);

    z0 = vec2(0,0); // project the triangle to the 2d basis (X,Y)
    z1 = vec2((p1 - p0).norm(), 0);
    z2 = vec2((p2 - p0)*X, (p2 - p0)*Y);
    return triangle_area_2d(z0, z1, z2);
}

inline double chi(double eps, double det) {
    if (det>0)
        return (det + std::sqrt(eps*eps + det*det))*.5;
    return .5*eps*eps / (std::sqrt(eps*eps + det*det) - det);
}

inline double chi_deriv(double eps, double det) {
    return .5+det/(2.*std::sqrt(eps*eps + det*det));
}

struct Untangle2D {
    Untangle2D(Triangles &mesh) : m(mesh), X(m.nverts()*2), lock(m.points), ref_tri(m), J(m), K(m), det(m) {
    }

    void lock_boundary() {
        SurfaceConnectivity fec(m);
        for (int v : vert_iter(m))
            lock[v] = fec.is_boundary_vert(v);
    }

    // normalize the mesh, place it well inside the [0,boxside]^2 square (max size will be boxside/shrink)
    void scale() {
        bbmin = bbmax = {X[0], X[1]};
        for (int v : vert_iter(m)) {
             for (int d : range(2)) {
                bbmin[d] = std::min(bbmin[d], X[v*2+d]);
                bbmax[d] = std::max(bbmax[d], X[v*2+d]);
            }
        }
        double maxside = std::max(bbmax.x-bbmin.x, bbmax.y-bbmin.y);
        for (int v : vert_iter(m))
            for (int d : range(2))
                X[v*2+d] = (X[v*2+d] - (bbmax[d]+bbmin[d])/2.)*boxsize/(shrink*maxside) + boxsize/2.;
    }

    void restore_scale() {
        double maxside = std::max(bbmax.x-bbmin.x, bbmax.y-bbmin.y);
        for (int v : vert_iter(m))
            for (int d : range(2))
                X[v*2+d] = (X[v*2+d] - boxsize/2.)*shrink/boxsize*maxside + (bbmax[d]+bbmin[d])/2.;
    }

    void evaluate_jacobian(const std::vector<double> &X) {
        if (debug>3) std::cerr << "evaluate the jacobian...";
        detmin = std::numeric_limits<double>::max();
        ninverted = 0;
#pragma omp parallel for reduction(min:detmin) reduction(+:ninverted)
        for (int t=0; t<m.nfacets(); t++) {
            mat<2,2> &J = this->J[t];
            J = {};
            for (int i=0; i<3; i++)
                for (int d : range(2))
                    J[d] += ref_tri[t][i]*X[2*m.vert(t,i) + d];
            det[t] = J.det();
            detmin = std::min(detmin, det[t]);
            ninverted += (det[t]<=0);

            mat<2,2> &K = this->K[t];
            K = { // dual basis
                {{
                     +J[1].y,
                     -J[1].x
                 },
                {
                    -J[0].y,
                    +J[0].x
                }}
            };
        }
        if (debug>3) std::cerr << "ok" << std::endl;
    }

    double evaluate_energy(const std::vector<double> &X) {
        evaluate_jacobian(X);
        double E = 0;
#pragma omp parallel for reduction(+:E)
        for (int t=0; t<m.nfacets(); t++) {
            double chi_ = chi(eps, det[t]);
            double f = (square(J[t][0]) + square(J[t][1]))/chi_;
            double g = (1+square(det[t]))/chi_;
            E += (1.-theta)*f + theta*g;
        }
        return E;
    }

    bool go() {
        scale();
        { // prepare the reference geometery
            double target_area = 0;
            double source_area = 0;
            for (int t : facet_iter(m)) {
                vec2 a = {X[m.vert(t, 0)*2+0], X[m.vert(t, 0)*2+1]};
                vec2 b = {X[m.vert(t, 1)*2+0], X[m.vert(t, 1)*2+1]};
                vec2 c = {X[m.vert(t, 2)*2+0], X[m.vert(t, 2)*2+1]};
                target_area += triangle_area_2d(a, b, c);
                source_area += triangle_area_3d(m, t);
            }
            if (debug>0) std::cerr << "source area: " << source_area << std::endl;
            if (debug>0) std::cerr << "target area: " << target_area << std::endl;
            if (target_area<=0) {
                std::cerr << "Error: the target area must be positive" << std::endl;
                return false;
            }
            for (int t : facet_iter(m)) {
                double area = target_area/m.nfacets();
                double a = std::sqrt(4*area/std::sqrt(3.));
                mat<3,2> equi_tri = mat<3,2>{{ {0,-1}, {std::sqrt(3.)/2.,.5}, {-std::sqrt(3.)/2.,.5} }}*a / (-2*area) ; // equilateral triangle with unit side length (sqrt(3)/4 area): three non-unit normal vectors
                ref_tri[t] = equi_tri;
            }
        }

        evaluate_jacobian(X);
#if EPS_FROM_THE_THEOREM
        eps = 1.;
#else
        double e0 = 1e-3;
#endif

        for (int iter=0; iter<maxiter; iter++) {
            if (debug>0) std::cerr << "iteration #" << iter << std::endl;
#if !EPS_FROM_THE_THEOREM
            if (iter && iter%10==0 && e0>1e-10) e0 /= 2.;
            eps = detmin>0 ? e0 : std::sqrt(square(e0) + 0.04*square(detmin));
#endif
            if (debug>0) std::cerr << "E: " << evaluate_energy(X) << " eps: " << eps << " detmin: " << detmin << " ninv: " << ninverted << std::endl;

            const hlbfgs_optimizer::simplified_func_grad_eval func = [&](const std::vector<double>& X, double& F, std::vector<double>& G) {
                std::fill(G.begin(), G.end(), 0);
                F = evaluate_energy(X);
#pragma omp parallel for reduction(vec_double_plus:G)
                for (int t=0; t<m.nfacets(); t++) {
                    double c1 = chi(eps, det[t]);
                    double c2 = chi_deriv(eps, det[t]);

                    double f = (square(J[t][0]) + square(J[t][1]))/c1;
                    double g = (1+square(det[t]))/c1;

                    for (int dim : range(2)) {
                        vec2 a = J[t][dim]; // tangent basis
                        vec2 b = K[t][dim]; // dual basis
                        vec2 dfda = (a*2. - b*f*c2)/c1;
                        vec2 dgda = b*(2*det[t]-g*c2)/c1;
                        for (int i=0; i<3; i++) {
                            int v = m.vert(t,i);
                            if (!lock[v])
                                G[v*2+dim] += (dfda*(1.-theta) + dgda*theta)*ref_tri[t][i];
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
    // Untangle2D state variables //
    ////////////////////////////////

    // optimization input parameters
    Triangles &m;           // the mesh to optimize
    double theta = 1./128.; // the energy is (1-theta)*(shape energy) + theta*(area energy)
    int maxiter = 10000;    // max number of outer iterations
    double bfgs_threshold = .1;
    int bfgs_maxiter = 30000; // max number of inner iterations

    int debug = 1;          // verbose level

    // optimization state variables

    std::vector<double> X;     // current geometry
    PointAttribute<bool> lock; // currently lock = boundary vertices
    FacetAttribute<mat<3,2>> ref_tri;
    FacetAttribute<mat<2,2>> J; // per-tet Jacobian matrix = [[JX.x JX.y, JX.z], [JY.x, JY.y, JY.z], [JZ.x, JZ.y, JZ.z]]
    FacetAttribute<mat<2,2>> K; // per-tet dual basis: det J = dot J[i] * K[i]
    FacetAttribute<double> det; // per-tet determinant of the Jacobian matrix
    double eps;       // regularization parameter, depends on min(jacobian)

    double detmin;    // min(jacobian) over all tetrahedra
    int ninverted; // number of inverted tetrahedra

    vec2 bbmin, bbmax; // these are used to undo the scaling we apply to the model
    const double boxsize = 10.;
    const double shrink  = 1.3;
};

int main(int argc, char** argv) {
    if (2>argc) {
        std::cerr << "Usage: " << argv[0] << " model.mesh [result.mesh]" << std::endl;
        return 1;
    }
    std::string res_filename = "result.mesh";
    if (3<=argc) {
        res_filename = std::string(argv[2]);
    }

    Triangles m;
    SurfaceAttributes attr = read_by_extension(argv[1], m);
    std::cerr << "Untangling " << argv[1] << "," << m.nverts() << "," << std::endl;
    PointAttribute<vec2> tex_coord("tex_coord", attr, m);

    Untangle2D opt(m);

    for (int v : vert_iter(m))
        for (int d : range(2))
            opt.X[2*v+d] = tex_coord[v][d];

    opt.lock_boundary();

    auto t1 = std::chrono::high_resolution_clock::now();
    bool success = opt.go();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = t2 - t1;

    if (success)
        std::cerr << "SUCCESS; running time: " << time.count() << " s; min det J = " << opt.detmin << std::endl;
    else
        std::cerr << "FAIL TO UNTANGLE!" << std::endl;

    for (int v : vert_iter(m)) {
        for (int d : range(2))
            m.points[v][d] = opt.X[2*v+d];
        m.points[v].z = 0;
    }

    write_by_extension(res_filename, m, SurfaceAttributes{ { {"selection", opt.lock.ptr} }, { {"det", opt.det.ptr} }, {} });
    return 0;
}

