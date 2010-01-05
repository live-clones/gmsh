#ifndef _DUMMY_BINDINGS_H_
#define _DUMMY_BINDINGS_H_
class classBinding {
public:
  void setDescription(std::string description){};
  template<typename parentType>
  void setParentClass(){}
  template <typename cb>
  methodBinding *addMethod(std::string n, cb f){
    return new methodBinding();
  }
  template <typename tObj, typename t0, typename t1, typename t2, typename t3 >
  methodBinding *setConstructor(){}
  template <typename tObj, typename t0, typename t1, typename t2 >
  methodBinding *setConstructor(){}
  template <typename tObj, typename t0, typename t1>
  methodBinding *setConstructor(){return 0;}
  template <typename tObj, typename t0>
  methodBinding *setConstructor(){return 0;}
  template<typename tObj>
  methodBinding *setConstructor(){return 0;}
};

class binding {
  public:
  template<class t>
  classBinding *addClass(std::string className){
    return new classBinding();
  }
};
#endif
