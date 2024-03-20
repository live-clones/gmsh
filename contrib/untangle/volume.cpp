#include <iostream>
#include <algorithm>
#include <cassert>
#include "volume.h"
#include "attributes.h"

namespace UM {
    void compute_corner_to_corner_map(const Volume &m, std::vector<int> &v2c, std::vector<int> &c2c);

    void Volume::resize_attrs() {
        for (auto &wp : attr_cells)   if (auto spt = wp.lock())
            spt->resize(ncells());
        for (auto &wp : attr_facets)  if (auto spt = wp.lock())
            spt->resize(nfacets());
        for (auto &wp : attr_corners) if (auto spt = wp.lock())
            spt->resize(ncorners());
    }

    void Volume::compress_attrs(const std::vector<bool> &cells_to_kill) {
        assert(cells_to_kill.size()==(size_t)ncells());
        std::vector<int>   cells_old2new(ncells(),   -1);
        std::vector<int>  facets_old2new(nfacets(),  -1);
        std::vector<int> corners_old2new(ncorners(), -1);

        int new_nb_cells   = 0;
        int new_nb_facets  = 0;
        int new_nb_corners = 0;

        for (int c=0; c<ncells(); c++) {
            if (cells_to_kill[c]) continue;
            for (int lf=0; lf<nfacets_per_cell(); lf++)
                facets_old2new[facet(c, lf)] = new_nb_facets++;
            for (int lv=0; lv<nverts_per_cell(); lv++)
                corners_old2new[corner(c, lv)] = new_nb_corners++;
            cells_old2new[c] = new_nb_cells++;
        }

        std::cerr << "compressing cell attributes\n";
        for (auto &wp : attr_cells)   if (auto spt = wp.lock())
            spt->compress(cells_old2new);
        std::cerr << "compressing facet attributes\n";
        for (auto &wp : attr_facets)  if (auto spt = wp.lock())
            spt->compress(facets_old2new);
        std::cerr << "compressing corner attributes\n";
        for (auto &wp : attr_corners) if (auto spt = wp.lock())
            spt->compress(corners_old2new);
    }

    void Volume::delete_cells(const std::vector<bool> &to_kill) {
        assert(to_kill.size()==(size_t)ncells());
        compress_attrs(to_kill);

        int new_nb_cells   = 0;
        int new_nb_corners = 0;
        for (int c=0; c<ncells(); c++) {
            if (to_kill[c]) continue;
            for (int lv=0; lv<nverts_per_cell(); lv++)
                cells[new_nb_corners++] = vert(c, lv);
            ++new_nb_cells;
        }
        cells.resize(new_nb_corners);
    }

    void Volume::delete_vertices(const std::vector<bool> &to_kill) {
        assert(to_kill.size()==(size_t)nverts());
        std::vector<bool> cells_to_kill(ncells(), false);

        std::vector<int> c2c, v2c;
        compute_corner_to_corner_map(*this, v2c, c2c);

        for (int v=0; v<nverts(); v++) {
            if (!to_kill[v]) continue;
            int cir = v2c[v];
            if (cir<0) continue; // isolated vertex
            do {
                cells_to_kill[cir/nverts_per_cell()] = true;
                cir = c2c[cir];
            } while (cir != v2c[v]);
        }
        delete_cells(cells_to_kill);

        std::vector<int> old2new;
        points.delete_points(to_kill, old2new);
        for (int &v : cells)
            v = old2new[v];
    }

    int Volume::create_cells(const int n) {
        assert(n>0);
        cells.resize(cells.size()+n*nverts_per_cell());
        resize_attrs();
        return ncells()-n;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool are_facets_adjacent(const Volume &m, int c1, int c2, int lf1, int lf2) {
        int n = m.facet_size(c1, lf1);
        if (n!=m.facet_size(c2, lf2)) return false;

        for (int i=0; i<n; i++) {
            bool found = true;
            for (int j=0; found && j<n; j++)
                found = (m.facet_vert(c1, lf1, (i+j)%n) == m.facet_vert(c2, lf2, n-j-1));
            if (found) return true;
        }

        return false;
    }

    VolumeConnectivity::VolumeConnectivity(const Volume &p_m) : m(p_m), adjacent(m.nfacets(), -1) {
        std::vector<int> c2c, v2c;
        compute_corner_to_corner_map(m, v2c, c2c);

        for (int c1=0; c1<m.ncells(); c1++)
            for (int lf1=0; lf1<m.nfacets_per_cell(); lf1++) {
                int f1 = m.facet(c1, lf1);
                if (adjacent[f1]>=0) continue;
                int crn1 = v2c[m.facet_vert(c1, lf1, 0)];
                int crn2 = crn1;
                do {
                    int c2 = crn2 / m.nverts_per_cell();
                    if (c2!=c1) {
                        for (int lf2=0; lf2<m.nfacets_per_cell(); lf2++) {
                            if (!are_facets_adjacent(m, c1, c2, lf1, lf2)) continue;
                            int f2 = m.facet(c2, lf2);
                            adjacent[f1] = f2;
                            adjacent[f2] = f1;
                        }
                    }
                    crn2 = c2c[crn2];
                } while (crn2!=crn1 && adjacent[f1]<0);
            }
    }

    void compute_corner_to_corner_map(const Volume &m, std::vector<int> &v2c, std::vector<int> &c2c) {
        c2c = std::vector<int>(m.ncorners(), -1);
        v2c = std::vector<int>(m.nverts(),   -1);

        // compute vertex-to-cell-corner map
        for (int c=0; c<m.ncells(); c++)
            for (int lv=0; lv<m.nverts_per_cell(); lv++)
                v2c[m.vert(c, lv)] = m.corner(c, lv);

        // chain cell corners around vertices
        for (int c=0; c<m.ncells(); c++)
            for (int lv=0; lv<m.nverts_per_cell(); lv++) {
                int crn = m.corner(c, lv);
                int v = m.vert(c, lv);
                c2c[crn] = v2c[v];
                v2c[v] = crn;
            }
    }
}

