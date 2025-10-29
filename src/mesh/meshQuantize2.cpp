#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <limits>
#include <numeric>
#include <unordered_map>
#include "gmsh.h"

using namespace std;

// -------- GF(2) bit-matrix --------
struct GF2Matrix {
    int rows = 0, cols = 0, W = 0;    // W = number of 64-bit words per row
    vector<vector<uint64_t>> a;       // a[r][w]

    GF2Matrix(int r=0, int c=0) { reset(r,c); }
    void reset(int r, int c) {
        rows = r; cols = c; W = (cols + 63) / 64;
        a.assign(rows, vector<uint64_t>(W, 0));
    }
    static inline void setbit(vector<uint64_t>& row, int j) {
        row[j >> 6] |= (uint64_t)1 << (j & 63);
    }
    static inline int getbit(const vector<uint64_t>& row, int j) {
        return (row[j >> 6] >> (j & 63)) & 1ULL;
    }
    static inline void xorrow(vector<uint64_t>& dst, const vector<uint64_t>& src) {
        for (size_t k = 0; k < dst.size(); ++k) dst[k] ^= src[k];
    }
};

struct GF2SolveWeightedResult {
    bool ok = false;
    vector<int> z;                 // particular solution over all columns (0/1)
    vector<vector<int>> kernel;    // null-space basis (vectors 0/1 of length m)
};

// Gaussian elimination on permuted columns; pivots only on allowed columns (U)
static GF2SolveWeightedResult solve_gf2_with_kernel(const GF2Matrix& A_in,
                                                    const vector<int>& b_in,
                                                    const vector<int>& perm,    // old -> new
                                                    const vector<int>& invperm, // new -> old
                                                    const vector<int>& col_is_in_U)
{
    int n = A_in.rows, m = A_in.cols;
    GF2Matrix A = A_in;
    vector<int> b = b_in;

    // Apply column permutation
    GF2Matrix Ap(n, m);
    for (int r = 0; r < n; ++r) {
        for (int oldc = 0; oldc < m; ++oldc) {
            if (GF2Matrix::getbit(A.a[r], oldc)) {
                int newc = perm[oldc];
                GF2Matrix::setbit(Ap.a[r], newc);
            }
        }
    }
    A = std::move(Ap);

    vector<int> where(m, -1);
    int row = 0;
    for (int col = 0; col < m && row < n; ++col) {
        // only pivot on columns permitted in U (unlocked)
        if (!col_is_in_U[ invperm[col] ]) continue;

        int sel = -1;
        for (int i = row; i < n; ++i) {
            if (GF2Matrix::getbit(A.a[i], col)) { sel = i; break; }
        }
        if (sel == -1) continue;

        if (sel != row) {
            swap(A.a[sel], A.a[row]);
            swap(b[sel], b[row]);
        }
        for (int i = 0; i < n; ++i) {
            if (i != row && GF2Matrix::getbit(A.a[i], col)) {
                GF2Matrix::xorrow(A.a[i], A.a[row]);
                b[i] ^= b[row];
            }
        }
        where[col] = row;
        ++row;
    }
    int rank = row;

    // Check consistency: all-zero A row => b must be 0
    for (int i = rank; i < n; ++i) {
        bool allzero = true;
        for (int w = 0; w < A.W; ++w) if (A.a[i][w]) { allzero = false; break; }
        if (allzero && b[i]) return {false, {}, {}};
    }

    // Particular solution (free vars = 0), in permuted order
    vector<int> z_perm(m, 0);
    for (int col = 0; col < m; ++col) {
        if (where[col] != -1) {
            int r = where[col];
            z_perm[col] = b[r] & 1;
        }
    }

    // Null space basis (permuted order): for each free column
    vector<vector<int>> kernel_perm;
    for (int free_col = 0; free_col < m; ++free_col) {
        if (where[free_col] != -1) continue; // not free
        vector<int> k(m, 0);
        k[free_col] = 1;
        for (int col = 0; col < m; ++col) {
            int r = where[col];
            if (r != -1) {
                if (GF2Matrix::getbit(A.a[r], free_col)) k[col] ^= 1;
            }
        }
        kernel_perm.push_back(std::move(k));
    }

    // Un-permute back to original column order
    vector<int> z(m, 0);
    for (int oldc = 0; oldc < m; ++oldc) z[oldc] = z_perm[ perm[oldc] ];

    vector<vector<int>> kernel;
    kernel.reserve(kernel_perm.size());
    for (auto& kp : kernel_perm) {
        vector<int> kg(m, 0);
        for (int oldc = 0; oldc < m; ++oldc) kg[oldc] = kp[ perm[oldc] ];
        kernel.push_back(std::move(kg));
    }

    return {true, z, kernel};
}

struct Solution {
    vector<int> n;   // final nonnegative solution
    bool ok = false;
    int flips = 0;   // Hamming weight of z
    double cost = 0.0; // sum w_i z_i
};

// decreasing weights in N; lock if N<=1 by returning +inf
static inline double weight_from_N(int Ni) {
    if (Ni <= 1) return std::numeric_limits<double>::infinity(); // locked
    return 1.0 / double(Ni); // simple decreasing rule
}

Solution compute_weighted_even_faces(const vector<int>& N,
                                     const vector<vector<int>>& faces)
{
    const int m = (int)N.size();
    const int f = (int)faces.size();

    // Build A and b = A*N mod 2
    GF2Matrix A(f, m);
    vector<int> b(f, 0);
    for (int j = 0; j < f; ++j) {
        int sum = 0;
        for (int i : faces[j]) {
            if (i < 0 || i >= m) continue;
            GF2Matrix::setbit(A.a[j], i);
            sum ^= (N[i] & 1);
        }
        b[j] = sum & 1;
    }

    // Locks and weights
    vector<int> locked(m, 0);
    vector<double> w(m, 0.0);
    for (int i = 0; i < m; ++i) {
        w[i] = weight_from_N(N[i]);
        if (!isfinite(w[i])) locked[i] = 1; // N_i in {0,1}
    }

    // Columns allowed for pivoting: U = not locked
    vector<int> col_is_in_U(m, 0);
    for (int i = 0; i < m; ++i) col_is_in_U[i] = !locked[i];

    // Column ordering: unlocked by increasing weight; locked last
    vector<int> order(m); iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](int a, int b){
        if (locked[a] != locked[b]) return locked[a] < locked[b];
        return w[a] < w[b];
    });
    vector<int> perm(m, 0), invperm(m, 0);
    for (int newc = 0; newc < m; ++newc) {
        int oldc = order[newc];
        perm[oldc] = newc;
        invperm[newc] = oldc;
    }

    // Solve and get kernel
    auto res = solve_gf2_with_kernel(A, b, perm, invperm, col_is_in_U);
    if (!res.ok) return {{}, false, 0, 0.0};

    // Apply locks: force z_i = 0 for locked
    vector<int> z = res.z;
    for (int i = 0; i < m; ++i) if (locked[i]) z[i] = 0;

    auto weighted_cost = [&](const vector<int>& zvec)->double{
        double c = 0.0;
        for (int i = 0; i < m; ++i) if (zvec[i]) c += w[i];
        return c;
    };
    double bestCost = weighted_cost(z);

    // Greedy improvement in kernel space
    bool improved = true;
    while (improved) {
        improved = false;
        for (const auto& k : res.kernel) {
            bool touches_locked = false;
            for (int i = 0; i < m; ++i) if (k[i] && locked[i]) { touches_locked = true; break; }
            if (touches_locked) continue;

            double delta = 0.0;
            for (int i = 0; i < m; ++i) if (k[i]) delta += (z[i] ? -w[i] : +w[i]);
            if (delta < -1e-15) {
                for (int i = 0; i < m; ++i) if (k[i]) z[i] ^= 1;
                bestCost += delta;
                improved = true;
            }
        }
    }

    // Reconstruct n with non-negativity
    vector<int> n = N;
    int flips = 0;
    for (int i = 0; i < m; ++i) {
        if (!z[i]) continue;
        ++flips;
        if (N[i] > 0) n[i] = N[i] - 1;   // prefer flipping down if possible
        else          n[i] = 1;          // N[i]==0 -> flip up to 1
    }

    return {n, true, flips, bestCost};
}

// ------------- Example main -------------


// Remplit `faces` (faces -> indices de courbes [0..m-1]) et `N` (#elts 1D par courbe)
void quantizeCurvesForEvenSurfaceSubdivision ( vector<int> &curveTags, vector<int> &N) {
    // --- 1. Lister toutes les surfaces (dim=2) et toutes les courbes (dim=1)
  vector<vector<int>> faces;
  gmsh::initialize();
  vector<pair<int,int>> surfaces, curves;
  gmsh::model::getEntities(surfaces, 2);
  gmsh::model::getEntities(curves,   1);
  
  //    printf("%lu %lu\n",surfaces.size(),curves.size());
  
  // --- 2. Map tag de courbe -> index compact [0..m-1]
  //  vector<int> curveTags;
  curveTags.reserve(curves.size());
  for (const auto &c : curves) curveTags.push_back(c.second);
  
  unordered_map<int,int> tag2idx;
  tag2idx.reserve(curveTags.size());
  for (size_t i = 0; i < curveTags.size(); ++i) tag2idx[curveTags[i]] = (int)i;
  
  // --- 3. faces: pour chaque surface, récupérer le bord "courbes" (dim=1)
  faces.clear();
  faces.reserve(surfaces.size());
  for (const auto &s : surfaces) {
    vector<pair<int,int>> boundary;
    // combined=true (pas de doublons), oriented=false, recursive=false
    gmsh::model::getBoundary({s}, boundary);
    //    printf("face %d %lu bnd\n",s.second,boundary.size());
    vector<int> f;
    f.reserve(boundary.size());
    for (const auto &b : boundary) {
      //      printf("%d ",b.second);
      if (b.first != 1) continue; // on ne garde que les entités 1D
      auto it = tag2idx.find(std::abs(b.second));
      if (it != tag2idx.end()) f.push_back(it->second);
    }
    //    printf("\n");
    faces.push_back(std::move(f));
  }
  
  // --- 4. N_i = nombre d'éléments 1D maillés sur la courbe i
  // NB: on additionne tous les types 1D retournés (2-node, 3-node, 4-node lines, etc.)
  N.assign((int)curveTags.size(), 0);
  
  for (size_t i = 0; i < curveTags.size(); ++i) {
    int ctag = curveTags[i];
    
    // Ces conteneurs seront remplis par Gmsh (par type d'élément)
    vector<int> elemTypes;
    vector<vector<std::size_t>> elemTags, nodeTags;
    
    gmsh::model::mesh::getElements(elemTypes, elemTags, nodeTags,
				   /*dim=*/1, /*tag=*/ctag);
    
    std::size_t count = 0;
    for (const auto &etags : elemTags) count += etags.size();
    
    N[i] = static_cast<int>(count);
  }

  //  for (auto l : faces){
  //    for (auto e : l){
  //      printf("(%d,%d) ",e,curveTags[e]);
  //    }
  //    printf("\n");
  //  }
  
  auto sol = compute_weighted_even_faces(N, faces);
  std::cout << "Flips: " << sol.flips << "\n";
  std::cout << "Weighted cost: " << sol.cost << "\n";
  N = sol.n;    
}
/*
int main(int argc, char **argv) {
    gmsh::initialize();
    // Ouvrir un modèle déjà maillé en 1D (ou qui contient un maillage de courbes)
    gmsh::open(argv[1]);
    gmsh::model::occ::synchronize();

    // (Optionnel) Si vous n’êtes pas sûr que les courbes sont maillées,
    // décommentez la ligne suivante pour générer le 1D :
    // gmsh::model::mesh::generate(1);

    vector<vector<int>> faces;
    vector<int> N;
    buildFacesAndN(faces, N);


    auto sol = compute_weighted_even_faces(N, faces);

    if(!sol.ok){
        std::cerr << "No feasible solution under current locks.\n";
        gmsh::finalize();
        return 1;
    }

    std::cout << "Flips: " << sol.flips << "\n";
    std::cout << "Weighted cost: " << sol.cost << "\n";
    std::cout << "N = [";
    for(size_t i=0;i<sol.n.size();++i){ if(i) std::cout << ", "; std::cout << N[i]; }
    std::cout << "]\n";
    std::cout << "n = [";
    for(size_t i=0;i<sol.n.size();++i){ if(i) std::cout << ", "; std::cout << sol.n[i]; }
    std::cout << "]\n";

    
    // // Affichage rapide
    // std::cout << "Curves (m): " << N.size() << "\n";
    // for (size_t i = 0; i < N.size(); ++i) {
    //     std::cout << "  curve #" << i << " -> N_i=" << N[i] << "\n";
    // }
    // std::cout << "Faces (f): " << faces.size() << "\n";
    // for (size_t j = 0; j < faces.size(); ++j) {
    //     std::cout << "  face #" << j << " :";
    //     for (int cid : faces[j]) std::cout << " " << cid;
    //     std::cout << "\n";
    // }

    gmsh::finalize();
    return 0;
}
*/
