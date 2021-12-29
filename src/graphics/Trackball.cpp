/*
 * (c) Copyright 1993, 1994, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(TM) is a trademark of Silicon Graphics, Inc.
 */
/*
 * Trackball code:
 *
 * Implementation of a virtual trackball.
 * Implemented by Gavin Bell, lots of ideas from Thant Tessman and
 *   the August '88 issue of Siggraph's "Computer Graphics," pp. 121-129.
 *
 * Vector manip code:
 *
 * Original code from:
 * David M. Ciemiewicz, Mark Grossman, Henry Moreton, and Paul Haeberli
 *
 * Much mucking with by:
 * Gavin Bell
 */
/*
 * Modified for inclusion in Gmsh (rotmatrix as a vector +
 * float->double + optional use of hyperbolic sheet for z-rotation)
 */
#include <cmath>
#include "Trackball.h"
#include "Context.h"
#include <iostream>
/*
 * This size should really be based on the distance from the center of
 * rotation to the point on the object underneath the mouse.  That
 * point would then track the mouse as closely as possible.  This is a
 * simple example, though, so that is left as an Exercise for the
 * Programmer.
 */
#define TRACKBALLSIZE  (.8)

/*
 * Local function prototypes (not defined in trackball.h)
 */
static double tb_project_to_sphere(double, double, double);
static void normalize_quat(double [4]);
using namespace std ;

void
vzero(double *v)
{
    v[0] = 0.0;
    v[1] = 0.0;
    v[2] = 0.0;
}

void
vset(double *v, double x, double y, double z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

void
vsub(const double *src1, const double *src2, double *dst)
{
    dst[0] = src1[0] - src2[0];
    dst[1] = src1[1] - src2[1];
    dst[2] = src1[2] - src2[2];
}

void
vcopy(const double *v1, double *v2)
{
    int i;
    for (i = 0 ; i < 3 ; i++)
        v2[i] = v1[i];
}

void
vcross(const double *v1, const double *v2, double *cross)
{
    double temp[3];

    temp[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
    temp[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
    temp[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
    vcopy(temp, cross);
}

double
vlength(const double *v)
{
    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

void
vscale(double *v, double div)
{
    v[0] *= div;
    v[1] *= div;
    v[2] *= div;
}

void
vnormal(double *v)
{
    vscale(v,1.0/vlength(v));
}

double
vdot(const double *v1, const double *v2)
{
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}

void
vadd(const double *src1, const double *src2, double *dst)
{
    dst[0] = src1[0] + src2[0];
    dst[1] = src1[1] + src2[1];
    dst[2] = src1[2] + src2[2];
}

/*
 * Ok, simulate a track-ball.  Project the points onto the virtual
 * trackball, then figure out the axis of rotation, which is the cross
 * product of P1 P2 and O P1 (O is the center of the ball, 0,0,0)
 * Note:  This is a deformed trackball-- is a trackball in the center,
 * but is deformed into a hyperbolic sheet of rotation away from the
 * center.  This particular function was chosen after trying out
 * several variations.
 *
 * It is assumed that the arguments to this routine are in the range
 * (-1.0 ... 1.0)
 */
void
trackball(double q[4], double p1x, double p1y, double p2x, double p2y)
{
  double a[3]; /* Axis of rotation */
  double phi;  /* how much to rotate about axis */
  double p1[3], p2[3], d[3];
  double t;

  if (p1x == p2x && p1y == p2y) {
    /* Zero rotation */
    vzero(q);
    q[3] = 1.0;
    return;
  }

  /*
   * First, figure out z-coordinates for projection of P1 and P2 to
   * deformed sphere
   */
  vset(p1,p1x,p1y,tb_project_to_sphere(TRACKBALLSIZE,p1x,p1y));
  vset(p2,p2x,p2y,tb_project_to_sphere(TRACKBALLSIZE,p2x,p2y));
  /*
   *  Now, we want the cross product of P1 and P2
   */
  vcross(p2,p1,a);

  /*
   *  Figure out how much to rotate around that axis.
   */
  vsub(p1,p2,d);
  if (CTX::instance()->trackballHyperbolicSheet)
    t = vlength(d) / (2.0*TRACKBALLSIZE);
  else
    t = vlength(d);

  /*
   * Avoid problems with out-of-control values...
   */
  if (t > 1.0) t = 1.0;
  if (t < -1.0) t = -1.0;
  phi = 2.0 * asin(t);

  axis_to_quat(a,phi,q);
}

/*
 *  Given an axis and angle, compute quaternion.
 */
void axis_to_quat(double a[3], double phi, double q[4])
{
    vnormal(a);
    vcopy(a,q);
    vscale(q,sin(phi/2.0));
    q[3] = cos(phi/2.0);
}

/*
 * Project an x,y pair onto a sphere of radius r OR a hyperbolic sheet
 * if we are away from the center of the sphere.
 */
static double
tb_project_to_sphere(double r, double x, double y)
{
  double d, t, z;

  d = sqrt(x*x + y*y);

  if (CTX::instance()->trackballHyperbolicSheet) {
    if (d < r * 0.70710678118654752440) {
      // Inside sphere
      z = sqrt(r*r - d*d);
    }
    else {
      // On hyperbola
      t = r / 1.41421356237309504880;
      z = t*t / d;
    }
  }
  else{
    if (d < r ) {
      z = sqrt(r*r - d*d);
    } else {
      z = 0.;
    }
  }

  return z;
}

/*
 * Given two rotations, e1 and e2, expressed as quaternion rotations,
 * figure out the equivalent single rotation and stuff it into dest.
 *
 * This routine also normalizes the result every RENORMCOUNT times it is
 * called, to keep error from creeping in.
 *
 * NOTE: This routine is written so that q1 or q2 may be the same
 * as dest (or each other).
 */

#define RENORMCOUNT 97

void
add_quats(double q1[4], double q2[4], double dest[4])
{
    static int count=0;
    double t1[4], t2[4], t3[4];
    double tf[4];

    vcopy(q1,t1);
    vscale(t1,q2[3]);

    vcopy(q2,t2);
    vscale(t2,q1[3]);

    vcross(q2,q1,t3);
    vadd(t1,t2,tf);
    vadd(t3,tf,tf);
    tf[3] = q1[3] * q2[3] - vdot(q1,q2);

    dest[0] = tf[0];
    dest[1] = tf[1];
    dest[2] = tf[2];
    dest[3] = tf[3];

    if (++count > RENORMCOUNT) {
        count = 0;
        normalize_quat(dest);
    }
}

/*
 * Quaternions always obey:  a^2 + b^2 + c^2 + d^2 = 1.0
 * If they don't add up to 1.0, dividing by their magnitued will
 * renormalize them.
 *
 * Note: See the following for more information on quaternions:
 *
 * - Shoemake, K., Animating rotation with quaternion curves, Computer
 *   Graphics 19, No 3 (Proc. SIGGRAPH'85), 245-254, 1985.
 * - Pletinckx, D., Quaternion calculus as a basic tool in computer
 *   graphics, The Visual Computer 5, 2-13, 1989.
 */
static void
normalize_quat(double q[4])
{
    int i;
    double mag;

    mag = (q[0]*q[0] + q[1]*q[1] + q[2]*q[2] + q[3]*q[3]);
    for (i = 0; i < 4; i++) q[i] /= mag;
}

/*
 * Build a rotation matrix, given a quaternion rotation.
 *
 */
void
build_rotmatrix(double m[16], double q[4])
{
    m[0] = 1.0 - 2.0 * (q[1] * q[1] + q[2] * q[2]);
    m[1] = 2.0 * (q[0] * q[1] - q[2] * q[3]);
    m[2] = 2.0 * (q[2] * q[0] + q[1] * q[3]);
    m[3] = 0.0;

    m[4] = 2.0 * (q[0] * q[1] + q[2] * q[3]);
    m[5]= 1.0 - 2.0 * (q[2] * q[2] + q[0] * q[0]);
    m[6] = 2.0 * (q[1] * q[2] - q[0] * q[3]);
    m[7] = 0.0;

    m[8] = 2.0 * (q[2] * q[0] - q[1] * q[3]);
    m[9] = 2.0 * (q[1] * q[2] + q[0] * q[3]);
    m[10] = 1.0 - 2.0 * (q[1] * q[1] + q[0] * q[0]);
    m[11] = 0.0;

    m[12] = 0.0;
    m[13] = 0.0;
    m[14] = 0.0;
    m[15] = 1.0;
}
