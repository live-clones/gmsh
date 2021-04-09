#ifndef _MESHGFACEBIPARTITE_
#define _MESHGFACEBIPARTITE_

#include <map>
class MVertex;

void meshGFaceQuadrangulateBipartiteLabelling (int faceTag,
    std::map<MVertex*,int>* bipartiteLabel = nullptr);

#endif
