#ifndef _GMODELIO_F_H_
#define _GMODELIO_F_H_

#include "GModel.h"
#include "FM_Reader.h"

#if defined(HAVE_FOURIER_MODEL)

class F_Internals {
 protected:
  FM_Reader* _reader;
 public:
  F_Internals() : _reader(0) {}
  void loadF(const char *);
  void buildGModel(GModel *gm);
};

#endif
#endif
