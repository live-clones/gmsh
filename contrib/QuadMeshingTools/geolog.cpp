#include "geolog.h"
#include <iostream>
#include <fstream>
#include "gmsh.h"

namespace QMT {
  namespace GLog {
    bool GeoLog::add(const std::vector<vec3>& pts, double value, const std::string& view) {
      std::vector<double> values(pts.size(), value);
      return add(pts,values,view);
    }

    bool GeoLog::addOptions(const std::vector<std::string>& strs, const std::string& view) {
      {
        for (size_t s = 0; s < strs.size(); ++s) {
          bool found = false;
          for (size_t i = 0; i < views.size() && !found; ++i) {
            if (views[i].name == view) {
              views[i].posOptions.push_back(strs[s]);
              found = true;
            } 
          }
          if (!found) {
            View nv;
            nv.name = view;
            nv.posOptions.push_back(strs[s]);
            views.push_back(nv);
          }
        }
      }
      return true;
    }

    bool GeoLog::add(const std::vector<vec3>& pts, const std::vector<double>& values, const std::string& view) {
      char buff[1000];
      switch (pts.size()) {
        case 1:
          if (sprintf(buff, "  SP(%.6f,%.6f,%.6f){%f};\n", pts[0][0], pts[0][1], pts[0][2], values[0]) < 0) {
            return false;
          };
          break;
        case 2:
          if (sprintf(buff, "  SL(%.6f,%.6f,%.6f,%.6f,%.6f,%.6f){%f,%f};\n", 
                pts[0][0], pts[0][1], pts[0][2], 
                pts[1][0], pts[1][1], pts[1][2], 
                values[0], values[1]) < 0) {
            return false;
          };
          break;
        case 3:
          if (sprintf(buff, "  ST(%.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f){%f,%f,%f};\n", 
                pts[0][0], pts[0][1], pts[0][2], 
                pts[1][0], pts[1][1], pts[1][2], 
                pts[2][0], pts[2][1], pts[2][2], 
                values[0], values[1], values[2]) < 0) {
            return false;
          };
          break;
        case 4:
          if (sprintf(buff, "  SS(%.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f){%f,%f,%f,%f};\n", 
                pts[0][0], pts[0][1], pts[0][2], 
                pts[1][0], pts[1][1], pts[1][2], 
                pts[2][0], pts[2][1], pts[2][2], 
                pts[3][0], pts[3][1], pts[3][2], 
                values[0], values[1], values[2], values[3]) < 0) {
            return false;
          };
          break;
        default:
          return false;
      }
      std::string buffAsStdStr = buff;

      GObj obj;
      obj.n = pts.size();
      obj.isVector = false;
      for (size_t i = 0; i < pts.size(); ++i) {
        obj.pts[i] = pts[i];
        obj.values[i] = values[i];
      }

      {
        bool found = false;
        for (size_t i = 0; i < views.size() && !found; ++i) {
          if (views[i].name == view) {
            views[i].content.push_back(buffAsStdStr);
            views[i].objs.push_back(obj);
            found = true;
          } 
        }
        if (!found) {
          View nv;
          nv.name = view;
          nv.content.push_back(buffAsStdStr);
          nv.objs.push_back(obj);
          views.push_back(nv);
        }
      }

      return true;
    }

    bool GeoLog::addVector(vec3 pos, vec3 vec, const std::string& view) {
      char buff[1000];
      if (sprintf(buff, "  VP(%.6f,%.6f,%.6f){%.6f,%.6f,%.6f};\n", pos[0], pos[1], pos[2], vec[0], vec[1], vec[2]) < 0) {
        return false;
      }
      std::string buffAsStdStr = buff;

      GObj obj;
      obj.isVector = true;
      obj.n = 2;
      obj.pts[0] = pos;
      obj.pts[1] = vec;
      obj.values[0] = length(vec);
      obj.values[1] = length(vec);

      {
        bool found = false;
        for (size_t i = 0; i < views.size() && !found; ++i) {
          if (views[i].name == view) {
            views[i].content.push_back(buffAsStdStr);
            views[i].objs.push_back(obj);
            found = true;
          } 
        }
        if (!found) {
          View nv;
          nv.name = view;
          nv.content.push_back(buffAsStdStr);
          nv.objs.push_back(obj);
          views.push_back(nv);
        }
      }
      return true;
    }

    bool GeoLog::clear() {
      views.clear();
      return true;
    }

    bool GeoLog::save(const std::string& path) {
      std::ofstream out(path);
      size_t nbItems = 0;
      for (size_t v = 0; v < views.size(); ++v) {
        out << "View \"" << views[v].name << "\" {\n";
        for (size_t i = 0; i < views[v].content.size(); ++i) {
          out << views[v].content[i];
          nbItems += 1;
        }
        out << "};\n\n";
        if (views[v].posOptions.size() > 0) {
          out << "n = PostProcessing.NbViews - 1;" << "\n";
          for (size_t i = 0; i < views[v].posOptions.size(); ++i) {
            out << views[v].posOptions[i];
          }
          out << "\n\n";
        }
      }
      out.close();
      if (views.size() > 0) {
        std::cout << "GeoLog (" << views.size() << " views and " << nbItems << " items) written at: " << path << std::endl;
      }
      return true;
    }

    bool GeoLog::toGmsh() {
      for (size_t v = 0; v < views.size(); ++v) {
        if (views[v].objs.size() == 0) continue;
        int view = gmsh::view::add(views[v].name);
        std::vector<double> data_VP;
        std::vector<double> data_SL;
        std::vector<double> data_SQ;
        for (size_t i = 0; i < views[v].objs.size(); ++i) {
          bool isVector = views[v].objs[i].isVector;
          if (isVector) {
            for (size_t lv = 0; lv < views[v].objs[i].n; ++lv) {
              for (size_t d = 0; d < 3; ++d) {
                data_VP.push_back(views[v].objs[i].pts[lv][d]);
              }
            }
          } else {
            size_t N = views[v].objs[i].n;
            for (size_t d = 0; d < 3; ++d) {
              for (size_t lv = 0; lv < N; ++lv) {
                if (N == 2) {
                  data_SL.push_back(views[v].objs[i].pts[lv][d]);
                } else if (N == 4) {
                  data_SQ.push_back(views[v].objs[i].pts[lv][d]);
                }
              }
            }
            for (size_t lv = 0; lv < views[v].objs[i].n; ++lv) {
              if (N == 2) {
                data_SL.push_back(views[v].objs[i].values[lv]);
              } else if (N == 4) {
                data_SQ.push_back(views[v].objs[i].values[lv]);
              }
            }
          }
        }
        gmsh::view::addListData(view, "SL", data_SL.size()/(6+2), data_SL);
        gmsh::view::addListData(view, "SQ", data_SQ.size()/(12+4), data_SQ);
        gmsh::view::addListData(view, "VP", data_VP.size()/6, data_VP);
      }
      exportedToGmsh = true;
      return true;
    }

    GeoLog::~GeoLog() {
      if (!exportedToGmsh) {
        toGmsh();
        exportedToGmsh = true;
      }
    }
  }
}
