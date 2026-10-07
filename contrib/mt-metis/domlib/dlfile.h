/**
 * @file dlfile.h
 * @brief File function prototypes and error types
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DL_FILE_H
#define DL_FILE_H




#include "domlib.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct file_t {
  FILE * fd;
  fpos_t pos;
  int marked;
  const char * path;
} file_t;


typedef enum dl_fileerrors_t {
  DL_FILE_SUCCESS = 0x01,
  DL_FILE_BAD_PARAMETERS = 0x10,
  DL_FILE_PATH_ACCESS_DENIED = 0x20,
  DL_FILE_PATH_PARSE_FAILURE = 0x21,
  DL_FILE_PATH_BAD = 0x22,
  DL_FILE_FILENOTFOUND = 0x23,
  DL_FILE_READ_ACCESS_DENIED = 0x30,
  DL_FILE_WRITE_ACCESS_DENIED = 0x31,
  DL_FILE_READ_ERROR = 0x32,
  DL_FILE_WRITE_ERROR = 0x33,
  DL_FILE_OPEN_ERROR = 0x34,
  DL_FILE_CLOSE_ERROR = 0x35,
  DL_FILE_UNKNOWN_ERROR = 0xFFFF
} dl_fileerrors_t;



/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


int dl_check_file(
    const char * filename, 
    const char * mode);


int dl_open_file(
    const char * filename, 
    const char * mode, 
    file_t ** r_file);


int dl_mark_file(
    file_t * file);


int dl_restore_file(
    file_t * file);


int dl_close_file(
    file_t * file);


int dl_reset_file(
    file_t * file);


int dl_fprintf(
    const file_t * file,
    const char * fmt,
    ...);


ssize_t dl_get_next_line(
    file_t * fin, 
    char ** buffer, 
    size_t * bufsize);


ssize_t dl_get_ne_str(
    const char * str);


ssize_t dl_get_ne_next_line(
    file_t * fin, 
    char ** buffer, 
    size_t * bufsize);




#endif
