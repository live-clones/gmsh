#ifndef __RANGE_H__
#define __RANGE_H__

#include <tuple>
#include <utility>
#include <iterator>

#include "surface.h"
#include "volume.h"

namespace UM {
    constexpr auto range(int n) {
        struct iterator {
            int i;
            void operator++() { ++i; }
            bool operator!=(const iterator& rhs) const { return i != rhs.i; }
            const int &operator*() const { return i; }
        };
        struct wrapper {
            int n;
            auto begin() { return iterator{0}; }
            auto end()   { return iterator{n}; }
        };
        return wrapper{n};
    }

    // N.B. this implementation works only over random access containers (i.e. std::vector and not std::list)
    template <typename T>
        constexpr auto enumerate(T && iterable) {
            struct iterator {
                int i;
                T iterable;
                bool operator!=(const iterator& rhs) const { return i != rhs.i; }
                void operator++() { ++i; }
                auto operator*() const { return std::tie(i, *(iterable.begin()+i)); }
                auto begin() { return iterator{0, std::forward<T>(iterable)}; }
                auto end()   { return iterator{static_cast<int>(std::end(iterable)-std::begin(iterable)), std::forward<T>(iterable)}; }
            };
            return iterator{0, std::forward<T>(iterable)};
        }

    // N.B. if you need to zip more than two arrays, probably you are doing something wrong
    template <typename T, typename U>
        constexpr auto zip(T && t, U && u) {
            struct iterator {
                typedef decltype(std::begin(std::declval<T>())) iterator_type_T;
                typedef decltype(std::begin(std::declval<U>())) iterator_type_U;
                iterator_type_T itert;
                iterator_type_U iteru;

                bool operator!=(const iterator& rhs) const { return itert != rhs.itert || iteru != rhs.iteru; }
                void operator++() { ++itert; ++iteru; }
                auto operator*() const { return std::make_pair(*itert, *iteru); }
            };
            struct wrapper {
                T iterablet;
                U iterableu;
                auto begin() { return iterator{std::begin(iterablet), std::begin(iterableu)}; }
                auto end()   { return iterator{std::end  (iterablet), std::end  (iterableu)}; }
            };

            return wrapper{std::forward<T>(t), std::forward<U>(u)};
        }

    inline auto vert_iter(const Surface &m) {
        return range(m.nverts());
    }

    inline auto vert_iter(const Volume &m) {
        return range(m.nverts());
    }

    inline auto corner_iter(const Surface &m) {
        return range(m.ncorners());
    }

    inline auto facet_iter(const Surface &m) {
        return range(m.nfacets());
    }

    struct facet_vert_iter { // TODO provide a non-const version?
        const Surface &m_;
        const int facet_;
        facet_vert_iter(const Surface &m, const int facet) : m_(m), facet_(facet) {}

        struct iterator {
            void operator++() { ++value_; }
            int operator*() const { return m_.vert(facet_, value_); }
            bool operator!=(const iterator& rhs) const { return value_ != rhs.value_; }
            const Surface &m_;
            const int facet_;
            int value_;
        };

        iterator begin() const { return iterator{m_, facet_, 0}; }
        iterator end()   const { return iterator{m_, facet_, m_.facet_size(facet_)}; }
    };

    inline auto cell_iter(const Volume &m) {
        return range(m.ncells());
    }

}
#endif // __RANGE_H__

