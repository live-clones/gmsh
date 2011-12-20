// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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

#if defined(HAVE_POST)
#include "PView.h"
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
  virtual std::list<int> &list() { throw(1); }
  virtual const std::string &string() const { throw(1); }
  virtual std::string &string() { throw(1); }
};

class Field {
 public:
  Field() {}
  virtual ~Field() {}
  int id;
  std::map<std::string, FieldOption *> options;
  virtual bool isotropic () const { return true; }
  // isotropic
  virtual double operator() (double x, double y, double z, GEntity *ge=0) = 0;
  // anisotropic
  virtual void operator() (double x, double y, double z, SMetric3 &, GEntity *ge=0){}
  bool update_needed;
  virtual const char *getName() = 0;
#if defined(HAVE_POST)
  void putOnView(PView * view, int comp = -1);
#endif
  void putOnNewView();
  virtual std::string getDescription(){ return ""; }
};

class FieldFactory {
 public:
  virtual ~FieldFactory() {}
  virtual Field * operator() () = 0;
};

class FieldManager : public std::map<int, Field*> {
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
  int background_field;
  int boundaryLayer_field;
  // compatibility with -bgm
  void setBackgroundMesh(int iView);
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
  double hwall_n,hwall_t,ratio,hfar,thickness; 
  double current_distance;
  SPoint3 _closest_point;
  AttractorField *current_closest;
  virtual bool isotropic () const {return false;}
  virtual const char *getName();
  virtual std::string getDescription();
  BoundaryLayerField();
  virtual double operator() (double x, double y, double z, GEntity *ge=0);
  virtual void operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge=0);
};
#endif

#endif
