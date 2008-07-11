// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FIELD_H_
#define _FIELD_H_

#include <map>
#include <list>
#include <string.h>
#include "Geo.h"

#if !defined(HAVE_NO_POST)
#include "PView.h"
#endif

class Field;

typedef enum { 
  FIELD_OPTION_DOUBLE = 0,
  FIELD_OPTION_INT,
  FIELD_OPTION_STRING, 
  FIELD_OPTION_PATH,
  FIELD_OPTION_BOOL, 
  FIELD_OPTION_LIST 
} FieldOptionType;

class FieldOption {
 protected:
  bool *status;
  inline void modified()
  {
    if(status)  *status = true;
  }
 public:
  FieldOption(bool *_status) : status(_status) {}
  virtual ~FieldOption() {}
  virtual FieldOptionType get_type() = 0;
  virtual void get_text_representation(std::string & v_str) = 0;
  virtual void numerical_value(double val) { throw(1); }
  virtual double numerical_value() const { throw(1); }
  virtual const std::list<int> &list() const { throw(1); }
  virtual std::list<int> &list() { throw(1); }
  virtual const std::string &string() const { throw(1); }
  virtual std::string &string() { throw(1); }
};

class FieldDialogBox;

class Field {
 public:
  int id;
  std::map<std::string, FieldOption *> options;
  virtual double operator() (double x, double y, double z) = 0;
  virtual ~Field() {}
  bool update_needed;
  Field();
  virtual const char *get_name() = 0;
  virtual FieldDialogBox *&dialog_box() = 0;
#if !defined(HAVE_NO_POST)
  void put_on_view(PView * view, int comp = -1);
#endif
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
