// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _PARSER_H_
#define _PARSER_H_

#include <map>
#include <string>
#include <vector>
#include "GmshIO.h"

int gmsh_yyparse();
int gmsh_yylex();
void gmsh_yyflush();

class gmsh_yysymbol{
 public:
  bool list;
  std::vector<double> value;
  gmsh_yysymbol() : list(false) {}
};

class Shape{
 public:
  int Type;
  int Num;
};

struct TwoChar { char *char1, *char2; };

// classes for Struct
class Struct {
public:
  Struct() {}
  Struct(int index,
         std::map<std::string, std::vector<double> > fopt,
         std::map<std::string, std::vector<std::string> > copt) :
    _index(index), _fopt(fopt), _copt(copt) {}
  ~Struct() {}

  void append(std::map<std::string, std::vector<double> > fopt,
              std::map<std::string, std::vector<std::string> > copt) {
    this->_fopt.insert(fopt.begin(), fopt.end());
    this->_copt.insert(copt.begin(), copt.end());
  }

  void print(const std::string & struct_name, const std::string & struct_namespace)
  {
    //...
  }

public:
  int _index;
  std::map<std::string, std::vector<double> > _fopt;
  std::map<std::string, std::vector<std::string> > _copt;
};


template <class K, class T>
class Map {
public:
  Map() {}
  ~Map() {}

  T * Find(K key) {
    typename std::map<K, T>::iterator it;
    if ( (it = _map.find(key)) != _map.end() ) return &it->second;
    else return NULL;
  }

  inline T & operator[] (K key) { return _map[key]; }
  inline std::map<K, T> & get() { return _map; }
  inline int count (std::string key) { return _map.count(key); }
  inline int size () { return _map.size(); }

public:
  std::map<K, T> _map;
};


typedef std::map<std::string, Struct> Map_string_Struct;

class Structs : public Map<std::string, Struct> {
public:
  Structs() { _new_index = 1; }
  ~Structs() {}

  int get_key_struct_from_index(int index, const std::string * & key_struct) {
    Map_string_Struct::iterator it_st;
    for (it_st = this->get().begin(); it_st != this->get().end(); ++it_st )
      if (it_st->second._index == index) break;
    if (it_st != this->get().end()) {
      key_struct = &it_st->first;
      return 0;
    }
    else return 2;
  }

  void print(const std::string & struct_namespace) {
    for (Map_string_Struct::iterator it_st = this->get().begin();
         it_st != this->get().end(); ++it_st )
      it_st->second.print(it_st->first, struct_namespace);
  }

public:
  int _new_index;
};


typedef std::map<std::string, Structs> Map_string_Structs;

class NameSpaces : public Map<std::string, Structs> {
public:
  NameSpaces() {}
  ~NameSpaces() {}

  int get_key_struct_from_index(int index, const std::string * & key_struct,
                                std::string & key_namespace) {
    if (this->count(key_namespace))
      return (*this)[key_namespace].get_key_struct_from_index(index, key_struct);
    else return 1;
  }

  void print() {
    for (Map_string_Structs::iterator it_ns = this->get().begin();
         it_ns != this->get().end(); ++it_ns )
      it_ns->second.print(it_ns->first);
  }
};


// global parser variables that need to be exported
extern gmshFILE gmsh_yyin;
extern int gmsh_yylineno;
extern char *gmsh_yytext;
extern int gmsh_yyviewindex;
extern std::string gmsh_yyname;
extern int gmsh_yyerrorstate;
extern std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;
extern std::map<std::string, std::vector<std::string> > gmsh_yystringsymbols;

void PrintParserSymbols(bool help, std::vector<std::string> &vec);

int NEWPOINT();
int NEWLINE();
int NEWLINELOOP();
int NEWSURFACE();
int NEWSURFACELOOP();
int NEWVOLUME();
int NEWREG();
int NEWFIELD();
int NEWPHYSICAL();

#endif
