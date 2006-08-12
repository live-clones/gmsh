#ifndef _GMSH_MODEL_H_
#define _GMSH_MODEL_H_

#include "GModel.h"

class gmshModel : public GModel {
 public:
  gmshModel(); 
  virtual ~gmshModel() {};

  // import data from the old Gmsh database ("THEM")
  virtual void import();
};

#endif
