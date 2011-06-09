// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _BACKGROUND_MESH_H_
#define _BACKGROUND_MESH_H_

#include "STensor3.h"
#include "simpleFunction.h"
#include <vector>
#include <list>

class MElementOctree;
class GFace;
class GVertex;
class GEdge;
class MElement;
class MVertex;
class GEntity;

struct crossField2d 
{
  double _angle;
  static void normalizeAngle (double &angle) {
    if (angle < 0) 
      while ( angle <  0 ) angle += (M_PI * .5);
    else if (angle >= M_PI * .5) 
      while ( angle >= M_PI * .5 ) angle -= (M_PI * .5);
  }
  crossField2d (MVertex*, GEdge*);
  crossField2d (double a) : _angle(a){}
  crossField2d & operator += ( const crossField2d & );
};


class backgroundMesh : public simpleFunction<double>
{
  MElementOctree *_octree;
  std::vector<MVertex*> _vertices;
  std::vector<MElement*> _triangles;
  std::map<MVertex*,double> _sizes;  
  std::map<MVertex*,MVertex*> _3Dto2D;
  std::map<MVertex*,MVertex*> _2Dto3D;
  std::map<MVertex*,double> _distance;  
  std::map<MVertex*,double> _angles;  
  static backgroundMesh * _current;
  backgroundMesh(GFace *);
  ~backgroundMesh();
 public:
  static void set(GFace *);
  static void unset();
  static backgroundMesh *current () { return _current; }
  void propagate1dMesh(GFace *);
  void propagatecrossField(GFace *);
  void updateSizes(GFace *);
  double operator () (double u, double v, double w) const;
  double getAngle(double u, double v, double w) const ; 
  void print (const std::string &filename, GFace *gf, const std::map<MVertex*,double>&) const;
  void print (const std::string &filename, GFace *gf, int choice = 0) const {
    switch(choice) {
    case 0 : print(filename,gf,_sizes); return;
    default : print(filename,gf,_angles); return;
    }
  }
  MElementOctree* get_octree();
};

double BGM_MeshSize(GEntity *ge, double U, double V, double X, double Y, double Z);
SMetric3 BGM_MeshMetric(GEntity *ge, double U, double V, double X, double Y, double Z);
bool Extend1dMeshIn2dSurfaces();
bool Extend2dMeshIn3dVolumes();
SMetric3 max_edge_curvature_metric(const GVertex *gv, double &l);
SMetric3 max_edge_curvature_metric(const GEdge *ge, double u, double &l);
void replaceMeshCompound(GFace*,std::list<GEdge*>&);

#endif
