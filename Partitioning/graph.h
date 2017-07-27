#ifndef GRAPH_INCLUDED
#define GRAPH_INCLUDED

#include "Gmsh.h"
#include "GModel.h"

namespace SEQ {
    void GModelToGraph(GModel* gModel, int* eptr, int** eind, int *metisToGmshIndex);
    template <class ITERATOR>
    void fillElementsToNodes(std::multimap<int, int> &nodesToElements, ITERATOR it_beg, ITERATOR it_end);
}

#ifdef PARALLEL
namespace PAR {
    int GModelToGraph(GModel* gModel, int* eptr, int** eind, int *metisToGmshIndex, int* elmdist);
}
#endif

#endif //GRAPH_INCLUDED
