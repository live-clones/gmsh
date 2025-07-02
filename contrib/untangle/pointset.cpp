#include "pointset.h"
#include "attributes.h"

namespace UM {
//  void PointSet::bbox(vec3 &min, vec3 &max) {
//      min = max = data->at(0);
//      for (vec3 const &p : *data) {
//          for (int j=0; j<3; j++) {
//              min[j] = std::min(min[j], p[j]);
//              max[j] = std::max(max[j], p[j]);
//          }
//      }
//  }

    void PointSet::resize(const int n) {
        assert(1==data.use_count());
        data->resize(n);
        resize_attrs();
    }

    int PointSet::create_points(const int n) {
        assert(n>=0);
        data->resize(size()+n);
        return size()-n;
    }

    int PointSet::push_back(const vec3 &p) {
        assert(1==data.use_count());
        data->push_back(p);
        resize_attrs();
        return size()-1;
    }

    void PointSet::delete_points(const std::vector<bool> &to_kill, std::vector<int> &old2new) {
        assert(1==data.use_count());
        assert(to_kill.size()==(size_t)size());
        old2new = std::vector<int>(size(),  -1);

        int new_nb_pts = 0;
        for (int v=0; v<size(); v++) {
            if (to_kill[v]) continue;
            data->at(new_nb_pts) = data->at(v);
            old2new[v] = new_nb_pts++;
        }
        data->resize(new_nb_pts);
        compress_attrs(old2new);
    }

    void PointSet::resize_attrs() {
        for (auto &wp : attr)  if (auto spt = wp.lock())
            spt->resize(size());
    }

    void PointSet::compress_attrs(const std::vector<int> &old2new) {
        for (auto &wp : attr)  if (auto spt = wp.lock())
            spt->compress(old2new);
    }
}

