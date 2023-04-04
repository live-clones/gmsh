#ifndef __MACHDEFS_H
#define __MACHDEFS_H

#define NDEBUG
#define CCSYS_STANDARD

#ifdef  CCSYS_STANDARD
#define CC_PROTOTYPE_ANSI
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#if !defined(WIN32)
#include <unistd.h>
#endif
#include <assert.h>
#include <time.h>
#undef CC_ZEIT_TIMES
#define CC_ZEIT_DUMMY
#endif

#ifdef  CCSYS_STANDARD_KNR
#undef CC_PROTOTYPE_ANSI
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#define CC_ZEIT_TIMES
#define const
#define void int
#endif

#ifdef  CCSYS_ALTERNATE
#define CC_PROTOTYPE_ANSI
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#define CC_ZEIT_RUSAGE
#endif

#ifdef  CCSYS_SUNOS_GCC
#define CC_PROTOTYPE_ANSI
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>

extern int
    printf (const char *, ...),
    fprintf (FILE *, const char *, ...),
    fflush (FILE *),
    scanf (const char *, ...),
    sscanf (const char *, const char *, ...),
    fscanf (FILE *, const char *, ...),
    fclose (FILE *),
    _filbuf (FILE *),
    rename (const char *, const char *),
    time (int *);

extern void
    perror (const char *);

#define CC_ZEIT_TIMES
#endif


#ifndef NULL
#define NULL (0)
#endif

#endif  /* __MACHDEFS_H */
