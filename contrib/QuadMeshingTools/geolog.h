#pragma  once

#include <vector>
#include <string>
#include "qmt_types.hpp"

namespace QMT {
  namespace GLog {
    struct GObj {
      size_t n;
      vec3 pts[8];
      double values[8];
      bool isVector;
    };

    struct View {
      std::string name;
      std::vector<std::string> content;
      std::vector<std::string> posOptions; /* for gmsh only */
      std::vector<GObj> objs;
    };

    class GeoLog {
      public:
        GeoLog() : exportedToGmsh(false) {};
        ~GeoLog();
        bool add(const std::vector<vec3>& pts, double value, const std::string& view);
        bool add(const std::vector<vec3>& pts, const std::vector<double>& values, const std::string& view);
        bool addOptions(const std::vector<std::string>& strs, const std::string& view);
        bool clear();
        bool save(const std::string& path); /* .pos export (gmsh) */
        bool addVector(vec3 pos, vec3 vec, const std::string& view);
        bool toGmsh();

      public:
        std::vector<View> views;
        bool exportedToGmsh;
    };
  }
}

