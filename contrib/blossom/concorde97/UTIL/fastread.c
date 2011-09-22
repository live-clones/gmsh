/***************************************************************************/
/*                                                                         */
/*                   CODE TO READ ASCI INTS FAST                           */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Dave                                                      */
/*  Date: Septmember 1994 (Bonn)  (cofeb16)                                */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCutil_readint (FILE *f)                                         */
/*        - Returns the next int in the file f.                            */
/*                                                                         */
/*    NOTES:                                                               */
/*       This is much faster that scanf. Its useful for big files and      */
/*    and for profiling.                                                   */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

#ifdef CC_PROTOTYPE_ANSI
int CCutil_readint (FILE *f)
#else
int CCutil_readint (f)
FILE *f;
#endif
{
    int v = 0;
    int c;

    while (( c = getc(f)) != EOF && !((c >= '0' && c <= '9') || c == '-'));
    if (c == '-') {
        v = 0;
        while ((c = getc(f)) != EOF && c >= '0' && c <= '9') {
            v = v * 10 + c - '0';
        }
        return -v;
    } else {
        v = c - '0';
        while ((c = getc(f)) != EOF && c >= '0' && c <= '9') {
            v = v * 10 + c - '0';
        }
        return v;
    }
}
