#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include <iostream>

#if WIN32
// disable int to size_t warning 
#pragma warning(disable: 4267)
#endif

namespace UM {
    template<int n> struct vec {
        vec() = default;
        double & operator[](const int i)       { assert(i>=0 && i<n); return data[i]; }
        double   operator[](const int i) const { assert(i>=0 && i<n); return data[i]; }
        double norm2() const { return (*this)*(*this) ; }
        double norm()  const { return std::sqrt(norm2()); }
        double data[n] = {0};
    };

    template<int n> double operator*(const vec<n>& lhs, const vec<n>& rhs) {
        double ret = 0;
        for (int i=n; i--; ret+=lhs[i]*rhs[i]);
        return ret;
    }

    template<int n> vec<n> operator+(const vec<n>& lhs, const vec<n>& rhs) {
        vec<n> ret = lhs;
        for (int i=n; i--; ret[i]+=rhs[i]);
        return ret;
    }

    template<int n> vec<n> operator-(const vec<n>& v) {
        vec<n> ret = v;
        for (int i=n; i--; ret[i]=-ret[i]);
        return ret;
    }

    template<int n> vec<n>& operator+=(vec<n>& a, const vec<n>& b) {
        for (int i=n; i--; a[i]+=b[i]);
        return a;
    }

    template<int n> vec<n> operator-(const vec<n>& lhs, const vec<n>& rhs) {
        vec<n> ret = lhs;
        for (int i=n; i--; ret[i]-=rhs[i]);
        return ret;
    }

    template<int n> vec<n> operator*(const double& rhs, const vec<n> &lhs) {
        vec<n> ret = lhs;
        for (int i=n; i--; ret[i]*=rhs);
        return ret;
    }

    template<int n> vec<n> operator*(const vec<n>& lhs, const double& rhs) {
        vec<n> ret = lhs;
        for (int i=n; i--; ret[i]*=rhs);
        return ret;
    }

    template<int n> vec<n> operator/(const vec<n>& lhs, const double& rhs) {
        vec<n> ret = lhs;
        for (int i=n; i--; ret[i]/=rhs);
        return ret;
    }

    template<int n> std::ostream& operator<<(std::ostream& out, const vec<n>& v) {
        for (int i=0; i<n; i++) out << v[i] << " ";
        return out;
    }

    /////////////////////////////////////////////////////////////////////////////////

    template<> struct vec<2> {
        vec() =  default;
        vec(double X, double Y) : x(X), y(Y) {}
        double& operator[](const int i)       { assert(i>=0 && i<2); return i==0 ? x : y; }
        double  operator[](const int i) const { assert(i>=0 && i<2); return i==0 ? x : y; }
        double norm2() const { return (*this)*(*this) ; }
        double norm()  const { return std::sqrt(norm2()); }
        vec & normalize() { *this = (*this)/norm(); return *this; }

        double x{}, y{};
    };

    /////////////////////////////////////////////////////////////////////////////////

    template<> struct vec<3> {
        vec() = default;
        vec(double X, double Y, double Z) : x(X), y(Y), z(Z) {}
        double& operator[](const int i)       { assert(i>=0 && i<3); return i==0 ? x : (1==i ? y : z); }
        double  operator[](const int i) const { assert(i>=0 && i<3); return i==0 ? x : (1==i ? y : z); }
        double norm2() const { return (*this)*(*this) ; }
        double norm()  const { return std::sqrt(norm2()); }
        vec & normalize() { *this = (*this)/norm(); return *this; }

        double x{}, y{}, z{};
    };

    /////////////////////////////////////////////////////////////////////////////////

    typedef vec<2> vec2;
    typedef vec<3> vec3;
    vec3 cross(const vec3 &v1, const vec3 &v2);

}
#endif //__GEOMETRY_H__

