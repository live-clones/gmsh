// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_MESSAGE_H
#define HXT_MESSAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdarg.h>


/* HEXTREME FUNCTIONS ONLY RETURN A STATUS (except hxtGetMessageString)*/
typedef enum
{
  // positive values mean a success         => HXT_CHECK does nothing for positive values
  HXT_STATUS_OK                    = 0,
  HXT_STATUS_TRUE                  = 0,
  HXT_STATUS_FALSE                 = 1,


  // ====== ERRORS
  // negatives values means errors

  // Fatal Errors                            => HXT_CHECK give trace message and return
  HXT_STATUS_ERROR                 = -1,
  HXT_STATUS_FAILED                = -2,
  HXT_STATUS_ASSERTION_FAILED      = -3,
  HXT_STATUS_OUT_OF_MEMORY         = -4,
  HXT_STATUS_FILE_CANNOT_BE_OPENED = -5,
  HXT_STATUS_POINTER_ERROR         = -6,
  HXT_STATUS_READ_ERROR            = -7,
  HXT_STATUS_WRITE_ERROR           = -8,
  HXT_STATUS_RANGE_ERROR           = -9,
  HXT_STATUS_FORMAT_ERROR          = -10,


  // INTERNAL Errors (<= HXT_STATUS_INTERNAL) => HXT_CHECK does not give trace message but returns... should be catched internally !
  HXT_STATUS_INTERNAL              = -1024,
  HXT_STATUS_SKIP                  = -1025,
  HXT_STATUS_TRYAGAIN              = -1026,
  // a smoothing or topological operation can silently fail because of these
  HXT_STATUS_CONFLICT              = -1027,
  HXT_STATUS_CONSTRAINT            = -1028,
  HXT_STATUS_NOTBETTER             = -1029,
  HXT_STATUS_DOUBLE_PT             = -1030


}HXTStatus;


#define STR(x) #x
#define STRINGIFY(x) STR(x)

#define HXT_INFO(...)                 hxtMessageInfo(__func__, __FILE__, STRINGIFY(__LINE__), ## __VA_ARGS__ )
#define HXT_INFO_COND(cond, ...)      ((cond)?HXT_INFO(__VA_ARGS__):HXT_STATUS_OK)
#define HXT_WARNING(...)              hxtMessageWarning(__func__, __FILE__, STRINGIFY(__LINE__), ## __VA_ARGS__ )

/* print an error message corresponding to a status */
#define HXT_ERROR_MSG(status, ...)    hxtMessageError(status, __func__, __FILE__, STRINGIFY(__LINE__), ## __VA_ARGS__ )
#define HXT_ERROR(status)             HXT_ERROR_MSG(status,NULL)

/* give trace message if status is not OK, but does not return */
#ifdef NDEBUG
#define HXT_TRACE_MSG(status, ...)    (void)0 // do nothing
#else
#define HXT_TRACE_MSG(status, ...)    hxtMessageTraceError(status, __func__, __FILE__, STRINGIFY(__LINE__), ## __VA_ARGS__ )
#endif
#define HXT_TRACE(status)             HXT_TRACE_MSG(status, NULL)

/* give trace message and return the error status if not ok */
#define HXT_CHECK_MSG(status, ...)              \
  do {                                          \
    HXTStatus _tmp_ = status;                   \
    if(_tmp_<0) {                               \
      if (_tmp_>HXT_STATUS_INTERNAL) {          \
        HXT_TRACE_MSG(_tmp_, ## __VA_ARGS__);   \
      }                                         \
      return _tmp_;                             \
    }                                           \
  } while(0)


#define HXT_CHECK(status)             HXT_CHECK_MSG(status,NULL)

/* use to check some expression inside of function, throw error if exp is not true */
#ifndef NDEBUG
  #define HXT_ASSERT_MSG(exp, ...)                                          \
    do {                                                                    \
      if (!(exp)) {                                                         \
        HXT_ERROR_MSG(HXT_STATUS_ASSERTION_FAILED, ## __VA_ARGS__ );        \
        abort();                                                            \
    }                                                                       \
  } while(0)
  #define HXT_ASSERT(exp)             HXT_ASSERT_MSG(exp, "assertion (" #exp ") Failed")
#else
  #define HXT_ASSERT_MSG(exp, ...)
  #define HXT_ASSERT(exp)
#endif


const char*  hxtGetStatusString(HXTStatus status);


/* MESSAGE */
typedef struct {
  /* the message content */
  const char* string; // lifetime = time of callback function

  /* information about the location of the code which sent the message */
  const char* func;   // lifetime = forever
  const char* file;   // lifetime = forever
  const char* line;   // lifetime = forever
  int threadId;      // the thread which sent the message
  int numThreads;    // the number of threads

  enum{
    HXT_MSGLEVEL_INFO     = 0,
    HXT_MSGLEVEL_DEBUG    = 1,
    HXT_MSGLEVEL_WARNING  = 2,
    HXT_MSGLEVEL_ERROR    = 3,
    HXT_MSGLEVEL_TRACE    = 4
  } level;
} HXTMessage;


/* MESSAGE AND ERROR HANDLING */
HXTStatus  hxtSetMessageCallback (HXTStatus (*hxtMsgCallback)(HXTMessage* msg));

HXTStatus  hxtMessageInfo       ( const char* func, const char* file, const char* line, const char *fmt, ...);
HXTStatus  hxtMessageWarning    ( const char* func, const char* file, const char* line, const char *fmt, ...);
HXTStatus  hxtMessageError      ( HXTStatus status, const char* func, const char* file, const char* line, const char *fmt, ...);

#ifndef NDEBUG
HXTStatus  hxtMessageTraceError ( HXTStatus status, const char* func, const char* file, const char* line, const char *fmt, ...);
#endif

#ifdef __cplusplus
}
#endif

#endif
