// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Paul-Emile Bernard

#ifndef _GENERIC_REGION_H_
#define _GENERIC_REGION_H_

#include "GmshConfig.h"
#include "GRegion.h"

/* The set of Generic Entities is a generic interface to any other modeler.
   Callbacks (function pointers) are given, sending requests, enquiries, to the
   native modeler. */

class GenericRegion : public GRegion {
public:
  GenericRegion(GModel *m, int num, int _native_id);
  virtual ~GenericRegion();

  virtual GeomType geomType() const;

  ModelType getNativeType() const { return GenericModel; }
  virtual int getNativeInt()const{return id;};

  // TODO: When using GRegion->l_dirs and l_faces, what is the convention for
  // l_dirs ? For now, assuming positive value for normals pointing inside the
  // region.
  void addFace(GenericFace *ptr, int sign){
    l_dirs.push_back(sign);
    l_faces.push_back(ptr);
    ptr->addRegion(this);
  };

private:
  int id;
};

#endif
