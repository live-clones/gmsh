#ifndef __MAT_H__
#define __MAT_H__

#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include <iostream>

#include "vec.h"

namespace UM {
    template<int n> struct dt;

    template<int nrows,int ncols> struct mat {
        vec<ncols> rows[nrows] = {};

        mat() = default;
        vec<ncols>& operator[] (const int idx)       { assert(idx>=0 && idx<nrows); return rows[idx]; }
        const vec<ncols>& operator[] (const int idx) const { assert(idx>=0 && idx<nrows); return rows[idx]; }

        vec<nrows> col(const int idx) const {
            assert(idx>=0 && idx<ncols);
            vec<nrows> ret;
            for (int i=nrows; i--; ret[i]=rows[i][idx]);
            return ret;
        }

        void set_col(const int idx, const vec<nrows> &v) {
            assert(idx>=0 && idx<ncols);
            for (int i=nrows; i--; rows[i][idx]=v[i]);
        }

        static mat<nrows,ncols> identity() {
            mat<nrows,ncols> ret;
            for (int i=nrows; i--; )
                for (int j=ncols;j--; ret[i][j]=(i==j));
            return ret;
        }

        double det() const {
            return dt<ncols>::det(*this);
        }

        mat<nrows-1,ncols-1> get_minor(const int row, const int col) const {
            mat<nrows-1,ncols-1> ret;
            for (int i=nrows-1; i--; )
                for (int j=ncols-1;j--; ret[i][j]=rows[i<row?i:i+1][j<col?j:j+1]);
            return ret;
        }

        double cofactor(const int row, const int col) const {
            return get_minor(row,col).det()*((row+col)%2 ? -1 : 1);
        }

        mat<nrows,ncols> adjugate() const {
            mat<nrows,ncols> ret;
            for (int i=nrows; i--; )
                for (int j=ncols; j--; ret[i][j]=cofactor(i,j));
            return ret;
        }

        mat<nrows,ncols> invert_transpose() const {
            mat<nrows,ncols> ret = adjugate();
            return ret/(ret[0]*rows[0]);
        }

        mat<nrows,ncols> invert() const {
            return invert_transpose().transpose();
        }

        mat<ncols,nrows> transpose() const {
            mat<ncols,nrows> ret;
            for (int i=ncols; i--; ret[i]=this->col(i));
            return ret;
        }

        double norm() {
            double n = 0.;
            for (int i=0; i<nrows; i++)
                for (int j=0; j<ncols; j++)
                    n += rows[i][j]*rows[i][j];
            return std::sqrt(n);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////

    template<int nrows,int ncols> vec<nrows> operator*(const mat<nrows,ncols>& lhs, const vec<ncols>& rhs) {
        vec<nrows> ret;
        for (int i=nrows; i--; ret[i]=lhs[i]*rhs);
        return ret;
    }

    template<int R1,int C1,int C2>mat<R1,C2> operator*(const mat<R1,C1>& lhs, const mat<C1,C2>& rhs) {
        mat<R1,C2> result;
        for (int i=R1; i--; )
            for (int j=C2; j--; result[i][j]=lhs[i]*rhs.col(j));
        return result;
    }

    template<int nrows,int ncols>mat<nrows,ncols> operator*(const mat<nrows,ncols>& lhs, const double& val) {
        mat<nrows,ncols> result;
        for (int i=nrows; i--; result[i] = lhs[i]*val);
        return result;
    }

    template<int nrows,int ncols>mat<nrows,ncols> operator/(const mat<nrows,ncols>& lhs, const double& val) {
        mat<nrows,ncols> result;
        for (int i=nrows; i--; result[i] = lhs[i]/val);
        return result;
    }

    template<int nrows,int ncols>mat<nrows,ncols> operator+(const mat<nrows,ncols>& lhs, const mat<nrows,ncols>& rhs) {
        mat<nrows,ncols> result;
        for (int i=nrows; i--; )
            for (int j=ncols; j--; result[i][j]=lhs[i][j]+rhs[i][j]);
        return result;
    }

    template<int nrows,int ncols>mat<nrows,ncols> operator-(const mat<nrows,ncols>& lhs, const mat<nrows,ncols>& rhs) {
        mat<nrows,ncols> result;
        for (int i=nrows; i--; )
            for (int j=ncols; j--; result[i][j]=lhs[i][j]-rhs[i][j]);
        return result;
    }

    template<int nrows,int ncols> std::ostream& operator<<(std::ostream& out, const mat<nrows,ncols>& m) {
        for (int i=0; i<nrows; i++) out << m[i] << std::endl;
        return out;
    }

    /////////////////////////////////////////////////////////////////////////////////

    template<int n> struct dt {
        static double det(const mat<n,n>& src) {
            double ret = 0;
            for (int i=n; i--; ret += src[0][i]*src.cofactor(0,i));
            return ret;
        }
    };

    template<> struct dt<1> {
        static double det(const mat<1,1>& src) {
            return src[0][0];
        }
    };

    /////////////////////////////////////////////////////////////////////////////////

    typedef mat<3,3> mat3x3;
    typedef mat<2,2> mat2x2;
}
#endif //__MAT_H__

