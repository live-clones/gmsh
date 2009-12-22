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
  template <typename cb>
  methodBinding *setConstructor(cb f){
    return new methodBinding();
  }
};

class binding {
  public:
  template<class t>
  classBinding *addClass(std::string className){
    return new classBinding();
  }
};
#endif
