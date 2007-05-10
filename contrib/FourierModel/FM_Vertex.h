#ifndef _FM_VERTEX_H_
#define _FM_VERTEX_H_

class FM_Vertex {
 private:
  int _tag;
  double _x,_y,_z;
 public:
  FM_Vertex() : _tag(-1), _x(0), _y(0), _z(0) {}
  FM_Vertex(double x, double y, double z) : _tag(-1), _x(x), _y(y), _z(z) {}
  FM_Vertex(int tag, double x, double y, double z) : _tag(tag), 
    _x(x), _y(y), _z(z) {}
  virtual ~FM_Vertex() {}

  inline int GetTag() { return _tag; }
  inline double GetX() { return _x; }
  inline double GetY() { return _y; }
  inline double GetZ() { return _z; }

  inline void SetTag(int tag) { _tag = tag; }
  inline void SetX(double x) { _x = x; }
  inline void SetY(double y) { _y = y; }
  inline void SetZ(double z) { _z = z; }
};

#endif
