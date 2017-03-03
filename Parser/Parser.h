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
  Struct(int tag,
         std::map<std::string, std::vector<double> > & fopt,
         std::map<std::string, std::vector<std::string> > & copt) :
    _tag(tag), _fopt(fopt), _copt(copt) {}
  ~Struct() {}

  int append(int tag,
             std::map<std::string, std::vector<double> > & fopt,
             std::map<std::string, std::vector<std::string> > & copt) {
    this->_fopt.insert(fopt.begin(), fopt.end());
    this->_copt.insert(copt.begin(), copt.end());
    if (tag >= 0) _tag = tag;
    return _tag;
  }

  inline int getTag() { return _tag; }

  int getMember(std::string & key_member, double &out) {
    std::map<std::string, std::vector<double> >::iterator it = _fopt.find(key_member);
    if (it != _fopt.end()) {
      out = it->second[0]; return 0;
    }
    else {
      out = 0.; return 1; // Error: Unknown member of Struct
    }
  }

  int getMember(std::string & key_member, std::string & out) {
    std::map<std::string, std::vector<std::string> >::iterator
      it = _copt.find(key_member);
    if (it != _copt.end()) {
      out = it->second[0]; return 0;
    }
    else {
      out = std::string(""); return 1; // Error: Unknown member of Struct
    }
  }

  void print(const std::string & struct_name, const std::string & struct_namespace)
  {
    //...
  }

private:
  int _tag;
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
  Structs() { _max_tag = 0; }
  ~Structs() {}

  int defStruct(std::string & struct_name,
                std::map<std::string, std::vector<double> > & fopt,
                std::map<std::string, std::vector<std::string> > & copt,
                bool append = false) {
    int tag;
    std::map<std::string, std::vector<double> >::iterator it = fopt.find("Tag");
    if (it != fopt.end()) {
      tag = it->second[0]; // Tag forced
      _max_tag = std::max(_max_tag, tag);
    }
    else
      tag = (!append)? ++_max_tag : -1; // Tag auto
    if (!append)
      (*this)[struct_name] = Struct(tag, fopt, copt);
    else
      (*this)[struct_name].append(tag, fopt, copt);
    return tag;
  }

  int get_key_struct_from_tag(int tag, const std::string * & key_struct) {
    Map_string_Struct::iterator it_st;
    for (it_st = this->get().begin(); it_st != this->get().end(); ++it_st )
      if (it_st->second.getTag() == tag) break;
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

private:
  int _max_tag;
};


typedef std::map<std::string, Structs> Map_string_Structs;

class NameSpaces : public Map<std::string, Structs> {
public:
  NameSpaces() {}
  ~NameSpaces() {}

  int defStruct(std::string & key_namespace, std::string & key_name,
                std::map<std::string, std::vector<double> > & fopt,
                std::map<std::string, std::vector<std::string> > & copt,
                int & tag_out, bool append = false) {
    Structs * structs_P = &(*this)[key_namespace];
    if (!append && structs_P->count(key_name)) {
      tag_out = (*structs_P)[key_name].getTag();
      return 1; // Error: Redefinition of Struct
    }
    tag_out = structs_P->defStruct(key_name, fopt, copt, append);
    return 0;
  }

  int getTag(std::string & key_namespace, std::string & key_name,
             double & out) {

    Structs * structs_P = this->Find(key_namespace);
    Struct * struct_P = (structs_P)? structs_P->Find(key_name) : NULL;
    if (structs_P && struct_P) {
      out = (double)struct_P->getTag();
    }
    else  {
      out = 0.; return 1; // Error: Unknown Struct
    }
    return 0;
  }

  int getMember(std::string & key_namespace, std::string & key_name,
                std::string & key_member, double & out) {

    Structs * structs_P = this->Find(key_namespace);
    Struct * struct_P = (structs_P)? structs_P->Find(key_name) : NULL;
    if (structs_P && struct_P) {
      if (struct_P->getMember(key_member, out)) {
        out = 0.; return 2; // Error: Unknown member of Struct
      }
    }
    else  {
      out = 0.; return 1; // Error: Unknown Struct
    }
    return 0;
  }

  int getMember(std::string & key_namespace, std::string & key_name,
                std::string & key_member, std::string & out) {

    Structs * structs_P = this->Find(key_namespace);
    Struct * struct_P = (structs_P)? structs_P->Find(key_name) : NULL;
    if (structs_P && struct_P) {
      if (struct_P->getMember(key_member, out)) {
        out = std::string(""); return 2; // Error: Unknown member of Struct
      }
    }
    else  {
      out = std::string(""); return 1; // Error: Unknown Struct
    }
    return 0;
  }

  int get_key_struct_from_tag(std::string & key_namespace,
                              int tag, const std::string * & key_struct) {
    if (this->count(key_namespace))
      return (*this)[key_namespace].get_key_struct_from_tag(tag, key_struct);
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
