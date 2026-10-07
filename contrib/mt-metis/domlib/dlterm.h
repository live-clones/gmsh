/**
 * @file dlterm.h
 * @brief Utilities for displaying on a terminal
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-04-11
 */


#ifndef DL_TERM_H
#define DL_TERM_H

#include "domlib.h"


/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct dl_status_bar_t {
  size_t ticks;
  size_t nticks;
  size_t done10;
  double done;
  char * str;
} dl_status_bar_t;




/******************************************************************************
* DOMLIB IMPORTS **************************************************************
******************************************************************************/


#define DLMEM_PREFIX dl_status_bar
#define DLMEM_TYPE_T dl_status_bar_t
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T





/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


/* term functions */

size_t dl_get_term_width(void);


size_t dl_get_term_height(void);


/**
 * @brief Print a row of chars with a title as wide as the terminal
 *
 * @param title The header title to print
 * @param marker The character to mark the row with
 *
 * @return !0 on success
 */
int dl_print_header(
    const char * title,
    char marker);


/**
 * @brief Print a row of chars of as wide as the terminal
 *
 * @param marker The char to print
 *
 * @return !0 on success
 */
int dl_print_footer(
    char marker);


/* status bar functions */

dl_status_bar_t * dl_status_bar_create(void);


void dl_status_bar_init(
    dl_status_bar_t * bar);


double dl_status_bar_update(
    double done, 
    dl_status_bar_t * bar);


void dl_status_bar_change(
    double done, 
    dl_status_bar_t * bar);


void dl_status_bar_draw(
    dl_status_bar_t * bar);


void dl_status_bar_free(
    dl_status_bar_t * bar);




#endif
