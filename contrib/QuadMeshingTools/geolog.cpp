#include "geolog.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

#define GMSH_LINKED
#if defined(GMSH_LINKED)
  #include "gmsh.h"
#endif



namespace GeoLog {
  std::vector<View> views; /* global variable instanciation */

  vec3 geolog_points_center(const std::vector<vec3>& pts) {
    if (pts.size() == 0) return {0.,0.,0.};
    vec3 center = {0.,0.,0.};
    for (size_t i = 0; i < pts.size(); ++i) {
      for (size_t d = 0; d < 3; ++d) {
        center[d] = center[d] + pts[i][d];
      }
    }
    for (size_t d = 0; d < 3; ++d) {
      center[d] = 1./double(pts.size()) * center[d];
    }
    return center;
  }

  View& get_global_view(const std::string& name) {
    bool found = false;
    for (size_t i = 0; i < views.size() && !found; ++i) {
      if (views[i].name == name) {
        return views[i];
      } 
    }
    View nv;
    nv.name = name;
    views.push_back(nv);
    return views.back();
  }

  bool add(const std::vector<vec3>& pts, const std::vector<double>& values, const std::string& view, bool isCell) {
    if (pts.size() == 0) return false;
    GObj obj;
    obj.pts.resize(pts.size());
    obj.values.resize(pts.size());
    obj.isVector = false;
    obj.isCell = isCell;
    for (size_t i = 0; i < pts.size(); ++i) {
      obj.pts[i] = pts[i];
      if (values.size() == 0) {
        obj.values[i] = 0.;
      } else if (values.size() == pts.size()) {
        obj.values[i] = values[i];
      } else {
        obj.values[i] = values[0];
      }
    }
    View& V = get_global_view(view);
    V.objs.push_back(obj);
    return true;
  }

  bool add(vec3 p, double value, const std::string& view) {
    return add(std::vector<vec3>{p},std::vector<double>{value}, view, false);
  }

  bool add(const std::vector<vec3>& pts, double value, const std::string& view, bool isCell) {
    return add(pts,std::vector<double>{value}, view, isCell);
  }

  double geolog_norm(vec3 a) {
    return std::sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]); 
  }

  bool add(vec3 p, vec3 n, const std::string& view) {
    GObj obj;
    obj.isVector = true;
    obj.isCell = false;
    obj.pts.resize(1);
    obj.values.resize(3);
    obj.pts[0] = p;
    obj.values[0] = n[0];
    obj.values[1] = n[1];
    obj.values[2] = n[2];
    View& V = get_global_view(view);
    V.objs.push_back(obj);
    return true;
  }

  bool add(const std::vector<vec3>& pts, vec3 n, const std::string& view) {
    if (pts.size() == 0) return false;
    vec3 center = geolog_points_center(pts);
    return add(center, n, view);
  }


  bool add(vec3 p, const std::string& text, const std::string& view) {
    GObj obj;
    obj.isVector = false;
    obj.isCell = false;
    obj.pts.resize(1);
    obj.pts[0] = p;
    obj.text = text;
    View& V = get_global_view(view);
    V.objs.push_back(obj);
    return true;
  }

  bool add(const std::vector<vec3>& pts, const std::string& text, const std::string& view) {
    if (pts.size() == 0) return false;
    vec3 center = geolog_points_center(pts);
    return add(center, text, view);
  }

  std::string gobj_type(const GObj& obj) {
    if        (obj.pts.size() == 1 && obj.isVector) {
      return "VP";
    } else if (obj.pts.size() == 1 && obj.text.size() > 0) {
      return "text";
    } else if (obj.pts.size() == 1 && obj.values.size() == 1) {
      return "SP";
    } else if (obj.pts.size() == 2) {
      return "SL";
    } else if (obj.pts.size() == 3) {
      return "ST";
    } else if (obj.pts.size() == 4 && !obj.isCell) {
      return "SQ";
    } else if (obj.pts.size() == 4 && obj.isCell) {
      return "SS";
    } else if (obj.pts.size() == 5 && !obj.isCell) {
      return "ST"; /* triangulation of polygon */
    } else if (obj.pts.size() == 5 && obj.isCell) {
      return "SY";
    } else if (obj.pts.size() == 6 && !obj.isCell) {
      return "ST"; /* triangulation of polygon */
    } else if (obj.pts.size() == 6 && obj.isCell) {
      return "SI";
    } else if (obj.pts.size() == 7 && !obj.isCell) {
      return "ST"; /* triangulation of polygon */
    } else if (obj.pts.size() == 8 && !obj.isCell) {
      return "ST"; /* triangulation of polygon */
    } else if (obj.pts.size() == 8 && obj.isCell) {
      return "SH";
    } else if (obj.pts.size() > 8 && !obj.isCell) {
      return "ST"; /* triangulation of polygon */
    }
    return "";
  }

  bool prepare_data(const GObj& obj, const std::string& ty, std::vector<double>& data, int& numElem) {
    size_t N = obj.pts.size();
    if (ty == "ST" && N > 3) { /* Require triangulation of polygon */
      vec3 center = geolog_points_center(obj.pts);
      for (size_t i = 0; i < obj.pts.size(); ++i) {
        vec3 p1 = obj.pts[i];
        vec3 p2 = obj.pts[(i+1)%obj.pts.size()];
        double vmid = 0.5*(obj.values[i]+obj.values[(i+1)%obj.pts.size()]);
        std::vector<vec3> tri_pts = {p1,p2,center};
        std::vector<double> tri_values = {obj.values[i],obj.values[(i+1)%obj.pts.size()],vmid};
        for (size_t d = 0; d < 3; ++d) {
          for (size_t lv = 0; lv < 3; ++lv) {
            data.push_back(tri_pts[lv][d]);
          }
        }
        for (size_t lv = 0; lv < 3; ++lv) {
          data.push_back(tri_values[lv]);
        }
        numElem += 1;
      }
    } else {
      for (size_t d = 0; d < 3; ++d) {
        for (size_t lv = 0; lv < N; ++lv) {
          data.push_back(obj.pts[lv][d]);
        }
      }
      for (size_t lv = 0; lv < N; ++lv) {
        data.push_back(obj.values[lv]);
      }
      numElem += 1;
    }
    return true;
  }

  bool export_to_gmsh() {
#if defined(GMSH_LINKED)
    for (size_t v = 0; v < views.size(); ++v) {
      if (views[v].objs.size() == 0) continue;
      std::unordered_map<std::string,std::vector<double>> data_TYPE;
      std::unordered_map<std::string,int> numElem_TYPE;
      std::vector<std::string> data_string;
      for (size_t i = 0; i < views[v].objs.size(); ++i) {
        const GObj& obj = views[v].objs[i];
        if (obj.text.size() > 0 && obj.pts.size() == 1) {
          for (size_t d = 0; d < 3; ++d) {
            data_TYPE["text"].push_back(obj.pts[0][d]);
          }
          data_string.push_back(obj.text);
          numElem_TYPE["text"] += 1;
        } else if (obj.isVector && obj.pts.size() == 1 && obj.values.size() == 3) {
          std::vector<double>& data = data_TYPE["VP"];
          for (size_t d = 0; d < 3; ++d) {
            data.push_back(obj.pts[0][d]);
          }
          for (size_t d = 0; d < 3; ++d) {
            data.push_back(obj.values[d]);
          }
          numElem_TYPE["VP"] += 1;
        } else if (obj.pts.size() > 0 && obj.values.size() == obj.pts.size()) {
          std::string ty = gobj_type(obj);
          if (ty == "") {
            std::cerr << "in GeoLog::export_to_gmsh(), GObj content not supported" << std::endl;
            return false;
          }
          std::vector<double>& data = data_TYPE[ty];
          int& numElem = numElem_TYPE[ty];
          prepare_data(obj, ty, data, numElem); /* will triangulate polygons */
        } else {
          std::cerr << "in GeoLog::export_to_gmsh(), GObj content not supported" << std::endl;
          return false;
        }
      }


      /* gmsh API calls */
      int view = gmsh::view::add(views[v].name);
      for (const auto& kv: data_TYPE) {
        if (kv.first != "" && kv.first != "text") {
          if (kv.second.size() > 0) gmsh::view::addListData(view, kv.first, numElem_TYPE[kv.first], kv.second);
        }
      }
      if (data_string.size() > 0) {
        gmsh::view::addListDataString(view, data_TYPE["text"], data_string);
      }
    }

    return true;
#else
    return false;
#endif
  }

  bool flush() {
    export_to_gmsh();
    views.clear();
    return true;
  }

}
