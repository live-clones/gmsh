// $Id: Context.cpp,v 1.50 2004-02-07 01:40:17 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "Options.h"
#include "DefaultOptions.h"
#include "Trackball.h"

/*
  3 successive rotations along x, y and z:

           c(y)c(z)    s(x)s(y)c(z)+c(x)s(z)   -c(x)s(y)c(z)+s(x)s(z) 
  t[][] = -c(y)s(z)   -s(x)s(y)s(z)+c(x)c(z)    c(x)s(y)s(z)+s(x)c(z)
           s(y)       -s(x)c(y)                 c(x)c(y)

  get the position angles:

  y = asin(t31)
      Pi - asin(t31)
 
  si y != +- Pi/2 :

  x = atan(-t32/t33)    si t33 cos y > 0
      atan(-t32/t33)+Pi si t33 cos y < 0

  z = atan(-t21/t11)    si t11 cos y > 0
      atan(-t21/t11)+Pi si t11 cos y < 0

*/

void Context_T::buildRotmatrix(void)
{
  double x, y, z;

  if(useTrackball) {
    build_rotmatrix(rot, quaternion);

#if defined(HAVE_FLTK)
    // We should reconstruct the Euler angles from the rotation
    // matrix. I'm too lazy to do it :-(
    extern void set_r(int i, double val);
    set_r(0, 0.);
    set_r(1, 0.);
    set_r(2, 0.);
    /*
       double x=0., y=0., z=0.

       y = asin(rot[2][0]) ; y = Pi - asin(rot[2][0]) ; // choix ???

       if(fabs(y) != Pi/2.){
       if(rot[2][2]*cos(y) > 0.) x = atan2(-rot[2][1],rot[2][2]);
       else                      x = atan2(-rot[2][1],rot[2][2]) + Pi;
       if(rot[0][0]*cos(y) > 0.) z = atan2(-rot[1][0],rot[0][0]);
       else                      z = atan2(-rot[1][0],rot[0][0]) + Pi;
       }
       set_r(0, x * 180./Pi);
       set_r(1, y * 180./Pi);
       set_r(2, z * 180./Pi);
     */
    /*
       double r0, r1, r2;

       r1 = atan2(-rot[0][2],sqrt(rot[1][2]*rot[1][2] + rot[2][2]*rot[2][2]));

       double c = cos(r1);  
       if(c != 0.0){
       r0 = atan2(rot[1][2]/c,rot[2][2]/c) ;
       r2 = atan2(-rot[1][0]/c,rot[0][0]/c) ;
       r0 *= 180./(Pi);
       r2 *= 180./(Pi);
       }
       set_r(0, r0);
       set_r(1, r1 * 180./(Pi));  // lazyyyyyy
       set_r(2, r2);
     */
#endif

  }
  else {
    x = r[0] * Pi / 180.;
    y = r[1] * Pi / 180.;
    z = r[2] * Pi / 180.;

    rot[0][0] = cos(y) * cos(z);
    rot[0][1] = sin(x) * sin(y) * cos(z) + cos(x) * sin(z);
    rot[0][2] = -cos(x) * sin(y) * cos(z) + sin(x) * sin(z);
    rot[0][3] = 0.0;

    rot[1][0] = -cos(y) * sin(z);
    rot[1][1] = -sin(x) * sin(y) * sin(z) + cos(x) * cos(z);
    rot[1][2] = cos(x) * sin(y) * sin(z) + sin(x) * cos(z);
    rot[1][3] = 0.0;

    rot[2][0] = sin(y);
    rot[2][1] = -sin(x) * cos(y);
    rot[2][2] = cos(x) * cos(y);
    rot[2][3] = 0.0;

    rot[3][0] = 0.0;
    rot[3][1] = 0.0;
    rot[3][2] = 0.0;
    rot[3][3] = 1.0;
  }

}

void Context_T::addQuaternion(float p1x, float p1y, float p2x, float p2y)
{
  float quat[4];
  trackball(quat, p1x, p1y, p2x, p2y);
  add_quats(quat, quaternion, quaternion);
}

void Context_T::setQuaternion(float q0, float q1, float q2, float q3)
{
  quaternion[0] = q0;
  quaternion[1] = q1;
  quaternion[2] = q2;
  quaternion[3] = q3;
}
