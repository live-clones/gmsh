#ifndef _H_GMSH_MODEL_
#define _H_GMSH_MODEL_

#include "GModel.h"

class gmshModel : public GModel {
  void convertFromUglyOldDataStructuresgmshModel(); 
public:
  gmshModel(char *geofile); 
  gmshModel(); 
  virtual ~gmshModel() {};
};

#endif
