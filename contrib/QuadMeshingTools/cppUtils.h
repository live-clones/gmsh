// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <array>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>

#include <ostream>
#include <stdio.h>
#include <string.h>

/* Debugging macro to print variable name and value in the terminal, usage: DBG(x); DBG(x,..,z); */
#define DBG(...) fprintf(stdout, "(DBG) %s:%i: ", __FILE__,__LINE__); CppUtils::show(std::cout, #__VA_ARGS__, __VA_ARGS__); fflush(stdout)

namespace CppUtils {
  using std::size_t;

  template<class T>
    inline std::array<T,2> sorted(T v1, T v2) {
      if (v1 < v2) { return {v1,v2}; } else { return {v2,v1}; }
    }

  template<class T>
    inline std::array<T,3> sorted(T v1, T v2, T v3) {
      if (v1 > v3) std::swap(v1,v3);
      if (v1 > v2) std::swap(v1,v2);
      if (v2 > v3) std::swap(v2,v3);
      return std::array<T,3>{v1,v2,v3};
    }

  template<class T>
    inline T min_value(T v1, T v2, T v3) {
      return std::min(v1,std::min(v2,v3));
    }

  template<class T>
    inline T min_value(T v1, T v2, T v3, T v4) {
      return std::min(std::min(v1,v2),std::min(v3,v4));
    }

  template<class T>
    inline T max_value(T v1, T v2, T v3) {
      return std::max(v1,std::max(v2,v3));
    }

  template<class T>
    inline T max_value(T v1, T v2, T v3, T v4) {
      return std::max(std::max(v1,v2),std::max(v3,v4));
    }


  /* hash_combine from boost */
  template <class T>
    inline void hash_combine(std::size_t& seed, const T& v)
    {
      std::hash<T> hasher;
      seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }


  template<class T>
  void sort_unique(std::vector<T>& vec) {
      std::sort( vec.begin(), vec.end() );
      vec.erase( std::unique( vec.begin(), vec.end() ), vec.end() );
  }

  template<class T1, class T2>
  T2 sort_unique_with_perm(
        const std::vector<T1>& in,
        std::vector<T1>& uniques,
        std::vector<T2>& old2new) {

      std::vector<T2> ids(in.size());
      for(T2 k = 0; k != in.size(); ++k) ids[k]=k;

      std::sort(ids.begin(), ids.end(),
          [&in](const T2& a, const T2&b){ return (in[a] < in[b]); }
          );

      uniques.resize(in.size());
      old2new.resize(in.size());
      for(T2 k = 0; k != in.size(); ++k) uniques[k]=in[k];

      std::sort(uniques.begin(), uniques.end());
      uniques.erase( std::unique(uniques.begin(), uniques.end()),
          uniques.end());
      T2 ic = 0; // indice current
      T2 ir = 0; // indice representant
      T2 cur_rep = 0; // indice of current representant
      while(ic < in.size()){
        ic = ir;
        while(ic < in.size() && in[ids[ic]]==in[ids[ir]]){
          old2new[ids[ic]] = cur_rep;
          ++ic;
        }
        ir = ic;
        ++cur_rep;
      }
      return (T2) uniques.size();
  }

  template<class T>
    void compress(const std::vector<std::vector<T> >& vov,
        std::vector<size_t>& first, std::vector<T>& values) {
      first.resize(vov.size()+1);
      size_t count = 0;
      for (size_t i = 0; i < vov.size(); ++i) {
        first[i] = count;
        count += vov[i].size();
      }
      first[vov.size()] = count;
      values.resize(count);
      for (size_t i = 0; i < vov.size(); ++i) {
        for (size_t j = 0; j < vov[i].size(); ++j) {
          values[first[i]+j] = vov[i][j];
        }
      }
      first.shrink_to_fit();
      values.shrink_to_fit();
    }

  template<class T>
    std::vector<T> intersection(const std::vector<T>& v1, const std::vector<T>& v2) {
      std::vector<T> s1 = v1;
      std::vector<T> s2 = v2;
      sort_unique(s1);
      sort_unique(s2);
      std::vector<T> s3;
      set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), std::back_inserter(s3));
      return s3;
    }

  template<class T>
    std::vector<T> merge(const std::vector<T>& v1, const std::vector<T>& v2) {
      std::vector<T> s1 = v1;
      std::vector<T> s2 = v2;
      sort_unique(s1);
      sort_unique(s2);
      std::vector<T> s3;
      set_union(s1.begin(),s1.end(),s2.begin(),s2.end(), std::back_inserter(s3));
      sort_unique(s3);
      return s3;
    }

  template<class T>
    std::vector<T> difference(const std::vector<T>& v1, const std::vector<T>& v2) {
      std::vector<T> s1 = v1;
      std::vector<T> s2 = v2;
      sort_unique(s1);
      sort_unique(s2);
      std::vector<T> s3;
      set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(), std::inserter(s3,s3.begin()));
      return s3;
    }

  template<class T1, class T2>
    inline std::vector<T2> dynamic_cast_vector(const std::vector<T1>& pointers) {
      std::vector<T2> output(pointers.size(),NULL);
      for (size_t i = 0; i < pointers.size(); ++i) {
        output[i] = dynamic_cast<T2>((T1)pointers[i]);
      }
      return output;
    }

  template<class T>
    void append(std::vector<T>& v1, const std::vector<T>& v2) {
      v1.insert(v1.end(),v2.begin(),v2.end());
    }

  template <typename T>
    bool inVector(const T& value, const std::vector<T> &vec) {
      if (vec.size() == 0) return false;
      auto it = std::find(vec.begin(), vec.end(), value);
      return (it != vec.end()) ? true : false;
    }

  template <typename T, size_t N>
    bool inArray(const T& value, const std::array<T,N> &vec) {
      if (vec.size() == 0) return false;
      auto it = std::find(vec.begin(), vec.end(), value);
      return (it != vec.end()) ? true : false;
    }

  template <typename T>
    bool contains(const std::unordered_set<T>& values, const T& value) {
      auto it = values.find(value);
      return (it != values.end());
    }

  template <typename T>
    bool contains(const std::vector<T>& vec, const T& value) {
      if (vec.size() == 0) return false;
      auto it = std::find(vec.begin(), vec.end(), value);
      return (it != vec.end()) ? true : false;
    }

  template <typename T, size_t N>
    bool contains(const std::array<T,N> &vec, const T& value) {
      if (vec.size() == 0) return false;
      auto it = std::find(vec.begin(), vec.end(), value);
      return (it != vec.end()) ? true : false;
    }


  template<class T1,class T2>
    std::ostream& operator<<(std::ostream& os, const std::pair<T1,T2>& val) {
      return os << "(" << val.first << "," << val.second << ")";
    }

  template<class T,size_t N>
    std::ostream& operator<<(std::ostream& os, const std::array<T,N>& values) {
      os << "(";
      for (size_t i = 0; i < values.size(); ++i) {
        os << values[i];
        if (i != values.size() - 1) {
          os << ", ";
        }
      }
      os << ")";
      return os;
    }

  template<class T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& values) {
      os << "[";
      for (size_t i = 0; i < values.size(); ++i) {
        const  T & x = values[i];
        os << x;
        if (i != values.size() - 1) {
          os << ", ";
        }
      }
      os << "]";
      return os;
    }

  template<class T>
    std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& values) {
      os << "{";
      for (const T& v: values) {
        os << v << ", ";
      }
      os << "}";
      return os;
    }

  template<class T1,class T2>
    std::ostream& operator<<(std::ostream& os, const std::unordered_map<T1,T2>& values) {
      os << "{";
      for (const auto& kv: values) {
        os << kv.first << ": " << kv.second << ", ";
      }
      os << "}";
      return os;
    }

  /* For debug prints, see the DBG() macro */
  template<typename H1>
    std::ostream& show(std::ostream& out, const char* label, H1&& value) {
      return out << label << "=" << std::forward<H1>(value) << '\n';
    }

  template<typename H1, typename ...T>
    std::ostream& show(std::ostream& out, const char* label, H1&& value, T&&... rest) {
      const char* pcomma = strchr(label, ',');
      return show(out.write(label, pcomma - label) << "="
          << std::forward<H1>(value)
          << ',',
          pcomma + 1,
          std::forward<T>(rest)...);
    }

  template <typename T>
    class RestoreValueAtEndOfLife
    {
      public:
        RestoreValueAtEndOfLife<T>(T* ptr) {
          _ptr = ptr;
          _value = *ptr;
        }
        ~RestoreValueAtEndOfLife<T>() {
          *_ptr = _value;
        }
      protected:
        T* _ptr;
        T _value;
    };

  void dummy();
}
