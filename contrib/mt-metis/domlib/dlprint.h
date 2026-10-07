/**
 * @file dlprint.h
 * @brief Misc print functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */



#ifndef DL_PRINT_H
#define DL_PRINT_H



/******************************************************************************
* VARIOUS MACROS **************************************************************
******************************************************************************/
#define vprintf(v,t,fmt, ...) \
  do { \
    if (v >= t) { \
      printf(fmt, ##__VA_ARGS__); \
    } \
  } while (0)


/******************************************************************************
* INTERNAL JUNK ***************************************************************
******************************************************************************/
#define _MK_MK_PRINT_FUNC(prefix,type,fmt,pname,strm) \
  void dl_ ## pname ## _ ## prefix ## _array(const char * name, \
      const type * a, const size_t n, const int newline) \
  { \
    size_t i; \
    fprintf(strm,"%s [",name); \
    for (i=0;i<n;++i) { \
      if (i < n-1) { \
        fprintf(strm,fmt",",a[i]); \
      } else { \
        fprintf(strm,fmt,a[i]); \
      } \
    } \
    if (newline) { \
      fprintf(strm,"]\n"); \
    } else { \
      fprintf(strm,"]"); \
    } \
  }

/******************************************************************************
* PRINT HEADERS ***************************************************************
******************************************************************************/
#define DL_MK_PRINT_HEADERS(prefix,type) \
  void dl_print_ ## prefix ## _array(const char * name, const type * a, \
      const size_t n, const int newline); \
  void dl_eprint_ ## prefix ## _array(const char * name, const type * a, \
      const size_t n, const int newline);

/******************************************************************************
* PRINT FUNCS *****************************************************************
******************************************************************************/
#define DL_MK_PRINT_FUNCS(prefix,type,fmt) \
  _MK_MK_PRINT_FUNC(prefix,type,fmt,print,stdout) \
  _MK_MK_PRINT_FUNC(prefix,type,fmt,eprint,stderr) \




#endif
