#ifndef _GMSH_MODEL_H_
#define _GMSH_MODEL_H_

#include "GModel.h"

class gmshModel : public GModel {
 private:
  void convertFromUglyOldDataStructuresgmshModel(); 
 public:
  gmshModel(char *geofile); 
  gmshModel(); 
  virtual ~gmshModel() {};
};

#endif
