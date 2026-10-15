/**
 * @file dlfile.c
 * @brief Functions for opening, reading, and writing files
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DL_FILE_C
#define DL_FILE_C




#include <stdarg.h>
#include "dlfile.h"




#ifdef __GNU_SOURCE
  #define fgets fgets_unlocked
#endif




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static int __read_chunk(
    char * buffer, 
    size_t bufsize, 
    file_t * const fin)
{
  char * tmpstr;

  DL_ASSERT(buffer != NULL,"Null buffer passed to internal function '%s'",
      __func__);
  DL_ASSERT(bufsize > 0,"Buffer of size 0 passed to internal function '%s'",
      __func__);

  tmpstr = fgets(buffer,bufsize,fin->fd);

  /* see if something went wrong */
  if (tmpstr == NULL) {
    if (feof(fin->fd)) {
      return 0; 
    } else if (ferror(fin->fd)) {
      dl_error("Error while reading from file stream\n");
    }
  }

  return 1;
}


static int __is_fupdate(const char * const mode, const size_t len)
{
  size_t i;
  for (i=0;i<len;++i) {
    if (mode[i] == '+') {
      return 1;
    }
  }
  return 0;
}


static int __is_fread(const char * const mode, const size_t len)
{
  if (len > 0 && mode[0] == 'r') {
    /* only valid if it starts with an 'r' */
    return 1;
  }
  return 0;
}


static int __is_fwrite(const char * const mode, const size_t len)
{
  if (len > 0 && (mode[0] == 'w' || mode[0] == 'a')) {
    /* only valid if it starts with an 'r' */
    return 1;
  }
  return 0;
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


int dl_check_file(
    const char * const filename, 
    const char * const mode)
{
  int pread, pwrite, pupdate, bmode;
  size_t len;

  if ((len = strlen(mode)) > 3) {
    return DL_FILE_BAD_PARAMETERS;
  }

  pupdate = __is_fupdate(mode,len);
  pread = pupdate || __is_fread(mode,len);
  pwrite = pupdate || __is_fwrite(mode,len);

  bmode = F_OK;
  if (pread) {
    bmode |= R_OK;
  } 
  if (pwrite) {
    bmode |= W_OK;
  }

  if (access(filename,bmode) == -1)  {
    switch (errno) {
      case EACCES:
        return DL_FILE_PATH_ACCESS_DENIED;
      case ELOOP:
      case ENAMETOOLONG:
        return DL_FILE_PATH_PARSE_FAILURE;
      case ENOENT:
        if (pread) {
          return DL_FILE_FILENOTFOUND;
        } else {
          /* should work */
          break;
        }
      case ENOTDIR:
        return DL_FILE_PATH_BAD;
      default:
        return DL_FILE_UNKNOWN_ERROR;
    }
  }

  return DL_FILE_SUCCESS;
}


int dl_open_file(
    const char * const filename, 
    const char * const mode, 
    file_t ** const r_file) 
{
  int rv;

  if ((rv = dl_check_file(filename,mode)) != DL_FILE_SUCCESS) {
    return rv;
  }

  file_t * file = (file_t*)malloc(sizeof(*file));

  file->marked = 0;
  file->path = filename;
  file->fd = fopen(filename,mode); 

  if (file->fd == NULL) {
    dl_free(file);
    return DL_FILE_OPEN_ERROR;    
  }

  *r_file = file;
  return DL_FILE_SUCCESS;
}


int dl_close_file(
    file_t * file) 
{
  int rv;

  if (fclose(file->fd) == EOF) {
    rv = DL_FILE_CLOSE_ERROR;
  } else {
    rv = DL_FILE_SUCCESS;
  }

  dl_free(file);

  return rv;
}


int dl_mark_file(
    file_t * const file)
{
  int rv;

  if (fgetpos(file->fd,&file->pos) != 0) {
    rv = DL_FILE_UNKNOWN_ERROR;
  } else {
    file->marked = 1;
    rv = DL_FILE_SUCCESS;
  }

  return rv;
}


int dl_restore_file(
    file_t * const file)
{
  int rv;

  if (fsetpos(file->fd,&file->pos) != 0) {
    rv = DL_FILE_UNKNOWN_ERROR;
  } else {
    rv = DL_FILE_SUCCESS;
  }

  return rv;
}


int dl_reset_file(
    file_t * const file) 
{
  if (fseek(file->fd,0,SEEK_SET) != 0) {
    switch (errno) {
      default:
        return DL_FILE_UNKNOWN_ERROR;
    }
  }
  return DL_FILE_SUCCESS;
}



int dl_fprintf(
    const file_t * const file,
    const char * const fmt,
    ...)
{
  int rv;

  va_list args;
  va_start(args,fmt);

  rv = vfprintf(file->fd,fmt,args);

  va_end(args);

  return rv;
}


/**
* @brief Read a whole line from a file given a buffer and its
* size. If the line is longer than the buffer, it is reallocated and bufsize
* is changed.
*
* @param fin The file pointer
* @param buffer The buffer to store the data in (should be of lenghth at least
* 2 or should be NULL).
* @param bufsize The size of the buffer passed in
*
* @return The length of the line (not including the null character at the end).
*/
ssize_t dl_get_next_line(
    file_t * const fin, 
    char ** buffer, 
    size_t * bufsize)
{
  ssize_t i;
  size_t buffersize;
  char * str;

  if (*buffer == NULL) {
    *bufsize = 0x1000;
    *buffer = char_alloc(*bufsize);
  }

  str = *buffer;
  buffersize = *bufsize;
  i = 0;

  while (__read_chunk(str,buffersize-(str-(*buffer)),fin) &&
        (i = strlen(*buffer)) >= ((ssize_t)buffersize)-1 &&
        (*buffer)[buffersize-2] != '\n') {
    *bufsize = buffersize *= 2;
    *buffer = char_realloc(*buffer,buffersize);
    str = (*buffer) + i;
  }

  /* cap the string with null over the newline */
  if (i > 0 && (*buffer)[i-1] == '\n') {
    (*buffer)[i-1] = '\0';
  }

  return i -1;
}


ssize_t dl_get_ne_str(
    const char * const str)
{
  ssize_t ne = 0;
  const char * tok;
  int w;

  w = 0;

  tok = str;
  while (*tok != '\0') {
    if (*tok == ' ' || *tok == '\t' || *tok == '\n') {
      w = 0;
    } else {
      if (!w) {
        /* found the start of an element */
        ++ne;
      }
      w = 1;
    }
    ++tok;
  }
  
  return ne;
}


/**
 * @brief Reads the next line of the file and returns the number of words. This
 * function resets the position in the file when its finished.
 *
 * @param fin File pointer
 * @param buffer The character buffer to be read into
 * @param bufsize The size of the character buffer.
 *
 * @return The number of elmenents on the next line of the file, or -1 if there
 * is an error.
 */
ssize_t dl_get_ne_next_line(
    file_t * const fin, 
    char ** buffer, 
    size_t * bufsize)
{
  ssize_t i, linesize;

  if ((linesize = dl_get_next_line(fin,buffer,bufsize)) < 0) {
    return linesize;
  } else {
    i = dl_get_ne_str(*buffer);
    fseek(fin->fd,-linesize,SEEK_CUR);
    return i;
  }
}


#ifdef __GNU_SOURCE
  #undef fgets
#endif


#endif
