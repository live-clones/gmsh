/**
 * @file dlterm.c
 * @brief Functions for using terminals
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-04-11
 */




#ifndef DL_TERM_C
#define DL_TERM_C




#include "dlterm.h"




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static const size_t __DEFAULT_TERM_WIDTH = 80;
static const size_t __MAX_VALID_TERM_WIDTH = 640;
static const size_t __MIN_VALID_TERM_WIDTH = 16;
static const size_t __DEFAULT_TERM_HEIGHT = 20;
static const size_t __MAX_VALID_TERM_HEIGHT = 320;
static const size_t __MIN_VALID_TERM_HEIGHT = 1;
static const char __BAR_START = '[';
static const char __BAR_END = ']';
static const char __BAR_MID = '=';
static const char __BAR_EMPTY = ' ';
static const char __BAR_HEAD = '>';
static const size_t __BAR_ENDS_LENGTH = 9;
static const char * const __BAR_FMT = "%03.1lf%%";




/******************************************************************************
* DOMLIB IMPORTS **************************************************************
******************************************************************************/


#define DLMEM_PREFIX dl_status_bar
#define DLMEM_TYPE_T dl_status_bar_t
#define DLMEM_DLTYPE DLTYPE_STRUCT
#define DLMEM_INITFUNCTION dl_status_bar_init
#include "dlmem_funcs.h"
#undef DLMEM_INITFUNCTION
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


size_t dl_get_term_width(void)
{
  struct winsize w;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0 && 
      ((size_t)w.ws_col) <= __MAX_VALID_TERM_WIDTH &&
      ((size_t)w.ws_col) >= __MIN_VALID_TERM_WIDTH) {
    return (size_t)w.ws_col;
  } else {
    return __DEFAULT_TERM_WIDTH;
  }
}


size_t dl_get_term_height(void)
{
  struct winsize w;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0 &&
      ((size_t)w.ws_row) <= __MAX_VALID_TERM_HEIGHT &&
      ((size_t)w.ws_row) >= __MIN_VALID_TERM_HEIGHT) {
    return (size_t)w.ws_row;
  } else {
    return __DEFAULT_TERM_HEIGHT;
  }
}


int dl_print_header(
    const char * const title,
    const char marker)
{
  size_t i = 0;
  const size_t width = dl_get_term_width();

  printf("%c ",marker);
  i += 2;
  if (strlen(title) > width-i) {
    printf("%.*s",(int)(width-i),title);
  } else {
    printf("%s ",title);
  }
  i += strlen(title)+1;
  for (;i<width;++i) {
    printf("%c",marker);
  }
  printf("\n");
  return 1;
}


int dl_print_footer(
    const char marker)
{
  size_t i = 0;
  const size_t width = dl_get_term_width();

  for (i=0;i<width;++i) {
    printf("%c",marker);
  }
  printf("\n");
  return 1;
}


dl_status_bar_t * dl_status_bar_create(void)
{
  dl_status_bar_t * bar = dl_status_bar_calloc(1);
  bar->nticks = dl_get_term_width() - __BAR_ENDS_LENGTH;
  bar->str = (char*)malloc(bar->nticks + __BAR_ENDS_LENGTH); 
  bar->str[0] = '\r';
  bar->str[1] = __BAR_START;
  memset(bar->str+2,__BAR_EMPTY,bar->nticks);
  bar->str[bar->nticks+2] = __BAR_END;
  bar->str[bar->nticks+3] = ' ';
  sprintf(bar->str+bar->nticks+4,__BAR_FMT,bar->done10/10.0);
  return bar;
}


void dl_status_bar_init(
    dl_status_bar_t * const bar)
{
  bar->ticks = 0;
  bar->nticks = 0;
  bar->done = 0.0;
  bar->done10 = (size_t)(bar->done*1000);
  bar->str = NULL;
}


double dl_status_bar_update(
    const double done, 
    dl_status_bar_t * const bar)
{
  size_t nset;
  size_t old10 = bar->done10;
  size_t oldticks = bar->ticks;
  int draw = 0;
  bar->done += done;
  bar->ticks = bar->done*bar->nticks;
  bar->done10 = (size_t)(bar->done*1000);
  if (bar->ticks > oldticks) {
    nset = bar->ticks-oldticks;
    memset(bar->str+2+oldticks,__BAR_MID,nset);
    if (bar->ticks < bar->nticks) {
      bar->str[2+bar->ticks] = __BAR_HEAD;
    }
    draw = 1;
  } else if (bar->ticks < oldticks) {
    nset = oldticks - bar->ticks -1;
    if (nset > 0) {
      memset(bar->str+3+bar->ticks,__BAR_EMPTY,nset); 
    }
    bar->str[2+bar->ticks] = __BAR_HEAD;
    draw = 1;
  }
  if (bar->done10 != old10) {
    sprintf(bar->str+bar->nticks+4,__BAR_FMT,bar->done10/10.0);
    draw = 1;
  }
  if (draw) {
    dl_status_bar_draw(bar);
  }
  return bar->done;
}


void dl_status_bar_draw(
    dl_status_bar_t * const bar)
{
  printf("%s",bar->str);
}


void dl_status_bar_free(
    dl_status_bar_t * bar)
{
  dl_free(bar->str);
  dl_free(bar);
}





#endif
