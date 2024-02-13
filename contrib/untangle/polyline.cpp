#include <iostream>
#include <algorithm>
#include <cassert>
#include "polyline.h"
#include "attributes.h"

namespace UM {
    int PolyLine::nverts() const {
        return points.size();
    }

    int PolyLine::nsegments() const {
        assert(segments.size()%2==0);
        return segments.size()/2;
    }

    int PolyLine::vert(const int s, const int lv) const {
        assert(s>=0 && s<nsegments() && lv>=0 && lv<2);
        return segments[s*2 + lv];
    }

    int &PolyLine::vert(const int s, const int lv) {
        assert(s>=0 && s<nsegments() && lv>=0 && lv<2);
        return segments[s*2 + lv];
    }

    int PolyLine::create_segments(const int n) {
        segments.resize(segments.size()+n*2);
        resize_attrs();
        return nsegments()-n;
    }

    void PolyLine::resize_attrs() {
        for (auto &wp : attr)  if (auto spt = wp.lock())
            spt->resize(nsegments());
    }
}

