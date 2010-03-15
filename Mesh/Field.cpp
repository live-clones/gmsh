// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Jonathan Lambrechts
//

#include <stdlib.h>
#include <list>
#include <math.h>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include "GmshConfig.h"
#include "Context.h"
#include "Field.h"
#include "GeoInterpolation.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "mathEvaluator.h"

#if defined(HAVE_POST)
#include "OctreePost.h"
#include "PViewDataList.h"
#include "MVertex.h"
#endif

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
#endif

class FieldOptionDouble : public FieldOption
{
 public:
  double &val;
  FieldOptionType getType(){ return FIELD_OPTION_DOUBLE; }
  FieldOptionDouble(double &_val, std::string _help, bool *_status=0)
    : FieldOption(_help, _status), val(_val){}
  double numericalValue() const { return val; }
  void numericalValue(double v){ modified(); val = v; }
  void getTextRepresentation(std::string &v_str)
  {
    std::ostringstream sstream;
    sstream.precision(16);
    sstream << val;
    v_str = sstream.str();
  }
};

class FieldOptionInt : public FieldOption
{
 public:
  int &val;
  FieldOptionType getType(){ return FIELD_OPTION_INT; }
  FieldOptionInt(int &_val, std::string _help, bool *_status=0) 
    : FieldOption(_help, _status), val(_val){}
  double numericalValue() const { return val; }
  void numericalValue(double v){ modified(); val = (int)v; }
  void getTextRepresentation(std::string & v_str)
  {
    std::ostringstream sstream;
    sstream << val;
    v_str = sstream.str();
  }
};

class FieldOptionList : public FieldOption
{
 public:
  std::list<int> &val;
  FieldOptionType getType(){ return FIELD_OPTION_LIST; }
  FieldOptionList(std::list<int> &_val, std::string _help, bool *_status=0) 
    : FieldOption(_help, _status), val(_val) {}
  std::list<int> &list(){ modified(); return val; }
  const std::list<int>& list() const { return val; }
  void getTextRepresentation(std::string & v_str)
  {
    std::ostringstream sstream;
    sstream << "{";
    for(std::list<int>::iterator it = val.begin(); it != val.end(); it++) {
      if(it != val.begin())
        sstream << ", ";
      sstream << *it;
    }
    sstream << "}";
    v_str = sstream.str();
  }
};

class FieldOptionString : public FieldOption
{
 public:
  std::string & val;
  virtual FieldOptionType getType(){ return FIELD_OPTION_STRING; }
  FieldOptionString(std::string &_val, std::string _help, bool *_status=0)
    : FieldOption(_help, _status), val(_val) {}
  std::string &string() { modified(); return val; }
  const std::string &string() const { return val; }
  void getTextRepresentation(std::string &v_str)
  {
    std::ostringstream sstream;
    sstream << "\"" << val << "\"";
    v_str = sstream.str();
  }
};

class FieldOptionPath : public FieldOptionString
{
 public:
  virtual FieldOptionType getType(){ return FIELD_OPTION_PATH; }
  FieldOptionPath(std::string &_val, std::string _help, bool *_status=0)
    : FieldOptionString(_val, _help, _status) {}
};

class FieldOptionBool : public FieldOption
{
 public:
  bool & val;
  FieldOptionType getType(){ return FIELD_OPTION_BOOL; }
  FieldOptionBool(bool & _val, std::string _help, bool *_status=0)
    : FieldOption(_help, _status), val(_val) {}
  double numericalValue() const { return val; }
  void numericalValue(double v){ modified(); val = v; }
  void getTextRepresentation(std::string & v_str)
  {
    std::ostringstream sstream;
    sstream << val;
    v_str = sstream.str();
  }
};

void FieldManager::reset()
{
  for(std::map<int, Field *>::iterator it = begin(); it != end(); it++) {
    delete it->second;
  }
  clear();
}

Field *FieldManager::get(int id)
{
  iterator it = find(id);
  if(it == end()) return NULL;
  return it->second;
}

Field *FieldManager::newField(int id, std::string type_name)
{
  if(find(id) != end()) {
    Msg::Error("Field id %i is already defined", id);
    return 0;
  }
  if(map_type_name.find(type_name) == map_type_name.end()) {
    Msg::Error("Unknown field type \"%s\"", type_name.c_str());
    return 0;
  }
  Field *f = (*map_type_name[type_name]) ();
  if(!f)
    return 0;
  f->id = id;
  (*this)[id] = f;
  return f;
}

int FieldManager::newId()
{
  int i = 0;
  iterator it = begin();
  while(1) {
    i++;
    while(it != end() && it->first < i)
      it++;
    if(it == end() || it->first != i)
      break;
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
  iterator it = find(id);
  if(it == end()) {
    Msg::Error("Cannot delete field id %i, it does not exist", id);
    return;
  }
  delete it->second;
  erase(it);
}

// StructuredField
class StructuredField : public Field
{
  double o[3], d[3];
  int n[3];
  double *data;
  bool error_status;
  bool text_format;
  std::string file_name;
 public:
  StructuredField()
  {
    options["FileName"] = new FieldOptionPath
      (file_name, "Name of the input file", &update_needed);
    text_format = false;
    options["TextFormat"] = new FieldOptionBool
      (text_format, "True for ASCII input files, false for binary files (4 bite "
       "signed integers for n, double precision floating points for v, D and O)", 
       &update_needed);
    data = 0;
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
      "between nodes in each direction, n are the numbers of nodes in each "
      "direction, and v are the values on each node.";
  }
  const char *getName()
  {
    return "Structured";
  }
  virtual ~StructuredField()
  {
    if(data) delete[]data;
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    if(update_needed) {
      error_status = false;
      try {
        std::ifstream input;
        if(text_format)
          input.open(file_name.c_str());
        else
          input.open(file_name.c_str(),std::ios::binary);
        if(!input.is_open())
          throw(1);
        input.
          exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::
                     ifstream::badbit);
        if(!text_format) {
          input.read((char *)o, 3 * sizeof(double));
          input.read((char *)d, 3 * sizeof(double));
          input.read((char *)n, 3 * sizeof(int));
          int nt = n[0] * n[1] * n[2];
          if(data)
            delete[]data;
          data = new double[nt];
          input.read((char *)data, nt * sizeof(double));
        }
        else {
          input >> o[0] >> o[1] >> o[2] >> d[0] >> d[1] >> d[2] >> n[0] >>
            n[1] >> n[2];
          int nt = n[0] * n[1] * n[2];
          if(data)
            delete[]data;
          data = new double[nt];
          for(int i = 0; i < nt; i++)
            input >> data[i];
        }
        input.close();
      }
      catch(...) {
        error_status = true;
        Msg::Error("Field %i : error reading file %s", this->id, file_name.c_str());
      }
      update_needed = false;
    }
    if(error_status)
      return MAX_LC;
    //tri-linear
    int id[2][3];
    double xi[3];
    double xyz[3] = { x, y, z };
    for(int i = 0; i < 3; i++) {
      id[0][i] = (int)floor((xyz[i] - o[i]) / d[i]);
      id[1][i] = id[0][i] + 1;
      id[0][i] = std::max(std::min(id[0][i], n[i] - 1), 0);
      id[1][i] = std::max(std::min(id[1][i], n[i] - 1), 0);
      xi[i] = (xyz[i] - (o[i] + id[0][i] * d[i])) / d[i];
      xi[i] = std::max(std::min(xi[i], 1.), 0.);
    }
    double v = 0;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
        for(int k = 0; k < 2; k++) {
          v += data[id[i][0] * n[1] * n[2] + id[j][1] * n[2] + id[k][2]]
            * (i * xi[0] + (1 - i) * (1 - xi[0]))
            * (j * xi[1] + (1 - j) * (1 - xi[1]))
            * (k * xi[2] + (1 - k) * (1 - xi[2]));
        }
    return v;
  }
};

class UTMField : public Field
{
  int iField, zone;
  double a, b, n, n2, n3, n4, n5, e, e2, e1, e12, e13, e14, J1, J2, J3, J4,
    Ap, Bp, Cp, Dp, Ep, e4, e6, ep, ep2, ep4, k0, mu_fact;
 public:
  std::string getDescription()
  {
    return "Evaluate Field[IField] in Universal Transverse Mercator coordinates.\n\n"
      "The formulas for the coordinates transformation are taken from:\n\n"
      "  http://www.uwgb.edu/dutchs/UsefulData/UTMFormulas.HTM";
  }
  UTMField()
  {
    iField = 1;
    zone = 0;
    options["IField"] = new FieldOptionInt
      (iField, "Index of the field to evaluate");
    options["Zone"] = new FieldOptionInt
      (zone, "Zone of the UTM projection");
    a = 6378137; // Equatorial Radius
    b = 6356752.3142; // Rayon Polar Radius
    // see http://www.uwgb.edu/dutchs/UsefulData/UTMFormulas.HTM
    n = (a - b) / (a + b);
    n2 = n * n;
    n3 = n * n * n;
    n4 = n * n * n * n;
    n5 = n * n * n * n * n;
    e = sqrt(1 - b * b / a / a);
    e2 = e * e;
    e1 = (1 - sqrt(1 - e2)) / (1 + sqrt(1 - e2));
    e12 = e1 * e1;
    e13 = e1 * e1 * e1;
    e14 = e1 * e1 * e1 * e1;
    J1 = (3 * e1 / 2 - 27 * e13 / 32);
    J2 = (21 * e12 / 16 - 55 * e14 / 32);
    J3 = 151 * e13 / 96;
    J4 = 1097 * e14 / 512;
    Ap = a * (1 - n + (5. / 4.) * (n2 - n3) + (81. / 64.) * (n4 - n5));
    Bp = -3 * a * n / 2 * (1 - n + (7. / 8.) * (n2 - n3) +
                           (55. / 64.) * (n4 - n5));
    Cp = 14 * a * n2 / 16 * (1 - n + (3. / 4) * (n2 - n3));
    Dp = -35 * a * n3 / 48 * (1 - n + 11. / 16. * (n2 - n3));
    Ep = +315 * a * n4 / 51 * (1 - n);
    e4 = e2 * e2;
    e6 = e2 * e2 * e2;
    ep = e * a / b;
    ep2 = ep * ep;
    ep4 = ep2 * ep2;
    k0 = 0.9996;
    mu_fact = 1 / (k0 * a * (1 - e2 / 4 - 3 * e4 / 64 - 5 * e6 / 256));
  }
  const char *getName()
  {
    return "UTM";
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    double r = sqrt(x * x + y * y + z * z);
    double lon = atan2(y, x);
    double lat = asin(z / r);
    double meridionalarc = Ap * lat + Bp * sin(2 * lat)
      + Cp * sin(4 * lat) + Dp * sin(6 * lat) + Ep;
    double slat = sin(lat);
    double clat = cos(lat);
    double slat2 = slat * slat;
    double clat2 = clat * clat;
    double clat3 = clat2 * clat;
    double clat4 = clat3 * clat;
    double tlat2 = slat2 / clat2;
    double nu = a / sqrt(1 - e * e * slat2);
    double p = lon - ((zone - 0.5) / 30 - 1) * M_PI;
    double p2 = p * p;
    double p3 = p * p2;
    double p4 = p2 * p2;
    double utm_x =
      k0 * nu * clat * p + (k0 * nu * clat3 / 6) * (1 - tlat2 +
                                                    ep2 * clat2) * p3 + 5e5;
    double utm_y =
      meridionalarc * k0 + k0 * nu * slat * clat / 2 * p2 +
      k0 * nu * slat * clat3 / 24 * (5 - tlat2 + 9 * ep2 * clat2 +
                                     4 * ep4 * clat4) * p4;
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) return MAX_LC;
    return (*field)(utm_x, utm_y, 0);
  }
};

class LonLatField : public Field
{
  int iField;
 public:
  std::string getDescription()
  {
    return "Evaluate Field[IField] in geographic coordinates (longitude, latitude):\n\n"
      "  F = Field[IField](atan(y/x), asin(z/sqrt(x^2+y^2+z^2))";
  }
  LonLatField()
  {
    iField = 1;
    options["IField"] = new FieldOptionInt
      (iField, "Index of the field to evaluate.");
  }
  const char *getName()
  {
    return "LonLat";
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) return MAX_LC;
    return (*field)(atan2(y, x), asin(z / sqrt(x * x + y * y + z * z)), 0);
  }
};

class BoxField : public Field
{
  double v_in, v_out, x_min, x_max, y_min, y_max, z_min, z_max;
 public:
  std::string getDescription()
  {
    return "The value of this field is VIn inside the box, VOut outside the box. "
      "The box is given by\n\n"
      "  Xmin <= x <= XMax &&\n"
      "  YMin <= y <= YMax &&\n"
      "  ZMin <= z <= ZMax";
  }
  BoxField()
  {
    v_in = v_out = x_min = x_max = y_min = y_max = z_min = z_max = 0;
    options["VIn"] = new FieldOptionDouble
      (v_in, "Value inside the box");
    options["VOut"] = new FieldOptionDouble
      (v_out, "Value outside the box");
    options["XMin"] = new FieldOptionDouble
      (x_min, "Minimum X coordinate of the box");
    options["XMax"] = new FieldOptionDouble
      (x_max, "Maximum X coordinate of the box");
    options["YMin"] = new FieldOptionDouble
      (y_min, "Minimum Y coordinate of the box");
    options["YMax"] = new FieldOptionDouble
      (y_max, "Maximum Y coordinate of the box");
    options["ZMin"] = new FieldOptionDouble
      (z_min, "Minimum Z coordinate of the box");
    options["ZMax"] = new FieldOptionDouble
      (z_max, "Maximum Z coordinate of the box");    
  }
  const char *getName()
  {
    return "Box";
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {    
    return (x <= x_max && x >= x_min && y <= y_max && y >= y_min && z <= z_max
            && z >= z_min) ? v_in : v_out;
  }
};

class CylinderField : public Field
{
  double v_in, v_out;
  double xc,yc,zc;
  double xa,ya,za;
  double R;
  
 public:
  std::string getDescription()
  {
    return "The value of this field is VIn inside a frustrated cylinder, VOut outside. "
      "The cylinder is given by\n\n"
      "  ||dX||^2 < R^2 &&\n"
      "  (X-X0).A < ||A||^2\n"
      "  dX = (X - X0) - ((X - X0).A)/(||A||^2) . A";
  }
  CylinderField()
  {
    v_in = v_out = xc = yc = zc = xa = ya = R = 0;
    za = 1.;
    
    options["VIn"] = new FieldOptionDouble
      (v_in, "Value inside the cylinder");
    options["VOut"] = new FieldOptionDouble
      (v_out, "Value outside the cylinder");

    options["XCenter"] = new FieldOptionDouble
      (xc, "X coordinate of the cylinder center");
    options["YCenter"] = new FieldOptionDouble
      (yc, "Y coordinate of the cylinder center");
    options["ZCenter"] = new FieldOptionDouble
      (zc, "Z coordinate of the cylinder center");

    
    options["XAxis"] = new FieldOptionDouble
      (xa, "X component of the cylinder axis");
    options["YAxis"] = new FieldOptionDouble
      (ya, "Y component of the cylinder axis");
    options["ZAxis"] = new FieldOptionDouble
      (za, "Z component of the cylinder axis");

    options["Radius"] = new FieldOptionDouble
      (R,"Radius");    
    
  }
  const char *getName()
  {
    return "Cylinder";
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {    
    double dx = x-xc;
    double dy = y-yc;
    double dz = z-zc;
    
    double adx = (xa * dx + ya * dy + za * dz)/(xa*xa + ya*ya + za*za);
    
    dx -= adx * xa;
    dy -= adx * ya;
    dz -= adx * za;
    
    return ((dx*dx + dy*dy + dz*dz < R*R) && fabs(adx) < 1) ? v_in : v_out;
    
  }
};

class ThresholdField : public Field
{
 protected :
  int iField;
  double dmin, dmax, lcmin, lcmax;
  bool sigmoid, stopAtDistMax;
 public:
  virtual const char *getName()
  {
    return "Threshold";
  }
  virtual std::string getDescription()
  {
    return "F = LCMin if Field[IField] <= DistMin,\n"
      "F = LCMax if Field[IField] >= DistMax,\n"
      "F = interpolation between LcMin and LcMax if DistMin < Field[IField] < DistMax";
  }
  ThresholdField()
  {
    iField = 0;
    dmin = 1;
    dmax = 10;
    lcmin = 0.1;
    lcmax = 1;
    sigmoid = false;
    stopAtDistMax = false;
    options["IField"] = new FieldOptionInt
      (iField, "Index of the field to evaluate");
    options["DistMin"] = new FieldOptionDouble
      (dmin, "Distance from entity up to which element size will be LcMin");
    options["DistMax"] = new FieldOptionDouble
      (dmax, "Distance from entity after which element size will be LcMax");
    options["LcMin"] = new FieldOptionDouble
      (lcmin, "Element size inside DistMin");
    options["LcMax"] = new FieldOptionDouble
      (lcmax, "Element size outside DistMax");
    options["Sigmoid"] = new FieldOptionBool
      (sigmoid, "True to interpolate between LcMin and LcMax using a sigmoid, "
       "false to interpolate linearly");
    options["StopAtDistMax"] = new FieldOptionBool
      (stopAtDistMax, "True to not impose element size outside DistMax (i.e., "
       "F = a very big value if Field[IField] > DistMax)");
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) return MAX_LC;
    double r = ((*field) (x, y, z) - dmin) / (dmax - dmin);
    r = std::max(std::min(r, 1.), 0.);
    double lc;
    if(stopAtDistMax && r >= 1.){
      lc = MAX_LC;
    }
    else if(sigmoid){
      double s = exp(12. * r - 6.) / (1. + exp(12. * r - 6.));
      lc = lcmin * (1. - s) + lcmax * s;
    }
    else{ // linear
      lc = lcmin * (1 - r) + lcmax * r;
    }
    return lc;
  }
};

class BoundaryLayerField : public ThresholdField {
public:
  BoundaryLayerField() 
  {  }
  virtual bool isotropic () const {return false;}
  virtual const char *getName()
  {
    return "BoundaryLayer";
  }
  virtual std::string getDescription()
  {
    return "F = LCMin if Field[IField] <= DistMin,\n"
      "F = LCMax if Field[IField] >= DistMax,\n"
      "F = interpolation between LcMin and LcMax if DistMin < Field[IField] < DistMax";
  }
  virtual void operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge=0)
  {
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) {
      metr(0,0) = 1/(MAX_LC*MAX_LC);
      metr(1,1) = 1/(MAX_LC*MAX_LC);
      metr(2,2) = 1/(MAX_LC*MAX_LC);
      metr(0,1) = metr(0,2) = metr(1,2) = 0;
      return;
    }
    double dist = (*field) (x, y, z);

    double r = (dist - dmin) / (dmax - dmin);
    r = std::max(std::min(r, 1.), 0.);
    double lc;
    if(stopAtDistMax && r >= 1.){
      lc = MAX_LC;
    }
    else if(sigmoid){
      double s = exp(12. * r - 6.) / (1. + exp(12. * r - 6.));
      lc = lcmin * (1. - s) + lcmax * s;
    }
    else{ // linear
      lc = lcmin * (1 - r) + lcmax * r;
    }
    
    double delta = std::min(CTX::instance()->lc / 1e4, dist);
    double gx =
      ((*field) (x + delta / 2, y, z) -
       (*field) (x - delta / 2, y, z)) / delta;
    double gy =
      ((*field) (x, y + delta / 2, z) -
       (*field) (x, y - delta / 2, z)) / delta;
    double gz =
      ((*field) (x, y, z + delta / 2) -
       (*field) (x, y, z - delta / 2)) / delta;

    SVector3 g(gx,gy,gz);
    g.normalize();
    SVector3 t1,t2;

    if (fabs(gx) < fabs(gy) && fabs(gx) < fabs(gz))
      t1 = SVector3(1,0,0);
    else if (fabs(gy) < fabs(gx) && fabs(gy) < fabs(gz))
      t1 = SVector3(0,1,0);
    else
      t1 = SVector3(0,0,1);
    
    t2 = crossprod(g,t1);
    t2.normalize();
    t1 = crossprod(t2,g);
    
    metr  = SMetric3(1./(lc*lc), 
                     1/(lcmax*lcmax),
                     1/(lcmax*lcmax),
                     g,t1,t2);
  }
};

class GradientField : public Field
{
  int iField, kind;
  double delta;
 public:
  const char *getName()
  {
    return "Gradient";
  }
  std::string getDescription()
  {
    return "Compute the finite difference gradient of Field[IField]:\n\n"
      "  F = (Field[IField](X + Delta/2) - "
      "       Field[IField](X - Delta/2)) / Delta";
  }
  GradientField() : iField(0), kind(3), delta(CTX::instance()->lc / 1e4)
  {
    iField = 1;
    kind = 0;
    delta = 0.;
    options["IField"] = new FieldOptionInt
      (iField, "Field index");
    options["Kind"] = new FieldOptionInt
      (kind, "Component of the gradient to evaluate: 0 for X, 1 for Y, 2 for Z, "
       "3 for the norm");
    options["Delta"] = new FieldOptionDouble
      (delta, "Finite difference step");
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) return MAX_LC;
    double gx, gy, gz;
    switch (kind) {
    case 0:    /* x */
      return ((*field) (x + delta / 2, y, z) -
              (*field) (x - delta / 2, y, z)) / delta;
    case 1:    /* y */
      return ((*field) (x, y + delta / 2, z) -
              (*field) (x, y - delta / 2, z)) / delta;
    case 2:    /* z */
      return ((*field) (x, y, z + delta / 2) -
              (*field) (x, y, z - delta / 2)) / delta;
    case 3:    /* norm */
      gx =
        ((*field) (x + delta / 2, y, z) -
         (*field) (x - delta / 2, y, z)) / delta;
      gy =
        ((*field) (x, y + delta / 2, z) -
         (*field) (x, y - delta / 2, z)) / delta;
      gz =
        ((*field) (x, y, z + delta / 2) -
         (*field) (x, y, z - delta / 2)) / delta;
      return sqrt(gx * gx + gy * gy + gz * gz);
    default:
      Msg::Error("Field %i : Unknown kind (%i) of gradient", this->id,
                 kind);
      return MAX_LC;
    }
  }
};


class CurvatureField : public Field
{
  int iField;
  double delta;
 public:
  const char *getName()
  {
    return "Curvature";
  }
  std::string getDescription()
  {
    return "Compute the curvature of Field[IField]:\n\n"
      "  F = div(norm(grad(Field[IField])))";
  }
  CurvatureField() : iField(0), delta(CTX::instance()->lc / 1e4)
  {
    iField = 1;
    delta = 0.;
    options["IField"] = new FieldOptionInt
      (iField, "Field index");
    options["Delta"] = new FieldOptionDouble
      (delta, "Step of the finite differences");
  }
  void grad_norm(Field &f, double x, double y, double z, double *g)
  {
    g[0] = f(x + delta / 2, y, z) - f(x - delta / 2, y, z);
    g[1] = f(x, y + delta / 2, z) - f(x, y - delta / 2, z);
    g[2] = f(x, y, z + delta / 2) - f(x, y, z - delta / 2);
    double n=sqrt(g[0] * g[0] + g[1] * g[1] + g[2] * g[2]);
    g[0] /= n;
    g[1] /= n;
    g[2] /= n;
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) return MAX_LC;
    double grad[6][3];
    grad_norm(*field, x + delta / 2, y, z, grad[0]);
    grad_norm(*field, x - delta / 2, y, z, grad[1]);
    grad_norm(*field, x, y + delta / 2, z, grad[2]);
    grad_norm(*field, x, y - delta / 2, z, grad[3]);
    grad_norm(*field, x, y, z + delta / 2, grad[4]);
    grad_norm(*field, x, y, z - delta / 2, grad[5]);
    return (grad[0][0] - grad[1][0] + grad[2][1] - 
            grad[3][1] + grad[4][2] - grad[5][2]) / delta;
  }
};

class MaxEigenHessianField : public Field
{
  int iField;
  double delta;
 public:
  const char *getName()
  {
    return "MaxEigenHessian";
  }
  std::string getDescription()
  {
    return "Compute the maximum eigenvalue of the Hessian matrix of "
      "Field[IField], with the gradients evaluated by finite differences:\n\n"
      "  F = max(eig(grad(grad(Field[IField]))))";
  }
  MaxEigenHessianField() : iField(0), delta(CTX::instance()->lc / 1e4)
  {
    iField = 1;
    delta = 0.;
    options["IField"] = new FieldOptionInt
      (iField, "Field index");
    options["Delta"] = new FieldOptionDouble
      (delta, "Step used for the finite differences");
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) return MAX_LC;
    double mat[3][3], eig[3];
    mat[1][0] = mat[0][1] = (*field) (x + delta / 2 , y + delta / 2, z)
      + (*field) (x - delta / 2 , y - delta / 2, z)
      - (*field) (x - delta / 2 , y + delta / 2, z)
      - (*field) (x + delta / 2 , y - delta / 2, z);
    mat[2][0] = mat[0][2] = (*field) (x + delta/2 , y, z + delta / 2)
      + (*field) (x - delta / 2 , y, z - delta / 2)
      - (*field) (x - delta / 2 , y, z + delta / 2)
      - (*field) (x + delta / 2 , y, z - delta / 2);
    mat[2][1] = mat[1][2] = (*field) (x, y + delta/2 , z + delta / 2)
      + (*field) (x, y - delta / 2 , z - delta / 2)
      - (*field) (x, y - delta / 2 , z + delta / 2)
      - (*field) (x, y + delta / 2 , z - delta / 2);
    double f = (*field)(x, y, z);
    mat[0][0] = (*field)(x + delta, y, z) + (*field)(x - delta, y, z) - 2 * f;
    mat[1][1] = (*field)(x, y + delta, z) + (*field)(x, y - delta, z) - 2 * f;
    mat[2][2] = (*field)(x, y, z + delta) + (*field)(x, y, z - delta) - 2 * f;
    eigenvalue(mat, eig);
    return eig[0] / (delta * delta);
  }
};

class LaplacianField : public Field
{
  int iField;
  double delta;
 public:
  const char *getName()
  {
    return "Laplacian";
  }
  std::string getDescription()
  {
    return "Compute finite difference the Laplacian of Field[IField]:\n\n"
      "  F = G(x+d,y,z) + G(x-d,y,z) +\n"
      "      G(x,y+d,z) + G(x,y-d,z) +\n"
      "      G(x,y,z+d) + G(x,y,z-d) - 6 * G(x,y,z),\n\n"
      "where G=Field[IField] and d=Delta";
  }
  LaplacianField() : iField(0), delta(CTX::instance()->lc / 1e4)
  {
    iField = 1;
    delta = 0.1;
    options["IField"] = new FieldOptionInt
      (iField, "Field index");
    options["Delta"] = new FieldOptionDouble
      (delta, "Finite difference step");
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) return MAX_LC;
    return ((*field) (x + delta , y, z)+ (*field) (x - delta , y, z)
            +(*field) (x, y + delta , z)+ (*field) (x, y - delta , z)
            +(*field) (x, y, z + delta )+ (*field) (x, y, z - delta )
            -6* (*field) (x , y, z)) / (delta*delta);
  }
};

class MeanField : public Field
{
  int iField;
  double delta;
 public:
  const char *getName()
  {
    return "Mean";
  }
  std::string getDescription()
  {
    return "Simple smoother:\n\n"
      "  F = (G(x+delta,y,z) + G(x-delta,y,z) +\n"
      "       G(x,y+delta,z) + G(x,y-delta,z) +\n"
      "       G(x,y,z+delta) + G(x,y,z-delta) +\n"
      "       G(x,y,z)) / 7,\n\n"
      "where G=Field[IField]";
  }
  MeanField() : iField(0), delta(CTX::instance()->lc / 1e4)
  {
    options["IField"] = new FieldOptionInt
      (iField, "Field index");
    options["Delta"] = new FieldOptionDouble
      (delta, "Distance used to compute the mean value");
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) return MAX_LC;
    return ((*field) (x + delta , y, z) + (*field) (x - delta, y, z)
            + (*field) (x, y + delta, z) + (*field) (x, y - delta, z)
            + (*field) (x, y, z + delta) + (*field) (x, y, z - delta)
            + (*field) (x, y, z)) / 7;
  }
};

class MathEvalExpression
{
 private:
  mathEvaluator *_f;
  std::set<int> _fields;
 public:
  MathEvalExpression() : _f(0) {}
  ~MathEvalExpression(){ if(_f) delete _f; }
  bool set_function(const std::string &f)
  {
    // get id numbers of fields appearing in the function
    _fields.clear();
    unsigned int i = 0;
    while(i < f.size()){
      unsigned int j = 0;
      if(f[i] == 'F'){
        std::string id("");
        while(i + 1 + j < f.size() && f[i + 1 + j] >= '0' && f[i + 1 + j] <= '9'){
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
    for(std::set<int>::iterator it = _fields.begin(); it != _fields.end(); it++){
      std::ostringstream sstream;
      sstream << "F" << *it;
      variables[i++] = sstream.str();
    }
    if(_f) delete _f;
    _f = new mathEvaluator(expressions, variables);
    if(expressions.empty()) {
      delete _f;
      _f = 0;
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
    for(std::set<int>::iterator it = _fields.begin(); it != _fields.end(); it++){
      Field *field = GModel::current()->getFields()->get(*it);
      values[i++] = field ? (*field)(x, y, z) : MAX_LC;
    }
    if(_f->eval(values, res)) 
      return res[0];
    else
      return MAX_LC;
  }
};

class MathEvalField : public Field
{
  MathEvalExpression expr;
  std::string f;
 public:
  MathEvalField()
  {
    options["F"] = new FieldOptionString
      (f, "Mathematical function to evaluate.", &update_needed);
    f = "F2 + Sin(z)";
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    if(update_needed) {
      if(!expr.set_function(f))
        Msg::Error("Field %i: Invalid matheval expression \"%s\"",
                   this->id, f.c_str());
      update_needed = false;
    }
    return expr.evaluate(x, y, z);
  }
  const char *getName()
  {
    return "MathEval";
  }
  std::string getDescription()
  {
    return "Evaluate a mathematical expression. The expression can contain "
      "x, y, z for spatial coordinates, F0, F1, ... for field values, and "
      "and mathematical functions.";
  }
};

class ParametricField : public Field
{
  MathEvalExpression expr[3];
  std::string f[3];
  int iField;
 public:
  ParametricField()
  {
    iField = 1;
    options["IField"] = new FieldOptionInt
      (iField, "Field index");
    options["FX"] = new FieldOptionString
      (f[0], "X component of parametric function", &update_needed);
    options["FY"] = new FieldOptionString
      (f[1], "Y component of parametric function", &update_needed);
    options["FZ"] = new FieldOptionString
      (f[2], "Z component of parametric function", &update_needed);
  }
  std::string getDescription()
  {
    return "Evaluate Field IField in parametric coordinates:\n\n"
      "  F = Field[IField](FX,FY,FZ)\n\n"
      "See the MathEval Field help to get a description of valid FX, FY "
      "and FZ expressions.";
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    if(update_needed) {
      for(int i = 0; i < 3; i++) {
        if(!expr[i].set_function(f[i]))
          Msg::Error("Field %i : Invalid matheval expression \"%s\"",
                     this->id, f[i].c_str());
      }
      update_needed = false;
    }
    Field *field = GModel::current()->getFields()->get(iField);
    if(!field || iField == id) return MAX_LC;
    return (*field)(expr[0].evaluate(x, y, z),
                    expr[1].evaluate(x, y, z),
                    expr[2].evaluate(x, y, z));
  }
  const char *getName()
  {
    return "Param";
  }
};

#if defined(HAVE_POST)
class PostViewField : public Field
{
  OctreePost *octree;
 public:
  int view_index;
  bool crop_negative_values;
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    // we should maybe test the unique view num instead, but that
    // would be slower
    if(view_index < 0 || view_index >= (int)PView::list.size())
      return MAX_LC;
    PView *v = PView::list[view_index];
    if(v->getData()->hasModel(GModel::current())){
      Msg::Error("Cannot use view based on current model for background mesh");
      Msg::Error("Use a list-based view (.pos file) instead?");
      return MAX_LC;
    }
    if(update_needed){
      if(octree) delete octree;
      octree = new OctreePost(v);
      update_needed = false;
    }
    double l = 0.;
    if(!octree->searchScalarWithTol(x, y, z, &l, 0, 0, 10.))
      Msg::Info("No element found containing point (%g,%g,%g)", x, y, z);
    if(l <= 0 && crop_negative_values) return MAX_LC;
    return l;
  }
  const char *getName()
  {
    return "PostView";
  }
  std::string getDescription()
  {
    return "Evaluate the post processing view IView.";
  }
  PostViewField()
  {
    octree = 0;
    view_index = 0;
    options["IView"] = new FieldOptionInt
      (view_index, "Post-processing view index", &update_needed);
    crop_negative_values = true;
    options["CropNegativeValues"] = new FieldOptionBool
      (crop_negative_values, "return LC_MAX instead of a negative value (this "
       "option is needed for backward compatibility with the BackgroundMesh option");
  }
  ~PostViewField()
  {
    if(octree) delete octree;
  }
};
#endif

class MinField : public Field
{
  std::list<int> idlist;
 public:
  MinField()
  {
    options["FieldsList"] = new FieldOptionList
      (idlist, "Field indices", &update_needed);
  }
  std::string getDescription()
  {
    return "Take the minimum value of a list of fields.";
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    double v = MAX_LC;
    for(std::list<int>::iterator it = idlist.begin(); it != idlist.end(); it++) {
      Field *f = (GModel::current()->getFields()->get(*it));
      if(f && *it != id) v = std::min(v, (*f) (x, y, z, ge));
    }
    return v;
  }
  const char *getName()
  {
    return "Min";
  }
};

class MaxField : public Field
{
  std::list<int> idlist;
 public:
  MaxField()
  {
    options["FieldsList"] = new FieldOptionList
      (idlist, "Field indices", &update_needed);
  }
  std::string getDescription()
  {
    return "Take the maximum value of a list of fields.";
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    double v = -MAX_LC;
    for(std::list<int>::iterator it = idlist.begin(); it != idlist.end(); it++) {
      Field *f = (GModel::current()->getFields()->get(*it));
      if(f && *it != id) v = std::max(v, (*f) (x, y, z, ge));
    }
    return v;
  }
  const char *getName()
  {
    return "Max";
  }
};

class RestrictField : public Field
{
  int iField;
  std::list<int> edges, faces, regions;
 public:
  RestrictField()
  {
    iField = 1;
    options["IField"] = new FieldOptionInt(iField, "Field index");
    options["EdgesList"] = new FieldOptionList(edges, "Curve indices");
    options["FacesList"] = new FieldOptionList(faces, "Surface indices");
    options["RegionsList"] = new FieldOptionList(regions, "Volume indices");
  }
  std::string getDescription()
  {
    return "Restrict the application of a field to a given list of geometrical "
      "curves, surfaces or volumes.";
  }
  double operator() (double x, double y, double z, GEntity *ge=0)
  {
    Field *f = (GModel::current()->getFields()->get(iField));
    if(!f || iField == id) return MAX_LC;
    if(!ge) return (*f) (x, y, z);
    if((ge->dim() == 0) ||
       (ge->dim() == 1 && std::find
        (edges.begin(), edges.end(), ge->tag()) != edges.end()) ||
       (ge->dim() == 2 && std::find
        (faces.begin(), faces.end(), ge->tag()) != faces.end()) ||
       (ge->dim() == 3 && std::find
        (regions.begin(), regions.end(), ge->tag()) != regions.end()))
      return (*f) (x, y, z);
    return MAX_LC;
  }
  const char *getName()
  {
    return "Restrict";
  }
};

#if defined(HAVE_ANN)
class AttractorField : public Field
{
  ANNkd_tree *kdtree;
  ANNpointArray zeronodes;
  ANNidxArray index;
  ANNdistArray dist;
  std::list<int> nodes_id, edges_id, faces_id;
  int n_nodes_by_edge;
 public:
  AttractorField() : kdtree(0), zeronodes(0)
  {
    index = new ANNidx[1];
    dist = new ANNdist[1];
    n_nodes_by_edge = 20;
    options["NodesList"] = new FieldOptionList
      (nodes_id, "Indices of nodes in the geometric model", &update_needed);
    options["EdgesList"] = new FieldOptionList
      (edges_id, "Indices of curves in the geometric model", &update_needed);
    options["NNodesByEdge"] = new FieldOptionInt
      (n_nodes_by_edge, "Number of nodes used to discretized each curve",
       &update_needed);
    options["FacesList"] = new FieldOptionList
      (faces_id, "Indices of surfaces in the geometric model (Warning: might "
       "give strange results for complex surfaces)", &update_needed);
  }
  ~AttractorField()
  {
    if(kdtree) delete kdtree;
    if(zeronodes) annDeallocPts(zeronodes);
    delete[]index;
    delete[]dist;
  }
  const char *getName()
  {
    return "Attractor";
  }
  std::string getDescription()
  {
    return "Compute the distance from the nearest node in a list. It can also "
      "be used to compute the distance from curves, in which case each curve "
      "is replaced by NNodesByEdge equidistant nodes and the distance from those "
      "nodes is computed.";
  }
  virtual double operator() (double X, double Y, double Z, GEntity *ge=0)
  {
    if(update_needed) {
      if(zeronodes) {
        annDeallocPts(zeronodes);
        delete kdtree;
      }
      int totpoints = nodes_id.size() + n_nodes_by_edge * edges_id.size() + 
        n_nodes_by_edge * n_nodes_by_edge * faces_id.size();
      if(totpoints)
        zeronodes = annAllocPts(totpoints, 4);
      int k = 0;
      for(std::list<int>::iterator it = nodes_id.begin();
          it != nodes_id.end(); ++it) {
        Vertex *v = FindPoint(*it);
        if(v) {
          zeronodes[k][0] = v->Pos.X;
          zeronodes[k][1] = v->Pos.Y;
          zeronodes[k++][2] = v->Pos.Z;
        }
        else {
          GVertex *gv = GModel::current()->getVertexByTag(*it);
          if(gv) {
            zeronodes[k][0] = gv->x();
            zeronodes[k][1] = gv->y();
            zeronodes[k++][2] = gv->z();
          }
        }
      }
      for(std::list<int>::iterator it = edges_id.begin();
          it != edges_id.end(); ++it) {
        Curve *c = FindCurve(*it);
        if(c) {
          for(int i = 0; i < n_nodes_by_edge; i++) {
            double u = (double)i / (n_nodes_by_edge - 1);
            Vertex V = InterpolateCurve(c, u, 0);
            zeronodes[k][0] = V.Pos.X;
            zeronodes[k][1] = V.Pos.Y;
            zeronodes[k++][2] = V.Pos.Z;
          }
        }
        else {
          GEdge *e = GModel::current()->getEdgeByTag(*it);
          if(e) {
            for(int i = 0; i < n_nodes_by_edge; i++) {
              double u = (double)i / (n_nodes_by_edge - 1);
              Range<double> b = e->parBounds(0);
              double t = b.low() + u * (b.high() - b.low());
              GPoint gp = e->point(t);
              zeronodes[k][0] = gp.x();
              zeronodes[k][1] = gp.y();
              zeronodes[k++][2] = gp.z();
            }
          }
        }
      }
      // This can lead to weird results as we generate attractors over
      // the whole parametric plane (we should really use a mesh,
      // e.g. a refined STL.)
      for(std::list<int>::iterator it = faces_id.begin();
          it != faces_id.end(); ++it) {
        Surface *s = FindSurface(*it);
        if(s) {
          for(int i = 0; i < n_nodes_by_edge; i++) {
            for(int j = 0; j < n_nodes_by_edge; j++) {
              double u = (double)i / (n_nodes_by_edge - 1);
              double v = (double)j / (n_nodes_by_edge - 1);
              Vertex V = InterpolateSurface(s, u, v, 0, 0);
              zeronodes[k][0] = V.Pos.X;
              zeronodes[k][1] = V.Pos.Y;
              zeronodes[k++][2] = V.Pos.Z;
            }
          }
        }
        else {
          GFace *f = GModel::current()->getFaceByTag(*it);
          if(f) {
            for(int i = 0; i < n_nodes_by_edge; i++) {
              for(int j = 0; j < n_nodes_by_edge; j++) {
                double u = (double)i / (n_nodes_by_edge - 1);
                double v = (double)j / (n_nodes_by_edge - 1);
                Range<double> b1 = ge->parBounds(0);
                Range<double> b2 = ge->parBounds(1);
                double t1 = b1.low() + u * (b1.high() - b1.low());
                double t2 = b2.low() + v * (b2.high() - b2.low());
                GPoint gp = f->point(t1, t2);
                zeronodes[k][0] = gp.x();
                zeronodes[k][1] = gp.y();
                zeronodes[k++][2] = gp.z();
              }
            }
          }
        }
      }
      kdtree = new ANNkd_tree(zeronodes, totpoints, 3);
      update_needed = false;
    }
    double xyz[3] = { X, Y, Z };
    kdtree->annkSearch(xyz, 1, index, dist);
    return sqrt(dist[0]);
  }
};

#endif

template<class F> class FieldFactoryT : public FieldFactory {
 public:
  Field * operator()() { return new F; }
};

template<class F> Field *field_factory()
{
  return new F();
};

FieldManager::FieldManager()
{
  map_type_name["Structured"] = new FieldFactoryT<StructuredField>();
  map_type_name["Threshold"] = new FieldFactoryT<ThresholdField>();
  map_type_name["BoundaryLayer"] = new FieldFactoryT<BoundaryLayerField>();
  map_type_name["Box"] = new FieldFactoryT<BoxField>();
  map_type_name["Cylinder"] = new FieldFactoryT<CylinderField>();
  map_type_name["LonLat"] = new FieldFactoryT<LonLatField>();
#if defined(HAVE_POST)
  map_type_name["PostView"] = new FieldFactoryT<PostViewField>();
#endif
  map_type_name["Gradient"] = new FieldFactoryT<GradientField>();
  map_type_name["Restrict"] = new FieldFactoryT<RestrictField>();
  map_type_name["Min"] = new FieldFactoryT<MinField>();
  map_type_name["Max"] = new FieldFactoryT<MaxField>();
  map_type_name["UTM"] = new FieldFactoryT<UTMField>();
  map_type_name["Laplacian"] = new FieldFactoryT<LaplacianField>();
  map_type_name["Mean"] = new FieldFactoryT<MeanField>();
  map_type_name["Curvature"] = new FieldFactoryT<CurvatureField>();
  map_type_name["Param"] = new FieldFactoryT<ParametricField>();
  map_type_name["MathEval"] = new FieldFactoryT<MathEvalField>();
#if defined(HAVE_ANN)
  map_type_name["Attractor"] = new FieldFactoryT<AttractorField>();
#endif
  map_type_name["MaxEigenHessian"] = new FieldFactoryT<MaxEigenHessianField>();
  background_field = -1;
}

#if defined(HAVE_POST)
void Field::putOnNewView()
{
  if(GModel::current()->getMeshStatus() < 1){
    Msg::Error("No mesh available to create the view: please mesh your model!");
    return;
  }
  std::map<int, std::vector<double> > d;
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      d[v->getNum()].push_back((*this)(v->x(), v->y(), v->z(), entities[i]));
    }
  }
  std::ostringstream oss;
  oss << "Field " << id;
  PView *view = new PView(oss.str(), "NodeData", GModel::current(), d);
  view->setChanged(true);
}

void Field::putOnView(PView *view, int comp)
{
  PViewData *data = view->getData();
  for(int ent = 0; ent < data->getNumEntities(0); ent++){
    for(int ele = 0; ele < data->getNumElements(0, ent); ele++){
      if(data->skipElement(0, ent, ele)) continue;
      for(int nod = 0; nod < data->getNumNodes(0, ent, ele); nod++){
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
  background_field = id;
}
