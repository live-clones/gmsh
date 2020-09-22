#pragma  once

#include <vector>
#include <array>
#include <string>

namespace GeoLog {

  using vec3 = std::array<double,3>;

  struct GObj {
    std::vector<vec3> pts;
    std::vector<double> values;
    bool isCell = false;
    bool isVector = false;
    std::string text = "";
  };

  struct View {
    std::string name;
    std::vector<GObj> objs;
    std::vector<std::pair<std::string,double>> optionsSetNumber;
  };

  /* Global variable */
  extern std::vector<View> views;

  /* Global functions (fill the global views) */
  /* - scalar values */
  bool add(vec3 p, double value, const std::string& view);
  bool add(const std::vector<vec3>& pts, double value, const std::string& view, bool isCell = false);
  bool add(const std::vector<vec3>& pts, const std::vector<double>& values, const std::string& view, bool isCell = false);
  /* - vector value (vector at center if multiple points) */
  bool add(vec3 p, vec3 n, const std::string& view);
  bool add(const std::vector<vec3>& pts, vec3 n, const std::string& view);
  /* - text value (text at center if multiple points) */
  bool add(vec3 p, const std::string& text, const std::string& view);
  bool add(const std::vector<vec3>& pts, const std::string& text, const std::string& view);

  View& get_global_view(const std::string& name);

  /* Send the views to gmsh (deleting them in the process) */
  bool flush();

}
