#include "GmshConfig.h"
#include "cartesian.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
class hiddenANN{
public: 
  ANNkd_tree *kdtree;
  ANNpointArray zeronodes;
  ANNidxArray index;
  ANNdistArray dist;
};

template <>
double cartesianBox<double>::distance (double x, double y, double z) const{
  if (!_ann){
    _ann = new hiddenANN;
    _ann->index = new ANNidx[2];
    _ann->dist = new ANNdist[2];
    if(_points.size())
      _ann->zeronodes = annAllocPts(_points.size(), 4);
    for (unsigned int i = 0; i < _points.size(); i++){
      _ann->zeronodes[i][0] = _points[i].x(); 
      _ann->zeronodes[i][1] = _points[i].y(); 
      _ann->zeronodes[i][2] = _points[i].z(); 
    }
    _ann->kdtree = new ANNkd_tree(_ann->zeronodes, _points.size(), 3);
  }
  double xyz[3] = { x, y, z };
  _ann->kdtree->annkSearch(xyz, 1, _ann->index, _ann->dist);
  SVector3 n1  = _normals[_ann->index[0]];
  //  SVector3 n2  = _normals[_ann->index[1]];
  SVector3 dx1 = SPoint3(x,y,z) - _points[_ann->index[0]];
  //  SVector3 dx2 = SPoint3(x,y,z) - _points[_ann->index[1]];
  double d1 = sqrt(_ann->dist[0]);
  //  double d2 = sqrt(_ann->dist[1]);
  double sign1 = dot(n1,dx1) > 0 ? 1. : -1.0;
  //  double sign2 = dot(n2,dx2) > 0 ? 1. : -1.0;
  //  if (fabs(d1-d2) > 1.e-4 * _dxi/((double)_Nxi)){
  return sign1 * d1;
    //  }
    //  return (sign1 != sign2) ? d1 : sign1 *d1;
}
#else
template <>
double cartesianBox<double>::distance (double x, double y, double z) const{
  printf("youpiiie\n");
  return 0.0;
}
#endif

