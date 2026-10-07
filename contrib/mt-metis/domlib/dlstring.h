/**
 * @file dlstring.h
 * @brief Functions for manipulating strings
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DL_STRING_H
#define DL_STRING_H




#include "domlib.h"




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


size_t dl_string_split(
    char const * string, 
    char const * delims, 
    char *** ptrs);


size_t dl_string_occurances(
    char const * string, 
    char const * substr);


int dl_string_endswith(
    char const * string, 
    char const * suffix);


int dl_string_lowerize(
    char * string);


int dl_string_nlowerize(
    char * string, 
    size_t len);


int dl_string_upperize(
    char * string);


int dl_string_nupperize(
    char * string, 
    size_t len);


int dl_strncmp_nocase(
    char const * a,
    char const * b,
    size_t n);


#endif
