#ifndef _MVERTEX_OCTREE_
#define _MVERTEX_OCTREE_

class Octree;
class GModel;
class MVertex;

class MVertexOctree{
 private:
  Octree *_octree;
 public:
  static double tolerance;
 public:
  MVertexOctree(GModel *, double);
  ~MVertexOctree();
  void insert(MVertex *);
  void finalize();
  MVertex *find(double x, double y, double z);
};

#endif
