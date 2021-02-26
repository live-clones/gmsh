#pragma once

#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <fstream>
#include <algorithm>

namespace HxtUVW {
  /* IO functions */

  static bool file_exists(const char* path) {
    std::ifstream in(path);
    return in.good();
  }

  template<typename T>
  bool save_vector(const std::vector<T>& vec, const std::string& path) {
    std::ofstream ofs(path, std::ios::out | std::ios::binary);
    size_t size = vec.size(); // Write size of the vector in first
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(vec.size()));
    // Write values of the vector
    ofs.write(reinterpret_cast<const char*>(&vec[0]), vec.size() * sizeof(T));
    return true;
  }

  template<typename T>
  bool load_vector(const std::string& path, std::vector<T>& vec) {
    std::ifstream ifs(path, std::ios::in | std::ios::binary);
    if(ifs.fail()) return false;
    size_t size = 0; // Read size at beginning of file and resize vector
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
    vec.resize(size);
    // Read data in the file
    ifs.read(reinterpret_cast<char*>(&vec[0]), size * sizeof(T));
    return true;
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
}
