// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef __HXT_OPT_H__
#define __HXT_OPT_H__

#include "hxt_message.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


/****************************************************************************************
 *  argument type: the type of the argument that must be given to the option
 * or HXT[_NO]_FLAG to indicate that the option doesn't have an argument
 ***************************************************************************************/
typedef enum {
// flags
  // no argument must be given, the value must be an integer set to 0 (it is set to 1 when option is called)
    HXT_FLAG,
  // no argument must be given, the value must be an integer set to 1 (it is set to 0 when option is called)
    HXT_NO_FLAG,

// floating point values:
    HXT_DOUBLE,
    HXT_FLOAT,

// integer values
    HXT_INT,
    HXT_I64,
    HXT_I32,
    HXT_I16,

// unsigned integer values
    HXT_UNSIGNED,
    HXT_U64,
    HXT_U32,
    HXT_U16,

// strings values
    HXT_STRING,
    HXT_EXISTING_FILENAME,
    HXT_NEW_FILENAME,
    HXT_ASK_TO_ERASE_FILENAME
} HXTOptionArgumentType;

/*************************************************************************************
 *  Constraints on the accepted range of the value given in argument                 *
 ************************************************************************************/
typedef struct {
  // acceptable range for floating-point values
  double doubleMin;
  double doubleMax;

  // acceptable range for integer values
  long long int intMin;
  long long int intMax;

  // acceptable range for unsigned integer values
  unsigned long long unsignedMin;
  unsigned long long unsignedMax;

  // required prefix and suffix to the string (NULL pointer are omitted)
  const char* stringPrefix;
  const char* stringSuffix;

  // character allowed, required or forbidden (NULL pointer are omitted)
  const char* stringCharAllowed;
} HXTOptionArgumentConstraints;

#define HXT_ALPHA_LOWERCASE_CHARACTERS        "abcdefghijklmnopqrstuvwxyz"
#define HXT_ALPHA_UPPERCASE_CHARACTERS        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define HXT_ALPHA_CHARACTERS                  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define HXT_NUMERIC_CHARACTERS                "0123456789"
#define HXT_ALPHANUMERIC_LOWERCASE_CHARACTERS "abcdefghijklmnopqrstuvwxyz0123456789"
#define HXT_ALPHANUMERIC_UPPERCASE_CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define HXT_ALPHANUMERIC_CHARACTERS  \
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define HXT_PRINTABLE_VISIBLE_CHARACTERS  \
    "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
#define HXT_PRINTABLE_CHARACTERS \
    "\t\n !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

// built-in hxtOptionArg
extern const HXTOptionArgumentConstraints HXT_POSITIVE_RANGE;

extern const HXTOptionArgumentConstraints HXT_ALPHA_LOWERCASE_RANGE;
extern const HXTOptionArgumentConstraints HXT_ALPHA_UPPERCASE_RANGE;
extern const HXTOptionArgumentConstraints HXT_ALPHA_RANGE;
extern const HXTOptionArgumentConstraints HXT_NUMERIC_RANGE;
extern const HXTOptionArgumentConstraints HXT_ALPHANUMERIC_LOWERCASE_RANGE;
extern const HXTOptionArgumentConstraints HXT_ALPHANUMERIC_UPPERCASE_RANGE;
extern const HXTOptionArgumentConstraints HXT_ALPHANUMERIC_RANGE;
extern const HXTOptionArgumentConstraints HXT_PRINTABLE_VISIBLE_RANGE;
extern const HXTOptionArgumentConstraints HXT_PRINTABLE_RANGE;

extern const HXTOptionArgumentConstraints HXT_0_1_RANGE;
extern const HXTOptionArgumentConstraints HXT_0_2_RANGE;
extern const HXTOptionArgumentConstraints HXT_0_3_RANGE;
extern const HXTOptionArgumentConstraints HXT_0_4_RANGE;
extern const HXTOptionArgumentConstraints HXT_0_5_RANGE;
extern const HXTOptionArgumentConstraints HXT_0_10_RANGE;
extern const HXTOptionArgumentConstraints HXT_0_20_RANGE;
extern const HXTOptionArgumentConstraints HXT_0_50_RANGE;
extern const HXTOptionArgumentConstraints HXT_0_100_RANGE;
extern const HXTOptionArgumentConstraints HXT_0_1000_RANGE;


HXTStatus hxtAddOption(char short_name,
                       const char* longName,
                       const char* description,
                       HXTOptionArgumentType valueType,
                       const HXTOptionArgumentConstraints* constraints,
                       void* valuePtr);

/* Trailing options are options without an option name.
 * the order in which they are added is important !
 * by default, the last trailing option is optional
 * you can add an empty trailing option (a trailing option with valuePtr==NULL) at the end to make the last trailing option required
 * example:
 *
 *    const char* input = NULL;
 *    HXT_CHECK(hxtAddTrailingOption("INPUT_MESH", HXT_EXISTING_FILENAME, NULL, &input));
 *
 *    // without the next line, the user would be allowed not giving an input mesh file in the command line
 *
 *    HXT_CHECK(hxtAddTrailingOption(NULL, 0, NULL, NULL));
 *
 *    // this empty trailing option option ensure that an input mesh file is required
*/
static inline HXTStatus hxtAddTrailingOption(
                      const char* argumentName, // name to use in the usage line ./program [Options] trailingArg1 trailingArg2 ...
                      HXTOptionArgumentType valueType,
                      const HXTOptionArgumentConstraints* constraints,
                      void* valuePtr)
{
  HXT_CHECK( hxtAddOption('\0', NULL, argumentName, valueType, constraints, valuePtr) );
  return HXT_STATUS_OK;
}

// use the HXT_PARSE_COMMAND_LINE macro instead
HXTStatus hxtGetOptionHelp(char message[16384],
                           const char* programName,
                           const char* programDescription,
                           const char* additionalInfo);

// use the HXT_PARSE_COMMAND_LINE macro instead
HXTStatus hxtParseOptions(const int argc, char* argv[]);

// This macro should be placed in the main, after all options are added !
#define HXT_PARSE_COMMAND_LINE(argc, argv, programName, programDescription, additionalInfo)   \
do{                                                                                           \
  char help[16384];                                                                           \
  HXTStatus status = hxtGetOptionHelp(help, programName, programDescription, additionalInfo); \
  if(status==HXT_STATUS_OK)                                                                   \
    status = hxtParseOptions(argc, argv);                                                     \
  if(status!=HXT_STATUS_OK && status!=HXT_STATUS_INTERNAL) {                                  \
    HXT_TRACE(status);                                                                        \
    puts("\n  ==> Help on Error\n\n                              ---\n");                     \
  }                                                                                           \
  if(status!=HXT_STATUS_OK) {                                                                 \
    printf("%s", help);                                                                       \
    return status!=HXT_STATUS_INTERNAL?status:0;                                              \
  }                                                                                           \
} while(0);


#ifdef __cplusplus
}
#endif

#endif
