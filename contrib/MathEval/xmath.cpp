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
#include <stdlib.h>
#include <cmath>
#include <stdio.h>

using std::fabs;

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
  return 0.5 * log((x + 1) / (x - 1));
}

double
x_rand(double x)
{
  /*
   * Calculate random value in [0, x].
   */
  
  return x*(double)rand()/(double)RAND_MAX;
}
double
x_step(double x)
{
	/* 
	 * Calculate step function value.
	 */
	return (x < 0) ? 0 : 1;
}

double
x_heavs(double x) //, double eps)
{
	/* 
	 * Calculate smoothed heaviside function value.
	 */
  double eps=3.0;
         return (fabs(x) < eps) ? 0.5*(1+ x/eps +1/3.14*sin(3.14*x/eps)):(x<0? 0:1);
}

#if !defined(INFINITY)
#define INFINITY 1.e100
#endif

#if !defined(NAN)
#define NAN (1./0.)
#endif

double
x_delta(double x)
{
	/* 
	 * Calculate delta function value.
	 */
	return (x == 0) ? INFINITY : 0;
}

double
x_nandelta(double x)
{
	/* 
	 * Calculate modified delta function value.
	 */
	return (x == 0) ? NAN : 0;
}

