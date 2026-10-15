/**
 * @file dlenv.h
 * @brief Function prototypes for getting and setting environment variables
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DL_ENV_H
#define DL_ENV_H




#include "domlib.h"




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


const char * dl_get_env_string(const char * name, const char * def);


int dl_get_env_bool(const char * name, int def);


ssize_t dl_get_env_int(const char * name, ssize_t def);


double dl_get_env_float(const char * name, double def);




#endif
