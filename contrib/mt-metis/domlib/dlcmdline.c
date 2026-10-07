/**
 * @file dlcmdline.c
 * @brief Functions for parseing command line arguemnts
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DL_CMDLINE_C
#define DL_CMDLINE_C




#include "dlcmdline.h"




/******************************************************************************
* STATIC VARIABLES ************************************************************
******************************************************************************/


static const char * const __DELIM = "=";
static const char __ARGPREFIX = '-';
static const size_t __BASE_NARGS = 32;
static const int __NULLID = -1;
static const char * __STRYES[] = {"yes","Yes","YES","true",
  "True","TRUE","on","On","ON","1"};
static const size_t __NSTRYES = 10;
static const char * __ARGVALUES[] = {
  [CMD_OPT_CHOICE] = "string",
  [CMD_OPT_STRING] = "string",
  [CMD_OPT_BOOL] = "yes/no",
  [CMD_OPT_INT] = "int",
  [CMD_OPT_FLOAT] = "decimal",
  [CMD_OPT_FLAG] = NULL,
  [CMD_OPT_XARG] = NULL,
  [CMD_OPT_NULL] = NULL 
};




/******************************************************************************
* MEMORY FUNCTIONS ************************************************************
******************************************************************************/


#define DLMEM_PREFIX cmd_opt
#define DLMEM_TYPE_T cmd_opt_t
#define DLMEM_TYPE DLTYPE_STRUCT
#define DLMEM_INITFUNCTION init_cmd_opt
#include "dlmem_funcs.h"
#undef DLMEM_INITFUNCTION
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T

#define DLMEM_PREFIX cmd_arg
#define DLMEM_TYPE_T cmd_arg_t
#define DLMEM_TYPE DLTYPE_STRUCT
#define DLMEM_INITFUNCTION init_cmd_arg
#include "dlmem_funcs.h"
#undef DLMEM_INITFUNCTION
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static size_t __split(
    char const * str, 
    char const * delim, 
    char const ** back)
{
  size_t i,j,k;
  k = j = 0;
  *back = NULL;
  for (i=0;str[i] != '\0';++i) {
    if (str[i] == delim[j]) {
      ++j;
    } else {
      j = 0;
      k = i+1;
    }
    if (delim[j] == '\0') {
      /* we matched the whole delimeter */
      *back = str+i+1; 
      break;
    }
  }
  if (*back) {
    return k;
  } else {
    return i;
  }
}


static int __parse_parameter(
    cmd_opt_t const opt, 
    char const * const str, 
    cmd_arg_t * const arg)
{
  size_t l;
  char * eptr;

  switch (arg->type) {
    case CMD_OPT_CHOICE:
      /* match the parameter */
      for (l=0;l<opt.nvals;++l) {
        if (strcmp(str,opt.vals[l].str) == 0) {
          arg->val.o = opt.vals[l].val;
          break;
        }
      }
      if (l == opt.nvals) {
        eprintf("Invalid parameter '%s' for '%c/%s'\n",str,opt.sflag,
            opt.lflag);
        return DL_CMDLINE_BAD_PARAMETER;
      }
      break;
    case CMD_OPT_STRING:
      /* the shell should handle quoted strings */
      arg->val.s = str;
      break;
    case CMD_OPT_INT:
      arg->val.i = strtoll(str,(char**)&eptr,10);
      if (str == eptr) {
        eprintf("Invalid integer '%s' for '%c/%s'\n",str,opt.sflag,opt.lflag);
        return DL_CMDLINE_BAD_PARAMETER;
      }
      break;
    case CMD_OPT_FLOAT:
      arg->val.f = strtod(str,(char**)&eptr);
      if (str == eptr) {
        eprintf("Invalid number '%s' for '%c/%s'\n",str,opt.sflag,opt.lflag);
        return DL_CMDLINE_BAD_PARAMETER;
      }
      break;
    case CMD_OPT_BOOL:
      for (l=0;l<__NSTRYES;++l) {
        if (strcmp(__STRYES[l],str) == 0) {
          break;
        }
      }
      arg->val.b = (l < __NSTRYES);
      break;
    default:
      dl_error("Unknown command type '%d'\n",arg->type);
  }
  return DL_CMDLINE_SUCCESS;
}



/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


cmd_opt_t * init_cmd_opt(
    cmd_opt_t * cmd_opt)
{
  cmd_opt->id = __NULLID;
  cmd_opt->sflag = '\0';
  cmd_opt->lflag = NULL;
  cmd_opt->desc = NULL;
  cmd_opt->type = CMD_OPT_NULL; 
  cmd_opt->vals = NULL;
  cmd_opt->nvals = 0;
  return cmd_opt;
}


cmd_arg_t * init_cmd_arg(
    cmd_arg_t * cmd_arg)
{
  cmd_arg->id = __NULLID;
  cmd_arg->type = CMD_OPT_NULL;
  cmd_arg->val.i = 0;
  return cmd_arg;
}


int cmd_parse_args(
    size_t const argc, 
    char ** argv, 
    cmd_opt_t const * const opts, 
    size_t const nopts, 
    cmd_arg_t ** const r_args, 
    size_t * const r_nargs)
{
  int parse;
  size_t i,j,len,nargs,argn,maxnargs;
  char c;
  const char *sptr, *stropt;
  cmd_arg_t arg;
  cmd_arg_t * args;
  int error;

  maxnargs = __BASE_NARGS;
  args = cmd_arg_alloc(maxnargs);

  nargs = 0;
  for (i=0;i<argc;++i) {
    sptr = argv[i];
    len = strlen(sptr);
    if (len == 0) {
      eprintf("Encountered bad argument '%s'\n",sptr);
      error = DL_CMDLINE_BAD_ARGUMENT;
      goto CLEANUP;
    } else if (len == 1) {
      /* must be an xarg */
      arg.type = CMD_OPT_XARG;
      arg.id = -1;
      arg.val.s = sptr;
    } else {
      if (*sptr == __ARGPREFIX) {
        ++sptr;
        /* start of an argument */
        if (*sptr == __ARGPREFIX) {
          ++sptr;
          /* start of a long cmd args */
          argn = __split(sptr,__DELIM,&stropt);
          for (j=0;j<nopts;++j) {
            if (strlen(opts[j].lflag) == argn && \
                strncmp(sptr,opts[j].lflag,argn) == 0) {
              arg.id = opts[j].id;
              arg.type = opts[j].type;
              if (arg.type == CMD_OPT_FLAG) {
                /* we've already flagged it -- do nothing */
                if (stropt != NULL) {
                  /* they gave us an option for a flag -- panick */
                  eprintf("Extra parameter '%s' for '%.*s'\n",stropt, \
                      (int)argn,sptr);
                  error = DL_CMDLINE_EXTRA_PARAMETER;
                  goto CLEANUP;
                }
              } else {
                if (stropt == NULL) {
                  /* missing parameter */
                  eprintf("Missing parameter for '%.*s'\n",(int)argn,sptr);
                  error = DL_CMDLINE_MISSING_PARAMETER;
                  goto CLEANUP;
                }
                parse = __parse_parameter(opts[j],stropt,&arg);
                if (parse != DL_CMDLINE_SUCCESS) {
                  error = parse;
                  goto CLEANUP;
                }
              }
              break;
            }
          }
          if (j == nopts) {
            eprintf("Unknown argument '%.*s'\n",(int)argn,sptr);
            error = DL_CMDLINE_UNKNOWN_ARGUMENT;
            goto CLEANUP;
          }
        } else {
          /* start of short cmd args */
          while ((c = *(sptr++)) != '\0') {
            /* this is ugly, but handle multiple args smushed togethor */
            if (sptr[-2] != '-') {
              if (nargs == maxnargs) {
                maxnargs *= 2;
                args = cmd_arg_realloc(args,maxnargs);
              }
              args[nargs++] = arg;
            }
            /* parse the arg */
            for (j=0;j<nopts;++j) {
              if (c == opts[j].sflag) {
                arg.id = opts[j].id;
                arg.type = opts[j].type;
                if (arg.type == CMD_OPT_FLAG) {
                  /* we've already flagged it -- do nothing */
                } else {
                  if (sptr[0] == '\0') {
                    /* the argument is specified with a space */
                    ++i;
                    if (i < argc) {
                      sptr = argv[i];
                    } else {
                      eprintf("Missing parameter for '%c'\n",c);
                      error = DL_CMDLINE_MISSING_PARAMETER;
                      goto CLEANUP;
                    }
                  } else  {
                    /* the argument is specified without a space */
                  }
                  parse = __parse_parameter(opts[j],sptr,&arg);
                  if (parse != DL_CMDLINE_SUCCESS) {
                    error = parse;
                    goto CLEANUP;
                  }
                  goto ENDBUNCH;
                }
                break;
              }
            }
            if (j == nopts) {
              eprintf("Unknown argument '%c'\n",c);
              error = DL_CMDLINE_UNKNOWN_ARGUMENT;
              goto CLEANUP;
            }
          }
          ENDBUNCH:;
        }
      } else {
        /* its an xarg */
        arg.type = CMD_OPT_XARG;
        arg.id = -1;
        arg.val.s = sptr;
      }
    }
    if (nargs == maxnargs) {
      maxnargs *= 2;
      args = cmd_arg_realloc(args,maxnargs);
    }
    args[nargs++] = arg;
  }
  *r_args = args;
  *r_nargs = nargs;
  return DL_CMDLINE_SUCCESS;

  /* if something went wrong, free the memory and return null */
  CLEANUP:
  if (args) {
    dl_free(args);
  }
  *r_nargs = 0;
  *r_args = NULL;
  return error;
}


void fprint_cmd_opts(
    FILE * out, 
    cmd_opt_t const * opts, 
    size_t const nopts)
{
  size_t i,j;
  const char * fmt;
  for (i=0;i<nopts;++i) {
    if ((fmt = __ARGVALUES[opts[i].type]) == NULL) {
      if (opts[i].sflag != '\0') {
        /* has short option */
        fprintf(out,"%c%c ",__ARGPREFIX,opts[i].sflag);
      }
      fprintf(out,"%c%c%s :\n",__ARGPREFIX,__ARGPREFIX,opts[i].lflag);
    } else {
      if (opts[i].sflag != '\0') {
        /* has short option */
        fprintf(out,"%c%c<%s> ",__ARGPREFIX,opts[i].sflag,fmt);
      }
      fprintf(out,"%c%c%s=<%s> :\n",__ARGPREFIX,__ARGPREFIX,opts[i].lflag,fmt);
    }
    fprintf(out,"%s\n",opts[i].desc);
    if (opts[i].type == CMD_OPT_CHOICE) {
      fprintf(out,"Valid Options:\n");
      for (j=0;j<opts[i].nvals;++j) {
        fprintf(out,"\t%s : %s\n",opts[i].vals[j].str,opts[i].vals[j].desc);
      }
    }
    fprintf(out,"\n");
  }
}


#endif
