#include "hxt_option.h"
#include "hxt_message.h"
#include "hxt_tools.h"
#include <string.h>

typedef struct {
  void *data;
  hxtOptionType type;
  char *description;
  char *name;
  HXTOptionCallback *cb;
  void *cbdata;
} hxtOption;

struct HXTOptionListStruct {
  size_t noptions;
  hxtOption *options;
  size_t narguments;
  hxtOption *arguments;
  int lastArgumentIsRepeated;
  char *description;
};

HXTStatus hxtOptionListCreate(HXTOptionList **list, const char *description)
{
  HXT_CHECK(hxtMalloc(list, sizeof(HXTOptionList)));
  (*list)->noptions = 0;
  (*list)->options = NULL;
  (*list)->narguments = 0;
  (*list)->arguments = NULL;
  (*list)->description = strdup(description);
  (*list)->lastArgumentIsRepeated = 0;
  return HXT_STATUS_OK;
}

HXTStatus hxtOptionListDelete(HXTOptionList **list)
{
  for (size_t i = 0; i < (*list)->noptions; ++i) {
    free((*list)->options[i].name);
    free((*list)->options[i].description);
  }
  for (size_t i = 0; i < (*list)->narguments; ++i) {
    free((*list)->arguments[i].name);
    free((*list)->arguments[i].description);
  }
  free((*list)->description);
  if((*list)->options)
    HXT_CHECK(hxtFree(&(*list)->options));
  if((*list)->arguments)
    HXT_CHECK(hxtFree(&(*list)->arguments));
  HXT_CHECK(hxtFree(list));
  return HXT_STATUS_OK;
}

HXTStatus hxtOptionListAdd(HXTOptionList *list, const char *name, const char *description, hxtOptionType otype, HXTOptionFlag oflag, void *data)
{
  return hxtOptionListAddCallback(list, name, description, otype, oflag, data, NULL, NULL);
}

HXTStatus hxtOptionListAddCallback(HXTOptionList *list, const char *name, const char *description, hxtOptionType otype, HXTOptionFlag oflag, void *data, HXTOptionCallback *cb, void *cbdata)
{
  hxtOption *opt;
  if (oflag & HXT_OPTION_ARGUMENT) {
    if(list->lastArgumentIsRepeated)
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "hxt options : cannot add an argument after a repeated command line argument (trying to add '%s' after '%s').", name, list->arguments[list->narguments-1].name);
    list->narguments++;
    HXT_CHECK(hxtRealloc(&list->arguments, list->narguments*sizeof(hxtOption)));
    opt = &list->arguments[list->narguments-1];
    if (oflag & HXT_OPTION_REPEATED_ARGUMENT) {
      if (!cb)
        return HXT_ERROR_MSG(HXT_STATUS_FAILED, "hxt options : a repeated argument without callback does not make sense");
      list->lastArgumentIsRepeated = 1;
    }
  }
  else {
    list->noptions++;
    HXT_CHECK(hxtRealloc(&list->options, list->noptions*sizeof(hxtOption)));
    opt = &list->options[list->noptions-1];
  }
  opt->name = strdup(name);
  opt->description = strdup(description);
  opt->type = otype;
  opt->data = data;
  opt->cb = cb;
  opt->cbdata = cbdata;
  return HXT_STATUS_OK;
}

static HXTStatus hxtOptionParse(hxtOption *option, const char *val) {
  switch(option->type) {
    case HXT_OPTION_INT :
      if(sscanf(val, "%d", (int*)option->data) == 1)
        return HXT_STATUS_OK;
      break;
    case HXT_OPTION_DOUBLE :
      if(sscanf(val, "%le", (double*)option->data) == 1)
        return HXT_STATUS_OK;
      break;
    case HXT_OPTION_STRING :
      {
        char *sdata = *(char**)option->data;
        if (sdata)
          hxtFree(&sdata);
        HXT_CHECK(hxtMalloc(&sdata, sizeof(char)*(strlen(val)+1)));
        strcpy(sdata, val);
        *(char**)option->data = sdata;
        return HXT_STATUS_OK;
      }
      break;
    default :
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "unknown option type for option %s", option->name);
  };
  return HXT_ERROR_MSG(HXT_STATUS_FAILED, "cannot parse option \"%s\" with value \"s\"", option->name, val);
}

static HXTStatus hxtOptionRunCallback(hxtOption *option) {
  if (!option->cb)
    return HXT_STATUS_OK;
  return option->cb(option->data, option->cbdata);
}

static HXTStatus hxtOptionPrint(hxtOption *option) {
  switch(option->type) {
    case HXT_OPTION_INT :
      printf("%i", *(int*)option->data);
      return HXT_STATUS_OK;
    case HXT_OPTION_DOUBLE :
      printf("%g", *(double*)option->data);
      return HXT_STATUS_OK;
    case HXT_OPTION_STRING :
      printf("\"%s\"", *(char**)option->data);
      return HXT_STATUS_OK;
    case HXT_OPTION_FLAG :
      printf("%s", (*(int*)option->data)?"on":"off");
      return HXT_STATUS_OK;
    default :
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "unknown option type for option %s", option->name);
  };
}

static HXTStatus hxtOptionListParseArgvCheck(HXTOptionList *options, int argc, char **argv, const char *description)
{
  int p=1;
  int iarg=0;
  while (p < argc) {
    if (strlen(argv[p]) > 2 && strncmp(argv[p],"--",2) == 0) {
      size_t i;
      const char *optname;
      if (strlen(argv[p]) > 5 && strncmp("--no-",argv[p],5) == 0) {
        optname = argv[p]+5;
        for (i = 0; i < options->noptions; ++i) {
          hxtOption *opt = &options->options[i];
          if(!strcmp(optname, opt->name) && opt->type == HXT_OPTION_FLAG) {
            *(int*)opt->data = 0;
            HXT_CHECK(hxtOptionRunCallback(opt));
            break;
          }
        }
      }
      else {
        optname = argv[p]+2;
        for (i = 0; i < options->noptions; ++i) {
          hxtOption *opt = &options->options[i];
          if(!strcmp(optname, opt->name)) {
            if (opt->type == HXT_OPTION_FLAG)
              *(int*)opt->data = 1;
            else{
              HXT_CHECK(hxtOptionParse(opt, argv[p+1]));
              HXT_CHECK(hxtOptionRunCallback(opt));
              p++;
            }
            break;
          }
        }
      }
      if (i == options->noptions)
        return HXT_ERROR_MSG(HXT_STATUS_FAILED, "unknown command line option \"%s\"", optname);
    }
    else {
      if ((size_t)iarg == options->narguments && options->lastArgumentIsRepeated)
        iarg--;
      if ((size_t)iarg >= options->narguments)
        return HXT_ERROR_MSG(HXT_STATUS_FAILED, "too many command line arguments (\"%s\")", argv[p]);
      hxtOption *opt = &options->arguments[iarg];
      HXT_CHECK(hxtOptionParse(opt, argv[p]));
      HXT_CHECK(hxtOptionRunCallback(opt));
        iarg++;
    }
    p++;
  }
  if ((size_t)iarg != options->narguments)
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "missing command line arguments (\"%s\")", options->arguments[iarg].name);
  return HXT_STATUS_OK;
}

HXTStatus hxtOptionListParseArgv(HXTOptionList *options, int argc, char **argv, const char *description)
{
  HXTStatus err = hxtOptionListParseArgvCheck(options, argc, argv, description);
  if (err){
    printf("\n");
    HXT_CHECK(hxtOptionListPrintUsage(options, argv[0]));
    printf("\n");
    return HXT_STATUS_FAILED;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtOptionListPrintUsage(const HXTOptionList *list, const char *exename)
{
  printf("Usage : %s", exename);
  if (list->noptions != 0)
    printf(" [options]");
  for (size_t i = 0; i < list->narguments; ++i) {
    printf(" %s", list->arguments[i].name);
  }
  if (list->lastArgumentIsRepeated)
    printf(" [%s2 ...]", list->arguments[list->narguments-1].name);
  printf("\n");
  printf("%s\n", list->description);
  char opstr[256];
  const char* hxtOptionTypeName[] = {"double", "int", "string"};
  if (list->narguments != 0) {
    printf("\nmandatory arguments :\n");
    for(size_t i = 0; i < list->narguments; ++i) {
      hxtOption *opt = &list->arguments[i];
      sprintf(opstr, "%s(%s)", opt->name, hxtOptionTypeName[opt->type]);
      printf("    %-20s %s\n", opstr, opt->description);
    }
  }
  if (list->noptions != 0) {
    printf("\noptions :\n");
    for(size_t i = 0; i < list->noptions; ++i) {
      hxtOption *opt = &list->options[i];
      if (opt->type == HXT_OPTION_FLAG)
        sprintf(opstr, "[no-]%s", opt->name);
      else
        sprintf(opstr, "%s %s", opt->name, hxtOptionTypeName[opt->type]);
      printf("  --%-20s %s [",opstr,  opt->description);
      HXT_CHECK(hxtOptionPrint(opt));
      printf("]\n");
    }
  }
  return HXT_STATUS_OK;
}
