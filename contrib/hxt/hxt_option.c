#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "hxt_option.h"

static HXTOpt help_option     = {"h", "help", "Display this help message"};

/*********************************************************************
*  program structure                                                 *
*********************************************************************/
struct HXTOptProgramStruct {
	const char* usage_line;
	const char* start_description;
	const char* end_description;
	HXTOpt** opts;
	size_t opt_length;
	size_t opt_capacity;
};


/*********************************************************************
*  Create a program                                                  *
*********************************************************************/
HXTStatus hxtOptProgCreate(HXTOptProgram** program_ptr,
			   const char* usage_line,
			   const char* start_description,
			   const char* end_description)
{
	HXT_ASSERT(program_ptr!=NULL);

	HXTOptProgram* program;
	HXT_CHECK( hxtMalloc(&program, sizeof(HXTOptProgram)) );
	*program_ptr = program;

	program->usage_line = usage_line;
	program->start_description = start_description;
	program->end_description = end_description;
	program->opts = NULL;
	program->opt_length = 0;
	program->opt_capacity = 0;

	hxtOptProgAddOption(program, &help_option);

	return HXT_STATUS_OK;
}


/*********************************************************************
*  add an option to a program                                        *
*********************************************************************/
HXTStatus hxtOptProgAddOption(HXTOptProgram* program, HXTOpt* opt)
{
	HXT_ASSERT( program!=NULL );
	HXT_ASSERT( opt!=NULL );

	if(program->opt_length >= program->opt_capacity){
		size_t newSize = program->opt_length?program->opt_length*2:16;
		HXT_CHECK( hxtRealloc(&program->opts,
					          sizeof(HXTOpt*) * newSize ) );
		program->opt_capacity = newSize;
	}

	program->opts[program->opt_length++] = opt;

	return HXT_STATUS_OK;
}


/*********************************************************************
*  delete a program                                                  *
*********************************************************************/
HXTStatus hxtOptProgDelete(HXTOptProgram* program){
	HXT_ASSERT( program!=NULL );
	HXT_CHECK( hxtFree(&program->opts) );
	HXT_CHECK( hxtFree(&program) );

	return HXT_STATUS_OK;
}


/*********************************************************************
*  search a long option inside the lists of a program                *
*********************************************************************/
static int searchLongOption(HXTOptProgram* program,
			                const char* string)
{
	for (size_t i=0; i<program->opt_length; i++) {
		if(program->opts[i]->longs!=NULL &&
		   strcmp(program->opts[i]->longs, string)==0) {
			return i;
		}
	}

	return -1;
}


/*********************************************************************
*  search a short option inside the lists of a program               *
*********************************************************************/
static int searchShortOption(HXTOptProgram* program,
                             char c)
{
	for (size_t i=0; i<program->opt_length; i++) {
		if(program->opts[i]->shorts!=NULL &&
		   strchr(program->opts[i]->shorts, c)!=NULL) {
			return i;
		}
	}

	return 0;
}

static inline const char* getArgTypeName(ARG_TYPE t){
	switch(t) {
		case ARG_INT64 :
			return "a 64-bit integer";
		case ARG_INT32 :
			return "a 32-bit integer";
		case ARG_UINT32 :
			return "a 32-bit unsigned integer";
		case ARG_DOUBLE :
			return "a float";
		case ARG_FLOAT :
			return "a double";
		case ARG_POSITIVE_FLOAT :
			return "a positive float";
		case ARG_POSITIVE_DOUBLE :
			return "a positive double";
		case ARG_STRING :
			return "a string";
		default:
			if(t>0)
				return "an integer";
			else
				return "a string";
	}
}


/*********************************************************************
*  scan parameter and execute callback function for user options     *
*********************************************************************/
static HXTStatus doOption(HXTOpt* opt,
                          const char* arg,
                          void* state,
                          char* optName)
{
	char* endptr = NULL;

	int64_t integer = INT64_MIN;
	double real = NAN;
	const char* string = "\a";

	
	if(opt->argRequirement&1 ||
	  (opt->argRequirement==ARG_OPTIONAL && arg!=NULL)) {
		if(opt->argType>-4)
			integer = strtol(arg, &endptr, 0);
		else if(opt->argType>-8)
			real = strtod(arg, &endptr);
		else
			string = arg;


		if(errno == ERANGE){
			return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
			       "cannot convert argument \"%s\" of option \"%s\" to %s (range overflow)",
			       arg, optName, getArgTypeName(opt->argType));
		}
		else if (arg == endptr)
		{
			return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
			       "cannot convert argument \"%s\" of option \"%s\" to %s (no digit)",
			       arg, optName, getArgTypeName(opt->argType));
		}
		else if(endptr!=NULL && *endptr!='\0') {
			return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
			    "cannot convert argument \"%s\" of option \"%s\" to %s (trailing unvalid characters)",
			    arg, optName, getArgTypeName(opt->argType));
		}

		switch(opt->argType){
			case ARG_POSITIVE_INT64 :
				if(integer<0)
					return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
					       "cannot convert argument \"%s\" of option \"%s\" to %s (value was negative)",
					       arg, optName, getArgTypeName(opt->argType));
			break;
			case ARG_INT32:
			{
				int32_t i32 = integer;
				if(i32!=integer)
					return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
					       "cannot convert argument \"%s\" of option \"%s\" to %s ((int32_t)%ld!=%ld)",
					       arg, optName, getArgTypeName(opt->argType), integer, integer);
			}
			break;
			case ARG_UINT32:
			{
				uint32_t u32 = integer;
				if(u32!=integer)
					return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
					       "cannot convert argument \"%s\" of option \"%s\" to %s ((uint32_t)%ld!=%ld)",
					       arg, optName, getArgTypeName(opt->argType), integer, integer);
			}
			break;
			case ARG_POSITIVE_DOUBLE:
				if(real<0.0)
					return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
					       "cannot convert argument \"%s\" of option \"%s\" to %s (value was negative)",
					       arg, optName, getArgTypeName(opt->argType));
			break;
			case ARG_POSITIVE_FLOAT:
				if(real<0.0)
					return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
					       "cannot convert argument \"%s\" of option \"%s\" to %s (value was negative)",
					       arg, optName, getArgTypeName(opt->argType));
			/* fallthrough */
			case ARG_FLOAT:
			{
				float f32 = real;
				if(f32!=real)
					return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
					       "cannot convert argument \"%s\" of option \"%s\" to %s ((float)%f!=%f)",
					       arg, optName, getArgTypeName(opt->argType), real, real);
			}
			break;
			default:
				if(opt->argType>0 && ( integer > opt->argType || integer<0 ) )
					return HXT_ERROR_MSG(HXT_STATUS_RANGE_ERROR,
					       "cannot convert argument \"%s\" of option \"%s\" to an integer between 0 and %d",
					       arg, optName, opt->argType);
			break;

		}
	}

	if(opt->argType>-4)
		opt->integer = integer;
	else if(opt->argType>-8)
		opt->real = real;
	else
		opt->string = string;

	if(opt->cb!=NULL){
		HXTStatus err = opt->cb(opt, state);
		if(err<0){
		return HXT_ERROR_MSG(HXT_STATUS_ERROR,
		       "argument \"%s\" of option \"%s\" triggered an error in callback",
		       arg, optName);
		}
	}

	return HXT_STATUS_OK;
}


HXTStatus hxtOptCalledWithoutArg(HXTOpt* opt){
	if(opt->argType>-4) // integer type
		return (opt->integer==INT64_MIN);
	else if(opt->argType>-8)
		return (opt->real==NAN);
	else
		return (opt->string[0]=='\a');
}


/*********************************************************************
*  Function parsing argv                                             *
*********************************************************************/
HXTStatus hxtOptProgParse(HXTOptProgram* program,
			  const int argc,
			  char* argv[],
			  void* state,
			  int* optind)
{
	HXT_ASSERT(program!=NULL);
	HXT_ASSERT(optind!=NULL);

	int numarg = argc;
	*optind = 1;
	for (int i=1; i<numarg; i++) {
		char *arg = NULL;
		HXTOpt* opt = NULL;

		if(argv[i][0]!='-' || (argv[i][0]=='-' && argv[i][1]=='\0')){
			/* not opt, shift everything before this string */
			arg = argv[i];
			for (int j=i; j<argc-1; j++) {
				argv[j] = argv[j+1];
			}
			argv[argc-1] = arg;
			numarg--;
			i--;
		}
		else if(argv[i][1]=='-') { /* long opt */
			if(argv[i][2]=='\0') /* -- terminate argument parsing */
				return HXT_STATUS_OK;

			char* equalSign = strchr(argv[i]+2,'=');
			
			if(equalSign!=NULL){
				*equalSign = '\0';
				arg = equalSign + 1;
			}

			int num = searchLongOption(program, argv[i]+2);
			if(num<0){
				return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
				       "option \"%s\" not found", argv[i]);
			}
			opt = program->opts[num];

			if(equalSign!=NULL){
				*equalSign = '=';
				if(opt->argRequirement==ARG_NONE){
					return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
					       "option \"%s\" takes no argument", argv[i]);
				}
			}
			else{
				if(num==0) { // it's the help option
					*optind = -1;
					return HXT_STATUS_OK;
				}
				if(opt->argRequirement&1 && numarg<=i+1){
					return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
					       "options \"%s\" requires an argument", argv[i]);
				}
				else if(numarg>i+1 && (opt->argRequirement&1 || argv[i+1][0]!='-')) {
					arg = argv[i+1];
					i++;
				}
			}

			HXT_CHECK( doOption(opt, arg, state, argv[i]) );
		}
		else{ /* short option */
			int cond = argv[i][1];
			for(int j=1; cond; j++){
				int num = searchShortOption(program, argv[i][j]);
				if(num<0){
					return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
					       "option \'%c\' in \"%s\" not found", argv[i][j], argv[i]);
				}

				char optName[] = "- ";
				optName[1] = argv[i][j];
				cond = argv[i][j+1];

				if(num==0){
					*optind = -1;
					return HXT_STATUS_OK;
				}

				opt = program->opts[num];

				if(opt->argRequirement!=ARG_NONE){
					if(cond){
						arg = argv[i] + j+1;
						cond = 0; // stop the loop
					}
					else if(opt->argRequirement&1 && numarg<=i+1){
						return HXT_ERROR_MSG(HXT_STATUS_FORMAT_ERROR,
						       "options \'%c\' in \"%s\" requires an argument", argv[i][j], argv[i]);
					}
					else if(numarg>i+1 && (opt->argRequirement==ARG_REQUIRED || argv[i+1][0]!='-')) {
						arg = argv[i+1];
						i++;
					}
				}

				HXT_CHECK( doOption(opt, arg, state, optName) );
			}
		}
		*optind = i+1;
	}

	for (size_t i=0; i<program->opt_length; i++) {
		HXTOpt* opt = program->opts[i];
		if(opt->argRequirement==ARG_NON_NULL_REQUIRED &&
			 ((opt->argType>-4 && opt->integer==0) ||
			  (opt->argType>-8 && opt->real==0.0)  ||
			  (opt->argType<=-8 && opt->string==NULL)
			 )
			) {
			if(opt->longs!=NULL)
				return HXT_ERROR_MSG(HXT_STATUS_ERROR,
				       "mandatory option \"--%s\" must have a non-null argument",
				       opt->longs);
			else
				return HXT_ERROR_MSG(HXT_STATUS_ERROR,
				       "mandatory option \'-%c\' must have a non-null argument",
				       opt->shorts[0]);
		}
	}

	return HXT_STATUS_OK;
}


#define MY_SPRINTF(...) *offset+=snprintf(text+ *offset, 16384- *offset, ## __VA_ARGS__ )

static void printOptionLine(HXTOpt* opt, char text[16384], int* offset)
{
	int char_max = 30;
	int oldOffset = *offset;
	MY_SPRINTF("  ");

	int long_exist = opt->longs!=NULL && opt->longs[0]!='\0';

	// short params
	if(opt->shorts!=NULL && opt->shorts[0]!='\0'){
		int len = strlen(opt->shorts);

		for (int i=0; i<len-1; i++){
			MY_SPRINTF("-%c, ", opt->shorts[i]);
		}
		
		if(long_exist){
			MY_SPRINTF("-%c, ", opt->shorts[len-1]);
		}
		else{
			MY_SPRINTF("-%c", opt->shorts[len-1]);
		}
	}

	if(long_exist){
		if(opt->argRequirement==ARG_NONE)
			MY_SPRINTF("--%s", opt->longs);
		else if(opt->argRequirement==ARG_OPTIONAL)
			MY_SPRINTF("--%s[=%s]", opt->longs, opt->argName);
		else
			MY_SPRINTF("--%s=%s", opt->longs, opt->argName);

		
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
	if(opt->argRequirement!=ARG_NONE &&
		(opt->argType!=ARG_STRING || opt->string!=NULL))
	{
		MY_SPRINTF("\n%*cdefault: %s=", char_max+1, ' ', opt->argName);
		if(opt->argType>-4) // integer type
			MY_SPRINTF("%ld",opt->integer);
		else if(opt->argType>-8)
			MY_SPRINTF("%g",opt->real);
		else
			MY_SPRINTF("%s",opt->string);
	}

	MY_SPRINTF("\n");
}



HXTStatus hxtOptProgGetHelp(HXTOptProgram* program, char text[16384])
{
	int offsetval = 0;
	int* offset = &offsetval;
	if(program->usage_line)
		MY_SPRINTF("%s\n\n", program->usage_line);

	if(program->start_description)
		MY_SPRINTF("%s\n\n", program->start_description);

	int oldOffset = *offset;
	MY_SPRINTF("Application Options:\n");
	int char_printed = *offset - oldOffset;

	MY_SPRINTF("%.*s\n", char_printed>64?63:char_printed-1,
   "---------------------------------------------------------------");

	for (size_t i=0; i<program->opt_length; i++) {
		printOptionLine(program->opts[i], text, offset);
	}

	if(program->end_description)
		MY_SPRINTF("%s\n", program->end_description);
	return HXT_STATUS_OK;
}