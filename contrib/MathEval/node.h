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

#ifndef NODE_H
#define NODE_H 1

#include "symbol_table.h"

/* Data structure representing function tree node.  */
typedef struct _Node {
  char            type;	/* Node type ('c' for constant, 'v' for
			 * variable, 'f' for function, 'u' for unary
			 * operator, 'b' for binary operator).  */
  union {
    double          constant;	/* Constant value.  */
    Record         *variable;	/* Symbol table record for
				 * variable.  */
    struct {
      Record         *record;	/* Symbol table record for
				 * function.  */
      struct _Node   *child;	/* Function argument node.  */
    }               function;	/* Structure representing
				 * function.  */
    struct {
      char            operatorr;/* Operator type ('-'
				 * for unary minus).  */
      struct _Node   *child;	/* Operand node.  */
    }               un_op;	/* Structure representing unary
				 * operator.  */
    struct {
      char            operatorr;/* Operator type ('+'
				 * for adition, '-' for
				 * subtraction, '*' for
				 * multiplication, '/'
				 * for division and '^'
				 * for exponentiation).  */
      struct _Node   *left, *right;	/* Operands nodes.  */
    }               bin_op;	/* Structure representing binary
				 * operator.  */
  }               data;
}               Node;

/*
 * Create node of given type and initialize it from optional arguments.
 * Function returns pointer to node object that should be passed as first
 * argument to all other node functions.
 */
Node           *node_create(char type,...);

/* Destroy subtree rooted at specified node.  */
void            node_destroy(Node * node);

/*
 * Make a copy of subtree rooted at given node.  Deep copy operation is
 * employed.
 */
Node           *node_copy(Node * node);

/*
 * Simplify subtree rooted at given node.  Function returns root of
 * simplified subtree (that may or may not be original node).
 */
Node           *node_simplify(Node * node);

/*
 * Evaluate subtree rooted at given node.  For variables, values from symbol
 * table are used.
 */
double          node_evaluate(Node * node);

/*
 * Create derivative tree for subtree rooted at given node.  Second argument
 * is derivation variable, third argument is symbol table (needed for
 * functions derivatives).  Function returns root of corresponding derivation
 * tree.
 */
Node           *node_derivative(Node * node, char *name, SymbolTable * symbol_table);

/*
 * Calculate length of the string representing subtree rooted at specified
 * node.
 */
int             node_calculate_length(Node * node);

/*
 * Write subtree rooted at specified node to given string variable.  No
 * checking of string overflow is done by this procedure; it is expected that
 * string of appropriate length is passed as argument.
 */
void            node_write(Node * node, char *string);

#endif
