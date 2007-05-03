#ifndef _FM_EDGE_H_
#define _FM_EDGE_H_

#include "Curve.h"
#include "FM_Vertex.h"

class FM_Edge {
 private:
  Curve* _curve;
  FM_Vertex* _SP;
  FM_Vertex* _EP;
 public:
  FM_Edge() : _curve(0), _SP(0), _EP(0) {}
  FM_Edge(Curve* curve) : _curve(curve), _SP(0), _EP(0) {}
  FM_Edge(Curve* curve, FM_Vertex* SP, FM_Vertex* EP) : 
    _curve(curve), _SP(SP), _EP(EP) {}
  virtual ~FM_Edge() {}

  inline FM_Vertex* GetStartPoint() { return _SP; }
  inline FM_Vertex* GetEndPoint() { return _EP; }

  inline void SetStartPoint(FM_Vertex* SP) { _SP = SP; }
  inline void SetStartPoint(double x, double y, double z) { 
    _SP = new FM_Vertex(x,y,z); 
  }
  inline void SetEndPoint(FM_Vertex* EP) { _EP = EP; }
  inline void SetEndPoint(double x, double y, double z) { 
    _EP = new FM_Vertex(x,y,z); 
  }

  void F(double t, double &x, double &y, double &z);
  bool Inverse(double x,double y,double z,double &t);
  void Dfdt(double t, double &x, double &y, double &z);  
  void Dfdfdtdt(double t, double &x, double &y, double &z);
};

#endif
