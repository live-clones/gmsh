// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_opt.h"
#include "hxt_tools.h"
#include <float.h>
#include <errno.h>
#include <limits.h>



const HXTOptionArgumentConstraints HXT_POSITIVE_RANGE = {
	0, DBL_MAX,
	0, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_ALPHA_LOWERCASE_RANGE = {
	-DBL_MAX, DBL_MAX,
	LLONG_MIN, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, HXT_ALPHA_LOWERCASE_CHARACTERS
};
const HXTOptionArgumentConstraints HXT_ALPHA_UPPERCASE_RANGE = {
	-DBL_MAX, DBL_MAX,
	LLONG_MIN, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, HXT_ALPHA_UPPERCASE_CHARACTERS
};
const HXTOptionArgumentConstraints HXT_ALPHA_RANGE = {
	-DBL_MAX, DBL_MAX,
	LLONG_MIN, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, HXT_ALPHA_CHARACTERS
};
const HXTOptionArgumentConstraints HXT_NUMERIC_RANGE = {
	-DBL_MAX, DBL_MAX,
	LLONG_MIN, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, HXT_NUMERIC_CHARACTERS
};
const HXTOptionArgumentConstraints HXT_ALPHANUMERIC_LOWERCASE_RANGE = {
	-DBL_MAX, DBL_MAX,
	LLONG_MIN, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, HXT_ALPHANUMERIC_LOWERCASE_CHARACTERS
};
const HXTOptionArgumentConstraints HXT_ALPHANUMERIC_UPPERCASE_RANGE = {
	-DBL_MAX, DBL_MAX,
	LLONG_MIN, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, HXT_ALPHANUMERIC_UPPERCASE_CHARACTERS
};
const HXTOptionArgumentConstraints HXT_ALPHANUMERIC_RANGE = {
	-DBL_MAX, DBL_MAX,
	LLONG_MIN, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, HXT_ALPHANUMERIC_CHARACTERS
};
const HXTOptionArgumentConstraints HXT_PRINTABLE_VISIBLE_RANGE = {// between space and ~
	-DBL_MAX, DBL_MAX,
	LLONG_MIN, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, HXT_PRINTABLE_VISIBLE_CHARACTERS
};
const HXTOptionArgumentConstraints HXT_PRINTABLE_RANGE = {
	-DBL_MAX, DBL_MAX,
	LLONG_MIN, LLONG_MAX,
	0, ULLONG_MAX,
	NULL, NULL, HXT_PRINTABLE_CHARACTERS
};
const HXTOptionArgumentConstraints HXT_0_1_RANGE = {
	0., 1.,
	0, 1,
	0, 1,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_0_2_RANGE = {
	0., 2.,
	0, 2,
	0, 2,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_0_3_RANGE = {
	0., 3.,
	0, 3,
	0, 3,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_0_4_RANGE = {
	0., 4.,
	0, 4,
	0, 4,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_0_5_RANGE = {
	0., 5.,
	0, 5,
	0, 5,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_0_10_RANGE = {
	0., 10.,
	0, 10,
	0, 10,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_0_20_RANGE = {
	0., 20.,
	0, 20,
	0, 20,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_0_50_RANGE = {
	0., 50.,
	0, 50,
	0, 50,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_0_100_RANGE = {
	0., 100.,
	0, 100,
	0, 100,
	NULL, NULL, NULL
};
const HXTOptionArgumentConstraints HXT_0_1000_RANGE = {
	0., 1000.,
	0, 1000,
	0, 1000,
	NULL, NULL, NULL
};


typedef struct HXTOptionStruct {
  char shortName;
  const char* longName;
  const char* description;
  const HXTOptionArgumentConstraints* constraints;
  HXTOptionArgumentType valueType;
  void* valuePtr;
} HXTOption;

static HXTOption helpOption = {'h', "help", "Display this help message", NULL, HXT_FLAG, NULL};
static HXTOption* optionList = NULL;
static int optionListLength = 0;
static int optionListSize = 0;


#define MAX(a,b) (((a)>(b))?(a):(b))


static HXTStatus optionListReserve(int n)
{
	if(optionList==NULL) {
		optionListSize = MAX(16,n);
		HXT_CHECK( hxtMalloc(&optionList, optionListSize*sizeof(HXTOption)) );
		optionList[0] = helpOption;
		optionListLength = 1;
	}
	else if(optionListLength + n > optionListSize) {
		optionListSize = MAX(2*optionListSize, optionListLength + n);
		HXT_CHECK( hxtRealloc(&optionList, optionListSize*sizeof(HXTOption)) );
	}
	return HXT_STATUS_OK;
}


HXTStatus hxtAddOption(char shortName,
                       const char* longName,
                       const char* description,
                       HXTOptionArgumentType valueType,
                       const HXTOptionArgumentConstraints* constraints,
                       void* valuePtr)
{
	HXT_CHECK( optionListReserve(1) );

#ifndef NDEBUG
	if(valuePtr==NULL && (shortName!='\0' || longName!=NULL || description!=NULL))
		return HXT_ERROR_MSG(HXT_STATUS_ERROR, "Adding a non-empty option with a NULL value pointer makes no sense");
	for (int i=0; i<optionListLength; i++) {
		if(shortName!='\0' && shortName==optionList[i].shortName)
			return HXT_ERROR_MSG(HXT_STATUS_ERROR, "-%c is already the short name of another option", shortName);
	}
	if(longName!=NULL) {
		if(longName[0]=='\0')
			return HXT_ERROR_MSG(HXT_STATUS_ERROR, "Cannot use empty string as a long option name. Use NULL pointer if you do not want a long option name.");
		if(longName[0]=='-')
			return HXT_ERROR_MSG(HXT_STATUS_ERROR, "long option \"%s\" cannot begin with a '-'", longName);
		for (int i=0; longName[i]!='\0'; i++) {
			if(longName[i]<=' ')
				return HXT_ERROR_MSG(HXT_STATUS_ERROR, "long option \"%s\" should only contain printable characters", longName);
		}
		for (int i=0; i<optionListLength; i++) {
			if(optionList[i].longName!=NULL && strcmp(longName, optionList[i].longName)==0)
				return HXT_ERROR_MSG(HXT_STATUS_ERROR, "--%s is already the long name of another option", longName);
		}
	}
#endif

	if(shortName=='\0' && (longName==NULL || longName[0]=='\0') &&
	   (valueType==HXT_FLAG || valueType==HXT_NO_FLAG) && valuePtr!=NULL) {
		return HXT_ERROR_MSG(HXT_STATUS_ERROR, "A flag must have an option name. Therefore, it can not be a trailing option");
	}

	optionList[optionListLength].shortName = shortName;
	optionList[optionListLength].longName = longName;
	optionList[optionListLength].description = description;
	optionList[optionListLength].valueType = valueType;
	optionList[optionListLength].constraints = constraints;
	optionList[optionListLength].valuePtr = valuePtr;
	optionListLength++;

	return HXT_STATUS_OK;
}


/*********************************************************************
*  search a long option inside the list                              *
*********************************************************************/
static int searchLongOption(const char* string)
{
	for (int i=0; i<optionListLength; i++) {
		if(optionList[i].longName!=NULL &&
		   strcmp(optionList[i].longName, string)==0) {
			return i;
		}
	}

	return -1;
}


/*********************************************************************
*  search a short option inside the list                             *
*********************************************************************/
static int searchShortOption(char c)
{
	for (int i=0; i<optionListLength; i++) {
		if(c==optionList[i].shortName) {
			return i;
		}
	}
	return -1;
}


int fileExists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}


static const char* getArgTypeName(HXTOptionArgumentType t){
	switch(t) {
	case HXT_FLAG:
	case HXT_NO_FLAG:
		return "(none)";
    case HXT_DOUBLE:
    	return "a double";
    case HXT_FLOAT:
    	return "a float";
    case HXT_INT:
    	return "an integer ";
    case HXT_I64:
    	return "a 64-bit integer";
    case HXT_I32:
    	return "a 32-bit integer";
    case HXT_I16:
    	return "a 16-bit integer";
    case HXT_UNSIGNED:
    	return "an unsigned integer ";
    case HXT_U64:
    	return "a 64-bit unsigned integer";
    case HXT_U32:
    	return "a 32-bit unsigned integer";
    case HXT_U16:
    	return "a 16-bit unsigned integer";
    default:
		return "a string";
	}
}


/*********************************************************************
*  scan the argument and verify its validity                         *
*********************************************************************/
static HXTStatus doOption(HXTOption* opt,
	                      const char* arg,
	                      const char* optName)
{
	if(opt->valueType==HXT_FLAG) {
		*(int*) opt->valuePtr = 1;
		return HXT_STATUS_OK;
	}
	if(opt->valueType==HXT_NO_FLAG) {
		*(int*) opt->valuePtr = 0;
		return HXT_STATUS_OK;
	}

	char* endptr = NULL;
	double r = 0;
	unsigned long long u = 0;
	long long int i = 0;
	const char* s = NULL;

	int isDouble = 0, isInteger = 0, isUnsigned = 0;

	if(opt->valueType==HXT_DOUBLE || opt->valueType==HXT_FLOAT) {
		isDouble = 1;
		r = strtod(arg, &endptr);
	}
	else if(opt->valueType==HXT_INT ||
	        opt->valueType==HXT_I64 ||
	        opt->valueType==HXT_I32 ||
	        opt->valueType==HXT_I16) {
		isInteger = 1;
		i = strtoll(arg, &endptr, 10);
	}
	else if(opt->valueType==HXT_UNSIGNED ||
	        opt->valueType==HXT_U64 ||
	        opt->valueType==HXT_U32 ||
	        opt->valueType==HXT_U16) {
		isUnsigned = 1;
		u = strtoull(arg, &endptr, 10);
	}
	else {
		s = arg;
	}

	// verify the validity
	if(errno == ERANGE){
range_error:
		return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
		       "cannot convert argument \"%s\" of option \"%s\" to %s (range overflow)",
		       arg, optName, getArgTypeName(opt->valueType));
	}
	else if (arg == endptr)
	{
		return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
		       "cannot convert argument \"%s\" of option \"%s\" to %s (no digit)",
		       arg, optName, getArgTypeName(opt->valueType));
	}
	else if(endptr!=NULL && *endptr!='\0') {
		return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
		       "cannot convert argument \"%s\" of option \"%s\" to %s (trailing unvalid characters)",
		       arg, optName, getArgTypeName(opt->valueType));
	}

	// verify the conversion is possible
	switch(opt->valueType) {
	// floating point values:
		case HXT_DOUBLE:
			*(double*) opt->valuePtr = r;
			break;
	    case HXT_FLOAT:
		    if((float)r!=r) goto range_error;
		    *(float*) opt->valuePtr = r;
		    break;
	// integer values
	    case HXT_INT:
		    if((int)i!=i) goto range_error;
		    *(int*) opt->valuePtr = i;
		    break;
	    case HXT_I64:
		    if((int64_t)i!=i) goto range_error;
		    *(int64_t*) opt->valuePtr = i;
		    break;
	    case HXT_I32:
		    if((int32_t)i!=i) goto range_error;
		    *(int32_t*) opt->valuePtr = i;
		    break;
	    case HXT_I16:
		    if((int16_t)i!=i) goto range_error;
		    *(int16_t*) opt->valuePtr = i;
		    break;
	// unsigned integer values
	    case HXT_UNSIGNED:
		    if((unsigned)u!=u) goto range_error;
		    *(unsigned*) opt->valuePtr = u;
		    break;
	    case HXT_U64:
		    if((uint64_t)u!=u) goto range_error;
		    *(uint64_t*) opt->valuePtr = u;
		    break;
	    case HXT_U32:
		    if((uint32_t)u!=u) goto range_error;
		    *(uint32_t*) opt->valuePtr = u;
		    break;
	    case HXT_U16:
		    if((uint16_t)u!=u) goto range_error;
		    *(uint16_t*) opt->valuePtr = u;
		    break;
   // string values
		case HXT_EXISTING_FILENAME:
			if(!fileExists(s))
				return HXT_ERROR_MSG(HXT_STATUS_FILE_CANNOT_BE_OPENED,
				                     "file \"%s\" does not exist", s);
			*(const char**) opt->valuePtr = s;
			break;
		case HXT_NEW_FILENAME:
			if(fileExists(s))
				return HXT_ERROR_MSG(HXT_STATUS_FILE_CANNOT_BE_OPENED,
				                     "file \"%s\" already exists", s);
			*(const char**) opt->valuePtr = s;
			break;
		case HXT_ASK_TO_ERASE_FILENAME:
			if(fileExists(s)) {
				char memory[64];
				HXT_INFO("file \"%s\" already exists\n do you want to overwrite it ? y/N", s);
				char* string = fgets(memory, 64, stdin);
				if(string==NULL || (string[0]!='y' && string[0]!='Y') )
					return HXT_ERROR_MSG(HXT_STATUS_FILE_CANNOT_BE_OPENED, "aborting");
			}
			/* fall through */

		default:
			*(const char**) opt->valuePtr = s;
	    	break;
	}

	if(opt->constraints==NULL)
		return HXT_STATUS_OK;


	if(isDouble){
		if(r < opt->constraints->doubleMin || r > opt->constraints->doubleMax)
			return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
			                     "cannot convert argument \"%s\" of option \"%s\" "
			                     "to %s between %g and %g (range overflow)",
			                     arg, optName, getArgTypeName(opt->valueType),
								 opt->constraints->doubleMin, opt->constraints->doubleMax);
	}
	else if(isInteger){
		if(i < opt->constraints->intMin || i > opt->constraints->intMax)
			return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
			                     "cannot convert argument \"%s\" of option \"%s\" "
			                     "to %s between %lld and %lld (range overflow)",
			                     arg, optName, getArgTypeName(opt->valueType),
								 opt->constraints->intMin, opt->constraints->intMax);
	}
	else if(isUnsigned){
		if(u < opt->constraints->unsignedMin || u > opt->constraints->unsignedMax)
			return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
			                     "cannot convert argument \"%s\" of option \"%s\" "
			                     "to %s between %llu and %llu (range overflow)",
			                     arg, optName, getArgTypeName(opt->valueType),
								 opt->constraints->unsignedMin, opt->constraints->unsignedMax);
	}
	else {
		if(opt->constraints->stringPrefix!=NULL) {
			const char* prefix = opt->constraints->stringPrefix;
			size_t lenpre = strlen(prefix), lens = strlen(s);
			if(lens < lenpre || strncmp(prefix, s, lenpre) != 0)
				return HXT_ERROR_MSG(HXT_STATUS_ERROR, "argument \"%s\" of option \"%s\" is not prefixed by \"%s\"", arg, optName, prefix);
		}
		if(opt->constraints->stringSuffix!=NULL) {
			const char* suffix = opt->constraints->stringSuffix;
			size_t lensuf = strlen(suffix), lens = strlen(s);
			if(lens < lensuf || strcmp(suffix, s + lens - lensuf) != 0)
				return HXT_ERROR_MSG(HXT_STATUS_ERROR, "argument \"%s\" of option \"%s\" is not suffixed by \"%s\"", arg, optName, suffix);
		}
		if(opt->constraints->stringCharAllowed!=NULL) {
			const char* allowed = opt->constraints->stringCharAllowed;
			for (int j=0; s[j]!='\0'; j++) {
				int found = 0;
				int special = 0;
				if(opt->constraints==&HXT_ALPHA_LOWERCASE_RANGE
				|| opt->constraints==&HXT_ALPHA_RANGE
				|| opt->constraints==&HXT_ALPHANUMERIC_LOWERCASE_RANGE
				|| opt->constraints==&HXT_ALPHANUMERIC_RANGE) {
					special = 1;
					if(s[j]>='a' && s[j]<='z') found = 1;
				}
				if(opt->constraints==&HXT_ALPHA_UPPERCASE_RANGE
				|| opt->constraints==&HXT_ALPHA_RANGE
				|| opt->constraints==&HXT_ALPHANUMERIC_UPPERCASE_RANGE
				|| opt->constraints==&HXT_ALPHANUMERIC_RANGE) {
					special = 1;
					if(s[j]>='A' && s[j]<='Z') found = 1;
				}
				if(opt->constraints==&HXT_NUMERIC_RANGE
				|| opt->constraints==&HXT_ALPHANUMERIC_LOWERCASE_RANGE
				|| opt->constraints==&HXT_ALPHANUMERIC_UPPERCASE_RANGE
				|| opt->constraints==&HXT_ALPHANUMERIC_RANGE) {
					special = 1;
					if(s[j]>='0' && s[j]<='9') found = 1;
				}
				if(opt->constraints==&HXT_PRINTABLE_VISIBLE_RANGE
				|| opt->constraints==&HXT_PRINTABLE_RANGE) {
					special = 1;
					if(s[j]>' ' && s[j]<='~') found = 1;
				}
				if(opt->constraints==&HXT_PRINTABLE_RANGE) {
					special = 1;
					if(s[j]==' ' || s[j]=='\t' || s[j]=='\n') found = 1;
				}
				if(special!=1) {
					for (int k=0; allowed[k]!='\0'; k++) {
						if(s[j]==allowed[k]){
							found = 1;
							break;
						}
					}
				}
				
				if(found==0)
					return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR, "argument \"%s\" of option \"%s\" contain the unvalid character %c", s[j]);
			}
		}
	}

	return HXT_STATUS_OK;
}


static int getNextTrailingOption(int n) {
	for (int i=n+1; i<optionListLength; i++) {
		if(optionList[i].shortName=='\0' && optionList[i].longName==NULL) {
			return i;
		}
	}
	return -1;
}


HXTStatus hxtParseOptions(const int argc, char* argv[])
{
	int dashdash = 0;
	int trailing = getNextTrailingOption(0);
	for (int i=1; i<argc; i++) {
		const char *arg = NULL;
		HXTOption* opt = NULL;

		if(dashdash || argv[i][0]!='-' || (argv[i][0]=='-' && argv[i][1]=='\0')){
			if(trailing==-1 || optionList[trailing].valuePtr==NULL)
				return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
				                     "Additional argument \"%s\" does not correspond to any option",
				                     argv[i]);
			else
				HXT_CHECK( doOption(&optionList[trailing], argv[i], optionList[trailing].description) );

			trailing = getNextTrailingOption(trailing);
		}
		else if(argv[i][1]=='-') { /* long opt */
			if(argv[i][2]=='\0') /* -- terminate argument parsing,
			everything from now on is a trailing option */ {
				dashdash = 1;
				continue;
			}

			char* equalSign = strchr(argv[i]+2,'=');
			
			if(equalSign!=NULL){
				*equalSign = '\0';
				arg = equalSign + 1;
			}

			int num = searchLongOption(argv[i]+2);
			if(num<0){
				return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
				       "option \"%s\" not found", argv[i]);
			}
			opt = &optionList[num];

			if(equalSign!=NULL){
				*equalSign = '=';
				if(opt->valueType==HXT_FLAG || opt->valueType==HXT_NO_FLAG){
					return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
					       "option \"%s\" takes no argument", argv[i]);
				}
			}
			else{
				if(num==0) { // it's the help option
					return HXT_STATUS_INTERNAL;
				}
				if(opt->valueType!=HXT_FLAG && opt->valueType!=HXT_NO_FLAG) {
					if(argc<=i+1) {
						return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
					       "options \"%s\" requires an argument", argv[i]);
					}
					else {
						arg = argv[i+1];
						i++;
					}
				}
			}

			HXT_CHECK( doOption(opt, arg, argv[i]) );
		}
		else{ /* short option */
			int cond = argv[i][1];
			for(int j=1; cond; j++){
				int num = searchShortOption(argv[i][j]);
				if(num<0){
					return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
					       "option \'%c\' in \"%s\" not found", argv[i][j], argv[i]);
				}

				char optName[] = "- ";
				optName[1] = argv[i][j];
				cond = argv[i][j+1];

				if(num==0){
					return HXT_STATUS_INTERNAL;
				}

				opt = &optionList[num];

				if(opt->valueType!=HXT_FLAG && opt->valueType!=HXT_NO_FLAG){
					if(cond){
						arg = argv[i] + j+1;
						cond = 0; // stop the loop
					}
					else if(argc<=i+1) {
						return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
						       "options \'%c\' in \"%s\" requires an argument", argv[i][j], argv[i]);
					}
					else {
						arg = argv[i+1];
						i++;
					}
				}

				HXT_CHECK( doOption(opt, arg, optName) );
			}
		}
	}

	if(trailing!=-1) {
		if(getNextTrailingOption(trailing)!=-1)
			return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR, "No \"%s\" given", optionList[trailing].description);
	}

	HXT_CHECK( hxtFree(&optionList) );

	return HXT_STATUS_OK;
}


#define MY_SPRINTF(...) *offset+=snprintf(text+ *offset, 16384- *offset, ## __VA_ARGS__ )

static const char* getHelpValueName(HXTOption* opt) {
	switch(opt->valueType) {
    case HXT_DOUBLE:
    case HXT_FLOAT:
    return "VAL";
    case HXT_INT:
    case HXT_I64:
    case HXT_I32:
    case HXT_I16:
    case HXT_UNSIGNED:
    case HXT_U64:
    case HXT_U32:
    case HXT_U16:
    return "NUM";
    case HXT_STRING:
    return "TEXT";
    case HXT_EXISTING_FILENAME:
    case HXT_NEW_FILENAME:
    case HXT_ASK_TO_ERASE_FILENAME:
    return "FILENAME";
    default:
    return "(none)";
	}
}


static void printOptionLine(HXTOption* opt, char text[16384], int* offset)
{
	const int char_max = 30;
	int oldOffset = *offset;
	MY_SPRINTF("  ");

	if(opt->shortName!='\0'){
		if(opt->longName!=NULL){
			MY_SPRINTF("-%c, ", opt->shortName);
		}
		else{
			MY_SPRINTF("-%c", opt->shortName);
		}
	}

	if(opt->longName!=NULL){
		if(opt->valueType==HXT_FLAG || opt->valueType==HXT_NO_FLAG)
			MY_SPRINTF("--%s", opt->longName);
		else
			MY_SPRINTF("--%s=%s", opt->longName, getHelpValueName(opt));

		
	}

	int char_count = *offset - oldOffset;
	if(char_count<char_max)
		MY_SPRINTF("%*c", char_max - char_count, ' ');
	else
		MY_SPRINTF("\n%*c", char_max, ' ');

	// description
	{
		int i,k;
		for (i=0,k=0; opt->description[i+1]!='\0'; i++, k++) {
			if(opt->description[i]=='\n'){
				if(opt->description[i+1]=='\n' || opt->description[i+1]=='\0')
					MY_SPRINTF("%.*s\n", k, opt->description+i-k);
				else
					MY_SPRINTF("%.*s\n%*c", k, opt->description+i-k, char_max+2, ' ');
				k=-1;
			}
		}
		MY_SPRINTF("%s", opt->description+i-k);
	}

	// default argument
	if(opt->valueType!=HXT_FLAG && opt->valueType!=HXT_NO_FLAG)
	{
		double r = 0;
		unsigned long long u = 0;
		long long int i = 0;
		MY_SPRINTF("\n%*cdefault: %s=", char_max+1, ' ', getHelpValueName(opt));
		switch(opt->valueType) {
	    case HXT_DOUBLE:
	    MY_SPRINTF("%g", *(double*) opt->valuePtr);
	    break;
	    case HXT_FLOAT:
	    r = *(float*) opt->valuePtr;
	    MY_SPRINTF("%g", r);
	    break;
	    case HXT_INT:
		MY_SPRINTF("%d", *(int*) opt->valuePtr);
	    break;
	    case HXT_I64:
	    i = *(int64_t*) opt->valuePtr;
	    MY_SPRINTF("%lld", i);
	    break;
	    case HXT_I32:
	    i = *(int32_t*) opt->valuePtr;
	    MY_SPRINTF("%lld", i);
	    break;
	    case HXT_I16:
	    i = *(int16_t*) opt->valuePtr;
	    MY_SPRINTF("%lld", i);
	    break;
	    case HXT_UNSIGNED:
	    MY_SPRINTF("%u", *(unsigned*) opt->valuePtr);
	    break;
	    case HXT_U64:
	    u = *(uint64_t*) opt->valuePtr;
	    MY_SPRINTF("%llu", u);
	    break;
	    case HXT_U32:
	    u = *(uint32_t*) opt->valuePtr;
	    MY_SPRINTF("%llu", u);
	    break;
	    case HXT_U16:
	    u = *(uint16_t*) opt->valuePtr;
	    MY_SPRINTF("%llu", u);
	    break;
	    case HXT_STRING:
	    case HXT_EXISTING_FILENAME:
	    case HXT_NEW_FILENAME:
	    case HXT_ASK_TO_ERASE_FILENAME:
	    if(opt->valuePtr!=NULL)
	    	MY_SPRINTF("%s", *(const char**) opt->valuePtr);
	    break;
	    default:
	    break;
		}
	}

	MY_SPRINTF("\n");
}


HXTStatus hxtGetOptionHelp(char text[16384],
                           const char* programName,
                           const char* programDescription,
                           const char* additionalInfo)
{
	int offsetval = 0;
	int* offset = &offsetval;
	if(programName!=NULL) {
		MY_SPRINTF("Usage:  %s [OPTION]...", programName);
		int n = getNextTrailingOption(0);
		while(n!=-1 && optionList[n].valuePtr!=NULL) {
			int n2 = getNextTrailingOption(n);
			if(optionList[n].shortName=='\0' && optionList[n].longName==NULL && optionList[n].description!=NULL) {
				if(n2==-1)
					MY_SPRINTF(" [%s]", optionList[n].description);
				else
					MY_SPRINTF(" %s", optionList[n].description);
			}
			n=n2;
		}
	}

	if(programDescription!=NULL)
		MY_SPRINTF("\n\n%s", programDescription);
	MY_SPRINTF("\n\n");

	for (int i=0; i<optionListLength; i++) {
		if(optionList[i].shortName!='\0' || optionList[i].longName!=NULL)
			printOptionLine(&optionList[i], text, offset);
	}

	if(additionalInfo)
		MY_SPRINTF("%s\n", additionalInfo);
	return HXT_STATUS_OK;
}