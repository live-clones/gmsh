/*
 * Copyright (C) 1999, 2002, 2003  Free Software Foundation, Inc.
 *
 * This file is part of GNU libmatheval
 *
 * GNU libmatheval is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2, or (at your option) any later
 * version.
 *
 * GNU libmatheval is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * program; see the file COPYING. If not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/* This file was modified for inclusion in Gmsh */

#include "xmath.h"
#include <math.h>

double
x_ctan(double x)
{
  /*
   * Calculate cotangent value.
   */
  return 1 / tan(x);
}

double
x_actan(double x)
{
  /*
   * Calculate inverse cotangent value.
   */
  return atan(1 / x);
}

double
x_ctanh(double x)
{
  /*
   * Calculate hyperbolic cotangent value.
   */
  return 1 / tanh(x);
}

double
x_asinh(double x)
{
  /*
   * Calculate inverse hyperbolic sine value using relation between
   * hyperbolic and exponential functions.
   */
  return log(x + sqrt(x * x + 1));
}

double
x_acosh(double x)
{
  /*
   * Calculate inverse hyperbolic cosine value using relation between
   * hyperbolic and exponential functions.
   */
  return log(x + sqrt(x * x - 1));
}

double
x_atanh(double x)
{
  /*
   * Calculate inverse hyperbolic tangent value using relation between
   * hyperbolic and exponential functions.
   */
  return 0.5 * log((1 + x) / (1 - x));
}

double
x_actanh(double x)
{
  /*
   * Calculate inverse hyperbolic cotangent value.
   */
  return atanh(1 / x);
}
