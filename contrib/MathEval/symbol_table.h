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

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

/* Data structure representing symbol table record.  */
typedef struct _Record {
  struct _Record *next;	/* Pointer to next record.  */
  char *name; /* Symbol name.  */
  char type; /* Symbol type ('v' for variable, 'f' for function).  */
  union {
    double value; /* Variable value.  */
    double (*function) (double); /* Pointer to function to calculate
				  * its value.  */
  } data;
} Record;

/*
 * Data structure representing symbol table (hash table is used for this
 * purpose).
 */
typedef struct {
  int length; /* Hash table length.  */
  Record  *records; /* Hash table buckets.  */
  int reference_count; /* Reference count for symbol table (evaluator
			* for derivative uses same symbol table as
			* evaluator for corresponding function).  */
} SymbolTable;

/* Create symbol table using specified length of hash table.  */
SymbolTable *symbol_table_create(int length);

/* Destroy symbol table.  */
void symbol_table_destroy(SymbolTable * symbol_table);

/*
 * Insert symbol into given symbol table.  Further arguments are symbol name
 * and its type, as well as additional arguments according to symbol type.
 * Return value is pointer to symobl table record created to represent
 * symbol.  If symbol already in symbol table, pointer to its record is
 * returned immediately.
 */
Record *symbol_table_insert(SymbolTable * symbol_table, char *name, char type,...);

/*
 * Lookup symbol by name from given symbol table.  Pointer to symbol record
 * is returned if symbol found, null pointer otherwise.
 */
Record *symbol_table_lookup(SymbolTable * symbol_table, char *name);

/*
 * Return symbol table pointer to be assigned to variable.  This function
 * should be used instead of simple pointer assignement for proper reference
 * counting.  Users willing to manage reference counts by themselves are free
 * to ignore this functions.
 */
SymbolTable *symbol_table_assign(SymbolTable * symbol_table);

#endif
