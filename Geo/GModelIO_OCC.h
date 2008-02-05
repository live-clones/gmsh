#ifndef _GMODELIO_OCC_H_
#define _GMODELIO_OCC_H_

// $Id: GModelIO_OCC.h,v 1.3 2008-02-05 14:40:29 remacle Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "OCCIncludes.h"

#if defined(HAVE_OCC)

class OCC_Internals {
 protected :
  TopoDS_Shape shape;
  TopTools_IndexedMapOfShape fmap, emap, vmap, somap, shmap, wmap;
 public:
  
  enum BooleanOperator { Add , Cut }; 

  OCC_Internals()
  {
    somap.Clear();
    shmap.Clear();
    fmap.Clear();
    wmap.Clear();
    emap.Clear();
    vmap.Clear();
  }
  void HealGeometry(double tolerance, bool fixsmalledges, 
		    bool fixspotstripfaces, bool sewfaces, 
		    bool makesolids=false);
  void loadSTEP(const char *);
  void loadIGES(const char *);
  void loadBREP(const char *);  
  void buildGModel(GModel *gm);
  void buildLists();
  void removeAllDuplicates (const double &tolerance);

  void Sphere  ( const SPoint3 & center, const double & radius, const BooleanOperator & op );
  void Cylinder( const SPoint3 & bottom_center, const SVector3 & dir, const BooleanOperator & op );
  void applyBooleanOperator ( TopoDS_Shape tool, const BooleanOperator & op);
};

#endif
#endif
