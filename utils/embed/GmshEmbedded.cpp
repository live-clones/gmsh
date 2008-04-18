#include "GModel.h"
#include "GmshEmbedded.h"

Context_T CTX;

void GModel::_createGEOInternals(){}
void GModel::_deleteGEOInternals(){}
void GModel::_deleteOCCInternals(){}

void GmshInitialize(int argc, char **argv)
{
}

void GmshFinalize(int argc, char **argv)
{
}

void Msg(int level, const char *fmt, ...)
{
  va_list args;
  int abort = 0;

  va_start(args, fmt);

  switch (level) {

  case PROGRESS:
  case STATUS1N:
  case STATUS2N:
    break;

  case DIRECT:
    if(CTX.verbosity >= 2) {
      vfprintf(stdout, fmt, args);
      fprintf(stdout, "\n");
    }
    break;

  case FATAL:
  case FATAL3: abort = 1;
  case FATAL1:
  case FATAL2:
    fprintf(stderr, FATAL_STR);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    break;

  case GERROR:
  case GERROR1:
  case GERROR2:
  case GERROR3:
    fprintf(stderr, ERROR_STR);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    break;

  case WARNING:
  case WARNING1:
  case WARNING2:
  case WARNING3:
    if(CTX.verbosity >= 1) {
      fprintf(stderr, WARNING_STR);
      vfprintf(stderr, fmt, args);
      fprintf(stderr, "\n");
    }
    break;

  case DEBUG:
  case DEBUG1:
  case DEBUG2:
  case DEBUG3:
    if(CTX.verbosity >= 4) {
      fprintf(stderr, DEBUG_STR);
      vfprintf(stderr, fmt, args);
      fprintf(stderr, "\n");
    }
    break;

  default:
    if(CTX.verbosity >= 2) {
      fprintf(stderr, INFO_STR);
      vfprintf(stderr, fmt, args);
      fprintf(stderr, "\n");
    }
    break;
  }

  va_end(args);

  if(abort)
    exit(1);
}
