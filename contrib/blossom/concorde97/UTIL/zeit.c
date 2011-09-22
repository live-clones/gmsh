/***************************************************************************/
/*                                                                         */
/*                        TIMING FUNCTIONS                                 */
/*                                                                         */
/*                            TSP CODE                                     */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: Summer 1994  (cofeb16)                                           */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    double CCutil_zeit (void)                                            */
/*        - To measure cpu time.                                           */
/*                                                                         */
/*    double CCutil_real_zeit (void)                                       */
/*        - To measure wall clock time.                                    */
/*                                                                         */
/*    NOTES:                                                               */
/*       To use these, set double t = CCutil_zeit (), run the function you */
/*    want to time, then commpute CCutil_zeit () - t.                      */
/*                                                                         */
/***************************************************************************/


#include "machdefs.h"
#include "util.h"

#ifdef CC_ZEIT_RUSAGE

#include <sys/time.h>
#include <sys/resource.h>

#ifdef CC_PROTOTYPE_ANSI
double CCutil_zeit (void)
#else
double CCutil_zeit ()
#endif
{
    struct rusage ru;

    getrusage (RUSAGE_SELF, &ru);

    return ((double) ru.ru_utime.tv_sec) +
            ((double) ru.ru_utime.tv_usec) / 1000000.0;
}
#endif /* CC_ZEIT_RUSAGE */

#ifdef CC_ZEIT_TIMES

#include <sys/param.h>
#include <sys/times.h>

#ifdef CLK_TCK
#define MACHINE_FREQ CLK_TCK
#else
#define MACHINE_FREQ HZ
#endif

#ifdef CC_PROTOTYPE_ANSI
double CCutil_zeit (void)
#else
double CCutil_zeit ()
#endif
{
    struct tms now;

    times (&now);
    return ((double) now.tms_utime) / ((double) MACHINE_FREQ);
}
#endif /* CC_ZEIT_TIMES */

#ifdef CC_ZEIT_DUMMY

#ifdef CC_PROTOTYPE_ANSI
double CCutil_zeit (void)
#else
double CCutil_zeit ()
#endif
{
    return 0.0;
}
#endif /* CC_ZEIT_DUMMY */

#ifdef CC_PROTOTYPE_ANSI
double CCutil_real_zeit (void)
#else
double CCutil_real_zeit ()
#endif
{
    return (double) time (0);
}
