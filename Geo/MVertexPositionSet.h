// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MVERTEX_POSITION_SET_
#define _MVERTEX_POSITION_SET_

#include <vector>
#include "GmshMessage.h"
#include "MVertex.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"

// Stores MVertices in a kd-tree so we can query unique vertices (up
// to a prescribed tolerance). The constructor tags all the vertices
// with 0; find() tags the returned vertex with -1; if no
// negatively-tagged vertex exists, find() returns the closest vertex
// up to the prescribed tolerance.
class MVertexPositionSet{
 private:
  ANNkd_tree *_kdtree;
  ANNpointArray _zeronodes;
  ANNidxArray _index;
  ANNdistArray _dist;
  int _maxDuplicates;
  std::vector<MVertex*> &_vertices;
 public:
  MVertexPositionSet(std::vector<MVertex*> &vertices, int maxDuplicates=10)
    : _kdtree(0), _maxDuplicates(maxDuplicates), _vertices(vertices)
  {
    int totpoints = vertices.size();
    if(!totpoints) return;
    if(_maxDuplicates > totpoints) _maxDuplicates = totpoints;
    _zeronodes = annAllocPts(totpoints, 3);
    for(int i = 0; i < totpoints; i++){
      vertices[i]->setIndex(0);
      _zeronodes[i][0] = vertices[i]->x();
      _zeronodes[i][1] = vertices[i]->y();
      _zeronodes[i][2] = vertices[i]->z();
    }
    _kdtree = new ANNkd_tree(_zeronodes, totpoints, 3);
    _index = new ANNidx[_maxDuplicates];
    _dist = new ANNdist[_maxDuplicates];
  }
  ~MVertexPositionSet()
  {
    if(!_kdtree) return;
    delete _kdtree;
    annDeallocPts(_zeronodes);
    delete [] _index;
    delete [] _dist;
  }
  MVertex *find(double x, double y, double z, double tolerance)
  {
    if(!_kdtree) return 0;
    double xyz[3] = {x, y, z};
    _kdtree->annkSearch(xyz, _maxDuplicates, _index, _dist);
    for(int i = 0; i < _maxDuplicates; i++){
      if(_index[i] >= 0 && sqrt(_dist[i]) < tolerance &&
         _vertices[_index[i]]->getIndex() < 0)
        return _vertices[_index[i]];
    }
    if(_index[0] >= 0 && sqrt(_dist[0]) < tolerance){
      _vertices[_index[0]]->setIndex(-1);
      return _vertices[_index[0]];
    }
    Msg::Error("Could not find vertex (%g,%g,%g) (tol %g)",
               x, y, z, tolerance);
    return 0;
  }
};

#else

class MVertexPositionSet{
 public:
  MVertexPositionSet(std::vector<MVertex*> &vertices, int maxDuplicates=10){}
  ~MVertexPositionSet(){}
  MVertex *find(double x, double y, double z, double tolerance)
  {
    Msg::Error("Gmsh must be compiled with ANN to use MVertexPositionSet");
    return 0;
  }
};

#endif

#endif
