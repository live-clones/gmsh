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

#ifndef XMATH_H
#define XMATH_H

#include <math.h>

/* Calculate cotangent of value x.  */
double ctan(double x);

/* Calculate inverse cotangent of value x.  */
double actan(double x);

/* Calculate hyperbolical cotangent of value x.  */
double ctanh(double x);

/* Calculate inverse hyperbolical sine of value x.  */
double asinh(double x);

/* Calculate inverse hyperbolical cosine of value x.  */
double acosh(double x);

/* Calculate inverse hyperbolical tangent of value x.  */
double atanh(double x);

/* Calculate inverse hyperbolical cotangent of value x.  */
double actanh(double x);

#endif
