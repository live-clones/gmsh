// -*-c++-*-
#ifndef IG_STAT_COORDSYS_H
#define IG_STAT_COORDSYS_H

// $Id: stat_coordsys.h,v 1.1.2.6 2005/05/30 09:14:25 hkuiper Exp $

// CwMtx matrix and vector math library
// Copyright (C) 1999-2001  Harry Kuiper
// Copyright (C) 2000  Will DeVore (template conversion)

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA

#ifndef IG_STAT_SMATRIX_H
#include "stat_smatrix.h"
#endif

#ifndef IG_STAT_QUATERNION_H
#include "stat_quatern.h"
#endif

#ifndef IG_STAT_SVECTOR_H
#include "stat_svector.h"
#endif

// CWTSSquareMatrix utilities for use in coordinate systems

namespace CwMtx
{

  // NOTE: These template functions only work with floating point
  // template arguments due to the use of sin(3), cos(3), tan(3), etc.

  // PLEASE, READ THIS!!!

  // Function smatFromEuler321(sclrAbout3, sclrAbout2, sclrAbout1)
  // returns a transformation matrix which transforms coordinates from
  // the reference axis system to coordinates in an axis system with
  // Euler angles: sclrAbout3, sclrAbout2, sclrAbout1 relative to that
  // reference axis system DO NOT CHANGE THIS DEFINITION!!!

  // rotation about axis 3 (yaw angle), axis 2 (pitch angle) axis 1
  // (roll angle)
  template <class T>
  CWTSSquareMatrix<3, T>
  smatFromEuler321Angles(T sclrAbout3,
			 T sclrAbout2,
			 T sclrAbout1)
  {
    CWTSSquareMatrix<3, T> smat;

    // to reduce the number of calls to CPU expensive sin(..) and
    // cos(..) functions
    T sin3 = sin(sclrAbout3);
    T sin2 = sin(sclrAbout2);
    T sin1 = sin(sclrAbout1);

    T cos3 = cos(sclrAbout3);
    T cos2 = cos(sclrAbout2);
    T cos1 = cos(sclrAbout1);

    // first row
    smat[0][0] =  cos3*cos2;
    smat[0][1] =  sin3*cos2;
    smat[0][2] = -sin2;

    // second row
    smat[1][0] = -sin3*cos1 + cos3*sin2*sin1;
    smat[1][1] =  cos3*cos1 + sin3*sin2*sin1;
    smat[1][2] =  cos2*sin1;

    // third row
    smat[2][0] =  sin3*sin1 + cos3*sin2*cos1;
    smat[2][1] = -cos3*sin1 + sin3*sin2*cos1;
    smat[2][2] =  cos2*cos1;

    return smat;
  }

  // Next three functions calculate Euler angles from a transformation matrix
  // WARNING!!! They suffer from the ubiquitos singularities at 0, pi, 2*pi,
  // etc.

  // yaw angle, rotation angle about Z-axis
  template <class T>
  T
  euler321Angle3FromSmat(const CWTSSquareMatrix<3, T> &smat)
  {
    return atan2(smat[0][1], smat[0][0]);
  }

  // pitch angle, rotation angle about Y-axis
  template <class T>
  T
  euler321Angle2FromSmat(const CWTSSquareMatrix<3, T> &smat)
  {
    return asin(-smat[0][2]);
  }

  // roll angle, rotation angle about X-axis
  template <class T>
  T
  euler321Angle1FromSmat(const CWTSSquareMatrix<3, T> &smat)
  {
    return atan2(smat[1][2], smat[2][2]);
  }

  // CWTSQuaternion utilities for use in coordinate systems

  // PLEASE, READ THIS!!!

  // next three functions calculate Euler angles from a quaternion
  // that represents a rigid body's attitude WARNING!!! They do suffer
  // from the ubiquitos singularities around 0, pi and 2*pi.

  // yaw angle, rotation angle about Z-axis
  template <class T>
  T
  euler321Angle3FromQtn(const CWTSQuaternion<T> &qtn)
  {
    // to reduce the number of calls to the subscript operator
    T qtn0 = qtn[0];
    T qtn1 = qtn[1];
    T qtn2 = qtn[2];
    T qtn3 = qtn[3];

    // NOTE: Speed tip from Jeffrey T Duncan: use the identity: 1 =
    // q0^2 + q1^2 + q2^2 + q3^2 which simplifies: q0^2 - q1^2 -
    // q2^2 + q3^2 down to: 2*(q0^2 + q3^2) - 1
    return atan2(2*(qtn0*qtn1 + qtn2*qtn3),
		 2*(qtn0*qtn0 + qtn3*qtn3) - 1);
  }

  // pitch angle, rotation angle about Y-axis
  template <class T>
  T
  euler321Angle2FromQtn(const CWTSQuaternion<T> &qtn)
  {
    return asin(-2*(qtn[0]*qtn[2] - qtn[1]*qtn[3]));
  }

  // roll angle, rotation angle about X-axis
  template <class T>
  T
  euler321Angle1FromQtn(const CWTSQuaternion<T> &qtn)
  {
    // to reduce the number of calls to the subscript operator
    T qtn0 = qtn[0];
    T qtn1 = qtn[1];
    T qtn2 = qtn[2];
    T qtn3 = qtn[3];

    return atan2(2*(qtn1*qtn2 + qtn0*qtn3),
		 2*(qtn2*qtn2 + qtn3*qtn3) - 1);
  }

  // Function QtnFromEulerAxisAndAngle returns a quaternion
  // representing a rigid body's attitude from its Euler axis and
  // angle. NOTE: Argument vector svecEulerAxis MUST be a unit vector.
  template <class T>
  CWTSQuaternion<T>
  qtnFromEulerAxisAndAngle(const CWTSSpaceVector<T> &svecEulerAxis,
			   const T &sclrEulerAngle)
  {
    return CWTSQuaternion<T>(1, svecEulerAxis, 0.5*sclrEulerAngle);
  }

  // returns Euler axis
  template <class T>
  CWTSSpaceVector<T>
  eulerAxisFromQtn(const CWTSQuaternion<T> &qtn)
  {
    T sclrTmp = sqrt(1 - qtn[3]*qtn[3]);

    return CWTSSpaceVector<T>(qtn[0]/sclrTmp,
			      qtn[1]/sclrTmp,
			      qtn[2]/sclrTmp);
  }

  // returns Euler angle
  template <class T>
  T
  eulerAngleFromQtn(const CWTSQuaternion<T> &qtn)
  {
    return 2*acos(qtn[3]);
  }

  // Function QtnFromEuler321 returns a quaternion representing a
  // rigid body's attitude. The quaternion elements correspond to the
  // Euler symmetric parameters of the body. The body's attitude must
  // be entered in Euler angle representation with rotation order
  // 3-2-1, i.e. first about Z-axis next about Y-axis and finally
  // about X-axis.

  // rotation about axis 3 (yaw angle), axis 2 (pitch angle) axis 1
  // (roll angle)
  template <class T>
  CWTSQuaternion<T>
  qtnFromEuler321Angles(T sclrAbout3,
			T sclrAbout2,
			T sclrAbout1)
  {
    return
      CWTSQuaternion<T>(1, CWTSSpaceVector<T>(0, 0, 1), 0.5*sclrAbout3)
      *CWTSQuaternion<T>(1, CWTSSpaceVector<T>(0, 1, 0), 0.5*sclrAbout2)
      *CWTSQuaternion<T>(1, CWTSSpaceVector<T>(1, 0, 0), 0.5*sclrAbout1);
  }

  // SmatFromQtn returns the transformation matrix corresponding to a
  // quaternion
  template <class T>
  CWTSSquareMatrix<3, T>
  smatFromQtn(const CWTSQuaternion<T> &qtn)
  {
    CWTSSquareMatrix<3, T> smat;

    // to reduce the number of calls to the subscript operator
    T qtn0 = qtn[0];
    T qtn1 = qtn[1];
    T qtn2 = qtn[2];
    T qtn3 = qtn[3];

    smat[0][0] = 1 - 2*(qtn1*qtn1 + qtn2*qtn2);
    smat[0][1] = 2*(qtn0*qtn1 + qtn2*qtn3);
    smat[0][2] = 2*(qtn0*qtn2 - qtn1*qtn3);

    smat[1][0] = 2*(qtn0*qtn1 - qtn2*qtn3);
    smat[1][1] = 1 - 2*(qtn0*qtn0 + qtn2*qtn2);
    smat[1][2] = 2*(qtn1*qtn2 + qtn0*qtn3);

    smat[2][0] = 2*(qtn0*qtn2 + qtn1*qtn3);
    smat[2][1] = 2*(qtn1*qtn2 - qtn0*qtn3);
    smat[2][2] = 1 - 2*(qtn0*qtn0 + qtn1*qtn1);

    return smat;
  }

  // QtnFromSmat returns the quaternion corresponding to a
  // transformation matrix
  template <class T>
  CWTSQuaternion<T>
  qtnFromSmat(const CWTSSquareMatrix<3, T> &smat)
  {
    // Check trace to prevent loss of accuracy
    T sclrTmp = tr(smat);
    CWTSQuaternion<T> qtn;

    if(sclrTmp > 0)
      {
	// No trouble, we can use standard expression
	sclrTmp = 0.5*sqrt(1 + sclrTmp);
	qtn[0] = 0.25*(smat[1][2] - smat[2][1])/sclrTmp;
	qtn[1] = 0.25*(smat[2][0] - smat[0][2])/sclrTmp;
	qtn[2] = 0.25*(smat[0][1] - smat[1][0])/sclrTmp;
	qtn[3] = sclrTmp;
      }
    else
      {
	// We could be in trouble, so we have to take
	// precautions. NOTE: Parts of this piece of code were taken
	// from the example in the article "Rotating Objects Using
	// Quaternions" in Game Developer Magazine written by Nick
	// Bobick, july 3, 1998, vol. 2, issue 26.
	int i = 0;
	if (smat[1][1] > smat[0][0]) i = 1;
	if (smat[2][2] > smat[i][i]) i = 2;

	switch (i)
	  {
	  case 0:
	    sclrTmp = 0.5*sqrt(1 + smat[0][0] - smat[1][1] - smat[2][2]);
	    qtn[0] = sclrTmp;
	    qtn[1] = 0.25*(smat[0][1] + smat[1][0])/sclrTmp;
	    qtn[2] = 0.25*(smat[0][2] + smat[2][0])/sclrTmp;
	    qtn[3] = 0.25*(smat[1][2] - smat[2][1])/sclrTmp;
	    break;

	  case 1:
	    sclrTmp = 0.5*sqrt(1 - smat[0][0] + smat[1][1] - smat[2][2]);
	    qtn[0] = 0.25*(smat[1][0] + smat[0][1])/sclrTmp;
	    qtn[1] = sclrTmp;
	    qtn[2] = 0.25*(smat[1][2] + smat[2][1])/sclrTmp;
	    qtn[3] = 0.25*(smat[2][0] - smat[0][2])/sclrTmp;
	    break;

	  case 2:
	    sclrTmp = 0.5*sqrt(1 - smat[0][0] - smat[1][1] + smat[2][2]);
	    qtn[0] = 0.25*(smat[2][0] + smat[0][2])/sclrTmp;
	    qtn[1] = 0.25*(smat[2][1] + smat[1][2])/sclrTmp;
	    qtn[2] = sclrTmp;
	    qtn[3] = 0.25*(smat[0][1] - smat[1][0])/sclrTmp;

	    break;
	  }
      }

    return qtn;
  }

  // NOTE: This function duplicates eulerAxisFromQtn(qtn) it only has
  // a different return type.
  template <class T>
  CWTSVector<3, T>
  axisAngleFromQtn( const CWTSQuaternion<T> &qtn )
  {
    return eulerAxisFromQtn(qtn);
  }

  // NOTE: This function duplicates qtnFromEulerAxisAndAngle(..) it
  // only has a different function profile.
  template <class T>
  CWTSQuaternion<T>
  qtnFromAxisAndAngle(const CWTSVector<3, T> &vAxis,
                      const T sAngle)
  {
    return qtnFromEulerAxisAndAngle(vAxis, sAngle);
  }

  template <class T>
  CWTSSquareMatrix<3, T>
  changeOfBasis(CWTSSpaceVector< CWTSSpaceVector<T> >&from, 
		CWTSSpaceVector< CWTSSpaceVector<T> >&to)
  {
    CWTSSquareMatrix<3, T> A;

    // This is a "change of basis" from the "from" frame to the "to"
    // frame.  the "to" frame is typically the "Standard basis"
    // frame.  The "from" is a frame that represents the current
    // orientation of the object in the shape of an orthonormal
    // tripod.

    enum { x , y , z };

    // _X,_Y,_Z is typically the standard basis frame.

    //  | x^_X , y^_X , z^_X |
    //  | x^_Y , y^_Y , z^_Y |
    //  | x^_Z , y^_Z , z^_Z |
	
    A[0][0] = from[x]*to[x];
    A[0][1] = from[y]*to[x];
    A[0][2] = from[z]*to[x];

    A[1][0] = from[x]*to[y];
    A[1][1] = from[y]*to[y];
    A[1][2] = from[z]*to[y];

    A[2][0] = from[x]*to[z];
    A[2][1] = from[y]*to[z];
    A[2][2] = from[z]*to[z];
	
    // This is simply the transpose done manually which would save
    // and inverse call.
    //	| x ^ _X , x ^ _Y , x ^ _Z |
    //	| y ^ _X , y ^ _Y , y ^ _Z |
    //	| z ^ _X , z ^ _Y , z ^ _Z |
	
    // And finally we return the matrix that takes the "from" frame
    // to the "to"/"Standard basis" frame.
    return A;
  }

}

#endif   // IG_STAT_COORDSYS_H
