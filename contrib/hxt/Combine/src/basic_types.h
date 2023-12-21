#ifndef HXT_COMBINE_BASIC_TYPES_HEXTREME__
#define HXT_COMBINE_BASIC_TYPES_HEXTREME__

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

#include "predicates.h"

/**
* \addtogroup Combine
* @{
*/

/*
* \file basic_types.h Integer, small sets of integer and point structures 
* \authors Jeanne Pellerin, Bruno Lévy
*
* In the Combine module we use typedefs of integers to make explicit what they represent
* \warning For now cell indices (TetIndex, CellIndex etc) are represented by 32-bit integer,
*          this is a limitation and switch to 64-bit integer is to consider to manage big meshes.
*/


using std::vector; // dangerous pollution but convenient


namespace HXTCombine {

  // Indices in a mesh 
  typedef unsigned int VertexIndex;
  typedef unsigned int TetIndex;
  typedef uint64_t     AdjacentTetIndex;    // Use of 64 bit integer to be compatible with HxtMesh
  typedef unsigned int HexIndex;
  typedef unsigned int CellIndex;


  // GENERIC CELL
  typedef unsigned int CellVertexIndex;
  typedef unsigned int CellTetIndex;
  typedef unsigned int CellEdgeIndex;
  typedef unsigned int CellFacetIndex;
  typedef unsigned int CellFacetVertexIndex;

  // HEX
  typedef unsigned int HexVertexIndex;      // a vertex in a hex 0 to 8
  typedef unsigned int HexFacetVertexIndex; // a vertex in a hex facet 0 to 4
  typedef unsigned int HexEdgeIndex;        // a edge in a hex 0 to 12
  typedef unsigned int HexFacetIndex;       // a facet in a hex 0 to 6

  // PRISM
  typedef unsigned int PrismVertexIndex;      // a vertex in a prism 0 to 6
  typedef unsigned int PrismFacetVertexIndex; // a vertex in a prism facet 0 to 4
  typedef unsigned int PrismEdgeIndex;        // a edge in a prism 0 to 9
  typedef unsigned int PrismFacetIndex;       // a facet in a prism 0 to 5

  // TET
  typedef unsigned int TetVertexIndex;      // a vertex in a tet 0 to 4
  typedef unsigned int TetFacetVertexIndex; // a vertex in a tet facet 0 to 3
  typedef unsigned int TetFacetIndex;       // a facet in a tet 0 to 4
  typedef unsigned int TetEdgeIndex;        // an edge in a tet 0 to 6
  typedef unsigned int TetCornerIndex;      // a tet corner 0 to 4*n - n number of tets

  // TRIANGLE
  typedef unsigned int TriangleIndex;
  typedef unsigned int TriangleVertexIndex; // a vertex in a triangle 0 to 3
  typedef unsigned int TriangleCornerIndex; // a triangle corner 0 to 3*n - n number of triangles
  typedef unsigned int TriangleEdgeIndex;

  typedef uint32_t ColorIndex;              // a color on a tet or triangle
  typedef unsigned int PatternIndex;        // a triangulation pattern

  static const unsigned int NO_ID = -1;
  static const ColorIndex NO_COLOR = -1;


  /************************************************************************/
  // The following code comes from  Geogram - BSD license
  /************************************************************************/
  /*
  *   Copyright (c) 2012-2014,  Bruno  Levy
  *   All rights reserved.
  *
  *   Redistribution and use in source and binary forms, with or without
  *  modification, are permitted provided that the following conditions are met:
  *
  *  * Redistributions of source code must retain the above copyright notice,
  *  this list of conditions and the following disclaimer.
  *  * Redistributions in binary form must reproduce the above copyright notice,
  *  this list of conditions and the following disclaimer in the documentation
  *  and/or other materials provided with the distribution.
  *  * Neither the name of the ALICE  Project-Team nor the names of its
  *  contributors may be used to endorse or promote products derived from this
  *  software without specific prior written permission.
  *
  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  *  POSSIBILITY OF SUCH DAMAGE.
  *
  *   If you modify this software, you should include a notice giving the
  *  name of the person performing the modification, the date of modification,
  *  and the reason for such modification.
  *
  *   Contact:  Bruno  Levy
  *
  *      Bruno.Levy@inria.fr
  *     http://www.loria.fr/~levy
  *
  *     ALICE  Project
  *     LORIA, INRIA  Lorraine,
  *      Campus  Scientifique, BP 239
  *     54506 VANDOEUVRE LES NANCY CEDEX
  *     FRANCE
  */
  template <class IndexType>
  struct basicBindex {
    IndexType indices[2];

    inline basicBindex() {}
    inline basicBindex(IndexType i, IndexType j, bool keepOrder = false) {
      indices[0] = i;
      indices[1] = j;
      if (!keepOrder && indices[1] < indices[0]) {
        std::swap(indices[0], indices[1]);
      }
    }
    inline bool operator< (const basicBindex<IndexType>& rhs) const {
      if (indices[0] < rhs.indices[0]) {
        return true;
      }
      if (indices[0] > rhs.indices[0]) {
        return false;
      }
      if (indices[1] < rhs.indices[1]) {
        return true;
      }
      return false;
    }
    inline bool operator== (const basicBindex<IndexType>& rhs) const {
      return (indices[0] == rhs.indices[0])
        && (indices[1] == rhs.indices[1]);
    }
    inline bool operator!= (const basicBindex<IndexType>& rhs) const {
      return (indices[0] != rhs.indices[0])
        || (indices[1] != rhs.indices[1]);
    }
  };

  template <class IndexType>
  inline std::ostream& operator<< (std::ostream& out, const basicBindex<IndexType>& B) {
    return out << B.indices[0] << " " << B.indices[1];
  }

  typedef basicBindex<unsigned int> bindex;

  template <class IndexType>
  struct basicTrindex {
    IndexType indices[3];
    inline basicTrindex() {}
    inline basicTrindex(IndexType i, IndexType j, IndexType k, bool keepOrder = false) {
      indices[0] = i;
      indices[1] = j;
      indices[2] = k;
      if (!keepOrder) {
        if (indices[0]> indices[1]) std::swap(indices[0], indices[1]);
        if (indices[1]> indices[2]) std::swap(indices[1], indices[2]);
        if (indices[0]> indices[1]) std::swap(indices[0], indices[1]);
      }
    }
    inline bool operator< (const basicTrindex<IndexType>& rhs) const {
      for (unsigned int i = 0; i < 3; i++) {
        if (indices[i] < rhs.indices[i]) {
          return true;
        }
        if (indices[i] > rhs.indices[i]) {
          return false;
        }
      }
      return false;
    }
    inline bool operator== (const basicTrindex<IndexType>& rhs) const {
      return (indices[0] == rhs.indices[0])
        && (indices[1] == rhs.indices[1])
        && (indices[2] == rhs.indices[2]);
    }
    inline bool operator!= (const basicTrindex<IndexType>& rhs) const {
      return (indices[0] != rhs.indices[0])
        || (indices[1] != rhs.indices[1])
        || (indices[2] != rhs.indices[2]);
    }
    /* \return true if the indices in \p t are a circular permutation
    *  of (\p i, \p j, \p k), false otherwise.
    */
    inline static bool sameOrientation(const basicTrindex<IndexType>& t,
      IndexType i, IndexType j, IndexType k)
    {
      return (t.indices[0] == i && t.indices[1] == j && t.indices[2] == k)
        || (t.indices[1] == i && t.indices[2] == j && t.indices[0] == k)
        || (t.indices[2] == i && t.indices[0] == j && t.indices[1] == k);
    }
    /*\return true if the indices in \p t2 are a circular permutation
    *  of the indices in \p t1, false otherwise.
    */
    inline static bool sameOrientation(const basicTrindex<IndexType>& t1,
      const basicTrindex<IndexType>& t2)
    {
      return sameOrientation(t1, t2.indices[0], t2.indices[1], t2.indices[2]);
    }
    /*\return a basicTrindex with the same indices as \p t but in reverse
    * order.
    */
    inline static basicTrindex inverse(const basicTrindex<IndexType>& t)
    {
      return basicTrindex(t.indices[2], t.indices[1], t.indices[0], true);
    }
  };

  typedef basicTrindex<unsigned int> trindex;

  template <class IndexType>
  inline std::ostream& operator<< (std::ostream& out, const basicTrindex<IndexType>& T) {
    return out
      << T.indices[0] << " " << T.indices[1] << " " << T.indices[2];
  }

  template <class IndexType>
  struct basicQuadindex {
    IndexType indices[4];
    inline basicQuadindex() {}
    inline basicQuadindex(IndexType i, IndexType j, IndexType k, IndexType l, bool keepOrder = false)
    {
      indices[0] = i;
      indices[1] = j;
      indices[2] = k;
      indices[3] = l;

      if (!keepOrder) {
        if (indices[1] < indices[0]) std::swap(indices[0], indices[1]);
        if (indices[3] < indices[2]) std::swap(indices[2], indices[3]);
        if (indices[2] < indices[0]) {
          std::swap(indices[0], indices[2]);
          std::swap(indices[1], indices[3]);
        }
        if (indices[2] < indices[1]) std::swap(indices[1], indices[2]);
        if (indices[3] < indices[2]) std::swap(indices[2], indices[3]);
      }
    }
    inline bool operator< (const basicQuadindex<IndexType>& rhs) const {
      for (unsigned int i = 0; i < 4; i++) {
        if (indices[i] < rhs.indices[i]) {
          return true;
        }
        if (indices[i] > rhs.indices[i]) {
          return false;
        }
      }
      return false;
    }
    inline bool operator== (const basicQuadindex<IndexType>& rhs) const {
      return
        (indices[0] == rhs.indices[0]) &&
        (indices[1] == rhs.indices[1]) &&
        (indices[2] == rhs.indices[2]) &&
        (indices[3] == rhs.indices[3]);
    }
    inline bool operator!= (const basicQuadindex<IndexType>& rhs) const {
      return
        (indices[0] != rhs.indices[0]) ||
        (indices[1] != rhs.indices[1]) ||
        (indices[2] != rhs.indices[2]) ||
        (indices[3] != rhs.indices[3]);
    }
    inline static basicQuadindex inverse(const basicQuadindex<IndexType>& t) {
      return basicQuadindex(t.indices[0], t.indices[2], t.indices[1], t.indices[3], true);
    }
  };

  typedef basicQuadindex<unsigned int> quadindex;

  template <class IndexType>
  inline std::ostream& operator<< (
    std::ostream& out, const basicQuadindex<IndexType>& Q
    ) {
    return out
      << Q.indices[0] << " " << Q.indices[1] << " "
      << Q.indices[2] << " " << Q.indices[3];
  }

  /************************************************************************/
  // The following code comes from Geogram - BSD license
  /************************************************************************/

  /**
  * \brief Generic maths vector
  * \details Vecng implements a maths vector of dimension \p DIM containing
  * coordinates of type \p T and provides operations for manipulating it.
  * Type \p T is expected to be a numeric type.
  * \tparam DIM dimension of the vector
  * \tparam T type of the vector coordinates.
  */
  template <unsigned int DIM, class T>
  class vecng {
  public:
    /** \brief The dimension of the vector */
    static const unsigned int dim = DIM;

    /** \brief This vector type */
    typedef vecng<DIM, T> vectorType;

    /** \brief The type of the vector coordinates */
    typedef T value_type;

    /**
    * \brief Default vector constructor
    * \details All coordinates are initialized to 0 (zero).
    */
    vecng() {
      for (unsigned int i = 0; i < DIM; i++) {
        data_[i] = T(0);
      }
    }

    /**
    * \brief vecng default copy constructor.
    * \param[in] rhs a const reference to the vecng to be copied
    */
    vecng(const vecng<DIM, T>& rhs) {
      for (unsigned int i = 0; i < DIM; i++) {
        data_[i] = rhs.data_[i];
      }
    }

    // This one should never be called :
    // a template constructor cannot be a copy constructor

    /**
    * \brief Constructs a vector by copy
    * \details This copies coordinates of vector \p v to this vector.
    * The type \p T2 of the coordinates in \p v must be convertible to
    * the type \p T of this vector.
    * \param[in] v an vector of same dimension with coordinates of type
    * \p T2
    * \tparam T2 the type of coordinates in vector \p v
    */
    template <class T2>
    explicit vecng(const vecng<DIM, T2>& v) {
      for (unsigned int i = 0; i < DIM; i++) {
        data_[i] = T(v[i]);
      }
    }

    // to avoid compilation problems
    template <class T2, unsigned int DIM2>
    explicit vecng(
      const vecng<DIM2, T2>& v
    ) {
      assert(DIM2 == DIM);
      for (unsigned int i = 0; i < DIM; i++) {
        data_[i] = T(v[i]);
      }
    }

    /**
    * \brief Constructs a vector from an array
    * \details This copies coordinates the first \p DIM coordinates of
    * array \p v to this vector. The type \p T2 of the coordinates in
    * \p v must be convertible to the type \p T of this vector.
    * \param[in] v an array of values of type \p T2
    * \tparam T2 the type of coordinates in vector \p v
    */
    template <class T2>
    explicit vecng(const T2* v) {
      for (unsigned int i = 0; i < DIM; i++) {
        data_[i] = T(v[i]);
      }
    }

    /**
    * \brief Assignment operator
    * \details This copies coordinates of vector \p v to this vector.
    * \param[in] v a vector of same dimension and same type
    * \return a reference to this vector
    */
    vectorType& operator= (const vectorType& v) {
      memcpy(data_, v.data(), DIM * sizeof(T));
      return *this;
    }

    /**
    * \brief Gets the vector dimension
    * \return the value of \p DIM
    */
    unsigned int dimension() const {
      return DIM;
    }

    /**
    * \brief Gets modifiable vector data
    * \return a pointer to the first element of the vector
    */
    T* data() {
      return data_;
    }

    /**
    * \brief Gets non-modifiable vector data
    * \return a const pointer to the first element of the vector
    */
    const T* data() const {
      return data_;
    }

    /**
    * \brief Gets a modifiable vector coordinate
    * \param[in] i index of the coordinate
    * \return a reference to coordinate at index \p i
    */
    inline T& operator[] (unsigned int i) {
      assert(i < DIM);
      return data()[i];
    }

    /**
    * \brief Gets a non-modifiable vector coordinate
    * \param[in] i index of the coordinate
    * \return a const reference to coordinate at index \p i
    */
    inline const T& operator[] (unsigned int i) const {
      assert(i < DIM);
      return data()[i];
    }

    /**
    * \brief Gets the squared length of the vector
    */
    inline T length2() const {
      T result = T(0);
      for (unsigned int i = 0; i < DIM; i++) {
        result += data_[i] * data_[i];
      }
      return result;
    }

    /**
    * \brief Gets the length of the vector
    */
    inline T length() const {
      return sqrt(length2());
    }

    /**
    * \brief Gets the squared distance to a vector
    * \param[in] v another vector
    * \return (\p v - \p this).length2()
    */
    inline T distance2(const vectorType& v) const {
      T result(0);
      for (unsigned int i = 0; i < DIM; i++) {
        result += geoSqr(v.data_[i] - data_[i]);
      }
      return result;
    }

    /**
    * \brief Gets the distance to a vector
    * \param[in] v another vector
    * \return (\p v - \p this).length()
    */
    inline T distance(const vectorType& v) const {
      return sqrt(distance2(v));
    }

    // operators

    /**
    * \brief Adds a vector in place
    * \details Adds coordinates of vector \p v to this vector
    * coordinates
    * \param[in] v another vector
    * \return a reference to this vector
    */
    inline vectorType& operator+= (const vectorType& v) {
      for (unsigned int i = 0; i < DIM; i++) {
        data_[i] += v.data_[i];
      }
      return *this;
    }

    /**
    * \brief Subtracts a vector in place
    * \details Substracts coordinates of vector \p v from this vector
    * coordinates
    * \param[in] v another vector
    * \return a reference to this vector
    */
    inline vectorType& operator-= (const vectorType& v) {
      for (unsigned int i = 0; i < DIM; i++) {
        data_[i] -= v.data_[i];
      }
      return *this;
    }

    /**
    * \brief Multiplies by a scalar in place
    * \details Multiplies this vector coordinates by value \p s. The type
    * \p T2 of \p s must be convertible to the type \p T of this vector
    * coordinates.
    * \param[in] s a value of type \p T2
    * \tparam T2 the type of value \p s
    * \return a reference to this vector
    */
    template <class T2>
    inline vectorType& operator*= (T2 s) {
      for (unsigned int i = 0; i < DIM; i++) {
        data_[i] *= T(s);
      }
      return *this;
    }

    /**
    * \brief Divides by a scalar in place
    * \details Divides this vector coordinates by value \p s. The type
    * \p T2 of \p s must be convertible to the type \p T of this vector
    * coordinates.
    * \param[in] s a value of type \p T2
    * \tparam T2 the type of value \p s
    * \return a reference to this vector
    */
    template <class T2>
    inline vectorType& operator/= (T2 s) {
      for (unsigned int i = 0; i < DIM; i++) {
        data_[i] /= T(s);
      }
      return *this;
    }

    /**
    * \brief Adds 2 vectors
    * \details Builds a vector by adding coordinates of this vector and
    * coordinates of vector \p v.
    * \param[in] v another vector
    * \return the result vector (\p this + \p v)
    */
    inline vectorType operator+ (const vectorType& v) const {
      vectorType result(*this);
      for (unsigned int i = 0; i < DIM; i++) {
        result.data_[i] += v.data_[i];
      }
      return result;
    }

    /**
    * \brief Substracts 2 vectors
    * \details Builds a vector by substracting coordinates of vector \p v
    * to coordinates of this vector.
    * \param[in] v another vector
    * \return the result vector (\p this - \p v)
    */
    inline vectorType operator- (const vectorType& v) const {
      vectorType result(*this);
      for (unsigned int i = 0; i < DIM; i++) {
        result.data_[i] -= v.data_[i];
      }
      return result;
    }

    /**
    * \brief Multiplies a vector by a scalar
    * \details Builds a vector by multipying this vector coordinates by
    * value \p s. The type \p T2 of \p s must be convertible to the type
    * \p T of this vector coordinates.
    * \param[in] s a value of type \p T2
    * \tparam T2 the type of value \p s
    * \return the result vector (\p this * \p s)
    */
    template <class T2>
    inline vectorType operator* (T2 s) const {
      vectorType result(*this);
      for (unsigned int i = 0; i < DIM; i++) {
        result.data_[i] *= T(s);
      }
      return result;
    }

    /**
    * \brief Divides a vector by a scalar
    * \details Builds a vector by dividing this vector coordinates by
    * value \p s. The type \p T2 of \p s must be convertible to the type
    * \p T of this vector coordinates.
    * \param[in] s a value of type \p T2
    * \tparam T2 the type of value \p s
    * \return the result vector (\p this / \p s)
    */
    template <class T2>
    inline vectorType operator/ (T2 s) const {
      vectorType result(*this);
      for (unsigned int i = 0; i < DIM; i++) {
        result.data_[i] /= T(s);
      }
      return result;
    }

    /**
    * \brief Negates a vector
    * \details Builds a vector by negating coordinates of this vector.
    * \return the result vector (-\p this)
    */
    inline vectorType operator- () const {
      vectorType result;
      for (unsigned int i = 0; i < DIM; i++) {
        result.data_[i] = -data_[i];
      }
      return result;
    }

  private:
    T data_[DIM];
  };

  /**
  * \brief Computes the dot product of 2 vectors
  * \param[in] v1 the first vector
  * \param[in] v2 the second vector
  * \return the dot product (\p v1 . \p v2)
  * \relates vecng
  */
  template <unsigned int DIM, class T>
  inline T dot(
    const vecng<DIM, T>& v1, const vecng<DIM, T>& v2
  ) {
    T result = 0;
    for (unsigned int i = 0; i < DIM; i++) {
      result += v1[i] * v2[i];
    }
    return result;
  }

  /**
  * \brief Multiplies a scalar by a vector
  * \details Builds a vector by multipying this vector coordinates by
  * value \p s. The type \p T2 of \p s must be convertible to the type \p
  * T of this vector coordinates.
  * \param[in] s a value of type \p T2
  * \param[in] v the vector to multiply
  * \tparam T2 the type of value \p s
  * \return the result vector (\p s * \p v)
  * \relates vecng
  */
  template <class T2, unsigned int DIM, class T>
  inline vecng<DIM, T> operator* (
    T2 s, const vecng<DIM, T>& v
    ) {
    vecng<DIM, T> result;
    for (unsigned int i = 0; i < DIM; i++) {
      result[i] = T(s) * v[i];
    }
    return result;
  }

  // Compatibility with GLSL

  /**
  * \brief Gets the norm of a vector
  * \param[in] v a vector
  * \return the norm of vector \p v
  * \see vecng::length()
  * \relates vecng
  */
  template <unsigned int DIM, class T>
  inline T length(const vecng<DIM, T>& v) {
    return v.length();
  }

  /**
  * \brief Gets the square norm of a vector
  * \param[in] v a vector
  * \return the square norm of vector \p v
  * \see vecng::length2()
  * \relates vecng
  */
  template <unsigned int DIM, class T>
  inline T length2(const vecng<DIM, T>& v) {
    return v.length2();
  }

  /**
  * \brief Gets the square distance between 2 vectors
  * \param[in] v1 the first vector
  * \param[in] v2 the second vector
  * \return the square distance between \p v1 and \p v2.
  * \see vecng::distance2()
  * \relates vecng
  */
  template <unsigned int DIM, class T>
  inline T distance2(
    const vecng<DIM, T>& v1, const vecng<DIM, T>& v2
  ) {
    return v2.distance2(v1);
  }

  /**
  * \brief Gets the distance between 2 vectors
  * \param[in] v1 the first vector
  * \param[in] v2 the second vector
  * \return the distance between \p v1 and \p v2.
  * \see vecng::distance()
  * \relates vecng
  */
  template <unsigned int DIM, class T>
  inline T distance(
    const vecng<DIM, T>& v1, const vecng<DIM, T>& v2
  ) {
    return v2.distance(v1);
  }

  /**
  * \brief Normalizes a vector
  * \details Returns a normalized vector constructed by dividing
  * coordinates of vector \p v by it norm. If the norm is 0, then the
  * result is undefined.
  * \param[in] v a vector
  * \return the normalized vector
  * \relates vecng
  */
  template <unsigned int DIM, class T>
  inline vecng<DIM, T> normalize(
    const vecng<DIM, T>& v
  ) {
    T s = length(v);
    if (s > 1e-30) {
      s = T(1) / s;
    }
    return s * v;
  }

  /**
  * \brief Computes a weighted barycenter
  * \details Computes the barycenter of \p v1 and \p v2 weighted by value
  * 1 - \p s and \p s.
  * \param[in] v1 the first vector
  * \param[in] v2 the second vector
  * \param[in] s the weight value
  * \return the barycenter (1 - \p s) * \p v1 + \p s * \p v2
  * \relates vecng
  */
  template <unsigned int DIM, class T>
  inline vecng<DIM, T> mix(
    const vecng<DIM, T>& v1, const vecng<DIM, T>& v2, T s
  ) {
    return (T(1) - s) * v1 + s * v2;
  }

  /**
  * \brief Writes a vector to a stream
  * \details This writes the coordinates of vector \p v separated by a
  * space character to the output stream \p out.
  * \param[in] out the output stream
  * \param[in] v the vector to write
  * \return a reference to the output stream \p out
  * \relates vecng
  */
  template <unsigned int DIM, class T>
  inline std::ostream& operator<< (
    std::ostream& out, const vecng<DIM, T>& v
    ) {
    const char* sep = "";
    for (unsigned int i = 0; i < DIM; i++) {
      out << sep << v[i];
      sep = " ";
    }
    return out;
  }

  /************************************************************************/

  /**
  * \brief Specialization of class vecng for DIM == 3
  * \see vecng
  */
  template <class T>
  class vecng<3, T> {
  public:
    /** \copydoc vecng::dim */
    static const unsigned int dim = 3;

    /** \copydoc vecng::vectorType */
    typedef vecng<dim, T> vectorType;

    /** \copydoc vecng::value_type */
    typedef T value_type;

    /** \copydoc vecng::vecng() */
    vecng() :
      x(0),
      y(0),
      z(0) {
    }

    /**
    * \brief Constructs a vector from coordinates
    * \param[in] xIn , yIn , zIn vector coordinates
    */
    vecng(T xIn, T yIn, T zIn) :
      x(xIn),
      y(yIn),
      z(zIn) {
    }

    /** \copydoc vecng::vecng(const vecng<DIM, T2>&) */
    template <class T2>
    explicit vecng(const vecng<dim, T2>& v) :
      x(v.x),
      y(v.y),
      z(v.z) {
    }

    /** \copydoc vecng::vecng(const T2*) */
    template <class T2>
    explicit vecng(const T2* v) :
      x(v[0]),
      y(v[1]),
      z(v[2]) {
    }

    /** \copydoc vecng::length2() const */
    inline T length2() const {
      return x * x + y * y + z * z;
    }

    /** \copydoc vecng::length() const */
    inline T length() const {
      return sqrt(x * x + y * y + z * z);
    }

    /** \copydoc vecng::distance2(const vectorType&) const */
    inline T distance2(const vectorType& v) const {
      T dx = v.x - x;
      T dy = v.y - y;
      T dz = v.z - z;
      return dx * dx + dy * dy + dz * dz;
    }

    /** \copydoc vecng::distance(const vectorType&) const */
    inline T distance(const vectorType& v) const {
      return sqrt(distance2(v));
    }

    /** \copydoc vecng::operator+=(const vectorType&) */
    inline vectorType& operator+= (const vectorType& v) {
      x += v.x;
      y += v.y;
      z += v.z;
      return *this;
    }

    /** \copydoc vecng::operator-=(const vectorType&) */
    inline vectorType& operator-= (const vectorType& v) {
      x -= v.x;
      y -= v.y;
      z -= v.z;
      return *this;
    }

    /** \copydoc vecng::operator*=(T2) */
    template <class T2>
    inline vectorType& operator*= (T2 s) {
      x *= T(s);
      y *= T(s);
      z *= T(s);
      return *this;
    }

    /** \copydoc vecng::operator/=(T2) */
    template <class T2>
    inline vectorType& operator/= (T2 s) {
      x /= T(s);
      y /= T(s);
      z /= T(s);
      return *this;
    }

    /** \copydoc vecng::operator+(const vectorType&) const */
    inline vectorType operator+ (const vectorType& v) const {
      return vectorType(x + v.x, y + v.y, z + v.z);
    }

    /** \copydoc vecng::operator-(const vectorType&) const */
    inline vectorType operator- (const vectorType& v) const {
      return vectorType(x - v.x, y - v.y, z - v.z);
    }

    /** \copydoc vecng::operator*(T2) const */
    template <class T2>
    inline vectorType operator* (T2 s) const {
      return vectorType(x * T(s), y * T(s), z * T(s));
    }

    /** \copydoc vecng::operator/(T2) const */
    template <class T2>
    inline vectorType operator/ (T2 s) const {
      return vectorType(x / T(s), y / T(s), z / T(s));
    }

    /** \copydoc vecng::operator-() const */
    inline vectorType operator- () const {
      return vectorType(-x, -y, -z);
    }

    /** \copydoc vecng::dimension() const */
    unsigned int dimension() const {
      return dim;
    }

    /** \copydoc vecng::data() */
    T* data() {
      return &x;
    }

    /** \copydoc vecng::data() const */
    const T* data() const {
      return &x;
    }

    /** \copydoc vecng::operator[](unsigned int) */
    inline T& operator[] (unsigned int i) {
      assert(i < dim);
      return data()[i];
    }

    /** \copydoc vecng::operator[](unsigned int) const */
    inline const T& operator[] (unsigned int i) const {
      assert(i < dim);
      return data()[i];
    }

    /** \brief Vector x coordinate */
    T x;
    /** \brief Vector y coordinate */
    T y;
    /** \brief Vector z coordinate */
    T z;
  };

  /**
  * \copydoc vecng::dot(const vecng<DIM,T>&, const vecng<DIM,T>&)\
  * \relates vecng
  */
  template <class T>
  inline T dot(
    const vecng<3, T>& v1, const vecng<3, T>& v2
  ) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  }

  /**
  * \brief Computes the cross product of 2 vectors
  * \param[in] v1 the first vector
  * \param[in] v2 the second vector
  * \return the cross product (\p v1 x \p v2)
  * \relates vecng
  */
  template <class T>
  inline vecng<3, T> cross(
    const vecng<3, T>& v1, const vecng<3, T>& v2
  ) {
    return vecng<3, T>(
      v1.y * v2.z - v1.z * v2.y,
      v1.z * v2.x - v1.x * v2.z,
      v1.x * v2.y - v1.y * v2.x
      );
  }

  /**
  * \copydoc vecng::operator*(T2, const vecng<DIM,T>&)
  * \relates vecng
  */
  template <class T2, class T>
  inline vecng<3, T> operator* (
    T2 s, const vecng<3, T>& v
    ) {
    return vecng<3, T>(T(s) * v.x, T(s) * v.y, T(s) * v.z);
  }

  /************************************************************************/

  typedef vecng<3, double> vec3;

  inline double orient3d(vec3 a, vec3 b, vec3 c, vec3 d) {
    return ::orient3d(a.data(), b.data(), c.data(), d.data());
  }
  
}


//namespace std {
//  /** To remove ?? Not used anymore ..
//  * \todo Test if it was faster or not than what we have now
//  */
//  template <>
//  struct hash<basicTrindex<unsigned int> >
//  {
//    size_t operator()(const basicTrindex<unsigned int> &k) const
//    {
//      // No idea why this works [JL] It is very fast. Check the timings if you change it.
//      return k.indices[0]<<16|k.indices[1]<<8|k.indices[2];
//      // The more classical solution that is slower
//      //return std::hash<int>()(k.indices[0])^std::hash<int>()(k.indices[1])^std::hash<int>()(k.indices[1]);
//    }
//  };
//}

/**
* @}
*/

#endif
