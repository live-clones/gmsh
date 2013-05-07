#ifndef _DISTANCE_TO_MESH_
#define _DISTANCE_TO_MESH_
#include <ANN/ANN.h>
#include "GModel.h"
#include "simpleFunction.h"
class distanceToMesh : public simpleFunction <double>
{
  bool _computed;
  GModel * _gm;
  const int _nbClose;
#if defined(HAVE_ANN)
  std::vector<GEntity*> _entities;
  std::vector<MVertex*> _vertices;
  std::multimap<MVertex*,MElement*> _v2e;
  ANNkd_tree *_kdtree;
  ANNpointArray _nodes;
  ANNidxArray _index;
  ANNdistArray _dist;
  void setup ();
#endif
public :
  distanceToMesh(GModel *gm, std::string physical, int nbClose = 5);
  double operator () (double x, double y, double z);
#if defined(HAVE_ANN)
  ~distanceToMesh();
#endif
}; 

#endif
