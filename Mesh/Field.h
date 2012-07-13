// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FIELD_H_
#define _FIELD_H_

#include <string>
#include <map>
#include <list>
#include "GmshConfig.h"
#include "STensor3.h"
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>

#if defined(HAVE_POST)
class PView;
#endif

class Field;
class GEntity;

typedef enum { 
  FIELD_OPTION_DOUBLE = 0,
  FIELD_OPTION_INT,
  FIELD_OPTION_STRING, 
  FIELD_OPTION_PATH,
  FIELD_OPTION_BOOL, 
  FIELD_OPTION_LIST 
} FieldOptionType;

class FieldCallback {
  private:
    std::string _help;
  public:
  virtual void run() = 0;
  FieldCallback(const std::string help){ _help = help;}
  virtual ~FieldCallback(){};
  virtual std::string getDescription(){ return _help; }
};

class FieldOption {
 private:
  std::string _help;
 protected:
  bool *status;
  inline void modified(){ if(status) *status = true; }
 public:
  FieldOption(std::string help, bool *_status) : _help(help), status(_status) {}
  virtual ~FieldOption() {}
  virtual FieldOptionType getType() = 0;
  virtual void getTextRepresentation(std::string & v_str) = 0;
  virtual std::string getDescription(){ return _help; }
  std::string getTypeName(){
    switch(getType()){
    case FIELD_OPTION_INT: return "integer"; break;
    case FIELD_OPTION_DOUBLE: return "float"; break;
    case FIELD_OPTION_BOOL: return "boolean"; break;
    case FIELD_OPTION_PATH: return "path"; break;
    case FIELD_OPTION_STRING: return "string"; break;
    case FIELD_OPTION_LIST: return "list"; break;
    default: return "unknown";
    }
  }
  virtual void numericalValue(double val) { throw(1); }
  virtual double numericalValue() const { throw(1); }
  virtual const std::list<int> &list() const { throw(1); }
  virtual void list(std::list<int> value) { throw(1); }
  virtual std::string string() const { throw(1); }
  virtual void string(const std::string value) { throw(1); }
};

class Field {
 public:
  Field() {}
  virtual ~Field();
  int id;
  std::map<std::string, FieldOption *> options;
  std::map<std::string, FieldCallback*> callbacks;
  virtual bool isotropic () const { return true; }
  // isotropic
  virtual double operator() (double x, double y, double z, GEntity *ge=0) = 0;
  // anisotropic
  virtual void operator() (double x, double y, double z, SMetric3 &, GEntity *ge=0){}
  
  //temporary
  virtual void operator()(double x,double y,double z,SVector3& v1,SVector3& v2,SVector3& v3,GEntity* ge=0){}
  
  bool update_needed;
  //void update(){ printf("up f \n"); return;}
  virtual const char *getName() = 0;
#if defined(HAVE_POST)
  void putOnView(PView * view, int comp = -1);
#endif
  void putOnNewView();
  virtual std::string getDescription(){ return ""; }
  FieldOption * getOption(const std::string optionName);
};

class FieldFactory {
 public:
  virtual ~FieldFactory() {}
  virtual Field * operator() () = 0;
};

class FieldManager : public std::map<int, Field*> {
 private:
  int _background_field;
  int _boundaryLayer_field;
 public:
  std::map<std::string, FieldFactory*> map_type_name;
  void reset();
  Field *get(int id);
  Field *newField(int id, std::string type_name);
  void deleteField(int id);
  int newId();
  int maxId();
  FieldManager();
  ~FieldManager();
  // compatibility with -bgm
  void setBackgroundMesh(int iView);
  // set and get background field
  void setBackgroundField(Field* BGF);
  inline void setBackgroundFieldId(int id){_background_field = id;};
  inline void setBoundaryLayerFieldId(int id){_boundaryLayer_field = id;};
  inline int getBackgroundField(){return _background_field;}
  inline int getBoundaryLayerField(){return _boundaryLayer_field;}
};

// Boundary Layer Field (used both for anisotropic meshing and BL
// extrusion)

#if defined(HAVE_ANN)
class AttractorField;

class BoundaryLayerField : public Field {
 private:
  std::list<AttractorField *> _att_fields;
  std::list<int> nodes_id, edges_id, faces_id;
  void operator() (AttractorField *cc, double dist, double x, double y, double z,
                   SMetric3 &metr, GEntity *ge);
 public:
  double hwall_n,hwall_t,ratio,hfar,thickness,fan_angle; 
  double current_distance, tgt_aniso_ratio;
  SPoint3 _closest_point;
  int iRecombine, iIntersect;
  AttractorField *current_closest;
  virtual bool isotropic () const {return false;}
  virtual const char *getName();
  virtual std::string getDescription();
  BoundaryLayerField();
  virtual double operator() (double x, double y, double z, GEntity *ge=0);
  virtual void operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge=0);
  bool isFaceBL (int iF) const {return std::find(faces_id.begin(),faces_id.end(),iF) != faces_id.end();}
};
#endif
class FieldOptionString : public FieldOption
{
 public:
  std::string & val;
  virtual FieldOptionType getType(){ return FIELD_OPTION_STRING; }
  FieldOptionString(std::string &_val, std::string _help, bool *_status=0)
    : FieldOption(_help, _status), val(_val) {}
  void string(const std::string value) { modified(); val = value;}
  std::string string() const { return val; }
  void getTextRepresentation(std::string &v_str)
  {
    std::ostringstream sstream;
    sstream << "\"" << val << "\"";
    v_str = sstream.str();
  }
};


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
  void list(std::list<int> value){ modified(); val = value; }
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

template<class t>
class FieldCallbackGeneric : public FieldCallback {
  t * _field;
  void (t::*_callback)();
  public :
  void run()
  {
    (_field->*_callback)();
  }
  FieldCallbackGeneric( t *field, void (t::*callback)(), const std::string description) : FieldCallback(description)
  {
    _field = field;
    _callback = callback;
  }
};

#endif
