%{
/*
 * Copyright (C) 1999, 2002, 2003  Free Software Foundation, Inc.
 * 
 * This file is part of GNU libmatheval
 *
 * GNU libmatheval is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * GNU libmatheval is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with program; see the file COPYING. If not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
 * USA.
 */

/* This file was modified for inclusion in Gmsh */

#include "common.h"
#include "node.h"
#include "parser.h"
#include "symbol_table.h"

/* Redefine macro to redirect scanner input from string instead of
   standard input.  */
#define YY_INPUT( buffer, result, max_size ) \
{ result = input_from_string (buffer, max_size); }

/* Variables used to communicate with code using scanner.  */
extern SymbolTable *matheval_symbol_table; /* Evaluator symbol table.  */
extern char *matheval_input_string; /* String representing function.  */

/* Read next max_size character from string into buffer.  */
static int input_from_string (char *buffer, int max_size);
%}

/* Token definitions.  */
whitespace [\ \t]+
digit [0-9]
number ({digit}+|{digit}+"."{digit}*|{digit}*"."{digit}+)([Ee][-+]?{digit}+)?
function "Exp"|"Log"|"Sqrt"|"Sin"|"Cos"|"Tan"|"Ctan"|"Asin"|"Acos"|"Atan"|"Actan"|"Sinh"|"Cosh"|"Tanh"|"Ctanh"|"Asinh"|"Acosh"|"Atanh"|"Actanh"|"Fabs"
identifier [a-zA-Z\_][a-zA-Z0-9\_]*

%%

{whitespace}

{number} {
  /* Create node representing constant with appropriate value.  */
  melval.node = node_create ('c', atof (metext));
  return NUMBER;
}

{function} {
  /* Find symbol table record corresponding to function name.  */
  melval.record = symbol_table_lookup (matheval_symbol_table, metext);
  return FUNCTION;
}

{identifier} {
  Record *record; /* Symbol table record.  */
  /* Inserty variable into symbol table.  */
  record = symbol_table_insert (matheval_symbol_table, metext, 'v');
  melval.node = node_create ('v', record);
  return VARIABLE;
}

"+" {
  return '+';
}

"-" {
  return '-';
}

"*" {
  return '*';
}

"/" {
  return '/';
}

"^" {
  return '^';
}

"(" {
  return '(';
}

")" {
  return ')';
}

"\n" {
  return '\n';
}

%%

#undef mewrap

int mewrap() { return 1; }

static int input_from_string (char *buffer, int max_size)
{
  int count; /* Count of characters to copy from input string to buffer.  */

  /* Calculate count of characters to copy.  */
  count = strlen (matheval_input_string);
  if (count > max_size)
    count = max_size;

  /* Perform copy operation and update input string.  */
  memcpy(buffer, matheval_input_string, count);
  matheval_input_string += count;

  return count;
}

int force_buffer_flush() { YY_FLUSH_BUFFER; }
