#ifndef __SURFACE_H__
#define __SURFACE_H__
#include <vector>
#include <memory>
#include "vec.h"
#include "pointset.h"

namespace UM {
    struct GenericAttributeContainer;

    struct Surface { // polygonal mesh interface
        PointSet points{};
        std::vector<int> facets{};
        std::vector<std::weak_ptr<GenericAttributeContainer> > attr_facets{};
        std::vector<std::weak_ptr<GenericAttributeContainer> > attr_corners{};

        Surface() = default;

        void delete_vertices(const std::vector<bool> &to_kill);
        virtual void delete_facets(const std::vector<bool> &to_kill);
        void resize_attrs();
        void compress_attrs(const std::vector<bool> &facets_to_kill);

        int nverts() const;
        int ncorners() const;

        virtual int nfacets() const = 0;
        virtual int facet_size(const int fi) const = 0;
        virtual int corner(const int fi, const int ci) const = 0;
        virtual int  vert(const int fi, const int lv) const = 0;
        virtual int &vert(const int fi, const int lv)       = 0;
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct Triangles : Surface { // simplicial mesh implementation
        int create_facets(const int n);

        int nfacets()  const;
        int facet_size(const int) const;
        int corner(const int fi, const int ci) const;
        int  vert(const int fi, const int lv) const;
        int &vert(const int fi, const int lv);
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct Quads : Surface { // quad mesh implementation
        int create_facets(const int n);

        int nfacets()  const;
        int facet_size(const int) const;
        int corner(const int fi, const int ci) const;
        int  vert(const int fi, const int lv) const;
        int &vert(const int fi, const int lv);
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct Polygons : Surface { // polygonal mesh implementation
        std::vector<int> offset;
        Polygons();

        int create_facets(const int n, const int size);
        void delete_facets(const std::vector<bool> &to_kill);

        int nfacets()  const;
        int facet_size(const int fi) const;
        int corner(const int fi, const int ci) const;
        int  vert(const int fi, const int lv) const;
        int &vert(const int fi, const int lv);
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct SurfaceConnectivity { // half-edge-like connectivity interface
        SurfaceConnectivity(const Surface &p_m);

        vec3 geom(const int corner_id) const;
        int facet(const int corner_id) const;
        int  from(const int corner_id) const;
        int    to(const int corner_id) const;
        int  prev(const int corner_id) const;
        int  next(const int corner_id) const;
        int opposite(const int corner_id) const;
        bool is_boundary_vert(const int v) const;
        int next_around_vertex(const int corner_id) const;

        void reset();
        const Surface &m;
        std::vector<int> v2c; // vertex to corner
        std::vector<int> c2f; // corner to facet
        std::vector<int> c2c; // corner to next corner sharing the same vertex (unordered)
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // these implementations are here and not in the .cpp because all inline functions must be available in all translation units //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    inline int Surface::nverts() const {
        return points.size();
    }

    inline int Surface::ncorners() const {
        return facets.size();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    inline int Triangles::nfacets() const {
        assert(0==facets.size()%3);
        return facets.size()/3;
    }

    inline int Triangles::facet_size(const int) const {
        return 3;
    }

    inline int Triangles::corner(const int fi, const int ci) const {
        assert(ci>=0 && ci<3 && fi>=0 && fi<nfacets());
        return fi*3 + ci;
    }

    inline int Triangles::vert(const int fi, const int lv) const {
        assert(fi>=0 && fi<nfacets() && lv>=0 && lv<3);
        return facets[fi*3 + lv];
    }

    inline int &Triangles::vert(const int fi, const int lv) {
        assert(fi>=0 && fi<nfacets() && lv>=0 && lv<3);
        return facets[fi*3 + lv];
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    inline int Quads::nfacets() const {
        assert(0==facets.size()%4);
        return facets.size()/4;
    }

    inline int Quads::facet_size(const int) const {
        return 4;
    }

    inline int Quads::corner(const int fi, const int ci) const {
        assert(ci>=0 && ci<4 && fi>=0 && fi<nfacets());
        return fi*4 + ci;
    }

    inline int Quads::vert(const int fi, const int lv) const {
        assert(fi>=0 && fi<nfacets() && lv>=0 && lv<4);
        return facets[fi*4 + lv];
    }

    inline int &Quads::vert(const int fi, const int lv) {
        assert(fi>=0 && fi<nfacets() && lv>=0 && lv<4);
        return facets[fi*4 + lv];
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    inline int Polygons::nfacets() const {
        return static_cast<int>(offset.size())-1;
    }

    inline int Polygons::facet_size(const int fi) const {
        assert(fi>=0 && fi<nfacets());
        return offset[fi+1]-offset[fi];
    }

    inline int Polygons::corner(const int fi, const int ci) const {
        assert(fi>=0 && fi<nfacets());
        return offset[fi]+ci;
    }

    inline int Polygons::vert(const int fi, const int lv) const {
        assert(fi>=0 && fi<nfacets());
        assert(lv>=0 && lv<facet_size(fi));
        return facets[offset[fi]+lv];
    }

    inline int &Polygons::vert(const int fi, const int lv) {
        assert(fi>=0 && fi<nfacets());
        assert(lv>=0 && lv<facet_size(fi));
        return facets[offset[fi]+lv];
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    inline vec3 SurfaceConnectivity::geom(const int corner_id) const {
        return m.points[to(corner_id)] - m.points[from(corner_id)];
    }

    inline int SurfaceConnectivity::facet(const int corner_id) const {
        return c2f[corner_id];
    }

    inline int SurfaceConnectivity::from(const int corner_id) const {
        int fi = c2f[corner_id];
        int lv = corner_id - m.corner(fi, 0);
        return m.vert(fi, lv);
    }

    inline int SurfaceConnectivity::to(const int corner_id) const {
        int fi = c2f[corner_id];
        int lv = corner_id - m.corner(fi, 0);
        int n = m.facet_size(fi);
        return m.vert(fi, (lv+1)%n);
    }

    inline int SurfaceConnectivity::next(const int corner_id) const {
        int fi = c2f[corner_id];
        int lv = corner_id - m.corner(fi, 0);
        int n = m.facet_size(fi);
        return m.corner(fi, (lv+1)%n);
    }

    inline int SurfaceConnectivity::prev(const int corner_id) const {
        int fi = c2f[corner_id];
        int lv = corner_id - m.corner(fi, 0);
        int n = m.facet_size(fi);
        return m.corner(fi, (lv-1+n)%n);
    }
}

#endif //__SURFACE_H__

