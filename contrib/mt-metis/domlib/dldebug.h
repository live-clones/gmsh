/**
 * @file dldebug.h
 * @brief Debugging functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */



#ifndef DL_DEBUG_H
#define DL_DEBUG_H




/******************************************************************************
* PRIVATE MACROS **************************************************************
******************************************************************************/


static inline void __backtrace(void)
{
  int size, i;
  void * buffer[255];
  char ** strings; 

  size = backtrace(buffer,255);
  strings = backtrace_symbols(buffer,size);
  for (i=0;i<size;++i) {
    fprintf(stderr,"%d:[%p] %s\n",i,buffer[i],strings[i]);
  }
  free(strings);
}




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static inline const char * __current_time(void)
{
  time_t tm = time(NULL);
  char * str = ctime(&tm);
  str[24] = '\0';
  return str;
}




/******************************************************************************
* Output Macros ***************************************************************
******************************************************************************/


#ifdef DEBUG
#define eprintf(...) \
  do { \
    fprintf(stderr,"At %s: %d, in %s()", __FILE__, __LINE__, __func__); \
    fprintf(stderr, "%s ERROR: ",__current_time()); \
    fprintf(stderr, __VA_ARGS__); \
    fflush(stderr); \
  } while (0)
#else
#define eprintf(...) \
  do { \
    fprintf(stderr, "ERROR: "); \
    fprintf(stderr, __VA_ARGS__); \
    fflush(stderr); \
  } while (0)
#endif

#define dl_error(...) \
  do { \
    eprintf( __VA_ARGS__); \
    abort(); \
  } while (0)

#define dl_unimplemented() \
  dl_error("Unimplemented function '%s' in '%s' called.\n", __func__,__FILE__)

#ifdef DEBUG
  #define wprintf( ...) \
    do { \
      fprintf(stderr,"%s WARN: ",__current_time()); \
      fprintf(stderr,__VA_ARGS__); \
      fflush(stderr); \
    } while (0)

  #define dprintf( ...) \
    do { \
      fprintf(stdout,"%s DEBUG: ",__current_time()); \
      fprintf(stdout,__VA_ARGS__); \
      fflush(stdout); \
    } while (0)
#else
  #define wprintf( ...)
  #define dprintf( ...)
#endif

#ifdef USE_ASSERTS
  #define __my_fail() ((int*)NULL)[0] = 0
  #ifdef MPI_VERSION
  #define DL_ASSERT(cond, ...) \
    do { \
      if (!(cond)) { \
        int __rank, __size; \
        fflush(stdout); \
        fflush(stderr); \
        MPI_Comm_rank(MPI_COMM_WORLD,&__rank); \
        MPI_Comm_size(MPI_COMM_WORLD,&__size); \
        eprintf("[%d/%d] : ",__rank,__size); \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stdout); \
        fflush(stderr); \
        /* print the stack trace */ \
        /*__backtrace();*/ \
        __my_fail(); \
      } \
    } while (0)
  #else
  #define DL_ASSERT(cond, ...) \
    do { \
      if (!(cond)) { \
        fflush(stdout); \
        fflush(stderr); \
        eprintf( __VA_ARGS__); \
        fprintf(stderr,"\n"); \
        fflush(stdout); \
        fflush(stderr); \
        /* print the stack trace */ \
        /*__backtrace();*/ \
        __my_fail(); \
      } \
    } while (0)
  #endif
  #define DL_ASSERT_EQUALS(a,b,fmt) \
    DL_ASSERT((a) == (b),"("#a" = "fmt") != ("#b" = "fmt")",a,b)
#else
  #define DL_ASSERT(cnd, ...)
  #define DL_ASSERT_EQUALS(a,b,fmt)
#endif

/* static assertions */
#define __DL_STATIC_ASSERT2(x,y) \
  enum { __static_assertion_ ## y = (2/(x)) }
#define __DL_STATIC_ASSERT1(x,y) __DL_STATIC_ASSERT2(x,y)
#define DL_STATIC_ASSERT(x) \
  __DL_STATIC_ASSERT1(x,__COUNTER__)


#endif
