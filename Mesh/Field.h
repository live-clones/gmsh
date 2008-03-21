#ifndef _FIELD_H_
#define _FIELD_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include <list>
#include <string.h>
#include "Geo.h"
#include "PView.h"

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
  struct lstr {
    bool operator() (const char *s1, const char *s2) const
    {
      return strcmp(s1, s2) < 0;
    }
  };
 public:
  int id;
  std::map<const char *, FieldOption *, lstr> options;
  virtual double operator() (double x, double y, double z) = 0;
  virtual ~Field() {}
  bool update_needed;
  Field();
  virtual const char *get_name() = 0;
  virtual FieldDialogBox *&dialog_box() = 0;
  void put_on_view(PView * view, int comp = -1);
};

class FieldFactory {
 public:
  virtual Field * operator() () = 0;
};

class FieldManager : public std::map<int, Field*> {
 public:
  std::map<const std::string, FieldFactory*> map_type_name;
  void reset();
  Field *get(int id);
  Field *new_field(int id, const char *type_name);
  void delete_field(int id);
  int new_id();
  int max_id();
  FieldManager();
  int background_field;
  // compatibility with -bgm
  void set_background_mesh(int iView);
};

#endif
