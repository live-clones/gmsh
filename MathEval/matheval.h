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

#ifndef EVALUATOR_H
#define EVALUATOR_H

/*
 * Create evaluator from string representing function.  Function
 * returns pointer that should be passed as first argument to all
 * other library functions.  If an error occurs, function will return
 * null pointer.
 */
void    *evaluator_create(char *string);

/*
 * Destroy evaluator specified.
 */
void     evaluator_destroy(void *evaluator);

/*
 * Evaluate function represented by evaluator given.  Variable names
 * and respective values are represented by function third and fourth
 * argument. Number of variables i.e. length of these two arrays is
 * given by second argument.  Function returns evaluated function
 * value.  In case that function contains variables with names not
 * given through third function argument, value of this variable is
 * undeterminated.
 */
double   evaluator_evaluate(void *evaluator, int count, char **names, double *values);

/*
 * Calculate length of textual representation of evaluator. This
 * procedure is inteded to be used along with evaluator_write()
 * procedure that follows.
 */
int      evaluator_calculate_length(void *evaluator);

/*
 * Write textual representation of evaluator (i.e. corresponding
 * function) to given string.  No string overflow is checked by this
 * procedure; string of appropriate length (calculated beforehand
 * using above evaluator_calculate_length() procedure) is expected to
 * be allocated beforehand.
 */
void     evaluator_write(void *evaluator, char *length);

/*
 * Create evaluator for first derivative of function represented by
 * evaluator given as first argument using derivative variable given
 * as second argument.
 */
void    *evaluator_derivative(void *evaluator, char *name);

/*
 * Helper functions to simplify evaluation when variable names are
 * "x", "x" and "y" or "x" and "y" and "z" respectively.
 */
double   evaluator_evaluate_x(void *evaluator, double x);
double   evaluator_evaluate_x_y(void *evaluator, double x, double y);
double   evaluator_evaluate_x_y_z(void *evaluator, double x, double y, double z);

/*
 * Helper functions to simplify differentiation when variable names
 * are "x" or "y" or "z" respectively.
 */
void    *evaluator_derivative_x(void *evaluator);
void    *evaluator_derivative_y(void *evaluator);
void    *evaluator_derivative_z(void *evaluator);

#endif
