// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributor(s):
//   Koen Hillewaert

#include "GEntity.h"
#include "MVertex.h"

// -----------------------------------------------------------------------------

bool correctPeriodicity(MVertex* tgt,
                        MVertex* src,
                        const std::vector<double>& tfo) {
  
  double ps[4] = {src->x(),src->y(),src->z(),1};
  double pt[4] = {tgt->x(),tgt->y(),tgt->z(),1};
  int idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      ps[j] +=  tfo[idx++] * pt[i];
  
  for (int i=0;i<4;i++) ps[i] *= 0.5;
  for (int i=0;i<4;i++) pt[i] = 0;

  src->x() = ps[0];
  src->y() = ps[1];
  src->z() = ps[2];
  
  idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      pt[i] +=  tfo[idx++] * ps[j];
  
  tgt->x() = pt[0];
  tgt->y() = pt[1];
  tgt->z() = pt[2];

  return true;
}

// -----------------------------------------------------------------------------

bool correctVertexPeriodicity(GEntity* tgt) {
  
  if (tgt->meshMaster() == NULL) return false;
  bool check = true;
  std::map<MVertex*,MVertex*>::iterator vIter = tgt->correspondingVertices.begin();
  for (;vIter!=tgt->correspondingVertices.end();++vIter) {
    check = check && correctPeriodicity(vIter->first,
                                        vIter->second,
                                        tgt->affineTransform);
    
  }
  return check;
}

// -----------------------------------------------------------------------------
