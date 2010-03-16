#ifndef _MELEMENT_OCTREE_
#define _MELEMENT_OCTREE_

#include <vector>

class Octree;
class GModel;
class MElement;

Octree *buildMElementOctree(GModel *);
Octree *buildMElementOctree(std::vector<MElement*> &);

#endif
