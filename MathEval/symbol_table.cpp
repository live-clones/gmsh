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

#include <assert.h>
#include <stdarg.h>

#include "common.h"
#include "symbol_table.h"
#include "xmath.h"

/*
 * Type definition for function accepting single argument of double type and
 * returning double value.
 */
typedef double  (*function_type) (double);

/* Calculate hash value for given name and hash table length.  */
static int      hash(char *name, int length);

SymbolTable *
symbol_table_create(int length)
{
  SymbolTable    *symbol_table;	/* Pointer to symbol table.  */
  static char    *names[] = {"Exp", "Log", "Sqrt", "Sin", "Cos", "Tan", "Ctan", 
			     "Asin", "Acos", "Atan", "Actan", "Sinh", "Cosh", "Tanh",
			     "Ctanh", "Asinh", "Acosh", "Atanh", "Actanh", "Fabs" };
  static double   (*functions[]) (double) = { exp, log, sqrt, sin, cos, tan, ctan, 
					      asin, acos, atan, actan, sinh, cosh, tanh, 
					      ctanh, asinh, acosh, atanh, actanh, fabs};
  unsigned int i;
  
  /*
   * Allocate memory for symbol table data structure as well as for
   * corresponding hash table.
   */
  symbol_table = XMALLOC(SymbolTable, 1);
  symbol_table->length = length;
  symbol_table->records = XCALLOC(Record, symbol_table->length);
  
  /*
   * Insert predefined functions into symbol table.
   */
  for (i = 0; i < sizeof(names) / sizeof(names[0]); i++)
    symbol_table_insert(symbol_table, names[i], 'f', functions[i]);
  
  /*
   * Initialize symbol table reference count.
   */
  symbol_table->reference_count = 1;
  
  return symbol_table;
}

void
symbol_table_destroy(SymbolTable * symbol_table)
{
  Record         *curr, *next; /* Pointers to current and next record
				* while traversing hash table bucket.  */
  int             i;

  if(!symbol_table)
    return;
  
  /*
   * Decrement refernce count and return if symbol table still used
   * elsewhere.
   */
  if (--symbol_table->reference_count > 0)
    return;
  
  /*
   * Delete hash table as well as data structure representing symbol
   * table.
   */
  for (i = 0; i < symbol_table->length; i++)
    for (curr = symbol_table->records[i].next; curr;) {
      next = curr->next;
      XFREE(curr->name);
      XFREE(curr);
      curr = next;
    }
  XFREE(symbol_table->records);
  XFREE(symbol_table);
}

Record *
symbol_table_insert(SymbolTable * symbol_table, char *name, char type,...)
{
  Record         *record;	/* Pointer to symbol table record
				 * corresponding to name given.  */
  va_list         ap;		/* Function variable argument list.  */
  int             i;
  
  /*
   * Check if symbol already in table and, if affirmative and record
   * type same as type given, return corresponding record immediately.
   */
  if ((record = symbol_table_lookup(symbol_table, name))) {
    assert(record->type == type);
    return record;
  }
  /*
   * Allocate memory for and initialize new record.
   */
  record = XMALLOC(Record, 1);
  record->name = XMALLOC(char, strlen(name) + 1);
  strcpy(record->name, name);
  record->type = type;
  
  /*
   * Parse function variable argument list to complete record
   * initialization.
   */
  va_start(ap, type);
  switch (record->type) {
  case 'v':
    record->data.value = 0;
    break;
    
  case 'f':
    record->data.function = va_arg(ap, function_type);
    break;
  }
  va_end(ap);
  
  /*
   * Calculate hash value and put record in corresponding hash table
   * bucket.
   */
  i = hash(name, symbol_table->length);
  record->next = symbol_table->records[i].next;
  symbol_table->records[i].next = record;
  
  return record;
}

Record *
symbol_table_lookup(SymbolTable * symbol_table, char *name)
{
  int             i;	/* Hash value. */
  Record         *curr;	/* Pointer to current symbol table record.  */
  
  /*
   * Calcuate hash value for name given.
   */
  i = hash(name, symbol_table->length);
  
  /*
   * Lookup for name in hash table bucket corresponding to above hash
   * value.
   */
  for (curr = symbol_table->records[i].next; curr; curr = curr->next)
    if (!strcmp(curr->name, name))
      return curr;
  
  return NULL;
}

SymbolTable *
symbol_table_assign(SymbolTable * symbol_table)
{
  /*
   * Increase symbol table reference count and return pointer to data
   * structure representing table.
   */
  symbol_table->reference_count++;
  return symbol_table;
}

/*
 * Function below reused from A.V. Aho, R. Sethi, J.D. Ullman, "Compilers -
 * Principle, Techniques, and Tools", Addison-Wesley, 1986, pp 435-437, and
 * in turn from P.J. Weineberger's C compiler.
 */
static int
hash(char *s, int n)
{
  char           *p;
  unsigned        h, g;
  
  h = 0;
  
  for (p = s; *p; p++) {
    h = (h << 4) + *p;
    if ((g = h & 0xf0000000)) {
      h = h ^ (g >> 24);
      h = h ^ g;
    }
  }
  
  return h % n;
}
