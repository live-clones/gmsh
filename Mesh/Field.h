// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FIELD_H_
#define _FIELD_H_

#include <string>
#include <map>
#include <list>

#if !defined(HAVE_NO_POST)
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
  virtual FieldOptionType get_type() = 0;
  virtual void get_text_representation(std::string & v_str) = 0;
  virtual std::string get_description(){ return _help; }
  std::string get_type_name(){
    switch(get_type()){
    case FIELD_OPTION_INT: return "integer"; break;
    case FIELD_OPTION_DOUBLE: return "float"; break;
    case FIELD_OPTION_BOOL: return "boolean"; break;
    case FIELD_OPTION_PATH: return "path"; break;
    case FIELD_OPTION_STRING: return "string"; break;
    case FIELD_OPTION_LIST: return "list"; break;
    default: return "unknown";
    }
  }
  virtual void numerical_value(double val) { throw(1); }
  virtual double numerical_value() const { throw(1); }
  virtual const std::list<int> &list() const { throw(1); }
  virtual std::list<int> &list() { throw(1); }
  virtual const std::string &string() const { throw(1); }
  virtual std::string &string() { throw(1); }
};

class Field {
 public:
  int id;
  std::map<std::string, FieldOption *> options;
  virtual double operator() (double x, double y, double z, GEntity *ge=0) = 0;
  virtual ~Field() {}
  bool update_needed;
  Field();
  virtual const char *get_name() = 0;
#if !defined(HAVE_NO_POST)
  void put_on_view(PView * view, int comp = -1);
  void put_on_new_view();
#endif
  virtual std::string get_description(){ return ""; }
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
  Field *new_field(int id, std::string type_name);
  void delete_field(int id);
  int new_id();
  int max_id();
  FieldManager();
  int background_field;
  // compatibility with -bgm
  void set_background_mesh(int iView);
};

#endif
