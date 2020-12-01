// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
#include "meshQuadUtils.h"

#include "GmshMessage.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"

namespace QuadUtils {
  using std::vector;

  bool buildBoundary (const vector<MElement*>& elements, vector<MVertex*>& bnd){
    std::vector<MEdge> eds,veds;

    for (MElement* e: elements) {
      for (size_t j=0;j<(size_t)e->getNumEdges();j++){
        eds.push_back(e->getEdge(j));
      }
    }

    MEdgeLessThan melt;
    std::sort(eds.begin(),eds.end(), melt);
    for(size_t i=0;i<eds.size();i++){
      if (i != eds.size()-1 && eds[i] == eds[i+1])i++;
      else veds.push_back(eds[i]);
    }

    std::vector<std::vector<MVertex *> > vsorted;
    bool oks = SortEdgeConsecutive(veds, vsorted);
    if (!oks) {
      return false;
    }
    if (vsorted.empty()){
      return false;
    }
    else if (vsorted.size() > 1){
      printf("ARGHTTT %lu\n",vsorted.size());
      return false;
    }

    /* Reverse vertices if necessary, to keep coherent with elements orientation */
    {
      MEdge e = veds[0];
      MVertex* v1 = e.getVertex(0);
      MVertex* v2 = e.getVertex(1);
      auto it = std::find(vsorted[0].begin(),vsorted[0].end(),v1);
      if (it == vsorted[0].end()) {
        Msg::Error("buildBoundary(): vertex not found in sorted vertices, weird");
        return false;
      }
      size_t i = it - vsorted[0].begin();
      size_t i_next = (i+1)%vsorted[0].size();
      size_t i_prev = (i-1+vsorted[0].size())%vsorted[0].size();
      if (vsorted[0][i_next] == v2) { 
        // good ordering
      } else if (vsorted[0][i_prev] == v2) { // apply reverse
        std::reverse(vsorted[0].begin(),vsorted[0].end());
      } else {
        Msg::Error("buildBoundary(): second vertex not found in adjacent sorted vertices, weird");
        return false;
      }
    }
    bnd = vsorted[0];
    return true;
  }

  bool verticesStrictlyInside(const std::vector<MElement*>& quads,
      const std::vector<MVertex*>& bnd, std::vector<MVertex*>& inside) {
    std::vector<MVertex*> vert;
    vert.reserve(4*quads.size());
    for (MElement* f: quads) for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v = f->getVertex(lv);
      vert.push_back(v);
    }
    sort_unique(vert);
    inside = difference(vert,bnd);
    return true;
  }


}
