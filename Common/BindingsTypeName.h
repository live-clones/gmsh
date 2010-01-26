#ifndef BINDINGS_TYPE_NAME_H
#define BINDINGS_TYPE_NAME_H
#include <vector>
#include <string>
/*** store a unique static class name for each binded class ***/
template <typename type>
class className{
  static std::string _name;
  public:
  static void set(std::string name){
    if(_name!=""){
      throw;
    }
    _name=name;
  }
  static const std::string &get(){
    if(_name==""){
      throw;
    }
    return _name;
  }
};
template<typename type>
std::string  className<type>::_name;

template <>
class className<std::string>{
  public:
  static const std::string get(){
    return "string";
  }
};
template <>
class className<int>{
  public:
  static const std::string get(){
    return "int";
  }
};
template <>
class className<double>{
  public:
  static const std::string get(){
    return "double";
  }
};
template <>
class className<void>{
  public:
  static const std::string get(){
    return "void";
  }
};
template <typename t>
class className<t*>{
  public:
  static const std::string get(){
    return className<t>::get();
  }
};
template <typename t>
class className<const t &>{
  public:
  static const std::string get(){
    return className<t>::get();
  }
};

template <typename cb>
class argTypeNames;
template <typename tr, typename tObj, typename t0, typename t1, typename t2, typename t3>
class argTypeNames<tr (tObj::*)(t0,t1,t2,t3)>{
  public:
  static void get(std::vector<std::string> &names){
    names.clear();
    names.push_back(className<tr>::get());
    names.push_back(className<t0>::get());
    names.push_back(className<t1>::get());
    names.push_back(className<t2>::get());
    names.push_back(className<t3>::get());
  }
};
template <typename tr, typename tObj, typename t0, typename t1, typename t2>
class argTypeNames<tr (tObj::*)(t0,t1,t2)>{
  public:
  static void get(std::vector<std::string> &names){
    names.clear();
    names.push_back(className<tr>::get());
    names.push_back(className<t0>::get());
    names.push_back(className<t1>::get());
    names.push_back(className<t2>::get());
  }
};
template <typename tr, typename tObj, typename t0, typename t1>
class argTypeNames<tr (tObj::*)(t0,t1)>{
  public:
  static void get(std::vector<std::string> &names){
    names.clear();
    names.push_back(className<tr>::get());
    names.push_back(className<t0>::get());
    names.push_back(className<t1>::get());
  }
};
template <typename tr, typename tObj, typename t0>
class argTypeNames<tr (tObj::*)(t0)>{
  public:
  static void get(std::vector<std::string> &names){
    names.clear();
    names.push_back(className<tr>::get());
    names.push_back(className<t0>::get());
  }
};
template <typename tr, typename tObj>
class argTypeNames<tr (tObj::*)()>{
  public:
  static void get(std::vector<std::string> &names){
    names.clear();
    names.push_back(className<tr>::get());
  }
};
template <typename cb>
class argTypeNames;
template <typename tr, typename tObj, typename t0, typename t1, typename t2, typename t3>
class argTypeNames<tr (tObj::*)(t0,t1,t2,t3)const>{
  public:
  static void get(std::vector<std::string> &names){
    argTypeNames<tr (tObj::*)(t0,t1,t2,t3)>::get(names);
  }
};
template <typename tr, typename tObj, typename t0, typename t1, typename t2>
class argTypeNames<tr (tObj::*)(t0,t1,t2)const>{
  public:
  static void get(std::vector<std::string> &names){
    argTypeNames<tr (tObj::*)(t0,t1,t2)>::get(names);
  }
};
template <typename tr, typename tObj, typename t0, typename t1>
class argTypeNames<tr (tObj::*)(t0,t1)const>{
  public:
  static void get(std::vector<std::string> &names){
    argTypeNames<tr (tObj::*)(t0,t1)>::get(names);
  }
};
template <typename tr, typename tObj, typename t0>
class argTypeNames<tr (tObj::*)(t0)const>{
  public:
  static void get(std::vector<std::string> &names){
    argTypeNames<tr (tObj::*)(t0)>::get(names);
  }
};
template <typename tr, typename tObj>
class argTypeNames<tr (tObj::*)()const>{
  public:
  static void get(std::vector<std::string> &names){
    argTypeNames<tr (tObj::*)()>::get(names);
  }
};
#endif
