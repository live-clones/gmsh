#ifndef _FM_FACE_H_
#define _FM_FACE_H_

#include "Patch.h"
#include "FM_Edge.h"

class FM_Face {
 private:
  int _tag;
  Patch* _patch;
  std::vector<FM_Edge*> _edge;
 public:
  FM_Face() : _tag(-1), _patch(0) {}
  FM_Face(Patch* patch) : _tag(-1), _patch(patch) {}
  FM_Face(int tag, Patch* patch) : _tag(tag), _patch(patch) {}
  FM_Face(Patch* patch, std::vector<FM_Edge*> edge) :
    _tag(-1), _patch(patch), _edge(edge) {}
  FM_Face(int tag, Patch* patch, std::vector<FM_Edge*> edge) :
    _tag(tag), _patch(patch), _edge(edge) {}
  virtual ~FM_Face() {}

  inline void SetTag(int tag) { _tag = tag; }
  inline int GetTag() { return _tag; }
  inline bool IsPeriodic(int dim) { return _patch->_PI->periodic[dim]; }
  inline void AddEdge(FM_Edge* edge) { _edge.push_back(edge); }
  inline int GetNumEdges() { return _edge.size(); }
  inline FM_Edge* GetEdge(int i) { return _edge[i]; }

  void F(double u, double v, double &x, double &y, double &z);
  bool Inverse(double x,double y,double z,double &u, double &v);
  void Dfdu(double u, double v, double &x, double &y, double &z);
  void Dfdv(double u, double v, double &x, double &y, double &z);
  void Dfdfdudu(double u, double v, double &x, double &y, double &z);
  void Dfdfdudv(double u, double v, double &x, double &y, double &z);
  void Dfdfdvdv(double u, double v, double &x, double &y, double &z);
  void GetUnitNormal(double u,double v,double &x,double &y,double &z);
  void GetNormal(double u, double v, double &x, double &y, double &z);
};

#endif
