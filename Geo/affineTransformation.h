// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef AFFINETRANSFORMATION_H
#define AFFINETRANSFORMATION_H

#include <vector>

// compute (extended) affine transformation matrix from rotation/translation:
// x' = t + (I-R)*x_c + R*x
// where t is the translation vector, I is the identity matrix, and R is the
// matrix for an active intrinsic yaw-pitch-roll rotation (i.e. intrinsic
// z-y'-x'' rotation or extrinsinc x-y-z rotation) with counter-clockwise angles
template <class FLOAT>
bool computeAffineTransformation(const FLOAT *rc, // rotation center
                                 const FLOAT *ra, // rotation angle
                                 const FLOAT *tr, // translation
                                 std::vector<double> &tfo); // transformation

// compute rotation/translation from (extended) affine transformation matrix:
// x' = t + (I-R)*x_c + R*x
// where t is the translation vector, I is the identity matrix, and R is the
// matrix for an active intrinsic yaw-pitch-roll rotation (i.e. intrinsic
// z-y'-x'' rotation or extrinsinc x-y-z rotation) with counter-clockwise angles
template <class FLOAT>
bool getAffineTransformationParameters(const std::vector<double> &tfo, // trnsf.
                                       FLOAT *rc, // rotation center
                                       FLOAT *ra, // rotation angle
                                       FLOAT *tr); // translation

// invert affine transformation
bool invertAffineTransformation(const std::vector<double> &tfo,
                                std::vector<double> &newTfo);

// initialize transformation with unitary one
bool setUnitAffineTransformation(std::vector<double> &tfo);

#endif
