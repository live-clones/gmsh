#ifndef __ATTRIBUTES_H__
#define __ATTRIBUTES_H__
#include <vector>
#include <memory>
#include "polyline.h"
#include "surface.h"
#include "volume.h"
#include "pointset.h"

namespace UM {
    struct GenericAttributeContainer {
        virtual void resize(const int n) = 0;
        virtual void compress(const std::vector<int> &old2new) = 0;
        virtual ~GenericAttributeContainer() = default;
    };

    template <typename T> struct AttributeContainer : GenericAttributeContainer {
        AttributeContainer(const int n) : data(n) {}
        void resize(const int n) { data.resize(n); }
        void compress(const std::vector<int> &old2new) { // NB: old2new is not a permutation!
            assert(old2new.size()==data.size());
            int cnt = 0;
            for (int i=0; i<static_cast<int>(old2new.size()); i++) {
                if (old2new[i]<0) continue;
                data[old2new[i]] = data[i];
                cnt++;
            }
            resize(cnt);
        }
        std::vector<T> data;
    };

    typedef std::pair<std::string, std::shared_ptr<GenericAttributeContainer> > NamedContainer;
    typedef std::tuple<
            std::vector<NamedContainer>,
            std::vector<NamedContainer> > PolyLineAttributes;
    typedef std::tuple<
            std::vector<NamedContainer>,
            std::vector<NamedContainer>,
            std::vector<NamedContainer> > SurfaceAttributes;
    typedef std::tuple<
            std::vector<NamedContainer>,
            std::vector<NamedContainer>,
            std::vector<NamedContainer>,
            std::vector<NamedContainer> > VolumeAttributes;

    template <typename T> struct GenericAttribute {
        GenericAttribute() : ptr(nullptr) {}
        GenericAttribute(int size) : ptr(new AttributeContainer<T>(size)) {}
        GenericAttribute(std::shared_ptr<AttributeContainer<T> > p) : ptr(p) {}
        GenericAttribute(const GenericAttribute<T>& rhs) = delete;
        GenericAttribute<bool>& operator=(const GenericAttribute<T>& rhs) = delete;
        T& operator[](const int i)       { return ptr->data[i]; }
        T  operator[](const int i) const { return ptr->data[i]; }
        std::shared_ptr<AttributeContainer<T> > ptr;
    };

    template <> struct GenericAttribute<bool> {
        GenericAttribute() : ptr(nullptr) {}
        GenericAttribute(int size) : ptr(new AttributeContainer<bool>(size)) {}
        GenericAttribute(std::shared_ptr<AttributeContainer<bool> > p) : ptr(p) {}
        GenericAttribute(const GenericAttribute<bool>& rhs) = delete;
        GenericAttribute<bool>& operator=(const GenericAttribute<bool>& rhs) = delete;

        struct ConstBoolAttributeAccessor {
            ConstBoolAttributeAccessor(const GenericAttribute<bool>& attribute, int index) : attribute_(&attribute), index_(index) {}
            operator bool() const {
                return attribute_->ptr->data[index_];
            }
            const GenericAttribute<bool>* attribute_;
            const int index_;
        };

        struct BoolAttributeAccessor {
            BoolAttributeAccessor(GenericAttribute<bool>& attribute, int index) : attribute_(&attribute), index_(index) { }
            operator bool() const {
                return attribute_->ptr->data[index_];
            }

            BoolAttributeAccessor(const BoolAttributeAccessor& rhs) {
                attribute_ = rhs.attribute_;
                index_ = rhs.index_;
            }

            BoolAttributeAccessor& operator=(bool x) {
                attribute_->ptr->data[index_] = x;
                return *this;
            }

            BoolAttributeAccessor& operator=(const BoolAttributeAccessor& rhs) {
                if (&rhs != this)
                    attribute_->ptr->data[index_] = rhs.attribute_->ptr->data[rhs.index_];
                return *this;
            }

            BoolAttributeAccessor& operator=(const ConstBoolAttributeAccessor& rhs) {
                attribute_->ptr->data[index_] = rhs.attribute_->ptr->data[rhs.index_];
                return *this;
            }

            GenericAttribute<bool>* attribute_;
            int index_;
        };

        BoolAttributeAccessor operator[](const int i) {
            return BoolAttributeAccessor(*this, i);
        }

        ConstBoolAttributeAccessor operator[](const int i) const {
            return ConstBoolAttributeAccessor(*this, i);
        }

        std::shared_ptr<AttributeContainer<bool> > ptr;
    };

    template <typename T> void bind_attribute(GenericAttribute<T> *A, const std::string name, const int size, std::vector<NamedContainer> &containers, std::vector<std::weak_ptr<GenericAttributeContainer> > &callbacks) {
        for (auto &pair : containers) {
            if (pair.first!=name) continue;
            A->ptr = std::dynamic_pointer_cast<AttributeContainer<T> >(pair.second);
            assert(A->ptr.get());
            //   callbacks.push_back(ptr); // TODO architectural choice: to bind or not to bind? At the moment the binding is done in mesh_io.cpp
            return;
        }
        A->ptr = std::make_shared<AttributeContainer<T> >(size);
        callbacks.push_back(A->ptr);
        containers.emplace_back(name, A->ptr);
    }

    template <typename T> struct PointAttribute : GenericAttribute<T> {
        PointAttribute(PointSet &pts) : GenericAttribute<T>(pts.size()) {
            pts.attr.push_back(this->ptr);
        }

        PointAttribute(std::string name, PolyLineAttributes &attributes, PolyLine &seg) : GenericAttribute<T>() {
            bind_attribute(this, name, seg.nverts(), std::get<0>(attributes), seg.points.attr);
        }

        PointAttribute(std::string name, SurfaceAttributes &attributes, Surface &m) : GenericAttribute<T>() {
            bind_attribute(this, name, m.nverts(), std::get<0>(attributes), m.points.attr);
        }

        PointAttribute(std::string name, VolumeAttributes &attributes, Volume &m) : GenericAttribute<T>() {
            bind_attribute(this, name, m.nverts(), std::get<0>(attributes), m.points.attr);
        }
    };

    template <typename T> struct SegmentAttribute : GenericAttribute<T> {
        SegmentAttribute(PolyLine &seg) : GenericAttribute<T>(seg.nsegments()) {
            seg.attr.push_back(this->ptr);
        }

        SegmentAttribute(std::string name, PolyLineAttributes &attributes, PolyLine &seg) : GenericAttribute<T>() {
            bind_attribute(this, name, seg.nsegments(), std::get<1>(attributes), seg.attr);
        }
    };

    template <typename T> struct FacetAttribute : GenericAttribute<T> {
        FacetAttribute(Surface &m) : GenericAttribute<T>(m.nfacets()) {
            m.attr_facets.push_back(this->ptr);
        }

        FacetAttribute(std::string name, SurfaceAttributes &attributes, Surface &m) : GenericAttribute<T>() {
            bind_attribute(this, name, m.nfacets(), std::get<1>(attributes), m.attr_facets);
        }
    };

    template <typename T> struct CornerAttribute : GenericAttribute<T> {
        CornerAttribute(Surface &m) : GenericAttribute<T>(m.ncorners()) {
            m.attr_corners.push_back(this->ptr);
        }

        CornerAttribute(std::string name, SurfaceAttributes &attributes, Surface &m) : GenericAttribute<T>() {
            bind_attribute(this, name, m.ncorners(), std::get<2>(attributes), m.attr_corners);
        }
    };

    template <typename T> struct CellAttribute : GenericAttribute<T> {
        CellAttribute(Volume &m) : GenericAttribute<T>(m.ncells()) {
            m.attr_cells.push_back(this->ptr);
        }

        CellAttribute(std::string name, VolumeAttributes &attributes, Volume &m) : GenericAttribute<T>() {
            bind_attribute(this, name, m.ncells(), std::get<1>(attributes), m.attr_cells);
        }
    };

    template <typename T> struct CellFacetAttribute : GenericAttribute<T> {
        CellFacetAttribute(Volume &m) : GenericAttribute<T>(m.nfacets()) {
            m.attr_facets.push_back(this->ptr);
        }

        CellFacetAttribute(std::string name, VolumeAttributes &attributes, Volume &m) : GenericAttribute<T>() {
            bind_attribute(this, name, m.nfacets(), std::get<2>(attributes), m.attr_facets);
        }
    };

    template <typename T> struct CellCornerAttribute : GenericAttribute<T> {
        CellCornerAttribute(Volume &m) : GenericAttribute<T>(m.ncorners()) {
            m.attr_corners.push_back(this->ptr);
        }

        CellCornerAttribute(std::string name, VolumeAttributes &attributes, Volume &m) : GenericAttribute<T>() {
            bind_attribute(this, name, m.ncorners(), std::get<3>(attributes), m.attr_corners);
        }
    };

}


#endif //__ATTRIBUTES_H__

