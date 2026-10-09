/**
 * @file dlenv.c
 * @brief Functions for getting and setting environment variables
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DL_ENV_C
#define DL_ENV_C




#include "dlenv.h"




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


const char * dl_get_env_string(const char * const name, const char * const def)
{
  const char * const env = getenv(name);
  if (env == NULL) {
    return def;
  } else {
    return env;
  }
}


int dl_get_env_bool(const char * name, int def)
{
  const char * const env = getenv(name);
  if (env == NULL) {
    return def;
  } else if (memchr("tTyY1\0",env[0],6) != NULL) {
    return 1;
  } else {
    return 0;
  }
}


ssize_t dl_get_env_int(const char * name, ssize_t def)
{
  ssize_t res;
  char * endptr;
  const char * const env = getenv(name);
  if (env == NULL) {
    return def;
  } else {
    res = (ssize_t)strtoll(env,&endptr,10);
    /* if somebody put something stupid in there */
    if (endptr == env) {
      return def;
    } else {
      return res;
    }
  }
}


double dl_get_env_float(const char * name, double def)
{
  double res;
  char * endptr;
  const char * const env = getenv(name);
  if (env == NULL) {
    return def;
  } else {
    res = strtod(env,&endptr);
    /* if somebody put something stupid in there */
    if (endptr == env) {
      return def;
    } else {
      return res;
    }
  }
}



#endif
