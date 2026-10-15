/**
 * @file dlcmdline.h
 * @brief Command-line parsing types and function prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DL_CMDLINE_H
#define DL_CMDLINE_H




#include "domlib.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef enum cmd_opt_type_t {
  CMD_OPT_CHOICE,
  CMD_OPT_STRING,
  CMD_OPT_BOOL,
  CMD_OPT_INT,
  CMD_OPT_FLOAT,
  CMD_OPT_FLAG,
  CMD_OPT_XARG,
  CMD_OPT_NULL
} cmd_opt_type_t;


typedef struct cmd_opt_pair_t {
  const char * str;
  const char * desc;
  int val;
} cmd_opt_pair_t;


typedef struct cmd_opt_t {
  ssize_t id;
  char sflag;
  const char * lflag;
  const char * desc;
  cmd_opt_type_t type;
  const cmd_opt_pair_t * vals; 
  size_t nvals;
} cmd_opt_t;


typedef struct cmd_arg_t {
  ssize_t id;
  cmd_opt_type_t type;
  union {
    long long int i;
    double f;
    const char * s;
    int b;
    int o;
  } val;
} cmd_arg_t;


typedef enum dl_cmdline_error_t {
  DL_CMDLINE_SUCCESS,
  DL_CMDLINE_BAD_ARGUMENT,
  DL_CMDLINE_UNKNOWN_ARGUMENT,
  DL_CMDLINE_MISSING_PARAMETER,
  DL_CMDLINE_EXTRA_PARAMETER,
  DL_CMDLINE_BAD_PARAMETER
} dl_cmdline_error;


/******************************************************************************
* MEMORY HEADERS **************************************************************
******************************************************************************/


#define DLMEM_PREFIX cmd_opt
#define DLMEM_TYPE_T cmd_opt_t
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T

#define DLMEM_PREFIX cmd_arg
#define DLMEM_TYPE_T cmd_arg_t
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


/**
 * @brief Initialization function for the cmd_opt_t structure. Initialization
 * involves zeroing out all fields.
 *
 * @param cmd_opt The structure to initialize.
 *
 * @return The initialized structure.
 */
cmd_opt_t * init_cmd_opt(cmd_opt_t * cmd_opt);


/**
 * @brief Initialization function for the cmd_arg_t structure. Initialization
 * involves zeroing otu all fields.
 *
 * @param cmd_arg The structure to initialize.
 *
 * @return The initialized structure.
 */
cmd_arg_t * init_cmd_arg(cmd_arg_t * cmd_arg);


/**
 * @brief Parse the command line options passed to the main function and place
 * them in cmd_arg_t structures for processing. 
 *
 * @param argc The number of command line arguments. 
 * @param argv The command line arguments.
 * @param opts The command line options to match against.
 * @param nopts The size of the opts array.
 * @param args The parsed aguments.
 * @param nargs The number of parsed arguments.
 *
 * @return DL_CMDLINE_SUCCESS unless an error in parsing occurs.  
 */
int cmd_parse_args(size_t argc, char ** argv, const cmd_opt_t * opts, 
    size_t nopts, cmd_arg_t ** args, size_t * nargs);


/**
 * @brief This function generates and prints the helpfile associated with the
 * passed in command line options.
 *
 * @param out The file stream to print to.
 * @param opts The options array to print.
 * @param nopts The size of the options array.
 */
void fprint_cmd_opts(FILE * out, const cmd_opt_t * opts, size_t nopts);




#endif
