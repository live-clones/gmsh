// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Jonathan Lambrechts
//

#include <cstdlib>
#include <limits>
#include <list>
#include <cmath>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#include "GmshConfig.h"
#include "Context.h"
#include "Field.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "mathEvaluator.h"
#include "BackgroundMeshTools.h"
#include "STensor3.h"
#include "ExtrudeParams.h"
#include "automaticMeshSizeField.h"
#include "fullMatrix.h"
#include "nanoflann.hpp"

#if defined(HAVE_POST)
#include "PView.h"
#include "OctreePost.h"
#include "PViewDataList.h"
#include "MVertex.h"
#endif

#if defined(WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#include <io.h>
#else
#include <unistd.h>
#endif

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
#endif

Field::~Field()
{
  for(auto it = options.begin(); it != options.end(); ++it) delete it->second;
  for(auto it = callbacks.begin(); it != callbacks.end(); ++it)
    delete it->second;
}

FieldOption *Field::getOption(const std::string &optionName)
{
  auto it = options.find(optionName);
  if(it == options.end()) {
    Msg::Error("Field option '%s' does not exist", optionName.c_str());
    return nullptr;
  }
  return it->second;
}

void FieldManager::reset()
{
  for(auto it = begin(); it != end(); it++) { delete it->second; }
  clear();
}

Field *FieldManager::get(int id)
{
  auto it = find(id);
  if(it == end()) return nullptr;
  return it->second;
}

Field *FieldManager::newField(int id, const std::string &type_name)
{
  if(find(id) != end()) {
    Msg::Error("Field id %i is already defined", id);
    return nullptr;
  }
  if(mapTypeName.find(type_name) == mapTypeName.end()) {
    Msg::Error("Unknown field type \"%s\"", type_name.c_str());
    return nullptr;
  }
  Field *f = (*mapTypeName[type_name])();
  if(!f) return nullptr;
  f->id = id;
  (*this)[id] = f;
  return f;
}

int FieldManager::newId()
{
  int i = 0;
  auto it = begin();
  while(1) {
    i++;
    while(it != end() && it->first < i) it++;
    if(it == end() || it->first != i) break;
  }
  return std::max(i, 1);
}

int FieldManager::maxId()
{
  if(!empty())
    return rbegin()->first;
  else
    return 0;
}

void FieldManager::deleteField(int id)
{
  auto it = find(id);
  if(it == end()) {
    Msg::Error("Cannot delete field id %i, it does not exist", id);
    return;
  }
  delete it->second;
  erase(it);
}

// StructuredField
class StructuredField : public Field {
private:
  double _o[3], _d[3];
  int _n[3];
  double *_data;
  bool _errorStatus;
  bool _textFormat, _outsideValueSet;
  double _outsideValue;
  std::string _fileName;

public:
  StructuredField()
  {
    _data = nullptr;

    options["FileName"] =
      new FieldOptionPath(_fileName, "Name of the input file", &updateNeeded);
    _textFormat = false;
    options["TextFormat"] = new FieldOptionBool(
      _textFormat,
      "True for ASCII input files, false for binary files (4 bite "
      "signed integers for n, double precision floating points for v, D and O)",
      &updateNeeded);
    options["SetOutsideValue"] = new FieldOptionBool(
      _outsideValueSet, "True to use the \"OutsideValue\" option. If False, "
                        "the last values of the grid are used.");
    options["OutsideValue"] = new FieldOptionDouble(
      _outsideValue, "Value of the field outside the grid (only used if the "
                     "\"SetOutsideValue\" option is true).");
  }
  std::string getDescription()
  {
    return "Linearly interpolate between data provided on a 3D rectangular "
           "structured grid.\n\n"
           "The format of the input file is:\n\n"
           "  Ox Oy Oz \n"
           "  Dx Dy Dz \n"
           "  nx ny nz \n"
           "  v(0,0,0) v(0,0,1) v(0,0,2) ... \n"
           "  v(0,1,0) v(0,1,1) v(0,1,2) ... \n"
           "  v(0,2,0) v(0,2,1) v(0,2,2) ... \n"
           "  ...      ...      ... \n"
           "  v(1,0,0) ...      ... \n\n"
           "where O are the coordinates of the first node, D are the distances "
           "between nodes in each direction, n are the numbers of nodes in "
           "each "
           "direction, and v are the values on each node.";
  }
  const char *getName() { return "Structured"; }
  virtual ~StructuredField()
  {
    if(_data) delete[] _data;
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    if(updateNeeded) {
      _errorStatus = false;
      try {
        std::ifstream input;
        if(_textFormat)
          input.open(_fileName.c_str());
        else
          input.open(_fileName.c_str(), std::ios::binary);
        if(!input.is_open()) throw(1);
        input.exceptions(std::ifstream::eofbit | std::ifstream::failbit |
                         std::ifstream::badbit);
        if(!_textFormat) {
          input.read((char *)_o, 3 * sizeof(double));
          input.read((char *)_d, 3 * sizeof(double));
          input.read((char *)_n, 3 * sizeof(int));
          int nt = _n[0] * _n[1] * _n[2];
          if(_data) delete[] _data;
          _data = new double[nt];
          input.read((char *)_data, nt * sizeof(double));
        }
        else {
          input >> _o[0] >> _o[1] >> _o[2] >> _d[0] >> _d[1] >> _d[2] >>
            _n[0] >> _n[1] >> _n[2];
          int nt = _n[0] * _n[1] * _n[2];
          if(_data) delete[] _data;
          _data = new double[nt];
          for(int i = 0; i < nt; i++) input >> _data[i];
        }
        input.close();
      } catch(...) {
        _errorStatus = true;
        Msg::Error("Field %i: error reading file '%s'", this->id,
                   _fileName.c_str());
      }
      updateNeeded = false;
    }
    if(_errorStatus) return MAX_LC;
    // tri-linear
    int id[2][3];
    double xi[3];
    double xyz[3] = {x, y, z};
    for(int i = 0; i < 3; i++) {
      id[0][i] = (int)floor((xyz[i] - _o[i]) / _d[i]);
      id[1][i] = id[0][i] + 1;
      if(_outsideValueSet && (id[0][i] < 0 || id[1][i] >= _n[i]) && _n[i] > 1)
        return _outsideValue;
      id[0][i] = std::max(std::min(id[0][i], _n[i] - 1), 0);
      id[1][i] = std::max(std::min(id[1][i], _n[i] - 1), 0);
      xi[i] = (xyz[i] - (_o[i] + id[0][i] * _d[i])) / _d[i];
      xi[i] = std::max(std::min(xi[i], 1.), 0.);
    }
    double v = 0;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
        for(int k = 0; k < 2; k++) {
          v += _data[id[i][0] * _n[1] * _n[2] + id[j][1] * _n[2] + id[k][2]] *
               (i * xi[0] + (1 - i) * (1 - xi[0])) *
               (j * xi[1] + (1 - j) * (1 - xi[1])) *
               (k * xi[2] + (1 - k) * (1 - xi[2]));
        }
    return v;
  }
};

class LonLatField : public Field {
private:
  int _inField, _fromStereo;
  double _stereoRadius;

public:
  std::string getDescription()
  {
    return "Evaluate Field[InField] in geographic coordinates (longitude, "
           "latitude):\n\n"
           "  F = Field[InField](atan(y/x), asin(z/sqrt(x^2+y^2+z^2))";
  }
  LonLatField()
  {
    _inField = 1;
    _fromStereo = 0;
    _stereoRadius = 6371e3;

    options["InField"] =
      new FieldOptionInt(_inField, "Tag of the field to evaluate");
    options["FromStereo"] = new FieldOptionInt(
      _fromStereo, "If = 1, the mesh is in stereographic coordinates: "
                   "xi = 2Rx/(R+z),  eta = 2Ry/(R+z)");
    options["RadiusStereo"] = new FieldOptionDouble(
      _stereoRadius, "Radius of the sphere of the stereograpic coordinates");

    // deprecated names
    options["IField"] = new FieldOptionInt(
      _inField, "Tag of the field to evaluate", nullptr, true);
  }
  const char *getName() { return "LonLat"; }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    Field *field = GModel::current()->getFields()->get(_inField);
    if(!field || _inField == id) return MAX_LC;
    if(_fromStereo == 1) {
      double xi = x;
      double eta = y;
      double r2 = _stereoRadius * _stereoRadius;
      x = 4 * r2 * xi / (4 * r2 + xi * xi + eta * eta);
      y = 4 * r2 * eta / (4 * r2 + xi * xi + eta * eta);
      z = _stereoRadius * (4 * r2 - eta * eta - xi * xi) /
          (4 * r2 + xi * xi + eta * eta);
    }
    return (*field)(atan2(y, x), asin(z / _stereoRadius), 0);
  }
};

class BoxField : public Field {
private:
  double _vIn, _vOut, _xMin, _xMax, _yMin, _yMax, _zMin, _zMax, _thick;

public:
  std::string getDescription()
  {
    return "The value of this field is VIn inside the box, VOut outside the "
           "box. The box is defined by\n\n"
           "  Xmin <= x <= XMax &&\n"
           "  YMin <= y <= YMax &&\n"
           "  ZMin <= z <= ZMax\n\n"
           "If Thickness is > 0, the mesh size is interpolated between VIn and "
           "VOut "
           "in a layer around the box of the prescribed thickness.";
  }
  BoxField()
  {
    _vIn = _vOut = _xMin = _xMax = _yMin = _yMax = _zMin = _zMax = _thick = 0;

    options["VIn"] = new FieldOptionDouble(_vIn, "Value inside the box");
    options["VOut"] = new FieldOptionDouble(_vOut, "Value outside the box");
    options["XMin"] =
      new FieldOptionDouble(_xMin, "Minimum X coordinate of the box");
    options["XMax"] =
      new FieldOptionDouble(_xMax, "Maximum X coordinate of the box");
    options["YMin"] =
      new FieldOptionDouble(_yMin, "Minimum Y coordinate of the box");
    options["YMax"] =
      new FieldOptionDouble(_yMax, "Maximum Y coordinate of the box");
    options["ZMin"] =
      new FieldOptionDouble(_zMin, "Minimum Z coordinate of the box");
    options["ZMax"] =
      new FieldOptionDouble(_zMax, "Maximum Z coordinate of the box");
    options["Thickness"] = new FieldOptionDouble(
      _thick, "Thickness of a transition layer outside the box");
  }
  const char *getName() { return "Box"; }
  using Field::operator();
  double computeDistance(double xp, double yp, double zp)
  {
    // orthogonal basis with origin (_xMin,_yMin,_zMin)
    double x0[3] = {_xMin, _yMin, _zMin};
    double x1[3] = {_xMax, _yMin, _zMin};
    double y1[3] = {_xMin, _yMax, _zMin};
    double z1[3] = {_xMin, _yMin, _zMax};
    double nx[3] = {x1[0] - x0[0], x1[1] - x0[1], x1[2] - x0[2]};
    double ny[3] = {y1[0] - x0[0], y1[1] - x0[1], y1[2] - x0[2]};
    double nz[3] = {z1[0] - x0[0], z1[1] - x0[1], z1[2] - x0[2]};
    double pvect[3] = {xp - x0[0], yp - x0[1], zp - x0[2]};
    double projX = scalProd(nx, pvect);
    double tempX = scalProd(nx, nx);
    if(tempX) projX /= tempX;
    double projY = scalProd(ny, pvect);
    double tempY = scalProd(ny, ny);
    if(tempY) projY /= tempY;
    double projZ = scalProd(nz, pvect);
    double tempZ = scalProd(nz, nz);
    if(tempZ) projZ /= tempZ;
    if(projX < 0.0) projX = 0.0;
    if(projX > 1.0) projX = 1.0;
    if(projY < 0.0) projY = 0.0;
    if(projY > 1.0) projY = 1.0;
    if(projZ < 0.0) projZ = 0.0;
    if(projZ > 1.0) projZ = 1.0;
    double psbox[3] = {x0[0] + projX * nx[0] + projY * ny[0] + projZ * nz[0],
                       x0[1] + projX * nx[1] + projY * ny[1] + projZ * nz[1],
                       x0[2] + projX * nx[2] + projY * ny[2] + projZ * nz[2]};
    double dist =
      sqrt(std::pow((psbox[0] - xp), 2) + std::pow((psbox[1] - yp), 2) +
           std::pow((psbox[2] - zp), 2));
    return dist;
  }
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    // inside
    if(x >= _xMin && x <= _xMax && y >= _yMin && y <= _yMax && z >= _zMin &&
       z <= _zMax) {
      return _vIn;
    }
    // transition layer
    if(_thick > 0) {
      double dist = computeDistance(x, y, z);
      if(dist <= _thick) return _vIn + (dist / _thick) * (_vOut - _vIn);
    }
    return _vOut;
  }
};

class CylinderField : public Field {
private:
  double _vIn, _vOut;
  double _xc, _yc, _zc;
  double _xa, _ya, _za;
  double _R;

public:
  std::string getDescription()
  {
    return "The value of this field is VIn inside a frustrated cylinder, VOut "
           "outside. "
           "The cylinder is given by\n\n"
           "  ||dX||^2 < R^2 &&\n"
           "  (X-X0).A < ||A||^2\n"
           "  dX = (X - X0) - ((X - X0).A)/(||A||^2) . A";
  }
  CylinderField()
  {
    _vIn = _vOut = _xc = _yc = _zc = _xa = _ya = _R = 0;
    _za = 1.;

    options["VIn"] = new FieldOptionDouble(_vIn, "Value inside the cylinder");
    options["VOut"] =
      new FieldOptionDouble(_vOut, "Value outside the cylinder");
    options["XCenter"] =
      new FieldOptionDouble(_xc, "X coordinate of the cylinder center");
    options["YCenter"] =
      new FieldOptionDouble(_yc, "Y coordinate of the cylinder center");
    options["ZCenter"] =
      new FieldOptionDouble(_zc, "Z coordinate of the cylinder center");
    options["XAxis"] =
      new FieldOptionDouble(_xa, "X component of the cylinder axis");
    options["YAxis"] =
      new FieldOptionDouble(_ya, "Y component of the cylinder axis");
    options["ZAxis"] =
      new FieldOptionDouble(_za, "Z component of the cylinder axis");
    options["Radius"] = new FieldOptionDouble(_R, "Radius");
  }
  const char *getName() { return "Cylinder"; }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    double dx = x - _xc;
    double dy = y - _yc;
    double dz = z - _zc;

    double adx =
      (_xa * dx + _ya * dy + _za * dz) / (_xa * _xa + _ya * _ya + _za * _za);

    dx -= adx * _xa;
    dy -= adx * _ya;
    dz -= adx * _za;

    return ((dx * dx + dy * dy + dz * dz < _R * _R) && fabs(adx) < 1) ? _vIn :
                                                                        _vOut;
  }
};

class BallField : public Field {
private:
  double _vIn, _vOut;
  double _xc, _yc, _zc;
  double _R, _thick;

public:
  std::string getDescription()
  {
    return "The value of this field is VIn inside a spherical ball, VOut "
           "outside. "
           "The ball is defined by\n\n"
           "  ||dX||^2 < R^2 &&\n"
           "  dX = (X - XC)^2 + (Y-YC)^2 + (Z-ZC)^2\n\n"
           "If Thickness is > 0, the mesh size is interpolated between VIn and "
           "VOut "
           "in a layer around the ball of the prescribed thickness.";
  }
  BallField()
  {
    _vIn = _vOut = _xc = _yc = _zc = _R = _thick = 0;

    options["VIn"] = new FieldOptionDouble(_vIn, "Value inside the ball");
    options["VOut"] = new FieldOptionDouble(_vOut, "Value outside the ball");
    options["XCenter"] =
      new FieldOptionDouble(_xc, "X coordinate of the ball center");
    options["YCenter"] =
      new FieldOptionDouble(_yc, "Y coordinate of the ball center");
    options["ZCenter"] =
      new FieldOptionDouble(_zc, "Z coordinate of the ball center");
    options["Radius"] = new FieldOptionDouble(_R, "Radius");
    options["Thickness"] = new FieldOptionDouble(
      _thick, "Thickness of a transition layer outside the ball");
  }
  const char *getName() { return "Ball"; }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    double dx = x - _xc;
    double dy = y - _yc;
    double dz = z - _zc;
    double d = sqrt(dx * dx + dy * dy + dz * dz);
    if(d < _R) return _vIn;
    // transition layer
    if(_thick > 0) {
      double dist = d - _R;
      if(dist <= _thick) return _vIn + (dist / _thick) * (_vOut - _vIn);
    }
    return _vOut;
  }
};

class FrustumField : public Field {
private:
  double _x1, _y1, _z1;
  double _x2, _y2, _z2;
  double _r1i, _r1o, _r2i, _r2o;
  double _v1i, _v1o, _v2i, _v2o;

public:
  std::string getDescription()
  {
    return "This field is an extended cylinder with inner (i) and outer (o) "
           "radiuses"
           "on both endpoints (1 and 2). Length scale is bilinearly "
           "interpolated between"
           "these locations (inner and outer radiuses, endpoints 1 and 2)"
           "The field values for a point P are given by :"
           "  u = P1P.P1P2/||P1P2|| "
           "  r = || P1P - u*P1P2 || "
           "  Ri = (1-u)*R1i + u*R2i "
           "  Ro = (1-u)*R1o + u*R2o "
           "  v = (r-Ri)/(Ro-Ri)"
           "  lc = (1-v)*( (1-u)*v1i + u*v2i ) + v*( (1-u)*v1o + u*v2o )"
           "    where (u,v) in [0,1]x[0,1]";
  }
  FrustumField()
  {
    _x1 = _y1 = _z1 = 0.;
    _x2 = _y2 = 0.;
    _z1 = 1.;
    _r1i = _r2i = 0.;
    _r1o = _r2o = 1.;
    _v1i = _v2i = 0.1;
    _v1o = _v2o = 1.;

    options["X1"] = new FieldOptionDouble(_x1, "X coordinate of endpoint 1");
    options["Y1"] = new FieldOptionDouble(_y1, "Y coordinate of endpoint 1");
    options["Z1"] = new FieldOptionDouble(_z1, "Z coordinate of endpoint 1");
    options["X2"] = new FieldOptionDouble(_x2, "X coordinate of endpoint 2");
    options["Y2"] = new FieldOptionDouble(_y2, "Y coordinate of endpoint 2");
    options["Z2"] = new FieldOptionDouble(_z2, "Z coordinate of endpoint 2");
    options["InnerR1"] =
      new FieldOptionDouble(_r1i, "Inner radius of Frustum at endpoint 1");
    options["OuterR1"] =
      new FieldOptionDouble(_r1o, "Outer radius of Frustum at endpoint 1");
    options["InnerR2"] =
      new FieldOptionDouble(_r2i, "Inner radius of Frustum at endpoint 2");
    options["OuterR2"] =
      new FieldOptionDouble(_r2o, "Outer radius of Frustum at endpoint 2");
    options["InnerV1"] =
      new FieldOptionDouble(_v1i, "Element size at point 1, inner radius");
    options["OuterV1"] =
      new FieldOptionDouble(_v1o, "Element size at point 1, outer radius");
    options["InnerV2"] =
      new FieldOptionDouble(_v2i, "Element size at point 2, inner radius");
    options["OuterV2"] =
      new FieldOptionDouble(_v2o, "Element size at point 2, outer radius");

    // deprecated names
    options["R1_inner"] = new FieldOptionDouble(
      _r1i, "Inner radius of Frustum at endpoint 1", nullptr, true);
    options["R1_outer"] = new FieldOptionDouble(
      _r1o, "Outer radius of Frustum at endpoint 1", nullptr, true);
    options["R2_inner"] = new FieldOptionDouble(
      _r2i, "Inner radius of Frustum at endpoint 2", nullptr, true);
    options["R2_outer"] = new FieldOptionDouble(
      _r2o, "Outer radius of Frustum at endpoint 2", nullptr, true);
    options["V1_inner"] = new FieldOptionDouble(
      _v1i, "Element size at point 1, inner radius", nullptr, true);
    options["V1_outer"] = new FieldOptionDouble(
      _v1o, "Element size at point 1, outer radius", nullptr, true);
    options["V2_inner"] = new FieldOptionDouble(
      _v2i, "Element size at point 2, inner radius", nullptr, true);
    options["V2_outer"] = new FieldOptionDouble(
      _v2o, "Element size at point 2, outer radius", nullptr, true);
  }
  const char *getName() { return "Frustum"; }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    double dx = x - _x1;
    double dy = y - _y1;
    double dz = z - _z1;
    double x12 = _x2 - _x1;
    double y12 = _y2 - _y1;
    double z12 = _z2 - _z1;
    double l12 = sqrt(x12 * x12 + y12 * y12 + z12 * z12);

    double l = (dx * x12 + dy * y12 + dz * z12) / l12;
    double r = sqrt(dx * dx + dy * dy + dz * dz - l * l);

    double u = l / l12; // u varies between 0 (P1) and 1 (P2)
    double ri = (1 - u) * _r1i + u * _r2i;
    double ro = (1 - u) * _r1o + u * _r2o;
    double v = (r - ri) / (ro - ri); // v varies between 0 (inner) and 1 (outer)

    double lc = MAX_LC;
    if(u >= 0 && u <= 1 && v >= 0 && v <= 1) {
      lc =
        (1 - v) * ((1 - u) * _v1i + u * _v2i) + v * ((1 - u) * _v1o + u * _v2o);
    }
    return lc;
  }
};

class ThresholdField : public Field {
protected:
  int _inField;
  double _dMin, _dMax, _lcMin, _lcMax;
  bool _sigmoid, _stopAtDistMax;

public:
  virtual const char *getName() { return "Threshold"; }
  virtual std::string getDescription()
  {
    return "F = SizeMin if Field[InField] <= DistMin,\n"
           "F = SizeMax if Field[InField] >= DistMax,\n"
           "F = interpolation between SizeMin and SizeMax if DistMin < "
           "Field[InField] < DistMax";
  }
  ThresholdField()
  {
    _inField = 0;
    _dMin = 1;
    _dMax = 10;
    _lcMin = 0.1;
    _lcMax = 1;
    _sigmoid = false;
    _stopAtDistMax = false;

    options["InField"] =
      new FieldOptionInt(_inField, "Tag of the field to evaluate");
    options["DistMin"] = new FieldOptionDouble(
      _dMin, "Distance from entity up to which element size will be SizeMin");
    options["DistMax"] = new FieldOptionDouble(
      _dMax, "Distance from entity after which element size will be SizeMax");
    options["SizeMin"] =
      new FieldOptionDouble(_lcMin, "Element size inside DistMin");
    options["SizeMax"] =
      new FieldOptionDouble(_lcMax, "Element size outside DistMax");
    options["Sigmoid"] = new FieldOptionBool(
      _sigmoid,
      "True to interpolate between SizeMin and LcMax using a sigmoid, "
      "false to interpolate linearly");
    options["StopAtDistMax"] = new FieldOptionBool(
      _stopAtDistMax, "True to not impose element size outside DistMax (i.e., "
                      "F = a very big value if Field[InField] > DistMax)");

    // deprecated names
    options["IField"] = new FieldOptionInt(
      _inField, "Tag of the field to evaluate", nullptr, true);
    options["LcMin"] = new FieldOptionDouble(
      _lcMin, "Element size inside DistMin", nullptr, true);
    options["LcMax"] = new FieldOptionDouble(
      _lcMax, "Element size outside DistMax", nullptr, true);
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    Field *field = GModel::current()->getFields()->get(_inField);
    if(!field || _inField == id) return MAX_LC;
    double r = ((*field)(x, y, z) - _dMin) / (_dMax - _dMin);
    r = std::max(std::min(r, 1.), 0.);
    double lc;
    if(_stopAtDistMax && r >= 1.) { lc = MAX_LC; }
    else if(_sigmoid) {
      double s = exp(12. * r - 6.) / (1. + exp(12. * r - 6.));
      lc = _lcMin * (1. - s) + _lcMax * s;
    }
    else { // linear
      lc = _lcMin * (1 - r) + _lcMax * r;
    }
    return lc;
  }
};

class GradientField : public Field {
private:
  int _inField, _kind;
  double _delta;

public:
  const char *getName() { return "Gradient"; }
  std::string getDescription()
  {
    return "Compute the finite difference gradient of Field[InField]:\n\n"
           "  F = (Field[InField](X + Delta/2) - "
           "       Field[InField](X - Delta/2)) / Delta";
  }
  GradientField() : _inField(0), _kind(3), _delta(CTX::instance()->lc / 1e4)
  {
    _inField = 1;
    _kind = 0;
    _delta = 0.;

    options["InField"] = new FieldOptionInt(_inField, "Input field tag");
    options["Kind"] = new FieldOptionInt(
      _kind,
      "Component of the gradient to evaluate: 0 for X, 1 for Y, 2 for Z, "
      "3 for the norm");
    options["Delta"] = new FieldOptionDouble(_delta, "Finite difference step");

    // deprecated names
    options["IField"] =
      new FieldOptionInt(_inField, "Input field tag", nullptr, true);
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    Field *field = GModel::current()->getFields()->get(_inField);
    if(!field || _inField == id) return MAX_LC;
    double gx, gy, gz;
    switch(_kind) {
    case 0: /* x */
      return ((*field)(x + _delta / 2, y, z) - (*field)(x - _delta / 2, y, z)) /
             _delta;
    case 1: /* y */
      return ((*field)(x, y + _delta / 2, z) - (*field)(x, y - _delta / 2, z)) /
             _delta;
    case 2: /* z */
      return ((*field)(x, y, z + _delta / 2) - (*field)(x, y, z - _delta / 2)) /
             _delta;
    case 3: /* norm */
      gx = ((*field)(x + _delta / 2, y, z) - (*field)(x - _delta / 2, y, z)) /
           _delta;
      gy = ((*field)(x, y + _delta / 2, z) - (*field)(x, y - _delta / 2, z)) /
           _delta;
      gz = ((*field)(x, y, z + _delta / 2) - (*field)(x, y, z - _delta / 2)) /
           _delta;
      return sqrt(gx * gx + gy * gy + gz * gz);
    default:
      Msg::Error("Field %i: unknown kind (%i) of gradient", this->id, _kind);
      return MAX_LC;
    }
  }
};

class CurvatureField : public Field {
private:
  int _inField;
  double _delta;

public:
  const char *getName() { return "Curvature"; }
  std::string getDescription()
  {
    return "Compute the curvature of Field[InField]:\n\n"
           "  F = div(norm(grad(Field[InField])))";
  }
  CurvatureField() : _inField(0), _delta(CTX::instance()->lc / 1e4)
  {
    _inField = 1;
    _delta = 0.;

    options["InField"] = new FieldOptionInt(_inField, "Input field tag");
    options["Delta"] =
      new FieldOptionDouble(_delta, "Step of the finite differences");

    // deprecated names
    options["IField"] =
      new FieldOptionInt(_inField, "Input field tag", nullptr, true);
  }
  void grad_norm(Field &f, double x, double y, double z, double *g)
  {
    g[0] = f(x + _delta / 2, y, z) - f(x - _delta / 2, y, z);
    g[1] = f(x, y + _delta / 2, z) - f(x, y - _delta / 2, z);
    g[2] = f(x, y, z + _delta / 2) - f(x, y, z - _delta / 2);
    double n = sqrt(g[0] * g[0] + g[1] * g[1] + g[2] * g[2]);
    g[0] /= n;
    g[1] /= n;
    g[2] /= n;
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    Field *field = GModel::current()->getFields()->get(_inField);
    if(!field || _inField == id) return MAX_LC;
    double grad[6][3];
    grad_norm(*field, x + _delta / 2, y, z, grad[0]);
    grad_norm(*field, x - _delta / 2, y, z, grad[1]);
    grad_norm(*field, x, y + _delta / 2, z, grad[2]);
    grad_norm(*field, x, y - _delta / 2, z, grad[3]);
    grad_norm(*field, x, y, z + _delta / 2, grad[4]);
    grad_norm(*field, x, y, z - _delta / 2, grad[5]);
    return (grad[0][0] - grad[1][0] + grad[2][1] - grad[3][1] + grad[4][2] -
            grad[5][2]) /
           _delta;
  }
};

class MaxEigenHessianField : public Field {
private:
  int _inField;
  double _delta;

public:
  const char *getName() { return "MaxEigenHessian"; }
  std::string getDescription()
  {
    return "Compute the maximum eigenvalue of the Hessian matrix of "
           "Field[InField], with the gradients evaluated by finite "
           "differences:\n\n"
           "  F = max(eig(grad(grad(Field[InField]))))";
  }
  MaxEigenHessianField() : _inField(0), _delta(CTX::instance()->lc / 1e4)
  {
    _inField = 1;
    _delta = 0.;

    options["InField"] = new FieldOptionInt(_inField, "Input field tag");
    options["Delta"] =
      new FieldOptionDouble(_delta, "Step used for the finite differences");

    // deprecated names
    options["IField"] =
      new FieldOptionInt(_inField, "Input field tag", nullptr, true);
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    Field *field = GModel::current()->getFields()->get(_inField);
    if(!field || _inField == id) return MAX_LC;
    double mat[3][3], eig[3];
    mat[1][0] = mat[0][1] = (*field)(x + _delta / 2, y + _delta / 2, z) +
                            (*field)(x - _delta / 2, y - _delta / 2, z) -
                            (*field)(x - _delta / 2, y + _delta / 2, z) -
                            (*field)(x + _delta / 2, y - _delta / 2, z);
    mat[2][0] = mat[0][2] = (*field)(x + _delta / 2, y, z + _delta / 2) +
                            (*field)(x - _delta / 2, y, z - _delta / 2) -
                            (*field)(x - _delta / 2, y, z + _delta / 2) -
                            (*field)(x + _delta / 2, y, z - _delta / 2);
    mat[2][1] = mat[1][2] = (*field)(x, y + _delta / 2, z + _delta / 2) +
                            (*field)(x, y - _delta / 2, z - _delta / 2) -
                            (*field)(x, y - _delta / 2, z + _delta / 2) -
                            (*field)(x, y + _delta / 2, z - _delta / 2);
    double f = (*field)(x, y, z);
    mat[0][0] = (*field)(x + _delta, y, z) + (*field)(x - _delta, y, z) - 2 * f;
    mat[1][1] = (*field)(x, y + _delta, z) + (*field)(x, y - _delta, z) - 2 * f;
    mat[2][2] = (*field)(x, y, z + _delta) + (*field)(x, y, z - _delta) - 2 * f;
    eigenvalue(mat, eig);
    return eig[0] / (_delta * _delta);
  }
};

class LaplacianField : public Field {
private:
  int _inField;
  double _delta;

public:
  const char *getName() { return "Laplacian"; }
  std::string getDescription()
  {
    return "Compute finite difference the Laplacian of Field[InField]:\n\n"
           "  F = G(x+d,y,z) + G(x-d,y,z) +\n"
           "      G(x,y+d,z) + G(x,y-d,z) +\n"
           "      G(x,y,z+d) + G(x,y,z-d) - 6 * G(x,y,z),\n\n"
           "where G = Field[InField] and d = Delta";
  }
  LaplacianField() : _inField(0), _delta(CTX::instance()->lc / 1e4)
  {
    _inField = 1;
    _delta = 0.1;

    options["InField"] = new FieldOptionInt(_inField, "Input field tag");
    options["Delta"] = new FieldOptionDouble(_delta, "Finite difference step");

    // deprecated names
    options["IField"] =
      new FieldOptionInt(_inField, "Input field tag", nullptr, true);
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    Field *field = GModel::current()->getFields()->get(_inField);
    if(!field || _inField == id) return MAX_LC;
    return ((*field)(x + _delta, y, z) + (*field)(x - _delta, y, z) +
            (*field)(x, y + _delta, z) + (*field)(x, y - _delta, z) +
            (*field)(x, y, z + _delta) + (*field)(x, y, z - _delta) -
            6 * (*field)(x, y, z)) /
           (_delta * _delta);
  }
};

class MeanField : public Field {
private:
  int _inField;
  double _delta;

public:
  const char *getName() { return "Mean"; }
  std::string getDescription()
  {
    return "Simple smoother:\n\n"
           "  F = (G(x+delta,y,z) + G(x-delta,y,z) +\n"
           "       G(x,y+delta,z) + G(x,y-delta,z) +\n"
           "       G(x,y,z+delta) + G(x,y,z-delta) +\n"
           "       G(x,y,z)) / 7,\n\n"
           "where G = Field[InField]";
  }
  MeanField() : _inField(0), _delta(CTX::instance()->lc / 1e4)
  {
    options["InField"] = new FieldOptionInt(_inField, "Input field tag");
    options["Delta"] =
      new FieldOptionDouble(_delta, "Distance used to compute the mean value");

    // deprecated names
    options["IField"] =
      new FieldOptionInt(_inField, "Input field tag", nullptr, true);
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    Field *field = GModel::current()->getFields()->get(_inField);
    if(!field || _inField == id) return MAX_LC;
    return ((*field)(x + _delta, y, z) + (*field)(x - _delta, y, z) +
            (*field)(x, y + _delta, z) + (*field)(x, y - _delta, z) +
            (*field)(x, y, z + _delta) + (*field)(x, y, z - _delta) +
            (*field)(x, y, z)) /
           7;
  }
};

class MathEvalExpression {
private:
  mathEvaluator *_f;
  std::set<int> _fields;

public:
  MathEvalExpression() : _f(nullptr) {}
  ~MathEvalExpression()
  {
    if(_f) delete _f;
  }
  bool set_function(const std::string &f)
  {
    // get id numbers of fields appearing in the function
    _fields.clear();
    std::size_t i = 0;
    while(i < f.size()) {
      std::size_t j = 0;
      if(f[i] == 'F') {
        std::string id("");
        while(i + 1 + j < f.size() && f[i + 1 + j] >= '0' &&
              f[i + 1 + j] <= '9') {
          id += f[i + 1 + j];
          j++;
        }
        _fields.insert(atoi(id.c_str()));
      }
      i += j + 1;
    }
    std::vector<std::string> expressions(1), variables(3 + _fields.size());
    expressions[0] = f;
    variables[0] = "x";
    variables[1] = "y";
    variables[2] = "z";
    i = 3;
    for(auto it = _fields.begin(); it != _fields.end(); it++) {
      std::ostringstream sstream;
      sstream << "F" << *it;
      variables[i++] = sstream.str();
    }
    if(_f) delete _f;
    _f = new mathEvaluator(expressions, variables);
    if(expressions.empty()) {
      delete _f;
      _f = nullptr;
      return false;
    }
    return true;
  }
  double evaluate(double x, double y, double z)
  {
    if(!_f) return MAX_LC;
    std::vector<double> values(3 + _fields.size()), res(1);
    values[0] = x;
    values[1] = y;
    values[2] = z;
    int i = 3;
    for(auto it = _fields.begin(); it != _fields.end(); it++) {
      Field *field = GModel::current()->getFields()->get(*it);
      values[i++] = field ? (*field)(x, y, z) : MAX_LC;
    }
    if(_f->eval(values, res))
      return res[0];
    else
      return MAX_LC;
  }
};

class MathEvalExpressionAniso {
private:
  mathEvaluator *_f[6];
  std::set<int> _fields[6];

public:
  MathEvalExpressionAniso()
  {
    for(int i = 0; i < 6; i++) _f[i] = nullptr;
  }
  ~MathEvalExpressionAniso()
  {
    for(int i = 0; i < 6; i++)
      if(_f[i]) delete _f[i];
  }
  bool set_function(int iFunction, const std::string &f)
  {
    // get id numbers of fields appearing in the function
    _fields[iFunction].clear();
    std::size_t i = 0;
    while(i < f.size()) {
      std::size_t j = 0;
      if(f[i] == 'F') {
        std::string id("");
        while(i + 1 + j < f.size() && f[i + 1 + j] >= '0' &&
              f[i + 1 + j] <= '9') {
          id += f[i + 1 + j];
          j++;
        }
        _fields[iFunction].insert(atoi(id.c_str()));
      }
      i += j + 1;
    }
    std::vector<std::string> expressions(1),
      variables(3 + _fields[iFunction].size());
    expressions[0] = f;
    variables[0] = "x";
    variables[1] = "y";
    variables[2] = "z";
    i = 3;
    for(auto it = _fields[iFunction].begin(); it != _fields[iFunction].end();
        it++) {
      std::ostringstream sstream;
      sstream << "F" << *it;
      variables[i++] = sstream.str();
    }
    if(_f[iFunction]) delete _f[iFunction];
    _f[iFunction] = new mathEvaluator(expressions, variables);
    if(expressions.empty()) {
      delete _f[iFunction];
      _f[iFunction] = nullptr;
      return false;
    }
    return true;
  }
  void evaluate(double x, double y, double z, SMetric3 &metr)
  {
    const int index[6][2] = {{0, 0}, {1, 1}, {2, 2}, {0, 1}, {0, 2}, {1, 2}};
    for(int iFunction = 0; iFunction < 6; iFunction++) {
      if(!_f[iFunction])
        metr(index[iFunction][0], index[iFunction][1]) = MAX_LC;
      else {
        std::vector<double> values(3 + _fields[iFunction].size()), res(1);
        values[0] = x;
        values[1] = y;
        values[2] = z;
        int i = 3;
        for(auto it = _fields[iFunction].begin();
            it != _fields[iFunction].end(); it++) {
          Field *field = GModel::current()->getFields()->get(*it);
          values[i++] = field ? (*field)(x, y, z) : MAX_LC;
        }
        if(_f[iFunction]->eval(values, res))
          metr(index[iFunction][0], index[iFunction][1]) = res[0];
        else
          metr(index[iFunction][0], index[iFunction][1]) = MAX_LC;
      }
    }
  }
};

class MathEvalField : public Field {
private:
  MathEvalExpression _expr;
  std::string _f;

public:
  MathEvalField()
  {
    _f = "F2 + Sin(z)";
    options["F"] = new FieldOptionString(
      _f, "Mathematical function to evaluate.", &updateNeeded);
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    double ret = 0;
#if defined(_OPENMP)
#pragma omp critical
#endif
    {
      if(updateNeeded) {
        if(!_expr.set_function(_f))
          Msg::Error("Field %i: invalid matheval expression \"%s\"", this->id,
                     _f.c_str());
        updateNeeded = false;
      }
      ret = _expr.evaluate(x, y, z);
    }
    return ret;
  }
  const char *getName() { return "MathEval"; }
  std::string getDescription()
  {
    return "Evaluate a mathematical expression. The expression can contain "
           "x, y, z for spatial coordinates, F0, F1, ... for field values, and "
           "and mathematical functions.";
  }
};

class MathEvalFieldAniso : public Field {
private:
  MathEvalExpressionAniso _expr;
  std::string _f[6];

public:
  virtual bool isotropic() const { return false; }
  MathEvalFieldAniso()
  {
    _f[0] = "F2 + Sin(z)";
    _f[1] = "F2 + Sin(z)";
    _f[2] = "F2 + Sin(z)";
    _f[3] = "F2 + Sin(z)";
    _f[4] = "F2 + Sin(z)";
    _f[5] = "F2 + Sin(z)";

    options["M11"] = new FieldOptionString(
      _f[0], "Element 11 of the metric tensor", &updateNeeded);
    options["M22"] = new FieldOptionString(
      _f[1], "Element 22 of the metric tensor", &updateNeeded);
    options["M33"] = new FieldOptionString(
      _f[2], "Element 33 of the metric tensor", &updateNeeded);
    options["M12"] = new FieldOptionString(
      _f[3], "Element 12 of the metric tensor", &updateNeeded);
    options["M13"] = new FieldOptionString(
      _f[4], "Element 13 of the metric tensor", &updateNeeded);
    options["M23"] = new FieldOptionString(
      _f[5], "Element 23 of the metric tensor", &updateNeeded);

    // deprecated names
    options["m11"] = new FieldOptionString(
      _f[0], "Element 11 of the metric tensor", &updateNeeded, true);
    options["m22"] = new FieldOptionString(
      _f[1], "Element 22 of the metric tensor", &updateNeeded, true);
    options["m33"] = new FieldOptionString(
      _f[2], "Element 33 of the metric tensor", &updateNeeded, true);
    options["m12"] = new FieldOptionString(
      _f[3], "Element 12 of the metric tensor", &updateNeeded, true);
    options["m13"] = new FieldOptionString(
      _f[4], "Element 13 of the metric tensor", &updateNeeded, true);
    options["m23"] = new FieldOptionString(
      _f[5], "Element 23 of the metric tensor", &updateNeeded, true);
  }
  void operator()(double x, double y, double z, SMetric3 &metr,
                  GEntity *ge = nullptr)
  {
#if defined(_OPENMP)
#pragma omp critical
#endif
    {
      if(updateNeeded) {
        for(int i = 0; i < 6; i++) {
          if(!_expr.set_function(i, _f[i]))
            Msg::Error("Field %i: invalid matheval expression \"%s\"", this->id,
                       _f[i].c_str());
        }
        updateNeeded = false;
      }
      _expr.evaluate(x, y, z, metr);
    }
  }
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    SMetric3 metr;
#if defined(_OPENMP)
#pragma omp critical
#endif
    {
      if(updateNeeded) {
        for(int i = 0; i < 6; i++) {
          if(!_expr.set_function(i, _f[i]))
            Msg::Error("Field %i: invalid matheval expression \"%s\"", this->id,
                       _f[i].c_str());
        }
        updateNeeded = false;
      }
      _expr.evaluate(x, y, z, metr);
    }
    return metr(0, 0);
  }
  const char *getName() { return "MathEvalAniso"; }
  std::string getDescription()
  {
    return "Evaluate a metric expression. The expressions can contain "
           "x, y, z for spatial coordinates, F0, F1, ... for field values, and "
           "and mathematical functions.";
  }
};

#if defined(WIN32) && !defined(__CYGWIN__)
// windows implementation from
// https://msdn.microsoft.com/en-us/library/windows/desktop/ms682499(v=vs.85).aspx
class Popen2 {
private:
  HANDLE _hIn, _hOut;

public:
  Popen2()
  {
    _hIn = nullptr;
    _hOut = nullptr;
  }
  void stop()
  {
    if(_hIn) {
      CloseHandle(_hIn);
      CloseHandle(_hOut);
      _hIn = _hOut = nullptr;
    }
  }
  bool started() const { return _hIn; }
  bool start(const char *command)
  {
    stop();
    HANDLE hChildStd_OUT_Wr, hChildStd_IN_Rd;
    PROCESS_INFORMATION piProcInfo;
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = nullptr;
    if(!CreatePipe(&_hIn, &hChildStd_OUT_Wr, &saAttr, 0))
      Msg::Error("StdoutRd CreatePipe");
    if(!CreatePipe(&hChildStd_IN_Rd, &_hOut, &saAttr, 0))
      Msg::Error("Stdin CreatePipe");
    if(!CreatePipe(&_hIn, &hChildStd_OUT_Wr, &saAttr, 0))
      Msg::Error("StdoutRd CreatePipe");
    if(!SetHandleInformation(_hIn, HANDLE_FLAG_INHERIT, 0))
      Msg::Error("Stdout SetHandleInformation");
    STARTUPINFO siStartInfo;
    BOOL bSuccess = FALSE;
    ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
    siStartInfo.cb = sizeof(STARTUPINFO);
    siStartInfo.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    siStartInfo.hStdOutput = hChildStd_OUT_Wr;
    siStartInfo.hStdInput = hChildStd_IN_Rd;
    siStartInfo.dwFlags |= STARTF_USESTDHANDLES;
    bSuccess = CreateProcess(nullptr, (char *)command, nullptr, nullptr, TRUE,
                             0, nullptr, nullptr, &siStartInfo, &piProcInfo);
    if(!bSuccess) {
      Msg::Error("Child process creation failed %i", GetLastError());
      _hIn = _hOut = nullptr;
      return false;
    }
    CloseHandle(piProcInfo.hProcess);
    CloseHandle(piProcInfo.hThread);
    return true;
  }
  bool read(void *data, size_t size)
  {
    if(!_hIn) return false;
    DWORD nSuccess = 0;
    ReadFile(_hIn, data, size, &nSuccess, nullptr);
    return nSuccess == size;
  }
  bool write(void *data, size_t size)
  {
    if(!_hOut) return false;
    DWORD nSuccess = 0;
    WriteFile(_hOut, data, size, &nSuccess, nullptr);
    return nSuccess == size;
  }
  ~Popen2() { stop(); }
};

#else // unix

class Popen2 {
private:
  int _fdIn, _fdOut;

public:
  Popen2() { _fdIn = _fdOut = -1; }
  void stop()
  {
    if(_fdIn != -1) {
      ::close(_fdIn);
      ::close(_fdOut);
      _fdIn = _fdOut = -1;
    }
  }
  bool started() const { return _fdIn; }
  bool start(const char *command)
  {
    stop();
    int p_stdin[2], p_stdout[2];
    if(pipe(p_stdin) != 0 || pipe(p_stdout) != 0) return false;
    int pid = fork();
    if(pid < 0)
      return false;
    else if(pid == 0) {
      close(p_stdin[1]);
      dup2(p_stdin[0], 0);
      close(p_stdout[0]);
      dup2(p_stdout[1], 1);
      execl("/bin/sh", "sh", "-c", command, nullptr);
      perror("execl");
      exit(0);
    }
    _fdOut = p_stdin[1];
    _fdIn = p_stdout[0];
    return true;
  }
  bool read(void *data, size_t size)
  {
    return ::read(_fdIn, data, size) == (ssize_t)size;
  }
  bool write(void *data, size_t size)
  {
    return ::write(_fdOut, data, size) == (ssize_t)size;
  }
  ~Popen2() { stop(); }
};
#endif

class ExternalProcessField : public Field {
private:
  std::string _cmdLine;
  Popen2 _pipes;
  void closePipes()
  {
    if(_pipes.started()) {
      double xyz[3] = {std::numeric_limits<double>::quiet_NaN(),
                       std::numeric_limits<double>::quiet_NaN(),
                       std::numeric_limits<double>::quiet_NaN()};
      _pipes.write((void *)xyz, 3 * sizeof(double));
      _pipes.stop();
    }
  }

public:
  ExternalProcessField()
  {
    _cmdLine = "";

    options["CommandLine"] =
      new FieldOptionString(_cmdLine, "Command line to launch", &updateNeeded);
  }
  ~ExternalProcessField() { closePipes(); }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    double xyz[3] = {x, y, z};
    double f;
    if(updateNeeded) {
      closePipes();
      _pipes.start(_cmdLine.c_str());
      updateNeeded = false;
    }
    if(!_pipes.write((void *)xyz, 3 * sizeof(double)) ||
       !_pipes.read((void *)&f, sizeof(double))) {
      f = 1e22; // std::numeric_limits<double>::max();
    }
    return f;
  }
  const char *getName() { return "ExternalProcess"; }
  std::string getDescription()
  {
    return "**This Field is experimental**\n"
           "Call an external process that received coordinates triple (x,y,z) "
           "as binary double precision numbers on stdin and is supposed to "
           "write the "
           "field value on stdout as a binary double precision number.\n"
           "NaN,NaN,NaN is sent as coordinate to indicate the end of the "
           "process.\n"
           "\n"
           "Example of client (python2):\n"
           "import os\n"
           "import struct\n"
           "import math\n"
           "import sys\n"
           "if sys.platform == \"win32\" :\n"
           "import msvcrt\n"
           "msvcrt.setmode(0, os.O_BINARY)\n"
           "msvcrt.setmode(1, os.O_BINARY)\n"
           "while(True):\n"
           "____xyz = struct.unpack(\"ddd\", os.read(0,24))\n"
           "____if math.isnan(xyz[0]):\n"
           "_________break\n"
           "____f = 0.001 + xyz[1]*0.009\n"
           "____os.write(1,struct.pack(\"d\",f))\n"
           "\n"
           "Example of client (python3):\n"
           "import struct\n"
           "import sys\n"
           "import math\n"
           "while(True):\n"
           "____xyz = struct.unpack(\"ddd\", sys.stdin.buffer.read(24))\n"
           "____if math.isnan(xyz[0]):\n"
           "________break\n"
           "____f = 0.001 + xyz[1]*0.009\n"
           "____sys.stdout.buffer.write(struct.pack(\"d\",f))\n"
           "____sys.stdout.flush()\n"
           "\n"
           "Example of client (c, unix):\n"
           "#include <unistd.h>\n"
           "int main(int argc, char **argv) {\n"
           "__double xyz[3];\n"
           "__while(read(STDIN_FILENO, &xyz, 3*sizeof(double)) == "
           "3*sizeof(double)) {\n"
           "____if (xyz[0] != xyz[0]) break; //nan\n"
           "____double f = 0.001 + 0.009 * xyz[1];\n"
           "____write(STDOUT_FILENO, &f, sizeof(double));\n"
           "__}\n"
           "__return 0;\n"
           "}\n"
           "\n"
           "Example of client (c, windows):\n"
           "#include <stdio.h>\n"
           "#include <io.h>\n"
           "#include <fcntl.h>\n"
           "int main(int argc, char **argv) {\n"
           "__double xyz[3];\n"
           "__setmode(fileno(stdin),O_BINARY);\n"
           "__setmode(fileno(stdout),O_BINARY);\n"
           "__while(read(fileno(stdin), &xyz, 3*sizeof(double)) == "
           "3*sizeof(double)) {\n"
           "____if (xyz[0] != xyz[0])\n"
           "______break;\n"
           "____double f = f = 0.01 + 0.09 * xyz[1];\n"
           "____write(fileno(stdout), &f, sizeof(double));\n"
           "__}\n"
           "}\n";
  }
};

class ParametricField : public Field {
private:
  MathEvalExpression _expr[3];
  std::string _f[3];
  int _inField;

public:
  ParametricField()
  {
    _inField = 1;

    options["InField"] = new FieldOptionInt(_inField, "Input field tag");
    options["FX"] = new FieldOptionString(
      _f[0], "X component of parametric function", &updateNeeded);
    options["FY"] = new FieldOptionString(
      _f[1], "Y component of parametric function", &updateNeeded);
    options["FZ"] = new FieldOptionString(
      _f[2], "Z component of parametric function", &updateNeeded);

    // deprecated names
    options["IField"] =
      new FieldOptionInt(_inField, "Input field tag", nullptr, true);
  }
  std::string getDescription()
  {
    return "Evaluate Field[InField] in parametric coordinates:\n\n"
           "  F = Field[InField](FX,FY,FZ)\n\n"
           "See the MathEval Field help to get a description of valid FX, FY "
           "and FZ expressions.";
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    if(updateNeeded) {
      for(int i = 0; i < 3; i++) {
        if(!_expr[i].set_function(_f[i]))
          Msg::Error("Field %i: invalid matheval expression \"%s\"", this->id,
                     _f[i].c_str());
      }
      updateNeeded = false;
    }
    Field *field = GModel::current()->getFields()->get(_inField);
    if(!field || _inField == id) return MAX_LC;
    return (*field)(_expr[0].evaluate(x, y, z), _expr[1].evaluate(x, y, z),
                    _expr[2].evaluate(x, y, z));
  }
  const char *getName() { return "Param"; }
};

#if defined(HAVE_POST)

class PostViewField : public Field {
private:
  OctreePost *_octree;
  int _viewIndex, _viewTag;
  bool _cropNegativeValues;

public:
  PostViewField()
  {
    _octree = nullptr;
    _viewIndex = 0;
    _viewTag = -1;
    _cropNegativeValues = true;
    updateNeeded = true; // in case we don't set IView or ViewTag explicitely

    options["ViewIndex"] = new FieldOptionInt(
      _viewIndex, "Post-processing view index", &updateNeeded);
    options["ViewTag"] =
      new FieldOptionInt(_viewTag, "Post-processing view tag", &updateNeeded);
    options["CropNegativeValues"] = new FieldOptionBool(
      _cropNegativeValues, "return LC_MAX instead of a negative value (this "
                           "option is needed for backward compatibility with "
                           "the BackgroundMesh option");

    // deprecated names
    options["IView"] = new FieldOptionInt(
      _viewIndex, "Post-processing view index", &updateNeeded, true);
  }
  ~PostViewField()
  {
    if(_octree) delete _octree;
  }
  PView *getView() const
  {
    PView *v = nullptr;
    if(_viewTag >= 0) v = PView::getViewByTag(_viewTag);
    if(!v) {
      if(_viewIndex < 0 || _viewIndex >= (int)PView::list.size()) {
        Msg::Error("View[%d] does not exist", _viewIndex);
        return nullptr;
      }
      v = PView::list[_viewIndex];
    }
    if(v->getData()->hasModel(GModel::current())) {
      Msg::Error(
        "Cannot use view based on current mesh for background mesh: you might"
        " want to use a list-based view (.pos file) instead");
      return nullptr;
    }
    return v;
  }
  virtual bool isotropic() const
  {
    PView *v = getView();
    if(v && v->getData()->getNumTensors()) return false;
    return true;
  }
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    PView *v = getView();
    if(!v) return MAX_LC;
    if(updateNeeded) {
      if(_octree) delete _octree;
      _octree = new OctreePost(v);
      updateNeeded = false;
    }
    double l = 0.;
    // use large tolerance (in element reference coordinates) to maximize chance
    // of finding an element
    if(!_octree->searchScalarWithTol(x, y, z, &l, 0, nullptr, 0.05))
      Msg::Info("No scalar element found containing point (%g,%g,%g)", x, y, z);
    if(l <= 0 && _cropNegativeValues) return MAX_LC;
    return l;
  }
  void operator()(double x, double y, double z, SMetric3 &metr,
                  GEntity *ge = nullptr)
  {
    PView *v = getView();
    if(!v) return;
    if(updateNeeded) {
      if(_octree) delete _octree;
      _octree = new OctreePost(v);
      updateNeeded = false;
    }
    double l[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};
    // use large tolerance (in element reference coordinates) to maximize chance
    // of finding an element
    if(!_octree->searchTensorWithTol(x, y, z, l, 0, nullptr, 0.05))
      Msg::Info("No tensor element found containing point (%g,%g,%g)", x, y, z);
    if(0 && _cropNegativeValues) {
      if(l[0] <= 0 && l[1] <= 0 && l[2] <= 0 && l[3] <= 0 && l[4] <= 0 &&
         l[5] <= 0 && l[6] <= 0 && l[7] <= 0 && l[8] <= 0) {
        for(int i = 0; i < 9; i++) l[i] = MAX_LC;
      }
      else {
        for(int i = 0; i < 9; i++) {
          if(l[i] <= 0) l[i] = 0;
        }
      }
    }
    metr(0, 0) = l[0];
    metr(0, 1) = l[1];
    metr(0, 2) = l[2];
    metr(1, 0) = l[3];
    metr(1, 1) = l[4];
    metr(1, 2) = l[5];
    metr(2, 0) = l[6];
    metr(2, 1) = l[7];
    metr(2, 2) = l[8];
  }
  const char *getName() { return "PostView"; }
  std::string getDescription()
  {
    return "Evaluate the post processing view IView.";
  }
};

#endif

class MinAnisoField : public Field {
private:
  std::list<int> _fieldIds;

public:
  MinAnisoField()
  {
    options["FieldsList"] =
      new FieldOptionList(_fieldIds, "Field indices", &updateNeeded);
  }
  virtual bool isotropic() const { return false; }
  std::string getDescription()
  {
    return "Take the intersection of a list of possibly anisotropic fields.";
  }
  virtual void operator()(double x, double y, double z, SMetric3 &metr,
                          GEntity *ge = nullptr)
  {
    SMetric3 v(1. / MAX_LC);
    for(auto it = _fieldIds.begin(); it != _fieldIds.end(); it++) {
      Field *f = (GModel::current()->getFields()->get(*it));
      SMetric3 ff;
      if(f && *it != id) {
        if(f->isotropic()) {
          double l = (*f)(x, y, z, ge);
          ff = SMetric3(1. / (l * l));
        }
        else {
          (*f)(x, y, z, ff, ge);
        }
        v = intersection_conserve_mostaniso(v, ff);
      }
    }
    metr = v;
  }
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    SMetric3 metr(1. / MAX_LC);
    double v = MAX_LC;
    for(auto it = _fieldIds.begin(); it != _fieldIds.end(); it++) {
      Field *f = (GModel::current()->getFields()->get(*it));
      SMetric3 m;
      if(f && *it != id) {
        if(!f->isotropic()) { (*f)(x, y, z, m, ge); }
        else {
          double L = (*f)(x, y, z, ge);
          for(int i = 0; i < 3; i++) m(i, i) = 1. / (L * L);
        }
      }
      metr = intersection(metr, m);
    }
    fullMatrix<double> V(3, 3);
    fullVector<double> S(3);
    metr.eig(V, S, 1);
    double val = sqrt(1. / S(2)); // S(2) is largest eigenvalue
    return std::min(v, val);
  }
  const char *getName() { return "MinAniso"; }
};

class IntersectAnisoField : public Field {
private:
  std::list<int> _fieldIds;

public:
  IntersectAnisoField()
  {
    options["FieldsList"] =
      new FieldOptionList(_fieldIds, "Field indices", &updateNeeded);
  }
  virtual bool isotropic() const { return false; }
  std::string getDescription()
  {
    return "Take the intersection of 2 anisotropic fields according to "
           "Alauzet.";
  }
  virtual void operator()(double x, double y, double z, SMetric3 &metr,
                          GEntity *ge = nullptr)
  {
    // check if _fieldIds contains 2 elements other error message
    SMetric3 v;
    for(auto it = _fieldIds.begin(); it != _fieldIds.end(); it++) {
      Field *f = (GModel::current()->getFields()->get(*it));
      SMetric3 ff;
      if(f && *it != id) {
        if(f->isotropic()) {
          double l = (*f)(x, y, z, ge);
          ff = SMetric3(1. / (l * l));
        }
        else {
          (*f)(x, y, z, ff, ge);
        }
        if(it == _fieldIds.begin())
          v = ff;
        else
          v = intersection_alauzet(v, ff);
      }
    }
    metr = v;
  }
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    // check if _fieldIds contains 2 elements other error message
    SMetric3 metr;
    for(auto it = _fieldIds.begin(); it != _fieldIds.end(); it++) {
      Field *f = (GModel::current()->getFields()->get(*it));
      SMetric3 m;
      if(f && *it != id) {
        if(!f->isotropic()) { (*f)(x, y, z, m, ge); }
        else {
          double L = (*f)(x, y, z, ge);
          for(int i = 0; i < 3; i++) m(i, i) = 1. / (L * L);
        }
      }
      if(it == _fieldIds.begin())
        metr = m;
      else
        metr = intersection_alauzet(metr, m);
    }
    fullMatrix<double> V(3, 3);
    fullVector<double> S(3);
    metr.eig(V, S, 1);
    return sqrt(1. / S(2)); // S(2) is largest eigenvalue
  }
  const char *getName() { return "IntersectAniso"; }
};

class MinField : public Field {
private:
  std::list<int> _fieldIds;

public:
  MinField()
  {
    options["FieldsList"] =
      new FieldOptionList(_fieldIds, "Field indices", &updateNeeded);
  }
  std::string getDescription()
  {
    return "Take the minimum value of a list of fields.";
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    double v = MAX_LC;
    for(auto it = _fieldIds.begin(); it != _fieldIds.end(); it++) {
      Field *f = (GModel::current()->getFields()->get(*it));
      if(f && *it != id) {
        if(f->isotropic())
          v = std::min(v, (*f)(x, y, z, ge));
        else {
          SMetric3 ff;
          (*f)(x, y, z, ff, ge);
          fullMatrix<double> V(3, 3);
          fullVector<double> S(3);
          ff.eig(V, S, 1);
          v = std::min(v, sqrt(1. / S(2))); // S(2) is largest eigenvalue
        }
      }
    }
    return v;
  }
  const char *getName() { return "Min"; }
};

class MaxField : public Field {
private:
  std::list<int> _fieldIds;

public:
  MaxField()
  {
    options["FieldsList"] =
      new FieldOptionList(_fieldIds, "Field indices", &updateNeeded);
  }
  std::string getDescription()
  {
    return "Take the maximum value of a list of fields.";
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    double v = -MAX_LC;
    for(auto it = _fieldIds.begin(); it != _fieldIds.end(); it++) {
      Field *f = (GModel::current()->getFields()->get(*it));
      if(f && *it != id) {
        if(f->isotropic())
          v = std::max(v, (*f)(x, y, z, ge));
        else {
          SMetric3 ff;
          (*f)(x, y, z, ff, ge);
          fullMatrix<double> V(3, 3);
          fullVector<double> S(3);
          ff.eig(V, S, 1);
          v = std::max(v, sqrt(1. / S(0))); // S(0) is smallest eigenvalue
        }
      }
    }
    return v;
  }
  const char *getName() { return "Max"; }
};

class RestrictField : public Field {
private:
  int _inField;
  std::list<int> _pointTags, _curveTags, _surfaceTags, _volumeTags;

public:
  RestrictField()
  {
    _inField = 1;

    options["InField"] = new FieldOptionInt(_inField, "Input field tag");
    options["PointsList"] = new FieldOptionList(_pointTags, "Point tags");
    options["CurvesList"] = new FieldOptionList(_curveTags, "Curve tags");
    options["SurfacesList"] = new FieldOptionList(_surfaceTags, "Surface tags");
    options["VolumesList"] = new FieldOptionList(_volumeTags, "Volume tags");

    // deprecated names
    options["IField"] =
      new FieldOptionInt(_inField, "Input field tag", nullptr, true);
    options["VerticesList"] =
      new FieldOptionList(_pointTags, "Point tags", nullptr, true);
    options["EdgesList"] =
      new FieldOptionList(_curveTags, "Curve tags", nullptr, true);
    options["FacesList"] =
      new FieldOptionList(_surfaceTags, "Surface tags", nullptr, true);
    options["RegionsList"] =
      new FieldOptionList(_volumeTags, "Volume tags", nullptr, true);
  }
  std::string getDescription()
  {
    return "Restrict the application of a field to a given list of geometrical "
           "points, curves, surfaces or volumes.";
  }
  using Field::operator();
  double operator()(double x, double y, double z, GEntity *ge = nullptr)
  {
    Field *f = (GModel::current()->getFields()->get(_inField));
    if(!f || _inField == id) return MAX_LC;
    if(!ge) return (*f)(x, y, z);
    if((ge->dim() == 0 && std::find(_pointTags.begin(), _pointTags.end(),
                                    ge->tag()) != _pointTags.end()) ||
       (ge->dim() == 1 && std::find(_curveTags.begin(), _curveTags.end(),
                                    ge->tag()) != _curveTags.end()) ||
       (ge->dim() == 2 && std::find(_surfaceTags.begin(), _surfaceTags.end(),
                                    ge->tag()) != _surfaceTags.end()) ||
       (ge->dim() == 3 && std::find(_volumeTags.begin(), _volumeTags.end(),
                                    ge->tag()) != _volumeTags.end()))
      return (*f)(x, y, z);
    return MAX_LC;
  }
  const char *getName() { return "Restrict"; }
};

struct AttractorInfo {
  AttractorInfo(int a = 0, int b = 0, double c = 0, double d = 0)
    : ent(a), dim(b), u(c), v(d)
  {
  }
  int ent, dim;
  double u, v;
};

#if defined(HAVE_ANN)

class AttractorAnisoCurveField : public Field {
private:
  ANNkd_tree *_kdTree;
  ANNpointArray _zeroNodes;
  ANNidxArray _index;
  ANNdistArray _dist;
  std::list<int> _curveTags;
  double _dMin, _dMax, _lMinTangent, _lMaxTangent, _lMinNormal, _lMaxNormal;
  int _numPointsPerCurve;
  std::vector<SVector3> _tg;

public:
  AttractorAnisoCurveField() : _kdTree(nullptr), _zeroNodes(nullptr)
  {
    _index = new ANNidx[1];
    _dist = new ANNdist[1];
    _numPointsPerCurve = 20;
    updateNeeded = true;
    _dMin = 0.1;
    _dMax = 0.5;
    _lMinNormal = 0.05;
    _lMinTangent = 0.5;
    _lMaxNormal = 0.5;
    _lMaxTangent = 0.5;

    options["CurvesList"] = new FieldOptionList(
      _curveTags, "Tags of curves in the geometric model", &updateNeeded);
    options["NumPointsPerCurve"] = new FieldOptionInt(
      _numPointsPerCurve, "Number of points used to discretized each curve",
      &updateNeeded);
    options["DistMin"] = new FieldOptionDouble(
      _dMin, "Minimum distance, below this distance from the curves, "
             "prescribe the minimum mesh sizes");
    options["DistMax"] = new FieldOptionDouble(
      _dMax, "Maxmium distance, above this distance from the curves, prescribe "
             "the maximum mesh sizes");
    options["SizeMinTangent"] = new FieldOptionDouble(
      _lMinTangent, "Minimum mesh size in the direction tangeant to the "
                    "closest curve");
    options["SizeMaxTangent"] = new FieldOptionDouble(
      _lMaxTangent, "Maximum mesh size in the direction tangeant to the "
                    "closest curve");
    options["SizeMinNormal"] = new FieldOptionDouble(
      _lMinNormal, "Minimum mesh size in the direction normal to the "
                   "closest curve");
    options["SizeMaxNormal"] = new FieldOptionDouble(
      _lMaxNormal, "Maximum mesh size in the direction normal to the "
                   "closest curve");

    // deprecated names
    options["EdgesList"] = new FieldOptionList(
      _curveTags, "Tags of curves in the geometric model", &updateNeeded, true);
    options["NNodesByEdge"] = new FieldOptionInt(
      _numPointsPerCurve, "Number of points used to discretized each curve",
      &updateNeeded, true);
    options["dMin"] = new FieldOptionDouble(
      _dMin,
      "Minimum distance, below this distance from the curves, "
      "prescribe the minimum mesh sizes",
      nullptr, true);
    options["dMax"] = new FieldOptionDouble(
      _dMax,
      "Maxmium distance, above this distance from the curves, prescribe "
      "the maximum mesh sizes",
      nullptr, true);
    options["lMinTangent"] = new FieldOptionDouble(
      _lMinTangent,
      "Minimum mesh size in the direction tangeant to the "
      "closest curve",
      nullptr, true);
    options["lMaxTangent"] = new FieldOptionDouble(
      _lMaxTangent,
      "Maximum mesh size in the direction tangeant to the "
      "closest curve",
      nullptr, true);
    options["lMinNormal"] =
      new FieldOptionDouble(_lMinNormal,
                            "Minimum mesh size in the direction normal to the "
                            "closest curve",
                            nullptr, true);
    options["lMaxNormal"] =
      new FieldOptionDouble(_lMaxNormal,
                            "Maximum mesh size in the direction normal to the "
                            "closest curve",
                            nullptr, true);

    // make sure all internal GEO CAD data has been synced with GModel
    GModel::current()->getGEOInternals()->synchronize(GModel::current());
  }
  virtual bool isotropic() const { return false; }
  ~AttractorAnisoCurveField()
  {
    if(_kdTree) delete _kdTree;
    if(_zeroNodes) annDeallocPts(_zeroNodes);
    delete[] _index;
    delete[] _dist;
  }
  const char *getName() { return "AttractorAnisoCurve"; }
  std::string getDescription()
  {
    return "Compute the distance to the given curves and specify the mesh size "
           "independently in the direction normal and parallel to the nearest "
           "curve. "
           "(Each curve is replaced by NumPointsPerCurve equidistant points, "
           "to "
           "which the distance is actually computed.)";
  }
  void update()
  {
    if(_zeroNodes) {
      annDeallocPts(_zeroNodes);
      delete _kdTree;
    }
    int totpoints = _numPointsPerCurve * _curveTags.size();
    if(totpoints) { _zeroNodes = annAllocPts(totpoints, 3); }
    _tg.resize(totpoints);
    int k = 0;
    for(auto it = _curveTags.begin(); it != _curveTags.end(); ++it) {
      GEdge *e = GModel::current()->getEdgeByTag(*it);
      if(e) {
        for(int i = 0; i < _numPointsPerCurve; i++) {
          double u = (double)i / (_numPointsPerCurve - 1);
          Range<double> b = e->parBounds(0);
          double t = b.low() + u * (b.high() - b.low());
          GPoint gp = e->point(t);
          SVector3 d = e->firstDer(t);
          _zeroNodes[k][0] = gp.x();
          _zeroNodes[k][1] = gp.y();
          _zeroNodes[k][2] = gp.z();
          _tg[k] = d;
          _tg[k].normalize();
          k++;
        }
      }
    }
    _kdTree = new ANNkd_tree(_zeroNodes, totpoints, 3);
    updateNeeded = false;
  }
  void operator()(double x, double y, double z, SMetric3 &metr,
                  GEntity *ge = nullptr)
  {
    if(updateNeeded) update();
    double xyz[3] = {x, y, z};
#if defined(_OPENMP)
#pragma omp                                                                    \
  critical // just to avoid crash (still incorrect) - should use nanoflann
#endif
    _kdTree->annkSearch(xyz, 1, _index, _dist);
    double d = sqrt(_dist[0]);
    double lTg = d < _dMin ? _lMinTangent :
                 d > _dMax ? _lMaxTangent :
                             _lMinTangent + (_lMaxTangent - _lMinTangent) *
                                              (d - _dMin) / (_dMax - _dMin);
    double lN = d < _dMin ? _lMinNormal :
                d > _dMax ? _lMaxNormal :
                            _lMinNormal + (_lMaxNormal - _lMinNormal) *
                                            (d - _dMin) / (_dMax - _dMin);
    SVector3 t = _tg[_index[0]];
    SVector3 n0 = crossprod(t, fabs(t(0)) > fabs(t(1)) ? SVector3(0, 1, 0) :
                                                         SVector3(1, 0, 0));
    SVector3 n1 = crossprod(t, n0);
    metr = SMetric3(1 / lTg / lTg, 1 / lN / lN, 1 / lN / lN, t, n0, n1);
  }
  virtual double operator()(double X, double Y, double Z, GEntity *ge = nullptr)
  {
    if(updateNeeded) update();
    double xyz[3] = {X, Y, Z};
#if defined(_OPENMP)
#pragma omp                                                                    \
  critical // just to avoid crash (still incorrect) - should use nanoflann
#endif
    _kdTree->annkSearch(xyz, 1, _index, _dist);
    double d = sqrt(_dist[0]);
    return std::max(d, 0.05);
  }
};

class AttractorField : public Field {
private:
  ANNkd_tree *_kdTree;
  ANNpointArray _zeroNodes;
  std::list<int> _pointTags, _curveTags, _surfaceTags;
  std::vector<AttractorInfo> _infos;
  int _xFieldId, _yFieldId, _zFieldId;
  Field *_xField, *_yField, *_zField;
  int _numPointsPerCurve;
  ANNidxArray _index;
  ANNdistArray _dist;

public:
  AttractorField(int dim, int tag, int nbe)
    : _kdTree(nullptr), _zeroNodes(nullptr), _numPointsPerCurve(nbe)
  {
    _index = new ANNidx[1];
    _dist = new ANNdist[1];
    if(dim == 0)
      _pointTags.push_back(tag);
    else if(dim == 1)
      _curveTags.push_back(tag);
    else if(dim == 2)
      _surfaceTags.push_back(tag);
    _xField = _yField = _zField = nullptr;
    _xFieldId = _yFieldId = _zFieldId = -1;
    updateNeeded = true;
  }
  AttractorField() : _kdTree(nullptr), _zeroNodes(nullptr)
  {
    _index = new ANNidx[1];
    _dist = new ANNdist[1];
    _numPointsPerCurve = 20;
    _xFieldId = _yFieldId = _zFieldId = -1;

    options["PointsList"] = new FieldOptionList(
      _pointTags, "Tags of points in the geometric model", &updateNeeded);
    options["CurvesList"] = new FieldOptionList(
      _curveTags, "Tags of curves in the geometric model", &updateNeeded);
    options["SurfacesList"] = new FieldOptionList(
      _surfaceTags, "Tags of surfaces in the geometric model", &updateNeeded);
    options["NumPointsPerCurve"] =
      new FieldOptionInt(_numPointsPerCurve,
                         "Number of points used to discretize each curve "
                         "(and surface, relative to their bounding box size)",
                         &updateNeeded);
    options["FieldX"] = new FieldOptionInt(
      _xFieldId, "Tag of the field to use as x coordinate", &updateNeeded);
    options["FieldY"] = new FieldOptionInt(
      _yFieldId, "Tag of the field to use as y coordinate", &updateNeeded);
    options["FieldZ"] = new FieldOptionInt(
      _zFieldId, "Tag of the field to use as z coordinate", &updateNeeded);

    // deprecated names
    options["NodesList"] = new FieldOptionList(
      _pointTags, "Tags of points in the geometric model", &updateNeeded, true);
    options["EdgesList"] = new FieldOptionList(
      _curveTags, "Tags of curves in the geometric model", &updateNeeded, true);
    options["FacesList"] = new FieldOptionList(
      _surfaceTags, "Tags of surfaces in the geometric model", &updateNeeded,
      true);
    options["NNodesByEdge"] =
      new FieldOptionInt(_numPointsPerCurve,
                         "Number of points used to discretize each curve "
                         "(and surface, relative to their bounding box size)",
                         &updateNeeded, true);
  }
  ~AttractorField()
  {
    delete[] _index;
    delete[] _dist;
    if(_kdTree) delete _kdTree;
    if(_zeroNodes) annDeallocPts(_zeroNodes);
  }
  const char *getName() { return "Attractor"; }
  std::string getDescription()
  {
    return "Compute the distance to the given points, curves or surfaces. "
           "(Curves are replaced by NumPointsPerCurve equidistant points, "
           "to which the distance is actually computed. In the same way, "
           "surfaces are replaced by a point cloud, sampled according to "
           "NumPointsPerCurve and the size of their bounding box). "
           "The Attractor field is deprecated: use the Distance field instead.";
  }
  void getCoord(double x, double y, double z, double &cx, double &cy,
                double &cz, GEntity *ge = nullptr)
  {
    cx = _xField ? (*_xField)(x, y, z, ge) : x;
    cy = _yField ? (*_yField)(x, y, z, ge) : y;
    cz = _zField ? (*_zField)(x, y, z, ge) : z;
  }
  std::pair<AttractorInfo, SPoint3> getAttractorInfo() const
  {
    return std::make_pair(_infos[_index[0]], SPoint3(_zeroNodes[_index[0]][0],
                                                     _zeroNodes[_index[0]][1],
                                                     _zeroNodes[_index[0]][2]));
  }
  void update()
  {
    if(updateNeeded) {
      _xField = _xFieldId >= 0 ?
                  (GModel::current()->getFields()->get(_xFieldId)) :
                  nullptr;
      _yField = _yFieldId >= 0 ?
                  (GModel::current()->getFields()->get(_yFieldId)) :
                  nullptr;
      _zField = _zFieldId >= 0 ?
                  (GModel::current()->getFields()->get(_zFieldId)) :
                  nullptr;
      if(_zeroNodes) {
        annDeallocPts(_zeroNodes);
        delete _kdTree;
      }
      std::vector<SPoint3> points;
      std::vector<SPoint2> uvpoints;
      std::vector<int> offset;
      offset.push_back(0);
      for(auto it = _surfaceTags.begin(); it != _surfaceTags.end(); ++it) {
        GFace *f = GModel::current()->getFaceByTag(*it);
        if(f) {
          if(f->mesh_vertices.size()) {
            for(std::size_t i = 0; i < f->mesh_vertices.size(); i++) {
              MVertex *v = f->mesh_vertices[i];
              double uu, vv;
              v->getParameter(0, uu);
              v->getParameter(1, vv);
              points.push_back(SPoint3(v->x(), v->y(), v->z()));
              uvpoints.push_back(SPoint2(uu, vv));
            }
          }
          else {
            SBoundingBox3d bb = f->bounds();
            SVector3 dd = bb.max() - bb.min();
            double maxDist = dd.norm() / _numPointsPerCurve;
            f->fillPointCloud(maxDist, &points, &uvpoints);
            offset.push_back(points.size());
          }
        }
      }

      double x, y, z;
      std::vector<double> px, py, pz;

      for(auto it = _pointTags.begin(); it != _pointTags.end(); ++it) {
        GVertex *gv = GModel::current()->getVertexByTag(*it);
        if(gv) {
          getCoord(gv->x(), gv->y(), gv->z(), x, y, z, gv);
          px.push_back(x);
          py.push_back(y);
          pz.push_back(z);
          _infos.push_back(AttractorInfo(*it, 0, 0, 0));
        }
      }

      for(auto it = _curveTags.begin(); it != _curveTags.end(); ++it) {
        GEdge *e = GModel::current()->getEdgeByTag(*it);
        if(e) {
          if(e->mesh_vertices.size()) {
            for(std::size_t i = 0; i < e->mesh_vertices.size(); i++) {
              double u;
              e->mesh_vertices[i]->getParameter(0, u);
              GPoint gp = e->point(u);
              getCoord(gp.x(), gp.y(), gp.z(), x, y, z, e);
              px.push_back(x);
              py.push_back(y);
              pz.push_back(z);
              _infos.push_back(AttractorInfo(*it, 1, u, 0));
            }
          }
          int NNN = _numPointsPerCurve - e->mesh_vertices.size();
          for(int i = 1; i < NNN - 1; i++) {
            double u = (double)i / (NNN - 1);
            Range<double> b = e->parBounds(0);
            double t = b.low() + u * (b.high() - b.low());
            GPoint gp = e->point(t);
            getCoord(gp.x(), gp.y(), gp.z(), x, y, z, e);
            px.push_back(x);
            py.push_back(y);
            pz.push_back(z);
            _infos.push_back(AttractorInfo(*it, 1, t, 0));
          }
        }
      }
      // This can lead to weird results as we generate attractors over the whole
      // parametric plane (we should really use a mesh, e.g. a refined STL.)
      int count = 0;
      for(auto it = _surfaceTags.begin(); it != _surfaceTags.end(); ++it) {
        GFace *f = GModel::current()->getFaceByTag(*it);
        if(f) {
          if(points.size()) {
            for(int j = offset[count]; j < offset[count + 1]; j++) {
              px.push_back(points[j].x());
              py.push_back(points[j].y());
              pz.push_back(points[j].z());
              _infos.push_back(
                AttractorInfo(*it, 2, uvpoints[j].x(), uvpoints[j].y()));
            }
            count++;
          }
          else {
            for(int i = 0; i < _numPointsPerCurve; i++) {
              for(int j = 0; j < _numPointsPerCurve; j++) {
                double u = (double)i / (_numPointsPerCurve - 1);
                double v = (double)j / (_numPointsPerCurve - 1);
                Range<double> b1 = f->parBounds(0);
                Range<double> b2 = f->parBounds(1);
                double t1 = b1.low() + u * (b1.high() - b1.low());
                double t2 = b2.low() + v * (b2.high() - b2.low());
                GPoint gp = f->point(t1, t2);
                getCoord(gp.x(), gp.y(), gp.z(), x, y, z, f);
                px.push_back(x);
                py.push_back(y);
                pz.push_back(z);
                _infos.push_back(AttractorInfo(*it, 2, u, v));
              }
            }
          }
        }
        else {
          Msg::Error("Face %d not yet created", *it);
        }
      }

      int totpoints = px.size();
      if(!totpoints) { // for backward compatibility
        totpoints = 1;
        px.push_back(0.);
        py.push_back(0.);
        pz.push_back(0.);
      }

      _zeroNodes = annAllocPts(totpoints, 3);
      for(int i = 0; i < totpoints; i++) {
        _zeroNodes[i][0] = px[i];
        _zeroNodes[i][1] = py[i];
        _zeroNodes[i][2] = pz[i];
      }
      _kdTree = new ANNkd_tree(_zeroNodes, totpoints, 3);
      updateNeeded = false;
    }
  }

  using Field::operator();
  virtual double operator()(double X, double Y, double Z, GEntity *ge = nullptr)
  {
#if defined(_OPENMP)
#pragma omp critical
#endif
    {
      update();
    }
    double xyz[3];
    getCoord(X, Y, Z, xyz[0], xyz[1], xyz[2], ge);
#if defined(_OPENMP)
#pragma omp                                                                    \
  critical // just to avoid crash (still incorrect) - should use nanoflann
#endif
    _kdTree->annkSearch(xyz, 1, _index, _dist);
    double d = _dist[0];
    return sqrt(d);
  }
};

#endif // ANN

class OctreeField : public Field {
private:
  // octree field
  class Cell {
  private:
    void *_data;
    bool _isleaf;

  public:
    double evaluate(double x, double y, double z) const
    {
      if(_isleaf) return *(double *)_data;
      Cell *sub = (Cell *)_data;
      int i = x > 0.5 ? 1 : 0;
      int j = y > 0.5 ? 1 : 0;
      int k = z > 0.5 ? 1 : 0;
      return sub[i * 4 + j * 2 + k].evaluate(2 * x - i, 2 * y - j, 2 * z - k);
    }
    Cell(){};
    void init(double x0, double y0, double z0, double l, Field &field,
              int level)
    {
#if 0
      double v[8] =
        {field(x0, y0, z0), field(x0, y0, z0 + l), field(x0, y0 + l, z0),
         field(x0, y0 + l, z0 + l), field(x0 + l, y0, z0), field(x0 + l, y0, z0 + l),
         field(x0 + l, y0 + l, z0), field(x0 + l, y0 + l, z0 + l)};
      double dmax = 0;
      double vmin = v[0];
      double vc = field(x0+l/2,y0+l/2,z0+l/2);
      for (int i = 0; i < 8; ++i){
        dmax = std::max(dmax, std::abs(vc-v[i]));
        vmin = std::min(vmin, v[i]);
      }
#else
      double dmax = 0;
      double vc = field(x0 + l / 2, y0 + l / 2, z0 + l / 2);
      double vmin = vc;
      bool split = level > 0;
      if(level > -4) {
#define NSAMPLE 2
        double dl = l / NSAMPLE;
        for(int i = 0; i <= NSAMPLE; ++i) {
          for(int j = 0; j <= NSAMPLE; ++j) {
            for(int k = 0; k <= NSAMPLE; ++k) {
              double w = field(x0 + i * dl, y0 + j * dl, z0 + k * dl);
              dmax = std::max(dmax, std::abs(vc - w));
              vmin = std::min(vmin, w);
              split |= (dmax / vmin > 0.2 && vmin < l);
              if(split) break;
            }
          }
        }
#endif
    }
    if(split) {
      _isleaf = false;
      Cell *sub = new Cell[8];
      double l2 = l / 2;
      sub[0].init(x0, y0, z0, l2, field, level - 1);
      sub[1].init(x0, y0, z0 + l2, l2, field, level - 1);
      sub[2].init(x0, y0 + l2, z0, l2, field, level - 1);
      sub[3].init(x0, y0 + l2, z0 + l2, l2, field, level - 1);
      sub[4].init(x0 + l2, y0, z0, l2, field, level - 1);
      sub[5].init(x0 + l2, y0, z0 + l2, l2, field, level - 1);
      sub[6].init(x0 + l2, y0 + l2, z0, l2, field, level - 1);
      sub[7].init(x0 + l2, y0 + l2, z0 + l2, l2, field, level - 1);
      _data = (void *)sub;
    }
    else {
      _isleaf = true;
      _data = (void *)new double;
      *(double *)_data = vc;
    }
  } ~Cell()
  {
    if(_isleaf) { delete(double *)_data; }
    else {
      Cell *sub = (Cell *)_data;
      delete[] sub;
    }
  }
  void print(double x0, double y0, double z0, double l, FILE *f)
  {
    if(_isleaf) {
      fprintf(f, "SP(%g, %g, %g) {%g};\n", x0 + l / 2, y0 + l / 2, z0 + l / 2,
              *(double *)_data);
    }
    else {
      Cell *sub = (Cell *)_data;
      double l2 = l / 2;
      sub[0].print(x0, y0, z0, l2, f);
      sub[1].print(x0, y0, z0 + l2, l2, f);
      sub[2].print(x0, y0 + l2, z0, l2, f);
      sub[3].print(x0, y0 + l2, z0 + l2, l2, f);
      sub[4].print(x0 + l2, y0, z0, l2, f);
      sub[5].print(x0 + l2, y0, z0 + l2, l2, f);
      sub[6].print(x0 + l2, y0 + l2, z0, l2, f);
      sub[7].print(x0 + l2, y0 + l2, z0 + l2, l2, f);
    }
  }
};
Cell *_root;
int _inFieldId;
Field *_inField;
SBoundingBox3d bounds;
double _l0;

public:
OctreeField()
{
  _root = nullptr;

  options["InField"] = new FieldOptionInt(
    _inFieldId, "Id of the field to represent on the octree", &updateNeeded);
}
~OctreeField()
{
  if(_root) delete _root;
}
const char *getName() { return "Octree"; }
std::string getDescription()
{
  return "Pre compute another field on an octree to speed-up evalution";
}
void update()
{
  if(updateNeeded) {
    updateNeeded = false;
    if(_root) {
      delete _root;
      _root = nullptr;
    }
  }
  if(!_root) {
    _inField = _inFieldId >= 0 ?
                 (GModel::current()->getFields()->get(_inFieldId)) :
                 nullptr;
    if(!_inField) return;
    GModel::current()->getFields()->get(_inFieldId)->update();
    bounds = GModel::current()->bounds();
    _root = new Cell;
    SVector3 d = bounds.max() - bounds.min();
    _l0 = std::max(std::max(d.x(), d.y()), d.z());
    _root->init(bounds.min().x(), bounds.min().y(), bounds.min().z(), _l0,
                *_inField, 4);
  }
}
using Field::operator();
virtual double operator()(double X, double Y, double Z, GEntity *ge = nullptr)
{
  SPoint3 xmin = bounds.min();
  SVector3 d = bounds.max() - xmin;
  return _root->evaluate((X - xmin.x()) / _l0, (Y - xmin.y()) / _l0,
                         (Z - xmin.z()) / _l0);
}
}
;

struct PointCloud {
  std::vector<SPoint3> pts;
};

// And this is the "dataset to kd-tree" adaptor class:
template <typename Derived> struct PointCloudAdaptor {
  const Derived &obj; //!< A const ref to the data set origin

  // The constructor that sets the data set source
  PointCloudAdaptor(const Derived &obj_) : obj(obj_) {}

  // CRTP helper method
  inline const Derived &derived() const { return obj; }

  // Must return the number of data points
  inline size_t kdtree_get_point_count() const { return derived().pts.size(); }

  // Returns the distance between the vector "p1[0:size-1]" and the data point
  // with index "idx_p2" stored in the class:
  inline double kdtree_distance(const double *p1, const size_t idx_p2,
                                size_t /*size*/) const
  {
    const double d0 = p1[0] - derived().pts[idx_p2].x();
    const double d1 = p1[1] - derived().pts[idx_p2].y();
    const double d2 = p1[2] - derived().pts[idx_p2].z();
    return d0 * d0 + d1 * d1 + d2 * d2;
  }

  // Returns the dim'th component of the idx'th point in the class: Since this
  // is inlined and the "dim" argument is typically an immediate value, the
  // "if/else's" are actually solved at compile time.
  inline double kdtree_get_pt(const size_t idx, int dim) const
  {
    if(dim == 0)
      return derived().pts[idx].x();
    else if(dim == 1)
      return derived().pts[idx].y();
    else
      return derived().pts[idx].z();
  }

  // Optional bounding-box computation: return false to default to a standard
  // bbox computation loop.  Return true if the BBOX was already computed by the
  // class and returned in "bb" so it can be avoided to redo it again.  Look at
  // bb.size() to find out the expected dimensionality (e.g. 2 or 3 for point
  // clouds)
  template <class BBOX> bool kdtree_get_bbox(BBOX & /*bb*/) const
  {
    return false;
  }

}; // end of PointCloudAdaptor

typedef PointCloudAdaptor<PointCloud> PC2KD;
typedef nanoflann::KDTreeSingleIndexAdaptor<
  nanoflann::L2_Simple_Adaptor<double, PC2KD>, PC2KD, 3>
  my_kd_tree_t;

class DistanceField : public Field {
  std::list<int> _pointTags, _curveTags, _surfaceTags;
  std::vector<AttractorInfo> _infos;
  int _xFieldId, _yFieldId, _zFieldId;
  Field *_xField, *_yField, *_zField;
  int _numPointsPerCurve;
  PointCloud _P;
  my_kd_tree_t *_index;
  PC2KD _pc2kd;
  std::size_t _outIndex;
  double _outDistSqr;

public:
  DistanceField() : _index(nullptr), _pc2kd(_P), _outIndex(0), _outDistSqr(0)
  {
    _numPointsPerCurve = 20;
    _xFieldId = _yFieldId = _zFieldId = -1;

    options["PointsList"] = new FieldOptionList(
      _pointTags, "Tags of points in the geometric model", &updateNeeded);
    options["CurvesList"] = new FieldOptionList(
      _curveTags, "Tags of curves in the geometric model", &updateNeeded);
    options["SurfacesList"] = new FieldOptionList(
      _surfaceTags, "Tags of surfaces in the geometric model", &updateNeeded);
    options["NumPointsPerCurve"] =
      new FieldOptionInt(_numPointsPerCurve,
                         "Number of points used to discretized each curve "
                         "(and surface, relative to their bounding box size)",
                         &updateNeeded);
    options["FieldX"] = new FieldOptionInt(
      _xFieldId, "Id of the field to use as x coordinate", &updateNeeded);
    options["FieldY"] = new FieldOptionInt(
      _yFieldId, "Id of the field to use as y coordinate", &updateNeeded);
    options["FieldZ"] = new FieldOptionInt(
      _zFieldId, "Id of the field to use as z coordinate", &updateNeeded);

    // deprecated names
    options["NodesList"] = new FieldOptionList(
      _pointTags, "Tags of points in the geometric model", &updateNeeded, true);
    options["EdgesList"] = new FieldOptionList(
      _curveTags, "Tags of curves in the geometric model", &updateNeeded, true);
    options["NNodesByEdge"] =
      new FieldOptionInt(_numPointsPerCurve,
                         "Number of points used to discretized each curve "
                         "(and surface, relative to their bounding box size)",
                         &updateNeeded, true);
    options["FacesList"] = new FieldOptionList(
      _surfaceTags, "Tags of surfaces in the geometric model", &updateNeeded,
      true);
  }
  DistanceField(int dim, int tag, int nbe)
    : _numPointsPerCurve(nbe), _index(nullptr), _pc2kd(_P), _outIndex(0),
      _outDistSqr(0)
  {
    if(dim == 0)
      _pointTags.push_back(tag);
    else if(dim == 2)
      _curveTags.push_back(tag);
    else if(dim == 3)
      _surfaceTags.push_back(tag);
    _xField = _yField = _zField = nullptr;
    _xFieldId = _yFieldId = _zFieldId = -1;
    updateNeeded = true;
  }
  ~DistanceField()
  {
    if(_index) delete _index;
  }
  const char *getName() { return "DistanceField"; }
  std::string getDescription()
  {
    return "Compute the distance to the given points, curves or surfaces. "
           "(Curves are replaced by NumPointsPerCurve equidistant points, "
           "to which the distance is actually computed. In the same way, "
           "surfaces are replaced by a point cloud, sampled according to "
           "NumPointsPerCurve and the size of their bounding box).";
  }
  std::pair<AttractorInfo, SPoint3> getAttractorInfo() const
  {
    if(_outIndex < _infos.size() && _outIndex < _P.pts.size())
      return std::make_pair(_infos[_outIndex], _P.pts[_outIndex]);
    return std::make_pair(AttractorInfo(), SPoint3());
  }
  void update()
  {
    if(updateNeeded) {
      _xField = _xFieldId >= 0 ?
                  (GModel::current()->getFields()->get(_xFieldId)) :
                  nullptr;
      _yField = _yFieldId >= 0 ?
                  (GModel::current()->getFields()->get(_yFieldId)) :
                  nullptr;
      _zField = _zFieldId >= 0 ?
                  (GModel::current()->getFields()->get(_zFieldId)) :
                  nullptr;

      _infos.clear();
      std::vector<SPoint3> &points = _P.pts;
      points.clear();
      for(auto it = _surfaceTags.begin(); it != _surfaceTags.end(); ++it) {
        GFace *f = GModel::current()->getFaceByTag(*it);
        if(f) {
          if(f->mesh_vertices.size()) {
            for(std::size_t i = 0; i < f->mesh_vertices.size(); i++) {
              MVertex *v = f->mesh_vertices[i];
              points.push_back(SPoint3(v->x(), v->y(), v->z()));
              double uu = 0., vv = 0.;
              v->getParameter(0, uu);
              v->getParameter(1, vv);
              _infos.push_back(AttractorInfo(*it, 2, uu, vv));
            }
          }
          else {
            SBoundingBox3d bb = f->bounds();
            SVector3 dd = bb.max() - bb.min();
            double maxDist = dd.norm() / _numPointsPerCurve;
            std::vector<SPoint2> uvpoints;
            f->fillPointCloud(maxDist, &points, &uvpoints);
            for(std::size_t i = 0; i < uvpoints.size(); i++)
              _infos.push_back(
                AttractorInfo(*it, 2, uvpoints[i].x(), uvpoints[i].y()));
          }
        }
      }

      for(auto it = _pointTags.begin(); it != _pointTags.end(); ++it) {
        GVertex *gv = GModel::current()->getVertexByTag(*it);
        if(gv) {
          points.push_back(SPoint3(gv->x(), gv->y(), gv->z()));
          _infos.push_back(AttractorInfo(*it, 0, 0, 0));
        }
      }

      for(auto it = _curveTags.begin(); it != _curveTags.end(); ++it) {
        GEdge *e = GModel::current()->getEdgeByTag(*it);
        if(e) {
          if(e->mesh_vertices.size()) {
            for(std::size_t i = 0; i < e->mesh_vertices.size(); i++) {
              points.push_back(SPoint3(e->mesh_vertices[i]->x(),
                                       e->mesh_vertices[i]->y(),
                                       e->mesh_vertices[i]->z()));
              double t = 0.;
              e->mesh_vertices[i]->getParameter(0, t);
              _infos.push_back(AttractorInfo(*it, 1, t, 0));
            }
          }
          int NNN = _numPointsPerCurve - e->mesh_vertices.size();
          for(int i = 1; i < NNN - 1; i++) {
            double u = (double)i / (NNN - 1);
            Range<double> b = e->parBounds(0);
            double t = b.low() + u * (b.high() - b.low());
            GPoint gp = e->point(t);
            points.push_back(SPoint3(gp.x(), gp.y(), gp.z()));
            _infos.push_back(AttractorInfo(*it, 1, t, 0));
          }
        }
      }

      // construct a kd-tree index:
      _index = new my_kd_tree_t(3, _pc2kd,
                                nanoflann::KDTreeSingleIndexAdaptorParams(10));
      _index->buildIndex();
      updateNeeded = false;
    }
  }
  using Field::operator();
  virtual double operator()(double X, double Y, double Z, GEntity *ge = nullptr)
  {
    if(!_index) return MAX_LC;
    double query_pt[3] = {X, Y, Z};
    const size_t num_results = 1;
    nanoflann::KNNResultSet<double> resultSet(num_results);
    resultSet.init(&_outIndex, &_outDistSqr);
    _index->findNeighbors(resultSet, &query_pt[0], nanoflann::SearchParams(10));
    return sqrt(_outDistSqr);
  }
};

const char *BoundaryLayerField::getName() { return "BoundaryLayer"; }

std::string BoundaryLayerField::getDescription()
{
  return "Insert a 2D boundary layer mesh next to some curves in the model.";
}

BoundaryLayerField::BoundaryLayerField()
{
  betaLaw = 0;
  nb_divisions = 10;
  beta = 1.01;
  hWallN = .1;
  hFar = 1;
  ratio = 1.1;
  thickness = 1.e-2;
  tgtAnisoRatio = 1.e10;
  iRecombine = 0;
  iIntersect = 0;

  options["CurvesList"] = new FieldOptionList(
    _curveTags,
    "Tags of curves in the geometric model for which a boundary "
    "layer is needed",
    &updateNeeded);
  options["FanPointsList"] =
    new FieldOptionList(_fanPointTags,
                        "Tags of points in the geometric model for which a fan "
                        "is created",
                        &updateNeeded);
  options["FanPointsSizesList"] = new FieldOptionList(
    _fanSizes,
    "Number of elements in the fan for each fan node. "
    "If not present default value Mesh.BoundaryLayerFanElements",
    &updateNeeded);
  options["PointsList"] = new FieldOptionList(
    _pointTags,
    "Tags of points in the geometric model for which a boundary "
    "layer ends",
    &updateNeeded);
  options["Size"] =
    new FieldOptionDouble(hWallN, "Mesh size normal to the curve");
  options["SizesList"] = new FieldOptionListDouble(
    _hWallNNodes, "Mesh size normal to the curve, per point (overwrites "
                  "Size when defined)");
  options["Ratio"] =
    new FieldOptionDouble(ratio, "Size ratio between two successive layers");
  options["SizeFar"] =
    new FieldOptionDouble(hFar, "Element size far from the curves");
  options["Thickness"] =
    new FieldOptionDouble(thickness, "Maximal thickness of the boundary layer");
  options["Quads"] = new FieldOptionInt(
    iRecombine, "Generate recombined elements in the boundary layer");
  options["IntersectMetrics"] =
    new FieldOptionInt(iIntersect, "Intersect metrics of all surfaces");
  options["AnisoMax"] = new FieldOptionDouble(
    tgtAnisoRatio, "Threshold angle for creating a mesh fan in the boundary "
                   "layer");
  options["BetaLaw"] = new FieldOptionInt(
    betaLaw, "Use Beta Law instead of geometric progression ");
  options["Beta"] =
    new FieldOptionDouble(beta, "Beta coefficient of the Beta Law");
  options["NbLayers"] =
    new FieldOptionInt(nb_divisions, "Number of Layers in theBeta Law");
  options["ExcludedSurfacesList"] =
    new FieldOptionList(_excludedSurfaceTags,
                        "Tags of surfaces in the geometric model where the "
                        "boundary layer should not be contructed",
                        &updateNeeded);

  // deprecated names
  options["EdgesList"] = new FieldOptionList(
    _curveTags,
    "Tags of curves in the geometric model for which a boundary "
    "layer is needed",
    &updateNeeded, true);
  options["FanNodesList"] =
    new FieldOptionList(_fanPointTags,
                        "Tags of points in the geometric model for which a fan "
                        "is created",
                        &updateNeeded, true);
  options["NodesList"] = new FieldOptionList(
    _pointTags,
    "Tags of points in the geometric model for which a boundary "
    "layer ends",
    &updateNeeded, true);
  options["hwall_n"] = new FieldOptionDouble(
    hWallN,
    "Mesh size normal to the curvem per point (overwrites "
    "Size when defined)",
    nullptr, true);
  options["hwall_n_nodes"] = new FieldOptionListDouble(
    _hWallNNodes,
    "Mesh size normal to the curve, per point (overwrites "
    "Size when defined)",
    nullptr, true);
  options["ratio"] = new FieldOptionDouble(
    ratio, "Size ratio between two successive layers", nullptr, true);
  options["hfar"] = new FieldOptionDouble(
    hFar, "Element size far from the wall", nullptr, true);
  options["thickness"] = new FieldOptionDouble(
    thickness, "Maximal thickness of the boundary layer", nullptr, true);
  options["ExcludedFaceList"] =
    new FieldOptionList(_excludedSurfaceTags,
                        "Tags of surfaces in the geometric model where the "
                        "boundary layer should not be constructed",
                        &updateNeeded, true);
}

void BoundaryLayerField::removeAttractors()
{
  for(auto it = _attFields.begin(); it != _attFields.end(); ++it) delete *it;
  _attFields.clear();
  updateNeeded = true;
}

void BoundaryLayerField::setupFor1d(int iE)
{
  if(_curveTagsSaved.empty()) {
    _curveTagsSaved = _curveTags;
    _pointTagsSaved = _pointTags;
  }

  _pointTags.clear();
  _curveTags.clear();

  bool found = std::find(_curveTagsSaved.begin(), _curveTagsSaved.end(), iE) !=
               _curveTagsSaved.end();

  if(!found) {
    GEdge *ge = GModel::current()->getEdgeByTag(iE);
    if(ge) {
      GVertex *gv0 = ge->getBeginVertex();
      if(gv0) {
        found = std::find(_pointTagsSaved.begin(), _pointTagsSaved.end(),
                          gv0->tag()) != _pointTagsSaved.end();
        if(found) _pointTags.push_back(gv0->tag());
      }
      GVertex *gv1 = ge->getEndVertex();
      if(gv1) {
        found = std::find(_pointTagsSaved.begin(), _pointTagsSaved.end(),
                          gv1->tag()) != _pointTagsSaved.end();
        if(found) _pointTags.push_back(gv1->tag());
      }
    }
  }
  removeAttractors();
}

bool BoundaryLayerField::setupFor2d(int iF)
{
  if(std::find(_excludedSurfaceTags.begin(), _excludedSurfaceTags.end(), iF) !=
     _excludedSurfaceTags.end())
    return false;

  // remove GFaces from the attractors (only used in 2D) for edges and vertices
  if(_curveTagsSaved.empty()) {
    _curveTagsSaved = _curveTags;
    _pointTagsSaved = _pointTags;
  }

  _pointTags.clear();
  _curveTags.clear();

  // FIXME :
  // NOT REALLY A NICE WAY TO DO IT (VERY AD HOC)
  // THIS COULD BE PART OF THE INPUT
  // OR (better) CHANGE THE PHILOSOPHY

  GFace *gf = GModel::current()->getFaceByTag(iF);
  if(!gf) return false;
  std::vector<GEdge *> ed = gf->edges();
  std::vector<GEdge *> const &embedded_edges = gf->embeddedEdges();
  ed.insert(ed.begin(), embedded_edges.begin(), embedded_edges.end());

  for(auto it = ed.begin(); it != ed.end(); ++it) {
    bool isIn = false;
    int iE = (*it)->tag();
    bool found = std::find(_curveTagsSaved.begin(), _curveTagsSaved.end(),
                           iE) != _curveTagsSaved.end();
    // this edge is a BL Edge
    if(found) {
      std::vector<GFace *> fc = (*it)->faces();
      int numf = 0;
      for(auto it = fc.begin(); it != fc.end(); it++) {
        if((*it)->meshAttributes.extrude &&
           (*it)->meshAttributes.extrude->geo.Mode == EXTRUDED_ENTITY) {
          // ok
        }
        else if(std::find(_excludedSurfaceTags.begin(),
                          _excludedSurfaceTags.end(),
                          (*it)->tag()) != _excludedSurfaceTags.end()) {
          // ok
        }
        else {
          numf++;
        }
      }
      // one only face, or other faces are extruded --> 2D --> BL
      if(numf <= 1)
        isIn = true;
      else {
        Msg::Error("Only 2D Boundary Layers are supported (curve %d is adjacet "
                   "to %d surfaces)",
                   iE, fc.size());
      }
    }
    if(isIn) {
      _curveTags.push_back(iE);
      if((*it)->getBeginVertex())
        _pointTags.push_back((*it)->getBeginVertex()->tag());
      if((*it)->getEndVertex())
        _pointTags.push_back((*it)->getEndVertex()->tag());
    }
  }

  removeAttractors();
  return true;
}

double BoundaryLayerField::operator()(double x, double y, double z, GEntity *ge)
{
  if(updateNeeded) {
    for(auto it = _pointTags.begin(); it != _pointTags.end(); ++it) {
      _attFields.push_back(new DistanceField(0, *it, 100000));
    }
    for(auto it = _curveTags.begin(); it != _curveTags.end(); ++it) {
      _attFields.push_back(new DistanceField(1, *it, 300000));
    }
    updateNeeded = false;
  }

  double dist = 1.e22;
  if(_attFields.empty()) return dist;
  for(auto it = _attFields.begin(); it != _attFields.end(); ++it) {
    double cdist = (*(*it))(x, y, z);
    if(cdist < dist) { dist = cdist; }
  }

  if(dist > thickness * ratio) return 1.e22;
  currentDistance = dist;
  // const double dist = (*field) (x, y, z);
  // currentDistance = dist;
  double lc = dist * (ratio - 1) + hWallN;

  // double lc =  hWallN;
  return std::min(hFar, lc);
}

// assume that the closest point is one of the model vertices
void BoundaryLayerField::computeFor1dMesh(double x, double y, double z,
                                          SMetric3 &metr)
{
  double xpk = 0., ypk = 0., zpk = 0.;
  double distk = 1.e22;
  for(auto it = _pointTags.begin(); it != _pointTags.end(); ++it) {
    GVertex *v = GModel::current()->getVertexByTag(*it);
    if(v) {
      double xp = v->x();
      double yp = v->y();
      double zp = v->z();
      const double dist =
        sqrt((x - xp) * (x - xp) + (y - yp) * (y - yp) + (z - zp) * (z - zp));
      if(dist < distk) {
        distk = dist;
        xpk = xp;
        ypk = yp;
        zpk = zp;
      }
    }
  }

  const double ll1 = (distk * (ratio - 1) + hWallN) / (1. + 0.5 * (ratio - 1));
  double lc_n = std::min(ll1, hFar);

  if(distk > thickness) lc_n = hFar;
  lc_n = std::max(lc_n, CTX::instance()->mesh.lcMin);
  lc_n = std::min(lc_n, CTX::instance()->mesh.lcMax);
  SVector3 t1 = SVector3(x - xpk, y - ypk, z - zpk);
  t1.normalize();
  metr = buildMetricTangentToCurve(t1, lc_n, lc_n);
}

void BoundaryLayerField::operator()(DistanceField *cc, double dist, double x,
                                    double y, double z, SMetric3 &metr,
                                    GEntity *ge)
{
  // dist = hwall -> lc = hwall * ratio
  // dist = hwall (1+ratio) -> lc = hwall ratio ^ 2
  // dist = hwall (1+ratio+ratio^2) -> lc = hwall ratio ^ 3
  // dist = hwall (1+ratio+ratio^2+...+ratio^{m-1}) = (ratio^{m} - 1)/(ratio-1)
  // -> lc = hwall ratio ^ m
  // -> find m
  // dist/hwall = (ratio^{m} - 1)/(ratio-1)
  // (dist/hwall)*(ratio-1) + 1 = ratio^{m}
  // lc =  dist*(ratio-1) + hwall

  const double ll1 = dist * (ratio - 1) + hWallN;
  double lc_n = std::min(ll1, hFar);
  double lc_t = std::min(lc_n * CTX::instance()->mesh.anisoMax, hFar);

  lc_n = std::max(lc_n, CTX::instance()->mesh.lcMin);
  lc_n = std::min(lc_n, CTX::instance()->mesh.lcMax);
  lc_t = std::max(lc_t, CTX::instance()->mesh.lcMin);
  lc_t = std::min(lc_t, CTX::instance()->mesh.lcMax);

  std::pair<AttractorInfo, SPoint3> pp = cc->getAttractorInfo();
  double beta = CTX::instance()->mesh.smoothRatio;
  if(pp.first.dim == 0) {
    GVertex *v = GModel::current()->getVertexByTag(pp.first.ent);
    if(!v) return;
    SVector3 t1;
    if(dist < thickness) { t1 = SVector3(1, 0, 0); }
    else {
      t1 = SVector3(v->x() - x, v->y() - y, v->z() - z);
    }
    metr = buildMetricTangentToCurve(t1, lc_n, lc_n);
    return;
  }
  else if(pp.first.dim == 1) {
    GEdge *e = GModel::current()->getEdgeByTag(pp.first.ent);
    if(!e) return;
    if(dist < thickness) {
      SVector3 t1 = e->firstDer(pp.first.u);
      double crv = e->curvature(pp.first.u);
      const double b = lc_t;
      const double h = lc_n;
      double oneOverD2 =
        .5 / (b * b) *
        (1. +
         sqrt(1. + (4. * crv * crv * b * b * b * b / (h * h * beta * beta))));
      metr = buildMetricTangentToCurve(t1, sqrt(1. / oneOverD2), lc_n);
      return;
    }
    else {
      GPoint p = e->point(pp.first.u);
      SVector3 t2 = SVector3(p.x() - x, p.y() - y, p.z() - z);
      metr = buildMetricTangentToCurve(t2, lc_t, lc_n);
      return;
    }
  }
  else {
    GFace *gf = GModel::current()->getFaceByTag(pp.first.ent);
    if(!gf) return;
    if(dist < thickness) {
      double cmin, cmax;
      SVector3 dirMax, dirMin;
      cmax = gf->curvatures(SPoint2(pp.first.u, pp.first.v), dirMax, dirMin,
                            cmax, cmin);
      const double b = lc_t;
      const double h = lc_n;
      double oneOverD2_min =
        .5 / (b * b) *
        (1. +
         sqrt(1. + (4. * cmin * cmin * b * b * b * b / (h * h * beta * beta))));
      double oneOverD2_max =
        .5 / (b * b) *
        (1. +
         sqrt(1. + (4. * cmax * cmax * b * b * b * b / (h * h * beta * beta))));
      double dmin = sqrt(1. / oneOverD2_min);
      double dmax = sqrt(1. / oneOverD2_max);
      dmin = std::min(dmin, dmax * tgtAnisoRatio);
      metr = buildMetricTangentToSurface(dirMin, dirMax, dmin, dmax, lc_n);
      return;
    }
    else {
      GPoint p = gf->point(SPoint2(pp.first.u, pp.first.v));
      SVector3 t2 = SVector3(p.x() - x, p.y() - y, p.z() - z);
      metr = buildMetricTangentToCurve(t2, lc_n, lc_t);
      return;
    }
  }
}

void BoundaryLayerField::operator()(double x, double y, double z,
                                    SMetric3 &metr, GEntity *ge)
{
  if(updateNeeded) {
    for(auto it = _pointTags.begin(); it != _pointTags.end(); ++it) {
      _attFields.push_back(new DistanceField(0, *it, 100000));
    }
    for(auto it = _curveTags.begin(); it != _curveTags.end(); ++it) {
      _attFields.push_back(new DistanceField(1, *it, 10000));
    }
    updateNeeded = false;
  }

  currentDistance = 1.e22;
  currentClosest = nullptr;
  std::vector<SMetric3> hop;
  SMetric3 v(1. / (CTX::instance()->mesh.lcMax * CTX::instance()->mesh.lcMax));
  hop.push_back(v);
  for(auto it = _attFields.begin(); it != _attFields.end(); ++it) {
    double cdist = (*(*it))(x, y, z);
    SPoint3 CLOSEST = (*it)->getAttractorInfo().second;
    SMetric3 localMetric;
    if(iIntersect) {
      (*this)(*it, cdist, x, y, z, localMetric, ge);
      hop.push_back(localMetric);
    }
    if(cdist < currentDistance) {
      if(!iIntersect) (*this)(*it, cdist, x, y, z, localMetric, ge);
      currentDistance = cdist;
      currentClosest = *it;
      v = localMetric;
      _closestPoint = CLOSEST;
    }
  }
  if(iIntersect)
    for(std::size_t i = 0; i < hop.size(); i++)
      v = intersection_conserveM1(v, hop[i]);
  metr = v;
}

FieldManager::FieldManager()
{
  mapTypeName["Structured"] = new FieldFactoryT<StructuredField>();
  mapTypeName["Threshold"] = new FieldFactoryT<ThresholdField>();
  mapTypeName["BoundaryLayer"] = new FieldFactoryT<BoundaryLayerField>();
  mapTypeName["Box"] = new FieldFactoryT<BoxField>();
  mapTypeName["Cylinder"] = new FieldFactoryT<CylinderField>();
  mapTypeName["Ball"] = new FieldFactoryT<BallField>();
  mapTypeName["Frustum"] = new FieldFactoryT<FrustumField>();
  mapTypeName["LonLat"] = new FieldFactoryT<LonLatField>();
#if defined(HAVE_POST)
  mapTypeName["PostView"] = new FieldFactoryT<PostViewField>();
#endif
  mapTypeName["Gradient"] = new FieldFactoryT<GradientField>();
  mapTypeName["Octree"] = new FieldFactoryT<OctreeField>();
  mapTypeName["Distance"] = new FieldFactoryT<DistanceField>();
  mapTypeName["Restrict"] = new FieldFactoryT<RestrictField>();
  mapTypeName["Min"] = new FieldFactoryT<MinField>();
  mapTypeName["MinAniso"] = new FieldFactoryT<MinAnisoField>();
  mapTypeName["IntersectAniso"] = new FieldFactoryT<IntersectAnisoField>();
  mapTypeName["Max"] = new FieldFactoryT<MaxField>();
  mapTypeName["Laplacian"] = new FieldFactoryT<LaplacianField>();
  mapTypeName["Mean"] = new FieldFactoryT<MeanField>();
  mapTypeName["Curvature"] = new FieldFactoryT<CurvatureField>();
  mapTypeName["Param"] = new FieldFactoryT<ParametricField>();
  mapTypeName["ExternalProcess"] = new FieldFactoryT<ExternalProcessField>();
  mapTypeName["MathEval"] = new FieldFactoryT<MathEvalField>();
  mapTypeName["MathEvalAniso"] = new FieldFactoryT<MathEvalFieldAniso>();
#if defined(HAVE_ANN)
  mapTypeName["Attractor"] = new FieldFactoryT<AttractorField>();
  mapTypeName["AttractorAnisoCurve"] =
    new FieldFactoryT<AttractorAnisoCurveField>();
#endif
  mapTypeName["MaxEigenHessian"] = new FieldFactoryT<MaxEigenHessianField>();
  mapTypeName["AutomaticMeshSizeField"] =
    new FieldFactoryT<automaticMeshSizeField>();
  _backgroundField = -1;
}

void FieldManager::initialize()
{
  auto it = begin();
  for(; it != end(); ++it) it->second->update();
}

FieldManager::~FieldManager()
{
  for(auto it = mapTypeName.begin(); it != mapTypeName.end(); it++)
    delete it->second;
  for(auto it = begin(); it != end(); it++) delete it->second;
}

void FieldManager::setBackgroundField(Field *BGF)
{
  int id = newId();
  (*this)[id] = BGF;
  _backgroundField = id;
}

void Field::putOnNewView(int viewTag)
{
#if defined(HAVE_POST)
  if(GModel::current()->getMeshStatus() < 1) {
    Msg::Error("No mesh available to create the view: please mesh your model!");
    return;
  }
  std::map<int, std::vector<double> > d;
  std::vector<GEntity *> entities;
  GModel::current()->getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *v = entities[i]->mesh_vertices[j];
      d[v->getNum()].push_back((*this)(v->x(), v->y(), v->z(), entities[i]));
    }
  }
  std::ostringstream oss;
  oss << "Field " << id;
  PView *view =
    new PView(oss.str(), "NodeData", GModel::current(), d, 0, -1, viewTag);
  view->setChanged(true);
#endif
}

#if defined(HAVE_POST)
void Field::putOnView(PView *view, int comp)
{
  PViewData *data = view->getData();
  for(int ent = 0; ent < data->getNumEntities(0); ent++) {
    for(int ele = 0; ele < data->getNumElements(0, ent); ele++) {
      if(data->skipElement(0, ent, ele)) continue;
      for(int nod = 0; nod < data->getNumNodes(0, ent, ele); nod++) {
        double x, y, z;
        data->getNode(0, ent, ele, nod, x, y, z);
        double val = (*this)(x, y, z);
        for(int comp = 0; comp < data->getNumComponents(0, ent, ele); comp++)
          data->setValue(0, ent, ele, nod, comp, val);
      }
    }
  }
  std::ostringstream oss;
  oss << "Field " << id;
  data->setName(oss.str());
  data->finalize();
  view->setChanged(true);
  data->destroyAdaptiveData();
}
#endif

void FieldManager::setBackgroundMesh(int iView)
{
  int id = newId();
  Field *f = newField(id, "PostView");
  f->options["IView"]->numericalValue(iView);
  (*this)[id] = f;
  _backgroundField = id;
}

GenericField::GenericField(){};

GenericField::~GenericField(){};

double GenericField::operator()(double x, double y, double z, GEntity *ge)
{
  std::vector<double> sizes(cbs_with_data.size() +
                            cbs_extended_with_data.size());
  auto it = sizes.begin();

  // Go over all callback functions
  for(auto itcbs = cbs_with_data.begin(); itcbs != cbs_with_data.end();
      itcbs++, it++) {
    bool ok = (itcbs->first)(x, y, z, itcbs->second, (*it));
    if(!ok) { Msg::Warning("GenericField::ERROR from callback "); }
  }

  // Go over all extended callback functions
  for(auto itcbs = cbs_extended_with_data.begin();
      itcbs != cbs_extended_with_data.end(); itcbs++, it++) {
    bool ok = (itcbs->first)(x, y, z, ge, itcbs->second, (*it));
    if(!ok) { Msg::Warning("GenericField::ERROR from callback "); }
  }

  // Take minimum value
  return (*std::min_element(sizes.begin(), sizes.end()));
}

void GenericField::setCallbackWithData(ptrfunction fct, void *data)
{
  cbs_with_data.push_back(std::make_pair(fct, data));
}

void GenericField::setCallbackWithData(ptrfunctionextended fct, void *data)
{
  cbs_extended_with_data.push_back(std::make_pair(fct, data));
}
