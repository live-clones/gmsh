#include <iostream>
#include <algorithm>
#include <cassert>
#include "surface.h"
#include "attributes.h"

namespace UM {
    void Surface::resize_attrs() {
        for (auto &wp : attr_facets)  if (auto spt = wp.lock())
            spt->resize(nfacets());
        for (auto &wp : attr_corners) if (auto spt = wp.lock())
            spt->resize(ncorners());
    }

    void Surface::compress_attrs(const std::vector<bool> &facets_to_kill) {
        assert(facets_to_kill.size()==(size_t)nfacets());
        std::vector<int>  facets_old2new(nfacets(),  -1);
        std::vector<int> corners_old2new(ncorners(), -1);

        int new_nb_facets  = 0;
        int new_nb_corners = 0;

        for (int f=0; f<nfacets(); f++) {
            if (facets_to_kill[f]) continue;
            for (int lv=0; lv<facet_size(f); lv++)
                corners_old2new[corner(f, lv)] = new_nb_corners++;
            facets_old2new[f] = new_nb_facets++;
        }
        std::cerr << "compressing facet attributes\n";
        for (auto &wp : attr_facets)  if (auto spt = wp.lock())
            spt->compress(facets_old2new);
        std::cerr << "compressing corner attributes\n";
        for (auto &wp : attr_corners) if (auto spt = wp.lock())
            spt->compress(corners_old2new);
    }

    void Surface::delete_vertices(const std::vector<bool> &to_kill) {
        assert(to_kill.size()==(size_t)nverts());
        std::vector<bool> facets_to_kill(nfacets(), false);
        SurfaceConnectivity fec(*this);

        for (int v=0; v<nverts(); v++) {
            if (!to_kill[v]) continue;
            int cir = fec.v2c[v];
            if (cir<0) continue; // isolated vertex
            do {
                facets_to_kill[fec.c2f[cir]] = true;
                cir = fec.c2c[cir];
            } while (cir != fec.v2c[v]);
        }
        delete_facets(facets_to_kill);

        std::vector<int> old2new;
        points.delete_points(to_kill, old2new);
        for (int &v : facets)
            v = old2new[v];
    }

    void Surface::delete_facets(const std::vector<bool> &to_kill) {
        assert(to_kill.size()==(size_t)nfacets());
        compress_attrs(to_kill);

        int new_nb_facets  = 0;
        int new_nb_corners = 0;
        for (int f=0; f<nfacets(); f++) {
            if (to_kill[f]) continue;
            for (int lv=0; lv<facet_size(f); lv++)
                facets[new_nb_corners++] = vert(f, lv);
            ++new_nb_facets;
        }
        facets.resize(new_nb_corners);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    int Triangles::create_facets(const int n) {
        facets.resize(facets.size()+n*3);
        resize_attrs();
        return nfacets()-n;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    int Quads::create_facets(const int n) {
        facets.resize(facets.size()+n*4);
        resize_attrs();
        return nfacets()-n;
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    Polygons::Polygons() : Surface(), offset(1, 0) {}

    int Polygons::create_facets(const int n, const int size) {
        for (int i=0; i<n*size; i++)
            facets.push_back(0);
        for (int i=0; i<n; i++)
            offset.push_back(offset.back()+size);
        resize_attrs();
        return nfacets()-n;
    }

    void Polygons::delete_facets(const std::vector<bool> &to_kill) {
        Surface::delete_facets(to_kill);
        int new_nb_facets = 0;
        for (int f=0; f<nfacets(); f++) {
            if (to_kill[f]) continue;
            offset[new_nb_facets+1] = offset[new_nb_facets] + facet_size(f);
            ++new_nb_facets;
        }
        offset.resize(new_nb_facets+1);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    SurfaceConnectivity::SurfaceConnectivity(const Surface &p_m) : m(p_m) {
        reset();
    }

    void SurfaceConnectivity::reset() {
        c2f.resize(m.ncorners(), -1);
        c2c.resize(m.ncorners(), -1);
        v2c.resize(m.nverts(),   -1);

        for (int f=0; f<m.nfacets(); f++)
            for (int fc=0; fc<m.facet_size(f); fc++) {
                int c = m.corner(f, fc);
                int v = m.vert(f, fc);
                c2f[c] = f;
                v2c[v] = c;
            }
        for (int f=0; f<m.nfacets(); f++) // if it ain't broke, don't fix it
            for (int fc=0; fc<m.facet_size(f); fc++) {
                int c = m.corner(f, fc);
                int v = m.vert(f, fc);
                c2c[c] = v2c[v];
                v2c[v] = c;
            }
    }

    int SurfaceConnectivity::opposite(const int corner_id) const {
        int cir = corner_id;
        int result = -1; // not found
        do {
            int candidate = prev(cir);
            if (from(candidate) == to(corner_id) && to(candidate) == from(corner_id)) {
                if (result == -1) result = candidate;
                else return -1; // found more than one
            }
            if (cir != corner_id && to(corner_id) == to(cir))
                return -1; // the edge is non manifold
            cir = c2c[cir];
        } while (cir != corner_id);
        return result;
    }

    bool SurfaceConnectivity::is_boundary_vert(const int v) const {
        int cir = v2c[v];
        if (cir<0) return false;
        do {
            if (opposite(cir) == -1) return true;
            cir = c2c[cir];
        } while (cir != v2c[v]);
        return false;
    }

    int SurfaceConnectivity::next_around_vertex(const int corner_id) const {
        return opposite(prev(corner_id));
    }
}

