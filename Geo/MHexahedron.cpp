// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MHexahedron.h"
#include "Numeric.h"

int MHexahedron::getVolumeSign()
{ 
  double mat[3][3];
  mat[0][0] = _v[1]->x() - _v[0]->x();
  mat[0][1] = _v[3]->x() - _v[0]->x();
  mat[0][2] = _v[4]->x() - _v[0]->x();
  mat[1][0] = _v[1]->y() - _v[0]->y();
  mat[1][1] = _v[3]->y() - _v[0]->y();
  mat[1][2] = _v[4]->y() - _v[0]->y();
  mat[2][0] = _v[1]->z() - _v[0]->z();
  mat[2][1] = _v[3]->z() - _v[0]->z();
  mat[2][2] = _v[4]->z() - _v[0]->z();
  double d = det3x3(mat);
  if(d < 0.) return -1;
  else if(d > 0.) return 1;
  else return 0;
}

void MHexahedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQHPts(pOrder);
  *pts = getGQHPts(pOrder);
}

void MHexahedron::getFaceInfo(const MFace &face, int &ithFace, int &sign, int &rot) const
{
  for (ithFace = 0; ithFace < 6; ithFace++){
    MVertex *v0 = _v[faces_hexa(ithFace, 0)];
    MVertex *v1 = _v[faces_hexa(ithFace, 1)];
    MVertex *v2 = _v[faces_hexa(ithFace, 2)];
    MVertex *v3 = _v[faces_hexa(ithFace, 3)];

    if (v0 == face.getVertex(0) && v1 == face.getVertex(1) && 
        v2 == face.getVertex(2) && v3 == face.getVertex(3)){
      sign = 1; rot = 0; return;
    }
    if (v0 == face.getVertex(1) && v1 == face.getVertex(2) &&
        v3 == face.getVertex(3) && v2 == face.getVertex(0)){
      sign = 1; rot = 1; return;
    }
    if (v0 == face.getVertex(2) && v3 == face.getVertex(3) &&
        v1 == face.getVertex(0) && v2 == face.getVertex(1)){
      sign = 1; rot = 2; return;
    }
    if (v0 == face.getVertex(3) && v3 == face.getVertex(0) &&
        v1 == face.getVertex(1) && v2 == face.getVertex(2)){
      sign = 1; rot = 3; return;
    }
    if (v0 == face.getVertex(0) && v1 == face.getVertex(3) &&
        v2 == face.getVertex(2) && v3 == face.getVertex(1)){
      sign = -1; rot = 0; return;
    }
    if (v0 == face.getVertex(3) && v1 == face.getVertex(2) &&
        v2 == face.getVertex(1) && v3 == face.getVertex(0)){
      sign = -1; rot = 1; return;
    }
    if (v0 == face.getVertex(2) && v1 == face.getVertex(1) &&
        v2 == face.getVertex(0) && v3 == face.getVertex(3)){
      sign = -1; rot = 2; return;
    }
    if (v0 == face.getVertex(1) && v1 == face.getVertex(0) &&
        v2 == face.getVertex(3) && v3 == face.getVertex(2)){
      sign = -1; rot = 3; return;
    }
  }
  Msg::Error("Could not get face information for hexahedron %d", getNum());
}
