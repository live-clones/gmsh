#ifndef HEXTREME_BISSECTION_H
#define HEXTREME_BISSECTION_H

#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"


HXTStatus hxtLongestEdgeBisection(HXTEdges *edges,int nrefinements);
HXTStatus hxtEdgeRefinement(HXTEdges *edges,int nrefinements);
#endif
