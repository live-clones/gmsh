#ifndef _LOCALFUNCTIONSPACE_H_
#define _LOCALFUNCTIONSPACE_H_

class LocalFunctionSpace{
 protected:
  bool scalar;
  int  size;

 public:
  virtual ~LocalFunctionSpace(void);

  bool isScalar(void) const;
  int  getSize(void) const;

 protected:
  LocalFunctionSpace(void);
};

//////////////////////
// Inline Functions //
//////////////////////

inline bool LocalFunctionSpace::isScalar(void) const{
  return scalar;
}

inline int LocalFunctionSpace::getSize(void) const{
  return size;
}

#endif
