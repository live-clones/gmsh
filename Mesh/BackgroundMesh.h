// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _BACKGROUND_MESH_H_
#define _BACKGROUND_MESH_H_

#include "STensor3.h"
#include "simpleFunction.h"
#include <vector>

class MElementOctree;
class GFace;
class GVertex;
class GEdge;
class MElement;
class MVertex;
class GEntity;

class backgroundMesh : public simpleFunction<double>
{
  MElementOctree *_octree;
  std::vector<MVertex*> _vertices;
  std::vector<MElement*> _triangles;
  std::map<MVertex*,double> _sizes;  
  std::map<MVertex*,MVertex*> _3Dto2D;
  std::map<MVertex*,MVertex*> _2Dto3D;
  std::map<MVertex*,double> _distance;  
  static backgroundMesh * _current;
  backgroundMesh(GFace *);
  ~backgroundMesh();
 public:
  static void set(GFace *);
  static void unset();
  static backgroundMesh *current () { return _current; }
  void propagate1dMesh(GFace *);
  void updateSizes(GFace *);
  double operator () (double u, double v, double w) const;
  void print (const std::string &filename, GFace *gf) const;
};

double BGM_MeshSize(GEntity *ge, double U, double V, double X, double Y, double Z);
SMetric3 BGM_MeshMetric(GEntity *ge, double U, double V, double X, double Y, double Z);
bool Extend1dMeshIn2dSurfaces();
bool Extend2dMeshIn3dVolumes();
SMetric3 max_edge_curvature_metric(const GVertex *gv, double &l);
SMetric3 max_edge_curvature_metric(const GEdge *ge, double u, double &l);

#endif
