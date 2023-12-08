// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include <stdlib.h>
#include <stdio.h>
#include "hxt_omp.h"
#include "hxt_message.h"


HXTStatus defaultMessageCallback(HXTMessage* msg);

static HXTStatus (*msgCallback)(HXTMessage* msg) = &defaultMessageCallback; // the message callback is declared as a global variable
static const char* encodingIssue = "~~~~ (encoding issue) ~~~~";


const char*  hxtGetStatusString(HXTStatus status){
  switch(status){
    case HXT_STATUS_OK                   :
      return "no error";
      break;
    case HXT_STATUS_FAILED               :
      return "function failed";
      break;
    case HXT_STATUS_OUT_OF_MEMORY        :
      return "out of memory";
      break;
    case HXT_STATUS_ERROR                :
      return "error";
      break;
    case HXT_STATUS_FILE_CANNOT_BE_OPENED:
      return "file cannot be opened";
      break;
    case HXT_STATUS_ASSERTION_FAILED:
      return "assertion failed";
      break;
    case HXT_STATUS_POINTER_ERROR:
      return "wrong pointer given";
      break;
    case HXT_STATUS_READ_ERROR:
      return "read error";
      break;
    case HXT_STATUS_WRITE_ERROR:
      return "write error";
      break;
    case HXT_STATUS_RANGE_ERROR:
      return "number out of range";
      break;
    case HXT_STATUS_FORMAT_ERROR:
      return "wrong format";
      break;
    case HXT_STATUS_INPUT_ERROR:
      return "input mesh structure error";
      break;
    default:
      if(status<=HXT_STATUS_INTERNAL)
        return "internal error was not caught. This should not happen";
      else if(status<0)
        return "unknown error";
      else
        return "positive return value (no error)";
      break;
  }
}



HXTStatus defaultMessageCallback(HXTMessage* msg){
  if (msg->level == HXT_MSGLEVEL_INFO)
    fprintf(stdout,"Info : %s\n", msg->string);
#ifndef NDEBUG
  else if (msg->level == HXT_MSGLEVEL_ERROR)
    fprintf(stderr,"= X = Error : %s   \n in %s -> %s:%s\n", msg->string, msg->func, msg->file, msg->line);
  else if (msg->level == HXT_MSGLEVEL_TRACE)
    fprintf(stderr,"  - trace -   %s -> %s:%s  \t(%s)\n", msg->func, msg->file, msg->line, msg->string);
  else if (msg->level == HXT_MSGLEVEL_WARNING)
    fprintf(stderr,"/!\\ Warning : %s\n", msg->string);
  else if (msg->level == HXT_MSGLEVEL_DEBUG)
    fprintf(stderr,"Debug : %s   \t(in %s -> %s:%s)\n", msg->string, msg->func, msg->file, msg->line);
#else
  else if (msg->level == HXT_MSGLEVEL_ERROR)
    fprintf(stderr,"= X = Error : %s   \n", msg->string);
  else if (msg->level == HXT_MSGLEVEL_WARNING)
    fprintf(stderr,"/!\\ Warning : %s\n", msg->string);
#endif
  return HXT_STATUS_OK;
}


HXTStatus  hxtSetMessageCallback(HXTStatus (*newMsgCallback)(HXTMessage* msg)){
  if(newMsgCallback==NULL)
    msgCallback = defaultMessageCallback;
  else
    msgCallback = newMsgCallback;
  return HXT_STATUS_OK;
}


static void hxtMessageGeneral ( int messageLevel,
                                  const char* func,
                                  const char* file,
                                  const char* line,
                                  const char* encodingIssueString,
                                  const char* alternativeString,
                                  const char *fmt, va_list args){
  HXTMessage msg;

  char str[4096];
  if(fmt!=NULL){
    int err = vsnprintf(str, sizeof(str), fmt, args);

    if(err>=0)
      msg.string = str;
    else
      msg.string = encodingIssueString;
  }
  else{
    msg.string = alternativeString;
  }

  msg.func = func;
  msg.file = file;
  msg.line = line;
  msg.level = messageLevel;

  msg.threadId = omp_get_thread_num();
  msg.numThreads = omp_get_num_threads();

  // #pragma omp critical
  {
    msgCallback(&msg);
  }
}


HXTStatus  hxtMessageInfo        ( const char* func, const char* file, const char* line, const char *fmt, ...){
  va_list args;
  va_start(args, fmt);
  hxtMessageGeneral(HXT_MSGLEVEL_INFO, func, file, line, encodingIssue, "", fmt, args);
  va_end(args);
  return HXT_STATUS_OK;
}


HXTStatus  hxtMessageWarning        ( const char* func, const char* file, const char* line, const char *fmt, ...){
  va_list args;
  va_start(args, fmt);
  hxtMessageGeneral(HXT_MSGLEVEL_WARNING, func, file, line, encodingIssue, "", fmt, args);
  return HXT_STATUS_OK;
}


HXTStatus  hxtMessageError       ( HXTStatus status, const char* func, const char* file, const char* line, const char *fmt, ...){
  va_list args;
  va_start(args, fmt);
  hxtMessageGeneral(HXT_MSGLEVEL_ERROR, func, file, line, hxtGetStatusString(status), hxtGetStatusString(status), fmt, args);
  va_end(args);
  return status;
}

#ifndef NDEBUG
HXTStatus  hxtMessageTraceError( HXTStatus status, const char* func, const char* file, const char* line, const char *fmt, ...){
  if(status==HXT_STATUS_OK)
    return HXT_STATUS_OK;
  va_list args;
  va_start(args, fmt);
  hxtMessageGeneral(HXT_MSGLEVEL_TRACE, func, file, line, encodingIssue, hxtGetStatusString(status), fmt, args);
  va_end(args);
  return status;
}
#endif
