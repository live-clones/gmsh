// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <cstddef>
#include <ostream>
#include <string>
#include <string.h>
#include <sstream>
#include <sstream>
#include <vector>
#include <array>
#include <algorithm>

#define DBG(...) fprintf(stdout, "(DBG) %s:%i: ", __FILE__,__LINE__); QMT_Utils::show(std::cout, #__VA_ARGS__, __VA_ARGS__); fflush(stdout)

namespace QMT_Utils {
  using std::size_t;
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

  /* sformat inspired from variadic printf at
   * https://web.archive.org/web/20131018185034/http://www.generic-programming.org/~dgregor/cpp/variadic-templates.html */
  static void sformat(std::ostream& out, const char* s) {
    while (*s) {
      if (*s == '{' && *++s != '}') 
        throw std::runtime_error("invalid format string: missing arguments");
      out << *s++;
    }
  }

  template<typename T, typename... Args>
    static void sformat(std::ostream& out, const char* s, const T& value, const Args&... args) {
      while (*s) {
        if (*s == '{' && *++s == '}') {
          out << value;
          return sformat(out, ++s, args...);
        }
        out << *s++;
      }
      printf("! sformat problem, input: %s\n",s);
      throw std::runtime_error("extra arguments provided to printf");
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

  /* For debug prints */
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
}


