#ifndef __HXT_OPT_H__
#define __HXT_OPT_H__

#include "hxt_tools.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HXTOptListStruct HXTOptList;
typedef struct HXTOptProgramStruct HXTOptProgram;

/************** new option parsing method ******************

  ## the program is detailed into a HXTOptProgram.
  HXTOptProgram* program;
  HXT_CHECK( hxtOptProgCreate(&program, 
                "Usage: mon_programme [options]",                      ## a usage line for Help
                "mon_programme is a programme that doesn't do much",   ## a description of the program
                "Example:\n    mon_programme --coucou=David"           ## Examples, contact information etc.
           ) );

  ## then, we will add each possible options to this program
  ## each options is detailed into a HXTOpt:
  HXTOpt myOpt = {
         "cC",     ## short option names (each character is a short name => '-c' and '-C' refer to this option)
         "coucou", ## long option name   (a unique long name             => '--coucou' refers to this option)

         "Prints coucou c to the screen\n" ## a description of this option
         "Not usefull at all but funny",   ## can span multiple lines (no comma on the previous line)

         coucouCallBack, ## a callback function called everytime the program is called
                         ## the prototype of 'coucouCallBack' must be:
                         ##     HXTStatus coucouCallBack(HXTOpt* opt, void* state);
                         ## the option given will be 'myOpt'.
                         ## the state is a pointer that we give to the parsing function

         "YOUR_NAME",    ## the name of the argument to show in Help
                         ## here Help will show: 
                         ## -c, -C, --coucou=YOUR_NAME   Prints coucou YOUR_NAME to the screen

         ARG_REQUIRED,   ## one of ARG_NONE, ARG_REQUIRED, ARG_OPTIONAL and ARG_NON_NULL_REQUIRED
                         ## specify if an argument is required (see ARG_REQUIREMENT section)

         ARG_STRING,     ## the type of the argument as described below (ARG_TYPE section)
         
         {.string="Joe"} ## a default value for the argument (uneeded here as the argument is required...)
     };

  ##then we add the option to the program:
  HXT_CHECK( hxtOptProgAddOption(program, myOpt) );

  ## Once all options are added, we can parse the argument.
  ## The function will automatically return the status and print Help on errors

  void* state = NULL;  ## this pointer will be given to each callback functions
  int optind=0;        ## this integer will contain the number of string processed in argv
  HXT_OPT_MAIN_PARSE(program, argc, argv, NULL, &optind );

  ## you can now use the argument provided by the user safely
  printf(" Coucou %s !!!", myOpt.string);

  ## and delete the program structure
  HXT_CHECK( hxtOptProgDelete(program) );

*/


/****************************************************************************************
 *  ARG_REQUIREMENT : specify if an argument is required to follow the option
 ***************************************************************************************/
typedef enum {
  ARG_NONE=0,     /* no argument, the union value is incremented at each call */
  ARG_REQUIRED=1, /* argument required, the union value is the value of the argument */
  ARG_OPTIONAL=2, /* optional argument, the union value is:
                      - the value of the argument if there is an argument
                      - INT64_MIN for integers type
                      - NAN for floating point type if there was no argument
                      - "\a" for string types
                      */
  ARG_NON_NULL_REQUIRED=3  /* argument is required and the option should be non-null
                              at end of parsing */
} ARG_REQUIREMENT;


/****************************************************************************************
 *  ARG_TYPE: the accepted values of the possible argument
 * (use whatever you want if argRequirement==ARG_NONE)
 ***************************************************************************************/
typedef enum {
  // a positive value N means an integer between 0 and N included
  ARG_POSITIVE_INT32=INT32_MAX,

  /* Integer value types (stored in opt.integer) */
  ARG_INT64=0,    // an integer, whatever fits in a int64_t
  ARG_POSITIVE_INT64=-1,
  ARG_INT32=-2, // the value is checked to fit in a int32_t
  ARG_UINT32=-3,// the value is checked to fit in a uint32_t

  /* Floating value types (stored in opt.real)   */
  ARG_DOUBLE=-4,// a double value, whatever fits in a double
  ARG_FLOAT=-5, // the value is checked to fit in a float
  ARG_POSITIVE_FLOAT=-6, // the value is checked to fit in a float and be positive
  ARG_POSITIVE_DOUBLE=-7,// the value is checked to fit in a double and be positive

   /* String value type (stored in opt.string)    */
  ARG_STRING=-8
} ARG_TYPE;



typedef struct HXTOptStruct{
  const char* const shorts;
  const char* const longs;
  const char* const description;
  HXTStatus (*const cb)(struct HXTOptStruct* arg, void* state);
  const char* const argName;
  const ARG_REQUIREMENT argRequirement;
  const int argType;
//  struct {
    int64_t     integer;
    double      real;
    const char* string;
//  }
}HXTOpt;






HXTStatus hxtOptProgCreate(HXTOptProgram** program_ptr,
                           const char* usage_line,
                           const char* start_description,
                           const char* end_description);


HXTStatus hxtOptProgAddOption(HXTOptProgram* program,
                              HXTOpt* opt);


HXTStatus hxtOptProgParse(HXTOptProgram* program,
                          const int argc, char* argv[],
                          void* state,
                          int* optind);


#define HXT_OPT_MAIN_PARSE(program, argc, argv, state, optind_ptr)               \
  do {                                                                           \
    char help[16384];                                                            \
    hxtOptProgGetHelp(program, help);                                            \
    HXTStatus _status = hxtOptProgParse(program, argc, argv, NULL, optind_ptr ); \
    if(_status!=HXT_STATUS_OK){                                                  \
      HXT_TRACE(_status);                                                        \
      puts("\n  ==> Help on Error\n\n                              ---\n\n");    \
      *optind_ptr=-1;                                                            \
    }                                                                            \
    if(*optind_ptr==-1) {                                                        \
      printf("%s", help);                                                        \
      HXT_CHECK( hxtOptProgDelete(program) );                                    \
      return _status;                                                            \
    }                                                                            \
  }while(0)

HXTStatus hxtOptCalledWithoutArg(HXTOpt* opt);

HXTStatus hxtOptProgGetHelp(HXTOptProgram* program, char text[16384]);

HXTStatus hxtOptProgDelete(HXTOptProgram* program);


static inline HXTStatus hxtOptProgAddOptionArray(HXTOptProgram* program,
                                                 HXTOpt* opt, int n) {
  for (int i=0; i<n; i++) { HXT_CHECK( hxtOptProgAddOption(program, &opt[i]) ); }
  return HXT_STATUS_OK;
}

#ifdef __cplusplus
}
#endif

#endif
